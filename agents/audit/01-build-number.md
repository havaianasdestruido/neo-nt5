# build: NEONT version-header comment breaks genbldno.pl

Status: **not published — repository Issues disabled**. Local finding A01.

## Summary

The documented build-number target fails against the checked-in version header instead of generating build metadata.

## Evidence and reproduction

`published/sdk/inc/ntverp.h:26–32`:

```c
/* NEONT branding toggle: default enabled (NEONT). Define NEONT_BRANDING=0 for official branding. */
#ifndef NEONT_BRANDING
#define NEONT_BRANDING 1
#endif

#define VER_PRODUCTBUILD            /* NEONT */   2600
#define VER_PRODUCTBUILD_QFE        1106
```

`tools/genbldno.pl:74–82`:

```perl
         my( $ThisLine );
         # read through the file
         while ( $ThisLine = <$fh> ) {
            # see if this is the build number defining line
            if ( $ThisLine =~ /#define VER_PRODUCTBUILD\s*\/\* NT \*\/\s*(\d*)/ ) {
               # $1 is now the build number
               undef( $fh );
               return( $1 );
            }
```

`makefil0:30–37`:

```makefile
set_buildnum:
    @perl $(RAZZLETOOLPATH)\genbldno.pl
    @echo BuildNumber:
    @type $(BASEDIR)\__bldnum__
    binplace $(BASEDIR)\__bldnum__
    @echo QfeNumber:
    @type $(BASEDIR)\__qfenum__
    binplace $(BASEDIR)\__qfenum__
```

Run `python3 agents/audit_reproduce.py` from the checkout. The probe runs the unchanged Perl script against an exact-byte copy of the published header. On Linux the fixture filename intentionally contains Windows backslashes, allowing the original script to open it without patching. Actual output: `Failed to find a build number ... Failed to generate build number, exiting ...`; exit 1. Expected: exit 0 and `BUILDNUMBER=2600`.

## Root cause

The parser requires literal `/* NT */`, but PR #2 changed this machine-parsed marker to `/* NEONT */` in public and published headers.

## Impact and severity

**High** — Build/versioning.

## Recommended fix

Restore the compatible marker in both headers or parse the macro value without depending on a branding comment. Add fixtures covering both comment spellings and whitespace.

## Acceptance criteria

- [ ] Unchanged documented set_buildnum flow obtains build 2600 and QFE 1106.
- [ ] Parser tests cover supported header spellings and missing/malformed macros.

## Verification limitations

No Windows build, installed OS, or original Microsoft compiler/resource compiler is available. Extracted-code results do not establish a complete product build or boot result.

## Deduplication

Checked all available open/closed issue records, PRs #1/#2, their issue comments, review comments and reviews on 2026-10-16. No matching defect report found. PR #2 describes branding as a feature, not these failures. Discussions are disabled.
