---
title: Interfaces and cross-project contracts
sidebar_position: 9
description: Public, published and private headers, IDL and RPC, WMI schemas, INFs, and how to trace both sides of a contract before changing one.
---

A change in this tree often crosses a build or runtime boundary even when only one source file looks
involved. There is no single universal `include/` directory and no package manifest. This page maps
where contracts live so you can find **both sides** before editing either.

## Public, published and private

| Location | Contract | Notes |
| --- | --- | --- |
| `public/sdk/inc` (1,462 entries) | Application SDK headers | The user-facing ABI; `.idl` files live here too, e.g. `activaut.idl` |
| `public/sdk/lib`, `public/sdk/lib16`, `public/sdk/inc16` | Import libraries, 16-bit compat | |
| `public/ddk/inc`, `public/ddk/lib` | Driver headers | `wdm.h` is at `public/ddk/inc/wdm/wdm.h`, not `public/ddk/inc/wdm.h` |
| `public/halkit`, `public/ifskit`, `public/processorkit`, `public/oak`, `public/tst` | HAL, IFS, processor, OEM kit interfaces | |
| `public/internal` | Per-project internal headers consumed across trees | **Not** a public API promise |
| root `published/` | `ddk`, `sdk`, `oak`, `genxddk`, `genxwin` publication steps | |
| `*/published` | Project-level publication | `com/published`, `net/published`, `ds/published` |
| project `inc`, `lib`, `idl`, `componentdef` | Private/shared headers and registration descriptors | 65 tracked paths match `componentdef` |

