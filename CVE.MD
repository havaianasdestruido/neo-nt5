# Security Audit Bulletin

## Audit Metadata

- **Repository:** `havaianasdestruido/neo-nt5` (NEONT 5 — a re-branded Windows XP / Windows Server 2003 source tree)
- **Audited revision:** `04fc55266a9e4cf6259a83864713441eb0016ade` (branch `main` as merged by PR #27; the audit branch `arena/2fa433b0-neo-nt5` is based on this commit and the working tree was clean at the start of the audit)
- **Declared product version in tree:** `VER_PRODUCTMAJORVERSION` 5, `VER_PRODUCTMINORVERSION` 1, `VER_PRODUCTBUILD` 2600, `VER_PRODUCTBUILD_QFE` 1106 (`public/sdk/inc/ntverp.h:31-32`, `:44-45`) — i.e. NT 5.1 build 2600 at QFE level 1106, consistent with a Windows XP Service Pack 1-era tree. The tree also contains Windows Server 2003-era components (for example `inetsrv/iis/svcs/ftp/server51`, `base/fs/srv/daytonam`), so per-component servicing level cannot be assumed from the global header.
- **Audit date:** 2026-10-31
- **Architectures examined:** Source is architecture-independent C for the reported findings; both x86 and x64 builds use the same code. Runtime behaviour was modelled on x86-64 Linux with GCC/ASan only (see *Validation environment*).
- **Audit scope:** User-mode RPC servers and the shared NetAPI/NetLib code they link (`ds/netapi/**`), in particular `wkssvc.dll` (Workstation service) and `srvsvc.dll` (Server service), the RPC interface definitions that expose them (`ds/netapi/svcdlls/wkssvc/idl/wkssvc.idl`, `ds/netapi/svcdlls/srvsvc/idl/srvsvc.idl`), the IIS FTP server path-handling code (`inetsrv/iis/svcs/ftp/server`), the MSASN1 BER decoder (`enduser/msasn1`), ntdll DOS-path conversion (`base/ntdll/curdir.c`), kernel IO-manager buffering spot checks (`base/ntos/io`, `drivers/*` `METHOD_NEITHER` handlers), and the previously filed audit notes in `agents/audit/` (re-verified against the code, not taken on trust).
- **Validation environment:** Linux x86-64 sandbox; GCC 13 with `-fsanitize=address`; the project cannot be built here (no Windows DDK/build environment, `razzle`/`build.exe` and the Microsoft toolchain are unavailable). Validation used *extracted* functions copied verbatim from the audited revision into standalone harnesses; no project source file was modified.
- **Validation caveat:** the harnesses are *extractions*, not the compiled product. The formatting core was re-created with the same statement order, buffer size and `vsprintf` semantics, but the sandbox uses glibc rather than the Windows CRT (notably, `%ws` was translated to `%ls`, and locale-dependent wide-to-narrow conversion differs), and stack layout, `/GS` cookies, stack-growth direction and allocator behaviour are not those of the shipped binaries. Every finding below therefore separates "demonstrated in the extraction" from "inferred for the product".
- **Audit limitations:** No Windows build, no live instance, no RPC/SMB peer, no fuzzing at scale. The finder does not have the original Microsoft binaries, so binary-level confirmation (for example the presence of `/GS` cookies in the shipped `wkssvc.dll`) is inferred from publically documented builds, not from the artifact. Network reachability statements rely on the source plus vendor advisories, not on a live exploit. Coverage is a targeted audit, not exhaustive: see *Coverage, gaps and residual risk*.

## Executive Summary

The audit produced **two confirmed memory-corruption vulnerabilities** and **one unverified latent defect**. Both confirmed findings are already-public vulnerabilities whose fixes post-date this source revision; neither fix is present in the audited code. No new zero-day was established.

| Status | Count | Identifiers |
| --- | --- | --- |
| Confirmed | 2 | NT-AUDIT-001, NT-AUDIT-002 |
| Unverified (latent, reachability not established) | 1 | NT-AUDIT-003 |
| Rejected / deduplicated candidates | 6 | R-01 … R-06 |

- **By priority:** P0 — 2 (NT-AUDIT-001, NT-AUDIT-002); P3 — 1 (NT-AUDIT-003).
- **By novelty/wildness:** W0 (known CVE) — 2; Unresolved — 1.
- **By area:** `rpc` — 1 primary (`networking` secondary); `networking`/`smb` — 1 primary (`rpc` secondary); `networking` — 1 unverified (NT-AUDIT-003).

**Confirmed findings in one line each**

1. **NT-AUDIT-001** — `NetpDebugDumpRoutine` formats attacker-supplied RPC strings with `vsprintf` into `char OutputBuffer[2049]` with no output limit (`ds/netapi/netlib/debug.c:492-554`). The Workstation service calls this logging path unconditionally and logs the client-supplied `AlternateName` before validating it (`ds/netapi/svcdlls/wkssvc/server/join.c:1385-1390`), so a long `NetrAddAlternateComputerName` argument produces a stack buffer overflow in a LocalSystem service. This matches **CVE-2003-0812 / MS03-049**; the MS03-049 update (Q828035, `wkssvc.dll` 5.1.2600.1301 for SP1) is not reflected in this source.
2. **NT-AUDIT-002** — `BackUpPath` in `ds/netapi/netlib/canon.c:531-560` walks backwards from `ptr - 1` and tests the lower bound with pointer *equality* after dereferencing, so a crafted path (`\c\..\..\A…`) makes `ConvertPathMacros` read below `pathBuffer` and then copy attacker data to the address the runaway scan produced (`canon.c:503`, `:556`). The path is reachable through the `srvsvc` RPC method `NetprPathCanonicalize`, and the caller can suppress even the `NetpwPathType` sanity check by supplying a non-zero `PathType`. This matches **CVE-2008-4250 / MS08-067**; the October 2008 fix is not reflected in this source.

**Rejected candidates** include the related MS06-040 overflow (the prefix/path length checks are present in this tree), an unsigned-short truncation in `WsCreateTreeConnectName` (bounded upstream), an FTP `strcpy` (guarded by in-place sanitisation and a `MAX_PATH`-bounded lookup), and four findings from previous audit notes in `agents/audit/` that are already fixed at this revision. These are recorded in the appendix so the count is not inflated.

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
| **Confirmed** | The defect, the vulnerable path and the security consequence are demonstrated by source analysis and, where feasible, by executed validation. |
| **Provisional** | Source evidence indicates a defect, but one or more link in the reachability or impact chain is not demonstrated. |
| **Unverified** | A real defect exists in the source, but the security-relevant reachability across a trust boundary is not established. |
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

## Coverage, Gaps and Residual Risk

**What was traced end to end**

- `srvsvc` path canonicalisation: IDL → server routine → `NetpwPathCanonicalize` → `CanonicalizePathName` → `ConvertPathCharacters`/`ConvertDeviceName`/`ConvertPathMacros`/`BackUpPath` (NT-AUDIT-002).
- `wkssvc` alternate-computer-name flow: IDL → `NetrAddAlternateComputerName`/`NetrRemoveAlternateComputerName` → `NetpManageAltComputerName` → `NetSetuppOpenLog`/`NetpLog` → `NetpLogPrintHelper` → `NetpDebugDumpRoutine` (NT-AUDIT-001).
- NetLib build composition (`ds/netapi/netlib/sources`), service link lines (`wkssvc/server/sources`, `srvsvc/server/sources`) to establish which binaries contain the code.
- Prior audit notes in `agents/audit/` (A01–A15) were re-read and each code-affecting claim re-checked against the current source (see R-04).

**Areas inspected without a confirmed finding**

- `ds/netapi/netlib/namecan.c`, `nameval.c`, `pathtype.c`, `pathcmp.c`: bounds logic and caller contracts reviewed; no additional reachable defect found (the `USHORT` cast of `OutbufLen` in `namecan.c` truncates only in a way that makes `RtlUpcaseUnicodeString` fail closed).
- `ds/netapi/svcdlls/wkssvc/server/useaddel.c`, `useutil.c`: `NetrUseAdd` UNC-name handling reviewed; `WsUseCheckRemote` bounds the name through `I_NetPathCanonicalize` with `MAX_PATH` before the tree-connect name is built (R-02).
- `inetsrv/iis/svcs/ftp/server` (`engine.cxx`, `userdb.cxx`, `virtual.cxx`): command parsing, `RNFR`/`RNTO`, virtual-root mapping and path sanitisation reviewed; the `strcpy` into `RenameSourceBuffer` is guarded by in-place sanitisation and a `MAX_PATH`-bounded lookup (R-03).
- `enduser/msasn1/berdecod.c`: BER length handling spot-checked (allocations derived from declared lengths, `len - 1` underflow paths return allocation failure); no defect was demonstrated — this is a partial review of a large decoder, not a clearance.
- `base/ntdll/curdir.c` (`RtlDosPathNameToNtPathName_U*`): explicit `UNICODE_STRING_MAX_BYTES` bound present.
- `METHOD_NEITHER` handlers in `drivers/wdm/input/*`, `net/sockets/winsock2/wsp/afdsys/*`, `base/fs/*`: spot-checked for probe/validation; the sampled handlers (`hidclass/dispatch.c`, `afdsys/misc.c`, `afdsys/dispatch.c`) use `ProbeForRead`/`ProbeForWrite` or copy through the I/O manager.

**Gaps (explicitly not covered)**

- No build: the tree cannot be compiled here, so no compiler diagnostics, no `/GS` layout, no link-time confirmation beyond the `sources` files.
- No live Windows system, SMB peer or RPC endpoint: no end-to-end reproduction, no fuzzing, no WER/verifier data.
- The RPC stub generators (MIDL output) are not checked in; the IDL plus the hand-written server routines were used as the contract. Where a generated stub performs additional range checks, the wire limits could be tighter than assumed for NT-AUDIT-001 (this does not affect the conclusion, because several kilobytes are required and `[string]` parameters carry far more).
- Large areas were not audited at all: kernel memory manager and object manager internals, the NTFS/FastFAT parsers, `srv.sys` SMB request parsing, NDR marshalling in `com/rpc`, LSASS authentication protocols (`ds/security`), the IIS HTTP request parser, Terminal Services, and drivers outside the sampled directories. Absence of findings in those areas is not evidence of absence of vulnerabilities.
- Only public, non-destructive validation was performed; no exploit was developed.

## Rejected and Deduplicated Candidates (Appendix)

- **R-01 — MS06-040 / CVE-2006-3439 overflow in `NetpwPathCanonicalize`: not reproducible in this revision.** Public analyses describe a pre-patch `CanonicalizePathName` that concatenated prefix and path with an unchecked `wcscat` into a fixed stack buffer. In this tree the concatenations are guarded: `prefixLen > MAX_PATH*2` (`canon.c:174`), `pathLen + prefixLen > MAX_PATH*2 - 1` (`canon.c:192`), and the destination is `MAX_PATH*2 + 1` elements (`canon.c:166`), i.e. the path form is bounded before `STRCAT`. No input was found that makes the prefix/path concatenation exceed the array through the in-tree callers. The residual off-by-one that does exist is recorded as NT-AUDIT-003 (unverified, not reachable). *Deduplicated* with NT-AUDIT-002 only at the function level; they are distinct root causes.
- **R-02 — `USHORT` truncation in `WsCreateTreeConnectName` (`ds/netapi/svcdlls/wkssvc/server/useutil.c:689-707`, `:765`): unreachable.** The `MaximumLength` computation casts `UncNameLength * sizeof(WCHAR)` to `USHORT`, which would wrap for names of 32768+ characters and undersize the allocation before `wcscat(TreeConnectStr->Buffer, &UncName[1])`. However, `NetrUseAdd` obtains `UncNameLength` only after `WsUseCheckRemote` canonicalises the UNC name into a caller buffer of `MAX_PATH * sizeof(TCHAR)` (`useutil.c:1716-1724`) and sets `*UncNameLength = STRLEN(UncName)` (`:1761`), so the length is at most 259. The truncation is a latent robustness issue in a function that other callers could misuse, not a reachable vulnerability in this revision.
- **R-03 — `strcpy(pUserData->RenameSourceBuffer, pszArg)` in FTP `RNFR` (`inetsrv/iis/svcs/ftp/server/engine.cxx:2095-2105`): not reachable as an overflow.** `RenameSourceBuffer` is `MAX_PATH` bytes, and the copy looks dangerous because FTP command lines may be up to `MAX_COMMAND_LENGTH` (512, `cons.hxx:29`). But `VirtualCanonicalize` calls `VirtualpSanitizePath(pszArg)` in place (`userdb.cxx:3620`) before `LookupVirtualRoot`, which copies the virtual path plus the metadata root into a `STACK_STR(..., MAX_PATH)` and fails when it does not fit (`userdb.cxx:4925-4990`); the subsequent `strcpy` therefore only sees a sanitised string shorter than `MAX_PATH`. Kept as a note: the guard is indirect and would disappear if the sanitisation or the root-path bound changed.
- **R-04 — Findings from earlier repository audit notes (`agents/audit/01`–`15`): already fixed at this revision, re-verified.** (a) `net/rras/ras/ppp/common/clsa.c:691` now clears the full `USER_SESSION_KEY` with `memset(pUserKey, '\0', sizeof(*pUserKey))`; (b) `base/subsys/sm/server/sminit.c:1537` initialises `ValueData = NULL` before the branding query, so the error path is defined; (c) `admin/wmi/wbem/xmltransport/client/helpersources/httpconnectionagent.cpp:601-608` now tests `if(bResult == FALSE)`, frees the buffer and sets `E_FAIL`; (d) `termsrv/license/tlserver/server/license.cpp` uses `if(bSuccess == FALSE)` at the previously reported sites. None of these is reported as a current finding. The remaining `agents/audit` items are build/resource/documentation defects outside this audit's scope.
- **R-05 — Duplicate logging overflows in other services: deduplicated under NT-AUDIT-001.** The same unbounded-`vsprintf` pattern appears in the SAM log (`ds/ds/src/sam/server/log.c:338`), the NetLogon log (`ds/netapi/svcdlls/logonsrv/server/nlp.c:1637-1787`), the Browser trace log (`ds/netapi/svcdlls/browser/server/brutil.c:318`), the DNS server file log (`ds/dns/server/server/file.c:477`, `log.c:637`) and the Directory Service log (`ds/ds/src/common/dscommon/filelog.c:141`). Whether each is reachable with attacker-sized data by default was not established (several require debug logging to be enabled); they are recorded as the same defect family, and only the Workstation-service instance is claimed as confirmed.
- **R-06 — `RtlDosPathNameToNtPathName_U` (MS03-007 class) spot check: no defect identified.** `base/ntdll/curdir.c:2500-2540` computes the length with `wcslen`, rejects `Length + sizeof(WCHAR) >= UNICODE_STRING_MAX_BYTES`, and stores the length in a `UNICODE_STRING`; the DOS-to-NT conversion was not audited further. This is a spot check, not a clearance of the WebDAV path.

## Validation Artifacts

All harnesses live outside the repository (`/home/user/audit-work/`), were compiled with `gcc -g -O0 -fsanitize=address`, and contain only functions copied from the audited revision plus libc equivalents of the Windows primitives (`STRCPY`→`wcscpy`, `vsprintf`, `TCHAR`→`wchar_t`). No project file was edited.

| Artifact | Purpose | Observed result |
| --- | --- | --- |
| `log_harness.c` | `NetpDebugDumpRoutine` formatting core with `char[2049]` | 2000-char name: no overflow; 3000-char name: `stack-buffer-overflow`, WRITE of size 3019 |
| `canon_stack.c` | `ConvertPathMacros` with a real `TCHAR[521]` stack array | `\a\..\x` → ASan `stack-buffer-underflow` READ in `BackUpPath` (call from `ConvertPathMacros`) |
| `canon_groomed.c` | `ConvertPathMacros` with a modelled stack neighbourhood | `\c\..\..\AAAA` → six TCHARs written before the array, first at offset −6, NUL at −1 |
| `canon_prefix.c` | `CanonicalizePathName` prefix concatenation, exact buffer size | prefix 519 → clean; prefix 520 without trailing separator → ASan `stack-buffer-overflow` WRITE at the `wcscat`; prefix 520 with trailing separator → clean |

Method notes: the harnesses replace `RtlIsDosDeviceName_U`/`RtlDetermineDosPathNameType_U` outcomes with "not a device name" (documented behaviour for these inputs), stub the unrelated `ConvertPathCharacters`/`ConvertDeviceName`/`ConvertPathMacros` in `canon_prefix.c`, and model "groomable stack memory" explicitly in `canon_groomed.c` rather than relying on the host's real stack layout. Results are stated as observed; no claim is made that a full product build or boot was validated.

## References

Primary sources consulted during the audit (accessed 2026-10-31):

1. Microsoft Security Bulletin MS03-049, "Buffer Overrun in the Workstation Service Could Allow Code Execution (828749)", 11 Nov 2003 — `https://learn.microsoft.com/en-us/security-updates/securitybulletins/2003/ms03-049`
2. NVD, CVE-2003-0812 — `https://nvd.nist.gov/vuln/detail/CVE-2003-0812`
3. CERT/CC CA-2003-28, "Buffer Overflow in Windows Workstation Service" — `https://www.kb.cert.org/vuls/id/567620`
4. Microsoft Security Bulletin MS08-067, "Vulnerability in Server Service Could Allow Remote Code Execution (958644)", 23 Oct 2008 — `https://learn.microsoft.com/en-us/security-updates/securitybulletins/2008/ms08-067`
5. NVD, CVE-2008-4250 — `https://nvd.nist.gov/vuln/detail/CVE-2008-4250`
6. Microsoft Security Bulletin MS06-040 / CVE-2006-3439 — `https://learn.microsoft.com/en-us/security-updates/securitybulletins/2006/ms06-040`, `https://nvd.nist.gov/vuln/detail/CVE-2006-3439`
7. Microsoft, "The Inside Story Behind MS08-067" (post-mortem describing the `netapi32!ConvertPathMacros` stack overflow and the out-of-bounds `0x5C` scan) — `https://github.com/JohnLaTwC/Shared/blob/master/The%20Inside%20Story%20Behind%20MS08-067.md`
8. Public technical analyses of MS08-067 (`NetpwPathCanonicalize` → `CanonicalizePathName` → `RemoveLegacyFolder`) and of MS06-040, used only to establish historical relationships, not as proof of the defects.
9. Repository documentation used for scoping: `README.md`, `AGENTS.md`, `agents/architecture.md`, `agents/README.md`, `agents/audit/README.md`, `agents/audit/manifest.json`, `PLAN.md` (SEC-004, TST-024, REL-023).
10. Source references in this bulletin are pinned to commit `04fc55266a9e4cf6259a83864713441eb0016ade`; see the per-finding reference lists.

**Statement of scope of claims.** This bulletin reports two confirmed, already-public vulnerabilities present in the audited revision, one latent defect whose reachability is not established, and six rejected or deduplicated candidates. It does not claim that all vulnerabilities in this code base have been found, and it does not claim that any finding listed here is a previously undisclosed vulnerability.
