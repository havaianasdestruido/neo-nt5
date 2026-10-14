# `com/` — RPC, COM/OLE and component activation

`com/` supplies RPC transport/stubs, COM/OLE runtime and related libraries/interfaces used across projects. [`com/dirs`](../../com/dirs) calls out ordering constraints (IDL before consumers, storage before proxy code); consult [every nested COM directory](../catalog/com.md). COM-based application code in other top-level trees is not all contained here.

| Path (relative to `com/`) | Responsibility |
| --- | --- |
| [`rpc`](../../com/rpc) | RPC runtime, MIDL compiler, NDR marshalling, locator, UUID and debugging/tools. |
| [`ole32`](../../com/ole32) | Core COM/OLE runtime, storage, activation/service and proxy/host components. |
| [`ole2ui32`](../../com/ole2ui32) | Standard OLE dialog/user-interface components. |
| [`winole`](../../com/winole) | WinOLE client/server code and samples. |
| [`mobile`](../../com/mobile) | Synchronization Manager and system event notification (`sens`) support. |
| [`mts`](../../com/mts) | Microsoft Transaction Server / COM+ related material. |
| [`netfxoc`](../../com/netfxoc) | .NET optional-component integration; the `netfx` child named in `com/dirs` is missing here. |
| [`svcdlls`](../../com/svcdlls) | COM-related service DLLs, including tracking services. |
| [`rpcutil`](../../com/rpcutil) · [`componentdef`](../../com/componentdef) | RPC utilities and component descriptions/identity. |
| [`inc`](../../com/inc) · [`published`](../../com/published) | Private/shared headers, IDL, UUID and published interfaces/libs. |
| [`oleutest`](../../com/oleutest) | Optional OLE/COM test suite; explicitly listed under `OPTIONAL_DIRS`. |

## Follow an interface end to end

An IDL source (often a project's own `idl` folder or [`com/published/idlrpc`](../../com/published/idlrpc)) → MIDL in [`com/rpc/midl`](../../com/rpc/midl) → generated headers/stubs/proxies in producer and consumer builds → NDR in [`com/rpc/ndr20`](../../com/rpc/ndr20)/[`ndr64`](../../com/rpc/ndr64) and RPC runtime → COM activation/marshaling under [`ole32`](../../com/ole32). Registration, threading, apartment/security and compatibility are part of the contract; simply compiling both sides is insufficient. See [interfaces](../interfaces.md#binary-and-process-boundaries).

**Checkout note:** `com/dirs` names `OleAutomation` and `netfx`, neither present as a `com/` child here. Do not interpret their absence as proof other projects do not depend on them; do not claim a complete COM build has been verified. See [checkout limitations](../build-and-release.md#checkout-limitations).
