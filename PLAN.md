# PLAN.md — NEONT 5 → 2026 daily-driver roadmap

**Status:** authoritative project-wide implementation checklist (living document)
**Baseline audited:** `arena/9f241727-neo-nt5` @ `c24c9fcb8` (single squashed commit, 277,941 tracked files)
**Audit date:** 2026-10-31
**Scope:** technical roadmap only. Nothing in this file is implemented yet except items explicitly marked `[x]`.

---

## 0. Document control

### 0.1 How to use this file

This is the **single source of truth** for what must be done to turn this source tree into a
usable, secure, stable, modern operating system. It is not a wish list: every task has an ID,
a priority, a status, concrete subtasks, and measurable acceptance criteria.

Rules that keep this document trustworthy:

1. **Never delete an unfinished task.** If a task becomes obsolete, mark it `[-]` with the
   reason and a pointer to what replaced it. Use `[!]` only for *blocked* work. If scope changes, add a new task and cross-link.
2. **Never mark `[x]` without evidence.** A task is done only when its acceptance criteria are
   met *and* the evidence is recorded (commit SHA, test run ID, or artifact path) in the task.
3. **Separate verified fact from intention.** Baseline statements in §2 and §4 are tagged
   `[V]` only if they were reproduced in this checkout. Everything else is `[P]`.
4. **One task per defect/feature.** Do not bundle. Do not split a single fix across five IDs.
5. **Update §13 (change log) every time you touch this file.** Include date, author, and the
   IDs added/changed/closed.

### 0.2 Status legend

| Mark | Meaning |
| --- | --- |
| `[ ]` | Not started / open |
| `[~]` | In progress (owner + branch recorded in the task line) |
| `[x]` | Done, acceptance criteria met, evidence recorded |
| `[!]` | Blocked or infeasible. **Must** carry `blocked-by:` and a pointer to §10 |
| `[-]` | Deliberately dropped; reason recorded, replaced-by pointer if any |

### 0.3 Priority legend

| Pri | Meaning | Rule of thumb |
| --- | --- | --- |
| **P0** | Blocks *any* credible use of the OS. Data loss, non-boot, non-build, or trivially exploitable. | Fix before anyone installs this on real hardware. |
| **P1** | Required for the 2026 baseline: modern network access, modern storage, modern displays, modern apps, safe defaults. | The "daily driver" bar. |
| **P2** | Breadth and comfort: peripheral coverage, UX polish, accessibility, localization, tooling. | Beta-quality bar. |
| **P3** | Research / speculative / high-risk-high-reward. | Only after M5. |

### 0.4 Evidence tags used in the baseline

- `[V]` **Verified** — directly observed in this checkout by file read, grep, or a reproduction
  run whose command is recorded.
- `[P]` **Proposed/inferred** — engineering judgement, not yet proven here.
- `[B]` **Blocked** — external dependency (legal, missing sources, missing hardware, upstream).

### 0.5 Task ID prefixes

`GOV` governance/legal · `ENV` build environment · `BLD` build system · `VER` versioning/branding ·
`BOOT` boot/firmware · `SETUP` installation · `REC` recovery · `KRN` kernel/executive · `MM` memory ·
`PS` processes/scheduler · `IO` I/O, PnP, power · `SEC` security architecture · `CRY` crypto/TLS/PKI ·
`AUTH` identity/authentication · `DRV` driver infrastructure · `GFX` graphics · `AUD` audio · `MMD` media/capture ·
`NET` networking · `FS` filesystems/storage semantics · `API` modern API/ABI layer · `APP` application
compatibility · `SHEL` shell/UX · `ACC` accessibility · `LOC` localization/i18n · `USE` daily-driver
usability · `DX` developer experience · `TST` testing/validation · `REL` release/updates · `MT` maintenance.


### 0.6 Table of contents

| § | Section | What it answers |
| --- | --- | --- |
| 1 | Executive summary | Why this is hard, and the order of attack |
| 2 | Verified baseline | What the tree actually is, with evidence |
| 3 | Feasibility doctrine | The three tiers, and the rule against ABI-changing "cosmetics" |
| 4 | Verified findings register | 48 concrete defects/limitations, with file:line and current status |
| 5 | Constraints and legal posture | What we may not do, and what we are missing |
| 6 | Definition of Done (R1–R10) | The only gates that count as "done" |
| 7 | Roadmap phases 0–15 | The task list itself: 472 tracked items |
| 8 | Sequencing & quick wins | Critical path, parallel streams, ≤2-day wins |
| 9 | Milestones M0–M8 | State-based milestones, not dates |
| 10 | Blocked / infeasible registry | 18 items deliberately not scheduled |
| 11 | Risk register | What can kill the project, and the mitigation |
| 12 | Appendices | Dangling dirs, source map, external specs, release checklist, open questions |
| 13 | Change log & maintenance | How to keep this document honest |

**Task-count snapshot (2026-10-31):** 472 scheduled tasks — 5 `[x]`, 467 `[ ]`; plus 18 `[!]` blocked items tracked centrally in §10 (`BLK-001…BLK-018`). Counts are regenerated with `python3 agents/plan_stats.py --write`.


---


### 0.7 Already-landed fixes (regression tests still outstanding)

These were fixed before this plan was written. They are marked `[x]` only because the code change
is verifiably present; each still needs a permanent regression test (`TST-021`).

