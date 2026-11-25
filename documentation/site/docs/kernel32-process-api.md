---
title: Process, thread and synchronization API
sidebar_position: 14
description: CreateProcess, CreateThread, TLS, the wait functions, critical sections, events, mutexes, semaphores, timers and job objects — semantics, examples and the kernel services behind them.
---

Process and thread creation in the Win32 API are **policy layers over the executive**: they build
the environment, the parameter block, the section and the initial context, then call
`NtCreateProcessEx` and `NtCreateThread`. Synchronization objects are thin wrappers around kernel
dispatcher objects (`KEVENT`, `KMUTANT`, `KSEMAPHORE`, `KTIMER`) plus a wait that blocks in the
kernel.

This page documents the calling surface, the semantics that are easy to get wrong, and the exact
implementation points in this checkout.

## Processes

### `CreateProcessW`

```c
BOOL CreateProcessW(
    LPCWSTR               lpApplicationName,
    LPWSTR                lpCommandLine,
    LPSECURITY_ATTRIBUTES lpProcessAttributes,
    LPSECURITY_ATTRIBUTES lpThreadAttributes,
    BOOL                  bInheritHandles,
    DWORD                 dwCreationFlags,
    LPVOID                lpEnvironment,
    LPCWSTR               lpCurrentDirectory,
    LPSTARTUPINFOW        lpStartupInfo,
    LPPROCESS_INFORMATION lpProcessInformation
    );
```

