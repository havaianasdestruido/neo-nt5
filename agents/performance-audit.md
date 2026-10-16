# Performance audit — 2026-10-16

## Scope and method

This is an incremental, source-based investigation, not a claim of complete repository coverage. The checkout is a historical Windows NT source tree organized into distinct `dirs`/`sources` build targets. This pass prioritized a kernel memory-manager entry path and followed its call into the I/O manager's triage-dump helpers. Findings are classified by evidence; textual loop matches alone are not defects.

The documented native build is Razzle + `build.exe`/NMAKE under Windows (`agents/build-and-release.md`). Those tools are not installed in this Linux workspace. No kernel image, boot, crash-dump workload, or performance benchmark was run.

## Findings

### PERF-NTOS-001 — Repeated full triage-dump validation in module matching

- **Category:** B — optimization candidate; repeated work is established, material impact is unmeasured.
- **Subsystem / location:** Memory manager startup triage, `base/ntos/mm/triage.c`, `MiTriageSystem` (particularly the loader-list comparison around lines 286–306); helper `TriageGetLoaderEntry` in `base/ntos/io/iomgr/triage.c` around lines 416–476; validation helper `TriagepVerifyDump` in the same file around lines 171–213.
- **Execution path:** `MiInitializeMemoryManager` in `base/ntos/mm/mminit.c` calls `MiTriageSystem` during initialization (around line 1131), except safe boot. `MiTriageSystem` exits early unless a previous dump exists, its bugcheck is actionable, triage is enabled, and triage information is valid. This is therefore a conditional boot-time path—not a recurring worker or every-second path.
- **Observed operation:** For every loaded kernel module, `MiTriageSystem` scans all `ModuleCount` triage entries to find any matching checksum. Each iteration calls `TriageGetLoaderEntry`. That helper calls `TriagepVerifyDump`, which validates the dump header and sentinel inside SEH, before calculating an indexed entry. On an actionable triage boot, dump verification is consequently repeated up to once per dump entry per loaded module.
- **Cost evidence:** With `L` loaded modules and `M` dump entries, the comparison is O(L×M); validation adds O(L×M) repeated checks of dump-wide fixed metadata. `TriageGetLoaderEntry` itself indexes the driver array directly, so this is not an additional linear search in that helper. The checksum comparison is set-membership-like and currently accepts any entry with an equal checksum.
- **Why not changed:** The path runs only during early initialization and only for actionable triage dumps, so frequency and user-visible cost are likely low. Removing defensive validation from the helper or bypassing it would change a checked boundary around memory sourced from a crash dump; making a cache/hash index introduces allocation, bounds, collision, and checksum-equivalence concerns. No representative large dump or Windows kernel build is available to quantify benefit or test malformed-dump behavior. A safe next step is profiling this path on a supported kernel build and considering a private validated accessor scoped to `MiTriageSystem`, preserving validation at the external boundary.
- **Correctness/concurrency:** Initialization phase and helper comments specify phase 0 / APC_LEVEL or below. Do not add pageable allocation or synchronization assumptions without checking the relevant kernel constraints. Preserve matching semantics, malformed-dump rejection, and exception safety.
- **Validation performed:** Read the caller and helper implementations; verified that the loop is conditional boot-time work and that helper indexing is direct. No code change, build, runtime test, or benchmark was performed.
- **Remaining uncertainty:** Typical and worst-case `ModuleCount`, loaded module count, cost of SEH validation on the target architecture, and whether this path is measurable relative to boot/triage work.

## High-frequency path checked, no defect established

`MmZeroPageThread` in `base/ntos/mm/zeropage.c` is a genuine recurring kernel worker. It waits with `KeWaitForMultipleObjects` on the zero-page event and system-idle timer, then removes a free page, releases the PFN lock before zeroing, and reacquires it to insert the page. The multi-node scan is bounded by `KeNumberNodes`, while the color loop advances through the color mask until a non-empty color is found (with an invariant assertion). This source inspection found no safe, clearly redundant operation to remove. Changing its waits, lock scope, or page/color selection without workload and kernel validation would be speculative and potentially affect memory-manager correctness.

## Validation environment and limitations

- `python3 agents/generate_catalog.py --check`: passed.
- `python3 agents/verify.py`: failed on pre-existing documentation validation errors in `agents/audit/14-docs-chkkernel.md` (two broken links), `agents/audit/15-security-readme-keys.md` (one broken link), and missing `agents/components/.jules.md` guide. These unrelated files were not modified.
- `git diff --check`: passed before adding this report; rerun on final changes.
- No `build`, `cl`, or `nmake` executable is available. No kernel compilation or runtime test is claimed.

## Next investigations

1. Use a supported Windows kernel build and boot/crash-dump workload to measure PERF-NTOS-001 before deciding whether a helper/API change is warranted.
2. Continue subsystem-by-subsystem through scheduler/dispatcher and I/O paths, tracing actual entry points and callers rather than treating loop-search hits as hot paths.
3. Record only source-backed, independently actionable findings; classify impact separately from source-level certainty.
