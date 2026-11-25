---
title: Kernel objects and handles
sidebar_position: 30
description: The object manager, handle tables, reference counting, the object directory and symbolic links, and the Ob*/Nt* services that implement them — with verified paths in base/ntos/ob.
---

Every kernel resource the executive exposes to a process is an **object**: a process, a thread, a
file, an event, a section, a port, a key, a device, a semaphore, a mutant, a timer, a token. The
object manager (`base/ntos/ob`) owns the type, the name, the reference count and the security
descriptor. Handles are just indices into a per-process table.

```text
HANDLE (user mode)
   |  NtClose / NtDuplicateObject / NtQueryObject
   v
HANDLE TABLE  (per process, base/ntos/ob/obhandle.c)
   |  index -> OBJECT_HANDLE_ENTRY { ObjectPointer, GrantedAccess, HandleAttributes }
   v
OBJECT HEADER (OBJECT_HEADER)  + body (EPROCESS, ETHREAD, FILE_OBJECT, ...)
   |  Type -> OBJECT_TYPE  (name, pool type, valid access mask, methods)
   v
Security descriptor, name, directory, quota charges
```

## Object types

Each type is an `OBJECT_TYPE` created at boot by `ObCreateObjectType`:

| Type | Body | Created by |
| --- | --- | --- |
| `Process` | `EPROCESS` | `PsCreateSystemProcess` / `NtCreateProcessEx` |
| `Thread` | `ETHREAD` | `PsCreateSystemThread` / `NtCreateThreadEx` |
| `Job` | `EJOB` | `NtCreateJobObject` |
| `File` | `FILE_OBJECT` | `IoCreateStreamFileObject` / `NtCreateFile` |
| `Device` | `DEVICE_OBJECT` | `IoCreateDevice` |
| `Driver` | `DRIVER_OBJECT` | `IoCreateDriver` |
| `Event` | `KEVENT` | `NtCreateEvent` |
| `Semaphore` | `KSEMAPHORE` | `NtCreateSemaphore` |
| `Mutant` | `KMUTANT` | `NtCreateMutant` |
| `Timer` | `KTIMER` | `NtCreateTimer` |
| `Key` | `CM_KEY_BODY` | `NtCreateKey` |
| `Section` | `SECTION` | `MmCreateSection` |
| `Port` | `LPCP_PORT_OBJECT` | `NtCreatePort` |
| `Token` | `TOKEN` | `SepCreateToken` (`base/ntos/se/token.c:2532`) via `NtCreateToken` |
| `SymbolicLink` | — | `IoCreateSymbolicLink` |
| `Directory` | `OBJECT_DIRECTORY` | `NtCreateDirectoryObject` |
| `Callback` | `CALLBACK_OBJECT` | `ExCreateCallback` |

A type defines a **valid access mask** and a set of **methods** (`Open`, `Parse`, `Close`, `Delete`,
`QueryName`, `Security`). The `Parse` method is why `NtCreateFile("\Device\...\path")` can resolve
through a device object: the file type's parse method hands the rest of the path to the filesystem.

## The object directory

The kernel namespace is a tree of `OBJECT_DIRECTORY` objects rooted at `\`:

```text
\
 +-- ??                     (symbolic links: C:, COM1, ...)
 |    +-- C:  -> \Device\HarddiskVolume1
 +-- Device
 |    +-- HarddiskVolume1
 |    +-- Tcp, Udp, RawIp, Ip
 |    +-- Afd
 |    +-- KsecDD
 |    +-- Null, Zero, Random, PhysicalMemory
 +-- BaseNamedObjects        (per session: events, mutexes, semaphores)
 |    +-- <Global>\
 +-- KernelObjects           (events: LowMemory, ... )
 +-- ObjectTypes             (the type objects themselves)
 +-- Security                (LSA policy objects)
 +-- Session\<n>\BaseNamedObjects
 +-- ArcName, Registry, FileSystem, Nls, Psxss, ...
```

Names are `UNICODE_STRING` and **case-sensitive** in the kernel, though the Win32 layer may
case-fold for some types. A name can be up to whatever the object manager allows; a path lookup
walks one component at a time, each component a directory.

| API | Purpose |
| --- | --- |
| `NtCreateDirectoryObject` | Create a directory |
| `NtOpenDirectoryObject` | Open one |
| `NtQueryDirectoryObject` | Enumerate its entries |
| `NtCreateSymbolicLinkObject` | Create a symbolic link |
| `NtOpenSymbolicLinkObject` | Open one |
| `NtQuerySymbolicLinkObject` | Read the target |

## Handles and the handle table

A handle is a **process-relative** index, not a pointer:

```text
handle value (32-bit)
  3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0
  1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
 +-+--------------------------------+-------------------------------+
 |S|         handle index           |       generation / tag          |
 +-+--------------------------------+-------------------------------+
  ^ sign bit: set for kernel handles
