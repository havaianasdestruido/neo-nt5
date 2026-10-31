# NT-family source audit — security bulletin

> **This document does not assign CVEs.** The `NNT-*` identifiers below are local audit IDs, not CVE IDs. The review is partial and source-based; it does not establish a complete audit, a product binary's vulnerability, a zero-day, unauthenticated reachability, or remote code execution.

## Report metadata

| Field | Value |
|---|---|
| Audit date | 2026-10-31 (UTC) |
| Repository snapshot | `havaianasdestruido/neo-nt5`, baseline `04fc55266a9e4cf6259a83864713441eb0016ade` |
| Source context | Older NT-family / NT 5.1-era source; exact shipped build, service pack, QFE, and binary correspondence are **Unknown**. |
| Audit status | **Partial, targeted source audit**; not a certification or complete repository review. |
| Change scope | Documentation only. No production source or test source is changed by this bulletin. |
| Official CVE assignment | None. Historical CVEs below are comparison context only. |
| W rating | **Unresolved** for every item: no W0–W3 rubric was found in repository guidance or the task context, so a scale is not invented. |

## Executive summary

The reviewed source exposes two path-canonicalization boundary defects and two narrower memory-safety issues:

1. **NNT-001 — empty-prefix stack-buffer misuse.** A non-null empty prefix leaves a stack path buffer uninitialized before an unbounded concatenation. The source-level defect is confirmed; the remote worker-thread reuse needed for the demonstrated overflow and the resulting impact on an actual Windows service remain unverified.
2. **NNT-002 — byte-sized RPC output length used for a Unicode store.** The SRVSVC contract expresses the output capacity in bytes, while the Unicode implementation writes a two-byte `TCHAR` terminator for every positive capacity. A source-extracted ASan harness confirms the one-byte allocation case; the generated RPC server stub is absent from this checkout, so its exact allocation and practical server impact are unverified.
3. **NNT-003 — local overflow in the IIS UL `snd` test client.** The test program accepts unbounded input and writes a terminator at index 2048 in a 2048-byte stack buffer. It is not evidence of a defect in the IIS server or a network-triggerable product path.
4. **NNT-004 — optional `SLMDBG` mailslot diagnostic overrun.** A debug-only helper writes one byte beyond a local array and copies an uninitialized adjacent byte into an outgoing datagram. The tracked default server manifest does not define `SLMDBG`; build inclusion and runtime impact are not established.

No official CVE is assigned to any item. In particular, the path-canonicalization findings are **not mapped** to CVE-2006-3439. The old audit leads concerning SMSS, CHAP key clearing, the UL `OVERLAPPED` initializers, licensing insert status, and the WMI assignment condition do not match the current source at the checked locations and are not reported as findings.

## Classification key

**Status** distinguishes evidence from impact. “Confirmed source-level” means the cited source behavior is present; it does not imply a product build or exploit has been validated. “Impact unverified” means the call path, runtime allocation, authentication, or exploit consequence is not proven.

The P-levels are this report's triage priorities, not vendor severity ratings:

- **P0:** confirmed, immediately critical compromise or equivalent impact.
- **P1:** high-risk memory corruption on a remotely callable sensitive service, with significant impact plausible but not demonstrated.
- **P2:** moderate security impact or constrained remote memory/availability issue.
- **P3:** low-impact, local, test-only, optional-debug, or narrowly bounded issue.

No item is P0. `W: Unresolved` means the requested W0–W3 level cannot be assigned without a defined rubric.

## Findings register