- `[x]` **P1 `MT-020`** — F-08: seven transposed `memset(&Overlapped, sizeof(...), 0)` calls in
  `inetsrv/iis/iisrearc/ul/win9x/src/test/**` corrected to the `(ptr, 0, size)` form (PR #15).
  Evidence: `rg -n "memset.*Overlapped" inetsrv/iis/iisrearc/ul/win9x/` shows the corrected order
  at every former defect site. **Test outstanding:** prefilled-struct probe.
- `[x]` **P1 `MT-021`** — F-10: `TLSDbLicenseAddEntry` used `if (bSuccess = FALSE)`, silently
  reporting success on a failed insert; now `if (bSuccess == FALSE)`
  (`termsrv/license/tlserver/server/license.cpp:408`, PR #19). **Test outstanding:** forced
  `InsertRecord` failure must return an error status.
- `[x]` **P1 `MT-022`** — F-12: PPP CHAP cleared only `sizeof(pointer)` bytes of `USER_SESSION_KEY`;
  now `memset(pUserKey, 0, sizeof(*pUserKey))` (`net/rras/ras/ppp/common/clsa.c:690`, PR #4).
  **Test outstanding:** 16-byte zeroing assertion on both 32- and 64-bit builds.

---

## 1. Executive summary

### 1.1 What we are actually working with `[V]`

This is **not** a modern Windows codebase and it is not a clean-room reimplementation. It is a
**Windows XP / Server 2003-era NT 5.1 source tree** (`5.1.2600`, QFE `1106`,
`public/sdk/inc/ntverp.h:26-32`) with:

- ~278k tracked files, ~128k C/C++/asm/header files, 5,246 `.htm*` files.
- A **Razzle + NMAKE + `build.exe`** build system driven by `dirs`/`sources` files.
- A **checked-in VC7-era toolchain** (cl 13.00.9176 x86, 13.00.9269.1 amd64; see `tools/x86`,
  `tools/win64/x86/amd64`).
- A cosmetic rebrand ("NEONT") layered on top by PR #2, which **broke the build** and several
  machine-consumed ABI strings (§4).

Structurally that is good news: kernel, HAL, drivers, networking, crypto, shell, setup and the
build tools themselves (`sdktools/build`, `sdktools/nmake`, `sdktools/rc`, `sdktools/mc`, plus
`com/rpc/midl`) are all present as source. It is *possible* to bootstrap and modernize this tree
from within itself. That is the entire strategy of this plan.

### 1.2 The hard truth about "daily driver in 2026" `[P]`

The gap between NT 5.1 and a 2026 daily driver is not a set of missing features that can be
shimmed in a weekend. It is at least five structural gaps:

1. **No build.** The tree cannot currently produce a bootable image from a clean checkout
   (§2.2; F-01, F-18…F-21, F-41, F-43). Until M0 there is no product to harden.
2. **No modern transport security.** Schannel tops out at TLS 1.0 with RC4/3DES/AES-CBC and no
   ECDHE; Kerberos has no AES etypes. Every HTTPS site, every package manager, every API call
   fails (F-25, F-26).
3. **No modern driver model.** NDIS 5.1, no MSI/MSI-X, no xHCI, no NVMe/AHCI-in-box, no
   Bluetooth, no WDDM. Modern hardware is simply invisible to the kernel
   (F-27, F-35, F-36, F-46, F-47, F-48).
4. **No modern API surface.** The loader rejects any image whose subsystem version exceeds 5.1
   (`base/win32/client/process.c:203-215`), and dozens of routine Win7+ entry points do not exist
   (F-31, F-32, F-33). Almost every current application refuses to start.
5. **No exploit mitigations.** No ASLR, no NX on x86, no SEHOP, no CFG, no integrity levels
   (F-22, F-23, F-24). A machine on a 2026 network is compromised within minutes.

Everything else — a nicer shell, better fonts, Bluetooth audio — is downstream of those five.

### 1.3 Strategy in one paragraph `[P]`

Fix the build first and keep it honest (Phase 0). Then close the *security* and *transport* gaps
because they gate everything networked (Phase 3, Phase 6). In parallel, make the **loader and API
surface** accept and satisfy modern binaries (Phase 5) — the cheapest possible compatibility win
is a loader that stops rejecting 6.0+ images. Only then chase hardware breadth (Phase 4), because
driver work without a reproducible build and a test harness is unverifiable. Shell, accessibility
and localization come last, when the platform underneath can actually run the tools used to
test them.

### 1.4 What this plan explicitly refuses to promise `[P]`

- It does **not** promise that unmodified 2026 Chrome, Teams, or Adobe CC will run. See §10.
- It does **not** promise Secure Boot, TPM 2.0 measured boot, VBS/HVCI, or WDDM 3.x. Those need
  architectural work that exceeds a backport.
- It does **not** promise redistributable install media until the licensing question in
  `GOV-001` is answered. **Nothing may be published before that.**

---

## 2. Verified baseline

Every statement in this section was checked in this checkout. Commands are reproducible; where a
claim is an inference it is tagged `[P]`.

### 2.1 Repository shape `[V]`

| Fact | Evidence |
| --- | --- |
| 277,941 tracked files; 128,041 source files; 5,246 `.htm/.html` | `git ls-files` counts |
| Root build traversal lists 18 trees, including a `QFE` directory that does not exist | `dirs:3-22` |
| Root `dirs` does **not** name `termsrv/`, `public/`, `tools/`, `developer/` | `dirs` vs. `ls` |
| Single commit history (`c24c9fcb8`); no usable upstream history for forensics | `git rev-list --count HEAD` → 1 |
| No `LICENSE` file; `agents/README.md:68-72` calls the tree proprietary | root listing, guide text |
| 21 top-level trees documented in `agents/catalog/` | `python3 agents/generate_catalog.py --check` |

### 2.2 Build system and toolchain `[V]`

| Fact | Evidence |
| --- | --- |
| Build is Razzle + NMAKE + `build.exe`; `build`/`nmake`/`rc`/`mc` sources are in-tree | `tools/razzle.cmd`, `sdktools/build`, `sdktools/nmake`, `sdktools/rc`, `sdktools/mc` |
| Checked-in compiler is **cl 13.00.9176** (x86) and **13.00.9269.1** (amd64) | `strings tools/x86/cl.exe`, `tools/win64/x86/amd64/cl.exe` |
| `build.exe`, `nmake.exe`, `midl.exe`, `rc.exe`, `ml.exe` binaries present for x86 | `tools/x86` |
| README references `tools\missing.cmd` and `tools\oscdimg.cmd`; **neither exists** | `ls tools` |
| `tools/postbuildscripts/cdimage.cmd` exists but is a postbuild step, not the ISO tool | file present, README mismatch |
| ~140 `DIRS`/`OPTIONAL_DIRS` entries across the tree point at **absent** directories | sweep of every `dirs` ≤2 levels deep (full list in §12.1) |
| `loc/bin/dirs` lists 24 language folders; **none exist** | `loc/bin/dirs` vs. `ls loc/bin` |
| Timebomb is applied by postbuild (`DAYS=180`) | `tools/postbuildscripts/timebomb.cmd:44`, `pbuild.dat` |

### 2.3 Architecture and reachability `[V]`

| Fact | Evidence |
| --- | --- |
| i386 kernel targets are traversed (`up`, `mp`, `pae`, `paemp`) | `base/ntos/ke/dirs`, `base/ntos/mm/dirs` |
| AMD64 kernel sources exist (`base/ntos/ke/amd64`, `mm/amd64`, `ntdll/amd64`) | directories present |
| …but **`base/ntos/ke/sources.inc` never references `amd64`** → the AMD64 kernel is not assembled | grep over `sources.inc` |
| `base/ntdll/amd64/sources` references `amd64\usrstubs.asm`, **which is absent** | `ls base/ntdll/amd64` |
| **No AMD64 HAL target exists**; `base/hals/dirs` lists x86 HALs plus `halia64` only | `base/hals/dirs` |
| `base/hals/halacpi/amd64/*` is simulator scaffolding (`_AMD64_SIMULATOR_`, `DbgBreakPoint()` stubs) | `fakeacpi.c:26`, `irqlstub.c` |
| Boot chain is NTLDR/`osloader.exe` + `ntdetect`; **no `bootmgr`/`winload`** | `base/boot/bldr`, `base/boot/detect` |
| EFI support is IA-64 era (`base/boot/efi` built only for `{ia64}`) | `base/boot/dirs:19` |
| AMD64 boot transition helpers exist but are documented as restricted | `base/boot/lib/amd64/amd64.txt` |
| `termsrv/` is not reachable from the root build | root `dirs` |

**Conclusion:** the only architecture with a plausible end-to-end build path in this checkout is
**i386**. AMD64 is a genuine project (HAL + kernel assembly + loader + WOW64), not a flag flip.
This plan therefore targets **i386 as the shipping baseline**, with AMD64 as a named, scheduled
workstream (`KRN-001`…`KRN-003`) — not as an assumption.

### 2.4 Capability matrix vs. 2026 requirements `[V]` unless marked

| Area | Current state in this tree | 2026 requirement | Gap class |
| --- | --- | --- | --- |
| Transport security | Schannel: SSL2/SSL3/TLS1.0, `spbase/ssl2*`, `ssl3*`, `tls1key.c`; no TLS 1.2/1.3, no ECDHE/GCM | TLS 1.2 minimum, ideally 1.3 | Backport (major) |
| Kerberos | DES/RC4 etypes only (`ntsecapi.h:2193-2234`) | AES128/256 (RFC 3962), PKINIT | Backport (major) |
| Hashing/PKI | MD5/SHA-1 era; SHA-2 OIDs present in headers, chain engine SHA-1 | SHA-256 everywhere, modern root store | Backport (medium) |
| Crypto providers | No `rsaenh`/`dssenh` sources in tree; smartcard CSPs only | CNG (`bcrypt`/`ncrypt`), AES-NI, ECDSA | Backport (major) |
| Network driver interface | **NDIS 5.1** (`net/ndis/sys/wrapper.h:46-47`) | NDIS 6.x | Architectural |
| PCI | **MSI/MSI-X disabled** (`base/busdrv/pci/pcip.h:84` `MSI_SUPPORTED 0`) | MSI-X, ECAM, AER, SR-IOV | Backport (medium/large) |
| ACPI | AMLI interpreter; `_OSI` knows only "Windows 2000/2001/SP1" (`type2op.c:1528-1530`) | ACPI 6.x, `_OSI` for modern OS | Backport (large) |
| Storage I/O | classpnp emits **CDB10 only** (`xferpkt.c:416-422`), `READ_CAPACITY(10)` (`:852`) | CDB16, >2 TB, 4Kn, TRIM/UNMAP, NVMe | Backport (large) |
| USB | OHCI/UHCI/EHCI miniports only (`drivers/wdm/usb/hcd/miniport`) | xHCI (USB 3.x), UASP | Backport (large) |
| Wi-Fi | WZC/`layer2svc` with WEP + 802.1X semantics (`zeroconf/server/storage.c`) | WPA2/WPA3, 802.11ac/ax | Architectural |
| Bluetooth | **No stack** (only `net/irda/irprops/bth.def`) | Bluetooth 5.x, LE Audio | New subsystem |
| Graphics | XDDM + `d3d8`/`ddraw`/`dsound` (D3D7-era headers, `d3dtypes.h`), OpenGL 1.1 software (`multimedia/opengl`) | D3D11/12, GL 4.x, Vulkan | Architectural / port |
| Audio | WDM/KS + `multimedia/media/audiosrv` (XP Audio Service), DirectSound/WaveOut; no per-app sessions, no APO, no WASAPI | WASAPI-class engine | Backport (large) |
| TCP | RFC1323 WS/SACK/TS implemented but **off by default** (`tcp/init.c:62,65`) | autotuning, CUBIC/BBR, ECN | Backport (medium) |
| IPv6 | `net/tcpip/tpipv6` (XP-era preview) | RFC 8200 stack, DHCPv6, privacy addrs | Backport (large) |
| SMB | SMB1 redirector/server (`base/fs/rdr2`, `srv`) | SMB2/3 with signing/encryption | Architectural |
| Filesystems | NTFS, FAT, CDFS, UDF (1.x/2.x), EFS | exFAT, >2 TB, 4Kn, TRIM | Backport (medium) |
| Process APIs | No `NtCreateUserProcess`, `NtCreateThreadEx` | Required by modern kernel32/CRT | Backport (large) |
| Loader policy | Rejects subsystem version > 5.1 (`base/win32/client/process.c:203-215`) | Accept 6.x–10.x images | **Quick win** |
| Runtime support | No CLR/.NET sources (`com/netfxoc` empty of code; `com/dirs` names a missing `netfx`) | .NET Framework 4.8 / .NET 8 | Architectural / external |
| Exploit mitigations | No ASLR (no `DYNAMIC_BASE` handling in `mm`), no NX on x86 (`nti386.h` has no `NoExecute`), no SEHOP/CFG symbols | DEP+ASLR+SEHOP+CFG | Backport (large) |
| Console | XP-era `ntcon`; no VT/ANSI (`ENABLE_VIRTUAL_TERMINAL` absent) | VT sequences, ConPTY | Backport (medium) |
| CPU count | `MAXIMUM_PROCESSORS` 32 x86 / 64 amd64 (`winnt.h:4688-4692`) | >64 cores, processor groups | Architectural |
| Memory | 4 GB default cap, suite-gated (`mm/mminit.c:2715-2769`) | 16–64 GB | Backport (medium) |

### 2.5 Security-relevant defaults that must change before any network exposure `[V]`

- `OS=NEONT` is written to the process environment (`base/subsys/sm/server/sminit.c:1565-1568`),
  breaking every `%OS%==Windows_NT` test in the tree and in third-party installers (F-09).
- ACPI `_OS` is `"NEONT"` (`base/busdrv/acpi/driver/nt/amlisupp.c:32-36`), changing firmware
  behaviour versus every real NT 5.1 machine (F-10).
- Product keys are still published in `README.md:75-79` (F-33).
- Build is timebombed by default (`tools/postbuildscripts/timebomb.cmd:44`).

### 2.6 Audit environment and its limits `[V]`

Be explicit about what was *not* done, because the plan's credibility depends on it:

- The audit ran in a **Linux sandbox**. There is no `cl.exe`/`build.exe` execution environment, no
  Windows host, and no bootable media. **No build, install, boot, driver load, or runtime test was
  performed.**
- Evidence is therefore: file reads, `rg`/`grep` searches, `python3 agents/*.py` runs, GCC
  preprocessing of `.dlg`/header fragments, `strings` on checked-in binaries, and one existing
  reproduction script (`agents/audit_reproduce.py`, which itself now fails at its last probe —
  F-17).
- Every quantitative claim in §2 and §4 cites a path and, where useful, a line. Where a claim is
  an inference from structure (for example "no AES in Schannel"), it is phrased as an absence
  observed by search, not as proof of impossibility — absence of a symbol in this snapshot does
  not guarantee it was never present in the original product.
- Findings that depend on runtime behaviour (performance, crash reproducibility under load,
  hardware compatibility) are **not** in §4; they live as test tasks in Phase 13 and must be
  established there.

---

## 3. Feasibility doctrine

Three tiers. Use these when deciding whether a task may be scheduled at all.

### Tier A — Direct backport (normal engineering)
Code already exists in-tree; the work is a fix, a flag, or a port within the existing
architecture. Examples: fixing the build-number parser, enabling SACK/WS, lifting the 4 GB
licensing cap, adding CDB16, adding exFAT, implementing TLS 1.2 inside Schannel's existing
state machine, raising the loader's subsystem-version ceiling.

**Rule:** Tier A tasks must have a test that fails before and passes after.

### Tier B — Large but tractable project
Touches a subsystem's contract or requires porting an external implementation with a compatible
license. Examples: NDIS 6.x, xHCI, NVMe, ACPI 6.x AML fixes, a CNG (`bcrypt`) layer, a WASAPI-class
audio engine, ASLR+SEHOP, a UCRT/MSVC-runtime compatibility layer, WPA2 supplicant.

**Rule:** Tier B tasks require a written design note, a named owner, and a staged merge plan
(feature flag → default off → default on). No big-bang landings.

### Tier C — Requires architectural replacement (do not schedule as a backport)
The feature is defined by an architecture this OS does not have. Examples: WDDM/KMDF driver
models, Secure Boot + measured boot, VBS/HVCI, processor groups (>64 CPUs), kernel CFG
(compiler-dependent), AppContainer, Hyper-V-based isolation, SMB3 encryption, ReFS, .NET runtime.

**Rule:** Tier C items live in §10 until a design spike proves a bounded path. Spikes are
timeboxed and have a kill criterion. Never let a Tier C item block a milestone.

### 3.1 Cross-cutting principle: never break NT 5.1 semantics
Modern compatibility must be **additive**. Where a modern API changes behaviour, gate it on an
explicit opt-in (manifest, compatibility database entry, registry policy), not on the system
version. Rebranding taught us this the hard way: `OS=NEONT` and `_OS="NEONT"` are ABI changes
disguised as cosmetics (F-09, F-10).

---

## 4. Verified findings register

Findings from the pre-existing audit (`agents/audit/`) are re-verified here as of this audit.
**Status is re-checked against the current working tree**, not copied from the older report.

| ID | Finding | Location | Sev | Status | Notes |
| --- | --- | --- | --- | --- | --- |
| F-01 | `genbldno.pl` requires literal `/* NT */`; header now says `/* NEONT */` → build-number generation fails | `tools/genbldno.pl:74-82`, `public/sdk/inc/ntverp.h:31` | High | **Open** `[V]` | Reproduced: `perl tools/genbldno.pl` → `Failed to find a build number`, exit 1 |
| F-02 | `fdisk.dlg` appends `,-1,"static",...` after `#endif` in both branding modes → malformed CONTROL | `base/fs/utils/fdisk/fdisk.dlg:11-15` | Med | **Open** `[V]` | GCC preprocess shows first `CONTROL "NEONT"` lacks ID/class/geometry |
| F-03 | SMSS read of uninitialized `ValueData` | `base/subsys/sm/server/sminit.c:1530-1565` | High | **Fixed** `[V]` | `ValueData = NULL;` now precedes the query (PR #17) |
| F-04 | SMSS `wcslen` on unterminated REG_SZ | `sminit.c:1555-1560` | High | **Fixed** `[V]` | `CharCount-1` NUL forced before use |
| F-05 | `OS=NEONT` breaks `%OS%==Windows_NT` consumers | `sminit.c:1565-1568`, `tools/x86/perl/bin/pl2bat.bat:3` | Med | **Open** `[V]` | Still emits `NEONT` when branding is on |
| F-06 | ACPI `_OS` set to `NEONT` | `base/busdrv/acpi/driver/nt/amlisupp.c:32-36` | Med | **Open** `[V]` | Firmware-visible identity |
| F-07 | Multimedia version resources ignore `NEONT_BRANDING=0` | `multimedia/media/mmcaps2k/mmcaps.h:63-79` (+2 copies) | Low | **Open** `[V]` | Toggle is defined but product strings are unconditional |
| F-08 | Transposed `memset` in UL Win9x samples | `inetsrv/iis/iisrearc/ul/win9x/src/test/{cmd/snd,cmd/rcv,chat/client,chat/server}` | Low | **Fixed** `[V]` | Sites now read `memset(&Overlapped, 0, sizeof(Overlapped))` (PR #15) |
| F-09 | `snd` accepts lengths ≥ buffer size; `gets`/`atoi` unbounded | `…/test/cmd/snd/snd.c:65-70` | Low | **Open** `[V]` | `pBuffer[ulSize] = '\0'` with `ulSize == 2048` overflows; `gets` still used |
| F-10 | License DB insert failure reported as success (`=` in `if`) | `termsrv/license/tlserver/server/license.cpp:408` | Med | **Fixed** `[V]` | Now `if (bSuccess == FALSE)` (PR #19) |
| F-11 | WMI `GetResultHeader` returns `S_OK` **without setting `*ppszBuffer`** when the first `HttpQueryInfo` succeeds | `admin/wmi/wbem/xmltransport/client/helpersources/httpconnectionagent.cpp:571-620` | Med | **Open** `[V]` | PR #23 fixed only the failure path; the success path still leaves the out-param untouched |
| F-12 | PPP CHAP zeroes only pointer width of `USER_SESSION_KEY` | `net/rras/ras/ppp/common/clsa.c:690` | High | **Fixed** `[V]` | `memset(pUserKey, 0, sizeof(*pUserKey))` (PR #4) |
| F-13 | NetMeeting codecs assign `FALSE` in `if` → `*Started` never set | `enduser/netmeeting/av/codecs/dec/dech263/sa_api.c:564,570,853,873` (+`dech261` copies) | Med | **Open** `[V]` | Six sites per file; duplicated tree |
| F-14 | README documents unsupported `CkhKernel` switch | `README.md:33` | Low | **Open** `[V]` | Parser accepts `ChkKernel` only (`tools/razzle.cmd:96`) |
| F-15 | README publishes product keys | `README.md:75-79` | Med | **Open** `[V]` | PRs #9/#12 closed unmerged |
| F-16 | `agents/verify.py` fails on its own tree | `agents/audit/14`, `15`, missing `agents/components/.jules.md` | Low | **Open** `[V]` | 4 errors; doc gate is red |
| F-17 | `agents/audit_reproduce.py` crashes at the license probe | `agents/audit_reproduce.py:137` | Low | **Open** `[V]` | `ValueError: substring not found` after F-10 was fixed — the harness is now stale |
| F-18 | AMD64 kernel not in build traversal | `base/ntos/ke/sources.inc` | High | **Open** `[V]` | No `amd64` reference anywhere in that file |
| F-19 | `base/ntdll/amd64/sources` references a missing file | `base/ntdll/amd64/sources:3` | High | **Open** `[V]` | `amd64\usrstubs.asm` absent |
| F-20 | No AMD64 HAL | `base/hals/dirs` | High | **Open** `[V]` | Only x86 + `halia64` |
| F-21 | Timebomb applied by default | `tools/postbuildscripts/timebomb.cmd:44`, `pbuild.dat` | High | **Open** `[V]` | Also `drivers/wdm/audio/timebomb/timebomb.c` |
| F-22 | No ASLR in memory manager | `base/ntos/mm/*` | High | **Open** `[V]` | No `DYNAMIC_BASE`/randomization logic |
| F-23 | No NX/DEP on x86 | `public/sdk/inc/nti386.h` | High | **Open** `[V]` | No `NoExecute` PTE bit defined; amd64 has it (`mm/amd64/miamd.h:631`) |
| F-24 | No SEHOP/CFG/heap-integrity symbols | tree-wide grep | High | **Open** `[V]` | Baseline pre-mitigation |
| F-25 | TLS ceiling is 1.0; SSL2/3/PCT compiled in | `ds/security/protocols/schannel/spbase/` | High | **Open** `[V]` | `ssl2cli.c`, `ssl3*.c`, `tls1key.c`; no TLS1.2 files |
| F-26 | Kerberos has no AES etypes | `public/sdk/inc/ntsecapi.h:2193-2234` | High | **Open** `[V]` | DES/RC4 only |
| F-27 | MSI/MSI-X compiled out | `base/busdrv/pci/pcip.h:84` | High | **Open** `[V]` | `MSI_SUPPORTED 0` |
| F-28 | `_OSI` recognises only 2000/2001/SP1 | `base/busdrv/acpi/driver/amlinew/type2op.c:1528-1530` | High | **Open** `[V]` | Modern DSDTs take legacy paths |
| F-29 | Storage stack is CDB10-only | `drivers/storage/classpnp/xferpkt.c:416-422,852` | High | **Open** `[V]` | 2 TB ceiling, no CDB16 |
| F-30 | TCP window scaling/timestamps off by default | `net/tcpip/driver/tcp/init.c:62,65`, `ntinit.c:1576-1579` | Med | **Open** `[V]` | `GlobalMaxRcvWin = 0xFFFF`, `TcpHostSendOpts = 0` |
| F-31 | Loader rejects subsystem version > 5.1 | `base/win32/client/process.c:203-215` | **Critical** | **Open** `[V]` | `ERROR_BAD_EXE_FORMAT` for any `/SUBSYSTEM:6.0+` image |
| F-32 | No modern process/thread APIs | tree-wide grep | **Critical** | **Open** `[V]` | `NtCreateUserProcess`, `NtCreateThreadEx` absent |
| F-33 | No `GetTickCount64`, `CreateFile2`, `SetThreadDescription`, `GetSystemTimePreciseAsFileTime` | `base/win32` grep | **Critical** | **Open** `[V]` | Blocks most modern runtimes outright |
| F-34 | No VT/ANSI console support | `windows/core/ntcon` grep | Med | **Open** `[V]` | No `ENABLE_VIRTUAL_TERMINAL` |
| F-35 | Wi-Fi is WEP/802.1X-era | `net/layer2svc/zeroconf/server/storage.c` | High | **Open** `[V]` | No RSN/CCMP/TKIP anywhere |
| F-36 | No Bluetooth stack | tree-wide grep | High | **Open** `[V]` | Only an IrDA `.def` names `bth` |
| F-37 | No .NET/CLR sources | `com/netfxoc` (only `dirs`), `com/dirs` names missing `netfx` | High | **Open** `[V]` | Confirmed absent |
| F-38 | 4 GB default physical-memory cap + suite gating | `base/ntos/mm/mminit.c:2715-2769` | Med | **Open** `[V]` | `MI_DEFAULT_MAX_PAGES`, `ExVerifySuite(DataCenter/Enterprise/Blade)` |
| F-39 | 32 logical processors max on x86 | `public/sdk/inc/winnt.h:4688-4692` | Med | **Open** `[V]` | No processor groups |
| F-40 | Duplicate codec trees | `enduser/netmeeting/av/codecs/dec/dech261` vs `dech263` | Low | **Open** `[V]` | Identical files; fix twice or dedupe |
| F-41 | ~140 dangling `dirs` references | all `dirs` files | Med | **Open** `[V]` | Blocks "complete tree" claims; full list §12.1 |
| F-42 | `loc/bin` language trees absent (24 entries) | `loc/bin/dirs` | Med | **Open** `[V]` | No localized build possible |
| F-43 | No `oscdimg`; ISO creation documented but unavailable | `README.md:60`, `tools/` | Med | **Open** `[V]` | Use `cdimage.cmd`? no — different tool |
| F-44 | 5,246 HTML files are shipped content, not source | tree-wide | Info | **Open** `[V]` | `AGENTS.md` forbids editing them for fixes |
| F-45 | Single-commit history; no bisect/forensics | `git log` | Info | **Open** `[V]` | Limits regression hunting |
| F-46 | Network driver interface is **NDIS 5.1**; no 6.x | `net/ndis/sys/wrapper.h:46-47` | High | **Open** `[V]` | Modern NIC/Wi-Fi miniports cannot load |
| F-47 | No USB 3 host controller: only OHCI/UHCI/EHCI miniports | `drivers/wdm/usb/hcd/miniport` | High | **Open** `[V]` | No xHCI; USB 3 ports unusable without a driver |
| F-48 | No NVMe and no in-box AHCI driver; storage is ATA/ATAPI + SCSI port | `drivers/storage/{ide,scsiport,port}` | High | **Open** `[V]` | Modern SSDs run in legacy/IDE mode or not at all |

### 4.1 Findings that change the plan's shape

1. **F-31 is the single highest-leverage one-line fix in the repository.** A modern executable
   fails at `CreateProcess` before a single API is called. Fix it in Phase 0, verify it, and the
   entire Phase 5 effort becomes measurable.
2. **F-22…F-24 mean the OS cannot be exposed to a 2026 network at all.** Security work is not a
   later phase; it is Phase 3 and it runs in parallel with compatibility work.
3. **F-18…F-20 mean "AMD64 daily driver" is not a variant — it is a second platform bring-up.**
   Plan i386 first; do not let AMD64 block M1–M5.
4. **F-41/F-42 mean "full build from clean checkout" is currently impossible**, and any claim of
   completeness must be scoped to a *ledger* of what actually builds (§7 Phase 0, `BLD-012`).

### 4.2 Repository hygiene checks to run before every change

```bat
git diff --check
python3 agents/generate_catalog.py --check
python3 agents/verify.py            :: currently red — see F-16
```

These are the only checks that are known to work on this checkout today. Everything else in
Phase 13 is new work.

---

## 5. Constraints, external dependencies and legal posture

### 5.1 Legal / licensing — read before planning anything user-facing

| Constraint | Detail | Effect on plan |
| --- | --- | --- |
| **Provenance** | No `LICENSE` file; `agents/README.md:68-72` describes the tree as proprietary Microsoft source and instructs not to publish keys, certificates, or binaries. | **GOV-001 is a hard gate.** No distribution, no ISO, no public CI artifacts until resolved. |
| **Redistribution** | The tree contains `developer/*.pub` keys, signing material under `tools/`, product keys in `README.md`. | Must be removed/quarantined (`GOV-002`, `GOV-003`) before any artifact build. |
| **Upstream licenses** | Any ported code (Wine, Mesa, musl, FFmpeg, vkd3d, OpenSSL, ext4 driver…) carries its own license. GPL code cannot be statically linked into NT-derived binaries without legal review. | `GOV-004`: license ledger. LGPL dynamic linking preferred; GPL avoided except in isolated user-mode tools. |
| **Patent exposure** | FAT/exFAT, MP3/AAC/H.264 codecs, TLS suites. | `GOV-005`: codec and filesystem licence review before bundling. |
| **Trademarks** | "NEONT", "Windows", "Microsoft" appear in resources and banners. | `GOV-006`: naming policy; do not ship Microsoft marks. |

### 5.2 Missing inputs and upstream projects

| Need | Status | Candidate source |
| --- | --- | --- |
| Modern compiler capable of `/guard:cf`, `/GS`, C11 | Only cl 13.00 in-tree `[V]` | clang-cl (Apache-2.0 w/ LLVM exception) cross/self-build; MSVC 2019+ if licensed |
| `rc.exe` equivalent on Linux for CI | In-tree Windows `rc.exe`; `sdktools/rc` source available | `windres`/`llvm-rc` for linting, in-tree `rc` for production |
| MIDL | `com/rpc/midl` sources `[V]` | Build in-tree; `widl` (Wine) for CI generation |
| ISO mastering | `oscdimg` absent `[V]` | `xorriso`/`genisoimage` + El Torito boot catalog; `mkisofs` for CI |
| WIM/compression for install images | `compress.exe`, `makecab.exe` present `[V]` | Keep CAB; add WIM later only if needed |
| .NET runtime | No sources `[V]` | Mono (MIT) or CoreCLR port; see `API-060` |
| UCRT | Absent `[V]` | Wine `ucrtbase` (LGPL), musl (MIT), or self-written shim |
| Vulkan/OpenGL driver | None `[V]` | Mesa (MIT), `vkd3d-proton` (LGPL), `wined3d` (LGPL) |
| Codec coverage | XP-era codecs `[V]` | FFmpeg (LGPL/GPL split — review), libopus (BSD) |
| Driver sources for modern NIC/Wi-Fi | Absent `[V]` | Vendor BSD/GPL drivers → licence conflict with kernel linking; prefer NDIS 6 port + whitelisted binary drivers |
| Test corpora | Wine conformance suite, Microsoft WCAG samples | Wine (LGPL), open test suites |

### 5.3 Hardware restrictions `[P]`

- **Secure Boot:** cannot be enabled without anEV-signed bootloader; a self-compiled loader needs
  the user to disable Secure Boot or enrol a custom key in firmware setup. Document as a hard
  requirement of installation (`SETUP-004`).
- **Modern laptops** may expose no legacy boot at all, no S3 (only Modern Standby), and
  I2C-attached touchpads. Those machines are out of scope until `DRV` work lands.
- **GPUs** shipped after ~2012 have no XDDM drivers. Display output is limited to VESA/GOP
  framebuffer unless a driver is found (`GFX-001`).
- **NVMe-only** systems cannot boot until `BOOT-004` + `DRV-020` exist.

### 5.4 Upstream projects this plan depends on (tracked, not vendored)

- **One-Core-API** (One-Core-API-Binaries / One-Core-API-Source) — the de-facto Vista+ API
  backport for XP/2003; primary reference for `API-0xx` export lists and apiset schema.
- **Wine** — conformance tests (`TST-010`), `ucrtbase`/`vcruntime` behaviour, `wined3d`/`vkd3d`.
- **Mesa** — OpenGL/Vulkan for `GFX-010`.
- **ReactOS** — independent NT 5.2 implementation; useful cross-reference for missing pieces
  (do **not** copy GPL code into this tree; review per `GOV-004`).
- **OpenSSL 3.x / BoringSSL** — reference implementations for TLS 1.2/1.3 primitives if
  Schannel's internal crypto is insufficient.
- **FFmpeg / libopus / libvpx / dav1d** — media decode (`MMD`).
- **Ext2Fsd / WinBtrfs / exFAT specs** — filesystem breadth (`FS-010`).
- **QEMU / VirtualBox / VMware** — boot and driver test matrix (`TST-040`).

---

## 6. Definition of Done — release gates for "daily driver 2026"

A milestone is not "done" because a feature merged. These gates define acceptance. Every gate is
measurable; the measurement method is named.

| Gate | Requirement | Measurement |
| --- | --- | --- |
| **R1 Build** | Clean i386 free build from a pristine clone completes with **0 errors**; every failure is either fixed or recorded in the ledger as out-of-scope with a reason. | `BLD-012` ledger; CI run link |
| **R2 Boot** | Installs and boots to a usable desktop on ≥3 distinct hypervisors and ≥2 physical machines; 20 consecutive cold boots without bugcheck. | `TST-041` matrix |
| **R3 Data** | NTFS write path survives 72 h power-loss/soak testing with `chkdsk` clean; no data-loss bug open above P2. | `TST-052`, `FS-020` |
| **R4 Network** | HTTPS to ≥95 % of the Alexa top 500 succeeds; TLS 1.2 negotiated; SMB share mount works; DHCP/DNS resilient to loss. | `TST-060` |
| **R5 Security** | ASLR+DEP active for all system binaries; no SSL2/3/TLS1.0/RC4/NTLMv1/LM enabled by default; a published baseline scan is clean. | `TST-020`, `SEC-003` |
| **R6 Apps** | Top-50 application matrix (browsers, office, media, dev tools) passes with no unresolved P0/P1 blocker; see `API-100` and `APP-001`. | `TST-070` |
| **R7 Performance** | Cold boot ≤30 s on SSD; shell idle CPU ≤2 %; app launch parity within 2× of a reference XP SP3 VM on identical hardware. | `TST-080` |
| **R8 Usability** | 30 consecutive days of a maintainer using it as primary OS with no data loss and no more than 1 reinstall. | `USE-090` journal |
| **R9 Update/Recovery** | An update can be installed and rolled back offline; a corrupted install can be repaired without reinstall. | `REL-012`, `REC-001` |
| **R10 Honesty** | Every claim in README/PLAN matches the ledger; no feature is described as supported unless a test proves it. | doc review |

**Publishing rule:** no artifact, ISO, or binary is distributed before `GOV-001` is resolved and
R1/R5 are green.

---

## 7. Roadmap phases

Phases are ordered by dependency, not by glamour. Each phase lists: goal, exit criteria, tasks.
Tasks carry `[status]` `P#` ID — title — subtasks — acceptance.

Dependency notation: `dep: ID, ID`.

> **Navigation note:** for readability, the sixteen phases (0–15) are rendered as top-level
> sections between this introduction and §8. They *belong* to §7; there is no §7.1. When a task
> says "Phase 5.3", it means the subsection of Phase 5, not a section of this document.

---

## Phase 0 — Truth, buildability and governance (P0)

**Goal:** a pristine clone produces a known-good i386 build, reproducibly, with no timebomb, and
with an accurate inventory of what does and does not build.
**Exit:** R1 green; `BLD-012` ledger published; `GOV-001` decision recorded; no timebomb in
artifacts; CI runs the three existing checks on every change.

### Phase 0.1 — Governance

- `[ ]` **P0 `GOV-001`** — Determine the legal basis for building and (non-)distributing this tree.
  - Subtasks: inventory provenance claims; confirm no `LICENSE`; document jurisdiction(s);
    decide internal-use-only vs. distribution; obtain written decision from the project owner.
  - Acceptance: a dated decision record in `docs/legal/provenance.md` that states explicitly
    whether artifacts may leave the build lab. All downstream release tasks depend on it.
  - `[!]` **blocked-by:** project owner decision. **Do not work around this.**
- `[ ]` **P0 `GOV-002`** — Remove secrets and licence material from tracked content.
  - Subtasks: delete product keys from `README.md:75-79`; audit `developer/*.pub`,
    `tools/**/*.pem|pfx|pvk|snk`, `developer/anvil.*`; replace with documented "bring your own
    key" flow; check `agents/` for copied material.
  - Acceptance: `git grep -nE 'M6RJ9|QW32K|KK2WD'` empty; a secrets scanner (gitleaks) reports
    no high-confidence findings; `AGENTS.md` updated with the policy.
- `[ ]` **P0 `GOV-003`** — Quarantine signing and lab infrastructure behind an explicit opt-in.
  - Subtasks: make `tools/postbuildscripts/*sign*` fail closed unless `OFFICIAL_SIGN=1`; document
    the dev-cert path; ensure no private key is required for a normal build.
  - Acceptance: a normal `postbuild` run with no keys produces images with test signatures or
    none, and logs exactly which artifacts are unsigned.
- `[ ]` **P1 `GOV-004`** — Third-party licence ledger.
  - Subtasks: enumerate every external library already in-tree (zlib in `base/zlib`, ASN.1,
    `msasn1`, Perl under `tools/x86/perl`, `makecab`, etc.); record licence, version, CVE status;
    establish rules for Tier B ports.
  - Acceptance: `docs/legal/third-party.md` lists every dependency with SPDX identifier and
    linking model; new dependencies cannot merge without an entry.
- `[ ]` **P1 `GOV-005`** — Codec and filesystem patent/licence review for anything bundled.
- `[ ]` **P2 `GOV-006`** — Name and trademark policy; remove Microsoft marks from user-visible
  resources produced by this project (keep them where required for compatibility strings).

### Phase 0.2 — Branding correctness (the PR #2 debt)

- `[x]` **P0 `VER-001`** — SMSS uninitialised `ValueData` (F-03). Fixed; regression test still
  required → `TST-021`.
- `[x]` **P0 `VER-002`** — SMSS non-terminated REG_SZ (F-04). Fixed; regression test → `TST-021`.
- `[ ]` **P0 `VER-003`** — Decouple `OS` environment variable from branding (F-05).
  - Subtasks: always write `OS=Windows_NT`; add `NEONT_BRAND` (or similar) for display only;
    grep every `%OS%` consumer in `tools/**/*.bat|cmd` and `*/prop.bat`; add a build-time check.
  - Acceptance: both branding modes produce `OS=Windows_NT`; `pl2bat.bat` takes the WinNT branch;
    `inetcore/outlookexpress/prop.bat` passes its platform check; a unit test asserts the value.
- `[ ]` **P0 `VER-004`** — Keep ACPI `_OS` at `Microsoft Windows NT` (F-06).
  - Subtasks: revert `gpszOSName` to the compatibility string unconditionally; add an AML fixture
    test that compares `_OS` in both build modes; document that firmware identities are excluded
    from branding.
  - Acceptance: `_OS` identical in both modes; fixture passes; behaviour documented in
    `docs/compat/firmware-identity.md`.
- `[ ]` **P1 `VER-005`** — Fix multimedia product-name conditionals (F-07).
  - Subtasks: guard `APP_VERSION_PRODUCTNAME_RC` in `mmcaps2k/mmcaps.h`, `samples/mmcapsex/`,
    `samples/acmapp/acmapp.h` with `#if NEONT_BRANDING`, preserving arch suffixes.
  - Acceptance: preprocessor snapshot test asserts both branches for _X86_/MIPS/Alpha/PPC/fallback.
- `[ ]` **P0 `VER-006`** — Fix `genbldno.pl` (F-01).
  - Subtasks: parse `#define VER_PRODUCTBUILD` by value, not by comment text; accept `/* NT */`
    and `/* NEONT */`; fail loudly on missing macro; add fixture headers.
  - Acceptance: `perl tools/genbldno.pl` exits 0 and yields `2600`/`1106`; fixtures cover both
    comment spellings, extra whitespace, and a malformed header.
- `[ ]` **P1 `VER-007`** — Single source of truth for the product identity.
  - Subtasks: introduce one header (e.g. `public/sdk/inc/ntbrand.h`) consumed by resources, ACPI,
    SMSS, and the build scripts; eliminate the ~dozen ad-hoc `#ifndef NEONT_BRANDING` blocks.
  - Acceptance: grep shows exactly one definition site; a script (`VER-008`) enforces it.
- `[ ]` **P1 `VER-008`** — Branding consistency gate in CI.
  - Subtasks: script that fails if a consumer of a machine-readable identity (OS env, `_OS`,
    version resources) branches on display branding.
  - Acceptance: gate runs in CI and has caught at least the three known regressions in a test.
- `[ ]` **P2 `VER-009`** — Version resources: verify `VER_PRODUCTVERSION_*` consistency and that
  `ntverp.h` regenerates correctly under `set_builddate`/`set_buildnum`.
  - Acceptance: `nmake -f makefil0 set_builddate set_buildnum` produces a consistent
    `__blddate__`/`__bldnum__`/`__qfenum__` triple and binplaces them.

### Phase 0.3 — Build environment

- `[ ]` **P0 `ENV-001`** — Reproducible build host.
  - Subtasks: document the supported host (Windows XP/2003 x86 with the in-tree cl 13.00 +
    `tools/x86` payload); create a VM image and a provisioning script; pin by hash.
  - Acceptance: two independent hosts produce byte-identical binaries for ≥3 targets, or the
    deltas are explained and enumerated.
- `[ ]` **P0 `ENV-002`** — Toolchain integrity.
  - Subtasks: hash every binary in `tools/x86|win64|ia64`; record BuildID/version; scan for
    tampering; document which tools are used vs. vestigial; delete nothing yet.
  - Acceptance: `tools/MANIFEST.sha256` + `docs/build/toolchain.md`; CI verifies the hashes.
- `[ ]` **P0 `ENV-003`** — Make `razzle.cmd` honest.
  - Subtasks: validate every argument against the parser; add `-?` output that lists the real
    spellings (`ChkKernel`, `no_opts`, `binaries_dir`, `offline`); fail on unknown switches;
    fix `README.md` (F-14).
  - Acceptance: `razzle.cmd Bogus` fails with a message; README matches usage output exactly;
    a test greps both.
- `[ ]` **P1 `ENV-004`** — Linux-side lint/preprocess harness.
  - Subtasks: generate `compile_commands.json` by translating `sources` files; run `clang -fsyntax-only`
    with `-fms-extensions -D_M_IX86` to catch syntax regressions without a Windows build.
  - Acceptance: ≥60 % of `sources` targets produce a translation unit that parses; the rest are
    documented with reasons (assembly, MIDL, RC).
- `[ ]` **P2 `ENV-005`** — Build in a container (Wine + in-tree toolchain) to remove the Windows
  host dependency; see `DX-020`.
- `[ ]` **P1 `ENV-006`** — Toolchain modernization spike (VC7 → clang-cl/MSVC).
  - Subtasks: pick 5 diverse targets (a DLL, a driver, `ntoskrnl`, a shell app, a tool); try to
    compile with clang-cl 18 in `-fms-compatibility -std=c11` mode; record the top 20 error classes.
  - Acceptance: a report that quantifies the effort; no production switch until ≥1 target links
    and boots in a VM.

### Phase 0.4 — Build system

- `[ ]` **P0 `BLD-001`** — Repair the ISO path (F-43).
  - Subtasks: implement `tools/oscdimg.cmd` as a wrapper around a supported mastering tool
    (`xorriso` preferred), producing El Torito BIOS + no-emulation boot; keep an in-tree
    `cdimage`-independent path; document the boot image layout expected by `osloader`.
  - Acceptance: `tools\oscdimg.cmd pro out.iso` produces an ISO that boots to setup in QEMU.
- `[ ]` **P0 `BLD-002`** — Publish a build ledger (F-41).
  - Subtasks: parse every `dirs`/`sources`; classify each target as *built*, *skipped-missing-dir*,
    *skipped-arch*, *skipped-sku*; emit `build/ledger.json` + Markdown summary; CI diffs it.
  - Acceptance: ledger covers all 21 trees; the ≥140 dangling entries from §12.1 appear as
    explicit `skipped-missing-dir` with the referencing path.
- `[ ]` **P0 `BLD-003`** — First honest full build.
  - Subtasks: `razzle free offline` + `build /cZP`; capture every error; triage into
    (a) fix now, (b) needs missing source, (c) needs toolchain; repeat until zero errors.
  - Acceptance: R1 green; `build/build-report-<date>.md` lists every fix with a commit.
- `[ ]` **P1 `BLD-004`** — Deterministic outputs.
  - Subtasks: strip timestamps from PE resources (`/Brepro` equivalent); normalize PDB paths;
    sort archive members; normalize CAB timestamps; document `SOURCE_DATE_EPOCH` analogue.
  - Acceptance: two clean builds in separate directories produce identical PE images (hash match)
    for ≥90 % of binaries.
- `[ ]` **P1 `BLD-005`** — Incremental-build correctness.
  - Subtasks: audit `sources` for missing dependencies on generated headers/IDL; add dependency
    generation for MIDL/MC outputs; verify `build /ZP` after touching a public header.
  - Acceptance: touching `public/sdk/inc/ntverp.h` rebuilds all version-consuming targets; no
    stale-object bug in a 20-target sample.
- `[ ]` **P1 `BLD-006`** — Remove the timebomb from all build paths (F-21).
  - Subtasks: delete the `timebomb.cmd` line from `pbuild.dat`; remove `TIME_BOMB` defines from
    audio drivers; delete `drivers/wdm/audio/timebomb/timebomb.c` usage; keep the file only if a
    documented evaluation build still needs it (default off).
  - Acceptance: `grep -ri timebomb` shows no default-enabled path; built images run past day 180
    in a clock-advanced VM test.
- `[ ]` **P1 `BLD-007`** — Evaluation/expiry code removal from binaries.
  - Subtasks: audit for `STATUS_EVALUATION_EXPIRATION`, `__DATE__`-based checks, trial banners;
    remove or gate behind an explicit `EVAL_BUILD` define that is off.
  - Acceptance: binary string scan of a free build finds no evaluation strings.
- `[ ]` **P1 `BLD-008`** — Build warnings baseline.
  - Subtasks: enable `/W4` where it does not break; capture warning counts per component; freeze
    the baseline; fail CI on increase for touched components.
  - Acceptance: `build/warnings-baseline.json`; a PR that adds a warning fails.
- `[ ]` **P1 `BLD-009`** — Dead option and dead switch cleanup in `razzle.cmd`/`makefile.def`.
  - Acceptance: every switch either works or errors; no silently ignored argument remains.
- `[ ]` **P2 `BLD-010`** — Precompiled-header sanity and incremental link times.
- `[ ]` **P2 `BLD-011`** — Split monolithic `dirs` traversal into explicit target groups
  (`kernel`, `drivers`, `user`, `tools`) so a component build does not require the whole tree.
- `[ ]` **P1 `BLD-012`** — Publication/import-library integrity.
  - Subtasks: detect public headers/libs that no in-tree producer regenerates (`public/` is
    described as a checked-in artifact tree in `agents/components/public.md`); mark them `vendored`
    in the ledger; add a check that a published `.lib` matches its producer's exports.
  - Acceptance: `docs/build/publication.md` lists every vendored artifact and its owner.

### Phase 0.5 — CI foundation

- `[ ]` **P0 `BLD-020`** — CI job that runs the three existing checks (`git diff --check`,
  `generate_catalog.py --check`, `verify.py`) and blocks merges.
- `[ ]` **P0 `BLD-021`** — Fix `agents/verify.py` failures (F-16) so the gate is green.
  - Subtasks: fix 3 broken links in `agents/audit/14`, `15`; add the missing
    `agents/components/.jules.md` or remove it from the expected list.
  - Acceptance: `python3 agents/verify.py` exits 0.
- `[ ]` **P1 `BLD-022`** — Fix `agents/audit_reproduce.py` (F-17).
  - Subtasks: make the license probe resilient to already-fixed code; assert the *fixed*
    behaviour; make each probe independent so one failure does not abort the run.
  - Acceptance: script exits 0 and its output is attached to CI.
- `[ ]` **P1 `BLD-023`** — Nightly full build + boot smoke in a VM, publishing the ledger.
- `[ ]` **P2 `BLD-024`** — Artifact retention and SBOM generation (`REL-022`).

---

## Phase 1 — Boot, firmware, installation and recovery (P0)

**Goal:** a machine (VM first, then physical) installs, boots, and can be recovered without a
reinstall. **Depends on:** Phase 0 (need an image to test).
**Exit:** R2 green; R9 partially green (repair without reinstall).

### Phase 1.1 — Boot chain

- `[ ]` **P0 `BOOT-001`** — Document and instrument the real boot path.
  - Subtasks: trace `bootsect` → `osloader` → `ntdetect` → `ntoskrnl` → `SMSS` → `CSRSS` →
    `winlogon` with boot logging enabled; capture on both QEMU (SeaBIOS) and a physical BIOS
    machine; publish a timing breakdown.
  - Acceptance: `docs/boot/boot-trace.md` with per-stage timings and the exact files read; any
    undocumented dependency becomes a new task.
- `[ ]` **P0 `BOOT-002`** — Fix the i386-only NTDLR assumptions in `osloader`.
  - Subtasks: audit `base/boot/bldr/osloader.c` for hard-coded 8 GB/4 GB limits, `INT 13`
    assumptions, 1024-cylinder bugs, LBA48 handling, and CHS fallbacks.
  - Acceptance: boots from a >2 TB disk's first partition and from an LBA-only disk in a VM
    test fixture.
- `[ ]` **P0 `BOOT-003`** — GPT boot support.
  - Subtasks: loader must read a GPT protective MBR + GPT header and locate the system partition;
    `fstub` already understands `PARTITION_STYLE_GPT` (`base/ntos/fstub/ex.c`), so add the loader
    side; keep MBR as default.
  - Acceptance: installs and boots on a GPT disk in UEFI-CSM and BIOS VMs; `boot.ini`-equivalent
    configuration survives.
- `[ ]` **P1 `BOOT-004`** — Boot from USB mass storage.
  - Subtasks: add a minimal USB mass-storage + xHCI/EHCI stack usable from the loader (a
    "boot driver" approach); or require a BIOS that provides USB legacy emulation and document it.
  - Acceptance: USB stick install and boot works on ≥2 machines without legacy emulation.
  - Risk: depends on `DRV-030` (xHCI) for USB 3 ports.
- `[ ]` **P2 `BOOT-005`** — NVMe boot.
  - Subtasks: loader NVMe driver (polled, single-queue, no interrupts) + namespace enumeration.
  - Acceptance: cold boot on an NVMe-only machine in QEMU (`-device nvme`).
- `[ ]` **P1 `BOOT-006`** — Boot-time memory map hardening.
  - Subtasks: handle firmware that reports reserved ranges above 4 GB, `E820` type 3/4 correctly,
    and >4 GB RAM on x86 PAE; verify `LoaderBlock->u.I386` fields remain consistent.
  - Acceptance: boots with 8 GB and 16 GB RAM in a PAE VM without bugcheck or memory loss >1 %.
- `[ ]` **P1 `BOOT-007`** — Safe mode and boot-option coverage.
  - Subtasks: verify `/SAFEBOOT:MINIMAL|NETWORK`, `/NOGUIBOOT`, `/BASEVIDEO`, `/BOOTLOG`,
    `/MAXMEM`, `/PAE`, `/3GB` all still work; add `/NOEXECUTE` handling if `SEC-010` lands.
  - Acceptance: a boot-option matrix test in CI (`TST-041`).
- `[ ]` **P2 `BOOT-008`** — Boot-time driver rollback: if a newly installed driver bugchecks, the
  next boot offers "last known good" reliably.
  - Subtasks: verify LKG works with modern hardware state; add a boot counter and auto-fallback.
  - Acceptance: inject a failing driver, confirm the OS recovers in ≤2 boots.
- `[ ]` **P3 `BOOT-009`** — Design spike: UEFI boot without CSM.
  - Subtasks: evaluate porting `winload`-equivalent (PE/COFF UEFI application) vs. writing a new
    loader; measure effort; decide go/no-go.
  - Acceptance: a written spike with a go/no-go decision. **Do not schedule implementation
    until `BOOT-003` and `DRV-030` are done.**

### Phase 1.2 — Setup / installation

- `[ ]` **P0 `SETUP-001`** — In-box AHCI and NVMe drivers for text-mode setup.
  - Subtasks: build `msahci`/`storahci` equivalent as a boot-critical driver; add to `txtsetup.sif`
    and the setup driver list; handle F6-less installs.
  - Acceptance: install on AHCI default mode without a floppy/USB F6 driver; NVMe after `BOOT-005`.
- `[ ]` **P0 `SETUP-002`** — Install on modern disks (>2 TB, 4Kn).
  - Subtasks: depends on `FS-010` (CDB16) and `BOOT-003` (GPT); verify partitioning, format, and
    boot on 3 TB/4 TB disks and 4Kn-emulated devices.
  - Acceptance: full install + boot + 100 GB write test on a 4 TB disk and a 4Kn device.
- `[ ]` **P1 `SETUP-003`** — Unattended installation.
  - Subtasks: validate `winnt.sif`/`unattend.txt` flows; add driver injection directories; make
    the result deterministic; document the supported keys.
  - Acceptance: a scripted install to a VM with zero interaction, reproducible file list.
- `[ ]` **P1 `SETUP-004`** — Secure Boot and firmware policy documentation.
  - Subtasks: document that Secure Boot must be disabled or a custom key enrolled; provide
    instructions per vendor; detect and warn in setup when Secure Boot blocks boot.
  - Acceptance: `docs/install/firmware.md`; setup shows a clear message rather than a black screen.
- `[ ]` **P1 `SETUP-005`** — Installer driver database.
  - Subtasks: ship a curated driver pack (`DRV-050`); make `setupapi` handle modern INF syntax
    gracefully (unknown directives must not fail the whole install).
  - Acceptance: installing with an INF containing `[Manufacturer]`-level unknown keys succeeds
    with a logged warning.
- `[ ]` **P2 `SETUP-006`** — Upgrade path from XP SP3 / this build's own earlier versions.
  - Subtasks: verify winnt32 upgrade and in-place repair; preserve user data; document caveats.
  - Acceptance: upgrade from a stock XP SP3 VM retains programs and settings (documented subset).
- `[ ]` **P2 `SETUP-007`** — Multi-boot coexistence.
  - Subtasks: do not clobber other bootloaders; support chain-loading from GRUB/systemd-boot;
    document `boot.ini` equivalents.
  - Acceptance: dual-boot with Linux on the same disk; uninstall restores previous bootloader.
- `[ ]` **P2 `SETUP-008`** — Installation media media-check and integrity.
  - Subtasks: add a "verify media" step with CRC/SHA-256 manifest; fail early on bad media.
- `[ ]` **P3 `SETUP-009`** — WIM-based installation (`install.wim`) replacing CAB-per-file.
  - Subtasks: implement or port a WIM writer/reader; measure install time delta.
  - Acceptance: spike report; only proceed if install time improves ≥30 %.

### Phase 1.3 — Recovery

- `[ ]` **P0 `REC-001`** — Bootable recovery environment.
  - Subtasks: a minimal WinPE-like image on the install media with `cmd`, `chkdsk`, `bootcfg`,
    `diskpart`-equivalent, registry editor, file copy, and network driver injection.
  - Acceptance: repairs a deliberately broken boot sector, `boot.ini`, and registry hive from
    the recovery image.
- `[ ]` **P0 `REC-002`** — Offline `chkdsk` that can actually fix modern failures.
  - Subtasks: audit `base/fs/ntfs/chkdsk` for assumptions broken by >2 TB/4Kn/TRIM; fuzz the
    MFT/USN/attribute parsers; ensure it refuses to "fix" a healthy volume when it misparses.
  - Acceptance: `TST-052` fault-injection suite leaves the volume mountable and data intact.
- `[ ]` **P1 `REC-003`** — Offline SFC (`sfc /scannow /offbootdir=/offwindir=`).
- `[ ]` **P1 `REC-004`** — Registry hive repair tooling (load/repair/export from recovery).
- `[ ]` **P1 `REC-005`** — System Restore verification under modern disk layouts.
- `[ ]` **P1 `REC-006`** — Password/reset and account recovery procedure (documented, not a
  backdoor).
- `[ ]` **P2 `REC-007`** — Factory reset (restore to a clean image without media).
- `[ ]` **P2 `REC-008`** — Crash-dump collection and offline analysis from the recovery image.
- `[ ]` **P2 `REC-009`** — Recovery documentation with step-by-step playbooks per failure class.

---

## Phase 2 — Kernel and executive (P0)

**Goal:** the kernel keeps modern hardware alive and does not fall over under modern workloads.
**Depends on:** Phase 0. **Exit:** R2 and R7 green on reference hardware.

### Phase 2.1 — Architecture bring-up

- `[ ]` **P0 `KRN-001`** — Land the AMD64 build as a first-class target (F-18…F-20).
  - Subtasks: wire `base/ntos/ke/amd64` into `ke/sources.inc`; supply the missing
    `base/ntdll/amd64/usrstubs.asm`; create an AMD64 HAL target under `base/hals` (start from
    the x86 ACPI HAL plus the `halacpi/amd64` interrupt/port code); extend `base/boot/lib/amd64`
    transition; add `amd64` to `public/sdk/lib`, `public/ddk/lib` verification; make
    `razzle.cmd Amd64` produce a kernel.
  - Acceptance: `build /cZP` produces a loadable `ntoskrnl.exe` + `hal.dll` for AMD64 and a VM
    boots to `SMSS` (desktop not required for this task).
  - **This is the largest single item in Phase 2. Do not let it block i386 milestones.**
- `[ ]` **P1 `KRN-002`** — AMD64 correctness: paging, PAT, MTRR, TLB shootdown, IPI, context
  switch, exception dispatch.
  - Subtasks: review `base/ntos/mm/amd64/miamd.h`, `initamd.c`, `ke/amd64/trap.asm`,
    `exceptn.c` against the AMD64 ABI; test with CPU stress + context-switch microbenchmarks.
- `[ ]` **P1 `KRN-003`** — WOW64 completeness on AMD64.
  - Subtasks: verify `base/wow64` (cpu, wow64, whnt32, regremap, ntvdm64) builds and runs
    32-bit apps; test registry and filesystem redirection; verify `wow64cpu` context switching.
  - Acceptance: 32-bit test suite (Win32 conformance subset) passes under WOW64.
- `[ ]` **P2 `KRN-004`** — Remove dead architectures from build traversal without deleting sources
  (alpha, axp64, ppc, IA64) and mark them unsupported in the ledger.
- `[ ]` **P3 `KRN-005`** — Design spike: ARM64. **Not scheduled.** Recorded in §10.

### Phase 2.2 — Scheduler and process model

- `[ ]` **P1 `PS-001`** — Scheduler behavior on modern CPUs.
  - Subtasks: measure with 1/2/4/8/16 vCPUs; verify SMT sibling awareness; fix ready-queue lock
    contention (`base/ntos/ke/up|mp`); evaluate per-Processor-Control-Block ready queues; add
    priority-inversion boosting for GUI waits.
  - Acceptance: `TST-080` shows ≤10 % regression vs. a reference XP SP3 VM on identical vCPU
    counts; no starvation in a 16-thread CPU-bound + 1-thread interactive workload.
- `[ ]` **P1 `PS-002`** — Tickless/idle behavior.
  - Subtasks: evaluate moving from periodic timer to a one-shot/deferred timer model; measure
    idle power and timer interrupts per second.
  - Acceptance: idle interrupt rate reduced ≥50 % with no latency regression in `TST-083`.
- `[ ]` **P2 `PS-003`** — `NtCreateUserProcess` and `NtCreateThreadEx` (F-32).
  - Subtasks: implement both in `base/ntos/ps` with full parameter validation; add the user-mode
    prototypes; have `kernel32!CreateProcessInternalW` use the new path behind a flag; keep the
    legacy `NtCreateProcess` path working.
  - Acceptance: modern binaries that call `CreateProcess` with `PROC_THREAD_ATTRIBUTE_*` work;
    Wine's process-creation conformance subset passes.
- `[ ]` **P2 `PS-004`** — Thread naming (`SetThreadDescription`, `GetThreadDescription`) and
  `GetThreadId`/`GetProcessIdOfThread` semantics.
- `[ ]` **P2 `PS-005`** — Job object completeness: nested jobs, `JOB_OBJECT_LIMIT_*` breadth,
  completion ports per job.
- `[ ]` **P2 `PS-006`** — Thread pool API (`CreateThreadpool*`) — many modern runtimes use it.
  - Acceptance: a test harness that exercises work/timer/wait/IO pools passes under stress.
- `[ ]` **P3 `PS-007`** — Processor groups (>64 logical CPUs) (F-39). Tier C spike only.

### Phase 2.3 — Memory manager

- `[ ]` **P0 `MM-001`** — Lift artificial memory caps (F-38).
  - Subtasks: make `MI_DEFAULT_MAX_PAGES` policy-driven rather than licensure-driven; remove
    `ExVerifySuite` memory gating or convert it to a configurable ceiling; verify PAE paths with
    16/32/64 GB.
  - Acceptance: 16 GB usable on x86 PAE and 64 GB on AMD64 in VMs; no PFN-database overrun.
- `[ ]` **P1 `MM-002`** — >4 GB RAM correctness on x86 PAE.
  - Subtasks: audit `mm/pae`, `miamd`-equivalent i386 paths, `MiInsertPageInFreeOrZeroedList`
    with high PFNs; test with memory stress (`sdktools/vmtests/vmstress`).
- `[ ]` **P1 `MM-003`** — Large-page support hardening and automatic promotion.
  - Subtasks: make 2 MB pages usable for more than the kernel image; add a policy for user
    large pages (`SeLockMemoryPrivilege`); measure TLB benefit.
- `[ ]` **P1 `MM-004`** — Working-set and trimming improvements for 8 GB+ machines.
- `[ ]` **P1 `MM-005`** — Section/view accounting and `MEMORY_PARTITION`-free improvements:
  avoid the 32-bit `SIZE_T` assumptions in `mm/creasect.c`.
- `[ ]` **P2 `MM-006`** — Heap hardening (`MT-010`), LFH tuning, heap corruption detection.
- `[ ]` **P2 `MM-007`** — Pagefile: support >4 GB pagefiles on x86 PAE; multiple pagefiles.
- `[ ]` **P3 `MM-008`** — Memory compression / dedup. Tier C; spike only.

### Phase 2.4 — I/O manager, PnP, power, timers

- `[ ]` **P0 `IO-001`** — Enable MSI/MSI-X (F-27).
  - Subtasks: flip `MSI_SUPPORTED` and implement the missing arbiter/routing pieces in
    `base/busdrv/pci/routintf.c`, `utils.c`, `enum.c`; add MSI-X table/PBA mapping; teach the HAL
    to allocate message vectors; validate with a modern NIC and NVMe in a VM.
  - Acceptance: a device that only has MSI works; interrupt counts verified in `!irp`/perfmon;
    no regression on line-based devices.
  - **This is a prerequisite for `DRV-020`, `DRV-021`, `NET-020`.**
- `[ ]` **P1 `IO-002`** — PCI Express support.
  - Subtasks: ECAM/MMCONFIG access, capability parsing for PCIe (AER, LTR, OBFF, ASPM),
    hot-plug attention button, slot power control; test with a QEMU `pcie-port` topology.
  - Acceptance: devices behind a PCIe root port enumerate; hotplug event surfaces to PnP.
- `[ ]` **P1 `IO-003`** — PnP robustness.
  - Subtasks: fix surprise-removal paths; verify `IRP_MN_QUERY_STOP_DEVICE`/`CANCEL_STOP`;
    handle device re-enumeration after a failed start; add a PnP stress harness.
  - Acceptance: 1000 hotplug cycles (USB) with no leak or bugcheck (`TST-051`).
- `[ ]` **P1 `IO-004`** — Power management correctness for modern CPUs.
  - Subtasks: verify C-state entry (`base/ntos/po/idle.c`, `pocall.c`), P-state/thermal throttling,
    S3 on hardware that supports it, S4 hibernate on >4 GB RAM, and battery/AC notifications.
  - Acceptance: S3/S4 resume 50× on a laptop VM with no device loss; hibernate file >4 GB works.
- `[ ]` **P2 `IO-005`** — Runtime PM / selective suspend for USB and PCIe devices.
- `[ ]` **P2 `IO-006`** — High-resolution timers and invariant TSC.
  - Subtasks: detect invariant TSC, use it for `KeQueryPerformanceCounter`; coalesce timers.
  - Acceptance: `QueryPerformanceCounter` monotonic across cores; drift <100 ppm over 24 h.
- `[ ]` **P2 `IO-007`** — IRP cancellation and `CancelIoEx`/`GetOverlappedResultEx` semantics.
- `[ ]` **P2 `IO-008`** — I/O prioritization (background copy vs. interactive).
- `[ ]` **P3 `IO-009`** — KMDF port (Tier C). Spike only; record in §10.

### Phase 2.5 — Kernel hardening (enablers for Phase 3)

- `[ ]` **P0 `SEC-010`** — NX/DEP on x86 PAE (F-23).
  - Subtasks: add `NoExecute` to the PAE PTE definitions (`public/sdk/inc/nti386.h`); set the
    bit for non-executable pages; enable via `/NOEXECUTE=OPTIN|ALWAYSON`; default to OPTIN.
  - Acceptance: DEP is reported by `GetSystemDEPPolicy`; a test executable data page faults;
    no boot regression on 20 VMs.
- `[ ]` **P0 `SEC-011`** — NX on AMD64 for user and kernel stacks; `PAGE_EXECUTE_*` honoured
    correctly (`base/ntos/mm/amd64/miamd.h:631` exists — verify enforcement).
- `[ ]` **P1 `SEC-012`** — Pool and object hardening.
  - Subtasks: pool cookies/headers, freed-allocation poisoning, object-type index validation,
    handle-table bounds checks in `base/ntos/ob`.
  - Acceptance: `MT-020` fuzz corpus does not produce a controllable corruption in 72 h.
- `[ ]` **P1 `SEC-013`** — Kernel stack and IRQL discipline:
  `/GS`-equivalent cookie for kernel, guard pages, stack overflow detection, `KeExpandKernelStack`
  limits.
- `[ ]` **P2 `SEC-014`** — `DbgPrint`/`KdPrint` information-leak sweep; remove verbose debug
  output from free builds.
- `[ ]` **P2 `SEC-015`** — Kernel pointer disclosure mitigations in `NtQuery*` paths.

---

## Phase 3 — Security architecture (P0)

**Goal:** the machine survives contact with a 2026 network and a hostile document.
**Depends on:** Phase 0; benefits from `SEC-010…013`. **Exit:** R5 green; a published baseline
scan is clean; no P0/P1 security bug open.

### Phase 3.1 — Baseline and policy

- `[ ]` **P0 `SEC-001`** — Threat model.
  - Subtasks: define assets (user data, credentials, update channel), adversaries (network,
    malicious document, malicious local app, physical), and trust boundaries (kernel/user,
    session, network). Map each boundary to an enforcement point in this tree.
  - Acceptance: `docs/security/threat-model.md`, reviewed; every mitigation task in Phase 3
    references a threat ID.
- `[ ]` **P0 `SEC-002`** — Secure-by-default configuration.
  - Subtasks: define the shipped defaults for SMB signing, NTLM level, TLS protocols/suites,
    autorun, anonymous shares, LM hash storage, RDP encryption, browser zones; encode them in
    `base/ntsetup/inf` + registry templates; write a test that asserts each default.
  - Acceptance: `TST-090` asserts every default from the policy table; drift fails CI.
- `[ ]` **P1 `SEC-003`** — Security baseline scanner.
  - Subtasks: a tool that checks the running system against `SEC-002` and emits machine-readable
    output; ship it on the install media and in CI.
- `[ ]` **P1 `SEC-004`** — Vulnerability intake process.
  - Subtasks: enable the issue tracker (currently disabled — see §10 `BLK-002`); create a
    security-report path; define severity/SLA; create `docs/security/advisories/` with a template.

### Phase 3.2 — Exploit mitigations

- `[ ]` **P1 `SEC-020`** — ASLR (F-22).
  - Subtasks: randomized image base for DLLs/EXEs honouring `IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE`
    (`base/ntos/mm/creasect.c`, `mm/sysload.c`); relocate when the preferred base is taken;
    randomize PEB/TEB and stack start; add `IMAGE_DLLCHARACTERISTICS_HIGH_ENTROPY_VA` handling on
    AMD64; provide a per-process opt-out via the compatibility DB.
  - Acceptance: 100 loads of a test DLL land on ≥50 distinct bases; system boots with ASLR on;
    `TST-091` confirms a non-ASLR binary still loads.
- `[ ]` **P1 `SEC-021`** — SEHOP.
  - Subtasks: validate the SEH chain on exception dispatch (`base/ntos/ke/*/exceptn.c`,
    `base/ntdll`); per-image opt-out; allow-list for known-broken system binaries.
  - Acceptance: a hand-crafted SEH-overwrite exploit fails; the OS boots and the app corpus runs.
- `[ ]` **P1 `SEC-022`** — `/GS` coverage audit.
  - Subtasks: verify the cookie is initialized in every module (`__security_init_cookie`); ensure
    kernel modules link `/GS`; check that `__security_cookie` is randomized per boot.
- `[ ]` **P2 `SEC-023`** — Heap hardening: terminate-on-corruption, safe unlinking, block headers
  encoded; `RtlSetHeapInformation(HeapEnableTerminationOnCorruption)`.
- `[ ]` **P2 `SEC-024`** — Stack pivot / call-preceded validation (ROP mitigation). Tier C-ish;
  spike only.
- `[ ]` **P3 `SEC-025`** — Kernel CFG (`/guard:cf`) — requires a compiler upgrade (`ENV-006`);
  record as Tier C.

### Phase 3.3 — Process isolation and privilege

- `[ ]` **P1 `SEC-030`** — Integrity levels and UIPI.
  - Subtasks: add mandatory integrity control to the token (`base/ntos/se`), IL in the SACL,
    `CreateRestrictedToken` integration, `ChangeWindowMessageFilter`; default system processes to
    System/High and user apps to Medium.
  - Acceptance: a Medium-IL process cannot `SendMessage`/`WriteProcessMemory` to a High-IL
    process; existing apps still run (with documented exceptions).
  - **This is a prerequisite for meaningful browser sandboxing.**
- `[ ]` **P1 `SEC-031`** — Privilege model audit.
  - Subtasks: enumerate every `SePrivilegeCheck` call site; find places where a privilege is
    checked but not enabled/validated; fuzz `NtAdjustPrivilegesToken` inputs.
- `[ ]` **P2 `SEC-032`** — Low-integrity sandbox for the browser and untrusted viewers.
- `[ ]` **P2 `SEC-033`** — Service isolation: per-service SIDs, restricted tokens for network
  services (XP-era services often run as SYSTEM).
- `[ ]` **P3 `SEC-034`** — AppContainer equivalent. Tier C; record in §10.
- `[ ]` **P3 `SEC-035`** — Credential Guard / LSA protection. Tier C.

### Phase 3.4 — Attack-surface reduction

- `[ ]` **P0 `SEC-040`** — Disable SMB1/LM/NTLMv1 by default (server and client).
  - Subtasks: registry defaults, `LmCompatibilityLevel=5`, `SMB1=0`, refuse anonymous sessions;
    verify against a modern SMB2-only server (see `NET-040`).
- `[ ]` **P0 `SEC-041`** — Remove/disable obsolete network listeners and services by default:
  NetBEUI, IPX/SPX, DLC, IrDA, RAS/server roles, IIS (unless explicitly enabled), Telnet,
  SMTP/NNTP, Indexing Service, Remote Registry, UPnP SSDP.
  - Subtasks: SKU/INF-level removal, not just "stopped"; document how to re-enable.
  - Acceptance: a default install exposes only the ports listed in `SEC-002`; verified with an
    external `nmap` from another VM.
- `[ ]` **P1 `SEC-042`** — Parser hardening for document and media formats.
  - Subtasks: font parsers (`windows/core/ntgdi`), metafiles (WMF/EMF), `richedit`, `mshtml`,
    image codecs (GDI+), OLE compound files; enable heap termination; fuzz each (see `TST-100`).
- `[ ]` **P1 `SEC-043`** — `win32k` hardening: object type confusion, user-pointer validation
  (`ProbeFor*`), callback validation.
- `[ ]` **P1 `SEC-044`** — RPC endpoint security review; require authentication on sensitive
  interfaces; remove `ncacn_np` interfaces with `RPC_C_AUTHN_LEVEL_NONE` where possible.
- `[ ]` **P2 `SEC-045`** — Autorun/autoplay policy: disable autorun for removable media.
- `[ ]` **P2 `SEC-046`** — Macro/script host policy: WSH, Office macros, ActiveX kill-bits.
- `[ ]` **P2 `SEC-047`** — Firewall defaults: block inbound by default except explicit rules.
- `[ ]` **P2 `SEC-048`** — Audit policy defaults and log integrity (event log wrapping).

### Phase 3.5 — Code integrity and update trust

- `[ ]` **P1 `SEC-050`** — Kernel-mode code signing (KMCS) with SHA-256.
  - Subtasks: extend the PE signature checks in `base/ntos/se`/`ci` paths to SHA-256 and
    catalog-based signatures; enforce on 64-bit; policy for test-signing mode.
- `[ ]` **P1 `SEC-051`** — User-mode code integrity policy (driver + system DLL protection).
- `[ ]` **P2 `SEC-052`** — Trusted installer / update signing chain (`REL-020`).
- `[ ]` **P3 `SEC-053`** — Measured boot / TPM 2.0. Tier C.

### Phase 3.6 — Cryptography and PKI

- `[ ]` **P0 `CRY-001`** — TLS 1.2 (RFC 5246) in Schannel (F-25).
  - Subtasks: add protocol version 3.3; the SHA-256 PRF (RFC 5246 §5); AEAD suites
    `TLS_RSA_WITH_AES_128_GCM_SHA256`, `TLS_ECDHE_RSA_WITH_AES_128_GCM_SHA256`,
    `…_AES_256_GCM_SHA384`; ECDHE (P-256/P-384); signature_algorithms extension; SNI (RFC 6066);
    `CertificateRequest` with SHA-256; secure renegotiation (RFC 5746); extended master secret
    (RFC 7627); session ticket stubs. Keep the existing record layer where correct.
  - Acceptance: negotiates TLS 1.2 with `openssl s_client` and with a modern public site; passes
    the TLS 1.2 subset of a public test suite; no downgrade to TLS 1.0 when 1.2 is offered.
- `[ ]` **P0 `CRY-002`** — Server-side TLS 1.2 (IIS/Schannel server role).
  - Subtasks: cipher selection, certificate chain building with SHA-256, ALPN extension (required
    for HTTP/2).
  - Acceptance: a modern browser connects to the in-box web server over TLS 1.2 with HSTS-capable
    ciphers; hostname validation works.
- `[ ]` **P1 `CRY-003`** — SHA-256/384/512 in CryptoAPI and the internal crypto library.
  - Subtasks: implement/provide `CALG_SHA_256/384/512` (`public/sdk/inc/wincrypt.h:240` already
    declares some ALG_IDs); HMAC-SHA2; PBKDF2; wire into certificate chain validation.
  - Acceptance: `CertVerifyCertificateChainPolicy` accepts a SHA-256-signed chain to a modern root.
- `[ ]` **P1 `CRY-004`** — AES-GCM and AES-CBC in the crypto provider; AES-NI acceleration.
  - Subtasks: constant-time GHASH; CPU feature detection (`cpuid`); fallback path for old CPUs;
    test vectors from NIST CAVP.
- `[ ]` **P2 `CRY-005`** — ECDSA/ECDH P-256/P-384; RSA 3072/4096 support and key-size limits.
- `[ ]` **P2 `CRY-006`** — CNG (`bcrypt.dll`/`ncrypt.dll`) compatibility layer (see `API-040`).
- `[ ]` **P0 `CRY-007`** — Disable legacy protocols and ciphers by default (F-25).
  - Subtasks: SSL2/SSL3/PCT off; RC4 off; 3DES off; TLS 1.0 off unless compatibility mode is
    explicitly enabled; remove the `ssl2*`/`pct1*` code paths from reachable state machines.
  - Acceptance: a scanner (e.g. `testssl.sh` equivalent) reports only TLS 1.2 with AEAD suites.
- `[ ]` **P1 `CRY-008`** — Certificate chain engine modernization.
  - Subtasks: SHA-256 signatures, `nameConstraints`, `policyConstraints`, `basicConstraints`
    `pathLen` enforcement, AIA/CRL/OCSP fetch over HTTPS (depends on `CRY-001`), CT log
    expectations (advisory), modern root store with an update mechanism (`REL-016`).
  - Acceptance: validates a modern public chain; rejects a deliberately malformed
    `nameConstraints` chain; root store updatable without reinstalling.
- `[ ]` **P1 `CRY-009`** — PKCS#12/PFX PBES2 (AES-256) import/export.
- `[ ]` **P2 `CRY-010`** — RNG hardening: seed from `RDRAND`/`RDSEED` when available, mix with
  the existing entropy sources, never block at boot without a hardware source.
- `[ ]` **P2 `CRY-011`** — EFS: verify AES-256 path (`ds/security/base/lsa/server/efssrv.cxx`
  selects `CALG_AES_256`); add key backup/escrow documentation; test recovery agent flows.
- `[ ]` **P3 `CRY-012`** — TLS 1.3 (RFC 8446). Tier C for the record layer rewrite; spike only.
- `[ ]` **P3 `CRY-013`** — Post-quantum hybrids (X25519MLKEM768). Not scheduled; note in §10.

### Phase 3.7 — Authentication and identity

- `[ ]` **P0 `AUTH-001`** — Eliminate LM and NTLMv1 (client + server).
  - Subtasks: `NoLMHash`, `LmCompatibilityLevel=5`, remove LM response generation, reject NTLMv1
    at the SSPI layer, log downgrade attempts.
  - Acceptance: an NTLMv1-only client fails with a clear error; modern NTLMv2/Kerberos works.
- `[ ]` **P1 `AUTH-002`** — Kerberos AES (RFC 3962) and AES-SHA2 (RFC 8009) (F-26).
  - Subtasks: etype implementations, key derivation, PAC signatures with AES, `msDS-SupportedEncryptionTypes`
    behaviour, interop test against a modern KDC.
  - Acceptance: obtains a ticket from a Windows Server 2019+ KDC using AES256-CTS; no RC4 fallback.
- `[ ]` **P1 `AUTH-003`** — Smart card minidriver model.
  - Subtasks: the in-tree CSPs are smartcard-specific (`ds/security/csps/*`); add the
    Base CSP/minidriver interface so modern cards work without a vendor CSP port.
  - Acceptance: a modern PIV card can be used for logon via a minidriver.
- `[ ]` **P2 `AUTH-004`** — Credential provider model (Vista+) or a compatible shim; needed for
  modern logon UI and third-party providers.
- `[ ]` **P2 `AUTH-005`** — Password policy hardening (length, history, lockout) and a documented
  local-admin recovery path.
- `[ ]` **P2 `AUTH-006`** — SSPI/Negotiate correctness against modern servers; `CredSSP` fixes.
- `[ ]` **P3 `AUTH-007`** — TPM-backed key storage / Windows Hello equivalent. Tier C.

---

## Phase 4 — Drivers, PnP and hardware support (P0/P1)

**Goal:** a 2015–2020 era PC (and a safe subset of 2020s hardware) installs, boots, and has
working storage, network, display, audio, USB, input and power.
**Depends on:** `IO-001` (MSI), `SEC-010/011` (mitigations must not be broken by drivers).
**Exit:** a published hardware compatibility list (`TST-042`) with ≥¼ of the HCL at "works".

### Phase 4.1 — Driver infrastructure

- `[ ]` **P0 `DRV-001`** — INF and driver-installation modernization.
  - Subtasks: tolerate Vista+ INF directives (`Include`/`Needs` breadth, `AddPowerSetting`,
    `PnpLockdown`, `DriverPackageType`), implement `SetupDi*` missing APIs used by modern
    installers, add a driver store (staging + rollback), surface actionable errors.
  - Acceptance: three real vendor driver packages (a NIC, an audio device, a printer) install
    from INF without manual editing; each can be rolled back.
- `[ ]` **P0 `DRV-002`** — Driver signing and catalogue handling with SHA-256.
  - Subtasks: `makecat`/`signtool` equivalents in-tree, PE hash algorithm negotiation, catalog
    validation at install.
  - Acceptance: a SHA-256 catalog validates; a tampered catalog is rejected with a clear error.
- `[ ]` **P1 `DRV-003`** — Driver Verifier coverage for new code.
  - Subtasks: enable the existing verifier (`base/ntos/verifier`) in CI VMs; add IRQL, pool,
    and PnP checks to the default test image; triage every hit.
- `[ ]` **P1 `DRV-004`** — DMA and IOMMU policy.
  - Subtasks: 64-bit DMA (`DMA_ADAPTER` limits), bounce-buffer correctness >4 GB, document that
    VT-d/AMD-Vi is not supported (Tier C) and why that matters for untrusted devices.
- `[ ]` **P1 `DRV-005`** — Device power states: D3cold, `IRP_MN_SET_POWER` correctness, wake
  armed from S3/S4.
- `[ ]` **P2 `DRV-006`** — Driver unload/reload robustness and leak checking.
- `[ ]` **P2 `DRV-007`** — WMI provider coverage for new devices (battery, thermal, NIC link).
- `[ ]` **P3 `DRV-008`** — KMDF port. Tier C; §10.

### Phase 4.2 — Storage

- `[ ]` **P0 `DRV-010`** — AHCI/SATA driver in-box (not just IDE compatibility mode).
  - Subtasks: port or write a SATA AHCI miniport with NCQ, hot-plug, port multiplier rejection,
    power management; integrate with `storport`/`scsiport`; add to `txtsetup` (`SETUP-001`).
  - Acceptance: 500 MB/s+ sequential on a SATA SSD in a VM and on real hardware; hot-plug works.
- `[ ]` **P0 `DRV-011`** — NVMe driver.
  - Subtasks: admin/IO queues, MSI-X (requires `IO-001`), PRP lists, namespace scan, SMART/health
    log, power states; align with the boot driver (`BOOT-005`).
  - Acceptance: NVMe SSD reaches ≥80 % of its rated sequential throughput in a VM; no timeout
    under 8-queue stress (`TST-053`).
- `[ ]` **P1 `DRV-012`** — USB attached SCSI (UASP) and USB mass storage robustness.
- `[ ]` **P1 `DRV-013`** — SD/eMMC support (some laptops have no SATA).
- `[ ]` **P2 `DRV-014`** — RAID: Intel RST/AMD RAID metadata recognition (read-only at minimum).
- `[ ]` **P2 `DRV-015`** — Optical: verify Blu-ray/UDF 2.5+ with the updated `udfs`.
- `[ ]` **P2 `DRV-016`** — SMART/health monitoring surfaced to the OS and a user tool.
- `[ ]` **P2 `DRV-017`** — TRIM/UNMAP plumbing end-to-end (`FS-012`).

### Phase 4.3 — USB and input

- `[ ]` **P0 `DRV-020`** — xHCI (USB 3.x) host controller driver.
  - Subtasks: rings, TRBs, endpoint contexts, port state machine, USB 2.0 companion routing,
    MSI-X, suspend/resume; reuse the existing USB core (`drivers/wdm/usb/usbd`, `usbport`).
  - Acceptance: USB 3 stick at ≥200 MB/s; keyboard/mouse on a USB 3 port at boot; 1000 hotplug
    cycles clean.
  - **Largest driver item after NDIS 6. Treat as its own milestone.**
- `[ ]` **P1 `DRV-021`** — EHCI/OHCI/UHCI correctness on modern chipsets (they are emulated via
  xHCI on many systems; verify actual fallback behaviour).
- `[ ]` **P1 `DRV-022`** — USB HID: modern report descriptors, consumer-control pages, composite
  devices, `usbccgp` fixes.
- `[ ]` **P1 `DRV-023`** — Precision touchpad / I2C HID (`HIDI2C`).
  - Subtasks: I2C controller driver (Intel LPSS/AMD), HID over I2C, multitouch report parsing,
    gestures; fall back to PS/2 emulation when unavailable.
  - Acceptance: two-finger scroll and tap-to-click work on a 2018+ laptop.
- `[ ]` **P2 `DRV-024`** — USB audio class 2 (`AUD-004`), USB video class (`MMD-030`).
- `[ ]` **P2 `DRV-025`** — USB tethering / RNDIS for phones (`net/rndis` exists; verify).
- `[ ]` **P3 `DRV-026`** — USB4/Thunderbolt. Tier C; no path without PCIe tunneling work.

### Phase 4.4 — Networking hardware

- `[ ]` **P0 `DRV-030`** — NDIS 6.x compatibility layer (F-46).
  - Subtasks: evaluate two paths — (a) implement an NDIS 6.0/6.20 shim over the existing 5.1 core
    (miniport-facing translation, `NET_BUFFER_LIST`, `NDIS_OID_REQUEST`, receive-side
    throttling, RSS stubs), or (b) port the NDIS 6 core from a compatible source. Choose after a
    4-week spike; record decision in `docs/design/ndis6.md`.
  - Acceptance: an unmodified NDIS 6 miniport (Intel e1000e from a Windows 7 driver package)
    loads and passes 1 Gbit throughput + 24 h soak.
  - **This gates Wi-Fi, modern NICs, and RSS/offload.**
- `[ ]` **P0 `DRV-031`** — In-box drivers for common wired NICs (Intel 8257x/I21x, Realtek
  8168/8125, Broadcom NetXtreme) — via NDIS 6 shim where the driver is 6.x-only.
- `[ ]` **P1 `DRV-032`** — Wi-Fi: 802.11n/ac drivers + WPA2/WPA3 supplicant (`NET-050`).
- `[ ]` **P1 `DRV-033`** — Checksum/LSO/RSS offload correctness (needed for >1 Gbit).
- `[ ]` **P2 `DRV-034`** — 2.5G/10G Ethernet validation and jumbo frames.
- `[ ]` **P3 `DRV-035`** — WWAN/5G modems (MBIM). Tier C.
- `[ ]` **P3 `DRV-036`** — Bluetooth stack (F-36). Tier C/Tier B spike; see §10.

### Phase 4.5 — Display and graphics

- `[ ]` **P0 `GFX-001`** — Usable display on any machine without a vendor driver.
  - Subtasks: VESA/VBE 2.0+ modes, UEFI GOP framebuffer driver, EDID parsing for native
    resolution, multi-monitor via framebuffer where possible; 1920×1080 and 2560×1440 at 60 Hz.
  - Acceptance: installs and reaches native resolution on 5 machines with no GPU driver.
- `[ ]` **P1 `GFX-002`** — XDDM driver compatibility for GPUs that still have XP drivers
  (through ~2010): Intel GMA, NVIDIA 6/7/8-series era, AMD/ATI X1000-HD4000 era.
  - Acceptance: hardware acceleration and video overlay work on ≥2 such GPUs.
- `[ ]` **P1 `GFX-003`** — DPI scaling: `SetProcessDPIAware`, per-monitor awareness (`API-070`),
    font metrics, shell scaling.
- `[ ]` **P1 `GFX-004`** — Multi-monitor topology, hotplug, rotation, and `ChangeDisplaySettingsEx`.
- `[ ]` **P2 `GFX-005`** — Software rendering performance for modern resolutions (GDI+ and
  D3D8/9 software paths).
- `[ ]` **P2 `GFX-006`** — Mesa port for OpenGL 3.3+ (`GFX-020`).
- `[ ]` **P3 `GFX-007`** — WDDM-class display model. Tier C; §10.

### Phase 4.6 — Audio hardware

- `[ ]` **P0 `AUD-001`** — Intel HDA controller driver in-box.
  - Subtasks: HDA controller + codec widget parsing, jack detection, multiple codecs, HDMI audio
    (at least enumeration); MSI support (`IO-001`).
  - Acceptance: audio playback and capture on 3 machines; jack detection events reach the shell.
- `[ ]` **P1 `AUD-002`** — USB Audio Class 2 support.
  - Subtasks: the in-tree `drivers/wdm/audio/drivers/usbaudio` and its `usbaudio.2` copy implement
    UAC1; add UAC2 descriptor parsing (Clock Source/Selector, `bTerminalLink`), 24-bit formats,
    explicit feedback endpoints, and alternate-setting negotiation.
  - Acceptance: a UAC2 DAC plays 24-bit/96 kHz without resampling artefacts.
- `[ ]` **P2 `AUD-003`** — Bluetooth audio (depends on `DRV-036`).
- `[ ]` **P2 `AUD-004`** — Audio endpoints: default device selection, per-app routing,
  communications device role.

### Phase 4.7 — Power, thermal, battery, platform

- `[ ]` **P1 `DRV-040`** — ACPI battery/AC/thermal correctness on modern ECs.
  - Subtasks: `_BST`/`_BIF`/`_BIX` handling (including the modern `_BIX`), thermal zones,
    active/passive cooling, fan control pass-through.
- `[ ]` **P1 `DRV-041`** — CPU power: SpeedStep/Cool'n'Quiet, HWP where exposed via ACPI, C-states.
- `[ ]` **P2 `DRV-042`** — Lid/button/dock events; `WM_POWERBROADCAST` correctness.
- `[ ]` **P3 `DRV-043`** — Modern Standby (S0ix). Tier C; §10.

### Phase 4.8 — Peripherals and imaging

- `[ ]` **P1 `DRV-050`** — Printer support: in-box PCL5/PCL6/PostScript drivers, IPP printing
  (`NET-070`), scanner WIA drivers for modern flatbeds.
- `[ ]` **P2 `DRV-051`** — Webcam/UVC capture (`MMD-030`).
- `[ ]` **P2 `DRV-052`** — Smart card readers (CCID) and TPM 1.2 devices.
- `[ ]` **P2 `DRV-053`** — Gamepads/XInput-compatible HID devices.
- `[ ]` **P3 `DRV-054`** — Fingerprint sensors. Tier C (vendor SDK dependency).

### Phase 4.9 — Hardware compatibility program

- `[ ]` **P0 `DRV-060`** — HCL: enumerate reference machines and their status.
  - Subtasks: pick 6 physical targets spanning 2008–2020 (one laptop with S3, one desktop with
    NVMe, one with only USB 3, one legacy BIOS, one UEFI-CSM, one with 16 GB RAM); record exact
    chipsets; test boot/install/each subsystem; publish a table.
  - Acceptance: `docs/hcl.md` with per-machine pass/fail per subsystem and a bug ID for each fail.

---

## Phase 5 — Modern API and ABI compatibility layer (P1, highest value per effort)

**Goal:** modern binaries load, link against the DLLs they expect, and find the entry points they
call. This is the NT 5.1 equivalent of the "OneCore API" backport project.
**Depends on:** Phase 0; `PS-003` (process APIs); `CRY-003/004` (for `bcrypt`).
**Exit:** a defined "Modern App Baseline" (`API-100`) launches and runs.

### Phase 5.1 — The single most important fix

- `[ ]` **P0 `API-001`** — Stop rejecting modern subsystem versions (F-31).
  - Subtasks: `BasepIsImageVersionOk` (`base/win32/client/process.c:194-215`) must accept
    subsystem versions up to the maximum the image loader can actually honour (start with 10.0);
    also check `base/ntdll/ldrsnap.c` and any `MajorSubsystemVersion` gates; add a policy key to
    restore strict behaviour; test both PE32 and PE32+.
  - Acceptance: a "hello world" built with a modern MSVC and `/SUBSYSTEM:6.0` runs on this OS;
    a deliberately corrupt subsystem version still fails; the compatibility DB can opt a binary
    back into strict mode.
  - **Do this first. It converts "nothing runs" into "things run and fail at a specific API",
    which is what makes the rest of Phase 5 measurable.**

### Phase 5.1a — OneCore-API integration track

- `[ ]` **P1 `API-005`** — Decide and execute the One-Core-API relationship.
  - Context: [One-Core-API](https://github.com/shorthorn-project) is the established community
    backport of Vista+ APIs to XP/2003. It solves a large part of Phase 5.3–5.5. Re-implementing it
    from scratch would waste the budget; depending on it blindly would import unknown behaviour
    and licensing.
  - Subtasks:
    1. Inventory the upstream: which DLLs it ships (`kernelbase`, `bcrypt`, `combase`, `shcore`,
       `ucrtbase`, `vcruntime`, `d3d11`, `dxgi`, `mfplat`, …), which exports it implements, which
       it stubs, and which of its DLLs conflict with in-tree versions.
    2. Licence review (`GOV-004`): code licence per DLL, redistribution terms, and whether the
       build must remain a separate component rather than being merged into `ntdll`/`kernel32`.
    3. Compatibility test: install the upstream binaries on a stock, unmodified build of *this*
       tree and run the `API-100` baseline. Record which gaps it closes and which remain
       (this gives an empirical map before writing any code).
    4. Choose a model: (a) vendor the upstream as an optional compatibility pack with its own
       versioning, (b) absorb specific implementations into in-tree modules with attribution,
       (c) re-implement the export surface natively and use upstream only as a reference.
    5. Whichever model: pin a version, add it to the SBOM, run it through `TST-010` and `TST-070`,
       and document the exact export set in `docs/api/onecore-integration.md`.
  - Acceptance: a written decision record; the baseline pass-rate delta is measured and published;
    every absorbed file carries licence metadata; no silent dependency on an unpinned binary.
  - **Anti-goal:** do not claim "OneCore supported" as a feature. Compatibility is measured by the
    app matrix, not by the presence of a DLL.

### Phase 5.2 — Loader and API-set infrastructure

- `[ ]` **P1 `API-010`** — API sets (`api-ms-win-*.dll`) and schema.
  - Subtasks: implement the apiset resolution mechanism in the loader (`base/ntdll/ldrapi.c`,
    `ldrsnap.c`): parse `apisetschema` (or an equivalent schema resource), map `api-ms-win-core-*`
    to the implementing DLL, support forwarded exports and `ApiSetContract` versioning; generate
    stub DLLs where a host DLL does not exist.
  - Acceptance: a modern app importing `api-ms-win-core-file-l1-1-0.dll` and
    `api-ms-win-core-synch-l1-2-0.dll` loads; unresolved sets produce a clear diagnostic rather
    than a cryptic `STATUS_DLL_NOT_FOUND`.
- `[ ]` **P1 `API-011`** — Export table expansion, systematically.
  - Subtasks: build a machine-readable gap list (modern SDK import libraries vs. this tree's
    `.def`/`.src` files) for `kernel32`, `ntdll`, `user32`, `gdi32`, `advapi32`, `ole32`,
    `shell32`, `shlwapi`, `ws2_32`, `crypt32`; publish it as `docs/api/gap-matrix.md`; implement
    in descending order of observed demand from real applications.
  - Acceptance: the gap list is generated by a script (`DX-010`) and regenerated per release;
    ≥60 % of `kernel32` imports used by a sample of 50 modern binaries resolve.
- `[ ]` **P1 `API-012`** — `KERNELBASE.dll` facade.
  - Subtasks: modern `kernel32` forwards most of its implementation to `KERNELBASE`; either
    implement a real `KERNELBASE` and forward, or provide a forwarding DLL so binaries importing
    it directly (common in modern builds) load.
- `[ ]` **P2 `API-013`** — Forwarder stubs for `combase.dll`, `shcore.dll`, `dwmapi.dll`,
  `uxtheme.dll`, `powrprof.dll`, `userenv.dll`, `iphlpapi.dll`, `bcrypt.dll`, `ncrypt.dll`,
  `winhttp.dll`, `d3d11.dll`, `dxgi.dll`, `mfplat.dll`, `propsys.dll`, `d2d1.dll`.
  - Rule: a stub must return a documented failure (`E_NOTIMPL`/`ERROR_CALL_NOT_IMPLEMENTED`),
    never crash, and never silently claim success.

### Phase 5.3 — Core NT API additions

- `[ ]` **P1 `API-020`** — `ntdll` additions.
  - Subtasks (each with parameter validation and a conformance test):
    `NtCreateUserProcess`, `NtCreateThreadEx` (see `PS-003`), `NtQueryInformationProcess`
    classes `ProcessImageFileNameWin32`, `ProcessCommandLineInformation`,
    `ProcessMitigationPolicy`, `NtQuerySystemInformation` classes `SystemExtendedProcessInformation`,
    `SystemLogicalProcessorInformationEx` (stub with correct failure), `NtQueryObject`
    `ObjectTypesInformation`, `NtCreateSymbolicLinkObject`, `NtDuplicateToken` breadth,
    `NtQueryInformationToken` `TokenIntegrityLevel` (after `SEC-030`).
  - Acceptance: Wine conformance subset for each added function passes (`TST-010`).
- `[ ]` **P1 `API-021`** — Synchronization primitives.
  - Subtasks: SRW locks (`InitializeSRWLock`, `AcquireSRWLockExclusive/Shared`,
    `TryAcquire*`), condition variables (`InitializeConditionVariable`, `SleepConditionVariable*`),
    `WaitOnAddress`/`WakeByAddressSingle/All` (Win8) implemented over existing kernel objects;
    `InitializeCriticalSectionEx`, `CreateEventEx`, `CreateMutexEx`, `CreateSemaphoreEx`.
  - Acceptance: stress test with 64 threads × 10⁷ operations, no lost wakeups, no deadlock.
- `[ ]` **P1 `API-022`** — Time and file APIs.
  - Subtasks: `GetTickCount64`, `GetSystemTimePreciseAsFileTime`, `GetSystemTimeAdjustmentPrecise`,
    `CreateFile2`, `GetFinalPathNameByHandleW`, `SetFileInformationByHandle`
    (`FileDispositionInfoEx`, `FileRenameInfoEx`), `GetVolumeInformationByHandleW`,
    `ReOpenFile`, `GetCompressedFileSizeW` correctness, `CopyFile2`.
  - Acceptance: a runtime smoke test (Python/Node-style file workload) passes.
- `[ ]` **P2 `API-023`** — Job/thread/process extensions.
  - Subtasks: `SetThreadDescription`/`GetThreadDescription`, `GetProcessMitigationPolicy` (stub
    with real values for DEP/ASLR), `SetProcessMitigationPolicy` (honour what we implement),
    `QueryFullProcessImageNameW`, `GetProcessIdOfThread`, `IsProcessCritical`,
    `SetProcessDEPPolicy`, `SetProcessDPIAware`, `SetThreadStackGuarantee`.
- `[ ]` **P2 `API-024`** — Long path support (> `MAX_PATH`) (Tier B).
  - Subtasks: `\\?\` handling breadth in `base/win32/client/file.c`, `RtlDosPathNameToNtPathName`,
    shell APIs, and `longPathAware` manifest opt-in.
  - Acceptance: create/read/write a 32,000-character path via the Win32 API; Explorer can browse it
    only if the shell work lands.

### Phase 5.4 — Runtimes and CRT

- `[ ]` **P0 `API-030`** — Modern C runtime compatibility.
  - Subtasks: evaluate three options and pick one:
    (a) port `ucrtbase` from a permissively-licensed source, (b) implement a shim over the
    existing `base/crts` with the modern export surface, (c) ship app-local CRT redistributables
    and provide only the OS-level dependencies they need. Requirements regardless of choice:
    `_s` functions, `strsafe`, `swprintf_s`, `__stdio_common_vfprintf`, locale `_locale_t`,
    `_set_invalid_parameter_handler`, `__C_specific_handler`, `_configthreadlocale`.
  - Acceptance: a modern MSVC-compiled binary linking `ucrtbase.dll` + `vcruntime140.dll` starts
    and performs file/console/string operations correctly.
- `[ ]` **P1 `API-031`** — MSVC runtime DLLs (`vcruntime140`, `vcruntime140_1`, `msvcp140`,
  `concrt140`) availability strategy.
  - Subtasks: determine whether redistribution of the Microsoft CRT is permitted in this project
    (`GOV-004`); if not, implement compatible DLLs or require app-local deployment and document it.
  - Acceptance: documented decision + a matrix of which runtimes work when app-local.
- `[ ]` **P2 `API-032`** — C++ standard library ABI support: exceptions (`__CxxFrameHandler3/4`),
  RTTI, `std::filesystem` dependencies, thread-local statics (`__dyn_tls_init`).
- `[ ]` **P2 `API-033`** — `mscoree.dll` / CLR hosting shim so .NET Framework apps at least fail
  gracefully, then work via `API-060`.
- `[ ]` **P3 `API-034`** — Full UCRT port with locale data (`LOC-010`).

### Phase 5.5 — COM, DPI, console, shell surface

- `[ ]` **P1 `API-040`** — CNG (`bcrypt`/`ncrypt`) layer over the in-tree crypto.
  - Subtasks: algorithm provider model, `BCryptOpenAlgorithmProvider` for SHA-256/AES-GCM/RSA/ECDSA,
    `BCryptGenRandom`, `NCrypt*` for key storage (machine/user), property model, key import/export.
  - Acceptance: a modern binary that uses `bcrypt` for SHA-256 + AES-GCM produces correct output
    against NIST vectors.
- `[ ]` **P1 `API-041`** — `combase.dll` / modern COM initialization.
  - Subtasks: `RoInitialize`/`RoUninitialize`, `CoInitializeEx` breadth (apartments already exist),
    agile references, `CoGetApartmentType`, `CoWaitForMultipleHandles`, `CoResumeClassObjects`,
    `CoRegisterActivationFilter` (stub), `IInitializeSpy` already present — verify.
  - Acceptance: a modern COM client (e.g. a WinRT-free app using `IStream`) works; STA/MTA
    cross-apartment calls pass a stress test.
- `[ ]` **P1 `API-050`** — Console: VT/ANSI and modern console APIs (F-34).
  - Subtasks: implement VT100/xterm escape processing in `windows/core/ntcon`; enable via
    `ENABLE_VIRTUAL_TERMINAL_PROCESSING`; support 24-bit colour, alternate screen buffer,
    `GetConsoleScreenBufferInfoEx`, `SetConsoleWindowInfo`, `ReadConsoleInput` with window events,
    `WriteConsoleW` bulk performance; add a ConPTY-like pseudo-console (needed by modern terminals
    and by IDEs).
  - Acceptance: `cmd`-hosted `less`, `git log --color`, and a Node/Python REPL render correctly;
    a PTY-based test harness passes.
- `[ ]` **P1 `API-051`** — DPI awareness.
  - Subtasks: `SetProcessDPIAware` (system DPI), per-monitor v2 (`SetProcessDpiAwarenessContext`),
    `GetDpiForWindow`, `AdjustWindowRectExForDpi`, shell scaling, non-client area scaling, bitmap
    stretching policy.
  - Acceptance: a 4K display at 200 % renders text and dialogs legibly; legacy apps are
    bitmap-scaled, not clipped.
- `[ ]` **P2 `API-052`** — Shell API additions used by modern installers: `SHGetKnownFolderPath`,
  `SHCreateItemFromParsingName`, `IFileOpenDialog` (replacing `GetOpenFileName`),
  `PathCch*` functions, `SHGetPropertyStoreFromParsingName` (stub), `IApplicationAssociationRegistration`.
- `[ ]` **P2 `API-053`** — `propsys` property system (`IPropertyStore`, `PROPVARIANT` helpers)
  — used widely by modern shell and media code.
- `[ ]` **P2 `API-054`** — Manifest handling in the loader: `trustInfo` (parse, do not enforce),
  `compatibility`/`supportedOS` GUIDs, `dpiAware`/`dpiAwareness`, `longPathAware`,
  `activeCodePage`, `gdiScaling`; store in the process and expose to `GetProcessMitigationPolicy`.
  - Acceptance: a manifest-driven DPI test app behaves as declared; an unknown element does not
    prevent load (SxS `nodefactory.cpp` currently validates strictly — verify and relax).
- `[ ]` **P2 `API-055`** — Version-lie policy.
  - Subtasks: keep `RtlGetVersion` truthful; implement a compatibility-database-driven "version
    lie" used only when an app declares `supportedOS`/is shimmed; never lie globally.
  - Acceptance: no system component depends on a lie; `VerifyVersionInfo` shims are per-app.

- `[ ]` **P2 `API-056`** — In-box library semantics modernization (not just new exports).
  - Subtasks: audit the behavioural differences that break modern code even when the symbol
    exists — `CreateFile` sharing/`FILE_SHARE_DELETE`, `MoveFileEx` atomicity,
    `GetFileAttributes` on symlinks, `WaitForSingleObject` on file handles, `ReadFile` with
    overlapped+NULL offset, `CreateProcess` quoting rules, `LoadLibrary` search order
    (`SetDefaultDllDirectories`/`AddDllDirectory`/`LoadLibraryEx` flags), `GetModuleFileName`
    truncation, `FormatMessage` with `%1` width specifiers.
  - Acceptance: each difference has a conformance test from `TST-010` proving parity with the
    documented modern behaviour, or a documented, deliberate divergence.

- `[ ]` **P2 `API-057`** — `user32`/`gdi32` breadth for modern UI code.
  - Subtasks: pointer/touch input (`WM_POINTER*`, `GetPointerInfo`, `EnableMouseInPointer`),
    `GetSystemMetricsForDpi`, `EnableNonClientDpiScaling`, `SetWindowCompositionAttribute` (no-op
    with a documented contract), `AddFontMemResourceEx`/`RemoveFontMemResourceEx`,
    `GetDCEx`/`BP_PAINTER` correctness, `AlphaBlend`/`TransparentBlt` edge cases,
    `GdiAlphaBlend` with premultiplied alpha.
  - Acceptance: a modern Qt/WinForms app draws correctly at 100 % and 200 % DPI; touch events
    arrive as pointer messages on a touchscreen VM.
- `[ ]` **P3 `API-058`** — DirectWrite/Direct2D availability.
  - Subtasks: decide between (a) implementing `dwrite` over GDI/Uniscribe with a limited factory
    surface, (b) porting a text shaper, (c) shipping stub DLLs that fail cleanly so apps fall back
    to GDI. Note that Electron/Chromium and modern .NET require real DirectWrite.
  - Acceptance: a documented decision + a test proving apps either get working text or a clean
    fallback, never a crash.

### Phase 5.6 — Managed runtimes and large frameworks

- `[ ]` **P2 `API-060`** — .NET runtime strategy (F-37).
  - Subtasks: pick a path — (a) Mono runtime port (MIT, self-contained, supports .NET Framework
    4.x API surface), (b) CoreCLR port (much larger; needs PAL work), (c) require .NET Framework
    2.0/4.0 reference assemblies + a compatible runtime and document the limit. Evaluate against
    a corpus of real apps (a WinForms tool, a WPF app, a console tool).
  - Acceptance: at minimum, .NET Framework 4.x WinForms apps run via the chosen runtime; documented
    unsupported features list.
- `[ ]` **P3 `API-061`** — WPF/Media Foundation dependency chain (Direct3D 9 + `milcore`). Tier C;
  only if `API-060` chooses WPF support.
- `[ ]` **P3 `API-062`** — PowerShell / modern scripting host. Needs .NET; record as blocked by
  `API-060`.
- `[ ]` **P2 `API-063`** — Java runtime support (JRE 8/11/17): requires `GetSystemTimePreciseAsFileTime`,
  `SetThreadDescription`, large pages, `NtQuerySystemInformation` classes, and a working
  `WSAPoll`; validate with a real JDK.
- `[ ]` **P2 `API-064`** — Node.js / Python / Ruby / Rust runtime support: enumerate the exact
  missing symbols per runtime version, then close them in `API-011` priority order.
  - Acceptance: `python -c "import ssl, sqlite3, ctypes"` and `node -e "require('https')"` work.
- `[ ]` **P3 `API-065`** — Go toolchain support (requires `NtCreateUserProcess`, `WaitOnAddress`,
  `GetSystemTimePreciseAsFileTime`, and precise stack unwinding). Record as dependent.

### Phase 5.7 — Compatibility shim framework

- `[ ]` **P1 `API-070`** — Expand the application compatibility database.
  - Subtasks: leverage the existing `windows/appcompat` (SDB, shim engine, layers). Add layers for:
    version lie, `GetProcAddress` failure masking, `CreateProcess` argument fixes, heap flags,
    DPI, `DEP`/`ASLR` opt-out, `OS` detection, registry virtualization. Add a *shim authoring
    guide* and a test per shim.
  - Acceptance: 10 real legacy apps that fail without shims run with a single SDB entry each.
- `[ ]` **P1 `API-071`** — Per-app mitigation policy.
  - Subtasks: `SetProcessMitigationPolicy`-driven opt-outs stored in the compatibility DB so that
    `SEC-020/021` do not break apps that need them.
- `[ ]` **P2 `API-072`** — API tracing for compatibility debugging.
  - Subtasks: a lightweight loader-level import/export tracer (`sdktools/trace` exists) that logs
    missing imports with the calling binary; ship it as a diagnostic tool.
  - Acceptance: running a failing app produces a report naming the first missing export.

### Phase 5.8 — Modern App Baseline (acceptance definition)

- `[ ]` **P0 `API-100`** — Define and automate the baseline set.
  - Subtasks: choose ~25 binaries representative of 2026 usage that are *technically* plausible:
    a modern CLI tool compiled with MSVC 2022, a Go binary, a Rust binary, Python 3.11, Node 20,
    a Qt 5 app, a .NET 4.8 WinForms app, 7-Zip 23, VLC 3, LibreOffice 7 (if feasible), GIMP 2.10,
    Inkscape 1.x, a Chromium-based browser (tracked separately in `APP-010`), Firefox ESR,
    SumatraPDF, Notepad++, PuTTY, WinSCP, Git for Windows, OpenSSH for Windows, curl 8, OpenSSL 3 CLI.
  - Acceptance: `TST-070` records pass/fail/partial per binary with the failing API named; this
    table is the public "what works" list and must never overstate.

---

## Phase 6 — Networking stack (P1)

**Goal:** the machine behaves like a 2026 network citizen: fast TCP, working IPv6, TLS 1.2,
SMB2 interop, modern Wi-Fi with WPA2/WPA3, DNS that resolves.
**Depends on:** `CRY-001/002`, `DRV-030`.
**Exit:** R4 green.

### Phase 6.1 — TCP/IP correctness and performance

- `[ ]` **P0 `NET-001`** — Enable modern TCP options by default (F-30).
  - Subtasks: `GlobalMaxRcvWin`/`TcpHostSendOpts` defaults (`net/tcpip/driver/tcp/init.c:62-65`,
    `ntinit.c:1576-1582`): enable window scaling, timestamps, SACK; raise default window; add
    receive-window auto-tuning; verify interaction with `tcpip6`.
  - Acceptance: single-stream throughput over a 100 ms RTT link improves ≥5× versus default;
    `TST-060` verifies SACK retransmission efficiency.
- `[ ]` **P1 `NET-002`** — Congestion control.
  - Subtasks: implement CUBIC (RFC 8312) and expose it via `TCP_CONGESTION`-equivalent; retain
    NewReno as default until benchmarks justify the switch; add a pluggable interface.
  - Acceptance: CUBIC reaches ≥90 % fairness against a Linux peer on a shared bottleneck.
- `[ ]` **P1 `NET-003`** — ECN (RFC 3168) and PLPMTUD (RFC 4821) support.
- `[ ]` **P1 `NET-004`** — Path MTU discovery robustness and black-hole detection.
- `[ ]` **P1 `NET-005`** — TIME_WAIT/port exhaustion tuning; SYN flood protection verification.
- `[ ]` **P2 `NET-006`** — TCP Fast Open (client + server), only if the security review passes.
- `[ ]` **P2 `NET-007`** — Loopback and localhost performance; IOCP integration for high connection
  counts (10k sockets without loss).

### Phase 6.2 — IPv6

- `[ ]` **P0 `NET-010`** — Make IPv6 production-usable.
  - Subtasks: audit `net/tcpip/tpipv6` (XP-era preview): RFC 4291 addressing, SLAAC (RFC 4862),
    neighbor discovery (RFC 4861), duplicate address detection, privacy extensions (RFC 4941),
    DHCPv6 client (RFC 8415), `getaddrinfo` preference (RFC 6724), dual-stack sockets without
    `IPV6_V6ONLY` surprises.
  - Acceptance: reaches a dual-stack site over IPv6 only; `ping6`/`tracert6` work; address
    privacy rotates; no leak when IPv6 is disabled.
- `[ ]` **P2 `NET-011`** — IPv6 transition: 6to4 deprecation, Teredo policy, ISATAP removal.
- `[ ]` **P2 `NET-012`** — IPv6 firewall parity with IPv4.

### Phase 6.3 — Name resolution

- `[ ]` **P0 `NET-020`** — Modern resolver behaviour.
  - Subtasks: EDNS0, large UDP responses with TCP fallback, multiple search suffixes, DNS suffix
    devolution correctness, negative caching, `getaddrinfo` sorting, mDNS/LLMNR policy (disable
    by default), hosts-file parsing limits.
  - Acceptance: resolves a large RRset (>512 bytes) and a DNSSEC-signed zone (served as A/AAAA);
    resolution survives a dead primary DNS with a 1 s timeout budget.
- `[ ]` **P1 `NET-021`** — DNS over HTTPS/TLS client (as an opt-in stub resolver alongside
  `dnsapi`), requiring `CRY-001` and an HTTP client.
- `[ ]` **P2 `NET-022`** — mDNS/DNS-SD for printers and displays (`NET-070`).

### Phase 6.4 — Sockets and Winsock

- `[ ]` **P1 `NET-030`** — Modern Winsock API surface.
  - Subtasks: `WSAPoll`, `WSARecvMsg`, `WSADuplicateSocket` correctness, `GetAddrInfoEx`,
    `SetAddrInfoEx`, `InetPtonEx`, `WSAIoctl(SIO_GET_EXTENSION_FUNCTION_POINTER)` for
    `WSASendMsg`, `RIO` (stub with `WSAEOPNOTSUPP`), `SIO_IDEAL_SEND_BACKLOG_QUERY`.
  - Acceptance: `curl`, `ssh`, and a Node HTTP server run over the stack.
- `[ ]` **P2 `NET-031`** — `AF_UNIX` support (used by modern apps and terminals).
- `[ ]` **P2 `NET-032`** — Socket option coverage (`TCP_KEEPIDLE`, `SO_REUSEPORT` stub,
  `TCP_NOTSENT_LOWAT`) and correct `SO_LINGER`.

### Phase 6.5 — HTTP clients and servers

- `[ ]` **P1 `NET-040`** — WinHTTP/WinINet modernization.
  - Subtasks: TLS 1.2 with SNI (`CRY-001`), certificate validation via the updated chain engine,
    HTTP/1.1 keep-alive and chunked correctness, proxy support (WPAD/PAC), redirect policy,
    cookie handling, `WINHTTP_OPTION_SECURE_PROTOCOLS` semantics.
  - Acceptance: `WinHttpRequest` fetches a modern HTTPS site; a PAC file is honoured; no plaintext
    downgrade.
- `[ ]` **P2 `NET-041`** — HTTP/2.
  - Subtasks: ALPN (needs `CRY-002`), HPACK, stream multiplexing, flow control; integrate into
    WinHTTP and the server role.
  - Acceptance: `curl --http2` against a public server negotiates h2 and completes a large download.
- `[ ]` **P3 `NET-042`** — HTTP/3 / QUIC. Tier C; record in §10.

### Phase 6.6 — Server-side networking (only if a server role is retained)

- `[ ]` **P1 `NET-050`** — SMB.
  - Subtasks: implement an SMB2.1/SMB3 client in `base/fs/rdr2` (dialect negotiation, signing with
    AES-CMAC, encryption with AES-CCM/GCM, persistent handles) and disable SMB1 by default;
    server side at minimum SMB2 with signing.
  - Acceptance: mounts a Windows Server 2019 and a Samba 4.19 share; transfers 10 GB at line rate;
    signing and encryption negotiated.
  - **This is the largest single item in Phase 6.** Consider a design spike first (`NET-051`).
- `[ ]` **P3 `NET-051`** — Spike: feasibility of SMB3 encryption without a full rewrite.
- `[ ]` **P2 `NET-052`** — NFS client (v3/v4) as an alternative to SMB for NAS users.
- `[ ]` **P2 `NET-053`** — WebDAV over the updated WinHTTP.
- `[ ]` **P2 `NET-054`** — SSH server/client (OpenSSH for Windows is a separate port; evaluate
  bundling rather than implementing).

### Phase 6.7 — Wi-Fi, VPN, firewall

- `[ ]` **P1 `NET-060`** — WPA2/WPA3 supplicant (F-35).
  - Subtasks: RSN IE parsing, 4-way handshake, CCMP (AES-CCMP) and GCMP-256, PMF (802.11w),
    SAE (WPA3-Personal, at least hash-to-element), 802.1X/EAP-TLS/PEAP, credential storage via
    DPAPI, per-profile policy; integrate with `layer2svc/zeroconf` (WZC) and the connection UI.
  - Acceptance: connects to WPA2-PSK, WPA2-Enterprise, and WPA3-SAE access points; survives
    roaming; no downgrade to WEP unless explicitly configured.
  - Depends on `DRV-030` + `DRV-032`.
- `[ ]` **P1 `NET-061`** — IPsec/IKEv2 client for VPN; WireGuard as a user-mode tunnel option.
- `[ ]` **P1 `NET-062`** — Firewall: stateful inspection correctness, per-app rules, inbound
  default-deny, IPv6 parity, logging.
- `[ ]` **P2 `NET-063`** — NAT/ICS and Internet Connection Sharing verification.
- `[ ]` **P2 `NET-064`** — Captive portal detection and handling (needed for hotels/airports).
- `[ ]` **P2 `NET-065`** — Network location awareness (domain/private/public) and its effect on
  firewall policy.

### Phase 6.8 — Stack hardening

- `[ ]` **P1 `NET-070`** — Fuzz the parsers: IP/TCP/UDP option parsing, ICMP, DHCP, DNS, ARP,
  SMB, HTTP. Use a harness that feeds captured frames (`TST-100`).
- `[ ]` **P1 `NET-071`** — Fragment and option handling limits; resist IP fragmentation attacks;
  correct ICMP error quoting limits (RFC 5927-style).
- `[ ]` **P2 `NET-072`** — Remove legacy protocols from the default build: NetBEUI
  (`net/netbeui`), IPX/SPX (`net/nwlink`), DLC (`net/dlc`), AppleTalk (`net/sfm`),
  ATM/1394/IPoIB.
- `[ ]` **P2 `NET-073`** — NDIS filter driver for telemetry-free packet accounting (optional).

---

## Phase 7 — Storage and filesystems (P1)

**Goal:** any modern disk, at full size and speed, with data integrity.
**Depends on:** `IO-001`, `DRV-010/011`. **Exit:** R3 green.

### Phase 7.1 — Block-addressing and size limits

- `[ ]` **P0 `FS-001`** — CDB16 and READ/WRITE(16) support (F-29).
  - Subtasks: extend `drivers/storage/classpnp` (`xferpkt.c`, `obsolete.c`, `retry.c`) to emit
    16-byte CDBs when the LBA or transfer exceeds 32-bit ranges; add `READ_CAPACITY(16)`
    (`SERVICE_ACTION_IN(16)`) and `GET_CONFIGURATION` handling; propagate 64-bit LBA through
    `DISK_GEOMETRY_EX`/`IOCTL_DISK_GET_DRIVE_GEOMETRY_EX`; fix `DBGERR` paths that assume
    `CDB10`.
  - Acceptance: reads/writes beyond 2 TB on a 4 TB disk; `chkdsk` clean; no truncation in
    `IOCTL_DISK_GET_LENGTH_INFO`.
- `[ ]` **P0 `FS-002`** — 4Kn (4096-byte sector) support.
  - Subtasks: audit sector-size assumptions in `drivers/storage/disk/{geometry,part,disk}.c`,
    `base/ntos/fstub`, `base/fs/ntfs`, `fastfat`; boot-sector handling; partitioning alignment.
  - Acceptance: installs to and boots from a 4Kn device in QEMU (`-device nvme,logical_block_size=4096`).
- `[ ]` **P1 `FS-003`** — Alignment and partition offset policy (1 MiB alignment) in setup and
  `diskpart`-equivalent, to avoid SSD read-modify-write penalties.
- `[ ]` **P1 `FS-004`** — TRIM/UNMAP end-to-end.
  - Subtasks: `IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES`, SCSI UNMAP and ATA TRIM issuance from
    NTFS delete paths, batched and rate-limited; expose a manual "optimize" action.
  - Acceptance: `smartctl`-observable UNMAP counters increase after file deletion on a thin-
    provisioned VM disk.

### Phase 7.2 — Filesystem breadth

- `[ ]` **P1 `FS-010`** — exFAT driver.
  - Subtasks: implement from the published Microsoft exFAT specification (licensing: `GOV-005`);
    full read/write, allocation bitmap, upcase table, TexFAT not required; mount as a normal
    volume; `chkdsk`-equivalent verification tool.
  - Acceptance: interchange a USB stick with Windows 10/11, macOS and Linux without corruption;
    a 100 GB file can be written.
- `[ ]` **P1 `FS-011`** — NTFS correctness on large volumes.
  - Subtasks: fuzz the MFT/attribute/index parsers; test >2 TB volumes, millions of files, deep
    directory trees, hard links, sparse files, compression, EFS; verify `$UsnJrnl` wrap.
- `[ ]` **P2 `FS-012`** — UDF updates (2.60) for Blu-ray/AVCHD and modern optical media.
- `[ ]` **P2 `FS-013`** — Read-only drivers for Btrfs/ext4/APFS (user-mode or read-only kernel
  driver) to ease dual-boot data access. Licence review mandatory before any GPL-derived code.
- `[ ]` **P3 `FS-014`** — ReFS. Tier C; §10.
- `[ ]` **P2 `FS-015`** — VHD/VHDX read-write mount (useful for backups and VMs).
- `[ ]` **P2 `FS-016`** — ISO/UDF image mounting natively.

### Phase 7.3 — Semantics and reliability

- `[ ]` **P0 `FS-020`** — Crash consistency.
  - Subtasks: NTFS log replay correctness under forced power-off at random points; test with a
    QEMU disk that drops writes; verify `chkdsk` repairs; add a fault-injection harness.
  - Acceptance: 500 forced power-offs during a write workload → zero unrepairable volumes.
- `[ ]` **P1 `FS-021`** — Write caching policy: honour flush barriers (`IRP_MJ_FLUSH_BUFFERS`,
    `SYNCHRONIZE`), no lost writes on removable media, safe-removal enforcement.
- `[ ]` **P1 `FS-022`** — File system filter model: verify minifilters, altitude, and ordering
  with an antivirus-style filter; add a sample filter test.
- `[ ]` **P2 `FS-023`** — Symbolic links and junctions across all APIs (needed by modern
  installers and dev tools).
- `[ ]` **P2 `FS-024`** — Case sensitivity per-directory (WSL-style) — optional, off by default.
- `[ ]` **P2 `FS-025`** — Quotas and volume shrink/grow correctness.
- `[ ]` **P2 `FS-026`** — Offline files/CSC correctness with modern servers (or remove the
  feature from default install).
- `[ ]` **P3 `FS-027`** — BitLocker-equivalent full-volume encryption. Tier C; §10.

---

## Phase 8 — Graphics, audio and multimedia (P1/P2)

**Goal:** the desktop is smooth at 1080p/1440p; video plays; audio works; webcams work.
**Depends on:** `GFX-001`, `AUD-001`. **Exit:** R7 (partially) and the media subset of R6.

### Phase 8.1 — Display and 2D

- `[ ]` **P0 `GFX-010`** — Display mode setting on arbitrary hardware.
  - Subtasks: see `GFX-001`; add `ChangeDisplaySettingsEx` correctness for VBE/GOP modes, EDID
    preferred mode, refresh-rate selection, and a safe fallback if the mode fails (never black
    screen — restore after 15 s).
- `[ ]` **P1 `GFX-011`** — Multi-monitor: extend the desktop, per-monitor DPI, per-monitor
    wallpaper, hotplug.
- `[ ]` **P1 `GFX-012`** — Font rendering quality: ClearType tuning, subpixel positioning,
    hinting, and support for modern font formats already present (TTF/OTF); CFF2/variable fonts
    are out of scope for GDI (`LOC-011`).
- `[ ]` **P2 `GFX-013`** — Compositing-free window drag performance at 4K (damage tracking,
    blit paths in `windows/core/ntgdi`).
- `[ ]` **P2 `GFX-014`** — Colour management: ICC v2/v4 profile application per monitor.
- `[ ]` **P3 `GFX-015`** — Desktop compositor with per-window alpha. Tier C.

### Phase 8.2 — 3D and GPU compute

- `[ ]` **P1 `GFX-020`** — OpenGL beyond 1.1.
  - Subtasks: port Mesa (`gallium` + `llvmpipe`/`softpipe` first, then hardware drivers for GPUs
    with usable DRM-independent paths); implement the WGL/ICD interface and `opengl32.dll`
    replacement; target GL 3.3 core.
  - Acceptance: `glxgears`-equivalent and a real 3D app (e.g. Blender 2.79 or a GL game) render
    at >30 fps at 720p using llvmpipe.
- `[ ]` **P1 `GFX-021`** — D3D8/D3D9 correctness on top of the existing runtime; fix shader model
  1.1/2/3 paths; ensure `d3d8.dll`/`d3d9.dll` work with the new display driver (D3D8 sources are in
  `multimedia/directx/d3d8`; a D3D9 runtime must be evaluated separately).
- `[ ]` **P2 `GFX-022`** — D3D10/11 via `wined3d`/`vkd3d` (licence: LGPL, dynamic link only).
  - Acceptance: a D3D11 sample renders; documented performance caveats.
- `[ ]` **P3 `GFX-023`** — Vulkan loader/driver (needs a real GPU driver; likely blocked by
  `GFX-002`). Tier C.

### Phase 8.3 — Audio engine

- `[ ]` **P0 `AUD-010`** — A modern audio engine.
  - Subtasks: extend the existing `multimedia/media/audiosrv` service rather than replacing it:
    session-based mixer (one stream per app, shared mode), per-app and per-device volume,
    high-quality sample-rate conversion, format negotiation, glitch-free device switch, low-latency
    exclusive mode; expose a WASAPI-like API on top of the existing KS/DirectSound
    infrastructure; keep DirectSound/WaveOut working for legacy apps.
  - Acceptance: two apps play simultaneously; per-app volume works; switching from speakers to
    headphones does not crash or silence; round-trip latency <30 ms shared mode.
- `[ ]` **P1 `AUD-011`** — MMCSS-equivalent thread priority for audio.
- `[ ]` **P1 `AUD-012`** — Audio effects/APO framework (equalizer, loudness) — optional but
  expected by users.
- `[ ]` **P2 `AUD-013`** — MIDI and legacy wave synthesis; GS/XG support if a soundfont path is
  provided.
- `[ ]` **P2 `AUD-014`** — HDMI/DisplayPort audio routing.

### Phase 8.4 — Media playback and capture

- `[ ]` **P0 `MMD-010`** — Play modern container/codec combinations.
  - Subtasks: integrate FFmpeg-based DirectShow filters and/or a Media Foundation shim for:
    H.264, HEVC, VP9, AV1 (dav1d), AAC, Opus, FLAC, Vorbis, MP3; containers MP4/MKV/WebM/TS;
    hardware decode where a driver exists (`DXVA2`-class), software decode otherwise; correct
    A/V sync, seek, subtitles (SRT/ASS), chapter support.
  - Acceptance: a 1080p H.264 MKV and a 4K AV1 WebM play with sync within 40 ms; seeking works;
    CPU usage for 1080p H.264 software decode ≤60 % of one core on a 2015 CPU.
- `[ ]` **P1 `MMD-011`** — Media Foundation facade (`mfplat`, `mfreadwrite`, `mfuuid`) sufficient
  for apps that only use it for decoding.
- `[ ]` **P1 `MMD-012`** — DirectShow graph-builder robustness: codec enumeration, merit,
  intelligent connect, and no crash on missing codecs.
- `[ ]` **P2 `MMD-020`** — Audio/video capture: microphone, line-in, webcam (`MMD-030`), screen
  capture with a documented API.
- `[ ]` **P2 `MMD-021`** — Colour space and HDR: at minimum correct BT.709 handling; HDR10
  output is out of scope.
- `[ ]` **P2 `MMD-022`** — Streaming: RTSP/RTMP/HLS/DASH playback via FFmpeg filters.
- `[ ]` **P3 `MMD-023`** — Hardware encode (NVENC/QSV/AMF). Blocked by driver model.

### Phase 8.5 — Imaging and cameras

- `[ ]` **P1 `MMD-030`** — USB Video Class (UVC) driver.
  - Subtasks: UVC 1.1/1.5 descriptor parsing, isochronous and bulk transfer, MJPEG/YUY2/NV12
    formats, exposure/white-balance controls; expose via DirectShow and WIA.
  - Acceptance: a 1080p webcam streams at 30 fps in a video-call app.
- `[ ]` **P2 `MMD-031`** — Image codecs: JPEG (progressive), PNG (16-bit), WebP, HEIF/AVIF
  (via libheif/libavif — licence review), with correct colour and alpha.
- `[ ]` **P2 `MMD-032`** — Scanner support via WIA 2.0 semantics (`printscan/wia`).

---

## Phase 9 — Application compatibility (P1)

**Goal:** the software people actually use, in the categories that matter, with honest status.
**Depends on:** Phase 5 (API), Phase 6 (TLS/network), Phase 8 (media).
**Exit:** R6 green with a published, honest matrix.

### Phase 9.1 — Method

- `[ ]` **P0 `APP-001`** — Build the app corpus and harness first.
  - Subtasks: define tiers — **Tier 1** (must work: browser, file manager, editor, terminal, PDF,
    archiver, media player, office suite), **Tier 2** (should work: dev tools, chat, image editor),
    **Tier 3** (best effort: games, niche tools). For each app: version, installer type, required
    APIs, expected result, automation script.
  - Acceptance: `docs/compat/app-matrix.md` with ≥100 entries and an automated runner
    (`TST-070`) that can execute the Tier 1 set unattended.
- `[ ]` **P1 `APP-002`** — Failure triage pipeline.
  - Subtasks: for each failing app, capture the first missing API/behaviour with `API-072`, file a
    targeted task, and link it back to the matrix row. No "it doesn't work" entries.
  - Acceptance: every red row has a named cause and an owning task ID.

### Phase 9.2 — Browsers (the hardest Tier 1 item)

- `[ ]` **P0 `APP-010`** — Modern browser strategy.
  - Reality check `[P]`: current Chromium requires Win10-era APIs, a sandbox built on integrity
    levels/job objects, CFG, and a GPU process using D3D11/DXGI or ANGLE; Firefox requires
    Win7+ APIs and a content sandbox. Neither will run unmodified in the near term.
  - Subtasks: (a) determine the newest Chromium/Firefox that runs with the API layer
    (`APP-011`/`APP-012`), (b) maintain a patched ESR build as the supported browser, (c) pursue
    full modern support only after `SEC-030` (integrity levels) and `GFX-022` (D3D11) land.
  - Acceptance: a supported browser renders the modern web (HTTP/2, TLS 1.2, WASM, video) with
    a documented version and known-broken feature list. **Do not claim "Chrome works" until the
    matrix says so.**
- `[ ]` **P1 `APP-011`** — Legacy-but-maintained browser baseline (e.g. Firefox 52 ESR fork,
  Chromium 86-era) with security backports (TLS, cipher, certificate handling) tracked per release.
- `[ ]` **P2 `APP-012`** — Modern browser prerequisites list as a single tracking task:
  integrity levels, job-object sandbox, `SetProcessMitigationPolicy`, `GetSystemTimePreciseAsFileTime`,
  `WaitOnAddress`, D3D11/ANGLE, `bcrypt`, `dwrite`-class text (or a fallback path), IPC via
  named pipes with proper security descriptors.

### Phase 9.3 — Development tools and runtimes

- `[ ]` **P1 `APP-020`** — Git for Windows / MSYS2 (needs console VT, `CreateSymbolicLink`, long
  paths, `NtCreateUserProcess`).
- `[ ]` **P1 `APP-021`** — Python 3.11+ (needs `GetSystemTimePreciseAsFileTime`,
  `SetThreadDescription`, `AddDllDirectory`, `LoadLibraryEx` flags, `bcrypt` for `ssl`).
- `[ ]` **P1 `APP-022`** — Node.js LTS (needs `WaitOnAddress`, `GetSystemTimePreciseAsFileTime`,
  `SetThreadDescription`, `uv` threadpool semantics).
- `[ ]` **P2 `APP-023`** — Rust toolchain binaries and cargo-installed tools.
- `[ ]` **P2 `APP-024`** — Go toolchain (see `API-065`).
- `[ ]` **P2 `APP-025`** — Java JDK 8/11/17 (see `API-063`).
- `[ ]` **P2 `APP-026`** — Editors/IDEs: VS Code (Electron — Tier 3), Notepad++, Neovim, Emacs,
  Sublime; at minimum a solid editor + terminal workflow.
- `[ ]` **P2 `APP-027`** — Build tools: CMake, Ninja, MSYS2 `pacman`, `curl`, `ssh`, `rsync`.

### Phase 9.4 — Productivity, media and utilities

- `[ ]` **P1 `APP-030`** — Office-class: LibreOffice 7.x (needs a modern CRT and possibly D3D for
  rendering — test), Microsoft Office 2007/2010 (native era), PDF readers (SumatraPDF, Acrobat 9).
- `[ ]` **P1 `APP-031`** — Media: VLC 3.x, MPC-HC, foobar2000, Audacity, HandBrake (encode
  performance caveat).
- `[ ]` **P1 `APP-032`** — Utilities: 7-Zip 23+, WinRAR, Everything (needs NTFS USN), FileZilla,
  PuTTY, WinSCP, Rufus, HWiNFO (may need kernel driver — check signing).
- `[ ]` **P2 `APP-033`** — Image: GIMP 2.10, Inkscape 1.x, Paint.NET (needs .NET), IrfanView.
- `[ ]` **P2 `APP-034`** — Communication: Discord/Slack/Teams (Electron → Tier 3), classic IRC/XMPP
  clients, Zoom (needs modern media stack — Tier 3).
- `[ ]` **P3 `APP-035`** — Games: D3D9-era titles first; anti-cheat and D3D11/12 titles are out
  of scope until `GFX-022`/`SEC` land.
- `[ ]` **P2 `APP-036`** — Virtualization clients (VirtualBox 5.x, VMware Workstation 12) as a
  practical escape hatch for unsupported apps.

### Phase 9.5 — Installer and packaging compatibility

- `[ ]` **P1 `APP-040`** — MSI modernization (`admin/darwin`).
  - Subtasks: support MSI 4.5 semantics used by modern installers (per-user installs, restart
    manager, `MsiSetExternalUI`, `ALLUSERS=2`, advertised shortcuts), fix custom-action
    marshalling for 64-bit, verify major upgrades and patches.
  - Acceptance: 10 modern MSI packages install and uninstall cleanly; no orphaned registry keys in
    a diff test.
- `[ ]` **P1 `APP-041`** — Installer framework support: NSIS, Inno Setup, WiX bundles, Squirrel.
  - Subtasks: verify each framework's runtime dependencies (usually CRT + COM + shell APIs) and
    add them to the API gap list.
- `[ ]` **P2 `APP-042`** — Portable-app compatibility (no install, user-profile writes, registry
  virtualization).
- `[ ]` **P2 `APP-043`** — Side-by-side assemblies for VC runtimes (`base/win32/fusion`), so
    app-local manifests resolve.
- `[ ]` **P2 `APP-044`** — `UAC`-less elevation semantics: modern installers assume elevation.
  Document and provide a compatibility shim that grants the requested privileges at install time.

---

## Phase 10 — Shell, UX, accessibility and localization (P2)

**Goal:** the OS is comfortable, legible, and accessible — not just functional.
**Depends on:** Phase 5 (DPI, console), Phase 8 (display). **Exit:** R8 support; accessibility audit
passes.

### Phase 10.1 — Shell stability and behaviour

- `[ ]` **P1 `SHEL-001`** — Explorer stability under modern workloads.
  - Subtasks: stress `shell32`, `browseui`, `shdocvw` with 10k-file directories, network paths,
    and removable media; fix leaks and hangs; add a 24 h soak to CI.
  - Acceptance: no crash in a 24 h soak with a scripted Explorer workload; handle count stable.
- `[ ]` **P1 `SHEL-002`** — Modern file operations: progress accuracy, pause/resume, conflict UI,
  long-running copy without freezing the UI, correct handling of read-only/ACL-denied files.
- `[ ]` **P2 `SHEL-003`** — Default programs and file associations UI that modern apps can register
  into (`IApplicationAssociationRegistration` shim).
- `[ ]` **P2 `SHEL-004`** — Notification area / balloon replacement with modern toast-like
  behaviour (optional; must not break legacy apps).
- `[ ]` **P2 `SHEL-005`** — Search: make the Indexing Service optional and provide a fast filename
  search that scales to 1M files without an index service running.
- `[ ]` **P2 `SHEL-006`** — Settings consolidation: one entry point that reaches all control panel
  applets; keep legacy applets working.
- `[ ]` **P3 `SHEL-007`** — Explorer tabs / modern navigation. Tier C for the shell rewrite.
- `[ ]` **P2 `SHEL-008`** — Shell extension isolation (crash of a third-party extension must not
  kill Explorer).
- `[ ]` **P1 `SHEL-009`** — Task Manager replacement with accurate per-process CPU/memory/IO,
  GPU-less but honest, and no WMI dependency.

### Phase 10.2 — Visual and input quality

- `[ ]` **P2 `SHEL-020`** — Themes: keep Luna-style visuals but fix high-DPI metrics, focus
  rectangles, and contrast; no new visual style required.
- `[ ]` **P2 `SHEL-021`** — Keyboard: full keyboard navigation of dialogs; `Alt+Tab` with many
  windows; `Win` key behaviour; IME switching.
- `[ ]` **P2 `SHEL-022`** — Clipboard: modern formats (HTML, PNG, file lists), large payloads,
  and a fix for the classic clipboard-freeze bugs.
- `[ ]` **P2 `SHEL-023`** — Drag-and-drop across elevation/IL boundaries (depends on `SEC-030`).
- `[ ]` **P3 `SHEL-024`** — Clipboarding history / emoji panel. Optional.

### Phase 10.3 — Accessibility

- `[ ]` **P1 `ACC-001`** — MSAA/`oleacc` correctness audit.
  - Subtasks: verify `IAccessible` exposure for common controls, dialogs, and Explorer; fix
    `OBJID_*` handling; test with a screen reader that can still run (see `ACC-002`).
- `[ ]` **P1 `ACC-002`** — Modern screen reader support path.
  - Subtasks: NVDA requires Win7+ APIs; determine which subset is needed (UIA, `oleacc` proxies,
    `SetWinEventHook` breadth) and close the gap, or support an older NVDA that runs today and
    document the ceiling.
  - Acceptance: NVDA (or documented alternative) reads a dialog, a menu, and a web page.
- `[ ]` **P2 `ACC-003`** — UI Automation provider (or a bridge from MSAA) so modern assistive
  technology can attach (`SEC-030`-independent). Tier B.
- `[ ]` **P1 `ACC-004`** — High contrast and system colour correctness across shell, dialogs, and
  in-box apps.
- `[ ]` **P1 `ACC-005`** — Magnifier, on-screen keyboard, sticky keys, filter keys, toggle keys
  verified at 4K and multiple DPIs.
- `[ ]` **P2 `ACC-006`** — Narrator-equivalent: at minimum a working text-to-speech path
  (`enduser/speech` exists) and a documented alternative.
- `[ ]` **P2 `ACC-007`** — Accessibility conformance checklist (WCAG 2.2 AA analogue for desktop
  UI) applied to in-box apps; publish results.
- `[ ]` **P2 `ACC-008`** — Focus/tab order and accessible names in every `*.rc` dialog (audit tool).

### Phase 10.4 — Localization and internationalization

- `[ ]` **P1 `LOC-001`** — Restore a buildable localized tree (F-42).
  - Subtasks: `loc/bin/dirs` lists 24 languages with no sources; either import the language
    resources or remove the entries from the traversal and mark languages unsupported in the
    ledger; do not fake localization.
  - Acceptance: a build with `-l <lang>` either succeeds for that language or fails with an
    explicit "language not present in this checkout".
- `[ ]` **P1 `LOC-002`** — Unicode correctness: UTF-16 surrogate handling in `ntdll`/`kernel32`
    string functions, `CompareStringEx`/`LCMapStringEx` semantics, normalization (NFC/NFD).
- `[ ]` **P1 `LOC-003`** — Locale data modernization: CLDR-derived collation and casing, or an
    ICU port (`LOC-010`); current NLS tables are XP-era and mis-sort many modern locales.
- `[ ]` **P1 `LOC-004`** — Time zone data refresh to the current IANA tzdata; including a
    mechanism to update it without reinstalling.
- `[ ]` **P2 `LOC-005`** — Text rendering for complex scripts (Indic, Arabic, Hebrew, Thai):
    verify Uniscribe/`usp10` shaping; add missing fonts.
- `[ ]` **P2 `LOC-006`** — RTL layout audit across shell and dialogs (`WS_EX_LAYOUTRTL`,
    mirrored icons).
- `[ ]` **P2 `LOC-007`** — CJK IME modernization: at least IME 2002/2003-era input methods working;
    document the ceiling.
- `[ ]` **P3 `LOC-010`** — ICU port (Tier B): needed for correct modern collation, normalization,
    and date formatting; licence: Unicode/ICU (permissive).
- `[ ]` **P2 `LOC-011`** — Fonts: ship a modern, licensed font set (e.g. Open Sans, Noto subsets,
    DejaVu) with correct hinting; document font-format limits (no CFF2/variable in GDI).

---

## Phase 11 — Daily-driver usability (P1)

**Goal:** it survives a month of real use without drama.
**Depends on:** all of the above. **Exit:** R8.

- `[ ]` **P0 `USE-001`** — Power and thermal behaviour on a laptop.
  - Subtasks: measure idle/load power, verify S3 and lid-close, battery reporting, thermal
    throttling, and no fan run-away; tune C-states (`IO-004`, `DRV-041`).
  - Acceptance: ≥3 h battery life on a 2015-era laptop at idle with Wi-Fi connected, no thermal
    shutdown in a 2 h load test.
- `[ ]` **P0 `USE-002`** — Hibernate/suspend reliability with >4 GB RAM and modern storage.
  - Acceptance: 100 suspend/resume cycles, 20 hibernate/resume cycles, zero data loss.
- `[ ]` **P1 `USE-003`** — Hotplug and docking: USB devices, monitors, network changes.
- `[ ]` **P1 `USE-004`** — Audio device switching and volume UX that never leaves the user silent
  without explanation.
- `[ ]` **P1 `USE-005`** — Time: SNTP client, correct DST via tzdata, no clock drift >1 s/day.
- `[ ]` **P1 `USE-006`** — Crash resilience: an app crash must not take the desktop; a driver
  crash must recover where possible and log a dump.
- `[ ]` **P1 `USE-007`** — Backup: a working file backup path (robocopy-based or NTBackup fixed)
  with verification and restore test.
- `[ ]` **P1 `USE-008`** — Update UX: check, download, install, reboot, verify (`REL-030`).
- `[ ]` **P1 `USE-009`** — Performance targets and tuning (R7).
  - Subtasks: boot time, shell idle CPU, first-login time, Explorer folder open latency, app
    launch times; fix the top 10 hot spots found by profiling.
- `[ ]` **P2 `USE-010`** — Multi-user and fast user switching on modern hardware.
- `[ ]` **P2 `USE-011`** — Remote access: RDP client to modern servers (TLS/NLA — needs `CRY-001`
  and CredSSP), plus a VNC server as a fallback.
- `[ ]` **P2 `USE-012`** — Printing UX: add printer, pick driver, print test page, IPP discovery.
- `[ ]` **P2 `USE-013`** — Disk health and failure warnings (SMART) surfaced to the user.
- `[ ]` **P2 `USE-014`** — Documented "known issues" list shipped with the OS and refreshed each
  release.
- `[ ]` **P1 `USE-090`** — 30-day dogfood journal with a daily note, bug list, and a final verdict
  (this is the R8 gate). **Do not skip this; it is the only honest acceptance test.**

---

## Phase 12 — Developer experience and SDK (P1)

**Goal:** a new contributor can build, debug, and test in under a day; the platform has a real SDK.
**Depends on:** Phase 0.

- `[ ]` **P0 `DX-001`** — Onboarding doc that actually works.
  - Subtasks: rewrite `docs/build/quickstart.md` from a clean machine: prerequisites, host image,
    commands, expected output, common failures with fixes; test it with someone who has never seen
    the tree.
  - Acceptance: a new contributor reaches a green build in <1 day using only the doc.
- `[ ]` **P1 `DX-002`** — Reproducible dev VM image (packer/vagrant/qcow2) with the toolchain,
  editor, and test VMs preinstalled.
- `[ ]` **P1 `DX-003`** — Source indexing: `compile_commands.json`, `clangd` config, ctags;
    document how to navigate a 128k-file tree.
- `[ ]` **P1 `DX-004`** — Debugging: WinDbg/`kd` workflow, symbol server for our builds, kernel
  debugging over serial/network, crash-dump triage guide.
- `[ ]` **P1 `DX-005`** — Tracing: ETW/WPP workflow for the components that use it; a curated set
  of trace providers and a doc for reading them.
- `[ ]` **P1 `DX-006`** — SDK refresh.
  - Subtasks: update `public/sdk` headers for every API we add (`API-011`); keep the header
    additions ABI-compatible; publish import libraries for the new exports; version the SDK.
- `[ ]` **P2 `DX-007`** — DDK refresh for the driver APIs we add (MSI, xHCI, NDIS 6).
- `[ ]` **P2 `DX-008`** — Sample code that builds: at least one driver, one service, one GUI app,
  one console app, each with a working `sources` file and a test.
- `[ ]` **P2 `DX-009`** — Static analysis in CI: clang-tidy/`clang --analyze` on the components
  that parse them; `cppcheck`; MSVC `/analyze` where the toolchain supports it.
- `[ ]` **P2 `DX-010`** — Automated API-gap generator (SDK import libs vs. our exports).
- `[ ]` **P2 `DX-011`** — Documentation site generated from `docs/` with search.
- `[ ]` **P2 `DX-012`** — Emulator/VM harness: one command to build an ISO, boot QEMU, run a test
  list, and collect logs.
- `[ ]` **P3 `DX-020`** — Build on Linux via clang-cl + lld + Wine-hosted `rc`/`midl`.
  - Acceptance: at least 20 user-mode targets link on Linux with byte-comparable output; kernel
    targets may remain Windows-only for now.
- `[ ]` **P2 `DX-013`** — Contribution guide for this tree (style, test requirements, review
    rules), consistent with `AGENTS.md`.

- `[ ]` **P1 `DX-014`** — Third-party dependency management.
  - Subtasks: define the vendoring policy (pin version + hash, patch queue, upstream tracking,
    update cadence, security-response SLA); create `deps/` metadata with SPDX identifiers and a
    machine-readable manifest; add a CVE watch for every dependency (`MT-009`); require
    `GOV-004` approval before a new dependency merges.
  - Acceptance: `deps/manifest.toml` (or equivalent) is the only place versions are declared;
    CI fails on an unpinned dependency or a missing licence entry.

---

## Phase 13 — Testing and validation (P0, continuous)

**Goal:** every claim is backed by a test that can be re-run.
**Depends on:** Phase 0 for CI; grows with each phase.

### Phase 13.1 — Test infrastructure

- `[ ]` **P0 `TST-001`** — Unit-test framework.
  - Subtasks: pick a minimal framework that compiles with cl 13.00 (a tiny hand-rolled harness is
    acceptable); add a `sources`-based test target pattern; run in CI on Windows and, where
    possible, under GCC/ASan on Linux for extracted logic.
- `[ ]` **P0 `TST-002`** — CI pipeline: build → unit tests → boot smoke → artifact. Every PR.
- `[ ]` **P0 `TST-003`** — Boot smoke test: QEMU with a fixed machine type, boot to desktop,
    screenshot, OCR/compare, capture event log; fail on any bugcheck.
- `[ ]` **P0 `TST-004`** — Regression dashboard: one page showing build status, boot status,
    app-matrix status, perf numbers.

### Phase 13.2 — Functional and conformance tests

- `[ ]` **P1 `TST-010`** — Win32/NT conformance via the Wine test suite (LGPL — run as external
  binaries, do not link into the product).
  - Subtasks: port the harness, prioritize `kernel32`, `ntdll`, `user32`, `gdi32`, `advapi32`,
    `ws2_32`; record a pass baseline; fail CI on regression.
  - Acceptance: a stable pass rate for the selected subsets, tracked per commit.
- `[ ]` **P1 `TST-011`** — Driver tests: I/O stress, PnP/Power state machine, cancel, and
  fault injection (the in-tree `sdktools/ioverify`, `verifier`, `appverif` help).
- `[ ]` **P1 `TST-012`** — Filesystem tests: crash consistency, `chkdsk` fault injection, large
  volumes, 4Kn, >2 TB, millions of files.
- `[ ]` **P1 `TST-013`** — Network tests: throughput/latency matrix, loss/reorder simulation
  (netem on a Linux peer), TLS negotiation matrix, DNS failure modes, IPv6.
- `[ ]` **P2 `TST-014`** — Media tests: a corpus of files per codec/container with pass/fail on
  play, seek, and A/V sync.
- `[ ]` **P2 `TST-015`** — Localization tests: pseudo-locale build, string truncation detection,
  RTL screenshots.
- `[ ]` **P2 `TST-016`** — Accessibility tests: automated `IAccessible` presence checks per dialog;
  keyboard-only navigation scripts.

### Phase 13.3 — Security testing

- `[ ]` **P0 `TST-020`** — Mitigation verification suite: assert DEP, ASLR, SEHOP, `/GS`, and
  (later) CFG are active on system binaries; assert legacy protocols are off.
- `[ ]` **P1 `TST-021`** — Regression tests for every fixed audit finding (F-01…F-48).
  - Acceptance: each F-xx has a test that fails on the pre-fix commit and passes after.
- `[ ]` **P1 `TST-022`** — Fuzzing: libFuzzer/AFL harnesses for parsers (fonts, WMF/EMF, JPEG/PNG,
  SMB, HTTP, DNS, RPC, registry hive, PE loader, `chkdsk`).
  - Acceptance: continuous fuzzing in CI with a corpus; any new crash becomes a task.
- `[ ]` **P1 `TST-023`** — Privilege-escalation test suite: a set of known exploit techniques
  (token stealing, handle duplication, `win32k` callbacks) run against the OS; all must fail.
- `[ ]` **P2 `TST-024`** — External vulnerability scan of a default install (port scan, SMB
  dialect scan, TLS scan, default credentials).

### Phase 13.4 — Hardware, performance, acceptance

- `[ ]` **P1 `TST-040`** — VM matrix: QEMU (SeaBIOS + OVMF/CSM), VirtualBox, VMware, Hyper-V
  (legacy generation). Each release runs install+boot+smoke on all four.
- `[ ]` **P1 `TST-041`** — Physical hardware matrix from `DRV-060`; every release runs the
  boot/install/subsystem checklist.
- `[ ]` **P1 `TST-042`** — HCL publication with a clear per-subsystem status.
- `[ ]` **P1 `TST-050`** — Soak tests: 72 h with a scripted workload (browser, file copy, media
  playback, network transfer); watch for leaks, handle growth, and thermal issues.
- `[ ]` **P1 `TST-051`** — Stress: 1000 hotplug cycles; 10k process create/exit; 1M file
  create/delete; 24 h network churn.
- `[ ]` **P1 `TST-052`** — Power-loss testing: QEMU disk that drops writes at random; verify
  NTFS recovery.
- `[ ]` **P1 `TST-053`** — Storage performance: sequential/random, queue depth 1/32, 4Kn/512e.
- `[ ]` **P1 `TST-060`** — Network acceptance: the top-100 HTTPS sites load, TLS 1.2 negotiated,
  no certificate errors on valid sites; DHCP/DNS survive server loss.
- `[ ]` **P1 `TST-070`** — Application matrix runner (see `APP-001`); results published per
  release.
- `[ ]` **P1 `TST-080`** — Performance benchmarks with a fixed reference image; track boot time,
  idle CPU, app launch, file I/O, network throughput; fail on >10 % regression.
- `[ ]` **P1 `TST-081`** — Memory-leak detection: a repeatable workload with handle/GDI/USER
  object and private-byte counters; fail on growth beyond a baseline.
- `[ ]` **P2 `TST-082`** — Disk footprint and install-size tracking.
- `[ ]` **P2 `TST-083`** — Latency: input-to-photon (measure with a camera or a hardware timer),
  audio round-trip, DPC latency (`dpclat`-style tool).
- `[ ]` **P2 `TST-090`** — Default-configuration assertions (see `SEC-002`).
- `[ ]` **P2 `TST-091`** — Mitigation/opt-out tests (ASLR/DEP on and off per app).
- `[ ]` **P2 `TST-100`** — Fuzzing corpus and crash triage pipeline with deduplication.
- `[ ]` **P2 `TST-101`** — Nightly "long" suite: full matrix, soak, fuzz, and perf.

---

## Phase 14 — Distribution, updates and servicing (P1)

**Goal:** users can install, update, and roll back without a lab. **Depends on:** `GOV-001`
(hard gate), Phase 0 (`BLD-001`), `SEC-050`.
**Exit:** R9.

### Phase 14.1 — Media and installation artifacts

- `[ ]` **P0 `REL-001`** — Release artifact set: ISO, USB image, recovery image, driver pack,
  symbols, SHA-256 manifest, and a signed SBOM.
- `[ ]` **P0 `REL-002`** — Versioning scheme.
  - Subtasks: define a version string that does not collide with real Windows versions (for
    compatibility purposes the reported OS version may need to stay 5.1 — document the split
    between *product version* and *reported OS version*); set the update channel identifiers.
  - Acceptance: `docs/release/versioning.md`; every artifact embeds the product version and the
    compatibility version separately.
- `[ ]` **P1 `REL-003`** — Build provenance: reproducible builds (`BLD-004`) + signing + a
  published log of the exact inputs.
- `[ ]` **P1 `REL-004`** — USB install media writer (a supported tool, since `oscdimg` is absent).

### Phase 14.2 — Updates

- `[ ]` **P0 `REL-010`** — Update mechanism design.
  - Subtasks: choose between (a) extending the existing hotfix/QFE infrastructure, (b) a
    package-based updater with a signed manifest, (c) an offline "component store" model. Include
    atomic apply, verification, and rollback in the design.
  - Acceptance: `docs/design/updates.md` approved before implementation.
- `[ ]` **P1 `REL-011`** — Update client + server.
  - Subtasks: HTTPS transport (`CRY-001`), signed manifests (SHA-256 + RSA/ECDSA), delta or full
    packages, resumable downloads, integrity verification before install, staged apply on reboot.
- `[ ]` **P1 `REL-012`** — Rollback.
  - Subtasks: snapshot the component being replaced, keep N previous versions, automatic rollback
    on failed boot (boot counter + watchdog), manual rollback from recovery media.
  - Acceptance: install a deliberately broken update, confirm automatic rollback to a bootable
    state without user intervention.
- `[ ]` **P1 `REL-013`** — Offline servicing: apply updates to an offline image (`/image:` style).
- `[ ]` **P2 `REL-014`** — Update channels: stable/beta/nightly with separate signing keys.
- `[ ]` **P2 `REL-015`** — Driver updates through the same channel, with rollback (`DRV-001`).
- `[ ]` **P2 `REL-016`** — Root certificate and tzdata update packages (small, frequent, low risk).
- `[ ]` **P3 `REL-017`** — Delta compression and peer distribution. Optional.

### Phase 14.3 — Trust and supply chain

- `[ ]` **P1 `REL-020`** — Code-signing infrastructure: an internal CA, a documented key ceremony,
  HSM or offline key storage, and a rotation plan.
- `[ ]` **P1 `REL-021`** — Trust store: ship a curated root set, an update channel for it, and a
  policy for removing distrusted roots.
- `[ ]` **P1 `REL-022`** — SBOM per release, with dependency versions and licence identifiers.
- `[ ]` **P1 `REL-023`** — Vulnerability disclosure and advisory publication process.
- `[ ]` **P2 `REL-024`** — Mirror/CDN plan if distribution is ever permitted (`GOV-001`).
- `[ ]` **P2 `REL-025`** — Release notes automation from the ledger and closed tasks.

### Phase 14.4 — Support lifecycle

- `[ ]` **P2 `REL-030`** — Support policy: which builds get security fixes, for how long, and what
  "supported hardware" means.
- `[ ]` **P2 `REL-031`** — End-of-life plan for removed components (e.g. IIS, NetMeeting,
  Outlook Express) with migration notes.
- `[ ]` **P2 `REL-032`** — A "factory image" for OEM-style deployment with a documented
  customization path.

---

## Phase 15 — Maintainability and technical debt (P2, continuous)

**Goal:** the tree does not rot faster than it improves.

- `[ ]` **P0 `MT-001`** — Close out every finding in §4 with a test (`TST-021`).
  - Subtasks: F-01, F-02, F-05, F-06, F-07, F-09, F-11, F-13, F-14, F-15, F-16, F-17, F-21
    (the remaining findings are owned by the phase tasks named in their rows).
- `[ ]` **P0 `MT-002`** — Sweep for `if (x = CONST)` assignment bugs (F-10, F-13).
  - Subtasks: compiler warning `C4706`/`-Wparentheses` where available; a regex-based tree scan
    for `if\s*\([^)]*[^=!<>]=[^=]`; triage every hit; add the check to CI.
  - Acceptance: zero unexplained hits; CI blocks new ones.
- `[ ]` **P1 `MT-003`** — Unsafe-string sweep: `strcpy`, `strcat`, `sprintf`, `gets`, `atoi`,
  `alloca`, fixed-size stack buffers in parsers.
  - Subtasks: triage by reachability; convert to `StringCch*`/bounds-checked helpers; fuzz the
    remaining ones.
- `[ ]` **P1 `MT-004`** — Uninitialized-variable sweep: enable `/W4` + analyzer on components that
  accept it; fix high-severity hits (F-03 class).
- `[ ]` **P1 `MT-005`** — Integer-overflow sweep in size computations (allocations, packet lengths,
  registry data lengths).
- `[ ]` **P1 `MT-006`** — Remove evaluation/timebomb code from the product (F-21).
- `[ ]` **P1 `MT-007`** — Deduplicate copied source trees (F-40: `dech261`/`dech263`; check for
  other `cmp`-identical pairs tree-wide) and document the policy for generated/duplicated code.
- `[ ]` **P2 `MT-008`** — Dead code and vestigial architecture removal (alpha, axp64, ppc, IA64,
  Win9x paths) — remove from *traversal* first, delete only after a release cycle.
- `[ ]` **P2 `MT-009`** — Dependency inventory and CVE tracking for in-tree third-party code
  (zlib, Perl, `msasn1`, `makecab`, `cabarc`, `iexpress`).
- `[ ]` **P2 `MT-010`** — Compiler warning baseline per component (`BLD-008`), ratcheting down.
- `[ ]` **P2 `MT-011`** — Documentation drift prevention: `verify.py` in CI, catalog regeneration,
  a link checker, and a rule that docs changes ship with code changes.
- `[ ]` **P2 `MT-012`** — Issue tracker enablement (see `BLK-002`) and a triage rotation.
- `[ ]` **P2 `MT-013`** — Branch/review policy: no direct pushes to main, required checks, signed
  commits.
- `[ ]` **P3 `MT-014`** — Long-term: evaluate replacing the `sources`/`dirs` build system with
  CMake/Ninja *only if* `ENV-006` succeeds; keep the old system working in parallel until the new
  one covers 100 % of targets.

---

## 8. Sequencing, dependencies and quick wins

### 8.1 Dependency graph (critical path)

```text
GOV-001 (legal) ──► REL-* (everything user-facing)
BLD-001/002/003 (build truth) ──► every phase
   ├─► VER-003/004/006 (identity + build number)
   ├─► API-001 (subsystem version) ──► API-010/011/020 (API layer) ──► APP-*
   ├─► SEC-010/011 (DEP/NX) ──► SEC-020/021 (ASLR/SEHOP) ──► SEC-030 (IL/UIPI) ──► browser sandbox
   ├─► CRY-001/002 (TLS 1.2) ──► NET-040 (HTTPS) ──► REL-011 (updates) ──► APP-*
   ├─► IO-001 (MSI) ──► DRV-011 (NVMe), DRV-020 (xHCI), DRV-030 (NDIS 6)
   │        └─► DRV-030 ──► DRV-032 (Wi-Fi) ──► NET-060 (WPA2/3)
   ├─► FS-001/002 (CDB16/4Kn) ──► SETUP-002 ──► R2/R3
   └─► TST-001/002/003 (CI + boot smoke) ──► every phase's acceptance
```

**Critical path to M5 (daily driver):** `BLD-003 → API-001 → CRY-001 → NET-001/010/040 →
FS-001 → DRV-010 → SEC-010/020 → TST-070 → USE-090`.

### 8.2 Quick wins (≤ 2 days each, high value)

| Task | Why it matters | Effort |
| --- | --- | --- |
| `API-001` subsystem-version ceiling | Turns "nothing runs" into "one specific API missing" | 0.5 d |
| `VER-006` `genbldno.pl` fix | Unblocks every build | 0.5 d |
| `VER-003` `OS=Windows_NT` | Fixes installers and in-tree scripts | 0.5 d |
| `VER-004` ACPI `_OS` | Restores firmware behaviour | 0.5 d |
| `BLD-006` timebomb off | Product stops expiring | 0.5 d |
| `NET-001` enable WS/SACK/TS | 5–10× throughput on real links | 1 d |
| `MT-002` `=` in `if` sweep | Removes silent-failure class | 1–2 d |
| `GOV-002` remove product keys | Stops credential leakage | 0.2 d |
| `BLD-021` fix `verify.py` | Green documentation gate | 0.3 d |
| `CRY-007` disable SSL2/3/RC4 | Removes trivially broken crypto | 1 d |
| `SEC-041` disable legacy listeners | Large reduction in exposed surface | 1 d |
| `MM-006` heap terminate-on-corruption | Cheap hardening | 0.5 d |
| `FS-004` TRIM plumbing | SSD longevity | 2 d |
| `BOOT-007` boot-option verification | Prevents "can't recover" | 1 d |

### 8.3 Recommended parallel workstreams

| Stream | Owner profile | Tasks |
| --- | --- | --- |
| **Build & CI** | release engineer | `ENV-*`, `BLD-*`, `REL-001…004`, `TST-001…004` |
| **Transport security** | crypto/network engineer | `CRY-001…009`, `NET-040`, `AUTH-001/002` |
| **Kernel & memory** | kernel engineer | `KRN-001…003`, `MM-001…005`, `IO-001…006`, `SEC-010…013` |
| **Driver bring-up** | driver engineer | `DRV-010…023`, `DRV-030…033`, `GFX-001…004`, `AUD-001` |
| **API compatibility** | Win32/loader engineer | `API-001…072`, `APP-*` |
| **Shell & UX** | client engineer | `SHEL-*`, `ACC-*`, `LOC-*` |
| **Validation** | QA | `TST-*`, `DRV-060`, `USE-090` |

---

## 9. Milestones

Each milestone has an exit gate from §6 and a concrete artifact. A milestone is *not* a date;
it is a state.

### M0 — "Honest build" (target: 6–10 weeks)
- **Exit:** R1 + R10. A pristine clone builds on a documented host; the ledger exists; CI runs the
  three checks plus a full build; no timebomb; `GOV-001` decision recorded.
- **Tasks:** Phase 0 complete; `API-001`; `VER-003/004/006`; `MT-001/002` first pass.
- **Artifact:** `build-report-YYYYMMDD.md` + `build/ledger.json`.

### M1 — "Installs and boots" (target: +6 weeks)
- **Exit:** R2 in VMs (4 hypervisors). ISO boots and installs on a 40 GB disk and on a 4 TB disk.
- **Tasks:** `BLD-001`, `BOOT-001/002/003/007`, `SETUP-001/002/003`, `REC-001/002`, `TST-003`.
- **Artifact:** bootable ISO + recovery image.

### M2 — "Safe on the network" (target: +10 weeks)
- **Exit:** R5. DEP+ASLR+SEHOP on system binaries; TLS 1.2 with AEAD; SSL3/TLS1.0/RC4/NTLMv1/LM
  off; legacy listeners off; baseline scan clean.
- **Tasks:** `SEC-010/011/020/021/030/040/041`, `CRY-001/002/003/004/007/008`, `AUTH-001`,
  `NET-001/010/020/040`, `TST-020/023/060`.
- **Artifact:** security baseline document + scan report.

### M3 — "Modern hardware" (target: +16 weeks)
- **Exit:** installs and is usable on the 6 reference machines; AHCI + NVMe + xHCI + HDA + a
  1 Gbit NIC work; S3/S4 stable.
- **Tasks:** `IO-001/002`, `DRV-010/011/020/022/031`, `AUD-001`, `GFX-001`, `FS-001/002/004`,
  `DRV-060`, `TST-040/041/042/050/051/053`.
- **Artifact:** HCL v1.

### M4 — "Modern APIs" (target: +20 weeks)
- **Exit:** the Modern App Baseline (`API-100`) starts; ≥60 % of it is functional; `TST-010`
  conformance baseline established.
- **Tasks:** `API-010…055`, `PS-003`, `API-063/064`, `TST-010/070`.
- **Artifact:** API gap matrix + app matrix v1.

### M5 — "Daily-driver beta" (target: +24 weeks)
- **Exit:** R3, R4, R6 (Tier 1 apps), R7, R8 (30-day journal).
- **Tasks:** Phase 6/7/8 completion for Tier 1, `USE-001…009`, `USE-090`, `TST-050/080/081`.
- **Artifact:** beta ISO + honest known-issues list.

### M6 — "Breadth" (target: +36 weeks)
- **Exit:** Tier 2 apps; Wi-Fi WPA2/3; printing; multi-monitor + DPI; accessibility audit; a
  first localization.
- **Tasks:** `DRV-032/033`, `NET-060`, `DRV-050`, `GFX-011/012`, `ACC-001…007`, `LOC-001…007`.

### M7 — "Release and update" (target: +44 weeks)
- **Exit:** R9. Signed artifacts, update channel with rollback, offline servicing, SBOM, advisories.
- **Tasks:** Phase 14 complete, `SEC-050`, `REL-020/021/022/023`.

### M8 — "Long-term maintenance" (ongoing)
- **Exit:** a documented support policy; a security-only release cadence; a debt budget of ≥20 %
  of every cycle spent on `MT-*`.

### 9.1 Effort realism (read this before promising a date)

The week numbers above assume **2–3 full-time engineers plus one part-time QA and one part-time
release engineer**, working in the order given. They are indicative, not commitments, and the
following are the known schedule risks:

| Milestone | Optimistic | Likely | Pessimistic | Main risk |
| --- | --- | --- | --- | --- |
| M0 | 4 w | 8 w | 16 w | Missing sources make a "full" build impossible; ledger keeps it honest |
| M1 | 4 w | 10 w | 20 w | Loader/GPT/USB boot work is deeper than it looks |
| M2 | 6 w | 14 w | 26 w | ASLR/SEHOP break applications; TLS 1.2 needs ECDHE + GCM from scratch |
| M3 | 10 w | 20 w | 40 w | xHCI and NDIS 6 are each multi-month projects |
| M4 | 8 w | 18 w | 36 w | The API gap is larger than any list suggests |
| M5 | 6 w | 12 w | 24 w | Dogfooding surfaces issues no test catches |

**If only one engineer is available, halve the scope per milestone, never the gates.** The failure
mode to avoid is declaring M5 while R3/R4/R5 are red.

**M2 may legitimately split into M2a (transport + policy + DEP) and M2b (ASLR/SEHOP).** M3 does
not depend on M2b; M5's R5 gate does.

---

## 10. Blocked and infeasible registry

Every entry here is deliberately **not** on the roadmap. Do not schedule these as backports.
Re-open only with a written design spike and a go/no-go decision.

| Status | ID | Item | Why it is blocked / infeasible | Re-open condition |
| --- | --- | --- | --- | --- |
| `[!]` | **BLK-001** | Secure Boot with Microsoft-signed loader | Requires a Microsoft-signed bootloader or custom key enrolment; no legal or technical path from this tree. | User enrols a custom key (`SETUP-004` documents it) and a UEFI loader exists (`BOOT-009`). |
| `[!]` | **BLK-002** | GitHub Issues / public tracker | Repository has issues and discussions **disabled**; the prior audit could not publish any finding. | Owner enables issues, or a self-hosted tracker is provided. |
| `[!]` | **BLK-003** | Modern GPU drivers (WDDM 1.x+) | Requires a display driver model, DDI, and vendor cooperation; XDDM is dead since 2008. | A vendor supplies an XDDM driver, or `GFX-015` compositor work creates a model worth porting to. |
| `[!]` | **BLK-004** | Unmodified 2026 Chromium/Electron | Requires Win10-era APIs (`win32k` lockdown, CFG, AppContainer, D3D11, `dwrite`), a multi-process sandbox with integrity levels, and a modern CFG-capable toolchain. | `SEC-030` + `GFX-022` + `API-012` all complete and a spike shows <20 % of the required surface remains. |
| `[!]` | **BLK-005** | .NET Framework 4.8 / .NET 8 full runtime | No CLR sources in tree; CoreCLR's PAL assumes Vista+ APIs extensively. | `API-060` picks Mono and proves WinForms coverage; or an external CLR port lands. |
| `[!]` | **BLK-006** | SMB3 encryption (full) | Requires a rewrite of `rdr2`/`srv` and AES-CCM/GCM in the redirector, plus a new dialect abstraction. | `NET-050` spike succeeds with a bounded design. |
| `[!]` | **BLK-007** | Bluetooth stack | No sources; requires HCI, L2CAP, SDP, GATT, profiles, and a new device stack. | A permissively-licensed stack is found and `DRV-036` spike is approved. |
| `[!]` | **BLK-008** | WDDM/KMDF/VBS/HVCI/AppContainer/ReFS/BitLocker | Each requires an architectural component this OS does not have (hypervisor, driver framework, object isolation, copy-on-write FS, pre-boot encryption integration). | Separate design spikes; not part of this roadmap. |
| `[!]` | **BLK-009** | >64 logical processors (processor groups) | `MAXIMUM_PROCESSORS` is baked into the kernel ABI, scheduler, and every `KAFFINITY` user. | Tier C spike only. |
| `[!]` | **BLK-010** | ARM64 / RISC-V ports | No HAL, no loader, no compiler toolchain in tree. | Out of scope; would be a new project. |
| `[!]` | **BLK-011** | Modern Standby (S0ix) | Requires a completely different power model, ACPI device constraints, and driver cooperation. | Vendor ACPI firmware support + `IO-004` redesign. |
| `[!]` | **BLK-012** | HTTP/3 (QUIC) | Requires a userspace UDP stack, TLS 1.3, and a new HTTP mapping; huge for the value. | `CRY-012` (TLS 1.3) lands and a QUIC library is licensed. |
| `[!]` | **BLK-013** | Post-quantum TLS | Depends on `CRY-012` and a vetted PQ library. | TLS 1.3 done + library review. |
| `[!]` | **BLK-014** | Redistribution of the tree or binaries | `GOV-001` — proprietary provenance, no licence. | Written legal decision. |
| `[!]` | **BLK-015** | Localized builds for the 24 `loc/bin` languages | Sources absent from this checkout. | Language resources imported. |
| `[!]` | **BLK-016** | Full-tree "everything builds" claim | ~140 dangling `dirs` references and several missing subsystems (F-41). | Ledger shows 100 % of *referenced, present* targets building; missing ones imported or removed from traversal. |
| `[!]` | **BLK-017** | NTVDM / DOS compatibility on 64-bit | Not present for AMD64; `base/mvdm` is 32-bit only. | Out of scope for a daily driver. |
| `[!]` | **BLK-018** | DirectX 12 / Vulkan on modern GPUs | Requires WDDM-class driver model and a real GPU driver. | `BLK-003` resolved. |

### 10.1 Things commonly asked for that *are* feasible (do not wrongly block them)

- TLS 1.2 with ECDHE/AES-GCM — yes (`CRY-001`).
- SHA-256 certificates and a modern root store — yes (`CRY-008`).
- ASLR/DEP/SEHOP — yes (`SEC-010…021`).
- IPv6 that works — yes (`NET-010`).
- exFAT — yes (`FS-010`).
- >2 TB and 4Kn disks — yes (`FS-001/002`).
- OpenGL 3.3 via Mesa/llvmpipe — yes (`GFX-020`).
- Python/Node/Java — likely yes once `API-011` closes the gap (`API-063/064`).
- MSI 4.5-era installers — yes (`APP-040`).
- VT/ANSI console — yes (`API-050`).

---

## 11. Risk register

| Risk | Likelihood | Impact | Mitigation |
| --- | --- | --- | --- |
| Legal block kills distribution after months of work | High | Fatal | `GOV-001` in week 1; treat the project as internal-use until decided. |
| Missing sources prevent a full build | High | High | `BLD-002` ledger; scope releases to the built set; import or drop missing trees explicitly. |
| Compiler (cl 13.00) cannot express modern mitigations | High | High | `ENV-006` spike early; fall back to clang-cl; keep mitigations that do not need new codegen first. |
| AMD64 bring-up consumes the whole budget | Medium | High | i386 ships first; AMD64 is a separate track with its own milestone. |
| Driver work is unverifiable without hardware | Medium | High | HCL first (`DRV-060`); buy/borrow reference machines early. |
| Security work breaks applications | High | Medium | Compatibility DB opt-outs (`API-071`), staged defaults, per-app mitigation policy. |
| API shims create a false sense of compatibility | High | Medium | Honest matrix (`APP-001`), stubs must fail loudly (`API-013`), never silently succeed. |
| Scope creep into "rewrite Windows" | High | High | Tier C registry (§10); milestone gates; no Tier C item blocks a release. |
| Regressions in a 278k-file tree | High | Medium | CI + boot smoke + conformance baseline; no change without a test. |
| Single-maintainer bus factor | Medium | High | Documentation (`DX-001`), reproducible environments (`DX-002`), small reviewable changes. |
| Timebomb/eval code ships by accident | Low | High | `BLD-006/007` + a binary scan in CI (`TST-020`). |

---

## 12. Appendices

### 12.1 Dangling `dirs`/`OPTIONAL_DIRS` references (F-41)

Generated by walking every `dirs` file at depth ≤2 and comparing against the filesystem
(case-insensitive, since NT source is case-preserving but not case-sensitive). This list is the
authoritative input to `BLD-002`. Counts: **140 dangling entries across 268 `dirs` files scanned**.

Root and major trees:
`QFE` (root `dirs`), `base/cluster/docs`, `com/OleAutomation`, `com/netfx`, `com/mts/binary_release`,
`com/netfxoc/binary_release{x86}`, `com/netfxoc/netfxocm`, `drivers/infiniband`, `drivers/scmmicro{x86}`,
`drivers/tabletpc{x86}`, `drivers/vsm`, `drivers/oem`, `ds/prssigned`, `inetcore/java`,
`inetcore/vml`, `inetsrv/infosoft`, `multimedia/oem`, `multimedia/slalom{32}`, `printscan/oem`,
`sdktools/ddk`, `sdktools/logger`, `sdktools/oletools`, `sdktools/ResourceKit`, `termsrv/newclient`,
`termsrv/rdpclip`, `termsrv/rdpsnd`, `termsrv/rdpwsx`, `termsrv/notify`, `windows/langpack`.

Driver subtrees:
`drivers/dot4/{dot4,dot4prt,dot4scan}`, `drivers/filters/update`, `drivers/input/twotrack`,
`drivers/ksfilter/{waveport,mswaveio}`, `drivers/net/{netcard,wan}`, `drivers/parallel/ptilink`,
`drivers/smartcrd/{grserial,scr111}`, `drivers/sound/ihvaudio`,
`drivers/storage/{parzip,imapi,ppa3x,rsm,sony,i2o}`, `drivers/wdm/1394`.

Filesystem/other subtrees:
`base/fs/clfs` has only `readme.txt` (the CLFS implementation is absent),
`multimedia/directx/{redist{386},setup{386}}`, `multimedia/dshow/{mci,compdlls}`,
`multimedia/netshow/binary_release`, `multimedia/reality/rl`,
`net/atm/uni`, `net/diagnostics/netmon`, `net/ias/rasserver\`, `net/ipsec/{ipsecsnp,oakley}`,
`net/mmc/ipsnap`, `net/qos/rsvp`, `net/sockets/sockutil`, `net/upnp/downlevel`,
`printscan/faxsrv/Win9xMig`, `printscan/scan/twain`,
`shell/ext/{imapi,zip{x86}}`, `shell/iecontrols/plugin`, `shell/osshell/cabinet`,
`admin/activec/setup{x86}`, `enduser/*` (~24 entries including `HelpContent*`, `Moviemk`,
`ScriptEngines`, `MSN_Explorer`, `VB_binaries`, `VC_binaries`),
`loc/bin/*` (24 language folders), `termsrv/common/{clientidl,remdskidl,compress,uniwrap{32}}`,
`termsrv/drivers/rdp`, `inetcore/ietools/stress`, `inetcore/urlmon/urltest`,
`inetsrv/iis/diablo`, `inetsrv/intlwb/JPN2`, `inetsrv/msmq/binary_release`,
`ds/adsi/{win95,nt40}`, `ds/dns/nslookup`, `ds/nw/test`.

**Rule:** these are *missing sources*, not bugs to "fix" by creating empty directories. Each must
be either (a) imported, (b) removed from the traversal with a documented reason, or (c) declared
out of scope in the ledger.

### 12.2 Source map by subsystem (verified paths)

| Concern | Where to look |
| --- | --- |
| Kernel: scheduler, dispatch, traps | `base/ntos/ke/{up,mp,pae,amd64}` |
| Memory manager | `base/ntos/mm` (+ `mm/amd64/miamd.h`, `initamd.c`) |
| Object manager, handles | `base/ntos/ob` |
| I/O manager, IRP, PnP kernel side | `base/ntos/io` |
| Power | `base/ntos/po` |
| Security reference monitor | `base/ntos/se` |
| Registry | `base/ntos/config` |
| Cache manager | `base/ntos/cache` |
| LPC/ALPC | `base/ntos/lpc` |
| Verifier | `base/ntos/verifier` |
| Fsrtl / fstub (partition tables) | `base/ntos/fsrtl`, `base/ntos/fstub` |
| Native API | `base/ntdll` (+ `ntdlldef.src`, `amd64/`) |
| Win32 client | `base/win32/client` |
| Win32 kernel/user GUI | `windows/core/{ntuser,ntgdi,kmode,umode}` |
| Session manager | `base/subsys/sm/server/sminit.c` |
| CSRSS | `base/subsys/csr/csrss` |
| Services | `base/screg/sc` |
| Boot loader | `base/boot/bldr`, `base/boot/detect`, `base/boot/lib/amd64` |
| HAL | `base/hals/{halacpi,halx86,halmps,halsp,halia64}` |
| ACPI interpreter | `base/busdrv/acpi/driver/amlinew` |
| PCI bus driver | `base/busdrv/pci` |
| Storage stack | `drivers/storage/{classpnp,class,disk,partmgr,port,scsiport,...}` |
| USB | `drivers/wdm/usb/{hcd,usbd,usbccgp,driver}` |
| Audio | `drivers/wdm/audio`, `drivers/ksfilter` |
| Graphics | `drivers/video`, `windows/core/ntgdi`, `multimedia/directx`, `multimedia/opengl` |
| NDIS | `net/ndis` |
| TCP/IP | `net/tcpip/driver`, `net/tcpip/tpipv6` |
| Winsock | `net/sockets`, `net/tcpip/winsock` |
| Wi-Fi / WZC | `net/layer2svc` |
| RPC | `com/rpc` |
| COM/OLE | `com/ole32` |
| SxS | `base/win32/fusion` |
| App compat | `windows/appcompat` |
| Crypto/PKI | `ds/security/cryptoapi`, `ds/security/protocols/{schannel,kerberos}`, `ds/security/csps` |
| LSA/logon | `ds/security/base/lsa`, `ds/security/gina` |
| Active Directory | `ds/ds/src/ntdsa`, `ds/ds/schema` |
| ESE | `ds/ese98` |
| Shell | `shell/{explorer,shell32,shlwapi,comctl32}` |
| Browser engine | `inetcore/{mshtml,urlmon,wininet,winhttp}` |
| IIS | `inetsrv/iis` |
| Terminal services | `termsrv` |
| Printing | `printscan/print/{spooler,drivers}` |
| Installer | `admin/darwin` |
| Setup | `base/ntsetup`, `*/setup`, `tools/postbuildscripts` |
| Build tools | `sdktools/{build,nmake,rc,mc}`, `com/rpc/midl` |
| Build env scripts | `tools/razzle.cmd`, `tools/makefile.def`, `tools/projects.inc` |

### 12.3 External references to consult per area

| Area | Reference |
| --- | --- |
| TLS 1.2/1.3 | RFC 5246, RFC 8446, RFC 5288 (AES-GCM), RFC 6066 (SNI), RFC 5746 (renegotiation), RFC 7627 (EMS), RFC 7905 (ChaCha20) |
| AES-GCM | NIST SP 800-38D; CAVP test vectors |
| Kerberos AES | RFC 3962, RFC 8009 |
| SHA-2 | FIPS 180-4 |
| PBKDF2 | RFC 8018 |
| PKCS#12 | RFC 7292, PBES2 in RFC 8018 |
| IPv6 | RFC 8200, 4291, 4861, 4862, 4941, 6724, 8415 |
| TCP | RFC 9293, 5681 (congestion), 8312 (CUBIC), 3168 (ECN), 4821 (PLPMTUD), 7323 (window scaling/timestamps) |
| SMB | [MS-SMB2], [MS-SMB], [MS-SPNG], [MS-NLMP] |
| exFAT | Microsoft exFAT specification (current revision) |
| UEFI | UEFI Specification 2.10, ACPI Specification 6.5 |
| PCIe | PCI Express Base Specification; ACPI MCFG/ECAM |
| xHCI | xHCI Specification 1.2 |
| NVMe | NVM Express Base Specification 2.0 |
| AHCI | Serial ATA AHCI Specification 1.3.1 |
| ACPI AML | ACPI Specification, sections 19–20 (AML grammar, 64-bit integers) |
| USB HID | HID 1.11, HID Usage Tables |
| UVC | USB Device Class Definition for Video Devices 1.5 |
| PE/COFF | Microsoft PE and COFF Specification |
| Win32 API surface | Microsoft Learn API index; One-Core-API export lists |
| ASLR/DEP/SEHOP/CFG | Microsoft mitigations documentation; Windows Internals |
| UIA/MSAA | Microsoft UI Automation and MSAA documentation; WCAG 2.2 |
| Unicode | UAX #15 (normalization), UTS #35 (CLDR), IANA tzdata |

### 12.4 Measurable release checklist (copy into each release issue)

```text
[ ] R1  Build green, ledger published, zero unexplained failures
[ ] R2  Install+boot on 4 hypervisors, 2 physical machines, 20 cold boots
[ ] R3  72h soak + 500 power-loss cycles, chkdsk clean
[ ] R4  Top-100 HTTPS sites OK, TLS1.2 only, SMB share mount OK, DHCP/DNS failover OK
[ ] R5  DEP/ASLR/SEHOP verified, legacy protocols off, baseline scan clean
[ ] R6  App matrix Tier 1 green; known-issues updated
[ ] R7  Boot ≤30s SSD, idle CPU ≤2%, no >10% perf regression
[ ] R8  Dogfood journal complete with verdict
[ ] R9  Update install/rollback verified; offline repair verified
[ ] R10 Docs match reality; no overclaim in README/PLAN
```

### 12.5 Open questions that must be answered before M1

1. Which exact host OS/toolchain is the supported build environment long-term (`ENV-001/006`)?
2. Can the tree legally be distributed in any form (`GOV-001`)?
3. Is i386 the only shipping architecture for the next 12 months (`KRN-001`)?
4. Which 6 physical machines are the reference HCL (`DRV-060`)?
5. Which browser is the supported one, and at what version (`APP-010`)?
6. Does the project accept LGPL components as dynamically linked DLLs (`GOV-004`)?
7. What is the compatibility target: "runs XP-era software safely" or "runs 2026 software"
   (the answer changes the ordering of Phase 5 vs. Phase 6)?

---

## 13. Change log

| Date | Author | Change |
| --- | --- | --- |
| 2026-10-31 | initial audit | Created `PLAN.md`. Baseline audit of `c24c9fcb8`; 48 findings registered (F-01…F-48); 18 blocked/infeasible items registered; phases 0–15 and milestones M0–M8 defined. Re-verified the 15 pre-existing `agents/audit/` findings against the working tree and corrected their status (5 fixed, 10 open, 1 partially fixed → F-11). |

### 13.1 Maintenance procedure

1. **Weekly:** move task statuses; add a change-log row if any `[x]`/`[!]` changed.
2. **Per release:** re-run the §4 verification pass; update the findings register with new IDs
   (`F-46`, …) rather than editing history; refresh §12.1 counts.
3. **Per milestone:** revisit §10 — a blocked item may become unblocked only with a written spike.
4. **Never:** delete a task without `[-]` + reason; claim a gate is green without the artifact.

### 13.2 Regenerate the counts

Run `python3 agents/plan_stats.py --write` after every status change; it rewrites the snapshot
in §0.6 and fails if two tasks share an ID.
