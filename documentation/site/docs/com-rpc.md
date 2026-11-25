---
title: COM, RPC and OLE
sidebar_position: 27
description: The COM object model, class factories and registration, the RPC runtime and NDR engines, MIDL and IDL, structured storage, and where com/ implements each layer.
---

COM and RPC are the two IPC/component systems that make Windows extensible. COM is the object
model (interfaces, class factories, registration, marshalling); RPC is the remote procedure call
substrate underneath it. They share the same wire format (NDR), the same IDL compiler, and in this
tree the same project root: `com/`.

```text
+------------------------------------------------------------------+
| COM           com/ole32/com  (objact, dcomrem, rot, moniker)     |
|               com/ole32/stg  (structured storage)                |
+--------------------------------+---------------------------------+
                                 | ORPC / DCE RPC
+--------------------------------v---------------------------------+
| RPC runtime    com/rpc/runtime/mtrt                              |
| NDR engines    com/rpc/ndr20 (32-bit), com/rpc/ndr64 (64-bit)    |
| MIDL compiler  com/rpc/midl                                      |
| Locator        com/rpc/locator                                   |
+------------------------------------------------------------------+
```

## COM fundamentals

### Interfaces and `IUnknown`

Every COM interface derives from `IUnknown`, which has exactly three methods:

```c
interface IUnknown
{
    HRESULT QueryInterface(REFIID riid, void **ppvObject);
    ULONG   AddRef();
    ULONG   Release();
}
```

| Method | Contract |
| --- | --- |
| `QueryInterface` | Returns a pointer to another interface on the same object, or `E_NOINTERFACE` |
| `AddRef` | Increments the reference count; returns the new count |
| `Release` | Decrements the reference count; destroys the object at zero |

Three rules govern COM identity:

1. **Identity**: `QueryInterface(IID_IUnknown)` on any interface of an object returns the **same**
   pointer. That is the definition of object identity.
2. **Reflexivity**: `QueryInterface` for the interface you already have succeeds.
3. **Transitivity**: if A can query B and B can query C, A can query C.

Reference counting is per object, not per interface in most implementations, but an object may
aggregate or tear off interfaces. `AddRef`/`Release` must be paired; a leaked `Release` is a leak,
an extra `Release` is a use-after-free.

### Class factories and activation

A COM class is identified by a **CLSID** (GUID). A client activates it with `CoCreateInstance`:

```c
HRESULT hr = CoCreateInstance(clsid, NULL, CLSCTX_INPROC_SERVER, IID_IShellLink, (void **)&pLink);
```

`CoCreateInstance` is a convenience wrapper over `CoGetClassObject` + `IClassFactory::CreateInstance`.
The delay-load wrappers are at `com/published/dload/ole32.c:56` (and `CoGetClassObject` at `:727`).

| `CLSCTX` | Meaning |
| --- | --- |
| `CLSCTX_INPROC_SERVER` | In-process DLL |
| `CLSCTX_LOCAL_SERVER` | Out-of-process EXE on the same machine |
| `CLSCTX_REMOTE_SERVER` | Remote machine (requires DCOM) |
| `CLSCTX_INPROC_HANDLER` | In-process handler |
| `CLSCTX_ALL` | Any |

Registration is in the registry:

```text
HKCR\CLSID\{clsid}\InprocServer32     = path, ThreadingModel
HKCR\CLSID\{clsid}\LocalServer32      = command line
HKCR\CLSID\{clsid}\AppID              = AppID GUID
```

A class that builds and is not registered is not creatable. `mergedcomponents/uuid/` holds the
GUID generation for merged components; `com/componentdef` carries registration descriptors (`.sld` files).

### A minimal COM object

```c
#include <unknwn.h>
#include <shlwapi.h>   // not needed; shown for clarity

// A minimal IUnknown implementation.
class CMyObject : public IUnknown
{
    LONG m_cRef;
public:
    CMyObject() : m_cRef(1) {}

    STDMETHODIMP QueryInterface(REFIID riid, void **ppv)
    {
        if (riid == IID_IUnknown) { *ppv = static_cast<IUnknown *>(this); }
        else { *ppv = NULL; return E_NOINTERFACE; }
        AddRef();
        return S_OK;
    }
    STDMETHODIMP_(ULONG) AddRef()  { return (ULONG)InterlockedIncrement(&m_cRef); }
    STDMETHODIMP_(ULONG) Release()
    {
        ULONG c = (ULONG)InterlockedDecrement(&m_cRef);
        if (c == 0) delete this;
        return c;
    }
};
```