```

| Bit | Meaning |
| --- | --- |
| Low 2 bits | Tag; a handle is always a multiple of 4 |
| Bits 2–29 | The index into the handle table |
| Bit 31 | The **kernel handle** bit (`OBJ_KERNEL_HANDLE`) — the handle is looked up in the system handle table, not the caller's |

| Service | Purpose | Implementation |
| --- | --- | --- |
| `NtCreateFile` | Create/open a file (returns a handle) | `base/ntos/io/iomgr/create.c:37` |
| `NtClose` | Close a handle | `base/ntos/ob/obclose.c` |
| `NtDuplicateObject` | Duplicate into another process | `base/ntos/ob/obhandle.c` |
| `NtQueryObject` | Query type/name/security | `base/ntos/ob/obquery.c:60` |
| `NtSetInformationObject` | Set object flags | `base/ntos/ob/obquery.c:664` |
| `NtQuerySystemInformation` | Enumerate all handles (`SystemHandleInformation`) | `base/ntos/ex/sysinfo.c:1342` |
| `NtWaitForSingleObject` / `NtWaitForMultipleObjects` | Wait on dispatcher objects | `base/ntos/ob/obwait.c:286` |
| `ObReferenceObjectByHandle` | Handle → object pointer | `base/ntos/ob/obref.c` |
| `ObReferenceObjectByName` | Name → object pointer | `base/ntos/ob/obref.c` |
| `ObOpenObjectByName` | Name → handle | `base/ntos/ob/obref.c` |

Closing a handle is **not** destroying an object. It drops one reference; the object lives while any
other handle or pointer reference exists. `NtClose` also performs a **type-specific close method** —
for a file, that is the last-close cleanup; for a process, it may be the process-delete path.

## Reference counting

| Primitive | Effect |
| --- | --- |
| `ObReferenceObject(obj)` | +1 pointer reference; never fails |
| `ObReferenceObjectByHandle(handle, access, type, mode, &obj, &info)` | +1, with an access check |
| `ObDereferenceObject(obj)` | −1; at zero, runs the delete method and frees the pool |
| `ObReferenceObjectSafe(obj)` | +1 unless the object is already being deleted (returns `FALSE`) |

Rules that prevent the classic bugs:

1. Every successful `ObReferenceObjectByHandle` needs an `ObDereferenceObject`, including on every
   error path after it.
2. Do **not** call `ObDereferenceObject` on a pointer you did not reference — the caller's reference
   is not yours to drop.
3. A driver that stores an object pointer must take its **own** reference; the caller may close its
   handle immediately after the call returns.
4. `ObDereferenceObject` can **block** (the delete method may wait), so do not call it at
   `DISPATCH_LEVEL` or while holding a spin lock.

`ObReferenceObjectByHandle` also returns the `OBJECT_HANDLE_INFORMATION`, whose `GrantedAccess` is
what the caller's handle actually permits — **not** what the caller requested. Trusting the request
instead of the granted access is a privilege-escalation bug.

## Access masks and generic mapping

Every type defines a `GENERIC_MAPPING` that maps `GENERIC_READ`/`WRITE`/`EXECUTE`/`ALL` to
type-specific rights:

```c
GENERIC_MAPPING FileGenericMapping = {
    STANDARD_RIGHTS_READ | FILE_READ_DATA | FILE_READ_ATTRIBUTES | FILE_READ_EA | SYNCHRONIZE,
    STANDARD_RIGHTS_WRITE | FILE_WRITE_DATA | FILE_WRITE_ATTRIBUTES | FILE_WRITE_EA | FILE_APPEND_DATA | SYNCHRONIZE,
    STANDARD_RIGHTS_EXECUTE | FILE_EXECUTE | SYNCHRONIZE,
    FILE_ALL_ACCESS
};
```

`NtCreateFile` maps `GENERIC_*` to specific rights **before** the access check, and the handle
stores the specific rights. That is why a handle opened with `GENERIC_READ` reports
`FILE_READ_DATA|FILE_READ_ATTRIBUTES|...` when you query it, not `GENERIC_READ`.

| Standard right | Value | Meaning |
| --- | --- | --- |
| `DELETE` | `0x00010000` | Delete the object |
| `READ_CONTROL` | `0x00020000` | Read the security descriptor |
| `WRITE_DAC` | `0x00040000` | Change the DACL |
| `WRITE_OWNER` | `0x00080000` | Change the owner |
| `SYNCHRONIZE` | `0x00100000` | Wait on the object |
| `STANDARD_RIGHTS_REQUIRED` | `0x000F0000` | DELETE `|` READ_CONTROL `|` WRITE_DAC `|` WRITE_OWNER |
| `STANDARD_RIGHTS_READ` | `READ_CONTROL` | |
| `STANDARD_RIGHTS_WRITE` | `READ_CONTROL` | |
| `STANDARD_RIGHTS_EXECUTE` | `READ_CONTROL` | |
| `GENERIC_READ` | `0x80000000` | Mapped per type |
| `GENERIC_WRITE` | `0x40000000` | Mapped per type |
| `GENERIC_EXECUTE` | `0x20000000` | Mapped per type |
| `GENERIC_ALL` | `0x10000000` | Mapped per type |
| `MAXIMUM_ALLOWED` | `0x02000000` | Grant the maximum the DACL allows |

## Object attributes and the path

`OBJECT_ATTRIBUTES` is how a caller names an object and states the security context:

```c
OBJECT_ATTRIBUTES oa;
UNICODE_STRING name;
RtlInitUnicodeString(&name, L"\\BaseNamedObjects\\MyEvent");

