---
title: Security and directory services
sidebar_position: 8
description: Access checks in the kernel security reference monitor, tokens and auditing, LSA and authentication protocols, and the Active Directory layers.
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

## Identity: LSA and the authentication protocols

`ds/security/` is the user-mode security project:

| Directory | Role |
| --- | --- |
| *(not in this checkout)* | `lsass.exe` itself is **not** present as a source directory here; only its published IDL is (`ds/published/lsa/lsarpc.idl`, `lsaimp.idl`). Do not cite a `base/lsa` path. |
| `authz`, `azroles` | Authorization manager and role-based access |
| `protocols/kerberos` | Kerberos SSPI provider |
| `protocols/schannel` | TLS/SSL SSPI provider |
| `protocols/digest` | Digest authentication |
| `protocols/msv_sspi` | MSV1_0 (NTLM) SSPI provider |
| `protocols/pwdssp` | Password-change notification providers |
| `protocols/xtcb` | Trusted-computing-base protocol |
| `gina` | The graphical logon interface |
| `cryptoapi`, `csps`, `asn1` | Cryptographic services, providers, ASN.1 |
| `ntmarta` | Multiple-access-provider abstraction for security descriptors |
| `winsafer` | Software restriction policies |
| `dsrole`, `passport`, `services`, `tools` | Domain role, Passport, services, tooling |

The split that matters: **`gina` collects credentials, `lsass` authenticates them, the kernel
enforces the resulting token.** A validation added in the logon UI is not an authorization control.

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

## The security descriptor

A security descriptor is the whole access-control state of an object:

```text
SECURITY_DESCRIPTOR
 +-- Owner SID
 +-- Group SID
 +-- DACL      (discretionary ACL) — who is allowed/denied what
 +-- SACL      (system ACL)        — audit and mandatory label
 +-- Control bits  (SE_DACL_PRESENT, SE_DACL_DEFAULTED, SE_SELF_RELATIVE, ...)
```

An ACE (access-control entry) is one line of an ACL:

| ACE type | Meaning |
| --- | --- |
| `ACCESS_ALLOWED_ACE_TYPE` | Grants a set of access rights to a SID |
| `ACCESS_DENIED_ACE_TYPE` | Denies a set of access rights to a SID |
| `SYSTEM_AUDIT_ACE_TYPE` | Generates an audit record when the SID exercises the rights |
| `SYSTEM_MANDATORY_LABEL_ACE_TYPE` | Sets the integrity level (`LOW`, `MEDIUM`, `HIGH`, `SYSTEM`) |
| `ACCESS_ALLOWED_OBJECT_ACE_TYPE` | Grants rights to a specific property/property set (DS) |
| `ACCESS_ALLOWED_CALLBACK_ACE_TYPE` | Grants rights after calling an authz callback |

The evaluation order is documented and matters: ACEs are walked **in order**, and the first matching
ACE wins. A deny ACE placed after an allow ACE never fires. That is why `SetEntriesInAcl` and the
ACL editors place denies first, and why hand-built ACLs must too.

### The access check

```text
SeAccessCheck
  1. Is the desired access a subset of the token's granted access?   -> yes: grant
  2. Is the caller the owner?                                        -> yes: READ_CONTROL | WRITE_DAC
  3. Walk the DACL in order:
       deny ACE that matches the token's SIDs  -> STATUS_ACCESS_DENIED (unless MAX_ALLOWED)
       allow ACE that matches                    -> accumulate granted rights
  4. If the DACL is absent (NULL DACL)           -> full access to everyone
  5. If the DACL is empty (0 ACEs)               -> no access to anyone
  6. If accumulated rights cover the request     -> STATUS_SUCCESS
  7. Otherwise                                    -> STATUS_ACCESS_DENIED
```

A **NULL DACL** and an **empty DACL** are opposite extremes and are the two most common
security-definition mistakes. A NULL DACL grants everyone everything; an empty DACL denies everyone
everything, including the owner. `InitializeSecurityDescriptor` sets a NULL DACL by default in some
code paths — check `SE_DACL_PRESENT` before trusting a descriptor.