The cast in `QueryInterface` matters: `static_cast<IUnknown *>(this)` adjusts the pointer to the
`IUnknown` subobject. Returning `this` directly works only when the object has a single base at
offset zero.

### Marshalling

An interface pointer is valid only in the apartment where it was obtained. To pass it to another
apartment or process, you must marshal it:

| Mechanism | Use |
| --- | --- |
| `CoMarshalInterThreadInterfaceInStream` | Pass an interface to another thread in the same process |
| `CoGetInterfaceAndReleaseStream` | Unmarshal on the receiving thread |
| `CoMarshalInterface` / `CoUnmarshalInterface` | General-purpose stream marshalling |
| Standard marshalling (proxy/stub DLL) | Cross-process, via `CoRegisterClassObject` |
| `GIT` (Global Interface Table) | Long-lived cross-apartment access |

The proxy/stub pair is generated by MIDL from the IDL. A mismatch between the proxy version and the
stub version produces `RPC_E_WRONG_THREAD`, `E_NOINTERFACE` or a crash in NDR.

## RPC fundamentals

### IDL and MIDL

An RPC interface is defined in **IDL** and compiled by MIDL (`com/rpc/midl`) into a header, a
client stub and a server stub. A real example from
[`com/rpc/locator/idl/nsiclt.idl`](https://github.com/havaianasdestruido/neo-nt5/blob/main/com/rpc/locator/idl/nsiclt.idl):

```idl
[
 uuid (d3fbb514-0e3b-11cb-8fad-08002b1d29c3),
 version (1.0),
 pointer_default (unique)]

interface NsiC
{

import "nsicom.idl";

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

Every attribute is a compatibility decision:

| Attribute | Effect |
| --- | --- |
| `uuid` | Identifies the interface on the wire |
| `version` | Gates negotiation; a version mismatch fails the bind |
| `pointer_default(unique)` | Default null-handling for pointers that do not state their own |
| `[in]`, `[out]`, `[in, out]` | Direction of marshalling |
| `[string]`, `[size_is]`, `[length_is]` | Array/string sizing |
| `[context_handle]` | Server-side state carried between calls |
| `[handle]` | Binding handle |

### The RPC runtime

`com/rpc/runtime/mtrt` is the runtime. Its major entry points:

| Function | Purpose | Implementation |
| --- | --- | --- |
| `RpcBindingFromStringBindingW` | Create a binding from a string | `com/rpc/runtime/mtrt/dcethunk.cxx` (ANSI thunk) |
| `RpcStringBindingComposeW` | Build a binding string | `com/rpc/runtime/mtrt` |
| `RpcServerRegisterIf` | Register an interface | `com/rpc/runtime/mtrt/dcesvr.cxx:380` |
| `RpcServerRegisterIfEx` | Register with security callback | `dcesvr.cxx:435` |
| `RpcImpersonateClient` | Impersonate the caller | `dcesvr.cxx:1862` |
| `RpcRevertToSelf` | End impersonation | `dcesvr.cxx:2254` |
| `RpcServerUseProtseqEpW` | Register an endpoint | `com/rpc/runtime/mtrt` |

### NDR20 and NDR64

NDR (Network Data Representation) is the wire format. `com/rpc/ndr20` is the classic 32-bit
engine; `com/rpc/ndr64` is the 64-bit optimised engine. The same IDL can marshal differently on
the two, which is why the tree carries both and why a wire-format change must be tested on both.

The NDR engines implement:

- Type formatting (the `-Lf` type format string).
- Procedure formatting (the `-Fi` proc format string).
- Stubless proxies (interpreted NDR) versus `/Oicf`-compiled stubs.
- `NdrMes` (marshalling engine) for pickling.

### RPC security

| Function | Purpose |
| --- | --- |
| `RpcServerRegisterAuthInfoW` | Register an authentication service with the RPC runtime |
| `RpcServerRegisterIfEx` with a security callback | Per-interface authentication |
| `RpcImpersonateClient` | Impersonate the authenticated caller |
| `RpcRevertToSelf` | Revert |
| `RpcBindingSetAuthInfoExW` | Set authentication on a binding |

An RPC server that calls `RpcImpersonateClient` must always `RpcRevertToSelf` before returning,
including on error paths. A leaked impersonation token is a privilege escalation.

## OLE and structured storage

`com/ole32/stg` is the structured storage engine: compound files (`IFilter`, `IStorage`,
`IStream`), property sets and the persistence model. `com/ole32/com` is the COM implementation:

| Directory | Contents |
| --- | --- |
| `com/ole32/com/objact` | Object activation (`CoCreateInstance` path) |
| `com/ole32/com/dcomrem` | DCOM remoting |
| `com/ole32/com/rot` | Running Object Table |
| `com/ole32/com/moniker`, `moniker2` | Monikers and binding |
| `com/ole32/com/catalog` | Class catalog |
| `com/ole32/com/class` | Class registration |
| `com/ole32/com/util` | Utilities |
| `com/ole32/stg` | Structured storage |

OLE Automation (`IDispatch`, type libraries, variant marshalling, `DispInvoke`) is **not** a
standalone `com/oleaut32` directory in this checkout; `oleaut32.dll` is built under
`enduser/stuff/oleaut32`, with a compatibility copy at `base/win32/fusion/oleaut32`. The
automation *runtime* pieces that live under `com/` are in `com/ole32/com` and `com/ole32/stg`.

## A minimal RPC client/server

Server side, in outline:

```c
// IDL: interface with a [handle] binding, one procedure.
// MIDL generates hello_c.c (client stub), hello_s.c (server stub), hello.h.

#include "hello.h"

int wmain(void)
{
    RPC_STATUS status;
    status = RpcServerUseProtseqEpW((unsigned short *)L"ncacn_ip_tcp", 20,
                                    (unsigned short *)L"8642", NULL);
    if (status != RPC_S_OK) return 1;

    status = RpcServerRegisterIf2(hello_v1_0_s_ifspec, NULL, NULL,
                                  RPC_IF_ALLOW_SECURE_ONLY, 20, 0, NULL, 0);
    if (status != RPC_S_OK) return 1;

    status = RpcServerListen(1, RPC_C_LISTEN_MAX_CALLS_DEFAULT, FALSE);
    return status == RPC_S_OK ? 0 : 1;
}

// The manager routine: this is the actual implementation.
void Hello(handle_t binding, unsigned char *text)
{
    printf("Hello, %s\n", text);
}
```

Client side:

```c
#include "hello.h"

int wmain(void)
{
    RPC_STATUS status;
    unsigned char *binding = NULL;
    RPC_WSTR stringBinding = NULL;

    RpcStringBindingComposeW(NULL, (RPC_WSTR)L"ncacn_ip_tcp",
                             (RPC_WSTR)L"localhost",
                             (RPC_WSTR)L"8642", NULL, &stringBinding);
    RpcBindingFromStringBindingW(stringBinding, &binding);
    RpcStringFreeW(&stringBinding);

    RpcTryExcept {
        Hello(binding, (unsigned char *)"world");
    }
    RpcExcept(1) {
        printf("RPC exception 0x%08lX\n", RpcExceptionCode());
    }
    RpcEndExcept;

    RpcBindingFree(&binding);
    return 0;
}
```

The `RpcTryExcept`/`RpcExcept`/`RpcEndExcept` macros map to SEH; they are the only way to catch
RPC exceptions on the client. The server-side manager routine runs on an RPC thread, not the
client's thread, which is why it must not touch thread-local state.

## Function reference

| Function | Header | Implementation | Documentation |
| --- | --- | --- | --- |
| `CoInitializeEx` | `combaseapi.h` | `com/published/dload/ole32.c:107` | [CoInitializeEx](https://learn.microsoft.com/en-us/windows/win32/api/combaseapi/nf-combaseapi-coinitializeex) |
| `CoCreateInstance` | `combaseapi.h` | `com/published/dload/ole32.c:56` | [CoCreateInstance](https://learn.microsoft.com/en-us/windows/win32/api/combaseapi/nf-combaseapi-cocreateinstance) |
| `CoGetClassObject` | `combaseapi.h` | `com/published/dload/ole32.c:727` | [CoGetClassObject](https://learn.microsoft.com/en-us/windows/win32/api/combaseapi/nf-combaseapi-cogetclassobject) |
| `CoUninitialize` | `combaseapi.h` | `com/published/dload/ole32.c:265` | [CoUninitialize](https://learn.microsoft.com/en-us/windows/win32/api/combaseapi/nf-combaseapi-couninitialize) |
| `RpcServerRegisterIf` | `rpcdce.h` | `com/rpc/runtime/mtrt/dcesvr.cxx:380` | [RpcServerRegisterIf](https://learn.microsoft.com/en-us/windows/win32/api/rpcdce/nf-rpcdce-rpcserverregisterif) |
| `RpcServerRegisterIfEx` | `rpcdce.h` | `com/rpc/runtime/mtrt/dcesvr.cxx:435` | [RpcServerRegisterIfEx](https://learn.microsoft.com/en-us/windows/win32/api/rpcdce/nf-rpcdce-rpcserverregisterifex) |
| `RpcImpersonateClient` | `rpcdce.h` | `com/rpc/runtime/mtrt/dcesvr.cxx:1862` | [RpcImpersonateClient](https://learn.microsoft.com/en-us/windows/win32/api/rpcdce/nf-rpcdce-rpcimpersonateclient) |
| `RpcRevertToSelf` | `rpcdce.h` | `com/rpc/runtime/mtrt/dcesvr.cxx:2254` | [RpcRevertToSelf](https://learn.microsoft.com/en-us/windows/win32/api/rpcdce/nf-rpcdce-rpcreverttoself) |
| `RpcBindingFromStringBindingW` | `rpcdce.h` | `com/rpc/runtime/mtrt/dcethunk.cxx` | [RpcBindingFromStringBindingW](https://learn.microsoft.com/en-us/windows/win32/api/rpcdce/nf-rpcdce-rpcbindingfromstringbindingw) |

## Frequently asked questions

### Q: Where is `CoCreateInstance` actually implemented?

The public export is a delay-load wrapper at `com/published/dload/ole32.c:56`; the real activation
path is `com/ole32/com/objact` (object activation), which consults the class registration and calls
the class factory. `com/ole32/com/dcomrem` handles the out-of-process case.

### Q: Why does `CoCreateInstance` return `REGDB_E_CLASSNOTREG`?

Because the CLSID is not registered, or the registered server is not reachable, or the
`InprocServer32` path is wrong. Check `HKCR\CLSID\{clsid}` and the `AppID` entry. A class that
builds and is not registered is not creatable.

### Q: What is the difference between an in-process and a local server?

An in-process server is a DLL loaded into the client's process (`CLSCTX_INPROC_SERVER`); calls are
direct function calls through the vtable. A local server is an EXE (`CLSCTX_LOCAL_SERVER`); calls
cross a process boundary and go through proxy/stub marshalling. The in-process server is faster and
less isolated; the local server is slower and more robust.

### Q: Why must `QueryInterface(IID_IUnknown)` return the same pointer?

Because COM defines object identity that way. Two interface pointers refer to the same object if
and only if `QueryInterface(IID_IUnknown)` on both returns the same pointer. Breaking this rule
breaks aggregation, `IUnknown`-based identity comparisons and the COM runtime.

### Q: Why does my interface pointer crash in another thread?

Because COM objects have **apartment affinity**. An interface pointer obtained in one apartment is
not valid in another. Marshal it with `CoMarshalInterThreadInterfaceInStream` or use the Global
Interface Table. The proxy/stub pair handles the cross-apartment call.

### Q: What does `[pointer_default(unique)]` mean?

It sets the default pointer attribute for every pointer parameter that does not state its own.
`unique` means the pointer may be `NULL`, and a `NULL` is transmitted as a null flag rather than
dereferenced. `ref` means the pointer must not be null. `ptr` means a full pointer with aliasing.

### Q: Why are there two NDR engines?

Because 32-bit and 64-bit wire formats differ in alignment and pointer size. `ndr20` is the classic
engine; `ndr64` is the optimised 64-bit engine. The same IDL can marshal differently, so a wire
change must be tested on both.

### Q: How do I catch RPC exceptions?

Use `RpcTryExcept` / `RpcExcept(1)` / `RpcEndExcept` on the client. On the server, an exception in
a manager routine is propagated to the client as an RPC exception; the server can also install an
`RpcExceptionFilter` to log it.

### Q: Where is the MIDL compiler?

`com/rpc/midl`. It consumes `.idl` files and emits the header, the client stub, the server stub and
the type format strings. The build order matters: `com/dirs` warns that IDL must be built early
because everything else consumes the generated headers.

### Q: Is COM the same as RPC?

No. COM is an object model with identity, interfaces, class factories and registration; RPC is a
procedure-call substrate. COM uses RPC for cross-process calls (ORPC over DCE RPC), but COM also
works in-process where RPC is not involved.
