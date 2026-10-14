# End-to-end flows: how the parts cooperate

These are **orientation traces** through relevant source trees, not claims that every SKU follows a single path or that each arrow is an unconditional function call. Use them to locate the boundaries that need review when changing behavior. The [architecture](architecture.md), [interfaces](interfaces.md), and [component catalog](catalog/README.md) supply the next level of detail.

## 1. Boot to an interactive desktop

1. Platform boot code/loader: [`base/boot/bootcode`](../base/boot/bootcode) and [`base/boot/bldr`](../base/boot/bldr); selected boot media and architecture also involve [`detect`](../base/boot/detect), [`efi`](../base/boot/efi), or network boot code.
2. Kernel/HAL start: [`base/ntos/init`](../base/ntos/init), [`base/hals`](../base/hals), and the other [`ntos`](../base/ntos) managers initialize memory, devices, security and processes. [`base/fs`](../base/fs) and [`drivers`](../drivers) provide boot/runtime I/O.
3. First user-mode services: [`base/ntdll`](../base/ntdll), [`base/subsys/sm/server`](../base/subsys/sm/server), [`base/subsys/csr`](../base/subsys/csr), [`base/screg/sc`](../base/screg/sc), and [`ds/security`](../ds/security).
4. Win32 session/UI: [`base/win32`](../base/win32), [`windows/core`](../windows/core), logon code under [`ds/security/gina`](../ds/security/gina), and [`shell/explorer`](../shell/explorer).

**Change impact:** boot format, loader ABI, HAL, registry hive/INF, driver start order, logon/session policies and shell startup are separate concerns. A build in one architecture or locale does not verify them all.

## 2. A Win32/UI operation

Application call → headers under [`public/sdk/inc`](../public/sdk/inc) → user-mode implementations in [`base/win32/client`](../base/win32/client) or [`windows/core/umode`](../windows/core/umode) → [`base/ntdll`](../base/ntdll) / subsystem messaging to [`base/subsys/csr`](../base/subsys/csr) or the kernel-side [`windows/core/ntuser`](../windows/core/ntuser) and [`ntgdi`](../windows/core/ntgdi) → window server / display and input drivers under [`drivers/video`](../drivers/video) and [`drivers/input`](../drivers/input). Higher-level dialogs, Explorer and controls live in [`shell`](../shell). Different APIs take different branches of this trace.

**Change impact:** check ABI and architecture-specific stubs, shared header declarations, cross-process protocols, GUI kernel/user assumptions, and accessibility/locale behavior.

## 3. A local file or network-share operation

File API in [`base/win32`](../base/win32) → native API in [`base/ntdll`](../base/ntdll) → [`base/ntos/io`](../base/ntos/io) and the object/cache/memory managers → local filesystem (for example [`base/fs/ntfs`](../base/fs/ntfs) or [`fastfat`](../base/fs/fastfat)) → volume/class/port drivers in [`drivers/storage`](../drivers/storage). For remote paths, redirector components such as [`base/fs/mup`](../base/fs/mup) and [`rdr2`](../base/fs/rdr2) connect to the network stack; server components such as [`base/fs/srv`](../base/fs/srv) handle the other side. Installation and device enumeration run through [`base/pnp`](../base/pnp) and INF/setup metadata.

**Change impact:** I/O completion, caching, filesystem metadata, access checking, remote protocol and filter layering. Do not edit a storage driver as if it were the filesystem implementation.

## 4. A network packet / socket operation

Physical NIC driver (see [`drivers/net`](../drivers/net)) ↔ [`net/ndis`](../net/ndis) ↔ [`net/tcpip/driver`](../net/tcpip/driver) / [`net/ipsec`](../net/ipsec) ↔ user-facing [`net/sockets`](../net/sockets) and [`net/tcpip/winsock`](../net/tcpip/winsock) ↔ an application or server role (for example [`inetsrv/iis`](../inetsrv/iis)). Configuration, addresses and routing are separate in [`net/config`](../net/config), [`net/dhcp`](../net/dhcp) and [`net/rras`](../net/rras). Legacy stacks under `net/` may be alternatives, not additional mandatory hops.

**Change impact:** kernel/user boundary, packet lifetime, interface contracts (NDIS/TDI/Winsock), IPv4 vs any other stack, and setup/registration of protocol components.

## 5. Logon, policy, and directory lookup

Credentials/logon UI in [`ds/security/gina`](../ds/security/gina) → LSA/authentication in [`ds/security/base/lsa`](../ds/security/base/lsa) and [`ds/security/protocols`](../ds/security/protocols) → local security subsystem and kernel checks in [`base/ntos/se`](../base/ntos/se). When Active Directory is involved, [`ds/ds/src`](../ds/ds/src) provides directory logic, [`ds/ese98`](../ds/ese98) storage, and [`ds/dns`](../ds/dns) / [`ds/netapi`](../ds/netapi) related discovery/APIs. [`admin/dcpromo`](../admin/dcpromo) and [`admin/snapin`](../admin/snapin) manage, rather than themselves enforce, the underlying behavior.

**Change impact:** token/ACL semantics, authentication protocol, RPC/LDAP/ADSI clients, directory schema, database durability, setup and migration. Do not mistake UI validation for kernel authorization.

## 6. A web request or print job

* **Web:** network stack → [`inetsrv/iis/iisrearc`](../inetsrv/iis/iisrearc) and [`inetsrv/iis/svcs/w3`](../inetsrv/iis/svcs/w3) → site content, filters, administration and configuration under [`inetsrv/iis`](../inetsrv/iis). Browser/client rendering instead involves [`inetcore/wininet`](../inetcore/wininet), [`inetcore/urlmon`](../inetcore/urlmon), [`inetcore/mshtml`](../inetcore/mshtml), and [`shell/shdocvw`](../shell/shdocvw).
* **Print:** Win32/shell print API → [`printscan/print/spooler/spoolss`](../printscan/print/spooler/spoolss) → spooler/print processor/monitor under [`printscan/print/spooler`](../printscan/print/spooler) → device-specific drivers under [`printscan/print/drivers`](../printscan/print/drivers). Scanning and imaging are separately under [`printscan/scan`](../printscan/scan) and [`printscan/wia`](../printscan/wia).

**Change impact:** these paths cross process, protocol, service and driver boundaries; public headers, IDL, setup/INF, localization and postbuild packaging can matter as much as the implementation source.