Path macros for all of these are defined once in
[`tools/projects.inc`](https://github.com/havaianasdestruido/neo-nt5/blob/main/tools/projects.inc),
so a `sources` file refers to `$(BASE_LIB_PATH)` rather than to a directory.

### The `.w` publication convention

Some projects publish interface headers under a `.w` extension. `net/published/inc/` holds 132 of
them — `afd.w`, `atm.w`, `dhcpapi.w`, `authif.w` and so on. They are header copies, not a new
language; `net/published/inc/afd.w` opens with:

```c
/*++

Module Name:

    Afd.h

Abstract:

    Contains structures and declarations for AFD.  AFD stands for the
    Ancillary Function Driver.  This driver enhances the functionality
    of TDI so that it is a sufficiently rich interface to support
    user-mode sockets and XTI DLLs.

--*/
```

Meanwhile the private original is `public/internal/net/inc/afd.h`. **Two copies of one contract.**
Editing only the published copy will be overwritten by the next build; editing only the private one
leaves other trees compiling against a stale interface. Find the `sources` or publication step that
produces the copy and change the producer.

## IDL and RPC

The tree contains **1,658 `.idl` files**. The compiler and runtime are in `com/rpc/`:

| Directory | Role |
| --- | --- |
| `com/rpc/midl` | The MIDL compiler |
| `com/rpc/runtime` | The RPC runtime, including `trans/common/afd.cxx` (the AFD transport) |
| `com/rpc/ndr20`, `com/rpc/ndr64` | 32-bit and 64-bit NDR marshalling engines |
| `com/rpc/ndrlib`, `com/rpc/ndrmem`, `com/rpc/ndrexts` | NDR support libraries |
| `com/rpc/locator` | The RPC locator service and its `idl/` |
| `com/rpc/uuidgen`, `com/rpc/rpccfg`, `com/rpc/tools` | UUID generation, configuration, tooling |

A real interface definition,
[`com/rpc/locator/idl/nsiclt.idl`](https://github.com/havaianasdestruido/neo-nt5/blob/main/com/rpc/locator/idl/nsiclt.idl):

```idl
[
 uuid (d3fbb514-0e3b-11cb-8fad-08002b1d29c3),
 version (1.0),
 pointer_default (unique)]

interface NsiC
{

import"nsicom.idl";

void nsi_binding_lookup_begin
    (
#ifdef __CLIENT__         // workaround for midl bug.
    [in]        handle_t                function_explicit_handle,
#endif
    [in]        UNSIGNED32              entry_name_syntax,
    [in]        STRING_T                entry_name,
    [in]        NSI_INTERFACE_ID_T     *if_spec,
    [in]        NSI_UUID_P_T            obj_uuid,
    [in]        UNSIGNED32              binding_max_count,
    [in]        UNSIGNED32              ignore,
    [out]       NSI_NS_HANDLE_T        *import_context,
    [out]       UNSIGNED16             *status
    );
```

Every attribute there is a compatibility decision: the `uuid` identifies the interface on the wire,
`version` gates negotiation, `pointer_default(unique)` sets null-handling semantics for every pointer
that does not state its own, and `ndr64` means the same IDL marshals differently on 64-bit — which is
why the tree carries two NDR engines.

Build order matters for IDL. `com/dirs` warns that IDL projects must be traversed early because
everything else consumes their generated headers.

## WMI and management schemas

The tree contains **540 `.mof` files**. A MOF file is a schema contract, and a provider binary
without its MOF registered is not discoverable. From
[`admin/eelvewer/eel.mof`](https://github.com/havaianasdestruido/neo-nt5/blob/main/admin/eelvewer/eel.mof):

```mof
#pragma namespace("\\\\.\\ROOT")
instance of __namespace{
     name="EMM";
};
#pragma namespace("\\\\.\\ROOT\\EMM")
// Event Log record
Class Microsoft_EELEntry
{
    [Description ("The EventID property is the GUID. It identifies "
"the event. ..."), DisplayName("Event ID")]
    uint64 EventID;
    [Description ("The SourceSubsystemType property reveals the source within "
"the node - Ntevent log, SMS log, etc.."), DisplayName("Source Subsystem Type")]
    string SourceSubsystemType;
```

The pieces that have to agree: the MOF class definition, the provider that fills it, its
registration, and the consumer's query. `ndis.sys` even carries its own schema at
`net/ndis/sys/ndis.mof`, so a change to NDIS-managed properties is a schema change.

Relevant locations: `base/wmi`, `admin/wmi/wbem`, `admin/wmiprov`, `mergedcomponents/wmistub`, and
per-project `mof` files.

## Installation and registration contracts

There are **1,318 `.inf` files**. The delivery chain for a binary is:

```text
sources target -> binplace / publication -> setup INF or MOF registration
                -> postbuild selection (pbuild.dat) -> SKU / media
```

A minimal INF, [`admin/dcpromo/dcpdns.inf`](https://github.com/havaianasdestruido/neo-nt5/blob/main/admin/dcpromo/dcpdns.inf):

```inf
[Version]
Signature = "$Windows NT$"

[Components]
NetOC=netoc.dll,NetOcSetupProc,netoc.inf

[Global]
WindowTitle=Windows NT Server Setup -- Installing DNS Server
```

Useful locations: `base/ntsetup/inf`, `mergedcomponents/setupinfs`, per-project `setup` and `sld`
folders, and `tools/postbuildscripts`.

## IDL in depth

An IDL file is a complete contract: the interface identity, the wire types, the direction of every
parameter, and the error semantics. Every attribute in the `[...]` block changes what the generated
stub does.

```idl
[
    object,                                     // COM interface; generates vtable-based stubs
    uuid(00000000-0000-0000-0000-000000000000),
    pointer_default(unique),
    helpstring("ISample Interface"),
    dual,                                       // dual interface: IDispatch + vtable
    oleautomation                               //Automation-compatible types only
]
interface ISample : IUnknown
{
    HRESULT Method([in] long cb, [in, size_is(cb)] byte *buf);
    HRESULT Get([out, retval] BSTR *pName);
};
```

| Attribute | Effect |
| --- | --- |
| `object` | COM (vtable) rather than RPC (handle-based) binding |
| `uuid` | Interface identity; must be stable forever |
| `dual` | Generates both `IDispatch` and vtable access |
| `oleautomation` | Restricts types to Automation-compatible ones |
| `pointer_default(unique`/`ref`/`ptr`) | Default pointer semantics |
| `local` | No wire stub; local RPC only (same machine) |
| `async_uuid` | Generates an asynchronous variant |
| `implicit_handle` | Declares an implicit binding handle |
| `auto_handle` | Let the runtime choose the binding |
| `string` | Null-terminated string |
| `size_is` / `length_is` / `max_is` | Array sizing |
| `in` / `out` / `in,out` | Marshalling direction |
| `ref` | Non-nullable pointer |
| `unique` | Nullable pointer, no aliasing |
| `ptr` | Full pointer, aliasing allowed |
| `context_handle` | Server-side state, not marshalled |
| `handle` | Explicit binding handle |
| `transmit_as` / `wire_marshal` | Custom wire representation |
| `call_as` / `local` | Separate local and remote prototypes |
| `iid_is` | Runtime-typed interface pointer |

### What MIDL emits

```text
foo.idl
  -> foo.h        prototypes, format-string externs, type definitions
  -> foo_c.c      client stubs (or foo_p.c for /Oicf proxy)
  -> foo_s.c      server stubs (the dispatch table)
  -> foo_i.c      the interface (MIDL 3.x, for /env win64)
  -> dlldata.c    the proxy/stub registration (PSFactoryBuffer)
```

| Flag | Meaning |
| --- | --- |
| `/Oicf` | Interpreted stubs with format strings (smaller, flexible) |
| `/Os` | Fully interpreted stubs (smaller, slower) |
| `/O1` / `/O2` | Optimisation levels for size/speed |
| `/env win32` / `/env win64` | Target environment for pointer sizing |
| `/robust` | Add range and correlation checks (NDRExt) |
| `/protocol all` | Generate both NDR20 and NDR64 format strings |
| `/app_config` | Use an application configuration file |
| `/tlb` | Also produce a type library |

`/robust` is what makes `size_is` and `range` enforceable on the wire. Without it, a malicious
client can send a count that does not match the buffer, and the stub will trust it.

### A complete RPC example, both sides

Interface:

```idl
// calc.idl
[
    uuid(6B4E1B40-8F0F-11D0-8A2B-00C04FD75A13),
    version(1.0),
    pointer_default(unique)
]
interface calc
{
    void Shutdown([in] handle_t h);
    long Add([in] handle_t h, [in] long a, [in] long b);
    error_status_t Divide(
        [in]  handle_t h,
        [in]  long a,
        [in]  long b,
        [out] long *result);
}
```

Server implementation:

```c
#include "calc.h"

long Add(handle_t h, long a, long b) { return a + b; }

error_status_t Divide(handle_t h, long a, long b, long *result)
{
    if (b == 0) return CALC_ERROR_DIVIDE_BY_ZERO;
    *result = a / b;
    return ERROR_SUCCESS;
}

void Shutdown(handle_t h) { RpcMgmtStopServerListening(NULL); }
```

Server setup:

```c
RPC_STATUS status = RpcServerUseProtseqEpW(
    (RPC_WSTR)L"ncacn_ip_tcp", RPC_C_PROTSEQ_MAX_REQS_DEFAULT,
    (RPC_WSTR)L"8642", NULL);
if (status == RPC_S_OK) {
    status = RpcServerRegisterIf(calc_v1_0_s_ifspec, NULL, NULL);
    if (status == RPC_S_OK) RpcServerListen(1, RPC_C_LISTEN_MAX_CALLS_DEFAULT, FALSE);
}
```

Client:

```c
RPC_STATUS status;
RPC_WSTR str = NULL;
handle_t h = NULL;

RpcStringBindingComposeW(NULL, (RPC_WSTR)L"ncacn_ip_tcp",
                         (RPC_WSTR)L"server", (RPC_WSTR)L"8642", NULL, &str);
RpcBindingFromStringBindingW(str, &h);
RpcStringFreeW(&str);

long r = 0;
RpcTryExcept {
    r = Add(h, 2, 3);
} RpcExcept(1) {
    printf("RPC error 0x%08lX\n", RpcExceptionCode());
} RpcEndExcept;
RpcBindingFree(&h);
```

Note that `Divide` returns `error_status_t`, which MIDL maps to a fault PDU on the wire: the server
does not return a value, the client raises an RPC exception. That is why `error_status_t` procedures
must be wrapped in `RpcTryExcept`.

## WMI: MOF and the provider contract

A MOF file is a **compiled schema** that the WMI repository stores. A provider binary implements
the methods the schema declares.

```mof
// A minimal provider: one class, one method, one instance.
[dynamic, provider("WmiProv")]
class SampleEvent : __ExtrinsicEvent
{
    [key] string InstanceName;
    uint32  Severity;
};

class SampleMethod
{
    [implemented, static] uint32 DoWork([in] uint32 Count);
};
```

| MOF qualifier | Meaning |
| --- | --- |
| `dynamic` | Instances come from a provider, not the repository |
| `provider("Name")` | The provider's `__Win32Provider` registration |
| `key` | Part of the instance identity |
| `implemented` | The provider implements this method |
| `static` | Called on the class, not an instance |
| `read`, `write` | Property access rights |
| `Values` / `ValueMap` | Enumerated values |
| `Description` | Documentation |

A provider registers with `__Win32Provider` and a `__MethodProviderRegistration`/`__InstanceProviderRegistration`
instance. `admin/wmi` and `base/wmi` hold the WMI infrastructure; `net/ndis/sys/ndis.mof` is a real
schema, and `base/fs/ntfs` and `drivers/storage/classpnp` carry more.

The provider's side of the contract is a set of `IWbemProviderInit` and `IWbemServices` methods:

| Method | Called when |
| --- | --- |
| `IWbemProviderInit::Initialize` | The provider is loaded |
| `IWbemServices::OpenNamespace` | A namespace is opened |
| `IWbemServices::GetObject` | A single object is read |
| `IWbemServices::CreateInstanceEnumAsync` | An enumeration starts |
| `IWbemServices::ExecMethodAsync` | A method is invoked |
| `IWbemServices::PutInstanceAsync` | An instance is written |
| `IWbemServices::DeleteInstanceAsync` | An instance is deleted |

A provider that blocks in `ExecMethodAsync` blocks the WMI service's thread; use `IWbemObjectSink::Indicate`
on a worker thread and return `WBEM_S_NO_ERROR` immediately.

## INF: the installation contract

An INF is a script that the setup interpreter runs. The sections:

| Section | Contents |
| --- | --- |
| `[Version]` | `Signature`, `Class`, `ClassGuid`, `Provider`, `DriverVer` |
| `[Manufacturer]` | Manufacturer names and their model sections |
| `[Models]` / `[Manufacturer%...]` | Device models and their install sections |
| `[DDInstall]` | The install section: `CopyFiles`, `AddReg`, `Include`, `Needs` |
| `[DDInstall.Services]` | `AddService` entries |
| `[DDInstall.HW]` | Hardware-specific settings (`AddReg`) |
| `[DDInstall.CoInstallers]` | Co-installer registration |
| `[DestinationDirs]` | Where `CopyFiles` puts things |
| `[SourceDisksNames]` / `[SourceDisksFiles]` | Source media layout |
| `[Strings]` | Localizable strings (`%Key% = value`) |
| `[DefaultInstall]` | A primitive install, for legacy INFs |

A minimal PnP device INF:

```inf
[Version]
Signature="$WINDOWS NT$"
Class=Sample
ClassGuid={6B4E1B40-8F0F-11D0-8A2B-00C04FD75A13}
Provider=%ProviderName%
DriverVer=11/23/2026,1.0.0.0

[DestinationDirs]
Sample.Copy = 12

[Manufacturer]
%ManufacturerName%=Sample.Mfg

[Sample.Mfg]
%DeviceDesc%=Sample.Install, PCI\VEN_8086&DEV_100E

[Sample.Install]
CopyFiles=Sample.Copy
AddReg=Sample.AddReg

[Sample.Install.Services]
AddService=Sample,0x00000002,Sample.Service

[Sample.Service]
DisplayName=%ServiceDesc%
ServiceType=1
StartType=3
ErrorControl=1
ServiceBinary=%12%\sample.sys

[Sample.Copy]
sample.sys

[Sample.AddReg]
HKR,,DebugLevel,0x00010001,3

[Strings]
ProviderName="Example"
ManufacturerName="Example Hardware"
DeviceDesc="Example Device"
ServiceDesc="Example Device Driver"
```

The `PCI\VEN_8086&DEV_100E` hardware ID is matched against the PnP enumeration. A typo in the
hardware ID produces a device that is "unknown" in Device Manager with no driver installed — the
most common INF bug.

## Frequently asked questions

### Q: I changed a header and one tree broke. How do I find every consumer?

Search for the symbol, then map each hit back to its build node:

```bash
rg -n 'PAFD_ENDPOINT' --glob '*.c' --glob '*.cpp' --glob '*.h' | head -20
rg -n 'AFD_' net/sockets/winsock2 base/ntos | head -20

# which build nodes own the hits?
rg --files-with-matches 'PAFD_ENDPOINT' | xargs -n1 dirname | sort -u | head
```

Then check whether each consumer compiles against the **private** header or the **published** copy —
that is the usual reason a change looks correct and still breaks a distant tree.

### Q: Which header is authoritative when a private and a published copy both exist?

The one the producer's `sources` or publication step names. Trace it rather than guessing:

```bash
# find the publication step
rg -rn 'afd\.w' net/published net/dirs net/*/sources 2>/dev/null | head
# find the private original
find public/internal net -name 'afd.h' -o -name 'afd.w' | head
```

If you cannot find the producer, say so — do not edit both copies and hope.

### Q: Is changing an IDL file a breaking change?

Assume yes until you have checked. The wire contract is the `uuid` plus `version` plus the exact
parameter attributes:

```idl
uuid (d3fbb514-0e3b-11cb-8fad-08002b1d29c3),
version (1.0),
pointer_default (unique)
```

Adding a parameter changes the stub/signature pair. Changing `[in]` to `[out]`, adding `[unique]`
where the default was implicit, or reordering parameters all break marshalling. And because
`com/rpc/ndr20` and `com/rpc/ndr64` are separate engines, a change can behave differently on 32-bit
and 64-bit. Rebuild both clients and servers, and check the generated headers.

### Q: What is `componentdef`, and do I need to touch it?

`componentdef` directories carry component registration and identity descriptors — 65 tracked paths
match the name. `mergedcomponents/uuid/` similarly exists to hold UUID generation for merged
components. If your change adds a COM class, a new interface IID or a new provider identity, the
registration has to land there or in the component's own `componentdef`, or the object will build and
still not be creatable.

### Q: How do I know whether a header is a supported public API?

By location, and the location is a promise, not a label:

| Path | Promise |
| --- | --- |
| `public/sdk/inc` | Application SDK — applications may depend on it |
| `public/ddk/inc`, `public/halkit`, `public/ifskit` | Driver/HAL/IFS — kernel-mode ABI, review IRQL and lifetime |
| `public/internal` | Cross-tree internal — no external promise, but in-tree callers exist |
| project `inc/` | Private to that project, in principle |

"Publicly named here does not override licensing or support conditions" — the tree is proprietary
source, and this documentation makes no support claim about any of it.

### Q: Why did my INF change not reach the installed image?

Because INF delivery goes through postbuild filtering and SKU selection. `pbuild.dat` sequences the
layout and packaging steps, and scripts there loop over per-SKU INF directories — `timebomb.cmd`
iterates `. perinf srvinf blainf sbsinf entinf dtcinf`, which shows the shape of the selection. A
source-tree INF that no setup path references is inert. See
[Build, package and release](/build#sku-shipping).

### Q: Can I check any of this without building?

Partly, and it is worth doing before you claim anything:

```sh
python3 agents/generate_catalog.py --check   # tracked-directory catalog is current
python3 agents/verify.py                     # Markdown links, guide coverage per root tree
python3 -m unittest discover -s documentation/tests
```

Those verify documentation and inventory consistency. They do **not** verify that an interface change
compiles or that a wire format is unchanged — only a real build against both sides can do that, and
no build was run for this site.

### Q: Why does MIDL generate two format strings?

Because the client and the server need different views of the same data. The **type format string**
describes how each type is laid out on the wire (offsets, alignments, pointer layouts); the **procedure
format string** describes each call's stack frame and which type offsets it uses. The client uses
both to build the request; the server uses both to unmarshal it. Both must agree byte for byte, which
is why a mismatched proxy/stub pair fails in ways that look like memory corruption.

### Q: What is the difference between `[in]` and `[in, out]`?

`[in]` marshals from client to server only; the server's changes are discarded. `[in, out]` marshals
both ways: the server sees the client's buffer and its modifications come back. An `[out]`-only
parameter is not initialised on the server — reading it before writing is undefined, and MIDL's
`/robust` stubs may not check it.

### Q: How do I make a COM interface safe for remoting?

Mark it `object` and `uuid`, use only Automation-compatible types if you want `dual`, derive from
`IUnknown`, and — crucially — register a proxy/stub DLL (or a type library) for the interface on
**both** machines. Without a registered proxy/stub, `CoMarshalInterface` fails with
`E_NOINTERFACE` and the cross-apartment call dies.

### Q: What is a `handle_t` really?

It is an opaque pointer to a binding. In RPC it identifies the server and the authentication
context; in COM it is unused. `handle_t` is declared as `void *` in `rpcdce.h` and must be passed
as the first parameter to every RPC call when the interface uses explicit handles.

### Q: Why does my INF install work on one machine and fail on another?

Almost always a hardware-ID mismatch. `PCI\VEN_xxxx&DEV_yyyy` must match the enumerated device exactly;
a machine with a different subsystem revision gets a different ID. Use wildcards
(`PCI\CC_0200`) only if the driver really handles the whole class, and never for a device that
needs a specific workaround. Also check that `DriverVer` is not older than an already-installed
driver — PnP will not downgrade.

### Q: How do I debug an IDL/RPC mismatch?

Start with `RpcDbg` / the RPC debug extensions, and compare the two `Foo__MIDL_ProcFormatString`
blobs. A quick practical check: build both sides from the same `foo.idl` at the same time, with the
same MIDL version and the same `/protocol` setting. Most "RPC server unavailable" reports on a
hand-built pair are a stale stub on one side.

### Q: Where is the type library generated?

By MIDL with `/tlb`, or by the `midl` step in `com/rpc/midl`. `mktyplib` is the older tool and only
handles ODL. The type library is embedded as a resource in the server DLL, so `LoadTypeLib` on the
DLL is how a client discovers the interface.

### Q: Is `oleautomation` required for `dual`?

No, but strongly recommended. `dual` generates both `IDispatch` and vtable paths; `oleautomation`
restricts the parameter types to the Automation-compatible set (`VARIANT`-compatible). A `dual`
interface with a non-Automation type will compile but fail at `IDispatch::Invoke` time.

### Q: How does WMI tie a MOF class to a provider?

Through the `provider` qualifier, which names a `__Win32Provider` instance. The provider's `CLSID`
points at the COM class; the class's `__MethodProviderRegistration`/`__InstanceProviderRegistration`
says which `IWbemServices` methods it supports. `mofcomp` compiles the MOF into the repository. A
class that is `dynamic` but has no provider registration returns `WBEM_E_INVALID_CLASS` at query time.

### Q: What is the difference between `__InstanceProviderRegistration` and `__MethodProviderRegistration`?

They declare different capabilities. The first says the provider can enumerate, get, put and delete
instances; the second says it can execute methods. A provider can register both, or only one. A
`dynamic` class with methods but no method registration returns `WBEM_E_METHOD_NOT_IMPLEMENTED`.
