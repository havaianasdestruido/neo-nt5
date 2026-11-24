---
title: "Synchronization"
sidebar_position: 14
description: "Events, mutexes, semaphores, WaitFor* functions, critical sections and SRW locks: official signatures, NT-tree locations and compiled examples."
---

# Synchronization

Synchronization primitives in Win32 are kernel dispatcher objects (events, mutexes, semaphores) plus user-mode fast paths (critical sections and SRW locks). A wait on a dispatcher object ends in the kernel wait code: `KeWaitForSingleObject` is defined in `base/ntos/ke/wait.c`, and the mutex object behind `CreateMutexW` is `NtCreateMutant` in `base/ntos/ex/mutant.c`.

Critical sections and SRW locks are designed to avoid a kernel transition when uncontended. Choose a dispatcher object only when you need cross-process or timed waits.

This page covers **17 functions**: [`CreateEventW`](#createeventw), [`SetEvent`](#setevent), [`ResetEvent`](#resetevent), [`WaitForSingleObject`](#waitforsingleobject), [`WaitForMultipleObjects`](#waitformultipleobjects), [`Sleep`](#sleep), [`CreateMutexW`](#createmutexw), [`ReleaseMutex`](#releasemutex), [`CreateSemaphoreW`](#createsemaphorew), [`ReleaseSemaphore`](#releasesemaphore), [`InitializeCriticalSection`](#initializecriticalsection), [`EnterCriticalSection`](#entercriticalsection), [`LeaveCriticalSection`](#leavecriticalsection), [`DeleteCriticalSection`](#deletecriticalsection), [`InitializeSRWLock`](#initializesrwlock), [`AcquireSRWLockExclusive`](#acquiresrwlockexclusive), [`ReleaseSRWLockExclusive`](#releasesrwlockexclusive).

## Shared setup

Paste this block at the top of your source file, then one or more example functions below, then call them from `main`. The complete, compiled file is [synchronization.c](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/synchronization.c).

```c
/*
 * Win32 synchronization examples for the NEONT 5 documentation site.
 *
 * Build with MinGW-w64 or zig cc (any Windows target):
 *     zig cc -target x86_64-windows-gnu -std=c11 -Wall -Wextra -Werror synchronization.c -o synchronization.exe -lkernel32
 * Build with MSVC:
 *     cl /nologo /W4 /WX synchronization.c
 *
 * Each example creates its own objects and closes them before returning.
 */
#define UNICODE
#define _UNICODE
#include <windows.h>
#include <stdio.h>
#include <wchar.h>

/* Shared state for the critical-section and SRW-lock examples below. */
static CRITICAL_SECTION g_lock;
static SRWLOCK g_srw = SRWLOCK_INIT;
static LONG g_shared = 0;
```

## Functions

## CreateEventW

Creates or opens a named or unnamed event object. To specify an access mask for the object, use the [CreateEventEx](https://learn.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-createeventexa) function.

| Attribute | Value |
| --- | --- |
| Header | `synchapi.h` (include `Windows.h on Windows Server 2003, Windows Vista, Windows 7, Windows Server 2008  Windows Server 2008 R2`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | CreateEventW (Unicode) and CreateEventA (ANSI) |
| Official reference | [CreateEventW function (synchapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-createeventw) |
| In this tree | [`base/win32/client/synch.c:168`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/synch.c#L168) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
HANDLE WINAPI CreateEventW(
    LPSECURITY_ATTRIBUTES lpEventAttributes,
    WINBOOL bManualReset,
    WINBOOL bInitialState,
    LPCWSTR lpName
);
```

**Return value.** If the function succeeds, the return value is a handle to the event object. If the named event object existed before the function call, the function returns a handle to the existing object and [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **ERROR_ALREADY_EXISTS**. If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Tested example** — `example_CreateEventW` in [`synchronization.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/synchronization.c):

```c
static void example_CreateEventW(void)
{
    /* Manual-reset event, initially non-signaled, unnamed. */
    HANDLE ev = CreateEventW(NULL, TRUE, FALSE, NULL);
    if (ev == NULL) {
        wprintf(L"CreateEventW failed: %lu\n", GetLastError());
        return;
    }
    wprintf(L"Event created\n");
    CloseHandle(ev);
}
```

## SetEvent

Sets the specified event object to the signaled state.

| Attribute | Value |
| --- | --- |
| Header | `synchapi.h` (include `Windows.h on Windows Server 2003, Windows Vista, Windows 7, Windows Server 2008  Windows Server 2008 R2`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [SetEvent function (synchapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-setevent) |
| In this tree | [`base/win32/client/synch.c:389`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/synch.c#L389) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
WINBOOL WINAPI SetEvent(
    HANDLE hEvent
);
```

**Return value.** If the function succeeds, the return value is nonzero. If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Tested example** — `example_SetEvent` in [`synchronization.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/synchronization.c):

```c
static void example_SetEvent(void)
{
    HANDLE ev = CreateEventW(NULL, TRUE, FALSE, NULL);
    if (ev == NULL) return;
    /* Signal the event: waiters are released (all of them for a manual-reset event). */
    if (SetEvent(ev) && WaitForSingleObject(ev, 0) == WAIT_OBJECT_0)
        wprintf(L"Event is signaled\n");
    CloseHandle(ev);
}
```

## ResetEvent

Sets the specified event object to the nonsignaled state.

| Attribute | Value |
| --- | --- |
| Header | `synchapi.h` (include `Windows.h on Windows Server 2003, Windows Vista, Windows 7, Windows Server 2008  Windows Server 2008 R2`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [ResetEvent function (synchapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-resetevent) |
| In this tree | [`base/win32/client/synch.c:432`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/synch.c#L432) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
WINBOOL WINAPI ResetEvent(
    HANDLE hEvent
);
```

**Return value.** If the function succeeds, the return value is nonzero. If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Tested example** — `example_ResetEvent` in [`synchronization.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/synchronization.c):

```c
static void example_ResetEvent(void)
{
    HANDLE ev = CreateEventW(NULL, TRUE, TRUE, NULL);   /* starts signaled */
    if (ev == NULL) return;
    ResetEvent(ev);                                     /* back to non-signaled */
    if (WaitForSingleObject(ev, 0) == WAIT_TIMEOUT)
        wprintf(L"Event is non-signaled after ResetEvent\n");
    CloseHandle(ev);
}
```

## WaitForSingleObject

Waits until the specified object is in the signaled state or the time-out interval elapses. To enter an alertable wait state, use the [WaitForSingleObjectEx](https://learn.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-waitforsingleobjectex) function. To wait for multiple objects, use [WaitForMultipleObjects](https://learn.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-waitformultipleobjects).

| Attribute | Value |
| --- | --- |
| Header | `synchapi.h` (include `Windows.h on Windows Server 2003, Windows Vista, Windows 7, Windows Server 2008  Windows Server 2008 R2`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [WaitForSingleObject function (synchapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-waitforsingleobject) |
| In this tree | [`base/win32/client/synch.c:1169`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/synch.c#L1169) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
DWORD WINAPI WaitForSingleObject(
    HANDLE hHandle,
    DWORD dwMilliseconds
);
```

**Return value.** If the function succeeds, the return value indicates the event that caused the function to return. It can be one of the following values. Return code/value Description **WAIT_ABANDONED** 0x00000080L The specified object is a mutex object that was not released by the thread that owned the mutex object before the owning thread terminated. Ownership of the mutex object is granted to the calling thread and the mutex state is set to nonsignaled.

**Tested example** — `example_WaitForSingleObject` in [`synchronization.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/synchronization.c):

```c
static void example_WaitForSingleObject(void)
{
    HANDLE ev = CreateEventW(NULL, FALSE, TRUE, NULL);  /* auto-reset, signaled */
    if (ev == NULL) return;
    /* Wait up to 1000 ms. WAIT_OBJECT_0 = acquired, WAIT_TIMEOUT = still not signaled. */
    DWORD r = WaitForSingleObject(ev, 1000);
    if (r == WAIT_OBJECT_0)
        wprintf(L"Acquired the event (auto-reset clears it)\n");
    else if (r == WAIT_TIMEOUT)
        wprintf(L"Timed out\n");
    else
        wprintf(L"Wait failed: %lu\n", GetLastError());
    CloseHandle(ev);
}
```

## WaitForMultipleObjects

Waits until one or all of the specified objects are in the signaled state or the time-out interval elapses. To enter an alertable wait state, use the [WaitForMultipleObjectsEx](https://learn.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-waitformultipleobjectsex) function.

| Attribute | Value |
| --- | --- |
| Header | `synchapi.h` (include `Windows.h`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [WaitForMultipleObjects function (synchapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-waitformultipleobjects) |
| In this tree | [`base/win32/client/synch.c:1389`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/synch.c#L1389) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
/* prototype not found in the bundled headers; see the official reference */
```

**Return value.** If the function succeeds, the return value indicates the event that caused the function to return. It can be one of the following values. (Note that **WAIT_OBJECT_0** is defined as 0 and **WAIT_ABANDONED_0** is defined as 0x00000080L.) Return code/value Description **WAIT_OBJECT_0** to (**WAIT_OBJECT_0** + *nCount*– 1) If *bWaitAll* is **TRUE**, a return value within the specified range indicates that the state of all specified objects is signaled.

**Tested example** — `example_WaitForMultipleObjects` in [`synchronization.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/synchronization.c):

```c
static void example_WaitForMultipleObjects(void)
{
    HANDLE handles[2];
    handles[0] = CreateEventW(NULL, TRUE, FALSE, NULL);
    handles[1] = CreateEventW(NULL, TRUE, TRUE, NULL);  /* the second one is already signaled */
    if (!handles[0] || !handles[1]) return;

    /* bWaitAll = FALSE: returns when any one is signaled. The index is WAIT_OBJECT_0 + i. */
    DWORD r = WaitForMultipleObjects(2, handles, FALSE, 1000);
    if (r >= WAIT_OBJECT_0 && r < WAIT_OBJECT_0 + 2)
        wprintf(L"Object %lu signaled\n", r - WAIT_OBJECT_0);
    CloseHandle(handles[0]);
    CloseHandle(handles[1]);
}
```

## Sleep

Suspends the execution of the current thread until the time-out interval elapses. To enter an alertable wait state, use the [SleepEx](https://learn.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-sleepex) function.

| Attribute | Value |
| --- | --- |
| Header | `synchapi.h` (include `Windows.h on Windows Vista, Windows 7, Windows Server 2008  Windows Server 2008 R2`) |
| Library | Kernel32.lib; WindowsPhoneCore.lib on Windows Phone 8.1 (DLL `Kernel32.dll; KernelBase.dll on Windows Phone 8.1`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [Sleep function (synchapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-sleep) |
| In this tree | [`base/win32/client/synch.c:1593`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/synch.c#L1593) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
VOID WINAPI Sleep(
    DWORD dwMilliseconds
);
```

**Return value.** See the official reference.

**Tested example** — `example_Sleep` in [`synchronization.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/synchronization.c):

```c
static void example_Sleep(void)
{
    /* Sleep yields the rest of this thread's time slice; it is not a precise timer. */
    wprintf(L"Sleeping 100 ms\n");
    Sleep(100);
}
```

## CreateMutexW

Creates or opens a named or unnamed mutex object. To specify an access mask for the object, use the [CreateMutexEx](https://learn.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-createmutexexa) function.

| Attribute | Value |
| --- | --- |
| Header | `synchapi.h` (include `Windows.h on Windows Server 2003, Windows Vista, Windows 7, Windows Server 2008  Windows Server 2008 R2`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | CreateMutexW (Unicode) and CreateMutexA (ANSI) |
| Official reference | [CreateMutexW function (synchapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-createmutexw) |
| In this tree | [`base/win32/client/synch.c:907`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/synch.c#L907) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
HANDLE WINAPI CreateMutexW(
    LPSECURITY_ATTRIBUTES lpMutexAttributes,
    WINBOOL bInitialOwner,
    LPCWSTR lpName
);
```

**Return value.** If the function succeeds, the return value is a handle to the newly created mutex object. If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Tested example** — `example_CreateMutexW` in [`synchronization.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/synchronization.c):

```c
static void example_CreateMutexW(void)
{
    /* A named mutex makes the application single-instance across processes. */
    HANDLE m = CreateMutexW(NULL, FALSE, L"Local\\NEONT5-DocsExample");
    if (m == NULL) return;
    if (GetLastError() == ERROR_ALREADY_EXISTS)
        wprintf(L"Another instance already owns this name\n");
    else
        wprintf(L"Created the named mutex\n");
    CloseHandle(m);
}
```

## ReleaseMutex

Releases ownership of the specified mutex object.

| Attribute | Value |
| --- | --- |
| Header | `synchapi.h` (include `Windows.h on Windows Server 2003, Windows Vista, Windows 7, Windows Server 2008  Windows Server 2008 R2`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [ReleaseMutex function (synchapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-releasemutex) |
| In this tree | [`base/win32/client/synch.c:1118`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/synch.c#L1118) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
WINBOOL WINAPI ReleaseMutex(
    HANDLE hMutex
);
```

**Return value.** If the function succeeds, the return value is nonzero. If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Tested example** — `example_ReleaseMutex` in [`synchronization.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/synchronization.c):

```c
static void example_ReleaseMutex(void)
{
    HANDLE m = CreateMutexW(NULL, TRUE, NULL);   /* the creator owns it initially */
    if (m == NULL) return;
    /* Only the owning thread may release; releasing from another thread fails. */
    if (ReleaseMutex(m))
        wprintf(L"Mutex released\n");
    CloseHandle(m);
}
```

## CreateSemaphoreW

Creates or opens a named or unnamed semaphore object. To specify an access mask for the object, use the [CreateSemaphoreEx](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-createsemaphoreexa) function.

| Attribute | Value |
| --- | --- |
| Header | `synchapi.h` (include `Windows.h`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | CreateSemaphoreW (Unicode) and CreateSemaphoreA (ANSI) |
| Official reference | [CreateSemaphoreW function (synchapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-createsemaphorew) |
| In this tree | [`base/win32/client/synch.c:581`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/synch.c#L581) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
/* prototype not found in the bundled headers; see the official reference */
```

**Return value.** If the function succeeds, the return value is a handle to the semaphore object. If the named semaphore object existed before the function call, the function returns a handle to the existing object and [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **ERROR_ALREADY_EXISTS**. If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Tested example** — `example_CreateSemaphoreW` in [`synchronization.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/synchronization.c):

```c
static void example_CreateSemaphoreW(void)
{
    /* Initial count 2, maximum count 4. */
    HANDLE s = CreateSemaphoreW(NULL, 2, 4, NULL);
    if (s == NULL) return;
    wprintf(L"Semaphore created (initial 2, max 4)\n");
    CloseHandle(s);
}
```

## ReleaseSemaphore

Increases the count of the specified semaphore object by a specified amount.

| Attribute | Value |
| --- | --- |
| Header | `synchapi.h` (include `Windows.h on Windows Server 2003, Windows Vista, Windows 7, Windows Server 2008  Windows Server 2008 R2`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [ReleaseSemaphore function (synchapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-releasesemaphore) |
| In this tree | [`base/win32/client/synch.c:796`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/synch.c#L796) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
WINBOOL WINAPI ReleaseSemaphore(
    HANDLE hSemaphore,
    LONG lReleaseCount,
    LPLONG lpPreviousCount
);
```

**Return value.** If the function succeeds, the return value is nonzero. If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Tested example** — `example_ReleaseSemaphore` in [`synchronization.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/synchronization.c):

```c
static void example_ReleaseSemaphore(void)
{
    LONG previous = -1;
    HANDLE s = CreateSemaphoreW(NULL, 0, 4, NULL);
    if (s == NULL) return;
    /* Raise the count by 1; lpPreviousCount receives the count before the call. */
    if (ReleaseSemaphore(s, 1, &previous))
        wprintf(L"Previous count was %ld\n", previous);
    CloseHandle(s);
}
```

## InitializeCriticalSection

Initializes a critical section object.

| Attribute | Value |
| --- | --- |
| Header | `synchapi.h` (include `Windows.h on Windows Server 2003, Windows Vista, Windows 7, Windows Server 2008  Windows Server 2008 R2`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [InitializeCriticalSection function (synchapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-initializecriticalsection) |
| In this tree | [`base/win32/client/synch.c:28`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/synch.c#L28) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
define SYNCHRONIZATION_BARRIER_FLAGS_NO_DELETE 0x04 VOID WINAPI InitializeCriticalSection(
    LPCRITICAL_SECTION lpCriticalSection
);
```

**Return value.** This function does not return a value. **Windows Server 2003 and Windows XP:** In low memory situations, **InitializeCriticalSection** can raise a **STATUS_NO_MEMORY** exception. Starting with Windows Vista, this exception was eliminated and **InitializeCriticalSection** always succeeds, even in low memory situations.

**Tested example** — `example_InitializeCriticalSection` in [`synchronization.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/synchronization.c):

```c
static void example_InitializeCriticalSection(void)
{
    /* Must be initialized before the first EnterCriticalSection. */
    InitializeCriticalSection(&g_lock);
    wprintf(L"Critical section initialized\n");
    DeleteCriticalSection(&g_lock);
}
```

## EnterCriticalSection

Waits for ownership of the specified critical section object. The function returns when the calling thread is granted ownership.

| Attribute | Value |
| --- | --- |
| Header | `synchapi.h` (include `Windows.h on Windows Server 2003, Windows Vista, Windows 7, Windows Server 2008  Windows Server 2008 R2`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [EnterCriticalSection function (synchapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-entercriticalsection) |
| In this tree | No definition extracted by the generator from `base/win32`, `base/screg`, `net/sockets`, `windows/core`, `base/ntos`, `base/ntdll`, `base/subsys`, `base/fs` or `net/published`. A fixed-string search found call sites only, so the implementation is either outside this checkout or reached through a macro. Search the [generated index](/reference/) by name. |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
VOID WINAPI EnterCriticalSection(
    LPCRITICAL_SECTION lpCriticalSection
);
```

**Return value.** This function does not return a value. This function can raise **EXCEPTION_POSSIBLE_DEADLOCK**, also known as **STATUS_POSSIBLE_DEADLOCK**, if a wait operation on the critical section times out. The timeout interval is specified by the following registry value: **HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Session Manager**&#92;**CriticalSectionTimeout**. Do not handle a possible deadlock exception; instead, debug the application.

**Tested example** — `example_EnterCriticalSection` in [`synchronization.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/synchronization.c):

```c
static void example_EnterCriticalSection(void)
{
    InitializeCriticalSection(&g_lock);
    EnterCriticalSection(&g_lock);     /* blocks until the lock is free; recursive for the same thread */
    g_shared++;
    LeaveCriticalSection(&g_lock);
    DeleteCriticalSection(&g_lock);
    wprintf(L"Shared value: %ld\n", g_shared);
}
```

## LeaveCriticalSection

Releases ownership of the specified critical section object.

| Attribute | Value |
| --- | --- |
| Header | `synchapi.h` (include `Windows.h on Windows Server 2003, Windows Vista, Windows 7, Windows Server 2008  Windows Server 2008 R2`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [LeaveCriticalSection function (synchapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-leavecriticalsection) |
| In this tree | No definition extracted by the generator from `base/win32`, `base/screg`, `net/sockets`, `windows/core`, `base/ntos`, `base/ntdll`, `base/subsys`, `base/fs` or `net/published`. A fixed-string search found call sites only, so the implementation is either outside this checkout or reached through a macro. Search the [generated index](/reference/) by name. |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
VOID WINAPI LeaveCriticalSection(
    LPCRITICAL_SECTION lpCriticalSection
);
```

**Return value.** See the official reference.

**Tested example** — `example_LeaveCriticalSection` in [`synchronization.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/synchronization.c):

```c
static void example_LeaveCriticalSection(void)
{
    InitializeCriticalSection(&g_lock);
    EnterCriticalSection(&g_lock);
    /* Every Enter must be matched by exactly one Leave, even on early return paths. */
    LeaveCriticalSection(&g_lock);
    DeleteCriticalSection(&g_lock);
}
```

## DeleteCriticalSection

Releases all resources used by an unowned critical section object.

| Attribute | Value |
| --- | --- |
| Header | `synchapi.h` (include `Windows.h on Windows Server 2003, Windows Vista, Windows 7, Windows Server 2008  Windows Server 2008 R2`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [DeleteCriticalSection function (synchapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-deletecriticalsection) |
| In this tree | No definition extracted by the generator from `base/win32`, `base/screg`, `net/sockets`, `windows/core`, `base/ntos`, `base/ntdll`, `base/subsys`, `base/fs` or `net/published`. A fixed-string search found call sites only, so the implementation is either outside this checkout or reached through a macro. Search the [generated index](/reference/) by name. |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
VOID WINAPI DeleteCriticalSection(
    LPCRITICAL_SECTION lpCriticalSection
);
```

**Return value.** See the official reference.

**Tested example** — `example_DeleteCriticalSection` in [`synchronization.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/synchronization.c):

```c
static void example_DeleteCriticalSection(void)
{
    InitializeCriticalSection(&g_lock);
    /* Delete only when no thread holds or waits on the section. */
    DeleteCriticalSection(&g_lock);
    wprintf(L"Critical section deleted\n");
}
```

## InitializeSRWLock

Initialize a slim reader/writer (SRW) lock.

| Attribute | Value |
| --- | --- |
| Header | `synchapi.h` (include `Windows.h on Windows 7, Windows Server 2008  Windows Server 2008 R2`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows Vista [desktop apps / UWP apps] |
| Minimum server | Windows Server 2008 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [InitializeSRWLock function (synchapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-initializesrwlock) |
| In this tree | No definition extracted by the generator from `base/win32`, `base/screg`, `net/sockets`, `windows/core`, `base/ntos`, `base/ntdll`, `base/subsys`, `base/fs` or `net/published`. A fixed-string search found call sites only, so the implementation is either outside this checkout or reached through a macro. Search the [generated index](/reference/) by name. |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
define CREATE_EVENT_INITIAL_SET 0x2 VOID WINAPI InitializeSRWLock(
    PSRWLOCK SRWLock
);
```

**Return value.** See the official reference.

**Tested example** — `example_InitializeSRWLock` in [`synchronization.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/synchronization.c):

```c
static void example_InitializeSRWLock(void)
{
    /* Static initialization with SRWLOCK_INIT is equivalent; the call is for dynamic objects. */
    InitializeSRWLock(&g_srw);
    wprintf(L"SRW lock initialized\n");
}
```

## AcquireSRWLockExclusive

Acquires a slim reader/writer (SRW) lock in exclusive mode.

| Attribute | Value |
| --- | --- |
| Header | `synchapi.h` (include `Windows.h on Windows 7, Windows Server 2008  Windows Server 2008 R2`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows Vista [desktop apps / UWP apps] |
| Minimum server | Windows Server 2008 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [AcquireSRWLockExclusive function (synchapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-acquiresrwlockexclusive) |
| In this tree | No definition extracted by the generator from `base/win32`, `base/screg`, `net/sockets`, `windows/core`, `base/ntos`, `base/ntdll`, `base/subsys`, `base/fs` or `net/published`. A fixed-string search found call sites only, so the implementation is either outside this checkout or reached through a macro. Search the [generated index](/reference/) by name. |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
VOID WINAPI AcquireSRWLockExclusive(
    PSRWLOCK SRWLock
);
```

**Return value.** See the official reference.

**Tested example** — `example_AcquireSRWLockExclusive` in [`synchronization.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/synchronization.c):

```c
static void example_AcquireSRWLockExclusive(void)
{
    InitializeSRWLock(&g_srw);
    AcquireSRWLockExclusive(&g_srw);    /* writers: one at a time */
    g_shared++;
    ReleaseSRWLockExclusive(&g_srw);
    wprintf(L"Writer updated the value to %ld\n", g_shared);
}
```

## ReleaseSRWLockExclusive

Releases a slim reader/writer (SRW) lock that was acquired in exclusive mode.

| Attribute | Value |
| --- | --- |
| Header | `synchapi.h` (include `Windows.h on Windows 7, Windows Server 2008  Windows Server 2008 R2`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows Vista [desktop apps / UWP apps] |
| Minimum server | Windows Server 2008 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [ReleaseSRWLockExclusive function (synchapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-releasesrwlockexclusive) |
| In this tree | No definition extracted by the generator from `base/win32`, `base/screg`, `net/sockets`, `windows/core`, `base/ntos`, `base/ntdll`, `base/subsys`, `base/fs` or `net/published`. A fixed-string search found call sites only, so the implementation is either outside this checkout or reached through a macro. Search the [generated index](/reference/) by name. |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
VOID WINAPI ReleaseSRWLockExclusive(
    PSRWLOCK SRWLock
);
```

**Return value.** See the official reference.

**Tested example** — `example_ReleaseSRWLockExclusive` in [`synchronization.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/synchronization.c):

```c
static void example_ReleaseSRWLockExclusive(void)
{
    AcquireSRWLockExclusive(&g_srw);
    /* Must be released by the same thread that acquired it. */
    ReleaseSRWLockExclusive(&g_srw);
    wprintf(L"SRW lock released\n");
}
```

## Build and test

Compile for an x86_64 Windows target with warnings treated as errors (run it on Windows; the examples are compiled here, not executed):

```sh
zig cc -target x86_64-windows-gnu -std=c11 -Wall -Wextra -Werror synchronization.c -o synchronization.exe -lkernel32 -ladvapi32 -lws2_32 -luser32 -lgdi32 -lshell32
```

With MSVC from a Developer Command Prompt: `cl /nologo /W4 /WX synchronization.c`. MSVC is not run in this checkout; the file is verified only with the zig/clang Windows targets.

## Frequently asked questions

### Q: Which should I use: a critical section or an SRW lock?

A critical section is recursive and works with `TryEnterCriticalSection`; an SRW lock is smaller, not recursive, and has shared (reader) mode. Use SRW for read-mostly data and critical sections when you need recursion.

### Q: Why does WaitForSingleObject return WAIT_OBJECT_0 for a manual-reset event that I never reset?

A manual-reset event stays signaled until `ResetEvent` is called, so every wait succeeds. An auto-reset event is cleared by the first successful wait, as the example shows.

### Q: Can I wait on a mutex I already own?

Yes, mutexes are recursive for the owning thread; each successful wait needs one `ReleaseMutex`.

### Q: Where are these implemented?

Kernel side in `base/ntos/ke` (dispatcher, `wait.c`) and `base/ntos/ex/mutant.c`; user-mode wrappers in `base/win32/client/synch.c`. Search there for the exported name.