| ID | Status | Priority | W | Repository-grounded area | Short description |
|---|---|---:|---|---|---|
| NNT-001 | Confirmed source defect; remote exploitability and impact unverified | P1 | Unresolved | `ds/netapi/netlib/canon.c:165–196`; `ds/netapi/netlib/pathcan.c:109–163`; SRVSVC RPC route | Empty non-null prefix can leave the stack destination uninitialized before `STRCAT`. |
| NNT-002 | Confirmed byte/element-size mismatch; generated-stub allocation and practical impact unverified | P3 | Unresolved | `ds/netapi/netlib/pathcan.c:147–163`; `ds/netapi/svcdlls/srvsvc/idl/srvsvc.idl:905–912`; server `ds/netapi/svcdlls/srvsvc/server/canon.c:64–109` | A one-byte output capacity still receives a two-byte Unicode NUL store. |
| NNT-003 | Confirmed local test-client defect; product-server exposure not established | P3 | Unresolved | `inetsrv/iis/iisrearc/ul/win9x/src/test/cmd/snd/snd.c:34–45,65–70` | Unbounded local input can overflow the `snd` program's stack buffer. |
| NNT-004 | Confirmed in conditional debug code; build and triggerability unverified | P3 | Unresolved | `base/fs/srv/svcsupp.c:1180–1298`; `base/fs/srv/slmcheck.c:274` | Optional SLM diagnostics write beyond a local array and can send an uninitialized byte. |

### NNT-001 — Non-null empty prefix reaches concatenation with an uninitialized stack buffer

- **Status:** Confirmed source-level defect. Remote triggerability, worker-thread stack reuse, and security impact on a Windows product build are unverified.
- **Priority:** P1, based on the possibility of stack corruption in a remotely callable server interface; no code execution is asserted.
- **W:** Unresolved; no W0–W3 rubric was found.
- **Official CVE:** None assigned; this report uses local audit IDs only.
- **CWE:** CWE-457 (use of an uninitialized variable); CWE-121 (potential stack-based buffer overflow).
- **Area:** `ds/netapi/netlib/canon.c:165–196`, reached through `ds/netapi/netlib/pathcan.c:109–163` and `ds/netapi/svcdlls/srvsvc/server/canon.c:64–109`.
- **Affected version/build:** Unknown beyond the audited source snapshot. No corresponding Windows binary was built or tested.
- **Summary and root cause:** `NetpwPathCanonicalize` treats a null or empty prefix as “no prefix” for validation (`ds/netapi/netlib/pathcan.c:111,141–145`) but passes the original prefix onward (`ds/netapi/netlib/pathcan.c:159`). In `CanonicalizePathName`, a *present but empty* prefix enters the `ARGUMENT_PRESENT(PathPrefix)` branch, sets `prefixLen` to zero, and skips the initialization performed only in the absent-prefix branch (`ds/netapi/netlib/canon.c:170–189`). Execution then reaches `STRCAT(pathBuffer, PathName)` (`ds/netapi/netlib/canon.c:191–196`) with `pathBuffer` uninitialized. The later length check accounts for the new path and `prefixLen`, not any stale string already in the destination.
- **Attacker-controlled flow / trust boundary:** The reviewed path is the SRVSVC `NetprPathCanonicalize` RPC method: the IDL declares `PathName`, `Prefix`, `OutbufLen`, and `[in,out] PathType` (`ds/netapi/svcdlls/srvsvc/idl/srvsvc.idl:905–912`); the server routine calls the local canonicalizer (`ds/netapi/svcdlls/srvsvc/server/canon.c:99–108`); the SRVSVC interface is passed to the service's RPC start routine (`ds/netapi/svcdlls/srvsvc/server/srvmain.c:336–339`). A caller able to invoke this method can supply an empty non-null prefix and a path. The service's effective RPC authorization policy and whether a particular deployment allows anonymous calls were **not assessed**; no unauthenticated-access claim is made.
- **Checks and their limitation:** Non-empty prefixes are passed through `NetpwPathType`; an empty prefix bypasses that validation. A zero `PathType` causes `PathName` validation, which limits the examined path to the normal path bound, but does not initialize `pathBuffer` or account for residual contents. The source's array is `MAX_PATH*2+1` `TCHAR` elements; concatenation is unbounded.
- **Impact:** Depending on residual stack contents, the concatenation can scan uninitialized data and append beyond the array, potentially corrupting the service stack or causing a fault. The source does not establish code execution. A prior call on the same RPC worker could plausibly leave controlled text in a reused stack slot, but thread assignment/reuse and a product-level exploit were not tested.
- **Validation:** A temporary ASan harness was built from the extracted `CanonicalizePathName` body with platform shims. With the reused destination containing 519 characters and the next path containing 259 characters, ASan reported a stack-buffer-overflow at the concatenation. The harness preserved the 521-element capacity, but ran on Linux, where `wchar_t` is four bytes; it is **not** a Windows build, RPC reproduction, or exploit demonstration. Temporary harness files were removed.
- **Concurrency / synchronization:** No shared-state race is alleged; `pathBuffer` is local stack storage. The repro's residual-data condition requires reuse of a compatible stack frame, and RPC worker scheduling was not traced to runtime behavior.
- **Historical / novelty check:** Microsoft MS06-040 and NVD describe the historical Server Service RPC issue CVE-2006-3439. That is relevant class context only. No exact source-version or patch correspondence was established, and this finding is **not** assigned CVE-2006-3439. No zero-day or novelty claim is made.
- **Remediation direction:** Initialize the destination for both null and empty prefixes (or normalize empty to absent before the call); calculate the full effective prefix, separator, and path length before writing; use bounded concatenation with explicit capacity checks.
- **Confidence / unknowns:** High confidence in the source defect; remote reachability conditions, same-thread stack reuse, target binaries, authentication, and exploitation impact remain unknown.

