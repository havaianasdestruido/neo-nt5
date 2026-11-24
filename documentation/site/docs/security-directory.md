---
title: Security and directory services
sidebar_position: 8
description: Access checks in the kernel security reference monitor with the official SeAccessCheck contract, tokens and privileges from the advapi32 source, auditing, LSA and authentication protocols, and the Active Directory layers.
---

Security in this tree is split between **enforcement** (the kernel) and **identity** (user-mode
services). A management tool never enforces anything: it edits the data that the kernel enforces
later. Keeping those two apart is the single most important thing on this page.

## Enforcement: the security reference monitor

`base/ntos/se/` is the kernel side. Its files fall into families:

| Family | Files | Role |
| --- | --- | --- |
| Access checking | `accessck.c`, `sep.c`, `semethod.c`, `seassign.c` | The `SeAccessCheck` family and default-SD assignment |
| Tokens | `token.c`, `tokendup.c`, `tokenopn.c`, `tokenqry.c`, `tokenset.c`, `tokenadj.c`, `tokenp.h` | Token creation, duplication, query, adjustment |
| Client context | `seclient.c`, `subject.c`, `tse.c`, `tsecomm.c`, `tseum.c` | Impersonation and security-subject context |
| Auditing | `adtinit.c`, `adtlog.c`, `adtutil.c`, `seaudit.c`, `sepaudit.c`, `rmaudit.c` | Audit policy and event generation |
| Privileges | `privileg.c`, `uipriv.c`, `uipers.c` | Privilege checks and the user-mode privilege APIs |
| Capture / validation | `capture.c`, `ctaccess.c`, `cttoken.c`, `ctseacc.c`, `ctlnpqos.c`, `ctlpcqos.c` | Argument capture from user mode and LPC QoS |
| In-tree tests | `utaccess.c`, `uttoken.c`, `utseacc.c`, `utseqos.c`, `utsertl.c`, `utlpcqos.c`, `utlnpqos.c`, `ttseacc.c`, `ttsertl.c`, `ttokend.c`, `ct*.c` | Unit and component tests |

The central routine is `SepAccessCheck`, at
[`base/ntos/se/accessck.c:1660`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/se/accessck.c):

```c
BOOLEAN
SepAccessCheck (
    IN PSECURITY_DESCRIPTOR SecurityDescriptor,
    IN PSID PrincipalSelfSid,
    IN PTOKEN PrimaryToken,
    IN PTOKEN ClientToken OPTIONAL,
    IN ACCESS_MASK DesiredAccess,
    IN PIOBJECT_TYPE_LIST ObjectTypeList OPTIONAL,
    IN ULONG ObjectTypeListLength,
    IN PGENERIC_MAPPING GenericMapping,
    IN ACCESS_MASK PreviouslyGrantedAccess,
    IN KPROCESSOR_MODE PreviousMode,
    OUT PACCESS_MASK GrantedAccess,
    OUT PPRIVILEGE_SET *Privileges OPTIONAL,
    OUT PNTSTATUS AccessStatus,
    IN BOOLEAN ReturnResultList,
    OUT PBOOLEAN ReturnSomeAccessGranted,
    OUT PBOOLEAN ReturnSomeAccessDenied
    )
```

and its object-tree-aware sibling:

```c
NTSTATUS
SeAccessCheckByType (
    IN PSECURITY_DESCRIPTOR SecurityDescriptor,
    IN PSID PrincipalSelfSid,
    IN HANDLE ClientToken,
    IN ACCESS_MASK DesiredAccess,
    IN POBJECT_TYPE_LIST ObjectTypeList OPTIONAL,
    IN ULONG ObjectTypeListLength,
    ...
    )
```

The exported wrapper is `SeAccessCheck` itself, at
[`base/ntos/se/accessck.c:3447`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/se/accessck.c).
All three of `SepAccessCheck`, `SeAccessCheckByType` and `SeAccessCheck` are explicitly paged, at
`accessck.c` lines 132, 136 and 138:

