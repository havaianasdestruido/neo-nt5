---
title: PE format and the loader
sidebar_position: 25
description: The PE/COFF image layout, imports, exports, relocations and TLS, and how ntdll's Ldr maps, snaps and initialises a module.
---

A Windows executable or DLL is a **PE** (Portable Executable) image: a COFF header plus an NT
header, a section table and data directories. The loader (`base/ntdll/ldr*`) maps it, resolves its
imports, applies relocations, runs TLS callbacks and calls `DllMain`. Understanding the format is
the difference between guessing why a DLL will not load and knowing.

```text
+---------------------------+ 0x0
| IMAGE_DOS_HEADER          |  "MZ", e_lfanew -> PE header
+---------------------------+
| MS-DOS stub               |
+---------------------------+ e_lfanew
| "PE\0\0" signature        |
+---------------------------+
| IMAGE_FILE_HEADER         |  machine, sections, timestamp, characteristics
+---------------------------+
| IMAGE_OPTIONAL_HEADER32/64|  entry point, image base, section alignment, data directories
+---------------------------+
| section table             |  .text .data .rdata .pdata .reloc .tls ...
+---------------------------+
| section data              |
+---------------------------+
```

## Headers

`IMAGE_DOS_HEADER` is at
[`public/sdk/inc/winnt.h:5700`](https://github.com/havaianasdestruido/neo-nt5/blob/main/public/sdk/inc/winnt.h#L5700);
its `e_lfanew` points to the PE signature. `IMAGE_NT_HEADERS64` is at `:6004`, `IMAGE_NT_HEADERS` at
`:6010`, and `IMAGE_SECTION_HEADER` at `:6104`.

```c
typedef struct _IMAGE_NT_HEADERS {
    DWORD Signature;                      // "PE\0\0"
    IMAGE_FILE_HEADER FileHeader;
    IMAGE_OPTIONAL_HEADER32 OptionalHeader;
} IMAGE_NT_HEADERS32, *PIMAGE_NT_HEADERS32;
```

`IMAGE_OPTIONAL_HEADER32` carries the fields the loader needs:

| Field | Meaning |
| --- | --- |
| `AddressOfEntryPoint` | RVA of `WinMain`/`DllMain` |
| `ImageBase` | Preferred load address |
| `SectionAlignment` | Alignment of sections in memory (usually 64 KiB) |
| `FileAlignment` | Alignment of sections in the file (usually 512 bytes) |
| `SizeOfImage` | Total mapped size |
| `Subsystem` | `IMAGE_SUBSYSTEM_WINDOWS_GUI`, `..._CUI`, `..._NATIVE` |
| `NumberOfRvaAndSizes` | Number of data directories |
| `DataDirectory[]` | Export, import, resource, exception, base reloc, TLS, ... |

Data directory indices are defined at `winnt.h:6067`:

```c
#define IMAGE_DIRECTORY_ENTRY_EXPORT      0
#define IMAGE_DIRECTORY_ENTRY_IMPORT      1
#define IMAGE_DIRECTORY_ENTRY_RESOURCE    2
#define IMAGE_DIRECTORY_ENTRY_EXCEPTION   3
#define IMAGE_DIRECTORY_ENTRY_SECURITY    4
#define IMAGE_DIRECTORY_ENTRY_BASERELOC   5
#define IMAGE_DIRECTORY_ENTRY_DEBUG       6
#define IMAGE_DIRECTORY_ENTRY_TLS         9
```

## Sections

| Section | Contents |
| --- | --- |
| `.text` | Code, usually `IMAGE_SCN_MEM_EXECUTE \| IMAGE_SCN_MEM_READ` |
| `.data` | Read/write initialised data |
| `.rdata` | Read-only data: import table, strings, constants |
| `.bss` | Uninitialised data |
| `.edata` | Export table (if not folded into `.rdata`) |
| `.idata` | Import table |
| `.reloc` | Base relocations |
| `.tls` | Thread-local storage directory and callbacks |
| `.rsrc` | Resources |
| `.pdata` | Exception table (x64) |

Section flags (`IMAGE_SCN_MEM_READ`, `IMAGE_SCN_MEM_WRITE`, `IMAGE_SCN_MEM_EXECUTE`) determine
page protection: the loader maps `.text` as `PAGE_EXECUTE_READ`, `.data` as `PAGE_READWRITE`, and
`.rdata` as `PAGE_READONLY`. A section with both write and execute is a security smell.

## Exports

`IMAGE_EXPORT_DIRECTORY` is at `winnt.h:6785`. Its layout is a directory of names and RVAs:

```c
typedef struct _IMAGE_EXPORT_DIRECTORY {
    DWORD Characteristics;
    DWORD TimeDateStamp;
    WORD  MajorVersion;
    WORD  MinorVersion;
    DWORD Name;
    DWORD Base;
    DWORD NumberOfFunctions;
    DWORD NumberOfNames;
    DWORD AddressOfFunctions;     // RVA of an array of RVAs
    DWORD AddressOfNames;         // RVA of an array of name RVAs
    DWORD AddressOfNameOrdinals;  // RVA of an array of ordinals
} IMAGE_EXPORT_DIRECTORY, *PIMAGE_EXPORT_DIRECTORY;
```

Lookup by name is a binary search over `AddressOfNames`, then `AddressOfNameOrdinals[nameIndex]`
gives the function index into `AddressOfFunctions`. Lookup by ordinal is `AddressOfFunctions[ordinal - Base]`.

The tree's module definition files are the source of truth for exports:
`windows/core/ntuser/client/user32.def`, `windows/core/ntgdi/client/gdi32.def`,
`mergedcomponents/advapi32/advapi32.def`, and `kernel32.prf`/`kernel32.src`.

## Imports

`IMAGE_IMPORT_DESCRIPTOR` is at `winnt.h:6888`:

```c
typedef struct _IMAGE_IMPORT_DESCRIPTOR {
    union {
        DWORD Characteristics;
        DWORD OriginalFirstThunk;   // RVA of INT
    };
    DWORD TimeDateStamp;
    DWORD ForwarderChain;
    DWORD Name;                     // RVA of the DLL name
    DWORD FirstThunk;               // RVA of the IAT
} IMAGE_IMPORT_DESCRIPTOR;
```

The loader walks the descriptors, maps each DLL, and writes the resolved address into the **IAT**
(`FirstThunk`). `OriginalFirstThunk` points to the **INT** (import name table), which is the
read-only copy the loader reads. If `OriginalFirstThunk` is zero, the loader reads the names from
the IAT itself — a legacy format that cannot be bound.

`LdrpWalkImportDescriptor` (`base/ntdll/ldrsnap.c`) is the routine that does this in this tree; its
name appears in `ntdll.prf`:

```text
LdrpWalkImportDescriptor@8
LdrpCheckForLoadedDll@16
LdrpMapDll@16
LdrpSnapIAT@16
LdrpSnapThunk@28
```

## Relocations

If a DLL cannot be loaded at its preferred `ImageBase` (because another image is already there),
the loader maps it elsewhere and applies the base relocation table. `IMAGE_BASE_RELOCATION`
blocks contain `(type, offset)` pairs:

| Type | Meaning |
| --- | --- |
| `IMAGE_REL_BASED_ABSOLUTE` | Padding, skip |
| `IMAGE_REL_BASED_HIGH` | Add the high 16 bits of the delta |
| `IMAGE_REL_BASED_LOW` | Add the low 16 bits |
| `IMAGE_REL_BASED_HIGHLOW` | Add the full 32-bit delta (x86) |
| `IMAGE_REL_BASED_DIR64` | Add the full 64-bit delta (x64) |

A DLL with no `.reloc` section (`IMAGE_FILE_RELOCS_STRIPPED`) **must** load at its preferred base.
If that base is taken, the load fails with `STATUS_CONFLICTING_ADDRESSES`. ASLR relies on relocations.

## TLS

`IMAGE_TLS_DIRECTORY32`/`64` (`winnt.h:6850`/`:6860`) describe thread-local storage:

```c
typedef struct _IMAGE_TLS_DIRECTORY32 {
    DWORD StartAddressOfRawData;
    DWORD EndAddressOfRawData;
    DWORD AddressOfIndex;
    DWORD AddressOfCallBacks;
    DWORD SizeOfZeroFill;
    DWORD Characteristics;
} IMAGE_TLS_DIRECTORY32, *PIMAGE_TLS_DIRECTORY32;
```

TLS callbacks run on process attach, thread attach, thread detach and process detach — **before
`DllMain`** for process attach. That makes them useful for initialization that must precede the
loader's `DllMain` call, and dangerous because the loader lock is held.

`LdrpInitializeTls` in `ntdll.prf` is the routine that walks the callbacks.

## The loader's work

The user-mode loader is `base/ntdll`:

| Step | Routine |
| --- | --- |
| Map the image | `LdrpMapDll` |
| Walk imports recursively | `LdrpWalkImportDescriptor` |
| Snap the IAT | `LdrpSnapIAT`, `LdrpSnapThunk` |
| Run TLS callbacks | `LdrpInitializeTls` |
| Run initialisers | `LdrpRunInitializeRoutines` |
| Per-thread initialisation | `LdrpInitialize` (`ldrinit.c:331`) |
| Per-process initialisation | `LdrpInitializeProcess` (`ldrinit.c:851`) |
| Public entry point | `LdrLoadDll` (`ldrapi.c:98`) |

`LdrpInitializeProcess` is called from `LdrpInitialize` on the first thread of the process. It
walks the import graph depth-first, maps each DLL, snaps its IAT, then calls the initialisers in
dependency order.

## DLL search order

The documented order (with `SafeDllSearchMode` enabled, the default):

1. The directory the application was loaded from.
2. The 32-bit Windows system directory (`GetSystemDirectory`).
3. The 16-bit Windows system directory (`System`).
4. The Windows directory (`GetWindowsDirectory`).
5. The current directory.
6. The directories in `PATH`.

`LoadLibraryExW` flags alter it: `LOAD_WITH_ALTERED_SEARCH_PATH` puts the directory of the named
file first, `LOAD_LIBRARY_AS_DATAFILE` skips `DllMain`, and `DONT_RESOLVE_DLL_REFERENCES` skips
imports. The tree's implementation is `base/win32/client/module.c:245`.

Known DLLs (`HKLM\SYSTEM\CurrentControlSet\Control\Session Manager\KnownDLLs`) are mapped at boot
and never unloaded; the loader checks the KnownDLL section before searching. `shell/docs/shelldev.doc`
mentions the mechanism and the `AlwaysUnloadDll` override.

## Parsing an image

```c
#include <windows.h>
#include <stdio.h>

int wmain(int argc, wchar_t **argv)
{
    if (argc != 2) return 2;

    HANDLE hFile = CreateFileW(argv[1], GENERIC_READ, FILE_SHARE_READ, NULL,
                               OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE) { wprintf(L"open %lu\n", GetLastError()); return 1; }

    HANDLE hMap = CreateFileMappingW(hFile, NULL, PAGE_READONLY, 0, 0, NULL);
    if (!hMap) { CloseHandle(hFile); return 1; }

    PBYTE base = (PBYTE)MapViewOfFile(hMap, FILE_MAP_READ, 0, 0, 0);
    if (!base) { CloseHandle(hMap); CloseHandle(hFile); return 1; }

    PIMAGE_NT_HEADERS nt = RtlImageNtHeader(base);
    if (!nt) { wprintf(L"not a PE\n"); }
    else {
        wprintf(L"machine: 0x%04X, sections: %u, entry: 0x%08lX, image base: 0x%08lX\n",
                nt->FileHeader.Machine,
                nt->FileHeader.NumberOfSections,
                nt->OptionalHeader.AddressOfEntryPoint,
                (unsigned long)nt->OptionalHeader.ImageBase);

        ULONG size = 0;
        PVOID exports = RtlImageDirectoryEntryToData(base, FALSE,
                                                     IMAGE_DIRECTORY_ENTRY_EXPORT, &size);
        wprintf(L"exports: %ls (%lu bytes)\n", exports ? L"present" : L"none", size);
    }

    UnmapViewOfFile(base);
    CloseHandle(hMap);
    CloseHandle(hFile);
    return 0;
}
```

`RtlImageNtHeader` (`base/ntos/rtl/imagedir.c:49`) validates the signatures;
`RtlImageDirectoryEntryToData` (`:270`) maps a directory index to an address.

## Frequently asked questions

### Q: Why does a DLL fail with `STATUS_DLL_NOT_FOUND` when the file exists?

Because the loader searched the standard order and did not find it there, or because a dependent
DLL is missing. `GetLastError` reports `ERROR_MOD_NOT_FOUND`; the missing module is usually in the
loader snaps (`gflags /sls`) or in a debugger breakpoint on `LdrpMapDll` failure. Check the
`PATH`, the application directory, and the dependency tree.

### Q: Why does a DLL fail with `ERROR_BAD_EXE_FORMAT`?

Because the architecture does not match the process (32-bit DLL in a 64-bit process, or vice
versa), or the header is malformed. `STATUS_INVALID_IMAGE_FORMAT` maps to `ERROR_BAD_EXE_FORMAT`.
WOW64 can run a 32-bit process on 64-bit Windows, but a 32-bit DLL cannot load into a 64-bit
process.

### Q: What is the difference between the IAT and the INT?

The IAT (`FirstThunk`) is the writable table the loader patches with resolved addresses. The INT
(`OriginalFirstThunk`) is the read-only table of names the loader reads. If `OriginalFirstThunk` is
zero, the loader reads names from the IAT (legacy), and the image cannot be bound.

### Q: Why does a DLL need a `.reloc` section?

Because it may not load at its preferred base. Without relocations, the loader can only map it at
`ImageBase`; if that range is occupied, the load fails. ASLR requires relocations, which is why
`/DYNAMICBASE` images always carry them.

### Q: Can TLS callbacks call `LoadLibrary`?

They run with the loader lock held, so `LoadLibrary` from a TLS callback can deadlock. The safe
operations are initialization of the DLL's own data and calls into already-loaded modules. Do not
do COM initialization or create threads in a TLS callback.

### Q: Why is `DllMain` dangerous?

Because it runs with the loader lock held. You must not call `LoadLibrary`, create threads, call
COM, or synchronize with other threads. The documented rule is: do the minimum in `DllMain` and
defer everything else to an initialization function called by the application.

### Q: Where is the loader's source?

`base/ntdll/ldrapi.c` (public entry points), `ldrinit.c` (process/thread initialisation),
`ldrsnap.c` (import snapping), `ldrutil.c` (helper utilities), `ldrp.h` (internal structures).
`LdrLoadDll` is at `ldrapi.c:98`, `LdrGetProcedureAddress` at `:1243`.

### Q: How do I inspect the import table of a binary?

Use a PE parser (`dumpbin /imports`, `link /dump`, or the `IMAGE_IMPORT_DESCRIPTOR` walk above).
In the debugger, `!dh <module>` prints the headers and the import directory.

### Q: What is a forwarder in an export table?

An export whose RVA points to a string of the form `DLL.Function` instead of code. The loader
resolves it by loading the target DLL and looking up the name. `kernel32.src` uses forwarders for
`HeapAlloc = NTDLL.RtlAllocateHeap`; the loader follows them transparently.
