---
title: "Processes and threads"
sidebar_position: 13
description: "CreateProcessW, OpenProcess, CreateThread, exit codes and process identity: official signatures, NT-tree locations and compiled examples."
---

# Processes and threads

Process and thread creation is where Win32 and the NT executive meet most directly. `CreateProcessW` is implemented in `base/win32/client/process.c` and ends in the process manager (`base/ntos/ps/create.c`): `NtCreateProcessEx` at line 884 and `NtCreateThread` at line 86. Handles returned by `CreateProcessW` are *both* owned by the caller and must be closed.

The examples start only `cmd.exe` children and terminate only the child they created.

This page covers **10 functions**: [`CreateProcessW`](#createprocessw), [`OpenProcess`](#openprocess), [`TerminateProcess`](#terminateprocess), [`GetExitCodeProcess`](#getexitcodeprocess), [`GetCurrentProcessId`](#getcurrentprocessid), [`GetCurrentProcess`](#getcurrentprocess), [`CreateThread`](#createthread), [`GetCurrentThreadId`](#getcurrentthreadid), [`GetProcessId`](#getprocessid), [`GetModuleFileNameW`](#getmodulefilenamew).

## Shared setup

Paste this block at the top of your source file, then one or more example functions below, then call them from `main`. The complete, compiled file is [processes.c](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/processes.c).

```c
/*
 * Win32 process and thread examples for the NEONT 5 documentation site.
 *
 * Build with MinGW-w64 or zig cc (any Windows target):
 *     zig cc -target x86_64-windows-gnu -std=c11 -Wall -Wextra -Werror processes.c -o processes.exe -lkernel32
 * Build with MSVC:
 *     cl /nologo /W4 /WX processes.c
 *
 * The examples start only harmless child processes (cmd.exe) and never terminate
 * processes that the example did not create.
 */
#define UNICODE
#define _UNICODE
#include <windows.h>
#include <stdio.h>
#include <wchar.h>
```

## Functions

## CreateProcessW

Creates a new process and its primary thread. The new process runs in the security context of the calling process. If the calling process is impersonating another user, the new process uses the token for the calling process, not the impersonation token. To run the new process in the security context of the user represented by the impersonation token, use the [CreateProcessAsUser](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-createprocessasusera) or [CreateProcessWithLogonW](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-createprocesswithlogonw) function.

| Attribute | Value |
| --- | --- |
| Header | `processthreadsapi.h` (include `Windows.h on Windows Server 2003, Windows Vista, Windows 7, Windows Server 2008  Windows Server 2008 R2`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | CreateProcessW (Unicode) and CreateProcessA (ANSI) |
| Official reference | [CreateProcessW function (processthreadsapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-createprocessw) |
| In this tree | [`base/win32/client/process.c:4326`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/process.c#L4326) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
WINBOOL WINAPI CreateProcessW(
    LPCWSTR lpApplicationName,
    LPWSTR lpCommandLine,
    LPSECURITY_ATTRIBUTES lpProcessAttributes,
    LPSECURITY_ATTRIBUTES lpThreadAttributes,
    WINBOOL bInheritHandles,
    DWORD dwCreationFlags,
    LPVOID lpEnvironment,
    LPCWSTR lpCurrentDirectory,
    LPSTARTUPINFOW lpStartupInfo,
    LPPROCESS_INFORMATION lpProcessInformation
);
```

**Return value.** If the function succeeds, the return value is nonzero. If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Tested example** — `example_CreateProcessW` in [`processes.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/processes.c):

```c
static void example_CreateProcessW(void)
{
    STARTUPINFOW si;
    PROCESS_INFORMATION pi;
    /* lpCommandLine must be writable, so use a local array rather than a string literal. */
    wchar_t cmd[] = L"cmd.exe /c exit 7";

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    if (!CreateProcessW(NULL, cmd, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        wprintf(L"CreateProcessW failed: %lu\n", GetLastError());
        return;
    }
    wprintf(L"Started process %lu (thread %lu)\n", pi.dwProcessId, pi.dwThreadId);
    WaitForSingleObject(pi.hProcess, INFINITE);
    CloseHandle(pi.hThread);     /* both handles must be closed by the creator */
    CloseHandle(pi.hProcess);
}
```

## OpenProcess

Opens an existing local process object.

| Attribute | Value |
| --- | --- |
| Header | `processthreadsapi.h` (include `Windows.h on Windows Server 2003, Windows Vista, Windows 7, Windows Server 2008  Windows Server 2008 R2`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [OpenProcess function (processthreadsapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-openprocess) |
| In this tree | [`base/win32/client/process.c:4513`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/process.c#L4513) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
_WIN32_WINNT_WIN10 HANDLE WINAPI OpenProcess(
    DWORD dwDesiredAccess,
    WINBOOL bInheritHandle,
    DWORD dwProcessId
);
```

**Return value.** If the function succeeds, the return value is an open handle to the specified process. If the function fails, the return value is NULL. To get extended error information, call [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Tested example** — `example_OpenProcess` in [`processes.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/processes.c):

```c
static void example_OpenProcess(void)
{
    /* Open our own process with the least privilege that answers the question. */
    HANDLE self = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, GetCurrentProcessId());
    if (self != NULL) {
        wprintf(L"Opened own process handle\n");
        CloseHandle(self);
    } else {
        wprintf(L"OpenProcess failed: %lu\n", GetLastError());
    }
}
```

## TerminateProcess

Terminates the specified process and all of its threads.

| Attribute | Value |
| --- | --- |
| Header | `processthreadsapi.h` (include `Windows.h on Windows Server 2003, Windows Vista, Windows 7, Windows Server 2008  Windows Server 2008 R2`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [TerminateProcess function (processthreadsapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-terminateprocess) |
| In this tree | [`base/win32/fusion/dll/whistler/termproc.c:10`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/fusion/dll/whistler/termproc.c#L10) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
WINBOOL WINAPI TerminateProcess(
    HANDLE hProcess,
    UINT uExitCode
);
```

**Return value.** If the function succeeds, the return value is nonzero. If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Tested example** — `example_TerminateProcess` in [`processes.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/processes.c):

```c
static void example_TerminateProcess(void)
{
    STARTUPINFOW si;
    PROCESS_INFORMATION pi;
    wchar_t cmd[] = L"cmd.exe /c ping -n 30 127.0.0.1 >nul";

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    if (!CreateProcessW(NULL, cmd, NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi))
        return;
    /* Only terminate a process you created. Exit code 1 is what the caller chooses. */
    if (TerminateProcess(pi.hProcess, 1))
        wprintf(L"Terminated child process %lu\n", pi.dwProcessId);
    WaitForSingleObject(pi.hProcess, 5000);
    CloseHandle(pi.hThread);
    CloseHandle(pi.hProcess);
}
```

## GetExitCodeProcess

Retrieves the termination status of the specified process.

| Attribute | Value |
| --- | --- |
| Header | `processthreadsapi.h` (include `Windows.h on Windows Server 2003, Windows Vista, Windows 7, Windows Server 2008  Windows Server 2008 R2`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [GetExitCodeProcess function (processthreadsapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-getexitcodeprocess) |
| In this tree | [`base/win32/client/process.c:4782`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/process.c#L4782) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
WINBOOL WINAPI GetExitCodeProcess(
    HANDLE hProcess,
    LPDWORD lpExitCode
);
```

**Return value.** If the function succeeds, the return value is nonzero. If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Tested example** — `example_GetExitCodeProcess` in [`processes.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/processes.c):

```c
static void example_GetExitCodeProcess(void)
{
    STARTUPINFOW si;
    PROCESS_INFORMATION pi;
    DWORD code = 0;
    wchar_t cmd[] = L"cmd.exe /c exit 7";

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    if (!CreateProcessW(NULL, cmd, NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi))
        return;
    WaitForSingleObject(pi.hProcess, INFINITE);
    /* STILL_ACTIVE (259) would mean the process has not exited yet. */
    if (GetExitCodeProcess(pi.hProcess, &code))
        wprintf(L"Child exit code: %lu\n", code);
    CloseHandle(pi.hThread);
    CloseHandle(pi.hProcess);
}
```

## GetCurrentProcessId

Retrieves the process identifier of the calling process.

| Attribute | Value |
| --- | --- |
| Header | `processthreadsapi.h` (include `Windows.h on Windows Server 2003, Windows Vista, Windows 7, Windows Server 2008  Windows Server 2008 R2`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [GetCurrentProcessId function (processthreadsapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-getcurrentprocessid) |
| In this tree | [`base/win32/client/process.c:6097`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/process.c#L6097) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
DWORD WINAPI GetCurrentProcessId(
    VOID
);
```

**Return value.** The return value is the process identifier of the calling process.

**Tested example** — `example_GetCurrentProcessId` in [`processes.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/processes.c):

```c
static void example_GetCurrentProcessId(void)
{
    wprintf(L"PID of this process: %lu\n", GetCurrentProcessId());
}
```

## GetCurrentProcess

Retrieves a pseudo handle for the current process.

| Attribute | Value |
| --- | --- |
| Header | `processthreadsapi.h` (include `Windows.h on Windows Server 2003, Windows Vista, Windows 7, Windows Server 2008  Windows Server 2008 R2`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [GetCurrentProcess function (processthreadsapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-getcurrentprocess) |
| In this tree | [`base/win32/client/process.c:6063`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/process.c#L6063) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
endif HANDLE WINAPI GetCurrentProcess(
    VOID
);
```

**Return value.** The return value is a pseudo handle to the current process.

**Tested example** — `example_GetCurrentProcess` in [`processes.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/processes.c):

```c
static void example_GetCurrentProcess(void)
{
    /* The pseudo-handle is always (HANDLE)-1 and must NOT be passed to CloseHandle. */
    HANDLE self = GetCurrentProcess();
    DWORD code = 0;
    if (GetExitCodeProcess(self, &code) && code == STILL_ACTIVE)
        wprintf(L"This process is still running\n");
}

static DWORD WINAPI worker_thread(LPVOID arg)
{
    LONG *counter = (LONG *)arg;
    InterlockedIncrement(counter);
    return 0;
}
```

## CreateThread

Creates a thread to execute within the virtual address space of the calling process. To create a thread that runs in the virtual address space of another process, use the [CreateRemoteThread](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-createremotethread) function.

| Attribute | Value |
| --- | --- |
| Header | `processthreadsapi.h` (include `Windows.h on Windows Server 2003, Windows Vista, Windows 7, Windows Server 2008  Windows Server 2008 R2`) |
| Library | Kernel32.lib; WindowsPhoneCore.lib on Windows Phone 8.1 (DLL `Kernel32.dll; KernelBase.dll on Windows Phone 8.1`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [CreateThread function (processthreadsapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-createthread) |
| In this tree | [`base/win32/client/thread.c:28`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/thread.c#L28) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
endif HANDLE WINAPI CreateThread(
    LPSECURITY_ATTRIBUTES lpThreadAttributes,
    SIZE_T dwStackSize,
    LPTHREAD_START_ROUTINE lpStartAddress,
    LPVOID lpParameter,
    DWORD dwCreationFlags,
    LPDWORD lpThreadId
);
```

**Return value.** If the function succeeds, the return value is a handle to the new thread. If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Tested example** — `example_CreateThread` in [`processes.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/processes.c):

```c
static void example_CreateThread(void)
{
    LONG counter = 0;
    DWORD tid = 0;
    /* Pass the thread routine and its argument; the thread starts running immediately. */
    HANDLE t = CreateThread(NULL, 0, worker_thread, &counter, 0, &tid);
    if (t == NULL) {
        wprintf(L"CreateThread failed: %lu\n", GetLastError());
        return;
    }
    WaitForSingleObject(t, INFINITE);
    CloseHandle(t);
    wprintf(L"Worker thread %lu incremented the counter to %ld\n", tid, counter);
}
```

## GetCurrentThreadId

Retrieves the thread identifier of the calling thread.

| Attribute | Value |
| --- | --- |
| Header | `processthreadsapi.h` (include `Windows.h on Windows Server 2003, Windows Vista, Windows 7, Windows Server 2008  Windows Server 2008 R2`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [GetCurrentThreadId function (processthreadsapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-getcurrentthreadid) |
| In this tree | [`base/win32/client/thread.c:1089`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/thread.c#L1089) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
DWORD WINAPI GetCurrentThreadId(
    VOID
);
```

**Return value.** The return value is the thread identifier of the calling thread.

**Tested example** — `example_GetCurrentThreadId` in [`processes.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/processes.c):

```c
static void example_GetCurrentThreadId(void)
{
    wprintf(L"Thread id: %lu\n", GetCurrentThreadId());
}
```

## GetProcessId

Retrieves the process identifier of the specified process.

| Attribute | Value |
| --- | --- |
| Header | `processthreadsapi.h` (include `Windows.h on Windows Server 2003, Windows Vista, Windows 7, Windows Server 2008  Windows Server 2008 R2`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows Vista, Windows XP with SP1 [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [GetProcessId function (processthreadsapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-getprocessid) |
| In this tree | [`base/win32/client/process.c:6126`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/process.c#L6126) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
DWORD WINAPI GetProcessId(
    HANDLE Process
);
```

**Return value.** If the function succeeds, the return value is the process identifier. If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Tested example** — `example_GetProcessId` in [`processes.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/processes.c):

```c
static void example_GetProcessId(void)
{
    /* GetProcessId returns the PID of a process from its handle (needs PROCESS_QUERY_LIMITED_INFORMATION). */
    HANDLE self = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, GetCurrentProcessId());
    if (self != NULL) {
        wprintf(L"GetProcessId: %lu\n", GetProcessId(self));
        CloseHandle(self);
    }
}
```

## GetModuleFileNameW

Retrieves the fully qualified path for the file that contains the specified module. The module must have been loaded by the current process. To locate the file for a module that was loaded by another process, use the [GetModuleFileNameEx](https://learn.microsoft.com/en-us/windows/win32/api/psapi/nf-psapi-getmodulefilenameexa) function.

| Attribute | Value |
| --- | --- |
| Header | `libloaderapi.h` (include `Windows.h`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | GetModuleFileNameW (Unicode) and GetModuleFileNameA (ANSI) |
| Official reference | [GetModuleFileNameW function (libloaderapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-getmodulefilenamew) |
| In this tree | [`base/win32/client/module.c:882`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/module.c#L882) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
DWORD WINAPI GetModuleFileNameW(
    HMODULE hModule,
    LPWSTR lpFilename,
    DWORD nSize
);
```

**Return value.** If the function succeeds, the return value is the length of the string that is copied to the buffer, in characters, not including the terminating null character. If the buffer is too small to hold the module name, the string is truncated to *nSize* characters including the terminating null character, the function returns *nSize*, and the function sets the last error to **ERROR_INSUFFICIENT_BUFFER**. **Windows XP:  **If the buffer is too small to hold the module name, the function returns *nSize* and the last error code is not modified. If *nSize* is zero, the return value is zero and the last error code is not modified.

**Tested example** — `example_GetModuleFileNameW` in [`processes.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/processes.c):

```c
static void example_GetModuleFileNameW(void)
{
    wchar_t path[MAX_PATH];
    /* NULL means the executable that started this process. */
    DWORD n = GetModuleFileNameW(NULL, path, MAX_PATH);
    if (n > 0 && n < MAX_PATH)
        wprintf(L"Executable: %ls\n", path);
}
```

## Build and test

Compile for an x86_64 Windows target with warnings treated as errors (run it on Windows; the examples are compiled here, not executed):

```sh
zig cc -target x86_64-windows-gnu -std=c11 -Wall -Wextra -Werror processes.c -o processes.exe -lkernel32 -ladvapi32 -lws2_32 -luser32 -lgdi32 -lshell32
```

With MSVC from a Developer Command Prompt: `cl /nologo /W4 /WX processes.c`. MSVC is not run in this checkout; the file is verified only with the zig/clang Windows targets.

## Frequently asked questions

### Q: Why do I need to close both pi.hProcess and pi.hThread?

Each is a separate kernel object with its own reference. `CreateProcessW` returns a handle to the process and to its primary thread; leaking either keeps the object alive. The example closes both.

### Q: What does GetExitCodeProcess return while the child is still running?

`STILL_ACTIVE` (259). A child can legitimately exit with 259 too, so wait on the handle first, as the example does, rather than polling the exit code.

### Q: Is GetCurrentProcess a handle I must close?

No. It returns a pseudo-handle, always `(HANDLE)-1`, that means "this process". Passing it to `CloseHandle` is an error.

### Q: Where is the process manager in this tree?

Under `base/ntos/ps` (process/thread services, see [Kernel and executive](/kernel)). The Win32 wrappers that call it are in `base/win32/client/process.c` and `thread.c`.
