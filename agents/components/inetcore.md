# `inetcore/` — Internet client stack and browser engine

This tree contains HTML/browser, URL/protocol and HTTP clients, Outlook Express and connection setup. It is **not** IIS: servers live in [`inetsrv/`](inetsrv.md). Browser UI is also split across [`shell/shdocvw`](../../shell/shdocvw), `browseui` and `iexplore`. [`inetcore/dirs`](../../inetcore/dirs) determines build traversal; [the full catalog](../catalog/inetcore.md) covers all checked-in paths.

| Path (relative to `inetcore/`) | Responsibility |
| --- | --- |
| [`mshtml`](../../inetcore/mshtml) | Trident HTML engine, DOM/rendering/layout-related implementation. |
| [`urlmon`](../../inetcore/urlmon) | URL monikers, binding and protocol handling. |
| [`wininet`](../../inetcore/wininet) · [`winhttp`](../../inetcore/winhttp) | Different Internet/HTTP client libraries; do not assume their APIs share an implementation. |
| [`outlookexpress`](../../inetcore/outlookexpress) | Outlook Express mail/news client components. |
| [`connectionwizard`](../../inetcore/connectionwizard) | Internet connection setup wizard. |
| [`digest`](../../inetcore/digest) · [`passport`](../../inetcore/passport) | Web authentication/integration components. |
| [`datacab`](../../inetcore/datacab) · [`setup`](../../inetcore/setup) | Client packaging and installation. |
| [`webcontrols`](../../inetcore/webcontrols) · [`ietools`](../../inetcore/ietools) | Web editing/control and IE tooling material checked in here; inspect `dirs` reachability. |
| [`javahlp`](../../inetcore/javahlp) | Java helper/integration; `java/` itself is named by `inetcore/dirs` but absent here. |
| [`lcinf`](../../inetcore/lcinf) · [`published`](../../inetcore/published) | Localization and interface-publication assets. |

## Trace a web-client change

Host UI (`shell/iexplore`, `shdocvw`, `browseui`) → `urlmon` and/or `wininet`/`winhttp` → networking (`net/tcpip`, `net/sockets`) → remote server; content rendering → `mshtml` and Win32 graphics (`windows/core`). Check security zones/protocol handlers, encoding/locale, threading, COM registration, setup and tests at the actual boundary. `inetcore/dirs` also lists absent `vml/`; never equate this checkout with a complete IE build. See [web flow](../system-flows.md#6-a-web-request-or-print-job) and [checkout limits](../build-and-release.md#checkout-limitations).
