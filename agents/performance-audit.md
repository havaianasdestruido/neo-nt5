# Performance audit — 2026-10-16

## Scope and method

This is an incremental, source-based investigation, not a claim of complete repository coverage. The checkout is a historical Windows NT source tree organized into distinct `dirs`/`sources` build targets. This pass prioritized a kernel memory-manager entry path and followed its call into the I/O manager's triage-dump helpers. Findings are classified by evidence; textual loop matches alone are not defects.

The documented native build is Razzle + `build.exe`/NMAKE under Windows (`agents/build-and-release.md`). Those tools are not installed in this Linux workspace. No kernel image, boot, crash-dump workload, or performance benchmark was run.

## Findings

### PERF-NTOS-001 — Repeated full triage-dump validation in module matching

- **Category:** A for the redundant repeated validation in the nested match path; no claim of measurable boot-time impact.
- **Subsystem / location:** Memory manager startup triage, `base/ntos/mm/triage.c`, `MiTriageSystem` (particularly the loader-list comparison around lines 286–306); helper `TriageGetLoaderEntry` in `base/ntos/io/iomgr/triage.c` around lines 416–476; validation helper `TriagepVerifyDump` in the same file around lines 171–213.
- **Execution path:** `MiInitializeMemoryManager` in `base/ntos/mm/mminit.c` calls `MiTriageSystem` during initialization (around line 1131), except safe boot. `MiTriageSystem` exits early unless a previous dump exists, its bugcheck is actionable, triage is enabled, and triage information is valid. This is therefore a conditional boot-time path—not a recurring worker or every-second path.
- **Observed operation (before fix):** For every loaded kernel module, `MiTriageSystem` scanned all `ModuleCount` triage entries to find any matching checksum. Each iteration called `TriageGetLoaderEntry`, which called `TriagepVerifyDump` (header/sentinel validation inside SEH) before calculating an indexed entry. This repeated dump-wide validation up to once per dump entry per loaded module.
- **Cost evidence:** With `L` loaded modules and `M` dump entries, the comparison is O(L×M); validation adds O(L×M) repeated checks of dump-wide fixed metadata. `TriageGetLoaderEntry` itself indexes the driver array directly, so this is not an additional linear search in that helper. The checksum comparison is set-membership-like and currently accepts any entry with an equal checksum.
- **Correction:** Added `TriageHasLoaderChecksum` in `base/ntos/io/iomgr/triage.c`; it validates the dump once per loaded module, then compares the checksum across the indexed driver array. `MiTriageSystem` now calls this helper instead of invoking the validating accessor for every entry. The existing `TriageGetLoaderEntry` remains unchanged for other uses. This preserves the checksum-any-entry match behavior and avoids allocation or a new index. Matching remains O(L×M); redundant dump verification in the nested loop is reduced from O(L×M) to O(L) validation calls (plus the separate initial enumeration pass).
- **Correctness/concurrency:** The helper retains `TriagepVerifyDump` before dereferencing dump content, uses the existing indexed layout and driver count, and is called in the same phase-0 path. No new shared state, locks, or allocations. The dump format's offsets are trusted to the same extent as in the existing accessor. In checked builds, `TriagepGetTriagePointer`'s assertion may perform an additional validation once per helper call.
- **Validation performed:** Inspected caller/helper and reviewed the source diff; `git diff --check` and repository catalog validation are run after the edit. Windows build, runtime malformed-dump tests, and benchmark remain unavailable.
- **Remaining uncertainty:** Actual boot-time impact and malformed/corrupt dump behavior still require testing on the supported kernel toolchain. The optimization removes repeated validation by construction, but measured speedup is not claimed.

## High-frequency path checked, no defect established

`MmZeroPageThread` in `base/ntos/mm/zeropage.c` is a genuine recurring kernel worker. It waits with `KeWaitForMultipleObjects` on the zero-page event and system-idle timer, then removes a free page, releases the PFN lock before zeroing, and reacquires it to insert the page. The multi-node scan is bounded by `KeNumberNodes`, while the color loop advances through the color mask until a non-empty color is found (with an invariant assertion). This source inspection found no safe, clearly redundant operation to remove. Changing its waits, lock scope, or page/color selection without workload and kernel validation would be speculative and potentially affect memory-manager correctness.

## Validation environment and limitations

- `python3 agents/generate_catalog.py --check`: passed.
- `python3 agents/verify.py`: failed on pre-existing documentation validation errors in `agents/audit/14-docs-chkkernel.md` (two broken links), `agents/audit/15-security-readme-keys.md` (one broken link), and missing `agents/components/.jules.md` guide. These unrelated files were not modified.
- `git diff --check`: passed before adding this report; rerun on final changes.
- No `build`, `cl`, or `nmake` executable is available. No kernel compilation or runtime test is claimed.

## Next investigations

1. Use a supported Windows kernel build and boot/crash-dump workload to measure PERF-NTOS-001 and exercise malformed-dump rejection against the corrected helper.
2. Continue subsystem-by-subsystem through scheduler/dispatcher and I/O paths, tracing actual entry points and callers rather than treating loop-search hits as hot paths.
3. Record only source-backed, independently actionable findings; classify impact separately from source-level certainty.
