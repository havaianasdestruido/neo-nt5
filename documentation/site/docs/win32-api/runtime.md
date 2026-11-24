---
title: "Errors, strings, modules and timing"
sidebar_position: 16
description: "GetLastError, FormatMessageW, UTF-8 and UTF-16 conversion, LoadLibraryW and GetProcAddress, command-line parsing and high-resolution timers."
---

# Errors, strings, modules and timing

This page groups the runtime helpers that most programs need on day one: the thread-local last-error value, message text, Unicode conversion, dynamic loading, command-line parsing and clocks. The implementations are split between `base/win32/client` (kernel32-style wrappers), `base/win32/client/module.c` (loader) and `base/win32/client/error.c` (last error).

The last-error value is per thread and is overwritten by almost every call, so read it immediately.

This page covers **14 functions**: [`GetLastError`](#getlasterror), [`SetLastError`](#setlasterror), [`FormatMessageW`](#formatmessagew), [`MultiByteToWideChar`](#multibytetowidechar), [`WideCharToMultiByte`](#widechartomultibyte), [`LoadLibraryW`](#loadlibraryw), [`GetProcAddress`](#getprocaddress), [`FreeLibrary`](#freelibrary), [`GetModuleHandleW`](#getmodulehandlew), [`GetCommandLineW`](#getcommandlinew), [`CommandLineToArgvW`](#commandlinetoargvw), [`GetTickCount64`](#gettickcount64), [`QueryPerformanceCounter`](#queryperformancecounter), [`QueryPerformanceFrequency`](#queryperformancefrequency).

## Shared setup

Paste this block at the top of your source file, then one or more example functions below, then call them from `main`. The complete, compiled file is [runtime.c](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/runtime.c).

```c
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
```

## Functions

## GetLastError

Retrieves the calling thread's last-error code value. The last-error code is maintained on a per-thread basis. Multiple threads do not overwrite each other's last-error code. **Visual Basic:** Applications should call **err.LastDllError** instead of **GetLastError**.

| Attribute | Value |
| --- | --- |
| Header | `errhandlingapi.h` (include `Windows.h`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [GetLastError function (errhandlingapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) |
| In this tree | [`base/win32/client/error.c:91`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/error.c#L91), [`base/win32/fusion/inc/debmacro.h:590`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/fusion/inc/debmacro.h#L590) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
DWORD WINAPI GetLastError(
    VOID
);
```

**Return value.** The return value is the calling thread's last-error code. The Return Value section of the documentation for each function that sets the last-error code notes the conditions under which the function sets the last-error code. Most functions that set the thread's last-error code set it when they fail. However, some functions also set the last-error code when they succeed. If the function is not documented to set the last-error code, the value returned by this function is simply the most recent last-error code to have been set; some functions set the last-error code to 0 on success and others do not.

**Tested example** — `example_GetLastError` in [`runtime.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/runtime.c):

```c
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
```

## SetLastError

Sets the last-error code for the calling thread.

| Attribute | Value |
| --- | --- |
| Header | `errhandlingapi.h` (include `Windows.h`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [SetLastError function (errhandlingapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-setlasterror) |
| In this tree | [`base/win32/client/error.c:123`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/error.c#L123), [`base/win32/fusion/inc/debmacro.h:548`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/fusion/inc/debmacro.h#L548) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
VOID WINAPI SetLastError(
    DWORD dwErrCode
);
```

**Return value.** See the official reference.

**Tested example** — `example_SetLastError` in [`runtime.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/runtime.c):

```c
static void example_SetLastError(void)
{
    /* Clear the last-error value before a call whose success you must check by GetLastError. */
    SetLastError(ERROR_SUCCESS);
    wprintf(L"Last error after reset: %lu\n", GetLastError());
}
```

## FormatMessageW

Formats a message string. The function requires a message definition as input. The message definition can come from a buffer passed into the function. It can come from a message table resource in an already-loaded module. Or the caller can ask the function to search the system's message table resource(s) for the message definition. The function finds the message definition in a message table resource based on a message identifier and a language identifier. The function copies the formatted message text to an output buffer, processing any embedded insert sequences if requested.

| Attribute | Value |
| --- | --- |
| Header | `winbase.h` (include `Windows.h`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | FormatMessageW (Unicode) and FormatMessageA (ANSI) |
| Official reference | [FormatMessageW function (winbase.h)](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-formatmessagew) |
| In this tree | [`base/win32/client/message.c:154`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/message.c#L154) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
DWORD WINAPI FormatMessageW(
    DWORD dwFlags,
    LPCVOID lpSource,
    DWORD dwMessageId,
    DWORD dwLanguageId,
    LPWSTR lpBuffer,
    DWORD nSize,
    va_list *Arguments
);
```

**Return value.** If the function succeeds, the return value is the number of **TCHARs** stored in the output buffer, excluding the terminating null character. If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Tested example** — `example_FormatMessageW` in [`runtime.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/runtime.c):

```c
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
```

## MultiByteToWideChar

Maps a character string to a UTF-16 (wide character) string. The character string is not necessarily from a multibyte character set.

| Attribute | Value |
| --- | --- |
| Header | `stringapiset.h` (include `Windows.h`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows 2000 Professional [desktop apps / UWP apps] |
| Minimum server | Windows 2000 Server [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [MultiByteToWideChar function (stringapiset.h)](https://learn.microsoft.com/en-us/windows/win32/api/stringapiset/nf-stringapiset-multibytetowidechar) |
| In this tree | [`base/win32/fusion/appweek/host/chost.cpp:22`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/fusion/appweek/host/chost.cpp#L22), [`base/win32/fusion/appweek/host1/chost.cpp:22`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/fusion/appweek/host1/chost.cpp#L22), [`base/win32/winnls/mbcs.c:1544`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/winnls/mbcs.c#L1544) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
int WINAPI MultiByteToWideChar(
    UINT CodePage,
    DWORD dwFlags,
    LPCCH lpMultiByteStr,
    int cbMultiByte,
    LPWSTR lpWideCharStr,
    int cchWideChar
);
```

**Return value.** Returns the number of characters written to the buffer indicated by *lpWideCharStr* if successful. If the function succeeds and *cchWideChar* is `0`, the return value is the required size, in characters, for the buffer indicated by *lpWideCharStr*. Also see *dwFlags* for info about how the **MB_ERR_INVALID_CHARS** flag affects the return value when invalid sequences are input. The function returns `0` if it does not succeed. To get extended error information, the application can call [GetLastError](../errhandlingapi/nf-errhandlingapi-getlasterror.md), which can return one of the following error codes:

**Tested example** — `example_MultiByteToWideChar` in [`runtime.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/runtime.c):

```c
static void example_MultiByteToWideChar(void)
{
    const char utf8[] = "caf\xC3\xA9";     /* "café" as UTF-8 bytes */
    wchar_t wide[32];
    int n = MultiByteToWideChar(CP_UTF8, 0, utf8, -1, wide, 32);   /* -1: the input is NUL-terminated */
    if (n > 0)
        wprintf(L"Converted %d wchar_t units: %ls\n", n, wide);
}
```

## WideCharToMultiByte

Maps a UTF-16 (wide character) string to a new character string. The new character string is not necessarily from a multibyte character set. **Caution**  Using the **WideCharToMultiByte** function incorrectly can compromise the security of your application. Calling this function can easily cause a buffer overrun because the size of the input buffer indicated by *lpWideCharStr* equals the number of characters in the Unicode string, while the size of the output buffer indicated by *lpMultiByteStr* equals the number of bytes. To avoid a buffer overrun, your application must specify a buffer size appropriate for the data type the buffer receives.

| Attribute | Value |
| --- | --- |
| Header | `stringapiset.h` (include `Windows.h`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows 2000 Professional [desktop apps / UWP apps] |
| Minimum server | Windows 2000 Server [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [WideCharToMultiByte function (stringapiset.h)](https://learn.microsoft.com/en-us/windows/win32/api/stringapiset/nf-stringapiset-widechartomultibyte) |
| In this tree | [`base/win32/winnls/mbcs.c:2140`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/winnls/mbcs.c#L2140) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
int WINAPI WideCharToMultiByte(
    UINT CodePage,
    DWORD dwFlags,
    LPCWCH lpWideCharStr,
    int cchWideChar,
    LPSTR lpMultiByteStr,
    int cbMultiByte,
    LPCCH lpDefaultChar,
    LPBOOL lpUsedDefaultChar
);
```

**Return value.** If successful, returns the number of bytes written to the buffer pointed to by *lpMultiByteStr*. If the function succeeds and *cbMultiByte* is 0, the return value is the required size, in bytes, for the buffer indicated by *lpMultiByteStr*. Also see *dwFlags* for info about how the WC_ERR_INVALID_CHARS flag affects the return value when invalid sequences are input. The function returns 0 if it does not succeed. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

**Tested example** — `example_WideCharToMultiByte` in [`runtime.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/runtime.c):

```c
static void example_WideCharToMultiByte(void)
{
    const wchar_t wide[] = L"NEONT 5";
    char utf8[64];
    int n = WideCharToMultiByte(CP_UTF8, 0, wide, -1, utf8, (int)sizeof(utf8), NULL, NULL);
    if (n > 0)
        printf("UTF-8 byte count including NUL: %d\n", n);
}
```

## LoadLibraryW

Loads the specified  module into the address space of the calling process. The specified module may cause other modules to be loaded. For additional load options, use the [LoadLibraryEx](https://learn.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibraryexw) function.

| Attribute | Value |
| --- | --- |
| Header | `libloaderapi.h` (include `Windows.h`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps only] |
| Minimum server | Windows Server 2003 [desktop apps only] |
| Character set | LoadLibraryW (Unicode) and LoadLibraryA (ANSI) |
| Official reference | [LoadLibraryW function (libloaderapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibraryw) |
| In this tree | [`base/win32/client/module.c:93`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/module.c#L93) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
HMODULE WINAPI LoadLibraryW(
    LPCWSTR lpLibFileName
);
```

**Return value.** If the function succeeds, the return value is a handle to the module. If the function fails, the return value is NULL. To get extended error information, call [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Tested example** — `example_LoadLibraryW` in [`runtime.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/runtime.c):

```c
static void example_LoadLibraryW(void)
{
    /* Load by a full path or a name the loader can find. kernel32.dll is always present. */
    HMODULE lib = LoadLibraryW(L"kernel32.dll");
    if (lib != NULL) {
        wprintf(L"kernel32.dll loaded at %p\n", (void *)lib);
        FreeLibrary(lib);
    }
}
```

## GetProcAddress

Retrieves the address of an exported function (also known as a procedure) or variable from the specified dynamic-link library (DLL).

| Attribute | Value |
| --- | --- |
| Header | `libloaderapi.h` (include `Windows.h`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [GetProcAddress function (libloaderapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) |
| In this tree | [`base/win32/client/module.c:1429`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/module.c#L1429), [`base/win32/fusion/tools/resourcetool/handle.h:250`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/fusion/tools/resourcetool/handle.h#L250) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
FARPROC WINAPI GetProcAddress(
    HMODULE hModule,
    LPCSTR lpProcName
);
```

**Return value.** If the function succeeds, the return value is the address of the exported function or variable. If the function fails, the return value is NULL. To get extended error information, call [GetLastError](../errhandlingapi/nf-errhandlingapi-getlasterror.md).

**Tested example** — `example_GetProcAddress` in [`runtime.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/runtime.c):

```c
static void example_GetProcAddress(void)
{
    typedef ULONGLONG (WINAPI *GetTickCount64Fn)(void);
    HMODULE k32 = GetModuleHandleW(L"kernel32.dll");
    /* Resolve by name; the cast must match the exported function's real prototype. */
    GetTickCount64Fn fn = (GetTickCount64Fn)GetProcAddress(k32, "GetTickCount64");
    if (fn != NULL)
        wprintf(L"Uptime: %llu ms\n", (unsigned long long)fn());
}
```

## FreeLibrary

Frees the loaded dynamic-link library (DLL) module and, if necessary, decrements its reference count. When the reference count reaches zero, the module is unloaded from the address space of the calling process and the handle is no longer valid.

| Attribute | Value |
| --- | --- |
| Header | `libloaderapi.h` (include `Windows.h`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [FreeLibrary function (libloaderapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-freelibrary) |
| In this tree | [`base/win32/client/module.c:482`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/module.c#L482) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
WINBOOL WINAPI FreeLibrary(
    HMODULE hLibModule
);
```

**Return value.** If the function succeeds, the return value is nonzero. If the function fails, the return value is zero. To get extended error information, call the [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

**Tested example** — `example_FreeLibrary` in [`runtime.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/runtime.c):

```c
static void example_FreeLibrary(void)
{
    HMODULE lib = LoadLibraryW(L"advapi32.dll");   /* reference count +1 */
    if (lib != NULL && FreeLibrary(lib))           /* reference count -1 */
        wprintf(L"advapi32.dll released\n");
}
```

## GetModuleHandleW

Retrieves a module handle for the specified module. The module must have been loaded by the calling process. To avoid the race conditions described in the Remarks section, use the [GetModuleHandleEx](https://learn.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-getmodulehandleexa) function.

| Attribute | Value |
| --- | --- |
| Header | `libloaderapi.h` (include `Windows.h`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps only] |
| Minimum server | Windows Server 2003 [desktop apps only] |
| Character set | GetModuleHandleW (Unicode) and GetModuleHandleA (ANSI) |
| Official reference | [GetModuleHandleW function (libloaderapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-getmodulehandlew) |
| In this tree | [`base/win32/client/module.c:1151`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/module.c#L1151) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
HMODULE WINAPI GetModuleHandleW(
    LPCWSTR lpModuleName
);
```

**Return value.** If the function succeeds, the return value is a handle to the specified module. If the function fails, the return value is NULL. To get extended error information, call [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Tested example** — `example_GetModuleHandleW` in [`runtime.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/runtime.c):

```c
static void example_GetModuleHandleW(void)
{
    /* Unlike LoadLibraryW, this never loads and does not add a reference: do not FreeLibrary the result. */
    HMODULE self = GetModuleHandleW(NULL);     /* NULL = the executable itself */
    HMODULE user32 = GetModuleHandleW(L"user32.dll");
    wprintf(L"self=%p user32=%p\n", (void *)self, (void *)user32);
}
```

## GetCommandLineW

Retrieves the command-line string for the current process.

| Attribute | Value |
| --- | --- |
| Header | `processenv.h` (include `Windows.h on Windows Server 2003, Windows Vista, Windows 7, Windows Server 2008  Windows Server 2008 R2`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | GetCommandLineW (Unicode) and GetCommandLineA (ANSI) |
| Official reference | [GetCommandLineW function (processenv.h)](https://learn.microsoft.com/en-us/windows/win32/api/processenv/nf-processenv-getcommandlinew) |
| In this tree | [`base/win32/client/process.c:5045`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/process.c#L5045) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
LPWSTR WINAPI GetCommandLineW(
    VOID
);
```

**Return value.** The return value is a pointer to the command-line string for the current process.

**Tested example** — `example_GetCommandLineW` in [`runtime.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/runtime.c):

```c
static void example_GetCommandLineW(void)
{
    /* Returns the whole command line, including the program name. Do not modify or free it. */
    LPCWSTR cmd = GetCommandLineW();
    wprintf(L"Command line: %ls\n", cmd);
}
```

## CommandLineToArgvW

Parses a Unicode command line string and returns an array of pointers to the command line arguments, along with a count of such arguments, in a way that is similar to the standard C run-time *argv* and *argc* values.

| Attribute | Value |
| --- | --- |
| Header | `shellapi.h` |
| Library | Shell32.lib (DLL `Shell32.dll (version 6.0 or later)`) |
| Minimum client | Windows 2000 Professional, Windows XP [desktop apps only] |
| Minimum server | Windows 2000 Server, Windows Server 2003 [desktop apps only] |
| Character set | CommandLineToArgvW (Unicode) |
| Official reference | [CommandLineToArgvW function (shellapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/shellapi/nf-shellapi-commandlinetoargvw) |
| In this tree | [`shell/published/inc/shellapi.w:95`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/shell/published/inc/shellapi.w#L95) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
/* prototype not found in the bundled headers; see the official reference */
```

**Return value.** Type: **LPWSTR*** A pointer to an array of **LPWSTR** values, similar to *argv*.

**Tested example** — `example_CommandLineToArgvW` in [`runtime.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/runtime.c):

```c
static void example_CommandLineToArgvW(void)
{
    int argc = 0;
    LPWSTR *argv = CommandLineToArgvW(L"tool.exe --name \"two words\" -v", &argc);
    if (argv == NULL) return;
    for (int i = 0; i < argc; i++)
        wprintf(L"argv[%d] = %ls\n", i, argv[i]);
    LocalFree(argv);     /* a single LocalFree releases the whole array */
}
```

## GetTickCount64

Retrieves the number of milliseconds that have elapsed since the system was started.

| Attribute | Value |
| --- | --- |
| Header | `sysinfoapi.h` (include `Windows.h`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows Vista [desktop apps / UWP apps] |
| Minimum server | Windows Server 2008 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [GetTickCount64 function (sysinfoapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/sysinfoapi/nf-sysinfoapi-gettickcount64) |
| In this tree | No definition extracted by the generator from `base/win32`, `base/screg`, `net/sockets`, `windows/core`, `base/ntos`, `base/ntdll`, `base/subsys`, `base/fs` or `net/published`. A fixed-string search found call sites only, so the implementation is either outside this checkout or reached through a macro. Search the [generated index](/reference/) by name. |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
x0600 ULONGLONG WINAPI GetTickCount64(
    VOID
);
```

**Return value.** The number of milliseconds.

**Tested example** — `example_GetTickCount64` in [`runtime.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/runtime.c):

```c
static void example_GetTickCount64(void)
{
    /* Milliseconds since boot as a 64-bit value; it does not wrap after 49 days like GetTickCount. */
    ULONGLONG ms = GetTickCount64();
    wprintf(L"Milliseconds since boot: %llu\n", (unsigned long long)ms);
}
```

## QueryPerformanceCounter

Retrieves the current value of the performance counter, which is a high resolution (&lt;1&micro;s) time stamp that can be used for time-interval measurements.

| Attribute | Value |
| --- | --- |
| Header | `profileapi.h` (include `Windows.h`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows 2000 Professional [desktop apps / UWP apps] |
| Minimum server | Windows 2000 Server [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [QueryPerformanceCounter function](https://learn.microsoft.com/en-us/windows/win32/api/profileapi/nf-profileapi-queryperformancecounter) |
| In this tree | [`base/win32/client/perfctr.c:24`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/perfctr.c#L24) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
endif WINBOOL WINAPI QueryPerformanceCounter(
    LARGE_INTEGER *lpPerformanceCount
);
```

**Return value.** If the function succeeds, the return value is nonzero. If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror). On systems that run Windows XP or later, the function will always succeed when given valid parameters and will thus never return zero.

**Tested example** — `example_QueryPerformanceCounter` in [`runtime.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/runtime.c):

```c
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
```

## QueryPerformanceFrequency

Retrieves the frequency of the performance counter. The frequency of the performance counter is fixed at system boot and is consistent across all processors. Therefore, the frequency need only be queried upon application initialization, and the result can be cached.

| Attribute | Value |
| --- | --- |
| Header | `profileapi.h` (include `Windows.h`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows 2000 Professional [desktop apps / UWP apps] |
| Minimum server | Windows 2000 Server [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [QueryPerformanceFrequency function](https://learn.microsoft.com/en-us/windows/win32/api/profileapi/nf-profileapi-queryperformancefrequency) |
| In this tree | [`base/win32/client/perfctr.c:77`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/perfctr.c#L77) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
WINBOOL WINAPI QueryPerformanceFrequency(
    LARGE_INTEGER *lpFrequency
);
```

**Return value.** If the installed hardware supports a high-resolution performance counter, the return value is nonzero. If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror). On systems that run Windows XP or later, the function will always succeed when given valid parameters and will thus never return zero.

**Tested example** — `example_QueryPerformanceFrequency` in [`runtime.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/runtime.c):

```c
static void example_QueryPerformanceFrequency(void)
{
    /* Counts per second; fixed at system boot, so read it once and reuse it. */
    LARGE_INTEGER freq;
    if (QueryPerformanceFrequency(&freq))
        wprintf(L"Counter frequency: %lld Hz\n", (long long)freq.QuadPart);
}
```

## Build and test

Compile for an x86_64 Windows target with warnings treated as errors (run it on Windows; the examples are compiled here, not executed):

```sh
zig cc -target x86_64-windows-gnu -std=c11 -Wall -Wextra -Werror runtime.c -o runtime.exe -lkernel32 -ladvapi32 -lws2_32 -luser32 -lgdi32 -lshell32
```

With MSVC from a Developer Command Prompt: `cl /nologo /W4 /WX runtime.c`. MSVC is not run in this checkout; the file is verified only with the zig/clang Windows targets.

## Frequently asked questions

### Q: Why does GetLastError return a stale value after a successful call?

Success does not clear the value. Call `SetLastError(ERROR_SUCCESS)` before an operation whose outcome you check through `GetLastError`, as the `SetLastError` example demonstrates.

### Q: Who frees the buffer returned by FormatMessageW?

With `FORMAT_MESSAGE_ALLOCATE_BUFFER`, the caller frees it with `LocalFree`. Without that flag you supply the buffer.

### Q: Why does GetTickCount64 exist when GetTickCount is available?

GetTickCount wraps after about 49.7 days. The 64-bit variant does not wrap in practice; use it for timeouts and durations.

### Q: Which function locates a module already loaded in my process?

`GetModuleHandleW`. It does not load the module and does not change its reference count, so do not pass its result to `FreeLibrary`.
