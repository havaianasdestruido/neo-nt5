# NEONT 5.1 — Source-Level Security Audit Bulletin

**Document type:** Source audit bulletin (responsible-disclosure draft, internal review pending)
**Audit ID:** NT-SA-2026-10 / NEONT-2600
**Report date:** 2026-10-31
**Auditor:** Arena.ai agent (senior security researcher mode), autonomous source review
**Target repository:** `havaianasdestruido/neo-nt5` (NEONT 5.1, Windows NT 5.1 / XP–Server 2003-family source tree)
**Audited revision:** `04fc55266a9e4cf6259a83864713441eb0016ade` (branch `arena/c6a758e7-neo-nt5`, shallow history — single commit)
**Version banner:** `public/sdk/inc/ntverp.h:31-45` → `VER_PRODUCTMAJORVERSION 5`, `VER_PRODUCTMINORVERSION 1`, `VER_PRODUCTBUILD 2600`, `VER_PRODUCTBUILD_QFE 1106`
**Document scope:** documentation only. This audit changed no source, build file, workflow, or configuration. The only artifact added by this work is this file.
**Classification of content:** technical vulnerability analysis for defenders. Contains no exploit code, no payloads, no weaponized steps, and no credentials, keys, or product identifiers found elsewhere in the repository.

---

## 1. Executive summary

This bulletin reports the results of a source-level security audit of the NEONT 5.1 tree at commit `04fc5526`. The audit was **manual and targeted**: the tree contains 277,943 tracked files and roughly 8.2 GB of content, which cannot be exhaustively reviewed by one auditor in one pass. Review therefore concentrated on memory-safety-critical kernel and server components that historically produced remotely reachable defects: the x86 VDM (virtual DOS machine) subsystem, kernel trap/BIOS-transition assembly, the SMB server (`srv.sys`), the Terminal Services device driver (`termdd.sys`), the TCP/IP receive path, NetBIOS-over-TCP, the SNMP agent parser, the AFD (Winsock kernel) driver, and the NetAPI path canonicalisation library.

**Result: four findings are reported; none is confirmed to be a zero-day.** Three are source-code manifestations of vulnerability classes that already have public advisories and CVE identifiers; one is a new candidate that could not be closed because the code that supplies its attacker-controlled input is not present in this repository. The two most serious findings are old, published issues that are *still present in this source snapshot* — an important result in itself, because it means the snapshot does not carry the hardening that shipped in the corresponding security updates.

| ID | Title | Status | Priority | Wildness | Area |
|----|-------|--------|----------|----------|------|
| NT-AUDIT-001 | VDM context forgery: user-controlled `SegCs`/`Eip`/`Esi` reach the kernel stack pivot in `Ki386BiosCallReturnAddress` (x86) | Confirmed (source) | **P1** | W1 | kernel/vdm |
| NT-AUDIT-002 | `VdmpInitialize` maps physical page 0 `PAGE_READWRITE` and copies to virtual address 0 — zero-page manipulation race | Confirmed (source) | P2 | W0 | kernel/vdm |
| NT-AUDIT-003 | `SrvSmbWriteRaw` accepts a `DataOffset` beyond the received SMB; immediate data pointer is used as the source of a file write | Confirmed (source) | P2 | W1 | fs/srv (SMB server) |
| NT-AUDIT-004 | `termdd` channel rebinding relies on `ASSERT`-only invariants; client-supplied names can rebind existing channels and `VirtualClass` is not range-checked | Provisional | P2 | W2 | drivers/termsrv (RDP) |

**Headline technical result (NT-AUDIT-001).** `NtVdmControl(VdmStartExecution, …)` is reachable by any local process in this source, because the access gate at `base/ntos/vdm/i386/vdmentry.c:145-150` explicitly exempts `VdmStartExecution`. `VdmpStartExecution` then loads a *user-writable* context (`VDM_TIB.VdmContext`) into the current thread's kernel trap frame. The only content check is a bit-mask "valid" flag (`FRAME_EDITED`), which a crafted `SegCs` of `0x000B` passes. The forged frame causes the kernel's own `iret` to fault; `KiTrap0D` recognises the resulting error code and trapped instruction as its *legitimate* V86-return idiom and jumps to `Ki386BiosCallReturnAddress`, which then performs `mov esp, [TsEsi]`, four `pop`s and a `ret` using the attacker's `TsEsi`. That is a full ring-0 stack pivot. The mechanism — and the exact "magic" check that permits it — is the one described by Tavis Ormandy as CVE-2010-0232 / MS10-015; the audit nevertheless reports it because the source shows **no privilege gate anywhere in the path** (`VdmAllowed` does not occur anywhere in the source trees examined), i.e. this snapshot appears to have weaker preconditions than the binaries the advisory describes. It is classified W1 ("variant / distinct manifestation of a known issue") rather than W0 because the audit cannot prove the snapshot differs from the patched binary.

**Headline technical result (NT-AUDIT-003).** The `WRITE_RAW` (0x1D) SMB handler validates the immediate-data length against the receive buffer with a signed/unsigned comparison:

```c
if ( ( immediateLength > writeLength ) ||
     ( immediateLength > ( WorkContext->ResponseBuffer->DataLength -
                                SmbGetUshort(&request->DataOffset) ) ) )   /* smbraw.c:967-970 */
```

`immediateLength` is `ULONG`; `(DataLength - DataOffset)` is `int`. If `DataOffset` exceeds the received length, the right-hand side is negative and is converted to a huge unsigned value, so the test passes. The unchecked offset is later used as `(PCHAR)RequestHeader + SmbGetUshort(&request->DataOffset)` (`smbraw.c:1246-1247`), which becomes the source buffer of a `FastIoWrite`, and (if fast I/O is unavailable) of an MDL write (`smbraw.c:1519-1545`). The neighbouring `Write`, `WriteAndX` and `Transact` handlers were hardened with a clamped `MIN(…)` idiom (`smbrdwrt.c:2385-2389`, `2851-2858`, `smbtrans.c:1707-1711`); the `WRITE_RAW` path was not. That asymmetry is the signature of an incomplete fix for the historical "SMB validation" defect family (CVE-2008-4114 / MS09-001), hence W1.

**Ruled out.** Several historically fruitful candidates were reviewed and found sound in this revision: NetAPI32 path canonicalisation (`MS08-067` class), SMB transaction offset/count validation, `SrvValidateSmb`, the OS/2 EA list conversion, the SNMP agent's BER parser, AFD non-blocking/`POLL` validation, TCP/IP received-option parsing, NetBIOS datagram proxying, and the VDM BOP fast-path dispatcher. Section 6 records each rejection with the evidence that closed it.

### 1.1 Priority summary

- **P0:** 0
- **P1:** 1 (NT-AUDIT-001)
- **P2:** 3 (NT-AUDIT-002, -003, -004)
- **P3:** 0

### 1.2 Status summary

- **Confirmed:** 3 (NT-AUDIT-001, -002, -003) — the defect is present in the audited source by direct inspection; each is mapped to a published issue or, for -003, to a published defect family.
- **Provisional:** 1 (NT-AUDIT-004) — defect visible in `termdd.sys`; exploitability depends on a component absent from this tree.
- **Unverified:** 3 candidates in Section 7 (need runtime/hardware to close).
- **Rejected:** 9 candidates in Section 6.

### 1.3 What this bulletin does **not** claim

- No CVE identifier has been requested or assigned for NT-AUDIT-004. Local identifiers (`NT-AUDIT-00n`) are used throughout; published CVE IDs appear only where they name *prior art*.
- No finding was validated by running the affected code. There is no Windows build environment, no target hardware, and no instrumentation in the audit environment (Section 9). Everything below is static source analysis plus small, non-destructive arithmetic reproductions of the predicates under test.
- The repository is a **source snapshot**, not a specific shipping binary. A finding "present at commit X" does not prove that any released product was built from exactly this source, nor that no out-of-band hotfix existed.
- Absence of a finding in a component is not evidence of absence of vulnerabilities in that component.

---

## 2. Methodology

### 2.1 Approach

