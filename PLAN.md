# PLAN.md — NEONT 5 "daily-driver in 2026" roadmap

> **Scope of this file:** an exhaustive, status-marked TODO roadmap for turning this source tree into a secure, compatible, stable, modern daily-driver OS. It is a planning document only. **Nothing listed here has been implemented.** No build, install, boot, or test of the NT code was run for this plan. Work that was run is listed in section 3 with its result.
>
> **Baseline:** `main` at `c24c9fcb83ef2ae3d7c600a4aff557db75e5732b`, working branch `arena/58fa8037-neo-nt5`. Audit date: 2026-10-31.
>
> **Parallel plan:** open PR #26 (`arena/0dffc95c-neo-nt5`) also adds a `PLAN.md` (278 lines) from the same baseline. Decision DEC-06 (section 9) decides which file is canonical before anything is merged.

---

## 0. How to read and maintain this file

### 0.1 Status markers

| Marker | Meaning |
|---|---|
| `[ ]` | Open. Includes work that is planned but not yet verified on target hardware. |
| `[x]` | Done **to the scope stated in the item**. Evidence goes on an indented `Evidence:` line (commit or PR, command, configuration, result, residual risk). |
| `[!]` | Blocked or infeasible under current constraints. The item states the unblock condition or the alternative. |

### 0.2 Priority

| Priority | Meaning |
|---|---|
| **P0** | Blocks safe use or lawful distribution. Do first. |
| **P1** | Required for a first supported daily-driver baseline. |
| **P2** | Expands compatibility or coverage. |
| **P3** | Optional or long-horizon. |

### 0.3 Work class

| Class | Meaning |
|---|---|
| **BP** | Backport or fix of code **already in the tree**. The source exists; the work is bounded. |
| **PORT** | New implementation or large port **inside the existing architecture** (same kernel model, same API family). |
| **ARCH** | Fundamental architectural change: new driver model, new ABI, new trust model, or a multi-team project. |

### 0.4 Size (estimates only)

| Size | Rough meaning |
|---|---|
| **S** | ≤ 1 engineer-week |
| **M** | ≤ 1 engineer-month |
| **L** | ≤ 1 engineer-quarter |
| **XL** | More than a quarter, or multi-team. |

Sizes are planning estimates, not commitments. They should be replaced by measured estimates after the first build baseline (BLD-006).

**QW** (quick win) marks items that are S-size or smaller, are BP, have low ABI risk, and can be verified in one VM session.

### 0.5 IDs and maintenance rules

- ID format: `AREA-NNN`. IDs are never reused. A task that needs splitting gets a suffix (`SEC-006a`, `SEC-006b`) instead of renumbering.
- Each item line is followed by: **Evidence** (repo paths verified in this audit, or the research that motivates the item), **Done when** (measurable where it is a major task), and **Deps**.
- Never delete an open requirement silently. Move it to `[!]` with the reason, or split it.
- When the tree changes, re-verify the Evidence paths (`git grep`, `agents/generate_catalog.py --check`).
- New findings get new IDs and a line in the change log (section 11).
- Items marked "**verify**" are hypotheses that still need a check. They must not be treated as facts until the check is recorded.

---

## 1. Executive summary

**What this tree is (verified).** A proprietary-derived source snapshot of the NT 5.x line. Its version macros say 5.1 build 2600 (`public/sdk/inc/ntverp.h`, `published/sdk/inc/ntverp.h`), and a build toggle `NEONT_BRANDING` rebrands it as "NEONT". It has 277,941 tracked files, 21 top-level trees (per `agents/README.md`), a `.git` of about 1.7 GB, and about 6.6 GB on disk. It contains x86 and AMD64 code, plus IA-64, Alpha, and MIPS remnants. There is no ARM or ARM64 code.

**What it is not (verified).**
- It is not a buildable product on Linux. The Windows build environment (`razzle`, `build.exe`, and the MSVC toolchain) is not present, and the repo's own docs say no full build has been verified (`agents/build-and-release.md`).
- Some build inputs are absent: `tools/missing.cmd`, `tools/oscdimg.cmd`, the `QFE/` tree, and several `dirs` targets (section 6.3, BLD-007).
- Its own defaults are weak. Examples: SSLv2 and SSLv3 are enabled by default; `/GS` is opt-in; no image is built with NX, ASLR, SafeSEH, or CFG flags.

**Bottom line.** A "modern daily driver" is **not reachable by backports alone**. The verified gaps that set the scope are:

1. **Security defaults and crypto.** Schannel's cipher table is RC4/DES/3DES with MD5/SHA-1 MACs, and contains zero AES references. No TLS 1.1–1.3 identifiers exist in the tree. SMB 2/3 is absent. There is no NX on 32-bit PAE. No KASLR exists.
2. **Hardware stacks.** No xHCI, AHCI, NVMe, NDIS 6, WDDM, Bluetooth, WPA2/CCMP, x64 UEFI loader, Secure Boot, x2APIC, or HPET support was found. Processor count is capped at 32 on x86.
3. **API surface.** The SDK headers and `base/win32` have no post-XP APIs from the checked list (section 2, V-20). There is no Filter Manager, no WDF/KMDF directory, no D3D9+/DXGI, no WASAPI/MMDevice, no Media Foundation, and no UI Automation.
4. **Known defects.** Verified and open: A01, A02, A05, A06, A07, A09, A13, A14, A15 (section 3).

**Recommendation (for the owner to decide, see section 9):**
- Keep this tree as the **x86 first, AMD64 second** platform. Retire IA-64, Alpha, and MIPS from the default build.
- Do the **quick wins and the security-default work first** (section 8). They are cheap and they remove risk from any lab build.
- Treat **TLS/crypto, SMB2/3, NDIS 6, xHCI/AHCI/NVMe, x64 boot, and the API shim layer** as the major projects. Each has a measurable gate in section 7.
- Treat **modern browsers, .NET 4.x+, Wi-Fi/Bluetooth, WDDM GPU drivers, Secure Boot/VBS, Office, and Windows 10/11 app-model compatibility** as `[!]` unless the owner funds a clean-room stack for each (section 4).

---

## 2. Verified baseline (V-xx)

These are facts established by reading the tree during this audit. Each one cites its evidence. Counts are word- or path-level unless stated otherwise.