### The token

| Token field | Meaning |
| --- | --- |
| `TokenUser` | The user SID |
| `TokenGroups` | The group SIDs, with attributes (`SE_GROUP_LOGON_ID`, `SE_GROUP_OWNER`, ...) |
| `TokenPrivileges` | The privilege array (`SE_PRIVILEGE_ENABLED`, `SE_PRIVILEGE_ENABLED_BY_DEFAULT`, ...) |
| `TokenOwner` | The default owner for new objects |
| `TokenPrimaryGroup` | The default primary group |
| `TokenDefaultDacl` | The default DACL applied to new objects |
| `TokenSource` | The logon source (`TokenSource` name) |
| `TokenType` | `TokenPrimary` or `TokenImpersonation` |
| `TokenImpersonationLevel` | `SecurityAnonymous`, `SecurityIdentification`, `SecurityImpersonation`, `SecurityDelegation` |
| `TokenElevationType` | `TokenElevationTypeDefault`, `TokenElevationTypeFull`, `TokenElevationTypeLimited` |
| `TokenIntegrityLevel` | The mandatory integrity level |
| `TokenVirtualizationAllowed` | Whether the token is virtualized for legacy apps |

| Impersonation level | What the server can do with the client's token |
| --- | --- |
| `SecurityAnonymous` | Nothing — the server cannot impersonate or identify |
| `SecurityIdentification` | Identify only; cannot open objects as the client |
| `SecurityImpersonation` | Open local objects as the client |
| `SecurityDelegation` | Also pass the token to remote servers |

A local (same-machine) impersonation can reach `SecurityImpersonation`; only `SecurityDelegation`
lets the token leave the machine. That is why an RPC server that calls another server as the client
needs delegation, and why delegation is off by default.

### Privileges

A privilege is the right to perform a system-level act. Important ones:

| Privilege | What it allows |
| --- | --- |
| `SeAssignPrimaryTokenPrivilege` | Assign a primary token to a process |
| `SeBackupPrivilege` | Read any file, bypassing the DACL (`BackupRead`) |
| `SeRestorePrivilege` | Write any file, bypassing the DACL (`BackupWrite`) |
| `SeDebugPrivilege` | Open any process, ignoring the DACL |
| `SeTakeOwnershipPrivilege` | Take ownership of any object |
| `SeTcbPrivilege` | Act as part of the operating system (TCB) |
| `SeLoadDriverPrivilege` | Load and unload drivers |
| `SeShutdownPrivilege` | Shut down the system |
| `SeTimeZonePrivilege` | Change the time zone |
| `SeUndockPrivilege` | Undock the machine |
| `SeManageVolumePrivilege` | Raw volume access (`IOCTL_DISK_READ`) |
| `SeSecurityPrivilege` | Read and change SACLs, read the audit log |
| `SeAuditPrivilege` | Generate audit records |

The pattern for using a privilege:

```c
HANDLE hToken = NULL;
OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken);

TOKEN_PRIVILEGES tp = { 1 };
tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
LookupPrivilegeValueW(NULL, SE_SHUTDOWN_NAME, &tp.Privileges[0].Luid);

AdjustTokenPrivileges(hToken, FALSE, &tp, 0, NULL, NULL);
// ... call the privileged operation ...
AdjustTokenPrivileges(hToken, FALSE, &tp, 0, NULL, NULL);   // or restore the old state
CloseHandle(hToken);
```

`AdjustTokenPrivileges` **enables an already-held privilege**; it does not grant one. A privilege
not present in the token cannot be enabled. That is the difference between "the code runs as admin"
and "the code has the privilege".

## LSA and authentication

