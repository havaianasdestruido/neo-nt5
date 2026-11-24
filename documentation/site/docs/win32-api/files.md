---
title: "File and device I/O"
sidebar_position: 12
description: "CreateFileW, ReadFile, WriteFile, directory enumeration, path resolution, device control and pipes: official signatures, the matching NT-tree implementations, and compiled examples."
---

# File and device I/O

File handles are the most used Win32 object. Almost every program reaches the file system through `CreateFileW` followed by `ReadFile`/`WriteFile` and `CloseHandle`, and the `W` suffix means UTF-16 (`LPCWSTR`) paths. The functions on this page are the ones a driver author sees at the bottom of the stack: the Win32 wrappers in `base/win32/client` translate arguments and call `Nt*` services, so the names here are the entry points for [I/O, file systems and storage](/io-storage).

Use the table as a checklist: the first column is the public contract; the tree column shows where NEONT 5 implements it.

This page covers **19 functions**: [`CreateFileW`](#createfilew), [`ReadFile`](#readfile), [`WriteFile`](#writefile), [`CloseHandle`](#closehandle), [`GetFileSizeEx`](#getfilesizeex), [`SetFilePointerEx`](#setfilepointerex), [`FlushFileBuffers`](#flushfilebuffers), [`GetFileAttributesExW`](#getfileattributesexw), [`FindFirstFileW`](#findfirstfilew), [`FindNextFileW`](#findnextfilew), [`FindClose`](#findclose), [`DeleteFileW`](#deletefilew), [`MoveFileExW`](#movefileexw), [`CreateDirectoryW`](#createdirectoryw), [`RemoveDirectoryW`](#removedirectoryw), [`GetFinalPathNameByHandleW`](#getfinalpathnamebyhandlew), [`GetTempPathW`](#gettemppathw), [`DeviceIoControl`](#deviceiocontrol), [`CreatePipe`](#createpipe).

## Shared setup

Paste this block at the top of your source file, then one or more example functions below, then call them from `main`. The complete, compiled file is [files.c](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/files.c).

```c
/*
 * Win32 file and device I/O examples for the NEONT 5 documentation site.
 *
 * Build (Visual Studio Developer Command Prompt, MSVC):
 *     cl /nologo /W4 /WX files.c
 * Build (MinGW-w64 or zig cc, any Windows target):
 *     zig cc -target x86_64-windows-gnu -std=c11 -Wall -Wextra -Werror files.c -o files.exe -lkernel32
 *
 * Every example works on a scratch file in %TEMP% and removes it afterwards.
 * Each example is reproduced verbatim in the Win32 API reference.
 */
#define UNICODE
#define _UNICODE
#include <windows.h>
#include <winioctl.h>
#include <stdio.h>
#include <wchar.h>

/* Shared helper: writes "<%TEMP%>\<name>" into out (out must hold MAX_PATH wchar_t). */
static void temp_file(wchar_t *out, const wchar_t *name)
{
    wchar_t dir[MAX_PATH];
    DWORD len = GetTempPathW(MAX_PATH, dir);
    if (len == 0 || len > MAX_PATH) {
        out[0] = L'\0';
        return;
    }
    lstrcpyW(out, dir);
    lstrcatW(out, name);
}
```

## Functions

## CreateFileW

Creates or opens a file or I/O device. The most commonly used I/O devices are as follows: file, file stream, directory, physical disk, volume, console buffer, tape drive, communications resource, mailslot, and pipe. The function returns a handle that can be used to access the file or device for various types of I/O depending on the file or device and the flags and attributes specified. To perform this operation as a transacted operation, which results in a handle that can be used for transacted I/O, use the [CreateFileTransacted](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-createfiletransacteda) function.

| Attribute | Value |
| --- | --- |
| Header | `fileapi.h` (include `Windows.h`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps only] |
| Minimum server | Windows Server 2003 [desktop apps only] |
| Character set | CreateFileW (Unicode) and CreateFileA (ANSI) |
| Official reference | [CreateFileW function (fileapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-createfilew) |
| In this tree | [`base/win32/client/fileopcr.c:5369`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/fileopcr.c#L5369) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
HANDLE WINAPI CreateFileW(
    LPCWSTR lpFileName,
    DWORD dwDesiredAccess,
    DWORD dwShareMode,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    DWORD dwCreationDisposition,
    DWORD dwFlagsAndAttributes,
    HANDLE hTemplateFile
);
```

**Return value.** If the function succeeds, the return value is an open handle to the specified file, device, named pipe, or mail slot. If the function fails, the return value is **INVALID_HANDLE_VALUE**. To get extended error information, call [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Tested example** — `example_CreateFileW` in [`files.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/files.c):

```c
static void example_CreateFileW(void)
{
    wchar_t path[MAX_PATH];
    temp_file(path, L"neont5-createfile.txt");

    HANDLE h = CreateFileW(path,
                           GENERIC_WRITE,
                           0,                       /* no sharing while we write */
                           NULL,                    /* default security, not inheritable */
                           CREATE_ALWAYS,           /* create or truncate */
                           FILE_ATTRIBUTE_TEMPORARY,
                           NULL);
    if (h == INVALID_HANDLE_VALUE) {
        wprintf(L"CreateFileW failed: %lu\n", GetLastError());
        return;
    }
    wprintf(L"Opened %ls for writing\n", path);
    CloseHandle(h);
    DeleteFileW(path);
}
```

## ReadFile

Reads data from the specified file or input/output (I/O) device. Reads occur at the position specified by the file pointer if supported by the device. This function is designed for both synchronous and asynchronous operations. For a similar function designed solely for asynchronous operation, see [ReadFileEx](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-readfileex).

| Attribute | Value |
| --- | --- |
| Header | `fileapi.h` (include `Windows.h`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [ReadFile function (fileapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-readfile) |
| In this tree | [`base/win32/client/filehops.c:211`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/filehops.c#L211) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
WINBOOL WINAPI ReadFile(
    HANDLE hFile,
    LPVOID lpBuffer,
    DWORD nNumberOfBytesToRead,
    LPDWORD lpNumberOfBytesRead,
    LPOVERLAPPED lpOverlapped
);
```

**Return value.** If the function succeeds, the return value is nonzero (**TRUE**). If the function fails, or is completing asynchronously, the return value is zero (**FALSE**). To get extended error information, call the [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

**Tested example** — `example_ReadFile` in [`files.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/files.c):

```c
static void example_ReadFile(void)
{
    wchar_t path[MAX_PATH];
    char buffer[64];
    DWORD written = 0, read = 0;
    temp_file(path, L"neont5-readfile.txt");

    HANDLE h = CreateFileW(path, GENERIC_READ | GENERIC_WRITE, 0, NULL,
                           CREATE_ALWAYS, FILE_ATTRIBUTE_TEMPORARY, NULL);
    if (h == INVALID_HANDLE_VALUE) return;

    WriteFile(h, "hello, win32", 11, &written, NULL);
    SetFilePointer(h, 0, NULL, FILE_BEGIN);   /* rewind; SetFilePointerEx is preferred for 64-bit offsets */

    if (ReadFile(h, buffer, sizeof(buffer) - 1, &read, NULL)) {
        buffer[read] = '\0';
        wprintf(L"Read %lu bytes: %S\n", read, buffer);
    } else {
        wprintf(L"ReadFile failed: %lu\n", GetLastError());
    }
    CloseHandle(h);
    DeleteFileW(path);
}
```

## WriteFile

Writes data to the specified file or input/output (I/O) device. This function is designed for both synchronous and asynchronous operation. For a similar function designed solely for asynchronous operation, see [WriteFileEx](nf-fileapi-writefileex.md).

| Attribute | Value |
| --- | --- |
| Header | `fileapi.h` (include `Windows.h`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [WriteFile function (fileapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-writefile) |
| In this tree | [`base/win32/client/filehops.c:422`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/filehops.c#L422) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
WINBOOL WINAPI WriteFile(
    HANDLE hFile,
    LPCVOID lpBuffer,
    DWORD nNumberOfBytesToWrite,
    LPDWORD lpNumberOfBytesWritten,
    LPOVERLAPPED lpOverlapped
);
```

**Return value.** If the function succeeds, the return value is nonzero (**TRUE**). If the function fails, or is completing asynchronously, the return value is zero (**FALSE**). To get extended error information, call the [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

**Tested example** — `example_WriteFile` in [`files.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/files.c):

```c
static void example_WriteFile(void)
{
    wchar_t path[MAX_PATH];
    const char text[] = "line one\r\nline two\r\n";
    DWORD written = 0;
    temp_file(path, L"neont5-writefile.txt");

    HANDLE h = CreateFileW(path, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_TEMPORARY, NULL);
    if (h == INVALID_HANDLE_VALUE) return;

    /* For a synchronous handle (no FILE_FLAG_OVERLAPPED), lpOverlapped may be NULL. */
    if (WriteFile(h, text, (DWORD)(sizeof(text) - 1), &written, NULL))
        wprintf(L"Wrote %lu bytes\n", written);
    CloseHandle(h);
    DeleteFileW(path);
}
```

## CloseHandle

Closes an open object handle.

| Attribute | Value |
| --- | --- |
| Header | `handleapi.h` (include `Windows.h`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows 2000 Professional [desktop apps / UWP apps] |
| Minimum server | Windows 2000 Server [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [CloseHandle function (handleapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/handleapi/nf-handleapi-closehandle) |
| In this tree | [`base/win32/client/handle.c:23`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/handle.c#L23) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
WINBOOL WINAPI CloseHandle(
    HANDLE hObject
);
```

**Return value.** If the function succeeds, the return value is nonzero. If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Tested example** — `example_CloseHandle` in [`files.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/files.c):

```c
static void example_CloseHandle(void)
{
    HANDLE event = CreateEventW(NULL, TRUE, FALSE, NULL);
    if (event != NULL) {
        if (CloseHandle(event))
            wprintf(L"Handle closed; further use of the value is invalid\n");
    }
}
```

## GetFileSizeEx

Retrieves the size of the specified file.

| Attribute | Value |
| --- | --- |
| Header | `fileapi.h` (include `Windows.h`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [GetFileSizeEx function (fileapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-getfilesizeex) |
| In this tree | [`base/win32/client/filehops.c:1902`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/filehops.c#L1902) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
WINBOOL WINAPI GetFileSizeEx(
    HANDLE hFile,
    PLARGE_INTEGER lpFileSize
);
```

**Return value.** If the function succeeds, the return value is nonzero. If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Tested example** — `example_GetFileSizeEx` in [`files.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/files.c):

```c
static void example_GetFileSizeEx(void)
{
    wchar_t path[MAX_PATH];
    LARGE_INTEGER size;
    temp_file(path, L"neont5-size.txt");

    HANDLE h = CreateFileW(path, GENERIC_WRITE | GENERIC_READ, 0, NULL,
                           CREATE_ALWAYS, FILE_ATTRIBUTE_TEMPORARY, NULL);
    if (h == INVALID_HANDLE_VALUE) return;

    DWORD written;
    WriteFile(h, "0123456789", 10, &written, NULL);
    if (GetFileSizeEx(h, &size))
        wprintf(L"Size: %lld bytes\n", (long long)size.QuadPart);
    CloseHandle(h);
    DeleteFileW(path);
}
```

## SetFilePointerEx

Moves the file pointer of the specified file.

| Attribute | Value |
| --- | --- |
| Header | `fileapi.h` (include `Windows.h`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [SetFilePointerEx function (fileapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-setfilepointerex) |
| In this tree | [`base/win32/client/filehops.c:878`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/filehops.c#L878) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
WINBOOL WINAPI SetFilePointerEx(
    HANDLE hFile,
    LARGE_INTEGER liDistanceToMove,
    PLARGE_INTEGER lpNewFilePointer,
    DWORD dwMoveMethod
);
```

**Return value.** If the function succeeds, the return value is nonzero. If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Tested example** — `example_SetFilePointerEx` in [`files.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/files.c):

```c
static void example_SetFilePointerEx(void)
{
    wchar_t path[MAX_PATH];
    LARGE_INTEGER offset, newpos;
    temp_file(path, L"neont5-seek.txt");

    HANDLE h = CreateFileW(path, GENERIC_READ | GENERIC_WRITE, 0, NULL,
                           CREATE_ALWAYS, FILE_ATTRIBUTE_TEMPORARY, NULL);
    if (h == INVALID_HANDLE_VALUE) return;

    offset.QuadPart = 4096;                  /* a 64-bit offset */
    if (SetFilePointerEx(h, offset, &newpos, FILE_BEGIN))
        wprintf(L"Position is now %lld\n", (long long)newpos.QuadPart);
    CloseHandle(h);
    DeleteFileW(path);
}
```

## FlushFileBuffers

Flushes the buffers of a specified file and causes all buffered data to be written to a file.

| Attribute | Value |
| --- | --- |
| Header | `fileapi.h` (include `Windows.h`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [FlushFileBuffers function (fileapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-flushfilebuffers) |
| In this tree | [`base/win32/client/filehops.c:1332`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/filehops.c#L1332) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
WINBOOL WINAPI FlushFileBuffers(
    HANDLE hFile
);
```

**Return value.** If the function succeeds, the return value is nonzero. If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Tested example** — `example_FlushFileBuffers` in [`files.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/files.c):

```c
static void example_FlushFileBuffers(void)
{
    wchar_t path[MAX_PATH];
    DWORD written;
    temp_file(path, L"neont5-flush.txt");

    HANDLE h = CreateFileW(path, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_TEMPORARY, NULL);
    if (h == INVALID_HANDLE_VALUE) return;
    WriteFile(h, "durable", 7, &written, NULL);
    /* Ask the system to write cached data for this handle to the device. */
    if (FlushFileBuffers(h))
        wprintf(L"Flushed\n");
    CloseHandle(h);
    DeleteFileW(path);
}
```

## GetFileAttributesExW

Retrieves attributes for a specified file or directory. To perform this operation as a transacted operation, use the [GetFileAttributesTransacted](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-getfileattributestransacteda) function.

| Attribute | Value |
| --- | --- |
| Header | `fileapi.h` (include `Windows.h`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | GetFileAttributesExW (Unicode) and GetFileAttributesExA (ANSI) |
| Official reference | [GetFileAttributesExW function (fileapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-getfileattributesexw) |
| In this tree | [`base/win32/client/filemisc.c:398`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/filemisc.c#L398) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
WINBOOL WINAPI GetFileAttributesExW(
    LPCWSTR lpFileName,
    GET_FILEEX_INFO_LEVELS fInfoLevelId,
    LPVOID lpFileInformation
);
```

**Return value.** If the function succeeds, the return value is a nonzero value. If the function fails, the return value is zero (0). To get extended error information, call [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Tested example** — `example_GetFileAttributesExW` in [`files.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/files.c):

```c
static void example_GetFileAttributesExW(void)
{
    WIN32_FILE_ATTRIBUTE_DATA data;
    /* A directory always exists; query it without opening a handle. */
    if (GetFileAttributesExW(L"C:\\Windows", GetFileExInfoStandard, &data)) {
        LARGE_INTEGER size;
        size.HighPart = (LONG)data.nFileSizeHigh;
        size.LowPart = data.nFileSizeLow;
        wprintf(L"Directory attributes: 0x%08lX, size %lld\n",
                data.dwFileAttributes, (long long)size.QuadPart);
    }
}
```

## FindFirstFileW

Searches a directory for a file or subdirectory with a name that matches a specific name (or partial name if wildcards are used). To specify additional attributes to use in a search, use the [FindFirstFileEx](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-findfirstfileexw) function.

| Attribute | Value |
| --- | --- |
| Header | `fileapi.h` (include `Windows.h`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | FindFirstFileW (Unicode) and FindFirstFileA (ANSI) |
| Official reference | [FindFirstFileW function (fileapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-findfirstfilew) |
| In this tree | [`base/win32/client/filefind.c:126`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/filefind.c#L126) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
HANDLE WINAPI FindFirstFileW(
    LPCWSTR lpFileName,
    LPWIN32_FIND_DATAW lpFindFileData
);
```

**Return value.** If the function succeeds, the return value is a search handle used in a subsequent call to [FindNextFile](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-findnextfilew) or [FindClose](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-findclose), and  the *lpFindFileData* parameter contains information about the first file or directory found. If the function fails or fails to locate files from the search string in the *lpFileName* parameter, the return value is **INVALID_HANDLE_VALUE** and the contents of *lpFindFileData* are indeterminate. To get extended error information, call the [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

**Tested example** — `example_FindFirstFileW` in [`files.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/files.c):

```c
static void example_FindFirstFileW(void)
{
    WIN32_FIND_DATAW find;
    HANDLE h = FindFirstFileW(L"C:\\Windows\\*", &find);   /* wildcard is part of the pattern */
    if (h == INVALID_HANDLE_VALUE) {
        wprintf(L"FindFirstFileW: no match (%lu)\n", GetLastError());
        return;
    }
    wprintf(L"First entry: %ls\n", find.cFileName);
    FindClose(h);
}
```

## FindNextFileW

Continues a file search from a previous call to the [FindFirstFile](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-findfirstfilea), [FindFirstFileEx](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-findfirstfileexa), or [FindFirstFileTransacted](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-findfirstfiletransacteda) functions.

| Attribute | Value |
| --- | --- |
| Header | `fileapi.h` (include `Windows.h`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | FindNextFileW (Unicode) and FindNextFileA (ANSI) |
| Official reference | [FindNextFileW function (fileapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-findnextfilew) |
| In this tree | [`base/win32/client/filefind.c:261`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/filefind.c#L261) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
WINBOOL WINAPI FindNextFileW(
    HANDLE hFindFile,
    LPWIN32_FIND_DATAW lpFindFileData
);
```

**Return value.** If the function succeeds, the return value is nonzero and  the *lpFindFileData* parameter contains information about the next file or directory found. If the function fails, the return value is zero and the contents of *lpFindFileData* are indeterminate. To get extended error information, call the [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

**Tested example** — `example_FindNextFileW` in [`files.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/files.c):

```c
static void example_FindNextFileW(void)
{
    WIN32_FIND_DATAW find;
    int count = 0;
    HANDLE h = FindFirstFileW(L"C:\\Windows\\*", &find);
    if (h == INVALID_HANDLE_VALUE) return;
    do {
        if (!(find.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) count++;
    } while (FindNextFileW(h, &find));
    /* ERROR_NO_MORE_FILES is the normal end of enumeration, not a failure. */
    if (GetLastError() == ERROR_NO_MORE_FILES)
        wprintf(L"Files in C:\\Windows: %d\n", count);
    FindClose(h);
}
```

## FindClose

Closes a file search handle opened by the [FindFirstFile](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-findfirstfilea), [FindFirstFileEx](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-findfirstfileexa), [FindFirstFileNameW](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-findfirstfilenamew), [FindFirstFileNameTransactedW](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-findfirstfilenametransactedw), [FindFirstFileTransacted](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-findfirstfiletransacteda), [FindFirstStreamTransactedW](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-findfirststreamtransactedw), or [FindFirstStreamW](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-findfirststreamw) functions.

| Attribute | Value |
| --- | --- |
| Header | `fileapi.h` (include `Windows.h`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [FindClose function (fileapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-findclose) |
| In this tree | [`base/win32/client/filefind.c:447`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/filefind.c#L447) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
WINBOOL WINAPI FindClose(
    HANDLE hFindFile
);
```

**Return value.** If the function succeeds, the return value is nonzero. If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Tested example** — `example_FindClose` in [`files.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/files.c):

```c
static void example_FindClose(void)
{
    WIN32_FIND_DATAW find;
    HANDLE h = FindFirstFileW(L"C:\\Windows\\win.ini", &find);
    if (h != INVALID_HANDLE_VALUE) {
        /* Every successful FindFirstFile handle must be closed with FindClose. */
        FindClose(h);
    }
}
```

## DeleteFileW

Deletes an existing file. To perform this operation as a transacted operation, use the [DeleteFileTransacted](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-deletefiletransactedw) function.

| Attribute | Value |
| --- | --- |
| Header | `fileapi.h` (include `Windows.h`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | DeleteFileW (Unicode) and DeleteFileA (ANSI) |
| Official reference | [DeleteFileW function (fileapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-deletefilew) |
| In this tree | [`base/win32/client/filemisc.c:529`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/filemisc.c#L529) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
WINBOOL WINAPI DeleteFileW(
    LPCWSTR lpFileName
);
```

**Return value.** If the function succeeds, the return value is nonzero. If the function fails, the return value is zero (0). To get extended error information, call [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Tested example** — `example_DeleteFileW` in [`files.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/files.c):

```c
static void example_DeleteFileW(void)
{
    wchar_t path[MAX_PATH];
    temp_file(path, L"neont5-delete.txt");
    HANDLE h = CreateFileW(path, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_TEMPORARY, NULL);
    if (h != INVALID_HANDLE_VALUE) CloseHandle(h);   /* must be closed before deleting it */
    if (DeleteFileW(path))
        wprintf(L"Deleted %ls\n", path);
}
```

## MoveFileExW

Moves an existing file or directory, including its children, with various move options. The [MoveFileWithProgress](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-movefilewithprogressa) function is equivalent to the **MoveFileEx** function, except that **MoveFileWithProgress** allows you to provide a callback function that receives progress notifications.

| Attribute | Value |
| --- | --- |
| Header | `winbase.h` (include `Windows.h`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | MoveFileExW (Unicode) and MoveFileExA (ANSI) |
| Official reference | [MoveFileExW function (winbase.h)](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-movefileexw) |
| In this tree | [`base/win32/client/filemisc.c:1191`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/filemisc.c#L1191) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
WINBOOL WINAPI MoveFileExW(
    LPCWSTR lpExistingFileName,
    LPCWSTR lpNewFileName,
    DWORD dwFlags
);
```

**Return value.** If the function succeeds, the return value is nonzero. If the function fails, the return value is zero (0). To get extended error information, call [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Tested example** — `example_MoveFileExW` in [`files.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/files.c):

```c
static void example_MoveFileExW(void)
{
    wchar_t from[MAX_PATH], to[MAX_PATH];
    DWORD written;
    temp_file(from, L"neont5-move-src.txt");
    temp_file(to, L"neont5-move-dst.txt");

    HANDLE h = CreateFileW(from, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_TEMPORARY, NULL);
    if (h == INVALID_HANDLE_VALUE) return;
    WriteFile(h, "x", 1, &written, NULL);
    CloseHandle(h);

    /* MOVEFILE_REPLACE_EXISTING overwrites the destination if it already exists. */
    if (MoveFileExW(from, to, MOVEFILE_REPLACE_EXISTING))
        wprintf(L"Moved to %ls\n", to);
    DeleteFileW(to);
}
```

## CreateDirectoryW

Creates a new directory. If the underlying file system supports security on files and directories, the function applies a specified security descriptor to the new directory. To specify a template directory, use the [CreateDirectoryEx](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-createdirectoryexa) function.

| Attribute | Value |
| --- | --- |
| Header | `fileapi.h` (include `Windows.h`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | CreateDirectoryW (Unicode) and CreateDirectoryA (ANSI) |
| Official reference | [CreateDirectoryW function (fileapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-createdirectoryw) |
| In this tree | [`base/win32/client/dir.c:50`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/dir.c#L50) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
WINBOOL WINAPI CreateDirectoryW(
    LPCWSTR lpPathName,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes
);
```

**Return value.** If the function succeeds, the return value is nonzero. If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror). Possible errors include the following.

**Tested example** — `example_CreateDirectoryW` in [`files.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/files.c):

```c
static void example_CreateDirectoryW(void)
{
    wchar_t dir[MAX_PATH];
    temp_file(dir, L"neont5-demo-dir");
    if (CreateDirectoryW(dir, NULL))
        wprintf(L"Created %ls\n", dir);
    else if (GetLastError() == ERROR_ALREADY_EXISTS)
        wprintf(L"Already exists\n");
    RemoveDirectoryW(dir);   /* only works on an empty directory */
}
```

## RemoveDirectoryW

Deletes an existing empty directory. To perform this operation as a transacted operation, use the [RemoveDirectoryTransacted](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-removedirectorytransactedw) function.

| Attribute | Value |
| --- | --- |
| Header | `fileapi.h` (include `Windows.h`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | RemoveDirectoryW (Unicode) and RemoveDirectoryA (ANSI) |
| Official reference | [RemoveDirectoryW function (fileapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-removedirectoryw) |
| In this tree | [`base/win32/client/dir.c:985`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/dir.c#L985) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
WINBOOL WINAPI RemoveDirectoryW(
    LPCWSTR lpPathName
);
```

**Return value.** If the function succeeds, the return value is nonzero. If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Tested example** — `example_RemoveDirectoryW` in [`files.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/files.c):

```c
static void example_RemoveDirectoryW(void)
{
    wchar_t dir[MAX_PATH];
    temp_file(dir, L"neont5-remove-dir");
    CreateDirectoryW(dir, NULL);
    if (RemoveDirectoryW(dir))
        wprintf(L"Removed empty directory\n");
    else
        wprintf(L"RemoveDirectoryW failed: %lu\n", GetLastError());
}
```

## GetFinalPathNameByHandleW

Retrieves the final path for the specified file. For more information about file and path names, see [Naming a File](https://learn.microsoft.com/en-us/windows/win32/FileIO/naming-a-file).

| Attribute | Value |
| --- | --- |
| Header | `fileapi.h` (include `Windows.h`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows Vista [desktop apps / UWP apps] |
| Minimum server | Windows Server 2008 [desktop apps / UWP apps] |
| Character set | GetFinalPathNameByHandleW (Unicode) and GetFinalPathNameByHandleA (ANSI) |
| Official reference | [GetFinalPathNameByHandleW function (fileapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-getfinalpathnamebyhandlew) |
| In this tree | No definition extracted by the generator from `base/win32`, `base/screg`, `net/sockets`, `windows/core`, `base/ntos`, `base/ntdll`, `base/subsys`, `base/fs` or `net/published`. A fixed-string search found call sites only, so the implementation is either outside this checkout or reached through a macro. Search the [generated index](/reference/) by name. |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
DWORD WINAPI GetFinalPathNameByHandleW(
    HANDLE hFile,
    LPWSTR lpszFilePath,
    DWORD cchFilePath,
    DWORD dwFlags
);
```

**Return value.** If the function succeeds, the return value is the length of the string received by *lpszFilePath*, in **TCHAR**s. This value does not include the size of the terminating null character. **Windows Server 2008 and Windows Vista:  **For the ANSI version of this function, **GetFinalPathNameByHandleA**, the return value includes the size of the terminating null character.

**Tested example** — `example_GetFinalPathNameByHandleW` in [`files.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/files.c):

```c
static void example_GetFinalPathNameByHandleW(void)
{
    wchar_t path[MAX_PATH];
    wchar_t finalPath[MAX_PATH * 2];
    temp_file(path, L"neont5-final.txt");

    HANDLE h = CreateFileW(path, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_TEMPORARY, NULL);
    if (h == INVALID_HANDLE_VALUE) return;

    /* Returns the resolved path, e.g. \\?\C:\Users\...; the return value is the length in characters. */
    DWORD n = GetFinalPathNameByHandleW(h, finalPath, (DWORD)(sizeof(finalPath) / sizeof(finalPath[0])), FILE_NAME_NORMALIZED);
    if (n > 0 && n < sizeof(finalPath) / sizeof(finalPath[0]))
        wprintf(L"Final path: %ls\n", finalPath);
    CloseHandle(h);
    DeleteFileW(path);
}
```

## GetTempPathW

Retrieves the path of the directory designated for temporary files.

| Attribute | Value |
| --- | --- |
| Header | `fileapi.h` (include `Windows.h`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | GetTempPathW (Unicode) and GetTempPathA (ANSI) |
| Official reference | [GetTempPathW function (fileapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-gettemppathw) |
| In this tree | [`base/win32/client/pathmisc.c:1589`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/pathmisc.c#L1589) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
DWORD WINAPI GetTempPathW(
    DWORD nBufferLength,
    LPWSTR lpBuffer
);
```

**Return value.** If the function succeeds, the return value is the length, in **TCHARs**, of the string copied to *lpBuffer*, not including the terminating null character. If the return value is greater than *nBufferLength*, the return value is the length, in **TCHARs**, of the buffer required to hold the path. If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Tested example** — `example_GetTempPathW` in [`files.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/files.c):

```c
static void example_GetTempPathW(void)
{
    wchar_t dir[MAX_PATH];
    DWORD len = GetTempPathW(MAX_PATH, dir);
    /* len is the number of characters copied, excluding the terminating NUL, and ends in a backslash. */
    if (len > 0 && len < MAX_PATH)
        wprintf(L"Temp directory: %ls\n", dir);
}
```

## DeviceIoControl

Sends a control code directly to a specified device driver, causing the corresponding device to perform the corresponding operation. See the [Assign drive letter sample](https://github.com/microsoft/Windows-classic-samples/tree/master/Samples/Win7Samples/winbase/io/dledit).

| Attribute | Value |
| --- | --- |
| Header | `ioapiset.h` (include `Windows.h`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP |
| Minimum server | Windows Server 2003 |
| Character set | - |
| Official reference | [DeviceIoControl function (ioapiset.h)](https://learn.microsoft.com/en-us/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) |
| In this tree | [`base/win32/client/filehops.c:2431`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/filehops.c#L2431) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
WINBOOL WINAPI DeviceIoControl(
    HANDLE hDevice,
    DWORD dwIoControlCode,
    LPVOID lpInBuffer,
    DWORD nInBufferSize,
    LPVOID lpOutBuffer,
    DWORD nOutBufferSize,
    LPDWORD lpBytesReturned,
    LPOVERLAPPED lpOverlapped
);
```

**Return value.** If the operation completes successfully, the return value is nonzero (TRUE). If the operation fails or is pending, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Tested example** — `example_DeviceIoControl` in [`files.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/files.c):

```c
static void example_DeviceIoControl(void)
{
    wchar_t path[MAX_PATH];
    USHORT compression = 0;
    DWORD bytes = 0;
    temp_file(path, L"neont5-ioctl.txt");

    HANDLE h = CreateFileW(path, GENERIC_READ | GENERIC_WRITE, 0, NULL,
                           CREATE_ALWAYS, FILE_ATTRIBUTE_TEMPORARY, NULL);
    if (h == INVALID_HANDLE_VALUE) return;

    /* FSCTL_GET_COMPRESSION is a file-system control code (winioctl.h). Not every volume supports it. */
    if (DeviceIoControl(h, FSCTL_GET_COMPRESSION, NULL, 0, &compression, sizeof(compression), &bytes, NULL))
        wprintf(L"Compression format: %u\n", (unsigned)compression);
    else
        wprintf(L"DeviceIoControl: %lu\n", GetLastError());
    CloseHandle(h);
    DeleteFileW(path);
}
```

## CreatePipe

Creates an anonymous pipe, and returns handles to the read and write ends of the pipe.

| Attribute | Value |
| --- | --- |
| Header | `namedpipeapi.h` |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows 2000 Professional [desktop apps / UWP apps] |
| Minimum server | Windows 2000 Server [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [CreatePipe function (namedpipeapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/namedpipeapi/nf-namedpipeapi-createpipe) |
| In this tree | [`base/win32/client/pipe.c:25`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/pipe.c#L25) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
_WIN32_WINNT_WIN10 WINBOOL WINAPI CreatePipe(
    PHANDLE hReadPipe,
    PHANDLE hWritePipe,
    LPSECURITY_ATTRIBUTES lpPipeAttributes,
    DWORD nSize
);
```

**Return value.** If the function succeeds, the return value is nonzero. If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Tested example** — `example_CreatePipe` in [`files.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/files.c):

```c
static void example_CreatePipe(void)
{
    HANDLE readEnd = NULL, writeEnd = NULL;
    char buffer[16];
    DWORD n = 0, written = 0;

    /* An anonymous pipe: one end writes, the other reads. Here both ends stay in one process. */
    if (!CreatePipe(&readEnd, &writeEnd, NULL, 0))
        return;
    WriteFile(writeEnd, "ping", 4, &written, NULL);
    ReadFile(readEnd, buffer, sizeof(buffer), &n, NULL);
    wprintf(L"Pipe delivered %lu bytes\n", n);
    CloseHandle(writeEnd);
    CloseHandle(readEnd);
}
```

## Build and test

Compile for an x86_64 Windows target with warnings treated as errors (run it on Windows; the examples are compiled here, not executed):

```sh
zig cc -target x86_64-windows-gnu -std=c11 -Wall -Wextra -Werror files.c -o files.exe -lkernel32 -ladvapi32 -lws2_32 -luser32 -lgdi32 -lshell32
```

With MSVC from a Developer Command Prompt: `cl /nologo /W4 /WX files.c`. MSVC is not run in this checkout; the file is verified only with the zig/clang Windows targets.

## Frequently asked questions

### Q: Why does CreateFileW return INVALID_HANDLE_VALUE and not NULL on failure?

For file handles the documented failure value is `INVALID_HANDLE_VALUE` (`(HANDLE)-1`). `NULL` is a valid but different value for other calls, so comparing against `NULL` misses failures. The example in [`files.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/files.c) checks `h == INVALID_HANDLE_VALUE`.

### Q: Can I call ReadFile on a handle opened with FILE_FLAG_OVERLAPPED without an OVERLAPPED structure?

No. Overlapped handles require an `OVERLAPPED` structure, otherwise the operation completes unpredictably. The examples here open synchronous handles, so `lpOverlapped` is `NULL`.

### Q: Where does the tree implement these functions?

The Win32 wrappers for the file APIs live in `base/win32/client/` (for example `fileopcr.c`, `filehops.c`, `filefind.c`). They call the native services implemented under `base/ntos/io/`. The table on each function lists the exact definition the generator found.

### Q: How do I check that the examples really compile?

Run `zig cc -target x86_64-windows-gnu -std=c11 -Wall -Wextra -Werror files.c -lkernel32` (see the Build line at the top of the file), or run `python3 -m unittest discover -s documentation/tests`, which performs the same compile when a Windows compiler is available. The examples are compiled, not executed, in this checkout.