```c
#pragma alloc_text(PAGE,SepAccessCheck)
#pragma alloc_text(PAGE,SeAccessCheckByType)
#pragma alloc_text(PAGE,SeAccessCheck)
```

Note what the parameters *do not* include: there is no "caller is trusted" shortcut. Everything that
matters — descriptor, tokens, desired access, generic mapping, previously granted access — arrives
as data. That is why a caller that pre-computes `PreviouslyGrantedAccess` incorrectly produces an
access-check bypass rather than an error.

### The official `SeAccessCheck` contract

The WDK documentation for `SeAccessCheck` (wdm.h) states the semantics this implementation must
honour:

> *DesiredAccess* — Specifies the **ACCESS_MASK** bitmask for the access rights that the caller is
> attempting to acquire. If the caller sets the MAXIMUM_ALLOWED bit, the routine performs all DACL
> checks. However, **SeAccessCheck** does not do any privilege checks unless the caller specifically
> requests them by setting the ACCESS_SYSTEM_SECURITY or WRITE_OWNER bits.
>
> *GrantedAccess* — Pointer to a returned access mask indicating the granted access. If the caller
> specifies MAXIMUM_ALLOWED, and the DACL in *SecurityDescriptor* is NULL, then the routine returns
> GENERIC_ALL plus any additional access the caller explicitly requests.
>
> *AccessStatus* — Pointer to the status value indicating why access was denied.
>
> If access is allowed, **SeAccessCheck** returns TRUE.
>
> — [SeAccessCheck function, Microsoft Learn](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-seaccesscheck)
> (documentation source: `MicrosoftDocs/windows-driver-docs-ddi`, `wdk-ddi-src/content/wdm/nf-wdm-seaccesscheck.md`)

Three consequences worth memorising:

1. `MAXIMUM_ALLOWED` in `DesiredAccess` changes what the routine *checks*, not just what it grants.
2. A `NULL` DACL plus `MAXIMUM_ALLOWED` grants `GENERIC_ALL` — the "empty DACL means everyone"
   rule, at the exact spot it is implemented.
3. Privilege-based elevation (`ACCESS_SYSTEM_SECURITY`, `WRITE_OWNER`) is opt-in per call; a caller
   that forgets those bits gets a denial even when the token holds the privilege.

The user-mode mirror of the same check is `AccessCheck` in advapi32 (documented at
[AccessCheck function (winbase.h)](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-accesscheck));
both ultimately exercise the same descriptor semantics.

## Identity: LSA and the authentication protocols

`ds/security/` is the user-mode security project:

| Directory | Role |
| --- | --- |
| `base/lsa` | The Local Security Authority: `client/`, `server/`, `uclient/`, `netclient/`, `crypt/`, `msprivs/`, `security/`, `idl/` |
| `base/audit` | Audit policy storage |
| `protocols/kerberos` | Kerberos SSPI provider |
| `protocols/schannel` | TLS/SSL SSPI provider |
| `protocols/digest` | Digest authentication |
| `protocols/msv_sspi` | MSV1_0 (NTLM) SSPI provider |
| `protocols/pwdssp` | Password-change notification providers |
| `protocols/xtcb` | Trusted-computing-base protocol |
| `gina` | The graphical logon interface |
| `cryptoapi`, `csps`, `asn1` | Cryptographic services, providers, ASN.1 |
| `authz`, `azroles` | Authorization manager and role-based access |
| `ntmarta` | Multiple-access-provider abstraction for security descriptors |
| `winsafer` | Software restriction policies |
| `dsrole`, `passport`, `services`, `tools` | Domain role, Passport, services, tooling |

The split that matters: **`gina` collects credentials, `lsass` authenticates them, the kernel
enforces the resulting token.** A validation added in the logon UI is not an authorization control.

The logon call itself, in this checkout:

