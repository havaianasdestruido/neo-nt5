# Interfaces and cross-project contracts

A change in this tree often crosses a build or runtime boundary even when only one source file appears involved. Use this map to find **both sides** of a contract. There is no single universal `include/` or package manifest. Consult [architecture](architecture.md), [build/release](build-and-release.md), and the [directory catalog](catalog/README.md) for context.

## Public, published and private

| Location | Contract / ownership rule |
| --- | --- |
| [`public/sdk`](../public/sdk) | Application SDK headers and import libraries (`inc`, architecture-specific `lib`); declarations/ABI for user-facing APIs. |
| [`public/ddk`](../public/ddk), [`public/halkit`](../public/halkit), [`public/ifskit`](../public/ifskit) | Driver, HAL and filesystem development headers/libs. Kernel interfaces require architecture/IRQL/lifetime review, not just a successful header build. |
| [`public/internal`](../public/internal) | Per-project internal headers/libs consumed across engineering trees; **not** a promise of public supported API. |
| Root [`published`](../published) and project-specific `*/published` | Build steps and copies that expose selected interfaces/assets across projects. See [`com/published`](../com/published), [`net/published`](../net/published), [`ds/published`](../ds/published), etc.; some `published` folders are data-only in this snapshot. |
| Project `inc`, `lib`, `componentdef`, `idl` | Source-owned private/shared headers, static helpers, registration/component descriptors and IDL definitions. Check the exact component's `dirs` and `sources` before deciding which file is authoritative. |

**Practical rule:** find the producer `sources` or IDL file, its published copy and every consumer. Editing a generated or staged copy alone may be overwritten by a build; editing a private header can nevertheless break callers in another tree. The build uses path macros defined in [`tools/projects.inc`](../tools/projects.inc) and project makefiles.

## Binary and process boundaries

* **Native and Win32:** [`base/ntdll`](../base/ntdll) and [`base/ntos`](../base/ntos) meet at native system-call/structure contracts; [`base/win32`](../base/win32), [`windows/core`](../windows/core), [`shell`](../shell) and `public/sdk/inc` expose Win32/user/window contracts. Evaluate calling convention, structure layout, pointer size, version and WOW64 translation before changing signatures.
* **Kernel ↔ device:** I/O request, PnP/power, storage, display, sound and NDIS contracts span [`base/ntos/io`](../base/ntos/io), [`base/pnp`](../base/pnp), [`drivers`](../drivers), [`base/fs`](../base/fs), [`net/ndis`](../net/ndis) and `public/ddk`. The driver and OS sides must agree on registration, request completion, synchronization and teardown. Setup INFs are part of getting the driver loaded, not just deployment decoration.
* **RPC and COM:** [`com/rpc/midl`](../com/rpc/midl), [`com/rpc/runtime`](../com/rpc/runtime), [`com/ole32`](../com/ole32), and each project's `idl`/proxy/UUID directories define wire and object contracts. For changes to an IDL, inspect generated headers, clients and servers, security checks, marshaling, registration and versioning. [`mergedcomponents/uuid`](../mergedcomponents/uuid) and `*/componentdef` also carry identities/registration information.
* **Services/WMI:** management spans [`base/wmi`](../base/wmi), [`admin/wmi/wbem`](../admin/wmi/wbem), [`admin/wmiprov`](../admin/wmiprov), plus per-project providers/`mof` files. MOF and provider registration are contracts; a provider binary without them may not be discoverable. Server services often have separate API/client/IDL/server/setup directories (e.g. [`ds/netapi`](../ds/netapi), [`inetsrv/iis`](../inetsrv/iis)).
* **Networking:** [`net/ndis`](../net/ndis), [`net/tcpip/driver`](../net/tcpip/driver), [`net/tdi`](../net/tdi), [`net/sockets`](../net/sockets) and network configuration/INF all expose different layers; do not equate a socket API change with a packet-driver change.

## Installation, resources and shipment

Source → built target (`sources`) → published headers/libs or staged binary (`binplace`/build macros) → setup INF/registration/MOF → postbuild selection (`pbuild.dat`) → SKU/media. Useful locations include [`base/ntsetup/inf`](../base/ntsetup/inf), [`mergedcomponents/setupinfs`](../mergedcomponents/setupinfs), project-specific `setup` folders, `sld` descriptions, [`tools/postbuildscripts`](../tools/postbuildscripts), and the language/resource trees under the owning project. Not every file goes through every stage. A source fix is not a delivered fix until the appropriate target is reachable, packaged and installed for the intended architecture, locale and SKU.

## Review checklist for interface changes

1. Find declarations and definitions (`public/`, `*/inc`, `*/idl`, local sources); search consumers with `rg` and locate their [build nodes](catalog/README.md).
2. Decide whether the interface is user/kernel, RPC/COM, driver, WMI, on-disk, registry/INF, or resource/locale data. Consider backward compatibility and 32/64-bit variants.
3. Check both error and cleanup paths, security boundary (tokens/ACLs/impersonation), serialization/size rules and versioned structures where applicable.
4. Update the producing target, publication/generated artifacts **through their source**, setup/registration, and relevant tests. Do not check in unrelated generated binaries.
5. Verify [build reachability and limitations](build-and-release.md#checkout-limitations) before claiming the change works on a product image.
