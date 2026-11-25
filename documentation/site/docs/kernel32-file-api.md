---
title: File, directory, pipe and mailslot API
sidebar_position: 13
description: CreateFile, ReadFile, WriteFile, directory enumeration, file mapping, named pipes and mailslots — signatures, flags, working examples and the kernel path each call takes.
---

Every file operation in the Win32 API is a thin policy layer over the I/O manager. This page is the
reference for that layer: what each function does, which header declares it, where this checkout
implements it, and what happens on the way to `NtCreateFile`.

All code on this page is plain C against the Windows SDK, so it can be compiled against
`public/sdk/inc` and linked against `public/sdk/lib/i386/kernel32.lib`.

## The one function everything goes through

`CreateFileW` opens files, directories, devices, volumes, consoles, pipes and mailslots. The
disposition table is the part people get wrong:

| `dwCreationDisposition` | Value | If the object exists | If it does not |
| --- | --- | --- | --- |
| `CREATE_NEW` | 1 | Fails, `ERROR_FILE_EXISTS` | Created |
| `CREATE_ALWAYS` | 2 | Truncated, `ERROR_ALREADY_EXISTS` | Created |
| `OPEN_EXISTING` | 3 | Opened | Fails, `ERROR_FILE_NOT_FOUND` |
| `OPEN_ALWAYS` | 4 | Opened, `ERROR_ALREADY_EXISTS` | Created |
| `TRUNCATE_EXISTING` | 5 | Truncated (needs `GENERIC_WRITE`) | Fails, `ERROR_FILE_NOT_FOUND` |