| Component | Location | Role |
| --- | --- | --- |
| LSA (LSASS) | `ds/security/protocols/msv_sspi` and the `security` providers | The local security authority: logon sessions, packages, policy. `lsass.exe` itself is not in this checkout as a standalone source directory |
| Authentication packages | `ds/security/protocols/{kerberos,msv_sspi,schannel,digest,pwdssp,xtcb}` | `MSV1_0`, `Kerberos`, `Negotiate`, `Digest` |
| `LSA` client | `base/lsaclient` / `base/win32/client` (advapi32) | The `Lsa*` API |
| GINA | `windows/core/winsrv`, `shell/osshell` | Interactive logon UI |
| Credentials | `ds/win32/credui` | `CredUIPromptForWindowsCredentials` |
| `Secur32.dll` | `base/security` | SSPI: `AcquireCredentialsHandle`, `InitializeSecurityContext` |

The SSPI handshake:

```text
client                              server
  AcquireCredentialsHandle
  InitializeSecurityContext  ----->  AcceptSecurityContext
       ... continues until SEC_E_OK ...
  QueryContextAttributes            QueryContextAttributes
  ApplyControlToken
  DeleteSecurityContext             DeleteSecurityContext
  FreeCredentialsHandle             FreeCredentialsHandle
```

Every SSPI call returns a `SECURITY_STATUS`; `SEC_I_CONTINUE_NEEDED` means "send this token to the
other side and call again". A common bug is treating `SEC_I_CONTINUE_NEEDED` as an error and
aborting the handshake on the first step.

## The directory

| Layer | Location | Role |
| --- | --- | --- |
| Directory Service (NTDS) | `ds/ds/src/ntdsa` | The Active Directory DSA and replication engine |
| Admin tools | `ds/ds/src/ntdsapi`, `ds/win32` | `ntdsutil`, `dcdiag` and the management snap-ins |
| LDAP client | `ds/ds/src/ldap` | `wldap32.dll` — the LDAP API |
| ADSI | `ds/adsi` | ADSI COM providers, including `ds/adsi/ldap` |
| Kerberos | `ds/security/protocols/kerberos` | `kerberos.dll` |
| NTLM | `ds/security/protocols/msv_sspi` | `msv1_0.dll` |
| SChannel | `ds/security/protocols/schannel` | TLS/SSL SSPI package |
| Certificate services | `ds/security/cryptoapi` | `certsrv` and the crypto providers |
| Group Policy | `ds/win32/gpedit`, `ds/ds/src` | GPO client-side extensions |

A directory **distinguished name** (DN) is the canonical address:

```text
CN=Alice,OU=Engineering,DC=corp,DC=example,DC=com
```

| Component | Meaning |
| --- | --- |
| `CN` | Common name |
| `OU` | Organizational unit |
| `DC` | Domain component |
| `O` | Organization |
| `UID` | User ID (X.500) |

An LDAP search has a **base**, a **scope** (`base`, `one`, `sub`) and a **filter**:

```text
ldap_search_s(ld, "DC=corp,DC=example,DC=com", LDAP_SCOPE_SUBTREE,
              "(&(objectClass=user)(sAMAccountName=alice))", attrs, 0, &res);
```

The filter grammar is RFC 1960: `&`, `|`, `!`, `=`, `~=`, `<=`, `>=`, and `*` as a wildcard.
`objectClass=user` is an LDAP filter, not a schema query; the schema itself is at `CN=Schema,CN=Configuration,...`.

## Auditing

An audit record is generated when a SACL ACE matches an access. The system audit policy is in
`HKLM\SECURITY\Policy\PolAdtEv` (via `AuditSetSystemPolicy`). Categories include `AuditCategoryLogon`,
`AuditCategoryObjectAccess`, `AuditCategoryPrivilegeUse`, `AuditCategoryDetailedTracking`,
`AuditCategoryPolicyChange`, `AuditCategoryAccountManagement`, `AuditCategoryDirectoryServiceAccess`,
`AuditCategoryAccountLogon`.

`base/ntos/se/seaudit.c` builds the records (`SeAuditingFileEvents` at 4514, `SeAuditingFileOrGlobalEvents` at 4469); the event log writer is `base/eventlog`. A SACL is only
honoured if the caller has `SE_SECURITY_NAME` when setting it (`SetSecurityInfo` with `SACL_SECURITY_INFORMATION`)
and if the object is opened with `ACCESS_SYSTEM_SECURITY` or the audit policy enables it.

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