1. **Reconnaissance.** Enumerated the tree (`git ls-files`, extension census, per-directory line counts) to identify security-relevant components and their historical defect density. Read `README.md`, `AGENTS.md`, and the tracked-directory catalogue under `agents/catalog/` to establish scope rules (source only; generated `.htm/.html` artefacts excluded from review).
2. **Hypothesis-driven review.** For each component, the audit started from the *published* vulnerability history of the corresponding Windows component and asked a single question: *does this revision contain the input validation that the public fix added?* This is a high-yield method for a snapshot that mixes pre- and post-fix code.
3. **Data-flow tracing.** Every candidate was traced from the protocol/user entry point to the memory access: entry function → field extraction (`SmbGetUshort`, `ProbeForRead`, IOCTL buffers, TEB/TIB reads) → validation (or absence) → dereference/copy/indexing. Findings are only reported where the trace closes at source level.
4. **Cross-handler differential.** Where a validation idiom exists in sibling handlers, the audit compared implementations (e.g. the `MIN(…)` clamp in `Write`/`WriteAndX`/`Transact` versus its absence in `WriteRaw`). Divergence between siblings is strong evidence of an incomplete fix.
5. **Novelty check.** Each confirmed defect was searched against public vulnerability databases and advisories before classification; the outcome determines the W-level and is recorded per finding (Section 5) and in Section 8.

### 2.2 Evidence standards

A finding may only reach **Confirmed** if all of the following hold:

- the exact file, function and **line range** are quoted from the audited commit;
- every field in the vulnerable expression is traced to a boundary the attacker can influence (user-mode syscall, network packet, or IOCTL), or the finding states explicitly which boundary is assumed;
- the consequence is described in terms of the code that consumes the value, not in terms of an assumed exploitation outcome;
- the audit states what it did **not** prove.

**Provisional** means the defect is visible and self-consistent in the audited source but at least one link in the attack chain lies outside this repository (missing driver, missing protocol stack, missing build glue), so exploitability could not be established.

**Rejected** means the candidate was examined and closed: either a validator exists that the initial grep missed, or the consequence is not a security boundary violation. Rejections are documented so future audits do not repeat the work.

### 2.3 Tooling and environment

- **Environment:** Linux sandbox, `gcc` and `python3` only. No Windows SDK/WDK, no cross-compiler for this tree, no debugger, no hypervisor.
- **No static-analysis engines were available** (`cppcheck`, `clang`, `CodeQL`, `semgrep`, `flawfinder` all absent), so the review is manual. Pattern sweeps were done with `grep`/`sed`/`nl` over scoped subtrees (whole-tree greps over 278k files take 5–10 s each and were avoided).
- **Non-destructive validation only.** Where a defect reduces to an arithmetic or bit-mask predicate, the predicate was extracted into a ~20-line standalone C program in `/tmp` (never in the repository) and executed, to confirm the *predicate's* behaviour independently of the surrounding kernel. These programs contain no payloads, no addresses, and no exploitation logic; they demonstrate that a check admits input it should reject. Two such harnesses were used (Section 5.1 and 5.3). They are a correctness check on the auditor's reading, **not** a reproduction of the vulnerability.
- No network, protocol, or binary fuzzing was performed. No live target was touched.

### 2.4 Coverage

| Component | Path | Depth |
|---|---|---|
| VDM subsystem (x86) | `base/ntos/vdm/i386/`, `base/ntos/vdm/vdm.c` | Deep — entry, init, context switch, trap gates, BOP dispatch, printer stubs |
| Kernel x86 trap/BIOS assembly | `base/ntos/ke/i386/{trap,biosa}.asm` | Deep — `KiTrap0D` special case, `Ki386BiosCallReturnAddress` |
| SMB server | `base/fs/srv/` (`smbraw`, `smbrdwrt`, `smbtrans`, `smbsupp`, `smbproc`, `smbmpx`, `pipe`, `smbopen`, `smbadmin`, `smblock`, `ea`, `fsd*`, `network`, `blkwork`) | Deep on raw read/write, trans, validation, EA; survey elsewhere |
| Terminal Services driver | `termsrv/drivers/termdd/{channel,stack}.c`, `icap.h` | Deep on channel lifecycle; survey on IOCTL surface |
| TCP/IP receive | `net/tcpip/driver/ipv4/iprcv.c`, `ipdef.h` | Deep on option parsing |
| NetBIOS over TCP/IP | `net/netbt/sys/{inbound,hndlrs,parse}.c` | Targeted (datagram proxying, name-scope length) |
| SNMP agent | `net/snmp/…/snmppdus.c` | Targeted (BER type/length/OID parsing) |
| AFD (Winsock kernel) | `net/sockets/winsock2/wsp/afdsys/{poll,afddata}.c` | Targeted (IOCTL dispatch, poll validation) |
| NetAPI32 | `ds/netapi/netlib/canon.c` | Targeted (`MS08-067` class) |
| Kernel I/O manager | `base/ntos/io/iomgr/iosubs.c` | Targeted (`IoIs32bitProcess` semantics) |

Roughly 40 files were read in depth; the remainder of the tree (IIS services, `windows/`, `shell/`, `printscan/`, `com/rpc/`, `multimedia/`, `net/dhcp`, `net/wins`, …) was surveyed for structure only and is **out of scope** for this bulletin.

### 2.5 Taxonomies used

**Priority (impact if the defect were fixed nowhere):**

| Level | Meaning |
|---|---|
| P0 | Remotely reachable without authentication, leads to code execution in a privileged context; wormable. |
| P1 | Local privilege escalation to kernel, or authenticated remote code execution, with low complexity. |
| P2 | Remote/local denial of service, information disclosure across a security boundary, or corruption requiring significant preconditions, a race, or a race-like reliability cost. |
| P3 | Defence-in-depth, hardening, or robustness issue with no demonstrated boundary violation. |

**Wildness (relationship to public knowledge):**

| Level | Meaning |
|---|---|
| W0 | Directly maps to a published CVE/advisory, including its published mechanism. Not new; reported because it is present in this revision. |
| W1 | Same defect family/root cause as published work, but a distinct code path or distinct manifestation not covered by the published CVE. |
| W2 | No matching published issue identified by this audit; plausibly novel, unproven. |
| W3 | Novel and independently reproduced/validated dynamically by this audit. |

**Status:** `Confirmed` / `Provisional` / `Unverified` / `Rejected` as defined in §2.2.

**Area taxonomy:** `kernel/vdm`, `kernel/ke-asm`, `kernel/io`, `fs/srv`, `fs/ntfs`, `drivers/termsrv`, `net/tcpip`, `net/netbt`, `net/afd`, `net/snmp`, `ds/netapi`.

---

## 3. Threat model and assumptions

- **Local attacker:** an unprivileged interactive user on the audited system (any process context, no administrator rights).
- **Remote authenticated attacker:** a user who can negotiate an SMB session and connect to a share (guest or low-privilege account is sufficient for NT-AUDIT-003).
- **Remote unauthenticated attacker:** reachable only through pre-session protocol handling. No P0 finding was identified; the audit found no defect in the pre-authentication parse paths it reviewed (Section 6).
- **Trust boundaries considered:** user mode → kernel (syscall/IOCTL/TEB/TIB inputs); network → kernel (SMB, TCP/IP options, NetBIOS datagrams, SNMP); kernel → kernel (values cached in shared structures, e.g. `BUFFER.DataLength`).
- **Assumptions:** default service configuration of the era; SMB server enabled on a file-share host (`NT-AUDIT-003`); NTVDM-capable x86 build (`NT-AUDIT-001`, `-002`); Terminal Services enabled (`NT-AUDIT-004`). x64 builds are not affected by the VDM findings — `base/ntos/vdm/vdm.c:45-80` compiles a stub returning `STATUS_NOT_IMPLEMENTED` for every service except `VdmQueryDir` on non-x86.

---

## 4. Findings index

| ID | Status | Priority | Wildness | Component | Attacker model | Consequence class |
|----|--------|----------|----------|-----------|----------------|-------------------|
| NT-AUDIT-001 | Confirmed | P1 | W1 | ntoskrnl (x86 VDM + KiTrap0D + biosa.asm) | local, unprivileged | ring-0 execution / kernel stack control |
| NT-AUDIT-002 | Confirmed | P2 | W0 | ntoskrnl (VdmpInitialize) | local, unprivileged | physical page 0 manipulation (race) |
| NT-AUDIT-003 | Confirmed | P2 | W1 | srv.sys (SMB `WRITE_RAW`) | remote, authenticated | OOB read of kernel pool written into a file |
| NT-AUDIT-004 | Provisional | P2 | W2 | termdd.sys (RDP channel binding) | remote (pre-session assumed) | channel-table corruption / dangling pointer |

