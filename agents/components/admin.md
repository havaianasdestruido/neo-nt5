# `admin/` — management, WMI, setup and administrator UX

`admin/` contains management consoles, WMI/WBEM, directory/network administration, installers, scheduled tasks and system-health UI. It is generally the **management surface**, not the kernel/service implementation it configures. [`admin/dirs`](../../admin/dirs) explicitly orders `burnslib` and `dsadminlib` ahead of consumers. [The catalog](../catalog/admin.md) indexes its full nested tree.

| Path (relative to `admin/`) | Responsibility |
| --- | --- |
| [`activec`](../../admin/activec) · [`controls`](../../admin/controls) | Administrative console/control infrastructure, components, designers and samples. |
| [`snapin`](../../admin/snapin) · [`consoles`](../../admin/consoles) · [`wizards`](../../admin/wizards) | MMC snap-ins, console definitions and management wizards. |
| [`wmi`](../../admin/wmi) · [`wmiprov`](../../admin/wmiprov) · [`wmiscmgr`](../../admin/wmiscmgr) | WBEM/WMI service, providers and management tooling; core WMI helpers also in `base/wmi`. |
| [`admt`](../../admin/admt) · [`dcpromo`](../../admin/dcpromo) | Active Directory Migration Tool and domain controller promotion/setup. |
| [`dscmd`](../../admin/dscmd) · [`dsutils`](../../admin/dsutils) · [`dsweb`](../../admin/dsweb) | Directory CLI, migration/helpers and web controls. |
| [`dsadminlib`](../../admin/dsadminlib) · [`burnslib`](../../admin/burnslib) | Shared administration/DS libraries; `burnslib` documents strings, logging and debug allocation. |
| [`dsclientnt4`](../../admin/dsclientnt4) | Down-level directory client/setup material. |
| [`netid`](../../admin/netid) · [`netui`](../../admin/netui) | Network identity and administrative network UI. |
| [`cys`](../../admin/cys) | Configure Your Server wizard. |
| [`darwin`](../../admin/darwin) | Windows Installer (MSI) engine/tools, SDK and installation data. |
| [`services`](../../admin/services) | Scheduler and other administrative service code. |
| [`pchealth`](../../admin/pchealth) | Help/Support Center, System Restore, system information and related client pieces. |
| [`sms`](../../admin/sms) | SMS/management-related integration or binary-release material; inspect child `dirs` for exact targets. |
| [`hmonitor`](../../admin/hmonitor) | Health monitoring agent and MMC UI. |
| [`select`](../../admin/select) · [`display`](../../admin/display) | Object-selection/control and administration property-page/display code. |
| [`extens`](../../admin/extens) | Directory/admin extensions such as ACL diagnostics and delegation. |
| [`cmdline`](../../admin/cmdline) | Admin commands for events, scheduled tasks, policy, network information, etc. |
| [`eelvewer`](../../admin/eelvewer) | Kalpa viewer/MOF and install assets checked into this tree; not the general Event Log service. |
| [`published`](../../admin/published) | Shared admin headers/libraries and interfaces consumed by other projects. |

## WMI and management boundaries

[`admin/wmi/wbem`](../../admin/wmi/wbem) contains `winmgmt`, providers, consumers, scripting, SDK, setup and tests. Kernel/base helpers are under [`base/wmi`](../../base/wmi); projects may contribute their own providers/`mof` files (network, terminal server, IIS, etc.). An MMC snap-in or command can invoke a WMI/RPC/COM service rather than implement it. For directory behavior compare [`ds/ds`](../../ds/ds), [`ds/security`](../../ds/security), [`ds/netapi`](../../ds/netapi) and setup (`admin/dcpromo`) before changing UI validation. For installer behavior check MSI and component-specific setup/INF plus [postbuild](../build-and-release.md).

## Editing guidance

Trace the object interface, permissions, localization/resources, service implementation and installation/registration. If adding a snap-in command, confirm its backend understands it and that client/server contracts are updated. Do not use administrative UI checks as a substitute for server or kernel authorization; see [interface checklist](../interfaces.md#review-checklist-for-interface-changes).
