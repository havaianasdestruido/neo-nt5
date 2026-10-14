# `public/` — shared development headers and import libraries

`public/` is a checked-in interface/artifact tree, **not** a root `dirs` project in this checkout. Consumers use its SDK/DDK/private headers and architecture-specific libraries; the owning source may be elsewhere or not present. Do not patch an artifact here and assume the producer will retain that edit. [Every nested public directory](../catalog/public.md) is indexed.

| Path (relative to `public/`) | Interface family |
| --- | --- |
| [`sdk`](../../public/sdk) | User-mode SDK: `inc`, `inc16`, `lib`, `lib16`, class and media headers. [`sdk/inc/ntverp.h`](../../public/sdk/inc/ntverp.h) has snapshot version macros. |
| [`ddk`](../../public/ddk) | DDK headers and architecture-specific driver import libraries. |
| [`halkit`](../../public/halkit) | HAL development headers/libraries. |
| [`ifskit`](../../public/ifskit) | Installable filesystem kit headers. |
| [`oak`](../../public/oak) | OEM adaptation kit headers. |
| [`processorkit`](../../public/processorkit) | Processor/platform interfaces. |
| [`internal`](../../public/internal) | Engineering-private headers/import libraries divided by project (`base`, `com`, `ds`, `net`, etc.); not a supported public API merely because of its pathname. |
| [`tst`](../../public/tst) | Shared test headers/support. |

A consumer's `sources` may refer to path macros in [`tools/projects.inc`](../../tools/projects.inc) instead of literal `public` paths. Match headers with the producing tree's `*/published`, `inc`/IDL and `sources`; check target architecture and ABI. See [interfaces](../interfaces.md#public-published-and-private) and [build pipeline](../build-and-release.md).
