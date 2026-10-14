# `termsrv/` — terminal sessions and remote desktop

Terminal Services adds session management, remote protocol/graphics/transport, client and administrative APIs, licensing, printing/resource redirection and setup. It works with Win32 session code in [`windows/core`](windows.md), subsystem startup in [`base/subsys`](../../base/subsys), networking in [`net/`](net.md), and shell/logon in other trees. [`termsrv/dirs`](../../termsrv/dirs) documents its own build order, but **root `dirs` does not name `termsrv/`**. The [catalog](../catalog/termsrv.md) inventories all nested paths without claiming they are root-build reachable.

| Path (relative to `termsrv/`) | Responsibility |
| --- | --- |
| [`drivers`](../../termsrv/drivers) | Session/terminal driver and transport subtrees (`termdd`, `td`, etc.). |
| [`winsta`](../../termsrv/winsta) · [`wtsapi`](../../termsrv/wtsapi) · [`apisub`](../../termsrv/apisub) | Window-station, Terminal Services API and subsystem interface pieces. |
| [`syslib`](../../termsrv/syslib) · [`common`](../../termsrv/common) · [`tsutil`](../../termsrv/tsutil) | Shared system, runtime and utility code. |
| [`regapi`](../../termsrv/regapi) · [`icaapi`](../../termsrv/icaapi) | Registration/client and ICA-compatible API surfaces. |
| [`license`](../../termsrv/license) · [`tscert`](../../termsrv/tscert) | Licensing and certificate-related service assets. |
| [`sessdir`](../../termsrv/sessdir) | Session Directory infrastructure. |
| [`admtools`](../../termsrv/admtools) · [`perfts`](../../termsrv/perfts) · [`wmi`](../../termsrv/wmi) | Administration, performance instrumentation and management providers. |
| [`remdsk`](../../termsrv/remdsk) · [`cdmodem`](../../termsrv/cdmodem) | Redirected desktop/device/modem-related components. |
| [`clcreator`](../../termsrv/clcreator) · [`httpproxy`](../../termsrv/httpproxy) | Client-generation and HTTP proxy-related material. |
| [`tsappcmp`](../../termsrv/tsappcmp) · [`tsuserex`](../../termsrv/tsuserex) | Application compatibility and user/session extensions. |
| [`rdfilter`](../../termsrv/rdfilter) | RDP-related filter and unit test. |
| [`setup`](../../termsrv/setup) · [`sld`](../../termsrv/sld) · [`publish`](../../termsrv/publish) | Install/component descriptions and published interfaces. |
| [`inc`](../../termsrv/inc) · [`dload`](../../termsrv/dload) · [`reskit`](../../termsrv/reskit) | Internal headers, delay-load and resource-kit support. |
| [`wince`](../../termsrv/wince) | Optional Windows CE client material (`OPTIONAL_DIRS` in `termsrv/dirs`). |

## Session boundary

Trace connection (transport under `termsrv/drivers/td` and `net/`) → session/window-station API → Win32 graphical subsystem and logon/security → redirected devices/print/clipboard and user environment. Follow both local and remote paths; auth, permissions, licensing, reconnect/disconnect and 32/64-bit handling are distinct concerns. Do not assume this checkout's root build packages `termsrv/` merely because its subtree contains `dirs` and `sources`. See [build limitations](../build-and-release.md#checkout-limitations).
