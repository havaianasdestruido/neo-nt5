# `ds/` — identity, directory, name services and security

This tree spans Active Directory, DNS/name resolution, authentication/policy/crypto, domain/network APIs, and supporting databases. Kernel access enforcement remains in [`base/ntos/se`](../../base/ntos/se); MMC/administration is largely under [`admin/`](admin.md). Build order: [`ds/dirs`](../../ds/dirs). Browse [all nested DS directories](../catalog/ds.md).

| Path (relative to `ds/`) | Responsibility |
| --- | --- |
| [`ds`](../../ds/ds) | Directory service implementation (`src`) and schema. |
| [`security`](../../ds/security) | Logon, LSA, authentication protocols, crypto/PKI, smart cards and policy; see below. |
| [`adsi`](../../ds/adsi) | ADSI interfaces/adapters, LDAP clients, directory access and tests/setup. |
| [`dns`](../../ds/dns) · [`nameres`](../../ds/nameres) | DNS API/resolver/server and name-resolution support. |
| [`netapi`](../../ds/netapi) | Network/domain management APIs, commands, services and RPC translation. |
| [`nlrepl`](../../ds/nlrepl) | Legacy NetLogon replication-related component. |
| [`nw`](../../ds/nw) | NetWare/Novell interoperability and redirector/service support. |
| [`ese98`](../../ds/ese98) · [`edb500`](../../ds/edb500) | ESE/Jet database engine sources and a separate older binary-release area. |
| [`win32`](../../ds/win32) | Security-facing Win32/Advapi, credential UI and crypto components. |
| [`xpress`](../../ds/xpress) · [`safealloca`](../../ds/safealloca) | Compression and allocation helpers. |
| [`inc`](../../ds/inc) · [`published`](../../ds/published) | Internal/shared headers and published LSA/DS/security interfaces. |

## Directory and security layers

* [`ds/ds/src/ntdsa`](../../ds/ds/src/ntdsa) and siblings under [`ds/ds/src`](../../ds/ds/src) contain directory logic, replication/KCC, LDAP, SAM, IDL and tests; [`ds/ds/schema`](../../ds/ds/schema) defines schema material. [`ds/ese98`](../../ds/ese98) is storage infrastructure, not the directory policy layer. [`ds/adsi`](../../ds/adsi) and [`ds/netapi`](../../ds/netapi) are client/API surfaces; [`admin/dcpromo`](../../admin/dcpromo) and snap-ins are management/setup.
* [`ds/security/base/lsa`](../../ds/security/base/lsa) provides LSA clients/server and security services. [`ds/security/gina`](../../ds/security/gina) includes MSGina, user environment, policy and logon/userinit components. [`ds/security/protocols`](../../ds/security/protocols) contains Kerberos, Digest, MSV/SSPI and Schannel-related subtrees. These are not equivalent to kernel [`se`](../../base/ntos/se) checks.
* [`ds/security/cryptoapi`](../../ds/security/cryptoapi) includes cryptographic APIs, certificates/PKI, trust, DPAPI and services; [`csps`](../../ds/security/csps) contains cryptographic service providers, [`authz`](../../ds/security/authz) authorization support, and [`services`](../../ds/security/services) certificate authority, smart-card and time services. Pay attention to key storage, trust, signing and setup boundaries.

## How to change safely

For a logon/policy change, inspect kernel security, LSA/protocols, GINA/userenv, directory APIs, shared headers/IDL, and administration only as applicable. For a directory change, verify schema, LDAP/RPC behavior, ESE storage and replication as well as setup/migration. Follow [the authentication flow](../system-flows.md#5-logon-policy-and-directory-lookup) and [interface review](../interfaces.md#review-checklist-for-interface-changes). Never place copied credentials, test keys or signing material into new docs or artifacts.
