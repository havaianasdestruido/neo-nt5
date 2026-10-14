# `published/` — root-level publication targets

Root [`dirs`](../../dirs) visits `Published` early. [`published/dirs`](../../published/dirs) lists shared publication areas; many engineering projects also have their own `*/published` or `*/publish` trees. This tree helps expose SDK/DDK/OAK interfaces, rather than implementing the entire OS. [All nested published paths](../catalog/published.md) are indexed.

| Path (relative to `published/`) | Purpose |
| --- | --- |
| [`ddk`](../../published/ddk) | Driver-development publication and header/interface work. |
| [`oak`](../../published/oak) | OEM adaptation kit publication. |
| [`sdk`](../../published/sdk) | SDK headers/libraries publication. |
| [`genxwin`](../../published/genxwin) · [`genxddk`](../../published/genxddk) | Generated/exported Windows and DDK interface artifacts. |

**How it fits:** a project's interface sources/IDL may generate or publish headers/import libs consumed via [`public/`](public.md). Root ordering is significant; if an API changes, follow producer → publication → consumer and account for generated files. `published/` itself is small; it does not replace project-specific trees like [`com/published`](../../com/published) or [`net/published`](../../net/published). See [interface contracts](../interfaces.md) and [build phases](../build-and-release.md#phases-and-artifacts).