| ID | Verified fact | Evidence |
|---|---|---|
| V-01 | Version macros: 5.1 build 2600, `VER_PRODUCTBUILD /* NEONT */ 2600`. Public and published copies are identical. | `public/sdk/inc/ntverp.h`, `published/sdk/inc/ntverp.h` |
| V-02 | Top-level trees: 21 (per `agents/README.md` and `generate_catalog.py --check`, which passes). | `agents/generate_catalog.py`, `agents/catalog/` |
| V-03 | Root `dirs` omits `termsrv/`, `public/`, `tools/`, `developer/`. | `dirs` |
| V-04 | No `LICENSE`, `.gitignore`, `.gitattributes`, `.github/`, or CI configuration in the repo. | repo root listing |
| V-05 | About 6,000 checked-in binaries, including 1,924 `.exe`, 1,803 `.dll`, 2,642 `.lib`, 572 `.pdb`, 68 `.sys`. | `git ls-files` counts |
| V-06 | Build-language mix: 13,139 files named `sources`; 13,392 files named `makefile`; 3,650 `dirs`; 1,028 `.dsp` and 490 `.dsw` (VC6 project files); 72 `.sln`; 32 `.vcproj`; **0** `.vcxproj`; 2,571 `.cmd`/`.bat`; 881 `.pl`/`.pm`; 1,027 `.vbs`/`.js`; 3 `.py`; 0 `.ps1`. | `git ls-files` counts |
| V-07 | Build-number parser `tools/genbldno.pl` expects `/* NT */`; headers say `/* NEONT */`. | `tools/genbldno.pl`, `public/sdk/inc/ntverp.h` (audit A01 reproduces) |
| V-08 | `tools/i386mk.inc:175–176` adds `/GS` only when `BUFFER_OVERFLOW_CHECKS` is set. About 21 `sources` files mention the switch; 5 set it to 1. | `tools/i386mk.inc` |
| V-09 | No `/NXCOMPAT`, `/SAFESEH`, `/guard:cf`, `/HIGHENTROPYVA`, or `/CETCOMPAT` in build definitions. The whole-tree `DYNAMICBASE` hit is a **false positive**. | `git grep` in `tools/`, `*.inc`, `sources` |
| V-10 | 32-bit PAE: `MM_PTE_EXECUTE 0x0 // read-only on x86`. AMD64 has a NoExecute bit. | `base/ntos/mm/i386/mipae.h:399–402`; `base/ntos/mm/amd64/miamd.h:2708` |
| V-11 | `MAXIMUM_PROCESSORS` is 32 on x86 and 64 on x64. | `public/ddk/inc/ntddk.h` ~L5741–5748 |
| V-12 | No processor-group APIs (`KeQueryActiveProcessorCountEx`, `GetCurrentProcessorNumberEx`, `KeGetProcessorNumberFromIndex`, `KeQueryActiveGroupCount`) in `base/ntos` or `public/ddk`. | `git grep -lw` |
| V-13 | No x2APIC, HPET, KASLR, PatchGuard, `_OSC`, or Secure Boot references found in the scoped trees. | content greps on `base/`, `base/hals`, `base/busdrv/acpi` |
| V-14 | MSI capability parsing exists in PCI enumeration. MSI-X: found in 2 files only (**verify**). | `base/busdrv/pci/enum.c` |
| V-15 | Kernel debug transports present: `kd64`, `kdcom`, `kd1394`. No KDNET (`kdnet`) found. | `base/ntos/kd64`, `base/boot/kdcom`, `base/boot/kd1394` |
| V-16 | Schannel: `SP_PROT_ALL` = 0xffffffff in the SDK; `SSL2_CLIENT_DISABLED_SETTING FALSE`; default client protocol set includes SSL2. | `public/sdk/inc/schannel.h:458`; `ds/security/protocols/schannel/inc/spreg.h:115`; `ds/security/protocols/schannel/lsa/spreg.c:31` |
| V-17 | WinINet default protocols = SSL2|SSL3. WinHTTP v5 = SSL2|SSL3. WinHTTP v5.1 = SSL3|TLS1. | `inetcore/wininet/inc/defaults.h:99`; `inetcore/winhttp/v5/inc/defaults.h:94`; `inetcore/winhttp/v5.1/inc/defaults.h:85` |
| V-18 | Schannel cipher table: RC4-128 with MD5/SHA-1 MACs, DES/3DES suites. **0** `CALG_AES` references and **0** GCM, ECDHE, ECDH, or ChaCha references in `ds/security/protocols/schannel`, `ds/security/cryptoapi`, `public/sdk/inc`. | `ds/security/protocols/schannel/spbase/cliprot.c` ~L80–100; `git grep` counts |
| V-19 | No TLS 1.1, 1.2, or 1.3 identifiers in the source. Only `SP_PROT_TLS1` style flags. | `git grep` for `TLS1_1`, `TLS1_2`, `TLS1_3`, `TLS 1.2`, `TLSv1.2` = 0 |
| V-20 | Post-XP Win32 APIs absent from `public/sdk/inc` and sampled `base/win32`: `GetTickCount64`, `CancelIoEx`, `CreateSymbolicLinkW`, `SetThreadDescription`, `InitializeSRWLock`, `WaitOnAddress`, `BCryptGenRandom`, `CreateFile2`, `GetSystemTimePreciseAsFileTime`, `IsWow64Process2`. | path and content greps |
| V-21 | `windows.h:22` sets `WINVER 0x0501`. No `sdkddkver.h` in the tree. | `public/sdk/inc/windows.h:22` |
| V-22 | Absent SDK headers: `bcrypt.h`, `ncrypt.h`, `wlanapi.h`, `netioapi.h`, `dwmapi.h`, `d2d1.h`, `dxgi.h`, `d3d10.h`, `d3d11.h`, `d3d12.h`, `mmdeviceapi.h`, `audioclient.h`, `xinput.h`, `winusb.h`, `ws2bth.h`, `mfapi.h`, `propsys.h`, `wincodec.h`, `winrt.h`, `BluetoothAPIs.h`, `dinput8.h`, `xaudio2.h`, `nvme.h`, `UIAutomationClient.h`. Present: `iphlpapi.h`, `ws2tcpip.h`, `winhttp.h`, `setupapi.h`, `cfgmgr32.h`, `storport.h`, `usbdi.h`, `hidclass.h`, `ntddk.h`, `wdm.h`, `ndis.h`, `ntifs.h`, `dinput.h`, `dsound.h`. | `public/sdk/inc`, `public/ddk/inc` listings |
| V-23 | NDIS is version 5 (`NDIS_MINIPORT_MAJOR_VERSION 5`); no NDIS 6 identifiers. | `public/ddk/inc/ndis.h`; content grep = 0 for `NDIS_MINIPORT_MAJOR_VERSION 6` |
| V-24 | Storage: no AHCI, NVMe, or xHCI identifiers (word-match = 0 in source). Storport header and libraries are present. IDE/ATAPI present (`drivers/storage/ide`). GPT handling in `drivers/storage/partmgr/partmgr.c`. | `git grep -lwiE 'nvme|ahci|xhci'` = 0 real hits |
| V-25 | USB: EHCI, OHCI, and UHCI miniports present (`drivers/wdm/usb/hcd/miniport/`). No xHCI. | directory listing |
| V-26 | Video: VGA-era miniports (`drivers/video/ms`), Matrox MGA. No WDDM (`DXGKDDI`/`WDDM` content = 0). | directory listing; content grep |
| V-27 | Audio: PortCls and WDMAUD/KS present. HDAudio controller driver not located by path (**verify**). | `drivers/wdm/audio/` (557 files) |
| V-28 | NIC drivers in `drivers/net/ms`: `e100bex` (Intel 82557-class, NDIS 5) and `ne2000`. No `e1000`, `rtl8169`, `bcm57xx`, or `rtl8139` drivers found by name. PXE UNDI sources (3c90x) under `base/remoteboot`. | directory listing; path grep |
| V-29 | Filter Manager (`fltMgr`) not present. `FltRegisterFilter` = 0 hits in `base/` and `drivers/`. `base/fs/fltsamples` contains samples only. | `git grep -lw FltRegisterFilter` = 0 |
| V-30 | No WDF/KMDF or UMDF framework directory found by path. | `git ls-files` path grep |
| V-31 | File systems: NTFS (`base/fs/ntfs`), EFS, FAT (`base/fs/fastfat`), UDF (`base/fs/udfs`), CDFS. No exFAT, no ReFS, no BitLocker volume encryption (FVE hits are NTFS-side only, **verify**). | `base/fs/` listing |
| V-32 | SMB: `base/fs/srv` (server) and `base/fs/rdr2` redirector present. **0** SMB2/SMB3 identifiers in `base/fs`, `net`, `base`. No `RequireSecuritySignature` policy checked yet (**verify**). | `git grep -liE 'SMB2'` = 0 in scoped trees |
| V-33 | Networking: TCP SACK, window scaling, and timestamps present (`net/tcpip`). **0** CUBIC, TFO, or syncookie references. IPv6 present (`net/tcpip/tpipv6`). IPsec present (`net/ipsec`). No IKEv2 (RFC 7296) identifiers. | `git grep` counts |
| V-34 | 802.1X/EAPOL present (`net/layer2svc/eapol`, `net/config/netman/eapol`). **0** WPA2/CCMP/RSN in wireless code, except a `base/cluster` CCMP file. No Wi-Fi 802.11 MAC stack. No Bluetooth stack (IrDA only, `net/irda`). | path and content greps |
| V-35 | CredSSP, NLA: **0** references in `termsrv`, `net`, `ds/security`. | `git grep` |
| V-36 | Kerberos: RC4-HMAC used in `ds/security/protocols/kerberos/client2/credman.cxx` (lines 280, 292). No AES etype identifiers (case-insensitive search for `aes` in kerberos tree = 0). | `git grep` |
| V-37 | NTLM: NTLMv2 present; server-side LM compatibility check `NtLmCheckLmCompatibility` exists; client path (`ctxtcli.cxx:227`) **not traced**. No `NoLMHash` identifier found. | `ds/security/protocols/msv_sspi/ntlm.cxx` (server check); `ds/security/protocols/msv_sspi/ctxtcli.cxx` (client, not traced) |
| V-38 | Cryptography API: wincrypt defines SHA-1 (`ALG_SID_SHA` 4), MD5 (3), AES SIDs (14–17). No SHA-256/384/512 SIDs found in scoped headers (**verify** full wincrypt). Default RSA key-size UI default 1024 (`ds/security/cryptoapi/ui/wizards/wizards.cpp:922`). | `public/sdk/inc/wincrypt.h`; wizards |
| V-39 | Root certificates shipped as files: 167 `.cer`, 24 `.crt`, 23 `.der`, 8 `.sst` (certs directory `ds/security/cryptoapi/pkitrust/initpki/certs/` holds 160 tracked files). | `git ls-files` counts |
| V-40 | Key and certificate material tracked: 16 `.pvk`, 4 `.snk`, 27 `.spc`, 8 `.sst`, 64 files with `.key` extension (contents not classified), and others. Examples: `ds/security/cryptoapi/pkisign/tools/makecert/`, `enduser/netmeeting/nmmkcert/root.pvk`, `termsrv/remdsk/rds/cert/root.pvk`. **Contents not read or reproduced in this plan.** | `git ls-files` |
| V-41 | Product keys in `README.md` under the "Product Keys" section (about lines 75–79). Values not reproduced here. | `README.md` |
| V-42 | Browsers and runtimes: IE-era stack only (`inetcore/mshtml`, `inetcore/outlookexpress`, `inetcore/urlmon`, `inetcore/wininet`, `inetcore/winhttp`). No Chromium, WebKit, Gecko, CPython, or WebSocket identifiers. `netfxoc` present; `netfx` directory absent per `com/dirs`. | directory listings; `git grep` |
| V-43 | HTTP/2: none. The `http2.cxx` file is RPC-over-HTTP v2, not HTTP/2. | `com/rpc/runtime/trans/common/http2.cxx` |
| V-44 | Multimedia: DirectShow (`multimedia/dshow`), DirectDraw, DirectSound, DirectInput, D3D8 (`multimedia/directx/dxg/d3d8`). No D3D9 directory, no DXGI, no D3D10/11, no XInput, no Media Foundation (`mfplat` = 0, `mfapi.h` absent). | path and content greps |
| V-45 | Codecs: no H.264, AAC, or Vorbis decoder identified by path. Several path matches for `aac`, `h264`, `avc`, `ogg`, `vorbis` turned out to be noise (AV/C, WMI, and similar). **Verify before citing any codec.** | path greps |
| V-46 | Accessibility: MSAA (`windows/oleacc`) present. UI Automation: 3 files, no provider framework (`UIAutomationClient.h` absent). Accessibility wizard present (`shell/osshell/accessib`). | path and content greps |
| V-47 | Locales: 141 `.nls` files. `loc/` is near-empty. Installer localization data exists in `admin/darwin/data/intl/` (`*.ptb` for pt-BR). IME directories present for Simplified/Traditional Chinese, Japanese, Korean (`windows/feime`, **verify path**). | path counts |
| V-48 | Test-like directories: 1,644 (by name pattern); 4,952 test source files (by path). Counts are approximate. | path counts |
| V-49 | Code-health markers in ~130,400 source-like files: TODO 10,197; HACK 1,954; XXX 1,670; FIXME 138. | content counts |
| V-50 | Unsafe C-library call sites (word-matches, including comments and samples, **not vulnerability counts**): strcpy ~12.6k, sprintf ~11.8k, lstrcpy ~21.5k, wsprintf ~24k, strcat ~6.8k, gets ~215. | content counts |
| V-51 | Safe-string helpers present: `base/strsafe`, `ntstrsafe`. | path listing |
| V-52 | Triage: `base/ntos/io/iomgr/triage.c:484` defines `TriageHasLoaderChecksum`; `base/ntos/mm/triage.c:127` declares it; `base/ntos/mm/triage.c:298` calls it. Present, not a duplicate. | `git grep` (PERF-NTOS-001) |
| V-53 | Power: `base/ntos/po` (hibernate, suspend, idle), ACPI battery drivers (`base/busdrv/acpi/battc`, `base/busdrv/acpi/cmbatt`). | directory listings |
| V-54 | Boot: `base/boot/efi` contains an ia64 subtree and generic EFI helpers. No amd64/x64 EFI loader directory found by path. `base/boot/oschoice`, `base/boot/startrom`, `base/boot/tftplib` present. | directory listings |
| V-55 | ACPI: AML interpreter under `base/busdrv/acpi/driver/nt/` (`amlisupp.c`, `amlinew` tree). `_OS` string is set from `NEONT_BRANDING` (A06). | `base/busdrv/acpi/driver/nt/amlisupp.c:24–35` |
| V-56 | Setup and install: `base/ntsetup` present; `base/ntsetup/legacy/dll/dospif.c` present. NTBackup source absent: only `tools/postbuildscripts/ntbackuponpersonal.cmd`. | directory listings |
| V-57 | Time bomb: `tools/postbuildscripts/timebomb.cmd` present (its policy is not evaluated here). | file listing |
| V-58 | Build helper files referenced by README are absent: `tools/missing.cmd`, `tools/oscdimg.cmd`. Present: `tools/razzle.cmd`, `tools/ntenv.cmd`, `tools/postbuild.cmd`, `tools/postbuildscripts/pbuild.dat`. | file listing |
| V-59 | Dangling build targets (approximate parser, **not a build break until evaluated**): ~380 of ~12,778 `DIRS` tokens do not map to a tracked directory. Examples: root `dirs` target `QFE`; `drivers/dirs` targets `infiniband`, `vsm`, `oem`; `com/dirs` targets `OleAutomation`, `netfx`; `inetcore/dirs` targets `java`, `vml`; `termsrv/dirs` target `newclient`. | `/tmp` scratch parser; `dirs` files |
| V-60 | `agents/verify.py` currently exits 1 with 3 errors (section 3, rows A14/A15 and missing `.jules.md`). `agents/generate_catalog.py --check` exits 0. | run in this audit |
| V-61 | Repo settings: public; default branch `main`; GitHub **Issues and Discussions disabled**; PR #26 open; PRs #22–#25 merged. | `gh repo view`, `gh pr list` |
| V-62 | PR #22 (merged) changed `shell/shdocvw/{dnserror,navcancl,servbusy}.htm`. `AGENTS.md` forbids visual `.htm`/`.html` edits. | `gh pr view 22 --json files` |
| V-63 | PR #23 (merged) changed `admin/wmi/wbem/xmltransport/client/helpersources/httpconnectionagent.cpp` (A11 fix). | `gh pr view 23 --json files` |
| V-64 | `git rev-list --count HEAD` = 1. The baseline is a single commit (merge of PR #25, 2026-10-22, per the audit notes). Earlier history is not in this clone. | `git rev-list --count HEAD` |

---

## 3. Audit register (A-xx) and status on 2026-10-31

Status words: **Present** = defect still in current source. **Fixed** = fixed in current source, verified by reading the code. **Mitigated** = not a direct fix, but the risk is reduced. **Stale probe** = the reproduction script tests an old snippet, so its result does not describe current source. The three audit tooling problems are in section 6.4 (TST-003).

| ID | Title (from `agents/audit/`) | Status (2026-10-31) | Evidence | Plan item |
|---|---|---|---|---|
| A01 | build: NEONT version-header comment breaks `genbldno.pl` | **Present** (probe exit 1) | V-07 | BLD-001 |
| A02 | build: `fdisk.dlg` loses CONTROL fields after `#endif` | **Present** | `base/fs/utils/fdisk/fdisk.dlg` line 15 (`#endif,-1,...` trailing tokens) | BLD-002 |
| A03 | bug: SMSS reads uninitialized `ValueData` when Branding is absent | **Fixed** (`ValueData = NULL` before the query, line 1537; REG_SZ checked before use, lines ~1545–1561) | `base/subsys/sm/server/sminit.c` | TST-004 (close after test) |
| A04 | security: SMSS calls `wcslen` on unvalidated REG_SZ | **Mitigated**: `sminit.c` checks `DataLength >= sizeof(WCHAR)` and forces a terminating NUL on the last character (~line 1555) before `wcslen` (~line 1580). Not a full length validation; re-check in TST-004 | `base/subsys/sm/server/sminit.c` | TST-004 |
| A05 | bug: default `OS=NEONT` breaks `Windows_NT` batch branches | **Present** | `base/subsys/sm/server/sminit.c` ~L1565–1574: the `OS` value is `NEONT` when branding is on and `Windows_NT` otherwise, unless a `Branding` value overrides | BOOT-005 |
| A06 | bug: branding changes firmware-visible ACPI `_OS` identity | **Present** | `base/busdrv/acpi/driver/nt/amlisupp.c:24–35` | BOOT-004 |
| A07 | bug: multimedia product resources ignore `NEONT_BRANDING=0` | **Present** (strings hard-coded to `"NEONT (i386)"`; consumers and gating not traced) | `multimedia/media/mmcaps2k/mmcaps.h` lines 66–78 (the product-name lines never reference `NEONT_BRANDING`; the toggle is defined only at lines 43–44) | BLD-003 |
| A08 | bug: UL Win9x samples zero-length `memset` for OVERLAPPED | **Fixed in current source**. Probe reproduces an old snippet (**stale probe**). 0 transposed hits. | `inetsrv/iis/iisrearc/ul/win9x/src/test/cmd/snd/snd.c:50` | TST-003 |
| A09 | bug: UL `snd` accepts message lengths beyond its stack buffer | **Present**. Unbounded `gets()` into `pBuffer[CMD_BUFFER_SIZE=2048]`; `atoi()`-derived `ulSize` unchecked before the write loop. ASan reproduction is from a **reconstruction**, not the original binary. | `inetsrv/iis/iisrearc/ul/win9x/src/test/cmd/snd/snd.c`; `cmd/cmd.h:31` | SEC-015 |
| A10 | bug: `TLSDBLicenseAddEntry` reports success after insert fails | **Fixed** (verified by reading lines ~372–460). Probe is **stale or crashes**. | `termsrv/license/tlserver/server/license.cpp` | TST-004 |
| A11 | bug: WMI HTTP header query returns success and uninitialized data on failure | **Mostly fixed**. Residual: returns `S_OK` without setting `*ppszBuffer` when the first `HttpQueryInfo` succeeds. | `admin/wmi/wbem/xmltransport/client/helpersources/httpconnectionagent.cpp` ~L575–620 | TST-004 |
| A12 | security: PPP CHAP user-session key zeroing clears only a pointer width | **Fixed** (prior status "stale" confirmed as fixed in source). Not an open item. | `net/rras/ras/ppp/common/clsa.c` ~L680–690 | TST-004 |
| A13 | bug: NetMeeting codec begin functions never set `DecompressStarted`/`CompressStarted` | **Present**. Re-read so far: assignment-in-condition at `sa_api.c` lines 564–873 in `dech261` and `dech263`. The "flag never set" claim still needs a line-level check. | `enduser/netmeeting/av/codecs/dec/dech261/sa_api.c`; `dech263/sa_api.c` | TST-008 |
| A14 | docs: README documents `CkhKernel` razzle switch | **Present** | `README.md:33` vs `tools/razzle.cmd:96` (`ChkKernel`) | BLD-004 |
| A15 | security: README publishes product keys | **Present** (values **not** reproduced here) | `README.md`, "Product Keys" section | GOV-004 |

**Additional verified findings (N-xx), not in the original audit:**

| ID | Finding | Evidence | Plan item |
|---|---|---|---|
| N-01 | Schannel default enables SSLv2 for clients and `SP_PROT_ALL` for servers | V-16 | SEC-001, SEC-002 |
| N-02 | Cipher suites are RC4/DES/3DES with MD5/SHA-1 MACs; **0** AES in Schannel | V-18 | SEC-004, CRY-001 |
| N-03 | Kerberos default encryption type is RC4-HMAC on at least one client path | V-36 | AUT-001 |
| N-04 | `/GS` is opt-in; `NXCOMPAT`, `DYNAMICBASE`, `SAFESEH`, `CFG` absent | V-08, V-09 | SEC-006 to SEC-010 |
| N-05 | Build number parser / header marker mismatch blocks the version step | V-07 | BLD-001 |
| N-06 | `TriageHasLoaderChecksum` is present and used (not a duplicate) | V-52 | MEM-003 |
| N-07 | `verify.py` fails on broken relative links (`agents/audit/14-docs-chkkernel.md`, `agents/audit/15-security-readme-keys.md`) and a missing `agents/components/.jules.md` | V-60 | TST-002 |
| N-08 | Filter Manager absent: the minifilter ecosystem (AV, encryption, sync clients) cannot run | V-29 | FS-014 |
| N-09 | No processor-group APIs: systems with more than 64 logical processors cannot be supported on AMD64 without ARCH work | V-12 | KRN-001 |

---

## 4. Hard constraints and infeasibility register

Every item here is `[!]` or a constraint that other items depend on. Read this section before scheduling work.

### 4.1 Support lifecycle (verified)

- Windows XP extended support ended **2014-04-08**; Windows Server 2003 support ended **2015-07-14** [1](https://www.newsboss.com/windows-xp-support-ends). Microsoft does not supply security patches for this code. Every applicable public vulnerability must be triaged and fixed in-house (SEC-030, SEC-031).
- Microsoft's own update service cannot be used for this line. The update channel must be built and signed separately (UPD-001).

### 4.2 Legal, licensing, and provenance

- **Proprietary source.** `README.md` states the provenance is not established. Redistribution, modification, and any publication need written rights review (GOV-001). Do not treat this plan as a license grant.
- **Third-party code and blobs.** Crypto, JPEG, and handwriting data are vendored (SUP-001 to SUP-003). Each needs a license record.
- **Copyleft and clean-room constraints.** Reusing code from copyleft projects, including ReactOS (copyleft components; verify per file), Wine (LGPL-2.1-or-later [2](https://github.com/Grys73/wine)), and VxKex-style shims, may create license obligations. Wine's Clean Room Guidelines are quoted in a public issue as forbidding LLM-generated code in Wine [3](https://github.com/chaoss/wg-ai-alignment/issues/108); the wiki page it quotes is `https://gitlab.winehq.org/wine/wine/-/wikis/Clean-Room-Guidelines` (not fetched directly). **Verify upstream policy before adopting any code, and before any AI-assisted contribution to Wine-derived work.**
- **Codec and font licensing.** Patent pools (AAC, AVC/H.264, AC-3, MPEG-2) and font redistribution rules apply to shipped media (GOV-008, MMD-002). Distribution may be blocked until licenses are obtained, even for a lab build.
- **Trademarks.** The Windows name and Microsoft strings in shipped resources need a naming policy (GOV-005).
- **Product activation.** Any activation work must be a legitimate local license model. Bypassing a vendor activation system is out of scope (INS-005).
- **CSS (DVD) decryption** requires a license. Not planned (MMD-005 is `[!]`).

### 4.3 Hardware and firmware

- x64 UEFI loader and Secure Boot trust chain (BOOT-001, BOOT-006) require key ownership decisions (DEC-02, GOV-003).
- Modern Wi-Fi (802.11n/ac/ax), Bluetooth LE, and vendor GPUs require their own driver models (NET-011, NET-022, GFX-002). See 4.4.
- Modern chipsets with no open register documentation cannot be supported without vendor specs. Those devices are `[!]` per device, and must appear in the HCL (TST-011).
- Intel TXT/VT-x/AMD-V hypervisor features are not in this tree. VBS, HVCI, and Credential Guard (SEC-026) need a hypervisor that is not present.

### 4.4 Features that are not backportable without an architectural project

These are `[!]` for a daily-driver baseline unless the owner funds a dedicated clean-room project.

| Feature | Why it is not a backport | Alternative |
|---|---|---|
| **Modern browsers (Chromium, Firefox)** | Chrome 109 was the last release to support Windows 7 and 8.1 [4](https://www.neowin.net/news/google-chrome-109-now-available-last-version-to-support-windows-7-and-81/). This tree has IE-era WinINet/WinHTTP, no TLS 1.2+, no AES-GCM/ECDHE, no Win7+ APIs, and no modern GPU model. | Legacy IE-era browsing only for the lab. Any modern-browser path is a separate project (APP-002). |
| **.NET Framework 4.x and modern .NET** | `netfx` absent (`com/dirs` target missing). Modern runtimes set their own minimum OS. | APP-003, [!]. |
| **Java (JDK/JRE)** | Vendor JDKs set their own minimum OS. `java` target missing from `inetcore/dirs`. | APP-004, [!]. |
| **Python 3.x / Node.js / Git for Windows** | Upstream minimum OS versions are not in this tree. Verify before scheduling. | APP-007 (verify). |
| **Microsoft Office / Visual Studio 2015+** | Proprietary, not in tree, and needs a modern OS. | Document; no plan. |
| **WDDM GPU drivers and D3D10/11/12** | No WDDM model in tree (V-26); no DXGI. | GFX-002 to GFX-005. Options: XDDM + D3D8/9 only, or a clean-room WDDM (multi-year). |
| **Media Foundation (modern playback)** | `mfplat`, `mfapi.h` absent (V-44). | MMD-003. |
| **WASAPI / Core Audio (MMDevice)** | Absent (V-22). | AUD-003 (ARCH). |
| **UI Automation** | Absent (V-46). MSAA only. | A11Y-002 (ARCH). |
| **WPA2/WPA3 Wi-Fi, 802.11 MAC** | No 802.11 MAC or WLAN stack. Only 802.1X/EAPOL (V-34). | NET-011, [!] for daily-driver. |
| **Bluetooth stack** | No stack. IrDA only (V-34). | NET-022, [!]. |
| **Hyper-V / VMBus / VBS / HVCI** | No hypervisor, no VMBus (content = 0 for "vmbus" and "Hyper-V"). | SEC-026, [!]. |
| **TPM 2.0 / measured boot / BitLocker-with-TPM** | No TPM stack. | SEC-025, [!]. |
| **PatchGuard-equivalent kernel integrity** | No KPP (V-13). | SEC-024, [!] (needs design, not a port). |
| **Windows Update, Store, OneDrive, Microsoft account, telemetry** | Services are Microsoft-operated and not licensed here. | UPD-001 (own channel). |
| **ARM / ARM64** | No code (V-01 scope). | [!]. |
| **Windows 10/11 app model (UWP, AppContainer, WinRT)** | Absent. | APP-013, [!]. |
| **Modern PowerShell** | Absent (1 path match). | APP-005, [!]. |
| **Modern shell features (Windows Search index UI, cloud-tied features)** | Partial/absent and needs cloud services. | SHL-004, [!] for cloud. |
| **HTTP/3, QUIC** | No QUIC identifiers (earlier `quic` hits were noise). | NET-017, [!] until TLS 1.3 (CRY-007). |
| **exFAT / ReFS** | exFAT absent (V-31); ReFS absent. exFAT is documented publicly but has patent and licensing questions (GOV-008). | FS-004 (gated); FS-008 `[!]`. |
| **Modern SSD features (NVMe native, UASP, Zoned Namespaces)** | No NVMe, no UASP. | STO-002, USB-004 (ARCH). |
| **Secure Boot / UEFI-only boot on AMD64** | No x64 EFI loader (V-54). | BOOT-001 (ARCH). |

### 4.5 Upstream projects

- **ReactOS.** An open-source NT-compatible OS. Reporting says version 0.4.15 (March 2025) is its largest release to date, adds amd64 support as far as the desktop (no WOW64 yet) [5](https://www.xda-developers.com/reactos-major-update-2025/) [7](https://tech.yahoo.com/computing/articles/reactos-open-source-windows-just-200448247.html), and that it is aimed at running XP and Server 2003 era applications [6](https://softtechhub.us/2025/03/23/reactos-the-open-source-alternative-to-windows-has-been-updated/). Its license and code provenance differ from this tree. It is a candidate reference and a possible collaborator for DEC-02 option B. Do not copy code without a license review.
- **VxKex / VxKex-NEXT.** Import-table redirection that supplies newer Windows APIs to older systems, with the redirection applied per program [8](https://github.com/YuZhouRen86/VxKex-NEXT). A related fork describes loading its DLL into each enabled process through the IFEO `VerifierDlls` registry value [9](https://github.com/xuzhongxing/VxKex-NEXT). This is the closest precedent for API shims (API-002). Their READMEs target Windows 7 and 8.x hosts; their XP/Server 2003 support was **not** verified in this session (the experimental XP/2003 mode reported elsewhere needs its own check). Reimplement from documented behavior and check each license before reuse.
- **Wine.** LGPL-2.1-or-later [2](https://github.com/Grys73/wine). Useful as a behavioral reference for WinHTTP, D3D, and Winsock, subject to 4.2.
- **Not used:** a ReactOS NT6-API claim reported by a news site could not be confirmed in this session and is not relied on.

---

## 5. Phases and gates

Phases group work by dependency and risk. Items may start in an earlier phase when their dependencies are met.

| Phase | Name | Goal | Gate |
|---|---|---|---|
| **0** | Governed baseline | Legal path chosen, keys and secrets handled, build inputs fixed, first checks green | G0 |
| **1** | Build and test foundation | Reference Windows build host, scoped build, test harnesses, audit tooling repaired | G1 |
| **2** | Secure defaults (no ABI change) | Disable legacy protocols, enable existing mitigations, remove weak defaults | G2 |
| **3** | Crypto, transport, and identity | TLS 1.2, AES/SHA-2/AEAD, Kerberos AES, certificate validation, SMB2 signing | G3 |
| **4** | Platform hardware | AMD64 boot, x2APIC/HPET, MSI-X, AHCI, xHCI, NDIS 6 decision | G4 |
| **5** | Applications and shell | API shim layer, app corpus, shell, accessibility, i18n | G5 |
| **6** | Release engineering | Update channel, rollback, install media, signing, support | G6 |
| **7** | Long-horizon projects | WDDM/D3D10+, Wi-Fi, Bluetooth, Secure Boot, hypervisor features | (optional) |

Phases 2 and 3 can run in parallel with Phase 4 once Phase 1 is green.

---

## 6. Work items by subsystem

Each subsystem lists items in rough priority order. Quick wins are tagged **QW**.

### 6.1 GOV — Governance, rights, and provenance

- [ ] **GOV-001** · P0 · S — Written rights review of the whole tree: sources, binaries (about 6,000), SDK and DDK headers, fonts (`*.ttf`, `*.fon`), `*.nls`, third-party code, media.
  - Evidence: `README.md` provenance statement; V-04 (no LICENSE); V-05 (binaries).
  - Done when: a rights memo lives in `docs/legal/` and lists every top-level tree with its rights status; a named owner signs it off; distribution scope is set (DEC-01).
  - Deps: none.

- [ ] **GOV-002** · P0 · S · QW — Add `LICENSE` and `NOTICE` at the root that separate **project-owned changes** from **inherited code**.
  - Done when: both files exist; an automated check in TST-001 fails if either is missing.
  - Deps: GOV-001.

- [ ] **GOV-003** · P0 · S — Key and certificate inventory (V-40): classify each file as test-only, public-only, or production-private, and decide its disposition.
  - Done when: `docs/security/key-inventory.md` lists each file with its category and action (keep and label as test, remove, or rotate). No private key is used as a product trust anchor. A secret scan in TST-001 reports zero unapproved hits.
  - Deps: GOV-001.
  - Note: Do not print or copy key contents into docs, logs, or chat.

- [ ] **GOV-004** · P0 · S · QW — Remove product keys from `README.md` (A15), then decide the history question (DEC-04).
  - Done when: README no longer lists keys; a secret-scan rule blocks their reintroduction; the history decision (rewrite or accept, with rotation if any key is in use) is recorded.
  - Deps: DEC-04.

- [ ] **GOV-005** · P0 · S — Naming and trademark policy: the NEONT name, retained "Windows NT" strings, Microsoft copyright lines, and product names in resources (V-01, A07, A06).
  - Done when: the policy is written and all branding strings come from one configuration (BLD-003).
  - Deps: GOV-001.

- [ ] **GOV-006** · P1 · S — Clean-room and provenance policy for new code: what references are allowed (public specs, documented behavior, own tests); a provenance statement in each PR for PORT and ARCH items; prohibited sources (leaked code, disassembly-derived copies).
  - Done when: `docs/legal/clean-room.md` exists and each PORT or ARCH PR links to a provenance statement. Upstream copyleft policies (4.2) are recorded for any borrowed code.
  - Deps: GOV-001.

- [ ] **GOV-007** · P0 · S · QW — Declare the support posture: lab-only until gates G2 and G3 pass; no internet-exposed service enabled by default.
  - Done when: a `SECURITY.md` at the root states the posture and a reporting path (no public issue tracker; Issues are disabled, V-61).
  - Deps: DEC-07.

- [ ] **GOV-008** · P1 · S — Codec, font, and firmware license register: AAC, MP3, AC-3, MPEG-2, H.264 pools; exFAT; font redistribution; vendor microcode; OEM drivers.
  - Done when: each item has a status (removed, licensed, or not shipped), and no unlicensed item is in a release build.
  - Deps: GOV-001.

- [ ] **GOV-009** · P1 · M — Binary provenance: classify the ~6,000 tracked binaries as (a) rebuildable output to remove, (b) redistributable tool, or (c) test fixture. Move or drop the rest per DEC-05.
  - Done when: every binary path has a category; the tracked binary count drops by an agreed percentage (record the baseline of ~6,000).
  - Deps: DEC-05, BLD-014.

- [ ] **GOV-010** · P2 · S — Review PR #22's `.htm` changes (`shell/shdocvw/dnserror.htm`, `navcancl.htm`, `servbusy.htm`) against `AGENTS.md`, which forbids visual `.htm` edits.
  - Done when: a decision is recorded: keep (if the change is content or accessibility only, with the reason) or revert to a source-level equivalent.
  - Deps: none.

### 6.2 DEC — Decisions the owner must make

- [ ] **DEC-01** · P0 — Distribution scope: (a) private lab research, (b) internal organization, (c) public release. Each needs different rights (GOV-001).
  - Done when: recorded in section 9.

- [ ] **DEC-02** · P0 — Base strategy:
  - **(A)** keep this tree and backport/port (this plan's default assumption);
  - **(B)** use this tree as a specification and build a new clean-room kernel and base, possibly with an existing NT-compatible project (ReactOS, 4.5);
  - **(C)** hybrid: keep user-mode and application stack, replace the kernel.
  - Done when: a written cost comparison (rights, schedule, ABI, hardware reach) is recorded in section 9.

- [ ] **DEC-03** · P0 — Target platform and architecture set: x86 (PAE-capable) first, AMD64 second. Retire IA-64, Alpha, MIPS, and PPC remnants from the default traversal.
  - Done when: a supported-architectures table is approved; dead targets are excluded from the default build with a list (BLD-013), not deleted without review.

- [ ] **DEC-04** · P0 — Keys in git history: rewrite, accept, or rotate. The repo is one squashed commit at baseline, so a rewrite changes all SHAs.
  - Done when: decided and recorded; GOV-004 is complete.

- [ ] **DEC-05** · P1 — Binary storage: remove, move to an external artifact store, or Git LFS.
  - Done when: decided; BLD-014 and GOV-009 reference the decision.

- [ ] **DEC-06** · P1 — Canonical plan: this file versus PR #26's `PLAN.md` (branch `arena/0dffc95c-neo-nt5`, 278 lines, same baseline). Only one may be authoritative.
  - Done when: the owner chooses; the other is closed or merged into it by an explicit action. Until then, this file is the working copy and PR #26 is not modified.

- [ ] **DEC-07** · P1 — Tracking: GitHub Issues are disabled (V-61), so this file and `agents/audit/` are the tracker. Decide whether to enable Issues or keep this model.
  - Done when: decided and recorded.

### 6.3 BLD — Build system, toolchain, and reproducibility

- [ ] **BLD-001** · P0 · BP · S · QW — Fix the build-number parser (A01). `tools/genbldno.pl` expects `/* NT */`; headers use `/* NEONT */`.
  - Evidence: V-07; `agents/audit/01-build-number.md`.
  - Done when: `tools/genbldno.pl` extracts `2600` from both marker forms (or the marker is standardized and every parser updated, found by `git grep VER_PRODUCTBUILD`); `agents/audit_reproduce.py` case A01 passes; the result is recorded in the change log.
  - Deps: none.

- [ ] **BLD-002** · P0 · BP · S · QW — Fix `base/fs/utils/fdisk/fdisk.dlg` (A02): the `#endif` line on line 15 carries trailing tokens that make CONTROL fields disappear.
  - Done when: after preprocessing with `cl /EP` or `gcc -E -P`, both branding settings produce complete CONTROL lines; `rc` compiles the dialog without error on the reference host.
  - Deps: BLD-006 (for `rc`).

- [ ] **BLD-003** · P0 · BP · S — One source of truth for `NEONT_BRANDING`. It is defined in 23 files, and defaults are repeated (e.g., `multimedia/media/mmcaps2k/mmcaps.h` L43–44, `public/sdk/inc/ntverp.h`, `base/subsys/sm/server/sminit.c`, `base/busdrv/acpi/driver/nt/amlisupp.c`). Also fixes A07.
  - Done when: one header defines the default and all 23 files include it; `NEONT_BRANDING=0` produces "Windows NT" strings in every touched component (checked by resource dump on the reference host); `NEONT_BRANDING` controls **display strings only** (not `OS`, not ACPI `_OS` — see BOOT-004, BOOT-005).
  - Deps: GOV-005.

- [ ] **BLD-004** · P0 · S · QW — Fix A14: README:33 says `CkhKernel`; `tools/razzle.cmd:96` uses `ChkKernel`. Trust the script.
  - Done when: README matches the script; `verify.py` link check passes for this file (TST-002).

- [ ] **BLD-005** · P0 · M — Reference Windows build host, documented in `docs/build/host.md`: OS version and patch level, the chosen VC toolchain and Windows SDK, Perl version, `build.exe`, and the environment set up by `tools/razzle.cmd`.
  - Done when: a single leaf component (e.g., `sdktools/gflags`, pending verification of its dependencies) builds from clean twice with logs archived; the host recipe reproduces from a clean image.
  - Deps: GOV-001 (for any redistributed host image), DEC-03.

- [ ] **BLD-006** · P0 · L — Define and build the **scoped** set: the minimum traversal that yields kernel, HAL, `ntdll`, `smss`, `csrss`, `winlogon`, `explorer`, and setup for x86 free builds.
  - Done when: `build /cZP` over the scoped set completes with a log; error count is 0; warning count is recorded as the baseline; a per-component list of skipped targets with reasons is committed.
  - Deps: BLD-005, BLD-007.

- [ ] **BLD-007** · P0 · M — Resolve dangling `dirs` targets (V-59). Examples: `QFE` (root `dirs`); `drivers/dirs`: `infiniband`, `vsm`, `oem`, `tabletpc`, `scmmicro`; `com/dirs`: `OleAutomation`, `netfx`; `inetcore/dirs`: `java`, `vml`; `termsrv/dirs`: `newclient`.
  - Done when: a conditional-aware evaluator (BLD-008) reports zero unexpected missing targets for the scoped set; every intentional omission is listed with its reason.
  - Deps: BLD-008.

- [ ] **BLD-008** · P1 · M — `dirs`/`sources` evaluator (Python standard library only): expands `{arch}` and `!IF` conditions, handles `OPTIONAL_DIRS`, and emits a JSON build graph.
  - Done when: it reproduces the build order for the scoped set; unit tests on fixtures pass; it is documented in `agents/`. Pure tooling; no source changes.
  - Deps: none.

- [ ] **BLD-009** · P1 · S — Restore or replace `tools/missing.cmd` and `tools/oscdimg.cmd` (V-58). Restore only from a rights-cleared source. A replacement must not be described as equivalent to Microsoft's tool.
  - Done when: either a verified file is present, or `README.md` is corrected to describe the replacement; the ISO build (DIST-002) runs.
  - Deps: GOV-001.

- [ ] **BLD-010** · P1 · M — Reproducible-build inputs: fixed build date and number, deterministic PE timestamps (linker option for the chosen toolchain), no absolute paths in binaries or PDBs.
  - Done when: two clean builds of the scoped set on the reference host are byte-identical except for documented files (PDB GUID and similar); the count of differing files is recorded.
  - Deps: BLD-006, BLD-012.

- [ ] **BLD-011** · P1 · S — Warning policy: `/W3` to `/W4` where it can be enabled per component; treat new warnings in touched files as errors.
  - Done when: a `/W4`-clean result is recorded for every touched file in each PR.
  - Deps: BLD-006.

- [ ] **BLD-012** · P1 · L — Toolchain evaluation: which compiler and linker produce NT 5-compatible binaries **and** support NXCOMPAT, DYNAMICBASE, SAFESEH, `/guard:cf`, and deterministic output. Document `_WIN32_WINNT` and `NTDDI_VERSION` decisions and ABI differences (`/GS` defaults, CRT).
  - Done when: a compiler matrix exists in `docs/build/toolchain.md`; one component builds with the chosen toolchain on the reference host; ABI differences are listed.
  - Deps: BLD-005, DEC-03.

- [ ] **BLD-013** · P1 · M — Remove dead architectures from the default traversal: IA-64 (`base/ntos/ia64`, `base/hals/halia64`, `base/boot/efi/ia64`), Alpha (`axp64`), and MIPS/PPC remnants.
  - Done when: default build excludes them; the exclusion list is committed; build time and output size are measured before and after.
  - Deps: DEC-03.

- [ ] **BLD-014** · P1 · M — Reduce checked-in build outputs (2,642 `.lib`, 1,924 `.exe`, 1,803 `.dll`, 572 `.pdb`). Migrate regenerated outputs to a build directory excluded from git.
  - Done when: tracked binary count is reduced by an agreed percentage; `.gitignore` excludes build outputs (BLD-015).
  - Deps: DEC-05, GOV-009.

- [ ] **BLD-015** · P1 · S · QW — Add `.gitignore` and `.gitattributes` (binary markings for known binary extensions). **No mass normalization or reformatting** of existing files (`AGENTS.md`).
  - Done when: both files exist; `git diff --check` is clean; no existing tracked file is rewritten by the change.
  - Deps: none.

- [ ] **BLD-016** · P2 · S — Host toolset preflight: Perl, cmd, VBS/JS tools, `makefile`/`sources` handling. A missing tool produces a clear message before any build step.
  - Done when: `tools/razzle.cmd` (or a new preflight script) prints a pass/fail list and exits non-zero on a missing tool.
  - Deps: BLD-005.

### 6.4 TST — Testing, validation, and audit tooling

- [ ] **TST-001** · P0 · S · QW — One entry point for non-Windows checks (Python, standard library only). It runs: `git diff --check`; `generate_catalog.py --check`; `verify.py`; audit probes (TST-003); secret scan (GOV-003); `.htm`/`.html` guard (`AGENTS.md`); unsafe-API ratchet (TST-007); missing-LICENSE check (GOV-002).
  - Done when: one command exits non-zero on any failing check and prints a summary table; CI-ready.
  - Deps: none.

- [ ] **TST-002** · P0 · S · QW — Fix `agents/verify.py` failures (N-07): `agents/audit/14-docs-chkkernel.md` links to `../tools/razzle.cmd` (should resolve from `agents/audit/`); `agents/audit/15-security-readme-keys.md` links to `../public/sdk/inc/ntverp.h`; `agents/components/.jules.md` is missing.
  - Done when: `python3 agents/verify.py` exits 0. Only the agent docs change; no source change.
  - Deps: none.

- [ ] **TST-003** · P1 · M — Repair `agents/audit_reproduce.py`:
  - The A10 license probe raises `ValueError: substring not found` and aborts the run.
  - The A08 probe reproduces the old transposed `memset` snippet, not current source (`snd.c:50`).
  - Done when: each probe reports `pass`, `fail`, or `stale: source changed` (never a crash); A08 and A10 probes match current source; a summary is printed.
  - Deps: none.

- [ ] **TST-004** · P1 · M — Regression harnesses for fixed items: A03 (SMSS Branding with missing or malformed `REG_SZ`), A04 (unterminated `REG_SZ`), A10 (license insert failure returns an error), A11 (`HttpQueryInfo` failure path and the residual `S_OK` edge), A12 (CHAP user-session key zeroing covers the full buffer, not a pointer width).
  - Done when: each has a runnable harness (extracted C test or component DRT on the reference host); where possible, the harness fails on the pre-fix code; then the audit item is closed as `[x]`.
  - Deps: BLD-006.

- [ ] **TST-005** · P1 · M — Catalogue the existing DRT and unit tests (≈1,644 test-like directories, ≈4,952 test files, V-48): which are buildable in scope, which run on the reference host, and their pass/fail results.
  - Done when: a committed list exists (`docs/test/inventory.md`) with per-component status.
  - Deps: BLD-006.

- [ ] **TST-006** · P1 · L — Static analysis on the scoped build: run the Windows analyzer (`/analyze`, PREfast) or clang's static analyzer on extracted modules. Store a baseline.
  - Done when: analyzer runs on the scoped set; the baseline is committed; CI fails on increases in touched files.
  - Deps: BLD-006, BLD-012.

- [ ] **TST-007** · P1 · M — Unsafe-API ratchet: no new uses of `strcpy`, `strcat`, `sprintf`, `wsprintf`, `lstrcpy`, `lstrcat`, `gets` in touched code; prefer `StringCchCopy` (`base/strsafe`, V-51).
  - Done when: a checker reports the baseline (V-50 counts, recomputed per scope); the count may not increase in touched files.
  - Deps: TST-001.

- [ ] **TST-008** · P1 · S · QW — Assignment-in-condition: fix lines in `enduser/netmeeting/av/codecs/dec/dech261/sa_api.c` and `dech263/sa_api.c` (lines 564–873), `base/efiutil/sdk/shell/edit/libmenubar.c` ~L472, and the two SE self-test banners `base/ntos/se/ctseacc.c` ~L914 and `ctsertl.c` ~L1108 (`if (Result = TRUE)`). Also verify A13's "flags never set" claim line by line before fixing.
  - Done when: each `=` in a condition is intended or corrected; warning C4706 is enabled for these files; a regression test exists for the A13 flags.
  - Deps: BLD-011.

- [ ] **TST-009** · P1 · L — Fuzzing harnesses for externally reachable parsers: SMB server (`base/fs/srv`), TCP/IP packet parsing (`net/tcpip`), DHCP (`net/dhcp`), PPP/CHAP (`net/rras/ras/ppp`), X.509/PKCS parsing in `ds/security/cryptoapi/pkitrust`, Kerberos ASN.1 (`ds/security/protocols/kerberos`), WinHTTP/WinINet header parsing, HTTP.sys (`inetsrv/iis/iisrearc/ul`), USB descriptor parsing.
  - Done when: each harness runs at least 24 CPU-hours without crash or leak under AddressSanitizer or Driver Verifier; each crash is triaged with a bucket.
  - Deps: TST-001, BLD-006.

- [ ] **TST-010** · P1 · M — Driver Verifier stress on reference drivers: standard options defined; 72-hour run.
  - Done when: zero verifier violations in scope drivers over 72 hours; results archived.
  - Deps: BLD-006.

- [ ] **TST-011** · P1 · L — Hardware compatibility list (HCL): reference devices, driver version, test result, date. Devices with `[!]` status are listed too.
  - Done when: the HCL exists (`docs/hcl.md`) and each supported device has a complete row.
  - Deps: section 7.2.

- [ ] **TST-012** · P1 · L — Application compatibility suite (section 7.4): automated launch and workflow tests.
  - Done when: the suite runs headless and reports per-app pass or fail with logs.
  - Deps: BLD-006, APP-001.

- [ ] **TST-013** · P1 · M — Security test battery:
  - TLS scan of installed clients and servers (protocols offered, ciphers, certificate chain);
  - SMB negotiation tests;
  - PE hardening audit of shipped images (`/GS`, NX, ASLR, SafeSEH, CFG flags);
  - default listener scan;
  - Authenticode verification of shipped binaries.
  - Done when: the battery runs from one command and its results are recorded per build.
  - Deps: SEC-001 to SEC-010.

- [ ] **TST-014** · P2 · M — Performance harness: boot time, idle memory, shell latency, file copy throughput, network throughput, TCP connect latency (PERF section).
  - Done when: baselines are recorded for the reference configurations with versions and command lines.
  - Deps: BLD-006, section 7.2.

- [ ] **TST-015** · P2 · S — Golden manifest of shipped file hashes; diff between builds.
  - Done when: the manifest is generated per build and the diff is reviewed in each release.
  - Deps: BLD-006.

- [ ] **TST-016** · P1 · M — Crash-dump pipeline: capture dumps from test runs; symbol server; automatic bucketing.
  - Done when: a bugcheck in a test run produces a bucketed report without manual steps.
  - Deps: KRN-006, BLD-006.

### 6.5 DOC — Documentation accuracy

- [ ] **DOC-001** · P1 · S — Update the audit status in `agents/audit/` and `agents/audit/manifest.json` to match section 3. Change A03, A04, A08, A10, A11, A12 to fixed or mitigated (with evidence). Keep A01, A02, A05, A06, A07, A09, A13, A14, A15 open. The audit README is dated 2026-10-16 and is historical.
  - Done when: the audit README and manifest agree with section 3.
  - Deps: TST-003.

- [ ] **DOC-002** · P1 · S · QW — Annotate README statements that are unverified or historical (SKU list, supported-OS claims). Do not expand the README.
  - Done when: each unverified statement has a note or a link to evidence.
  - Deps: GOV-004.

- [ ] **DOC-003** · P2 · M — Keep component guides and generated catalogs in step with source changes (`generate_catalog.py` `--write` and `--check`).
  - Done when: `--check` passes on every PR.
  - Deps: TST-001.

- [ ] **DOC-004** · P1 · M — First-build guide for the reference host, written from the first real build's failures (BLD-005).
  - Done when: a new engineer can reproduce the scoped build from the guide alone.
  - Deps: BLD-006.

- [ ] **DOC-005** · P2 · S — `CHANGELOG.md`, created at the first release candidate. Initial entries come from the `[x]` items in this file.
  - Done when: entries exist for every closed item with a date.
  - Deps: DIST-004.

- [ ] **DOC-006** · P2 · S — Document the `dirs`/`sources` conditionals and link to the BLD-008 output.
  - Done when: a page exists and the link resolves.
  - Deps: BLD-008.

### 6.6 SEC — Security defaults and exploit mitigations

Priority is driven by exposure: anything network-reachable or privileged comes first.

- [ ] **SEC-001** · P0 · BP · S · QW — Disable SSLv2 and SSLv3 by default in WinINet, WinHTTP v5 and v5.1, and Schannel.
  - Evidence: `inetcore/wininet/inc/defaults.h:99` (SSL2|SSL3); `inetcore/winhttp/v5/inc/defaults.h:94` (SSL2|SSL3); `inetcore/winhttp/v5.1/inc/defaults.h:85` (SSL3|TLS1); `ds/security/protocols/schannel/inc/spreg.h:115` (`SSL2_CLIENT_DISABLED_SETTING FALSE`); V-16, N-01.
  - Done when: a default-profile client's ClientHello offers neither SSLv2 nor SSLv3 (packet capture); a default server does not accept SSLv2; the default values are documented.
  - Deps: none.

- [ ] **SEC-002** · P0 · BP · S — Schannel server default: `DEFAULT_ENABLED_PROTOCOLS_SETTING` is `SP_PROT_ALL` (0xffffffff) in `public/sdk/inc/schannel.h:458`, which enables SSLv2 and PCT for servers. Change the default to TLS1 for now and TLS 1.2 when CRY-006 lands.
  - Done when: a server-side handshake test rejects SSLv2, SSLv3, and PCT1 by default.
  - Deps: SEC-001.

- [ ] **SEC-003** · P0 · BP · S — TLS 1.0 default. RFC 8996 formally deprecates TLS 1.0 and 1.1 [10](https://www.rfc-editor.org/info/rfc8996/). Keep TLS 1.0 as an explicit policy opt-in for legacy interop.
  - Done when: a default install does not offer TLS 1.0 unless an administrator enables it; the opt-in is documented.
  - Deps: SEC-002, CRY-006.

- [ ] **SEC-004** · P0 · BP · S · QW — Cipher defaults: disable RC4 and single DES in the Schannel suite table (`ds/security/protocols/schannel/spbase/cliprot.c` ~L80–100) and remove them from the default ordering; keep 3DES as an opt-in.
  - Done when: an external TLS scan of a default server and default client shows no RC4, no single DES, no export, and no NULL suites.
  - Deps: SEC-002.

- [ ] **SEC-005** · P0 · BP · S — NTLM defaults: confirm the LM-response behavior (`NtLmCheckLmCompatibility` in `ds/security/protocols/msv_sspi/`) and the client path (`ctxtcli.cxx:227`, **not yet traced**). Default to NTLMv2-only where domain controllers permit.
  - Done when: a default workgroup install sends no LM response and no NTLMv1 in capture tests; a compatibility matrix is recorded for DC versions tested.
  - Deps: AUT-003.

- [ ] **SEC-006** · P0 · BP · M — `/GS` stack cookies by default. Today `tools/i386mk.inc:175–176` adds `/GS` only with `BUFFER_OVERFLOW_CHECKS`; 5 build files set `BUFFER_OVERFLOW_CHECKS=1` (`inetsrv/query/user.mk:18`, `multimedia/dshow/vidctl/msvidctl/sources:29`, `net/rras/cm/profwiz/sources:20`, `net/rras/cps/pbserver/sources:10`, `net/rras/cps/pbsmon/sources:11`); everything else relies on the default.
  - Done when: `/GS` is on for all user-mode and kernel-mode targets except a listed exception set (with owners); a PE audit (TST-013) finds cookies in at least 99% of scoped images.
  - Deps: BLD-012 (toolchain), BLD-006.

- [ ] **SEC-007** · P0 · PORT · M — NX compatibility flag (`/NXCOMPAT`) for all scoped images. Absent from build definitions (V-09).
  - Done when: a PE header check shows NX-compatible on every scoped image; exceptions are listed; boot and run tests pass.
  - Deps: BLD-012.

- [ ] **SEC-008** · P1 · PORT · M — ASLR (`/DYNAMICBASE`): absent (V-09). Requires relocations and `/FIXED:NO`.
  - Done when: scoped images are relocatable; kernel and driver images are tested (kernel relocation is a separate item if needed); a test shows image bases vary across boots.
  - Deps: SEC-007, BLD-012.

- [ ] **SEC-009** · P1 · PORT · S — SafeSEH (`/SAFESEH`) for x86 user-mode images. Absent (V-09).
  - Done when: every x86 user-mode image has a verified SEH table; a corrupted-handler test fails.
  - Deps: BLD-012.

- [ ] **SEC-010** · P1 · ARCH · XL — Control-flow Guard (`/guard:cf`). Requires CFG-aware loader, `ntdll`, and kernel support (bitmaps).
  - Done when: a CFG-enabled `ntdll` and a sample application run; invalid indirect calls are caught in a test.
  - Deps: BLD-012, SEC-008.

- [ ] **SEC-011** · P1 · PORT · L — NX for 32-bit PAE (V-10). Implement XD/NX on PAE PTEs and enforce non-executable data pages (heap, stack, pool). Note: NX on PAE requires CPU support and the EFER-style enable bit.
  - Done when: a test that executes from a data page faults on PAE x86 with NX enabled; the exceptions list is recorded; the PAE kernel boots on a CPU with NX.
  - Deps: BLD-006.

- [ ] **SEC-012** · P1 · PORT · M — Kernel pool execution policy: pools that are not meant to hold code are non-executable on x86 PAE and AMD64.
  - Done when: a pool-allocation test confirms non-executable pools (via Driver Verifier counters or an equivalent check).
  - Deps: SEC-011.

- [ ] **SEC-013** · P2 · PORT · L — SMEP/SMAP for kernel protection on supporting CPUs. Feasibility study first.
  - Done when: study recorded; if feasible, the kernel refuses user-mode execution at ring 0 on a supporting CPU in a test.
  - Deps: SEC-011.

- [ ] **SEC-014** · P1 · PORT · L — Unsafe-API cleanup in network-reachable components first: SMB server, DHCP, WinHTTP/WinINet, RRAS PPP, TCP/IP, SMSS, and the Winsock/RPC layers. Priority order follows TST-009 results.
  - Done when: each listed component has zero unbounded copies in its network parsing paths (checked by TST-007 and review).
  - Deps: TST-007, TST-009.

- [ ] **SEC-015** · P0 · BP · S · QW — Fix A09 in the UL test client `snd.c`: unbounded `gets()` into `pBuffer[CMD_BUFFER_SIZE=2048]`; `ulSize` from `atoi()` is unchecked before the write loop. It is a test tool, but it is a copy-paste source.
  - Done when: input is read with a bound; the size is validated; the ASan reconstruction (TST-003) is clean on the fixed code; the reconstruction limits are recorded (it is not the original binary).
  - Deps: TST-003.

- [ ] **SEC-016** · P1 · BP · S — A12 is fixed in source. Verify the fix with TST-004 and record the evidence.
  - Done when: TST-004 passes for A12 and the item is closed.
  - Deps: TST-004.

- [ ] **SEC-017** · P0 · BP · S · QW — Disable legacy network protocols by default on fresh installs: NetBEUI (`net/netbeui`), NWLink/IPX (`net/nwlink`), DLC (`net/dlc`), SFM (`net/sfm`), IrDA (`net/irda`). Keep them installable as optional components.
  - Done when: a fresh install lists no legacy protocol bindings; each remains installable and documented. NetBIOS/NetBT stays enabled only if name resolution requires it (decide by test).
  - Deps: none.

- [ ] **SEC-018** · P1 · BP · S — Default listener inventory: services and ports on a fresh install (Telnet, FTP, Messenger, Alerter, RPC endpoints, and others). Reduce to an allowlist.
  - Done when: a port scan (TST-013) of a fresh install matches the documented allowlist.
  - Deps: SEC-017.

- [ ] **SEC-019** · P1 · BP · M — Default ACL audit for `%SystemRoot%`, `HKLM` keys, and services: no world-writable system locations.
  - Done when: an `icacls`-based audit reports zero world-writable system paths on a fresh install.
  - Deps: BLD-006.

- [ ] **SEC-020** · P1 · BP · M — Token and privilege review in `base/ntos/se`: impersonation and subject-context paths; negative tests for a standard user.
  - Done when: a standard-user negative suite passes on the reference host.
  - Deps: TST-005.

- [ ] **SEC-021** · P1 · BP · M — Least privilege for network-exposed services that run as LocalSystem (IIS/HTTP.sys, RRAS, Terminal Services, SMB).
  - Done when: each exposed service's privilege is documented and reduced where the test passes.
  - Deps: SEC-018.

- [ ] **SEC-022** · P1 · PORT · M — Driver load policy: unsigned drivers are refused by default on AMD64; test signing requires an explicit boot flag and a reboot.
  - Done when: an unsigned driver fails to load by default in a test; the flag path works.
  - Deps: DRV-001, BOOT-001.

- [ ] **SEC-023** · P1 · BP · S — Kernel debugging off by default in production images; `kdcom` and `kd1394` enabled only when requested.
  - Done when: a default boot configuration has debugging disabled; a test enables it explicitly.
  - Deps: none.

- [!] **SEC-024** · P2 · ARCH · XL — Kernel patch protection (PatchGuard-equivalent). No code exists (V-13). Design study required, and it has its own threat model.
  - Done when: the design study is recorded. Until then, the plan does not claim kernel integrity protection.

- [!] **SEC-025** · P2 · ARCH · XL — TPM-backed measured boot and BitLocker-with-TPM. No TPM stack (4.4).
  - Done when: unblock requires a TPM stack decision (DEC-02). Software volume encryption is a separate item (FS-015).

- [!] **SEC-026** · P2 · ARCH · XL — VBS, HVCI, and Credential Guard. Requires a hypervisor not in this tree (4.4).
  - Done when: unblock requires a hypervisor decision.

- [ ] **SEC-027** · P1 · BP · S — Signatures: block MD5-RSA for new signatures; treat SHA-1 signatures as policy-controlled. SHA-2 signing depends on CRY-002.
  - Done when: the signing tool refuses MD5-RSA; verification rejects MD5-signed binaries unless a legacy policy is set.
  - Deps: CRY-002.

- [ ] **SEC-028** · P1 · BP · M — Network-facing RPC and HTTP endpoints: inventory and review (RPC over HTTP in `com/rpc/runtime/trans/common/`; HTTP.sys in `inetsrv/iis/iisrearc/ul`).
  - Done when: each endpoint has an owner, a default state, and a fuzz harness (TST-009).
  - Deps: TST-009.

- [ ] **SEC-029** · P0 · PORT · M — Known-vulnerability triage: map public advisories to the exact code in this tree (not by product name), and record applicability.
  - Done when: each advisory has a status (fixed, mitigated, or not applicable), with evidence; the backlog is in `docs/security/advisories.md`.
  - Deps: GOV-007.

- [ ] **SEC-030** · P0 · process — Security servicing policy: no vendor patches exist (4.1), so every applicable fix is in-house. Define severity, response time, and a release-blocking rule.
  - Done when: `SECURITY.md` (GOV-007) contains the policy.
  - Deps: GOV-007.

- [ ] **SEC-031** · P2 · BP · S — Remove or hide debug surfaces and development-only tools from shipped images (e.g., `sdktools` tools that should not ship).
  - Done when: the shipped image list is reviewed and recorded.
  - Deps: DIST-001.

### 6.7 CRY — Cryptography and TLS

- [ ] **CRY-001** · P0 · BP · S — Algorithm matrix: for each algorithm (SHA-1, SHA-2, MD5, MD4, RC4, DES/3DES, RC2, AES, AES-GCM, ECDHE, X25519, ChaCha20-Poly1305, HKDF, RSA sizes, DSA), record present or absent, where, and default state.
  - Evidence: V-18, V-38, N-02.
  - Done when: `docs/crypto/matrix.md` exists and every row cites a path or a test.
  - Deps: none.

- [ ] **CRY-002** · P1 · PORT · M — SHA-2 family (SHA-256, SHA-384, SHA-512) per FIPS 180-4 [11](https://csrc.nist.gov/publications/detail/fips/180/4/final). Implement in the CSP and expose through CryptoAPI ALG_IDs; add known-answer tests.
  - Done when: NIST known-answer vectors pass; `CryptHashData` works with the new ALG_IDs; a SHA-256-signed certificate chain validates.
  - Deps: CRY-001.

- [ ] **CRY-003** · P1 · PORT · L — AEAD: AES-GCM (NIST SP 800-38D [12](https://csrc.nist.gov/pubs/sp/800/38/d/final)) and ChaCha20-Poly1305 (RFC 8439 [13](https://www.rfc-editor.org/info/rfc8439)).
  - Done when: known-answer and cross-implementation vectors pass (for example, against OpenSSL 3.x); tag-mismatch tests reject tampered records.
  - Deps: CRY-002.

- [ ] **CRY-004** · P1 · PORT · L — ECDHE with P-256 (RFC 8422 [14](https://www.rfc-editor.org/info/rfc8422)) and X25519 (RFC 7748 [15](https://www.rfc-editor.org/info/rfc7748)). Constant-time implementation.
  - Done when: ECDH vectors pass; interop with a modern TLS client succeeds; a timing-check script is part of TST-013.
  - Deps: CRY-002.

- [ ] **CRY-005** · P1 · PORT · M — HKDF (RFC 5869 [16](https://www.rfc-editor.org/info/rfc5869)), HMAC-SHA2, and the TLS 1.2 PRF (RFC 5246 [17](https://www.rfc-editor.org/info/rfc5246)).
  - Done when: vectors pass; TLS 1.2 key derivation matches a reference implementation.
  - Deps: CRY-002.

- [ ] **CRY-006** · P1 · ARCH · XL — TLS 1.2 in Schannel. The tree has no TLS 1.1/1.2 identifiers (V-19). Decide: extend Schannel's SPBase state machine, or bridge to a maintained, license-compatible TLS library.
  - Done when: TLS 1.2 handshakes with ECDHE-GCM suites interoperate with OpenSSL, curl, and Go clients; negative tests cover downgrade, bad MAC, and renegotiation; WinINet and WinHTTP can use it by default.
  - Deps: CRY-003, CRY-004, CRY-005, SEC-002.

- [ ] **CRY-007** · P2 · ARCH · XL — TLS 1.3 (RFC 8446 [18](https://www.rfc-editor.org/info/rfc8446)). 0-RTT disabled by default.
  - Done when: TLS 1.3 interop passes; 0-RTT is off in the default policy.
  - Deps: CRY-006.

- [ ] **CRY-008** · P1 · PORT · L — Certificate validation: chain building, name constraints, extended key usage, key usage, validity times, RFC 6125 host matching [19](https://www.rfc-editor.org/info/rfc6125), revocation (CRL per RFC 5280, OCSP per RFC 6960). SHA-1 and MD5 signatures rejected for new chains by policy.
  - Done when: a fixture suite passes (valid, expired, revoked, wrong name, untrusted root, MD5 and SHA-1 signature cases); the code path is in `ds/security/cryptoapi/pkitrust`.
  - Deps: CRY-002, SEC-027.

- [ ] **CRY-009** · P1 · BP · M — Root store refresh: audit the shipped root files (V-39, 167 `.cer`, 24 `.crt`, 23 `.der`, 8 `.sst`). Remove distrusted roots; add current roots only from an approved, licensed source with a date.
  - Done when: the root-store snapshot is dated and recorded; a chain under a removed root fails in a test.
  - Deps: GOV-001, GOV-003.

- [ ] **CRY-010** · P1 · BP · S · QW — Default RSA key size: the certificate wizard defaults to 1024 bits (`ds/security/cryptoapi/ui/wizards/wizards.cpp:922`). Default to 2048 and reject 512-bit keys for new keys.
  - Done when: a new key generated by the default flow is 2048 bits; a 512-bit key request is rejected in a test.
  - Deps: none.

- [ ] **CRY-011** · P1 · PORT · M — Random-number API: provide a `BCryptGenRandom`-style interface backed by an approved DRBG (NIST SP 800-90A [20](https://csrc.nist.gov/pubs/sp/800/90/a/r1/final)). `bcrypt.h` is absent (V-22).
  - Done when: DRBG known-answer and health tests pass; no call path uses a predictable seed; the API is exported in the SDK headers.
  - Deps: CRY-001.

- [ ] **CRY-012** · P1 · BP · S — Legacy algorithms policy: MD4 stays for NTLM compatibility; MD5, RC2, DES, and RC4 are restricted to legacy contexts; new code paths may not use them.
  - Done when: an allowlist exists; `git grep` in new code finds none outside it.
  - Deps: CRY-001.

- [ ] **CRY-013** · P2 · BP · S — Kerberos default encryption type: RC4-HMAC is used on at least one client path (V-36). Move to AES (AUT-001).
  - Done when: see AUT-001.
  - Deps: AUT-001.

- [!] **CRY-014** · P2 — FIPS 140 validation requires an accredited lab. Not in scope.
  - Done when: unblock requires a funded validation; until then, the plan claims no FIPS status.

- [ ] **CRY-015** · P1 · BP · S — Crypto dependency watch: list every vendored crypto implementation (SUP-001) with its version and a CVE watch.
  - Done when: the list is in the SBOM and reviewed each release.
  - Deps: SUP-001.

### 6.8 AUT — Authentication and identity

- [ ] **AUT-001** · P1 · PORT · L — Kerberos AES: AES-128/256 CTS-HMAC-SHA1-96 etypes (RFC 3962 [21](https://www.rfc-editor.org/info/rfc3962)) in client, KDC interaction, and server paths. RC4-HMAC is used by `ds/security/protocols/kerberos/client2/credman.cxx` (lines 280, 292) and no AES etype identifiers were found (V-36).
  - Done when: domain logon and service-ticket exchange negotiate AES-256 against a modern KDC (MIT Kerberos or a current Windows Server; test both).
  - Deps: CRY-001, CRY-005.

- [ ] **AUT-002** · P2 · PORT · L — Kerberos PAC and ticket compatibility with modern domain controllers.
  - Done when: a test domain with current DCs issues tickets this client accepts; the compatibility matrix is recorded.
  - Deps: AUT-001.

- [ ] **AUT-003** · P1 · BP · S — NTLM hardening: NTLMv2 default (SEC-005), NTLM auditing, and LM-hash storage. No `NoLMHash` identifier was found (V-37), so the LM-hash policy must be verified before any claim.
  - Done when: a new account's stored credentials do not include an LM hash, verified in a test environment (no real credentials used).
  - Deps: SEC-005.

- [ ] **AUT-004** · P1 · BP · S — Password policy and lockout in the logon path (`ds/security/gina`, `ds/security/gina/snapins/fde`); Secure Attention Sequence (Ctrl+Alt+Del).
  - Done when: lockout after N failures and SAS behavior are tested.
  - Deps: none.

- [ ] **AUT-005** · P2 · PORT · L — CredSSP and Network Level Authentication for RDP (V-35). Requires SPNEGO, NTLM/Kerberos, and TLS (CRY-006).
  - Done when: NLA-enabled RDP connects between this client and server in a test; without CRY-006, it stays `[!]`.
  - Deps: CRY-006, AUT-001.

- [!] **AUT-006** · P2 — Modern credentials (WebAuthn/FIDO2, OAuth-based sign-in). Requires TLS 1.2+ and a modern browser or host stack (4.4).
  - Done when: unblock requires CRY-006 and a decision on the browser path (APP-002).

- [ ] **AUT-007** · P1 · BP · M — DPAPI key size and rotation: `ds/security/cryptoapi/secstor/dpapisvc` uses 1024-bit defaults in `keysrv.cpp` (lines 1663, 1732, 1764). Raise to 2048 and add master-key rotation.
  - Done when: new master keys are 2048 bits; rotation runs in a test.
  - Deps: CRY-010.

### 6.9 KRN — Kernel and executive

- [ ] **KRN-001** · P1 · ARCH · L — Processor scale: x86 is capped at 32 (V-11); AMD64 has no processor-group APIs (V-12, N-09). Decide the target scale. For x86, 32 is probably sufficient; document it. For AMD64 above 64 logical processors, implement processor groups.
  - Done when: the limit is documented; a 32-CPU VM runs the stress suite (TST-010); for groups, a 128-logical-CPU test runs (if in scope).
  - Deps: DEC-03, BLD-006.

- [ ] **KRN-002** · P1 · PORT · L — x2APIC support (V-13). Needed for APIC IDs above 255 and on modern platforms. Detect via CPUID leaf 1 ECX bit 21; use MSR mode; route interrupts through the HAL.
  - Done when: a VM with x2APIC enabled (QEMU `-cpu host,x2apic=on` or equivalent) boots, routes interrupts, and passes the stress suite.
  - Deps: BLD-006.

- [ ] **KRN-003** · P1 · PORT · M — HPET (ACPI `HPET` table) as a high-resolution timer source. No HPET references in HAL or kernel source (V-13).
  - Done when: HPET is detected and used; `KeQueryPerformanceCounter` is monotonic over 24 hours; drift is recorded.
  - Deps: BOOT-010.

- [ ] **KRN-004** · P1 · PORT · S — Invariant TSC use for the performance counter where CPUID reports it.
  - Done when: the choice is logged at boot; a 24-hour monotonicity test passes.
  - Deps: KRN-003.

- [ ] **KRN-005** · P1 · PORT · M — Kernel debugging: serial (`kdcom`) and 1394 (`kd1394`) present (V-15). Verify both on a VM. KDNET over a network device depends on NDIS 6 (NET-001) and is `[!]` until then.
  - Done when: KD over serial works in a VM from the reference debugger host.
  - Deps: BLD-006.

- [ ] **KRN-006** · P1 · BP · M — Crash dumps: `crashdmp.c` and `triage.c` present. Test full and kernel dumps on VMs with 4 GB+ RAM.
  - Done when: dumps load and analyze with the tree's debugger tools; PERF-NTOS-001 (N-06) is tested.
  - Deps: BLD-006.

- [ ] **KRN-007** · P1 · BP · S — MP and UP kernel variants compile and run on 1, 2, and 4 CPUs.
  - Done when: boot and stress pass on each.
  - Deps: BLD-006.

- [ ] **KRN-008** · P2 · ARCH · L — Kernel ASLR (KASLR). No KASLR references were found (V-13).
  - Done when: the design is recorded; implementation depends on SEC-008 and the boot loader (BOOT-001).
  - Deps: SEC-008, BOOT-001.

- [ ] **KRN-009** · P1 · PORT · M — Modern kernel APIs used by Vista+ drivers (e.g., processor-number and active-processor APIs, process and thread notification extensions). Absent per V-12 and V-20.
  - Done when: an API-gap list is recorded and a shim or implementation is chosen for each in the API set (API-003).
  - Deps: API-002.

- [ ] **KRN-010** · P1 · BP · S — Remove or quarantine IA-64 kernel code paths from `base/ntos` in the default build (see BLD-013).
  - Done when: default build excludes them.
  - Deps: BLD-013.

### 6.10 BOOT — Boot, firmware, and ACPI

- [ ] **BOOT-001** · P0 · ARCH · XL — x64 UEFI boot loader. No amd64 EFI loader directory found (V-54).
  - Done when: a loader boots under OVMF (QEMU) on AMD64 and reaches kernel entry; the test is in TST-011's HCL for firmware.
  - Deps: DEC-03, BLD-012.

- [ ] **BOOT-002** · P0 · PORT · L — GPT in the boot path. `drivers/storage/partmgr/partmgr.c` handles GPT (V-24), but the loader's disk access and ESP discovery are unverified.
  - Done when: a GPT disk with an ESP and an NTFS system partition boots; the test is repeated after a backup-GPT corruption.
  - Deps: BOOT-001.

- [ ] **BOOT-003** · P1 · PORT · M — ACPI `_OSC` negotiation (capabilities, native PCIe features). `_OSC` = 0 in `base/busdrv/acpi` and `base/hals` (V-13).
  - Done when: firmware receives OS capabilities; native PCIe hotplug or AER runs on a test machine.
  - Deps: PNP-003.

- [ ] **BOOT-004** · P1 · BP · S · QW — `_OS` identity (A06). `amlisupp.c` sets `gpszOSName` to `"NEONT"` or `"Microsoft Windows NT"` from `NEONT_BRANDING` (lines 26–34). Firmware and AML code may branch on the `_OS` string. Keep the firmware-compatible value; keep "NEONT" for display only.
  - Done when: `_OS` returns the compatibility string in a test; a DSDT fixture still loads without AML errors.
  - Deps: BLD-003.

- [ ] **BOOT-005** · P1 · BP · S · QW — `OS` environment variable (A05). It is set to `NEONT` by default, which breaks batch files that test for `Windows_NT`. Set `OS=Windows_NT`; keep the display name in a separate variable. The change is in `base/subsys/sm/server/sminit.c` ~L1565–1574 (the `OS` value; keep `Branding` as the display name).
  - Done when: the count of batch files that test `%OS%`, measured by search, all pass in a test run; `echo %OS%` returns `Windows_NT`.
  - Deps: BLD-003.

- [!] **BOOT-006** · P2 · ARCH · XL — Secure Boot. No references (V-13). Requires a signed loader chain, key enrollment, and a revocation list.
  - Done when: unblock requires a key-ownership decision (GOV-003, DEC-02). Then: a verified boot chain in OVMF with Secure Boot on.

- [ ] **BOOT-007** · P1 · PORT · M — Boot menu and recovery: last-known-good, safe mode, recovery console. `base/boot/oschoice` is present (V-54).
  - Done when: fault injection (corrupt boot configuration, missing boot-start driver) reaches the recovery menu in a test.
  - Deps: BOOT-001 (UEFI), BLD-006.

- [ ] **BOOT-008** · P2 · BP · S — PXE boot: `base/boot/startrom` and `base/boot/tftplib` present (V-54).
  - Done when: a PXE boot to the installer works in a test network.
  - Deps: BLD-006.

- [ ] **BOOT-009** · P2 · BP · S — Legacy BIOS path: keep for legacy VMs; UEFI is primary (DEC-03).
  - Done when: the dual-path policy is documented.
  - Deps: DEC-03.

- [ ] **BOOT-010** · P1 · BP · M — ACPI table robustness: `base/hals/acpidtct.c` is present; test with tables from QEMU and OVMF, and with malformed tables.
  - Done when: well-formed tables load; malformed tables are rejected without a bugcheck.
  - Deps: BLD-006.

- [ ] **BOOT-011** · P1 · PORT · M — AML interpreter coverage for ACPI 3.0+ opcodes. Verify against `iasl`-compiled fixtures; this is unverified (**verify**).
  - Done when: a fixture set from modern DSDTs loads without AML errors; unsupported opcodes are logged and listed.
  - Deps: BOOT-010.

### 6.11 MEM — Memory manager

- [ ] **MEM-001** · P1 · PORT · M — PAE large-memory validation: `base/ntos/mm/pae` present. Test with 8 GB and 16 GB VMs (PAE for x86; AMD64 for more). Test `/3GB` boot option behavior.
  - Done when: all memory is usable in a test with no leak growth; `/3GB` is documented.
  - Deps: BLD-006.

- [ ] **MEM-002** · P1 · BP · M — Pool and handle leak tracking in soak tests (`!poolused` before and after).
  - Done when: leak budgets (section 7.3) are met in the 72-hour soak.
  - Deps: REL-001.

- [ ] **MEM-003** · P1 · BP · S — PERF-NTOS-001 (N-06): `TriageHasLoaderChecksum` is present (`base/ntos/io/iomgr/triage.c:484`), declared (`base/ntos/mm/triage.c:127`), and called (`base/ntos/mm/triage.c:298`). Code presence is verified; the behavior with malformed dumps is not.
  - Done when: malformed dump input is rejected without a bugcheck in a test. Then close as `[x]`.
  - Deps: KRN-006.

- [ ] **MEM-004** · P1 · BP · S — Zero-page thread and page zeroing correctness: stress test (the performance audit reviewed `base/ntos/mm/zeropage.c` and found no defect; keep a test).
  - Done when: a 24-hour stress test finds no zeroing error.
  - Deps: BLD-006.

- [ ] **MEM-005** · P1 · PORT · M — User-mode heap corruption detection in test builds: enable Application Verifier heap checks (`sdktools/appverif` present, verify).
  - Done when: a deliberate heap overflow is caught in a test build.
  - Deps: BLD-006.

- [ ] **MEM-006** · P3 · ARCH · L — Memory compression and working-set tuning. Not started; low priority.
  - Done when: design recorded.

### 6.12 PWR — Power management

- [ ] **PWR-001** · P1 · BP · M — Sleep and hibernate (`base/ntos/po`: hibernate, suspend, idle). Test S3, S4, and S5 on VMs and on supported laptops.
  - Done when: 100 suspend/resume cycles and 100 hibernate/resume cycles complete with no failure on the HCL machines.
  - Deps: TST-011.

- [ ] **PWR-002** · P1 · PORT · M — Processor performance states: verify P-state and idle behavior on modern CPUs (Intel and AMD MSRs). Currently unverified (**verify**).
  - Done when: frequency scales with load and idles down on a test CPU, measured.
  - Deps: KRN-002 (for APIC changes), BLD-006.

- [ ] **PWR-003** · P1 · BP · S — Battery and thermal: ACPI battery drivers `base/busdrv/acpi/battc` and `cmbatt` present (V-53).
  - Done when: charge and remaining-time values are correct on a laptop test.
  - Deps: TST-011.

- [ ] **PWR-004** · P1 · PORT · M — USB selective suspend and hub power management.
  - Done when: an idle USB hub suspends and wakes on device activity in a test.
  - Deps: USB-001.

- [!] **PWR-005** · P2 — Modern Standby (S0ix-style connected standby). Requires firmware and driver model changes not in tree.
  - Done when: unblock requires a design decision; not in the daily-driver baseline.

### 6.13 PNP — Plug and Play and buses

- [ ] **PNP-001** · P1 · BP · M — PnP map: `base/pnp`, `base/ntos/io/pnpmgr`, `base/busdrv/pci`, `base/busdrv/acpi`, `base/ntsetup`, setup API. Produce a dependency diagram.
  - Done when: the diagram is committed under `docs/`.
  - Deps: none.

- [ ] **PNP-002** · P1 · PORT · M — MSI-X (V-14: found in only 2 files). Implement or verify the MSI-X table mapping and vector allocation for devices that need it (NICs, xHCI, NVMe).
  - Done when: a device exposing MSI-X gets its vectors routed in a test; the verification steps are recorded.
  - Deps: KRN-002.

- [ ] **PNP-003** · P1 · PORT · M — PCIe AER and native hotplug: verify in PCI drivers.
  - Done when: hot-add and hot-remove of a PCIe device work on a QEMU root port in a test.
  - Deps: PNP-002.

- [!] **PNP-004** · P2 — CPU and memory hot-add on x86. Not in scope.

- [ ] **PNP-005** · P1 · BP · S — Enumeration performance: measure device enumeration time at boot and on hot-add.
  - Done when: enumeration times are recorded in the PERF baseline (section 7.3).
  - Deps: PERF-001.

- [ ] **PNP-006** · P2 · BP · M — Resource rebalancing for 64-bit BARs (AMD64 and PAE).
  - Done when: a device with a 64-bit BAR is assigned correctly in a test.
  - Deps: BLD-006.

- [ ] **PNP-007** · P1 · PORT · M — ACPI namespace compatibility with modern DSDTs: see BOOT-011.
  - Done when: see BOOT-011.
  - Deps: BOOT-011.

### 6.14 USB — USB host controllers and devices

- [ ] **USB-001** · P1 · BP · M — EHCI, OHCI, and UHCI miniports (V-25): validate with keyboard, mouse, and mass storage on each controller type in a VM and on real hardware.
  - Done when: 100 plug and unplug cycles per device class pass with no bugcheck.
  - Deps: BLD-006.

- [ ] **USB-002** · P1 · ARCH · XL — xHCI host controller (USB 3.x). Absent (V-24). Needs a miniport against the xHCI specification, with ring management, MSI or MSI-X, and power states.
  - Done when: the miniport loads on QEMU's `qemu-xhci` and on one real controller; HID and mass storage pass 100 cycles.
  - Deps: PNP-002, KRN-002.

- [ ] **USB-003** · P1 · BP · M — USB descriptor robustness: fuzz malformed descriptors (TST-009).
  - Done when: 24 CPU-hours of fuzzing without crash or leak.
  - Deps: TST-009.

- [ ] **USB-004** · P2 · ARCH · L — UASP (USB Attached SCSI) for fast external storage. Requires USB-002.
  - Done when: UASP enclosure works; fallback to BOT is tested.
  - Deps: USB-002.

- [ ] **USB-005** · P1 · BP · S — USB HID: keyboards, mice, and gamepads. The HID stack has many paths; coverage is unverified (**verify**).
  - Done when: a keyboard, a mouse, and one gamepad work on each supported controller.
  - Deps: USB-001.

- [ ] **USB-006** · P2 · PORT · M — USB video class (UVC) webcams via `drivers/wdm/capture/mini/usbcamd` (present; check dependencies).
  - Done when: one UVC webcam streams in a capture application test.
  - Deps: USB-001.

- [!] **USB-007** · P2 — Thunderbolt and USB4. Needs xHCI and vendor firmware.
  - Done when: unblock requires USB-002 and vendor specs.

### 6.15 STO — Storage

- [ ] **STO-001** · P1 · PORT · L — AHCI (SATA) miniport on Storport (`storport.h` present, V-24). Absent today: SATA runs through the IDE/ATAPI path only.
  - Evidence: `drivers/storage/ide` (IDE and ATAPI); V-24.
  - Done when: an AHCI disk installs and boots in QEMU (`ich9-ahci`) and on one physical controller; 1-hour mixed fio workload with zero I/O errors.
  - Deps: BLD-006.

- [ ] **STO-002** · P1 · ARCH · XL — NVMe miniport on Storport against the NVM Express base specification. Absent (V-24).
  - Done when: an NVMe SSD boots; surprise-removal and flush and FUA behavior pass tests.
  - Deps: STO-001, PNP-002.

- [ ] **STO-003** · P1 · BP · M — Storport validation: miniport ABI and timeouts (`drivers/storage/port`).
  - Done when: IRP stress and timeout tests pass.
  - Deps: BLD-006.

- [ ] **STO-004** · P1 · BP · S — 4Kn (4096-byte logical sectors): verify the class driver (`drivers/storage/classpnp/`).
  - Done when: a 4Kn disk partitions and formats NTFS correctly in a test.
  - Deps: BLD-006.

- [ ] **STO-005** · P1 · BP · M — GPT validation: disks above 2 TB, protective MBR, backup header repair.
  - Done when: a disk with a corrupted backup GPT is repaired in a test.
  - Deps: BOOT-002.

- [ ] **STO-006** · P2 · BP · M — iSCSI initiator (`drivers/storage/iscsiprt`): test against a current iSCSI target.
  - Done when: login and a 1-hour I/O test pass.
  - Deps: BLD-006.

- [ ] **STO-007** · P2 · PORT · S — TRIM and UNMAP for SSDs.
  - Done when: TRIM commands are issued and verified on an SSD in a test.
  - Deps: STO-001.

- [ ] **STO-008** · P1 · BP · M — Disk error handling and timeouts: fault injection for one hour.
  - Done when: injected faults produce logged errors and no hang.
  - Deps: TST-010.

- [ ] **STO-009** · P1 · BP · M — Volume shadow copy (`volsnap` present) snapshot and restore on NTFS.
  - Done when: a snapshot and restore cycle passes in a test.
  - Deps: BLD-006.

- [ ] **STO-010** · P2 · BP · M — Dynamic disks and MPIO (`drivers/storage/newft`, `mpath`): mirror and failover tests.
  - Done when: a mirror survives a disk removal in a test.
  - Deps: BLD-006.

- [ ] **STO-011** · P2 · ARCH · L — SD and card-reader host controllers. Not located in tree (**verify**).
  - Done when: unblock requires a verified inventory.

### 6.16 FS — File systems and file access

- [ ] **FS-001** · P0 · PORT · XL — SMB 2.x and 3.x (V-32). The SRV and RDR code is the NT-era SMB1 implementation. Implement SMB 2.0.2 first (open specification [MS-SMB2]), then signing, then 3.x features. Encryption depends on CRY-003.
  - Done when: a current Samba 4.x server and a current client (test both) negotiate SMB 3.1.1 with signing; file copy and locking tests pass; encryption tests pass after CRY-003.
  - Deps: CRY-002, CRY-003 (for encryption).

- [ ] **FS-002** · P0 · BP · S — SMB1 default off on new installs (server and client). Keep it as an opt-in for legacy NT4-era peers.
  - Done when: a fresh install has no SMB1 server listener; the opt-in works; the setting is documented.
  - Deps: FS-001 (for a usable alternative).

- [ ] **FS-003** · P1 · BP · S — SMB signing: require it by policy and test the default.
  - Done when: a signed session is required under the policy; an unsigned client is refused in a test.
  - Deps: FS-002.

- [ ] **FS-004** · P1 · PORT · L — exFAT (V-31: absent). License and patent review required (GOV-008) before any implementation.
  - Done when: after GOV-008 clears, exFAT formats, mounts, reads, and writes SD cards (above 32 GB) and a Linux-formatted exFAT image.
  - Deps: GOV-008.

- [ ] **FS-005** · P1 · BP · M — FAT32 on large volumes and long file names (`base/fs/fastfat`).
  - Done when: a FAT32 volume above 32 GB formats, reads, and writes; long names round-trip; the test set passes.
  - Deps: BLD-006.

- [ ] **FS-006** · P1 · BP · L — NTFS validation: EFS, compression, sparse files, reparse points, quotas, TxF. Fault-injection with chkdsk-equivalent repair.
  - Done when: 1,000 fault-injection runs complete with repairs and no unexpected data loss in controlled tests.
  - Deps: BLD-006, TST-010.

- [ ] **FS-007** · P1 · BP · S — UDF read and write on modern optical and flash media (`base/fs/udfs`). Verify version support.
  - Done when: a UDF 2.5 or 2.6 image mounts and reads in a test.
  - Deps: BLD-006.

- [!] **FS-008** · P3 — ReFS. Not present; not needed for a daily-driver baseline (4.4).

- [ ] **FS-009** · P1 · PORT · M — Long paths: NTFS supports long names (V-31); Win32 path handling is limited to MAX_PATH unless `\\?\` is used. Test the `\\?\` path for file APIs that exist in the tree.
  - Done when: a 32K path test passes for each file API in scope.
  - Deps: API-001.

- [ ] **FS-010** · P2 · PORT · M — Symbolic links: `CreateSymbolicLinkW` is absent from the SDK (V-20); NTFS reparse points exist. Expose the link-creation API and privilege checks.
  - Done when: a `mklink`-equivalent creates file and directory links with the correct privilege checks.
  - Deps: API-002.

- [ ] **FS-011** · P2 · BP · M — DFS and MUP redirector (`base/fs/dfs`, `base/fs/mup`): test with a current DFS namespace.
  - Done when: a DFS path resolves in a test.
  - Deps: FS-001.

- [ ] **FS-012** · P1 · ARCH · XL — Filter Manager and minifilter model (N-08, V-29). Needed for AV, backup, and encryption products. Design: a filter manager in the kernel with a minifilter API, or an equivalent.
  - Done when: a sample minifilter (from `base/fs/fltsamples`) loads, attaches to a volume, and sees file operations; a test confirms the sample's callbacks run.
  - Deps: BLD-006, DEC-02.

- [ ] **FS-013** · P2 · PORT · L — Software volume encryption (not TPM-based) using the existing CryptoAPI and FVE pieces.
  - Done when: a volume encrypts and decrypts with a passphrase in a test, and recovers after a reboot.
  - Deps: CRY-002, CRY-003.

- [ ] **FS-014** · P1 · BP · S — EFS round-trip with certificates generated in tests (no shipped keys, GOV-003).
  - Done when: a file encrypted by one user decrypts after a recovery-key operation in a test.
  - Deps: GOV-003.

### 6.17 NET — Networking

- [ ] **NET-001** · P1 · ARCH · XL — NDIS 6.x miniports. The stack is NDIS 5 (V-23). Modern NIC drivers are NDIS 6. Decide: implement NDIS 6 (large) or limit to NDIS 5 drivers in the lab.
  - Done when: DEC-02 is made; if NDIS 6 is chosen, a NDIS 6 sample miniport loads and passes a send and receive test.
  - Deps: DEC-02.

- [ ] **NET-002** · P1 · BP · M — NIC driver coverage. In-tree: `e100bex` (Intel 82557-class) and `ne2000` (V-28). No gigabit or Realtek drivers.
  - Done when: `e100bex` passes a 1-hour send and receive test on the QEMU `e100` device; a coverage plan for other NICs is written (open-source driver licensing, GOV-008, must be reviewed).
  - Deps: BLD-006, GOV-001.

- [ ] **NET-003** · P1 · BP · M — IPv6 conformance: NDP, addressing, dual-stack HTTP.
  - Done when: an IPv6 conformance tool (e.g., THC-IPv6 or a published test suite) passes the agreed tests, and a dual-stack HTTP request succeeds.
  - Deps: BLD-006.

- [ ] **NET-004** · P1 · BP · M — TCP options: window scaling, SACK, timestamps (present, V-33). Measure LAN throughput with iperf3 against a modern Linux host.
  - Done when: throughput is recorded against the same hardware baseline (section 7.3).
  - Deps: PERF-001.

- [ ] **NET-005** · P2 · PORT · M — Congestion control: CUBIC (or a documented alternative) as an option; no CUBIC present (V-33).
  - Done when: a CUBIC option passes interop tests and a benchmark.
  - Deps: NET-004.

- [ ] **NET-006** · P2 · PORT · M — TCP Fast Open (RFC 7413). Absent; optional.
  - Done when: TFO works between this host and a Linux peer in a test.
  - Deps: NET-004.

- [ ] **NET-007** · P1 · PORT · M — SYN cookies and SYN-flood defense (absent, V-33).
  - Done when: a SYN-flood test does not exhaust the backlog and legitimate connections continue.
  - Deps: NET-004.

- [ ] **NET-008** · P1 · BP · M — DNS client and resolver. The client library location is not identified by path (**verify**; `admin/cys/wrappers/dns` is a wizard, not the resolver).
  - Done when: the resolver code path is mapped; resolution and TTL behavior tests pass.
  - Deps: NET-003.

- [ ] **NET-009** · P1 · BP · M — DHCP client and server (`net/dhcp` present). Test lease, renewal, and rebind against ISC dhcpd.
  - Done when: lease, renewal, and rebind pass in a test; DHCPv6 is listed under NET-010.
  - Deps: BLD-006.

- [ ] **NET-010** · P2 · PORT · M — DHCPv6 and SLAAC. Verify support (**verify**).
  - Done when: DHCPv6 leases in a test on a dual-stack network.
  - Deps: NET-003, NET-009.

- [!] **NET-011** · P1 · ARCH · XL — Wi-Fi: no 802.11 MAC or WLAN stack (V-34). WPA2 and WPA3 need the stack (NET-012).
  - Done when: unblock requires an NDIS 6 wireless design (NET-001) and a WLAN stack decision.

- [!] **NET-012** · P1 · PORT · L — WPA2-PSK (CCMP, 802.11i) on top of NET-011. Blocked until NET-011 is designed.
  - Done when: a WPA2-PSK association with a standard access point works.

- [ ] **NET-013** · P1 · BP · M — 802.1X and EAPOL (wired): present (V-34). Test EAP-MSCHAPv2 now; EAP-TLS after CRY-006.
  - Done when: EAP-MSCHAPv2 passes against a RADIUS server (FreeRADIUS, test host); EAP-TLS passes after CRY-006.
  - Deps: CRY-006 (for EAP-TLS).

- [ ] **NET-014** · P1 · BP · S — PPP and CHAP (RRAS). A12 is fixed in source (A12, section 3). Test CHAP and MS-CHAPv2, and make MS-CHAPv1 non-default.
  - Done when: the default configuration negotiates MS-CHAPv2 only, verified with a PPP peer.
  - Deps: TST-004.

- [ ] **NET-015** · P2 · PORT · L — IKEv2 (RFC 7296 RFC 7296 (https://www.rfc-editor.org/info/rfc7296)). Absent (V-33).
  - Done when: an IKEv2 tunnel forms with a standard peer (strongSwan) in a test.
  - Deps: CRY-002, CRY-004.

- [ ] **NET-016** · P0 · BP · S — Legacy protocol defaults. Duplicates SEC-017 for tracking.
  - Done when: see SEC-017.
  - Deps: SEC-017.

- [!] **NET-017** · P3 — QUIC and HTTP/3. No QUIC identifiers (V-42 notes). Requires TLS 1.3 (CRY-007).
  - Done when: unblock requires CRY-007.

- [ ] **NET-018** · P1 · PORT · L — HTTP/2 in WinHTTP and WinINet (absent, V-43). Requires TLS 1.2 and ALPN.
  - Done when: an HTTP/2 request to a modern server succeeds in a test.
  - Deps: CRY-006.

- [ ] **NET-019** · P1 · BP · M — Winsock: `getaddrinfo`, `AI_*` flags, and `WSAIoctl` behavior with IPv6.
  - Done when: a `ws2tcpip` API test suite passes.
  - Deps: NET-003.

- [ ] **NET-020** · P2 · PORT · M — Socket and IP Helper APIs from later Windows versions (e.g., `netioapi.h` is absent, V-22). Track as API gaps in API-002.
  - Done when: each gap has a shim or an explicit `[!]`.
  - Deps: API-002.

- [ ] **NET-021** · P1 · BP · M — RDP: RDP 5.1 strings present (`termsrv`). Later RDP versions are not in tree. TLS for RDP after CRY-006.
  - Done when: RDP 5.1 connects between this client and server; the feature gap list is recorded.
  - Deps: BLD-006.

- [!] **NET-022** · P1 · ARCH · XL — Bluetooth stack (absent, V-34; `BluetoothAPIs.h` and `ws2bth.h` absent, V-22). Needs a stack and drivers.
  - Done when: unblock requires a stack decision (DEC-02).

- [!] **NET-023** · P2 — DNS over TLS and DNS over HTTPS. Requires TLS 1.2+ (CRY-006).
  - Done when: unblock requires CRY-006.

- [ ] **NET-024** · P2 · BP · M — NAT, Internet Connection Sharing, and the firewall (`net/rras`, and firewall code, **verify location**).
  - Done when: NAT passes traffic between two subnets in a test.
  - Deps: NET-009.

- [ ] **NET-025** · P1 · BP · S — Network diagnostics and status UI (`net/diagnostics` present).
  - Done when: a disconnected cable and a DHCP failure produce correct status in a test.
  - Deps: NET-009.

### 6.18 GFX — Graphics

- [ ] **GFX-001** · P1 · BP · M — VGA and SVGA miniports (`drivers/video/ms`) and Matrox MGA (`drivers/video/matrox/mga`). Test mode set at 1024×768, 1280×1024, and 1920×1080 (VGA-class or VBE modes).
  - Done when: each mode sets and redraws correctly in a QEMU `std`-VGA-class test; the mode list is recorded.
  - Deps: BLD-006.

- [!] **GFX-002** · P1 · ARCH · XL — WDDM display model (absent, V-26). Modern GPU vendor drivers need WDDM. Two options: stay with XDDM for basic display, or design a WDDM stack (multi-year).
  - Done when: DEC-02 decides; XDDM-only is recorded as the baseline with an explicit limit.

- [ ] **GFX-003** · P1 · BP · M — Direct3D 8 (`multimedia/directx/dxg/d3d8`, V-44): software and reference rasterizers. Test with a D3D8 sample and a legacy game test.
  - Done when: a D3D8 sample renders correctly on the software rasterizer; the legacy test list passes.
  - Deps: BLD-006.

- [ ] **GFX-004** · P2 · ARCH · XL — Direct3D 9 (absent, V-44). Options: port a D3D9 implementation (license-reviewed), or layer D3D9 over D3D8 or OpenGL (Mesa is MIT-licensed; verify its terms).
  - Done when: a D3D9 sample runs on the chosen path; the approach is recorded.
  - Deps: GOV-006, GFX-003.

- [!] **GFX-005** · P3 — Direct3D 10, 11, 12 and DXGI (absent, V-22). Requires WDDM (GFX-002).
  - Done when: unblock requires GFX-002.

- [ ] **GFX-006** · P1 · PORT · M — OpenGL: `multimedia/opengl` present. Verify the ICD loader; test OpenGL 1.x and 2.x with a sample.
  - Done when: a 2.1-era OpenGL sample runs on the chosen driver path (software or hardware).
  - Deps: GFX-001.

- [ ] **GFX-007** · P2 · PORT · M — High-DPI and per-monitor DPI scaling. APIs are post-XP (API-001).
  - Done when: the UI renders correctly at 150% and 200% scaling in a test.
  - Deps: API-002.

- [ ] **GFX-008** · P2 · BP · S — Color management: ICM present (`windows/core/ntgdi/icm`).
  - Done when: an ICC profile applies in a test.
  - Deps: BLD-006.

- [ ] **GFX-009** · P1 · BP · M — ClearType and GDI+ (`windows/advcore/gdiplus` present). DirectWrite is absent (`dwrite.h` not in tree, V-22).
  - Done when: ClearType text renders in the shell and in an GDI+ sample.
  - Deps: BLD-006.

- [ ] **GFX-010** · P1 · BP · S — Font redistribution: the TrueType and bitmap fonts in tree must be cleared (GOV-008).
  - Done when: each font has a status in the license register.
  - Deps: GOV-008.

- [!] **GFX-011** · P2 — HDR and wide-gamut display output. Requires WDDM.
  - Done when: unblock requires GFX-002.

- [ ] **GFX-012** · P2 · PORT · L — DXVA-style hardware video decode. Verify the path (**verify**).
  - Done when: unblock requires a decision on the video decode path and codec licensing (MMD-002).
  - Deps: MMD-002, GFX-002.

### 6.19 AUD — Audio

- [ ] **AUD-001** · P1 · BP · M — PortCls and WDMAUD/KS audio stack (V-27). Test with an emulated AC'97 or HD Audio device in QEMU (use the device the in-tree driver supports; **verify**).
  - Done when: playback and capture pass; one hour of streaming has no glitches.
  - Deps: BLD-006.

- [ ] **AUD-002** · P1 · PORT · M — HD Audio controller and codec driver (**verify**: the HDAudio driver was not located by path).
  - Done when: an HD Audio codec enumerates and plays audio in a test.
  - Deps: AUD-001.

- [ ] **AUD-003** · P2 · ARCH · XL — WASAPI and Core Audio (MMDevice). Absent (V-22). Implement MMDevice and WASAPI on top of KS and WDM audio.
  - Done when: a WASAPI shared-mode sample streams audio on the reference host.
  - Deps: AUD-001, GOV-006.

- [ ] **AUD-004** · P2 · BP · S — DirectSound and DirectMusic (`dsound.h` present; `multimedia/directx/dmusic/` present, 644 files). Test with samples.
  - Done when: the DirectSound sample plays and the DirectMusic sample sequences.
  - Deps: AUD-001.

- [!] **AUD-005** · P2 — XAudio2 and XInput (absent, V-22). Needed by modern games; a clean-room XInput could map to DirectInput (see APP-008).
  - Done when: unblock requires a decision on the game target list.

- [ ] **AUD-006** · P2 · PORT · M — USB audio class devices (depends on USB-001).
  - Done when: a USB headset works in a test.
  - Deps: USB-001.

- [!] **AUD-007** · P3 — Bluetooth audio. Requires NET-022.

### 6.20 MMD — Multimedia

- [ ] **MMD-001** · P1 · BP · M — DirectShow playback (`multimedia/dshow`) with licensed test media only (WAV, MP3, AVI, MPEG-2 if licensed).
  - Done when: each licensed test file plays to completion with correct timing.
  - Deps: GOV-008, AUD-001, GFX-001.

- [ ] **MMD-002** · P1 · PORT · M — Codec inventory and licensing (V-45): verify each codec by its real identifiers before claiming support. AAC, MP3, AC-3, MPEG-2, WMV, H.264, Opus, Vorbis.
  - Done when: a codec register exists (GOV-008) with verified entries and a licensing status per codec.
  - Deps: GOV-008.

- [ ] **MMD-003** · P2 · ARCH · XL — Media Foundation (absent, V-44). Needed by modern media apps.
  - Done when: a Media Foundation sample pipeline plays a licensed file, or the item is `[!]` by decision.

- [ ] **MMD-004** · P2 · BP · S — Windows Media Player versions present in tree: verify version and features.
  - Done when: the player's version is recorded and a playback test passes.
  - Deps: MMD-001.

- [!] **MMD-005** · P2 — DVD-Video playback with CSS decryption. Requires a CSS license (4.2).
  - Done when: unblock requires a license decision.

- [ ] **MMD-006** · P2 · ARCH · L — Hardware-accelerated decode and presentation. Depends on GFX-002.
  - Done when: unblock requires GFX-002 and MMD-002.

- [ ] **MMD-007** · P2 · PORT · M — HTTP streaming through WinINet and WinHTTP. Requires TLS 1.2 for HTTPS sources (CRY-006).
  - Done when: an HTTP stream plays in a test; HTTPS after CRY-006.
  - Deps: CRY-006.

### 6.21 API — Win32 and native API compatibility

- [ ] **API-001** · P0 · BP · S — API baseline document (`docs/api/baseline.md`): target API level (XP SP2 / Server 2003 SP1 level), `WINVER 0x0501` (V-21), `_WIN32_WINNT` default in `winresrc.h` (around line 33, **verify**), and the explicit list of post-XP APIs in scope.
  - Done when: the baseline is committed and reviewed; each later API item references it.
  - Deps: none.

- [ ] **API-002** · P1 · PORT · XL — Forwarder and shim DLLs for post-XP APIs, using import-table redirection and an in-tree shim engine (`windows/appcompat/shimengines`, `windows/appcompat/shims`; **verify**). Model: VxKex-NEXT import-table redirection [8](https://github.com/YuZhouRen86/VxKex-NEXT), with per-process DLL loading via IFEO as described in [9](https://github.com/xuzhongxing/VxKex-NEXT). Implement from documented behavior only (GOV-006).
  - Done when: a test program importing `GetTickCount64` runs on the XP-era build through a shim; each shim logs its use; a per-process opt-in is the default.
  - Deps: API-001, GOV-006.

- [ ] **API-003** · P1 · PORT · L — Kernel-side API gaps for Vista+ drivers (KRN-009).
  - Done when: each gap in the list has an implementation or an explicit `[!]`.
  - Deps: KRN-009.

- [ ] **API-004** · P1 · ARCH · XL — API-set or OneCore-style layering (absent, V-22 family). Any use of Microsoft's API-set schema or OneCore binaries needs explicit rights (GOV-001). Otherwise, design an in-house partition with its own names.
  - Done when: GOV-001 approves the approach; the design is recorded.
  - Deps: GOV-001, DEC-02.

- [ ] **API-005** · P1 · PORT · M — C runtime: the tree has `base/crts` (MSVCRT-era). Modern apps need later runtime versions (e.g., VC++ 2005 through 2015 CRTs). Provide shims or runtimes after a license review.
  - Done when: a sample linked against a later CRT runs; the redistribution terms are recorded.
  - Deps: GOV-008, API-002.

- [ ] **API-006** · P2 · BP · S — Use safe-string helpers in all new code (V-51); add a lint rule in TST-001.
  - Done when: the lint rule is active.
  - Deps: TST-001.

- [ ] **API-007** · P1 · BP · M — WOW64 (32-bit on 64-bit, `base/wow64`): validate with a 32-bit test suite on AMD64.
  - Done when: the 32-bit suite passes on AMD64.
  - Deps: BLD-006, DEC-03.

- [ ] **API-008** · P1 · PORT · M — Application-compatibility shim database: extend for known XP-era applications; each entry gets a test.
  - Done when: each DB entry has a test and an owner.
  - Deps: APP-001.

- [ ] **API-009** · P2 · PORT · M — `CancelIoEx` and other Vista-era I/O APIs (absent, V-20): implement on top of IRP cancellation.
  - Done when: `CancelIoEx` cancels a pending I/O in a test.
  - Deps: API-002.

- [ ] **API-010** · P1 · PORT · M — Security APIs for CNG-style access: `ncrypt.h` and `bcrypt.h` absent (V-22). Provide the API over CRY-011 and CRY-002.
  - Done when: the API is exported; known-answer tests pass.
  - Deps: CRY-002, CRY-011.

- [ ] **API-011** · P2 · BP · S — RPC over HTTP naming and behavior: `com/rpc/runtime/trans/common/http2.cxx` is RPC over HTTP v2, not HTTP/2. Keep the name distinct in docs.
  - Done when: docs are corrected; no code change.
  - Deps: none.

### 6.22 APP — Application compatibility and runtimes

- [ ] **APP-001** · P1 · BP · M — XP/Server 2003-era application corpus: at least 50 applications with recorded versions and tests (launch, core workflow, close, 30 minutes idle).
  - Done when: the corpus is in `docs/apps/corpus.md`; the pass gate is in section 7.4.
  - Deps: TST-012.

- [!] **APP-002** · P2 — Modern browsers (Chromium, Firefox). See 4.4. Chrome 109 was the last release for Windows 7 and 8.1 [4](https://www.neowin.net/news/google-chrome-109-now-available-last-version-to-support-windows-7-and-81/). Requires CRY-006, API-002, and GFX-003 at minimum.
  - Done when: unblock requires a funded browser project.

- [!] **APP-003** · P2 — .NET Framework 4.x and modern .NET (netfx absent; `com/dirs` target missing). Requires a licensed source or runtime with an OS floor this line does not meet.
  - Done when: unblock requires a decision.

- [!] **APP-004** · P2 — Java runtimes (`java` target missing from `inetcore/dirs`). Vendor JDKs set their own OS floor.
  - Done when: unblock requires a decision.

- [!] **APP-005** · P2 — PowerShell (modern, absent) and WSH (`wscript`/`cscript` present, VBScript and JScript present, V-06). Modern PowerShell is [!]. WSH is verified present; test it.
  - Done when: WSH sample scripts run in a test; PowerShell is marked `[!]` with the reason.

- [ ] **APP-006** · P1 · BP · M — Developer tooling in tree: debuggers in `sdktools/debuggers`, `ntsd`/`kd` (V-15). Verify each runs on the reference host.
  - Done when: a debugger session on the test VM is recorded.
  - Deps: KRN-005.

- [ ] **APP-007** · P2 · PORT · M — Python, Node.js, Git for Windows: check each upstream release's minimum OS and the APIs it needs. Choose the newest version that runs on this baseline, or mark `[!]`.
  - Done when: a compatibility table records each runtime's test result on the baseline.
  - Deps: API-002.

- [ ] **APP-008** · P2 · PORT · L — Games: DirectX 8, DirectInput (`dinput.h` present; `dinput8.h` absent, V-22). Target a fixed game list.
  - Done when: each listed DirectX 8 game passes its launch and play test.
  - Deps: GFX-003, AUD-004.

- [!] **APP-009** · P2 — Modern games (DirectX 10+). Requires WDDM and D3D10+.
  - Done when: unblock requires GFX-005.

- [ ] **APP-010** · P1 · BP · S — Installers: Windows Installer and setup API behavior. Test common installers (Inno Setup, NSIS, WiX-built MSI) for the baseline.
  - Done when: each installer completes install and uninstall in a test.
  - Deps: BLD-006.

- [!] **APP-011** · P1 — Microsoft Office and other productivity suites that are not in tree. Document; test open-source alternatives that run on the baseline.
  - Done when: a productivity test list with results is recorded.

- [ ] **APP-012** · P2 · PORT · M — Printing (`printscan` present): test local printers, network printers, and print-to-file. Verify whether IPP (RFC 8011) is supported (**verify**).
  - Done when: a print job completes to a local and a network printer in a test.
  - Deps: BLD-006.

- [!] **APP-013** · P3 — Windows 10/11 app model: UWP, AppContainer, WinRT (absent). See 4.4.
  - Done when: unblock requires a funded project.

### 6.23 SHL — Shell and user experience

- [ ] **SHL-001** · P1 · BP · M — Explorer shell smoke test: desktop, taskbar, Start menu, file operations; 24-hour run.
  - Done when: the 24-hour run has zero shell crashes.
  - Deps: BLD-006.

- [ ] **SHL-002** · P1 · PORT · M — UTF-8 console I/O: `chcp 65001` and `WriteConsoleW` correctness.
  - Done when: UTF-8 text round-trips through the console in a test.
  - Deps: I18N-002.

- [ ] **SHL-003** · P2 · PORT · M — High-DPI shell (see GFX-007).
  - Done when: the shell renders at 200% without clipping.
  - Deps: GFX-007.

- [!] **SHL-004** · P3 — Cloud-tied features (cloud search, online accounts, store). Out of scope (4.4).

- [ ] **SHL-005** · P1 · BP · S — Tray notifications and balloon tips.
  - Done when: a balloon notification shows and dismisses in a test.
  - Deps: SHL-001.

- [ ] **SHL-006** · P2 · BP · S — File associations and default applications.
  - Done when: a file opens in its associated program after the association is changed.
  - Deps: SHL-001.

- [ ] **SHL-007** · P2 · BP · S — Control Panel: network, accessibility, date and time, and regional settings.
  - Done when: each panel opens and applies a change in a test.
  - Deps: I18N-001.

### 6.24 A11Y — Accessibility

- [ ] **A11Y-001** · P1 · BP · M — MSAA (`windows/oleacc`, V-46): test with an open-source screen reader that uses MSAA (NVDA is GPL and may be used as an external test tool; verify its terms).
  - Done when: a screen reader reads dialogs, buttons, and menus in the shell and in one legacy application.
  - Deps: SHL-001.

- [ ] **A11Y-002** · P1 · ARCH · XL · [!] — UI Automation provider model (absent, V-46). Unblock needs an MSAA-to-UIA bridge or a UIA implementation.
  - Done when: unblock requires a design decision.

- [ ] **A11Y-003** · P1 · BP · S — High-contrast and keyboard navigation (`shell/osshell/accessib`).
  - Done when: high-contrast mode applies to the shell and one application in a test.
  - Deps: SHL-001.

- [ ] **A11Y-004** · P2 · PORT · M — Magnifier and Narrator (verify in tree).
  - Done when: each runs in a test or is `[!]` with the reason.
  - Deps: A11Y-001.

- [ ] **A11Y-005** · P1 · BP · S — Accessibility at the logon screen and during setup.
  - Done when: a screen reader works at logon in a test.
  - Deps: AUT-004.

- [ ] **A11Y-006** · P2 · BP · S — Review the accessibility-related changes in PR #22 (`shell/shdocvw`), under GOV-010.
  - Done when: the review is recorded.
  - Deps: GOV-010.

### 6.25 I18N — Localization and NLS

- [ ] **I18N-001** · P1 · BP · M — Locale data (141 `.nls` files, V-47). Test the locales this build targets. **pt-BR is the first target** because the user's region is Brazil (São Paulo state): date and number formats, ABNT2 keyboard, and currency.
  - Done when: a pt-BR install works end to end; date, currency, and number formats match the locale tables; the test list is recorded.
  - Deps: BLD-006.

- [ ] **I18N-002** · P1 · PORT · L — Unicode tables: update case, normalization, and character-property data to a current Unicode version (the tree's version is **verify**). Use the Unicode conformance tests.
  - Done when: the Unicode conformance tests pass for the target version.
  - Deps: BLD-006.

- [ ] **I18N-003** · P1 · BP · M — IME: Simplified and Traditional Chinese, Japanese, Korean (V-47, verify paths). Test input in each.
  - Done when: input works in each IME in a test.
  - Deps: I18N-001.

- [ ] **I18N-004** · P1 · PORT · S — Keyboard layouts for modern USB keyboards: ABNT2 (pt-BR) and US.
  - Done when: each layout maps keys correctly on a USB keyboard in a test.
  - Deps: USB-005, I18N-001.

- [ ] **I18N-005** · P2 · BP · M — Setup and installer localization (`admin/darwin/data/intl/*.ptb` for pt-BR installer strings, V-47).
  - Done when: the installer shows pt-BR text in a test.
  - Deps: I18N-001.

- [ ] **I18N-006** · P1 · BP · S — Time zone rules: verify current rules for America/Sao_Paulo against an authoritative time zone database. Do not assume a rule; check it.
  - Done when: a test matrix of dates and offsets for São Paulo matches the reference database.
  - Deps: BLD-006.

- [ ] **I18N-007** · P2 · BP · S — Localization pipeline: `loc/` is near-empty (V-47). Document the pipeline and its inputs.
  - Done when: the pipeline doc exists.
  - Deps: none.

- [ ] **I18N-008** · P3 · PORT · L — Right-to-left scripts (Arabic and Hebrew).
  - Done when: a RTL locale renders and edits correctly in a test.
  - Deps: I18N-002.

### 6.26 PERF — Performance and responsiveness

- [ ] **PERF-001** · P1 · BP · M — Baselines on the reference hardware (section 7.2): boot time, idle memory, shell latency, file copy throughput, network throughput, TCP connect latency. Record hardware, versions, and command lines.
  - Done when: a baseline document is committed.
  - Deps: TST-014.

- [ ] **PERF-002** · P1 · BP · S — Triage performance item PERF-NTOS-001 (MEM-003). Code is present and used (N-06).
  - Done when: MEM-003 is closed.
  - Deps: MEM-003.

- [ ] **PERF-003** · P1 · PORT · M — Cache manager behavior: measure file cache hit rates and write-behind under load.
  - Done when: a recorded result with a target set by PERF-001.
  - Deps: PERF-001.

- [ ] **PERF-004** · P2 · ARCH · L — Scheduler and timer resolution: default timer resolution and high-resolution timers affect UI latency and power.
  - Done when: a latency test on the baseline shows the chosen defaults.
  - Deps: KRN-003.

- [ ] **PERF-005** · P2 · BP · S — Startup services review: remove or delay non-essential services.
  - Done when: boot time improves by a measured amount, recorded.
  - Deps: SEC-018.

- [ ] **PERF-006** · P1 · BP · M — Memory footprint of the default install: measure and reduce.
  - Done when: idle RAM is recorded and the target in section 7.3 is met or a plan exists.
  - Deps: PERF-001.

- [ ] **PERF-007** · P3 · PORT · L — Performance of repository tooling (`agents/`): already optimized per `.jules/bolt.md`; keep in maintenance. This does not affect the OS.
  - Done when: no action unless a regression appears.

### 6.27 REL — Reliability and maintenance

- [ ] **REL-001** · P1 · BP · M — 72-hour soak on each reference configuration, with a mixed workload.
  - Done when: zero bugchecks; leak budgets met (section 7.3).
  - Deps: BLD-006.

- [ ] **REL-002** · P1 · BP · S — Regression tracking: each audit item and each fixed bug has a test (TST-004).
  - Done when: the tracker is complete for the audit list.
  - Deps: TST-004.

- [ ] **REL-003** · P1 · BP · M — Leak tests: pool and handle counts in the soak (MEM-002).
  - Done when: budgets met.
  - Deps: MEM-002.

- [ ] **REL-004** · P1 · BP · S — Service watchdog and restart (`drivers/watchdog` present).
  - Done when: a hung service restarts in a test.
  - Deps: BLD-006.

- [ ] **REL-005** · P2 · BP · M — Third-party component versions and patch status (SUP section).
  - Done when: SBOM is complete and reviewed.
  - Deps: SUP-001.

- [ ] **REL-006** · P1 · BP · M — HTTP.sys (`inetsrv/iis/iisrearc/ul`) fuzzing and soak.
  - Done when: TST-009 passes for HTTP.sys.
  - Deps: TST-009.

- [ ] **REL-007** · P2 · BP · S — Crash-recovery behavior: boot after an unclean shutdown; disk check runs as expected.
  - Done when: 100 forced power-off cycles produce a boot without data loss in the test set.
  - Deps: FS-006.

### 6.28 INS — Installation, recovery, activation, and backup

- [ ] **INS-001** · P0 · BP · M — Safe installer defaults (`base/ntsetup`): destructive operations require explicit confirmation; existing partitions are not formatted without a clear prompt.
  - Done when: a test install on a disk with data shows the confirmation and preserves data when cancelled.
  - Deps: BLD-006.

- [ ] **INS-002** · P1 · PORT · M — UEFI and GPT installation path (BOOT-001, BOOT-002).
  - Done when: install to a GPT and UEFI VM completes and boots.
  - Deps: BOOT-001, BOOT-002.

- [ ] **INS-003** · P1 · BP · M — Recovery environment: a boot-time recovery mode that can repair a broken boot configuration.
  - Done when: corrupted boot configuration is repaired from recovery media in a test.
  - Deps: BOOT-007.

- [ ] **INS-004** · P1 · PORT · L — Backup and restore. NTBackup source is absent; only `tools/postbuildscripts/ntbackuponpersonal.cmd` exists (V-56). Design an in-house backup tool, or a supported third-party tool, that preserves ACLs and EFS.
  - Done when: a backup restores files with ACLs and EFS data intact in a test.
  - Deps: FS-014, GOV-006.

- [ ] **INS-005** · P1 · BP · M — Licensing and activation: local license and policy handling; no bypass of any vendor activation (4.2). Remove product-key validation dependencies on reproduced keys.
  - Done when: the policy is documented; key validation tests use fixtures that are not real keys.
  - Deps: GOV-004, GOV-001.

- [ ] **INS-006** · P1 · BP · S · QW — Time bomb (V-57, `tools/postbuildscripts/timebomb.cmd`). Decide: off for lab and daily builds; document any expiry policy.
  - Done when: the default setting is recorded; a test confirms no expiry in the default daily build.
  - Deps: DEC-01.

- [ ] **INS-007** · P2 · BP · S — Unattended installation from answer files (`base/ntsetup`): verify support (**verify**).
  - Done when: an unattended install completes in a test.
  - Deps: INS-001.

- [ ] **INS-008** · P1 · BP · S — Installation media integrity: checksums and signatures for each ISO (depends on BLD-009).
  - Done when: each release ISO has a published checksum and a verified signature.
  - Deps: BLD-009, DIST-005.

### 6.29 UPD — Updates, servicing, and rollback

- [ ] **UPD-001** · P0 · ARCH · XL — Update channel. Microsoft's service does not serve this line (4.1). Design a signed update channel: manifest, signature (CRY-002, CRY-003), rollback, and delta packages optional.
  - Done when: a signed package applies in a test and a tampered package is rejected.
  - Deps: CRY-002, UPD-002.

- [ ] **UPD-002** · P0 · PORT · M — Package verification: Authenticode and catalog verification (`ds/security/cryptoapi/pkitrust`).
  - Done when: a tampered catalog is rejected in a test.
  - Deps: CRY-008.

- [ ] **UPD-003** · P1 · PORT · L — Component servicing and side-by-side (WinSxS-era code present by count; verify). Windows File Protection (SFC) not located by path (**verify**).
  - Done when: a component update replaces the file and keeps the previous version available for rollback.
  - Deps: UPD-001.

- [ ] **UPD-004** · P1 · PORT · M — Rollback using volume snapshots (STO-009) and a last-known-good boot option (BOOT-007).
  - Done when: a failed update rolls back to the snapshot in a test.
  - Deps: STO-009, BOOT-007.

- [ ] **UPD-005** · P1 · BP · S — Hotfix (QFE) process: the `QFE/` tree is absent (V-59). Define the process and the directory.
  - Done when: a hotfix builds and applies in a test.
  - Deps: BLD-007.

- [ ] **UPD-006** · P2 · PORT · M — Driver update via catalog (DRV-002).
  - Done when: a driver update is applied and can be rolled back in a test.
  - Deps: DRV-002.

- [ ] **UPD-007** · P1 · BP · S — No telemetry or phone-home by default (any service that sends data is opt-in).
  - Done when: a fresh install makes no outbound connection except those the user configured (verified by capture).
  - Deps: SEC-018.

### 6.30 DRV — Drivers, signing, and frameworks

- [ ] **DRV-001** · P1 · BP · S — Driver signing policy and test signing (GOV-003 for keys).
  - Done when: an unsigned driver is refused by default on AMD64 and loads only in test mode.
  - Deps: SEC-022.

- [ ] **DRV-002** · P1 · BP · M — Driver store and INF handling (`base/pnp`, setup API): install, uninstall, rollback.
  - Done when: a driver package installs, uninstalls, and rolls back in a test.
  - Deps: PNP-001.

- [ ] **DRV-003** · P1 · PORT · M — Driver ABI compatibility: the DDK headers (`public/ddk/inc`, 176 headers) and version macros. Build a sample driver and load it.
  - Done when: a sample driver builds and loads on the baseline.
  - Deps: BLD-006.

- [ ] **DRV-004** · P2 · ARCH · L — Modern driver frameworks: no WDF/KMDF or UMDF directory found by path (V-30). Decide whether to port one or support WDM only.
  - Done when: the decision is recorded; if a framework is chosen, a sample loads.
  - Deps: DEC-02.

- [!] **DRV-005** · P2 — Modern driver model features that depend on WDDM or NDIS 6 (GFX-002, NET-001).
  - Done when: unblock requires those items.

- [ ] **DRV-006** · P1 · BP · S — OEM and unsigned driver packages: `drivers/oem` target is missing (V-59). Decide policy.
  - Done when: a policy is recorded.
  - Deps: DEC-02.

### 6.31 DEVX — Developer experience and SDK

- [ ] **DEVX-001** · P1 · BP · M — SDK packaging: `public/sdk/inc` (1,407 headers), `public/ddk/inc` (176 headers), `published/` (374 files; `published/sdk/inc` has 252 headers). Create a package manifest and a version (`ntverp.h`).
  - Done when: an SDK package installs, and a hello-world application builds with it on the reference host.
  - Deps: BLD-006.

- [ ] **DEVX-002** · P1 · BP · M — Debugger workflow: `sdktools/debuggers`, KD (KRN-005).
  - Done when: a remote-debug session from the reference host works.
  - Deps: KRN-005.

- [ ] **DEVX-003** · P2 · BP · M — Symbol server and PDB handling: 572 `.pdb` files are tracked (V-05); move them to the symbol store (DEC-05).
  - Done when: symbols for each build are published to a symbol store and removed from git.
  - Deps: DEC-05.

- [ ] **DEVX-004** · P2 · PORT · S — Static analysis integration (TST-006) in the developer workflow.
  - Done when: the analyzer runs locally on a touched file.
  - Deps: TST-006.

- [ ] **DEVX-005** · P2 · BP · S — Code search index generated locally (not committed).
  - Done when: the index generation command is documented.
  - Deps: none.

- [ ] **DEVX-006** · P1 · BP · S — Coding rules in `AGENTS.md` (source-only changes, no mass reformatting). Add an `.editorconfig` only if it matches existing files and does not reformat them.
  - Done when: rules are referenced from the contributor docs.
  - Deps: none.

- [ ] **DEVX-007** · P2 · BP · S — DRT test documentation for each component (TST-005).
  - Done when: each buildable component documents how to run its tests.
  - Deps: TST-005.

- [ ] **DEVX-008** · P1 · BP · S · QW — Repository hygiene (BLD-015).
  - Done when: see BLD-015.
  - Deps: BLD-015.

### 6.32 SUP — Third-party code and supply chain

- [ ] **SUP-001** · P0 · BP · M — Third-party code inventory (SBOM): search for vendored crypto and parsing libraries (for example, `md5.c`, `des.h`, `sha.h`, and `rc4.h` appear in several places; **verify each by content**). Record component, version, license, upstream, patches, and advisories.
  - Done when: `docs/sbom.csv` lists each vendored library.
  - Deps: GOV-001.

- [ ] **SUP-002** · P1 · BP · M — Vendored image libraries (`windows/advcore/gdiplus/engine/imaging/jpeg/libjpeg`): record version and advisories; update where the license allows.
  - Done when: the version is recorded and any advisory is triaged.
  - Deps: SUP-001.

- [ ] **SUP-003** · P1 · BP · S — Data blobs (e.g., handwriting data under `drivers/tpg/hwx`, large `.dls` MIDI banks): license and redistribution status.
  - Done when: each blob is in the license register (GOV-008).
  - Deps: GOV-008.

- [ ] **SUP-004** · P2 · BP · S — Build-tool supply chain: pin Perl and the other host tools (BLD-016).
  - Done when: the pinned versions are in the host document.
  - Deps: BLD-005.

- [!] **SUP-005** · P2 — Binary-only components with no source. Cannot be rebuilt or patched. Plan replacement or source recovery.
  - Done when: each binary-only component is listed and has a replacement or a source plan.
  - Deps: SUP-001.

### 6.33 DIST — Distribution and release

- [ ] **DIST-001** · P1 · BP · S — Distribution scope (DEC-01) and the matching rights (GOV-001).
  - Done when: scope is recorded.
  - Deps: DEC-01.

- [ ] **DIST-002** · P1 · BP · M — ISO build and verification (BLD-009; `oscdimg` replacement or restore).
  - Done when: an ISO builds from the scoped set and boots in a VM.
  - Deps: BLD-009, BLD-006.

- [ ] **DIST-003** · P2 · BP · S — Release channels (lab, beta, release).
  - Done when: the channel list is documented.
  - Deps: UPD-001.

- [ ] **DIST-004** · P2 · BP · S — Release notes and known-issues list generated from this file's statuses.
  - Done when: a release-notes template exists and pulls `[!]` and `[ ]` items for known issues.
  - Deps: DOC-005.

- [ ] **DIST-005** · P1 · BP · M — Release signing: production keys require a key authority (GOV-003, BOOT-006). Lab builds use a test CA that is labeled as test.
  - Done when: a signing policy is recorded; no test key is used for a release.
  - Deps: GOV-003.

---

## 7. Measurable acceptance criteria and test matrix

Numbers marked **proposed** are initial targets. Replace them with measured baselines (PERF-001) once the reference hardware exists. The criteria are not claims that any of this works today.

### 7.1 Gates

| Gate | Name | Pass criteria (all must hold) |
|---|---|---|
| **G0** | Governed baseline | DEC-01, DEC-02, DEC-03 recorded. GOV-001 to GOV-004 done. TST-001 and TST-002 pass (`verify.py` exit 0). Scoped build set defined (BLD-006 list committed). |
| **G1** | Build foundation | Clean build of the scoped set on the reference host: 0 errors, warning baseline recorded. Two clean builds: byte-identical except documented files. BLD-001, BLD-002, BLD-003 done. A01 and A02 probes pass. |
| **G2** | Secure defaults (x86 VM) | SEC-001 to SEC-006, SEC-015, SEC-017, SEC-018 done. A default-profile TLS scan shows no SSLv2, SSLv3, RC4, or single DES. PE audit: `/GS` on at least 99% of scoped images; NX on all scoped images (SEC-007). Fresh-install listener count matches the allowlist. |
| **G3** | Crypto and identity | CRY-002 to CRY-006 done (TLS 1.2 interop with OpenSSL and curl). AUT-001 done (AES-256 Kerberos against a modern KDC). FS-001 signing done (SMB 3.1.1 with Samba 4.x). Certificate fixtures (CRY-008) pass. |
| **G4** | Modern platform (AMD64 VM and listed hardware) | BOOT-001 and BOOT-002 done. KRN-002 done. STO-001 done (AHCI). USB-002 done (xHCI) or `[!]` by decision. NET-001 decided. AUD-002 done. |
| **G5** | Daily-driver candidate | APP-001 corpus: at least 90% pass (launch, core workflow, close). SHL, I18N-001, I18N-003, A11Y-001 gates pass. Performance within the proposed targets in 7.3. 14-day internal dogfood with a bug count recorded. |
| **G6** | Release | LEGAL and SECURITY sign-off recorded (GOV-001, SEC-030). Signed update channel (UPD-001) and rollback test (UPD-004) pass. Release ISO verified (INS-008). Known-issues list generated (DIST-004). |

### 7.2 Reference test configurations

| Config | Platform | Notes |
|---|---|---|
| **R-x86-VM** | QEMU or KVM, i440FX machine, OVMF not required | IDE disk (in-tree ATA path); Intel 82557-class NIC (`-device e100`) matches `e100bex`; VGA-class display. First gate config. |
| **R-x86-Q35** | QEMU Q35 machine | Adds PCIe root ports for PNP-003; AHCI disk (`ich9-ahci`) for STO-001; USB UHCI/EHCI controllers. |
| **R-AMD64-OVMF** | QEMU with OVMF (UEFI), AMD64 build | For BOOT-001, BOOT-002, KRN-002, xHCI (`qemu-xhci`). Add after BOOT-001. |
| **R-HW-1 … R-HW-n** | Physical machines (list in TST-011) | Each row: CPU, chipset, storage controller, NIC, GPU (VGA-class only until GFX-002), audio, USB controllers. Record the exact models. |
| **R-SRV-Samba** | Samba 4.x server (test host) | SMB 2.x and 3.x interop (FS-001). |
| **R-SRV-KDC** | MIT Kerberos KDC (test host) and a current Windows Server DC (if rights permit) | AUT-001, AUT-002. Test both where possible. |
| **R-TLS-Ref** | OpenSSL 3.x, curl, Go (test host) | CRY-006 interop. |
| **R-DHCP-Ref** | ISC dhcpd (test host) | NET-009. |
| **R-RADIUS-Ref** | FreeRADIUS (test host) | NET-013. |

### 7.3 Proposed quantitative targets (replace with measured baselines)

| Area | Metric | Proposed target |
|---|---|---|
| Boot | Cold boot to desktop on R-x86-Q35 | ≤ 90 s (proposed; baseline first) |
| Memory | Idle RAM, default install, R-x86-VM | ≤ baseline + 10% per release |
| Leaks | Pool and handle growth over 72 h idle + mixed workload | ≤ 5% per 24 h (proposed) |
| Stability | Bugchecks in 72 h soak | 0 |
| Storage | 1 h mixed 4K QD32 fio on AHCI (STO-001) | 0 I/O errors; latency recorded |
| USB | Plug and unplug cycles per device class | 100 cycles, 0 bugchecks |
| Network | LAN TCP throughput (iperf3) | Within 80% of the same hardware under a modern Linux peer (proposed; measure both) |
| Power | Suspend and resume cycles (PWR-001) | 100 cycles, 0 failures |
| Security | Default listener count | Equals the documented allowlist |
| Security | Default TLS offered | No SSLv2, SSLv3, RC4, single DES, NULL, or export suites |
| Crypto | Known-answer tests (CRY-002 to 005) | 100% pass on NIST and RFC vectors |
| Fuzzing | Per harness (TST-009) | ≥ 24 CPU-hours, 0 unresolved crashes |

### 7.4 Application pass criteria (APP-001 corpus)

An application **passes** when, on the stated configuration: (1) it installs or copies cleanly, (2) it launches, (3) its core workflow completes (the workflow is written in the corpus entry), (4) it closes without error, and (5) it runs for 30 minutes idle with no crash. The corpus records the version and configuration for each result. A failure is recorded with the reason, and `[!]` is used when the reason is a documented platform gap.

---

## 8. Quick wins (QW)

The items below are S-size or smaller, are BP, and carry low ABI risk. Do them early.

1. BLD-001 — build-number parser (A01).
2. BLD-002 — fdisk.dlg CONTROL fields (A02).
3. BLD-004 — README razzle switch (A14).
4. TST-002 — `verify.py` fixes (N-07).
5. GOV-002 — root LICENSE and NOTICE.
6. GOV-004 — remove product keys from README (A15).
7. GOV-007 — support posture and SECURITY.md.
8. BLD-015 — `.gitignore` and `.gitattributes`.
9. SEC-001 — disable SSLv2 and SSLv3 defaults.
10. SEC-004 — disable RC4 and single DES defaults.
11. SEC-015 — A09 fix in the UL test client.
12. SEC-017 — legacy protocols off by default.
13. CRY-010 — 2048-bit RSA default.
14. BOOT-004 — `_OS` compatibility value (A06).
15. BOOT-005 — `OS=Windows_NT` (A05).
16. TST-008 — assignment-in-condition fixes (A13 part).
17. INS-006 — time bomb default.
18. BLD-003 — branding single source (A07).

---

## 9. Decisions, open questions, and unresolved checks

### 9.1 Decisions (fill in)

| ID | Question | Options | Owner | Status |
|---|---|---|---|---|
| DEC-01 | Distribution scope | (a) lab, (b) internal, (c) public | project owner | `[ ]` |
| DEC-02 | Base strategy | (A) keep and backport/port; (B) clean-room new base (possibly with ReactOS collaboration); (C) hybrid kernel replacement | project owner | `[ ]` |
| DEC-03 | Architectures | x86 then AMD64; retire IA-64, Alpha, MIPS, PPC | project owner | `[ ]` |
| DEC-04 | Keys in history | rewrite, accept, rotate | project owner | `[ ]` |
| DEC-05 | Binary storage | remove, external store, LFS | project owner | `[ ]` |
| DEC-06 | Canonical plan | this file vs PR #26 | project owner | `[ ]` |
| DEC-07 | Issue tracking | enable Issues, or keep this model | project owner | `[ ]` |

### 9.2 Unresolved checks (not yet done; do not treat as facts)

These are the open checks from the audit. Each is needed before any dependent claim is made.

1. ACPI version support in the AML interpreter (BOOT-011).
2. MSI-X coverage beyond the two files found (PNP-002).
3. CodeIntegrity and driver-signature enforcement scope (SEC-022).
4. NTLM client LM default at `ds/security/protocols/msv_sspi/ctxtcli.cxx:227` (SEC-005). Not traced.
5. WinINet SSLv2 effective default in the running system (SEC-001). Only the source default was read.
6. A09 ASan result is from a **reconstruction**, not the original binary (SEC-015).
7. Whether A07 product-name strings are gated by `NEONT_BRANDING` at their consumers (BLD-003). Consumers not traced.
8. HDAudio driver location (AUD-002) and the DNS resolver location (NET-008).
9. Windows File Protection and SFC (UPD-003).
10. Protocol-level SMB1 behavior in `base/fs/srv` (FS-002). The "no SMB2 identifiers" finding is verified; the full dialect negotiation is not.
11. Full wincrypt.h algorithm list for SHA-2 (CRY-001).
12. Unicode version in the tree (I18N-002).
13. Whether the `windows/appcompat/shimengines` infrastructure can host API shims (API-002).

### 9.3 Verification notes on earlier audit tooling

- `agents/audit_reproduce.py` results are only partially reliable: A01 reproduced; A02 reproduced; A07 reproduced; A09 reproduced by reconstruction; A08 reproduces a stale snippet; A10 crashes; A11 probe uses a stub. See TST-003.
- Unsafe-API counts (V-50) are word-matches including comments and samples. They are not vulnerability counts.
- Some greps produced false positives and were not used as evidence: `DYNAMICBASE` (whole-tree hit), `http2`/`spdy` (RPC-over-HTTP), `quic`, `ogg|vorbis`, `avc`, `dotnet`/`netfx` (noise), `xhci`/`nvme`/`ahci` substrings in binary data and in longer identifiers.
- The DIRS parser count (~380 dangling) is approximate; it ignores conditionals. Do not cite it as a build break without an evaluator (BLD-008).

---

## 10. Dependency order (summary)

```
GOV-001 ──► GOV-002/003/005/008 ──► DEC-01 ──► DIST scope
   │
   ├──► BLD-001..004 ──► TST-002 ──► G0
   │
   ├──► BLD-005 (host) ──► BLD-006 (scoped build) ──► G1
   │         │
   │         ├──► BLD-007/008 (dirs evaluator)
   │         └──► BLD-012 (toolchain) ──► SEC-006/007/008/009 (mitigations)
   │
   ├──► SEC-001..005, SEC-017 (defaults) ──► G2
   │         │
   │         └──► CRY-001 ──► CRY-002/003/004/005 ──► CRY-006 (TLS 1.2) ──► G3
   │                  │                                      │
   │                  └──► AUT-001 (Kerberos AES)            ├──► NET-013 (EAP-TLS), NET-018 (HTTP/2),
   │                                                         │    AUT-005 (CredSSP), MMD-007
   │                                                         └──► CRY-007 (TLS 1.3) ──► NET-017 (QUIC)
   │
   ├──► FS-001 (SMB2) ──► FS-002 (SMB1 off)
   │
   ├──► BOOT-001 (x64 UEFI) ──► BOOT-002 (GPT) ──► INS-002 ──► G4
   │         │
   │         └──► SEC-022 (driver policy), KRN-008 (KASLR)
   │
   ├──► KRN-002 (x2APIC) ──► PNP-002 (MSI-X) ──► STO-001 (AHCI), USB-002 (xHCI), STO-002 (NVMe)
   │
   ├──► NET-001 (NDIS 6 decision) ──► NET-011 (Wi-Fi, [!]) ──► NET-022 (Bluetooth, [!])
   │
   ├──► FS-012 (Filter Manager) ──► AV/backup/encryption compatibility
   │
   └──► API-001 (baseline) ──► API-002 (shims) ──► APP-001 (corpus) ──► G5
              │
              └──► CRY-011 (RNG) ──► API-010 (bcrypt/ncrypt)
```

---

## 11. Change log

| Date | Change | Author |
|---|---|---|
| 2026-10-31 | Initial plan created. Audit verified 15 audit items (A01–A15) and 9 new findings (N-01–N-09). No implementation done. Parallel PLAN.md in PR #26 flagged (DEC-06). | agent |

---

## Appendix A — Upstream references

Numbered references used in the text. Items 1–9 were checked by search in this session (search results only; the pages themselves were not fully read). Items 10–21 are standard index pages that were **not fetched** in this session; use them as pointers and check the current text.

1. NewsBoss, end-of-support dates: Windows XP (2014-04-08) and Windows Server 2003 (2015-07-14) [1](https://www.newsboss.com/windows-xp-support-ends)
2. Wine (software) license statement, as stated by a fork of Wine: LGPL 2.1 or later [2](https://github.com/Grys73/wine)
3. Public issue quoting Wine's Clean Room Guidelines ("Don't use an LLM tool to generate code") [3](https://github.com/chaoss/wg-ai-alignment/issues/108)
4. Neowin, Chrome 109 is the last version to support Windows 7 and 8.1 [4](https://www.neowin.net/news/google-chrome-109-now-available-last-version-to-support-windows-7-and-81/)
5. XDA Developers, ReactOS 0.4.15 release (March 2025) [5](https://www.xda-developers.com/reactos-major-update-2025/)
6. Softtechhub, ReactOS 0.4.15 and XP/Server 2003 application targeting [6](https://softtechhub.us/2025/03/23/reactos-the-open-source-alternative-to-windows-has-been-updated/)
7. Yahoo Tech, ReactOS 0.4.15 amd64 to desktop, no WOW64 yet [7](https://tech.yahoo.com/computing/articles/reactos-open-source-windows-just-200448247.html)
8. VxKex-NEXT, import-table editing for API extensions [8](https://github.com/YuZhouRen86/VxKex-NEXT)
9. VxKex-NEXT fork, IFEO `VerifierDlls` per-process loading [9](https://github.com/xuzhongxing/VxKex-NEXT)
10. RFC 8996, deprecation of TLS 1.0 and 1.1 [10](https://www.rfc-editor.org/info/rfc8996/)
11. NIST FIPS 180-4, Secure Hash Standard [11](https://csrc.nist.gov/publications/detail/fips/180/4/final)
12. NIST SP 800-38D, GCM [12](https://csrc.nist.gov/pubs/sp/800/38/d/final)
13. RFC 8439, ChaCha20-Poly1305 [13](https://www.rfc-editor.org/info/rfc8439)
14. RFC 8422, ECC cipher suites for TLS [14](https://www.rfc-editor.org/info/rfc8422)
15. RFC 7748, X25519 and X448 [15](https://www.rfc-editor.org/info/rfc7748)
16. RFC 5869, HKDF [16](https://www.rfc-editor.org/info/rfc5869)
17. RFC 5246, TLS 1.2 [17](https://www.rfc-editor.org/info/rfc5246)
18. RFC 8446, TLS 1.3 [18](https://www.rfc-editor.org/info/rfc8446)
19. RFC 6125, service identity in PKI [19](https://www.rfc-editor.org/info/rfc6125)
20. NIST SP 800-90A Rev. 1, DRBGs [20](https://csrc.nist.gov/pubs/sp/800/90/a/r1/final)
21. RFC 3962, AES for Kerberos 5 [21](https://www.rfc-editor.org/info/rfc3962)

Also referenced without links (use the official text when working on the item): RFC 7296 (IKEv2), RFC 5280 (X.509/PKIX), RFC 6960 (OCSP), RFC 8011 (IPP), RFC 7413 (TCP Fast Open), MS-SMB2 (SMB 2/3 protocol), NVM Express base specification, xHCI specification, Intel AHCI specification, ACPI specification, UEFI specification, PCI Express base specification, USB 3.x specification, IEEE 802.11i, IEEE 802.1X, Unicode Standard and UCD, and the `strsafe` documentation.
