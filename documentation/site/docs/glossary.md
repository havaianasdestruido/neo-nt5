---
title: Glossary
sidebar_position: 28
description: Every abbreviation and term used across this wiki — kernel objects, IRQLs, IRPs, COM, RPC, PE sections, build macros and the tree's own naming conventions.
---

A working glossary for this wiki and for the source tree. Terms are grouped by area; each entry
names the header or directory where the term is defined when that is useful.

## Kernel and executive

| Term | Meaning |
| --- | --- |
| **Executive** | The kernel-mode managers in `base/ntos`: `ke`, `mm`, `ps`, `io`, `ob`, `se`, `ex`, `config`, `cache`, `lpc`, `po`, `dbgk`. |
| **Kernel** (`ke`) | The scheduler, dispatch objects, interrupt handling, spin locks and the lowest-level thread/process primitives. |
| **HAL** | Hardware Abstraction Layer (`base/hals`); the platform-specific layer between firmware and the kernel, built with `TARGETTYPE=HAL`. |
| **IRQL** | Interrupt Request Level: `PASSIVE_LEVEL` (0), `APC_LEVEL` (1), `DISPATCH_LEVEL` (2), device levels above. Code must not block or touch pageable memory at `DISPATCH_LEVEL`. |
| **DPC** | Deferred Procedure Call; runs at `DISPATCH_LEVEL` after an ISR. `KeInitializeDpc`/`KeInsertQueueDpc`. |
| **APC** | Asynchronous Procedure Call; queued to a thread and run at `APC_LEVEL` or `PASSIVE_LEVEL`. |
| **ISR** | Interrupt Service Routine; runs at the device's SynchronIRQL and must be short. |
| **IRP** | I/O Request Packet; the structure that carries a request through a device stack. `IRP_MJ_*` codes select the operation. |
| **IO_STACK_LOCATION** | The per-driver slot in an IRP: major/minor function, parameters, device/file object, completion routine. |
| **Pool** | Kernel heap memory: `ExAllocatePoolWithTag` with a four-character tag; paged or nonpaged. |
| **Paged pool** | Pool that can be paged to disk; only accessible at `IRQL < DISPATCH_LEVEL`. |
| **Nonpaged pool** | Pool that is never paged; required at `DISPATCH_LEVEL` or above. |
| **Object manager** (`ob`) | The kernel component that owns named objects, handle tables and reference counts. |
| **Handle** | A per-process index into the handle table; not a pointer. `ObReferenceObjectByHandle` turns it into an object pointer. |
| **Object directory** | The kernel namespace (`\`, `\??`, `\Device`, `\BaseNamedObjects`). `OBJECT_ATTRIBUTES.RootDirectory` names a parent. |
| **Token** | The security object that holds a user's SID, groups, privileges and integrity level. |
| **SRM** | Security Reference Monitor; the kernel component that performs access checks (`base/ntos/se`). |
| **LPC** | Local Procedure Call; the kernel IPC substrate under RPC and CSRSS. `NtCreatePort`, `NtRequestWaitReplyPort`. |
| **TEB** | Thread Environment Block; per-thread data at `fs:[0]` (x86) / `gs:[0]` (x64): last error, stack limits, TLS slots, exception chain. |
| **PEB** | Process Environment Block; per-process data: loaded modules, heap, command line, environment. |
| **KPCR** | Kernel Processor Control Region; per-CPU data including the current IRQL and the current thread. |
| **Bugcheck** | A kernel stop code; `KeBugcheckEx` in `base/ntos/ke/bugcheck.c`. |
| **Driver Verifier** | The kernel hooks that route I/O through checking code (`base/ntos/verifier`). |

## Memory

| Term | Meaning |
| --- | --- |
| **Virtual address space** | The per-process range of addresses; 2 GiB user / 2 GiB kernel by default on 32-bit, 8 TiB/248 TiB on x64. |
| **Page** | The unit of memory management, typically 4 KiB (`SYSTEM_INFO.dwPageSize`). |
| **Allocation granularity** | The minimum reservation, typically 64 KiB (`SYSTEM_INFO.dwAllocationGranularity`). |
| **Commit** | Charge committed pages to the page file; physical storage is assigned on first touch. |
| **Reserve** | Reserve address space without storage. |
| **Section** | A kernel object that maps a file or pagefile into address space; the basis of memory-mapped files. |
| **View** | A mapping of a section into an address range (`NtMapViewOfSection`). |
| **MDL** | Memory Descriptor List; describes pages for direct I/O (`Irp->MdlAddress`). |
| **VAD** | Virtual Address Descriptor; the kernel's tree describing a process's address space. |
| **Working set** | The set of pages currently resident for a process. |
| **Page fault** | A fault that occurs on access to a non-resident or protected page; handled in `base/ntos/mm/mmfault.c`. |
| **Copy-on-write** | Sharing pages until a write forces a private copy. |
| **Large pages** | Pages larger than 4 KiB (2 MiB/4 MiB), used for TLB efficiency. |

## I/O and storage

| Term | Meaning |
| --- | --- |
| **FSD** | File System Driver (`base/fs/ntfs`, `fastfat`, `cdfs`, `udfs`). |
| **FSD/FSP prefix** | `Fsd` routines run in the requesting thread; `Fsp` routines run in the filesystem's worker context. |
| **Fast I/O** | A cached-I/O path that bypasses IRPs (`FastIoDispatch` in the driver object). |
| **Cache manager** | `base/ntos/cache`; manages the system cache and file mappings for cached I/O. |
| **Class driver** | Device-type logic (`drivers/storage/classpnp`, `disk`, `cdrom`). |
| **Port driver** | Bus/HBA-specific driver (`scsiport`, `ide`, `iscsiprt`). |
| **Miniport** | A driver that links against a port/class library (`NDIS_MINIPORT`, SCSI miniport). |
| **PnP** | Plug and Play; device enumeration, resource assignment, removal (`base/pnp`, `base/ntos/io/pnpmgr`). |
| **Power IRP** | `IRP_MJ_POWER` with `IRP_MN_SET_POWER`/`QUERY_POWER`; must be sent with `PoCallDriver`. |
| **SCSI** | The storage command protocol; `scsi.h` defines CDBs and sense data. |
| **ATAPI** | The ATA packet interface; `drivers/storage/ide`. |
| **Reparse point** | A file-system tag that redirects a name lookup; used by symbolic links, junctions and filters. |
| **Oplock** | An opportunistic lock that lets a client cache a file while it is the only opener. |

## Win32 and USER/GDI

| Term | Meaning |
| --- | --- |
| **Win32 API** | The published C API: kernel32, user32, gdi32, advapi32, shell32, ole32, ws2_32. |
| **Native API** | The `Nt*`/`Zw*` syscall interface implemented by the executive. |
| **ANSI/Unicode** | The A/W export split; the kernel is Unicode. |
| **Calling convention** | `__stdcall` (`WINAPI`), `__cdecl`, `__fastcall` (`FASTCALL`), `__thiscall`. |
| **Window class** | A registered template for windows (`WNDCLASSEX`), owned by the registering module. |
| **Window procedure** | The callback that receives messages for a window. |
| **Message loop** | `GetMessage`/`TranslateMessage`/`DispatchMessage` on a GUI thread. |
| **Non-client area** | The title bar, menu, borders and scroll bars handled by `DefWindowProc`. |
| **DC** | Device Context; a GDI handle to a drawing surface (`GetDC`, `CreateCompatibleDC`). |
| **DIB** | Device-Independent Bitmap; a bitmap with a documented header and accessible bits. |
| **Palette** | A logical colour table for 8-bpp devices. |
| **HRGN** | Region handle; used for clipping and shaped windows. |
| **Hook** | A procedure in the system hook chain (`SetWindowsHookEx`). |
| **CSRSS** | Client/Server Runtime Subsystem; the Windows subsystem process. |
| **Win32k** | The kernel-mode window manager and graphics engine (`windows/core/ntuser`, `ntgdi`). |

## Processes, threads and sync

| Term | Meaning |
| --- | --- |
| **Process** | An address space plus a handle table plus at least one thread. |
| **Thread** | A scheduling unit with its own stack, TEB and context. |
| **Job object** | A container that applies limits to a set of processes. |
| **Critical section** | A user-mode lock with a lazily created kernel event; recursive. |
| **Mutex** | A kernel dispatcher object with ownership and abandoned detection. |
| **Semaphore** | A counted kernel sync object. |
| **Event** | A kernel sync object, manual or auto reset. |
| **Waitable timer** | A kernel timer that can be waited on. |
| **APC queue** | Per-thread queue of APCs; user APCs run at alertable wait. |
| **Quantum** | A thread's scheduling slice. |
| **Affinity** | The set of processors a thread may run on. |
| **Impersonation** | A thread adopting a client's token (`ImpersonateLoggedOnUser`, `RpcImpersonateClient`). |
| **Token** | The security object produced by logon; primary for the process, impersonation for a thread. |

## Registry

| Term | Meaning |
| --- | --- |
| **Hive** | A file-backed or volatile container of keys and values. |
| **Key** | A node in the registry tree; has a name, class, security descriptor and last-write time. |
| **Value** | A named data item under a key; has a type and a byte blob. |
| **Cell** | The allocation unit inside a hive. |
| **Bin** | A 4 KiB-aligned group of cells in a hive. |
| **Root key** | `HKLM`, `HKCU`, `HKCR`, `HKU`, `HKCC`. |
| **Volatile key** | A key not persisted to the hive file (`REG_OPTION_VOLATILE`). |
| **Registry symbolic link** | A `REG_LINK` value resolved during name lookup. |
| **WOW6432Node** | The redirected registry view for 32-bit processes on 64-bit Windows. |

## COM, RPC and OLE

| Term | Meaning |
| --- | --- |
| **COM** | Component Object Model; interfaces, identity, class factories, registration. |
| **IUnknown** | The root interface: `QueryInterface`, `AddRef`, `Release`. |
| **CLSID** | A class GUID; identifies a COM class. |
| **IID** | An interface GUID. |
| **Apartment** | A COM threading context: single-threaded (STA) or multi-threaded (MTA). |
| **Marshalling** | Converting an interface pointer for cross-apartment/process use. |
| **Proxy/stub** | The generated pair that marshals calls across apartments/processes. |
| **Moniker** | A COM object that names and binds another object. |
| **ROT** | Running Object Table; tracks active objects by moniker. |
| **RPC** | Remote Procedure Call; the substrate under COM and many system services. |
| **IDL** | Interface Definition Language; compiled by MIDL. |
| **MIDL** | The IDL compiler (`com/rpc/midl`). |
| **NDR** | Network Data Representation; the RPC wire format (`ndr20`, `ndr64`). |
| **ORPC** | DCOM's object RPC protocol layered on DCE RPC. |
| **Structured storage** | Compound files: `IStorage`, `IStream` (`com/ole32/stg`). |

## PE and the loader

| Term | Meaning |
| --- | --- |
| **PE** | Portable Executable; the Windows image format. |
| **COFF** | Common Object File Format; the object/section format underlying PE. |
| **RVA** | Relative Virtual Address; an offset from the image base. |
| **IAT** | Import Address Table; the patched table of resolved import addresses. |
| **INT** | Import Name Table; the read-only table of imported names. |
| **Relocation** | A fixup applied when the image loads at a different base. |
| **TLS** | Thread-Local Storage; callbacks run before `DllMain`. |
| **KnownDLL** | A DLL mapped at boot and shared; listed under `Session Manager\KnownDLLs`. |
| **SxS** | Side-by-side assemblies; activation-context-based isolation. |

## Build system

| Term | Meaning |
| --- | --- |
| **Razzle** | The environment script `tools/razzle.cmd` that sets up a build session. |
| **`dirs`** | The build traversal file listing subdirectories. |
| **`sources`** | The per-component build definition (`TARGETNAME`, `TARGETTYPE`, `SOURCES`). |
| **`makefile`** | A one-line include of `makefile.def`; edit `sources`, not `makefile`. |
| **`build.exe`** | The historical build engine; `build /cZP` clean, `build /ZP` incremental. |
| **`TARGETTYPE`** | `PROGRAM`, `DYNLINK`, `LIBRARY`, `DRIVER`, `MINIPORT`, `HAL`, `GDI_DRIVER`, `NOTARGET`. |
| **`TARGETLIBS`** | Libraries to link against, resolved through the public/internal lib paths. |
| **Postbuild** | `tools/postbuild.cmd` driving `pbuild.dat`; staging, layout, SKU selection. |
| **Binplace** | The tool that copies build output into the layout. |
| **SKU** | Product edition: `srv`, `sbs`, `ads`, `dtc`, `bla`, `per`, `pro`. |
| **Checked build** | Debug/verification build; enables assertions and pool checking. |
| **Free build** | Optimised release build. |
| **UP/MP** | Uniprocessor / multiprocessor kernel link configuration. |
| **PAE** | Physical Address Extension; `/3GB` and `PAE` variants. |

## Tree-specific naming conventions

| Term | Meaning |
| --- | --- |
| **`Nt`/`Zw` prefix** | Native service names; `Nt` for user mode, `Zw` for kernel mode. |
| **`Rtl` prefix** | Runtime library routine, shared by kernel and user mode. |
| **`Ldr` prefix** | Loader routine in ntdll. |
| **`Csr` prefix** | CSRSS client routine in ntdll. |
| **`Io` prefix** | I/O manager routine (`IoCreateDevice`, `IoCallDriver`). |
| **`Ob` prefix** | Object manager routine. |
| **`Ps` prefix** | Process/thread routine. |
| **`Mm` prefix** | Memory manager routine. |
| **`Se` prefix** | Security routine. |
| **`Cm` prefix** | Configuration manager (registry) routine. |
| **`Ke` prefix** | Kernel routine. |
| **`Ex` prefix** | Executive support routine (pool, time, lookaside). |
| **`Po` prefix** | Power manager routine. |
| **`Fsd`/`Fsp` prefix** | Filesystem dispatch/service routines. |
| **`P` prefix** | Pointer typedef (`PVOID`, `PUNICODE_STRING`). |
| **`U`/`A` suffix** | Unicode/ANSI version of an API (`CreateFileW`/`CreateFileA`). |
| **`Ex` suffix** | Extended version (`CreateFileEx` is not real; `CreateProcessEx` is). |
| **`NtUser`/`NtGdi`** | Win32k system services installed in the shadow service table. |

## Frequently asked questions

### Q: Where can I find the definition of a constant like `PAGE_READONLY`?

In the headers: `public/sdk/inc/winnt.h` for memory and security constants,
`public/sdk/inc/winbase.h` for file and process constants, `public/sdk/inc/winerror.h` for error
codes, `public/sdk/inc/winreg.h` for registry constants. `rg -n 'PAGE_READONLY' public/sdk/inc`
finds the exact line.

### Q: Why do some terms have two meanings (for example, "object")?

Because Windows reuses words across layers. A **kernel object** is an object-manager object (event,
file, process); a **COM object** is an interface-based object; a **directory object** is a kernel
namespace container. This wiki qualifies the term by context.

### Q: What is the difference between an IRP and an IOCTL?

An IRP is the packet that carries any I/O request; an IOCTL is a device-control command code passed
in an IRP with `MajorFunction = IRP_MJ_DEVICE_CONTROL`. Every IOCTL is carried by an IRP; not every
IRP is an IOCTL.

### Q: What is the difference between a thread's stack and a kernel stack?

The user-mode stack is in the process's address space; the kernel stack is a separate per-thread
stack used while the thread executes in kernel mode. A kernel stack is small (12–24 KiB), which is
why deep recursion in kernel mode causes a stack overrun bugcheck.

### Q: What is the difference between `PASSIVE_LEVEL` and `APC_LEVEL`?

`PASSIVE_LEVEL` is the normal thread execution level; `APC_LEVEL` is the level at which APCs are
delivered. Code at `APC_LEVEL` cannot wait for objects and must not touch pageable memory that could
fault. Most driver dispatch routines run at `PASSIVE_LEVEL`; DPCs run at `DISPATCH_LEVEL`.

### Q: Where does "Win32k" end and "the executive" begin?

`win32k.sys` (windows/core/ntuser + ntgdi) is a separate kernel binary that imports a fixed list of
executive exports (`base/ntos/init/w32kexps.txt`). The executive does not import win32k. The
boundary is that import list.

### Q: Is the registry a database?

It is a hierarchical store with transactions, quotas, lazy writes and hive files, but not a
relational database. It has no query language; the API is key-based lookup and enumeration. Storing
large blobs or doing scans in it is an anti-pattern.

### Q: Why are there so many `Nt` prefixes in the tree?

Because the native API is the kernel's real call interface, and the Win32 API is a wrapper. The
`Nt` names are the ones implemented in `base/ntos`; the `Nt` names in `base/ntdll` are the stubs.
The `Zw` names are the kernel-mode aliases.
