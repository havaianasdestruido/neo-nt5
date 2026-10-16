# NEONT repository audit — 2026-10-16

This directory contains issue-ready reports for confirmed defects found during the repository-wide audit requested for branch `arena/c7c0958f-neo-nt5`.

**GitHub publishing status: blocked.** The repository `havaianasdestruido/neo-nt5` has Issues disabled, and Discussions are also disabled. The command `gh issue create` returns:

```text
the 'havaianasdestruido/neo-nt5' repository has disabled issues
```

`gh repo view` also confirms `hasIssuesEnabled: false`. I did not fabricate issue numbers or claim issues were created; each finding is saved here as an issue-shaped Markdown report that can be converted into a GitHub Issue after Issues are enabled, or filed in another tracker.

## Verified tooling and checks run

- Repository docs: `README.md`, `agents/README.md`, component guides, build/release guide, catalog and verification docs.
- Existing GitHub records: open/closed issues/PRs, PR comments, and reviews for PRs #1 and #2.
- Repository checks:
  - `python3 agents/verify.py` — passed.
  - `python3 agents/generate_catalog.py --check` — passed.
  - `git diff --check` — passed.
- Extracted-code reproduction probes: `python3 agents/audit_reproduce.py`. This uses Python 3, GCC/ASan and Perl available in the sandbox. It does not modify project source and does not attempt a full Windows build.
- Static source tracing for build scripts, resource files, SMSS, ACPI, WMI HTTP transport, RRAS PPP, NetMeeting codecs, Terminal Services licensing and documentation.

## Files created by the audit

- `manifest.json` — machine-readable list of findings, severities, affected subsystems and paths.
- `audit_reproduce.py` — non-destructive extracted-code probes used for reproduction.
- `01`–`15` Markdown reports — one issue per distinct defect, in the requested structure.

## Confirmed defects (15 local reports, **0 GitHub Issues published because Issues are disabled**)

| ID | Severity | Subsystem | Report |
| --- | --- | --- | --- |
| A01 | High | Build/versioning | [01-build-number.md](01-build-number.md) |
| A02 | Medium | Disk Administrator resources | [02-fdisk-resource.md](02-fdisk-resource.md) |
| A03 | High | Session Manager initialization | [03-smss-uninitialized.md](03-smss-uninitialized.md) |
| A04 | High | Session Manager registry boundary | [04-smss-string.md](04-smss-string.md) |
| A05 | Medium | OS environment / tool compatibility | [05-os-environment.md](05-os-environment.md) |
| A06 | Medium | ACPI firmware compatibility | [06-acpi-os.md](06-acpi-os.md) |
| A07 | Low | Multimedia version resources | [07-media-toggle.md](07-media-toggle.md) |
| A08 | Low | IIS UL Win9x test clients | [08-overlapped-zero.md](08-overlapped-zero.md) |
| A09 | Low | IIS UL Win9x snd test client | [09-snd-bounds.md](09-snd-bounds.md) |
| A10 | Medium | Terminal Services licensing database | [10-license-insert.md](10-license-insert.md) |
| A11 | Medium | WMI XML HTTP transport | [11-http-header.md](11-http-header.md) |
| A12 | High | RRAS PPP CHAP session-key derivation | [12-chap-session-key.md](12-chap-session-key.md) |
| A13 | Medium | NetMeeting audio/video codecs | [13-netmeeting-codec-flags.md](13-netmeeting-codec-flags.md) |
| A14 | Low | Build documentation | [14-docs-chkkernel.md](14-docs-chkkernel.md) |
| A15 | Medium | Repository documentation | [15-security-readme-keys.md](15-security-readme-keys.md) |

## Key findings summary

The highest-risk confirmed defects are:

1. **Build break after the NEONT branding change**: `tools/genbldno.pl` no longer parses the version-header build number because it requires the literal `/* NT */` comment.
2. **SMSS startup defects in the new Branding registry logic**: an uninitialized `ValueData` pointer on missing/error paths, plus an unbounded `wcslen` on REG_SZ data that may lack a NUL terminator.
3. **Compatibility break**: default branding sets the process environment `OS=NEONT`, while many checked-in NT batch wrappers require `%OS%==Windows_NT`.
4. **Security/correctness defects in existing and modified code**: PPP CHAP user session-key zeroing clears only pointer-width bytes; WMI HTTP header failure returns success with uninitialized data; Terminal Services license insert failures are reported as success.
5. **Resource/build/documentation defects**: malformed `fdisk.dlg` after the branding conditional, broken `NEONT_BRANDING=0` media resource fallback, transposed `memset`/buffer overflows in sample code, a NetMeeting codec one-shot flag bug, an incorrect Razzle switch in README, and plain-text product keys in README.

## Deduplication

I checked available GitHub issue/PR/discussion data before filing reports. At audit time there were two merged PRs (#1 and #2) and no non-PR issues. PR #2 introduced the branding toggle feature but did not contain fixes or reports for these defects. Existing bot comments were status/usage bots and did not identify the findings. Findings were grouped into one report per distinct root cause; for example the two independent SMSS defects are separate reports because one is about initialization/fallback and the other is about registry string validation, and fixing one does not fix the other. The duplicate `dech261`/`dech263` NetMeeting bug was consolidated because it is the same root fix across identical code copies.

## Coverage limitations

- The repository contains **277,918 tracked files** across 21 major trees and requires a Windows/Razzle/NMAKE build environment not available in this Linux sandbox. No full build, installation, boot, ESE database, IIS, DHCP, ACPI firmware, or MS-CHAP live integration was run.
- Execution evidence is therefore a mix of:
  - unchanged-script execution (`genbldno.pl`);
  - extracted-code probes under GCC/ASan for memory and control-flow defects;
  - static source tracing with file/line evidence and conservative impact statements;
  - repository/documentation verification (`verify.py`, catalog, `git diff --check`, grep/static analysis).
- Many trees remain only partially audited at a static level, so the absence of a finding in this set should not be interpreted as proof that no other defects exist. Priority was given to defects introduced or exposed by the recent branding change, security/correctness-sensitive code reachable from obvious entry points, and defects that could be reproduced with available tools.
- I did not enable GitHub Issues, modify repository settings, push code changes, or create pull requests. No product key values are reproduced in the issue reports beyond noting that README contains them.
