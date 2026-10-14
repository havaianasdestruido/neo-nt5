# Suggested agent specializations and handoffs

These are **review roles for people or coding agents**, not programs or actual owners declared by the original project. Assign a role from the change's runtime boundary, not just the folder named in a bug report. One change may require several roles; the [component guides](README.md#component-guides) and [catalog](catalog/README.md) identify the actual files.

| Role | Start in | Must coordinate with / evidence to hand off |
| --- | --- | --- |
| **Boot/kernel** | [base](components/base.md) (`boot`, `ntos`, `hals`, `subsys`) | Driver/storage, security, and build roles. Specify architecture, boot path, ABI/initialization changes and whether a boot test actually ran. |
| **Driver/storage/installation** | [drivers](components/drivers.md), `base/fs`, `base/pnp` | Kernel I/O and setup roles. Identify PnP/power/IRP behavior, INF, request lifetime and target device/test matrix. |
| **Win32/UI** | [windows](components/windows.md), [shell](components/shell.md) | COM/interface, accessibility, client/browser and session roles. Identify user/kernel and 32/64-bit contracts, locales/themes and affected controls/hosts. |
| **Network/transport** | [net](components/net.md), `drivers/net` | Security, IIS/clients and setup roles. Identify NDIS/TDI/Winsock layer, packet/API consumer, configuration and test network. |
| **Identity/directory** | [ds](components/ds.md), `base/ntos/se` | Kernel, COM/RPC, admin and setup roles. Identify token/ACL/LSA/protocol, schema/storage/replication and negative/security tests. |
| **RPC/COM/interface** | [com](components/com.md), [public](components/public.md), [published](components/published.md), [mergedcomponents](components/mergedcomponents.md) | Every producer/consumer. Identify IDL/headers/exports, marshalling, registration, ABI compatibility and generated/published output. |
| **Management/services** | [admin](components/admin.md), [inetsrv](components/inetsrv.md), `base/screg` | Backend and security roles. Identify service API, permissions, WMI/MOF, IPC, setup and administration UI separately. |
| **Internet client/media** | [inetcore](components/inetcore.md), [multimedia](components/multimedia.md), [enduser](components/enduser.md) | Shell/UI, network, device and setup roles. Identify client vs server, graph/codec/stream or content boundary, distribution target and compatibility. |
| **Print/remote sessions** | [printscan](components/printscan.md), [termsrv](components/termsrv.md) | Driver, Win32, network and security roles. Identify spooler/monitor/device or RDP/session/redirection boundary, remote failure paths and service packaging. |
| **Build/release/localization** | [tools](components/tools.md), [sdktools](components/sdktools.md), [loc](components/loc.md), `base/ntsetup` | All implementation roles. Identify ancestor `dirs`, target `sources`, published interfaces, architecture/flavor/SKU/locale, missing prerequisites and exact validation performed. |
| **Independent validation** | [working guide](working-guide.md), [flows](system-flows.md) | Reproduce the issue, review changed contracts and variants, run available tests, and report what could **not** be tested in this checkout. |

## Handoff template

1. **Observable behavior and target:** symptom, expected behavior, relevant [flow](system-flows.md), exact source/build-definition paths.
2. **Contract and risk:** producer/consumer, security boundary, target architecture/locale/SKU, installation/packaging implications.
3. **Change and evidence:** files changed, unit/static/target build/VM tests actually run, log locations and failures. Do not substitute a directory listing for a test.
4. **Unresolved dependencies:** absent directories/tools, alternate owners, architecture/locale/negative cases not tested and a concrete next step. The [checkout limitations](build-and-release.md#checkout-limitations) apply to every role.

Before handing off an interface change, follow the [interface checklist](interfaces.md#review-checklist-for-interface-changes); for documentation updates use `python3 agents/generate_catalog.py --check` and `python3 agents/verify.py`.