### NNT-002 — Byte-sized RPC output capacity is used for a Unicode terminator store

- **Status:** Confirmed source-level unit mismatch. The actual allocation used by the generated server stub and practical memory impact are unverified.
- **Priority:** P3; the reproduced overwrite is one byte beyond a one-byte logical buffer, with no RCE claim.
- **W:** Unresolved; no W0–W3 rubric was found.
- **Official CVE:** None assigned; this report uses local audit IDs only.
- **CWE:** CWE-787 (out-of-bounds write), conditional on the stub allocating only the declared byte count.
- **Area:** `ds/netapi/netlib/pathcan.c:147–163`; `ds/netapi/svcdlls/srvsvc/idl/srvsvc.idl:905–912`; server wrapper `ds/netapi/svcdlls/srvsvc/server/canon.c:64–109`.
- **Affected version/build:** Unknown beyond the audited source snapshot. The netlib and SRVSVC server manifests enable Unicode by default; exact product binaries were not built.
- **Summary and root cause:** The RPC IDL declares `Outbuf` as `[out,size_is(OutbufLen)] LPBYTE` and the API comments define `OutbufLen` in bytes. The server wrapper forwards that length to `NetpwPathCanonicalize`. In the Unicode build, the routine returns for `OutbufLen == 0`, but for every positive value it executes `*Outbuf = TCHAR_EOS` (`ds/netapi/netlib/pathcan.c:153–157`), a two-byte store. Thus a logical one-byte output capacity is not rejected before a two-byte write.
- **Attacker-controlled flow / trust boundary:** `NetpsPathCanonicalize` forwards the caller's byte length through the SRVSVC RPC call (`ds/netapi/svcdlls/srvsvc/client/srvstub.c:3183–3229`); the server wrapper forwards it unchanged to the local routine. A caller that can invoke the method controls `OutbufLen`. Authentication and deployment policy were not assessed.
- **Validation and contract:** The Microsoft [MS-SRVS `NetprPathCanonicalize` specification](https://learn.microsoft.com/en-us/openspecs/windows_protocols/ms-srvs/9281f528-e2e7-4113-abd8-6db7255e4387) also defines the output length in bytes and requires `NERR_BufTooSmall` when output cannot fit. The source checks only for zero before writing; it does not check for at least `sizeof(TCHAR)` bytes.
- **Validation:** A temporary ASan harness used the extracted `NetpwPathCanonicalize` body, a 16-bit `TCHAR` shim, and a one-byte allocation. ASan reported a two-byte heap write past that allocation at output initialization. The harness did not run MIDL/RPC or Windows code. The checked-in `srvsvc_s_stub.c` includes a generated `srvsvc_s.c` file that is not present, so the exact generated stub allocation/alignment behavior was not verified.
- **Impact:** If the runtime buffer is exactly the IDL-declared byte count, the server performs a one-byte logical overrun. Allocation granularity may affect whether this becomes observable heap corruption; no crash, code execution, or stable remote impact was demonstrated.
- **Concurrency / synchronization:** No shared-state or synchronization defect is implicated.
- **Historical / novelty check:** The MS-SRVS requirement is the relevant protocol contract. CVE-2006-3439 is not mapped to this size-unit mismatch; no official CVE or novelty claim is made.
- **Remediation direction:** Reject capacities smaller than `sizeof(TCHAR)` before the first store; keep the byte count and character count conversions explicit at every boundary; test zero-, one-, and odd-byte capacities against the generated RPC stubs.
- **Confidence / unknowns:** High confidence that the implementation's positive-length guard is insufficient for Unicode. The generated stub's actual allocation and resulting runtime impact remain unknown.

### NNT-003 — Local stack overflow in the IIS UL `snd` test client

- **Status:** Confirmed local memory-safety defect in a test utility; not a finding about the IIS server or a remote service.
- **Priority:** P3.
- **W:** Unresolved; no W0–W3 rubric was found.
- **Official CVE:** None assigned; this report uses local audit IDs only.
- **CWE:** CWE-121 (stack-based buffer overflow); CWE-242 (use of the inherently dangerous `gets` function).
- **Area:** `inetsrv/iis/iisrearc/ul/win9x/src/test/cmd/snd/snd.c:26,34–45,65–70`; `inetsrv/iis/iisrearc/ul/win9x/src/test/cmd/cmd.h:31`.
- **Affected version/build:** The source manifest declares `snd` as a console `PROGRAM` under the UL Win9x test tree. Whether it is included in any shipped package is **Unknown**; the parent `test/dirs` manifest does not include `cmd` in its default traversal.
- **Summary and root cause:** `pBuffer` is a 2,048-byte stack array (`inetsrv/iis/iisrearc/ul/win9x/src/test/cmd/cmd.h:31`). `gets(pBuffer)` has no bound; `atoi` is not range checked; the fill loop writes `ulSize` bytes and then writes `pBuffer[ulSize] = '\0'` (`inetsrv/iis/iisrearc/ul/win9x/src/test/cmd/snd/snd.c:65–70`). A size of 2,048 therefore places the terminator one byte past the array, and larger sizes overrun in the loop. The command-line URI copy at `inetsrv/iis/iisrearc/ul/win9x/src/test/cmd/snd/snd.c:43–45` is also unbounded relative to its destination.
- **Attacker-controlled flow / trust boundary:** Input is supplied locally through the program's command line and console. The writes occur before `UlSendMessage`; no inbound network data reaches this overflow in the reviewed path.
- **Checks:** The code exits only for a parsed zero. It has no maximum-size check, robust numeric parse, or bounded line input.
- **Impact:** Local memory corruption or process termination in the test client. Control-flow impact was not demonstrated. This is not evidence of remotely exploitable IIS product code.
- **Validation:** The exact fill-loop and terminator statements were compiled in a temporary host ASan harness with a 2,048-byte buffer and size 2,048; ASan reported a stack-buffer-overflow. The Windows executable and UL driver were not run. Temporary harness files were removed.
- **Concurrency / synchronization:** Not applicable to the local input overflow.
- **Historical / novelty check:** No official CVE was assigned or mapped; public novelty was not assessed. No zero-day claim is made.
- **Remediation direction:** Replace `gets` and `atoi` with bounded input and checked numeric parsing; require `ulSize < sizeof(pBuffer)`; bound-check the URI copy.
- **Confidence / unknowns:** High confidence in the test-client source defect. Distribution and operational exposure are unknown.

### NNT-004 — Optional `SLMDBG` mailslot diagnostic overrun and uninitialized-byte send

- **Status:** Confirmed source-level defect in code guarded by `SLMDBG`; whether that configuration is built or deployed and whether the diagnostic trigger is practically reachable are unverified.
- **Priority:** P3 because it is optional diagnostic code and its runtime impact is unvalidated.
- **W:** Unresolved; no W0–W3 rubric was found.
- **Official CVE:** None assigned; this report uses local audit IDs only.
- **CWE:** CWE-121 (stack-based buffer overflow); CWE-200 (potential disclosure of an uninitialized byte).
- **Area:** `base/fs/srv/svcsupp.c:1180–1298`, `base/fs/srv/slmcheck.c:114–278`, with conditional callers in `base/fs/srv/smbclose.c:228–253` and `base/fs/srv/smbrdwrt.c:4533–4555`.
- **Affected version/build:** Conditional on `SLMDBG`. The tracked `base/fs/srv/sources.inc` does not define `SLMDBG`; inclusion in other build configurations is unknown.
- **Summary and root cause:** `COMPUTER_NAME_LENGTH` is 15 (`base/fs/srv/srvconst.h:28`), so `domainName[COMPUTER_NAME_LENGTH+1]` has 16 elements (`base/fs/srv/svcsupp.c:1205`). For the short constant domain passed by the active diagnostic caller (`base/fs/srv/slmcheck.c:274`), the padding loop fills indices through 14 and leaves index 15 unset; `domainName[++domainLength] = '\0'` then writes at index 16 (`base/fs/srv/svcsupp.c:1213–1230`). The helper sets the outgoing string length to 16, and `SrvSendDatagram` copies up to 16 bytes from that buffer (`base/fs/srv/svcsupp.c:1083–1087`), which includes the uninitialized index-15 byte.
- **Attacker-controlled flow / trust boundary:** The helper is compiled and called only under the `SLMDBG` diagnostic path. `SrvReportSlmStatusOperations` sends the fixed-domain diagnostic after reporting a failed SLM status validation; the reviewed SMB close paths call it only when the client has write access to the relevant file and validation fails. Whether a remote client can reliably reach that specific condition was not tested. The normal server manifest does not enable `SLMDBG`.
- **Impact:** In a build with the conditional code enabled, a one-byte stack write past the array and transmission of one uninitialized stack byte are possible. No kernel crash, information exposure to a real peer, or exploitability was demonstrated.
- **Validation:** Static size/index analysis only; no dynamic test was run for this optional path.
- **Concurrency / synchronization:** No race is alleged; the relevant buffer is local to the diagnostic call.
- **Historical / novelty check:** No exact historical CVE mapping was established. Novelty was not assessed; no official CVE or zero-day claim is made.
- **Remediation direction:** Bound the domain to the NetBIOS field size, place the signature/terminator at a verified in-range index, initialize all bytes that will be transmitted, and add a compile-time test for the `SLMDBG` configuration.
- **Confidence / unknowns:** High confidence in the conditional source-level index error. Build configuration, triggerability, packet behavior, and practical impact remain unknown.

## Reviewed paths with no confirmed finding

These results are limited to the cited paths and do not imply that the entire component is safe.

- **SMB transaction and mailslot receive path:** The transaction parser checks setup/parameter/data offset-plus-count values against the received SMB length and rejects counts larger than totals (`base/fs/srv/smbtrans.c:1690–1727`). Copied input storage rounds data allocation to four-byte alignment (`base/fs/srv/smbtrans.c:2151–2167`). The mailslot dispatcher opens the target with `IO_FORCE_ACCESS_CHECK` and submits `transaction->InData` with `TotalDataCount` (`base/fs/srv/smbtrans.c:3715–3768,3863–3869`). The mailslot filesystem checks writes against `MaximumMessageSize` and uses exclusive FCB access while validating the CCB and updating the data queue (`base/fs/mailslot/write.c:188–228,209–267`). The completion routine closes the handle and dereferences the file object (`base/fs/srv/smbtrans.c:3920–3974`). No confirmed attacker-controlled out-of-bounds write or race was established in this traced path.
- **SMB string scanning:** `END_OF_REQUEST_SMB` denotes the last valid byte (`base/fs/srv/srvmacro.h:394–400`). The ANSI scanner checks through that inclusive endpoint; the Unicode scanner avoids reading a partial final character. The reviewed callers check the `(USHORT)-1` error result before using the lengths, including tree connect, share validation, and SMB user/domain parsing (`base/fs/srv/smbtree.c:116–145,1129–1150`; `base/fs/srv/share.c:92–114`; `base/fs/srv/smbadmin.c:2297–2318,2346–2381`). The Unicode branch of `SrvGetStringLength` is bounded (`base/fs/srv/smbsupp.c:2155–2252`). No finding was established from these call sites.
- **SMB EA paths:** Open2 validates `FEALIST.cbList` against transaction data (`base/fs/srv/smbopen.c:1152–1185`); the conversion path checks each variable-length FEA against the list boundary (`base/fs/srv/ea.c:443–480`). No defect was established there. A separate SD/EA alignment concern is listed below as unresolved.
- **Outbound server announcements:** The SRVSVC scavenger builds and sends announcement packets from server information and configured names (`ds/netapi/svcdlls/srvsvc/server/scavengr.c:666–729,777–905,1056–1211`). No attacker-controlled inbound payload was identified in that outbound path. This is not a complete review of announcement input sources or configuration handling.
- **Local and legacy path wrappers:** The transaction API path in `ds/netapi/xactsrv/apipath.c:297–413` converts lengths, allocates output, calls the local API, and copies the result back; no defect was established in that trace. The `canonapi.c` pointer probe is discussed below and remains a low-confidence local-wrapper candidate.

## Rejected and unresolved candidates

| Lead | Result | Source-grounded reason |
|---|---|---|
| A03/A04 — SMSS branding pointer and unterminated registry string | Rejected for the checked source | `base/subsys/sm/server/sminit.c:1537` initializes `ValueData` to `NULL`; lines 1554–1558 validate `REG_SZ` and terminate the last available `WCHAR`; lines 1565–1571 choose a defined fallback. The old report's quoted source does not match this snapshot. |
| A08 — transposed `memset` for UL `OVERLAPPED` values | Rejected | All seven inspected current initializers pass `(pointer, 0, sizeof(...))`, including `inetsrv/iis/iisrearc/ul/win9x/src/test/cmd/snd/snd.c:50`, `inetsrv/iis/iisrearc/ul/win9x/src/test/cmd/rcv/rcv.c:60`, and the chat client/server sites. The prior zero-byte probe hard-coded the alleged bad argument order and was not evidence of current source. |
| A10 — license insert assignment in condition | Rejected | Current `termsrv/license/tlserver/server/license.cpp:411–414` uses `if (bSuccess == FALSE)`, not assignment. The old extraction assertion searched for the absent assignment. |
| A11 — WMI header-query assignment condition | Old claim rejected; surrounding behavior not fully assessed | Current `admin/wmi/wbem/xmltransport/client/helpersources/httpconnectionagent.cpp:387` uses `if (bResult == FALSE)`. The caller at `admin/wmi/wbem/xmltransport/client/mainsources/xmlwbemclienttransport.cpp:95` initializes the response pointer to `NULL`; broader WMI error handling was not fully audited. |
| A12 — CHAP session-key clear uses pointer size | Rejected | Current `net/rras/ras/ppp/common/clsa.c:690–691` uses `sizeof(*pUserKey)`, clearing the full pointed-to object. |
| Overlong SRVSVC prefix | Rejected on the examined RPC route | For non-empty prefixes, `NetpwPathCanonicalize` calls `NetpwPathType`; that parser rejects names longer than `MAX_PATH-1` (`ds/netapi/netlib/pathcan.c:141–145`; `ds/netapi/netlib/pathtype.c:197–204`). This does not fix the separate empty-prefix defect. |
| `canonapi.c` output-end pointer arithmetic | Not accepted as a security finding; local effect not fully assessed | `ds/netapi/api/canonapi.c:504–508` subtracts `sizeof(*Outbuf)` as an element count even though `OutbufLen` is in bytes. In Unicode this can probe before a very short caller buffer. The probe reads a value and writes the same value inside SEH; no attacker-controlled mutation or privilege boundary was established. No priority is assigned because it is not included as a finding. |
| NT Create-with-SD-or-EA alignment mismatch | Unresolved; not reported as a finding | `base/fs/srv/smbopen.c:2863–2870` aligns the EA pointer from `sdLength` but checks the unaligned sum. Transaction input allocation uses aligned storage in some paths; the exact data-count, descriptor-validity, and padding conditions were not proven to produce an out-of-bounds access. |
| `SrvGetString` terminator handling | Not established as a security defect | The Unicode helper records an explicit `UNICODE_STRING.Length`; the reviewed API-buffer copy path writes its own terminator (`base/fs/srv/svcsupp.c:132–140`). No overread or security impact was shown from the observed length/copy behavior. |

A rejected or unresolved item is not a claim that its entire component has been audited.

## Methodology and validation

- Reviewed current source rather than treating `agents/audit/` reports as authoritative. Followed selected inputs from RPC IDL or SMB dispatch into validation, allocation, copying, status handling, and asynchronous completion.
- Checked source-level trust boundaries, integer/length units, alignment, bounds checks, access checks, thread-local versus shared state, FCB locking, and object lifetime where relevant to the selected paths.
- Compared historical CVE descriptions with the checked source only at the vulnerability-class level. No CVE was assigned without an exact source/version match.
- Used non-destructive host-side ASan harnesses for the extracted path-canonicalization bodies and the `snd` fill loop. The harnesses used platform shims and did not build or run a Windows product binary. The optional `SLMDBG` issue was classified from source arithmetic only.
- No network exploit, live system, VM, production service, database, or credential was used. No weaponized exploit code is included.
- The existing `python3 agents/audit_reproduce.py` did **not** complete: it stopped at line 137 with `ValueError: substring not found` while extracting the stale license-assignment claim. Its partial output is not a passing test suite. In particular, its old `OVERLAPPED` probe is synthetic; current source uses the correct argument order.
- A Windows/Razzle/NMAKE build and a Windows RPC runtime test were unavailable. GCC/ASan results are limited to the isolated host harnesses.

## Historical references and CVE correspondence

- [Microsoft MS-SRVS, `NetprPathCanonicalize`](https://learn.microsoft.com/en-us/openspecs/windows_protocols/ms-srvs/9281f528-e2e7-4113-abd8-6db7255e4387) — byte-sized `OutbufLen`, output array sizing, and the `NERR_BufTooSmall` contract.
- [Microsoft MS06-040](https://learn.microsoft.com/en-us/security-updates/securitybulletins/2006/ms06-040) and [NVD CVE-2006-3439](https://nvd.nist.gov/vuln/detail/CVE-2006-3439) — historical Server Service RPC message-validation/RCE context. No exact correspondence to NNT-001 or NNT-002 is established.
- [Microsoft MS06-035](https://learn.microsoft.com/en-us/security-updates/securitybulletins/2006/ms06-035), [NVD CVE-2006-1314](https://nvd.nist.gov/vuln/detail/CVE-2006-1314), [NVD CVE-2006-1315](https://nvd.nist.gov/vuln/detail/CVE-2006-1315), and [CERT VU#189140](https://www.kb.cert.org/vuls/id/189140) — historical Server Service mailslot/SMB context. No source-to-checkout mapping was established by the reviewed mailslot paths.

These references are historical material, not evidence that this source snapshot is the vulnerable revision or that any NNT finding has a public/official CVE. Novelty and zero-day status are **not determined**.

## Coverage limitations

- This was a targeted audit of selected NetAPI/SRVSVC path canonicalization, selected SMB transaction/EA/string paths, mailslot dispatch and queue handling, outbound announcement helpers, and a few stale audit leads. It was not a systematic review of all repository code or every network parser.
- The generated SRVSVC server stub (`srvsvc_s.c`) is not present; the checked-in `srvsvc_s_stub.c` includes it. Exact MIDL allocation behavior and RPC runtime bounds were therefore not tested.
- Authentication, RPC interface ACLs, service configuration, default deployment exposure, and exact worker-pool scheduling were not traced end-to-end. No anonymous-access claim is made.
- No exact product version or binary was built, booted, or tested. Source applicability to an installed NT-family release or QFE is unknown.
- The SD/EA alignment candidate, the short-buffer `canonapi.c` probe, and broader WMI behavior remain unresolved. Other repository areas—including kernel drivers and network services outside the traced paths—were not comprehensively examined.
- Repository-wide audit tooling has pre-existing failures unrelated to this bulletin (broken links in older audit reports and a missing `agents/components/.jules.md`). Markdown link syntax and all source line ranges in this file were checked separately; this does not imply the repository-wide verifier is clean.
