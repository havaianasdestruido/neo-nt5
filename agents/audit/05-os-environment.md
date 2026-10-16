# bug: default OS=NEONT breaks existing Windows_NT batch branches

Status: **not published — repository Issues disabled**. Local finding A05.

## Summary

Branding changes a machine-consumed OS environment discriminator, causing checked-in NT batch wrappers to select their non-NT paths.

## Evidence and reproduction

`base/subsys/sm/server/sminit.c:1562–1577`:

```c
        if (ValueData == NULL) {
#if NEONT_BRANDING
            ValueData = L"NEONT";
#else
            ValueData = L"Windows_NT";
#endif
        }

        RtlInitUnicodeString( &ValueName, L"OS" );
        Status = NtSetValueKey( Key,
                                &ValueName,
                                0,
                                REG_SZ,
                                ValueData,
                                (wcslen( ValueData ) + 1) * sizeof( WCHAR )
                              );
```

`tools/x86/perl/bin/pl2bat.bat:1–10`:

```bat
@rem = '--*-Perl-*--
@echo off
if "%OS%" == "Windows_NT" goto WinNT
perl -x -S "%0" %1 %2 %3 %4 %5 %6 %7 %8 %9
goto endofperl
:WinNT
perl -x -S "%0" %*
if NOT "%COMSPEC%" == "%SystemRoot%\system32\cmd.exe" goto endofperl
if %errorlevel% == 9009 echo You do not have Perl in your PATH.
goto endofperl
```

`inetcore/outlookexpress/prop.bat:1–8`:

```bat
@echo off

::
:: First we must test the OS.
:: NT provides command line extensions we need
::
if not "%OS%"=="Windows_NT" goto e_badplt

```

Static producer/consumer trace: default NEONT_BRANDING is 1 (`sminit.c:39–41`), producing `OS=NEONT`; the batch comparisons shown require `Windows_NT`. The Perl wrapper then passes only `%1` through `%9` instead of `%*`; Outlook Express propagation immediately takes `e_badplt`. Expected: branding must not invalidate OS capability detection. This is independent of A03: it remains after the pointer is initialized.

## Root cause

A stable compatibility token was treated as a display brand. Consumers use it as a Windows NT platform contract.

## Impact and severity

**Medium** — OS environment / tool compatibility.

## Recommended fix

Keep OS=Windows_NT independently of branding. Expose display branding through a separate variable/value instead of changing this discriminator.

## Acceptance criteria

- [ ] Both branding build modes preserve the Windows_NT environment discriminator.
- [ ] With more than nine arguments the Perl batch wrapper selects the NT forwarding branch.
- [ ] Checked-in OS-gated batch scripts do not reject the branded OS.

## Verification limitations

No Windows build, installed OS, or original Microsoft compiler/resource compiler is available. Extracted-code results do not establish a complete product build or boot result. Branch outcomes are confirmed from literal producer/consumer values; cmd.exe was not executed.

## Deduplication

Checked all available open/closed issue records, PRs #1/#2, their issue comments, review comments and reviews on 2026-10-16. No matching defect report found. PR #2 describes branding as a feature, not these failures. Discussions are disabled.