---

## 5. Findings

### NT-AUDIT-001 — VDM context forgery reaches the ring-0 stack pivot in `Ki386BiosCallReturnAddress`

| Field | Value |
|---|---|
| **Status** | Confirmed (source-level) |
| **Priority** | P1 |
| **Wildness** | W1 |
| **Area** | `kernel/vdm` (+ `kernel/ke-asm`) |
| **Components** | `ntoskrnl.exe` (x86): VDM subsystem, `KiTrap0D`, `Ki386BiosCallReturnAddress` |
| **Affected revisions** | Source at `04fc55266a9e4cf6259a83864713441eb0016ade`; x86 only |
| **CVE mapping** | Same mechanism as CVE-2010-0232 (MS10-015). Not claimed as new — see §5.1.6 |
| **Confidence** | High for the code path; **not** dynamically validated |

#### 5.1.1 Summary

`NtVdmControl` publishes two services to user mode without any privilege gate: `VdmInitialize` and `VdmStartExecution` are exempted from the process-state check at `vdmentry.c:145-150`. `VdmStartExecution` copies a context supplied by the caller — via the *user-writable* VDM TIB — into the kernel trap frame of the calling thread, validating only a bit-mask "edited" flag in the `SegCs` slot. Because `0x000B` (`KGDT_R0_CODE|RPL_MASK`) satisfies that mask, an attacker can install a frame whose `CS` is a ring-0 code selector carrying RPL 3, whose `EIP` is the kernel symbol `Ki386BiosCallReturnAddress`, and whose `ESI` is an arbitrary kernel pointer. The subsequent `iret` faults, and `KiTrap0D`'s special-case handler **authenticates the frame by exactly those two values** — the CS/EIP pair it expects from its own internal V86-return idiom — then jumps to `Ki386BiosCallReturnAddress`, which sets `ESP` from `TsEsi` and returns. The result is a kernel stack pivot under attacker control, i.e. kernel-mode code execution for any local process.

#### 5.1.2 Locations

| File | Function | Lines | Relevance |
|---|---|---|---|
| `base/ntos/vdm/i386/vdmentry.c` | `NtVdmControl` | 107-158 | syscall entry; gate at 145-150; dispatch to `VdmpStartExecution` at 157-158 |
| `base/ntos/vdm/i386/vdmtib.c` | `VdmpGetVdmTib` | 29-73 | reads `NtCurrentTeb()->Vdm` (54), probes it for write (60), checks only `Size` (62) |
| `base/ntos/vdm/i386/strtexec.c` | `VdmpStartExecution` | 40-215 | copies `VdmTib->VdmContext` (178); "valid" test (180-188); swap (194-196) |
| `base/ntos/vdm/i386/vdmmisc.asm` | `VdmSwapContexts` | 90-291 | saves trap frame (112-183); loads forged context (185-235); `or ax,3` (194-195) |
| `base/ntos/inc/i386.h` | — | 1556 | `FRAME_EDITED 0xfff8` |
| `base/ntos/ke/i386/trap.asm` | `KiTrap0D` | 4702-4731 | the "magic" iret/CS/EIP special case |
| `base/ntos/ke/i386/biosa.asm` | `Ki386BiosCallReturnAddress` | 220-286 | stack pivot (241-255), pops and `ret` (282-286) |
| `base/ntos/vdm/vdm.c` | `NtVdmControl` (non-x86) | 45-80 | architecture scope: stub on non-x86 |

#### 5.1.3 Vulnerable code shape

Gate and dispatch (`vdmentry.c:138-158`):

```c
    // Make sure the caller is ntvdm.  Except ...
    //     VdmStartExecution - video driver uses it to support int 10
    //     VdmInitialize     - the vdm state is not fully initialized ...
    if ((Service != VdmInitialize) &&
        (Service != VdmStartExecution) &&
        (PsGetCurrentProcess()->VdmObjects == NULL)) {
        return STATUS_ACCESS_DENIED;
    }
    ...
        if (Service == VdmStartExecution) {
            Status = VdmpStartExecution();
```

Context acceptance (`strtexec.c:176-196`):

```c
        VdmContext = VdmTib->VdmContext;          /* fully user-controlled */
        if (!(VdmContext.SegCs & FRAME_EDITED)) { /* only check performed  */
            KeLowerIrql(OldIrql);
            return(STATUS_INVALID_SYSTEM_SERVICE);
        }
        VdmSwapContexts (TrapFrame, &VdmTib->MonitorContext, &VdmContext);
```

Copy into the trap frame (`vdmmisc.asm:185-221`, abridged):

```asm
        mov     edi,esi                       ; edi -> TrapFrame
        mov     esi,[ebp + 10h]               ; esi -> &VdmContext
        mov     eax,[esi].CsSegCs
        mov     ebx,[esi].CsSegSs
        ...
        or      ax, 3                         ; RPL 3 only
        or      bx, 3
        mov     [edi].TsSegCs,eax
        mov     [edi].TsHardwareSegSs,ebx
        ...
        mov     eax,[esi].CsEsp
        mov     [edi].TsHardwareEsp,eax
        mov     eax,[esi].CsEip
        mov     [edi].TsEip,eax
        ...
        mov     eax,[esi].CsEFlags
        and     eax,EFLAGS_USER_SANITIZE      ; 0x3e0dd7 - TF (0x100) survives
        or      eax,EFLAGS_INTERRUPT_MASK
```

Authentication of the resulting fault (`trap.asm:4702-4731`):

```asm
        cmp     al, IRET_OP                   ; is the trapped instruction an iret?
        jne     Kt0d002
        lea     edx, [ebp]+TsHardwareEsp      ; (edx)->trapped iret frame
        mov     ax, [ebp]+TsErrCode
        and     ax, NOT RPL_MASK
        mov     cx, word ptr [edx]+4          ; cs selector of the iret target
        and     cx, NOT RPL_MASK
        cmp     cx, ax                        ; does it match the error code?
        jne     short Kt0d0008
        mov     eax, OFFSET FLAT:Ki386BiosCallReturnAddress
        cmp     eax, [edx]                    ; trapped eip == that symbol?
        jne     short Kt0d0005
        mov     eax, [edx]+4
        cmp     ax, KGDT_R0_CODE OR RPL_MASK  ; trapped cs == 8|3?
        jne     short Kt0d0005
        jmp     Ki386BiosCallReturnAddress     ; with interrupts off
```

Stack pivot (`biosa.asm:220-255`, `280-286`):

```asm
Ki386BiosCallReturnAddress:
        mov     eax, fs:PcSelfPcr
        mov     edi, [ebp].TsEsi              ; attacker-controlled
        mov     edi, [edi]                    ; *(attacker ptr)
        ...
        mov     esp, [ebp].TsEsi              ; ESP := attacker value
        add     esp, 4
        ...
        sti
        pop     edi
        pop     esi
        pop     ebx
        pop     ebp
        ret                                   ; return address also attacker-chosen
```

The in-file comment at `biosa.asm:224-231` documents this idiom verbatim: *"the 'iret' instruction of the EXIT_ALL will be trapped to our GP fault handler which recognizes this and transfers control back to here"*. The handler's recognition predicate is precisely the two user-settable values (`CS`, `EIP`); the third input it consumes (`ESI`) is never authenticated.

#### 5.1.4 Root cause

A three-part trust failure:

1. **Entry:** the process-state gate exempts the one service that performs the context swap, and `VdmObjects`/`VdmAllowed` is not consulted for it. `VdmAllowed` does not occur anywhere in this tree (`grep -rn VdmAllowed` over `base/`, `public/`, `internal/`, `tools/` → no matches; the only related identifier is the unrelated `KeI386VdmIoplAllowed`, `base/ntos/inc/i386.h:2962`), and `SeTcbPrivilege` is not checked in `base/ntos/vdm` or `base/ntos/ke`.
2. **Content:** `VdmpStartExecution` treats a *user-writable* structure (`TEB->Vdm`, probed only with `ProbeForWrite`) as trusted kernel input. The single content test is `SegCs & FRAME_EDITED`, a mask of `0xfff8`; any selector with one of those bits set passes, and `0x000B` does.
3. **Consumption:** `KiTrap0D`'s V86-return special case authenticates a faulting frame with two values the attacker supplies, and `Ki386BiosCallReturnAddress` derives `ESP` and the final `ret` target from a third (`TsEsi`) that no validator ever ranges.

