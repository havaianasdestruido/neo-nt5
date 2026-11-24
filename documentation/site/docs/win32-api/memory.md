---
title: "Memory, heaps and file mappings"
sidebar_position: 15
description: "VirtualAlloc, file mapping views, private heaps and process heap calls: official signatures, NT-tree locations and compiled examples."
---

# Memory, heaps and file mappings

Win32 exposes three layers of memory: virtual pages (`VirtualAlloc`), file-backed or pagefile-backed sections (`CreateFileMappingW` and `MapViewOfFile`), and heaps (`HeapAlloc`, plus the process default heap). Each layer is implemented by the memory manager in `base/ntos/mm`, and the user-mode heap in `base/ntos/rtl/heap.c` (`RtlAllocateHeap`).

The rules that cause most bugs: `MEM_RELEASE` needs size 0; closing a mapping handle while views are still mapped is allowed, but unmapping first is the clear pattern; and a heap block can only be freed to the heap that allocated it.

This page covers **13 functions**: [`VirtualAlloc`](#virtualalloc), [`VirtualFree`](#virtualfree), [`VirtualProtect`](#virtualprotect), [`VirtualQuery`](#virtualquery), [`CreateFileMappingW`](#createfilemappingw), [`MapViewOfFile`](#mapviewoffile), [`UnmapViewOfFile`](#unmapviewoffile), [`HeapCreate`](#heapcreate), [`HeapAlloc`](#heapalloc), [`HeapFree`](#heapfree), [`HeapDestroy`](#heapdestroy), [`GetProcessHeap`](#getprocessheap), [`LocalFree`](#localfree).

## Shared setup

Paste this block at the top of your source file, then one or more example functions below, then call them from `main`. The complete, compiled file is [memory.c](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/memory.c).

```c
/*
 * Win32 memory examples for the NEONT 5 documentation site.
 *
 * Build with MinGW-w64 or zig cc (any Windows target):
 *     zig cc -target x86_64-windows-gnu -std=c11 -Wall -Wextra -Werror memory.c -o memory.exe -lkernel32
 * Build with MSVC:
 *     cl /nologo /W4 /WX memory.c
 *
 * Every allocation made by an example is released by the same example.
 */
#define UNICODE
#define _UNICODE
#include <windows.h>
#include <stdio.h>
#include <wchar.h>
#include <string.h>

/* Shared helper: a page-aligned region of one page, committed and writable. */
static void *alloc_one_page(void)
{
    SYSTEM_INFO si;
    GetSystemInfo(&si);
    return VirtualAlloc(NULL, si.dwPageSize, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
}
```

## Functions

## VirtualAlloc

Reserves, commits, or changes the state  of a region of pages in the virtual address space of the calling process. Memory allocated by this function is automatically initialized to zero. To allocate memory in the address space of another process, use the [VirtualAllocEx](https://learn.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-virtualallocex) function.

| Attribute | Value |
| --- | --- |
| Header | `memoryapi.h` (include `Windows.h, Memoryapi.h`) |
| Library | onecore.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [VirtualAlloc function (memoryapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-virtualalloc) |
| In this tree | [`base/win32/client/gmem.c:886`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/gmem.c#L886) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
LPVOID WINAPI VirtualAlloc(
    LPVOID lpAddress,
    SIZE_T dwSize,
    DWORD flAllocationType,
    DWORD flProtect
);
```

**Return value.** If the function succeeds, the return value is the base address of the allocated region of pages. If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Tested example** — `example_VirtualAlloc` in [`memory.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/memory.c):

```c
static void example_VirtualAlloc(void)
{
    SYSTEM_INFO si;
    GetSystemInfo(&si);
    /* Reserve and commit one page. Passing NULL lets the system choose the address. */
    char *p = (char *)VirtualAlloc(NULL, si.dwPageSize, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    if (p == NULL) {
        wprintf(L"VirtualAlloc failed: %lu\n", GetLastError());
        return;
    }
    strcpy_s(p, si.dwPageSize, "committed");
    wprintf(L"Page at %p holds \"%S\"\n", (void *)p, p);
    VirtualFree(p, 0, MEM_RELEASE);   /* MEM_RELEASE requires size 0 */
}
```

## VirtualFree

Releases, decommits, or releases and decommits a region of pages within the virtual address space of the calling process. To free memory allocated in another process by the [VirtualAllocEx](https://learn.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-virtualallocex) function, use the [VirtualFreeEx](https://learn.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-virtualfreeex) function.

| Attribute | Value |
| --- | --- |
| Header | `memoryapi.h` (include `Windows.h, Memoryapi.h`) |
| Library | onecore.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [VirtualFree function (memoryapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-virtualfree) |
| In this tree | [`base/win32/client/gmem.c:906`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/gmem.c#L906) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
WINBOOL WINAPI VirtualFree(
    LPVOID lpAddress,
    SIZE_T dwSize,
    DWORD dwFreeType
);
```

**Return value.** If the function succeeds, the return value is nonzero. If the function fails, the return value is 0 (zero). To get extended error information, call [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Tested example** — `example_VirtualFree` in [`memory.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/memory.c):

```c
static void example_VirtualFree(void)
{
    void *p = alloc_one_page();
    if (p == NULL) return;
    /* MEM_DECOMMIT keeps the reservation; MEM_RELEASE frees the whole region. */
    if (VirtualFree(p, 0, MEM_RELEASE))
        wprintf(L"Region released\n");
}
```

## VirtualProtect

Changes the protection on a region of committed pages in the virtual address space of the calling process. To change the access protection of any process, use the [VirtualProtectEx](https://learn.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-virtualprotectex) function.

| Attribute | Value |
| --- | --- |
| Header | `memoryapi.h` (include `Windows.h, Memoryapi.h`) |
| Library | onecore.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [VirtualProtect function (memoryapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-virtualprotect) |
| In this tree | [`base/win32/client/gmem.c:1012`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/gmem.c#L1012) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
WINBOOL WINAPI VirtualProtect(
    LPVOID lpAddress,
    SIZE_T dwSize,
    DWORD flNewProtect,
    PDWORD lpflOldProtect
);
```

**Return value.** If the function succeeds, the return value is nonzero. If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Tested example** — `example_VirtualProtect` in [`memory.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/memory.c):

```c
static void example_VirtualProtect(void)
{
    DWORD oldProtect = 0;
    void *p = alloc_one_page();
    if (p == NULL) return;
    /* Make the page read-only, then restore the previous protection. */
    if (VirtualProtect(p, 1, PAGE_READONLY, &oldProtect))
        wprintf(L"Protection was 0x%08lX\n", oldProtect);
    VirtualProtect(p, 1, oldProtect, &oldProtect);
    VirtualFree(p, 0, MEM_RELEASE);
}
```

## VirtualQuery

Retrieves information about a range of pages in the virtual address space of the calling process. To retrieve information about a range of pages in the address space of another process, use the [VirtualQueryEx](nf-memoryapi-virtualqueryex.md) function.

| Attribute | Value |
| --- | --- |
| Header | `memoryapi.h` (include `Windows.h, Memoryapi.h`) |
| Library | onecore.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [VirtualQuery function (memoryapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-virtualquery) |
| In this tree | [`base/win32/client/gmem.c:1080`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/gmem.c#L1080) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
define FILE_MAP_LARGE_PAGES 0x20000000 SIZE_T WINAPI VirtualQuery(
    LPCVOID lpAddress,
    PMEMORY_BASIC_INFORMATION lpBuffer,
    SIZE_T dwLength
);
```

**Return value.** The return value is the actual number of bytes returned in the information buffer. If the function fails, the return value is zero. To get extended error information, call [GetLastError](../errhandlingapi/nf-errhandlingapi-getlasterror.md). Possible error values include **ERROR_INVALID_PARAMETER**.

**Tested example** — `example_VirtualQuery` in [`memory.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/memory.c):

```c
static void example_VirtualQuery(void)
{
    MEMORY_BASIC_INFORMATION mbi;
    void *p = alloc_one_page();
    if (p == NULL) return;
    if (VirtualQuery(p, &mbi, sizeof(mbi)) == sizeof(mbi))
        wprintf(L"State 0x%lX, protect 0x%lX, region size %Iu\n", mbi.State, mbi.Protect, mbi.RegionSize);
    VirtualFree(p, 0, MEM_RELEASE);
}
```

## CreateFileMappingW

Creates or opens a named or unnamed file mapping object for a specified file. To specify the NUMA node for the physical memory, see [CreateFileMappingNuma](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-createfilemappingnumaa).

| Attribute | Value |
| --- | --- |
| Header | `memoryapi.h` (include `Windows.h, Memoryapi.h`) |
| Library | onecore.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps only] |
| Minimum server | Windows Server 2003 [desktop apps only] |
| Character set | CreateFileMappingW (Unicode) and CreateFileMappingA (ANSI) |
| Official reference | [CreateFileMappingW function (memoryapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-createfilemappingw) |
| In this tree | [`base/win32/client/filemap.c:74`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/filemap.c#L74) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
HANDLE WINAPI CreateFileMappingW(
    HANDLE hFile,
    LPSECURITY_ATTRIBUTES lpFileMappingAttributes,
    DWORD flProtect,
    DWORD dwMaximumSizeHigh,
    DWORD dwMaximumSizeLow,
    LPCWSTR lpName
);
```

**Return value.** If the function succeeds, the return value is a handle to the newly created file mapping object. If the object exists before the function call, the function returns a handle to the existing object (with its current size, not the specified size), and [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **ERROR_ALREADY_EXISTS**.

**Tested example** — `example_CreateFileMappingW` in [`memory.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/memory.c):

```c
static void example_CreateFileMappingW(void)
{
    /* Anonymous (pagefile-backed) mapping of 4096 bytes; INVALID_HANDLE_VALUE selects the pagefile. */
    HANDLE map = CreateFileMappingW(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, 4096, L"Local\\NEONT5-DocsMapping");
    if (map == NULL) {
        wprintf(L"CreateFileMappingW failed: %lu\n", GetLastError());
        return;
    }
    wprintf(L"Mapping created%ls\n", GetLastError() == ERROR_ALREADY_EXISTS ? L" (already existed)" : L"");
    CloseHandle(map);
}
```

## MapViewOfFile

Maps a view of a file mapping into the address space of a calling process. To specify a suggested base address for the view, use the [MapViewOfFileEx](https://learn.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-mapviewoffileex) function. However, this practice is not recommended.

| Attribute | Value |
| --- | --- |
| Header | `memoryapi.h` (include `Windows.h, Memoryapi.h`) |
| Library | onecore.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps only] |
| Minimum server | Windows Server 2003 [desktop apps only] |
| Character set | - |
| Official reference | [MapViewOfFile function (memoryapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-mapviewoffile) |
| In this tree | [`base/win32/client/filemap.c:375`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/filemap.c#L375) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
LPVOID WINAPI MapViewOfFile(
    HANDLE hFileMappingObject,
    DWORD dwDesiredAccess,
    DWORD dwFileOffsetHigh,
    DWORD dwFileOffsetLow,
    SIZE_T dwNumberOfBytesToMap
);
```

**Return value.** If the function succeeds, the return value is the starting address of the mapped view. If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Tested example** — `example_MapViewOfFile` in [`memory.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/memory.c):

```c
static void example_MapViewOfFile(void)
{
    HANDLE map = CreateFileMappingW(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, 4096, NULL);
    if (map == NULL) return;
    /* Map the whole object read/write, then unmap it before closing the mapping handle. */
    char *view = (char *)MapViewOfFile(map, FILE_MAP_WRITE, 0, 0, 4096);
    if (view != NULL) {
        strcpy_s(view, 4096, "through the view");
        wprintf(L"View says: %S\n", view);
        UnmapViewOfFile(view);
    }
    CloseHandle(map);
}
```

## UnmapViewOfFile

Unmaps a mapped view of a file from the calling process's address space.

| Attribute | Value |
| --- | --- |
| Header | `memoryapi.h` (include `Windows.h, Memoryapi.h`) |
| Library | onecore.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [UnmapViewOfFile function (memoryapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-unmapviewoffile) |
| In this tree | [`base/win32/client/filemap.c:673`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/filemap.c#L673) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
WINBOOL WINAPI UnmapViewOfFile(
    LPCVOID lpBaseAddress
);
```

**Return value.** If the function succeeds, the return value is nonzero. If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Tested example** — `example_UnmapViewOfFile` in [`memory.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/memory.c):

```c
static void example_UnmapViewOfFile(void)
{
    HANDLE map = CreateFileMappingW(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, 4096, NULL);
    if (map == NULL) return;
    void *view = MapViewOfFile(map, FILE_MAP_READ, 0, 0, 0);   /* 0 = map the whole object */
    if (view != NULL && UnmapViewOfFile(view))
        wprintf(L"View unmapped\n");
    CloseHandle(map);
}
```

## HeapCreate

Creates a private heap object that can be used by the calling process. The function reserves space in the virtual address space of the process and allocates physical storage for a specified initial portion of this block.

| Attribute | Value |
| --- | --- |
| Header | `heapapi.h` (include `Windows.h`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [HeapCreate function (heapapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/heapapi/nf-heapapi-heapcreate) |
| In this tree | [`base/win32/client/lmem.c:619`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/lmem.c#L619) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
HANDLE WINAPI HeapCreate(
    DWORD flOptions,
    SIZE_T dwInitialSize,
    SIZE_T dwMaximumSize
);
```

**Return value.** If the function succeeds, the return value is a handle to the newly created heap. If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Tested example** — `example_HeapCreate` in [`memory.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/memory.c):

```c
static void example_HeapCreate(void)
{
    /* A private heap: 64 KB initial size, growable (maximum 0). Destroy it when done. */
    HANDLE heap = HeapCreate(0, 64 * 1024, 0);
    if (heap == NULL) {
        wprintf(L"HeapCreate failed: %lu\n", GetLastError());
        return;
    }
    wprintf(L"Private heap created\n");
    HeapDestroy(heap);
}
```

## HeapAlloc

Allocates a block of memory from a heap. The allocated memory is not movable.

| Attribute | Value |
| --- | --- |
| Header | `heapapi.h` (include `Windows.h`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [HeapAlloc function (heapapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/heapapi/nf-heapapi-heapalloc) |
| In this tree | [`base/ntos/rtl/heap.c:1487`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/ntos/rtl/heap.c#L1487) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
LPVOID WINAPI HeapAlloc(
    HANDLE hHeap,
    DWORD dwFlags,
    SIZE_T dwBytes
);
```

**Return value.** If the function succeeds, the return value is a pointer to the allocated memory block. If the function fails and you have not specified **HEAP_GENERATE_EXCEPTIONS**, the return value is **NULL**.

**Tested example** — `example_HeapAlloc` in [`memory.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/memory.c):

```c
static void example_HeapAlloc(void)
{
    HANDLE heap = GetProcessHeap();
    /* HEAP_ZERO_MEMORY zeroes the block; the returned block is 8- or 16-byte aligned. */
    int *numbers = (int *)HeapAlloc(heap, HEAP_ZERO_MEMORY, 16 * sizeof(int));
    if (numbers == NULL) return;
    numbers[0] = 42;
    wprintf(L"Heap block first value: %d\n", numbers[0]);
    HeapFree(heap, 0, numbers);
}
```

## HeapFree

Frees a memory block allocated from a heap by the [HeapAlloc](https://learn.microsoft.com/en-us/windows/win32/api/heapapi/nf-heapapi-heapalloc) or [HeapReAlloc](https://learn.microsoft.com/en-us/windows/win32/api/heapapi/nf-heapapi-heaprealloc) function.

| Attribute | Value |
| --- | --- |
| Header | `heapapi.h` (include `Windows.h`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [HeapFree function (heapapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/heapapi/nf-heapapi-heapfree) |
| In this tree | No definition extracted by the generator from `base/win32`, `base/screg`, `net/sockets`, `windows/core`, `base/ntos`, `base/ntdll`, `base/subsys`, `base/fs` or `net/published`. A fixed-string search found call sites only, so the implementation is either outside this checkout or reached through a macro. Search the [generated index](/reference/) by name. |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
WINBOOL WINAPI HeapFree(
    HANDLE hHeap,
    DWORD dwFlags,
    LPVOID lpMem
);
```

**Return value.** If the function succeeds, the return value is nonzero. If the function fails, the return value is zero. An application can call [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) for extended error information.

**Tested example** — `example_HeapFree` in [`memory.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/memory.c):

```c
static void example_HeapFree(void)
{
    HANDLE heap = GetProcessHeap();
    void *p = HeapAlloc(heap, 0, 128);
    if (p != NULL) {
        /* Must be the same heap handle that allocated the block. */
        if (HeapFree(heap, 0, p))
            wprintf(L"Block freed\n");
    }
}
```

## HeapDestroy

Destroys the specified heap object. **HeapDestroy** de-commits and releases all the pages of a private heap object, and it invalidates the handle to the heap.

| Attribute | Value |
| --- | --- |
| Header | `heapapi.h` (include `Windows.h`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [HeapDestroy function (heapapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/heapapi/nf-heapapi-heapdestroy) |
| In this tree | [`base/win32/client/lmem.c:665`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/lmem.c#L665) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
WINBOOL WINAPI HeapDestroy(
    HANDLE hHeap
);
```

**Return value.** If the function succeeds, the return value is nonzero. If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Tested example** — `example_HeapDestroy` in [`memory.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/memory.c):

```c
static void example_HeapDestroy(void)
{
    HANDLE heap = HeapCreate(0, 0, 0);
    if (heap == NULL) return;
    void *p = HeapAlloc(heap, 0, 256);   /* everything in the heap is released by HeapDestroy */
    (void)p;
    if (HeapDestroy(heap))
        wprintf(L"Heap and its blocks destroyed\n");
}
```

## GetProcessHeap

Retrieves a handle to the default heap of the calling process. This handle can then be used in subsequent calls to the heap functions.

| Attribute | Value |
| --- | --- |
| Header | `heapapi.h` (include `Windows.h`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [GetProcessHeap function (heapapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/heapapi/nf-heapapi-getprocessheap) |
| In this tree | [`base/win32/client/lmem.c:828`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/lmem.c#L828), [`base/subsys/posix/client/crtsup.c:231`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/subsys/posix/client/crtsup.c#L231) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
HANDLE WINAPI GetProcessHeap(
    VOID
);
```

**Return value.** If the function succeeds, the return value is a handle to the calling process's heap. If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Tested example** — `example_GetProcessHeap` in [`memory.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/memory.c):

```c
static void example_GetProcessHeap(void)
{
    /* The default heap of this process. Do NOT destroy it; use HeapAlloc/HeapFree on it. */
    HANDLE heap = GetProcessHeap();
    if (heap != NULL)
        wprintf(L"Default heap handle: %p\n", (void *)heap);
}
```

## LocalFree

Frees the specified local memory object and invalidates its handle. **Note**  The local functions have greater overhead and provide fewer features than other memory management functions. New applications should use the [heap functions](https://learn.microsoft.com/en-us/windows/win32/Memory/heap-functions) unless documentation states that a local function should be used. For more information, see [Global and Local Functions](https://learn.microsoft.com/en-us/windows/win32/Memory/global-and-local-functions).

| Attribute | Value |
| --- | --- |
| Header | `winbase.h` (include `Windows.h`) |
| Library | Kernel32.lib (DLL `Kernel32.dll`) |
| Minimum client | Windows XP [desktop apps / UWP apps] |
| Minimum server | Windows Server 2003 [desktop apps / UWP apps] |
| Character set | - |
| Official reference | [LocalFree function (winbase.h)](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-localfree) |
| In this tree | [`base/win32/client/lmem.c:519`](https://github.com/havaianasdestruido/neo-nt5/blob/b5251b626275c8db05693098200c3cf84068ebb4/base/win32/client/lmem.c#L519) |

**Prototype** (from the mingw-w64 SDK headers bundled with zig 0.17.1):

```c
HLOCAL WINAPI LocalFree(
    HLOCAL hMem
);
```

**Return value.** If the function succeeds, the return value is **NULL**. If the function fails, the return value is equal to a handle to the local memory object. To get extended error information, call [GetLastError](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Tested example** — `example_LocalFree` in [`memory.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/documentation/examples/win32/memory.c):

```c
static void example_LocalFree(void)
{
    /* Memory returned by FormatMessageW with FORMAT_MESSAGE_ALLOCATE_BUFFER is released with LocalFree. */
    LPWSTR text = NULL;
    DWORD n = FormatMessageW(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                             NULL, ERROR_FILE_NOT_FOUND, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                             (LPWSTR)&text, 0, NULL);
    if (n > 0 && text != NULL) {
        wprintf(L"Message: %ls", text);
        LocalFree(text);
    }
}
```

## Build and test

Compile for an x86_64 Windows target with warnings treated as errors (run it on Windows; the examples are compiled here, not executed):

```sh
zig cc -target x86_64-windows-gnu -std=c11 -Wall -Wextra -Werror memory.c -o memory.exe -lkernel32 -ladvapi32 -lws2_32 -luser32 -lgdi32 -lshell32
```

With MSVC from a Developer Command Prompt: `cl /nologo /W4 /WX memory.c`. MSVC is not run in this checkout; the file is verified only with the zig/clang Windows targets.

## Frequently asked questions

### Q: Why must VirtualFree with MEM_RELEASE pass size 0?

The whole reservation is released at once, from the base address that `VirtualAlloc` returned. Passing a non-zero size with `MEM_RELEASE` makes the call fail.

### Q: Does UnmapViewOfFile close the mapping?

No. It removes the view from the address space. The mapping object stays alive until `CloseHandle` is called on it.

### Q: Can I HeapFree a pointer that came from VirtualAlloc?

No. Each heap block belongs to the heap that allocated it. Use `VirtualFree` for pages, and `HeapFree` only with the same heap handle.

### Q: Where is the memory manager?

In `base/ntos/mm`, documented in [Kernel and executive](/kernel). The user-mode wrappers are in `base/win32/client/gmem.c` (`VirtualAlloc` is defined there at line 886).
