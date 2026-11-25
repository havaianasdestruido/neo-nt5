---
title: Library, loader, resource and diagnostics API
sidebar_position: 16
description: LoadLibrary and the DLL search order, GetProcAddress, module handles, resources, ToolHelp, FormatMessage, environment blocks and the console API.
---

The loader is the part of the system that turns a file into a mapped module, resolves imports,
runs initialisers, and answers `GetProcAddress`. In this tree it is split in two: the user-mode
loader (`base/ntdll/ldrapi.c`, `ldrinit.c`, `ldrsnap.c`, `ldrutil.c`) and the kernel32 wrappers that
turn names into paths.

## Loading a module

### `LoadLibraryW`

```c
HMODULE LoadLibraryW(LPCWSTR lpLibFileName);
```

Implementation: [`base/win32/client/module.c:94`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/win32/client/module.c#L94).
It is a one-line wrapper:

```c
    return LoadLibraryExW( lpwLibFileName, NULL, 0 );
```

and `LoadLibraryExW` (`:245`) is where the flags, the search path and the call to `LdrLoadDll`
(`base/ntdll/ldrapi.c:98`) live. The ANSI entry point at `:102` converts with
`Basep8BitStringToStaticUnicodeString` and forwards.

The documented search order, in the absence of `SafeDllSearchMode` changes and application
manifests, is:

```text
1. The directory the application was loaded from
2. The current directory
3. The 32-bit Windows system directory   (GetSystemDirectory)
4. The 16-bit Windows system directory   (System)
5. The Windows directory                 (GetWindowsDirectory)
6. The directories in PATH
```

`LoadLibraryExW` accepts flags that change this:

| Flag | Effect |
| --- | --- |
| `LOAD_WITH_ALTERED_SEARCH_PATH` | Search the directory of `lpLibFileName` first |
| `LOAD_LIBRARY_AS_DATAFILE` | Map as data, no `DllMain`, no imports resolved |
| `LOAD_LIBRARY_AS_DATAFILE_EXCLUSIVE` | Same, with exclusive access to the file |
| `LOAD_LIBRARY_AS_IMAGE_RESOURCE` | Map as an image, not as a DLL |
| `DONT_RESOLVE_DLL_REFERENCES` | Do not resolve imports or call `DllMain` |
| `LOAD_IGNORE_CODE_AUTHZ_LEVEL` | Do not check the code authorization level |

`LOAD_LIBRARY_AS_DATAFILE` is the standard way to read a resource out of a DLL without executing
its initialiser — useful for version information, icons and string tables in a file that may not
even be loadable as code.

### `GetProcAddress`

```c
FARPROC GetProcAddress(HMODULE hModule, LPCSTR lpProcName);
```

Implementation: [`base/win32/client/module.c:1430`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/win32/client/module.c#L1430).
Its own routine description contains two warnings worth quoting:

```c
    If the lpProcName parameter is an ordinal value and a function with
    the specified ordinal does not exist in the module, GetProcAddress
    can still return a non-NULL value.  In cases where the function may
    not exist, specify the function by name rather than ordinal value.

    Only use GetProcAddress to retrieve addresses of exported functions
    that belong to library modules.
```

- The name is **case sensitive** and must match the `.def` spelling, not the C identifier if the
  `.def` renames it.
- An ordinal is `MAKEINTRESOURCEA(n)` — the low word holds the ordinal, the high word is zero.
- `GetProcAddress` returns `NULL` both when the export is missing and when the export is a
  forwarder that fails to resolve. Check `GetLastError`.

### A correct dynamic-loading pattern

```c
#include <windows.h>
#include <stdio.h>

typedef DWORD (WINAPI *PFN_GETFINALPATHNAMEBYHANDLEW)(
    HANDLE, LPCWSTR, LPWSTR, DWORD);

int wmain(void)
{
    HMODULE hKernel32 = GetModuleHandleW(L"kernel32.dll");
    if (!hKernel32) { wprintf(L"kernel32 missing?\n"); return 1; }

    // Resolve by name, never by ordinal, and never cache a pointer across
    // a FreeLibrary of the module that owns it.
    PFN_GETFINALPATHNAMEBYHANDLEW pGetFinalPath =
        (PFN_GETFINALPATHNAMEBYHANDLEW)GetProcAddress(hKernel32, "GetFinalPathNameByHandleW");

    if (!pGetFinalPath) {
        wprintf(L"not available on this OS, error %lu\n", GetLastError());
        return 0;      // optional API: degrade gracefully
    }

    wprintf(L"resolved GetFinalPathNameByHandleW at %p\n", (void *)pGetFinalPath);
    return 0;
}
```

### Module handles and file names

| Function | Purpose | Implementation | Documentation |
| --- | --- | --- | --- |
| `GetModuleHandleW` | Handle for a loaded module, without loading | `module.c:1153` | [GetModuleHandleW](https://learn.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-getmodulehandlew) |
| `GetModuleHandleExW` | Handle with flags (`GET_MODULE_HANDLE_EX_FLAG_*`) | `module.c:1305` | [GetModuleHandleExW](https://learn.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-getmodulehandleexw) |
| `GetModuleFileNameW` | Path of a loaded module | `module.c:884` | [GetModuleFileNameW](https://learn.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-getmodulefilenamew) |
| `FreeLibrary` | Decrement the module reference count | `module.c:483` | [FreeLibrary](https://learn.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-freelibrary) |
| `FreeLibraryAndExitThread` | Free and exit without returning to freed code | `module.c:552` | [FreeLibraryAndExitThread](https://learn.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-freelibraryandexitthread) |

`GetModuleFileNameW` with `hModule == NULL` returns the executable's path. The buffer is
`MAX_PATH` characters in the common case; use `GetModuleFileNameW(NULL, buf, size)` and check for
truncation by comparing the return value to `size`.

`FreeLibraryAndExitThread` exists because a thread must not return into a module it just unloaded:
the return address would point into unmapped memory.

## Resources

| Function | Purpose | Implementation | Documentation |
| --- | --- | --- | --- |
| `FindResourceW` | Locate a resource by type/name/language | `module.c:2873` | [FindResourceW](https://learn.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-findresourcew) |
| `LoadResource` | Load the resource into memory | `module.c:2020` | [LoadResource](https://learn.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-loadresource) |
| `LockResource` | Pointer to the resource bytes | `module.c:2864` | [LockResource](https://learn.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-lockresource) |
| `SizeofResource` | Size in bytes | `module.c:2078` | [SizeofResource](https://learn.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-sizeofresource) |

```c
HRSRC   hRes  = FindResourceW(hModule, MAKEINTRESOURCEW(IDR_VERSION), RT_VERSION);
HGLOBAL hGlob = LoadResource(hModule, hRes);
DWORD   size  = SizeofResource(hModule, hRes);
LPVOID  p     = LockResource(hGlob);       // valid until the module is unloaded
```

`LockResource` does not allocate; it returns a pointer into the mapped image. That is why the
pointer is valid only while the module stays loaded.

## ToolHelp

The ToolHelp functions snapshot process, thread, module and heap state. They are the easiest way to
enumerate the system without the debug API.

| Function | Purpose | Implementation | Documentation |
| --- | --- | --- | --- |
| `CreateToolhelp32Snapshot` | Take a snapshot | `base/win32/client/toolhelp.c:102` | [CreateToolhelp32Snapshot](https://learn.microsoft.com/en-us/windows/win32/api/tlhelp32/nf-tlhelp32-createtoolhelp32snapshot) |
| `Process32FirstW` / `Process32NextW` | Walk processes | `toolhelp.c:735` | [Process32FirstW](https://learn.microsoft.com/en-us/windows/win32/api/tlhelp32/nf-tlhelp32-process32firstw) |
| `Thread32First` / `Thread32Next` | Walk threads | `toolhelp.c:1005` | [Thread32First](https://learn.microsoft.com/en-us/windows/win32/api/tlhelp32/nf-tlhelp32-thread32first) |
| `Module32FirstW` / `Module32NextW` | Walk modules of a process | `toolhelp.c:1157` | [Module32FirstW](https://learn.microsoft.com/en-us/windows/win32/api/tlhelp32/nf-tlhelp32-module32firstw) |

```c
#include <windows.h>
#include <tlhelp32.h>
#include <stdio.h>

int wmain(void)
{
    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hSnap == INVALID_HANDLE_VALUE) { wprintf(L"snapshot failed %lu\n", GetLastError()); return 1; }

    PROCESSENTRY32W pe = { sizeof(pe) };
    for (BOOL ok = Process32FirstW(hSnap, &pe); ok; ok = Process32NextW(hSnap, &pe)) {
        wprintf(L"%6lu  %ls\n", pe.th32ProcessID, pe.szExeFile);
    }
    CloseHandle(hSnap);
    return 0;
}
```

A snapshot is a **copy**, not a live view. A process that exits after the snapshot still appears in
the enumeration; a process created after it does not. For live notification use
`WaitForSingleObject` on a process handle or `WMI`/`ETW`.

## Error reporting

| Function | Purpose | Implementation | Documentation |
| --- | --- | --- | --- |
| `GetLastError` | Thread's last Win32 error | `base/win32/client/error.c:92` | [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) |
| `SetLastError` | Set it | `error.c:124` | [SetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-setlasterror) |
| `FormatMessageW` | Turn an error code into text | `base/win32/client/message.c:156` | [FormatMessageW](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-formatmessagew) |
| `RaiseException` | Raise a software exception | `base/win32/client/thread.c:1356` | [RaiseException](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-raiseexception) |

`BaseSetLastNTError` (`error.c:177`) is the internal bridge from `NTSTATUS` to `ERROR_*`; it calls
`RtlNtStatusToDosError` and then `SetLastError`. That is the function every Win32 wrapper uses when
it returns `FALSE`/`NULL` after a failed `Nt*` call.

```c
DWORD err = GetLastError();
LPWSTR msg = NULL;
DWORD n = FormatMessageW(
    FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
    NULL, err, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPWSTR)&msg, 0, NULL);
if (n) { wprintf(L"error %lu: %ls", err, msg); LocalFree(msg); }
```

## Environment and command line

| Function | Purpose | Implementation | Documentation |
| --- | --- | --- | --- |
| `GetCommandLineW` | The raw command line | `base/win32/client/process.c:5047` | [GetCommandLineW](https://learn.microsoft.com/en-us/windows/win32/api/processenv/nf-processenv-getcommandlinew) |
| `GetEnvironmentVariableW` | Read one variable | `process.c:5432` | [GetEnvironmentVariableW](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-getenvironmentvariablew) |
| `SetEnvironmentVariableW` | Write one variable | `process.c:5487` | [SetEnvironmentVariableW](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-setenvironmentvariablew) |
| `ExpandEnvironmentStringsW` | Substitute `%VAR%` | `process.c:5604` | [ExpandEnvironmentStringsW](https://learn.microsoft.com/en-us/windows/win32/api/processenv/nf-processenv-expandenvironmentstringsw) |
| `GetEnvironmentStringsW` | Whole environment block | `process.c` | [GetEnvironmentStringsW](https://learn.microsoft.com/en-us/windows/win32/api/processenv/nf-processenv-getenvironmentstringsw) |
| `FreeEnvironmentStringsW` | Free the block | `process.c` | [FreeEnvironmentStringsW](https://learn.microsoft.com/en-us/windows/win32/api/processenv/nf-processenv-freeenvironmentstringsw) |

`GetCommandLineW` returns a pointer to the process's command line, not a copy. The CRT's `argv`
parsing is separate and uses different quoting rules; `CommandLineToArgvW` (in `shell32`) is the
closest thing to a canonical parser.

## Console

`kernel32.src` exports the full console API — `AllocConsole` at line 11, `FreeConsole` at line 216,
`WriteConsoleW` at line 865, `GetConsoleMode` at line 279 and so on. **The implementations are not
present in `base/win32/client` in this checkout.** The export list is there, the source is not:

```bash
grep -n 'AllocConsole' base/win32/client/kernel32.src    # present in the export list
rg -n '^AllocConsole[[:space:]]*\(' base/win32            # no implementation found
```

That is a gap in the checkout, not a statement about the product. The console subsystem itself lives
in `windows/core/winsrv` and `base/subsys/csr`, and the client-side console API was historically
split between kernel32 and `crtdll`/`user32`. When documenting console behaviour for this tree, cite
the export list and the winsrv source rather than claiming an implementation path that is absent.

## Function reference table

| Function | Header | Implementation | Documentation |
| --- | --- | --- | --- |
| `LoadLibraryW` | `libloaderapi.h` | `base/win32/client/module.c:94` | [LoadLibraryW](https://learn.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibraryw) |
| `LoadLibraryExW` | `libloaderapi.h` | `base/win32/client/module.c:245` | [LoadLibraryExW](https://learn.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibraryexw) |
| `GetProcAddress` | `libloaderapi.h` | `base/win32/client/module.c:1430` | [GetProcAddress](https://learn.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) |
| `GetModuleHandleW` | `libloaderapi.h` | `base/win32/client/module.c:1153` | [GetModuleHandleW](https://learn.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-getmodulehandlew) |
| `GetModuleHandleExW` | `libloaderapi.h` | `base/win32/client/module.c:1305` | [GetModuleHandleExW](https://learn.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-getmodulehandleexw) |
| `GetModuleFileNameW` | `libloaderapi.h` | `base/win32/client/module.c:884` | [GetModuleFileNameW](https://learn.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-getmodulefilenamew) |
| `FreeLibrary` | `libloaderapi.h` | `base/win32/client/module.c:483` | [FreeLibrary](https://learn.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-freelibrary) |
| `FreeLibraryAndExitThread` | `libloaderapi.h` | `base/win32/client/module.c:552` | [FreeLibraryAndExitThread](https://learn.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-freelibraryandexitthread) |
| `FindResourceW` | `libloaderapi.h` | `base/win32/client/module.c:2873` | [FindResourceW](https://learn.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-findresourcew) |
| `LoadResource` | `libloaderapi.h` | `base/win32/client/module.c:2020` | [LoadResource](https://learn.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-loadresource) |
| `LockResource` | `libloaderapi.h` | `base/win32/client/module.c:2864` | [LockResource](https://learn.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-lockresource) |
| `SizeofResource` | `libloaderapi.h` | `base/win32/client/module.c:2078` | [SizeofResource](https://learn.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-sizeofresource) |
| `CreateToolhelp32Snapshot` | `tlhelp32.h` | `base/win32/client/toolhelp.c:102` | [CreateToolhelp32Snapshot](https://learn.microsoft.com/en-us/windows/win32/api/tlhelp32/nf-tlhelp32-createtoolhelp32snapshot) |
| `Process32FirstW` | `tlhelp32.h` | `base/win32/client/toolhelp.c:735` | [Process32FirstW](https://learn.microsoft.com/en-us/windows/win32/api/tlhelp32/nf-tlhelp32-process32firstw) |
| `Thread32First` | `tlhelp32.h` | `base/win32/client/toolhelp.c:1005` | [Thread32First](https://learn.microsoft.com/en-us/windows/win32/api/tlhelp32/nf-tlhelp32-thread32first) |
| `Module32FirstW` | `tlhelp32.h` | `base/win32/client/toolhelp.c:1157` | [Module32FirstW](https://learn.microsoft.com/en-us/windows/win32/api/tlhelp32/nf-tlhelp32-module32firstw) |
| `GetLastError` | `errhandlingapi.h` | `base/win32/client/error.c:92` | [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) |
| `SetLastError` | `errhandlingapi.h` | `base/win32/client/error.c:124` | [SetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-setlasterror) |
| `FormatMessageW` | `winbase.h` | `base/win32/client/message.c:156` | [FormatMessageW](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-formatmessagew) |
| `RaiseException` | `errhandlingapi.h` | `base/win32/client/thread.c:1356` | [RaiseException](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-raiseexception) |
| `GetCommandLineW` | `processenv.h` | `base/win32/client/process.c:5047` | [GetCommandLineW](https://learn.microsoft.com/en-us/windows/win32/api/processenv/nf-processenv-getcommandlinew) |
| `GetEnvironmentVariableW` | `winbase.h` | `base/win32/client/process.c:5432` | [GetEnvironmentVariableW](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-getenvironmentvariablew) |
| `SetEnvironmentVariableW` | `winbase.h` | `base/win32/client/process.c:5487` | [SetEnvironmentVariableW](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-setenvironmentvariablew) |
| `ExpandEnvironmentStringsW` | `processenv.h` | `base/win32/client/process.c:5604` | [ExpandEnvironmentStringsW](https://learn.microsoft.com/en-us/windows/win32/api/processenv/nf-processenv-expandenvironmentstringsw) |

## Frequently asked questions

### Q: Why is `LoadLibraryW` only one line long?

Because the work is in `LoadLibraryExW` (`module.c:245`), which handles the flags, the search path,
the activation-context redirection and the `LdrLoadDll` call. The split exists because
`LoadLibraryExW` has to support `LOAD_LIBRARY_AS_DATAFILE` and friends, which `LoadLibraryW` does
not expose.

### Q: Why can `GetProcAddress` return non-NULL for a missing ordinal?

Because the export directory can contain an ordinal entry that is a forwarder or a stub. The
documented safe practice is to look up by name. The tree's own routine description at
`base/win32/client/module.c:1430` says exactly this.

### Q: What is the difference between `GetModuleHandleW` and `LoadLibraryW`?

`GetModuleHandleW` returns a handle **only if the module is already loaded** and does not increment
the reference count. `LoadLibraryW` maps the module if it is not loaded and increments the count.
Calling `FreeLibrary` on a handle from `GetModuleHandleW` is a bug: you would decrement a count you
never incremented.

### Q: Why does `GetModuleFileNameW` return a path that may be short (8.3)?

Because that is how the loader recorded it. Use `GetLongPathNameW` to expand it, or
`GetFinalPathNameByHandleW` on a handle opened to the file. The tree's implementation at
`module.c:884` returns the loader's stored path.

### Q: How do I read a resource without loading the DLL?

`LoadLibraryExW(path, NULL, LOAD_LIBRARY_AS_DATAFILE)`, then `FindResourceW`, `LoadResource`,
`LockResource`. This skips `DllMain` and import resolution, which is essential for files that are
not loadable as code (wrong architecture, missing dependencies, or untrusted).

### Q: Is the console API implemented in this tree?

The exports are listed in `base/win32/client/kernel32.src` (from line 11 onward), but the
implementation files are **not** under `base/win32/client` in this checkout. Do not claim an
implementation path for `AllocConsole`/`WriteConsoleW` here. The subsystem side is
`windows/core/winsrv` and `base/subsys/csr`.

### Q: What is the difference between `RaiseException` and `ExitProcess`?

`RaiseException` (`thread.c:1356`) raises a software exception that can be caught by
`__try`/`__except` or a vectored handler; if uncaught it becomes an unhandled exception and the
process terminates. `ExitProcess` (`process.c:4617`) terminates immediately and cleanly. Use
`RaiseException` for recoverable errors, `ExitProcess` for deliberate shutdown.

### Q: Where does the loader live?

User mode: `base/ntdll/ldrapi.c` (`LdrLoadDll` at line 98, `LdrGetProcedureAddress` at line 1243),
`ldrinit.c`, `ldrsnap.c`, `ldrutil.c`. Kernel mode: the section and image-loading path in
`base/ntos/mm` and the `NtCreateSection`/`NtMapViewOfSection` services. See
[NTDLL runtime](/ntdll-api) and [PE loader](/pe-loader).

### Q: Why does `FormatMessageW` need `FORMAT_MESSAGE_IGNORE_INSERTS`?

Because some messages contain `%1`-style insert placeholders. Without the flag, `FormatMessageW`
will try to read insertion arguments from a `va_list` that you may not have supplied, which is
undefined behaviour. Pass the flag unless you are supplying the arguments.

### Q: How do I get the command line as `argc`/`argv`?

Either let the CRT provide `wmain(int, wchar_t **)`, or call `CommandLineToArgvW` (in `shell32`)
and free it with `LocalFree`. `GetCommandLineW` alone returns the raw string; the parsing rules for
quotes and backslashes are subtle and are documented with `CommandLineToArgvW`.
