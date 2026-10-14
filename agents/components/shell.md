# `shell/` — desktop, Explorer, controls and shell services

The interactive shell spans Explorer, common controls/dialogs, shell APIs, browser integration, accessibility/applets, themes and policy. It depends on [`base/win32`](../../base/win32), [`windows/core`](../../windows/core) and COM; browser engine/client networking live in [`inetcore/`](inetcore.md). [`shell/dirs`](../../shell/dirs) specifies build order; see [the complete shell catalog](../catalog/shell.md).

| Path (relative to `shell/`) | Responsibility |
| --- | --- |
| [`explorer`](../../shell/explorer) | Desktop/Explorer process implementations; `desktop2` and `winnt` are distinct build paths. |
| [`shell32`](../../shell/shell32) · [`shlwapi`](../../shell/shlwapi) | Shell APIs, namespaces/extensions, helper utilities. |
| [`shdocvw`](../../shell/shdocvw) · [`browseui`](../../shell/browseui) | Browser/shell view and browsing UI components. |
| [`iexplore`](../../shell/iexplore) · [`iecontrols`](../../shell/iecontrols) | Internet Explorer host and integrated controls; HTML engine is `inetcore/mshtml`. |
| [`comctl32`](../../shell/comctl32) · [`comdlg32`](../../shell/comdlg32) | Common UI controls and dialogs. |
| [`cpls`](../../shell/cpls) · [`applets`](../../shell/applets) | Control Panel and shell applets. |
| [`osshell`](../../shell/osshell) | Accessories, accessibility, OS shell control panels and related programs. |
| [`services`](../../shell/services) | Shell services including themes and hardware-detection paths. |
| [`themes`](../../shell/themes) · [`policies`](../../shell/policies) | Visual styles/themes and shell policy. |
| [`ext`](../../shell/ext) · [`browseinfo`](../../shell/browseinfo) | Explorer extensions and browsing information/support. |
| [`evtmon`](../../shell/evtmon) | Event-monitoring shell component. |
| [`thunk`](../../shell/thunk) · [`typebin`](../../shell/typebin) · [`types`](../../shell/types) | Compatibility/thunk and type/binary-description support. |
| [`lib`](../../shell/lib) · [`inc`](../../shell/inc) · [`ddk`](../../shell/ddk) · [`published`](../../shell/published) | Shared shell libraries/interfaces and publication. |
| [`lcinf`](../../shell/lcinf) · [`sld`](../../shell/sld) | Localization/build metadata and component descriptions. |
| [`tools`](../../shell/tools) · [`drts`](../../shell/drts) · [`shelldrt`](../../shell/shelldrt) · [`docs`](../../shell/docs) | Tools, regression tests and documentation. |
| [`wallpaper`](../../shell/wallpaper) · [`samplemusic`](../../shell/samplemusic) · [`samplemypicts`](../../shell/samplemypicts) | Shipped/sample content and image assets; content is not executable shell logic. |

## Cross-tree trace

For a window/control change, follow [`windows/core/ntuser`](../../windows/core/ntuser) and [`ntgdi`](../../windows/core/ntgdi) → Win32 user clients → `comctl32`/`comdlg32`/`shell32` → Explorer/applets, plus accessibility, themes, locales and tests. For a browser-view change, distinguish `shell/shdocvw` or `browseui` from [`inetcore/mshtml`](../../inetcore/mshtml), [`urlmon`](../../inetcore/urlmon), [`wininet`](../../inetcore/wininet) and [`inetsrv/iis`](../../inetsrv/iis). Service and policy changes may involve security/server enforcement elsewhere. See [Win32 flow](../system-flows.md#2-a-win32ui-operation).
