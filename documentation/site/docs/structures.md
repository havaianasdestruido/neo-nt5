---
title: Core structures and constants
sidebar_position: 22
description: The structures every Windows API and native call depends on — UNICODE_STRING, OBJECT_ATTRIBUTES, IO_STATUS_BLOCK, OVERLAPPED, MEMORY_BASIC_INFORMATION, SYSTEM_INFO and the constants they carry.
---

Most Windows API bugs are structure bugs: a wrong `Length`, a missing null terminator, a
`sizeof` that does not match the target architecture, or an `OBJECT_ATTRIBUTES` that points at a
stack string that has gone out of scope. This page collects the structures that appear everywhere,
with the exact declarations from `public/sdk/inc` and the constants that go with them.

Architecture matters: this tree carries 32-bit and 64-bit definitions side by side
(`OBJECT_ATTRIBUTES32`/`64`, `MEMORY_BASIC_INFORMATION32`/`64`, `IO_STATUS_BLOCK32`). When a
structure crosses the 32/64 boundary, the width of `ULONG_PTR`, `SIZE_T` and pointers changes, which
is why the tree has explicit variants.

## Strings

### `UNICODE_STRING`

Declared at [`public/sdk/inc/ntdef.h:1084`](https://github.com/havaianasdestruido/neo-nt5/blob/main/public/sdk/inc/ntdef.h#L1084):

```c
typedef struct _UNICODE_STRING {
    USHORT Length;
    USHORT MaximumLength;
#ifdef MIDL_PASS
    [size_is(MaximumLength / 2), length_is((Length) / 2) ] USHORT * Buffer;
#else // MIDL_PASS
    PWSTR  Buffer;
#endif // MIDL_PASS
} UNICODE_STRING;
typedef UNICODE_STRING *PUNICODE_STRING;
typedef const UNICODE_STRING *PCUNICODE_STRING;
```

The comment above it is the contract:

```c
// Unicode strings are counted 16-bit character strings. If they are
// NULL terminated, Length does not include trailing NULL.
```

| Field | Meaning |
| --- | --- |
| `Length` | Bytes of valid data, excluding any terminator |
| `MaximumLength` | Bytes allocated for `Buffer`, including room for a terminator |
| `Buffer` | Pointer to the first wide character |

Constants: `UNICODE_STRING_MAX_BYTES` is 65534 and `UNICODE_STRING_MAX_CHARS` is 32767 (both
defined at `ntdef.h` for `_WIN32_WINNT >= 0x0501`). That is the hard limit on a native path —
the reason `PLARGE_STRING` exists in the window manager.

### `ANSI_STRING`

The narrow counterpart, with the same layout:

```c
typedef struct _STRING {
    USHORT Length;
    USHORT MaximumLength;
    PCHAR  Buffer;
} STRING, ANSI_STRING, *PANSI_STRING;
```

`RtlAnsiStringToUnicodeString` converts between them and allocates a new buffer. See
[NTDLL runtime](/ntdll-api#strings).

### `LARGE_STRING`

The window manager's string type, used where `UNICODE_STRING` is too short:

```c
typedef struct _LARGE_STRING {
    ULONG Length;        // characters
    ULONG MaximumLength; // characters
    PVOID Buffer;
    BOOLEAN fAllocated;
} LARGE_STRING, *PLARGE_STRING;
```

`NtUserCreateWindowEx` takes two of them (`pstrNVClassName`, `pstrClassName`) — see
[USER](/user32-api#window-creation).

## Objects

### `OBJECT_ATTRIBUTES`

Declared at [`public/sdk/inc/ntdef.h:1254`](https://github.com/havaianasdestruido/neo-nt5/blob/main/public/sdk/inc/ntdef.h#L1254):

```c
typedef struct _OBJECT_ATTRIBUTES {
    ULONG Length;
    HANDLE RootDirectory;
    PUNICODE_STRING ObjectName;
    ULONG Attributes;
    PVOID SecurityDescriptor;        // Points to type SECURITY_DESCRIPTOR
    PVOID SecurityQualityOfService;  // Points to type SECURITY_QUALITY_OF_SERVICE
} OBJECT_ATTRIBUTES;
```

`InitializeObjectAttributes` is the initialiser:

```c
InitializeObjectAttributes(
    OUT POBJECT_ATTRIBUTES p,
    IN PUNICODE_STRING n,
    IN ULONG a,
    IN HANDLE r,
    IN PSECURITY_DESCRIPTOR s
    );
```

It does **not** copy `n` — the pointer must remain valid for the duration of the call. A common
bug is initialising on a local `UNICODE_STRING` and then letting it go out of scope before the
`Nt*` call.

| Attribute | Effect |
| --- | --- |
| `OBJ_INHERIT` | Handle is inheritable by child processes |
| `OBJ_PERMANENT` | Object is not deleted when its last handle closes |
| `OBJ_EXCLUSIVE` | Only one handle at a time |
| `OBJ_CASE_INSENSITIVE` | Name lookup ignores case |
| `OBJ_OPENIF` | Open if it exists, otherwise create |
| `OBJ_OPENLINK` | Open a symbolic link itself, not its target |
| `OBJ_KERNEL_HANDLE` | Handle is valid in any process context |

### `IO_STATUS_BLOCK`

Declared at `public/sdk/inc/wdm.h:3475`:

```c
typedef struct _IO_STATUS_BLOCK {
    union {
        NTSTATUS Status;
        PVOID    Pointer;
    };
    ULONG_PTR Information;
} IO_STATUS_BLOCK, *PIO_STATUS_BLOCK;
```

`Status` is the completion status; `Information` is operation-specific:

| Call | `Information` |
| --- | --- |
| `NtReadFile` / `NtWriteFile` | Bytes transferred |
| `NtCreateFile` | `FILE_CREATED`, `FILE_OPENED`, `FILE_OVERWRITTEN`, `FILE_SUPERSEDED` |
| `NtQueryInformationFile` | Bytes written to the output buffer |
| `NtDeviceIoControlFile` | Bytes written to the output buffer |

### `CLIENT_ID`

```c
typedef struct _CLIENT_ID {
    HANDLE UniqueProcess;
    HANDLE UniqueThread;
} CLIENT_ID, *PCLIENT_ID;
```

These are process and thread **IDs**, not handles. `NtOpenProcess` and `NtOpenThread` use them to
look up the object by ID.

### `LIST_ENTRY`

Declared at `public/sdk/inc/winnt.h:753` and `ntdef.h:1125`:

```c
typedef struct _LIST_ENTRY {
    struct _LIST_ENTRY *Flink;
    struct _LIST_ENTRY *Blink;
} LIST_ENTRY, *PLIST_ENTRY;
```

The kernel uses circular doubly-linked lists everywhere: the ready queue, the wait list, the
handle table, the loader's module list. The macros are `InitializeListHead`, `InsertHeadList`,
`InsertTailList`, `RemoveEntryList`, `IsListEmpty`. A corrupted `Flink`/`Blink` is a use-after-free
waiting to happen; `LIST_ENTRY` is the reason the checked build validates list integrity.

## I/O

### `OVERLAPPED`

Declared at [`public/sdk/inc/winbase.h:227`](https://github.com/havaianasdestruido/neo-nt5/blob/main/public/sdk/inc/winbase.h#L227):

```c
typedef struct _OVERLAPPED {
    ULONG_PTR Internal;
    ULONG_PTR InternalHigh;
    union {
        struct {
            DWORD Offset;
            DWORD OffsetHigh;
        };
        PVOID Pointer;
    };
    HANDLE  hEvent;
} OVERLAPPED, *LPOVERLAPPED;
```

- `Internal` and `InternalHigh` are the I/O status and the number of bytes transferred; do not set
  them yourself.
- `Offset`/`OffsetHigh` form a 64-bit file position for synchronous and overlapped I/O.
- `hEvent` is signalled on completion. If it is `NULL`, the file handle itself is used, which
  requires `SYNCHRONIZE` access and prevents concurrent operations on the same handle.

### `MEMORY_BASIC_INFORMATION`

Declared at [`public/sdk/inc/winnt.h:5050`](https://github.com/havaianasdestruido/neo-nt5/blob/main/public/sdk/inc/winnt.h#L5050):

```c
typedef struct _MEMORY_BASIC_INFORMATION {
    PVOID BaseAddress;
    PVOID AllocationBase;
    DWORD AllocationProtect;
    SIZE_T RegionSize;
    DWORD State;
    DWORD Protect;
    DWORD Type;
} MEMORY_BASIC_INFORMATION, *PMEMORY_BASIC_INFORMATION;
```

| Field | Meaning |
| --- | --- |
| `BaseAddress` | Base of the region with uniform state/protection/type |
| `AllocationBase` | Base of the original `VirtualAlloc` reservation |
| `AllocationProtect` | Protection requested at allocation |
| `RegionSize` | Size of the uniform region, in bytes |
| `State` | `MEM_COMMIT`, `MEM_RESERVE`, `MEM_FREE` |
| `Protect` | Current protection, or `PAGE_NOACCESS`/0 |
| `Type` | `MEM_PRIVATE`, `MEM_MAPPED`, `MEM_IMAGE` |

## System information

### `SYSTEM_INFO`

```c
typedef struct _SYSTEM_INFO {
    union {
        DWORD dwOemId;
        struct { WORD wProcessorArchitecture; WORD wReserved; };
    };
    DWORD     dwPageSize;
    LPVOID    lpMinimumApplicationAddress;
    LPVOID    lpMaximumApplicationAddress;
    DWORD_PTR dwActiveProcessorMask;
    DWORD     dwNumberOfProcessors;
    DWORD     dwProcessorType;
    DWORD     dwAllocationGranularity;
    WORD      wProcessorLevel;
    WORD      wProcessorRevision;
} SYSTEM_INFO, *LPSYSTEM_INFO;
```

`dwPageSize` is typically 4096; `dwAllocationGranularity` is typically 65536. `VirtualAlloc`
reserves in multiples of the granularity and commits in multiples of the page size.

### `STARTUPINFO` and `PROCESS_INFORMATION`

Declared in `public/sdk/inc/winbase.h` and `processthreadsapi.h`:

```c
typedef struct _STARTUPINFOW {
    DWORD  cb;
    LPWSTR lpReserved;
    LPWSTR lpDesktop;
    LPWSTR lpTitle;
    DWORD  dwX, dwY, dwXSize, dwYSize, dwXCountChars, dwYCountChars;
    DWORD  dwFillAttribute, dwFlags;
    WORD   wShowWindow, cbReserved2;
    LPBYTE lpReserved2;
    HANDLE hStdInput, hStdOutput, hStdError;
} STARTUPINFOW, *LPSTARTUPINFOW;

typedef struct _PROCESS_INFORMATION {
    HANDLE hProcess;
    HANDLE hThread;
    DWORD  dwProcessId;
    DWORD  dwThreadId;
} PROCESS_INFORMATION, *LPPROCESS_INFORMATION;
```

`cb` must be `sizeof(STARTUPINFOW)`. The `hStd*` handles are used only when `STARTF_USESTDHANDLES`
is set **and** `bInheritHandles` is `TRUE`.

## Security

### `SECURITY_ATTRIBUTES`

```c
typedef struct _SECURITY_ATTRIBUTES {
    DWORD nLength;
    LPVOID lpSecurityDescriptor;
    BOOL bInheritHandle;
} SECURITY_ATTRIBUTES, *LPSECURITY_ATTRIBUTES;
```

`nLength` must be `sizeof(SECURITY_ATTRIBUTES)`; several APIs validate it and fail with
`ERROR_INVALID_PARAMETER` otherwise. `lpSecurityDescriptor` is `NULL` for the default descriptor;
`bInheritHandle` controls whether child processes inherit the handle.

### `SECURITY_DESCRIPTOR`

The self-relative form is what the APIs store:

```c
typedef struct _SECURITY_DESCRIPTOR {
    UCHAR Revision;
    UCHAR Sbz1;
    USHORT Control;
    PSID Owner;
    PSID Group;
    PACL Sacl;
    PACL Dacl;
} SECURITY_DESCRIPTOR, *PSECURITY_DESCRIPTOR;
```

`InitializeSecurityDescriptor` sets `Revision = SECURITY_DESCRIPTOR_REVISION` and `Control = 0`.
`SetSecurityDescriptorDacl` sets the DACL and the `SE_DACL_PRESENT` control bit.

## Synchronization

### `CRITICAL_SECTION`

```c
typedef struct _RTL_CRITICAL_SECTION {
    PRTL_CRITICAL_SECTION_DEBUG DebugInfo;
    LONG LockCount;
    LONG RecursionCount;
    HANDLE OwningThread;
    HANDLE LockSemaphore;
    ULONG_PTR SpinCount;
} RTL_CRITICAL_SECTION, *PRTL_CRITICAL_SECTION;
```

It is an opaque structure: initialise with `InitializeCriticalSection`, never write the fields
directly. `LockSemaphore` is the kernel event created on first contention.

## Threads

### `CONTEXT`

The thread context is architecture-specific. On x86 it contains `ContextFlags`, `Dr0`-`Dr7`,
`FloatSave`, `SegGs`-`SegSs`, `Edi`-`Eax`, `Ebp`, `Eip`, `SegCs`, `EFlags`, `Esp`, and the extended
registers. `GetThreadContext` requires the thread to be suspended; reading the context of a running
thread returns undefined values.

## Constants you will need

### Memory

| Constant | Value | Meaning |
| --- | --- | --- |
| `MEM_COMMIT` | `0x1000` | Commit pages |
| `MEM_RESERVE` | `0x2000` | Reserve address space |
| `MEM_RESET` | `0x80000` | Discard contents |
| `MEM_RELEASE` | `0x8000` | Release the reservation |
| `MEM_DECOMMIT` | `0x4000` | Decommit pages |
| `PAGE_NOACCESS` | `0x01` | No access |
| `PAGE_READONLY` | `0x02` | Read only |
| `PAGE_READWRITE` | `0x04` | Read/write |
| `PAGE_EXECUTE` | `0x10` | Execute |
| `PAGE_EXECUTE_READ` | `0x20` | Execute/read |
| `PAGE_EXECUTE_READWRITE` | `0x40` | Execute/read/write |
| `PAGE_GUARD` | `0x100` | Guard page (one-shot) |

### File creation

| Constant | Value | Meaning |
| --- | --- | --- |
| `CREATE_NEW` | 1 | Fail if exists |
| `CREATE_ALWAYS` | 2 | Truncate if exists |
| `OPEN_EXISTING` | 3 | Fail if absent |
| `OPEN_ALWAYS` | 4 | Open or create |
| `TRUNCATE_EXISTING` | 5 | Truncate if exists |
| `FILE_SHARE_READ` | `0x1` | Allow other readers |
| `FILE_SHARE_WRITE` | `0x2` | Allow other writers |
| `FILE_SHARE_DELETE` | `0x4` | Allow delete/rename |
| `FILE_FLAG_OVERLAPPED` | `0x40000000` | Overlapped I/O |
| `FILE_FLAG_BACKUP_SEMANTICS` | `0x02000000` | Open directories |
| `FILE_FLAG_SEQUENTIAL_SCAN` | `0x08000000` | Read-ahead hint |

### Wait results

| Constant | Value | Meaning |
| --- | --- | --- |
| `WAIT_OBJECT_0` | 0 | Signalled |
| `WAIT_ABANDONED` | `0x80` | Abandoned mutex |
| `WAIT_TIMEOUT` | `0x102` | Timed out |
| `WAIT_FAILED` | `0xFFFFFFFF` | Error |

### Registry

| Constant | Meaning |
| --- | --- |
| `KEY_READ` | Query values, enumerate, notify |
| `KEY_WRITE` | Set values, create subkeys |
| `KEY_ALL_ACCESS` | Everything |
| `REG_SZ` | Null-terminated string |
| `REG_EXPAND_SZ` | String with `%VAR%` |
| `REG_MULTI_SZ` | Double-null-terminated list |
| `REG_DWORD` | 32-bit value |
| `REG_QWORD` | 64-bit value |
| `REG_BINARY` | Raw bytes |

## Frequently asked questions

### Q: Why does `UNICODE_STRING` have both `Length` and `MaximumLength`?

Because NT strings are counted and may not be null-terminated. `Length` is the amount of valid data;
`MaximumLength` is the buffer size including room for a terminator. `RtlInitUnicodeString` sets both
to the string length plus the terminator when the source is terminated.

### Q: Why is `OBJECT_ATTRIBUTES.Length` needed?

Because the structure is versioned and may grow. The kernel checks `Length >= sizeof(OBJECT_ATTRIBUTES)`
before reading the rest. Passing a zero or wrong `Length` produces
`STATUS_INVALID_PARAMETER` or `STATUS_ACCESS_VIOLATION` depending on the path.

### Q: Why does `IO_STATUS_BLOCK.Information` mean different things for different calls?

Because it is a union-like output slot: the kernel fills it with whatever is most useful for the
operation. The documentation for each `Nt*` service defines its meaning; there is no single
interpretation.

### Q: Why is `OVERLAPPED.hEvent` needed when the file handle can be signalled?

Because a file handle can only be signalled for one operation at a time. If you issue multiple
overlapped operations on the same handle, each needs its own event to know which one completed.

### Q: Why does `MEMORY_BASIC_INFORMATION.RegionSize` jump over several pages?

Because it reports the size of the region with uniform state, protection and type. Two adjacent
committed pages with the same protection are one region; a protection change starts a new one. The
sum of all regions is the whole address space.

### Q: Why does `CRITICAL_SECTION` contain `DebugInfo`?

Because the debug info block is allocated on demand by the checked build and by the debugger. It
records the creation site and the lock history. In a free build it is usually `NULL`.

### Q: Why is `SYSTEM_INFO.dwAllocationGranularity` 64 KiB when pages are 4 KiB?

Because the memory manager reserves address space in 64 KiB chunks to keep the virtual address
descriptor (VAD) tree small. A reservation must be aligned to the granularity; a commit can be
page-granular inside a reservation.

### Q: Where are the 32/64-bit variants defined?

`ntdef.h` has `OBJECT_ATTRIBUTES32` and `OBJECT_ATTRIBUTES64` at lines 1232 and 1243;
`winnt.h` has `MEMORY_BASIC_INFORMATION32`/`64` at line 5060; `wdm.h` has `IO_STATUS_BLOCK32`.
They exist so a 32-bit process can be introspected by a 64-bit debugger or WOW64 layer.

### Q: How do I pass a security descriptor to `CreateFileW`?

Put a `SECURITY_DESCRIPTOR` pointer in `SECURITY_ATTRIBUTES.lpSecurityDescriptor`, set
`nLength = sizeof(SECURITY_ATTRIBUTES)`, and pass the structure. `CreateFileW` ignores the
descriptor when opening an existing file (the file's own descriptor wins) but uses it when creating
a new one.

### Q: Why does `CONTEXT` require the thread to be suspended?

Because the registers are only meaningful when the thread is not running. `GetThreadContext` on a
running thread returns whatever the kernel last saved, which may be stale. The usual pattern is
`suspend -> get/set context -> resume`.