The security invariant that is missing is: *only frames produced by `Ki386SetUpAndExitToV86Code` may take the `Ki386BiosCallReturnAddress` path*, and that can only be established by validating the saved stack pointer, not by matching constants the attacker can copy.

#### 5.1.5 Impact

Local privilege escalation to ring 0 for any process on an x86 build: the attacker controls the kernel stack pointer and the return address, and execution continues with interrupts enabled. This is the strongest impact class in this bulletin (P1). No memory corruption needs to be groomed; the primitive is the transition itself.

#### 5.1.6 Evidence, validation, and novelty check

- **Static trace (primary evidence):** every step above was read at the cited lines. The chain is closed entirely inside this tree, in shipped-code directories (`base/ntos/…`), with no missing component.
- **Arithmetic/bit-mask reproduction:** the two predicates that gate the chain were extracted into a standalone program (`/tmp`, not committed): `(0x000B & 0xfff8) != 0` and `((0x000B & ~3) | 3) == (KGDT_R0_CODE | RPL_MASK)`. Both evaluate true; the compiler additionally warns on the second comparison's operand types. This confirms the auditor's reading of the masks, and nothing more.
- **Not validated:** no execution. The audit did not verify the exact fault vector produced by an `iret` to an RPL-3 ring-0 selector with TF set on the specific CPU families of the era, nor the resulting trap-frame contents at run time. The `#GP` error-code equality in `trap.asm:4706-4711` is architectural for a DPL violation on the target selector; the audit relies on that architecture, not on measurement.
- **Prior art (W1):** CVE-2010-0232 / MS10-015 (Tavis Ormandy, "The 2010 Windows NT VDM privilege escalation") describes the same `NtVdmControl`/`VdmStartExecution`/`KiTrap0D` mechanism and states the attack requires `SeTcbPrivilege` or an NTVDM process to reach the service. This source contains **no such gate**, so the snapshot is at least as exposed as the published description and possibly more so. Related earlier work: eEye's 2004 VDM `#UD`/BOP advisory (kernel trusting a DOS transfer address) and the 2007 zero-page race (NT-AUDIT-002).
- **Why W1 and not W0:** the audit cannot demonstrate that this revision's *binary* differs from the MS10-015-patched build. The source shows the defect and shows no gate; the classification records both facts.

#### 5.1.7 Remediation

- Require the same privilege/process-state predicate for `VdmStartExecution` as for other services, or move the service behind an interface only NTVDM can reach.
- Treat `VDM_TIB` as untrusted input in the kernel: range-check `SegCs` against the GDT selectors that are legal for a VDM context (in particular reject ring-0 selectors and any selector that is not a V86/ring-3 code segment), and check `SegSs`/`Esp` for consistency.
- In `KiTrap0D`, authenticate the V86-return idiom with a value the attacker cannot supply — e.g. validate that `TsEsi` lies within the current thread's kernel stack and equals the expected saved stack pointer — not with `CS`/`EIP` constants.
- Do not use `FRAME_EDITED` alone as a validity flag for a user-writable structure; replace it with a kernel-side handle/registration.

#### 5.1.8 Detection ideas (non-destructive)

- Audit `NtVdmControl` calls from processes whose image is not `ntvdm.exe`, or from any process without an active VDM, and alert on `VdmStartExecution`.
- Alert on `KiTrap0D` paths reached from a `#GP` whose iret frame `CS` is not `KGDT_R3_CODE|RPL_MASK` and `EIP == Ki386BiosCallReturnAddress` while the current thread has no in-progress BIOS call.

#### 5.1.9 Limitations

The exact CPU-level behaviour of the faulting `iret` was not measured; the audit did not inspect the SSP/PCI or any platform-specific coupling; the audit could not confirm whether the build process compiles this file into the shipping image for the affected SKUs (`README.md` lists SKUs but the build was not run).

---

### NT-AUDIT-002 — `VdmpInitialize` maps physical page 0 `PAGE_READWRITE` and copies it to virtual address 0 (zero-page manipulation race)

| Field | Value |
|---|---|
| **Status** | Confirmed (source-level) |
| **Priority** | P2 |
| **Wildness** | W0 |
| **Area** | `kernel/vdm` |
| **Components** | `ntoskrnl.exe` (x86): `VdmpInitialize` |
| **Affected revisions** | Source at `04fc5526`; x86 only |
| **CVE mapping** | CVE-2007-1206 (MS07-022), zero-page race in the NT VDM |
| **Confidence** | High for the mapping and write-access; medium for end-to-end impact (chain not reproduced) |

#### 5.2.1 Summary

`VdmpInitialize` opens `\Device\PhysicalMemory` with `SECTION_ALL_ACCESS`, maps the first physical page into the process at a kernel-chosen address with `PAGE_READWRITE`, and then copies that page to user virtual address 0. Between the map and the unmap, the physical page is writable through a mapping the caller does not need to know about; and the copy target is virtual address 0, i.e. whatever mapping the process has placed there. The same service opens this window for any local process, because `VdmInitialize` is one of the two gated exemptions (see NT-AUDIT-001).

#### 5.2.2 Locations

| File | Function | Lines | Relevance |
|---|---|---|---|
| `base/ntos/vdm/i386/vdmentry.c` | `NtVdmControl` | 165-169 | `VdmInitialize` service, probe + copy of the init data |
| `base/ntos/vdm/i386/vdminit.c` | `VdmpInitialize` | 18-136 | `VdmObjects` single-init check (73); section open (77-87); `PAGE_READWRITE` map (106-115); copy to VA 0 (124-129); unmap (131) |

#### 5.2.3 Vulnerable code shape

```c
    RtlInitUnicodeString (&SectionName, L"\\Device\\PhysicalMemory");
    InitializeObjectAttributes (&ObjectAttributes, &SectionName,
                                OBJ_CASE_INSENSITIVE|OBJ_KERNEL_HANDLE, NULL, NULL);
    Status = ZwOpenSection (&SectionHandle, SECTION_ALL_ACCESS, &ObjectAttributes);
    ...
    BaseAddress = 0; destination = 0; ViewSize = 0x1000;
    Status = ZwMapViewOfSection (SectionHandle, NtCurrentProcess(), &BaseAddress,
                                 0, ViewSize, &ViewBase, &ViewSize,
                                 ViewUnmap, 0, PAGE_READWRITE);
    ...
    try { RtlCopyMemory (destination, BaseAddress, ViewSize); }   /* VA 0 */
    ...
    Status = ZwUnmapViewOfSection (NtCurrentProcess(), BaseAddress);
```

(`vdminit.c:77-131`.)

#### 5.2.4 Root cause

The routine needs to *read* physical page 0 to initialise the VDM's real-mode interrupt vector table; it asks for `SECTION_ALL_ACCESS`/`PAGE_READWRITE`, which is broader than the operation requires, and it exposes the mapping as a normal user view (`NtCurrentProcess()`), so the write permission is usable by any thread in the calling process during the window. A concurrent thread can `NtAllocateVirtualMemory`/`VirtualAlloc` at address 0 in the same process at the right moment and substitute its own page for the BIOS/IVT page the kernel is about to copy into the VDM's address space.

#### 5.2.5 Impact

Manipulation of physical page 0 content for the duration of a VDM initialisation, and control of what the kernel treats as the real-mode IVT/BIOS data area for the new VDM. CVE-2007-1206's published analysis describes the escalation chain (a mapped, writable zero page used by code that trusts IVT/BIOS contents — including hibernation/BSOD display paths). This audit did **not** reproduce that chain; it confirms the two preconditions in source — write access to the page and a user-chosen VA 0 mapping — and reports the defect at P2 rather than P1 for that reason.

#### 5.2.6 Evidence, validation, and novelty check

