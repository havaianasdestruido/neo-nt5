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

## The cache manager and fast I/O

Two caches sit in front of the disk. The **system cache** (`base/ntos/cache`) maps file data through
sections; the **filesystem metadata cache** is the FSD's own (the NTFS log and the FAT directory
cache). `CcInitializeCacheMap` attaches a file object to the cache, and from then on a read that
hits the cache is satisfied by a memory copy rather than an IRP to the disk.

| Cache manager routine | Purpose |
| --- | --- |
| `CcInitializeCacheMap` | Attach a file object to the cache |
| `CcPinRead` / `CcPinWrite` | Pin pages in memory for direct modification |
| `CcPreparePinWrite` | Prepare a pinned write (copy-on-write handling) |
| `CcMapData` | Map a range read-only |
| `CcUnpinData` | Release pinned pages |
| `CcFlushCache` | Write dirty pages to the FSD |
| `CcPurgeCacheSection` | Drop a range from the cache |
| `CcSetFileSizes` | Tell the cache about truncate/extend |
| `CcIsFileCached` | Is any of the range resident? |

The **fast I/O** path bypasses IRPs entirely for cached reads and writes. The driver object's
`FastIoDispatch` table carries `FastIoRead`, `FastIoWrite`, `FastIoQueryBasicInfo`,
`FastIoQueryStandardInfo` and `AcquireFileForNtCreateSection`. `base/ntos/fsrtl/fastio.c` holds the
shared default implementations a filesystem can copy into its own dispatch table.

```text
NtReadFile
  -> IoPageRead / NtReadFile -> IofCallDriver        (IRP path)
  -> FsRtlCopyRead                                  (fast I/O path)
       -> CcCopyRead -> memcpy out of the cache
       -> on a miss, CcWaitForCurrentLazyWriterActivity and build an IRP
```

A driver that supplies fast I/O must keep it consistent with its IRP path, or the same read returns
different data depending on whether the cache is warm. The classic bug is a fast I/O routine that
does not update the file pointer while the IRP path does.

## Oplocks and locking

| Operation | Mechanism |
| --- | --- |
| Byte-range lock | `IRP_MJ_LOCK_CONTROL` / `FSCTL_LOCK_VOLUME`; `FileLock` in the FSD |
| Opportunistic lock | `FSCTL_REQUEST_OPLOCK_LEVEL_1`/`_2`, `FSCTL_OPLOCK_BREAK_ACKNOWLEDGE` |
| Batch oplock | `FSCTL_REQUEST_BATCH_OPLOCK` |
| Filter oplock | `FSCTL_REQUEST_FILTER_OPLOCK` |
| Directory change notification | `IRP_MJ_DIRECTORY_CONTROL` with `IRP_MN_NOTIFY_CHANGE_DIRECTORY` |

An oplock is granted to the first opener of a file on a redirected (SMB) share. It lets the client
cache aggressively; when a second opener arrives, the server **breaks** the oplock, and the client
must acknowledge before the second open proceeds. `base/fs/ntfs` and `base/fs/fastfat` implement the
local break; `base/fs/rdr2` (the SMB redirector) implements the client side. A stale oplock causes
the notorious "file in use" message that no process seems to own.

## Volume management and mount

The volume stack is layered:

```text
IoCreateFile(\??\C:\path)
   -> ObpLookupObjectName -> \??\C: symbolic link -> \Device\HarddiskVolume1
      -> IoGetDeviceObjectPointer -> the volume device object
         -> IoGetDeviceVerifier... -> the volume's VPB -> the filesystem's device object
            -> IRP to the filesystem
```

