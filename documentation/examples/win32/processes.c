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

/* @fn CreateProcessW */
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

/* @fn OpenProcess */
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

/* @fn TerminateProcess */
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

/* @fn GetExitCodeProcess */
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

/* @fn GetCurrentProcessId */
static void example_GetCurrentProcessId(void)
{
    wprintf(L"PID of this process: %lu\n", GetCurrentProcessId());
}

/* @fn GetCurrentProcess */
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

/* @fn CreateThread */
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

/* @fn GetCurrentThreadId */
static void example_GetCurrentThreadId(void)
{
    wprintf(L"Thread id: %lu\n", GetCurrentThreadId());
}

/* @fn GetProcessId */
static void example_GetProcessId(void)
{
    /* GetProcessId returns the PID of a process from its handle (needs PROCESS_QUERY_LIMITED_INFORMATION). */
    HANDLE self = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, GetCurrentProcessId());
    if (self != NULL) {
        wprintf(L"GetProcessId: %lu\n", GetProcessId(self));
        CloseHandle(self);
    }
}

/* @fn GetModuleFileNameW */
static void example_GetModuleFileNameW(void)
{
    wchar_t path[MAX_PATH];
    /* NULL means the executable that started this process. */
    DWORD n = GetModuleFileNameW(NULL, path, MAX_PATH);
    if (n > 0 && n < MAX_PATH)
        wprintf(L"Executable: %ls\n", path);
}

int main(void)
{
    example_CreateProcessW();
    example_OpenProcess();
    example_TerminateProcess();
    example_GetExitCodeProcess();
    example_GetCurrentProcessId();
    example_GetCurrentProcess();
    example_CreateThread();
    example_GetCurrentThreadId();
    example_GetProcessId();
    example_GetModuleFileNameW();
    return 0;
}
