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

/* @fn CreateEventW */
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

/* @fn SetEvent */
static void example_SetEvent(void)
{
    HANDLE ev = CreateEventW(NULL, TRUE, FALSE, NULL);
    if (ev == NULL) return;
    /* Signal the event: waiters are released (all of them for a manual-reset event). */
    if (SetEvent(ev) && WaitForSingleObject(ev, 0) == WAIT_OBJECT_0)
        wprintf(L"Event is signaled\n");
    CloseHandle(ev);
}

/* @fn ResetEvent */
static void example_ResetEvent(void)
{
    HANDLE ev = CreateEventW(NULL, TRUE, TRUE, NULL);   /* starts signaled */
    if (ev == NULL) return;
    ResetEvent(ev);                                     /* back to non-signaled */
    if (WaitForSingleObject(ev, 0) == WAIT_TIMEOUT)
        wprintf(L"Event is non-signaled after ResetEvent\n");
    CloseHandle(ev);
}

/* @fn WaitForSingleObject */
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

/* @fn WaitForMultipleObjects */
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

/* @fn Sleep */
static void example_Sleep(void)
{
    /* Sleep yields the rest of this thread's time slice; it is not a precise timer. */
    wprintf(L"Sleeping 100 ms\n");
    Sleep(100);
}

/* @fn CreateMutexW */
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

/* @fn ReleaseMutex */
static void example_ReleaseMutex(void)
{
    HANDLE m = CreateMutexW(NULL, TRUE, NULL);   /* the creator owns it initially */
    if (m == NULL) return;
    /* Only the owning thread may release; releasing from another thread fails. */
    if (ReleaseMutex(m))
        wprintf(L"Mutex released\n");
    CloseHandle(m);
}

/* @fn CreateSemaphoreW */
static void example_CreateSemaphoreW(void)
{
    /* Initial count 2, maximum count 4. */
    HANDLE s = CreateSemaphoreW(NULL, 2, 4, NULL);
    if (s == NULL) return;
    wprintf(L"Semaphore created (initial 2, max 4)\n");
    CloseHandle(s);
}

/* @fn ReleaseSemaphore */
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

/* @fn InitializeCriticalSection */
static void example_InitializeCriticalSection(void)
{
    /* Must be initialized before the first EnterCriticalSection. */
    InitializeCriticalSection(&g_lock);
    wprintf(L"Critical section initialized\n");
    DeleteCriticalSection(&g_lock);
}

/* @fn EnterCriticalSection */
static void example_EnterCriticalSection(void)
{
    InitializeCriticalSection(&g_lock);
    EnterCriticalSection(&g_lock);     /* blocks until the lock is free; recursive for the same thread */
    g_shared++;
    LeaveCriticalSection(&g_lock);
    DeleteCriticalSection(&g_lock);
    wprintf(L"Shared value: %ld\n", g_shared);
}

/* @fn LeaveCriticalSection */
static void example_LeaveCriticalSection(void)
{
    InitializeCriticalSection(&g_lock);
    EnterCriticalSection(&g_lock);
    /* Every Enter must be matched by exactly one Leave, even on early return paths. */
    LeaveCriticalSection(&g_lock);
    DeleteCriticalSection(&g_lock);
}

/* @fn DeleteCriticalSection */
static void example_DeleteCriticalSection(void)
{
    InitializeCriticalSection(&g_lock);
    /* Delete only when no thread holds or waits on the section. */
    DeleteCriticalSection(&g_lock);
    wprintf(L"Critical section deleted\n");
}

/* @fn InitializeSRWLock */
static void example_InitializeSRWLock(void)
{
    /* Static initialization with SRWLOCK_INIT is equivalent; the call is for dynamic objects. */
    InitializeSRWLock(&g_srw);
    wprintf(L"SRW lock initialized\n");
}

/* @fn AcquireSRWLockExclusive */
static void example_AcquireSRWLockExclusive(void)
{
    InitializeSRWLock(&g_srw);
    AcquireSRWLockExclusive(&g_srw);    /* writers: one at a time */
    g_shared++;
    ReleaseSRWLockExclusive(&g_srw);
    wprintf(L"Writer updated the value to %ld\n", g_shared);
}

/* @fn ReleaseSRWLockExclusive */
static void example_ReleaseSRWLockExclusive(void)
{
    AcquireSRWLockExclusive(&g_srw);
    /* Must be released by the same thread that acquired it. */
    ReleaseSRWLockExclusive(&g_srw);
    wprintf(L"SRW lock released\n");
}

int main(void)
{
    example_CreateEventW();
    example_SetEvent();
    example_ResetEvent();
    example_WaitForSingleObject();
    example_WaitForMultipleObjects();
    example_Sleep();
    example_CreateMutexW();
    example_ReleaseMutex();
    example_CreateSemaphoreW();
    example_ReleaseSemaphore();
    example_InitializeCriticalSection();
    example_EnterCriticalSection();
    example_LeaveCriticalSection();
    example_DeleteCriticalSection();
    example_InitializeSRWLock();
    example_AcquireSRWLockExclusive();
    example_ReleaseSRWLockExclusive();
    return 0;
}
