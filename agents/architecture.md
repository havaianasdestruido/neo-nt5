# Architecture and runtime boundaries

The tree is partitioned mainly by **engineering project**, not a strict layered package manager. Kernel code lives in `base/ntos` and `windows/core`; networking lives in `net`, `drivers`, and file-system redirectors; end-user interfaces depend on many of those projects. Use this page as a map of relationships, then inspect [the actual build definitions](build-and-release.md) and [the directory catalog](catalog/README.md). No diagram here substitutes for a call graph or SKU-specific build evaluation.

## Execution and boot

```text
boot media / firmware
  -> base/boot/bootcode + base/boot/bldr (with boot filesystem/detect/EFI paths)
  -> base/ntos/init + base/hals
       |-- executive / scheduler / process & memory managers / object manager
       |-- I/O manager + PnP/power + file systems + device drivers
       `-- security reference monitor, configuration/registry, cache, IPC
  -> base/subsys/sm (SMSS), then client/server subsystems and services
       |-- base/subsys/csr (CSRSS) + base/win32 + windows/core
       |-- base/screg/sc (service-control infrastructure)
       `-- ds/security (LSA/logon/policy), other services
  -> shell, application/server components, optional roles
```

* **Boot**: [`base/boot/bootcode`](../base/boot/bootcode) holds boot-sector/filesystem boot code; [`base/boot/bldr`](../base/boot/bldr) the loader, [`base/boot/detect`](../base/boot/detect) detection, with EFI, PXE/netboot and setup variants under [`base/boot`](../base/boot). The kernel is assembled from [`base/ntos`](../base/ntos), with architecture-dependent HALs in [`base/hals`](../base/hals). The `up`/`mp`, `pae`, architecture and language folders are variants, not independent operating systems.
* **Executive**: the scheduler/low-level kernel is [`ke`](../base/ntos/ke); processes/threads [`ps`](../base/ntos/ps); virtual memory [`mm`](../base/ntos/mm); I/O and PnP [`io`](../base/ntos/io); object namespaces [`ob`](../base/ntos/ob); security [`se`](../base/ntos/se); configuration/registry [`config`](../base/ntos/config); caching [`cache`](../base/ntos/cache); power [`po`](../base/ntos/po); LPC [`lpc`](../base/ntos/lpc); debugging [`kd64`](../base/ntos/kd64). [`base/ntos/init`](../base/ntos/init) contains kernel initialization/linkage. Read the [base guide](components/base.md#kernel-and-boot-detail) for all `ntos` children.
* **I/O boundary**: drivers under [`drivers`](../drivers) and [`base/fs`](../base/fs) bind into the kernel's device/file abstractions; [`base/pnp`](../base/pnp) and [`drivers/storage`](../drivers/storage) handle device discovery/installation and storage hardware. User-mode file API calls in [`base/win32`](../base/win32) ultimately cross into kernel I/O; file-system redirectors in `base/fs` can route remote operations to networking. A system call is **not** just a direct library call into a driver.
* **First user processes**: [`base/ntdll`](../base/ntdll) exposes the native user-mode boundary. [`SMSS`](../base/subsys/sm/server) manages sessions/subsystem startup; [`CSRSS`](../base/subsys/csr/csrss) is a client/server subsystem host. Win32's user-mode API implementation is spread between [`base/win32/client`](../base/win32/client), [`windows/core/umode`](../windows/core/umode), and related servers; windowing and graphics include [`windows/core/kmode`](../windows/core/kmode), [`ntuser`](../windows/core/ntuser), and [`ntgdi`](../windows/core/ntgdi). Do not conflate the NT kernel (`ntos`) with the Win32 kernel-mode GUI code (`windows/core`).
* **Services and logon**: service control is under [`base/screg/sc`](../base/screg/sc); credentials, policy and LSA are in [`ds/security`](../ds/security), including [`base/lsa`](../ds/security/base/lsa) and [`gina`](../ds/security/gina). Services for events, WMI, directory, network and IIS live in their respective projects. The graphical desktop begins in [`shell/explorer`](../shell/explorer), rather than in kernel initialization.

## Cross-cutting planes

| Plane | Producer and consumer locations | Why it matters |
| --- | --- | --- |
| Native/Win32 API | [`base/ntdll`](../base/ntdll), [`base/win32`](../base/win32), [`windows/core`](../windows/core), [`public/sdk/inc`](../public/sdk/inc) | User/kernel ABI, process and UI contracts. |
| Devices and files | [`base/ntos/io`](../base/ntos/io), [`drivers`](../drivers), [`base/fs`](../base/fs), [`base/pnp`](../base/pnp) | IRPs, filesystem/cache/redirector behavior and installation must agree. |
| Transport | [`net/ndis`](../net/ndis), [`net/tcpip`](../net/tcpip), [`net/sockets`](../net/sockets), [`drivers/net`](../drivers/net) | NIC drivers, protocol stacks, socket-facing libraries and configuration are separate. |
| Identity and directory | [`base/ntos/se`](../base/ntos/se), [`ds/security`](../ds/security), [`ds/ds`](../ds/ds), [`ds/netapi`](../ds/netapi), [`admin`](../admin) | Enforcement, authentication, directory storage, APIs and management UI are separate. |
| Interprocess and object interfaces | [`com/rpc`](../com/rpc), [`com/ole32`](../com/ole32), [`admin/wmi`](../admin/wmi), [`base/wmi`](../base/wmi) | RPC/COM contracts and WMI providers bridge processes and project trees. |
| Session/presentation | [`windows/core`](../windows/core), [`shell`](../shell), [`termsrv`](../termsrv), [`printscan`](../printscan) | Interactive, remote, and printed output follow different paths. |
| Internet/media roles | [`inetcore`](../inetcore), [`inetsrv`](../inetsrv), [`multimedia`](../multimedia), [`enduser`](../enduser) | Browser client, server roles, codecs/graphics and bundled apps are not the OS kernel. |

## Storage, security, and networking

* [`base/fs/ntfs`](../base/fs/ntfs), [`fastfat`](../base/fs/fastfat), [`cdfs`](../base/fs/cdfs), [`udfs`](../base/fs/udfs), and [`efs`](../base/fs/efs) cover distinct formats/features; [`base/fs/mup`](../base/fs/mup), [`rdr2`](../base/fs/rdr2), and [`srv`](../base/fs/srv) route/provide network files. Storage port/class and volume drivers are in [`drivers/storage`](../drivers/storage). For a particular request, distinguish filesystem, filter, volume, port, and user-mode API layers.
* The kernel [`se`](../base/ntos/se) enforces access checks; the logon/LSA/crypto/PKI components are under [`ds/security`](../ds/security). Directory service implementation (`ds/ds`) and ESE storage (`ds/ese98`) are different layers. Policy editors/management tools appear in [`admin`](../admin). Do not infer a security guarantee solely from an administration tool.
* [`net/ndis`](../net/ndis) sits near network hardware, [`net/tcpip/driver`](../net/tcpip/driver) holds IPv4/TCP driver sources, [`net/tcpip`](../net/tcpip) also contains APIs/services/commands, and [`net/sockets`](../net/sockets) exposes Winsock-facing code. [`net/ipsec`](../net/ipsec), [`net/rras`](../net/rras), [`net/dhcp`](../net/dhcp), and [`net/config`](../net/config) add security, routing, address service and configuration. Older transports coexist in this historical tree.

## Service and application surface

[`com`](../com) supplies RPC/COM infrastructure; [`admin`](../admin) includes WMI, MMC/snap-ins and setup/management tools; [`inetsrv/iis`](../inetsrv/iis) contains HTTP/FTP and IIS management; [`inetsrv/msmq`](../inetsrv/msmq) messaging; [`inetcore`](../inetcore) browser/HTTP client components; [`printscan`](../printscan) the spooler, fax, scan and WIA; [`multimedia`](../multimedia) media pipelines; [`termsrv`](../termsrv) multi-session/remote desktop components; [`enduser`](../enduser) additional client software. Installation is shared between [`base/ntsetup`](../base/ntsetup) and component-specific `setup`/INF trees, while build staging uses [`tools/postbuildscripts`](../tools/postbuildscripts).

## How to read this architecture

1. Start at a user-visible feature, then follow one [end-to-end flow](system-flows.md).
2. Find the relevant `dirs` traversal and leaf `sources` file with [the catalog](catalog/README.md); account for architecture, locale, SKU and optional guards.
3. Check [interfaces](interfaces.md) for headers/IDL and installation metadata; inspect producers **and** consumers before editing.
4. Use [component guides](README.md#component-guides) for a broader tree map, and [checkout limitations](build-and-release.md#checkout-limitations) before asserting a build or release works.