- Direct reading of `vdminit.c:73-136`; `PAGE_READWRITE` at line 115 is unambiguous, as is the `destination = 0` copy at 101/125.
- `NtCurrentTeb()->Vdm = NULL` at line 66 and the `Process->VdmObjects` check at 73 mean the service is one-shot per process, which affects repeatability but not the single window.
- **Prior art (W0):** CVE-2007-1206, MS07-022 ("Vulnerability in Windows VDM could allow elevation of privilege"), with the public eEye/Derek Soeder write-up describing the `VdmpInitialize` mapping of `\Device\PhysicalMemory` as `PAGE_READWRITE` and the race on the page. The same public analysis also attributes a `VdmAllowed` privilege gate to the shim; that gate is absent from this source, which is recorded as an observation in NT-AUDIT-001 rather than as a separate claim here.
- **Not validated:** the race was not run; the hibernation/BSOD chain was not examined.

#### 5.2.7 Remediation

- Map the physical page `PAGE_READONLY` and copy it into a kernel buffer; never expose it through the process address space.
- Do not copy to virtual address 0. Build the VDM's initial IVT in kernel memory and map that page into the VDM context with the desired permissions.
- Gate `VdmInitialize` behind the same privilege check used for the remaining VDM services.

#### 5.2.8 Limitations

Impact statements beyond "the page is writable and VA 0 is user-selectable" are inherited from the public advisory, not from this audit's testing. The audit did not check whether the build's linker/loader or the VDM's section layout would defeat the chain on a given SKU.

---

### NT-AUDIT-003 — `SrvSmbWriteRaw` accepts a `DataOffset` beyond the received SMB, and the immediate-data pointer is used as a write source

| Field | Value |
|---|---|
| **Status** | Confirmed (source-level) |
| **Priority** | P2 |
| **Wildness** | W1 |
| **Area** | `fs/srv` (SMB server, `srv.sys`) |
| **Components** | `srv.sys` — `SMB_COM_WRITE_RAW` (0x1D) and `SMB_COM_NT_WRITE_RAW` |
| **Affected revisions** | Source at `04fc5526` |
| **CVE mapping** | Defect family of CVE-2008-4114 (MS09-001); the `WRITE_RAW` path itself is **not** covered by that CVE |
| **Confidence** | High for the missing/ineffective validation and the resulting read address; medium for the exploitation outcome (adjacent pool contents not measured) |

#### 5.3.1 Summary

`SrvSmbWriteRaw` validates the immediate-data length with a comparison whose right-hand side becomes negative — hence huge when converted to unsigned — whenever `DataOffset` exceeds the received length. The unchecked offset is then used to compute the source address of the write. On the fast path that address goes straight into `lfcb->FastIoWrite`; on the slow path the same value feeds an MDL write. The effect is that a client can make the server write kernel memory from an address of its choosing (up to 64 KB beyond the start of the request buffer) into a file it can read back — an out-of-bounds read across a security boundary with a file-backed exfiltration channel.

#### 5.3.2 Locations

| File | Function | Lines | Relevance |
|---|---|---|---|
| `base/fs/srv/smbraw.c` | `SrvSmbWriteRaw` | 882-1390 | handler; dialect gate (940-947); **validation (958-974)**; immediate fast write (1239-1292); source address (1246-1247); remaining-write success path (1298-1304) |
| `base/fs/srv/smbraw.c` | `SrvSmbWriteRaw` (MDL path) | 1437-1545 | copy-write vs MDL decision (1437-1462); `SrvBuildReadOrWriteRequest` with MDL (1519-1545) |
| `base/fs/srv/smbproc.c` | `SrvRestartReceive` | 399-400 | received length stored in `RequestBuffer->DataLength` |
| `base/fs/srv/smbproc.c` | response path | 102-105 | `ResponseBuffer->DataLength` overwritten with *response* length |
| `base/fs/srv/network.c` | SMB dispatch setup | 1907 | `ResponseBuffer = RequestBuffer` (same object in the normal flow) |
| `base/fs/srv/smbsupp.c` | `SrvValidateSmb` | 6097-6110 | pre-dispatch validation: ByteCount bounded by `RequestBuffer->DataLength`; **no `DataOffset` check** |
| `base/fs/srv/smbrdwrt.c` | `SrvWrite` / `SrvSmbWriteAndX` | 2385-2389, 2851-2858 | sibling handlers use the clamped `MIN(…)` idiom |
| `base/fs/srv/smbtrans.c` | `SrvSmbTransaction` | 1707-1711 | sibling path validates `dataOffset + dataCount` against the received length |
| `public/internal/base/inc/smb.h` | `REQ_WRITE_RAW` | 3121-3141 | `DataLength`/`DataOffset` are `USHORT`; `DataOffset` is "offset from header start to data" |

#### 5.3.3 Vulnerable code shape

```c
    immediateLength = SmbGetUshort( &request->DataLength );   /* ULONG   */
    writeLength     = SmbGetUshort( &request->Count );        /* ULONG   */

    if ( ( immediateLength > writeLength ) ||
         ( immediateLength > ( WorkContext->ResponseBuffer->DataLength -   /* CLONG - int */
                                    SmbGetUshort(&request->DataOffset) ) )     /* USHORT  */
       ) {
        status = STATUS_INVALID_SMB;
        goto error_exit_no_rfcb;
    }
```

(`smbraw.c:958-974`.) Later, with no further validation of the offset:

```c
    if ( (shareType != ShareTypePipe) ||
         (SmbGetUshort( &request->Count ) == (USHORT)immediateLength) ) {
        if ( lfcb->FastIoWrite != NULL ) {
            writeAddress = (PCHAR)WorkContext->RequestHeader +
                                    SmbGetUshort( &request->DataOffset );   /* 1246-1247 */
            immediateWriteDone = lfcb->FastIoWrite( lfcb->FileObject, &offset,
                                    immediateLength, TRUE, key, writeAddress, ... );
```

Both branches consume the same `writeAddress`: the fast path passes it as the data pointer, the MDL path hands the prepared MDL chain to `IoCallDriver` (`smbraw.c:1519-1545`).

#### 5.3.4 Root cause

Two independent issues combine:

1. **Signed/unsigned comparison.** `BUFFER.DataLength` is a signed 32-bit count; `DataOffset` is an unsigned 16-bit field; the subtraction is performed in `int` and the result is compared against a `ULONG`. `immediateLength > (int)negative` is always false after the usual arithmetic conversions, so the check cannot reject any `DataOffset > DataLength`. The compiler emits the diagnostic (`-Wsign-compare`) when this expression is isolated.
2. **Wrong object and missing range check.** The bound uses `ResponseBuffer->DataLength`, which in this code base is overwritten with the outgoing response length on every send (`smbproc.c:102-105`) before the buffer is reused for the next receive — a stale value in any case where the response buffer is not the request buffer. Even where the two are the same object (`network.c:1907`), the *intent* of the check is to ensure the data lies inside the received SMB, and the correct primitive is `MIN`-clamped arithmetic against `RequestBuffer->DataLength`, as used by the three sibling handlers. Additionally, `DataOffset` is never checked at the dispatch layer (`smbsupp.c:6097-6110` validates `ByteCount` and total length only), and — unlike `Transact` — `WRITE_RAW` never validates `DataOffset + DataLength ≤ received`.

The differential with the sibling handlers is the strongest evidence that this is an *incomplete* fix rather than a deliberate design: `Write` (`smbrdwrt.c:2385-2389`), `WriteAndX` (`2851-2858`, `2969-2971`) and `Transact` (`smbtrans.c:1707-1711`) all clamp or validate the same class of field.

#### 5.3.5 Attack surface and preconditions

- **Remote, authenticated.** A session and a tree connect are required before the handler runs; the dialect gate at `smbraw.c:940-947` rejects only `SmbDialect >= SmbDialectMsNet103`, i.e. MS-NET 1.03 and the two PC dialects — every NT/LAN Manager dialect proceeds (`public/internal/base/inc/smbtypes.h:140-158`).
- `immediateLength != 0`, and for a disk share `Count == immediateLength` (`smbraw.c:1239-1242`).
- A file handle opened for write (`SrvVerifyFidForRawWrite`, ~`smbraw.c:985`) and a file system providing `FastIoWrite`; when fast I/O is unavailable the slow path still builds the write from the same address.
- The attacker does not control the *content* read from the out-of-bounds address, but chooses the address and can repeat with different offsets and reread the file.

#### 5.3.6 Impact

