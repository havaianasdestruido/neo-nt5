# `multimedia/` — graphics, audio, video and streaming

Multimedia has API/runtime, hardware, codecs/filters, streaming and sample/packaging branches. Kernel streaming/device drivers also live in [`drivers/ksfilter`](../../drivers/ksfilter), [`drivers/wdm`](../../drivers/wdm), and display/windowing in [`windows/core`](../../windows/core). [`multimedia/dirs`](../../multimedia/dirs) selects components/architectures; browse [all nested multimedia paths](../catalog/multimedia.md).

| Path (relative to `multimedia/`) | Responsibility |
| --- | --- |
| [`directx`](../../multimedia/directx) | DirectX APIs, rendering/audio/game/media-related components; pair with Win32 graphics and display drivers. |
| [`dshow`](../../multimedia/dshow) | DirectShow filters, DMO, streams, media control and associated tools/setup. |
| [`media`](../../multimedia/media) | Wave/AVI, audio services, MCI and media applications/libraries. |
| [`netshow`](../../multimedia/netshow) | Network media/streaming components. |
| [`opengl`](../../multimedia/opengl) | OpenGL implementation/interfaces and graphics integration. |
| [`danim`](../../multimedia/danim) | DirectAnimation, with architecture-specific traversal. |
| [`embedded`](../../multimedia/embedded) | Embedded/component-description support. |
| [`resmgr`](../../multimedia/resmgr) | Media resource-manager/kernel-mode area. |
| [`reality`](../../multimedia/reality) | Legacy binary/registration assets and miscellaneous build data in this checkout; inspect before treating it as a runtime engine. |
| [`inc`](../../multimedia/inc) · [`lib`](../../multimedia/lib) · [`private`](../../multimedia/private) | Shared and private headers/libraries. |
| [`ddk`](../../multimedia/ddk) · [`published`](../../multimedia/published) | Driver-facing and published media interfaces. |

## Trace a playback/capture issue

Application → media API/graph (`directx`, `dshow`, `media`) → codec/filter or rendering service → Kernel Streaming (`drivers/ksfilter`, `drivers/wdm`) → sound/video hardware driver. Network streaming also traverses `net/` and `netshow`; windowed output also touches `windows/core` and shell controls. Validate format negotiation, timing, threading, resource lifetimes, 32/64-bit and locale/build flavors, not just a standalone filter. See [interface boundaries](../interfaces.md#binary-and-process-boundaries).
