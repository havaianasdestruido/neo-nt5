---
title: Kernel and executive
sidebar_position: 4
description: The base/ntos managers, where system services are implemented, object and handle lifetimes, pool allocation, and the in-tree module documentation.
---

`base/ntos/` is the NT executive: the kernel proper plus the managers that run in kernel mode. It is
**not** the Win32 kernel — that is `windows/core`, covered in
[Win32, windowing and the shell](/win32-shell).

## Manager map

| Directory | Manager | Representative files in this checkout |
| --- | --- | --- |
| `ke` | Kernel / scheduler | `kiinit.c`, `dpcobj.c`, `dpcsup.c`, `eventobj.c`, `mutntobj.c`, `bugcheck.c`, `balmgr.c`, `channel.c` |
| `ps` | Processes and threads | `create.c`, `pscid.c`, `psenum.c`, `psjob.c`, `psimpers.c`, `psquota.c`, `security.c` |
| `mm` | Virtual memory | `mmfault.c`, `allocvm.c`, `mapview.c`, `freevm.c`, `modwrite.c`, `crashdmp.c`, `mi.h`, `miglobal.c` |
| `io` | I/O manager and PnP | `iomgr/iosubs.c`, `iomgr/create.c`, `iomgr/complete.c`, `pnpmgr/` (under `base/ntos/io/`) |
| `ob` | Object manager | `obcreate.c`, `obhandle.c`, `obref.c`, `obinsert.c`, `obtype.c`, `ob.txt` |
| `ex` | Executive support, pool, time | `pool.c` |
| `se` | Security reference monitor | `accessck.c`, `token.c`, `adtlog.c` — see [Security](/security-directory) |
| `config` | Registry | `cmboot.c`, `cmapi.c`, `cmapi2.c`, `cmdelay.c`, `chkreg/` |
| `cache` | Cache manager | see `base/ntos/cache` |
| `lpc` | Local procedure calls | `lpccreat.c`, `lpcsend.c`, `lpcrecv.c`, `lpcreply.c`, `lpclistn.c` |
| `po` | Power manager | see `base/ntos/po` |
| `dbgk` | User-mode debugging | see `base/ntos/dbgk` |
| `kd64` | Kernel debugger | `kdinit.c`, `kdbreak.c`, `kdapi.c`, `kddbgio.c`, `print.c` |
| `verifier` | Driver Verifier hooks | `vfirp.c`, `vfdeadlock.c`, `vfddi.c`, `vfstack.c`, `vfpnp.c`, `vfpower.c` |
| `fsrtl`, `fstub`, `raw` | Filesystem runtime and stubs | shared by every filesystem driver |
| `rtl` | Kernel runtime library | string, unicode, security descriptor helpers |
| `arb` | Resource arbiters | bus-resource allocation for PnP |
| `init` | Kernel start-up and link configuration | `init.c`, `up/`, `mp/`, `pae/`, `paemp/` |

Each manager directory holds architecture subdirectories (`i386`, `amd64`, `ia64`, `alpha`,
`axp64`) and `up` / `mp` / `pae` / `paemp` variants, plus a `sources.inc` that the variant nodes
include.

## Where a system service lives

System services are implemented by the manager that owns the resource, not in `ntdll` and not in a
single dispatcher file. `NtCreateFile` is in the I/O manager:

```c
// base/ntos/io/iomgr/create.c:37
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

and it is explicitly paged:

```c
#ifdef ALLOC_PRAGMA
#pragma alloc_text(PAGE, NtCreateFile)
#pragma alloc_text(PAGE, NtCreateNamedPipeFile)
#pragma alloc_text(PAGE, NtCreateMailslotFile)
#endif
```

`#pragma alloc_text(PAGE, ...)` moves a routine into the pageable `PAGE` section. Routines that can
run at raised IRQL, in a DPC or during a crash must **not** be paged — that is why `IofCallDriver`
and `IofCompleteRequest` are `FASTCALL` and unpaged while `NtCreateFile` is pageable.

## Object and handle lifetimes

Handles are references counted in two places: a handle-table entry (per process) and a
pointer count (per object). `ObReferenceObjectByHandle`, at
[`base/ntos/ob/obref.c:1044`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/ob/obref.c),
is the canonical bridge between them:

```c
NTSTATUS
ObReferenceObjectByHandle (
    IN HANDLE Handle,
    IN ACCESS_MASK DesiredAccess,
    IN POBJECT_TYPE ObjectType OPTIONAL,
    IN KPROCESSOR_MODE AccessMode,
    OUT PVOID *Object,
    OUT POBJECT_HANDLE_INFORMATION HandleInformation OPTIONAL
    )
```