- **Primary:** a kernel-pool out-of-bounds read whose contents are written into a file the attacker can open and read — a coherent information-disclosure primitive across the network/kernel boundary (P2).
- **Secondary:** the same unchecked value can feed the MDL path, so a sufficiently unlucky address produces a fault in the file system's copy loop; historically this class produced bug-check denial of service (the consequence MS09-001 addressed for `WRITE_ANDX`).
- **Not claimed:** no reliable code execution. The audit did not measure pool adjacency, and the immediate write only stores what is *at* the address; there is no attacker-controlled write to kernel memory.

#### 5.3.7 Evidence and validation

- Full trace at the cited lines; `RequestHeader` is the start of the received SMB (`network.c:1909-1911`), and `DataOffset` is defined by the protocol as an offset from that header (`smb.h:3135`).
- The bound's arithmetic was reproduced standalone (`/tmp`, not committed) with Windows integer widths (`ULONG`/`CLONG` = 32-bit, `USHORT` = 16-bit). With a 160-byte received SMB, `DataOffset = 0xFF00`, `DataLength = 100`, `Count = 100`, the guard accepts the packet and the computed source is `RequestHeader + 0xFF00`, i.e. 65,280 bytes beyond the received data; with `DataOffset = 0x00A0` (exactly the received length) it correctly rejects. The compiler flags the sign mismatch in the isolation program. This validates the predicate, not the kernel behaviour.
- `SrvValidateSmb` was read in full (`smbsupp.c:5901-6285`): the table entry for `SMB_COM_WRITE_RAW` is `-1` (`srvdata.c:666`), i.e. the dispatch layer deliberately skips the word-count comparison (`smbsupp.c:6097-6099`), `ByteCount` is bounded by `RequestBuffer->DataLength` (`6103-6110`), and `DataOffset` is never examined.
- **Prior art (W1):** CVE-2008-4114 / MS09-001 ("SMB validation denial of service") covers an inconsistency between `DataOffset` and packet size in `srv.sys` write handling — the published fix is the clamped `MIN(…)` idiom that this tree contains in `Write`/`WriteAndX`/`Transact` but **not** in `WriteRaw`. CVE-2006-1315 (uninitialised SMB buffer information disclosure) is the nearest disclosure analogue. Linux kernel SMB client fixes from 2026 (unvalidated `DataOffset` in raw write/read paths) are client-side analogues and are cited only as evidence that the class is real, not as prior art for this server.

#### 5.3.8 Remediation

- Mirror the sibling idiom and reject explicitly:

  ```c
  offset = SmbGetUshort(&request->DataOffset);
  if (offset > receivedLength || immediateLength > receivedLength - offset) reject;
  ```
  using `RequestBuffer->DataLength` (the received length), not `ResponseBuffer->DataLength`.
- Add a dispatch-layer rule in `SrvValidateSmb` for `WRITE_RAW`/`NT_WRITE_RAW`: `DataOffset + ByteCount` (and `DataOffset + DataLength`) must not exceed the received length.
- Prefer unsigned arithmetic with an explicit pre-check (`offset > len`) over subtraction, and treat `BUFFER.DataLength` as an unsigned length by construction.

#### 5.3.9 Limitations

The audit did not run a server or capture packets; reachability is established from source and protocol documentation, not from a live session. Pool adjacency and the exact information disclosed depend on the running build and were not measured. `BUFFER.DataLength` reuse semantics were established by reading `smbproc.c`/`network.c`/`blkwork.c`, not by instrumentation.

---

### NT-AUDIT-004 — `termdd` channel rebinding relies on `ASSERT`-only invariants; client-supplied names can rebind existing channels and `VirtualClass` is not range-checked

| Field | Value |
|---|---|
| **Status** | Provisional |
| **Priority** | P2 |
| **Wildness** | W2 |
| **Area** | `drivers/termsrv` (Remote Desktop / Terminal Services, `termdd.sys`) |
| **Components** | `termdd.sys` — ICA channel table management |
| **Affected revisions** | Source at `04fc5526`; any build enabling Terminal Services |
| **CVE mapping** | Same component and the same binding logic that public analyses of CVE-2019-0708 describe; no direct CVE match established by this audit |
| **Confidence** | Medium — defect is visible; the attacker-controlled input path lies outside this repository |

#### 5.4.1 Summary

`IcaBindVirtualChannels` takes the virtual-channel list returned by the protocol stack driver and, for each entry, looks the channel up **by name**; if a channel object with that name already exists, it *rebinds* it to the client-supplied `VirtualClass`. `_IcaBindChannel` overwrites `pChannel->VirtualClass` and installs the object at the new table index, with the only uniqueness guarantee being an `ASSERT` — compiled out in free builds. `_IcaFreeChannel` clears only the slot matching the object's *current* class, so an object that has been rebound leaves a stale pointer in its previous slot: a textbook use-after-free precondition. Separately, `VirtualClass` is an unchecked 16-bit value used directly as an index into `pConnect->pChannel[CHANNEL_COUNT + VirtualClass]`, where `VIRTUAL_MAXIMUM` is 32.

#### 5.4.2 Locations

| File | Function | Lines | Relevance |
|---|---|---|---|
| `termsrv/drivers/termdd/channel.c` | `IcaBindVirtualChannels` | 1872-1940 | name-keyed lookup (1904, 1922-1923); rebind of an existing object (1928-1933) |
| `termsrv/drivers/termdd/channel.c` | `_IcaBindChannel` | 2284-2310 | `ASSERT` uniqueness (2306); unchecked index write (2307) |
| `termsrv/drivers/termdd/channel.c` | `_IcaFreeChannel` | 2157-2187 | clears only the current slot (2179-2181) |
| `termsrv/drivers/termdd/channel.c` | `_IcaRegisterVcBind` | 2190-2228 | stores the stack driver's `VirtualClass` (2215) |
| `termsrv/drivers/termdd/channel.c` | `IcaCreateChannel` | 197-300 | validates class range and NUL-termination only (232-242) |
| `termsrv/drivers/termdd/icap.h` | `_ICA_CONNECTION` | 84 | `pChannel[CHANNEL_COUNT+VIRTUAL_MAXIMUM]` |
| `public/internal/termsrv/inc/hydrix.h` | — | 156, 161-165 | `VIRTUAL_MAXIMUM 32`; `SD_VCBIND{ VirtualName; USHORT VirtualClass; ULONG Flags; }` |

#### 5.4.3 Vulnerable code shape

```c
    VirtualClass = _IcaFindVcBind(pConnect, pSdVcBind->VirtualName, &Flags);
    if (VirtualClass == UNBOUND_CHANNEL) {
        Status = _IcaRegisterVcBind(pConnect, pSdVcBind->VirtualName,
                                    pSdVcBind->VirtualClass, pSdVcBind->Flags);
    }
    pChannel = IcaFindChannelByName(pConnect, Channel_Virtual, pSdVcBind->VirtualName);
    if (pChannel != NULL) {                       /* name already bound */
        IcaLockChannel(pChannel);
        _IcaBindChannel(pChannel, Channel_Virtual,
                        pSdVcBind->VirtualClass,      /* client-supplied class */
                        pSdVcBind->Flags);
```

```c
    pChannel->ChannelClass = ChannelClass;
    pChannel->VirtualClass = VirtualClass;             /* overwrite first */
    ...
    if (VirtualClass != UNBOUND_CHANNEL) {
        ASSERT(pChannel->pConnect->pChannel[ChannelClass + VirtualClass] == NULL);
        pChannel->pConnect->pChannel[ChannelClass + VirtualClass] = pChannel;
    }
```

and on free, only the current slot is cleared:

```c
    if (pChannel->VirtualClass != UNBOUND_CHANNEL) {
        pChannel->pConnect->pChannel[pChannel->ChannelClass + pChannel->VirtualClass] = NULL;
    }
```

#### 5.4.4 Root cause

Three assertions are being used as invariants:

1. The slot being populated is empty (`channel.c:2306`) — violated by any rebind to a different class, including a colliding client-supplied name; in free builds the check does not exist, so the write proceeds and the old slot keeps a pointer to the object.
2. `VirtualClass` is a valid index — never asserted or validated before `pChannel[...]` is indexed (`channel.c:2307`), and the value originates in the stack driver's `SD_VCBIND` structure.
3. A channel's class never changes after creation — contradicted by the rebind path itself, and by `_IcaFreeChannel` assuming the class is still the one used at insertion.

