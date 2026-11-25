---
title: Memory management API
sidebar_position: 15
description: VirtualAlloc, heaps, page protection, memory-mapped views, cross-process memory and the kernel memory manager behind each call.
---

Windows exposes memory through three different abstractions, and choosing the wrong one is the
usual cause of fragmentation, exhaustion or `ERROR_NOT_ENOUGH_MEMORY`:

```text
+-------------------------------------------------------------+
| Virtual memory   VirtualAlloc / VirtualFree / VirtualProtect |  page-granular, per-process
+-------------------------------------------------------------+
| Heaps            HeapCreate / HeapAlloc / HeapFree           |  sub-allocates committed pages
+-------------------------------------------------------------+
| Sections         CreateFileMapping / MapViewOfFile           |  file- or pagefile-backed views
+-------------------------------------------------------------+
```

All three bottom out in the memory manager at `base/ntos/mm`, which turns requests into page-table
changes, page-file I/O and section objects.

## Virtual memory

### `VirtualAlloc`

```c
LPVOID VirtualAlloc(
    LPVOID lpAddress,
    SIZE_T dwSize,
    DWORD  flAllocationType,
    DWORD  flProtect
    );
```

Implementation: [`base/win32/client/gmem.c:888`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/win32/client/gmem.c#L888).
It is a thin wrapper over `VirtualAllocEx` with the current process pseudo-handle:

```c
    return VirtualAllocEx(
                NtCurrentProcess(),
                lpAddress,
                dwSize,
                flAllocationType,
                flProtect
                );
```

and `VirtualAllocEx` (`gmem.c:919`) validates that a requested base address is at least the
allocation granularity before calling `NtAllocateVirtualMemory`
(`base/ntos/mm/allocvm.c:83`).

The two-step reserve/commit model is the core concept:

| `flAllocationType` | Effect | Physical storage |
| --- | --- | --- |
| `MEM_RESERVE` | Reserves address space, no storage | None |
| `MEM_COMMIT` | Charges committed pages, zero-fills on first touch | On first access |
| `MEM_RESERVE \| MEM_COMMIT` | Both in one call | On first access |
| `MEM_RESET` | Marks pages as uninteresting; contents may be discarded | None |
| `MEM_RELEASE` (with `VirtualFree`) | Releases the reservation | Frees the range |
| `MEM_DECOMMIT` (with `VirtualFree`) | Returns committed pages, keeps the reservation | Frees the pages |

Protection values are page-level: `PAGE_NOACCESS`, `PAGE_READONLY`, `PAGE_READWRITE`,
`PAGE_EXECUTE`, `PAGE_EXECUTE_READ`, `PAGE_EXECUTE_READWRITE`, `PAGE_GUARD`,
`PAGE_NOCACHE`, `PAGE_WRITECOMBINE`. The execute bits matter on x86 with DEP; on x64 they are
enforced separately.

### Example: reserve, commit and protect

```c
#include <windows.h>
#include <stdio.h>

int wmain(void)
{
    SYSTEM_INFO si;
    GetSystemInfo(&si);
    SIZE_T granularity = si.dwAllocationGranularity;   // typically 64 KiB

    // Reserve 1 MiB of address space without committing any storage.
    BYTE *base = (BYTE *)VirtualAlloc(NULL, 1024 * 1024, MEM_RESERVE, PAGE_NOACCESS);
    if (!base) { wprintf(L"reserve failed %lu\n", GetLastError()); return 1; }

    // Commit the first 4 KiB read/write.
    BYTE *p = (BYTE *)VirtualAlloc(base, 4096, MEM_COMMIT, PAGE_READWRITE);
    if (!p) { wprintf(L"commit failed %lu\n", GetLastError()); return 1; }

    p[0] = 0x41;                       // first touch: page is zero-filled, then written
    wprintf(L"byte 0 = 0x%02X\n", p[0]);

    // Make it read-only, then try to write through it.
    DWORD oldProtect = 0;
    if (!VirtualProtect(p, 4096, PAGE_READONLY, &oldProtect)) {
        wprintf(L"protect failed %lu\n", GetLastError());
    }
    _SEH2_TRY {
        p[0] = 0x42;                    // raises STATUS_ACCESS_VIOLATION
    } _SEH2_EXCEPT(EXCEPTION_EXECUTE_HANDLER) {
        wprintf(L"write to read-only page raised an exception\n");
    } _SEH2_END;

    VirtualFree(base, 0, MEM_RELEASE);  // size must be 0 for MEM_RELEASE
    return 0;
}
```

### `VirtualFree`

```c
BOOL VirtualFree(LPVOID lpAddress, SIZE_T dwSize, DWORD dwFreeType);
```

- `MEM_RELEASE`: `dwSize` **must be 0**, and `lpAddress` must be the base returned by the original
  `VirtualAlloc`. The entire reservation is released.
- `MEM_DECOMMIT`: `dwSize` is a byte range, rounded to page boundaries; the reservation survives.

Mixing these up is the classic "why did my 1 MiB reservation disappear" bug.

### `VirtualProtect` and `VirtualQuery`

`VirtualProtect` (`gmem.c:1014`) changes protection and returns the previous protection through
`lpflOldProtect`. It works on committed pages only; calling it on a reserved-but-uncommitted range
fails with `ERROR_INVALID_ADDRESS`.

`VirtualQuery` (`gmem.c:1082`) fills a `MEMORY_BASIC_INFORMATION`:

```c
typedef struct _MEMORY_BASIC_INFORMATION {
    PVOID  BaseAddress;      // region base
    PVOID  AllocationBase;   // allocation base (the VirtualAlloc base)
    DWORD  AllocationProtect;
    SIZE_T RegionSize;       // bytes with identical state/protection/type
    DWORD  State;            // MEM_COMMIT / MEM_RESERVE / MEM_FREE
    DWORD  Protect;          // current protection
    DWORD  Type;             // MEM_PRIVATE / MEM_MAPPED / MEM_IMAGE
} MEMORY_BASIC_INFORMATION;
```

A walk of the address space is a loop over `VirtualQuery` with the returned `RegionSize`:

```c
BYTE *address = NULL;
MEMORY_BASIC_INFORMATION mbi;
while (VirtualQuery(address, &mbi, sizeof(mbi)) == sizeof(mbi)) {
    // ... inspect mbi.State, mbi.Protect, mbi.Type ...
    address = (BYTE *)mbi.BaseAddress + mbi.RegionSize;
}
```

`VirtualQueryEx` (`gmem.c:1098`) is the cross-process version, and it is how tools such as
`base/win32/client/toolhelp.c` enumerate another process's address space.

### Cross-process virtual memory

| Function | Purpose | Implementation | Documentation |
| --- | --- | --- | --- |
| `VirtualAllocEx` | Allocate in another process | `gmem.c:919` | [VirtualAllocEx](https://learn.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-virtualallocex) |
| `VirtualFreeEx` | Free in another process | `gmem.c:959` | [VirtualFreeEx](https://learn.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-virtualfreeex) |
| `VirtualProtectEx` | Change protection in another process | `gmem.c:1032` | [VirtualProtectEx](https://learn.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-virtualprotectex) |
| `VirtualQueryEx` | Query another process | `gmem.c:1098` | [VirtualQueryEx](https://learn.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-virtualqueryex) |
| `ReadProcessMemory` | Copy from another process | `process.c:6169` | [ReadProcessMemory](https://learn.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-readprocessmemory) |
| `WriteProcessMemory` | Copy to another process | `process.c:6252` | [WriteProcessMemory](https://learn.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-writeprocessmemory) |
| `FlushInstructionCache` | Flush modified code | `gmem.c:1251` | [FlushInstructionCache](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-flushinstructioncache) |

`WriteProcessMemory` followed by `FlushInstructionCache` is the required pair when patching code in
another process. Without the flush, the target may execute stale instructions from its pipeline.

`ReadProcessMemory`/`WriteProcessMemory` require `PROCESS_VM_READ`/`PROCESS_VM_WRITE` (and often
`PROCESS_QUERY_INFORMATION`). They are also the mechanism behind `GetWindowText` across processes:
the window manager asks the target process's user-mode side to read the text.

## Heaps

### The forwarder trick

`HeapAlloc`, `HeapFree`, `HeapReAlloc` and `HeapSize` are **not implemented in kernel32**. They are
export forwarders to `ntdll`, declared in
[`base/win32/client/kernel32.src`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/win32/client/kernel32.src):

```text
    HeapAlloc = NTDLL.RtlAllocateHeap
    HeapFree = NTDLL.RtlFreeHeap
    HeapReAlloc = NTDLL.RtlReAllocateHeap
    HeapSize = NTDLL.RtlSizeHeap
```

The file contains 48 such forwarders, including `GetLastError = NTDLL.RtlGetLastWin32Error`,
`EnterCriticalSection = NTDLL.RtlEnterCriticalSection` and `RtlZeroMemory = NTDLL.RtlZeroMemory`. That
is why the heap implementation lives in `base/ntos/rtl/heap.c` even though the export is kernel32's.

`RtlAllocateHeap` is at `base/ntos/rtl/heap.c` (with `#pragma alloc_text(PAGE, RtlAllocateHeap)` at
line 198), and `RtlCreateHeap`'s own description lists the heap flags:

```c
        HEAP_NO_SERIALIZE - if set, then allocations and deallocations on
                         this heap are NOT synchronized by these routines.
```

### Heap API

| Function | Purpose | Implementation | Documentation |
| --- | --- | --- | --- |
| `HeapCreate` | Create a private heap | `base/win32/client/lmem.c:621` | [HeapCreate](https://learn.microsoft.com/en-us/windows/win32/api/heapapi/nf-heapapi-heapcreate) |
| `HeapDestroy` | Destroy a heap and all its allocations | `lmem.c:667` | [HeapDestroy](https://learn.microsoft.com/en-us/windows/win32/api/heapapi/nf-heapapi-heapdestroy) |
| `HeapAlloc` | Allocate from a heap | forwarder to `RtlAllocateHeap` | [HeapAlloc](https://learn.microsoft.com/en-us/windows/win32/api/heapapi/nf-heapapi-heapalloc) |
| `HeapReAlloc` | Resize, move or in-place | forwarder to `RtlReAllocateHeap` | [HeapReAlloc](https://learn.microsoft.com/en-us/windows/win32/api/heapapi/nf-heapapi-heaprealloc) |
| `HeapFree` | Free | forwarder to `RtlFreeHeap` | [HeapFree](https://learn.microsoft.com/en-us/windows/win32/api/heapapi/nf-heapapi-heapfree) |
| `HeapSize` | Query the allocated size | forwarder to `RtlSizeHeap` | [HeapSize](https://learn.microsoft.com/en-us/windows/win32/api/heapapi/nf-heapapi-heapsize) |
| `HeapValidate` | Validate the heap structure | `lmem.c:819` | [HeapValidate](https://learn.microsoft.com/en-us/windows/win32/api/heapapi/nf-heapapi-heapvalidate) |
| `HeapWalk` | Enumerate heap blocks | `lmem.c:884` | [HeapWalk](https://learn.microsoft.com/en-us/windows/win32/api/heapapi/nf-heapapi-heapwalk) |
| `HeapLock` / `HeapUnlock` | Serialize access | `lmem.c:863`, `:874` | [HeapLock](https://learn.microsoft.com/en-us/windows/win32/api/heapapi/nf-heapapi-heaplock) |
| `HeapCompact` | Coalesce free blocks | `lmem.c:851` | [HeapCompact](https://learn.microsoft.com/en-us/windows/win32/api/heapapi/nf-heapapi-heapcompact) |
| `HeapSetInformation` | Enable termination on corruption, etc. | `lmem.c:964` | [HeapSetInformation](https://learn.microsoft.com/en-us/windows/win32/api/heapapi/nf-heapapi-heapsetinformation) |
| `HeapQueryInformation` | Query compatibility/compat values | `lmem.c:989` | [HeapQueryInformation](https://learn.microsoft.com/en-us/windows/win32/api/heapapi/nf-heapapi-heapqueryinformation) |

`GetProcessHeap` (`lmem.c:830`) returns the default heap, which is what `malloc` and `new` use in
the Microsoft CRT. A private heap is worth creating when:

- You need to free thousands of small objects at once (`HeapDestroy` instead of individual frees).
- You need `HEAP_NO_SERIALIZE` for a single-threaded allocator.
- You want heap tagging or low-fragmentation behaviour isolated from the process heap.

### Heap flags

| Flag | Effect |
| --- | --- |
| `HEAP_NO_SERIALIZE` | No lock; caller must serialize |
| `HEAP_GENERATE_EXCEPTIONS` | Raise on failure instead of returning `NULL` |
| `HEAP_ZERO_MEMORY` | Zero the allocation |
| `HEAP_CREATE_ENABLE_EXECUTE` | Allow executable memory from this heap |
| `HEAP_REALLOC_IN_PLACE_ONLY` | Fail if the block must move |
| `HEAP_TAIL_CHECKING_ENABLED` | Check for block overruns |
| `HEAP_FREE_CHECKING_ENABLED` | Fill freed blocks with a pattern |

### Example: a private heap with exception generation

```c
#include <windows.h>
#include <stdio.h>

int wmain(void)
{
    HANDLE hHeap = HeapCreate(0, 0, 0);   // default growable heap
    if (!hHeap) { wprintf(L"HeapCreate failed %lu\n", GetLastError()); return 1; }

    // HEAP_ZERO_MEMORY + HEAP_GENERATE_EXCEPTIONS
    PBYTE p = (PBYTE)HeapAlloc(hHeap, HEAP_ZERO_MEMORY | HEAP_GENERATE_EXCEPTIONS, 4096);
    if (!p) { wprintf(L"alloc failed\n"); HeapDestroy(hHeap); return 1; }

    SIZE_T size = HeapSize(hHeap, 0, p);
    wprintf(L"allocated %zu bytes\n", size);

    // Realloc larger, allowing a move.
    PBYTE q = (PBYTE)HeapReAlloc(hHeap, HEAP_ZERO_MEMORY, p, 64 * 1024);
    if (!q) { wprintf(L"realloc failed\n"); HeapFree(hHeap, 0, p); HeapDestroy(hHeap); return 1; }

    HeapFree(hHeap, 0, q);
    HeapDestroy(hHeap);      // frees everything still allocated
    return 0;
}
```

## Choosing an allocator

| Need | Use | Why |
| --- | --- | --- |
| Small, short-lived objects | CRT `malloc`/`new` or `HeapAlloc` | Sub-allocation amortises page cost |
| Large blocks, controlled lifetime | `VirtualAlloc` | Page-granular, no heap overhead |
| Shared memory between processes | `CreateFileMapping` + `MapViewOfFile` | Section object is the only cross-process primitive |
| Executable memory | `VirtualAlloc` with `PAGE_EXECUTE_READWRITE` | Heap memory is not executable by default |
| Guard pages / stack-like growth | `VirtualAlloc` + `PAGE_GUARD` | Heaps do not expose page protection |
| Many allocations freed together | Private heap + `HeapDestroy` | One call instead of N |

## Function reference table

| Function | Header | Implementation | Documentation |
| --- | --- | --- | --- |
| `VirtualAlloc` | `memoryapi.h` | `base/win32/client/gmem.c:888` | [VirtualAlloc](https://learn.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-virtualalloc) |
| `VirtualFree` | `memoryapi.h` | `base/win32/client/gmem.c:908` | [VirtualFree](https://learn.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-virtualfree) |
| `VirtualProtect` | `memoryapi.h` | `base/win32/client/gmem.c:1014` | [VirtualProtect](https://learn.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-virtualprotect) |
| `VirtualQuery` | `memoryapi.h` | `base/win32/client/gmem.c:1082` | [VirtualQuery](https://learn.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-virtualquery) |
| `VirtualAllocEx` | `memoryapi.h` | `base/win32/client/gmem.c:919` | [VirtualAllocEx](https://learn.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-virtualallocex) |
| `VirtualFreeEx` | `memoryapi.h` | `base/win32/client/gmem.c:959` | [VirtualFreeEx](https://learn.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-virtualfreeex) |
| `VirtualProtectEx` | `memoryapi.h` | `base/win32/client/gmem.c:1032` | [VirtualProtectEx](https://learn.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-virtualprotectex) |
| `VirtualQueryEx` | `memoryapi.h` | `base/win32/client/gmem.c:1098` | [VirtualQueryEx](https://learn.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-virtualqueryex) |
| `ReadProcessMemory` | `memoryapi.h` | `base/win32/client/process.c:6169` | [ReadProcessMemory](https://learn.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-readprocessmemory) |
| `WriteProcessMemory` | `memoryapi.h` | `base/win32/client/process.c:6252` | [WriteProcessMemory](https://learn.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-writeprocessmemory) |
| `FlushInstructionCache` | `processthreadsapi.h` | `base/win32/client/gmem.c:1251` | [FlushInstructionCache](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-flushinstructioncache) |
| `GetSystemInfo` | `sysinfoapi.h` | `base/win32/client/process.c:6636` | [GetSystemInfo](https://learn.microsoft.com/en-us/windows/win32/api/sysinfoapi/nf-sysinfoapi-getsysteminfo) |
| `GetNativeSystemInfo` | `sysinfoapi.h` | `base/win32/client/process.c:6723` | [GetNativeSystemInfo](https://learn.microsoft.com/en-us/windows/win32/api/sysinfoapi/nf-sysinfoapi-getnativesysteminfo) |
| `GetProcessHeap` | `heapapi.h` | `base/win32/client/lmem.c:830` | [GetProcessHeap](https://learn.microsoft.com/en-us/windows/win32/api/heapapi/nf-heapapi-getprocessheap) |
| `HeapCreate` | `heapapi.h` | `base/win32/client/lmem.c:621` | [HeapCreate](https://learn.microsoft.com/en-us/windows/win32/api/heapapi/nf-heapapi-heapcreate) |
| `HeapDestroy` | `heapapi.h` | `base/win32/client/lmem.c:667` | [HeapDestroy](https://learn.microsoft.com/en-us/windows/win32/api/heapapi/nf-heapapi-heapdestroy) |
| `HeapAlloc` | `heapapi.h` | forwarder to `RtlAllocateHeap` (`base/ntos/rtl/heap.c`) | [HeapAlloc](https://learn.microsoft.com/en-us/windows/win32/api/heapapi/nf-heapapi-heapalloc) |
| `HeapReAlloc` | `heapapi.h` | forwarder to `RtlReAllocateHeap` | [HeapReAlloc](https://learn.microsoft.com/en-us/windows/win32/api/heapapi/nf-heapapi-heaprealloc) |
| `HeapFree` | `heapapi.h` | forwarder to `RtlFreeHeap` | [HeapFree](https://learn.microsoft.com/en-us/windows/win32/api/heapapi/nf-heapapi-heapfree) |
| `HeapSize` | `heapapi.h` | forwarder to `RtlSizeHeap` | [HeapSize](https://learn.microsoft.com/en-us/windows/win32/api/heapapi/nf-heapapi-heapsize) |
| `HeapValidate` | `heapapi.h` | `base/win32/client/lmem.c:819` | [HeapValidate](https://learn.microsoft.com/en-us/windows/win32/api/heapapi/nf-heapapi-heapvalidate) |
| `HeapWalk` | `heapapi.h` | `base/win32/client/lmem.c:884` | [HeapWalk](https://learn.microsoft.com/en-us/windows/win32/api/heapapi/nf-heapapi-heapwalk) |
| `HeapLock` | `heapapi.h` | `base/win32/client/lmem.c:863` | [HeapLock](https://learn.microsoft.com/en-us/windows/win32/api/heapapi/nf-heapapi-heaplock) |
| `HeapUnlock` | `heapapi.h` | `base/win32/client/lmem.c:874` | [HeapUnlock](https://learn.microsoft.com/en-us/windows/win32/api/heapapi/nf-heapapi-heapunlock) |
| `HeapCompact` | `heapapi.h` | `base/win32/client/lmem.c:851` | [HeapCompact](https://learn.microsoft.com/en-us/windows/win32/api/heapapi/nf-heapapi-heapcompact) |
| `HeapSetInformation` | `heapapi.h` | `base/win32/client/lmem.c:964` | [HeapSetInformation](https://learn.microsoft.com/en-us/windows/win32/api/heapapi/nf-heapapi-heapsetinformation) |
| `HeapQueryInformation` | `heapapi.h` | `base/win32/client/lmem.c:989` | [HeapQueryInformation](https://learn.microsoft.com/en-us/windows/win32/api/heapapi/nf-heapapi-heapqueryinformation) |
| `IsBadReadPtr` | `winbase.h` | `base/win32/client/process.c:7262` | [IsBadReadPtr](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-isbadreadptr) |
| `IsBadWritePtr` | `winbase.h` | `base/win32/client/process.c:7373` | [IsBadWritePtr](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-isbadwriteptr) |
| `IsBadCodePtr` | `winbase.h` | `base/win32/client/process.c:7482` | [IsBadCodePtr](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-isbadcodeptr) |

## Frequently asked questions

### Q: Why does `VirtualAlloc` need two calls (reserve and commit)?

Because reserving is cheap and committing is not. A process can reserve gigabytes of address space
and commit only the pages it touches, which is how sparse data structures and custom allocators
avoid committing everything up front. `MEM_RESERVE | MEM_COMMIT` in one call is the common case when
you want both immediately.

### Q: What is the difference between `MEM_RELEASE` and `MEM_DECOMMIT`?

`MEM_RELEASE` gives the address space back to the system; the entire reservation is gone and the
address cannot be used again without a new `VirtualAlloc`. `MEM_DECOMMIT` returns the physical/page
file storage but keeps the reservation, so you can recommit later. `MEM_RELEASE` requires
`dwSize == 0` and the exact base address.

### Q: Why is `HeapAlloc` a forwarder to `ntdll`?

Because the heap is implemented once in the NT runtime and both kernel32 and ntdll export it. The
forwarder in `base/win32/client/kernel32.src` (`HeapAlloc = NTDLL.RtlAllocateHeap`) means the
kernel32 export table points at ntdll's implementation rather than duplicating it. That is also why
the source for `HeapAlloc` is in `base/ntos/rtl/heap.c`, not in `base/win32/client`.

### Q: Is `IsBadReadPtr` safe to use?

It is deprecated and racy: it probes the address, but another thread can free the memory between
the probe and your access. Use structured exception handling (`__try`/`__except`) around the actual
access instead, or validate pointers at the API boundary. The implementation at
`base/win32/client/process.c:7262` exists for compatibility.

### Q: How do I allocate executable memory?

`VirtualAlloc(NULL, size, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE)`. Do not use
`HeapAlloc` for code: heap pages are not executable, and DEP will fault on execution. The
`HEAP_CREATE_ENABLE_EXECUTE` flag exists for a private heap but is still less common than a direct
`VirtualAlloc`.

### Q: What does `FlushInstructionCache` actually do?

It invalidates the instruction pipeline for the specified range in the target process. On x86 the
architecture is mostly self-modifying-code coherent, but the API is still required for correctness
across architectures and after `WriteProcessMemory` into code.

### Q: Where is `NtAllocateVirtualMemory` implemented?

`base/ntos/mm/allocvm.c:83`. Its parameters include `ZeroBits`, which constrains the high bits of
the returned address, and `RegionSize`, which is both input (desired size) and output (actual
rounded size). See [Kernel and executive](/kernel) for the memory manager map.

### Q: How do I get the allocation granularity?

`GetSystemInfo` returns `SYSTEM_INFO.dwAllocationGranularity`, typically 64 KiB. It is the minimum
size of a reservation and the alignment of a `MEM_RESERVE` base address. Page size is
`SYSTEM_INFO.dwPageSize`, typically 4 KiB.

### Q: Why did my `VirtualAlloc` of 1 byte succeed and still consume 64 KiB?

Because the minimum reservation is the allocation granularity. The call rounds the size up to a
multiple of 64 KiB, and the region is page-aligned. If you need many small blocks, use a heap.

### Q: Can I rely on `VirtualAlloc` memory being zeroed?

Yes. The memory manager zero-fills committed pages on first touch, so `VirtualAlloc` with
`MEM_COMMIT` returns zeroed memory. `HEAP_ZERO_MEMORY` is the equivalent for heap blocks; without it,
a reused heap block may contain stale data.