| Layer | Directory | Role |
| --- | --- | --- |
| Volume manager | `drivers/inc/volmgr.h` (headers only) | Creates `\Device\HarddiskVolumeN`, assigns drive letters, mount points |
| Mount manager | `drivers/filters/mountmgr` | Database of volume GUIDs to mount points |
| Partition manager | `drivers/storage/partmgr` | Reads partition tables, creates volume PDOs |
| Fault-tolerant disk | `drivers/storage/newft` | FT volume sets and stripes (ftdisk) |
| Volume snapshot | `drivers/storage/volsnap` | Shadow-copy volume driver |
| Filesystem recognizer | `base/fsrec` | Probes an unmounted volume for a known FS and loads it |
| NTFS | `base/fs/ntfs` | The filesystem itself |
| Fastfat | `base/fs/fastfat` | FAT12/16/32 |
| CDFS/UDFS | `base/fs/cdfs`, `base/fs/udfs` | Optical media |

:::note
The volume manager itself is **not** present as a source directory in this checkout: only its
headers (`drivers/inc/volmgr.h`, `drivers/inc/volmgrx.h`) and the disktracker client
(`com/svcdlls/trksvcs/trkwks/volmgr.cxx`) are. `volmgr.sys` is a binary-only component here, so a
change to volume naming cannot be made from this tree. That is a genuine gap, not an omission in
this page.
:::

A filesystem registers with `IoRegisterFileSystem`. The recognizer then calls it when a volume
arrives. If no filesystem claims the volume, the mount fails with `STATUS_UNRECOGNIZED_VOLUME`, which
Win32 reports as `ERROR_UNRECOGNIZED_VOLUME` / "The volume does not contain a recognized file system."

A filesystem registers with `IoRegisterFileSystem`. The recognizer then calls it when a volume
arrives. If no filesystem claims the volume, the mount fails with `STATUS_UNRECOGNIZED_VOLUME`, which
Win32 reports as `ERROR_UNRECOGNIZED_VOLUME` / "The volume does not contain a recognized file system."

## IOCTL and the device-control contract

An IOCTL code is built with `CTL_CODE`:

```c
#define IOCTL_DISK_GET_DRIVE_GEOMETRY \
    CTL_CODE(IOCTL_DISK_BASE, 0x0000, METHOD_BUFFERED, FILE_ANY_ACCESS)
```

| Field | Bits | Meaning |
| --- | --- | --- |
| Device type | 16–31 | `FILE_DEVICE_DISK`, `FILE_DEVICE_FILE_SYSTEM`, ... |
| Access | 14–15 | `FILE_ANY_ACCESS`, `FILE_READ_ACCESS`, `FILE_WRITE_ACCESS`, `FILE_READ_ACCESS|FILE_WRITE_ACCESS` |
| Function | 2–13 | The driver's function number; `0x800`+ are vendor-defined |
| Method | 0–1 | `METHOD_BUFFERED`, `METHOD_IN_DIRECT`, `METHOD_OUT_DIRECT`, `METHOD_NEITHER` |

The method determines who copies the buffers and whether `Irp->AssociatedIrp.SystemBuffer` or the
MDL is used:

| Method | Input | Output | Driver must |
| --- | --- | --- | --- |
| `METHOD_BUFFERED` | `SystemBuffer` | `SystemBuffer` | Set `IoStatus.Information` and `Information` |
| `METHOD_IN_DIRECT` | MDL | `SystemBuffer` | Probe/lock the input |
| `METHOD_OUT_DIRECT` | `SystemBuffer` | MDL | Probe/lock the output |
| `METHOD_NEITHER` | `Irp->UserBuffer` | `Irp->UserBuffer` | Probe everything, build MDLs yourself |

`METHOD_NEITHER` is the only method where the driver must probe both buffers. It is also the source
of most historical local privilege escalations. Prefer `METHOD_BUFFERED` unless a large transfer
makes the double copy unacceptable.

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

### Q: Why does `IoCallDriver` return before the driver finishes?

Because the I/O model is asynchronous. `IoCallDriver` queues the IRP to the next device object and
returns immediately. The lower driver completes the IRP later, on its own thread, and
`IoCompleteRequest` walks the completion routines you attached with `IoSetCompletionRoutine`. If you
need to wait, use `KeWaitForSingleObject` on an event you set in the completion routine, or
`IoBuildSynchronousFsdRequest`, which does that for you.

