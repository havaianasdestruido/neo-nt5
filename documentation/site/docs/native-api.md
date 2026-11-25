---
title: NT native API — Nt*/Zw* system services
sidebar_position: 21
description: The syscall path from int 2Eh to the service table, the Nt versus Zw distinction, and the core Nt* services by category with signatures from the tree.
---

The **native API** is the kernel's own call interface: `Nt*` and `Zw*` routines implemented in the
executive and reached by a syscall instruction. It sits below the Win32 API, and it is the layer
`kernel32`, `user32`, `gdi32` and `advapi32` wrap.

```text
user mode
   ntdll!NtCreateFile stub        (generated from services.tab)
        |  mov eax, <syscall number>
        |  mov edx, esp / sysenter / int 2Eh
        v
kernel mode
   KiSystemService                base/ntos/ke/i386/trap.asm
        |  index into KeServiceDescriptorTable
        v
   NtCreateFile                   base/ntos/io/iomgr/create.c:37
        |  builds IRP, calls filesystem
        v
   filesystem driver              base/fs/ntfs/...
```

## The syscall path on x86

The kernel's system-call entry is in
[`base/ntos/ke/i386/trap.asm`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/ke/i386/trap.asm).
Two entry points matter:

```text
IDTEntry        _KiSystemService, D_INT332          ;2E: system service calls
...
        PUBLIC _KiFastCallEntry
_KiFastCallEntry:
```

`int 2Eh` enters at `KiSystemService`; `sysenter` enters at `KiFastCallEntry`. Both converge on the
same dispatch: the syscall number in `EAX` indexes the service table, the arguments are copied from
the user stack, and the target routine is called with ` PreviousMode == UserMode`.