InitializeObjectAttributes(
    &oa,
    &name,
    OBJ_CASE_INSENSITIVE | OBJ_OPENIF,   // Attributes
    NULL,                                  // RootDirectory
    NULL                                   // SecurityDescriptor
    );
```

| Attribute | Effect |
| --- | --- |
| `OBJ_INHERIT` | The handle is inherited by child processes |
| `OBJ_PERMANENT` | The object survives while any handle exists (and keeps the name) |
| `OBJ_EXCLUSIVE` | Only one handle at a time (used for some devices) |
| `OBJ_CASE_INSENSITIVE` | Name lookup is case-insensitive |
| `OBJ_OPENIF` | Open if it exists, otherwise create (for `NtCreateEvent` etc.) |
| `OBJ_OPENLINK` | Open the symbolic link itself, not its target |
| `OBJ_KERNEL_HANDLE` | The handle lives in the system handle table |
| `OBJ_FORCE_ACCESS_CHECK` | Perform the access check even for kernel callers |
| `OBJ_KERNEL_EXCLUSIVE` | Kernel-mode only |

`OBJ_FORCE_ACCESS_CHECK` exists because kernel callers are normally trusted. A driver that opens a
**user-specified** name on behalf of a user must set it, or the driver becomes a confused-deputy
privilege escalation.

## Symbolic links

| Link | Target |
| --- | --- |
| `\??\C:` | `\Device\HarddiskVolume1` |
| `\??\COM1` | `\Device\Serial0` |
| `\??\PRN` | `\Device\Parallel0` |
| `\??\Global` | `\BaseNamedObjects` (session 0) |
| `\??\CONIN$`, `\??\CONOUT$` | `\Device\ConDrv`-style console devices |

The `\??` prefix is what Win32 turns into `\??\` when you pass `C:\path` to `CreateFileW`: the
`??` directory is a shortcut to the per-session `Global??`/`DosDevices` directory. `QueryDosDeviceW`
reads it; `DefineDosDeviceW` writes it.

## Waiting on objects

`NtWaitForSingleObject` and `NtWaitForMultipleObjects` are implemented in `base/ntos/ob/obwait.c:286`.
They dispatch on the object's type: dispatcher objects (`Event`, `Semaphore`, `Mutant`, `Timer`,
`Thread`, `Process`, `File` with `SYNCHRONIZE`) are waited on directly; non-dispatcher objects
return `STATUS_HANDLE_ERROR`/`STATUS_OBJECT_TYPE_MISMATCH`.

| Wait rule | Consequence |
| --- | --- |
| The object must grant `SYNCHRONIZE` | `NtCreateFile` without `SYNCHRONIZE` cannot be waited on |
| `WaitAny` returns at the first signalled object | The index is the `Status` low bits |
| `WaitAll` returns when **all** are signalled | An abandoned mutex in the set fails the wait |
| `WaitAlertable` delivers APCs | A user APC can interrupt the wait |
| Waiting on a mutex you own | Deadlock, unless `WaitAll` semantics apply |

## The system handle table and `NtQuerySystemInformation`

`SystemHandleInformation` returns every open handle in the system: process ID, object, granted
access, handle value, type index, and the object's address. It is how `handle.exe`, Process Explorer
and the leak tools enumerate handles — and why it requires `SE_DEBUG_PRIVILEGE` for other processes'
handles.

```c
SYSTEM_HANDLE_INFORMATION_EX *info = NULL;
SIZE_T size = 1 << 20;
for (;;) {
    info = realloc(info, size);
    NTSTATUS st = NtQuerySystemInformation(SystemHandleInformation, info, size, NULL);
    if (st == STATUS_INFO_LENGTH_MISMATCH) { size *= 2; continue; }
    if (!NT_SUCCESS(st)) { /* handle error */ }
    break;
}
// info->NumberOfHandles, info->Handles[i]
```

The retry loop is mandatory: the table grows between calls, and the API returns
`STATUS_INFO_LENGTH_MISMATCH` rather than a partial result.

## Frequently asked questions

### Q: Why is a handle not a pointer?

Because a handle is an index that the kernel can validate, revoke and renumber. A pointer would let
user mode forge a kernel address. The index is bounds-checked against the table, and the
generation/tag bits catch use of a stale handle value.

### Q: What happens when I close a handle twice?

The second `NtClose` returns `STATUS_INVALID_HANDLE` and, in a checked build, may raise
`STATUS_INVALID_HANDLE` as a hard error. With Application Verifier's handle checks enabled, the
process is stopped at the second close. In a free build without verifier, a double close can close
an **unrelated** handle that the table reused at the same index — the classic "closing a recycled
handle" bug.

### Q: Why does `NtQueryObject` sometimes hang?

Because querying the name of a **named pipe** or a **socket** must ask the owning driver, which may
block. The published advice is to query the type first (`ObjectTypeInformation`), and only query
the name for types where it is safe. Querying `ObjectNameInformation` on every handle in the system
is a known way to hang a diagnostic tool.

### Q: What is a kernel handle?

One with bit 31 set (`OBJ_KERNEL_HANDLE`). It lives in the **system handle table** instead of the
per-process table, so it is valid in any process context. A driver that opens a handle in one
process and uses it in another must use a kernel handle, or duplicate it into the target process.

### Q: Why does `ObReferenceObjectByHandle` need a `DesiredAccess` when the handle already has one?

Because the caller states what it intends to do with the object, and the object manager checks that
the handle's **granted** access covers it. That prevents a driver from using a handle opened for
`FILE_READ_ATTRIBUTES` to perform a write.

### Q: What is `ObOpenObjectByName` for?

It resolves a name to a **handle** with an access check, exactly as `NtOpenFile` does for files.
Drivers use it for `\Device\...` objects and for `\BaseNamedObjects\...` events. It is the correct
way to open an object by name from kernel mode; `ObReferenceObjectByName` skips the access check
and should only be used for objects the driver created.

### Q: Why do all my objects disappear when the last handle closes?

Because most objects are not `OBJ_PERMANENT`. A permanent object keeps its name and its reference
while any handle exists, and survives until `NtMakeTemporaryObject` is called. The `\Device\...`
and `\BaseNamedObjects\...` objects are usually permanent, created by drivers that stay loaded.

### Q: How do I enumerate a process's handles?

`NtQuerySystemInformation(SystemHandleInformation)` and filter by `UniqueProcessId`, or
`NtQueryInformationProcess(ProcessHandleInformation)`. For a specific object, `NtQueryObject(ObjectNameInformation)`.
All of these require `PROCESS_DUP_HANDLE` or `SE_DEBUG_PRIVILEGE` for other processes.

### Q: What does `STATUS_OBJECT_TYPE_MISMATCH` mean?

It means the handle exists but points to an object of a different type than the call requires — for
example, passing an event handle to `NtQueryInformationFile`. It is usually a genuine bug in the
caller: the handle was reused or the wrong variable was passed.

### Q: Is the object namespace persisted?

No. It is rebuilt at every boot. Only the **registry** is persisted, and the registry is itself
backed by hive files. `\Registry` is the object-manager name for the configuration manager's
namespace; the keys inside it live in hives.

### Q: Where is `ObReferenceObjectByHandle` declared?

In `public/ifskit/inc/ntifs.h` — the IFS kit header that drivers compile against. (There is no
`public/ddk/inc/ntifs.h` in this checkout; the DDK-side kernel headers are `public/ddk/inc/wdm/wdm.h`
and `public/sdk/inc/wdm.h`.) User mode uses `NtDuplicateObject`/`NtQueryObject`
instead; there is no user-mode `ObReferenceObjectByHandle`.
