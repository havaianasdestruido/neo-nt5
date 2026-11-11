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
| `io` | I/O manager and PnP | `iomgr/iosubs.c`, `iomgr/create.c`, `iomgr/complete.c`, `pnpmgr/` |
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