The service table is initialised in
[`base/ntos/ke/kiinit.c:314`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/ke/kiinit.c#L314):

```c
    KeServiceDescriptorTable[0].Base = &KiServiceTable[0];
    KeServiceDescriptorTable[0].Count = NULL;
    KeServiceDescriptorTable[0].Limit = KiServiceLimit;
    ...
    KeServiceDescriptorTable[0].Number = &KiArgumentTable[0];
    for (Index = 1; Index < NUMBER_SERVICE_TABLES; Index += 1) {
        KeServiceDescriptorTable[Index].Limit = 0;
    }
    RtlCopyMemory(KeServiceDescriptorTableShadow,
                  KeServiceDescriptorTable,
                  sizeof(KeServiceDescriptorTable));
```

`KeServiceDescriptorTable` is declared in
[`base/ntos/ke/kernldat.c:193`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/ke/kernldat.c#L193)
as an array of `KSERVICE_TABLE_DESCRIPTOR`, one per architecture. `KiServiceTable` and
`KiArgumentTable` are generated from `services.tab` at build time; they are **not checked in**, which
is why you cannot grep the syscall number in the source tree.

`KeServiceDescriptorTableShadow` is the copy used by the Win32 subsystem: `win32k.sys` installs its
own `NtUser*`/`NtGdi*` services in the shadow table at index 1, and the dispatcher selects the table
by the `PreviousMode` of the caller.

## The source of truth: `services.tab`

[`base/ntos/ke/services.tab`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/ke/services.tab)
is 284 lines of `Name,ArgumentCount`:

```text
CreateFile,11
CreateProcess,8
CreateProcessEx,9
CreateThread,8
MapViewOfSection,10
OpenFile,6
OpenKey,3
QueryValueKey,6
```

The names have **no `Nt` prefix** — `gensrv` adds it. The argument count is used to generate the
stack probe and the `@n` decoration. `base/ntdll/makefile.nap` shows the generation:

```bat
i386\usrstubs.asm: \\nt\private\ntos\ke\services.tab
    gensrv -d i386 -e asm \\nt\private\ntos\ke
```

To add a system service in this tree:

1. Add `Name,ArgCount` to `base/ntos/ke/services.tab`.
2. Implement `NtName` in the owning manager (`base/ntos/<manager>/...`).
3. Add the declaration to the public header (`public/sdk/inc/winternl.h` for user mode, `ntifs.h`
   for kernel mode).
4. Rebuild the kernel and ntdll; the stub and the service table are regenerated.

## Nt versus Zw

Both prefixes export the same routine. The difference is how the routine treats its caller:

| Caller | `Nt*` | `Zw*` |
| --- | --- | --- |
| User mode | Same as `Zw*` | Same as `Nt*` |
| Kernel mode, `PreviousMode == UserMode` | Uses the caller's previous mode for probing | Forces `KernelMode` |
| Kernel mode, `PreviousMode == KernelMode` | Same | Same |

The rule in practice: **a kernel-mode driver should call `Zw*`** so that buffers are treated as
kernel pointers and are not probed. Calling `NtCreateFile` from a driver with a user-mode previous
mode can fail the probe or open a security hole.

## Structures you must build

### `OBJECT_ATTRIBUTES`

```c
typedef struct _OBJECT_ATTRIBUTES {
    ULONG           Length;
    HANDLE          RootDirectory;
    PUNICODE_STRING ObjectName;
    ULONG           Attributes;
    PVOID           SecurityDescriptor;
    PVOID           SecurityQualityOfService;
} OBJECT_ATTRIBUTES, *POBJECT_ATTRIBUTES;
```

The `InitializeObjectAttributes` macro fills it. `Attributes` is a mask of `OBJ_INHERIT`,
`OBJ_PERMANENT`, `OBJ_EXCLUSIVE`, `OBJ_CASE_INSENSITIVE`, `OBJ_OPENIF`, `OBJ_OPENLINK`,
`OBJ_KERNEL_HANDLE`. `OBJ_KERNEL_HANDLE` makes the handle valid in any process context and is how
the kernel keeps handles across process changes.

### `IO_STATUS_BLOCK`

```c
typedef struct _IO_STATUS_BLOCK {
    union {
        NTSTATUS Status;
        PVOID    Pointer;
    };
    ULONG_PTR Information;
} IO_STATUS_BLOCK, *PIO_STATUS_BLOCK;
```

`Status` is the completion status; `Information` is operation-specific — bytes transferred for
read/write, `FILE_CREATED`/`FILE_OPENED` for `NtCreateFile`, the required size for a too-small
buffer.

### `CLIENT_ID`

```c
typedef struct _CLIENT_ID {
    HANDLE UniqueProcess;
    HANDLE UniqueThread;
} CLIENT_ID, *PCLIENT_ID;
```

`NtOpenThread` and `NtCreateThread` take one. The values are the process and thread IDs, not
handles.

## Core services by category

### Processes and threads

| Service | Implementation | Purpose |
| --- | --- | --- |
| `NtCreateProcess` | `base/ntos/ps/create.c:847` | Create a process object (legacy) |
| `NtCreateProcessEx` | `base/ntos/ps/create.c:884` | Create a process with flags, section, debug/exception ports |
| `NtCreateThread` | `base/ntos/ps/create.c:86` | Create a thread with an explicit context |
| `NtOpenProcess` | `base/ntos/ps/psopen.c:30` | Open a process by `CLIENT_ID` |
| `NtOpenThread` | `base/ntos/ps/psopen.c:274` | Open a thread by `CLIENT_ID` |
| `NtQueryInformationProcess` | `base/ntos/ps/psquery.c:563` | Query process information class |
| `NtSetInformationProcess` | `base/ntos/ps/psquery.c` | Set process information class |
| `NtTerminateProcess` | `base/ntos/ps/psdelete.c:291` | Terminate a process |
| `NtTerminateThread` | `base/ntos/ps/psdelete.c:553` | Terminate a thread |

`NtCreateProcessEx`'s signature, from
[`base/ntos/ps/create.c:884`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/ps/create.c#L884):

```c
NtCreateProcessEx(
    OUT PHANDLE ProcessHandle,
    IN ACCESS_MASK DesiredAccess,
    IN POBJECT_ATTRIBUTES ObjectAttributes OPTIONAL,
    IN HANDLE ParentProcess OPTIONAL,
    IN ULONG Flags,
    IN HANDLE SectionHandle OPTIONAL,
    IN HANDLE DebugPort OPTIONAL,
    IN HANDLE ExceptionPort OPTIONAL,
    IN ULONG JobMemberLevel
    )
```

`SectionHandle` is the image to map. `DebugPort` and `ExceptionPort` are LPC ports: a debugger
creates the debug port and the kernel sends `DBGUI_*` messages to it.

### Memory

| Service | Implementation | Purpose |
| --- | --- | --- |
| `NtAllocateVirtualMemory` | `base/ntos/mm/allocvm.c:83` | Reserve/commit pages |
| `NtFreeVirtualMemory` | `base/ntos/mm/freevm.c:66` | Release/decommit |
| `NtProtectVirtualMemory` | `base/ntos/mm/protect.c:61` | Change page protection |
| `NtQueryVirtualMemory` | `base/ntos/mm/queryvm.c:61` | Query a region |
| `NtReadVirtualMemory` | `base/ntos/mm/readwrt.c:95` | Copy from another process |
| `NtWriteVirtualMemory` | `base/ntos/mm/readwrt.c:228` | Copy to another process |
| `NtCreateSection` | `base/ntos/mm/creasect.c:136` | Create a section object |
| `NtMapViewOfSection` | `base/ntos/mm/mapview.c:199` | Map a view |
| `NtUnmapViewOfSection` | `base/ntos/mm/mapview.c` | Unmap a view |
| `NtFlushVirtualMemory` | `base/ntos/mm` | Flush modified pages |

`NtAllocateVirtualMemory`'s signature:

```c
NtAllocateVirtualMemory(
    IN HANDLE ProcessHandle,
    IN OUT PVOID *BaseAddress,
    IN ULONG_PTR ZeroBits,
    IN OUT PSIZE_T RegionSize,
    IN ULONG AllocationType,
    IN ULONG Protect
    )
```

`ZeroBits` constrains the high bits of the returned address; `RegionSize` is both input (desired)
and output (rounded to page size). `MEM_RESERVE | MEM_COMMIT` is the usual combination.

### Files and I/O

| Service | Implementation | Purpose |
| --- | --- | --- |
| `NtCreateFile` | `base/ntos/io/iomgr/create.c:37` | Create or open a file/device |
| `NtOpenFile` | `base/ntos/io/iomgr/open.c:34` | Open an existing file |
| `NtReadFile` | `base/ntos/io/iomgr/read.c:39` | Read |
| `NtWriteFile` | `base/ntos/io/iomgr/write.c:35` | Write |
| `NtQueryInformationFile` | `base/ntos/io/iomgr/query.c` | Query file information class |
| `NtSetInformationFile` | `base/ntos/io/iomgr/qsinfo.c:846` | Set file information class |
| `NtQueryVolumeInformationFile` | `base/ntos/io/iomgr/qsfs.c:37` | Query volume information |
| `NtDeviceIoControlFile` | `base/ntos/io/iomgr/devctrl.c:34` | Device control (IOCTL) |
| `NtQueryDirectoryFile` | `base/ntos/io/iomgr/dir.c:687` | Enumerate a directory |
| `NtFlushBuffersFile` | `base/ntos/io/iomgr/misc.c:390` | Flush |
| `NtLockFile` / `NtUnlockFile` | `base/ntos/io/iomgr/lock.c` | Byte-range locks |
| `NtCancelIoFile` | `base/ntos/io/iomgr/iosubs.c` | Cancel pending I/O |

`NtCreateFile`'s signature:

```c
NTSTATUS
NtCreateFile(
    OUT PHANDLE FileHandle,
    IN ACCESS_MASK DesiredAccess,
    IN POBJECT_ATTRIBUTES ObjectAttributes,
    OUT PIO_STATUS_BLOCK IoStatusBlock,
    IN PLARGE_INTEGER AllocationSize OPTIONAL,
    IN ULONG FileAttributes,
    IN ULONG ShareAccess,
    IN ULONG CreateDisposition,
    IN ULONG CreateOptions,
    IN PVOID EaBuffer OPTIONAL,
    IN ULONG EaLength
    )
```

`CreateDisposition` uses `FILE_SUPERSEDE`, `FILE_CREATE`, `FILE_OPEN`, `FILE_OPEN_IF`,
`FILE_OVERWRITE`, `FILE_OVERWRITE_IF`. `CreateOptions` uses `FILE_DIRECTORY_FILE`,
`FILE_NON_DIRECTORY_FILE`, `FILE_WRITE_THROUGH`, `FILE_SEQUENTIAL_ONLY`, `FILE_RANDOM_ACCESS`,
`FILE_SYNCHRONOUS_IO_ALERT`, `FILE_SYNCHRONOUS_IO_NONALERT`, `FILE_NO_INTERMEDIATE_BUFFERING`,
`FILE_DELETE_ON_CLOSE`, `FILE_OPEN_REPARSE_POINT` and friends. These are the values the Win32 layer
maps `CREATE_NEW`/`OPEN_EXISTING` to.

### Synchronization

| Service | Implementation | Purpose |
| --- | --- | --- |
| `NtCreateEvent` | `base/ntos/ex/event.c:188` | Create an event |
| `NtSetEvent` / `NtResetEvent` | `base/ntos/ex/event.c` | Signal / unsignal |
| `NtCreateMutant` | `base/ntos/ex/mutant.c:161` | Create a mutex |
| `NtReleaseMutant` | `base/ntos/ex/mutant.c` | Release |
| `NtCreateSemaphore` | `base/ntos/ex/semphore.c:129` | Create a semaphore |
| `NtReleaseSemaphore` | `base/ntos/ex/semphore.c` | Release |
| `NtCreateTimer` | `base/ntos/ex/timer.c:456` | Create a timer |
| `NtSetTimer` / `NtCancelTimer` | `base/ntos/ex/timer.c` | Arm / cancel |
| `NtWaitForSingleObject` | `base/ntos/ob/obwait.c:286` | Wait on one object |
| `NtWaitForMultipleObjects` | `base/ntos/ob/obwait.c` | Wait on several |
| `NtDelayExecution` | `base/ntos/ex/delay.c:33` | Sleep |
| `NtYieldExecution` | `base/ntos/ke/yield.c:29` | Yield the quantum |

### Objects and handles

| Service | Implementation | Purpose |
| --- | --- | --- |
| `NtClose` | `base/ntos/ob/obclose.c:410` | Close a handle |
| `NtDuplicateObject` | `base/ntos/ob/obhandle.c:774` | Duplicate a handle, optionally across processes |
| `NtQueryObject` | `base/ntos/ob/obquery.c:60` | Query name, type, security |
| `NtSetInformationObject` | `base/ntos/ob/obquery.c:664` | Set object attributes |
| `NtQuerySystemInformation` | `base/ntos/ex/sysinfo.c:1342` | System-wide information classes |

### Registry

| Service | Implementation | Purpose |
| --- | --- | --- |
| `NtCreateKey` | `base/ntos/config/ntapi.c:221` | Create or open a key |
| `NtOpenKey` | `base/ntos/config/ntapi.c:2080` | Open a key |
| `NtQueryKey` | `base/ntos/config/ntapi.c:2239` | Key metadata |
| `NtEnumerateKey` | `base/ntos/config/ntapi.c:718` | Enumerate subkeys |
| `NtQueryValueKey` | `base/ntos/config/ntapi.c:2422` | Read a value |
| `NtSetValueKey` | `base/ntos/config/ntapi.c:3039` | Write a value |
| `NtDeleteKey` | `base/ntos/config/ntapi.c` | Delete a key |
| `NtNotifyChangeKey` | `base/ntos/config/ntapi.c` | Watch a key |

`NtQueryValueKey` returns a `KEY_VALUE_PARTIAL_INFORMATION` or `KEY_VALUE_FULL_INFORMATION`
depending on the information class. The Win32 `RegQueryValueExW` wrapper in
`base/screg/winreg/client/regqval.c` builds the same call.

### Security

| Service | Implementation | Purpose |
| --- | --- | --- |
| `NtOpenProcessToken` | `base/ntos/se/tokenopn.c:192` | Open a token |
| `NtOpenThreadToken` | `base/ntos/se/tokenopn.c` | Open a thread token |
| `NtQueryInformationToken` | `base/ntos/se/tokenqry.c:37` | Query token information class |
| `NtSetInformationToken` | `base/ntos/se/tokenset.c:40` | Set token information class |
| `NtAdjustPrivilegesToken` | `base/ntos/se/tokenadj.c:47` | Enable/disable privileges |
| `NtAccessCheck` | `base/ntos/se/ctseacc.c` | Access check (kernel) |

### LPC

| Service | Implementation | Purpose |
| --- | --- | --- |
| `NtCreatePort` | `base/ntos/lpc/lpccreat.c:45` | Create a port |
| `NtConnectPort` | `base/ntos/lpc/lpcconn.c:44` | Connect to a port |
| `NtListenPort` | `base/ntos/lpc/lpclistn.c:29` | Wait for a connection |
| `NtRequestWaitReplyPort` | `base/ntos/lpc/lpcsend.c:432` | Send and wait for a reply |
| `NtAcceptConnectPort` | `base/ntos/lpc` | Accept a connection |

LPC is the substrate under RPC, CSRSS communication and the debugger. `CsrClientCallServer` in
ntdll is a thin wrapper over `NtRequestWaitReplyPort`.

## Calling the native API from user mode

`winternl.h` declares a subset, and `ntdll` exports the stubs. The example opens a file with
`NtCreateFile` and reads it with `NtReadFile`, using the same structures the Win32 layer builds:

```c
#include <windows.h>
#include <winternl.h>
#include <stdio.h>

int wmain(void)
{
    UNICODE_STRING name;
    RtlInitUnicodeString(&name, L"\\??\\C:\\Windows\\notepad.exe");

    OBJECT_ATTRIBUTES oa;
    InitializeObjectAttributes(&oa, &name,
                               OBJ_CASE_INSENSITIVE | OBJ_KERNEL_HANDLE,
                               NULL, NULL);

    HANDLE hFile = NULL;
    IO_STATUS_BLOCK iosb = {0};
    NTSTATUS st = NtCreateFile(&hFile,
                               FILE_READ_DATA | SYNCHRONIZE,
                               &oa,
                               &iosb,
                               NULL,
                               FILE_ATTRIBUTE_NORMAL,
                               FILE_SHARE_READ,
                               FILE_OPEN,
                               FILE_SYNCHRONOUS_IO_NONALERT,
                               NULL, 0);
    if (!NT_SUCCESS(st)) {
        wprintf(L"NtCreateFile failed: 0x%08lX\n", (unsigned long)st);
        return 1;
    }

    BYTE buffer[256];
    st = NtReadFile(hFile, NULL, NULL, NULL, &iosb,
                    buffer, sizeof(buffer), NULL, NULL);
    if (NT_SUCCESS(st)) {
        wprintf(L"read %zu bytes\n", (size_t)iosb.Information);
    } else {
        wprintf(L"NtReadFile failed: 0x%08lX\n", (unsigned long)st);
    }

    NtClose(hFile);
    return 0;
}
```

Points the example encodes:

- The path is an **NT path**, not a Win32 path. `\??\C:\...` is the object-manager link to
  `\DosDevices`.
- `OBJ_KERNEL_HANDLE` is optional here; it makes the handle valid in any process context.
- `FILE_SYNCHRONOUS_IO_NONALERT` requires `SYNCHRONIZE` in `DesiredAccess`.
- `iosb.Information` is the byte count on success.

## Status codes

Every native call returns `NTSTATUS`. The severity is in the top three bits:

| Severity | Value | Meaning |
| --- | --- | --- |
| Success | `0x0` | The operation completed |
| Informational | `0x1` | Completed with information |
| Warning | `0x2` | Completed with a warning |
| Error | `0x3` | Failed |

The macros are:

```c
#define NT_SUCCESS(Status)   ((NTSTATUS)(Status) >= 0)
#define NT_INFORMATION(Status) (((ULONG)(Status)) >> 30 == 1)
#define NT_WARNING(Status)   (((ULONG)(Status)) >> 30 == 2)
#define NT_ERROR(Status)     (((ULONG)(Status)) >> 30 == 3)
```

The full table of common `STATUS_*` values and their Win32 mappings is in
[Status and error codes](/status-codes).

## Frequently asked questions

### Q: Where does the syscall number for `NtCreateFile` come from?

From the position of `CreateFile` in `base/ntos/ke/services.tab`. The table is ordered, and
`gensrv` emits `#define` constants in that order. The number is **not** stable across Windows
versions, which is why hardcoded syscall numbers break on upgrade.

### Q: Why does `NtCreateFile` take 11 arguments?

Because it is the raw create/open primitive: handle, access, object attributes, I/O status block,
allocation size, attributes, share, disposition, options, EA buffer, EA length. The Win32 layer
maps `CreateFileW`'s 7 parameters onto those 11 by filling in the rest.

### Q: Why does `NtCreateFile` return `STATUS_OBJECT_NAME_COLLISION` instead of `ERROR_FILE_EXISTS`?

Because it is a native service and speaks `NTSTATUS`. The Win32 wrapper translates it to
`ERROR_FILE_EXISTS` in `CreateFileW` (`base/win32/client/fileopcr.c`). If you call the native API
directly, you must handle the `NTSTATUS` yourself.

### Q: Is `ZwCreateFile` safer than `NtCreateFile` for a driver?

Yes, in the specific sense that `Zw*` forces `PreviousMode = KernelMode`, so the I/O manager does
not probe your buffers as if they were user-mode pointers. Using `Nt*` from a driver with a
user-mode previous mode can cause spurious `STATUS_ACCESS_VIOLATION` or, worse, a probe bypass.

### Q: Where are the `NtUser*` and `NtGdi*` services?

They are not in `services.tab`. They are installed by `win32k.sys` into
`KeServiceDescriptorTableShadow` at index 1, which is why they are only available when the Win32
subsystem is loaded. Their entry points are in `windows/core/ntuser/kernel/ntstubs.c` and
`windows/core/ntgdi/kernel`.

### Q: Why does `NtQueryInformationProcess` take an "information class"?

Because one service covers many queries. `ProcessBasicInformation`, `ProcessQuotaLimits`,
`ProcessIoCounters`, `ProcessVmCounters`, `ProcessTimes`, `ProcessBasePriority` and others are all
dispatched through the same call with a different class. Each class has its own output structure
and required buffer size.

### Q: How do I find the implementation of an `Nt*` service?

```bash
# exact definition in the executive
rg -n '^NtCreateFile' base/ntos
# which file owns a family
rg -n '^NtQueryValueKey' base/ntos/config
# the syscall table entry
grep -n '^QueryValueKey' base/ntos/ke/services.tab
```

### Q: Can I use the native API from a driver?

Yes, but the driver headers are different: `ntifs.h` and `wdm.h` declare the kernel-mode variants,
and the driver must link against `ntoskrnl.lib`. The services are the same routines; the header and
the calling convention are what change.

### Q: Why is `NtClose` in the object manager and not the I/O manager?

Because a handle can refer to any object type — file, event, process, key, port. `NtClose` calls
`ObCloseHandle`, which looks up the handle in the process's handle table and invokes the object
type's close method. The I/O manager's file object close path is one of those methods.

### Q: What is the difference between `NtCreateThread` and `NtCreateThreadEx`?

`NtCreateThread` (`base/ntos/ps/create.c:86`) takes a `PCONTEXT` and a `PINITEB` and is the legacy
interface. `NtCreateThreadEx` adds a `PS_ATTRIBUTE_LIST`, a start routine/context, and flags; it is
what modern `CreateRemoteThreadEx` uses. Both end up in `PspCreateThread`.

### Q: How do I read a `KEY_VALUE_PARTIAL_INFORMATION`?

```c
KEY_VALUE_PARTIAL_INFORMATION *info = (KEY_VALUE_PARTIAL_INFORMATION *)buffer;
// info->TitleIndex, info->Type, info->DataLength, info->Data[0..DataLength-1]
```

The buffer must be at least `sizeof(KEY_VALUE_PARTIAL_INFORMATION)` plus the data; if it is too
small, `NtQueryValueKey` returns `STATUS_BUFFER_OVERFLOW` or `STATUS_BUFFER_TOO_SMALL` and sets
`iosb.Information` to the required size.