#### 5.4.5 Impact if the input path is confirmed

- Rebinding an existing (including a server-created static) channel to a different class leaves a dangling table entry; a later close frees the object while another slot still references it → use-after-free of a channel object in kernel pool, with further references from IOCTL paths.
- An out-of-range `VirtualClass` would turn `channel.c:2307` into a kernel-pool pointer write (out of bounds of `_ICA_CONNECTION`). This is the more severe possibility and the reason the finding is retained despite being provisional.

#### 5.4.6 Why this is Provisional, and what would close it

- The values entering `IcaBindVirtualChannels` come from `IOCTL_ICA_VIRTUAL_QUERY_BINDINGS` handled by the protocol/stack driver (`MCSIcaVirtualQueryBindings`, declared at `termsrv/inc/mcskernl.h:48` and `termsrv/inc/mcsioctl.h:297-298`). **The MCS/T.120 provider is not present in this repository** — the audit verified that only declarations and IOCTL codes exist here. Therefore the audit cannot determine whether the channel names are client-controlled, whether `VirtualClass` is server-assigned (bounded) or copied from client data, or whether any upper layer already de-duplicates names.
- Closing steps: (a) locate the provider in the full product source and trace `SD_VCBIND` population from the RDP Client Network Data; (b) confirm the class assignment logic; (c) run a two-session test with duplicate/virtual channel names on a build with Driver Verifier (pool tracking, special pool) — this is the non-destructive validation the audit could not perform.

#### 5.4.7 Prior art and novelty check

- CVE-2019-0708 (BlueKeep) is a pre-authentication use-after-free in Remote Desktop Services attributed in public analyses to channel-name handling in this driver; the code shape here — name-keyed rebinding with `ASSERT`-only uniqueness — matches the pre-fix logic such analyses describe. The audit did **not** obtain a primary source that pins CVE-2019-0708 to these exact lines, and this tree may be far older than the affected 2019 builds, so the mapping is stated as *class-level*, not as an identification.
- No public advisory was found for the missing `VirtualClass` range check. That sub-issue is recorded as W2/unproven.
- **No CVE has been requested for NT-AUDIT-004.** Do not cite a CVE for it.

#### 5.4.8 Remediation

