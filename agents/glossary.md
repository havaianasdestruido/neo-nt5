# Terms and abbreviations used in these guides

| Term | Meaning in this tree |
| --- | --- |
| **NEONT 5.x** | NEONT 5 family. This snapshot contains XP/Server-related code and version/architecture branches; it is not evidence that every released variant is checked in. |
| **HAL** | Hardware Abstraction Layer, under [`base/hals`](../base/hals); bridges kernel and platform-specific hardware details. |
| **NTOS / executive** | Kernel/executive sources under [`base/ntos`](../base/ntos): memory, process, I/O, object, security, cache, scheduler and related managers. |
| **NTDLL / native API** | User-mode native-system interface under [`base/ntdll`](../base/ntdll); not itself the kernel. |
| **SMSS / CSRSS** | Session Manager and client/server subsystem process sources in [`base/subsys/sm`](../base/subsys/sm) and [`base/subsys/csr`](../base/subsys/csr). |
| **Win32k** | Kernel-side Win32 graphics/windowing code in [`windows/core`](../windows/core); distinct from `base/ntos`. |
| **IRP / PnP / WDM** | I/O Request Packet; Plug and Play; Windows Driver Model. Relevant paths: [`base/ntos/io`](../base/ntos/io), [`base/pnp`](../base/pnp), [`drivers/wdm`](../drivers/wdm). |
| **NDIS / TDI / Winsock** | Network driver, kernel transport and socket API boundaries respectively; see [`net/ndis`](../net/ndis), [`net/tdi`](../net/tdi), [`net/sockets`](../net/sockets). They are not interchangeable. |
| **LSA / GINA / AD / ESE** | Local Security Authority; logon interface; Active Directory; Extensible Storage Engine. See [`ds/security`](../ds/security), [`ds/ds`](../ds/ds), [`ds/ese98`](../ds/ese98). |
| **COM / RPC / MIDL / IDL** | Component Object Model; remote procedure calls; the IDL compiler; interface definitions. See [`com/ole32`](../com/ole32), [`com/rpc`](../com/rpc), and per-project `idl` directories. |
| **WMI / WBEM / MOF** | Windows Management Instrumentation; Web-Based Enterprise Management; management schema/registration files. See [`base/wmi`](../base/wmi), [`admin/wmi`](../admin/wmi), project providers. |
| **IIS / MSMQ / WIA / RDP** | Internet Information Services; Message Queuing; Windows Image Acquisition; Remote Desktop Protocol. Main paths: [`inetsrv/iis`](../inetsrv/iis), [`inetsrv/msmq`](../inetsrv/msmq), [`printscan/wia`](../printscan/wia), [`termsrv`](../termsrv). |
| **SDK / DDK / OAK** | Software / Driver / OEM adaptation kit interface families under [`public`](../public). Publicly named here does not override licensing or support conditions. |
| **`dirs` / `sources` / `makefile`** | Legacy `build.exe` traversal, leaf target definition and NMAKE indirection. See [build/release](build-and-release.md#inputs-and-traversal). |
| **`published` / `public`** | Publication-producing project subtrees vs shared interface/artifact destinations (which may also be checked in). See [interfaces](interfaces.md#public-published-and-private). |
| **`up` / `mp` / `pae` / `wow64`** | Uniprocessor, multiprocessor, Physical Address Extension, and 32-bit compatibility on 64-bit Windows. These are build/runtime variants; directory names alone do not mean they are all supported here. |
| **INF / SLD / SKU / postbuild** | Installation metadata; component description files; product edition selection; staging/signing/layout/media processing. See [build/release](build-and-release.md#phases-and-artifacts). |
| **Razzle / `build.exe` / NMAKE** | Historic environment setup, build traversal and make execution respectively. Not shell scripts for POSIX/Linux. |
| **DRT** | Design/regression testing convention visible in several project `drt`/`test` trees. A test folder's presence is not evidence the test can run outside its intended environment. |