Implementation: [`base/win32/client/process.c:4328`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/win32/client/process.c#L4328).
The ANSI entry point `CreateProcessA` is at `:1001`. The two calls that actually create kernel
objects are visible in the same file:

```c
Status = NtCreateProcessEx(          // process.c:3527
    &ProcessHandle,
    DesiredAccess,
    ObjectAttributes,
    ParentProcess,
    Flags,
    SectionHandle,
    DebugPort,
    ExceptionPort,
    JobMemberLevel
    );

Status = NtCreateThread(             // process.c:3915
    &ThreadHandle,
    ...);
```

`NtCreateProcessEx` is implemented at
[`base/ntos/ps/create.c:884`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/ps/create.c#L884),
and its own description is blunt about the layering:

```c
NtCreateProcessEx(
    OUT PHANDLE ProcessHandle,
    IN ACCESS_MASK DesiredAccess,
    IN POBJECT_ATTRIBUTES ObjectAttributes OPTIONAL,
    IN HANDLE ParentProcess OPTIONAL,
    IN ULONG Flags,
    IN HANDLE SectionHandle OPTIONAL,
    IN HANDLE DebugPort OPTIONAL,
    IN HANDLE ExceptionPort OPTIONAL,
    IN ULONG JobMemberLevel
    )
```

The `SectionHandle` is the executable image, mapped by `NtCreateSection` (`base/ntos/mm/creasect.c:136`).
The `DebugPort` and `ExceptionPort` are the two LPC ports a debugger or the unhandled-exception
filter uses; `CREATE_PROCESS_DEBUG_EVENT` and thevectored exception machinery hang off them.

### `STARTUPINFO` and `PROCESS_INFORMATION`

```c
typedef struct _STARTUPINFOW {
    DWORD  cb;
    LPWSTR lpReserved;
    LPWSTR lpDesktop;
    LPWSTR lpTitle;
    DWORD  dwX, dwY, dwXSize, dwYSize, dwXCountChars, dwYCountChars;
    DWORD  dwFillAttribute, dwFlags;
    WORD   wShowWindow, cbReserved2;
    LPBYTE lpReserved2;
    HANDLE hStdInput, hStdOutput, hStdError;
} STARTUPINFOW, *LPSTARTUPINFOW;

typedef struct _PROCESS_INFORMATION {
    HANDLE hProcess;
    HANDLE hThread;
    DWORD  dwProcessId;
    DWORD  dwThreadId;
} PROCESS_INFORMATION, *LPPROCESS_INFORMATION;
```

The tree's declarations are in `public/sdk/inc/winbase.h` and `processthreadsapi.h`. Three rules:

- `cb` must be `sizeof(STARTUPINFOW)`. A zero `cb` makes the call fail or read garbage.
- The `hStd*` handles are only used when `STARTF_USESTDHANDLES` is set **and** `bInheritHandles`
  is `TRUE`. Both conditions are required; setting one without the other silently does nothing.
- The returned handles must both be closed. Closing only `hProcess` leaks the thread handle.

### A complete process-launch example

```c
#include <windows.h>
#include <stdio.h>

int wmain(void)
{
    STARTUPINFOW si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // CreateProcessW may write back into the command line, so it must be writable.
    wchar_t cmdline[] = L"cmd.exe /c dir C:\\ > C:\\neo-dir.txt";

    BOOL ok = CreateProcessW(
        NULL,                 // lpApplicationName: derive from the command line
        cmdline,              // must be writable
        NULL, NULL,           // default security, no inheritance
        FALSE,                // bInheritHandles
        CREATE_NO_WINDOW,     // dwCreationFlags
        NULL,                 // inherit the parent environment
        NULL,                 // inherit the current directory
        &si, &pi);

    if (!ok) {
        wprintf(L"CreateProcessW failed, error %lu\n", GetLastError());
        return 1;
    }

    // Do not wait on the thread handle unless you specifically need the
    // thread's exit code; the process handle is the usual choice.
    if (WaitForSingleObject(pi.hProcess, 30000) != WAIT_OBJECT_0) {
        wprintf(L"child did not exit in 30 seconds\n");
    }

    DWORD exitCode = STILL_ACTIVE;
    GetExitCodeProcess(pi.hProcess, &exitCode);
    wprintf(L"child exit code: %lu\n", exitCode);

    CloseHandle(pi.hThread);
    CloseHandle(pi.hProcess);
    return 0;
}
```

### Creation flags worth knowing

| Flag | Effect | Gotcha |
| --- | --- | --- |
| `CREATE_SUSPENDED` | Primary thread starts suspended | You must `ResumeThread` or the process never runs |
| `CREATE_NEW_CONSOLE` | New console instead of inheriting | Ignored with `DETACHED_PROCESS` |
| `CREATE_NO_WINDOW` | No console window for a console child | Not a security boundary |
| `CREATE_NEW_PROCESS_GROUP` | New process group for `GenerateConsoleCtrlEvent` | Ctrl+C is not delivered to the group |
| `DEBUG_PROCESS` | Caller becomes the debugger for the child | Child's exceptions arrive as debug events |
| `DEBUG_ONLY_THIS_PROCESS` | Debug this child only, not grandchildren | Needed to avoid debugging the whole tree |
| `CREATE_UNICODE_ENVIRONMENT` | `lpEnvironment` is UTF-16 | Required if you pass a wide block |
| `CREATE_BREAKAWAY_FROM_JOB` | Escape the parent's job | Fails if the job disallows breakaway |

### Process access rights

`OpenProcess` (`base/win32/client/process.c:4515`) takes an access mask. The rights that matter:

| Right | Allows |
| --- | --- |
| `PROCESS_TERMINATE` | `TerminateProcess` |
| `PROCESS_CREATE_THREAD` | `CreateRemoteThread` |
| `PROCESS_VM_OPERATION` | `VirtualAllocEx`, `WriteProcessMemory` |
| `PROCESS_VM_READ` | `ReadProcessMemory` |
| `PROCESS_VM_WRITE` | `WriteProcessMemory` (without `VM_OPERATION`) |
| `PROCESS_QUERY_INFORMATION` | `GetExitCodeProcess`, token queries |
| `PROCESS_QUERY_LIMITED_INFORMATION` | A subset usable by lower-privileged callers |
| `SYNCHRONIZE` | `WaitForSingleObject` |
| `PROCESS_ALL_ACCESS` | Everything |

`OpenProcess` returning `NULL` with `ERROR_ACCESS_DENIED` is the normal result for a process in
another session or a protected process. `PROCESS_QUERY_LIMITED_INFORMATION` exists precisely so
that image name and command line can still be queried in that case.

### Pseudo-handles

```c
HANDLE GetCurrentProcess(void);   // returns (HANDLE)-1
HANDLE GetCurrentThread(void);    // returns (HANDLE)-2
```

They are constants, not real handles: `CloseHandle` on them fails, and they cannot be inherited.
`DuplicateHandle` with `DUPLICATE_CLOSE_SOURCE` is the only way to obtain a real handle. The
implementations are at `process.c:6065` and `thread.c:1057`.

## Threads

### `CreateThread`

```c
HANDLE CreateThread(
    LPSECURITY_ATTRIBUTES lpThreadAttributes,
    SIZE_T                dwStackSize,
    LPTHREAD_START_ROUTINE lpStartAddress,
    LPVOID                lpParameter,
    DWORD                 dwCreationFlags,
    LPDWORD               lpThreadId
    );
```

The implementation is a one-liner at
[`base/win32/client/thread.c:30`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/win32/client/thread.c#L30):

```c
    return CreateRemoteThread( NtCurrentProcess(),
                               lpThreadAttributes,
                               dwStackSize,
                               lpStartAddress,
                               lpParameter,
                               dwCreationFlags,
                               lpThreadId
                             );
```

`CreateRemoteThread` does the work: it builds a `CONTEXT`, an `INITIAL_TEB`, and calls
`NtCreateThread`. `dwStackSize == 0` means "use the image's default stack size", which is why
`CreateThread` with a zero stack does not mean a tiny stack.

### Thread creation flags

| Flag | Effect |
| --- | --- |
| `0` | Thread runs immediately |
| `CREATE_SUSPENDED` | Thread starts suspended; `ResumeThread` to start |
| `STACK_SIZE_PARAM_IS_A_RESERVATION` | `dwStackSize` is the reserve, not the commit |
| `CREATE_IGNORE_SYSTEM_DEFAULT` | Do not apply the system default stack size |

### A worker thread with clean shutdown

```c
#include <windows.h>
#include <stdio.h>

static volatile LONG g_stop = 0;

static DWORD WINAPI Worker(LPVOID param)
{
    HANDLE hStop = (HANDLE)param;
    while (!g_stop) {
        // Do a bounded unit of work, then check the stop event without blocking.
        if (WaitForSingleObject(hStop, 0) == WAIT_OBJECT_0) {
            break;
        }
        Sleep(50);
    }
    return 0;
}

int wmain(void)
{
    HANDLE hStop = CreateEventW(NULL, TRUE, FALSE, NULL);   // manual reset
    HANDLE hThread = CreateThread(NULL, 0, Worker, hStop, 0, NULL);
    if (!hThread) {
        wprintf(L"CreateThread failed, error %lu\n", GetLastError());
        CloseHandle(hStop);
        return 1;
    }

    Sleep(200);
    InterlockedExchange(&g_stop, 1);
    SetEvent(hStop);

    WaitForSingleObject(hThread, INFINITE);

    DWORD code = 0;
    GetExitCodeThread(hThread, &code);
    wprintf(L"worker exit code: %lu\n", code);

    CloseHandle(hThread);
    CloseHandle(hStop);
    return 0;
}
```

### Thread-local storage

| Function | Purpose | Implementation | Documentation |
| --- | --- | --- | --- |
| `TlsAlloc` | Allocate a TLS index | `thread.c:2164` | [TlsAlloc](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlsalloc) |
| `TlsGetValue` | Read the calling thread's slot | `thread.c:2242` | [TlsGetValue](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlsgetvalue) |
| `TlsSetValue` | Write the calling thread's slot | `thread.c:2324` | [TlsSetValue](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlssetvalue) |
| `TlsFree` | Release the index | `thread.c:2415` | [TlsFree](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlsfree) |

`TlsGetValue` clears the last error on success, so the documented pattern is:

```c
LPVOID p = TlsGetValue(index);
if (p == NULL && GetLastError() != ERROR_SUCCESS) {
    // real failure
}
```

The slot values are per-thread and are **not** initialised for new threads; `TlsSetValue` in
`DllMain` on `DLL_THREAD_ATTACH` is the usual way to give each thread a valid value.

### Thread access rights

| Right | Allows |
| --- | --- |
| `THREAD_TERMINATE` | `TerminateThread` |
| `THREAD_SUSPEND_RESUME` | `SuspendThread` / `ResumeThread` |
| `THREAD_GET_CONTEXT` / `THREAD_SET_CONTEXT` | `GetThreadContext` / `SetThreadContext` |
| `THREAD_QUERY_INFORMATION` | Exit code, token, times |
| `SYNCHRONIZE` | Wait on the thread |

`TerminateThread` (`thread.c:908`) is dangerous: the target thread does not unwind, does not
release held critical sections, and does not run DLL thread-detach notifications. Prefer a
cooperative stop.

## Synchronization

### The object table

| Object | Create | Signal | Reset | Wait behaviour |
| --- | --- | --- | --- | --- |
| Event (manual reset) | `CreateEventW` (`synch.c:170`) | `SetEvent` (`:390`) | `ResetEvent` (`:433`) | Wakes **all** waiters |
| Event (auto reset) | same | `SetEvent` | automatic after one waiter | Wakes **one** waiter |
| Mutex | `CreateMutexW` (`:909`) | `ReleaseMutex` (`:1119`) | ownership | Wakes one waiter; abandoned mutex returns `WAIT_ABANDONED` |
| Semaphore | `CreateSemaphoreW` (`:583`) | `ReleaseSemaphore` (`:797`) | count reaches zero | Wakes when count is nonzero |
| Waitable timer | `CreateWaitableTimerW` (`:1757`) | `SetWaitableTimer` (`:1906`) | manual or auto | Wakes at due time |
| Thread / process | `CreateThread` / `CreateProcess` | exit | n/a | Signalled when terminated |
| File / console input | `CreateFileW` | data available | read | Signalled when readable |
| Change notification | `FindFirstChangeNotificationW` | change | reset | Signalled on change |

### `WaitForSingleObject`

[`base/win32/client/synch.c:1170`](https://learn.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-waitforsingleobject)
is a policy wrapper over `NtWaitForSingleObject` (`base/ntos/ob/obwait.c:286`). Its return values:

| Return | Meaning |
| --- | --- |
| `WAIT_OBJECT_0` (0) | Object was signalled |
| `WAIT_ABANDONED` (0x80) | Mutex was abandoned by a terminated thread; ownership granted, state may be inconsistent |
| `WAIT_TIMEOUT` (0x102) | Interval elapsed, object not signalled |
| `WAIT_FAILED` (0xFFFFFFFF) | Invalid handle or access denied; call `GetLastError` |

`WAIT_ABANDONED` is a **success** in the sense that you own the mutex, but a **warning** that the
previous owner died while holding it. The documented response is to assume the protected state is
corrupt and reinitialise it.

```c
DWORD r = WaitForSingleObject(hMutex, 5000);
switch (r) {
case WAIT_OBJECT_0:
    // normal ownership
    break;
case WAIT_ABANDONED:
    // ownership granted, but the previous holder did not release cleanly
    break;
case WAIT_TIMEOUT:
    // someone else holds it
    break;
case WAIT_FAILED:
    // bad handle; GetLastError
    break;
}
```

### `WaitForMultipleObjects`

`WaitForMultipleObjects` (`synch.c:1390`) waits on up to `MAXIMUM_WAIT_OBJECTS` (64) handles. The
return value is `WAIT_OBJECT_0 + index` for the signalled handle, or `WAIT_TIMEOUT`/`WAIT_FAILED`.
Two modes:

- `bWaitAll = TRUE`: waits for all of them, return value is `WAIT_OBJECT_0`.
- `bWaitAll = FALSE`: returns the index of the first signalled one.

For more than 64 objects, either create a thread per group or use `RegisterWaitForSingleObject`
(`thread.c:3120`) / `CreateTimerQueueTimer`. The 64 limit is a hard API contract.

### Critical sections

A `CRITICAL_SECTION` is a user-mode lock with a kernel event behind it. It is faster than a mutex
for short, non-recursive critical regions because the uncontended path is a single interlocked
operation.

| Function | Purpose | Implementation | Documentation |
| --- | --- | --- | --- |
| `InitializeCriticalSection` | Initialise the structure | `synch.c:29` | [InitializeCriticalSection](https://learn.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-initializecriticalsection) |
| `InitializeCriticalSectionAndSpinCount` | Initialise with a spin count | `synch.c:69` | [InitializeCriticalSectionAndSpinCount](https://learn.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-initializecriticalsectionandspincount) |
| `EnterCriticalSection` | Acquire (recursive) | `synch.c` | [EnterCriticalSection](https://learn.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-entercriticalsection) |
| `TryEnterCriticalSection` | Acquire without blocking | `synch.c` | [TryEnterCriticalSection](https://learn.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-tryentercriticalsection) |
| `LeaveCriticalSection` | Release | `synch.c` | [LeaveCriticalSection](https://learn.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-leavecriticalsection) |
| `DeleteCriticalSection` | Free the kernel event | `synch.c` | [DeleteCriticalSection](https://learn.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-deletecriticalsection) |

```c
CRITICAL_SECTION g_lock;
InitializeCriticalSection(&g_lock);

EnterCriticalSection(&g_lock);
// ... shared state ...
LeaveCriticalSection(&g_lock);

DeleteCriticalSection(&g_lock);
```

Rules:

- A critical section is **recursive**: the owning thread can enter it again.
- Never `LeaveCriticalSection` from a different thread than the one that entered.
- Never delete a critical section while a thread is inside it.
- `EnterCriticalSection` can raise an exception if the lock is corrupted; `InitializeCriticalSectionAndSpinCount` is the safer initialiser on multiprocessor systems.

### Mutex versus critical section

| Concern | `CRITICAL_SECTION` | Mutex (`CreateMutexW`) |
| --- | --- | --- |
| Scope | Process only | Can be named and shared across processes |
| Recursive | Yes | Yes, for the owning thread |
| Timeout | No (`TryEnterCriticalSection` only) | Yes |
| Abandoned detection | No | `WAIT_ABANDONED` |
| Kernel object | Hidden event created on contention | Real object with a handle |
| Cost | Very low uncontended | Higher; always a kernel transition |

Use a critical section for process-local data, a mutex for cross-process locking or when a timeout
is required.

### Events and the auto/manual distinction

```c
HANDLE hEvt = CreateEventW(NULL, FALSE, FALSE, NULL);   // auto-reset, initially non-signalled
SetEvent(hEvt);        // wakes exactly one waiter, then resets automatically

HANDLE hManual = CreateEventW(NULL, TRUE, FALSE, NULL); // manual-reset
SetEvent(hManual);     // wakes every current and future waiter until ResetEvent
```

A common bug: using a manual-reset event for a work item and having two workers both wake for the
same item. Use auto-reset for work distribution, manual-reset for "state changed" broadcasts.

## Job objects

`CreateJobObjectW` (`base/win32/client/job.c:61`), `SetInformationJobObject` (`:293`) and
`AssignProcessToJobObject` (`:179`) group processes so limits apply to the whole tree:

| Information class | Effect |
| --- | --- |
| `JobObjectBasicLimitInformation` | Affinity, priority class, per-process/user time limits |
| `JobObjectExtendedLimitInformation` | Memory limits, active process limit, breakaway flags |
| `JobObjectAssociateCompletionPortInformation` | Completion port for job events |
| `JobObjectBasicAccountingInformation` | Total/user/kernel time and page faults |

```c
HANDLE hJob = CreateJobObjectW(NULL, NULL);
JOBOBJECT_EXTENDED_LIMIT_INFORMATION jeli = {0};
jeli.BasicLimitInformation.LimitFlags = JOB_OBJECT_LIMIT_KILL_ON_JOB_CLOSE;
SetInformationJobObject(hJob, JobObjectExtendedLimitInformation, &jeli, sizeof(jeli));

// Assign each child after CreateProcess.
AssignProcessToJobObject(hJob, pi.hProcess);
```

`JOB_OBJECT_LIMIT_KILL_ON_JOB_CLOSE` is the standard way to guarantee children die with the parent
— the tree's own `job.c` contains the implementation and the `psjob.c` kernel side is in
`base/ntos/ps`.

## Function reference table

| Function | Header | Implementation | Documentation |
| --- | --- | --- | --- |
| `CreateProcessW` | `processthreadsapi.h` | `base/win32/client/process.c:4328` | [CreateProcessW](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-createprocessw) |
| `OpenProcess` | `processthreadsapi.h` | `base/win32/client/process.c:4515` | [OpenProcess](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-openprocess) |
| `TerminateProcess` | `processthreadsapi.h` | `base/win32/client/process.c:4713` | [TerminateProcess](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-terminateprocess) |
| `ExitProcess` | `processthreadsapi.h` | `base/win32/client/process.c:4617` | [ExitProcess](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-exitprocess) |
| `GetExitCodeProcess` | `processthreadsapi.h` | `base/win32/client/process.c:4784` | [GetExitCodeProcess](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-getexitcodeprocess) |
| `GetCurrentProcess` | `processthreadsapi.h` | `base/win32/client/process.c:6065` | [GetCurrentProcess](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-getcurrentprocess) |
| `GetCurrentProcessId` | `processthreadsapi.h` | `base/win32/client/process.c:6099` | [GetCurrentProcessId](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-getcurrentprocessid) |
| `GetProcessId` | `processthreadsapi.h` | `base/win32/client/process.c:6128` | [GetProcessId](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-getprocessid) |
| `CreateThread` | `processthreadsapi.h` | `base/win32/client/thread.c:30` | [CreateThread](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-createthread) |
| `OpenThread` | `processthreadsapi.h` | `base/win32/client/thread.c:485` | [OpenThread](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-openthread) |
| `GetCurrentThread` | `processthreadsapi.h` | `base/win32/client/thread.c:1057` | [GetCurrentThread](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-getcurrentthread) |
| `GetCurrentThreadId` | `processthreadsapi.h` | `base/win32/client/thread.c:1091` | [GetCurrentThreadId](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-getcurrentthreadid) |
| `SuspendThread` | `processthreadsapi.h` | `base/win32/client/thread.c:1237` | [SuspendThread](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-suspendthread) |
| `ResumeThread` | `processthreadsapi.h` | `base/win32/client/thread.c:1290` | [ResumeThread](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-resumethread) |
| `TerminateThread` | `processthreadsapi.h` | `base/win32/client/thread.c:908` | [TerminateThread](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-terminatethread) |
| `GetExitCodeThread` | `processthreadsapi.h` | `base/win32/client/thread.c:999` | [GetExitCodeThread](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-getexitcodethread) |
| `SetThreadPriority` | `processthreadsapi.h` | `base/win32/client/thread.c:593` | [SetThreadPriority](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-setthreadpriority) |
| `GetThreadContext` | `processthreadsapi.h` | `base/win32/client/thread.c:1120` | [GetThreadContext](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-getthreadcontext) |
| `SetThreadContext` | `processthreadsapi.h` | `base/win32/client/thread.c:1180` | [SetThreadContext](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-setthreadcontext) |
| `TlsAlloc` | `processthreadsapi.h` | `base/win32/client/thread.c:2164` | [TlsAlloc](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlsalloc) |
| `TlsFree` | `processthreadsapi.h` | `base/win32/client/thread.c:2415` | [TlsFree](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlsfree) |
| `TlsGetValue` | `processthreadsapi.h` | `base/win32/client/thread.c:2242` | [TlsGetValue](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlsgetvalue) |
| `TlsSetValue` | `processthreadsapi.h` | `base/win32/client/thread.c:2324` | [TlsSetValue](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlssetvalue) |
| `QueueUserWorkItem` | `processthreadsapi.h` | `base/win32/client/thread.c:3421` | [QueueUserWorkItem](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-queueuserworkitem) |
| `RegisterWaitForSingleObject` | `processthreadsapi.h` | `base/win32/client/thread.c:3120` | [RegisterWaitForSingleObject](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-registerwaitforsingleobject) |
| `CreateEventW` | `synchapi.h` | `base/win32/client/synch.c:170` | [CreateEventW](https://learn.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-createeventw) |
| `SetEvent` | `synchapi.h` | `base/win32/client/synch.c:390` | [SetEvent](https://learn.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-setevent) |
| `ResetEvent` | `synchapi.h` | `base/win32/client/synch.c:433` | [ResetEvent](https://learn.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-resetevent) |
| `CreateMutexW` | `synchapi.h` | `base/win32/client/synch.c:909` | [CreateMutexW](https://learn.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-createmutexw) |
| `ReleaseMutex` | `synchapi.h` | `base/win32/client/synch.c:1119` | [ReleaseMutex](https://learn.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-releasemutex) |
| `CreateSemaphoreW` | `synchapi.h` | `base/win32/client/synch.c:583` | [CreateSemaphoreW](https://learn.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-createsemaphorew) |
| `ReleaseSemaphore` | `synchapi.h` | `base/win32/client/synch.c:797` | [ReleaseSemaphore](https://learn.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-releasesemaphore) |
| `CreateWaitableTimerW` | `synchapi.h` | `base/win32/client/synch.c:1757` | [CreateWaitableTimerW](https://learn.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-createwaitabletimerw) |
| `SetWaitableTimer` | `synchapi.h` | `base/win32/client/synch.c:1906` | [SetWaitableTimer](https://learn.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-setwaitabletimer) |
| `WaitForSingleObject` | `synchapi.h` | `base/win32/client/synch.c:1170` | [WaitForSingleObject](https://learn.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-waitforsingleobject) |
| `WaitForSingleObjectEx` | `synchapi.h` | `base/win32/client/synch.c:1221` | [WaitForSingleObjectEx](https://learn.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-waitforsingleobjectex) |
| `WaitForMultipleObjects` | `synchapi.h` | `base/win32/client/synch.c:1390` | [WaitForMultipleObjects](https://learn.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-waitformultipleobjects) |
| `InitializeCriticalSection` | `synchapi.h` | `base/win32/client/synch.c:29` | [InitializeCriticalSection](https://learn.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-initializecriticalsection) |
| `InitializeCriticalSectionAndSpinCount` | `synchapi.h` | `base/win32/client/synch.c:69` | [InitializeCriticalSectionAndSpinCount](https://learn.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-initializecriticalsectionandspincount) |
| `CreateJobObjectW` | `jobapi.h` | `base/win32/client/job.c:61` | [CreateJobObjectW](https://learn.microsoft.com/en-us/windows/win32/api/jobapi/nf-jobapi-createjobobjectw) |
| `SetInformationJobObject` | `jobapi.h` | `base/win32/client/job.c:293` | [SetInformationJobObject](https://learn.microsoft.com/en-us/windows/win32/api/jobapi/nf-jobapi-setinformationjobobject) |
| `AssignProcessToJobObject` | `jobapi.h` | `base/win32/client/job.c:179` | [AssignProcessToJobObject](https://learn.microsoft.com/en-us/windows/win32/api/jobapi/nf-jobapi-assignprocesstojobobject) |

## Frequently asked questions

### Q: Why does `CreateProcessW` need a writable command line?

Because the function may insert a null terminator between the module name and the arguments while
parsing. Passing a string literal is undefined behaviour and can fault on a read-only page. The
implementation at `base/win32/client/process.c:4328` documents the parameter as `[in, out]`.

### Q: What is the difference between `ExitProcess` and `TerminateProcess`?

`ExitProcess` (`process.c:4617`) is the process terminating itself: DLLs receive
`DLL_PROCESS_DETACH`, the C runtime flushes streams, and atexit handlers run. `TerminateProcess`
(`process.c:4713`) is an asynchronous kill from outside: nothing is unwound, DLLs get no
notification, and handles are closed by the kernel when the process object is destroyed. It is the
right tool for an unresponsive child, not for normal shutdown.

### Q: Why does `WaitForSingleObject` return `WAIT_ABANDONED`?

Because the thread that owned the mutex terminated without releasing it. The mutex is signalled and
ownership is granted to you, but the state it protected may be inconsistent. Treat it as "you own
it, but reinitialise the protected data". See the wait table above.

### Q: Can I wait on a thread from inside its own `DllMain`?

No. `DllMain` holds the loader lock; waiting on another thread that is itself waiting for the loader
lock deadlocks. This is the canonical `DllMain` restriction, and the tree's loader
(`base/ntdll/ldrinit.c`, `ldrsnap.c`) is where the lock is taken.

### Q: Why does `CreateThread` with `dwStackSize = 0` still get a big stack?

Because zero means "use the default from the executable image", which is typically 1 MiB reserved.
`STACK_SIZE_PARAM_IS_A_RESERVATION` changes whether `dwStackSize` is a reservation or a commit; it
does not change the zero-means-default rule.

### Q: How do I make sure child processes die when my process is killed?

Put them in a job object with `JOB_OBJECT_LIMIT_KILL_ON_JOB_CLOSE`. The tree implements this in
`base/win32/client/job.c` and `base/ntos/ps/psjob.c`. `CreateJobObjectW` with a name also lets
unrelated processes join the same job.

### Q: What is the maximum number of handles `WaitForMultipleObjects` accepts?

`MAXIMUM_WAIT_OBJECTS`, which is 64. For more, split the wait across threads or use
`RegisterWaitForSingleObject` / a thread pool.

### Q: Where are the kernel dispatcher objects implemented?

Events in `base/ntos/ex/event.c` (`NtCreateEvent` at line 188), mutexes in `base/ntos/ex/mutant.c`,
semaphores in `base/ntos/ex/semphore.c`, timers in `base/ntos/ex/timer.c`, and the wait machinery in
`base/ntos/ke/wait.c`. The Win32 wrappers in `base/win32/client/synch.c` build the
`OBJECT_ATTRIBUTES` and call the corresponding `Nt*` service.

### Q: Is `CRITICAL_SECTION` a kernel object?

No. The `CRITICAL_SECTION` structure lives in your process's memory. It contains a lock count, an
owner thread, and a handle to a kernel event that is created **lazily on first contention**. That is
why it is fast when uncontended and why deleting it without `DeleteCriticalSection` leaks a kernel
event.

### Q: How do I read another process's memory?

`ReadProcessMemory` (`base/win32/client/tmem.c` family) needs `PROCESS_VM_READ` on the handle, and
`VirtualQueryEx`/`VirtualAllocEx` need `PROCESS_VM_OPERATION`/`PROCESS_QUERY_INFORMATION`. The
kernel path is `NtReadVirtualMemory` in `base/ntos/mm`. See
[Memory API](/kernel32-memory-api).