- Replace the `ASSERT` with a runtime check: if the target slot is occupied by a different object, reject the binding (or explicitly close out the old object's slot) instead of overwriting.
- Validate `VirtualClass` (`< VIRTUAL_MAXIMUM`) at the `SD_VCBIND` boundary in `_IcaRegisterVcBind` and again in `_IcaBindChannel`.
- Do not permit a name that matches an already-bound channel to be rebound with a different class; make class immutable after creation, or add a generation/epoch to detect stale references.

#### 5.4.9 Limitations

Everything about reachability is inherited from an absent component. The audit did not examine `stack.c`'s IOCTL dispatch beyond confirming that it forwards to the provider, nor any product-specific glue in `termsrv/`.

---

## 6. Rejected candidates

Rejections are recorded with the evidence that closed each one. "Rejected" here means *this audit found no defect*, not *this code is secure*.

| # | Candidate | Location | Why rejected |
|---|---|---|---|
| R1 | NetAPI32 path canonicalisation (`MS08-067` class) | `ds/netapi/netlib/canon.c:165-210` | Every concatenation is length-checked before it happens (`prefixLen > MAX_PATH*2`, 174-176; `pathLen + prefixLen > MAX_PATH*2-1`, 191-194) into a fixed `MAX_PATH*2+1` stack buffer; device/macro conversion (including the `..` rules) fails closed (199-203) and the caller's buffer size is checked before copying out (205-210). No path length reaches an unbounded copy. |
| R2 | SMB `Transact`/`Trans2` offset+count validation (`MS08-067`-era family) | `base/fs/srv/smbtrans.c:1694-1728` | `smbLength = RequestBuffer->DataLength` (1705) and the four-clause test at 1707-1711 rejects `setupOffset+setupCount`, `parameterOffset+parameterCount`, `dataOffset+dataCount` beyond the received length, plus count>total inversions. Arithmetic cannot overflow (all 16-bit operands promoted to `int`). |
| R3 | `SrvValidateSmb` ByteCount handling | `base/fs/srv/smbsupp.c:6097-6110` | `ByteCount` is bounded by `RequestBuffer->DataLength` and by the work context's available space; the word-count table is consulted (negative entries exempt). (The `DataOffset` gap found here is reported under NT-AUDIT-003.) |
| R4 | SMB named-pipe transceive (`FSCTL_PIPE_INTERNAL_TRANSCEIVE` Type3 input) | `base/fs/srv/pipe.c:1650-1660` | The function is only called on the single-buffer path that the `SrvSmbTransaction` validator above has already bounded (`pipe.c` is reached from `smbtrans.c:1793-1797` after 1707-1711). |
| R5 | OS/2 EA list conversion (`MS11-020` class) | `base/fs/srv/ea.c:261-496`; callers `smbopen.c:1152-1185`, `smbdir.c:424-433` | The documented caller obligation (`ea.c:276-279`, "ensure `cbList` will fit within the buffer") **is** honoured: both callers reject `cbList <= sizeof(FEALIST)` or `cbList > transaction->DataCount` before conversion (`smbopen.c:1164-1174`, `smbdir.c:424-426`), and `DataCount` has already been bounded against the received SMB by `smbtrans.c:1707-1711`. Inside the conversion, each entry is re-validated against `lastValidLocation` (`ea.c:446-480`) and a corrupt first entry yields `STATUS_OS2_EA_LIST_INCONSISTENT` (321-324). The 16-bit `cbList` re-write at 477 affects the *response* length only. |
| R6 | SNMP agent BER parser | `net/snmp/…/snmppdus.c` (~1390-2060) | `ParseType`/`ParseLength` over-read at most one byte on a malformed PDU; no subsequent copy uses the mis-parsed length, and no write primitive exists. Robustness only. |
| R7 | AFD `IOCTL_AFD_POLL` validation | `net/sockets/winsock2/wsp/afdsys/poll.c` (`AfdPoll` 291, `AfdPoll32` 1010-1200) | Input buffer length is checked against the 32/64-bit structure sizes; poll-handle count is bounded; no unchecked user pointer survives the probe. |
| R8 | TCP/IP received-option parser | `net/tcpip/driver/ipv4/iprcv.c` (`ParseRcvdOptions`, 239-300) | The loop cannot spin: `OptLength >= 3` is required up front (247-252), and every continuation advances `i` by at least `MIN_RT_PTR-1 = 3` / `MIN_TS_PTR-1 = 4` (`ipdef.h:52-53`), so zero/one/two-byte options are rejected (259-276). The remaining over-read is bounded to one byte of the next option for a trailing malformed entry (`Length = Options[i+1]` at 259 is read before the range check); the value is not used as a length for any copy. Recorded as robustness, not a boundary violation. |
| R9 | NetBIOS datagram proxy | `net/netbt/sys/inbound.c` (`ProxyDoDgramDist`) and `hndlrs.c` | Header lengths are re-derived from the datagram and bounded before use; the scope-length underflow requires `NbtConfig.ScopeLength == 0`, but the default is 1 (`net/netbt/sys/init.c`) and the configuration path does not accept 0 from an unprivileged caller. |

Additional non-findings worth recording: the VDM BOP fast-path dispatcher (`VdmDispatchBop`, `base/ntos/vdm/i386/vdmuserrefs.c:210-330`) probes the user EIP and accepts only BOP numbers `0x42`/`0x43`, forwarding to `NTFastDOSIO`; no unvalidated kernel transfer was found. `VdmpPrinterDirectIoOpen` (`base/ntos/vdm/i386/vdmprint.c:510`) returns success without performing I/O — a stub, not a boundary violation.

---

## 7. Unverified candidates (need runtime / missing components)

| # | Candidate | Why it could not be closed | What would close it |
|---|---|---|---|
| U1 | `IoIs32bitProcess` NULL-IRP semantics in a 32-bit AFD query-handle path (`base/ntos/io/iomgr/iosubs.c:13814`, `public/sdk/inc/io.h:5215`) | The audit could not construct a caller in-tree that passes `Irp == NULL` and depends on the 32-bit answer; semantics are defensive-only without such a caller. | Enumerate all `IoIs32bitProcess` callers in the full product source; instrument a build. |
| U2 | VDM `#UD`/BOP kernel-transfer validation (the 2004 eEye class) | `VdmEndExecution` and the BOP handler force/assume ring-3 return (`vdmuserrefs.c`), which *should* make the historical transfer-address abuse unreachable; proving it needs a live NTVDM. | Dynamic test with Driver Verifier on a VDM-capable build. |
| U3 | `termdd` `SD_VCBIND` provenance (NT-AUDIT-004's missing link) | The MCS/T.120 provider is not in this repository (declarations only: `termsrv/inc/mcsioctl.h:297-298`, `mcskernl.h:48`). | Obtain the provider source; trace Client Network Data → `SD_VCBIND`; two-session test under special pool. |

---

## 8. Cross-cutting observations and recommendations

1. **Snapshot hygiene.** Two published, high-severity fixes (MS10-015's VDM gating; MS07-022's VDM page protection) are absent from this tree, and a third fix (MS09-001's clamped length idiom) is present in three SMB handlers but missing from a fourth. Any product built from this snapshot should be treated as **missing those security updates** until proven otherwise by binary comparison with patched builds.
2. **Assertions are not validation.** NT-AUDIT-004 exists because `ASSERT` was used for a security invariant (slot uniqueness) and for bounds (index range). Free builds compile these out. Audit rule: `ASSERT` on data that crosses a trust boundary is a finding, not a check.
3. **Signed/unsigned comparisons over protocol lengths** (NT-AUDIT-003) recur across the tree; the `MIN((CLONG)count, (CLONG)(limit - offset))` idiom used by the hardened handlers is the correct pattern and should be standardised, with a compile-time warning (`-Wsign-compare`, `/W4`) enforced in the build.
4. **User-writable kernel-visible structures** (the VDM TIB) should be treated as attacker input even when a "valid" flag is present; validity flags must be kernel-generated or must not be the sole gate.
5. **Differential review pays.** Comparing sibling protocol handlers found NT-AUDIT-003 in a fraction of the time a full read of `smbraw.c` would have taken; it is recommended as a standing technique for this code base.

---

## 9. Limitations of this audit (read before citing)

- **Static only.** No code was executed, no target was built, no network service was contacted, no fuzzing was performed. Priorities are analyst judgements of *potential* impact, not measured exploitability.
- **Snapshot, not product.** `04fc5526` is one commit of a reconstructed tree (history depth 1). Build artefacts, SKU-specific ifdefs, and post-snapshot hotfixes are outside the audit. Findings describe the source as committed.
- **Scope.** ~40 files in depth across 10 components; 277,943 tracked files exist. Coverage is a targeted sample chosen for historical defect density. IIS, RPC, DHCP, WINS, printing, shell, and multimedia were not reviewed.
- **Missing components.** Two findings depend on code that is not in the repository (NT-AUDIT-004's MCS provider; NT-AUDIT-001's build integration). Conclusions that depend on them are marked Provisional/Unverified.
- **No dynamic verification of the VDM fault semantics.** NT-AUDIT-001's chain relies on architectural `#GP` error-code semantics and on the exact trap-frame layout in `trap.asm`; both were read, neither was measured.
- **Information-disclosure content not measured.** NT-AUDIT-003's practical yield depends on pool layout, which was not measured.
- **No claim of exhaustiveness, no claim of novelty for W0/W1 items.** Only NT-AUDIT-004 is a candidate for new disclosure, and even there the audit could not exclude an unpublicised duplicate.

## 10. Disclosure and handling

This document contains no exploit code and no weaponized procedure; it is written for defenders and reviewers. NT-AUDIT-001 and NT-AUDIT-002 are **published** issues (CVE-2010-0232 / MS10-015 and CVE-2007-1206 / MS07-022) and may be discussed openly as "the snapshot is missing these fixes". NT-AUDIT-003 is a variant of a published defect family (CVE-2008-4114 / MS09-001) in a distinct handler; if it is to be reported as new, the receiving party should be told that the audit could not exclude an unpublicised duplicate. NT-AUDIT-004 should be treated as **embargoed** pending the validation described in §5.4.6; it must not be published with a CVE identifier, a reproduction, or an exploitation claim.

The repository's `README.md` contains build/product identifiers that are unrelated to this audit and are deliberately **not** reproduced here.

---

## 11. Revision and artefact record

| Item | Value |
|---|---|
| Repository | `havaianasdestruido/neo-nt5` |
| Commit audited | `04fc55266a9e4cf6259a83864713441eb0016ade` |
| Branch | `arena/c6a758e7-neo-nt5` |
| Tree state at audit start | clean (`git status --short` empty) |
| History depth | 1 (shallow) — no provenance/blame possible |
| Product banner | 5.1, build 2600, QFE 1106 (`public/sdk/inc/ntverp.h:31-45`) |
| Files tracked | 277,943; tree ≈ 8.2 GB |
| Components in depth | `base/ntos/vdm`, `base/ntos/ke/i386`, `base/fs/srv`, `termsrv/drivers/termdd`, `net/tcpip/driver/ipv4`, `net/netbt/sys`, `net/snmp`, `net/sockets/winsock2/wsp/afdsys`, `ds/netapi/netlib`, `base/ntos/io/iomgr` |
| Validation artefacts | Two ~20-line standalone C programs in `/tmp/audit/` (predicate reproduction only; **not** committed, no repository change) |
| Deliverable change set | this file (`CVE.MD`) only |
| Tooling available | `gcc`, `python3`; no static-analysis engine; no Windows toolchain |

### 11.1 Finding index by file

| File | Findings |
|---|---|
| `base/ntos/vdm/i386/vdmentry.c` | NT-AUDIT-001, NT-AUDIT-002 |
| `base/ntos/vdm/i386/vdmtib.c` | NT-AUDIT-001 |
| `base/ntos/vdm/i386/strtexec.c` | NT-AUDIT-001 |
| `base/ntos/vdm/i386/vdmmisc.asm` | NT-AUDIT-001 |
| `base/ntos/vdm/i386/vdminit.c` | NT-AUDIT-002 |
| `base/ntos/ke/i386/trap.asm` | NT-AUDIT-001 |
| `base/ntos/ke/i386/biosa.asm` | NT-AUDIT-001 |
| `base/fs/srv/smbraw.c` | NT-AUDIT-003 |
| `base/fs/srv/smbsupp.c` | NT-AUDIT-003 |
| `base/fs/srv/srvdata.c` | NT-AUDIT-003 (word-count entry for `WRITE_RAW`) |
| `base/fs/srv/smbrdwrt.c` | NT-AUDIT-003 (contrast) |
| `base/fs/srv/smbtrans.c` | NT-AUDIT-003 (contrast), R2 |
| `termsrv/drivers/termdd/channel.c` | NT-AUDIT-004 |
| `termsrv/drivers/termdd/icap.h` | NT-AUDIT-004 |
| `public/internal/termsrv/inc/hydrix.h` | NT-AUDIT-004 |
| `public/internal/base/inc/smb.h` | NT-AUDIT-003 |

### 11.2 External sources consulted for prior-art classification

- CVE-2010-0232 / MS10-015 — `NtVdmControl`/`KiTrap0D` VDM escalation (Tavis Ormandy; cr0.org paper and mirrored analyses).
- CVE-2007-1206 (MS07-022) and CVE-2007-1973 — VDM zero-page race and NT4 handle race (eEye / Derek Soeder write-up).
- eEye 2004 VDM `#UD`/BOP advisory — historical VDM trust boundary.
- CVE-2008-4114 (MS09-001) and CVE-2006-1315 — `srv.sys` write-path validation and buffer disclosure.
- CVE-2019-0708 (BlueKeep) public analyses — `termdd` channel-binding class (class-level only; no line-level identification).
- 2026 Linux kernel SMB client fixes for unvalidated `DataOffset` — cited only as evidence that the class is real.

No source outside this repository was used as code; all code excerpts above are from the audited commit and carry their file/line references.

---

*End of bulletin. Findings are reproducible by reading the cited line ranges at commit `04fc55266a9e4cf6259a83864713441eb0016ade`. Corrections and additional evidence should be appended as a new revision rather than by amending findings in place.*