The implementation in this tree is
[`base/win32/client/fileopcr.c:5371`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/win32/client/fileopcr.c#L5371),
and its own routine description states the same contract:

```c
    This API allows the caller to specify the following creation
    dispositions:

      - Create a new file and fail if the file exists ( CREATE_NEW )

      - Create a new file and succeed if it exists ( CREATE_ALWAYS )

      - Open an existing file ( OPEN_EXISTING )

      - Open and existing file or create it if it does not exist (
        OPEN_ALWAYS )

      - Truncate and existing file ( TRUNCATE_EXISTING )
```

### The path translation

Before the kernel sees a path, the Win32 layer converts it. `CreateFileW` calls
`RtlDosPathNameToNtPathName_U`, which turns `C:\dir\file.txt` into
`\??\C:\dir\file.txt`, resolves `\\?\` and `\\.\` prefixes, and rejects paths containing
`..` components in some forms. The call is visible at
`base/win32/client/fileopcr.c` around line 5860:

```c
    TranslationStatus = RtlDosPathNameToNtPathName_U(
                            lpFileName,
                            &ObjectName,
                            NULL,
                            NULL
                            );
    if ( !TranslationStatus ) {
        SetLastError(ERROR_PATH_NOT_FOUND);
        return INVALID_HANDLE_VALUE;
        }
```

The `\??` prefix is the object-manager directory that links to `\DosDevices`, which is why a Win32
path is a *native* path with one extra redirect. Device paths (`\\.\PhysicalDrive0`) bypass the
redirect and reach the device object directly. See
[I/O, file systems and storage](/io-storage) for the object-namespace side.

### The `NtCreateFile` call and the error mapping

At `base/win32/client/fileopcr.c:5866` the translated path is handed to the kernel:

```c
    Status = NtCreateFile(
                &Handle,
                DesiredAccess,
                &ObjectAttributes,
                &IoStatusBlock,
                NULL,
                FileAttributes,
                ShareMode,
                CreateDisposition,
                CreateFlags,
                EaBuffer,
                EaSize
                );
```

The failure path is the part worth memorising, because it shows how three error domains meet:

```c
    if ( !NT_SUCCESS(Status) ) {
        BaseSetLastNTError(Status);
        if ( Status == STATUS_OBJECT_NAME_COLLISION ) {
            SetLastError(ERROR_FILE_EXISTS);
            }
        else if ( Status == STATUS_FILE_IS_A_DIRECTORY ) {
            if ( EndsInSlash ) {
                SetLastError(ERROR_PATH_NOT_FOUND);
                }
            else {
                SetLastError(ERROR_ACCESS_DENIED);
                }
            }
        return INVALID_HANDLE_VALUE;
        }
```

`STATUS_OBJECT_NAME_COLLISION` is the kernel's "name already exists" status. It is mapped to
`ERROR_FILE_EXISTS`, but the **disposition** decides whether that is a failure at all: for
`CREATE_ALWAYS` the kernel returns success with `IoStatusBlock.Information == FILE_OVERWRITTEN`, and
the wrapper reports it as `ERROR_ALREADY_EXISTS` while still returning a valid handle:

```c
    if ( (dwCreationDisposition == CREATE_ALWAYS && IoStatusBlock.Information == FILE_OVERWRITTEN) ||
         (dwCreationDisposition == OPEN_ALWAYS && IoStatusBlock.Information == FILE_OPENED) ){
        SetLastError(ERROR_ALREADY_EXISTS);
        }
    else {
        SetLastError(0);
        }
```

That is why `GetLastError() == ERROR_ALREADY_EXISTS` with a valid handle is **not** an error. Checking
only `GetLastError` instead of the return value is a real bug pattern.

## Reading and writing

`ReadFile` and `WriteFile` live in
[`base/win32/client/filehops.c:213`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/win32/client/filehops.c#L213)
and `:424`. They take an optional `OVERLAPPED`, and the behaviour differs by how the handle was
opened:

| Handle opened with | `lpOverlapped` | Behaviour |
| --- | --- | --- |
| No `FILE_FLAG_OVERLAPPED` | `NULL` | Synchronous; returns after completion |
| No `FILE_FLAG_OVERLAPPED` | Non-`NULL` | Uses `Offset`/`OffsetHigh`, still waits |
| `FILE_FLAG_OVERLAPPED` | Non-`NULL` | May return `FALSE` with `ERROR_IO_PENDING` |
| `FILE_FLAG_OVERLAPPED` | `NULL` | Fails with `ERROR_INVALID_PARAMETER` |

The routine description in the tree is explicit that `lpNumberOfBytesRead` is zeroed before any I/O,
so a failed call leaves it at zero:

```c
    lpNumberOfBytesRead - Returns the number of bytes read by this call.
        This parameter is always set to 0 before doing any IO or error
        checking.
```

### A complete, correct example

```c
#include <windows.h>
#include <stdio.h>

int wmain(int argc, wchar_t **argv)
{
    if (argc != 2) {
        fwprintf(stderr, L"usage: %s <file>\n", argv[0]);
        return 2;
    }

    HANDLE hFile = CreateFileW(
        argv[1],
        GENERIC_READ,
        FILE_SHARE_READ,          // let other readers open it too
        NULL,                     // default security descriptor
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL | FILE_FLAG_SEQUENTIAL_SCAN,
        NULL);                    // no template file

    if (hFile == INVALID_HANDLE_VALUE) {
        // INVALID_HANDLE_VALUE, not NULL: the classic CreateFile trap.
        fwprintf(stderr, L"CreateFileW failed, error %lu\n", GetLastError());
        return 1;
    }

    // 1 MiB buffer: larger than the cache manager's read-ahead granularity,
    // but not so large that we commit a huge private block.
    BYTE buffer[64 * 1024];
    DWORD bytesRead = 0;
    ULONGLONG total = 0;

    for (;;) {
        if (!ReadFile(hFile, buffer, sizeof(buffer), &bytesRead, NULL)) {
            fwprintf(stderr, L"ReadFile failed, error %lu\n", GetLastError());
            CloseHandle(hFile);
            return 1;
        }
        if (bytesRead == 0) {          // EOF: TRUE with a zero count
            break;
        }
        total += bytesRead;
        // ... consume buffer[0 .. bytesRead-1] here
    }

    CloseHandle(hFile);
    wprintf(L"%llu bytes read\n", total);
    return 0;
}
```

Three details the example encodes:

1. `INVALID_HANDLE_VALUE` is the failure sentinel for `CreateFile`; `NULL` is not.
2. `ReadFile` returning `TRUE` with `*bytesRead == 0` means end of file, not failure.
3. `CloseHandle` is mandatory. The kernel reclaims the handle at process exit, but a long-lived
   process that leaks file handles eventually exhausts the handle table.

### Overlapped I/O

```c
#include <windows.h>

typedef struct {
    OVERLAPPED ov;
    HANDLE     hFile;
    BYTE       buffer[4096];
} READ_CONTEXT;

void ReadSomeAsync(HANDLE hFile, READ_CONTEXT *ctx)
{
    ZeroMemory(&ctx->ov, sizeof(ctx->ov));
    ctx->ov.Offset = 0;
    ctx->ov.OffsetHigh = 0;
    ctx->ov.hEvent = CreateEventW(NULL, TRUE, FALSE, NULL);  // manual reset

    if (!ReadFile(hFile, ctx->buffer, sizeof(ctx->buffer), NULL, &ctx->ov)) {
        if (GetLastError() != ERROR_IO_PENDING) {
            // real failure
            CloseHandle(ctx->ov.hEvent);
            return;
        }
        // pending: completion arrives via the event or GetOverlappedResult
    }

    DWORD bytes = 0;
    if (GetOverlappedResult(hFile, &ctx->ov, &bytes, TRUE)) {
        // ctx->buffer[0 .. bytes-1] is valid
    }
    CloseHandle(ctx->ov.hEvent);
}
```

Two rules that the tree enforces in `NtReadFile`:

- The `OVERLAPPED` must stay valid until completion. The kernel keeps a pointer to it; freeing it
  early corrupts kernel memory.
- `hEvent` must be a **manual-reset** event if more than one thread can wait, because the I/O
  manager signals it and does not reset it.

## File position and size

| Function | Purpose | Implementation | Documentation |
| --- | --- | --- | --- |
| `SetFilePointer` | 32-bit position, returns old position | `base/win32/client/filehops.c:694` | [SetFilePointer](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-setfilepointer) |
| `SetFilePointerEx` | 64-bit position, returns a `BOOL` | `filehops.c:880` | [SetFilePointerEx](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-setfilepointerex) |
| `GetFileSize` | 32-bit size, high half out-of-band | `filehops.c:1839` | [GetFileSize](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-getfilesize) |
| `GetFileSizeEx` | 64-bit `LARGE_INTEGER` | `filehops.c:1904` | [GetFileSizeEx](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-getfilesizeex) |
| `GetFileType` | Disk / character / pipe / remote | `filehops.c:89` | [GetFileType](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-getfiletype) |
| `SetEndOfFile` | Truncate or extend at the current pointer | `filehops.c:592` | [SetEndOfFile](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-setendoffile) |
| `GetFileInformationByHandle` | `BY_HANDLE_FILE_INFORMATION` | `filehops.c:1039` | [GetFileInformationByHandle](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-getfileinformationbyhandle) |
| `GetFileTime` / `SetFileTime` | Creation / access / write times | `filehops.c:1131`, `:1227` | [GetFileTime](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-getfiletime) |
| `FlushFileBuffers` | Force data to stable storage | `filehops.c:1334` | [FlushFileBuffers](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-flushfilebuffers) |
| `LockFile` / `UnlockFile` | Mandatory byte-range locks | `filehops.c:1396`, `:1622` | [LockFile](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-lockfile) |

`SetFilePointer` returns `0xFFFFFFFF` on failure **and** `0xFFFFFFFF` is a valid position, so the
only correct test is:

```c
DWORD high = 0;
DWORD low = SetFilePointer(hFile, 0, &high, FILE_CURRENT);
if (low == INVALID_SET_FILE_POINTER && GetLastError() != NO_ERROR) {
    // real failure
}
```

`SetFilePointerEx` avoids the ambiguity by returning a `BOOL` and giving the position through an
out parameter. Prefer it in new code.

## Directory enumeration

`FindFirstFileW`, `FindNextFileW` and `FindClose` are in
`base/win32/client/filefind.c:128`, `:263` and `:448`. They build on `NtQueryDirectoryFile`, which
is why the handle returned by `FindFirstFileW` is a real kernel handle and must be closed.

```c
#include <windows.h>
#include <stdio.h>

int wmain(void)
{
    WIN32_FIND_DATAW fd;
    HANDLE hFind = FindFirstFileW(L"C:\\Windows\\*.exe", &fd);
    if (hFind == INVALID_HANDLE_VALUE) {
        wprintf(L"no matches, error %lu\n", GetLastError());
        return 0;                       // "no files" is not necessarily an error
    }

    do {
        wprintf(L"%-40ls %10lu bytes\n",
                fd.cFileName,
                ((ULONGLONG)fd.nFileSizeHigh << 32) | fd.nFileSizeLow);
    } while (FindNextFileW(hFind, &fd));

    DWORD err = GetLastError();
    if (err != ERROR_NO_MORE_FILES) {
        wprintf(L"enumeration failed, error %lu\n", err);
    }

    FindClose(hFind);
    return 0;
}
```

Rules the API imposes:

- `FindFirstFileW` returns `INVALID_HANDLE_VALUE` on failure. Never pass that to `FindNextFileW`.
- `FindNextFileW` sets `ERROR_NO_MORE_FILES` at the end. Any other error is a real failure.
- The directory enumeration is a **snapshot with a cursor**. Files created after the find started
  may or may not appear.
- `fd.cFileName` is a leaf name, not a path. Join it to the directory you searched.

The implementation supports the `FINDEX_INFO_LEVELS` and `FINDEX_SEARCH_OPS` variants through
`FindFirstFileExW`; `filefind.c` contains the whole family.

## File mapping

A file mapping turns a file (or the paging file) into address space. `CreateFileMappingW` is at
`base/win32/client/filemap.c:76`, `MapViewOfFile` at `:377`, `UnmapViewOfFile` at `:675`.

```c
#include <windows.h>
#include <stdio.h>

int wmain(void)
{
    HANDLE hFile = CreateFileW(L"C:\\pagefile.sys", GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE,
                               NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE) { wprintf(L"open failed %lu\n", GetLastError()); return 1; }

    HANDLE hMap = CreateFileMappingW(hFile, NULL, PAGE_READONLY, 0, 0, NULL);
    if (!hMap) { wprintf(L"map failed %lu\n", GetLastError()); CloseHandle(hFile); return 1; }

    // Map the first 4 KiB, rounded to the allocation granularity by the OS.
    SYSTEM_INFO si;
    GetSystemInfo(&si);
    SIZE_T view = (4096 + si.dwAllocationGranularity - 1) & ~(SIZE_T)(si.dwAllocationGranularity - 1);

    LPVOID base = MapViewOfFile(hMap, FILE_MAP_READ, 0, 0, view);
    if (!base) { wprintf(L"view failed %lu\n", GetLastError()); CloseHandle(hMap); CloseHandle(hFile); return 1; }

    const BYTE *p = (const BYTE *)base;
    wprintf(L"first byte: 0x%02X\n", p[0]);

    UnmapViewOfFile(base);
    CloseHandle(hMap);
    CloseHandle(hFile);
    return 0;
}
```

The kernel path is `NtCreateSection` (`base/ntos/mm/creasect.c:136`) followed by
`NtMapViewOfSection` (`base/ntos/mm/mapview.c:199`). `MapViewOfFile` is a view of a **section
object**, not a copy: writes through `FILE_MAP_WRITE` are visible to every other process mapping the
same section, which is the basis of shared memory.

| Function | Purpose | Documentation |
| --- | --- | --- |
| `CreateFileMappingW` | Create a section object backed by a file or paging file | [CreateFileMappingW](https://learn.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-createfilemappingw) |
| `OpenFileMappingW` | Open a named section by name | [OpenFileMappingW](https://learn.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-openfilemappingw) |
| `MapViewOfFile` / `MapViewOfFileEx` | Map a view at an OS-chosen or specified address | [MapViewOfFile](https://learn.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-mapviewoffile) |
| `UnmapViewOfFile` | Release the view | [UnmapViewOfFile](https://learn.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-unmapviewoffile) |
| `FlushViewOfFile` | Dirty pages to the backing file | [FlushViewOfFile](https://learn.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-flushviewoffile) |

## Paths, directories and attributes

| Function | Purpose | Implementation | Documentation |
| --- | --- | --- | --- |
| `GetCurrentDirectoryW` | Process current directory | `base/win32/client/curdir.c:315` | [GetCurrentDirectoryW](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-getcurrentdirectoryw) |
| `SetCurrentDirectoryW` | Change it (per-drive state on Windows) | `curdir.c:420` | [SetCurrentDirectoryW](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-setcurrentdirectoryw) |
| `GetFullPathNameW` | Resolve relative against the current directory | `curdir.c:190` | [GetFullPathNameW](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-getfullpathnamew) |
| `SearchPathW` | Search a path list for a file | `pathmisc.c:1291` | [SearchPathW](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-searchpathw) |
| `GetTempPathW` | `TMP`, `TEMP`, `USERPROFILE`, then `Windows` | `pathmisc.c:1591` | [GetTempPathW](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-gettemppathw) |
| `GetFileAttributesW` | Attribute bits, or `INVALID_FILE_ATTRIBUTES` | `filemisc.c:262` | [GetFileAttributesW](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-getfileattributesw) |
| `SetFileAttributesW` | Set attribute bits | `filemisc.c:73` | [SetFileAttributesW](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-setfileattributesw) |
| `CreateDirectoryW` | Create one directory level | `dir.c:52` | [CreateDirectoryW](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-createdirectoryw) |
| `RemoveDirectoryW` | Remove an empty directory | `dir.c:987` | [RemoveDirectoryW](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-removedirectoryw) |
| `DeleteFileW` | Unlink a file | `filemisc.c:531` | [DeleteFileW](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-deletefilew) |
| `MoveFileW` | Rename or move | `filemisc.c:1179` | [MoveFileW](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-movefilew) |
| `CopyFileW` | Copy, optionally fail if the destination exists | `fileopcr.c:752` | [CopyFileW](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-copyfilew) |

The current directory is **per-drive** on Windows: `C:` and `D:` have independent current
directories, and a path of the form `D:file.txt` means "file.txt in D:'s current directory", not
"D:\file.txt". That is why `SetCurrentDirectoryW` keeps a per-drive table in `curdir.c`.

## Named pipes

`CreatePipe` (`base/win32/client/pipe.c:27`) is the anonymous-pipe helper: it creates a named pipe
with a unique name, returns read and write handles, and is what the C runtime uses for `popen`.
Named pipes proper are in `base/win32/client/namepipe.c`:

| Function | Purpose | Implementation | Documentation |
| --- | --- | --- | --- |
| `CreateNamedPipeW` | Server: create a pipe instance | `namepipe.c` | [CreateNamedPipeW](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-createnamedpipew) |
| `ConnectNamedPipe` | Server: wait for a client | `namepipe.c` | [ConnectNamedPipe](https://learn.microsoft.com/en-us/windows/win32/api/namedpipeapi/nf-namedpipeapi-connectnamedpipe) |
| `CreateFileW` | Client: open `\\.\pipe\name` | `fileopcr.c:5371` | [CreateFileW](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-createfilew) |
| `PeekNamedPipe` | Non-destructive read of pending bytes | `namepipe.c:1220` | [PeekNamedPipe](https://learn.microsoft.com/en-us/windows/win32/api/namedpipeapi/nf-namedpipeapi-peeknamedpipe) |
| `WaitNamedPipeW` | Client: wait for an instance to be free | `namepipe.c:1697` | [WaitNamedPipeW](https://learn.microsoft.com/en-us/windows/win32/api/namedpipeapi/nf-namedpipeapi-waitnamedpipew) |
| `TransactNamedPipe` | Write request + read reply in one call | `namepipe.c:1374` | [TransactNamedPipe](https://learn.microsoft.com/en-us/windows/win32/api/namedpipeapi/nf-namedpipeapi-transactnamedpipe) |
| `CreatePipe` | Anonymous read/write pair | `pipe.c:27` | [CreatePipe](https://learn.microsoft.com/en-us/windows/win32/api/namedpipeapi/nf-namedpipeapi-createpipe) |

The in-tree driver behind them is `base/fs/npfs` (named pipes) and `base/fs/mailslot`
(mailslots). A pipe is a file object, so the same `ReadFile`/`WriteFile`/`CloseHandle` calls apply.

### A minimal pipe server

```c
#include <windows.h>
#include <stdio.h>

int wmain(void)
{
    HANDLE hPipe = CreateNamedPipeW(
        L"\\\\.\\pipe\\neo-wiki-demo",
        PIPE_ACCESS_DUPLEX,
        PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT,
        1,                       // one instance
        512, 512,                // output / input buffer sizes
        0,                       // default timeout
        NULL);                   // default security

    if (hPipe == INVALID_HANDLE_VALUE) {
        wprintf(L"CreateNamedPipeW failed %lu\n", GetLastError());
        return 1;
    }

    wprintf(L"waiting for a client...\n");
    BOOL ok = ConnectNamedPipe(hPipe, NULL)
              ? TRUE
              : (GetLastError() == ERROR_PIPE_CONNECTED);

    if (ok) {
        wchar_t reply[] = L"hello from the pipe server";
        DWORD written = 0;
        WriteFile(hPipe, reply, (DWORD)(wcslen(reply) * sizeof(wchar_t)), &written, NULL);
    }

    CloseHandle(hPipe);
    return 0;
}
```

`ConnectNamedPipe` can return `FALSE` with `ERROR_PIPE_CONNECTED` when the client connected between
`CreateNamedPipe` and `ConnectNamedPipe`. Treating that as a failure is a classic bug.

## Mailslots

Mailslots are one-way, unreliable, broadcast-capable. `CreateMailslotW` is at
`base/win32/client/mailslot.c:25`, and the driver is `base/fs/mailslot`.

| Function | Purpose | Documentation |
| --- | --- | --- |
| `CreateMailslotW` | Create a mailslot (`\\.\mailslot\name`) | [CreateMailslotW](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-createmailslotw) |
| `GetMailslotInfo` | Query message size, next message, timeout | [GetMailslotInfo](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-getmailslotinfo) |
| `SetMailslotInfo` | Change the read timeout | [SetMailslotInfo](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-setmailslotinfo) |

A mailslot is implemented on top of a named pipe in this tree; `mailslot.c` contains the shim, and
`base/fs/mailslot` the filesystem.

## Function reference table

| Function | Header | Implementation | Official documentation |
| --- | --- | --- | --- |
| `CreateFileW` | `fileapi.h` | `base/win32/client/fileopcr.c:5371` | [CreateFileW](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-createfilew) |
| `ReadFile` | `fileapi.h` | `base/win32/client/filehops.c:213` | [ReadFile](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-readfile) |
| `WriteFile` | `fileapi.h` | `base/win32/client/filehops.c:424` | [WriteFile](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-writefile) |
| `CloseHandle` | `handleapi.h` | `base/win32/client/handle.c:24` | [CloseHandle](https://learn.microsoft.com/en-us/windows/win32/api/handleapi/nf-handleapi-closehandle) |
| `GetFileType` | `fileapi.h` | `base/win32/client/filehops.c:89` | [GetFileType](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-getfiletype) |
| `SetFilePointer` | `fileapi.h` | `base/win32/client/filehops.c:694` | [SetFilePointer](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-setfilepointer) |
| `SetFilePointerEx` | `fileapi.h` | `base/win32/client/filehops.c:880` | [SetFilePointerEx](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-setfilepointerex) |
| `GetFileSize` | `fileapi.h` | `base/win32/client/filehops.c:1839` | [GetFileSize](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-getfilesize) |
| `GetFileSizeEx` | `fileapi.h` | `base/win32/client/filehops.c:1904` | [GetFileSizeEx](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-getfilesizeex) |
| `SetEndOfFile` | `fileapi.h` | `base/win32/client/filehops.c:592` | [SetEndOfFile](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-setendoffile) |
| `FlushFileBuffers` | `fileapi.h` | `base/win32/client/filehops.c:1334` | [FlushFileBuffers](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-flushfilebuffers) |
| `LockFile` | `fileapi.h` | `base/win32/client/filehops.c:1396` | [LockFile](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-lockfile) |
| `UnlockFile` | `fileapi.h` | `base/win32/client/filehops.c:1622` | [UnlockFile](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-unlockfile) |
| `GetFileInformationByHandle` | `fileapi.h` | `base/win32/client/filehops.c:1039` | [GetFileInformationByHandle](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-getfileinformationbyhandle) |
| `GetFileTime` | `fileapi.h` | `base/win32/client/filehops.c:1131` | [GetFileTime](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-getfiletime) |
| `SetFileTime` | `fileapi.h` | `base/win32/client/filehops.c:1227` | [SetFileTime](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-setfiletime) |
| `FindFirstFileW` | `fileapi.h` | `base/win32/client/filefind.c:128` | [FindFirstFileW](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-findfirstfilew) |
| `FindNextFileW` | `fileapi.h` | `base/win32/client/filefind.c:263` | [FindNextFileW](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-findnextfilew) |
| `FindClose` | `fileapi.h` | `base/win32/client/filefind.c:448` | [FindClose](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-findclose) |
| `CreateFileMappingW` | `memoryapi.h` | `base/win32/client/filemap.c:76` | [CreateFileMappingW](https://learn.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-createfilemappingw) |
| `MapViewOfFile` | `memoryapi.h` | `base/win32/client/filemap.c:377` | [MapViewOfFile](https://learn.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-mapviewoffile) |
| `UnmapViewOfFile` | `memoryapi.h` | `base/win32/client/filemap.c:675` | [UnmapViewOfFile](https://learn.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-unmapviewoffile) |
| `OpenFileMappingW` | `memoryapi.h` | `base/win32/client/filemap.c:318` | [OpenFileMappingW](https://learn.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-openfilemappingw) |
| `GetFullPathNameW` | `fileapi.h` | `base/win32/client/curdir.c:190` | [GetFullPathNameW](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-getfullpathnamew) |
| `GetCurrentDirectoryW` | `fileapi.h` | `base/win32/client/curdir.c:315` | [GetCurrentDirectoryW](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-getcurrentdirectoryw) |
| `SetCurrentDirectoryW` | `fileapi.h` | `base/win32/client/curdir.c:420` | [SetCurrentDirectoryW](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-setcurrentdirectoryw) |
| `SearchPathW` | `fileapi.h` | `base/win32/client/pathmisc.c:1291` | [SearchPathW](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-searchpathw) |
| `GetTempPathW` | `fileapi.h` | `base/win32/client/pathmisc.c:1591` | [GetTempPathW](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-gettemppathw) |
| `GetFileAttributesW` | `fileapi.h` | `base/win32/client/filemisc.c:262` | [GetFileAttributesW](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-getfileattributesw) |
| `SetFileAttributesW` | `fileapi.h` | `base/win32/client/filemisc.c:73` | [SetFileAttributesW](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-setfileattributesw) |
| `DeleteFileW` | `fileapi.h` | `base/win32/client/filemisc.c:531` | [DeleteFileW](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-deletefilew) |
| `MoveFileW` | `fileapi.h` | `base/win32/client/filemisc.c:1179` | [MoveFileW](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-movefilew) |
| `CopyFileW` | `fileapi.h` | `base/win32/client/fileopcr.c:752` | [CopyFileW](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-copyfilew) |
| `CreateDirectoryW` | `fileapi.h` | `base/win32/client/dir.c:52` | [CreateDirectoryW](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-createdirectoryw) |
| `RemoveDirectoryW` | `fileapi.h` | `base/win32/client/dir.c:987` | [RemoveDirectoryW](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-removedirectoryw) |
| `CreatePipe` | `namedpipeapi.h` | `base/win32/client/pipe.c:27` | [CreatePipe](https://learn.microsoft.com/en-us/windows/win32/api/namedpipeapi/nf-namedpipeapi-createpipe) |
| `PeekNamedPipe` | `namedpipeapi.h` | `base/win32/client/namepipe.c:1220` | [PeekNamedPipe](https://learn.microsoft.com/en-us/windows/win32/api/namedpipeapi/nf-namedpipeapi-peeknamedpipe) |
| `WaitNamedPipeW` | `namedpipeapi.h` | `base/win32/client/namepipe.c:1697` | [WaitNamedPipeW](https://learn.microsoft.com/en-us/windows/win32/api/namedpipeapi/nf-namedpipeapi-waitnamedpipew) |
| `TransactNamedPipe` | `namedpipeapi.h` | `base/win32/client/namepipe.c:1374` | [TransactNamedPipe](https://learn.microsoft.com/en-us/windows/win32/api/namedpipeapi/nf-namedpipeapi-transactnamedpipe) |
| `CreateMailslotW` | `winbase.h` | `base/win32/client/mailslot.c:25` | [CreateMailslotW](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-createmailslotw) |
| `GetMailslotInfo` | `winbase.h` | `base/win32/client/mailslot.c:193` | [GetMailslotInfo](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-getmailslotinfo) |
| `SetMailslotInfo` | `winbase.h` | `base/win32/client/mailslot.c:308` | [SetMailslotInfo](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-setmailslotinfo) |

## Frequently asked questions

### Q: Why does `CreateFileW` return a handle when `GetLastError` says `ERROR_ALREADY_EXISTS`?

Because `ERROR_ALREADY_EXISTS` is a **success-with-history** code. For `CREATE_ALWAYS` the kernel
reports `FILE_OVERWRITTEN` in `IoStatusBlock.Information`, and for `OPEN_ALWAYS` it reports
`FILE_OPENED`. `CreateFileW` turns those into `ERROR_ALREADY_EXISTS` but returns the handle. Only
`INVALID_HANDLE_VALUE` means failure. The tree shows this explicitly at the end of
`base/win32/client/fileopcr.c`.

### Q: Why is `ReadFile` returning zero bytes but `TRUE`?

That is end of file. `ReadFile` only returns `FALSE` on an actual error; a zero count is a valid
short read. Check `GetLastError` only when the return value is `FALSE`.

### Q: Why does my `ReadFile` on a pipe block forever?

Because the pipe is in byte mode and the client has not written anything. Use `PeekNamedPipe` to
poll, `SetNamedPipeHandleState` with `PIPE_NOWAIT` (discouraged), or overlapped I/O with a timeout.
`base/fs/npfs` implements the blocking behaviour; `PeekNamedPipe` is at
`base/win32/client/namepipe.c:1220`.

### Q: Can I use `ReadFile` on a directory handle?

Only with `FILE_FLAG_BACKUP_SEMANTICS` and only for `ReadFile`-style directory reads in some
filesystems. The supported way is `FindFirstFileW` or `NtQueryDirectoryFile`. Opening a directory
without `FILE_FLAG_BACKUP_SEMANTICS` fails with `ERROR_ACCESS_DENIED`.

### Q: What is the difference between `FILE_SHARE_READ` and `GENERIC_READ`?

`GENERIC_READ` is the access you request for the handle. `FILE_SHARE_*` is the sharing you grant to
other openers. They are independent: you can open with `GENERIC_READ` and allow others to write
(`FILE_SHARE_WRITE`), or deny all sharing and fail any concurrent open.

### Q: Where is `NtReadFile` implemented?

`base/ntos/io/iomgr/read.c:39`. It builds an IRP with `MajorFunction = IRP_MJ_READ`, sets the
`ByteOffset` from the caller or the file object's current position, and sends it to the filesystem
through `IofCallDriver`. See [I/O, file systems and storage](/io-storage) for the IRP lifecycle.

### Q: How do I find every file API in this tree?

The implementation files are grouped by family rather than by API name:

```bash
ls base/win32/client | grep -E '^(file|dir|path|pipe|namepipe|mailslot|handle|curdir)'
rg -n '^(Create|Read|Write|Find|Delete|Move|Copy|Get|Set)[A-Za-z]*File' base/win32/client/*.c | head -40
```

`filehops.c` is handle operations, `filemisc.c` is path/attribute operations, `filefind.c` is
enumeration, `filemap.c` is mappings, `namepipe.c` and `mailslot.c` are the IPC file types.

### Q: Is `CreateFile` one function or two?

Two exports and one implementation. `CreateFileA` converts the path and calls `CreateFileW`; the
kernel only ever sees the wide form. The A wrapper is at
`base/win32/client/fileopcr.c:5331` and the W implementation at `:5371`.

### Q: What happens if I forget `CloseHandle`?

The handle stays open until the process exits. The kernel's object manager keeps the file object
alive, which can block deletes (the file is "in use"), hold locks, and consume handle-table quota.
Under a handle audit the leak is visible as a growing handle count in Task Manager.

### Q: Where can I read the official parameter documentation?

The `fileapi.h` index at [https://learn.microsoft.com/en-us/windows/win32/api/fileapi/](https://learn.microsoft.com/en-us/windows/win32/api/fileapi/) lists every
function with its signature, parameter semantics and requirements. Each row in the table above links
the specific function page.
