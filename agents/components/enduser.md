# `enduser/` — bundled client components and redistributables

`enduser/` collects application-facing components, speech, legacy clients, help/content and compatibility redistributables. It is not the desktop shell (`shell/`) or the browser engine (`inetcore/`). [`enduser/dirs`](../../enduser/dirs) contains many historical entries absent from this checkout; the [catalog](../catalog/enduser.md) distinguishes checked-in paths from build references.

| Path (relative to `enduser/`) | Responsibility |
| --- | --- |
| [`speech`](../../enduser/speech) | Speech API, text-to-speech, runtime, tools and setup material. |
| [`netmeeting`](../../enduser/netmeeting) | NetMeeting client/conferencing components. |
| [`zone_internetgames`](../../enduser/zone_internetgames) | Internet games/Zone client assets. |
| [`downlevelclients`](../../enduser/downlevelclients) | Clients/components for older Windows versions. |
| [`mapistub`](../../enduser/mapistub) · [`msasn1`](../../enduser/msasn1) | MAPI stub and ASN.1 support. |
| [`stuff`](../../enduser/stuff) | Miscellaneous bundled dependencies including HTML Help, XML, OLE DB/ODBC/automation and related binaries; inspect its nested `dirs`/`sources` for the owner. |
| [`vc_asms`](../../enduser/vc_asms) · [`vccomsupport`](../../enduser/vccomsupport) | Visual C++ assemblies and compatibility/support material. |
| [`troubleshoot`](../../enduser/troubleshoot) · [`testlockout`](../../enduser/testlockout) | Troubleshooting and test assets. |
| [`miscdocuments`](../../enduser/miscdocuments) · [`windows.com`](../../enduser/windows.com) | Documentation and web/content integration. |
| [`published`](../../enduser/published) | Interface publication/support for other trees. |

## Boundaries and caveats

For a component change, find its actual producer and runtime host: `stuff` aggregates unrelated technologies, some with primary implementations elsewhere (`com/`, `admin/darwin`, `inetcore/`). Match build target, COM/registry/INF, language and client architecture, not just a shipped file name. Many names in `enduser/dirs` (such as `HelpContent`, `Moviemk`, `ScriptEngines`) have no corresponding checked-in top-level child. Their `dirs` entries are **historical build references**, not proof of code here. See [checkout limitations](../build-and-release.md#checkout-limitations).
