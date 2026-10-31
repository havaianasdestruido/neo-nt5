# Security Audit Bulletin

## Audit Metadata

- **Repository:** `havaianasdestruido/neo-nt5` (NEONT 5 — a re-branded Windows XP / Windows Server 2003 source tree)
- **Audited revision:** `04fc55266a9e4cf6259a83864713441eb0016ade` (branch `main` as merged by PR #27; the audit branch `arena/2fa433b0-neo-nt5` is based on this commit and the working tree was clean at the start of the audit)
- **Declared product version in tree:** `VER_PRODUCTMAJORVERSION` 5, `VER_PRODUCTMINORVERSION` 1, `VER_PRODUCTBUILD` 2600, `VER_PRODUCTBUILD_QFE` 1106 (`public/sdk/inc/ntverp.h:31-32`, `:44-45`) — i.e. NT 5.1 build 2600 at QFE level 1106, consistent with a Windows XP Service Pack 1-era tree. The tree also contains Windows Server 2003-era components (for example `inetsrv/iis/svcs/ftp/server51`, `base/fs/srv/daytonam`), so per-component servicing level cannot be assumed from the global header.
- **Audit date:** 2026-10-31
- **Consolidation provenance:** PR #31 supplies the base report. Source-backed findings, negative results, and methodological improvements from PRs #30 and #32 were reviewed independently and normalized into this single bulletin; duplicated or unsupported claims were not carried forward.
- **Architectures examined:** Findings 004 and 005 are specific to the x86 VDM and trap/BIOS assembly; the non-x86 `NtVdmControl` stub returns `STATUS_NOT_IMPLEMENTED` for these services. The other findings are in portable C unless an entry says otherwise. Host-side runtime models used x86-64 Linux with GCC/ASan, which is not evidence about a shipped Windows architecture or binary.
- **Audit scope:** User-mode RPC servers and shared NetAPI/NetLib code (`ds/netapi/**`), especially `wkssvc.dll` and `srvsvc.dll`; x86 VDM and kernel trap/BIOS paths (`base/ntos/vdm/i386`, `base/ntos/ke/i386`); the SMB server (`base/fs/srv`); Terminal Services channel management (`termsrv/drivers/termdd`); IIS FTP path handling and the UL test utility; MSASN1 BER decoding; ntdll DOS-path conversion; selected kernel I/O-manager and `METHOD_NEITHER` handlers; and previously filed audit notes in `agents/audit/`, re-verified rather than trusted.
- **Validation environment:** Linux x86-64 sandbox with GCC and `-fsanitize=address`; the project cannot be built here because no Windows DDK/build environment, `razzle`/`build.exe`, or Microsoft toolchain is available. Validation used source-extracted functions or explicitly labelled statement models in temporary standalone harnesses. No project source file was modified.
- **Validation caveat:** Harnesses are *extractions or models*, not the compiled product. The Workstation formatting core uses glibc rather than the Windows CRT (`%ws` was translated to `%ls` in the original audit), and stack layout, `/GS`, allocator granularity, RPC stub behaviour, and Windows `wchar_t` semantics differ unless a 16-bit shim is stated. Every finding separates source evidence, host-harness observations, and inferred product impact.
- **Audit limitations:** No Windows build, live instance, RPC/SMB/RDP peer, or large-scale fuzzing was used. Original Microsoft binaries were unavailable, so binary mitigations and exact source-to-product correspondence are not confirmed. The generated SRVSVC server implementation `srvsvc_s.c` and the MCS/T.120 provider needed to prove two input paths are absent from this checkout. Network reachability and historical impact rely on source and cited advisories, not live exploitation. Coverage is targeted, not exhaustive; see *Coverage, Gaps and Residual Risk*. No exploit payload, credentials, or weaponized attack procedure is included.

## Executive Summary

The consolidated audit records **10 findings**: five confirmed at source level, two provisional, and three unverified latent defects. Five entries map directly to published CVEs, one is a distinct handler variant of a published SMB defect class, and four have no established public mapping. **No new zero-day, unauthenticated exploit, or product-level exploit chain is claimed.** Counts below were recalculated from the final entries.

| Status | Count | Identifiers |
| --- | ---: | --- |
| Confirmed (source-level) | 5 | NT-AUDIT-001, -002, -004, -005, -006 |
| Provisional (source defect; reachability or impact incomplete) | 2 | NT-AUDIT-007, -008 |
| Unverified (latent; security boundary or runtime allocation not established) | 3 | NT-AUDIT-003, -009, -010 |
| Rejected / deduplicated candidates | 15 | R-01 … R-15 |
| Additional unresolved leads, not counted as findings | 6 | U-01 … U-06 |

- **By priority:** P0 — 2 (001, 002); P1 — 2 (004, 008); P2 — 3 (005, 006, 007); P3 — 3 (003, 009, 010).
- **By novelty/wildness:** W0 — 5 (001, 002, 004, 005, 007); W1 — 1 (006); W2 — 1 (008); W3 — 0; Unresolved — 3 (003, 009, 010).
- **By primary area:** `rpc` — 2 (001, 009); `networking` — 4 (002, 003, 007, 008); `kernel` — 2 (004, 005); `smb` — 2 (006, 010). Secondary areas are listed per finding.

| ID | Status | Priority | W | Primary area | Short description |
| --- | --- | --- | --- | --- | --- |
| NT-AUDIT-001 | Confirmed | P0 | W0 | `rpc` | Workstation `NetSetup` logging uses unbounded `vsprintf` before validating the RPC alternate name (CVE-2003-0812). |
| NT-AUDIT-002 | Confirmed | P0 | W0 | `networking` | `BackUpPath` can leave `pathBuffer`, followed by an out-of-bounds copy in Server Service path canonicalization (CVE-2008-4250). |
| NT-AUDIT-003 | Unverified | P3 | Unresolved | `networking` | A 520-character prefix can append a separator and NUL past `pathBuffer`; in-tree prefix validation blocks the condition. |
| NT-AUDIT-004 | Confirmed | P1 | W0 | `kernel` | User-writable x86 VDM context reaches the historical `KiTrap0D`/`Ki386BiosCallReturnAddress` stack-pivot mechanism (CVE-2010-0232). |
| NT-AUDIT-005 | Confirmed | P2 | W0 | `kernel` | `VdmpInitialize` exposes physical page zero through a writable user mapping during initialization (CVE-2007-1206). |
| NT-AUDIT-006 | Confirmed | P2 | W1 | `smb` | `SrvSmbWriteRaw` has an ineffective signed/unsigned immediate-data bounds check and passes the unchecked pointer to `FastIoWrite`; distinct from the published `WRITE_ANDX` CVE. |
| NT-AUDIT-007 | Provisional | P2 | W0 | `networking` | Name-keyed `termdd` rebinding matches the historical `MS_T120` channel-lifetime defect; the absent MCS provider prevents an in-tree end-to-end trace (CVE-2019-0708 context). |
| NT-AUDIT-008 | Provisional | P1 | W2 | `networking` | A present-but-empty prefix leaves `pathBuffer` uninitialized before `STRCAT`; residual-stack control and product impact are unproven. |
| NT-AUDIT-009 | Unverified | P3 | Unresolved | `rpc` | Byte-sized SRVSVC output capacity is used for a Unicode terminator store; generated-stub allocation and practical impact are unknown. |
| NT-AUDIT-010 | Unverified | P3 | Unresolved | `smb` | Optional `SLMDBG` diagnostics write one byte past a local domain array and can copy an uninitialized byte; default build inclusion is absent. |

The classic MS06-040 concatenation overflow, upstream-bounded Workstation tree-connect truncation, guarded FTP rename copy, validated SMB transaction/EA/string paths, and stale findings from older audit notes are retained as negative results. The rejection of the *classic* canonicalization overflow is deliberately narrow: NT-AUDIT-002, -003, and -008 are distinct root causes and are not deduplicated into it.

## Classification Legend

**Priority (repository-specific severity and remediation priority; not CVSS)**

| Label | Meaning |
| --- | --- |
| **P0 — Critical** | Demonstrated, broadly reachable vulnerability with catastrophic impact, such as unauthenticated remote compromise of a core security boundary. |
| **P1 — High** | Serious compromise of confidentiality, integrity or availability, including significant privilege escalation or remote code execution under realistic conditions. |
| **P2 — Moderate** | Meaningful but constrained impact: extra privileges, restrictive prerequisites, limited exposure, narrower compromise. |
| **P3 — Low** | Limited-impact defect, defence-in-depth weakness, or a vulnerability with substantial practical constraints. |

**Wildness (repository-specific novelty)**

| Label | Meaning |
| --- | --- |
| **W0 — Known CVE** | The same underlying vulnerability is documented under a verified CVE; the audited code is affected by that same defect. |
| **W1 — Variant** | A distinct manifestation of a known vulnerability class or a closely related documented flaw. |
| **W2 — Potential zero-day** | Source-supported vulnerability for which no matching public disclosure or CVE was found during the audit. Provisional, not proof of undisclosed status. |
| **W3 — Novel vulnerability family** | A well-supported finding that appears to introduce a materially distinct mechanism not matched by the sources investigated. |
| **Unresolved** | Novelty could not be established either way. |

**Validation status**

| Label | Meaning |
| --- | --- |
| **Confirmed / Confirmed (source-level)** | The defect and the cited source path are established by source analysis and, where feasible, extracted validation. The entry separately qualifies historical, conditional, or unmeasured product impact; this label alone never means a live-product exploit was reproduced. |
| **Provisional** | Source evidence indicates a defect, but a material link in the trust-boundary, reachability, object-lifetime, or impact chain is not demonstrated. |
| **Unverified** | A real local or conditional defect exists in the source, but security-relevant reachability, runtime allocation/configuration, or impact across a trust boundary is not established. |
| **Rejected** | Demonstrably unreachable in this revision, adequately mitigated, duplicated, or contradicted by the surrounding code. |

**Areas** used in this bulletin: `rpc`, `networking`, `smb`, `configuration`, `authentication`, `access-control`, `filesystem`, `kernel`, `io-manager`, `compatibility`. Areas are taken from the tree's own component layout (`agents/architecture.md`, `agents/catalog/`), not invented.

## Findings

- **[NT-AUDIT-001] Unbounded `vsprintf` in the NetSetup debug-log path lets a remote RPC caller overflow a stack buffer in the Workstation service**
  - **Status:** Confirmed
  - **Priority:** P0 — the overflow is in a LocalSystem service, is triggerable by data that arrives in an RPC argument before any validation, and the affected service is enabled by default. This is the same defect Microsoft rated Critical in MS03-049.
  - **Wildness:** W0 — CVE-2003-0812 / MS03-049 describes exactly this logging-function overflow in `WKSSVC.DLL`, demonstrated through `NetAddAlternateComputerName`.
  - **Area:** `rpc` (primary); `networking` (secondary)
  - **CVE:** `CVE-2003-0812` (Microsoft Security Bulletin MS03-049, update Q828035 on XP SP1)
  - **Affected revision:** `04fc55266a9e4cf6259a83864713441eb0016ade`. The vulnerable code is present verbatim (`ds/netapi/netlib/debug.c:461-557`, `ds/netapi/svcdlls/wkssvc/server/join.c:1385-1390`). The tree declares NT 5.1 / 2600 / QFE 1106 (`public/sdk/inc/ntverp.h:31-32`, `:44-45`), and the MS03-049 update (which raises `wkssvc.dll` to 5.1.2600.1301 on SP1) is not represented in this source: logging is still performed with `vsprintf` into a fixed buffer.
  - **Affected architectures:** Both x86 and x64. The defect is in portable C and has no architecture-specific guards; the audit's runtime model was x86-64.
  - **Affected configurations:** Any build in which `wkssvc.dll` is loaded in the Workstation service host (`svchost.exe -k netsvcs`, LocalSystem) and the RPC interface `wkssvc` v1.0 (`6BFFD098-A112-3610-9833-46C3F87E345A`) is reachable. `NetSetup.LOG` is opened on the first logged operation without any debug-flag check (`NetSetuppOpenLog` → `NetpOpenDebugFile(L"NetSetup", FALSE)`, `ds/netapi/netlib/joinutl.c:7303-7336`), and `NetpOpenDebugFile` creates `%SystemRoot%\debug` if missing (`ds/netapi/netlib/debug.c:281-460`). No debug flag or registry setting gates the vulnerable formatting path.
  - **CWE:** CWE-121 (Stack-based Buffer Overflow). Rationale: an unbounded, formatted copy writes past a fixed-size stack array. CWE-787 (Out-of-bounds Write) is the applicable parent.
  - **CVSS:** `CVSS:3.1/AV:N/AC:L/PR:N/UI:N/S:U/C:H/I:H/A:H` = **9.8**. Justification: network-reachable RPC endpoint; no privileges required according to the MS03-049 bulletin ("any anonymous user who could deliver a malformed message"); no user interaction; code runs as LocalSystem. Uncertainty: whether a given deployment still permits anonymous access to `\PIPE\wkssvc` depends on policy; the vector assumes the documented default configuration.
  - **Attack vector:** Network (SMB transport, TCP 139/445, to the Workstation service RPC endpoint; MS03-049 explicitly lists blocking TCP/UDP 138/139/445 as the mitigation).
  - **Attacker prerequisites:** Ability to deliver a `wkssvc` RPC request to the target. No local access, no credentials in the configuration described by MS03-049, no user interaction. Environmental precondition: `%SystemRoot%\debug` must be creatable/writable by LocalSystem (the default) so that `hDebugLog != NULL`; if the log cannot be opened, `NetpDebugDumpRoutine` returns early at `ds/netapi/netlib/debug.c:501-504` and no overflow occurs.
  - **Impact:** Confidentiality/integrity/availability of the whole machine: memory corruption in a LocalSystem service allows arbitrary code execution at SYSTEM (as documented for MS03-049) or, at minimum, termination of the service host, taking down every service it hosts.
  - **Summary:** `NetpDebugDumpRoutine` writes a formatted log line into `char OutputBuffer[2049]` using `sprintf`/`vsprintf` and only asserts (`ASSERT`) that the result fits; `ASSERT` is compiled out of free builds. The Workstation service's join/rename code calls `NetpLog` on the client-supplied `AlternateName` immediately after opening the log and *before* `DnsValidateName_W` performs any length/character validation. A long alternate computer name therefore overflows the caller's stack frame with attacker-controlled bytes.
  - **Root cause:** Unbounded formatted output into a fixed-size stack buffer, plus an ordering error in `NetpManageAltComputerName`: an attacker-controlled string is logged before it is validated, and no layer between the RPC stub and the formatter enforces a length limit.
  - **Source evidence:**
    - `ds/netapi/netlib/debug.c:461-557` (`NetpDebugDumpRoutine`):

      ```c
      char OutputBuffer[2049];
      ...
      length += (ULONG) vsprintf(&OutputBuffer[length], Format, arglist);
      BeginningOfLine = (length > 0 && OutputBuffer[length-1] == '\n' );
      if ( BeginningOfLine ) {
          OutputBuffer[length-1] = '\r';
          OutputBuffer[length] = '\n';
          OutputBuffer[length+1] = '\0';
          length++;
      }
      ASSERT( length <= sizeof( OutputBuffer ) / sizeof( CHAR ) );
      ```

      (`char OutputBuffer[2049]` at `:492`; `vsprintf` at `:544`; the post-format `\r\n` writes at `:548-550` are themselves unbounded by up to two bytes even when the formatted text exactly fills the buffer; `ASSERT` at `:554`.)
    - `ds/netapi/svcdlls/wkssvc/server/join.c:1385-1390` (`NetpManageAltComputerName`, function begins at `:1247`):

      ```c
      NetSetuppOpenLog();
      NetpLog(( "NetpManageAltComputerName called:\n" ));
      NetpLog(( " AlternateName = %ws\n", AlternateName ));
      NetpLog(( " DomainAccount = %ws\n", DomainAccount ));
      NetpLog(( " Action = 0x%lx\n", Action ));
      NetpLog(( " Flags = 0x%lx\n", Reserved ));
      ```

      The first validation of `AlternateName` is `DnsValidateName_W( AlternateName, DnsNameHostnameFull )` at `:1427`, i.e. after the four logging calls.
    - `ds/netapi/netlib/joinutl.c:7303-7336` (`NetSetuppOpenLog` opens `NetSetup` unconditionally: `hDebugLog = NetpOpenDebugFile( L"NetSetup", FALSE ); LogFileInitialized = TRUE;`), and `:7406-7440` (`NetpLogPrintHelper` → `NetpLogPrintRoutineVEx`).
    - `ds/netapi/netlib/debug.c:623-665` (`NetpLogPrintRoutineVEx` → `NetpDebugDumpRoutine`).
    - `ds/netapi/svcdlls/wkssvc/idl/wkssvc.idl:578-586` (RPC signature; interface UUID/version at `:37-38`):

      ```c
      NET_API_STATUS
      NetrAddAlternateComputerName(
          [in]                handle_t                  RpcBindingHandle,
          [in,string,unique]  LPTSTR                    ServerName,
          [in,string,unique]  LPTSTR                    AlternateName,
          ...
      ```

    - `ds/netapi/svcdlls/wkssvc/server/join.c:2254` (`NetrAddAlternateComputerName`) forwards to `NetpManageAltComputerName`; `NetrRemoveAlternateComputerName` (`join.c:2321`) uses the same path.
    - Build evidence that the shared logging code is inside `wkssvc.dll`: `ds/netapi/svcdlls/wkssvc/server/sources:35` links `$(SDK_LIB_PATH)\netlib.lib`, and `ds/netapi/netlib/sources:71` (`Debug.c`) and `:86` (`JoinUtl.c`) compile the two files into that library.
  - **Data/control-flow trace:** SMB session to the target → open `\PIPE\wkssvc` → RPC bind to `wkssvc` v1.0 → call `NetrAddAlternateComputerName` with a long `AlternateName` (a `[in,string,unique] LPTSTR`) → generated server stub → `NetrAddAlternateComputerName` (`join.c:2254`) → `NetpManageAltComputerName` (`join.c:1247`) → `NetSetuppOpenLog` (`joinutl.c:7303`) → `NetpLog((" AlternateName = %ws\n", AlternateName))` (`join.c:1387`) → `NetpLogPrintHelper` (`joinutl.c:7406`) → `NetpLogPrintRoutineVEx` (`debug.c:623`) → `NetpDebugDumpRoutine` (`debug.c:461`) → `vsprintf` into `char OutputBuffer[2049]` (`debug.c:544`). Trust boundary: unauthenticated/remote RPC client → LocalSystem service heap/stack. Security-sensitive sink: the stack write; the return address and the `/GS` cookie live above this frame.
  - **Detailed proof:** The destination array is 2049 bytes (`debug.c:492`). Nothing between the RPC unmarshalling and `vsprintf` limits the rendered length: the format string is `" AlternateName = %ws\n"` (`join.c:1387`), the argument is the client's wide string, and the only check is a debug-only `ASSERT` that is not compiled into retail binaries. The overflow occurs before the product-type gate at `join.c:1396-1407`, which rejects the request on non-server SKUs only *after* the `NetpLog` calls at `join.c:1386-1390`; Windows XP Professional workstations are therefore affected as well, even though the API ultimately returns `ERROR_NOT_SUPPORTED` there. The routine first adds a timestamp (about 18 bytes at `:521-529`) and possibly a thread-id prologue (`:536`), then appends the fully expanded argument (`:544`). When the expanded line exceeds the remaining space, `vsprintf` writes past `OutputBuffer`; the subsequent `OutputBuffer[length-1] = '\r'`, `OutputBuffer[length] = '\n'`, `OutputBuffer[length+1] = '\0'` writes (`:548-550`) extend the out-of-bounds range by up to two bytes even in the borderline case where the text exactly fills the array. The violated invariant is "formatted output length < sizeof(OutputBuffer)". Validation with the extracted formatting core shows a 3000-character alternate name produces an ASan `stack-buffer-overflow` with a 3019-byte write, while a 2000-character name renders in 2036 bytes and does not overflow — consistent with the analytic threshold (2049 − timestamp − prefix).
  - **Preconditions:** (1) Workstation service reachable and running; (2) `%SystemRoot%\debug` writable by LocalSystem so the log opens; (3) `AlternateName` supplied with several thousand characters (MIDL `[string]` parameters carry far more than 2049 bytes; 3000 wide characters is 6000 bytes of wire data); (4) call `NetrAddAlternateComputerName` or `NetrRemoveAlternateComputerName`.
  - **Validation:** Executed in the sandbox with the production statement sequence extracted into `/home/user/audit-work/log_harness.c` (buffer size, `sprintf` prologue and `vsprintf` call preserved; `%ws` mapped to `%ls` for GCC/libc semantics). Commands and observed output:

    ```text
    $ gcc -g -O0 -fsanitize=address -o log_harness log_harness.c
    $ ./log_harness 2000
    alternate name chars=2000
    (only a LeakSanitizer report for the harness' own name buffer; no overflow)
    $ ./log_harness 3000
    ==ERROR: AddressSanitizer: stack-buffer-overflow ... WRITE of size 3019
    ```

    This reproduces the `vsprintf` overflow deterministically against a 2049-byte stack array. It does not reproduce the RPC transport or the service context.
  - **Reproduction procedure:** *Validated (source + harness).* For a full end-to-end check, use an isolated, disposable Windows XP SP1 VM with no network access other than a host-only segment: call the `wkssvc` interface (`6BFFD098-A112-3610-9833-46C3F87E345A` v1.0) `NetrAddAlternateComputerName` with `AlternateName` set to 3000 `A` characters (benign filler), then observe that the Workstation service host terminates and that a WER/Dr. Watson entry points into `wkssvc!NetpDebugDumpRoutine`/`netlib` formatting code. Do not use this against systems you do not own. *Proposed test, not run here.*
  - **Exploitability assessment:** A remote attacker can overwrite the stack frame of a LocalSystem service with attacker-chosen bytes. MS03-049 was exploited in the wild and Microsoft rated it Critical, so code execution is established historically; this audit did **not** attempt to build an exploit, bypass `/GS`, or defeat DEP. What remains unproven here is the exact stack layout and `/GS` behaviour of the specific shipped binary, which cannot be tested without the original toolchain and artifacts. One encoding caveat limits the payload alphabet: `%ws` renders a UTF-16 string through wide-to-narrow conversion, so the line ends at the first `0x0000` code unit. Printable ASCII filler (code units `0x00xx`) renders one byte per character and overflows exactly as modelled, but arbitrary byte values cannot be placed in the frame, which is a further reason this bulletin demonstrates the corruption and the crash, not a working exploit.
  - **Existing mitigations:** (a) `/GS` stack cookies in the shipped `wkssvc.dll` (a corruption of the cookie turns the overflow into a controlled process termination); (b) `NetpDebugDumpRoutine` returns early if the log handle is NULL (`debug.c:501-504`), so a host where `%SystemRoot%\debug` cannot be opened is not affected; (c) firewalls/port filtering can block the SMB transport to the RPC endpoint; (d) disabling the Workstation service removes the endpoint.
  - **Why mitigations are insufficient:** `/GS` does not prevent the out-of-bounds write and was demonstrably insufficient for the real MS03-049 exploits; the log directory is created automatically when missing (`debug.c:345-360`), so the NULL-handle early return is not the default; ICF is not enabled by default on the affected XP SP1 configuration, so port filtering is not a default mitigation; and disabling the Workstation service breaks NetBIOS name resolution and network logon for most deployments.
  - **Historical references:** Microsoft Security Bulletin MS03-049 "Buffer Overrun in the Workstation Service Could Allow Code Execution (828749)", 11 November 2003; CVE-2003-0812; CERT/CC CA-2003-28; eEye advisory AD20031111; NVD entry for CVE-2003-0812; the `wkssvc.dll` file-version checks in the corresponding OVAL definitions (5.1.2600.1301 for XP SP1).
  - **Novelty rationale:** W0. The defect, the affected function (Workstation service logging to `NetSetup.LOG`), and the demonstrated API (`NetAddAlternateComputerName`) match CVE-2003-0812 exactly. The audited revision is an affected configuration, and the fix is absent from the source. This is a known vulnerability that is still present in the audited code, not a novel discovery.
  - **Confidence:** High. The unbounded write is demonstrated by executed validation and the reachability chain is fully present in the source; only the shipped-binary layout (and therefore exploit reliability) is untested.
  - **Remediation direction:** Replace `sprintf`/`vsprintf` with bounded formatting (`_vsnprintf`/`StringCchVPrintfA`) against `sizeof(OutputBuffer)`, handle truncation explicitly, and make the `\r\n` fix-up conditional on remaining space. Independently, validate `AlternateName` (length and character set) before any logging, and centralise log-line construction so one defect cannot recur in the NetLogon, SAM and Browser log copies of this pattern.
  - **Regression tests:** (1) Unit test of the extracted `NetpDebugDumpRoutine` with inputs at 2040, 2048, 2049, 2050 and 4096 bytes under ASan, asserting no access outside the array and well-defined truncation. (2) A property test that the post-format `\r\n` fix-up never writes at index `>= sizeof(OutputBuffer)`. (3) An RPC-level fuzz test that sends `NetrAddAlternateComputerName` with 1–70000 character names and asserts the service stays alive and logs a truncated line.
  - **References:**
    - `https://github.com/havaianasdestruido/neo-nt5/blob/04fc55266a9e4cf6259a83864713441eb0016ade/ds/netapi/netlib/debug.c#L461-L557`
    - `https://github.com/havaianasdestruido/neo-nt5/blob/04fc55266a9e4cf6259a83864713441eb0016ade/ds/netapi/netlib/joinutl.c#L7303-L7440`
    - `https://github.com/havaianasdestruido/neo-nt5/blob/04fc55266a9e4cf6259a83864713441eb0016ade/ds/netapi/svcdlls/wkssvc/server/join.c#L1385-L1390`
    - `https://github.com/havaianasdestruido/neo-nt5/blob/04fc55266a9e4cf6259a83864713441eb0016ade/ds/netapi/svcdlls/wkssvc/idl/wkssvc.idl#L578-L586`
    - `https://learn.microsoft.com/en-us/security-updates/securitybulletins/2003/ms03-049`
    - `https://nvd.nist.gov/vuln/detail/CVE-2003-0812`
    - `https://www.kb.cert.org/vuls/id/567620`

- **[NT-AUDIT-002] `ConvertPathMacros`/`BackUpPath` scan backwards past `pathBuffer` and then copy attacker data to the out-of-bounds address (netapi32 path canonicalization)**
  - **Status:** Confirmed
  - **Priority:** P0 — remote, reachable before authentication in the configurations documented for MS08-067, in the Server service (LocalSystem) which is enabled by default; impact is memory corruption with a demonstrated out-of-bounds write of attacker-controlled content.
  - **Wildness:** W0 — CVE-2008-4250 / MS08-067 is the same defect: `netapi32!NetpwPathCanonicalize` → `CanonicalizePathName` → the legacy-folder removal loop (`ConvertPathMacros`, called `RemoveLegacyFolder` in shipping symbols), with the backwards search for `0x5C` running outside the buffer.
  - **Area:** `networking` (primary); `smb`, `rpc` (secondary)
  - **CVE:** `CVE-2008-4250` (Microsoft Security Bulletin MS08-067)
  - **Affected revision:** `04fc55266a9e4cf6259a83864713441eb0016ade`. `ds/netapi/netlib/canon.c` is the pre-fix revision: `BackUpPath` (`:531-560`) still uses the pointer-equality bound and `ConvertPathMacros` still copies with `STRCPY` (`:503`) to the pointer the scan returned. The netlib code is compiled into both `netapi32.dll`-side consumers and the `srvsvc.dll` service (`ds/netapi/svcdlls/srvsvc/server/sources:36` links `netlib.lib`).
  - **Affected architectures:** Both x86 and x64. The arithmetic is pointer-width independent, but the failure mode differs: on x64 the scan may hit a guard page sooner. Public in-the-wild exploitation (Conficker) targeted x86 XP/2003.
  - **Affected configurations:** `srvsvc` RPC interface v3.0 (`4B324FC8-1670-01D3-1278-5A47BF6EE188`, `ds/netapi/svcdlls/srvsvc/idl/srvsvc.idl:55-56`) exposed by the Server service in a LocalSystem service host, with SMB reachable (TCP 139/445). The vulnerable path is a *server-side* canonicalization call, so it also runs in any other binary that links `netlib.lib` and exposes a canonicalization RPC (for example `wkssvc!NetrUseAdd` through `WsUseCheckRemote`, `ds/netapi/svcdlls/wkssvc/server/useutil.c:1716-1724` — although that path constrains the input to a UNC name beginning with `\\`, which as explained under *Existing mitigations* does not reach the same out-of-bounds condition).
  - **CWE:** CWE-124 (Buffer Underwrite) for the write that lands before the array, with CWE-125 (Out-of-bounds Read) for the unbounded backward scan; CWE-787 is the applicable parent. Rationale: the defect is a lower-bound error in pointer arithmetic that permits access below the start of a stack buffer.
  - **CVSS:** `CVSS:3.1/AV:N/AC:L/PR:N/UI:N/S:U/C:H/I:H/A:H` = **9.8** for the documented unauthenticated configuration. Uncertainty: reliable code execution depends on stack grooming (the copy destination is derived from whatever `0x5C` the scan finds), and `/GS` must be defeated; the vector reflects impact if those are achieved, as they were in 2008. If a deployment requires credentials for the `srvsvc` endpoint, the applicable vector would be `PR:L` (8.8).
  - **Attack vector:** Network (SMB to `\PIPE\srvsvc`, RPC opnum for `NetprPathCanonicalize`).
  - **Attacker prerequisites:** Ability to bind the `srvsvc` interface and call `NetprPathCanonicalize` over the SMB named-pipe transport. No local access and no user interaction. Credentials: MS08-067 was exploited without valid credentials (Conficker); the source-level requirement is only that the RPC request reaches the server. Environmental precondition: Server service running and sharing ports reachable.
  - **Impact:** Out-of-bounds read of stack memory and, with a neighbouring `0x5C` word, an out-of-bounds write of attacker-supplied bytes below `pathBuffer` — stack corruption in a LocalSystem service. Minimum impact is a reliable remote crash (the documented WER signature is a stack overflow, `0xC00000FD`, in `netapi32!ConvertPathMacros`); maximum is remote code execution, as exploited in the wild in 2008.
  - **Summary:** `ConvertPathMacros` removes `.`/`..` path components in place. When a `..` component is reduced to the start of the buffer, it calls `BackUpPath(Path, ptr - 1)` with `ptr == Path`, i.e. a start pointer one element *before* the buffer. `BackUpPath` dereferences first and compares pointers afterwards (`*Path != '\\' && Path != Stopper`), and because the caller passes a pointer below `Stopper`, the equality test never fires; the routine keeps reading downwards until it happens to find a `0x5C`. The returned pointer is stored in `previousLastSlash`, and the next `..` component causes `STRCPY(previousLastSlash, ptr + 2)` — an unbounded copy of path bytes to an address outside the buffer.
  - **Root cause:** An unbounded backwards search whose loop condition tests the lower bound incorrectly (pointer equality after dereference instead of `Path > Stopper`), combined with the assumption that `previousLastSlash` always points inside the buffer. `ConvertPathMacros` then uses that value as the destination of an unchecked `wcscpy`/`strcpy`.
  - **Source evidence:**
    - `ds/netapi/netlib/canon.c:486-522` (`ConvertPathMacros` main loop), key excerpt:

      ```c
      while ((ch = *ptr) != TCHAR_EOS) {
          if (ch == TCHAR_BACKSLASH) {
              ...
              previousLastSlash = lastSlash;
              lastSlash = ptr;
          } else if ((ch == TCHAR_DOT) && ((lastSlash == ptr - 1) || (ptr == Path))) {
              TCHAR nextCh = *(ptr + 1);
              if (nextCh == TCHAR_DOT) {
                  TCHAR nextCh = *(ptr + 2);
                  if ((nextCh == TCHAR_BACKSLASH) || (nextCh == TCHAR_EOS)) {
                      if (!previousLastSlash) {
                          return FALSE;
                      }
                      STRCPY(previousLastSlash, ptr + 2);      /* :503 */
                      ...
                      ptr = lastSlash = previousLastSlash;     /* :507 */
                      previousLastSlash = BackUpPath(Path, ptr - 1); /* :508 */
                  }
              }
      ```

    - `ds/netapi/netlib/canon.c:555-560` (`BackUpPath`):

      ```c
      {
          while ((*Path != TCHAR_BACKSLASH) && (Path != Stopper)) {
              --Path;
          }
          return (*Path == TCHAR_BACKSLASH) ? Path : NULL;
      }
      ```

    - `ds/netapi/netlib/canon.c:166` the destination stack array `TCHAR pathBuffer[MAX_PATH*2 + 1];`, and `:199-203` the call into `ConvertPathMacros`.
    - `ds/netapi/netlib/pathcan.c:126-138`: the *only* structural validation of the path is skipped when the caller supplies a non-zero `PathType`:

      ```c
      typeOfPath = *PathType;
      ...
      if (!typeOfPath) {
          if (rc = NetpwPathType(PathName, &typeOfPath, 0)) {
              return rc;
          }
      }
      ```

      `PathType` is `[in,out] LPDWORD` on the wire (`ds/netapi/svcdlls/srvsvc/idl/srvsvc.idl:911`), so the remote caller decides whether this check runs. The prefix is always validated (`pathcan.c:141-146`), but the path itself is not.
    - `ds/netapi/netlib/pathcan.c:159`: `rc = CanonicalizePathName(Prefix, PathName, Outbuf, OutbufLen, NULL);`
    - `ds/netapi/svcdlls/srvsvc/server/canon.c:64-109`: the RPC server routine `NetprPathCanonicalize` forwards directly to `NetpwPathCanonicalize` (`:102`), with no additional checks. The RPC signature is `ds/netapi/svcdlls/srvsvc/idl/srvsvc.idl:904-913`.
  - **Data/control-flow trace:** SMB session to `\PIPE\srvsvc` → RPC bind to `srvsvc` v3.0 → `NetprPathCanonicalize` (IDL `:904`) → `canon.c:65` → `NetpwPathCanonicalize` (`pathcan.c:58`) → `PathType` taken from the request, so `NetpwPathType` may be skipped (`pathcan.c:130-136`) → `CanonicalizePathName` (`canon.c:86`) → `ConvertPathCharacters` turns `/` into `\` (`canon.c:197`, `:217-248`) → `ConvertDeviceName` returns FALSE for the crafted input (`canon.c:199`) → `ConvertPathMacros` (`canon.c:200`) → `BackUpPath(Path, ptr - 1)` (`canon.c:508`) reads below `pathBuffer` → `STRCPY(previousLastSlash, ptr + 2)` (`canon.c:503`) writes to the out-of-bounds address. Trust boundary: remote RPC client → LocalSystem service stack. Sink: `wcscpy`/`strcpy` with a destination derived from the out-of-bounds scan.
  - **Detailed proof:** For the input `\c\..\..\AAAA` (wire form `\c\..\..\AAAA`, or `/c/../../AAAA` before `ConvertPathCharacters`), the loop records `lastSlash = pathBuffer + 2`, `previousLastSlash = pathBuffer + 0` at the first `..` and performs `STRCPY(pathBuffer, ptr + 2)`, rewriting the buffer to `\..\AAAA`. It then sets `ptr = lastSlash = previousLastSlash` (index 0) and calls `BackUpPath(Path, ptr - 1)` with `ptr - 1 == pathBuffer - 1`. `BackUpPath` dereferences `pathBuffer[-1]`; since it is not `\`, and `Path != Stopper` compares a below-buffer pointer with the buffer start, the loop continues to `pathBuffer[-2]`, `[-3]`, … until a `0x5C` occurs. The returned pointer is outside the array; the following code treats it as a legitimate slash. When the scan lands on attacker-influenced stack content containing a slash followed by the bytes that make the next `..` component, `STRCPY` writes the remaining path (attacker-controlled, NUL-terminated) at that out-of-bounds address. The violated invariants are: (i) `BackUpPath` must never dereference below `Stopper`; (ii) `previousLastSlash` must always be a pointer into `pathBuffer`. The public in-the-wild crash signature (`netapi32!ConvertPathMacros+0x101: cmp word ptr [eax],5Ch`, exception `0xC00000FD`) is exactly this loop reading outside the buffer until it hits the guard page.
  - **Preconditions:** (1) The crafted path reaches `ConvertPathMacros`: it must start with a single separator (a double separator makes it take the UNC branch and moves `Path` forward, which removes the below-buffer condition — see *Existing mitigations*), contain at least one component, then a `..` component; (2) `PathType` in the RPC request is non-zero, or `NetpwPathType` accepts the path (the former is attacker-controlled and removes the dependency); (3) `OutbufLen` non-zero (the RPC stub allocates whatever the client asks for; the overflow happens before the output-size check); (4) the Server service is running and its RPC endpoint is reachable.
  - **Validation:** Two executed harnesses in `/home/user/audit-work`, built from the verbatim production functions (only `TCHAR`/macro definitions and Win32 primitives replaced), no project source modified:
    1. `canon_stack.c` — `pathBuffer` is a real `TCHAR[521]` stack array; `./canon_stack '\a\..\x'` produces

       ```text
       ==ERROR: AddressSanitizer: stack-buffer-underflow ... READ of size 4
           #0 BackUpPath canon_stack.c:19
           #1 ConvertPathMacros canon_stack.c:46
       ```

    2. `canon_groomed.c` — the 521-element array lives at offset 1024 of a 2048-element block whose pre-buffer region models groomable stack words; a single `0x5C` is placed six elements before the array. Running the documented path shape `\c\..\..\AAAA` gives:

       ```text
       result=1 output=[\..\AAAA]
       modified pre-buffer slots: [-6]='\' [-5]='A' [-4]='A' [-3]='A' [-2]='A' [-1]=NUL
       pre-buffer slots modified: count=6 firstOffset=-1
       ```

       i.e. six wide characters containing attacker-chosen path bytes were written *before* the array. This is a non-weaponised demonstration of the write primitive; no control-flow hijack was attempted.
    3. Control observations: an input without a leading single separator, or without a second `..`, exits without touching memory before the array (`canon_asan` with `\a\..\x` reports the underflow at `[-1]`; inputs such as `a\b\..\x` return normally because the scan stops at index 0 in-bounds).
  - **Reproduction procedure:** *Validated at function level; end-to-end test proposed, not executed.* In an isolated, non-networked lab with a disposable VM: send an `srvsvc` `NetprPathCanonicalize` request with `PathName = "/c/../../AAAA…"` (filler only), `Prefix = NULL`, `PathType = 1`, and observe that the service host crashes with `0xC00000FD` in `ConvertPathMacros`. Do not run this against systems you do not own.
  - **Exploitability assessment:** Demonstrated: an out-of-bounds backward read and an out-of-bounds write of attacker-controlled data whose target depends on neighbouring stack contents. Public exploitation in 2008 (Conficker) achieved remote code execution with SYSTEM privileges on XP/2003, including a stack-grooming stage and an egg-hunt payload that survived the constrained space; that work is historical and is **not** reproduced or extended here. What remains unproven in this audit is the exact target-dependent offset and the `/GS` interaction.
  - **Existing mitigations:** (a) `NetpwPathType` rejects paths longer than `MAX_PATH - 1` (`ds/netapi/netlib/pathtype.c:202`) and performs syntax validation — but it is skipped whenever the client supplies a non-zero `PathType` (`pathcan.c:130-136`), so it is not a barrier for a malicious caller; (b) the UNC branch of `ConvertPathMacros` (`canon.c:466-478`) advances `Path` past `\\server\`, so the `Stopper` used for the backwards scan is inside the buffer rather than at its start — this removes the below-buffer condition for names that must be UNC, which is why the `wkssvc` `NetUseAdd` route (`useutil.c:1716-1724`) does not reach it; (c) `/GS`, DEP and ASLR (the last only on x64 XP/2003) raise exploitation cost; (d) blocking 139/445 or disabling File and Printer Sharing removes reachability.
  - **Why mitigations are insufficient:** The decisive validation is under attacker control (`PathType`), so the parser's length and syntax checks cannot be relied on; `/GS` was demonstrably bypassable for this exact bug class (the 2008 in-the-wild exploit used a stack-pivot/egg-hunt technique); XP SP1 is 32-bit and has no ASLR, so a stack address is predictable enough for the documented exploitation; and the minimum guaranteed outcome — a remote crash of the Server service — is itself a denial of service that the mitigations do not prevent.
  - **Historical references:** Microsoft Security Bulletin MS08-067 "Vulnerability in Server Service Could Allow Remote Code Execution (958644)", 23 October 2008; CVE-2008-4250; MS06-040 (CVE-2006-3439), the earlier overflow in the same canonicalization code; Microsoft's post-mortem describing the `netapi32!ConvertPathMacros+0x101` stack overflow; public analyses of `NetpwPathCanonicalize` → `CanonicalizePathName` → `RemoveLegacyFolder`.
  - **Novelty rationale:** W0. The mechanism (backwards slash scan leaving the buffer, in the legacy-folder removal code of `netapi32`), the affected call chain and the reachability (srvsvc RPC over SMB) match CVE-2008-4250. The source is the pre-fix version, so the defect is present. Nothing in this finding is claimed as new.
  - **Confidence:** High for the defect, the reachability chain and the memory-safety consequence (executed validation + complete in-tree call chain). Medium for any statement about the exact shipped binary's stack layout, which was not tested.
  - **Remediation direction:** Rewrite `BackUpPath` with an explicit lower bound (`Path > Stopper`, or an index-based loop over a known length), never pass `ptr - 1`, and make `ConvertPathMacros` validate that every pointer used as a `STRCPY` destination lies within `[Path, Path + length]`. Replace `STRCPY` with a bounded copy whose size is computed from the remaining buffer, re-validate the canonical result (reject residual `..` components), and treat `PathType` as an output-only value on the server side instead of trusting the client's value to skip validation.
  - **Regression tests:** (1) A property/fuzz test over path strings (separators, `.`, `..`, mixed, with/without leading separator, up to `MAX_PATH*2`) that asserts every pointer passed to a copy is inside the array and that no access occurs outside it. (2) An ASan/Valgrind build of `CanonicalizePathName` executed against a corpus of crafted paths, with zero sanitizer findings. (3) A test that client-supplied `PathType` cannot suppress validation of `PathName`. (4) A test that canonicalisation never returns a path containing a `..` component when it reports success.
  - **References:**
    - `https://github.com/havaianasdestruido/neo-nt5/blob/04fc55266a9e4cf6259a83864713441eb0016ade/ds/netapi/netlib/canon.c#L486-L560`
    - `https://github.com/havaianasdestruido/neo-nt5/blob/04fc55266a9e4cf6259a83864713441eb0016ade/ds/netapi/netlib/pathcan.c#L126-L160`
    - `https://github.com/havaianasdestruido/neo-nt5/blob/04fc55266a9e4cf6259a83864713441eb0016ade/ds/netapi/svcdlls/srvsvc/server/canon.c#L64-L109`
    - `https://github.com/havaianasdestruido/neo-nt5/blob/04fc55266a9e4cf6259a83864713441eb0016ade/ds/netapi/svcdlls/srvsvc/idl/srvsvc.idl#L904-L913`
    - `https://learn.microsoft.com/en-us/security-updates/securitybulletins/2008/ms08-067`
    - `https://nvd.nist.gov/vuln/detail/CVE-2008-4250`

- **[NT-AUDIT-003] Prefix-length check in `CanonicalizePathName` allows a two-byte stack write past `pathBuffer` (latent; not reachable from in-tree callers)**
  - **Status:** Unverified
  - **Priority:** P3 — the code is genuinely wrong, but the only in-tree caller cannot supply the required prefix length, so no trust boundary is crossed in this revision. Reported because a future or out-of-tree caller that skips `NetpwPathType` would turn it into a stack overflow.
  - **Wildness:** Unresolved — it is a bounds defect in the same canonicalisation code as CVE-2006-3439 (MS06-040), but that CVE describes an unchecked `wcscat` of the concatenated path; the audited code already contains the fix's length checks, and no public record of this specific off-by-one was found. Novelty therefore cannot be established either as a variant or as an independent defect.
  - **Area:** `networking` (primary); `smb`, `rpc` (secondary)
  - **CVE:** Unassigned
  - **Affected revision:** `04fc55266a9e4cf6259a83864713441eb0016ade`; `ds/netapi/netlib/canon.c:166-194`.
  - **Affected architectures:** Both x86 and x64 (portable C).
  - **Affected configurations:** Any code that calls the exported `CanonicalizePathName` (netapi32 private export, `ds/netapi/api/netapi32.prf:57`) with a 520-character prefix that does not end in a path separator, *without* first passing the prefix through `NetpwPathType`. No such caller exists in this tree.
  - **CWE:** CWE-193 (Off-by-one Error) leading to CWE-121 (Stack-based Buffer Overflow); CWE-787 parent.
  - **CVSS:** Not assessed — reachability across a trust boundary is not established.
  - **Attack vector:** Not established (would require a caller that bypasses prefix validation).
  - **Attacker prerequisites:** Not established. Locally, any process can call the exported function with any arguments, but that only corrupts its own address space and crosses no privilege boundary.
  - **Impact:** If reachable from a service, a two-byte stack write of `\0` two elements past a 521-element array, with crash potential and a possible `/GS` abort; no code-execution primitive was demonstrated.
  - **Summary:** `CanonicalizePathName` reserves `TCHAR pathBuffer[MAX_PATH*2 + 1]` (521 elements), then permits `prefixLen == MAX_PATH*2` (`prefixLen > MAX_PATH*2` is false for 520). It copies the prefix (520 characters plus NUL) and, when the last character is not a separator, appends `\` with `STRCAT` before the later `pathLen + prefixLen > MAX_PATH*2 - 1` check runs. The append writes the separator at index 520 (in bounds) and its NUL at index 521 (out of bounds).
  - **Root cause:** The prefix bound `prefixLen > MAX_PATH*2` does not account for the separator that may be appended afterwards, and the concatenation happens before the combined-length check. The correct precondition is `prefixLen + 1 (separator) + 1 (NUL) <= MAX_PATH*2 + 1`.
  - **Source evidence:** `ds/netapi/netlib/canon.c:166-194`:

    ```c
    TCHAR   pathBuffer[MAX_PATH*2 + 1];
    ...
    if (prefixLen) {
        // Make sure we don't overrun our buffer
        if (prefixLen > MAX_PATH*2 ) {              /* :174  allows 520 */
            return ERROR_INVALID_NAME;
        }
        STRCPY(pathBuffer, PathPrefix);             /* :177 */
        if (!IS_PATH_SEPARATOR(pathBuffer[prefixLen - 1])) {
            STRCAT(pathBuffer, TEXT("\\"));         /* :179  writes index 520 and NUL at 521 */
            ++prefixLen;
        }
        ...
    }
    pathLen = STRLEN(PathName);
    if (pathLen + prefixLen > MAX_PATH*2 - 1) {     /* :192  too late */
        return ERROR_INVALID_NAME;
    }
    ```

  - **Data/control-flow trace:** `NetpwPathCanonicalize` validates a non-empty prefix with `NetpwPathType` (`ds/netapi/netlib/pathcan.c:141-146`), and `NetpwPathType` rejects any string longer than `MAX_PATH - 1` (`ds/netapi/netlib/pathtype.c:202`). Therefore a 520-character prefix never reaches `CanonicalizePathName` through this caller, and the defect is unreachable in this revision. Only a direct call to `CanonicalizePathName` (exported at `netapi32.prf:57`) that skips `NetpwPathType` would reach it.
  - **Detailed proof:** The array has 521 elements and the `STRCAT` at `:179` writes at `pathBuffer[520]` and `pathBuffer[521]`; index 521 is one element past the end. Executed validation with the extracted function (exact buffer size, `ConvertPathCharacters`/`ConvertDeviceName`/`ConvertPathMacros` stubbed) confirms the write: a 520-character prefix without a trailing separator produces `AddressSanitizer: stack-buffer-overflow ... WRITE` at the `STRCAT` line, with the faulting address "located in stack of thread T0 at offset 2132" in the `CanonicalizePathName` frame; a 520-character prefix ending in `\` and a 519-character prefix are clean (control runs). The violated invariant is "the total written length, including any appended separator and the terminator, must not exceed `sizeof(pathBuffer)/sizeof(TCHAR)`". Because the only way to trigger it in-tree is a call that bypasses validation, the security consequence is **not** established and the finding is deliberately not marked Confirmed.
  - **Preconditions:** A caller passes `PathPrefix` with exactly 520 characters and a non-separator last character, without `NetpwPathType` validation, in a security-relevant process.
  - **Validation:** `/home/user/audit-work/canon_prefix.c` (extracted statements, ASan). Observed: 519 characters → no overflow (only a harness-memory leak report); 520 characters, no trailing separator → `stack-buffer-overflow` WRITE at the `wcscat` call; the harness was also run with 520 characters ending in `\` (clean). This validates the code behaviour and the arithmetic; it does **not** validate reachability.
  - **Reproduction procedure:** *Proposed test.* Compile the extracted function with ASan and call it with a 520-character prefix lacking a trailing separator; observe the overflow. For a reachability test, instrument `CanonicalizePathName` in a Windows build and confirm that no reachable caller supplies `prefixLen > MAX_PATH - 1`; if one is found, reclassify as Confirmed and reassess priority.
  - **Exploitability assessment:** No attacker path was found in this revision. If a future caller (in-tree or third-party) invokes the private export without validation, a two-byte out-of-bounds write becomes possible from whatever context that caller runs in; code execution would be unlikely but a crash or `/GS` abort is plausible.
  - **Existing mitigations:** `NetpwPathType`'s `MAX_PATH - 1` limit on the prefix (`pathtype.c:202`), reached from `pathcan.c:141-146`, prevents the condition for every in-tree caller; the array is large enough for all legal prefixes.
  - **Why mitigations are insufficient:** Not established as a security issue; the check at `canon.c:174` is nevertheless incorrect on its own terms and would silently permit the overflow if the caller-side validation were relaxed or bypassed.
  - **Historical references:** MS06-040 / CVE-2006-3439 (unchecked canonicalisation concatenation in the same function); public analyses stating that `NetpwPathCanonicalize` performs length checks before `CanonicalizePathName` in patched builds.
  - **Novelty rationale:** Unresolved. No matching CVE or advisory was found; the defect is a bound error adjacent to a historically vulnerable code path, but reachability could not be shown, so neither W0–W3 nor a zero-day claim is justified.
  - **Confidence:** High that the code overflows for `prefixLen == 520` without a trailing separator (executed); high that in-tree callers cannot reach it (call-graph and validation analysis); the security impact is therefore low confidence and deliberately unclaimed.
  - **Remediation direction:** Change the guard to require room for the separator and terminator before any copy (for example `prefixLen + 2 > sizeof(pathBuffer)/sizeof(pathBuffer[0])`), perform all length checks before the first write, and convert the concatenations to bounded copies.
  - **Regression tests:** (1) ASan unit test at prefix lengths 518, 519, 520 with and without a trailing separator, asserting no access outside `pathBuffer`. (2) A test asserting that `CanonicalizePathName` returns `ERROR_INVALID_NAME` for `prefixLen == 520` instead of writing. (3) A call-graph check that every caller passes the prefix through `NetpwPathType`.
  - **References:**
    - `https://github.com/havaianasdestruido/neo-nt5/blob/04fc55266a9e4cf6259a83864713441eb0016ade/ds/netapi/netlib/canon.c#L166-L194`
    - `https://github.com/havaianasdestruido/neo-nt5/blob/04fc55266a9e4cf6259a83864713441eb0016ade/ds/netapi/netlib/pathtype.c#L202`
    - `https://github.com/havaianasdestruido/neo-nt5/blob/04fc55266a9e4cf6259a83864713441eb0016ade/ds/netapi/netlib/pathcan.c#L141-L146`
    - `https://learn.microsoft.com/en-us/security-updates/securitybulletins/2006/ms06-040`
    - `https://nvd.nist.gov/vuln/detail/CVE-2006-3439`

- **[NT-AUDIT-004] User-writable x86 VDM context reaches the historical `KiTrap0D` / `Ki386BiosCallReturnAddress` kernel stack-pivot mechanism**
  - **Status:** Confirmed (source-level). The complete mechanism is present in the audited C and assembly; no product execution was performed.
  - **Priority:** P1 — local privilege escalation to kernel context is the documented impact of this historical mechanism. This is not a remote finding.
  - **Wildness:** W0 — the `VDM_TIB` forgery, magic `CS:EIP` check, and stack restoration mechanism directly match **CVE-2010-0232 / MS10-015**. It is not reported as a new variant merely because this old source lacks later gating.
  - **Area:** `kernel` (primary); `compatibility` (secondary, x86 VDM).
  - **CVE:** `CVE-2010-0232` (historical mapping; no new identifier assigned).
  - **Affected revision / architecture:** `04fc55266a9e4cf6259a83864713441eb0016ade`, x86 only. The non-x86 implementation in `base/ntos/vdm/vdm.c:45-83` returns `STATUS_NOT_IMPLEMENTED` for `VdmStartExecution`.
  - **CWE:** CWE-345 (Insufficient Verification of Data Authenticity). The kernel recognizes an internal transition using attacker-reproducible frame values.
  - **CVSS:** Not reassessed for this source snapshot; no product binary or exploit was run.
  - **Attack vector and prerequisites:** A local attacker on an x86 build with VDM support, executing in a process context that can supply the VDM TIB and associated VDM state. Public analysis of CVE-2010-0232 describes using an NTVDM process to satisfy the process-context requirements. The source exempts `VdmStartExecution` from the `VdmObjects` gate (`vdmentry.c:145-158`) and contains no literal `VdmAllowed` reference, but those observations alone do **not** prove that every arbitrary process can complete the chain.
  - **Summary:** `NtVdmControl(VdmStartExecution)` reaches `VdmpStartExecution`, which copies the user-writable `VdmTib->VdmContext` into a local context and then the thread trap frame. The only content gate before the swap is `SegCs & FRAME_EDITED`. `VdmSwapContexts` copies `CS`, `EIP`, `ESI`, and the other context fields, applying only RPL/flag sanitization. A resulting faulting `iret` is specially recognized by `KiTrap0D` when its target matches the kernel's own BIOS-return `CS:EIP` pair; control then reaches `Ki386BiosCallReturnAddress`, which restores `ESP` from `TsEsi` and returns through that restored stack.
  - **Root cause:** A user-writable context is treated as an authentic kernel-produced V86/BIOS transition. The trap handler validates constants that can be reproduced in that context but does not authenticate the saved stack pointer or establish that the frame came from `Ki386SetUpAndExitToV86Code`.
  - **Source evidence:** `base/ntos/vdm/i386/vdmentry.c:107-169` (service gate and dispatch); `vdmtib.c:29-72` (`TEB->Vdm`, `ProbeForWrite`, and size check); `strtexec.c:39-215` (context copy at 178, mask at 180-188, swap at 194-196); `vdmmisc.asm:185-235` (context loads, `or ax,3`, and EFlags sanitization); `base/ntos/inc/i386.h:1552-1556` (`FRAME_EDITED 0xfff8`); `base/ntos/ke/i386/trap.asm:4702-4731` (faulting-`iret` and magic target checks); `base/ntos/ke/i386/biosa.asm:220-286` (stack restoration at 241-255 and final pops/return at 282-286). The comments at `trap.asm:4713-4719` explicitly say that `ESI` *should* be the saved stack pointer, but the following code checks only `EIP` and `CS`.
  - **Data/control-flow trace:** Local VDM-capable process → `NtVdmControl` → `VdmpStartExecution` → `VdmpGetVdmTib` / user-writable `VDM_TIB` → `VdmSwapContexts` → trap exit and general-protection fault → `KiTrap0D` special case → `Ki386BiosCallReturnAddress` → kernel stack restoration using `TsEsi`. The security consequence is kernel stack control; reliable token manipulation or a working exploit was not attempted.
  - **Validation:** The complete source chain was re-read at the cited revision. A temporary consolidation predicate check confirmed that the historical selector shape passes `SegCs & FRAME_EDITED` and retains the expected RPL bits after `or ax,3`. This validates only the masks. No CPU fault semantics, kernel trap-frame layout, Windows binary, or exploit was executed.
  - **Historical references and novelty:** Microsoft MS10-015, NVD CVE-2010-0232, and Tavis Ormandy's original `KiTrap0D` analysis describe this same VDM/BIOS-call validation defect. The source-level match justifies W0. The absence of a later `VdmAllowed` gate is an observation about this snapshot, not evidence of a separate CVE.
  - **Confidence:** High for presence of the source mechanism and its historical relationship; no independent dynamic confirmation of product exploitability.
  - **Remediation direction:** Require an authenticated VDM process context for the service; reject ring-0 or otherwise invalid selectors in user-writable contexts; validate the saved stack pointer and expected BIOS-call state instead of relying only on reproducible `CS:EIP` constants; apply the corresponding historical security update when servicing a real product.
  - **Limitations:** No exact SKU/build integration, CPU-level `#GP` behaviour, or shipped-binary comparison was tested. Detailed exploit construction is intentionally outside this bulletin.

- **[NT-AUDIT-005] `VdmpInitialize` maps physical page zero writable in the caller's user address space**
  - **Status:** Confirmed (source-level). The mapping permissions and copy are explicit; the race and downstream escalation chain were not reproduced.
  - **Priority:** P2 — a local race with substantial preconditions; historical analyses describe privilege escalation, but this audit confirms the source preconditions rather than a working chain.
  - **Wildness:** W0 — direct match to **CVE-2007-1206 / MS07-022**, the Windows VDM zero-page race.
  - **Area:** `kernel` (primary); `compatibility` (secondary, x86 VDM).
  - **CVE:** `CVE-2007-1206` (historical mapping).
  - **Affected revision / architecture:** `04fc55266a9e4cf6259a83864713441eb0016ade`, x86 VDM only.
  - **CWE:** CWE-732 (Incorrect Permission Assignment for Critical Resource) and CWE-362 (Concurrent Execution using Shared Resource with Improper Synchronization).
  - **Attack vector and prerequisites:** Local, on an x86 VDM-capable process. A concurrent thread must locate and write the temporary mapping before it is unmapped. `VdmInitialize` is exempt from the `VdmObjects` gate, while `VdmpInitialize` rejects a process whose `VdmObjects` is already initialized (`vdminit.c:66-75`).
  - **Summary and root cause:** `VdmpInitialize` opens `\Device\PhysicalMemory` with `SECTION_ALL_ACCESS`, maps its first page into `NtCurrentProcess()` with `PAGE_READWRITE`, copies the page to virtual address zero, and then unmaps the source view. A read-only initialization operation therefore exposes a writable physical-memory view to other threads in the calling process for a race window.
  - **Source evidence:** `base/ntos/vdm/i386/vdmentry.c:145-169` (entry and initialization dispatch); `base/ntos/vdm/i386/vdminit.c:77-87` (section open), `:100-115` (`BaseAddress = 0`, `destination = 0`, `ViewSize = 0x1000`, and `PAGE_READWRITE` mapping), `:124-131` (copy to VA 0 and unmap).
  - **Impact:** Modification of physical page-zero contents during the window and control over data copied into the VDM's initial IVT/BIOS area. Public CVE-2007-1206 analysis describes how trusted consumers of that data can turn this into local privilege escalation. This audit did not inspect or reproduce the hibernation/bug-check follow-on chain and does not claim a new exploit.
  - **Validation:** Static source inspection only for this finding. The mapping mode and destination are unambiguous; no race, VDM, or Windows memory manager was run.
  - **Historical references and novelty:** Microsoft MS07-022 and the eEye/Derek Soeder zero-page advisory document the same `VdmpInitialize` mapping and race. W0; no novelty is claimed.
  - **Confidence:** High for the source defect and historical mapping; medium for practical impact in any particular build.
  - **Remediation direction:** Map the source page read-only, preferably copy it through a kernel buffer rather than a user mapping, construct the VDM's initial page without copying to attacker-influenced VA 0, and apply the historical update to real deployments.

- **[NT-AUDIT-006] `SrvSmbWriteRaw` accepts an out-of-range immediate-data offset and passes the resulting pointer to `FastIoWrite`**
  - **Status:** Confirmed (source-level). The invalid comparison and its immediate-data consumer are present; practical disclosure yield was not measured.
  - **Priority:** P2 — an authenticated remote kernel out-of-bounds read can become file-backed information disclosure under the stated preconditions. No code execution is claimed.
  - **Wildness:** W1 — a distinct `WRITE_RAW` handler manifestation of the SMB `DataOffset` validation class. **CVE-2008-4114 / MS09-001 concerns `WRITE_ANDX`; this entry does not assign that CVE to `WRITE_RAW`.**
  - **Area:** `smb` (primary); `networking`, `kernel` (secondary).
  - **CVE:** Unassigned for this handler variant. CVE-2008-4114 is prior-art context only.
  - **Affected revision:** `04fc55266a9e4cf6259a83864713441eb0016ade`.
  - **CWE:** CWE-125 (Out-of-bounds Read), enabled by improper signed/unsigned length validation.
  - **Attack vector and prerequisites:** A remote SMB client with a session/tree connection and a writable FID; nonzero immediate data; raw mode enabled on the server/connection; and a file system fast-I/O path that consumes the immediate buffer. For a pipe, the immediate count must equal the total count (`smbraw.c:1239-1242`). Authentication may be a low-privilege or guest session where the server permits it; no unauthenticated claim is made.
  - **Summary:** `immediateLength` and `writeLength` are `ULONG`, while `BUFFER.DataLength` is `CLONG` (`base/fs/srv/srvblock.h:1916-1923`). The second guard subtracts the unsigned 16-bit `DataOffset` from the signed received length and then compares the signed result with `immediateLength`. If `DataOffset` exceeds the received length, the subtraction is negative and the usual arithmetic conversions turn it into a very large unsigned value, so the rejection is bypassed.

    ```c
    if ( ( immediateLength > writeLength ) ||
         ( immediateLength > ( WorkContext->ResponseBuffer->DataLength -
                                    SmbGetUshort(&request->DataOffset) ) ) ) {
        status = STATUS_INVALID_SMB;
    }
    ```

    `SrvSmbWriteRaw` later computes `writeAddress = (PCHAR)WorkContext->RequestHeader + DataOffset` and supplies it as the source buffer to `lfcb->FastIoWrite` (`base/fs/srv/smbraw.c:1239-1261`).
  - **Source evidence:** `base/fs/srv/smbraw.c:882-974` (handler and guard), `:1032-1106` (word count and write-access checks), `:1239-1283` (immediate fast write); `public/internal/base/inc/smb.h:3121-3141` (`Count`, `DataLength`, and `DataOffset` are 16-bit fields and the offset is from the SMB header); `base/fs/srv/network.c:1897-1915` (normal request/response aliasing and header setup); `base/fs/srv/smbproc.c:394-400` (received length recorded in `RequestBuffer`); `base/fs/srv/smbsupp.c:6097-6110` and `srvdata.c:663-667` (generic validation does not check this offset); `base/fs/srv/smbtrans.c:1690-1728` (a sibling transaction validator that does check offset plus count).
  - **Data/control-flow trace:** SMB `WRITE_RAW` request → generic SMB validation → `SrvSmbWriteRaw` length guard → writable-FID verification → `writeAddress = RequestHeader + DataOffset` → `FastIoWrite(..., immediateLength, ..., writeAddress, ...)`. If the file can be read back by the client, bytes beyond the received SMB can be disclosed through the file. Pool adjacency and the bytes actually returned were not measured.
  - **Scope correction / limitations:** The later `PrepareMdlWrite` / `SrvBuildReadOrWriteRequest` sequence at `smbraw.c:1434-1545` prepares the **remaining raw write**; it is not evidence that the same immediate `writeAddress` gets a second MDL consumer. This finding therefore relies only on the demonstrated immediate `FastIoWrite` path. Exception handling around that call and target filesystem behaviour may turn some invalid addresses into a failed request rather than a disclosure or system failure. No reliable denial of service or RCE is asserted.
  - **Validation:** A temporary 32-bit-integer model used a 160-byte received SMB, `DataOffset = 0xff00`, and immediate/total lengths of 100. The signed right-hand side became -65120, the guard accepted, and the computed offset was 65,280 bytes beyond the header. GCC emitted `-Wsign-compare`. This validates the predicate, not a Windows SMB server.
  - **Historical references and novelty:** MS09-001 / CVE-2008-4114 is the related published `WRITE_ANDX` invalid-`DataOffset` denial of service. The separate handler and source-level difference justify W1, but no official CVE or previously undisclosed status is claimed.
  - **Confidence:** High for the arithmetic defect and source pointer; medium for security impact until a real server test establishes the filesystem and pool behaviour.
  - **Remediation direction:** Read the offset once, reject `offset > receivedLength` before subtraction, then reject `immediateLength > receivedLength - offset`; use `RequestBuffer->DataLength` and overflow-safe unsigned arithmetic. Add raw-write tests at, below, and above the received boundary.

- **[NT-AUDIT-007] Name-keyed `termdd` channel rebinding matches the historical `MS_T120` channel-lifetime defect**
  - **Status:** Provisional. The vulnerable channel-management logic is present and matches public pre-fix analyses, but the provider that populates client bindings is absent, so this checkout cannot close the remote input and teardown chain.
  - **Priority:** P2 — potentially serious kernel channel-table corruption with constrained evidence in this snapshot. The historical CVE's pre-authentication impact is not asserted as independently reproduced here.
  - **Wildness:** W0 for the name-rebinding mechanism — public CVE-2019-0708 patch analyses identify these functions and the `MS_T120`-on-a-non-31-channel condition. The separate unchecked-class hypothesis is U-01, not folded into this W0 entry.
  - **Area:** `networking` (primary, RDP); `kernel` (secondary, `termdd.sys`).
  - **CVE:** `CVE-2019-0708` (historical mechanism mapping; no new CVE assigned).
  - **Affected revision:** `04fc55266a9e4cf6259a83864713441eb0016ade`; Terminal Services configurations whose provider supplies the relevant bindings.
  - **CWE:** CWE-416 (Use After Free), conditional on completion of the historical bind/close/reuse sequence.
  - **Attack vector and prerequisites:** Potentially remote through RDP channel negotiation, but **not established end to end in this repository**. `IcaBindVirtualChannels` receives `SD_VCBIND` records through `IOCTL_ICA_VIRTUAL_QUERY_BINDINGS`; the MCS/T.120 implementation that would prove client provenance is not checked in. No anonymous-access or wormability claim is made for this source snapshot.
  - **Summary and root cause:** For each provider-supplied name, `IcaBindVirtualChannels` calls `IcaFindChannelByName` and, if an object already exists, rebinds that object using the newly supplied class (`channel.c:1904-1933`). `_IcaBindChannel` overwrites `pChannel->VirtualClass` before checking the target slot only with `ASSERT` and then storing the pointer (`:2298-2307`). `_IcaFreeChannel` clears only the slot named by the object's *current* class (`:2179-2181`). Rebinding an existing internal channel to another class can therefore leave the old slot referencing an object that is later freed.
  - **Source evidence:** `termsrv/drivers/termdd/channel.c:1872-1940` (provider query and name-based rebind), `:1943-1968` (rebind path), `:2157-2187` (free clears only the current slot), `:2284-2310` (class overwrite, assertion, and slot store); `termsrv/drivers/termdd/icap.h:79-85` (channel-pointer array); `public/internal/termsrv/inc/hydrix.h:147-165` (name/class binding structure and `VIRTUAL_MAXIMUM 32`); `termsrv/inc/mcsioctl.h:293-298` (`MS_T120` and internal channel number 31); `termsrv/inc/mcskernl.h:43-50` (provider declaration only).
  - **Historical relationship:** Public patch analyses of CVE-2019-0708 state that the fix forces `MS_T120` to bind only to channel 31 in `IcaBindVirtualChannels` and `IcaRebindVirtualChannels`. The corresponding name-based rebinding and absence of that guard are visible here. This is stronger than a generic “same driver” comparison, but still does not replace the missing provider/runtime evidence.
  - **Impact if the chain is confirmed:** A stale channel-table pointer can survive object teardown and be dereferenced by later channel operations, producing kernel use-after-free. Historical remote-code-execution impact belongs to the cited CVE, not to a test performed for this bulletin.
  - **Validation:** Static source and historical patch-analysis comparison only. No RDP negotiation, channel close, Driver Verifier run, or product binary was used.
  - **Confidence:** High for the defective rebinding/free logic and its correspondence to public pre-fix analyses; medium-to-low for reachability from this checkout alone, hence Provisional.
  - **Remediation direction:** Enforce the historical `MS_T120`/31 invariant; reject duplicate or occupied target slots at runtime rather than with `ASSERT`; make channel class immutable or remove the old slot before rebinding; validate every class index at the provider boundary. See U-01 for the separate range-check follow-up.

- **[NT-AUDIT-008] A present-but-empty prefix leaves `pathBuffer` uninitialized before Server Service path concatenation**
  - **Status:** Provisional. The uninitialized stack use is confirmed in source and in an extracted model; residual-stack control, a product crash, and exploitation are not established.
  - **Priority:** P1 — memory corruption is plausible on a remotely callable sensitive service, but the impact evidence is incomplete and no code execution is claimed.
  - **Wildness:** W2 — no matching public disclosure was identified for this distinct empty-prefix initialization defect. This is provisional novelty, not a zero-day assertion. MS06-040 and MS08-067 are context, not mappings.
  - **Area:** `networking` (primary); `smb`, `rpc` (secondary).
  - **CVE:** Unassigned.
  - **Affected revision / architectures:** `04fc55266a9e4cf6259a83864713441eb0016ade`; portable C in both ANSI and Unicode forms, with build-specific width and stack behaviour.
  - **CWE:** CWE-457 (Use of Uninitialized Variable), potentially leading to CWE-121 (Stack-based Buffer Overflow).
  - **Attack vector and prerequisites:** The SRVSVC `NetprPathCanonicalize` route is present in IDL and forwards to this code (`srvsvc.idl:905-912`; server `canon.c:64-109`; registration at `srvmain.c:336-339`). A caller can supply an empty string for the required `[in,string] Prefix`; `NetpwPathCanonicalize` treats it as “no prefix” for validation but passes the original non-null pointer onward. RPC authorization, deployment policy, and worker-thread reuse were not assessed, so no unauthenticated claim is made.
  - **Summary and root cause:** `NetpwPathCanonicalize` computes `noPrefix = ((Prefix == NULL) || (*Prefix == TCHAR_EOS))` (`pathcan.c:111`) and skips `NetpwPathType` when it is true (`:141-145`). In `CanonicalizePathName`, however, only a null pointer takes the initialization branch. A non-null empty prefix enters `ARGUMENT_PRESENT(PathPrefix)`, produces `prefixLen == 0`, skips both the nonempty copy and the `pathBuffer[0] = 0` else-branch, and reaches `STRCAT(pathBuffer, PathName)` with uninitialized stack contents (`canon.c:166-196`).
  - **Source evidence:** `ds/netapi/netlib/pathcan.c:109-163` (empty-prefix validation and unchanged call); `ds/netapi/netlib/canon.c:165-196` (uninitialized branch and concatenation); `ds/netapi/svcdlls/srvsvc/idl/srvsvc.idl:905-912`; `ds/netapi/svcdlls/srvsvc/server/canon.c:99-108`. The later length check uses only `pathLen + prefixLen`, so it cannot account for residual data already in the array.
  - **Impact:** `STRCAT` first scans uninitialized data and then appends the supplied path. Depending on residual stack contents, this can read or write beyond the 521-element array. Controlled reuse of a prior RPC worker's stack frame is plausible but was not demonstrated; no RCE, reliable crash, or exact product impact is claimed.
  - **Validation:** PR #32 reported an extracted ASan reproduction with residual contents. Consolidation independently modelled the exact branch/copy ordering with 16-bit `TCHAR`, 519 residual characters, and a 259-character path; ASan reported a stack-buffer-overflow write. This is a deliberately conditioned host model, not an RPC or Windows reproduction.
  - **Historical references and novelty:** MS06-040 / CVE-2006-3439 and MS08-067 / CVE-2008-4250 concern other canonicalization defects. Neither is assigned to this entry. NT-AUDIT-002 differs in its backward-scan root cause; NT-AUDIT-003 differs in its 520-character nonempty-prefix boundary.
  - **Confidence:** High for the uninitialized source behaviour; low for attacker control of residual data and final product impact, hence Provisional.
  - **Remediation direction:** Normalize empty prefixes to null before calling, initialize `pathBuffer[0]` for both null and empty inputs, calculate the effective length before any write, and use bounded concatenation with explicit capacity.
  - **Follow-up:** Trace RPC worker-stack reuse in a disposable instrumented Windows build and test whether a prior request can leave bounded, attacker-influenced residual text in this frame. Do not reclassify impact without that evidence.

- **[NT-AUDIT-009] Byte-sized SRVSVC output capacity is used for a Unicode terminator store**
  - **Status:** Unverified. The byte/element unit mismatch is confirmed, but the generated server stub's actual allocation and any security impact are unknown.
  - **Priority:** P3 — the demonstrated model is a two-byte store into a one-byte logical allocation; alignment and allocator granularity may hide the error, and no RCE or reliable crash is claimed.
  - **Wildness:** Unresolved — no exact public mapping or novelty determination was established. CVE-2006-3439 is not assigned to this defect.
  - **Area:** `rpc` (primary); `networking`, `smb` (secondary).
  - **CVE:** Unassigned.
  - **Affected revision:** `04fc55266a9e4cf6259a83864713441eb0016ade`; Unicode builds (`ds/netapi/netlib/sources:42-45`, `ds/netapi/svcdlls/srvsvc/server/sources:55-58`).
  - **CWE:** CWE-787 (Out-of-bounds Write), conditional on the runtime buffer actually having only the declared byte capacity.
  - **Summary and root cause:** The SRVSVC IDL declares `[out,size_is(OutbufLen)] LPBYTE Outbuf` and defines `OutbufLen` as a byte count. The server wrapper forwards it unchanged. `NetpwPathCanonicalize` rejects only `OutbufLen == 0`; for every positive value it executes `*Outbuf = TCHAR_EOS` (`pathcan.c:153-157`). In a Unicode build, that is a two-byte store, so a one-byte capacity is insufficient.
  - **Source evidence:** `ds/netapi/svcdlls/srvsvc/idl/srvsvc.idl:904-913`; `ds/netapi/svcdlls/srvsvc/server/canon.c:64-109`; `ds/netapi/svcdlls/srvsvc/client/srvstub.c:3183-3229` (client length documented in bytes); `ds/netapi/netlib/pathcan.c:88-90,147-159`; Unicode build definitions cited above. The checked-in `server/srvsvc_s_stub.c` only includes `srvsvc_s.c`, and that generated implementation is absent, preventing inspection of its allocation behaviour.
  - **Attack vector and trust boundary:** A caller of `NetprPathCanonicalize` controls `OutbufLen`, but authentication and generated-stub allocation were not established. This is a contract and memory-safety concern, not a demonstrated remote vulnerability.
  - **Validation:** PR #32 reported a 16-bit `TCHAR` ASan model. Consolidation independently allocated one byte in a host model and executed the same positive-length terminator store; ASan reported a two-byte heap-buffer-overflow write. This demonstrates the unit mismatch under that allocation model only, not MIDL behaviour or a Windows service crash.
  - **Historical / protocol references:** Microsoft MS-SRVS documents `NetprPathCanonicalize` and its byte-sized output contract, including `NERR_BufTooSmall`. No CVE mapping is made.
  - **Confidence:** High for the implementation's inadequate positive-length guard; low for practical security impact, hence Unverified.
  - **Remediation direction:** Reject `OutbufLen < sizeof(TCHAR)` before the first store, keep byte/character conversions explicit at every boundary, and test zero-, one-, odd-, and aligned capacities against the actual generated RPC stub.

- **[NT-AUDIT-010] Optional `SLMDBG` diagnostics have inconsistent domain-length bookkeeping and out-of-bounds accesses**
  - **Status:** Unverified. The conditional source defects are confirmed, but the normal server manifest does not enable `SLMDBG`, and no diagnostic build or runtime trigger was tested.
  - **Priority:** P3 — optional diagnostic code with one-byte stack corruption and small out-of-bounds/disclosure reads; no default-build or remote-exploit claim.
  - **Wildness:** Unresolved — no exact historical mapping or meaningful novelty determination was made for this debug-only path.
  - **Area:** `smb` (primary); `kernel`, `configuration` (secondary).
  - **CVE:** Unassigned.
  - **Affected revision / configuration:** `04fc55266a9e4cf6259a83864713441eb0016ade`, only with `SLMDBG` defined. `base/fs/srv/sources.inc:59-66` does not define it in the tracked normal manifest.
  - **CWE:** CWE-121 (Stack-based Buffer Overflow), CWE-125 (Out-of-bounds Read), and CWE-200 (Exposure of Sensitive Information), all conditional on this diagnostic configuration and path.
  - **Summary and root cause:** `COMPUTER_NAME_LENGTH` is 15, so `domainName[COMPUTER_NAME_LENGTH+1]` has 16 elements (`srvconst.h:28`; `svcsupp.c:1205`). For the active caller's short constant `"BLUBBER"`, the first loop stops at index 7 and the padding loop fills through index 14, leaving `domainLength == 15` and index 15 uninitialized. `domainName[++domainLength] = '\0'` then writes index 16, one byte out of bounds (`svcsupp.c:1213-1230`).
  - **Additional consequences of the same length error:** `domain.Length` becomes 16, and `SrvSendDatagram` can copy 16 bytes from `domainName`, including uninitialized index 15 (`svcsupp.c:1083-1087`). Independently, `RtlCopyMemory(domainInData, Domain, domainLength + 1)` at `:1287` copies 17 bytes from the original short `Domain` string, reading beyond that source. These are all consequences of one incorrect length computation and are intentionally kept in one finding.
  - **Source evidence / trigger path:** `base/fs/srv/svcsupp.c:1180-1301`; `base/fs/srv/slmcheck.c:113-278` (fixed-domain call at 274); conditional callers in `base/fs/srv/smbclose.c:228-257` and `base/fs/srv/smbrdwrt.c:4533-4558` require the SLM status check to fail on a handle with write access. Actual client reachability of that condition was not tested.
  - **Validation:** Static index and copy-length analysis for all three consequences. Consolidation also executed the exact short-domain loop/index model under ASan and observed a one-byte stack-buffer-overflow at the terminator store. No diagnostic driver was built, no datagram was sent, and the additional source read was not dynamically exercised.
  - **Impact:** In an `SLMDBG` build, the routine can write one byte beyond a kernel stack array, transmit an uninitialized stack byte in the domain field, and read beyond the original constant domain while constructing the diagnostic message. No peer exposure, kernel crash, or exploitation was demonstrated.
  - **Confidence:** High for the conditional source arithmetic; low for build inclusion, runtime reachability, and operational impact, hence Unverified.
  - **Remediation direction:** Keep `domainLength` bounded to the NetBIOS field size, terminate at a verified in-range index, initialize every transmitted byte, use the original string's actual length for each copy, and add an `SLMDBG` build/test configuration with boundary cases.

## Coverage, Gaps and Residual Risk

**Source chains traced**

- `srvsvc` path canonicalization: IDL → server wrapper → `NetpwPathCanonicalize` → `CanonicalizePathName` → path conversion helpers / `BackUpPath` (NT-AUDIT-002, -003, -008, -009).
- `wkssvc` alternate-computer-name flow: IDL → add/remove methods → `NetpManageAltComputerName` → NetSetup logging → `NetpDebugDumpRoutine` (NT-AUDIT-001).
- x86 VDM initialization and execution: `NtVdmControl` → service dispatch → VDM TIB/context operations → context-switch assembly → trap/BIOS-return assembly (NT-AUDIT-004, -005).
- SMB immediate raw write: request buffer length → generic validation → `SrvSmbWriteRaw` guard and FID checks → immediate `FastIoWrite` source pointer (NT-AUDIT-006).
- `termdd` channel management as far as the checked-in provider boundary: binding records → name lookup/rebind → slot update/free (NT-AUDIT-007 and U-01).
- Conditional SLM diagnostic construction and datagram copy (NT-AUDIT-010), plus NetLib/SRVSVC/Workstation build manifests used to establish source inclusion.
- Prior audit notes in `agents/audit/` were re-read and code-affecting claims checked against the current source (R-04). The old reproduction script is not treated as authoritative.

**Scoped reviews without an additional confirmed finding**

- NetLib `namecan.c`, `nameval.c`, `pathtype.c`, and `pathcmp.c`; Workstation UNC/tree-connect handling (R-02); FTP `RNFR`/`RNTO` sanitization (R-03); ntdll DOS-path conversion (R-06); and sampled `METHOD_NEITHER` probing in HID/AFD/filesystem handlers.
- SMB transaction offsets/counts, named-pipe transceive, mailslot dispatch/write handling, FEALIST conversion, and SMB string scans (R-07 through R-09). The Create-with-SD/EA alignment question remains U-03.
- SRVSVC outbound announcements (`scavengr.c:666-729,777-905,1056-1211`) and the local/legacy transaction wrapper (`ds/netapi/xactsrv/apipath.c:297-413`): no attacker-controlled inbound copy or concrete defect was established in these limited traces. Configuration sources and the whole subsystem were not cleared.
- `enduser/msasn1/berdecod.c`: sampled allocation/underflow paths fail closed; this is not a review of the separate SNMP BER parser, whose corrected short-input lead is U-04.
- AFD poll length checks and the sampled NetBIOS proxy/scope path (R-13, R-14); `IoIs32bitProcess` NULL-IRP semantics (R-15); VDM BOP/printer paths (U-06). TCP option parsing remains U-05 rather than a clean rejection.

**Gaps and residual risk**

- **No product build or runtime:** No Windows/Razzle/NMAKE build, `/GS` layout, link-time binary confirmation, live Windows system, RPC/SMB/RDP peer, Driver Verifier, WER data, or fuzzing was used. Host compiler/ASan results apply only to the temporary extraction or model named in each entry.
- **Generated RPC code absent:** `srvsvc_s.c` is not checked in. IDL and hand-written wrappers were used as the contract. This is decisive uncertainty for NT-AUDIT-009. It does not negate NT-AUDIT-001's multi-kilobyte logging overflow, but exact wire limits were not independently generated.
- **Provider and configuration gaps:** The MCS/T.120 provider needed to prove client-controlled `SD_VCBIND` provenance is absent (NT-AUDIT-007, U-01). RPC ACLs, authentication policy, SMB guest policy, Terminal Services deployment state, `SLMDBG` build inclusion, and RPC worker-stack reuse were not established.
- **Targeted, not exhaustive:** Kernel memory/object manager internals, filesystem parsers, the remainder of `srv.sys`, NDR marshalling, LSASS, IIS HTTP parsing, Terminal Services outside the cited channel paths, and drivers/services outside the sampled files were not comprehensively audited. A negative result applies only to its cited path and revision.
- **No exploitation:** No exploit was developed, no real target was contacted, and no payload, credential, persistence, or weaponized procedure is included.

**Cross-cutting remediation priorities**

1. Establish exact source-to-binary/SKU correspondence and apply the historical updates associated with the W0 findings; absence of a fix in this old tree is not proof about an already-patched deployed binary.
2. Use overflow-safe unsigned offset/length validation before subtraction or pointer construction, and compile protocol code with signedness warnings treated as review gates (NT-AUDIT-006).
3. Do not use `ASSERT` as a runtime trust-boundary check, and do not authenticate kernel transitions solely with user-reproducible context values (NT-AUDIT-004, -007, U-01).
4. Check in or generate reproducible RPC stubs and test zero/empty/odd/boundary inputs at the actual marshalling boundary (NT-AUDIT-003, -008, -009).

## Rejected and Deduplicated Candidates (Appendix)

- **R-01 — The classic MS06-040 / CVE-2006-3439 unchecked prefix/path concatenation: rejected in this revision, narrowly.** Public analyses describe a pre-patch `CanonicalizePathName` that concatenated prefix and path without the present aggregate-length check. Here `prefixLen > MAX_PATH*2` (`canon.c:174`), `pathLen + prefixLen > MAX_PATH*2 - 1` (`canon.c:192`), and a `MAX_PATH*2 + 1` destination (`canon.c:166`) bound the ordinary validated path form before `STRCAT`. This is **not** a blanket statement that the function is safe: NT-AUDIT-002 is a backward-scan defect, NT-AUDIT-003 is the nonempty 520-character prefix boundary, and NT-AUDIT-008 is the empty-prefix initialization defect. They have different root causes and are not deduplicated into this rejection.
- **R-02 — `USHORT` truncation in `WsCreateTreeConnectName` (`ds/netapi/svcdlls/wkssvc/server/useutil.c:689-707`, `:765`): unreachable.** The `MaximumLength` computation casts `UncNameLength * sizeof(WCHAR)` to `USHORT`, which would wrap for names of 32768+ characters and undersize the allocation before `wcscat(TreeConnectStr->Buffer, &UncName[1])`. However, `NetrUseAdd` obtains `UncNameLength` only after `WsUseCheckRemote` canonicalises the UNC name into a caller buffer of `MAX_PATH * sizeof(TCHAR)` (`useutil.c:1716-1724`) and sets `*UncNameLength = STRLEN(UncName)` (`:1761`), so the length is at most 259. The truncation is a latent robustness issue in a function that other callers could misuse, not a reachable vulnerability in this revision.
- **R-03 — `strcpy(pUserData->RenameSourceBuffer, pszArg)` in FTP `RNFR` (`inetsrv/iis/svcs/ftp/server/engine.cxx:2095-2105`): not reachable as an overflow.** `RenameSourceBuffer` is `MAX_PATH` bytes, and the copy looks dangerous because FTP command lines may be up to `MAX_COMMAND_LENGTH` (512, `cons.hxx:29`). But `VirtualCanonicalize` calls `VirtualpSanitizePath(pszArg)` in place (`userdb.cxx:3620`) before `LookupVirtualRoot`, which copies the virtual path plus the metadata root into a `STACK_STR(..., MAX_PATH)` and fails when it does not fit (`userdb.cxx:4925-4990`); the subsequent `strcpy` therefore only sees a sanitised string shorter than `MAX_PATH`. Kept as a note: the guard is indirect and would disappear if the sanitisation or the root-path bound changed.
- **R-04 — Stale source claims in earlier repository audit notes: rejected against this revision.** (a) `net/rras/ras/ppp/common/clsa.c:690-691` clears the full pointed-to session key with `sizeof(*pUserKey)`; (b) `base/subsys/sm/server/sminit.c:1537` initializes `ValueData = NULL`, and `:1554-1571` validates `REG_SZ`, terminates the available buffer, and selects a defined fallback; (c) `admin/wmi/wbem/xmltransport/client/helpersources/httpconnectionagent.cpp:387` uses `if (bResult == FALSE)`, while the caller initializes the response pointer to null—broader WMI error handling was not exhaustively reviewed; (d) `termsrv/license/tlserver/server/license.cpp:411-414` uses `if (bSuccess == FALSE)` rather than assignment; (e) the seven inspected UL `OVERLAPPED` initializers, including `snd.c:50`, `rcv.c:60`, and the chat client/server sites, use `memset(pointer, 0, sizeof(...))`. The old zero-byte `OVERLAPPED` probe hard-coded the alleged argument order and is not evidence about current source. None of these stale claims is counted as a current finding; remaining build/resource/documentation notes are outside this security finding count.
- **R-05 — Duplicate logging overflows in other services: deduplicated under NT-AUDIT-001.** The same unbounded-`vsprintf` pattern appears in the SAM log (`ds/ds/src/sam/server/log.c:338`), the NetLogon log (`ds/netapi/svcdlls/logonsrv/server/nlp.c:1637-1787`), the Browser trace log (`ds/netapi/svcdlls/browser/server/brutil.c:318`), the DNS server file log (`ds/dns/server/server/file.c:477`, `log.c:637`) and the Directory Service log (`ds/ds/src/common/dscommon/filelog.c:141`). Whether each is reachable with attacker-sized data by default was not established (several require debug logging to be enabled); they are recorded as the same defect family, and only the Workstation-service instance is claimed as confirmed.
- **R-06 — `RtlDosPathNameToNtPathName_U` (MS03-007 class) spot check: no defect identified.** `base/ntdll/curdir.c:2500-2540` computes the length with `wcslen`, rejects `Length + sizeof(WCHAR) >= UNICODE_STRING_MAX_BYTES`, and stores the length in a `UNICODE_STRING`; the DOS-to-NT conversion was not audited further. This is a spot check, not a clearance of the WebDAV path.

- **R-07 — SMB transaction, named-pipe, and mailslot input-length candidates: rejected only for the reviewed routes.** `SrvSmbTransaction` checks setup/parameter/data offset-plus-count against the received SMB and rejects counts greater than totals (`base/fs/srv/smbtrans.c:1690-1728`); the 16-bit operands promote to `int` for these sums. `SrvValidateSmb` separately bounds the ByteCount location and available SMB space (`smbsupp.c:6097-6110`). The fast named-pipe transceive path is entered only for a single-buffer transaction after those checks (`smbtrans.c:1783-1800`), so its `header + DataOffset` Type3 buffer and `DataCount` length have the reviewed bound (`pipe.c:1423-1665`). Other pipe helpers use the transaction's copied `InData`. The mailslot route opens with `IO_FORCE_ACCESS_CHECK` (`smbtrans.c:3715-3768`), and `MsCommonWrite` enforces `MaximumMessageSize`, verifies the CCB under exclusive FCB access, and queues the stated write length (`base/fs/mailslot/write.c:188-267`). No out-of-bounds write or race was established in these paths. This does not clear every transaction secondary, pipe IOCTL, or mailslot operation, and it does not negate NT-AUDIT-006's separate raw-write guard.
- **R-08 — OS/2 FEALIST conversion overflow: rejected for the checked callers.** `smbopen.c:1152-1185` and `smbdir.c:424-433` require `cbList` to be larger than the header and no greater than `transaction->DataCount` before conversion; transaction data count has the R-07 received-length bound. `SrvOs2FeaListToNt` checks each variable-length FEA against `lastValidLocation` (`base/fs/srv/ea.c:443-480`) and rejects an inconsistent first entry (`:321-324`). The final 16-bit `cbList` rewrite affects the response length, not the input-loop bound. NT Create-with-SD/EA padding is a different, unresolved question (U-03).
- **R-09 — Unterminated SMB string extraction: rejected at the reviewed call sites.** `END_OF_REQUEST_SMB` is the last valid byte (`base/fs/srv/srvmacro.h:394-400`). `SrvGetStringLength` scans ANSI through that inclusive endpoint and Unicode only while a complete `WCH` remains before the endpoint, returning `(USHORT)-1` on exhaustion (`base/fs/srv/smbsupp.c:2155-2252`). Tree-connect, share-validation, and user/domain callers check that error before using the returned length (for example `smbtree.c:116-145`, `share.c:92-114`, `smbadmin.c:2297-2381`). The separate `SrvGetString` API-buffer copy writes its own terminator (`svcsupp.c:125-140`). No concrete over-read was established in these call sites; this is not a whole-parser clearance.
- **R-10 — IIS UL `snd` memory errors: confirmed local test-utility defects, rejected as remote/product-service findings.** `inetsrv/iis/iisrearc/ul/win9x/src/test/cmd/snd/snd.c:26,34-45,65-70` has a 2,048-byte stack buffer, unbounded `gets`, unchecked `atoi`, an unbounded URI copy, and a fill/terminator sequence for which size 2,048 already writes one byte past the array. These writes are driven by local command-line/console input before `UlSendMessage`; no inbound network data reaches them in the reviewed path. The manifest builds a console test `PROGRAM`, while the parent `test/dirs` traverses only `vxd`, not `cmd`; shipment is unknown. PR #32 reported an ASan reproduction of the size-2,048 fill. Retained as a P3 robustness/fix note, but excluded from the 10 security findings because no server trust boundary or product exposure was established. Replace `gets`/`atoi`, bound the URI copy, and require `ulSize < sizeof(pBuffer)`.
- **R-11 — Small/equal `WRITE_RAW` offsets as a separate finding: deduplicated into NT-AUDIT-006.** The same guard rejects a positive `immediateLength` when `DataOffset` equals the received length because the remaining length is zero. That boundary control does not fix the negative-subtraction case for larger offsets. It is a test control for one root cause, not another vulnerability or a contradiction of NT-AUDIT-006.
- **R-12 — Missing VDM gate or nearby stubs as independent findings: deduplicated / not established.** The absence of a literal `VdmAllowed` check and the `VdmStartExecution` exemption are evidence within NT-AUDIT-004, not a second root cause or proof that every process can exploit it. `VdmpPrinterDirectIoOpen` (`base/ntos/vdm/i386/vdmprint.c:505-516`) is a stub returning success without I/O; no boundary violation follows from that fact alone. The distinct historical BOP/#UD question remains U-06.
- **R-13 — AFD `IOCTL_AFD_POLL` short-buffer/count candidate: rejected in the sampled native and 32-bit entry points.** `AfdPoll` and `AfdPoll32` first require the fixed structure prefix, then compare the remaining input length divided by the handle-element size with `NumberOfHandles`, and require output capacity at least equal to input capacity (`net/sockets/winsock2/wsp/afdsys/poll.c:83-120,1010-1060`). They iterate the validated handle count, reference handles with `ObReferenceObjectByHandle`, and verify the device object. No unchecked direct user pointer was identified in this path. Allocation-scale, cancellation, and other AFD IOCTLs were not exhaustively assessed.
- **R-14 — NetBIOS proxy copy / zero-scope-length candidate: not reproduced in the reviewed configuration path.** `ProxyDoDgramDist` is in `net/netbt/sys/hndlrs.c:3704-3790` (not `inbound.c`); it allocates `DgramLen` bytes and copies exactly `DgramLen`. `ReadScope` rejects an empty/`*` registry scope into the default path, computes a positive length for a valid nonempty scope, and the default/root scope sets `ScopeLength = 1` (`net/netbt/sys/init.c:928-1095`). Thus the proposed `ScopeLength == 0` prerequisite for the size expression at `inbound.c:232` was not established from the tracked initialization/configuration path. This narrow result does not prove all NetBT name parsing or all administrative/registry corruption cases safe.
- **R-15 — `IoIs32bitProcess(NULL)` semantic defect: rejected as originally stated.** The x64 implementation explicitly handles a null IRP by combining `ExGetPreviousMode() == UserMode` with the current process's WoW64 state, matching its own fast-I/O contract (`base/ntos/io/iomgr/iosubs.c:13810-13853`). Contrary to the candidate's rationale, numerous in-tree AFD fast-I/O and miscellaneous paths do pass `NULL`; the sampled query-handle path uses that result for structure sizing and separately probes user output (`net/sockets/winsock2/wsp/afdsys/misc.c:869-885,1006-1025`). No defect was established in that usage. This is not a proof that every caller supplies the right process context; any future concern must name a caller where previous mode/current process differs from the request originator and show a security consequence.

### Additional Unresolved Leads (Not Counted as Findings)

These items retain explicit uncertainty because the available source neither closes them nor supports a vulnerability count, priority, or CVE assignment.

- **U-01 — `termdd` provider-supplied `VirtualClass` range.** `_IcaBindChannel` uses `VirtualClass` as an array index with an `ASSERT` but no free-build runtime range check (`termsrv/drivers/termdd/channel.c:2284-2310`; `VIRTUAL_MAXIMUM` is 32). The name-rebinding lifetime mechanism is NT-AUDIT-007, but a direct out-of-range class from a client is not established: the MCS/T.120 provider and its `SD_VCBIND` construction/validation are absent. **Follow-up:** obtain that provider, trace class provenance, and test an out-of-range binding only in a disposable instrumented build. Do not claim a separate CVE-2019-0708 variant without this evidence.
- **U-02 — `canonapi.c` output-end probe arithmetic.** `ds/netapi/api/canonapi.c:504-508` computes `Outbuf + OutbufLen/sizeof(*Outbuf) - sizeof(*Outbuf)`. Because the final subtraction is in elements, Unicode builds can probe before a very short buffer rather than at its last element. The code reads a value and writes the same value inside SEH; no attacker-controlled mutation, external buffer layout, or privilege-boundary impact was established. **Follow-up:** identify local callers and minimum `OutbufLen`, then replace the expression with `Outbuf + OutbufLen/sizeof(*Outbuf) - 1` after validating nonzero capacity and test page-bound buffers. Not accepted as a security finding yet.
- **U-03 — NT Create-with-SD/EA alignment versus length validation.** `base/fs/srv/smbopen.c:2861-2872` advances `eaBuffer` by `(sdLength + 3) & ~3` but checks the unaligned `eaLength + sdLength` sum against `DataCount`. Some transaction inputs are rounded to aligned storage (`smbtrans.c:2151-2167`), but exact descriptor validity, padding, secondary-buffer, and allocation-end conditions were not closed. **Follow-up:** model all input storage paths and test `sdLength % 4` cases with exact-end allocations; do not infer an out-of-bounds access from the pointer expression alone.
- **U-04 — SNMP BER short-input reads; PR #30's one-byte rejection rationale is not supported.** `pLastByte` is one past the logical buffer (`net/snmp/newagent/exe/snmppdus.c:2449`). `ParseType` dereferences before its pointer check, and `ParseLength` reads the initial length plus as many as four long-form bytes before checking the end (`:1397-1445,1451-1480`). After a valid final type byte, a missing length can therefore cause more than the previously claimed one-byte logical over-read—up to five bytes beyond the last valid byte in the extreme long-form case, depending on adjacent values. Error paths reject inconsistent lengths and no attacker-directed write was found, but allocation padding and page-bound availability impact were not established. **Follow-up:** add pre-read remaining-length checks and run non-destructive page-bound parser tests. No confirmed vulnerability or clean rejection is recorded.
- **U-05 — TCP received-option trailing-short reads; the one-byte characterization is incomplete.** `ParseRcvdOptions` requires at least three bytes only before entering the loop. After NOPs or a prior option, a non-NOP trailing element can cause reads of `Options[1]` and then `Options[2]` before the minimum-length checks (`net/tcpip/driver/ipv4/iprcv.c:239-300`). Thus the logical option region can be read by up to two bytes beyond its end, not necessarily only one. Non-NOP lengths below three are rejected and NOP advances by one, so the proposed infinite-loop concern is not supported. The surrounding IP receive buffer may contain payload beyond the option region, and no overwrite or copy using the stray value was established. **Follow-up:** verify actual receive-buffer boundaries and add a remaining-length check before both reads; keep this as parser robustness/availability uncertainty, not a confirmed security finding.
- **U-06 — Historical VDM `#UD`/BOP transfer-validation class.** `VdmDispatchBop` probes the user instruction and permits fast I/O only for BOP service numbers `0x42`/`0x43`, while other BOPs are reflected through `VdmEndExecution` (`base/ntos/vdm/i386/vdmuserrefs.c:210-323`; `strtexec.c:218-290`). The instruction reads and ring-3/context assumptions occur inside exception handling, but a live NTVDM was not available to close the historical kernel-transfer-address class or prove exploitability. **Follow-up:** compare the exact historical pre/post-fix code and use a disposable VDM-capable instrumented build. This is not merged into NT-AUDIT-004 and has no separate priority or CVE claim.

## Validation Artifacts

No harness is committed. Original PR #31 extraction harnesses were kept outside the repository under `/home/user/audit-work/` during that audit; PR #32 states that its temporary harnesses were removed. Consolidation used new temporary files under `/tmp/neo-consolidation/` and did not execute a Windows product, network service, or exploit. The only repository file changed by consolidation is `CVE.MD`.

**Original PR #31 extraction results (historical audit record; not represented as a full consolidation rerun)**

| Artifact | Purpose | Observed result |
| --- | --- | --- |
| `log_harness.c` | `NetpDebugDumpRoutine` formatting core with `char[2049]` | 2,000-character name: no overflow; 3,000-character name: ASan stack-buffer-overflow, WRITE of size 3,019 |
| `canon_stack.c` | Extracted `ConvertPathMacros` with a real `TCHAR[521]` stack array | `\a\..\x` → ASan stack-buffer-underflow READ in `BackUpPath` called from `ConvertPathMacros` |
| `canon_groomed.c` | Extracted function with an explicitly modelled stack neighbourhood | `\c\..\..\AAAA` → six TCHARs written before the array, first at offset −6, NUL at −1 |
| `canon_prefix.c` | Prefix concatenation with the exact array bound | Prefix 519: clean; prefix 520 without trailing separator: ASan stack-buffer-overflow; prefix 520 with separator: clean |

Those harnesses replaced Windows primitives with host equivalents and used an explicitly modelled groomable stack where stated. They do not establish Windows stack layout, `/GS`, RPC behaviour, or product exploitability.

**Consolidation checks actually run on 2026-10-31**

| Check | Exact result and scope |
| --- | --- |
| GCC 12.2 predicate model, `-Wall -Wextra -Wsign-compare` | `WRITE_RAW` model: signed RHS −65,120, unsigned conversion 4,294,902,176, guard accepted for the stated 160/100/`0xff00` case. VDM model: `SegCs & FRAME_EDITED = 0x0008`, masked selector `0x000b`. GCC emitted the expected signedness warning for the SMB expression. Arithmetic/masks only. |
| 16-bit `TCHAR` empty-prefix branch/copy model, ASan | Exit 1; stack-buffer-overflow, WRITE of size 2 after explicitly seeded residual contents. Supports NT-AUDIT-008's source/model claim only. |
| 16-bit `TCHAR` 520-character prefix model, ASan | Exit 1; stack-buffer-overflow, WRITE of size 2. Supports NT-AUDIT-003's local bound defect, not caller reachability. |
| One-byte output allocation with Unicode terminator model, ASan | Exit 1; heap-buffer-overflow, WRITE of size 2. Supports NT-AUDIT-009's unit mismatch under that allocation model only. |
| Short-domain `SLMDBG` loop/index model, ASan | Exit 1; stack-buffer-overflow, WRITE of size 1 at the terminator. The additional 17-byte source copy was checked statically, not executed. |
| Logging formatting model with a 3,000-byte name, ASan | Exit 1; stack-buffer-overflow, WRITE of size 3,034 in this simplified model. This supplements, but does not replace, the original extracted `vsprintf` result for NT-AUDIT-001. |
| Isolated `BackUpPath` lower-bound expression, ASan | Exit 1; out-of-bounds READ below the intended start (ASan classified the host array access as stack-buffer-overflow). The original full extracted `ConvertPathMacros` results remain the stronger source of the write-side observation. |
| PR #32-reported `snd` size-2,048 model | ASan stack-buffer-overflow reported by that audit; not rerun during consolidation. Source was independently re-read and the issue remains R-10, not a product finding. |
| `python3 agents/generate_catalog.py --check` | Exit 0: `Catalog current: 21 root trees.` |
| `git diff --check` | Exit 0. Only `CVE.MD` is modified. |
| Mechanical report checks | Exactly 10 finding headings (001–010), 15 rejected/deduplicated entries (R-01–R-15), and 6 unresolved leads (U-01–U-06). All 72 explicitly cited product-source paths were found at the audited revision; all explicit line numbers on the 65 paths carrying full-path line references were within the cited files. These are consistency checks, not proof of every semantic claim. |
| `python3 agents/verify.py` | Exit 1 on pre-existing unrelated items: two broken links in `agents/audit/14-docs-chkkernel.md`, one in `agents/audit/15-security-readme-keys.md`, and missing `agents/components/.jules.md`. It reported no `CVE.MD` error. Not a passing repository-wide suite. |
| `python3 agents/audit_reproduce.py` | Exit 1 after partial checks: line 137 raises `ValueError: substring not found` while searching for the stale license-assignment source pattern. Earlier output is not a complete pass; the old hard-coded `OVERLAPPED` and license probes do not override current source (R-04). |

Method notes: consolidation's canonicalization and Unicode models use explicit 16-bit elements rather than Linux `wchar_t`; residual stack contents are seeded only where the entry says so. Unrelated path transformations are stubbed in the prefix models. A sanitizer observation in these hosts demonstrates the isolated access, not a Windows crash, remote trigger, information-disclosure yield, or code execution.

## References

Primary sources consulted during the audit and consolidation (accessed 2026-10-31). Historical references establish correspondence or prior art; they do not substitute for the cited source evidence or imply that a live product was tested.

1. Microsoft Security Bulletin MS03-049, “Buffer Overrun in the Workstation Service Could Allow Code Execution (828749)”, 11 Nov 2003 — `https://learn.microsoft.com/en-us/security-updates/securitybulletins/2003/ms03-049`
2. NVD, CVE-2003-0812 — `https://nvd.nist.gov/vuln/detail/CVE-2003-0812`
3. CERT/CC CA-2003-28, “Buffer Overflow in Windows Workstation Service” — `https://www.kb.cert.org/vuls/id/567620`
4. Microsoft Security Bulletin MS08-067, “Vulnerability in Server Service Could Allow Remote Code Execution (958644)”, 23 Oct 2008 — `https://learn.microsoft.com/en-us/security-updates/securitybulletins/2008/ms08-067`
5. NVD, CVE-2008-4250 — `https://nvd.nist.gov/vuln/detail/CVE-2008-4250`
6. Microsoft, “GS Cookie Protection Effectiveness and Limitations” (includes the MS08-067 `ConvertPathMacros` mechanism and stack-frame discussion) — `https://msrc-blog.microsoft.com/2009/03/16/gs-cookie-protection-effectiveness-and-limitations/`
7. Microsoft, “The Inside Story Behind MS08-067” (archived post-mortem mirror) — `https://github.com/JohnLaTwC/Shared/blob/master/The%20Inside%20Story%20Behind%20MS08-067.md`
8. Microsoft Security Bulletin MS06-040 and NVD CVE-2006-3439 — `https://learn.microsoft.com/en-us/security-updates/securitybulletins/2006/ms06-040`, `https://nvd.nist.gov/vuln/detail/CVE-2006-3439`
9. Microsoft Security Bulletin MS10-015 and NVD CVE-2010-0232 — `https://learn.microsoft.com/en-us/security-updates/securitybulletins/2010/ms10-015`, `https://nvd.nist.gov/vuln/detail/CVE-2010-0232`
10. Tavis Ormandy, “Microsoft Windows NT VDM `KiTrap0D`” analysis — `https://blog.cr0.org/2010/01/cve-2010-0232-microsoft-windows-nt-gp.html`
11. Microsoft Security Bulletin MS07-022 and NVD CVE-2007-1206 — `https://learn.microsoft.com/en-us/security-updates/securitybulletins/2007/ms07-022`, `https://nvd.nist.gov/vuln/detail/CVE-2007-1206`
12. eEye / Derek Soeder, Windows VDM zero-page advisory (Full Disclosure archive) — `https://seclists.org/fulldisclosure/2007/Apr/357`
13. Microsoft Security Bulletin MS09-001 and NVD CVE-2008-4114 — `https://learn.microsoft.com/en-us/security-updates/securitybulletins/2009/ms09-001`, `https://nvd.nist.gov/vuln/detail/CVE-2008-4114`. These concern the related `WRITE_ANDX` validation defect; this bulletin does not map that CVE to NT-AUDIT-006's `WRITE_RAW` variant.
14. Microsoft MSRC, CVE-2019-0708 — `https://msrc.microsoft.com/update-guide/vulnerability/CVE-2019-0708`
15. Trellix, “RDP Stands for Really Do Patch: Understanding the Wormable RDP Vulnerability CVE-2019-0708” (pre-/post-fix `MS_T120` channel-binding analysis) — `https://www.trellix.com/blogs/research/rdp-stands-for-really-do-patch-understanding-the-wormable-rdp-vulnerability-cve-2019-0708/`
16. Microsoft MS-SRVS, `NetprPathCanonicalize` — `https://learn.microsoft.com/en-us/openspecs/windows_protocols/ms-srvs/9281f528-e2e7-4113-abd8-6db7255e4387`
17. Microsoft Security Bulletin MS06-035 and NVD CVE-2006-1314 / CVE-2006-1315 — historical Server Service / SMB context only, with no exact mapping asserted for the reviewed mailslot or raw-write paths — `https://learn.microsoft.com/en-us/security-updates/securitybulletins/2006/ms06-035`, `https://nvd.nist.gov/vuln/detail/CVE-2006-1314`, `https://nvd.nist.gov/vuln/detail/CVE-2006-1315`
18. Consolidated candidate reports: PR #30 `https://github.com/havaianasdestruido/neo-nt5/pull/30`, PR #31 `https://github.com/havaianasdestruido/neo-nt5/pull/31`, and PR #32 `https://github.com/havaianasdestruido/neo-nt5/pull/32`. PR descriptions were not treated as evidence without source verification.
19. Repository documentation used for scoping: `README.md`, `AGENTS.md`, `agents/architecture.md`, `agents/README.md`, `agents/audit/README.md`, `agents/audit/manifest.json`, and `PLAN.md` (SEC-004, TST-024, REL-023).
20. All repository source references in this bulletin are pinned to commit `04fc55266a9e4cf6259a83864713441eb0016ade`; see the per-finding source lists. Local `NT-AUDIT`, `R`, and `U` identifiers are not official CVE assignments.

**Statement of scope of claims.** This bulletin reports 10 findings: five confirmed at source level, two provisional, and three unverified latent defects. Five findings have direct historical CVE mappings, one is a W1 handler variant, one is a provisional W2 candidate, and three have unresolved novelty. It also records 15 rejected/deduplicated candidates and six additional unresolved leads. These counts are taxonomy entries, not a claim that all vulnerabilities in the repository have been found. Historical CVE impact is not represented as independently reproduced product impact; the W2 label is not proof of a zero-day; and no official CVE, unauthenticated exploit, reliable denial of service, information-disclosure yield, or code-execution capability is assigned without the evidence stated in the individual entry.
