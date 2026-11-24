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

/* @fn VirtualAlloc */
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

/* @fn VirtualFree */
static void example_VirtualFree(void)
{
    void *p = alloc_one_page();
    if (p == NULL) return;
    /* MEM_DECOMMIT keeps the reservation; MEM_RELEASE frees the whole region. */
    if (VirtualFree(p, 0, MEM_RELEASE))
        wprintf(L"Region released\n");
}

/* @fn VirtualProtect */
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

/* @fn VirtualQuery */
static void example_VirtualQuery(void)
{
    MEMORY_BASIC_INFORMATION mbi;
    void *p = alloc_one_page();
    if (p == NULL) return;
    if (VirtualQuery(p, &mbi, sizeof(mbi)) == sizeof(mbi))
        wprintf(L"State 0x%lX, protect 0x%lX, region size %Iu\n", mbi.State, mbi.Protect, mbi.RegionSize);
    VirtualFree(p, 0, MEM_RELEASE);
}

/* @fn CreateFileMappingW */
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

/* @fn MapViewOfFile */
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

/* @fn UnmapViewOfFile */
static void example_UnmapViewOfFile(void)
{
    HANDLE map = CreateFileMappingW(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, 4096, NULL);
    if (map == NULL) return;
    void *view = MapViewOfFile(map, FILE_MAP_READ, 0, 0, 0);   /* 0 = map the whole object */
    if (view != NULL && UnmapViewOfFile(view))
        wprintf(L"View unmapped\n");
    CloseHandle(map);
}

/* @fn HeapCreate */
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

/* @fn HeapAlloc */
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

/* @fn HeapFree */
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

/* @fn HeapDestroy */
static void example_HeapDestroy(void)
{
    HANDLE heap = HeapCreate(0, 0, 0);
    if (heap == NULL) return;
    void *p = HeapAlloc(heap, 0, 256);   /* everything in the heap is released by HeapDestroy */
    (void)p;
    if (HeapDestroy(heap))
        wprintf(L"Heap and its blocks destroyed\n");
}

/* @fn GetProcessHeap */
static void example_GetProcessHeap(void)
{
    /* The default heap of this process. Do NOT destroy it; use HeapAlloc/HeapFree on it. */
    HANDLE heap = GetProcessHeap();
    if (heap != NULL)
        wprintf(L"Default heap handle: %p\n", (void *)heap);
}

/* @fn LocalFree */
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

int main(void)
{
    example_VirtualAlloc();
    example_VirtualFree();
    example_VirtualProtect();
    example_VirtualQuery();
    example_CreateFileMappingW();
    example_MapViewOfFile();
    example_UnmapViewOfFile();
    example_HeapCreate();
    example_HeapAlloc();
    example_HeapFree();
    example_HeapDestroy();
    example_GetProcessHeap();
    example_LocalFree();
    return 0;
}
