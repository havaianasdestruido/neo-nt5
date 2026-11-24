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

/* @fn CreateFileW */
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

/* @fn ReadFile */
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

/* @fn WriteFile */
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

/* @fn CloseHandle */
static void example_CloseHandle(void)
{
    HANDLE event = CreateEventW(NULL, TRUE, FALSE, NULL);
    if (event != NULL) {
        if (CloseHandle(event))
            wprintf(L"Handle closed; further use of the value is invalid\n");
    }
}

/* @fn GetFileSizeEx */
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

/* @fn SetFilePointerEx */
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

/* @fn FlushFileBuffers */
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

/* @fn GetFileAttributesExW */
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

/* @fn FindFirstFileW */
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

/* @fn FindNextFileW */
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

/* @fn FindClose */
static void example_FindClose(void)
{
    WIN32_FIND_DATAW find;
    HANDLE h = FindFirstFileW(L"C:\\Windows\\win.ini", &find);
    if (h != INVALID_HANDLE_VALUE) {
        /* Every successful FindFirstFile handle must be closed with FindClose. */
        FindClose(h);
    }
}

/* @fn DeleteFileW */
static void example_DeleteFileW(void)
{
    wchar_t path[MAX_PATH];
    temp_file(path, L"neont5-delete.txt");
    HANDLE h = CreateFileW(path, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_TEMPORARY, NULL);
    if (h != INVALID_HANDLE_VALUE) CloseHandle(h);   /* must be closed before deleting it */
    if (DeleteFileW(path))
        wprintf(L"Deleted %ls\n", path);
}

/* @fn MoveFileExW */
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

/* @fn CreateDirectoryW */
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

/* @fn RemoveDirectoryW */
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

/* @fn GetFinalPathNameByHandleW */
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

/* @fn GetTempPathW */
static void example_GetTempPathW(void)
{
    wchar_t dir[MAX_PATH];
    DWORD len = GetTempPathW(MAX_PATH, dir);
    /* len is the number of characters copied, excluding the terminating NUL, and ends in a backslash. */
    if (len > 0 && len < MAX_PATH)
        wprintf(L"Temp directory: %ls\n", dir);
}

/* @fn DeviceIoControl */
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

/* @fn CreatePipe */
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

int main(void)
{
    example_CreateFileW();
    example_ReadFile();
    example_WriteFile();
    example_CloseHandle();
    example_GetFileSizeEx();
    example_SetFilePointerEx();
    example_FlushFileBuffers();
    example_GetFileAttributesExW();
    example_FindFirstFileW();
    example_FindNextFileW();
    example_FindClose();
    example_DeleteFileW();
    example_MoveFileExW();
    example_CreateDirectoryW();
    example_RemoveDirectoryW();
    example_GetFinalPathNameByHandleW();
    example_GetTempPathW();
    example_DeviceIoControl();
    example_CreatePipe();
    return 0;
}
