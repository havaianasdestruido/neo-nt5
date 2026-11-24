---
title: Interfaces and cross-project contracts
sidebar_position: 9
description: Public, published and private headers, IDL and RPC with wire-level attribute semantics, WMI schemas, INFs, version resources, and how to trace both sides of a contract before changing one.
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

The header families are also *ABI* families. `public/sdk/inc` is what applications compile against
(`windows.h`, `winsock2.h`, `winternl.h`); `public/ddk/inc/wdm/wdm.h` is the kernel contract drivers
compile against — every `Io*` macro quoted in
[I/O, file systems and storage](/io-storage#the-irp-lifecycle) comes from that one file. When a
macro changes there, every driver in the tree changes with it.

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

Every attribute there is a compatibility decision. The table below is the checklist to run against
any IDL diff in this tree — each row is a wire-format question, and the official MIDL reference is
[MIDL language reference](https://learn.microsoft.com/en-us/windows/win32/midl/midl-start-page):

| Attribute | What it fixes | Changing it breaks |
| --- | --- | --- |
| `uuid(...)` | The interface identity on the wire | Everything — old clients bind to the old IID |
| `version(maj.min)` | Negotiation between stubs | Mixed-version client/server pairs |
| `pointer_default(unique)` | Null semantics of every unannotated pointer | Marshalling of all pointer parameters |
| `[in]` / `[out]` / `[in, out]` | Which direction is copied | Stub buffer sizing; silent data loss |
| `[unique]` / `[ref]` / `[ptr]` | Aliasing and nullability | NDR layout of the pointer graph |
| `[string]` | NUL-terminated vs counted arrays | The wire encoding of the buffer |
| `[size_is]` / `[length_is]` / `[switch_is]` | Conformant/varying arrays, unions | The count prefix on the wire |
| `handle_t` / explicit handles | Binding and authentication | Which connection the call travels on |

Build order matters for IDL. `com/dirs` warns that IDL projects must be traversed early because
everything else consumes their generated headers. And because `com/rpc/ndr20` and `com/rpc/ndr64`
are separate marshalling engines, the *same* IDL marshals differently on 32-bit and 64-bit — which
is why the tree carries both and why a change must be validated against both.

The official references for the machinery: the
[MIDL compiler](https://learn.microsoft.com/en-us/windows/win32/midl/midl-compiler-options) and
[RPC](https://learn.microsoft.com/en-us/windows/win32/rpc/rpc-start-page) sections of Microsoft
Learn.

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
per-project `mof` files. The kernel-side registration entry points are documented at
[WMI library routines](https://learn.microsoft.com/en-us/windows-hardware/drivers/kernel/wmi-library-routines);
the MOF syntax itself at
[Managed object format (MOF) syntax](https://learn.microsoft.com/en-us/windows/win32/wmisdk/mof-syntax).

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
folders, and `tools/postbuildscripts`. INF section syntax is documented at
[INF files](https://learn.microsoft.com/en-us/windows-hardware/drivers/install/inf-files) in the
WDK; SetupAPI's role in consuming them is
[SetupAPI](https://learn.microsoft.com/en-us/windows/win32/setupapi/setupapi-start-page) (the
implementation is `base/pnp/setupapi` — see
[I/O, file systems and storage](/io-storage#plug-and-play-and-setup)).

Version resources are contracts too: each DLL carries an `.rcv` fragment (for example
`shell/explorer/explorer.rcv` next to `explorer.rc`) whose values come from
`public/sdk/inc/ntverp.h` — see [Build, package and release](/build#version-and-build-number-targets).

## COM identity

A COM class that builds but is not registered is not creatable. The registration descriptors live in
`componentdef` directories (65 tracked paths) and `mergedcomponents/uuid/` holds UUID generation for
merged components. `com/ole32` is the runtime — `CoCreateInstance` itself is
[`com/ole32/com/objact/actapi.cxx:89`](https://github.com/havaianasdestruido/neo-nt5/blob/main/com/ole32/com/objact/actapi.cxx):

```c
STDAPI CoCreateInstance(
    REFCLSID rclsid,
    LPUNKNOWN pUnkOuter,
    DWORD dwContext,
    REFIID riid,
    LPVOID * ppv)
```

The official contract:
[CoCreateInstance function (combaseapi.h)](https://learn.microsoft.com/en-us/windows/win32/api/combaseapi/nf-combaseapi-cocreateinstance).
If your change adds a CLSID, an IID or a provider identity, the registration has to land in the
component's `componentdef` or the object will build and still not be creatable.

## References

Official Microsoft documentation for the contract types on this page:

| Topic | Official documentation |
| --- | --- |
| MIDL language reference | [https://learn.microsoft.com/en-us/windows/win32/midl/midl-start-page](https://learn.microsoft.com/en-us/windows/win32/midl/midl-start-page) |
| RPC | [https://learn.microsoft.com/en-us/windows/win32/rpc/rpc-start-page](https://learn.microsoft.com/en-us/windows/win32/rpc/rpc-start-page) |
| MOF syntax | [https://learn.microsoft.com/en-us/windows/win32/wmisdk/mof-syntax](https://learn.microsoft.com/en-us/windows/win32/wmisdk/mof-syntax) |
| WMI kernel library | [https://learn.microsoft.com/en-us/windows-hardware/drivers/kernel/wmi-library-routines](https://learn.microsoft.com/en-us/windows-hardware/drivers/kernel/wmi-library-routines) |
| INF files (WDK) | [https://learn.microsoft.com/en-us/windows-hardware/drivers/install/inf-files](https://learn.microsoft.com/en-us/windows-hardware/drivers/install/inf-files) |
| SetupAPI | [https://learn.microsoft.com/en-us/windows/win32/setupapi/setupapi-start-page](https://learn.microsoft.com/en-us/windows/win32/setupapi/setupapi-start-page) |
| `CoCreateInstance` | [https://learn.microsoft.com/en-us/windows/win32/api/combaseapi/nf-combaseapi-cocreateinstance](https://learn.microsoft.com/en-us/windows/win32/api/combaseapi/nf-combaseapi-cocreateinstance) |
| Header files (SDK/DDK split) | [https://learn.microsoft.com/en-us/windows/win32/apiindex/windows-apis](https://learn.microsoft.com/en-us/windows/win32/apiindex/windows-apis) |

In-tree anchors:

| File | Why |
| --- | --- |
| [`tools/projects.inc`](https://github.com/havaianasdestruido/neo-nt5/blob/main/tools/projects.inc) | Every publication path macro |
| [`com/rpc/locator/idl/nsiclt.idl`](https://github.com/havaianasdestruido/neo-nt5/blob/main/com/rpc/locator/idl/nsiclt.idl) | A real annotated interface |
| [`net/published/inc/afd.w`](https://github.com/havaianasdestruido/neo-nt5/blob/main/net/published/inc/afd.w) | The `.w` convention |
| [`com/ole32/com/objact/actapi.cxx`](https://github.com/havaianasdestruido/neo-nt5/blob/main/com/ole32/com/objact/actapi.cxx) | COM activation |
| [`public/sdk/inc/ntverp.h`](https://github.com/havaianasdestruido/neo-nt5/blob/main/public/sdk/inc/ntverp.h) | Version resource source |

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
and 64-bit. Rebuild both clients and servers, and check the generated headers. The attribute
checklist in the IDL section above is the short version of this answer.

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