```c
// ds/security/base/lsa/client/austub.c:483
LsaLogonUser (
    IN HANDLE LsaHandle,
    IN PSTRING OriginName,
    IN SECURITY_LOGON_TYPE LogonType,
    IN ULONG AuthenticationPackage,
    IN PVOID AuthenticationInformation,
    IN ULONG AuthenticationInformationLength,
    IN PTOKEN_GROUPS LocalGroups OPTIONAL,
    IN PTOKEN_SOURCE SourceContext,
    OUT PVOID *ProfileBuffer,
    OUT PULONG ProfileBufferLength,
    OUT PLUID LogonId,
    OUT PHANDLE Token,
    OUT PQUOTA_LIMITS Quotas,
    OUT PNTSTATUS SubStatus
    )
```

`AuthenticationPackage` selects the provider (MSV1_0, Kerberos, …) and `Token` — the returned
kernel token — is the *only* thing the kernel will later enforce against. The official reference:
[LsaLogonUser function (ntsecapi.h), Microsoft Learn](https://learn.microsoft.com/en-us/windows/win32/api/ntsecapi/nf-ntsecapi-lsalogonuser).

## Tokens and privileges in advapi32

The user-mode token APIs are in `mergedcomponents/advapi32/security.c` in this tree:

```c
// mergedcomponents/advapi32/security.c:556
OpenProcessToken (
    HANDLE ProcessHandle,
    DWORD DesiredAccess,
    PHANDLE TokenHandle
    )
/*++

Routine Description:

    Open a token object associated with a process and return a handle
    that may be used to access that token.
```

| API | Definition here | Official documentation |
| --- | --- | --- |
| `OpenProcessToken` | `mergedcomponents/advapi32/security.c:556` | [nf-processthreadsapi-openprocesstoken](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-openprocesstoken) |
| `AdjustTokenPrivileges` | `mergedcomponents/advapi32/security.c:880` | [nf-winbase-adjusttokenprivileges](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-adjusttokenprivileges) |
| `LookupPrivilegeValueW` | `mergedcomponents/advapi32/security.c:8238` | [nf-winbase-lookupprivilegevaluew](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-lookupprivilegevaluew) |
| `LsaLogonUser` | `ds/security/base/lsa/client/austub.c:483` | [nf-ntsecapi-lsalogonuser](https://learn.microsoft.com/en-us/windows/win32/api/ntsecapi/nf-ntsecapi-lsalogonuser) |

The kernel counterpart that `OpenProcessToken`'s returned handle is checked against is the object
manager's token-type logic in `base/ntos/se/token.c` (`NtOpenProcessToken`, `NtDuplicateToken`,
`NtAdjustPrivilegesToken` are all services in
[`base/ntos/ke/services.tab`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/ke/services.tab)
— the list shows `AdjustPrivilegesToken,6` and `AdjustGroupsToken,6` under their service names).

One trap the official `AdjustTokenPrivileges` documentation repeats and code here confirms: the call
can return success while adjusting **nothing**, unless you check `GetLastError` for
`ERROR_NOT_ALL_ASSIGNED`. A privilege the token does not hold is silently skipped.

## The directory

`ds/` holds Active Directory and its dependencies as separate layers:

| Directory | Layer |
| --- | --- |
| `ds/ds/src/ntdsa` | The directory service agent (NTDSA) — the DS implementation |
| `ds/ds/src/ntdsapi` | The `Ds*` API surface |
| `ds/ds/src/ldap` | LDAP protocol support |
| `ds/ds/src/kcc` | The knowledge consistency checker (replication topology) |
| `ds/ds/src/sam` | Security accounts manager |
| `ds/ds/src/jetback` | The ESE/Jet storage interface |
| `ds/ds/src/ism` | Intersite messaging |
| `ds/ese98`, `ds/edb500` | Extensible Storage Engine — the on-disk database |
| `ds/dns` | DNS server |
| `ds/netapi` | Net* APIs (`ds/netapi`) |
| `ds/adsi` | Active Directory Service Interfaces |
| `ds/nlrepl` | Netlogon replication |

`ds/ds/src/test` and `ds/ds/src/util` exist alongside the implementation, and `admin/dcpromo` plus
`admin/snapin` provide the management UIs. Again: those UIs configure, they do not enforce.

## References

Official Microsoft documentation for the routines on this page:

| Routine / topic | Official documentation |
| --- | --- |
| `SeAccessCheck` (kernel) | [https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-seaccesscheck](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-seaccesscheck) |
| `SeAccessCheckFromState` (kernel) | [https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seaccesscheckfromstate](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seaccesscheckfromstate) |
| `SeAssignSecurity` (kernel) | [https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seassignsecurity](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seassignsecurity) |
| `AccessCheck` (user mode) | [https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-accesscheck](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-accesscheck) |
| `OpenProcessToken` | [https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-openprocesstoken](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-openprocesstoken) |
| `AdjustTokenPrivileges` | [https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-adjusttokenprivileges](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-adjusttokenprivileges) |
| `LookupPrivilegeValue` | [https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-lookupprivilegevalue](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-lookupprivilegevalue) |
| `LsaLogonUser` | [https://learn.microsoft.com/en-us/windows/win32/api/ntsecapi/nf-ntsecapi-lsalogonuser](https://learn.microsoft.com/en-us/windows/win32/api/ntsecapi/nf-ntsecapi-lsalogonuser) |
| `InitializeSecurityDescriptor` | [https://learn.microsoft.com/en-us/windows/win32/api/securitybaseapi/nf-securitybaseapi-initializesecuritydescriptor](https://learn.microsoft.com/en-us/windows/win32/api/securitybaseapi/nf-securitybaseapi-initializesecuritydescriptor) |
| `SetSecurityDescriptorDacl` | [https://learn.microsoft.com/en-us/windows/win32/api/securitybaseapi/nf-securitybaseapi-setsecuritydescriptordacl](https://learn.microsoft.com/en-us/windows/win32/api/securitybaseapi/nf-securitybaseapi-setsecuritydescriptordacl) |
| Access control overview | [https://learn.microsoft.com/en-us/windows/win32/secauthz/access-control](https://learn.microsoft.com/en-us/windows/win32/secauthz/access-control) |
| Privileges (list of constants) | [https://learn.microsoft.com/en-us/windows/win32/secauthz/privilege-constants](https://learn.microsoft.com/en-us/windows/win32/secauthz/privilege-constants) |
| Audit policy | [https://learn.microsoft.com/en-us/windows/win32/secauthz/auditing](https://learn.microsoft.com/en-us/windows/win32/secauthz/auditing) |

In-tree anchors:

| Document / file | Why |
| --- | --- |
| [`base/ntos/se/accessck.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/se/accessck.c) | `SepAccessCheck` (1660), `SeAccessCheck` (3447) |
| [`base/ntos/se/seassign.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/se/seassign.c) | `SeAssignSecurity` (90), `SeAssignSecurityEx` (230) |
| [`base/ntos/se/privileg.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/base/ntos/se/privileg.c) | `SePrivilegeCheck` (161) |
| [`mergedcomponents/advapi32/security.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/mergedcomponents/advapi32/security.c) | The advapi32 token APIs quoted above |
| [`ds/security/base/lsa/client/austub.c`](https://github.com/havaianasdestruido/neo-nt5/blob/main/ds/security/base/lsa/client/austub.c) | `LsaLogonUser` (483) |

## Frequently asked questions

### Q: Where do I fix an "access denied" that should have succeeded?

Establish who computed the denial before changing anything:

```bash
# kernel access check
rg -n 'SepAccessCheck|SeAccessCheckByType' base/ntos/se/accessck.c | head

# default security descriptor assignment for the object type
rg -n 'SeAssignSecurity|SeAssignSecurityEx' base/ntos/se/seassign.c | head

# the object manager's call into it
rg -n 'SeAccessCheck' base/ntos/ob/obse.c base/ntos/ob/obcreate.c | head
```

If the descriptor is wrong, the fix is in the code that *creates* the object; if the token is wrong,
it is in the logon path; if both are right, the check itself is the only remaining suspect — and that
is a much higher bar of evidence.

### Q: Why did `AdjustTokenPrivileges` succeed but nothing changed?

Because the API's success does not mean every privilege was adjusted. The token must already contain
the privilege being enabled; otherwise the call adjusts the rest and returns success with
`GetLastError() == ERROR_NOT_ALL_ASSIGNED`. Always check that code after the call — the tree's own
service code does.

### Q: Does this tree have unit tests for access checking?

Yes, and they are easy to miss because of how they are named. `base/ntos/se/` contains `utaccess.c`,
`utseacc.c`, `utseqos.c`, `utsertl.c`, `uttoken.c`, `utlpcqos.c`, `utlnpqos.c`, `ttseacc.c`,
`ttsertl.c`, `ttokend.c` and a `ct*.c` set. The `ut` / `tt` / `ct` prefixes are the convention; the
*directories* are not named `test`, which has a consequence for the generated index:

```python
# documentation/scripts/generate.py
TEST_PATH = re.compile(r'(^|[/_.-])(tests?|testing|unittests?|testcases?)([/_.-]|$)', re.I)
```

```python
>>> bool(TEST_PATH.search('base/ntos/se/utaccess.c'))
False
```

So the function index will report "No matching call found in test-named files" for kernel security
functions even though `utaccess.c` exercises them. See
[Using the generated function index](/function-index#test-detection-is-path-based).

### Q: How does impersonation affect an access check?

Through the `ClientToken` and `PreviousMode` parameters. When a thread impersonates, `SepAccessCheck`
receives both the primary and the client token and evaluates them together; `base/ntos/se/seclient.c`
and `subject.c` maintain the security-subject context that carries them. A service that forgets to
impersonate before a check evaluates the check against the *service* account, which is the classic
privilege-escalation shape in this codebase. Look at `SeImpersonateClient` callers before assuming a
check was correctly scoped.

### Q: Where are audit events generated?

In the kernel, by the `adt` family: `adtlog.c` writes the event, `seaudit.c` and `sepaudit.c` decide
when to generate one, `adtutil.c` supplies formatting, and `adtinit.c` initialises policy. User-mode
policy storage is `ds/security/base/audit`, and `base/seaudit` provides the user-mode audit API.
Adding an auditable operation means touching the generating call *and* the policy that enables it —
an event with no policy bit is silently never logged.

### Q: Is Kerberos in the kernel?

No. `ds/security/protocols/kerberos` is a user-mode SSPI provider running in `lsass`. The kernel
never negotiates a protocol; it receives a token. That means a Kerberos bug cannot be fixed in
`base/ntos/se`, and a kernel token bug cannot be fixed in the protocol provider.

### Q: What is `ntmarta` for?

`ds/security/ntmarta` is the multiple-access-provider layer: it lets security-descriptor editing APIs
work against NT, LDAP/AD and other providers through one interface. A change to how a descriptor is
read or written in a management tool usually belongs there rather than in the tool.

### Q: Does a directory-schema change need a database change?

Usually both. The schema and the objects live in `ds/ds/src/ntdsa`; the storage engine underneath is
`ds/ese98` (with `ds/edb500` present as the older engine). Durable-format changes cross that boundary,
and they also interact with replication — `ds/ds/src/kcc` computes topology and `ds/nlrepl` handles
netlogon replication. A schema change that is not replication-safe will not fail locally; it will
diverge.

### Q: Can I verify any security change here?

Only by reading and by running the tree's own static checks. This checkout has no test runner and no
target system:

```sh
python3 -m unittest discover -s documentation/tests   # documentation generator tests
python3 agents/verify.py                              # docs links and guide coverage
git diff --check                                      # whitespace defects
```

For a security change, also state explicitly which token shapes, impersonation states and
32/64-bit callers you did **not** exercise. An access-check change that is only reasoned about is not
verified.
