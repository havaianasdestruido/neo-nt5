/*
 * Win32 runtime examples for the NEONT 5 documentation site: error codes,
 * string conversion, dynamic loading, the command line and timers.
 *
 * Build with MinGW-w64 or zig cc (any Windows target):
 *     zig cc -target x86_64-windows-gnu -std=c11 -Wall -Wextra -Werror runtime.c -o runtime.exe -lkernel32 -lshell32
 * Build with MSVC:
 *     cl /nologo /W4 /WX runtime.c shell32.lib
 */
#define UNICODE
#define _UNICODE
#include <windows.h>
#include <shellapi.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

/* @fn GetLastError */
static void example_GetLastError(void)
{
    /* Ask for a file that cannot exist, then read the error code from the same thread. */
    HANDLE h = CreateFileW(L"C:\\this\\path\\does\\not\\exist.txt", GENERIC_READ, 0, NULL,
                           OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (h == INVALID_HANDLE_VALUE) {
        DWORD err = GetLastError();      /* read it immediately; other calls may overwrite it */
        wprintf(L"Error %lu (ERROR_PATH_NOT_FOUND is 3, ERROR_FILE_NOT_FOUND is 2)\n", err);
    }
}

/* @fn SetLastError */
static void example_SetLastError(void)
{
    /* Clear the last-error value before a call whose success you must check by GetLastError. */
    SetLastError(ERROR_SUCCESS);
    wprintf(L"Last error after reset: %lu\n", GetLastError());
}

/* @fn FormatMessageW */
static void example_FormatMessageW(void)
{
    LPWSTR text = NULL;
    DWORD n = FormatMessageW(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                             NULL, ERROR_ACCESS_DENIED, 0, (LPWSTR)&text, 0, NULL);
    if (n > 0 && text != NULL) {
        wprintf(L"ERROR_ACCESS_DENIED: %ls", text);
        LocalFree(text);     /* the buffer is allocated by the system */
    }
}

/* @fn MultiByteToWideChar */
static void example_MultiByteToWideChar(void)
{
    const char utf8[] = "caf\xC3\xA9";     /* "café" as UTF-8 bytes */
    wchar_t wide[32];
    int n = MultiByteToWideChar(CP_UTF8, 0, utf8, -1, wide, 32);   /* -1: the input is NUL-terminated */
    if (n > 0)
        wprintf(L"Converted %d wchar_t units: %ls\n", n, wide);
}

/* @fn WideCharToMultiByte */
static void example_WideCharToMultiByte(void)
{
    const wchar_t wide[] = L"NEONT 5";
    char utf8[64];
    int n = WideCharToMultiByte(CP_UTF8, 0, wide, -1, utf8, (int)sizeof(utf8), NULL, NULL);
    if (n > 0)
        printf("UTF-8 byte count including NUL: %d\n", n);
}

/* @fn LoadLibraryW */
static void example_LoadLibraryW(void)
{
    /* Load by a full path or a name the loader can find. kernel32.dll is always present. */
    HMODULE lib = LoadLibraryW(L"kernel32.dll");
    if (lib != NULL) {
        wprintf(L"kernel32.dll loaded at %p\n", (void *)lib);
        FreeLibrary(lib);
    }
}

/* @fn GetProcAddress */
static void example_GetProcAddress(void)
{
    typedef ULONGLONG (WINAPI *GetTickCount64Fn)(void);
    HMODULE k32 = GetModuleHandleW(L"kernel32.dll");
    /* Resolve by name; the cast must match the exported function's real prototype. */
    GetTickCount64Fn fn = (GetTickCount64Fn)GetProcAddress(k32, "GetTickCount64");
    if (fn != NULL)
        wprintf(L"Uptime: %llu ms\n", (unsigned long long)fn());
}

/* @fn FreeLibrary */
static void example_FreeLibrary(void)
{
    HMODULE lib = LoadLibraryW(L"advapi32.dll");   /* reference count +1 */
    if (lib != NULL && FreeLibrary(lib))           /* reference count -1 */
        wprintf(L"advapi32.dll released\n");
}

/* @fn GetModuleHandleW */
static void example_GetModuleHandleW(void)
{
    /* Unlike LoadLibraryW, this never loads and does not add a reference: do not FreeLibrary the result. */
    HMODULE self = GetModuleHandleW(NULL);     /* NULL = the executable itself */
    HMODULE user32 = GetModuleHandleW(L"user32.dll");
    wprintf(L"self=%p user32=%p\n", (void *)self, (void *)user32);
}

/* @fn GetCommandLineW */
static void example_GetCommandLineW(void)
{
    /* Returns the whole command line, including the program name. Do not modify or free it. */
    LPCWSTR cmd = GetCommandLineW();
    wprintf(L"Command line: %ls\n", cmd);
}

/* @fn CommandLineToArgvW */
static void example_CommandLineToArgvW(void)
{
    int argc = 0;
    LPWSTR *argv = CommandLineToArgvW(L"tool.exe --name \"two words\" -v", &argc);
    if (argv == NULL) return;
    for (int i = 0; i < argc; i++)
        wprintf(L"argv[%d] = %ls\n", i, argv[i]);
    LocalFree(argv);     /* a single LocalFree releases the whole array */
}

/* @fn GetTickCount64 */
static void example_GetTickCount64(void)
{
    /* Milliseconds since boot as a 64-bit value; it does not wrap after 49 days like GetTickCount. */
    ULONGLONG ms = GetTickCount64();
    wprintf(L"Milliseconds since boot: %llu\n", (unsigned long long)ms);
}

/* @fn QueryPerformanceCounter */
static void example_QueryPerformanceCounter(void)
{
    LARGE_INTEGER start, end, freq;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start);
    Sleep(10);
    QueryPerformanceCounter(&end);
    double ms = (double)(end.QuadPart - start.QuadPart) * 1000.0 / (double)freq.QuadPart;
    wprintf(L"Elapsed about %.1f ms\n", ms);
}

/* @fn QueryPerformanceFrequency */
static void example_QueryPerformanceFrequency(void)
{
    /* Counts per second; fixed at system boot, so read it once and reuse it. */
    LARGE_INTEGER freq;
    if (QueryPerformanceFrequency(&freq))
        wprintf(L"Counter frequency: %lld Hz\n", (long long)freq.QuadPart);
}

int main(void)
{
    example_GetLastError();
    example_SetLastError();
    example_FormatMessageW();
    example_MultiByteToWideChar();
    example_WideCharToMultiByte();
    example_LoadLibraryW();
    example_GetProcAddress();
    example_FreeLibrary();
    example_GetModuleHandleW();
    example_GetCommandLineW();
    example_CommandLineToArgvW();
    example_GetTickCount64();
    example_QueryPerformanceCounter();
    example_QueryPerformanceFrequency();
    return 0;
}
