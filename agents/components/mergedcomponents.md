# `mergedcomponents/` — cross-project integration targets

This tree gathers components whose sources/exports integrate multiple projects and shared setup assets. Do not assume it is a runtime layer inserted between every subsystem. [`mergedcomponents/dirs`](../../mergedcomponents/dirs) specifies its traversal; [the catalog](../catalog/mergedcomponents.md) lists each nested build input.

| Path (relative to `mergedcomponents/`) | Purpose |
| --- | --- |
| [`actxprxy`](../../mergedcomponents/actxprxy) | ActiveX/COM proxy/stub aggregation, including generated proxy sources. |
| [`advapi32`](../../mergedcomponents/advapi32) | Merged Win32 advanced API export/implementation surface (security, events and other contributions); see also [`ds/win32/advapi`](../../ds/win32/advapi) and [`base/win32`](../../base/win32). |
| [`uuid`](../../mergedcomponents/uuid) | Shared GUID/UUID definitions. |
| [`wlnotify`](../../mergedcomponents/wlnotify) | Winlogon notification component and resources. |
| [`wmistub`](../../mergedcomponents/wmistub) | WMI stub/export integration; coordinate with [`admin/wmi`](../../admin/wmi) and [`base/wmi`](../../base/wmi). |
| [`dload`](../../mergedcomponents/dload) · [`dlcheck`](../../mergedcomponents/dlcheck) | Delay-load helpers and checker. |
| [`setupinfs`](../../mergedcomponents/setupinfs) | Setup/INF integration and delivery metadata. |
| [`ddk`](../../mergedcomponents/ddk) · [`releasenotes`](../../mergedcomponents/releasenotes) | DDK-facing material and release-note packaging. |

When changing an exported API, find its contributing source and declaration, the merged target's `sources`/`.def`, dependent import library, callers, and setup/postbuild path. A change to `mergedcomponents/advapi32` can affect security, service, event and client APIs across trees; see [interfaces](../interfaces.md) and [build/release](../build-and-release.md).
