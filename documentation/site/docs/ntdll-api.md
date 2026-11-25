---
title: NTDLL — the NT runtime library
sidebar_position: 20
description: The Rtl, Ldr, Csr and SxS families of ntdll — strings, heaps, error translation, the loader, CSRSS client, activation contexts and vectored exception handling.
---

`ntdll.dll` is the user-mode half of the NT executive. It contains the **NT runtime library**
(`Rtl*`), the **loader** (`Ldr*`), the **CSRSS client** (`Csr*`), the **activation-context**
machinery (`Rtl*`/`SxS*`), the **vectored exception** support and the **system service stubs**.
Almost every other DLL in the process ultimately calls into it.

```text
ntdll.dll  (base/ntdll)
  |-- Rtl*   runtime: strings, heaps, NLS, errors, images, atoms, ACLs
  |-- Ldr*   loader: LdrLoadDll, LdrGetProcedureAddress, LdrGetDllHandle
  |-- Csr*   CSRSS client: CsrClientCallServer, CsrNewDirectory
  |-- SxS*   activation contexts: sxsactctx.c, sxsctxact.c
  |-- VEH    RtlAddVectoredExceptionHandler / Remove
  +-- Nt*/Zw* stubs generated from base/ntos/ke/services.tab
```

## Exports

`ntdll.prf` is the pre-link directive file; it lists 72 symbols with their `__stdcall` decorations:

```text
LdrInitializeThunk@16
LdrpInitialize@12
LdrpInitializeProcess@12
LdrDisableThreadCalloutsForDll@4
RtlInitializeCriticalSection@4
RtlCreateHeap@24
LdrpWalkImportDescriptor@8
LdrpCheckForLoadedDll@16
LdrpMapDll@16
LdrpSnapIAT@16
LdrpSnapThunk@28
LdrpNameToOrdinal@20
...
```

The rest of the `Nt*`/`Zw*` exports are generated at build time. `base/ntdll/makefile.nap`
records the rule:

```bat
i386\usrstubs.asm: \\nt\private\ntos\ke\services.tab
    gensrv -d i386 -e asm \\nt\private\ntos\ke
```

`services.tab` (`base/ntos/ke/services.tab`, 284 lines) maps a name to its argument count:

```text
CreateFile,11
CreateProcess,8
CreateProcessEx,9
CreateThread,8
MapViewOfSection,10
OpenFile,6
OpenKey,3
QueryValueKey,6
```

`gensrv` (`sdktools/gensrv`) reads that table and emits both the user-mode stub and the kernel
service table. **Adding a system service starts with `services.tab`.**

## Strings

NT strings are counted, not null-terminated:

```c
typedef struct _UNICODE_STRING {
    USHORT Length;          // bytes, excluding the terminator
    USHORT MaximumLength;   // bytes of the buffer, including the terminator
    PWSTR  Buffer;
} UNICODE_STRING, *PUNICODE_STRING;
```

