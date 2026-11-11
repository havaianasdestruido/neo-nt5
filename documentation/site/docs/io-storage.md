---
title: I/O, file systems and storage
sidebar_position: 5
description: The IRP lifecycle, the layered split between the I/O manager, file systems, class and port drivers, Plug and Play, and where each format lives.
---

A file operation in this tree crosses at least four separate projects. Knowing which layer owns a
symptom is most of the work: the I/O manager (`base/ntos/io`), the file system (`base/fs`), the class
and port drivers (`drivers/storage`), and Plug and Play / setup (`base/pnp`).

## The IRP lifecycle

An I/O request is a packet with a stack of locations, one per driver it passes through. The I/O
manager builds it, `IofCallDriver` sends it down, `IofCompleteRequest` walks the completion routines
back up. The stack cursor is a macro in the DDK header,
[`public/ddk/inc/wdm/wdm.h:12424`](https://github.com/havaianasdestruido/neo-nt5/blob/main/public/ddk/inc/wdm/wdm.h):

```c
#define IoGetNextIrpStackLocation( Irp ) (\
    (Irp)->Tail.Overlay.CurrentStackLocation - 1 )
```

Allocation and completion are indirections in
[`base/ntos/io/iomgr/iosubs.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/io/iomgr/iosubs.c),
so the verifier can substitute its own:

```c
PIRP
IoAllocateIrp(
    IN CCHAR StackSize,
    IN BOOLEAN ChargeQuota
    )
{
    return (pIoAllocateIrp(StackSize, ChargeQuota));
}
```

Other anchors in the same file: `IoBuildSynchronousFsdRequest` (line 2102), `IoCreateDevice`
(line 4236), `IofCallDriver` (line 2273), `IofCompleteRequest` (line 3316) and the thin
`IoCompleteRequest` wrapper (line 13025).

The completion path is documented at length in the source itself, in the header comment of
`IopfCompleteRequest`:

```text
1.  A check is made to determine whether the packet's stack locations
    have been exhausted.  If not, then the stack location pointer is set
    to the next location and if there is a routine to be invoked, then
    it will be invoked. ...

    If a routine is invoked to complete the packet for a specific driver
    which needs to perform work a lot of work or the work needs to be
    performed in the context of another process, then the routine will
    return an alternate success code of STATUS_MORE_PROCESSING_REQUIRED.
```

`STATUS_MORE_PROCESSING_REQUIRED` is the mechanism that lets a driver defer completion. Misusing it —
returning it without ever completing the IRP later — is the classic "hung I/O with no visible owner"
bug.

## File system drivers

`base/fs/` holds one directory per format or role:

| Directory | Role |
| --- | --- |
| `ntfs`, `fastfat`, `cdfs`, `udfs` | On-disk file systems |
| `efs` | Encrypting file system filter layer |
| `mup` | Multiple UNC provider — routes a UNC path to a redirector |
| `rdr2` | The SMB client redirector |
| `srv` | The SMB server service |
| `npfs`, `mailslot` | Named pipes and mailslots |
| `clfs`, `lfs` | Common log file system and the older log file service |
| `dfs`, `hsm`, `sis`, `remotefs`, `smbtrsup` | DFS, hierarchical storage, single-instance store, remote/transport support |
| `fltsamples` | Legacy filter samples: `filespy`, `sfilter`, `latency`, `iotest` |

A file system registers itself by filling in the driver object's dispatch table. From
[`base/fs/ntfs/ntfsinit.c:245`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/fs/ntfs/ntfsinit.c):

```c
DriverObject->MajorFunction[IRP_MJ_CREATE]                   = (PDRIVER_DISPATCH)NtfsFsdCreate;
DriverObject->MajorFunction[IRP_MJ_CLOSE]                    = (PDRIVER_DISPATCH)NtfsFsdClose;
DriverObject->MajorFunction[IRP_MJ_READ]                     = (PDRIVER_DISPATCH)NtfsFsdRead;
DriverObject->MajorFunction[IRP_MJ_WRITE]                    = (PDRIVER_DISPATCH)NtfsFsdWrite;
DriverObject->MajorFunction[IRP_MJ_FLUSH_BUFFERS]            = (PDRIVER_DISPATCH)NtfsFsdFlushBuffers;
DriverObject->MajorFunction[IRP_MJ_FILE_SYSTEM_CONTROL]      = (PDRIVER_DISPATCH)NtfsFsdFileSystemControl;
DriverObject->MajorFunction[IRP_MJ_CLEANUP]                  = (PDRIVER_DISPATCH)NtfsFsdCleanup;
DriverObject->MajorFunction[IRP_MJ_SHUTDOWN]                 = (PDRIVER_DISPATCH)NtfsFsdShutdown;
DriverObject->MajorFunction[IRP_MJ_PNP]                      = (PDRIVER_DISPATCH)NtfsFsdPnp;

DriverObject->FastIoDispatch = &NtfsFastIoDispatch;

NtfsFastIoDispatch.SizeOfFastIoDispatch =    sizeof(FAST_IO_DISPATCH);
NtfsFastIoDispatch.FastIoCheckIfPossible =   NtfsFastIoCheckIfPossible;
NtfsFastIoDispatch.FastIoRead =              NtfsCopyReadA;
NtfsFastIoDispatch.FastIoWrite =             NtfsCopyWriteA;
```

Two things to notice. Several major functions share one dispatcher (`NtfsFsdDispatch`) because they
all take the same path, and the `FastIoDispatch` table is a *separate* fast path that bypasses IRPs
entirely — a change to cached-read semantics has to be made in both places or the two paths diverge.

The `Fsd` prefix means "file system driver": the routine may be called in the context of the
requesting thread. `Fsp`-prefixed routines run in the file system's own worker context. That
distinction determines what you may do about blocking, APCs and exception handling.

## Storage class and port drivers

`drivers/storage/` is layered, and the layers have distinct owners:

| Layer | Directory | Example |
| --- | --- | --- |
| Class (device-type logic) | `class`, `classpnp`, `cdrom`, `disk`, `tape`, `changer` | `disk.sys` |
| Port / miniport | `port` (`scsi`, `raid`, `diskdump`), `scsiport`, `ide`, `iscsiprt`, `sbp2port` | `scsiport.sys` |
| Volume and filtering | `partmgr`, `volsnap`, `newft`, `drivearb`, `fpfilter`, `addfilter` | partitioning, snapshots, fault tolerance |
| Removable / legacy | `fdc`, `sfloppy`, `mcd`, `redbook`, `cdaudio`, `rsm2`, `tffsport` | |
| Instrumentation | `diskperf`, `scsiwmi`, `kdext` | performance and WMI |

The class driver `disk.sys` does not talk to hardware directly; it hands a `CLASS_INIT_DATA`
structure to `classpnp`. From
[`drivers/storage/disk/disk.c:181`](https://github.com/havaianasdestruido/neo-nt5/blob/main/drivers/storage/disk/disk.c):

```c
DriverEntry(
    IN PDRIVER_OBJECT DriverObject,
    IN PUNICODE_STRING RegistryPath
    )
{
    CLASS_INIT_DATA InitializationData;
    CLASS_QUERY_WMI_REGINFO_EX_LIST classQueryWmiRegInfoExList;
    GUID guidQueryRegInfoEx = GUID_CLASSPNP_QUERY_REGINFOEX;

    NTSTATUS status;

#if defined(_X86_)
    //
    // Read the information NtDetect squirreled away about the disks in this
    // system.
    //
    status = DiskSaveDetectInfo(DriverObject);
    ...
#endif
```

and its build definition, `drivers/storage/disk/sources`, links against the class library:

```bat
TARGETNAME=disk
TARGETPATH=obj
TARGETTYPE=DRIVER

TARGETLIBS=$(DDK_LIB_PATH)\classpnp.lib
```

`drivers/storage/classpnp` also ships an in-tree document,
[`classpnp.htm`](https://github.com/havaianasdestruido/neo-nt5/blob/main/drivers/storage/classpnp/classpnp.htm),
describing the class-driver contract. Read it as reference; per the repository's
[source-only policy](/#the-source-only-change-policy), behaviour changes belong in the C
source, not in that page.

## Plug and Play and setup

`base/pnp/` contains the user-mode half: `umpnpmgr` (the PnP manager service), `cfgmgr32` and
`setupapi` (the installation APIs), `newdev`, `hdwwiz` (add-hardware wizard), `hotplug`, plus `idl`
and a `test` directory. The kernel half is `base/ntos/io/pnpmgr`, and resource arbitration is
`base/ntos/arb`.

An INF is part of the contract, not decoration — a driver that builds but is not described by an INF
never loads on a clean install. A minimal real example,
[`admin/dcpromo/dcpdns.inf`](https://github.com/havaianasdestruido/neo-nt5/blob/main/admin/dcpromo/dcpdns.inf):

```inf
[Version]
Signature = "$Windows NT$"

[Components]
NetOC=netoc.dll,NetOcSetupProc,netoc.inf

[Global]
WindowTitle=Windows NT Server Setup -- Installing DNS Server
```

That one delegates to a network optional-component DLL. Driver INFs are larger and carry
`[Manufacturer]`, `[SourceDisksFiles]` and `[DestinationDirs]` sections.

## Frequently asked questions

### Q: Which layer produced this error status?

Walk the stack, not the status code. A `STATUS_*` value travels up through every completion routine
and any of them can rewrite it. Practical triage:

```bash
# is the status generated by the I/O manager itself?
rg -n 'STATUS_INVALID_PARAMETER' base/ntos/io/iomgr/*.c | head

# is it a filesystem-specific status?
rg -n 'return STATUS_' base/fs/ntfs/create.c | head

# or does the port driver translate a SCSI sense code?
rg -n 'ScsiPortNotification|MapScsiStatus' drivers/storage/port/scsi/*.c | head
```

If the same status appears in several layers, the *deepest* one that can produce it for this request
is the one to change.

### Q: Is `fltmgr` in this tree?

There is no `base/fs/fltmgr` directory in this checkout. What exists is the legacy filter sample set
under `base/fs/fltsamples/` — `filespy`, `sfilter`, `latency` and `iotest` — which attach to a device
object and intercept IRPs the older way. If you are looking for a filter framework, that is the
mechanism present here; do not assume the modern filter manager API is available.

```bash
ls base/fs/fltsamples        # dirs  filespy  iotest  latency  sfilter
ls base/fs | grep -i flt     # fltsamples only
```

### Q: Where does a network path (`\\server\share`) get resolved? {#network-path-resolution}

In `mup`, then in the redirector. `base/fs/mup` decides which redirector provider claims the prefix;
`base/fs/rdr2` implements the SMB client; `base/fs/srv` is the server side. A network-file bug
therefore has three candidate owners before the network stack is even involved:

```text
CreateFile("\\server\share\f") -> mup prefix lookup -> rdr2 redirector
                               -> net/tdi + net/tcpip transport
```

See [Networking stack](/networking) for the transport half.

### Q: What is the difference between `class` and `classpnp`?

`class` is the historical class driver; `classpnp` is the PnP/power-aware shared library that modern
class drivers (`disk`, `cdrom`) link against and delegate to. That is why `disk/sources` has
`TARGETLIBS=$(DDK_LIB_PATH)\classpnp.lib` and why `disk.sys`'s `DriverEntry` is mostly a
`CLASS_INIT_DATA` initialisation. A change to retry, autorun or power behaviour usually belongs in
`classpnp` — check `retry.c`, `autorun.c` and `power.c` there before touching `disk`.

### Q: How do I add a source file to a filesystem driver?

To the leaf `sources`, never to the local `makefile`. NTFS's own leaf file lists them explicitly, so
the edit is a one-line addition to a `SOURCES=` continuation:

```bash
grep -n "^SOURCES=" -A 30 base/fs/ntfs/sources | head -35
```

Then confirm the directory is reached: `base/dirs` must list `fs`, and `base/fs/dirs` must list the
format directory.

### Q: Does a change here need a registry or INF update too?

Often. Storage drivers read configuration from
`HKLM\SYSTEM\CurrentControlSet\Services\<name>` — the `RegistryPath` argument to `DriverEntry` is
exactly that services node. If you add a tunable, it needs a default in the INF or in the hive under
`base/ntsetup`, otherwise a clean install behaves differently from a machine that has the value set
by hand.

### Q: Can I test any of this without booting Windows?

Only statically. The tree does contain kernel test scaffolding and samples — for example
`base/pnp/test`, `base/fs/fltsamples/iotest`, and the `drt` directories described in
[Tests, diagnostics and debugging](/testing-debugging) — but running them needs a target system. On
this checkout the honest evidence is a source read, the build-definition chain, and
`git diff --check`. Say which of those you did.
