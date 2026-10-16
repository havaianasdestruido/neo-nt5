# build: fdisk.dlg loses CONTROL fields after #endif

Status: **not published — repository Issues disabled**. Local finding A02.

## Summary

The first About-dialog CONTROL declaration is malformed in both branding modes, blocking resource compilation of windisk.

## Evidence and reproduction

`base/fs/utils/fdisk/fdisk.dlg:6–18`:

```rc
IDD_ABOUT DIALOG LOADONCALL MOVEABLE DISCARDABLE 25,23,184,78
FONT 8,"MS Shell Dlg"
CAPTION "About Disk Administrator"
STYLE WS_BORDER | DS_MODALFRAME | WS_CAPTION | WS_DLGFRAME | WS_POPUP | WS_SYSMENU
BEGIN
    #if NEONT_BRANDING
    CONTROL "NEONT"
#else
    CONTROL "Microsoft Windows NT"
#endif,-1,"static",SS_CENTER | WS_GROUP | WS_CHILD,0,5 ,184,8
    CONTROL "Disk Administrator",-1,"static",SS_CENTER | WS_GROUP | WS_CHILD,0,15,184,8
    CONTROL "Version VERSION"     ,-1,"Static",SS_CENTER | WS_GROUP | WS_CHILD,0,34,184,8
    CONTROL "Copyright \251 1991 Microsoft Corp.",-1,"static",SS_CENTER | WS_GROUP | WS_CHILD,0,47,184,9
```

`base/fs/utils/fdisk/sources:1–3`:

```makefile
TARGETNAME=windisk
TARGETPATH=obj
TARGETTYPE=PROGRAM
```

Run `python3 agents/audit_reproduce.py` from the checkout. GCC preprocessing with `NEONT_BRANDING=0` and `=1` reports `extra tokens at end of #endif directive`; each emitted first CONTROL line contains only its caption and lacks ID, class, styles and geometry. `fdisk.rc:198` includes this file. Expected: a complete CONTROL declaration in either mode.

## Root cause

The common suffix was appended to the preprocessor directive itself (`#endif,-1,...`), which is not resource content.

## Impact and severity

**Medium** — Disk Administrator resources.

## Recommended fix

Place a complete CONTROL declaration in each conditional branch, or conditionally define only a caption macro and use one full CONTROL statement.

## Acceptance criteria

- [ ] Preprocessing both modes retains control ID, class, style and geometry.
- [ ] The target resource compiles with the supported Windows RC toolchain in both modes.

## Verification limitations

No Windows build, installed OS, or original Microsoft compiler/resource compiler is available. Extracted-code results do not establish a complete product build or boot result. GNU preprocessing demonstrates the lost fields; an actual RC diagnostic was not collected.

## Deduplication

Checked all available open/closed issue records, PRs #1/#2, their issue comments, review comments and reviews on 2026-10-16. No matching defect report found. PR #2 describes branding as a feature, not these failures. Discussions are disabled.