| Function | Purpose | Implementation | Documentation |
| --- | --- | --- | --- |
| `RtlInitUnicodeString` | Initialise from a null-terminated wide string | `base/ntos/rtl/string.c:156` | [UNICODE_STRING](https://learn.microsoft.com/en-us/windows/win32/api/ntdef/ns-ntdef-_unicode_string) |
| `RtlInitAnsiString` | Initialise from a narrow string | `string.c:110` | [ANSI_STRING](https://learn.microsoft.com/en-us/windows/win32/api/ntdef/ns-ntdef-_string) |
| `RtlAnsiStringToUnicodeString` | Convert with allocation | `base/ntos/rtl/nls.c:89` | [RtlAnsiStringToUnicodeString](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlansistringtounicodestring) |
| `RtlUnicodeStringToAnsiString` | Convert with allocation | `nls.c:247` | [RtlUnicodeStringToAnsiString](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlunicodestringtoansistring) |
| `RtlFreeUnicodeString` | Free a converted string | `string.c` | [RtlFreeUnicodeString](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfreeunicodestring) |
| `RtlCompareUnicodeString` | Compare two counted strings | `string.c` | [RtlCompareUnicodeString](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcompareunicodestring) |
| `RtlEqualUnicodeString` | Equality test | `string.c` | [RtlEqualUnicodeString](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlequalunicodestring) |
| `RtlCopyUnicodeString` | Copy | `string.c` | [RtlCopyUnicodeString](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcopyunicodestring) |

```c
UNICODE_STRING name;
RtlInitUnicodeString(&name, L"\\??\\C:\\Windows\\notepad.exe");
// name.Length is in bytes; name.Buffer is not necessarily null-terminated
// unless MaximumLength includes the terminator and the source was terminated.
```

The buffer of a `UNICODE_STRING` built by `RtlInitUnicodeString` **is** null-terminated in practice,
but the contract does not promise it. Always use `Length`/`MaximumLength`, never `wcscpy` on
`Buffer`.

## Heaps

The heap code lives in `base/ntos/rtl` because it is shared by kernel and user mode:

| Function | Purpose | Implementation | Documentation |
| --- | --- | --- | --- |
| `RtlCreateHeap` | Create a heap | `base/ntos/rtl/heap.c:224` | [RtlCreateHeap](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcreateheap) |
| `RtlDestroyHeap` | Destroy a heap | `heap.c:1247` | [RtlDestroyHeap](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-rtldestroyheap) |
| `RtlAllocateHeap` | Allocate | `heap.c:1487` | [RtlAllocateHeap](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlallocateheap) |
| `RtlFreeHeap` | Free | `heap.c:3391` | [RtlFreeHeap](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfreeheap) |
| `RtlReAllocateHeap` | Resize | `base/ntos/rtl/heapdll.c:581` | [RtlReAllocateHeap](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlreallocateheap) |
| `RtlSizeHeap` | Query size | `heap.c:4306` | [RtlSizeHeap](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlsizeheap) |

`RtlAllocateHeap` takes a **tag** as its second argument, which is how pool-mon and the debugger
identify allocation sites:

```c
PVOID p = RtlAllocateHeap(RtlProcessHeap(), HEAP_ZERO_MEMORY, 1024);
RtlFreeHeap(RtlProcessHeap(), 0, p);
```

`RtlProcessHeap()` returns the process heap. `kernel32!HeapAlloc` is a direct forwarder to
`RtlAllocateHeap` (`base/win32/client/kernel32.src:496`).

## Error translation

| Function | Purpose | Implementation | Documentation |
| --- | --- | --- | --- |
| `RtlNtStatusToDosError` | `NTSTATUS` to `ERROR_*` | `base/ntos/rtl/error.c:45` | [RtlNtStatusToDosError](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlntstatustodoserror) |
| `RtlGetLastWin32Error` | Read the TEB's last error | `error.c:209` | [RtlGetLastWin32Error](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlgetlastwin32error) |
| `RtlSetLastWin32Error` | Write it | `error.c:230` | [RtlSetLastWin32Error](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlsetlastwin32error) |
| `RtlNtStatusToDosErrorNoTeb` | Translate without touching the TEB | `error.c` | [RtlNtStatusToDosErrorNoTeb](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlntstatustodoserrornoteb) |

The translation is a table in `error.c`. Not every `NTSTATUS` has a distinct Win32 error; several
map to `ERROR_UNRECOGNIZED_MEDIA`-style generic codes, which is why the original `NTSTATUS` is more
diagnostic than the `GetLastError` value.

## The loader

| Function | Purpose | Implementation | Documentation |
| --- | --- | --- | --- |
| `LdrLoadDll` | Map a DLL into the process | `base/ntdll/ldrapi.c:98` | [LdrLoadDll](https://learn.microsoft.com/en-us/windows/win32/api/winternl/nf-winternl-ldrloaddll) |
| `LdrGetDllHandle` | Handle for an already-loaded DLL | `ldrapi.c:521` | [LdrGetDllHandle](https://learn.microsoft.com/en-us/windows/win32/api/winternl/nf-winternl-ldrgetdllhandle) |
| `LdrGetProcedureAddress` | Resolve an export | `ldrapi.c:1243` | [LdrGetProcedureAddress](https://learn.microsoft.com/en-us/windows/win32/api/winternl/nf-winternl-ldrgetprocedureaddress) |
| `LdrDisableThreadCalloutsForDll` | Suppress `DLL_THREAD_*` for one DLL | `ldrapi.c` | [LdrDisableThreadCalloutsForDll](https://learn.microsoft.com/en-us/windows/win32/api/winternl/nf-winternl-ldrdisablethreadcalloutsfordll) |
| `LdrFindEntryForAddress` | Map an address to a module | `ldrapi.c` | [LdrFindEntryForAddress](https://learn.microsoft.com/en-us/windows/win32/api/winternl/nf-winternl-ldrfindentryforaddress) |

`LdrLoadDll` is what `LoadLibraryExW` calls. Its path search, import resolution and initialiser
execution are in `ldrapi.c`, `ldrinit.c`, `ldrsnap.c` and `ldrutil.c`.

```c
// What LoadLibraryW does, in miniature:
UNICODE_STRING name;
RtlInitUnicodeString(&name, L"kernel32.dll");
PVOID base = NULL;
NTSTATUS st = LdrLoadDll(NULL, NULL, &name, &base);
if (!NT_SUCCESS(st)) {
    // map to a Win32 error
}
```

The loader lock is taken during `LdrLoadDll`, `LdrUnloadDll`, thread attach/detach and
`DllMain`. Calling `LoadLibrary` from `DllMain` can deadlock for exactly this reason.

## Images

| Function | Purpose | Implementation | Documentation |
| --- | --- | --- | --- |
| `RtlImageNtHeader` | Pointer to the `IMAGE_NT_HEADERS` | `base/ntos/rtl/imagedir.c:49` | [RtlImageNtHeader](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlimagentheader) |
| `RtlImageDirectoryEntryToData` | Find a data-directory entry | `imagedir.c:270` | [RtlImageDirectoryEntryToData](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlimagedirectoryentrytodata) |
| `RtlImageRvaToVa` | RVA to virtual address | `imagedir.c` | [RtlImageRvaToVa](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlimagervatova) |

```c
PIMAGE_NT_HEADERS nt = RtlImageNtHeader(moduleBase);
ULONG size = 0;
PVOID exports = RtlImageDirectoryEntryToData(moduleBase, FALSE,
                                             IMAGE_DIRECTORY_ENTRY_EXPORT, &size);
```

`RtlImageNtHeader` validates the `MZ` and `PE\0\0` signatures and returns `NULL` for a non-image.
It is the safest way to parse a module that may not be a PE.

## Activation contexts

`base/ntdll/sxsactctx.c`, `sxsctxact.c`, `sxsctxsrch.c`, `sxsquery.c`, `sxsstorage.c` and
`sxsstoragemap.c` implement side-by-side assembly resolution. The public entry points are
`CreateActCtxW`, `ActivateActCtx`, `DeactivateActCtx`, `ReleaseActCtx`, `FindActCtxSectionStringW`
and `QueryActCtxW`. They matter for `CreateWindowExW` (which takes a `PACTIVATION_CONTEXT`) and for
COM registration-free activation.

## Vectored exception handling

```c
PVOID RtlAddVectoredExceptionHandler(ULONG First, PVECTORED_EXCEPTION_HANDLER Handler);
ULONG RtlRemoveVectoredExceptionHandler(PVOID Handle);
```

`base/ntdll/vectxcpt.c:104`. A vectored handler runs **before** any frame-based handler and is
called for every exception, including those that will be handled by `__except`. Return
`EXCEPTION_CONTINUE_SEARCH` to pass the exception on, or `EXCEPTION_CONTINUE_EXECUTION` to resume.

```c
static LONG CALLBACK Veh(PEXCEPTION_POINTERS info)
{
    if (info->ExceptionRecord->ExceptionCode == STATUS_ACCESS_VIOLATION) {
        // log it, then let the frame-based handlers run
        return EXCEPTION_CONTINUE_SEARCH;
    }
    return EXCEPTION_CONTINUE_SEARCH;
}

PVOID h = RtlAddVectoredExceptionHandler(1, Veh);
// ...
RtlRemoveVectoredExceptionHandler(h);
```

## CSRSS client

`CsrClientCallServer` (`base/ntdll/csrutil.c:25`) is the LPC call into CSRSS
(`windows/core/winsrv`, `base/subsys/csr`). It is how user32 asks the Windows subsystem to do
work that only the subsystem process can do, such as creating a console or loading a driver.

## Function reference table

| Function | Header | Implementation | Documentation |
| --- | --- | --- | --- |
| `RtlInitUnicodeString` | `ntdef.h` | `base/ntos/rtl/string.c:156` | [UNICODE_STRING](https://learn.microsoft.com/en-us/windows/win32/api/ntdef/ns-ntdef-_unicode_string) |
| `RtlInitAnsiString` | `ntdef.h` | `base/ntos/rtl/string.c:110` | [ANSI_STRING](https://learn.microsoft.com/en-us/windows/win32/api/ntdef/ns-ntdef-_string) |
| `RtlAnsiStringToUnicodeString` | `ntdef.h` | `base/ntos/rtl/nls.c:89` | [RtlAnsiStringToUnicodeString](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlansistringtounicodestring) |
| `RtlUnicodeStringToAnsiString` | `ntdef.h` | `base/ntos/rtl/nls.c:247` | [RtlUnicodeStringToAnsiString](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlunicodestringtoansistring) |
| `RtlCreateHeap` | `ntdef.h` | `base/ntos/rtl/heap.c:224` | [RtlCreateHeap](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcreateheap) |
| `RtlDestroyHeap` | `ntdef.h` | `base/ntos/rtl/heap.c:1247` | [RtlDestroyHeap](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-rtldestroyheap) |
| `RtlAllocateHeap` | `ntdef.h` | `base/ntos/rtl/heap.c:1487` | [RtlAllocateHeap](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlallocateheap) |
| `RtlFreeHeap` | `ntdef.h` | `base/ntos/rtl/heap.c:3391` | [RtlFreeHeap](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfreeheap) |
| `RtlReAllocateHeap` | `ntdef.h` | `base/ntos/rtl/heapdll.c:581` | [RtlReAllocateHeap](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlreallocateheap) |
| `RtlSizeHeap` | `ntdef.h` | `base/ntos/rtl/heap.c:4306` | [RtlSizeHeap](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlsizeheap) |
| `RtlNtStatusToDosError` | `ntdef.h` | `base/ntos/rtl/error.c:45` | [RtlNtStatusToDosError](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlntstatustodoserror) |
| `RtlGetLastWin32Error` | `ntdef.h` | `base/ntos/rtl/error.c:209` | [RtlGetLastWin32Error](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlgetlastwin32error) |
| `RtlSetLastWin32Error` | `ntdef.h` | `base/ntos/rtl/error.c:230` | [RtlSetLastWin32Error](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlsetlastwin32error) |
| `RtlImageNtHeader` | `ntdef.h` | `base/ntos/rtl/imagedir.c:49` | [RtlImageNtHeader](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlimagentheader) |
| `RtlImageDirectoryEntryToData` | `ntdef.h` | `base/ntos/rtl/imagedir.c:270` | [RtlImageDirectoryEntryToData](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlimagedirectoryentrytodata) |
| `RtlAddVectoredExceptionHandler` | `winnt.h` | `base/ntdll/vectxcpt.c:104` | [RtlAddVectoredExceptionHandler](https://learn.microsoft.com/en-us/windows/win32/api/winnt/nf-winnt-rtladdvectoredexceptionhandler) |
| `LdrLoadDll` | `winternl.h` | `base/ntdll/ldrapi.c:98` | [LdrLoadDll](https://learn.microsoft.com/en-us/windows/win32/api/winternl/nf-winternl-ldrloaddll) |
| `LdrGetDllHandle` | `winternl.h` | `base/ntdll/ldrapi.c:521` | [LdrGetDllHandle](https://learn.microsoft.com/en-us/windows/win32/api/winternl/nf-winternl-ldrgetdllhandle) |
| `LdrGetProcedureAddress` | `winternl.h` | `base/ntdll/ldrapi.c:1243` | [LdrGetProcedureAddress](https://learn.microsoft.com/en-us/windows/win32/api/winternl/nf-winternl-ldrgetprocedureaddress) |
| `CsrClientCallServer` | `winternl.h` | `base/ntdll/csrutil.c:25` | [CsrClientCallServer](https://learn.microsoft.com/en-us/windows/win32/api/winternl/nf-winternl-csrclientcallserver) |

## Frequently asked questions

### Q: Is `ntdll.dll` a documented API?

Mostly no. `winternl.h` documents a subset (`NtCreateFile`, `NtOpenFile`, `NtClose`,
`NtQueryInformationProcess`, `RtlInitUnicodeString`, `LdrLoadDll`, ...), and the rest is internal.
The internal functions are stable in practice but not a supported contract: structure layouts and
syscall numbers change between releases. Treat this page as a map of **this tree**, not as a
portability promise.

### Q: Why are `Nt*` and `Zw*` both exported?

They are the same routine with different semantics for kernel-mode callers. `Nt*` uses the caller's
previous mode for pointer capture, so a kernel thread calling `NtCreateFile` is treated as a user
caller for the purpose of probing buffers. `Zw*` forces kernel mode. In user mode both are identical
because the previous mode is already `UserMode`.

### Q: Why is `HeapAlloc` a forwarder to `RtlAllocateHeap`?

Because the heap is implemented once in the runtime and exported twice. `kernel32.src` contains
`HeapAlloc = NTDLL.RtlAllocateHeap`, so kernel32's export points at ntdll's implementation. That is
also why `HeapAlloc`'s source is `base/ntos/rtl/heap.c`.

### Q: Why is `UNICODE_STRING.Length` in bytes, not characters?

Because NT strings are byte-counted. `Length` is the number of bytes in `Buffer`, excluding a
terminator; `MaximumLength` is the allocated size including room for a terminator. A string of 10
wide characters has `Length == 20`.

### Q: Where is the loader lock?

`LdrpLoaderLock` is a critical section in ntdll's data. It is held during `LdrLoadDll`,
`LdrUnloadDll`, thread attach/detach and `DllMain`. `LdrDisableThreadCalloutsForDll` exists so a DLL
can opt out of `DLL_THREAD_ATTACH`/`DETACH` and avoid taking the lock on every thread creation.

### Q: How does `LoadLibraryW` find the file?

Through the search order implemented in `LoadLibraryExW` and the loader's
`LdrpSearchPath`. The search order is: application directory, current directory (unless
`SafeDllSearchMode` moves it), system directory, 16-bit system directory, Windows directory, `PATH`.
Activation-context redirection can override it.

### Q: What is the difference between `RtlInitUnicodeString` and `RtlAnsiStringToUnicodeString`?

`RtlInitUnicodeString` points at a buffer you already have (no allocation, no copy).
`RtlAnsiStringToUnicodeString` converts and **allocates** a new buffer, which you must free with
`RtlFreeUnicodeString`. Use the former for literals and stack buffers, the latter for data you do
not own.

### Q: Where is the TEB, and why does `RtlGetLastWin32Error` use it?

The TEB (Thread Environment Block) is at `fs:[0]` on x86 and `gs:[0]` on x64. It holds the last
error value, the stack limits, the TLS slots and the exception chain. `RtlGetLastWin32Error` reads
`TEB->LastErrorValue`; `GetLastError` is a forwarder to it. That is why the error value is per
thread and why a context switch does not corrupt it.

### Q: Can I call `LdrLoadDll` instead of `LoadLibraryW`?

You can, but you lose the Win32 path resolution, the error mapping and the activation-context
handling. `LdrLoadDll` is one layer lower; use it only when you need to load a module by an NT path
or with `Ldr*`-specific flags.
