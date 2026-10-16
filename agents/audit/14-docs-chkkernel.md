# docs: README documents unsupported CkhKernel razzle switch

Status: **not published — repository Issues disabled**. Local finding A14.

## Summary

The README tells users to pass `CkhKernel`, but the actual razzle.cmd parser only recognizes `ChkKernel`; the typo silently does nothing.

## Evidence and reproduction

`README.md:30–35`:

```markdown
You can modify your **razzle** shortcut (or execute the command manually inside `C:\NT`) to include (or remove) additional arguments:

- `free`: Build 'free' bits (production, omitting it will generate 'checked' bits).
- `CkhKernel`: Build 'checked' (testing) kernel/hal/ntdll when building 'free' bits.
- `no_opts`: Disable binary optimization (useful for debugging, but will likely fail a full build since some code can't be built without optimization).
- `verbose`: Enable verbose execution of the build process.
```

`tools/razzle.cmd:90–98`:

```bat
if "%1" == "-help" goto Usage
if "%1" == "/help" goto Usage

if /I "%1" == "Amd64" set _ArgAmd64=true&goto ArgOk
if /I "%1" == "Binaries_dir" set _ArgBinDir=%2&shift&goto ArgOK
if /I "%1" == "CheckDepots" set _ArgCheckDepots=true&goto ArgOK
if /I "%1" == "ChkKernel" set _ArgChkKrnl=true&goto ArgOK
if /I "%1" == "Coverage" echo coverage parameter is no longer supported&goto Usage
if /I "%1" == "DotNet" set _ArgDotnet=true&goto ArgOK
```

`tools/razzle.cmd:724–733`:

```bat
echo                    if on x86 and amd64 defined, build for amd64
echo                    if on x86 and amd64 undefined build for ia64
echo        PocketPC - Build for ARM PocketPC target
echo       Emulation - Build PocketPC emulation target
echo            free - Build free bits (default is to build checked)
echo       chkkernel - Checked kernel/hal/ntdll (use with 'free')
echo          no_opt - disable compiler optimizations
echo       mui_magic - generate language neutral build
echo     no_binaries - disable creation of the binaries^<sepchar^>^<arch^>^<buildtype^> dir.
echo    binaries_dir - must specify ^<basepath^> immediately after this switch.
```

`agents/build-and-release.md:28–35`:

```markdown
C:\NT\tools\postbuild.cmd
```

These are **historic instructions**, not a test of this checkout. Razzle's options are parsed in [`tools/razzle.cmd`](../tools/razzle.cmd). `free` selects the free build (omitting it selects checked); `binaries_dir` changes the output location; architecture selection and tool paths vary. Its spelling for the mixed checked-kernel switch is **`ChkKernel`** in the script, while the root README says `CkhKernel`; consult the script rather than silently relying on the README. `offline` sets `BUILD_OFFLINE`; it is not a substitute for missing source/tool dependencies. Razzle is designed for a clean `cmd` session, not a Unix shell or repeated nested invocation.

A local targeted Windows build can start in a component folder with its required environment and `build` command, but project dependencies/publication must be available. `build /cZP` is the README's clean rebuild command; `build /ZP` its incremental command. Avoid claiming those flags will compile an arbitrary isolated directory. Outputs/obj dirs and staged binaries (`_NTTREE`) are **generated**, not source changes; inspect [`tools/razzle.cmd`](../tools/razzle.cmd) for their actual paths on the chosen host/architecture.

## Phases and artifacts
```

Static command-parser trace: `if /I "%1" == "ChkKernel" set _ArgChkKrnl=true` and usage output both use `chkkernel`. The README lists `CkhKernel`, while the agent guide already corrects it. Expected: README and razzle agree, and the recommended shortcut uses a supported flag. This is a build-documentation defect rather than opinion; it contradicts the exact script users are told to open.

## Root cause

The README change copied the switch with transposed characters.

## Impact and severity

**Low** — Build documentation.

## Recommended fix

Replace `CkhKernel` with `ChkKernel` and add a short verification command or cross-reference to razzle.cmd usage.

## Acceptance criteria

- [ ] README uses `ChkKernel` in the razzle shortcut/options table.
- [ ] Search for `CkhKernel` returns no remaining occurrences.
- [ ] A documentation/link check passes after the edit.

## Verification limitations

No runtime test needed. This is confirmed from the script parser and usage text; a real Windows cmd session was not executed.

## Deduplication

Checked all available open/closed issue records, PRs #1/#2, their issue comments, review comments and reviews on 2026-10-16. No matching defect report found. PR #2 describes branding as a feature, not these failures. Discussions are disabled.