It performs the access check against `DesiredAccess`, validates the object type when one is given,
increments the pointer count, and returns the object body. Every successful call must be balanced
with `ObDereferenceObject`; leaking the pointer count is a handle-independent leak that no handle
audit will find.

The object manager keeps its own in-tree documentation.
[`base/ntos/ob/ob.txt`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/ob/ob.txt)
is a 1,896-line breakdown of what each module exports:

```text
    obinit.c    KMUTANT ObpInitKillMutant;
                UNICODE_STRING ObpDosDevicesShortName;
                PDEVICE_MAP ObSystemDeviceMap

                ObInitSystem (
                ObInitProcess (
                ObKillProcess (
                ObFindHandleForObject (

    obhandle.c  NtDuplicateObject (
                ObpIncrPointerCount (
                ObpDecrPointerCountWithResult (
                ObpCreateHandle (
                ObpTranslateGrantedAccessIndex (

    obref.c     ObOpenObjectByName (
                ObOpenObjectByPointer (
```

Read it before changing object-manager internals — it names the private (`Obp`) routines that carry
the invariants.

## Threads and pool

Kernel worker threads are created through the process manager, at
[`base/ntos/ps/create.c:184`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/ps/create.c):

```c
NTSTATUS
PsCreateSystemThread(
    OUT PHANDLE ThreadHandle,
    IN ACCESS_MASK DesiredAccess,
    IN POBJECT_ATTRIBUTES ObjectAttributes OPTIONAL,
    IN HANDLE ProcessHandle OPTIONAL,
    OUT PCLIENT_ID ClientId OPTIONAL,
    IN PKSTART_ROUTINE StartRoutine,
    IN PVOID StartContext
    )
```

Passing `NULL` for `ProcessHandle` puts the thread in the initial system process. The returned
handle is a real handle and must be closed with `ZwClose`, or the thread object leaks even after the
thread exits.