### Q: What is a VPB and why does it matter?

A Volume Parameter Block (`VPB`) links a volume device object to the filesystem device object that
has mounted it. `IoGetDeviceObjectPointer` follows the VPB; a filesystem filter that wants to see
all requests attaches above the filesystem, not above the volume. `ReferenceCount` in the VPB
prevents the filesystem from unmounting while a file object is open.

### Q: What does `IoAttachDeviceToDeviceStack` do that `IoAttachDevice` does not?

`IoAttachDeviceToDeviceStack` attaches at the **top** of the existing stack and returns the device
object it attached above, which is what a filter must store in its own device extension. It also
propagates the `Characteristics`, `SectorSize`, `AlignmentRequirement` and `DeviceType` fields of the
target, so the filter does not need to copy them by hand. `IoAttachDevice` attaches at the bottom
and does not do that propagation — it is for drivers that replace the whole stack.

### Q: How does a filesystem tell the cache manager a file grew?

`CcSetFileSizes`. Forgetting it means the cache keeps stale beyond-EOF pages; the next read past the
old size either returns zeros or faults. A truncate must also `CcPurgeCacheSection` the removed
range, or a later read returns the truncated data from the cache.

### Q: Why does `IoCompleteRequest` require `IoStatus.Status` to be set?

Because the I/O manager copies `IoStatus.Status` into the caller's `IO_STATUS_BLOCK` and uses it to
decide whether to transfer data. An IRP completed without a status is a bugcheck in a checked build
and undefined behaviour in a free one. Set `Status` and `Information` **before** calling
`IoCompleteRequest`; the IRP may be freed the moment the call returns.

### Q: What is the difference between `IoBuildDeviceIoControlRequest` and allocating an IRP myself?

`IoBuildDeviceIoControlRequest` builds a **synchronous** IRP on the caller's stack, sets up the
system buffer or MDL for the transfer method, and returns an IRP that must be sent with
`IoCallDriver` and freed with `IoFreeIrp` after the wait. `IoBuildAsynchronousFsdRequest` builds one
that can be completed asynchronously. Allocating by hand (`IoAllocateIrp`) gives full control but
means you must set `MajorFunction`, `FileObject`, `IoStatus`, the stack location, and the cancel and
completion semantics yourself.

### Q: Where are the IOCTL codes for storage defined?

`public/sdk/inc/winioctl.h` (the published Win32 IOCTLs) and `public/sdk/inc/ntdddisk.h`,
`ntddscsi.h`, `ntddstor.h`, `ntddcdrm.h` (the DDK-level storage IOCTLs). `public/ddk/inc/wdm.h`
defines the `IO_STACK_LOCATION` fields they land in. A driver that defines a private IOCTL must use
`FILE_DEVICE_UNKNOWN` (or its own type) and a function number at or above `0x800`.

### Q: Why is my filesystem not being loaded for a volume?

Three common reasons: the volume's boot sector is not recognized by `base/fs/fs_rec`, the filesystem
is not registered with `IoRegisterFileSystem`, or the volume is marked `FILE_FLOPPY_DISKETTE`/removable
and the recognizer skips it. Check `HKLM\SYSTEM\CurrentControlSet\Services\<fs>` for the driver's
`Group` and `Start` values, and the ` SERVICE_FS_FILTER` ordering. Use `fsutil fsinfo drives` to see
what the mount manager thinks exists.

### Q: What is the difference between `IRP_MJ_READ` and `IRP_MJ_DEVICE_CONTROL` with
`IOCTL_DISK_READ`?

`IRP_MJ_READ` is a normal read through the filesystem; it is subject to caching, oplocks, byte-range
locks and security checks. `IOCTL_DISK_READ` goes to the **disk class driver** and bypasses the
filesystem entirely — it reads raw sectors, ignoring the mount. Raw access requires
`SE_MANAGE_VOLUME_NAME` or an administrative token, and must be aligned to the sector size.