Pool allocation is tagged, in
[`base/ntos/ex/pool.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/ex/pool.c):

```c
PVOID
ExAllocatePoolWithTag (
    IN POOL_TYPE PoolType,
    IN SIZE_T NumberOfBytes,
    IN ULONG Tag
    )
```

The same file defines `ExAllocatePoolWithTagPriority` (line 2111) and `ExAllocatePoolWithQuotaTag`
(line 2273). The four-character tag is what pool-mon and the crash dump show, so a new allocation
site should use a tag that identifies its component rather than reusing a generic one.

## The shape of a system service

Every `Nt*` service in this tree follows the same template. Reading one is enough to read them all.
`NtCreateProcessEx` (`base/ntos/ps/create.c:884`) shows the four mandatory parts:

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
{
    NTSTATUS Status;

    PAGED_CODE();                                  // 1. assert IRQL < DISPATCH_LEVEL

    if (KeGetPreviousMode() != KernelMode) {       // 2. only probe for user callers

        try {                                      // 3. exceptions must not escape
            ProbeForWriteHandle (ProcessHandle);
            ...
        } except (EXCEPTION_EXECUTE_HANDLER) {
            return GetExceptionCode();
        }
    }

    ...                                            // 4. do the work, return STATUS_*
}
```

| Step | Why |
| --- | --- |
| `PAGED_CODE()` | Expands to an assertion in checked builds that the caller is at `IRQL < DISPATCH_LEVEL`. It documents the paging contract in code. |
| `KeGetPreviousMode() != KernelMode` | A kernel caller's pointers are trusted; a user caller's pointers must be probed. |
| `ProbeForWrite`/`ProbeForRead` in `try`/`except` | A bad user pointer must become `STATUS_ACCESS_VIOLATION`, not a kernel crash. |
| `NTSTATUS` return | The caller translates it; the kernel never raises a Win32 error. |

`#pragma alloc_text(PAGE, NtName)` moves the routine into the pageable section. Services that can run
at raised IRQL — DPCs, completion routines, cancel routines — must **not** be paged, which is why
`IofCallDriver` and `IofCompleteRequest` are `FASTCALL` and unpaged while `NtCreateFile` is pageable.

## Pool, lookaside lists and quota

| Primitive | Purpose | Implementation |
| --- | --- | --- |
| `ExAllocatePoolWithTag` | Paged or nonpaged pool with a tag | `base/ntos/ex/pool.c` |
| `ExAllocatePoolWithTagPriority` | Allocation with a priority hint | `pool.c:2111` |
| `ExAllocatePoolWithQuotaTag` | Charge the process quota | `pool.c:2273` |
| `ExInitializeLookasideList` | Per-processor fixed-size cache | `base/ntos/ex/lookasid.c` |
| `ExInitializeNPagedLookasideList` | Nonpaged lookaside list | `base/ntos/ex/lookasid.c` |
| `PsChargePoolQuota` | Charge pool to a process | `base/ntos/ps/psquota.c` |
| `PsReturnPoolQuota` | Return it | `psquota.c` |

A lookaside list is a fixed-size, per-processor free list. It is faster than general pool for
objects that are allocated and freed frequently (IRPs, work items, SCB extensions). It trades memory
for lock-free fast paths.

Pool tags are four characters. The convention in this tree is to build them from the component
name, for example `'Irp '` or `'File'`. The tag is what `poolmon` and `!poolused` display, so a
generic tag (`'None'`) makes a leak undiagnosable.

## Kernel synchronization

| Primitive | IRQL | Use |
| --- | --- | --- |
| `FAST_MUTEX` (`ExAcquireFastMutex`) | Raises to `APC_LEVEL` | Protects data for short periods, allows paging |
| `KMUTANT` (`KeWaitForSingleObject`) | `PASSIVE_LEVEL` | Kernel mutex; can be acquired recursively by the owning thread |
| `KSPIN_LOCK` (`KeAcquireSpinLock`) | Raises to `DISPATCH_LEVEL` | Very short critical sections, no paging |
| `ERESOURCE` (`ExAcquireResourceExclusiveLite`) | `PASSIVE_LEVEL` | Reader/writer lock for filesystem metadata |
| `KEVENT` (`KeWaitForSingleObject`) | `PASSIVE_LEVEL` | Signalling between threads |
| `KSEMAPHORE` (`KeWaitForSingleObject`) | `PASSIVE_LEVEL` | Counted signalling |
| `KGATE` / `KQUEUE` | `PASSIVE_LEVEL` | Wait queues and completion ports |

The rule that prevents the most common deadlock: **never** acquire a spin lock and then call
something that can block or page. If you must, drop the lock first, or use a `FAST_MUTEX`/`ERESOURCE`
that permits paging.

## Kernel object lifetimes

| Object | Create | Reference | Dereference |
| --- | --- | --- | --- |
| Process | `PsCreateSystemProcess` | `ObReferenceObjectByHandle` | `ObDereferenceObject` |
| Thread | `PsCreateSystemThread` | `ObReferenceObjectByHandle` | `ObDereferenceObject` |
| Event | `KeInitializeEvent` | `ObReferenceObject` | `ObDereferenceObject` |
| File object | `IoCreateStreamFileObject` | `ObReferenceObject` | `ObDereferenceObject` |
| Device object | `IoCreateDevice` | `ObReferenceObject` | `IoDeleteDevice` |
| Section | `MmCreateSection` | `ObReferenceObjectByHandle` | `ObDereferenceObject` |

Every successful reference must be balanced. A leaked pointer count is invisible to a handle audit,
because the handle can be closed while the object stays alive.

## Frequently asked questions

### Q: How do I find every implementation of a system service?

Search for the `Nt`-prefixed definition, and remember the `Zw` alias is the same routine from kernel
mode:

```bash
rg -n '^NtCreateFile' base/ntos
rg -n '^Ob[A-Za-z]+\s*\(' base/ntos/ob
rg -n '#pragma alloc_text\(PAGE' base/ntos/io
```

`rg -n '^IofCallDriver' base/ntos/io` returns exactly one hit — `base/ntos/io/iomgr/iosubs.c:2273` —
which is a good sanity check that your search pattern is anchored to definitions rather than calls.

### Q: `IofCallDriver` is one line. Is that the real implementation? {#iofcalldriver-indirection}

No. It is a dispatcher indirection so the I/O verifier can be spliced in at run time:

```c
// base/ntos/io/iomgr/iosubs.c:2273
NTSTATUS
FASTCALL
IofCallDriver(
    IN PDEVICE_OBJECT DeviceObject,
    IN OUT PIRP Irp
    )
{
    //
    // This routine will either jump immediately to IopfCallDriver, or rather
    // IovCallDriver.
    //
    return pIofCallDriver(DeviceObject, Irp);
}
```

The real work is in `IopfCallDriver`, and the verified variant is `IovCallDriver` in
`base/ntos/verifier`. The same pattern applies to `IofCompleteRequest` (line 3316) and
`IopfCompleteRequest`. If you are fixing a bug "in `IoCallDriver`", you almost certainly mean one of
those two.

### Q: What runs at page-fault time, and what must not be paged?

Anything reachable from the fault path or from raised IRQL. Concretely, in this tree:
`base/ntos/mm/mmfault.c` handles the fault, and code paged with `#pragma alloc_text(PAGE, ...)` is
excluded from it. Rules of thumb drawn from the code:

```c
// pageable: system-service entry points that touch no pageable memory afterwards
#pragma alloc_text(PAGE, NtCreateFile)

// NOT pageable: dispatch and completion paths, DPC routines, cancel routines
NTSTATUS FASTCALL IofCallDriver(IN PDEVICE_OBJECT, IN OUT PIRP);
```

If you add a routine that a DPC, a completion routine or a spin-lock region calls, do not add it to
an `alloc_text(PAGE, ...)` list.

### Q: A handle audit shows no leak, but memory grows. Where do I look?

Pointer counts and quota, not the handle table. Three places to instrument:

```bash
# object pointer accounting
rg -n 'ObpIncrPointerCount|ObpDecrPointerCountWithResult' base/ntos/ob/obhandle.c
# per-process quota
rg -n 'PsChargeProcess|PspReturnQuota' base/ntos/ps/psquota.c
# pool by tag
rg -n 'ExAllocatePoolWithTag' base/ntos/ex/pool.c
```

A missing `ObDereferenceObject` after a successful `ObReferenceObjectByHandle` produces exactly this
symptom: handles look clean, the object never goes away.

### Q: How does the registry fit into the kernel?

`base/ntos/config` is the configuration manager — the registry implementation. `cmboot.c` loads the
boot hives, `cmapi.c` / `cmapi2.c` implement the `Nt*Key` services, `cmdelay.c` handles delayed
writes, and `chkreg/` holds registry checking tools. A registry *policy* read by a service is not a
kernel change; a change to hive layout, quota or notification semantics is. `base/ntos/config/boot`
holds the boot-hive pieces that must agree with `base/ntsetup`.

### Q: Is the debugger in the kernel?

`base/ntos/kd64` is the kernel debugger stub compiled into the kernel; the debugger *client* is
external. The boot-time transports live elsewhere: `base/boot/kdcom` (serial) and `base/boot/kd1394`
(1394). Kernel-mode support for the `!` extensions of individual components is in per-component
`kdext`/`kdexts` folders — for example `net/tcpip/driver/kdext`, `drivers/storage/kdext` and
`windows/core/ntuser/kdexts`. See [Tests, diagnostics and debugging](/testing-debugging).

### Q: Why does `base/ntos` have its own `makefil0` and `project.mk`?

Because `ntos` is a project with project-wide macros, not just a directory. `base/ntos/ntoskrnl.inc`
is included by the link-configuration nodes (`up`, `mp`, `pae`, `paemp`) and carries the kernel-wide
settings, while `project.mk` sets project-level paths. Changing one of those files changes every
kernel binary at once — which is exactly why such an edit needs a stated reason and a build of all
four configurations.

### Q: What does `PAGED_CODE()` actually do?

In a checked build it expands to an assertion that the current IRQL is below `DISPATCH_LEVEL`. In a
free build it is a no-op. It is both a runtime check and documentation: the routine is in a pageable
section (`#pragma alloc_text(PAGE, ...)`), so calling it at `DISPATCH_LEVEL` is a page fault at
raised IRQL — a bugcheck. `base/ntos/mm/mmfault.c` shows the fault path; there is no recovery.

### Q: Why are `IofCallDriver` and `IofCompleteRequest` not pageable?

Because they are called from DPCs and completion routines at `DISPATCH_LEVEL`, where paging is
illegal. They are marked `FASTCALL` and live in nonpaged code. If you need to do pageable work from a
completion routine, queue a work item (`ExQueueWorkItem`) instead of calling pageable code directly.

### Q: What is the difference between `ObReferenceObjectByHandle` and `ObOpenObjectByName`?

`ObReferenceObjectByHandle` converts an **existing handle** into an object pointer, with an access
check against the handle's granted access. `ObOpenObjectByName` looks a name up in the object
directory and creates a **new handle**, performing an access check against the caller's token. Use
the first when a driver receives a handle from user mode; use the second to open `\Device\...` or
`\BaseNamedObjects\...` by name.

### Q: Where does the kernel put its version string?

`public/sdk/inc/ntverp.h` defines the product type and build number, and the kernel's loader block
carries it into `NtMajorVersion`/`NtMinorVersion`/`NtBuildNumber` in the `KUSER_SHARED_DATA` page.
That page is mapped read-only into every process at `0x7FFE0000` and is how user mode reads the
version without a syscall.
