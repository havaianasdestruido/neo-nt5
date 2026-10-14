# `shell/` — directory and build-definition inventory

**906 tracked directories; 526 directories with `sources`.**
Read the [explanation of `shell/`](../components/shell.md),
the [catalog key](README.md), or the [agent guide](../README.md).
This is a literal inventory, not a resolved build graph or a claim that every
directory is shipped. Paths and metadata reflect tracked files at generation time.

## `shell/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [shell](../../shell) | 8 | [shell/dirs](../../shell/dirs) | — | — |

## `shell/applets/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [shell/applets](../../shell/applets) | 1 | [shell/applets/dirs](../../shell/applets/dirs) | — | — |
| [shell/applets/autorun](../../shell/applets/autorun) | 16 | [shell/applets/autorun/dirs](../../shell/applets/autorun/dirs) | — | — |
| [shell/applets/autorun/bla](../../shell/applets/autorun/bla) | 2 | [shell/applets/autorun/bla/sources](../../shell/applets/autorun/bla/sources), [shell/applets/autorun/bla/makefile](../../shell/applets/autorun/bla/makefile) | — | — |
| [shell/applets/autorun/dtc](../../shell/applets/autorun/dtc) | 2 | [shell/applets/autorun/dtc/sources](../../shell/applets/autorun/dtc/sources), [shell/applets/autorun/dtc/makefile](../../shell/applets/autorun/dtc/makefile) | — | — |
| [shell/applets/autorun/ent](../../shell/applets/autorun/ent) | 2 | [shell/applets/autorun/ent/sources](../../shell/applets/autorun/ent/sources), [shell/applets/autorun/ent/makefile](../../shell/applets/autorun/ent/makefile) | — | — |
| [shell/applets/autorun/per](../../shell/applets/autorun/per) | 2 | [shell/applets/autorun/per/sources](../../shell/applets/autorun/per/sources), [shell/applets/autorun/per/makefile](../../shell/applets/autorun/per/makefile) | — | — |
| [shell/applets/autorun/pro](../../shell/applets/autorun/pro) | 2 | [shell/applets/autorun/pro/sources](../../shell/applets/autorun/pro/sources), [shell/applets/autorun/pro/makefile](../../shell/applets/autorun/pro/makefile) | — | — |
| [shell/applets/autorun/res](../../shell/applets/autorun/res) | 43 | — | — | — |
| [shell/applets/autorun/sbs](../../shell/applets/autorun/sbs) | 2 | [shell/applets/autorun/sbs/sources](../../shell/applets/autorun/sbs/sources), [shell/applets/autorun/sbs/makefile](../../shell/applets/autorun/sbs/makefile) | — | — |
| [shell/applets/autorun/srv](../../shell/applets/autorun/srv) | 2 | [shell/applets/autorun/srv/sources](../../shell/applets/autorun/srv/sources), [shell/applets/autorun/srv/makefile](../../shell/applets/autorun/srv/makefile) | — | — |
| [shell/applets/cleanup](../../shell/applets/cleanup) | 1 | [shell/applets/cleanup/dirs](../../shell/applets/cleanup/dirs) | — | — |
| [shell/applets/cleanup/cleanmgr](../../shell/applets/cleanup/cleanmgr) | 31 | [shell/applets/cleanup/cleanmgr/dirs](../../shell/applets/cleanup/cleanmgr/dirs) | — | — |
| [shell/applets/cleanup/cleanmgr/win95](../../shell/applets/cleanup/cleanmgr/win95) | 2 | [shell/applets/cleanup/cleanmgr/win95/sources](../../shell/applets/cleanup/cleanmgr/win95/sources), [shell/applets/cleanup/cleanmgr/win95/makefile](../../shell/applets/cleanup/cleanmgr/win95/makefile) | — | — |
| [shell/applets/cleanup/cleanmgr/winnt](../../shell/applets/cleanup/cleanmgr/winnt) | 2 | [shell/applets/cleanup/cleanmgr/winnt/sources](../../shell/applets/cleanup/cleanmgr/winnt/sources), [shell/applets/cleanup/cleanmgr/winnt/makefile](../../shell/applets/cleanup/cleanmgr/winnt/makefile) | — | — |
| [shell/applets/cleanup/dataclen](../../shell/applets/cleanup/dataclen) | 20 | [shell/applets/cleanup/dataclen/dirs](../../shell/applets/cleanup/dataclen/dirs) | — | — |
| [shell/applets/cleanup/dataclen/win95](../../shell/applets/cleanup/dataclen/win95) | 3 | [shell/applets/cleanup/dataclen/win95/sources](../../shell/applets/cleanup/dataclen/win95/sources), [shell/applets/cleanup/dataclen/win95/makefile](../../shell/applets/cleanup/dataclen/win95/makefile) | — | — |
| [shell/applets/cleanup/dataclen/winnt](../../shell/applets/cleanup/dataclen/winnt) | 3 | [shell/applets/cleanup/dataclen/winnt/sources](../../shell/applets/cleanup/dataclen/winnt/sources), [shell/applets/cleanup/dataclen/winnt/makefile](../../shell/applets/cleanup/dataclen/winnt/makefile) | — | — |
| [shell/applets/cleanup/fldrclnr](../../shell/applets/cleanup/fldrclnr) | 18 | [shell/applets/cleanup/fldrclnr/sources](../../shell/applets/cleanup/fldrclnr/sources), [shell/applets/cleanup/fldrclnr/makefile](../../shell/applets/cleanup/fldrclnr/makefile) | `fldrclnr` | `DYNLINK` |
| [shell/applets/control](../../shell/applets/control) | 10 | [shell/applets/control/sources](../../shell/applets/control/sources), [shell/applets/control/makefile](../../shell/applets/control/makefile) | `ctrllib` | `LIBRARY` |
| [shell/applets/grpconv](../../shell/applets/grpconv) | 17 | [shell/applets/grpconv/dirs](../../shell/applets/grpconv/dirs) | — | — |
| [shell/applets/grpconv/winnt](../../shell/applets/grpconv/winnt) | 2 | [shell/applets/grpconv/winnt/sources](../../shell/applets/grpconv/winnt/sources), [shell/applets/grpconv/winnt/makefile](../../shell/applets/grpconv/winnt/makefile) | — | — |
| [shell/applets/taskmgr](../../shell/applets/taskmgr) | 43 | [shell/applets/taskmgr/sources](../../shell/applets/taskmgr/sources), [shell/applets/taskmgr/makefile](../../shell/applets/taskmgr/makefile) | `taskmgr` | `PROGRAM` |
| [shell/applets/tourstart](../../shell/applets/tourstart) | 9 | [shell/applets/tourstart/sources](../../shell/applets/tourstart/sources), [shell/applets/tourstart/makefile](../../shell/applets/tourstart/makefile) | `tourstrt` | `PROGRAM` |
| [shell/applets/upgrade](../../shell/applets/upgrade) | 11 | [shell/applets/upgrade/sources](../../shell/applets/upgrade/sources), [shell/applets/upgrade/makefile](../../shell/applets/upgrade/makefile) | `upgrade` | `PROGRAM` |
| [shell/applets/upgrade/res](../../shell/applets/upgrade/res) | 36 | — | — | — |

## `shell/browseinfo/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [shell/browseinfo](../../shell/browseinfo) | 4 | [shell/browseinfo/sources](../../shell/browseinfo/sources), [shell/browseinfo/makefile](../../shell/browseinfo/makefile) | — | `NOTARGET` |
| [shell/browseinfo/tools](../../shell/browseinfo/tools) | 0 | — | — | — |
| [shell/browseinfo/tools/x86](../../shell/browseinfo/tools/x86) | 1 | — | — | — |

## `shell/browseui/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [shell/browseui](../../shell/browseui) | 188 | [shell/browseui/dirs](../../shell/browseui/dirs), [shell/browseui/makefile](../../shell/browseui/makefile) | — | — |
| [shell/browseui/dll](../../shell/browseui/dll) | 7 | [shell/browseui/dll/sources](../../shell/browseui/dll/sources), [shell/browseui/dll/makefile](../../shell/browseui/dll/makefile) | — | — |
| [shell/browseui/emclient](../../shell/browseui/emclient) | 14 | [shell/browseui/emclient/sources](../../shell/browseui/emclient/sources), [shell/browseui/emclient/makefile](../../shell/browseui/emclient/makefile) | `emclient` | `LIBRARY` |
| [shell/browseui/legacy](../../shell/browseui/legacy) | 43 | [shell/browseui/legacy/sources](../../shell/browseui/legacy/sources), [shell/browseui/legacy/makefile](../../shell/browseui/legacy/makefile) | `legacy` | `LIBRARY` |
| [shell/browseui/mediabar](../../shell/browseui/mediabar) | 51 | — | — | — |
| [shell/browseui/nt5api](../../shell/browseui/nt5api) | 3 | [shell/browseui/nt5api/sources](../../shell/browseui/nt5api/sources), [shell/browseui/nt5api/makefile](../../shell/browseui/nt5api/makefile) | — | — |
| [shell/browseui/resdll](../../shell/browseui/resdll) | 3 | [shell/browseui/resdll/sources](../../shell/browseui/resdll/sources), [shell/browseui/resdll/makefile](../../shell/browseui/resdll/makefile) | `browseLC` | `DYNLINK` |
| [shell/browseui/srcc](../../shell/browseui/srcc) | 3 | [shell/browseui/srcc/sources](../../shell/browseui/srcc/sources), [shell/browseui/srcc/makefile](../../shell/browseui/srcc/makefile) | `srcc` | `LIBRARY` |
| [shell/browseui/srccpp](../../shell/browseui/srccpp) | 3 | [shell/browseui/srccpp/sources](../../shell/browseui/srccpp/sources), [shell/browseui/srccpp/makefile](../../shell/browseui/srccpp/makefile) | `srccpp` | `LIBRARY` |
| [shell/browseui/tools](../../shell/browseui/tools) | 4 | [shell/browseui/tools/sources](../../shell/browseui/tools/sources), [shell/browseui/tools/makefile](../../shell/browseui/tools/makefile) | — | `PROGRAM` |

## `shell/comctl32/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [shell/comctl32](../../shell/comctl32) | 2 | [shell/comctl32/dirs](../../shell/comctl32/dirs) | — | — |
| [shell/comctl32/policy_6.0](../../shell/comctl32/policy_6.0) | 1 | [shell/comctl32/policy_6.0/dirs](../../shell/comctl32/policy_6.0/dirs) | — | — |
| [shell/comctl32/policy_6.0/xpsp1](../../shell/comctl32/policy_6.0/xpsp1) | 3 | [shell/comctl32/policy_6.0/xpsp1/dirs](../../shell/comctl32/policy_6.0/xpsp1/dirs) | — | — |
| [shell/comctl32/policy_6.0/xpsp1/regular](../../shell/comctl32/policy_6.0/xpsp1/regular) | 2 | [shell/comctl32/policy_6.0/xpsp1/regular/sources](../../shell/comctl32/policy_6.0/xpsp1/regular/sources), [shell/comctl32/policy_6.0/xpsp1/regular/makefile](../../shell/comctl32/policy_6.0/xpsp1/regular/makefile) | — | — |
| [shell/comctl32/policy_6.0/xpsp1/wow6432](../../shell/comctl32/policy_6.0/xpsp1/wow6432) | 2 | [shell/comctl32/policy_6.0/xpsp1/wow6432/sources](../../shell/comctl32/policy_6.0/xpsp1/wow6432/sources), [shell/comctl32/policy_6.0/xpsp1/wow6432/makefile](../../shell/comctl32/policy_6.0/xpsp1/wow6432/makefile) | — | — |
| [shell/comctl32/v5](../../shell/comctl32/v5) | 136 | [shell/comctl32/v5/dirs](../../shell/comctl32/v5/dirs), [shell/comctl32/v5/makefile](../../shell/comctl32/v5/makefile) | — | — |
| [shell/comctl32/v5/loc](../../shell/comctl32/v5/loc) | 32 | — | — | — |
| [shell/comctl32/v5/loc/i386](../../shell/comctl32/v5/loc/i386) | 1 | — | — | — |
| [shell/comctl32/v5/multilingual](../../shell/comctl32/v5/multilingual) | 5 | [shell/comctl32/v5/multilingual/sources](../../shell/comctl32/v5/multilingual/sources), [shell/comctl32/v5/multilingual/makefile](../../shell/comctl32/v5/multilingual/makefile) | `comctl32` | `DYNLINK` |
| [shell/comctl32/v5/nt5api](../../shell/comctl32/v5/nt5api) | 2 | [shell/comctl32/v5/nt5api/sources](../../shell/comctl32/v5/nt5api/sources), [shell/comctl32/v5/nt5api/makefile](../../shell/comctl32/v5/nt5api/makefile) | `apithk` | `LIBRARY` |
| [shell/comctl32/v5/ntc](../../shell/comctl32/v5/ntc) | 2 | [shell/comctl32/v5/ntc/sources](../../shell/comctl32/v5/ntc/sources), [shell/comctl32/v5/ntc/makefile](../../shell/comctl32/v5/ntc/makefile) | `srcc` | `LIBRARY` |
| [shell/comctl32/v5/ntcpp](../../shell/comctl32/v5/ntcpp) | 2 | [shell/comctl32/v5/ntcpp/sources](../../shell/comctl32/v5/ntcpp/sources), [shell/comctl32/v5/ntcpp/makefile](../../shell/comctl32/v5/ntcpp/makefile) | `srccpp` | `LIBRARY` |
| [shell/comctl32/v5/redist](../../shell/comctl32/v5/redist) | 7 | — | — | — |
| [shell/comctl32/v5/redist/ar](../../shell/comctl32/v5/redist/ar) | 2 | — | — | — |
| [shell/comctl32/v5/redist/br](../../shell/comctl32/v5/redist/br) | 2 | — | — | — |
| [shell/comctl32/v5/redist/ca](../../shell/comctl32/v5/redist/ca) | 2 | — | — | — |
| [shell/comctl32/v5/redist/cn](../../shell/comctl32/v5/redist/cn) | 2 | — | — | — |
| [shell/comctl32/v5/redist/cs](../../shell/comctl32/v5/redist/cs) | 2 | — | — | — |
| [shell/comctl32/v5/redist/da](../../shell/comctl32/v5/redist/da) | 2 | — | — | — |
| [shell/comctl32/v5/redist/de](../../shell/comctl32/v5/redist/de) | 2 | — | — | — |
| [shell/comctl32/v5/redist/el](../../shell/comctl32/v5/redist/el) | 2 | — | — | — |
| [shell/comctl32/v5/redist/en](../../shell/comctl32/v5/redist/en) | 2 | — | — | — |
| [shell/comctl32/v5/redist/es](../../shell/comctl32/v5/redist/es) | 2 | — | — | — |
| [shell/comctl32/v5/redist/eu](../../shell/comctl32/v5/redist/eu) | 2 | — | — | — |
| [shell/comctl32/v5/redist/fi](../../shell/comctl32/v5/redist/fi) | 2 | — | — | — |
| [shell/comctl32/v5/redist/fr](../../shell/comctl32/v5/redist/fr) | 2 | — | — | — |
| [shell/comctl32/v5/redist/he](../../shell/comctl32/v5/redist/he) | 2 | — | — | — |
| [shell/comctl32/v5/redist/hu](../../shell/comctl32/v5/redist/hu) | 2 | — | — | — |
| [shell/comctl32/v5/redist/it](../../shell/comctl32/v5/redist/it) | 2 | — | — | — |
| [shell/comctl32/v5/redist/ja](../../shell/comctl32/v5/redist/ja) | 2 | — | — | — |
| [shell/comctl32/v5/redist/ko](../../shell/comctl32/v5/redist/ko) | 2 | — | — | — |
| [shell/comctl32/v5/redist/nl](../../shell/comctl32/v5/redist/nl) | 2 | — | — | — |
| [shell/comctl32/v5/redist/no](../../shell/comctl32/v5/redist/no) | 2 | — | — | — |
| [shell/comctl32/v5/redist/pl](../../shell/comctl32/v5/redist/pl) | 2 | — | — | — |
| [shell/comctl32/v5/redist/pt](../../shell/comctl32/v5/redist/pt) | 2 | — | — | — |
| [shell/comctl32/v5/redist/ru](../../shell/comctl32/v5/redist/ru) | 2 | — | — | — |
| [shell/comctl32/v5/redist/sk](../../shell/comctl32/v5/redist/sk) | 2 | — | — | — |
| [shell/comctl32/v5/redist/sl](../../shell/comctl32/v5/redist/sl) | 2 | — | — | — |
| [shell/comctl32/v5/redist/sv](../../shell/comctl32/v5/redist/sv) | 2 | — | — | — |
| [shell/comctl32/v5/redist/tr](../../shell/comctl32/v5/redist/tr) | 2 | — | — | — |
| [shell/comctl32/v5/redist/tw](../../shell/comctl32/v5/redist/tw) | 2 | — | — | — |
| [shell/comctl32/v5/redist/vi](../../shell/comctl32/v5/redist/vi) | 2 | — | — | — |
| [shell/comctl32/v5/usonly](../../shell/comctl32/v5/usonly) | 3 | [shell/comctl32/v5/usonly/sources](../../shell/comctl32/v5/usonly/sources), [shell/comctl32/v5/usonly/makefile](../../shell/comctl32/v5/usonly/makefile) | `comctlv5` | `DYNLINK` |
| [shell/comctl32/v6](../../shell/comctl32/v6) | 158 | [shell/comctl32/v6/dirs](../../shell/comctl32/v6/dirs), [shell/comctl32/v6/makefile](../../shell/comctl32/v6/makefile) | — | — |
| [shell/comctl32/v6/loc](../../shell/comctl32/v6/loc) | 31 | — | — | — |
| [shell/comctl32/v6/loc/i386](../../shell/comctl32/v6/loc/i386) | 1 | — | — | — |
| [shell/comctl32/v6/multilingual](../../shell/comctl32/v6/multilingual) | 3 | [shell/comctl32/v6/multilingual/sources](../../shell/comctl32/v6/multilingual/sources), [shell/comctl32/v6/multilingual/makefile](../../shell/comctl32/v6/multilingual/makefile) | `comctl32` | `DYNLINK` |
| [shell/comctl32/v6/ntc](../../shell/comctl32/v6/ntc) | 2 | [shell/comctl32/v6/ntc/sources](../../shell/comctl32/v6/ntc/sources), [shell/comctl32/v6/ntc/makefile](../../shell/comctl32/v6/ntc/makefile) | — | — |
| [shell/comctl32/v6/ntc6432](../../shell/comctl32/v6/ntc6432) | 2 | [shell/comctl32/v6/ntc6432/sources](../../shell/comctl32/v6/ntc6432/sources), [shell/comctl32/v6/ntc6432/makefile](../../shell/comctl32/v6/ntc6432/makefile) | — | — |
| [shell/comctl32/v6/ntcpp](../../shell/comctl32/v6/ntcpp) | 2 | [shell/comctl32/v6/ntcpp/sources](../../shell/comctl32/v6/ntcpp/sources), [shell/comctl32/v6/ntcpp/makefile](../../shell/comctl32/v6/ntcpp/makefile) | `srccpp` | `LIBRARY` |
| [shell/comctl32/v6/usonly](../../shell/comctl32/v6/usonly) | 3 | [shell/comctl32/v6/usonly/sources](../../shell/comctl32/v6/usonly/sources), [shell/comctl32/v6/usonly/makefile](../../shell/comctl32/v6/usonly/makefile) | `comctlv6` | `DYNLINK` |
| [shell/comctl32/v6/wow6432](../../shell/comctl32/v6/wow6432) | 3 | [shell/comctl32/v6/wow6432/sources](../../shell/comctl32/v6/wow6432/sources), [shell/comctl32/v6/wow6432/makefile](../../shell/comctl32/v6/wow6432/makefile) | `comctl32` | `DYNLINK` |
| [shell/comctl32/win95](../../shell/comctl32/win95) | 0 | — | — | — |
| [shell/comctl32/win95/i386](../../shell/comctl32/win95/i386) | 2 | — | — | — |

## `shell/comdlg32/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [shell/comdlg32](../../shell/comdlg32) | 53 | [shell/comdlg32/dirs](../../shell/comdlg32/dirs) | — | — |
| [shell/comdlg32/ntcpp](../../shell/comdlg32/ntcpp) | 2 | [shell/comdlg32/ntcpp/sources](../../shell/comdlg32/ntcpp/sources), [shell/comdlg32/ntcpp/makefile](../../shell/comdlg32/ntcpp/makefile) | — | — |
| [shell/comdlg32/w95cpp](../../shell/comdlg32/w95cpp) | 2 | [shell/comdlg32/w95cpp/sources](../../shell/comdlg32/w95cpp/sources), [shell/comdlg32/w95cpp/makefile](../../shell/comdlg32/w95cpp/makefile) | — | — |
| [shell/comdlg32/win95](../../shell/comdlg32/win95) | 2 | [shell/comdlg32/win95/sources](../../shell/comdlg32/win95/sources), [shell/comdlg32/win95/makefile](../../shell/comdlg32/win95/makefile) | — | — |
| [shell/comdlg32/win95/i386](../../shell/comdlg32/win95/i386) | 2 | — | — | — |
| [shell/comdlg32/winnt](../../shell/comdlg32/winnt) | 2 | [shell/comdlg32/winnt/sources](../../shell/comdlg32/winnt/sources), [shell/comdlg32/winnt/makefile](../../shell/comdlg32/winnt/makefile) | — | — |

## `shell/cpls/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [shell/cpls](../../shell/cpls) | 2 | [shell/cpls/dirs](../../shell/cpls/dirs) | — | — |
| [shell/cpls/appwzdui](../../shell/cpls/appwzdui) | 118 | [shell/cpls/appwzdui/dirs](../../shell/cpls/appwzdui/dirs) | — | — |
| [shell/cpls/appwzdui/html](../../shell/cpls/appwzdui/html) | 24 | — | — | — |
| [shell/cpls/appwzdui/nt4c](../../shell/cpls/appwzdui/nt4c) | 3 | [shell/cpls/appwzdui/nt4c/sources](../../shell/cpls/appwzdui/nt4c/sources), [shell/cpls/appwzdui/nt4c/makefile](../../shell/cpls/appwzdui/nt4c/makefile) | `srcc` | `LIBRARY` |
| [shell/cpls/appwzdui/nt5api](../../shell/cpls/appwzdui/nt5api) | 2 | [shell/cpls/appwzdui/nt5api/sources](../../shell/cpls/appwzdui/nt5api/sources), [shell/cpls/appwzdui/nt5api/makefile](../../shell/cpls/appwzdui/nt5api/makefile) | — | — |
| [shell/cpls/appwzdui/ntc](../../shell/cpls/appwzdui/ntc) | 3 | [shell/cpls/appwzdui/ntc/sources](../../shell/cpls/appwzdui/ntc/sources), [shell/cpls/appwzdui/ntc/makefile](../../shell/cpls/appwzdui/ntc/makefile) | `srcc` | `LIBRARY` |
| [shell/cpls/appwzdui/srcc](../../shell/cpls/appwzdui/srcc) | 2 | [shell/cpls/appwzdui/srcc/sources](../../shell/cpls/appwzdui/srcc/sources), [shell/cpls/appwzdui/srcc/makefile](../../shell/cpls/appwzdui/srcc/makefile) | `srcc` | `LIBRARY` |
| [shell/cpls/appwzdui/w5api](../../shell/cpls/appwzdui/w5api) | 2 | [shell/cpls/appwzdui/w5api/sources](../../shell/cpls/appwzdui/w5api/sources), [shell/cpls/appwzdui/w5api/makefile](../../shell/cpls/appwzdui/w5api/makefile) | — | — |
| [shell/cpls/appwzdui/w95c](../../shell/cpls/appwzdui/w95c) | 3 | [shell/cpls/appwzdui/w95c/sources](../../shell/cpls/appwzdui/w95c/sources), [shell/cpls/appwzdui/w95c/makefile](../../shell/cpls/appwzdui/w95c/makefile) | `srcc` | `LIBRARY` |
| [shell/cpls/appwzdui/win95](../../shell/cpls/appwzdui/win95) | 3 | [shell/cpls/appwzdui/win95/sources](../../shell/cpls/appwzdui/win95/sources), [shell/cpls/appwzdui/win95/makefile](../../shell/cpls/appwzdui/win95/makefile) | — | — |
| [shell/cpls/appwzdui/winnt](../../shell/cpls/appwzdui/winnt) | 3 | [shell/cpls/appwzdui/winnt/sources](../../shell/cpls/appwzdui/winnt/sources), [shell/cpls/appwzdui/winnt/makefile](../../shell/cpls/appwzdui/winnt/makefile) | — | — |
| [shell/cpls/appwzdui/winnt4](../../shell/cpls/appwzdui/winnt4) | 3 | [shell/cpls/appwzdui/winnt4/sources](../../shell/cpls/appwzdui/winnt4/sources), [shell/cpls/appwzdui/winnt4/makefile](../../shell/cpls/appwzdui/winnt4/makefile) | — | — |
| [shell/cpls/appwzdui/wnt4](../../shell/cpls/appwzdui/wnt4) | 3 | [shell/cpls/appwzdui/wnt4/sources](../../shell/cpls/appwzdui/wnt4/sources), [shell/cpls/appwzdui/wnt4/makefile](../../shell/cpls/appwzdui/wnt4/makefile) | — | — |
| [shell/cpls/common](../../shell/cpls/common) | 5 | — | — | — |
| [shell/cpls/deskadp](../../shell/cpls/deskadp) | 11 | [shell/cpls/deskadp/dirs](../../shell/cpls/deskadp/dirs) | — | — |
| [shell/cpls/deskadp/winnt](../../shell/cpls/deskadp/winnt) | 2 | [shell/cpls/deskadp/winnt/sources](../../shell/cpls/deskadp/winnt/sources), [shell/cpls/deskadp/winnt/makefile](../../shell/cpls/deskadp/winnt/makefile) | — | — |
| [shell/cpls/deskmon](../../shell/cpls/deskmon) | 11 | [shell/cpls/deskmon/dirs](../../shell/cpls/deskmon/dirs) | — | — |
| [shell/cpls/deskmon/winnt](../../shell/cpls/deskmon/winnt) | 2 | [shell/cpls/deskmon/winnt/sources](../../shell/cpls/deskmon/winnt/sources), [shell/cpls/deskmon/winnt/makefile](../../shell/cpls/deskmon/winnt/makefile) | — | — |
| [shell/cpls/desknt5](../../shell/cpls/desknt5) | 23 | [shell/cpls/desknt5/dirs](../../shell/cpls/desknt5/dirs) | — | — |
| [shell/cpls/desknt5/winnt](../../shell/cpls/desknt5/winnt) | 2 | [shell/cpls/desknt5/winnt/sources](../../shell/cpls/desknt5/winnt/sources), [shell/cpls/desknt5/winnt/makefile](../../shell/cpls/desknt5/winnt/makefile) | `desk` | — |
| [shell/cpls/deskpan](../../shell/cpls/deskpan) | 8 | [shell/cpls/deskpan/dirs](../../shell/cpls/deskpan/dirs) | — | — |
| [shell/cpls/deskpan/winnt](../../shell/cpls/deskpan/winnt) | 2 | [shell/cpls/deskpan/winnt/sources](../../shell/cpls/deskpan/winnt/sources), [shell/cpls/deskpan/winnt/makefile](../../shell/cpls/deskpan/winnt/makefile) | — | — |
| [shell/cpls/deskperf](../../shell/cpls/deskperf) | 11 | [shell/cpls/deskperf/dirs](../../shell/cpls/deskperf/dirs) | — | — |
| [shell/cpls/deskperf/regini](../../shell/cpls/deskperf/regini) | 1 | — | — | — |
| [shell/cpls/deskperf/winnt](../../shell/cpls/deskperf/winnt) | 2 | [shell/cpls/deskperf/winnt/sources](../../shell/cpls/deskperf/winnt/sources), [shell/cpls/deskperf/winnt/makefile](../../shell/cpls/deskperf/winnt/makefile) | — | — |
| [shell/cpls/inetcpl](../../shell/cpls/inetcpl) | 104 | [shell/cpls/inetcpl/dirs](../../shell/cpls/inetcpl/dirs) | — | — |
| [shell/cpls/inetcpl/dll](../../shell/cpls/inetcpl/dll) | 5 | [shell/cpls/inetcpl/dll/sources](../../shell/cpls/inetcpl/dll/sources), [shell/cpls/inetcpl/dll/makefile](../../shell/cpls/inetcpl/dll/makefile) | `inetcpl` | `DYNLINK` |
| [shell/cpls/inetcpl/ntapi](../../shell/cpls/inetcpl/ntapi) | 3 | [shell/cpls/inetcpl/ntapi/sources](../../shell/cpls/inetcpl/ntapi/sources), [shell/cpls/inetcpl/ntapi/makefile](../../shell/cpls/inetcpl/ntapi/makefile) | — | — |
| [shell/cpls/inetcpl/resdll](../../shell/cpls/inetcpl/resdll) | 2 | [shell/cpls/inetcpl/resdll/sources](../../shell/cpls/inetcpl/resdll/sources), [shell/cpls/inetcpl/resdll/makefile](../../shell/cpls/inetcpl/resdll/makefile) | `inetcplc` | `DYNLINK` |
| [shell/cpls/main](../../shell/cpls/main) | 46 | [shell/cpls/main/sources](../../shell/cpls/main/sources), [shell/cpls/main/makefile](../../shell/cpls/main/makefile) | `main` | `DYNLINK` |
| [shell/cpls/nusrmgr](../../shell/cpls/nusrmgr) | 21 | [shell/cpls/nusrmgr/sources](../../shell/cpls/nusrmgr/sources), [shell/cpls/nusrmgr/makefile](../../shell/cpls/nusrmgr/makefile) | `nusrmgr` | `DYNLINK` |
| [shell/cpls/nusrmgr/html](../../shell/cpls/nusrmgr/html) | 47 | — | — | — |
| [shell/cpls/nusrmgr/res](../../shell/cpls/nusrmgr/res) | 12 | — | — | — |
| [shell/cpls/plus](../../shell/cpls/plus) | 18 | [shell/cpls/plus/sources](../../shell/cpls/plus/sources), [shell/cpls/plus/makefile](../../shell/cpls/plus/makefile) | `plustab` | `DYNLINK` |
| [shell/cpls/plus/old_src](../../shell/cpls/plus/old_src) | 20 | [shell/cpls/plus/old_src/sources](../../shell/cpls/plus/old_src/sources), [shell/cpls/plus/old_src/makefile](../../shell/cpls/plus/old_src/makefile) | `plustab` | `DYNLINK` |
| [shell/cpls/poscpl](../../shell/cpls/poscpl) | 16 | [shell/cpls/poscpl/sources](../../shell/cpls/poscpl/sources), [shell/cpls/poscpl/makefile](../../shell/cpls/poscpl/makefile) | `poscpl` | `DYNLINK` |
| [shell/cpls/system](../../shell/cpls/system) | 57 | [shell/cpls/system/sources](../../shell/cpls/system/sources), [shell/cpls/system/makefile](../../shell/cpls/system/makefile) | `sysdm` | `DYNLINK` |
| [shell/cpls/system/ia64](../../shell/cpls/system/ia64) | 1 | [shell/cpls/system/ia64/sources](../../shell/cpls/system/ia64/sources) | — | — |
| [shell/cpls/utc](../../shell/cpls/utc) | 23 | [shell/cpls/utc/sources](../../shell/cpls/utc/sources), [shell/cpls/utc/makefile](../../shell/cpls/utc/makefile) | `timedate` | `DYNLINK` |
| [shell/cpls/vidupgrd](../../shell/cpls/vidupgrd) | 6 | [shell/cpls/vidupgrd/dirs](../../shell/cpls/vidupgrd/dirs) | — | — |
| [shell/cpls/vidupgrd/winnt](../../shell/cpls/vidupgrd/winnt) | 2 | [shell/cpls/vidupgrd/winnt/sources](../../shell/cpls/vidupgrd/winnt/sources), [shell/cpls/vidupgrd/winnt/makefile](../../shell/cpls/vidupgrd/winnt/makefile) | — | — |

## `shell/ddk/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [shell/ddk](../../shell/ddk) | 4 | [shell/ddk/sources](../../shell/ddk/sources), [shell/ddk/makefile](../../shell/ddk/makefile) | — | `NOTARGET` |

## `shell/docs/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [shell/docs](../../shell/docs) | 6 | — | — | — |

## `shell/drts/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [shell/drts](../../shell/drts) | 0 | — | — | — |
| [shell/drts/shdrt-sfstr](../../shell/drts/shdrt-sfstr) | 6 | [shell/drts/shdrt-sfstr/sources](../../shell/drts/shdrt-sfstr/sources), [shell/drts/shdrt-sfstr/makefile](../../shell/drts/shdrt-sfstr/makefile) | `shdrt-sfstr` | `DYNLINK` |
| [shell/drts/shdrt-shortcuts](../../shell/drts/shdrt-shortcuts) | 6 | [shell/drts/shdrt-shortcuts/sources](../../shell/drts/shdrt-shortcuts/sources), [shell/drts/shdrt-shortcuts/makefile](../../shell/drts/shdrt-shortcuts/makefile) | `SHDRT-SHORTCUTS` | `DYNLINK` |

## `shell/evtmon/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [shell/evtmon](../../shell/evtmon) | 0 | — | — | — |
| [shell/evtmon/inc](../../shell/evtmon/inc) | 16 | — | — | — |

## `shell/explorer/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [shell/explorer](../../shell/explorer) | 101 | [shell/explorer/dirs](../../shell/explorer/dirs), [shell/explorer/makefile](../../shell/explorer/makefile) | — | — |
| [shell/explorer/desktop2](../../shell/explorer/desktop2) | 46 | [shell/explorer/desktop2/sources](../../shell/explorer/desktop2/sources), [shell/explorer/desktop2/makefile](../../shell/explorer/desktop2/makefile) | `dv2host` | `LIBRARY` |
| [shell/explorer/tools](../../shell/explorer/tools) | 3 | [shell/explorer/tools/sources](../../shell/explorer/tools/sources), [shell/explorer/tools/makefile](../../shell/explorer/tools/makefile) | — | `PROGRAM` |
| [shell/explorer/win95](../../shell/explorer/win95) | 2 | [shell/explorer/win95/sources](../../shell/explorer/win95/sources), [shell/explorer/win95/makefile](../../shell/explorer/win95/makefile) | — | — |
| [shell/explorer/winnt](../../shell/explorer/winnt) | 2 | [shell/explorer/winnt/sources](../../shell/explorer/winnt/sources), [shell/explorer/winnt/makefile](../../shell/explorer/winnt/makefile) | — | — |

## `shell/ext/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [shell/ext](../../shell/ext) | 4 | [shell/ext/dirs](../../shell/ext/dirs), [shell/ext/makefile](../../shell/ext/makefile) | — | — |
| [shell/ext/audiodevice](../../shell/ext/audiodevice) | 19 | [shell/ext/audiodevice/sources](../../shell/ext/audiodevice/sources), [shell/ext/audiodevice/makefile](../../shell/ext/audiodevice/makefile) | `audiodevices` | `DYNLINK` |
| [shell/ext/autoimage](../../shell/ext/autoimage) | 1 | — | — | — |
| [shell/ext/biologon](../../shell/ext/biologon) | 6 | [shell/ext/biologon/sources](../../shell/ext/biologon/sources), [shell/ext/biologon/makefile](../../shell/ext/biologon/makefile) | `biologon` | `DYNLINK` |
| [shell/ext/brfcase](../../shell/ext/brfcase) | 1 | [shell/ext/brfcase/dirs](../../shell/ext/brfcase/dirs) | — | — |
| [shell/ext/brfcase/filesync](../../shell/ext/brfcase/filesync) | 1 | [shell/ext/brfcase/filesync/dirs](../../shell/ext/brfcase/filesync/dirs) | — | — |
| [shell/ext/brfcase/filesync/core](../../shell/ext/brfcase/filesync/core) | 87 | [shell/ext/brfcase/filesync/core/sources](../../shell/ext/brfcase/filesync/core/sources), [shell/ext/brfcase/filesync/core/makefile](../../shell/ext/brfcase/filesync/core/makefile) | `synceng` | `DYNLINK` |
| [shell/ext/brfcase/filesync/linkinfo](../../shell/ext/brfcase/filesync/linkinfo) | 21 | [shell/ext/brfcase/filesync/linkinfo/sources](../../shell/ext/brfcase/filesync/linkinfo/sources), [shell/ext/brfcase/filesync/linkinfo/makefile](../../shell/ext/brfcase/filesync/linkinfo/makefile) | `linkinfo` | `DYNLINK` |
| [shell/ext/brfcase/filesync/syncapp](../../shell/ext/brfcase/filesync/syncapp) | 8 | [shell/ext/brfcase/filesync/syncapp/sources](../../shell/ext/brfcase/filesync/syncapp/sources), [shell/ext/brfcase/filesync/syncapp/makefile](../../shell/ext/brfcase/filesync/syncapp/makefile) | `syncapp` | `LIBRARY` |
| [shell/ext/brfcase/filesync/syncui](../../shell/ext/brfcase/filesync/syncui) | 77 | [shell/ext/brfcase/filesync/syncui/sources](../../shell/ext/brfcase/filesync/syncui/sources), [shell/ext/brfcase/filesync/syncui/makefile](../../shell/ext/brfcase/filesync/syncui/makefile) | `syncui` | `DYNLINK` |
| [shell/ext/brfcase/inc](../../shell/ext/brfcase/inc) | 4 | — | — | — |
| [shell/ext/cabview](../../shell/ext/cabview) | 47 | [shell/ext/cabview/dirs](../../shell/ext/cabview/dirs) | — | — |
| [shell/ext/cabview/winnt](../../shell/ext/cabview/winnt) | 2 | [shell/ext/cabview/winnt/sources](../../shell/ext/cabview/winnt/sources), [shell/ext/cabview/winnt/makefile](../../shell/ext/cabview/winnt/makefile) | — | — |
| [shell/ext/cdfview](../../shell/ext/cdfview) | 58 | [shell/ext/cdfview/dirs](../../shell/ext/cdfview/dirs) | — | — |
| [shell/ext/cdfview/dll](../../shell/ext/cdfview/dll) | 3 | [shell/ext/cdfview/dll/sources](../../shell/ext/cdfview/dll/sources), [shell/ext/cdfview/dll/makefile](../../shell/ext/cdfview/dll/makefile) | `cdfview` | `DYNLINK` |
| [shell/ext/cdfview/res](../../shell/ext/cdfview/res) | 29 | — | — | — |
| [shell/ext/cdfview/resdll](../../shell/ext/cdfview/resdll) | 3 | [shell/ext/cdfview/resdll/sources](../../shell/ext/cdfview/resdll/sources), [shell/ext/cdfview/resdll/makefile](../../shell/ext/cdfview/resdll/makefile) | `cdfvwlc` | `DYNLINK` |
| [shell/ext/cdfview/test](../../shell/ext/cdfview/test) | 3 | — | — | — |
| [shell/ext/cdfview/test/chandir](../../shell/ext/cdfview/test/chandir) | 3 | [shell/ext/cdfview/test/chandir/sources](../../shell/ext/cdfview/test/chandir/sources), [shell/ext/cdfview/test/chandir/makefile](../../shell/ext/cdfview/test/chandir/makefile) | `chandir` | `PROGRAM` |
| [shell/ext/cdfview/test/chanmgr](../../shell/ext/cdfview/test/chanmgr) | 3 | [shell/ext/cdfview/test/chanmgr/sources](../../shell/ext/cdfview/test/chanmgr/sources), [shell/ext/cdfview/test/chanmgr/makefile](../../shell/ext/cdfview/test/chanmgr/makefile) | `chanmgr` | `PROGRAM` |
| [shell/ext/cscui](../../shell/ext/cscui) | 110 | [shell/ext/cscui/dirs](../../shell/ext/cscui/dirs) | — | — |
| [shell/ext/cscui/dll](../../shell/ext/cscui/dll) | 4 | [shell/ext/cscui/dll/sources](../../shell/ext/cscui/dll/sources), [shell/ext/cscui/dll/makefile](../../shell/ext/cscui/dll/makefile) | `cscui` | `DYNLINK` |
| [shell/ext/cscui/lib](../../shell/ext/cscui/lib) | 2 | [shell/ext/cscui/lib/sources](../../shell/ext/cscui/lib/sources), [shell/ext/cscui/lib/makefile](../../shell/ext/cscui/lib/makefile) | `cscui` | `LIBRARY` |
| [shell/ext/cscui/pin](../../shell/ext/cscui/pin) | 16 | [shell/ext/cscui/pin/sources](../../shell/ext/cscui/pin/sources), [shell/ext/cscui/pin/makefile](../../shell/ext/cscui/pin/makefile) | `cscpin` | `PROGRAM` |
| [shell/ext/cscui/sniff](../../shell/ext/cscui/sniff) | 3 | [shell/ext/cscui/sniff/sources](../../shell/ext/cscui/sniff/sources), [shell/ext/cscui/sniff/makefile](../../shell/ext/cscui/sniff/makefile) | `cscsniff` | `PROGRAM` |
| [shell/ext/diskcopy](../../shell/ext/diskcopy) | 16 | [shell/ext/diskcopy/sources](../../shell/ext/diskcopy/sources), [shell/ext/diskcopy/makefile](../../shell/ext/diskcopy/makefile) | `diskcopy` | `DYNLINK` |
| [shell/ext/diskcopy/srcfiles](../../shell/ext/diskcopy/srcfiles) | 15 | — | — | — |
| [shell/ext/docprop](../../shell/ext/docprop) | 39 | [shell/ext/docprop/dirs](../../shell/ext/docprop/dirs) | — | — |
| [shell/ext/docprop/win95](../../shell/ext/docprop/win95) | 2 | [shell/ext/docprop/win95/sources](../../shell/ext/docprop/win95/sources), [shell/ext/docprop/win95/makefile](../../shell/ext/docprop/win95/makefile) | — | — |
| [shell/ext/docprop/winnt](../../shell/ext/docprop/winnt) | 2 | [shell/ext/docprop/winnt/sources](../../shell/ext/docprop/winnt/sources), [shell/ext/docprop/winnt/makefile](../../shell/ext/docprop/winnt/makefile) | — | — |
| [shell/ext/docpropv3](../../shell/ext/docpropv3) | 57 | [shell/ext/docpropv3/sources](../../shell/ext/docpropv3/sources), [shell/ext/docpropv3/makefile](../../shell/ext/docpropv3/makefile) | `DOCPROP2` | `DYNLINK` |
| [shell/ext/dsui](../../shell/ext/dsui) | 2 | [shell/ext/dsui/dirs](../../shell/ext/dsui/dirs) | — | — |
| [shell/ext/dsui/common](../../shell/ext/dsui/common) | 7 | [shell/ext/dsui/common/dirs](../../shell/ext/dsui/common/dirs) | — | — |
| [shell/ext/dsui/common/winnt](../../shell/ext/dsui/common/winnt) | 3 | [shell/ext/dsui/common/winnt/sources](../../shell/ext/dsui/common/winnt/sources), [shell/ext/dsui/common/winnt/makefile](../../shell/ext/dsui/common/winnt/makefile) | — | — |
| [shell/ext/dsui/dsquery](../../shell/ext/dsui/dsquery) | 36 | [shell/ext/dsui/dsquery/dirs](../../shell/ext/dsui/dsquery/dirs) | — | — |
| [shell/ext/dsui/dsquery/res](../../shell/ext/dsui/dsquery/res) | 6 | — | — | — |
| [shell/ext/dsui/dsquery/winnt](../../shell/ext/dsui/dsquery/winnt) | 2 | [shell/ext/dsui/dsquery/winnt/sources](../../shell/ext/dsui/dsquery/winnt/sources), [shell/ext/dsui/dsquery/winnt/makefile](../../shell/ext/dsui/dsquery/winnt/makefile) | — | — |
| [shell/ext/dsui/dsuiext](../../shell/ext/dsui/dsuiext) | 23 | [shell/ext/dsui/dsuiext/dirs](../../shell/ext/dsui/dsuiext/dirs) | — | — |
| [shell/ext/dsui/dsuiext/res](../../shell/ext/dsui/dsuiext/res) | 35 | — | — | — |
| [shell/ext/dsui/dsuiext/winnt](../../shell/ext/dsui/dsuiext/winnt) | 2 | [shell/ext/dsui/dsuiext/winnt/sources](../../shell/ext/dsui/dsuiext/winnt/sources), [shell/ext/dsui/dsuiext/winnt/makefile](../../shell/ext/dsui/dsuiext/winnt/makefile) | — | — |
| [shell/ext/dsui/inc](../../shell/ext/dsui/inc) | 2 | — | — | — |
| [shell/ext/ftp](../../shell/ext/ftp) | 140 | [shell/ext/ftp/sources](../../shell/ext/ftp/sources), [shell/ext/ftp/makefile](../../shell/ext/ftp/makefile) | `MSIEFTP` | `DYNLINK` |
| [shell/ext/gina](../../shell/ext/gina) | 42 | [shell/ext/gina/sources](../../shell/ext/gina/sources), [shell/ext/gina/makefile](../../shell/ext/gina/makefile) | `gina` | `LIBRARY` |
| [shell/ext/hmmapi](../../shell/ext/hmmapi) | 10 | [shell/ext/hmmapi/sources](../../shell/ext/hmmapi/sources), [shell/ext/hmmapi/makefile](../../shell/ext/hmmapi/makefile) | `hmmapi` | `DYNLINK` |
| [shell/ext/hmmapi/inc](../../shell/ext/hmmapi/inc) | 1 | — | — | — |
| [shell/ext/hnw](../../shell/ext/hnw) | 2 | [shell/ext/hnw/dirs](../../shell/ext/hnw/dirs) | — | — |
| [shell/ext/hnw/nconn16](../../shell/ext/hnw/nconn16) | 10 | [shell/ext/hnw/nconn16/sources](../../shell/ext/hnw/nconn16/sources), [shell/ext/hnw/nconn16/makefile](../../shell/ext/hnw/nconn16/makefile) | — | `NOTARGET` |
| [shell/ext/hnw/nconn16/i386](../../shell/ext/hnw/nconn16/i386) | 1 | — | — | — |
| [shell/ext/hnw/nconn16/lib](../../shell/ext/hnw/nconn16/lib) | 1 | — | — | — |
| [shell/ext/hnw/nconn32](../../shell/ext/hnw/nconn32) | 35 | [shell/ext/hnw/nconn32/sources](../../shell/ext/hnw/nconn32/sources), [shell/ext/hnw/nconn32/makefile](../../shell/ext/hnw/nconn32/makefile) | `NCXP32` | `DYNLINK` |
| [shell/ext/hnw/nconn32/i386](../../shell/ext/hnw/nconn32/i386) | 1 | — | — | — |
| [shell/ext/hnw/nconnnt](../../shell/ext/hnw/nconnnt) | 12 | [shell/ext/hnw/nconnnt/sources](../../shell/ext/hnw/nconnnt/sources), [shell/ext/hnw/nconnnt/makefile](../../shell/ext/hnw/nconnnt/makefile) | `NCXPNT` | `DYNLINK` |
| [shell/ext/hnw/setup](../../shell/ext/hnw/setup) | 9 | [shell/ext/hnw/setup/sources](../../shell/ext/hnw/setup/sources), [shell/ext/hnw/setup/makefile](../../shell/ext/hnw/setup/makefile) | `WinXPChk` | `PROGRAM` |
| [shell/ext/hnw/shared](../../shell/ext/hnw/shared) | 25 | — | — | — |
| [shell/ext/hnw/win95](../../shell/ext/hnw/win95) | 13 | — | — | — |
| [shell/ext/hnw/wizard](../../shell/ext/hnw/wizard) | 62 | [shell/ext/hnw/wizard/dirs](../../shell/ext/hnw/wizard/dirs) | — | — |
| [shell/ext/hnw/wizard/dll](../../shell/ext/hnw/wizard/dll) | 7 | [shell/ext/hnw/wizard/dll/sources](../../shell/ext/hnw/wizard/dll/sources), [shell/ext/hnw/wizard/dll/makefile](../../shell/ext/hnw/wizard/dll/makefile) | `HNETWIZ` | `DYNLINK` |
| [shell/ext/hnw/wizard/res](../../shell/ext/hnw/wizard/res) | 10 | — | — | — |
| [shell/ext/hnw/wizard/srcc](../../shell/ext/hnw/wizard/srcc) | 2 | [shell/ext/hnw/wizard/srcc/sources](../../shell/ext/hnw/wizard/srcc/sources), [shell/ext/hnw/wizard/srcc/makefile](../../shell/ext/hnw/wizard/srcc/makefile) | `srcc` | `LIBRARY` |
| [shell/ext/inetfind](../../shell/ext/inetfind) | 14 | [shell/ext/inetfind/sources](../../shell/ext/inetfind/sources), [shell/ext/inetfind/makefile](../../shell/ext/inetfind/makefile) | `inetfind` | `DYNLINK` |
| [shell/ext/keyremap](../../shell/ext/keyremap) | 13 | [shell/ext/keyremap/sources](../../shell/ext/keyremap/sources), [shell/ext/keyremap/makefile](../../shell/ext/keyremap/makefile) | `keyremap` | `DYNLINK` |
| [shell/ext/loadwc](../../shell/ext/loadwc) | 9 | [shell/ext/loadwc/dirs](../../shell/ext/loadwc/dirs), [shell/ext/loadwc/makefile](../../shell/ext/loadwc/makefile) | — | — |
| [shell/ext/loadwc/dll](../../shell/ext/loadwc/dll) | 3 | [shell/ext/loadwc/dll/sources](../../shell/ext/loadwc/dll/sources), [shell/ext/loadwc/dll/makefile](../../shell/ext/loadwc/dll/makefile) | `loadwc` | `PROGRAM` |
| [shell/ext/loadwc/resdll](../../shell/ext/loadwc/resdll) | 3 | [shell/ext/loadwc/resdll/sources](../../shell/ext/loadwc/resdll/sources), [shell/ext/loadwc/resdll/makefile](../../shell/ext/loadwc/resdll/makefile) | `loadwclc` | `DYNLINK` |
| [shell/ext/logondui](../../shell/ext/logondui) | 44 | [shell/ext/logondui/sources](../../shell/ext/logondui/sources), [shell/ext/logondui/makefile](../../shell/ext/logondui/makefile) | `logonui` | `PROGRAM` |
| [shell/ext/logondui/gpres](../../shell/ext/logondui/gpres) | 11 | — | — | — |
| [shell/ext/media](../../shell/ext/media) | 20 | [shell/ext/media/sources](../../shell/ext/media/sources), [shell/ext/media/makefile](../../shell/ext/media/makefile) | `shmedia` | `DYNLINK` |
| [shell/ext/media/lib](../../shell/ext/media/lib) | 1 | — | — | — |
| [shell/ext/media/test](../../shell/ext/media/test) | 3 | [shell/ext/media/test/sources](../../shell/ext/media/test/sources), [shell/ext/media/test/makefile](../../shell/ext/media/test/makefile) | `proptest` | `PROGRAM` |
| [shell/ext/mlang](../../shell/ext/mlang) | 97 | [shell/ext/mlang/dirs](../../shell/ext/mlang/dirs) | — | — |
| [shell/ext/mlang/dll](../../shell/ext/mlang/dll) | 4 | [shell/ext/mlang/dll/sources](../../shell/ext/mlang/dll/sources), [shell/ext/mlang/dll/makefile](../../shell/ext/mlang/dll/makefile) | — | — |
| [shell/ext/mlang/loc](../../shell/ext/mlang/loc) | 2 | [shell/ext/mlang/loc/sources](../../shell/ext/mlang/loc/sources), [shell/ext/mlang/loc/makefile](../../shell/ext/mlang/loc/makefile) | — | — |
| [shell/ext/mlang/res](../../shell/ext/mlang/res) | 27 | — | — | — |
| [shell/ext/msident](../../shell/ext/msident) | 33 | [shell/ext/msident/dirs](../../shell/ext/msident/dirs), [shell/ext/msident/makefile](../../shell/ext/msident/makefile) | — | — |
| [shell/ext/msident/dll](../../shell/ext/msident/dll) | 4 | [shell/ext/msident/dll/sources](../../shell/ext/msident/dll/sources), [shell/ext/msident/dll/makefile](../../shell/ext/msident/dll/makefile) | `msident` | `DYNLINK` |
| [shell/ext/msident/resdll](../../shell/ext/msident/resdll) | 3 | [shell/ext/msident/resdll/sources](../../shell/ext/msident/resdll/sources), [shell/ext/msident/resdll/makefile](../../shell/ext/msident/resdll/makefile) | `msidntld` | `DYNLINK` |
| [shell/ext/msidle](../../shell/ext/msidle) | 9 | [shell/ext/msidle/sources](../../shell/ext/msidle/sources), [shell/ext/msidle/makefile](../../shell/ext/msidle/makefile) | `msidle` | `DYNLINK` |
| [shell/ext/msidle/sage](../../shell/ext/msidle/sage) | 3 | [shell/ext/msidle/sage/makefile](../../shell/ext/msidle/sage/makefile) | — | — |
| [shell/ext/msnspa](../../shell/ext/msnspa) | 10 | [shell/ext/msnspa/sources](../../shell/ext/msnspa/sources), [shell/ext/msnspa/makefile](../../shell/ext/msnspa/makefile) | `msnspa` | `PROGRAM` |
| [shell/ext/mydocs2](../../shell/ext/mydocs2) | 21 | [shell/ext/mydocs2/dirs](../../shell/ext/mydocs2/dirs) | — | — |
| [shell/ext/mydocs2/winnt](../../shell/ext/mydocs2/winnt) | 3 | [shell/ext/mydocs2/winnt/sources](../../shell/ext/mydocs2/winnt/sources), [shell/ext/mydocs2/winnt/makefile](../../shell/ext/mydocs2/winnt/makefile) | — | — |
| [shell/ext/neptune](../../shell/ext/neptune) | 1 | — | — | — |
| [shell/ext/neptune/aidanl](../../shell/ext/neptune/aidanl) | 0 | — | — | — |
| [shell/ext/neptune/aidanl/davtrans](../../shell/ext/neptune/aidanl/davtrans) | 3 | — | — | — |
| [shell/ext/neptune/aidanl/davtrans/asyncwnt](../../shell/ext/neptune/aidanl/davtrans/asyncwnt) | 9 | [shell/ext/neptune/aidanl/davtrans/asyncwnt/dirs](../../shell/ext/neptune/aidanl/davtrans/asyncwnt/dirs) | — | — |
| [shell/ext/neptune/aidanl/davtrans/asyncwnt/clsidslib](../../shell/ext/neptune/aidanl/davtrans/asyncwnt/clsidslib) | 3 | [shell/ext/neptune/aidanl/davtrans/asyncwnt/clsidslib/sources](../../shell/ext/neptune/aidanl/davtrans/asyncwnt/clsidslib/sources), [shell/ext/neptune/aidanl/davtrans/asyncwnt/clsidslib/makefile](../../shell/ext/neptune/aidanl/davtrans/asyncwnt/clsidslib/makefile) | `asyncwnt_g` | `LIBRARY` |
| [shell/ext/neptune/aidanl/davtrans/asyncwnt/dll](../../shell/ext/neptune/aidanl/davtrans/asyncwnt/dll) | 2 | [shell/ext/neptune/aidanl/davtrans/asyncwnt/dll/sources](../../shell/ext/neptune/aidanl/davtrans/asyncwnt/dll/sources), [shell/ext/neptune/aidanl/davtrans/asyncwnt/dll/makefile](../../shell/ext/neptune/aidanl/davtrans/asyncwnt/dll/makefile) | `asyncwnt` | `DYNLINK` |
| [shell/ext/neptune/aidanl/davtrans/asyncwnt/idl](../../shell/ext/neptune/aidanl/davtrans/asyncwnt/idl) | 3 | [shell/ext/neptune/aidanl/davtrans/asyncwnt/idl/sources](../../shell/ext/neptune/aidanl/davtrans/asyncwnt/idl/sources), [shell/ext/neptune/aidanl/davtrans/asyncwnt/idl/makefile](../../shell/ext/neptune/aidanl/davtrans/asyncwnt/idl/makefile) | — | `NOTARGET` |
| [shell/ext/neptune/aidanl/davtrans/clsids](../../shell/ext/neptune/aidanl/davtrans/clsids) | 0 | — | — | — |
| [shell/ext/neptune/aidanl/davtrans/clsids/inc](../../shell/ext/neptune/aidanl/davtrans/clsids/inc) | 9 | — | — | — |
| [shell/ext/neptune/aidanl/davtrans/common](../../shell/ext/neptune/aidanl/davtrans/common) | 1 | [shell/ext/neptune/aidanl/davtrans/common/dirs](../../shell/ext/neptune/aidanl/davtrans/common/dirs) | — | — |
| [shell/ext/neptune/aidanl/davtrans/common/comlnm](../../shell/ext/neptune/aidanl/davtrans/common/comlnm) | 7 | [shell/ext/neptune/aidanl/davtrans/common/comlnm/dirs](../../shell/ext/neptune/aidanl/davtrans/common/comlnm/dirs) | — | — |
| [shell/ext/neptune/aidanl/davtrans/common/comlnm/lib](../../shell/ext/neptune/aidanl/davtrans/common/comlnm/lib) | 3 | [shell/ext/neptune/aidanl/davtrans/common/comlnm/lib/sources](../../shell/ext/neptune/aidanl/davtrans/common/comlnm/lib/sources), [shell/ext/neptune/aidanl/davtrans/common/comlnm/lib/makefile](../../shell/ext/neptune/aidanl/davtrans/common/comlnm/lib/makefile) | `comlnm` | `LIBRARY` |
| [shell/ext/neptune/aidanl/davtrans/common/genxml](../../shell/ext/neptune/aidanl/davtrans/common/genxml) | 6 | [shell/ext/neptune/aidanl/davtrans/common/genxml/dirs](../../shell/ext/neptune/aidanl/davtrans/common/genxml/dirs) | — | — |
| [shell/ext/neptune/aidanl/davtrans/common/genxml/lib](../../shell/ext/neptune/aidanl/davtrans/common/genxml/lib) | 3 | [shell/ext/neptune/aidanl/davtrans/common/genxml/lib/sources](../../shell/ext/neptune/aidanl/davtrans/common/genxml/lib/sources), [shell/ext/neptune/aidanl/davtrans/common/genxml/lib/makefile](../../shell/ext/neptune/aidanl/davtrans/common/genxml/lib/makefile) | `genxml` | `LIBRARY` |
| [shell/ext/neptune/aidanl/davtrans/common/genxml/tstdrv](../../shell/ext/neptune/aidanl/davtrans/common/genxml/tstdrv) | 2 | [shell/ext/neptune/aidanl/davtrans/common/genxml/tstdrv/dirs](../../shell/ext/neptune/aidanl/davtrans/common/genxml/tstdrv/dirs) | — | — |
| [shell/ext/neptune/aidanl/davtrans/common/inc](../../shell/ext/neptune/aidanl/davtrans/common/inc) | 15 | — | — | — |
| [shell/ext/neptune/aidanl/davtrans/common/src](../../shell/ext/neptune/aidanl/davtrans/common/src) | 12 | [shell/ext/neptune/aidanl/davtrans/common/src/dirs](../../shell/ext/neptune/aidanl/davtrans/common/src/dirs) | — | — |
| [shell/ext/neptune/aidanl/davtrans/common/src/dll](../../shell/ext/neptune/aidanl/davtrans/common/src/dll) | 3 | [shell/ext/neptune/aidanl/davtrans/common/src/dll/sources](../../shell/ext/neptune/aidanl/davtrans/common/src/dll/sources), [shell/ext/neptune/aidanl/davtrans/common/src/dll/makefile](../../shell/ext/neptune/aidanl/davtrans/common/src/dll/makefile) | `httpcom` | `LIBRARY` |
| [shell/ext/neptune/aidanl/davtrans/davinet](../../shell/ext/neptune/aidanl/davtrans/davinet) | 16 | [shell/ext/neptune/aidanl/davtrans/davinet/dirs](../../shell/ext/neptune/aidanl/davtrans/davinet/dirs) | — | — |
| [shell/ext/neptune/aidanl/davtrans/davinet/clsidslib](../../shell/ext/neptune/aidanl/davtrans/davinet/clsidslib) | 3 | [shell/ext/neptune/aidanl/davtrans/davinet/clsidslib/sources](../../shell/ext/neptune/aidanl/davtrans/davinet/clsidslib/sources), [shell/ext/neptune/aidanl/davtrans/davinet/clsidslib/makefile](../../shell/ext/neptune/aidanl/davtrans/davinet/clsidslib/makefile) | `davinet_g` | `LIBRARY` |
| [shell/ext/neptune/aidanl/davtrans/davinet/dll](../../shell/ext/neptune/aidanl/davtrans/davinet/dll) | 2 | [shell/ext/neptune/aidanl/davtrans/davinet/dll/sources](../../shell/ext/neptune/aidanl/davtrans/davinet/dll/sources), [shell/ext/neptune/aidanl/davtrans/davinet/dll/makefile](../../shell/ext/neptune/aidanl/davtrans/davinet/dll/makefile) | `davinet` | `DYNLINK` |
| [shell/ext/neptune/aidanl/davtrans/davinet/idl](../../shell/ext/neptune/aidanl/davtrans/davinet/idl) | 3 | [shell/ext/neptune/aidanl/davtrans/davinet/idl/sources](../../shell/ext/neptune/aidanl/davtrans/davinet/idl/sources), [shell/ext/neptune/aidanl/davtrans/davinet/idl/makefile](../../shell/ext/neptune/aidanl/davtrans/davinet/idl/makefile) | — | `NOTARGET` |
| [shell/ext/neptune/aidanl/davtrans/davinet/tstdrv](../../shell/ext/neptune/aidanl/davtrans/davinet/tstdrv) | 4 | [shell/ext/neptune/aidanl/davtrans/davinet/tstdrv/sources](../../shell/ext/neptune/aidanl/davtrans/davinet/tstdrv/sources), [shell/ext/neptune/aidanl/davtrans/davinet/tstdrv/makefile](../../shell/ext/neptune/aidanl/davtrans/davinet/tstdrv/makefile) | `tstdrv` | `PROGRAM` |
| [shell/ext/neptune/aidanl/davtrans/davinet/xmltest](../../shell/ext/neptune/aidanl/davtrans/davinet/xmltest) | 5 | [shell/ext/neptune/aidanl/davtrans/davinet/xmltest/sources](../../shell/ext/neptune/aidanl/davtrans/davinet/xmltest/sources), [shell/ext/neptune/aidanl/davtrans/davinet/xmltest/makefile](../../shell/ext/neptune/aidanl/davtrans/davinet/xmltest/makefile) | `xmltest` | `PROGRAM` |
| [shell/ext/neptune/aidanl/davtrans/davstore](../../shell/ext/neptune/aidanl/davtrans/davstore) | 11 | [shell/ext/neptune/aidanl/davtrans/davstore/dirs](../../shell/ext/neptune/aidanl/davtrans/davstore/dirs) | — | — |
| [shell/ext/neptune/aidanl/davtrans/davstore/clsidslib](../../shell/ext/neptune/aidanl/davtrans/davstore/clsidslib) | 3 | [shell/ext/neptune/aidanl/davtrans/davstore/clsidslib/sources](../../shell/ext/neptune/aidanl/davtrans/davstore/clsidslib/sources), [shell/ext/neptune/aidanl/davtrans/davstore/clsidslib/makefile](../../shell/ext/neptune/aidanl/davtrans/davstore/clsidslib/makefile) | `davstore_g` | `LIBRARY` |
| [shell/ext/neptune/aidanl/davtrans/davstore/dll](../../shell/ext/neptune/aidanl/davtrans/davstore/dll) | 2 | [shell/ext/neptune/aidanl/davtrans/davstore/dll/sources](../../shell/ext/neptune/aidanl/davtrans/davstore/dll/sources), [shell/ext/neptune/aidanl/davtrans/davstore/dll/makefile](../../shell/ext/neptune/aidanl/davtrans/davstore/dll/makefile) | `davstore` | `DYNLINK` |
| [shell/ext/neptune/aidanl/davtrans/davstore/idl](../../shell/ext/neptune/aidanl/davtrans/davstore/idl) | 3 | [shell/ext/neptune/aidanl/davtrans/davstore/idl/sources](../../shell/ext/neptune/aidanl/davtrans/davstore/idl/sources), [shell/ext/neptune/aidanl/davtrans/davstore/idl/makefile](../../shell/ext/neptune/aidanl/davtrans/davstore/idl/makefile) | — | `NOTARGET` |
| [shell/ext/neptune/aidanl/davtrans/davstore/tstdrv](../../shell/ext/neptune/aidanl/davtrans/davstore/tstdrv) | 3 | [shell/ext/neptune/aidanl/davtrans/davstore/tstdrv/sources](../../shell/ext/neptune/aidanl/davtrans/davstore/tstdrv/sources), [shell/ext/neptune/aidanl/davtrans/davstore/tstdrv/makefile](../../shell/ext/neptune/aidanl/davtrans/davstore/tstdrv/makefile) | `tstdrv` | `PROGRAM` |
| [shell/ext/neptune/aidanl/davtrans/ftpstore](../../shell/ext/neptune/aidanl/davtrans/ftpstore) | 10 | [shell/ext/neptune/aidanl/davtrans/ftpstore/dirs](../../shell/ext/neptune/aidanl/davtrans/ftpstore/dirs) | — | — |
| [shell/ext/neptune/aidanl/davtrans/ftpstore/clsidslib](../../shell/ext/neptune/aidanl/davtrans/ftpstore/clsidslib) | 3 | [shell/ext/neptune/aidanl/davtrans/ftpstore/clsidslib/sources](../../shell/ext/neptune/aidanl/davtrans/ftpstore/clsidslib/sources), [shell/ext/neptune/aidanl/davtrans/ftpstore/clsidslib/makefile](../../shell/ext/neptune/aidanl/davtrans/ftpstore/clsidslib/makefile) | `ftpstore_g` | `LIBRARY` |
| [shell/ext/neptune/aidanl/davtrans/ftpstore/dll](../../shell/ext/neptune/aidanl/davtrans/ftpstore/dll) | 2 | [shell/ext/neptune/aidanl/davtrans/ftpstore/dll/sources](../../shell/ext/neptune/aidanl/davtrans/ftpstore/dll/sources), [shell/ext/neptune/aidanl/davtrans/ftpstore/dll/makefile](../../shell/ext/neptune/aidanl/davtrans/ftpstore/dll/makefile) | `ftpstore` | `DYNLINK` |
| [shell/ext/neptune/aidanl/davtrans/ftpstore/tstdrv](../../shell/ext/neptune/aidanl/davtrans/ftpstore/tstdrv) | 3 | [shell/ext/neptune/aidanl/davtrans/ftpstore/tstdrv/sources](../../shell/ext/neptune/aidanl/davtrans/ftpstore/tstdrv/sources), [shell/ext/neptune/aidanl/davtrans/ftpstore/tstdrv/makefile](../../shell/ext/neptune/aidanl/davtrans/ftpstore/tstdrv/makefile) | `tstdrv` | `PROGRAM` |
| [shell/ext/neptune/aidanl/davtrans/ftpstrm](../../shell/ext/neptune/aidanl/davtrans/ftpstrm) | 10 | [shell/ext/neptune/aidanl/davtrans/ftpstrm/dirs](../../shell/ext/neptune/aidanl/davtrans/ftpstrm/dirs) | — | — |
| [shell/ext/neptune/aidanl/davtrans/ftpstrm/clsidslib](../../shell/ext/neptune/aidanl/davtrans/ftpstrm/clsidslib) | 3 | [shell/ext/neptune/aidanl/davtrans/ftpstrm/clsidslib/sources](../../shell/ext/neptune/aidanl/davtrans/ftpstrm/clsidslib/sources), [shell/ext/neptune/aidanl/davtrans/ftpstrm/clsidslib/makefile](../../shell/ext/neptune/aidanl/davtrans/ftpstrm/clsidslib/makefile) | `ftpstrm_g` | `LIBRARY` |
| [shell/ext/neptune/aidanl/davtrans/ftpstrm/dll](../../shell/ext/neptune/aidanl/davtrans/ftpstrm/dll) | 3 | [shell/ext/neptune/aidanl/davtrans/ftpstrm/dll/sources](../../shell/ext/neptune/aidanl/davtrans/ftpstrm/dll/sources), [shell/ext/neptune/aidanl/davtrans/ftpstrm/dll/makefile](../../shell/ext/neptune/aidanl/davtrans/ftpstrm/dll/makefile) | `ftpstrm` | `DYNLINK` |
| [shell/ext/neptune/aidanl/davtrans/ftpstrm/tstdrv](../../shell/ext/neptune/aidanl/davtrans/ftpstrm/tstdrv) | 3 | [shell/ext/neptune/aidanl/davtrans/ftpstrm/tstdrv/sources](../../shell/ext/neptune/aidanl/davtrans/ftpstrm/tstdrv/sources), [shell/ext/neptune/aidanl/davtrans/ftpstrm/tstdrv/makefile](../../shell/ext/neptune/aidanl/davtrans/ftpstrm/tstdrv/makefile) | `tstdrv` | `PROGRAM` |
| [shell/ext/neptune/aidanl/davtrans/httpstrm](../../shell/ext/neptune/aidanl/davtrans/httpstrm) | 10 | [shell/ext/neptune/aidanl/davtrans/httpstrm/dirs](../../shell/ext/neptune/aidanl/davtrans/httpstrm/dirs) | — | — |
| [shell/ext/neptune/aidanl/davtrans/httpstrm/clsidslib](../../shell/ext/neptune/aidanl/davtrans/httpstrm/clsidslib) | 3 | [shell/ext/neptune/aidanl/davtrans/httpstrm/clsidslib/sources](../../shell/ext/neptune/aidanl/davtrans/httpstrm/clsidslib/sources), [shell/ext/neptune/aidanl/davtrans/httpstrm/clsidslib/makefile](../../shell/ext/neptune/aidanl/davtrans/httpstrm/clsidslib/makefile) | `httpstrm_g` | `LIBRARY` |
| [shell/ext/neptune/aidanl/davtrans/httpstrm/dll](../../shell/ext/neptune/aidanl/davtrans/httpstrm/dll) | 3 | [shell/ext/neptune/aidanl/davtrans/httpstrm/dll/sources](../../shell/ext/neptune/aidanl/davtrans/httpstrm/dll/sources), [shell/ext/neptune/aidanl/davtrans/httpstrm/dll/makefile](../../shell/ext/neptune/aidanl/davtrans/httpstrm/dll/makefile) | `httpstrm` | `DYNLINK` |
| [shell/ext/neptune/aidanl/davtrans/httpstrm/idl](../../shell/ext/neptune/aidanl/davtrans/httpstrm/idl) | 3 | [shell/ext/neptune/aidanl/davtrans/httpstrm/idl/sources](../../shell/ext/neptune/aidanl/davtrans/httpstrm/idl/sources), [shell/ext/neptune/aidanl/davtrans/httpstrm/idl/makefile](../../shell/ext/neptune/aidanl/davtrans/httpstrm/idl/makefile) | — | `NOTARGET` |
| [shell/ext/neptune/aidanl/davtrans/httpstrm/tstdrv](../../shell/ext/neptune/aidanl/davtrans/httpstrm/tstdrv) | 4 | [shell/ext/neptune/aidanl/davtrans/httpstrm/tstdrv/sources](../../shell/ext/neptune/aidanl/davtrans/httpstrm/tstdrv/sources), [shell/ext/neptune/aidanl/davtrans/httpstrm/tstdrv/makefile](../../shell/ext/neptune/aidanl/davtrans/httpstrm/tstdrv/makefile) | `tstdrv` | `PROGRAM` |
| [shell/ext/neptune/aidanl/davtrans/ifaces](../../shell/ext/neptune/aidanl/davtrans/ifaces) | 7 | — | — | — |
| [shell/ext/neptune/aidanl/davtrans/shellstg](../../shell/ext/neptune/aidanl/davtrans/shellstg) | 13 | [shell/ext/neptune/aidanl/davtrans/shellstg/dirs](../../shell/ext/neptune/aidanl/davtrans/shellstg/dirs) | — | — |
| [shell/ext/neptune/aidanl/davtrans/shellstg/clsidslib](../../shell/ext/neptune/aidanl/davtrans/shellstg/clsidslib) | 3 | [shell/ext/neptune/aidanl/davtrans/shellstg/clsidslib/sources](../../shell/ext/neptune/aidanl/davtrans/shellstg/clsidslib/sources), [shell/ext/neptune/aidanl/davtrans/shellstg/clsidslib/makefile](../../shell/ext/neptune/aidanl/davtrans/shellstg/clsidslib/makefile) | `shellstg_g` | `LIBRARY` |
| [shell/ext/neptune/aidanl/davtrans/shellstg/dll](../../shell/ext/neptune/aidanl/davtrans/shellstg/dll) | 2 | [shell/ext/neptune/aidanl/davtrans/shellstg/dll/sources](../../shell/ext/neptune/aidanl/davtrans/shellstg/dll/sources), [shell/ext/neptune/aidanl/davtrans/shellstg/dll/makefile](../../shell/ext/neptune/aidanl/davtrans/shellstg/dll/makefile) | `shellstg` | `DYNLINK` |
| [shell/ext/neptune/aidanl/davtrans/shellstg/idl](../../shell/ext/neptune/aidanl/davtrans/shellstg/idl) | 3 | [shell/ext/neptune/aidanl/davtrans/shellstg/idl/sources](../../shell/ext/neptune/aidanl/davtrans/shellstg/idl/sources), [shell/ext/neptune/aidanl/davtrans/shellstg/idl/makefile](../../shell/ext/neptune/aidanl/davtrans/shellstg/idl/makefile) | — | `NOTARGET` |
| [shell/ext/neptune/aidanl/davtrans/shellstg/tstdrv](../../shell/ext/neptune/aidanl/davtrans/shellstg/tstdrv) | 3 | [shell/ext/neptune/aidanl/davtrans/shellstg/tstdrv/sources](../../shell/ext/neptune/aidanl/davtrans/shellstg/tstdrv/sources), [shell/ext/neptune/aidanl/davtrans/shellstg/tstdrv/makefile](../../shell/ext/neptune/aidanl/davtrans/shellstg/tstdrv/makefile) | `tstdrv` | `PROGRAM` |
| [shell/ext/netplwiz](../../shell/ext/netplwiz) | 46 | [shell/ext/netplwiz/dirs](../../shell/ext/netplwiz/dirs) | — | — |
| [shell/ext/netplwiz/res](../../shell/ext/netplwiz/res) | 27 | — | — | — |
| [shell/ext/netplwiz/winnt](../../shell/ext/netplwiz/winnt) | 3 | [shell/ext/netplwiz/winnt/sources](../../shell/ext/netplwiz/winnt/sources), [shell/ext/netplwiz/winnt/makefile](../../shell/ext/netplwiz/winnt/makefile) | — | — |
| [shell/ext/nsc](../../shell/ext/nsc) | 20 | — | — | — |
| [shell/ext/occache](../../shell/ext/occache) | 43 | [shell/ext/occache/dirs](../../shell/ext/occache/dirs), [shell/ext/occache/makefile](../../shell/ext/occache/makefile) | — | — |
| [shell/ext/occache/dll](../../shell/ext/occache/dll) | 3 | [shell/ext/occache/dll/sources](../../shell/ext/occache/dll/sources), [shell/ext/occache/dll/makefile](../../shell/ext/occache/dll/makefile) | `occache` | `DYNLINK` |
| [shell/ext/occache/res](../../shell/ext/occache/res) | 2 | — | — | — |
| [shell/ext/occache/resdll](../../shell/ext/occache/resdll) | 2 | [shell/ext/occache/resdll/sources](../../shell/ext/occache/resdll/sources), [shell/ext/occache/resdll/makefile](../../shell/ext/occache/resdll/makefile) | `occachlc` | `DYNLINK` |
| [shell/ext/pack](../../shell/ext/pack) | 31 | [shell/ext/pack/dirs](../../shell/ext/pack/dirs), [shell/ext/pack/makefile](../../shell/ext/pack/makefile) | — | — |
| [shell/ext/pack/packexe](../../shell/ext/pack/packexe) | 7 | [shell/ext/pack/packexe/dirs](../../shell/ext/pack/packexe/dirs) | — | — |
| [shell/ext/pack/packexe/base](../../shell/ext/pack/packexe/base) | 2 | [shell/ext/pack/packexe/base/sources](../../shell/ext/pack/packexe/base/sources), [shell/ext/pack/packexe/base/makefile](../../shell/ext/pack/packexe/base/makefile) | `packager` | `PROGRAM` |
| [shell/ext/pack/winnt](../../shell/ext/pack/winnt) | 2 | [shell/ext/pack/winnt/sources](../../shell/ext/pack/winnt/sources), [shell/ext/pack/winnt/makefile](../../shell/ext/pack/winnt/makefile) | `packager` | `DYNLINK` |
| [shell/ext/powertoy](../../shell/ext/powertoy) | 13 | [shell/ext/powertoy/sources](../../shell/ext/powertoy/sources), [shell/ext/powertoy/makefile](../../shell/ext/powertoy/makefile) | `powertoy` | `DYNLINK` |
| [shell/ext/powertoy/res](../../shell/ext/powertoy/res) | 1 | — | — | — |
| [shell/ext/pstore](../../shell/ext/pstore) | 31 | [shell/ext/pstore/sources](../../shell/ext/pstore/sources), [shell/ext/pstore/makefile](../../shell/ext/pstore/makefile) | `pstoreex` | `DYNLINK` |
| [shell/ext/pstore/inc](../../shell/ext/pstore/inc) | 2 | — | — | — |
| [shell/ext/pstore/lib](../../shell/ext/pstore/lib) | 0 | — | — | — |
| [shell/ext/pstore/lib/i386](../../shell/ext/pstore/lib/i386) | 3 | — | — | — |
| [shell/ext/qlaunch](../../shell/ext/qlaunch) | 5 | [shell/ext/qlaunch/sources](../../shell/ext/qlaunch/sources), [shell/ext/qlaunch/makefile](../../shell/ext/qlaunch/makefile) | — | `NOTARGET` |
| [shell/ext/qvhack](../../shell/ext/qvhack) | 6 | [shell/ext/qvhack/sources](../../shell/ext/qvhack/sources), [shell/ext/qvhack/makefile](../../shell/ext/qvhack/makefile) | `quikview` | `PROGRAM` |
| [shell/ext/ratings](../../shell/ext/ratings) | 5 | [shell/ext/ratings/dirs](../../shell/ext/ratings/dirs), [shell/ext/ratings/makefile](../../shell/ext/ratings/makefile) | — | — |
| [shell/ext/ratings/common](../../shell/ext/ratings/common) | 57 | [shell/ext/ratings/common/sources](../../shell/ext/ratings/common/sources), [shell/ext/ratings/common/makefile](../../shell/ext/ratings/common/makefile) | `npcommon` | `LIBRARY` |
| [shell/ext/ratings/common/debug32](../../shell/ext/ratings/common/debug32) | 1 | — | — | — |
| [shell/ext/ratings/common/retail32](../../shell/ext/ratings/common/retail32) | 1 | — | — | — |
| [shell/ext/ratings/inc](../../shell/ext/ratings/inc) | 18 | — | — | — |
| [shell/ext/ratings/mslocusr](../../shell/ext/ratings/mslocusr) | 39 | [shell/ext/ratings/mslocusr/sources](../../shell/ext/ratings/mslocusr/sources), [shell/ext/ratings/mslocusr/makefile](../../shell/ext/ratings/mslocusr/makefile) | `mslocusr` | `DYNLINK` |
| [shell/ext/ratings/mslocusr/debug32](../../shell/ext/ratings/mslocusr/debug32) | 1 | — | — | — |
| [shell/ext/ratings/mslocusr/retail32](../../shell/ext/ratings/mslocusr/retail32) | 1 | — | — | — |
| [shell/ext/ratings/msrating](../../shell/ext/ratings/msrating) | 92 | [shell/ext/ratings/msrating/dirs](../../shell/ext/ratings/msrating/dirs) | — | — |
| [shell/ext/ratings/msrating/debug32](../../shell/ext/ratings/msrating/debug32) | 1 | — | — | — |
| [shell/ext/ratings/msrating/dll](../../shell/ext/ratings/msrating/dll) | 4 | [shell/ext/ratings/msrating/dll/sources](../../shell/ext/ratings/msrating/dll/sources), [shell/ext/ratings/msrating/dll/makefile](../../shell/ext/ratings/msrating/dll/makefile) | `msrating` | `DYNLINK` |
| [shell/ext/ratings/msrating/ntapi](../../shell/ext/ratings/msrating/ntapi) | 3 | [shell/ext/ratings/msrating/ntapi/sources](../../shell/ext/ratings/msrating/ntapi/sources), [shell/ext/ratings/msrating/ntapi/makefile](../../shell/ext/ratings/msrating/ntapi/makefile) | — | — |
| [shell/ext/ratings/msrating/resdll](../../shell/ext/ratings/msrating/resdll) | 3 | [shell/ext/ratings/msrating/resdll/sources](../../shell/ext/ratings/msrating/resdll/sources), [shell/ext/ratings/msrating/resdll/makefile](../../shell/ext/ratings/msrating/resdll/makefile) | `msratelc` | `DYNLINK` |
| [shell/ext/ratings/msrating/retail32](../../shell/ext/ratings/msrating/retail32) | 1 | — | — | — |
| [shell/ext/ratings/npstub](../../shell/ext/ratings/npstub) | 9 | [shell/ext/ratings/npstub/dirs](../../shell/ext/ratings/npstub/dirs) | — | — |
| [shell/ext/ratings/npstub/win95](../../shell/ext/ratings/npstub/win95) | 3 | [shell/ext/ratings/npstub/win95/sources](../../shell/ext/ratings/npstub/win95/sources), [shell/ext/ratings/npstub/win95/makefile](../../shell/ext/ratings/npstub/win95/makefile) | `ienpstub` | `DYNLINK` |
| [shell/ext/ratings/sample](../../shell/ext/ratings/sample) | 13 | — | — | — |
| [shell/ext/sendmail](../../shell/ext/sendmail) | 17 | [shell/ext/sendmail/sources](../../shell/ext/sendmail/sources), [shell/ext/sendmail/makefile](../../shell/ext/sendmail/makefile) | `sendmail` | `DYNLINK` |
| [shell/ext/shfolder](../../shell/ext/shfolder) | 12 | [shell/ext/shfolder/sources](../../shell/ext/shfolder/sources), [shell/ext/shfolder/makefile](../../shell/ext/shfolder/makefile) | `shfolder` | `DYNLINK` |
| [shell/ext/shfolder/app](../../shell/ext/shfolder/app) | 6 | [shell/ext/shfolder/app/sources](../../shell/ext/shfolder/app/sources), [shell/ext/shfolder/app/makefile](../../shell/ext/shfolder/app/makefile) | `shtest` | `PROGRAM` |
| [shell/ext/shfolder/loc](../../shell/ext/shfolder/loc) | 26 | — | — | — |
| [shell/ext/shgina](../../shell/ext/shgina) | 25 | [shell/ext/shgina/sources](../../shell/ext/shgina/sources), [shell/ext/shgina/makefile](../../shell/ext/shgina/makefile) | `shgina` | `DYNLINK` |
| [shell/ext/shgina/res](../../shell/ext/shgina/res) | 24 | — | — | — |
| [shell/ext/shimgvw](../../shell/ext/shimgvw) | 44 | [shell/ext/shimgvw/dirs](../../shell/ext/shimgvw/dirs) | — | — |
| [shell/ext/shimgvw/res](../../shell/ext/shimgvw/res) | 25 | — | — | — |
| [shell/ext/shimgvw/winnt](../../shell/ext/shimgvw/winnt) | 4 | [shell/ext/shimgvw/winnt/sources](../../shell/ext/shimgvw/winnt/sources), [shell/ext/shimgvw/winnt/makefile](../../shell/ext/shimgvw/winnt/makefile) | — | — |
| [shell/ext/shscrap](../../shell/ext/shscrap) | 25 | [shell/ext/shscrap/dirs](../../shell/ext/shscrap/dirs) | — | — |
| [shell/ext/shscrap/win95](../../shell/ext/shscrap/win95) | 2 | [shell/ext/shscrap/win95/sources](../../shell/ext/shscrap/win95/sources), [shell/ext/shscrap/win95/makefile](../../shell/ext/shscrap/win95/makefile) | — | — |
| [shell/ext/shscrap/winnt](../../shell/ext/shscrap/winnt) | 2 | [shell/ext/shscrap/winnt/sources](../../shell/ext/shscrap/winnt/sources), [shell/ext/shscrap/winnt/makefile](../../shell/ext/shscrap/winnt/makefile) | — | — |
| [shell/ext/shtl](../../shell/ext/shtl) | 20 | [shell/ext/shtl/sources](../../shell/ext/shtl/sources) | `datl` | `LIBRARY` |
| [shell/ext/srchasst](../../shell/ext/srchasst) | 15 | [shell/ext/srchasst/sources](../../shell/ext/srchasst/sources), [shell/ext/srchasst/makefile](../../shell/ext/srchasst/makefile) | — | `NOTARGET` |
| [shell/ext/srchasst/logos](../../shell/ext/srchasst/logos) | 17 | — | — | — |
| [shell/ext/sshow](../../shell/ext/sshow) | 35 | [shell/ext/sshow/sources](../../shell/ext/sshow/sources), [shell/ext/sshow/makefile](../../shell/ext/sshow/makefile) | `sshow` | `PROGRAM` |
| [shell/ext/sshow/res](../../shell/ext/sshow/res) | 3 | — | — | — |
| [shell/ext/systray](../../shell/ext/systray) | 1 | [shell/ext/systray/dirs](../../shell/ext/systray/dirs) | — | — |
| [shell/ext/systray/dll](../../shell/ext/systray/dll) | 70 | [shell/ext/systray/dll/sources](../../shell/ext/systray/dll/sources), [shell/ext/systray/dll/makefile](../../shell/ext/systray/dll/makefile) | `stobject` | `DYNLINK` |
| [shell/ext/systray/exestub](../../shell/ext/systray/exestub) | 6 | [shell/ext/systray/exestub/sources](../../shell/ext/systray/exestub/sources), [shell/ext/systray/exestub/makefile](../../shell/ext/systray/exestub/makefile) | `systray` | `PROGRAM` |
| [shell/ext/systray/test](../../shell/ext/systray/test) | 3 | [shell/ext/systray/test/sources](../../shell/ext/systray/test/sources), [shell/ext/systray/test/makefile](../../shell/ext/systray/test/makefile) | `test` | `PROGRAM` |
| [shell/ext/taskui](../../shell/ext/taskui) | 38 | [shell/ext/taskui/sources](../../shell/ext/taskui/sources), [shell/ext/taskui/makefile](../../shell/ext/taskui/makefile) | `taskui` | `DYNLINK` |
| [shell/ext/taskui/nusrmgr](../../shell/ext/taskui/nusrmgr) | 19 | [shell/ext/taskui/nusrmgr/sources](../../shell/ext/taskui/nusrmgr/sources), [shell/ext/taskui/nusrmgr/makefile](../../shell/ext/taskui/nusrmgr/makefile) | `nusrmgr` | `PROGRAM` |
| [shell/ext/taskui/nusrmgr/html](../../shell/ext/taskui/nusrmgr/html) | 15 | — | — | — |
| [shell/ext/taskui/test](../../shell/ext/taskui/test) | 20 | [shell/ext/taskui/test/sources](../../shell/ext/taskui/test/sources), [shell/ext/taskui/test/makefile](../../shell/ext/taskui/test/makefile) | `TaskApp` | `PROGRAM` |
| [shell/ext/url](../../shell/ext/url) | 103 | [shell/ext/url/dirs](../../shell/ext/url/dirs), [shell/ext/url/makefile](../../shell/ext/url/makefile) | — | — |
| [shell/ext/url/dll](../../shell/ext/url/dll) | 3 | [shell/ext/url/dll/sources](../../shell/ext/url/dll/sources), [shell/ext/url/dll/makefile](../../shell/ext/url/dll/makefile) | `url` | `DYNLINK` |
| [shell/ext/url/resdll](../../shell/ext/url/resdll) | 3 | [shell/ext/url/resdll/sources](../../shell/ext/url/resdll/sources), [shell/ext/url/resdll/makefile](../../shell/ext/url/resdll/makefile) | `urllc` | `DYNLINK` |
| [shell/ext/url/srcc](../../shell/ext/url/srcc) | 3 | [shell/ext/url/srcc/sources](../../shell/ext/url/srcc/sources), [shell/ext/url/srcc/makefile](../../shell/ext/url/srcc/makefile) | `srcc` | `LIBRARY` |
| [shell/ext/userstub](../../shell/ext/userstub) | 7 | [shell/ext/userstub/sources](../../shell/ext/userstub/sources), [shell/ext/userstub/makefile](../../shell/ext/userstub/makefile) | `userstub` | `PROGRAM` |
| [shell/ext/webcheck](../../shell/ext/webcheck) | 81 | [shell/ext/webcheck/dirs](../../shell/ext/webcheck/dirs) | — | — |
| [shell/ext/webcheck/dialtest](../../shell/ext/webcheck/dialtest) | 3 | [shell/ext/webcheck/dialtest/sources](../../shell/ext/webcheck/dialtest/sources), [shell/ext/webcheck/dialtest/makefile](../../shell/ext/webcheck/dialtest/makefile) | `dialtest` | `PROGRAM` |
| [shell/ext/webcheck/dll](../../shell/ext/webcheck/dll) | 4 | [shell/ext/webcheck/dll/sources](../../shell/ext/webcheck/dll/sources), [shell/ext/webcheck/dll/makefile](../../shell/ext/webcheck/dll/makefile) | `webcheck` | `DYNLINK` |
| [shell/ext/webcheck/ntapi](../../shell/ext/webcheck/ntapi) | 3 | [shell/ext/webcheck/ntapi/sources](../../shell/ext/webcheck/ntapi/sources), [shell/ext/webcheck/ntapi/makefile](../../shell/ext/webcheck/ntapi/makefile) | — | — |
| [shell/ext/webcheck/perf](../../shell/ext/webcheck/perf) | 1 | [shell/ext/webcheck/perf/dirs](../../shell/ext/webcheck/perf/dirs) | — | — |
| [shell/ext/webcheck/perf/webckdn](../../shell/ext/webcheck/perf/webckdn) | 8 | [shell/ext/webcheck/perf/webckdn/sources](../../shell/ext/webcheck/perf/webckdn/sources), [shell/ext/webcheck/perf/webckdn/makefile](../../shell/ext/webcheck/perf/webckdn/makefile) | `webckdn` | `PROGRAM` |
| [shell/ext/webcheck/res](../../shell/ext/webcheck/res) | 23 | — | — | — |
| [shell/ext/webcheck/resdll](../../shell/ext/webcheck/resdll) | 2 | [shell/ext/webcheck/resdll/sources](../../shell/ext/webcheck/resdll/sources), [shell/ext/webcheck/resdll/makefile](../../shell/ext/webcheck/resdll/makefile) | `webchklc` | `DYNLINK` |
| [shell/ext/webcheck/test](../../shell/ext/webcheck/test) | 3 | [shell/ext/webcheck/test/sources](../../shell/ext/webcheck/test/sources) | `testapp` | `PROGRAM` |
| [shell/ext/webcheck/test/autosub](../../shell/ext/webcheck/test/autosub) | 6 | [shell/ext/webcheck/test/autosub/sources](../../shell/ext/webcheck/test/autosub/sources), [shell/ext/webcheck/test/autosub/makefile](../../shell/ext/webcheck/test/autosub/makefile) | `autosub` | `PROGRAM` |
| [shell/ext/webcheck/test/dhcmpmrg](../../shell/ext/webcheck/test/dhcmpmrg) | 4 | [shell/ext/webcheck/test/dhcmpmrg/sources](../../shell/ext/webcheck/test/dhcmpmrg/sources), [shell/ext/webcheck/test/dhcmpmrg/makefile](../../shell/ext/webcheck/test/dhcmpmrg/makefile) | `dhcmpmrg` | `PROGRAM` |
| [shell/ext/webcheck/test/notfcvt](../../shell/ext/webcheck/test/notfcvt) | 4 | [shell/ext/webcheck/test/notfcvt/sources](../../shell/ext/webcheck/test/notfcvt/sources), [shell/ext/webcheck/test/notfcvt/makefile](../../shell/ext/webcheck/test/notfcvt/makefile) | `notfcvt` | `PROGRAM` |
| [shell/ext/webcheck/test/ripsubs](../../shell/ext/webcheck/test/ripsubs) | 11 | [shell/ext/webcheck/test/ripsubs/sources](../../shell/ext/webcheck/test/ripsubs/sources), [shell/ext/webcheck/test/ripsubs/makefile](../../shell/ext/webcheck/test/ripsubs/makefile) | `ripsubs` | `PROGRAM` |
| [shell/ext/webcheck/test/schedcdf](../../shell/ext/webcheck/test/schedcdf) | 5 | [shell/ext/webcheck/test/schedcdf/sources](../../shell/ext/webcheck/test/schedcdf/sources), [shell/ext/webcheck/test/schedcdf/makefile](../../shell/ext/webcheck/test/schedcdf/makefile) | `schedcdf` | `PROGRAM` |
| [shell/ext/webcheck/test/trackvw](../../shell/ext/webcheck/test/trackvw) | 5 | [shell/ext/webcheck/test/trackvw/sources](../../shell/ext/webcheck/test/trackvw/sources), [shell/ext/webcheck/test/trackvw/makefile](../../shell/ext/webcheck/test/trackvw/makefile) | `trackvw` | `PROGRAM` |
| [shell/ext/webcheck/test/upnow](../../shell/ext/webcheck/test/upnow) | 4 | [shell/ext/webcheck/test/upnow/sources](../../shell/ext/webcheck/test/upnow/sources), [shell/ext/webcheck/test/upnow/makefile](../../shell/ext/webcheck/test/upnow/makefile) | `upnow` | `PROGRAM` |
| [shell/ext/webfldrs](../../shell/ext/webfldrs) | 3 | [shell/ext/webfldrs/dirs](../../shell/ext/webfldrs/dirs) | — | — |
| [shell/ext/webfldrs/ara](../../shell/ext/webfldrs/ara) | 2 | [shell/ext/webfldrs/ara/sources](../../shell/ext/webfldrs/ara/sources), [shell/ext/webfldrs/ara/makefile](../../shell/ext/webfldrs/ara/makefile) | — | — |
| [shell/ext/webfldrs/ara/i386](../../shell/ext/webfldrs/ara/i386) | 1 | — | — | — |
| [shell/ext/webfldrs/binaries](../../shell/ext/webfldrs/binaries) | 2 | [shell/ext/webfldrs/binaries/sources](../../shell/ext/webfldrs/binaries/sources), [shell/ext/webfldrs/binaries/makefile](../../shell/ext/webfldrs/binaries/makefile) | — | `NOTARGET` |
| [shell/ext/webfldrs/chs](../../shell/ext/webfldrs/chs) | 2 | [shell/ext/webfldrs/chs/sources](../../shell/ext/webfldrs/chs/sources), [shell/ext/webfldrs/chs/makefile](../../shell/ext/webfldrs/chs/makefile) | — | — |
| [shell/ext/webfldrs/chs/i386](../../shell/ext/webfldrs/chs/i386) | 1 | — | — | — |
| [shell/ext/webfldrs/cht](../../shell/ext/webfldrs/cht) | 2 | [shell/ext/webfldrs/cht/sources](../../shell/ext/webfldrs/cht/sources), [shell/ext/webfldrs/cht/makefile](../../shell/ext/webfldrs/cht/makefile) | — | — |
| [shell/ext/webfldrs/cht/i386](../../shell/ext/webfldrs/cht/i386) | 1 | — | — | — |
| [shell/ext/webfldrs/ger](../../shell/ext/webfldrs/ger) | 2 | [shell/ext/webfldrs/ger/sources](../../shell/ext/webfldrs/ger/sources), [shell/ext/webfldrs/ger/makefile](../../shell/ext/webfldrs/ger/makefile) | — | — |
| [shell/ext/webfldrs/ger/i386](../../shell/ext/webfldrs/ger/i386) | 1 | — | — | — |
| [shell/ext/webfldrs/heb](../../shell/ext/webfldrs/heb) | 2 | [shell/ext/webfldrs/heb/sources](../../shell/ext/webfldrs/heb/sources), [shell/ext/webfldrs/heb/makefile](../../shell/ext/webfldrs/heb/makefile) | — | — |
| [shell/ext/webfldrs/heb/i386](../../shell/ext/webfldrs/heb/i386) | 1 | — | — | — |
| [shell/ext/webfldrs/jpn](../../shell/ext/webfldrs/jpn) | 2 | [shell/ext/webfldrs/jpn/sources](../../shell/ext/webfldrs/jpn/sources), [shell/ext/webfldrs/jpn/makefile](../../shell/ext/webfldrs/jpn/makefile) | — | — |
| [shell/ext/webfldrs/jpn/i386](../../shell/ext/webfldrs/jpn/i386) | 1 | — | — | — |
| [shell/ext/webfldrs/kor](../../shell/ext/webfldrs/kor) | 2 | [shell/ext/webfldrs/kor/sources](../../shell/ext/webfldrs/kor/sources), [shell/ext/webfldrs/kor/makefile](../../shell/ext/webfldrs/kor/makefile) | — | — |
| [shell/ext/webfldrs/kor/i386](../../shell/ext/webfldrs/kor/i386) | 1 | — | — | — |
| [shell/ext/webfldrs/usa](../../shell/ext/webfldrs/usa) | 2 | [shell/ext/webfldrs/usa/sources](../../shell/ext/webfldrs/usa/sources), [shell/ext/webfldrs/usa/makefile](../../shell/ext/webfldrs/usa/makefile) | — | — |
| [shell/ext/webfldrs/usa/i386](../../shell/ext/webfldrs/usa/i386) | 3 | — | — | — |
| [shell/ext/webvw](../../shell/ext/webvw) | 42 | [shell/ext/webvw/dirs](../../shell/ext/webvw/dirs) | — | — |
| [shell/ext/webvw/activedesktop](../../shell/ext/webvw/activedesktop) | 6 | [shell/ext/webvw/activedesktop/sources](../../shell/ext/webvw/activedesktop/sources), [shell/ext/webvw/activedesktop/makefile](../../shell/ext/webvw/activedesktop/makefile) | — | `NOTARGET` |
| [shell/ext/webvw/dll](../../shell/ext/webvw/dll) | 4 | [shell/ext/webvw/dll/sources](../../shell/ext/webvw/dll/sources), [shell/ext/webvw/dll/makefile](../../shell/ext/webvw/dll/makefile) | `webvw` | `DYNLINK` |
| [shell/ext/webvw/rc](../../shell/ext/webvw/rc) | 2 | — | — | — |
| [shell/ext/wizhost](../../shell/ext/wizhost) | 7 | [shell/ext/wizhost/sources](../../shell/ext/wizhost/sources), [shell/ext/wizhost/makefile](../../shell/ext/wizhost/makefile) | `wizhost` | `PROGRAM` |
| [shell/ext/zaxxon](../../shell/ext/zaxxon) | 29 | [shell/ext/zaxxon/dirs](../../shell/ext/zaxxon/dirs) | — | — |
| [shell/ext/zaxxon/dll](../../shell/ext/zaxxon/dll) | 3 | [shell/ext/zaxxon/dll/sources](../../shell/ext/zaxxon/dll/sources), [shell/ext/zaxxon/dll/makefile](../../shell/ext/zaxxon/dll/makefile) | — | — |

## `shell/iecontrols/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [shell/iecontrols](../../shell/iecontrols) | 2 | [shell/iecontrols/dirs](../../shell/iecontrols/dirs) | — | — |
| [shell/iecontrols/framewrk](../../shell/iecontrols/framewrk) | 26 | [shell/iecontrols/framewrk/sources](../../shell/iecontrols/framewrk/sources), [shell/iecontrols/framewrk/makefile](../../shell/iecontrols/framewrk/makefile) | `CtlFwLib` | `LIBRARY` |
| [shell/iecontrols/inc](../../shell/iecontrols/inc) | 19 | — | — | — |
| [shell/iecontrols/licmgr](../../shell/iecontrols/licmgr) | 2 | [shell/iecontrols/licmgr/dirs](../../shell/iecontrols/licmgr/dirs) | — | — |
| [shell/iecontrols/licmgr/core](../../shell/iecontrols/licmgr/core) | 8 | [shell/iecontrols/licmgr/core/sources](../../shell/iecontrols/licmgr/core/sources), [shell/iecontrols/licmgr/core/makefile](../../shell/iecontrols/licmgr/core/makefile) | `core` | `LIBRARY` |
| [shell/iecontrols/licmgr/core/include](../../shell/iecontrols/licmgr/core/include) | 8 | — | — | — |
| [shell/iecontrols/licmgr/mgr](../../shell/iecontrols/licmgr/mgr) | 9 | [shell/iecontrols/licmgr/mgr/sources](../../shell/iecontrols/licmgr/mgr/sources), [shell/iecontrols/licmgr/mgr/makefile](../../shell/iecontrols/licmgr/mgr/makefile) | `licmgr10` | `DYNLINK` |
| [shell/iecontrols/licmgr/mgr/include](../../shell/iecontrols/licmgr/mgr/include) | 6 | — | — | — |

## `shell/iexplore/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [shell/iexplore](../../shell/iexplore) | 39 | [shell/iexplore/sources](../../shell/iexplore/sources), [shell/iexplore/makefile](../../shell/iexplore/makefile) | `iexplore` | `PROGRAM` |
| [shell/iexplore/vbtest](../../shell/iexplore/vbtest) | 6 | — | — | — |
| [shell/iexplore/vbviewer](../../shell/iexplore/vbviewer) | 4 | — | — | — |

## `shell/inc/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [shell/inc](../../shell/inc) | 130 | — | — | — |
| [shell/inc/evtmon](../../shell/inc/evtmon) | 16 | — | — | — |
| [shell/inc/stubs](../../shell/inc/stubs) | 11 | — | — | — |
| [shell/inc/win95](../../shell/inc/win95) | 10 | — | — | — |

## `shell/lcinf/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [shell/lcinf](../../shell/lcinf) | 35 | — | — | — |

## `shell/lib/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [shell/lib](../../shell/lib) | 45 | [shell/lib/dirs](../../shell/lib/dirs) | — | — |
| [shell/lib/badapps](../../shell/lib/badapps) | 9 | [shell/lib/badapps/dirs](../../shell/lib/badapps/dirs) | — | — |
| [shell/lib/badapps/win95](../../shell/lib/badapps/win95) | 3 | [shell/lib/badapps/win95/sources](../../shell/lib/badapps/win95/sources), [shell/lib/badapps/win95/makefile](../../shell/lib/badapps/win95/makefile) | `badappsa` | — |
| [shell/lib/badapps/winnt](../../shell/lib/badapps/winnt) | 3 | [shell/lib/badapps/winnt/sources](../../shell/lib/badapps/winnt/sources), [shell/lib/badapps/winnt/makefile](../../shell/lib/badapps/winnt/makefile) | `badappsu` | — |
| [shell/lib/generic](../../shell/lib/generic) | 29 | [shell/lib/generic/sources](../../shell/lib/generic/sources), [shell/lib/generic/makefile](../../shell/lib/generic/makefile) | `generic` | `LIBRARY` |
| [shell/lib/i386](../../shell/lib/i386) | 7 | — | — | — |
| [shell/lib/ieguid](../../shell/lib/ieguid) | 4 | [shell/lib/ieguid/sources](../../shell/lib/ieguid/sources), [shell/lib/ieguid/makefile](../../shell/lib/ieguid/makefile) | — | `NOTARGET` |
| [shell/lib/inetutil](../../shell/lib/inetutil) | 3 | [shell/lib/inetutil/sources](../../shell/lib/inetutil/sources), [shell/lib/inetutil/makefile](../../shell/lib/inetutil/makefile) | `inetutil` | `LIBRARY` |
| [shell/lib/secutil](../../shell/lib/secutil) | 5 | [shell/lib/secutil/sources](../../shell/lib/secutil/sources), [shell/lib/secutil/makefile](../../shell/lib/secutil/makefile) | `secutil` | `LIBRARY` |
| [shell/lib/shfusion](../../shell/lib/shfusion) | 4 | [shell/lib/shfusion/dirs](../../shell/lib/shfusion/dirs) | — | — |
| [shell/lib/shfusion/ansi](../../shell/lib/shfusion/ansi) | 3 | [shell/lib/shfusion/ansi/sources](../../shell/lib/shfusion/ansi/sources), [shell/lib/shfusion/ansi/makefile](../../shell/lib/shfusion/ansi/makefile) | `shfusionA` | `LIBRARY` |
| [shell/lib/shfusion/cc](../../shell/lib/shfusion/cc) | 3 | [shell/lib/shfusion/cc/sources](../../shell/lib/shfusion/cc/sources), [shell/lib/shfusion/cc/makefile](../../shell/lib/shfusion/cc/makefile) | `shfusioncc` | `LIBRARY` |
| [shell/lib/shfusion/downlevel](../../shell/lib/shfusion/downlevel) | 3 | [shell/lib/shfusion/downlevel/sources](../../shell/lib/shfusion/downlevel/sources), [shell/lib/shfusion/downlevel/makefile](../../shell/lib/shfusion/downlevel/makefile) | `shfusion4` | `LIBRARY` |
| [shell/lib/shfusion/native](../../shell/lib/shfusion/native) | 3 | [shell/lib/shfusion/native/sources](../../shell/lib/shfusion/native/sources), [shell/lib/shfusion/native/makefile](../../shell/lib/shfusion/native/makefile) | `shfusion` | `LIBRARY` |
| [shell/lib/shguid](../../shell/lib/shguid) | 5 | [shell/lib/shguid/sources](../../shell/lib/shguid/sources), [shell/lib/shguid/makefile](../../shell/lib/shguid/makefile) | — | `NOTARGET` |
| [shell/lib/stock](../../shell/lib/stock) | 3 | [shell/lib/stock/sources](../../shell/lib/stock/sources), [shell/lib/stock/makefile](../../shell/lib/stock/makefile) | `stock` | — |
| [shell/lib/stock4](../../shell/lib/stock4) | 3 | [shell/lib/stock4/sources](../../shell/lib/stock4/sources), [shell/lib/stock4/makefile](../../shell/lib/stock4/makefile) | `stock4` | — |
| [shell/lib/stock4sxs](../../shell/lib/stock4sxs) | 1 | [shell/lib/stock4sxs/makefile](../../shell/lib/stock4sxs/makefile) | — | — |
| [shell/lib/stocksxs](../../shell/lib/stocksxs) | 1 | [shell/lib/stocksxs/makefile](../../shell/lib/stocksxs/makefile) | — | — |
| [shell/lib/stockthk](../../shell/lib/stockthk) | 3 | [shell/lib/stockthk/sources](../../shell/lib/stockthk/sources), [shell/lib/stockthk/makefile](../../shell/lib/stockthk/makefile) | `stockthk` | `LIBRARY` |
| [shell/lib/xml](../../shell/lib/xml) | 3 | [shell/lib/xml/sources](../../shell/lib/xml/sources), [shell/lib/xml/makefile](../../shell/lib/xml/makefile) | `xml` | `LIBRARY` |

## `shell/osshell/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [shell/osshell](../../shell/osshell) | 1 | [shell/osshell/dirs](../../shell/osshell/dirs) | — | — |
| [shell/osshell/accesory](../../shell/osshell/accesory) | 1 | [shell/osshell/accesory/dirs](../../shell/osshell/accesory/dirs) | — | — |
| [shell/osshell/accesory/access](../../shell/osshell/accesory/access) | 1 | [shell/osshell/accesory/access/dirs](../../shell/osshell/accesory/access/dirs) | — | — |
| [shell/osshell/accesory/access/access](../../shell/osshell/accesory/access/access) | 21 | [shell/osshell/accesory/access/access/sources](../../shell/osshell/accesory/access/access/sources), [shell/osshell/accesory/access/access/makefile](../../shell/osshell/accesory/access/access/makefile) | `access` | `PROGRAM` |
| [shell/osshell/accesory/access/inc](../../shell/osshell/accesory/access/inc) | 2 | — | — | — |
| [shell/osshell/accesory/access/skdll](../../shell/osshell/accesory/access/skdll) | 5 | [shell/osshell/accesory/access/skdll/sources](../../shell/osshell/accesory/access/skdll/sources), [shell/osshell/accesory/access/skdll/makefile](../../shell/osshell/accesory/access/skdll/makefile) | `skdll` | `DYNLINK` |
| [shell/osshell/accesory/access/skeys](../../shell/osshell/accesory/access/skeys) | 32 | [shell/osshell/accesory/access/skeys/sources](../../shell/osshell/accesory/access/skeys/sources), [shell/osshell/accesory/access/skeys/makefile](../../shell/osshell/accesory/access/skeys/makefile) | `skeys` | `PROGRAM` |
| [shell/osshell/accesory/calc](../../shell/osshell/accesory/calc) | 27 | [shell/osshell/accesory/calc/dirs](../../shell/osshell/accesory/calc/dirs) | — | — |
| [shell/osshell/accesory/calc/nt](../../shell/osshell/accesory/calc/nt) | 3 | [shell/osshell/accesory/calc/nt/sources](../../shell/osshell/accesory/calc/nt/sources), [shell/osshell/accesory/calc/nt/makefile](../../shell/osshell/accesory/calc/nt/makefile) | `calc` | `PROGRAM` |
| [shell/osshell/accesory/calc/win95](../../shell/osshell/accesory/calc/win95) | 2 | [shell/osshell/accesory/calc/win95/sources](../../shell/osshell/accesory/calc/win95/sources), [shell/osshell/accesory/calc/win95/makefile](../../shell/osshell/accesory/calc/win95/makefile) | `calc` | `PROGRAM` |
| [shell/osshell/accesory/calendar](../../shell/osshell/accesory/calendar) | 33 | [shell/osshell/accesory/calendar/sources](../../shell/osshell/accesory/calendar/sources), [shell/osshell/accesory/calendar/makefile](../../shell/osshell/accesory/calendar/makefile) | `calendar` | `LIBRARY` |
| [shell/osshell/accesory/clipbook](../../shell/osshell/accesory/clipbook) | 1 | [shell/osshell/accesory/clipbook/dirs](../../shell/osshell/accesory/clipbook/dirs) | — | — |
| [shell/osshell/accesory/clipbook/clipview](../../shell/osshell/accesory/clipbook/clipview) | 62 | [shell/osshell/accesory/clipbook/clipview/sources](../../shell/osshell/accesory/clipbook/clipview/sources), [shell/osshell/accesory/clipbook/clipview/makefile](../../shell/osshell/accesory/clipbook/clipview/makefile) | `CLIPBRD` | `PROGRAM` |
| [shell/osshell/accesory/clipbook/clipview/messages](../../shell/osshell/accesory/clipbook/clipview/messages) | 0 | — | — | — |
| [shell/osshell/accesory/clipbook/clipview/messages/usa](../../shell/osshell/accesory/clipbook/clipview/messages/usa) | 2 | — | — | — |
| [shell/osshell/accesory/clipbook/common](../../shell/osshell/accesory/clipbook/common) | 14 | [shell/osshell/accesory/clipbook/common/sources](../../shell/osshell/accesory/clipbook/common/sources), [shell/osshell/accesory/clipbook/common/makefile](../../shell/osshell/accesory/clipbook/common/makefile) | `common` | `LIBRARY` |
| [shell/osshell/accesory/clipbook/datasrv](../../shell/osshell/accesory/clipbook/datasrv) | 20 | [shell/osshell/accesory/clipbook/datasrv/sources](../../shell/osshell/accesory/clipbook/datasrv/sources), [shell/osshell/accesory/clipbook/datasrv/makefile](../../shell/osshell/accesory/clipbook/datasrv/makefile) | `dummy` | `LIBRARY` |
| [shell/osshell/accesory/clipbrd](../../shell/osshell/accesory/clipbrd) | 13 | [shell/osshell/accesory/clipbrd/sources](../../shell/osshell/accesory/clipbrd/sources), [shell/osshell/accesory/clipbrd/makefile](../../shell/osshell/accesory/clipbrd/makefile) | `clipbrd` | `PROGRAM` |
| [shell/osshell/accesory/clock](../../shell/osshell/accesory/clock) | 8 | [shell/osshell/accesory/clock/sources](../../shell/osshell/accesory/clock/sources), [shell/osshell/accesory/clock/makefile](../../shell/osshell/accesory/clock/makefile) | `clock` | `PROGRAM` |
| [shell/osshell/accesory/common](../../shell/osshell/accesory/common) | 12 | [shell/osshell/accesory/common/sources](../../shell/osshell/accesory/common/sources), [shell/osshell/accesory/common/makefile](../../shell/osshell/accesory/common/makefile) | `common` | `LIBRARY` |
| [shell/osshell/accesory/eudcedit](../../shell/osshell/accesory/eudcedit) | 65 | [shell/osshell/accesory/eudcedit/dirs](../../shell/osshell/accesory/eudcedit/dirs) | — | — |
| [shell/osshell/accesory/eudcedit/res](../../shell/osshell/accesory/eudcedit/res) | 28 | — | — | — |
| [shell/osshell/accesory/eudcedit/win95](../../shell/osshell/accesory/eudcedit/win95) | 2 | [shell/osshell/accesory/eudcedit/win95/sources](../../shell/osshell/accesory/eudcedit/win95/sources), [shell/osshell/accesory/eudcedit/win95/makefile](../../shell/osshell/accesory/eudcedit/win95/makefile) | — | — |
| [shell/osshell/accesory/eudcedit/winnt](../../shell/osshell/accesory/eudcedit/winnt) | 2 | [shell/osshell/accesory/eudcedit/winnt/sources](../../shell/osshell/accesory/eudcedit/winnt/sources), [shell/osshell/accesory/eudcedit/winnt/makefile](../../shell/osshell/accesory/eudcedit/winnt/makefile) | — | — |
| [shell/osshell/accesory/hypertrm](../../shell/osshell/accesory/hypertrm) | 7 | [shell/osshell/accesory/hypertrm/dirs](../../shell/osshell/accesory/hypertrm/dirs) | — | — |
| [shell/osshell/accesory/hypertrm/bin](../../shell/osshell/accesory/hypertrm/bin) | 2 | — | — | — |
| [shell/osshell/accesory/hypertrm/cnctstd](../../shell/osshell/accesory/hypertrm/cnctstd) | 7 | [shell/osshell/accesory/hypertrm/cnctstd/sources](../../shell/osshell/accesory/hypertrm/cnctstd/sources), [shell/osshell/accesory/hypertrm/cnctstd/makefile](../../shell/osshell/accesory/hypertrm/cnctstd/makefile) | `CNCTSTD` | `LIBRARY` |
| [shell/osshell/accesory/hypertrm/cncttapi](../../shell/osshell/accesory/hypertrm/cncttapi) | 15 | [shell/osshell/accesory/hypertrm/cncttapi/sources](../../shell/osshell/accesory/hypertrm/cncttapi/sources), [shell/osshell/accesory/hypertrm/cncttapi/makefile](../../shell/osshell/accesory/hypertrm/cncttapi/makefile) | `CNCTTAPI` | `LIBRARY` |
| [shell/osshell/accesory/hypertrm/comstd](../../shell/osshell/accesory/hypertrm/comstd) | 8 | [shell/osshell/accesory/hypertrm/comstd/sources](../../shell/osshell/accesory/hypertrm/comstd/sources), [shell/osshell/accesory/hypertrm/comstd/makefile](../../shell/osshell/accesory/hypertrm/comstd/makefile) | `COMSTD` | `LIBRARY` |
| [shell/osshell/accesory/hypertrm/comwsock](../../shell/osshell/accesory/hypertrm/comwsock) | 5 | [shell/osshell/accesory/hypertrm/comwsock/sources](../../shell/osshell/accesory/hypertrm/comwsock/sources), [shell/osshell/accesory/hypertrm/comwsock/makefile](../../shell/osshell/accesory/hypertrm/comwsock/makefile) | `COMWSOCK` | `LIBRARY` |
| [shell/osshell/accesory/hypertrm/emu](../../shell/osshell/accesory/hypertrm/emu) | 50 | [shell/osshell/accesory/hypertrm/emu/sources](../../shell/osshell/accesory/hypertrm/emu/sources), [shell/osshell/accesory/hypertrm/emu/makefile](../../shell/osshell/accesory/hypertrm/emu/makefile) | `EMU` | `LIBRARY` |
| [shell/osshell/accesory/hypertrm/ext](../../shell/osshell/accesory/hypertrm/ext) | 10 | [shell/osshell/accesory/hypertrm/ext/sources](../../shell/osshell/accesory/hypertrm/ext/sources), [shell/osshell/accesory/hypertrm/ext/makefile](../../shell/osshell/accesory/hypertrm/ext/makefile) | `hticons` | `DYNLINK` |
| [shell/osshell/accesory/hypertrm/ext2](../../shell/osshell/accesory/hypertrm/ext2) | 3 | [shell/osshell/accesory/hypertrm/ext2/sources](../../shell/osshell/accesory/hypertrm/ext2/sources), [shell/osshell/accesory/hypertrm/ext2/makefile](../../shell/osshell/accesory/hypertrm/ext2/makefile) | `EXT2` | `LIBRARY` |
| [shell/osshell/accesory/hypertrm/help](../../shell/osshell/accesory/hypertrm/help) | 8 | — | — | — |
| [shell/osshell/accesory/hypertrm/htrn_jis](../../shell/osshell/accesory/hypertrm/htrn_jis) | 10 | [shell/osshell/accesory/hypertrm/htrn_jis/sources](../../shell/osshell/accesory/hypertrm/htrn_jis/sources), [shell/osshell/accesory/hypertrm/htrn_jis/makefile](../../shell/osshell/accesory/hypertrm/htrn_jis/makefile) | `htrn_jis` | `DYNLINK` |
| [shell/osshell/accesory/hypertrm/tdll](../../shell/osshell/accesory/hypertrm/tdll) | 157 | [shell/osshell/accesory/hypertrm/tdll/sources](../../shell/osshell/accesory/hypertrm/tdll/sources), [shell/osshell/accesory/hypertrm/tdll/makefile](../../shell/osshell/accesory/hypertrm/tdll/makefile) | `HYPERTRM` | `DYNLINK` |
| [shell/osshell/accesory/hypertrm/term](../../shell/osshell/accesory/hypertrm/term) | 91 | [shell/osshell/accesory/hypertrm/term/sources](../../shell/osshell/accesory/hypertrm/term/sources), [shell/osshell/accesory/hypertrm/term/makefile](../../shell/osshell/accesory/hypertrm/term/makefile) | `HYPERTRM` | `PROGRAM` |
| [shell/osshell/accesory/hypertrm/xfer](../../shell/osshell/accesory/hypertrm/xfer) | 58 | [shell/osshell/accesory/hypertrm/xfer/sources](../../shell/osshell/accesory/hypertrm/xfer/sources), [shell/osshell/accesory/hypertrm/xfer/makefile](../../shell/osshell/accesory/hypertrm/xfer/makefile) | `XFER` | `LIBRARY` |
| [shell/osshell/accesory/mspaint](../../shell/osshell/accesory/mspaint) | 111 | [shell/osshell/accesory/mspaint/dirs](../../shell/osshell/accesory/mspaint/dirs) | — | — |
| [shell/osshell/accesory/mspaint/ansi](../../shell/osshell/accesory/mspaint/ansi) | 2 | [shell/osshell/accesory/mspaint/ansi/sources](../../shell/osshell/accesory/mspaint/ansi/sources), [shell/osshell/accesory/mspaint/ansi/makefile](../../shell/osshell/accesory/mspaint/ansi/makefile) | — | — |
| [shell/osshell/accesory/mspaint/hlp](../../shell/osshell/accesory/mspaint/hlp) | 20 | — | — | — |
| [shell/osshell/accesory/mspaint/ofn](../../shell/osshell/accesory/mspaint/ofn) | 2 | [shell/osshell/accesory/mspaint/ofn/sources](../../shell/osshell/accesory/mspaint/ofn/sources), [shell/osshell/accesory/mspaint/ofn/makefile](../../shell/osshell/accesory/mspaint/ofn/makefile) | `ofn` | `LIBRARY` |
| [shell/osshell/accesory/mspaint/ofn_ansi](../../shell/osshell/accesory/mspaint/ofn_ansi) | 2 | [shell/osshell/accesory/mspaint/ofn_ansi/sources](../../shell/osshell/accesory/mspaint/ofn_ansi/sources), [shell/osshell/accesory/mspaint/ofn_ansi/makefile](../../shell/osshell/accesory/mspaint/ofn_ansi/makefile) | `ofn_ansi` | `LIBRARY` |
| [shell/osshell/accesory/mspaint/res](../../shell/osshell/accesory/mspaint/res) | 1 | — | — | — |
| [shell/osshell/accesory/mspaint/res/bitmaps](../../shell/osshell/accesory/mspaint/res/bitmaps) | 33 | — | — | — |
| [shell/osshell/accesory/mspaint/res/cursors](../../shell/osshell/accesory/mspaint/res/cursors) | 17 | — | — | — |
| [shell/osshell/accesory/mspaint/res/icons](../../shell/osshell/accesory/mspaint/res/icons) | 8 | — | — | — |
| [shell/osshell/accesory/mspaint/unicode](../../shell/osshell/accesory/mspaint/unicode) | 2 | [shell/osshell/accesory/mspaint/unicode/sources](../../shell/osshell/accesory/mspaint/unicode/sources), [shell/osshell/accesory/mspaint/unicode/makefile](../../shell/osshell/accesory/mspaint/unicode/makefile) | — | — |
| [shell/osshell/accesory/netclip](../../shell/osshell/accesory/netclip) | 3 | [shell/osshell/accesory/netclip/dirs](../../shell/osshell/accesory/netclip/dirs) | — | — |
| [shell/osshell/accesory/netclip/idl](../../shell/osshell/accesory/netclip/idl) | 3 | [shell/osshell/accesory/netclip/idl/sources](../../shell/osshell/accesory/netclip/idl/sources), [shell/osshell/accesory/netclip/idl/makefile](../../shell/osshell/accesory/netclip/idl/makefile) | — | `NOTARGET` |
| [shell/osshell/accesory/netclip/netclip](../../shell/osshell/accesory/netclip/netclip) | 35 | [shell/osshell/accesory/netclip/netclip/sources](../../shell/osshell/accesory/netclip/netclip/sources), [shell/osshell/accesory/netclip/netclip/makefile](../../shell/osshell/accesory/netclip/netclip/makefile) | `NetClip` | `PROGRAM` |
| [shell/osshell/accesory/netclip/proxy](../../shell/osshell/accesory/netclip/proxy) | 11 | [shell/osshell/accesory/netclip/proxy/sources](../../shell/osshell/accesory/netclip/proxy/sources), [shell/osshell/accesory/netclip/proxy/makefile](../../shell/osshell/accesory/netclip/proxy/makefile) | `nclipps` | `DYNLINK` |
| [shell/osshell/accesory/netclip/setup](../../shell/osshell/accesory/netclip/setup) | 6 | [shell/osshell/accesory/netclip/setup/makefile](../../shell/osshell/accesory/netclip/setup/makefile) | — | — |
| [shell/osshell/accesory/newpad](../../shell/osshell/accesory/newpad) | 21 | [shell/osshell/accesory/newpad/sources](../../shell/osshell/accesory/newpad/sources), [shell/osshell/accesory/newpad/makefile](../../shell/osshell/accesory/newpad/makefile) | `newpad` | `PROGRAM` |
| [shell/osshell/accesory/notepad](../../shell/osshell/accesory/notepad) | 18 | [shell/osshell/accesory/notepad/sources](../../shell/osshell/accesory/notepad/sources), [shell/osshell/accesory/notepad/makefile](../../shell/osshell/accesory/notepad/makefile) | `notepad` | `PROGRAM` |
| [shell/osshell/accesory/notepad/mkuni](../../shell/osshell/accesory/notepad/mkuni) | 6 | [shell/osshell/accesory/notepad/mkuni/sources](../../shell/osshell/accesory/notepad/mkuni/sources), [shell/osshell/accesory/notepad/mkuni/makefile](../../shell/osshell/accesory/notepad/mkuni/makefile) | `mkuni` | `PROGRAM` |
| [shell/osshell/accesory/notepad/testtext](../../shell/osshell/accesory/notepad/testtext) | 1 | — | — | — |
| [shell/osshell/accesory/packager](../../shell/osshell/accesory/packager) | 27 | [shell/osshell/accesory/packager/sources](../../shell/osshell/accesory/packager/sources), [shell/osshell/accesory/packager/makefile](../../shell/osshell/accesory/packager/makefile) | `packgr32` | `LIBRARY` |
| [shell/osshell/accesory/pbrush](../../shell/osshell/accesory/pbrush) | 9 | [shell/osshell/accesory/pbrush/sources](../../shell/osshell/accesory/pbrush/sources), [shell/osshell/accesory/pbrush/makefile](../../shell/osshell/accesory/pbrush/makefile) | `pbrush` | `PROGRAM` |
| [shell/osshell/accesory/quickres](../../shell/osshell/accesory/quickres) | 9 | [shell/osshell/accesory/quickres/sources](../../shell/osshell/accesory/quickres/sources), [shell/osshell/accesory/quickres/makefile](../../shell/osshell/accesory/quickres/makefile) | `QuickRes` | `PROGRAM` |
| [shell/osshell/accesory/ratpak](../../shell/osshell/accesory/ratpak) | 18 | [shell/osshell/accesory/ratpak/dirs](../../shell/osshell/accesory/ratpak/dirs) | — | — |
| [shell/osshell/accesory/ratpak/nt](../../shell/osshell/accesory/ratpak/nt) | 2 | [shell/osshell/accesory/ratpak/nt/sources](../../shell/osshell/accesory/ratpak/nt/sources), [shell/osshell/accesory/ratpak/nt/makefile](../../shell/osshell/accesory/ratpak/nt/makefile) | `ratpak` | `LIBRARY` |
| [shell/osshell/accesory/ratpak/win95](../../shell/osshell/accesory/ratpak/win95) | 2 | [shell/osshell/accesory/ratpak/win95/sources](../../shell/osshell/accesory/ratpak/win95/sources), [shell/osshell/accesory/ratpak/win95/makefile](../../shell/osshell/accesory/ratpak/win95/makefile) | `ratpak` | `LIBRARY` |
| [shell/osshell/accesory/spechars](../../shell/osshell/accesory/spechars) | 10 | [shell/osshell/accesory/spechars/sources](../../shell/osshell/accesory/spechars/sources) | `charmap` | `PROGRAM` |
| [shell/osshell/accesory/sublocal](../../shell/osshell/accesory/sublocal) | 4 | [shell/osshell/accesory/sublocal/sources](../../shell/osshell/accesory/sublocal/sources), [shell/osshell/accesory/sublocal/makefile](../../shell/osshell/accesory/sublocal/makefile) | `sublocal` | `PROGRAM` |
| [shell/osshell/accesory/terminal](../../shell/osshell/accesory/terminal) | 66 | [shell/osshell/accesory/terminal/sources](../../shell/osshell/accesory/terminal/sources), [shell/osshell/accesory/terminal/makefile](../../shell/osshell/accesory/terminal/makefile) | `terminal` | `PROGRAM` |
| [shell/osshell/accesory/uce](../../shell/osshell/accesory/uce) | 1 | [shell/osshell/accesory/uce/dirs](../../shell/osshell/accesory/uce/dirs) | — | — |
| [shell/osshell/accesory/uce/getuname](../../shell/osshell/accesory/uce/getuname) | 8 | [shell/osshell/accesory/uce/getuname/sources](../../shell/osshell/accesory/uce/getuname/sources), [shell/osshell/accesory/uce/getuname/makefile](../../shell/osshell/accesory/uce/getuname/makefile) | `GetUName` | `DYNLINK` |
| [shell/osshell/accesory/uce/inc](../../shell/osshell/accesory/uce/inc) | 1 | — | — | — |
| [shell/osshell/accesory/uce/uce](../../shell/osshell/accesory/uce/uce) | 32 | [shell/osshell/accesory/uce/uce/sources](../../shell/osshell/accesory/uce/uce/sources), [shell/osshell/accesory/uce/uce/makefile](../../shell/osshell/accesory/uce/uce/makefile) | `CharMap` | `PROGRAM` |
| [shell/osshell/accesory/uce/uce/data](../../shell/osshell/accesory/uce/uce/data) | 8 | — | — | — |
| [shell/osshell/accesory/ucharma2](../../shell/osshell/accesory/ucharma2) | 2 | [shell/osshell/accesory/ucharma2/sources](../../shell/osshell/accesory/ucharma2/sources) | `ucharmap` | `PROGRAM` |
| [shell/osshell/accesory/ucharmap](../../shell/osshell/accesory/ucharmap) | 12 | [shell/osshell/accesory/ucharmap/sources](../../shell/osshell/accesory/ucharmap/sources), [shell/osshell/accesory/ucharmap/makefile](../../shell/osshell/accesory/ucharmap/makefile) | `charmap` | `LIBRARY` |
| [shell/osshell/accesory/winchat](../../shell/osshell/accesory/winchat) | 23 | [shell/osshell/accesory/winchat/sources](../../shell/osshell/accesory/winchat/sources), [shell/osshell/accesory/winchat/makefile](../../shell/osshell/accesory/winchat/makefile) | `winchat` | `PROGRAM` |
| [shell/osshell/accesory/wordpad](../../shell/osshell/accesory/wordpad) | 85 | [shell/osshell/accesory/wordpad/sources](../../shell/osshell/accesory/wordpad/sources), [shell/osshell/accesory/wordpad/makefile](../../shell/osshell/accesory/wordpad/makefile) | `wordpad` | `PROGRAM` |
| [shell/osshell/accesory/wordpad/conv](../../shell/osshell/accesory/wordpad/conv) | 1 | — | — | — |
| [shell/osshell/accesory/wordpad/core](../../shell/osshell/accesory/wordpad/core) | 3 | — | — | — |
| [shell/osshell/accesory/wordpad/memphis](../../shell/osshell/accesory/wordpad/memphis) | 80 | [shell/osshell/accesory/wordpad/memphis/sources](../../shell/osshell/accesory/wordpad/memphis/sources), [shell/osshell/accesory/wordpad/memphis/makefile](../../shell/osshell/accesory/wordpad/memphis/makefile) | `wordpad` | `PROGRAM` |
| [shell/osshell/accesory/wordpad/res](../../shell/osshell/accesory/wordpad/res) | 22 | — | — | — |
| [shell/osshell/accesory/write](../../shell/osshell/accesory/write) | 5 | [shell/osshell/accesory/write/sources](../../shell/osshell/accesory/write/sources), [shell/osshell/accesory/write/makefile](../../shell/osshell/accesory/write/makefile) | `write` | `PROGRAM` |
| [shell/osshell/accessib](../../shell/osshell/accessib) | 1 | [shell/osshell/accessib/dirs](../../shell/osshell/accessib/dirs) | — | — |
| [shell/osshell/accessib/accwiz](../../shell/osshell/accessib/accwiz) | 75 | [shell/osshell/accessib/accwiz/dirs](../../shell/osshell/accessib/accwiz/dirs) | — | — |
| [shell/osshell/accessib/accwiz/win95](../../shell/osshell/accessib/accwiz/win95) | 2 | [shell/osshell/accessib/accwiz/win95/sources](../../shell/osshell/accessib/accwiz/win95/sources), [shell/osshell/accessib/accwiz/win95/makefile](../../shell/osshell/accessib/accwiz/win95/makefile) | — | — |
| [shell/osshell/accessib/accwiz/winnt](../../shell/osshell/accessib/accwiz/winnt) | 2 | [shell/osshell/accessib/accwiz/winnt/sources](../../shell/osshell/accessib/accwiz/winnt/sources), [shell/osshell/accessib/accwiz/winnt/makefile](../../shell/osshell/accessib/accwiz/winnt/makefile) | — | — |
| [shell/osshell/accessib/cursors](../../shell/osshell/accessib/cursors) | 114 | [shell/osshell/accessib/cursors/sources](../../shell/osshell/accessib/cursors/sources), [shell/osshell/accessib/cursors/makefile](../../shell/osshell/accessib/cursors/makefile) | — | `NOTARGET` |
| [shell/osshell/accessib/embedded](../../shell/osshell/accessib/embedded) | 9 | [shell/osshell/accessib/embedded/sources](../../shell/osshell/accessib/embedded/sources), [shell/osshell/accessib/embedded/makefile](../../shell/osshell/accessib/embedded/makefile) | — | `NOTARGET` |
| [shell/osshell/accessib/inc](../../shell/osshell/accessib/inc) | 7 | — | — | — |
| [shell/osshell/accessib/magnify](../../shell/osshell/accessib/magnify) | 4 | [shell/osshell/accessib/magnify/dirs](../../shell/osshell/accessib/magnify/dirs) | — | — |
| [shell/osshell/accessib/magnify/mag_hook](../../shell/osshell/accessib/magnify/mag_hook) | 10 | [shell/osshell/accessib/magnify/mag_hook/dirs](../../shell/osshell/accessib/magnify/mag_hook/dirs) | — | — |
| [shell/osshell/accessib/magnify/mag_hook/winnt](../../shell/osshell/accessib/magnify/mag_hook/winnt) | 2 | [shell/osshell/accessib/magnify/mag_hook/winnt/sources](../../shell/osshell/accessib/magnify/mag_hook/winnt/sources), [shell/osshell/accessib/magnify/mag_hook/winnt/makefile](../../shell/osshell/accessib/magnify/mag_hook/winnt/makefile) | — | — |
| [shell/osshell/accessib/magnify/magnify](../../shell/osshell/accessib/magnify/magnify) | 26 | [shell/osshell/accessib/magnify/magnify/dirs](../../shell/osshell/accessib/magnify/magnify/dirs) | — | — |
| [shell/osshell/accessib/magnify/magnify/res](../../shell/osshell/accessib/magnify/magnify/res) | 6 | — | — | — |
| [shell/osshell/accessib/magnify/magnify/winnt](../../shell/osshell/accessib/magnify/magnify/winnt) | 2 | [shell/osshell/accessib/magnify/magnify/winnt/sources](../../shell/osshell/accessib/magnify/magnify/winnt/sources), [shell/osshell/accessib/magnify/magnify/winnt/makefile](../../shell/osshell/accessib/magnify/magnify/winnt/makefile) | — | — |
| [shell/osshell/accessib/narrator](../../shell/osshell/accessib/narrator) | 2 | [shell/osshell/accessib/narrator/dirs](../../shell/osshell/accessib/narrator/dirs) | — | — |
| [shell/osshell/accessib/narrator/narrator](../../shell/osshell/accessib/narrator/narrator) | 13 | [shell/osshell/accessib/narrator/narrator/dirs](../../shell/osshell/accessib/narrator/narrator/dirs) | — | — |
| [shell/osshell/accessib/narrator/narrator/winnt](../../shell/osshell/accessib/narrator/narrator/winnt) | 2 | [shell/osshell/accessib/narrator/narrator/winnt/sources](../../shell/osshell/accessib/narrator/narrator/winnt/sources), [shell/osshell/accessib/narrator/narrator/winnt/makefile](../../shell/osshell/accessib/narrator/narrator/winnt/makefile) | — | — |
| [shell/osshell/accessib/narrator/narrhook](../../shell/osshell/accessib/narrator/narrhook) | 15 | [shell/osshell/accessib/narrator/narrhook/dirs](../../shell/osshell/accessib/narrator/narrhook/dirs) | — | — |
| [shell/osshell/accessib/narrator/narrhook/winnt](../../shell/osshell/accessib/narrator/narrhook/winnt) | 2 | [shell/osshell/accessib/narrator/narrhook/winnt/sources](../../shell/osshell/accessib/narrator/narrhook/winnt/sources), [shell/osshell/accessib/narrator/narrhook/winnt/makefile](../../shell/osshell/accessib/narrator/narrhook/winnt/makefile) | — | — |
| [shell/osshell/accessib/osk](../../shell/osshell/accessib/osk) | 3 | [shell/osshell/accessib/osk/dirs](../../shell/osshell/accessib/osk/dirs) | — | — |
| [shell/osshell/accessib/osk/inc](../../shell/osshell/accessib/osk/inc) | 21 | — | — | — |
| [shell/osshell/accessib/osk/msswch](../../shell/osshell/accessib/osk/msswch) | 1 | [shell/osshell/accessib/osk/msswch/dirs](../../shell/osshell/accessib/osk/msswch/dirs) | — | — |
| [shell/osshell/accessib/osk/msswch/msswch](../../shell/osshell/accessib/osk/msswch/msswch) | 18 | [shell/osshell/accessib/osk/msswch/msswch/sources](../../shell/osshell/accessib/osk/msswch/msswch/sources), [shell/osshell/accessib/osk/msswch/msswch/makefile](../../shell/osshell/accessib/osk/msswch/msswch/makefile) | `msswch` | `DYNLINK` |
| [shell/osshell/accessib/osk/msswch/msswchx](../../shell/osshell/accessib/osk/msswch/msswchx) | 7 | [shell/osshell/accessib/osk/msswch/msswchx/sources](../../shell/osshell/accessib/osk/msswch/msswchx/sources), [shell/osshell/accessib/osk/msswch/msswchx/makefile](../../shell/osshell/accessib/osk/msswch/msswchx/makefile) | `msswchx` | `PROGRAM` |
| [shell/osshell/accessib/osk/msswch/msswchy](../../shell/osshell/accessib/osk/msswch/msswchy) | 3 | — | — | — |
| [shell/osshell/accessib/osk/res](../../shell/osshell/accessib/osk/res) | 55 | — | — | — |
| [shell/osshell/accessib/osk/src](../../shell/osshell/accessib/osk/src) | 17 | [shell/osshell/accessib/osk/src/dirs](../../shell/osshell/accessib/osk/src/dirs) | — | — |
| [shell/osshell/accessib/osk/src/winnt](../../shell/osshell/accessib/osk/src/winnt) | 2 | [shell/osshell/accessib/osk/src/winnt/sources](../../shell/osshell/accessib/osk/src/winnt/sources), [shell/osshell/accessib/osk/src/winnt/makefile](../../shell/osshell/accessib/osk/src/winnt/makefile) | `osk` | `PROGRAM` |
| [shell/osshell/accessib/utilman](../../shell/osshell/accessib/utilman) | 14 | [shell/osshell/accessib/utilman/dirs](../../shell/osshell/accessib/utilman/dirs) | — | — |
| [shell/osshell/accessib/utilman/umandlg](../../shell/osshell/accessib/utilman/umandlg) | 14 | [shell/osshell/accessib/utilman/umandlg/sources](../../shell/osshell/accessib/utilman/umandlg/sources), [shell/osshell/accessib/utilman/umandlg/makefile](../../shell/osshell/accessib/utilman/umandlg/makefile) | `UManDlg` | `DYNLINK` |
| [shell/osshell/accessib/utilman/utilman](../../shell/osshell/accessib/utilman/utilman) | 9 | [shell/osshell/accessib/utilman/utilman/sources](../../shell/osshell/accessib/utilman/utilman/sources), [shell/osshell/accessib/utilman/utilman/makefile](../../shell/osshell/accessib/utilman/utilman/makefile) | `UtilMan` | `PROGRAM` |
| [shell/osshell/control](../../shell/osshell/control) | 3 | [shell/osshell/control/dirs](../../shell/osshell/control/dirs) | — | — |
| [shell/osshell/control/bitmaps](../../shell/osshell/control/bitmaps) | 46 | [shell/osshell/control/bitmaps/sources](../../shell/osshell/control/bitmaps/sources), [shell/osshell/control/bitmaps/makefile](../../shell/osshell/control/bitmaps/makefile) | — | `NOTARGET` |
| [shell/osshell/control/console](../../shell/osshell/control/console) | 19 | [shell/osshell/control/console/sources](../../shell/osshell/control/console/sources), [shell/osshell/control/console/makefile](../../shell/osshell/control/console/makefile) | `console` | `DYNLINK` |
| [shell/osshell/control/cursors](../../shell/osshell/control/cursors) | 0 | — | — | — |
| [shell/osshell/control/cursors/anis](../../shell/osshell/control/cursors/anis) | 76 | — | — | — |
| [shell/osshell/control/cursors/anis/appstart](../../shell/osshell/control/cursors/anis/appstart) | 11 | — | — | — |
| [shell/osshell/control/cursors/anis/banana](../../shell/osshell/control/cursors/anis/banana) | 16 | — | — | — |
| [shell/osshell/control/cursors/anis/barber](../../shell/osshell/control/cursors/anis/barber) | 12 | — | — | — |
| [shell/osshell/control/cursors/anis/coin](../../shell/osshell/control/cursors/anis/coin) | 10 | — | — | — |
| [shell/osshell/control/cursors/anis/counter](../../shell/osshell/control/cursors/anis/counter) | 21 | — | — | — |
| [shell/osshell/control/cursors/anis/drum](../../shell/osshell/control/cursors/anis/drum) | 5 | — | — | — |
| [shell/osshell/control/cursors/anis/fillitup](../../shell/osshell/control/cursors/anis/fillitup) | 20 | — | — | — |
| [shell/osshell/control/cursors/anis/hand](../../shell/osshell/control/cursors/anis/hand) | 5 | — | — | — |
| [shell/osshell/control/cursors/anis/horse](../../shell/osshell/control/cursors/anis/horse) | 25 | — | — | — |
| [shell/osshell/control/cursors/anis/hourglas](../../shell/osshell/control/cursors/anis/hourglas) | 16 | — | — | — |
| [shell/osshell/control/cursors/anis/metronom](../../shell/osshell/control/cursors/anis/metronom) | 13 | — | — | — |
| [shell/osshell/control/cursors/anis/piano](../../shell/osshell/control/cursors/anis/piano) | 7 | — | — | — |
| [shell/osshell/control/cursors/anis/rainbow](../../shell/osshell/control/cursors/anis/rainbow) | 14 | — | — | — |
| [shell/osshell/control/cursors/anis/raindrop](../../shell/osshell/control/cursors/anis/raindrop) | 7 | — | — | — |
| [shell/osshell/control/cursors/anis/sizenesw](../../shell/osshell/control/cursors/anis/sizenesw) | 3 | — | — | — |
| [shell/osshell/control/cursors/anis/sizens](../../shell/osshell/control/cursors/anis/sizens) | 3 | — | — | — |
| [shell/osshell/control/cursors/anis/sizenwse](../../shell/osshell/control/cursors/anis/sizenwse) | 3 | — | — | — |
| [shell/osshell/control/cursors/anis/sizewe](../../shell/osshell/control/cursors/anis/sizewe) | 3 | — | — | — |
| [shell/osshell/control/cursors/anis/stopwtch](../../shell/osshell/control/cursors/anis/stopwtch) | 10 | — | — | — |
| [shell/osshell/control/cursors/anis/vanisher](../../shell/osshell/control/cursors/anis/vanisher) | 6 | — | — | — |
| [shell/osshell/control/cursors/anis/wagtail](../../shell/osshell/control/cursors/anis/wagtail) | 8 | — | — | — |
| [shell/osshell/control/drivers](../../shell/osshell/control/drivers) | 17 | [shell/osshell/control/drivers/sources](../../shell/osshell/control/drivers/sources), [shell/osshell/control/drivers/makefile](../../shell/osshell/control/drivers/makefile) | `drivers` | `DYNLINK` |
| [shell/osshell/control/h](../../shell/osshell/control/h) | 2 | — | — | — |
| [shell/osshell/control/joy](../../shell/osshell/control/joy) | 22 | [shell/osshell/control/joy/sources](../../shell/osshell/control/joy/sources), [shell/osshell/control/joy/makefile](../../shell/osshell/control/joy/makefile) | `joy` | `DYNLINK` |
| [shell/osshell/control/midi](../../shell/osshell/control/midi) | 25 | [shell/osshell/control/midi/sources](../../shell/osshell/control/midi/sources), [shell/osshell/control/midi/makefile](../../shell/osshell/control/midi/makefile) | `midimap` | `DYNLINK` |
| [shell/osshell/control/mmsys](../../shell/osshell/control/mmsys) | 156 | [shell/osshell/control/mmsys/sources](../../shell/osshell/control/mmsys/sources), [shell/osshell/control/mmsys/makefile](../../shell/osshell/control/mmsys/makefile) | `mmsys` | `DYNLINK` |
| [shell/osshell/control/mmsys_5.1](../../shell/osshell/control/mmsys_5.1) | 1 | [shell/osshell/control/mmsys_5.1/dirs](../../shell/osshell/control/mmsys_5.1/dirs) | — | — |
| [shell/osshell/control/mmsys_5.1/idl](../../shell/osshell/control/mmsys_5.1/idl) | 4 | [shell/osshell/control/mmsys_5.1/idl/sources](../../shell/osshell/control/mmsys_5.1/idl/sources), [shell/osshell/control/mmsys_5.1/idl/makefile](../../shell/osshell/control/mmsys_5.1/idl/makefile) | `mmsys` | `LIBRARY` |
| [shell/osshell/control/mmsys_5.1/src](../../shell/osshell/control/mmsys_5.1/src) | 30 | [shell/osshell/control/mmsys_5.1/src/sources](../../shell/osshell/control/mmsys_5.1/src/sources), [shell/osshell/control/mmsys_5.1/src/makefile](../../shell/osshell/control/mmsys_5.1/src/makefile) | `mmsys` | `DYNLINK` |
| [shell/osshell/control/mmsys_5.1/src/res](../../shell/osshell/control/mmsys_5.1/src/res) | 31 | — | — | — |
| [shell/osshell/control/mmsys_5.1/vc](../../shell/osshell/control/mmsys_5.1/vc) | 2 | — | — | — |
| [shell/osshell/control/multimed](../../shell/osshell/control/multimed) | 8 | [shell/osshell/control/multimed/sources](../../shell/osshell/control/multimed/sources), [shell/osshell/control/multimed/makefile](../../shell/osshell/control/multimed/makefile) | `multimed` | `DYNLINK` |
| [shell/osshell/control/profile](../../shell/osshell/control/profile) | 10 | [shell/osshell/control/profile/sources](../../shell/osshell/control/profile/sources), [shell/osshell/control/profile/makefile](../../shell/osshell/control/profile/makefile) | `profile` | `DYNLINK` |
| [shell/osshell/control/schemes](../../shell/osshell/control/schemes) | 12 | [shell/osshell/control/schemes/sources](../../shell/osshell/control/schemes/sources), [shell/osshell/control/schemes/makefile](../../shell/osshell/control/schemes/makefile) | `cursors` | `DYNLINK` |
| [shell/osshell/control/scrnsave](../../shell/osshell/control/scrnsave) | 3 | [shell/osshell/control/scrnsave/dirs](../../shell/osshell/control/scrnsave/dirs) | — | — |
| [shell/osshell/control/scrnsave/bezier](../../shell/osshell/control/scrnsave/bezier) | 11 | [shell/osshell/control/scrnsave/bezier/sources](../../shell/osshell/control/scrnsave/bezier/sources), [shell/osshell/control/scrnsave/bezier/makefile](../../shell/osshell/control/scrnsave/bezier/makefile) | `ssbezier` | `UMAPPL_NOLIB` |
| [shell/osshell/control/scrnsave/common](../../shell/osshell/control/scrnsave/common) | 8 | [shell/osshell/control/scrnsave/common/dirs](../../shell/osshell/control/scrnsave/common/dirs) | — | — |
| [shell/osshell/control/scrnsave/common/scrnsave](../../shell/osshell/control/scrnsave/common/scrnsave) | 2 | [shell/osshell/control/scrnsave/common/scrnsave/sources](../../shell/osshell/control/scrnsave/common/scrnsave/sources), [shell/osshell/control/scrnsave/common/scrnsave/makefile](../../shell/osshell/control/scrnsave/common/scrnsave/makefile) | `scrnsave` | `LIBRARY` |
| [shell/osshell/control/scrnsave/common/scrnsavw](../../shell/osshell/control/scrnsave/common/scrnsavw) | 2 | [shell/osshell/control/scrnsave/common/scrnsavw/sources](../../shell/osshell/control/scrnsave/common/scrnsavw/sources), [shell/osshell/control/scrnsave/common/scrnsavw/makefile](../../shell/osshell/control/scrnsave/common/scrnsavw/makefile) | `scrnsavw` | `LIBRARY` |
| [shell/osshell/control/scrnsave/d3dsaver](../../shell/osshell/control/scrnsave/d3dsaver) | 7 | [shell/osshell/control/scrnsave/d3dsaver/sources](../../shell/osshell/control/scrnsave/d3dsaver/sources), [shell/osshell/control/scrnsave/d3dsaver/makefile](../../shell/osshell/control/scrnsave/d3dsaver/makefile) | `D3DSaver` | `LIBRARY` |
| [shell/osshell/control/scrnsave/default](../../shell/osshell/control/scrnsave/default) | 7 | [shell/osshell/control/scrnsave/default/sources](../../shell/osshell/control/scrnsave/default/sources), [shell/osshell/control/scrnsave/default/makefile](../../shell/osshell/control/scrnsave/default/makefile) | `scrnsave` | `UMAPPL_NOLIB` |
| [shell/osshell/control/scrnsave/dolphin](../../shell/osshell/control/scrnsave/dolphin) | 44 | [shell/osshell/control/scrnsave/dolphin/sources](../../shell/osshell/control/scrnsave/dolphin/sources), [shell/osshell/control/scrnsave/dolphin/makefile](../../shell/osshell/control/scrnsave/dolphin/makefile) | `ssdolphins` | `PROGRAM` |
| [shell/osshell/control/scrnsave/flowerbox](../../shell/osshell/control/scrnsave/flowerbox) | 10 | [shell/osshell/control/scrnsave/flowerbox/sources](../../shell/osshell/control/scrnsave/flowerbox/sources), [shell/osshell/control/scrnsave/flowerbox/makefile](../../shell/osshell/control/scrnsave/flowerbox/makefile) | `ssflwbox` | `PROGRAM` |
| [shell/osshell/control/scrnsave/flyingobjects](../../shell/osshell/control/scrnsave/flyingobjects) | 26 | [shell/osshell/control/scrnsave/flyingobjects/sources](../../shell/osshell/control/scrnsave/flyingobjects/sources), [shell/osshell/control/scrnsave/flyingobjects/makefile](../../shell/osshell/control/scrnsave/flyingobjects/makefile) | `ss3dfo` | `PROGRAM` |
| [shell/osshell/control/scrnsave/logon](../../shell/osshell/control/scrnsave/logon) | 20 | [shell/osshell/control/scrnsave/logon/sources](../../shell/osshell/control/scrnsave/logon/sources), [shell/osshell/control/scrnsave/logon/makefile](../../shell/osshell/control/scrnsave/logon/makefile) | `logon` | `UMAPPL_NOLIB` |
| [shell/osshell/control/scrnsave/marquee](../../shell/osshell/control/scrnsave/marquee) | 10 | [shell/osshell/control/scrnsave/marquee/sources](../../shell/osshell/control/scrnsave/marquee/sources), [shell/osshell/control/scrnsave/marquee/makefile](../../shell/osshell/control/scrnsave/marquee/makefile) | `ssmarque` | `UMAPPL_NOLIB` |
| [shell/osshell/control/scrnsave/museum](../../shell/osshell/control/scrnsave/museum) | 31 | [shell/osshell/control/scrnsave/museum/sources](../../shell/osshell/control/scrnsave/museum/sources), [shell/osshell/control/scrnsave/museum/makefile](../../shell/osshell/control/scrnsave/museum/makefile) | `ssmuseum` | `PROGRAM` |
| [shell/osshell/control/scrnsave/museum/res](../../shell/osshell/control/scrnsave/museum/res) | 7 | — | — | — |
| [shell/osshell/control/scrnsave/mystify](../../shell/osshell/control/scrnsave/mystify) | 9 | [shell/osshell/control/scrnsave/mystify/sources](../../shell/osshell/control/scrnsave/mystify/sources), [shell/osshell/control/scrnsave/mystify/makefile](../../shell/osshell/control/scrnsave/mystify/makefile) | `ssmyst` | `UMAPPL_NOLIB` |
| [shell/osshell/control/scrnsave/pipes](../../shell/osshell/control/scrnsave/pipes) | 36 | [shell/osshell/control/scrnsave/pipes/sources](../../shell/osshell/control/scrnsave/pipes/sources), [shell/osshell/control/scrnsave/pipes/makefile](../../shell/osshell/control/scrnsave/pipes/makefile) | `sspipes` | `PROGRAM` |
| [shell/osshell/control/scrnsave/stars](../../shell/osshell/control/scrnsave/stars) | 9 | [shell/osshell/control/scrnsave/stars/sources](../../shell/osshell/control/scrnsave/stars/sources), [shell/osshell/control/scrnsave/stars/makefile](../../shell/osshell/control/scrnsave/stars/makefile) | `ssstars` | `UMAPPL_NOLIB` |
| [shell/osshell/control/scrnsave/swoosh](../../shell/osshell/control/scrnsave/swoosh) | 11 | [shell/osshell/control/scrnsave/swoosh/sources](../../shell/osshell/control/scrnsave/swoosh/sources), [shell/osshell/control/scrnsave/swoosh/makefile](../../shell/osshell/control/scrnsave/swoosh/makefile) | `swoosh` | `PROGRAM` |
| [shell/osshell/control/scrnsave/swrast](../../shell/osshell/control/scrnsave/swrast) | 0 | — | — | — |
| [shell/osshell/control/scrnsave/swrast/obj](../../shell/osshell/control/scrnsave/swrast/obj) | 0 | — | — | — |
| [shell/osshell/control/scrnsave/swrast/obj/amd64](../../shell/osshell/control/scrnsave/swrast/obj/amd64) | 2 | — | — | — |
| [shell/osshell/control/scrnsave/text3d](../../shell/osshell/control/scrnsave/text3d) | 14 | [shell/osshell/control/scrnsave/text3d/sources](../../shell/osshell/control/scrnsave/text3d/sources), [shell/osshell/control/scrnsave/text3d/makefile](../../shell/osshell/control/scrnsave/text3d/makefile) | `sstext3d` | `PROGRAM` |
| [shell/osshell/control/sound](../../shell/osshell/control/sound) | 12 | [shell/osshell/control/sound/sources](../../shell/osshell/control/sound/sources), [shell/osshell/control/sound/makefile](../../shell/osshell/control/sound/makefile) | `sound` | `DYNLINK` |
| [shell/osshell/control/t1instal](../../shell/osshell/control/t1instal) | 53 | [shell/osshell/control/t1instal/sources](../../shell/osshell/control/t1instal/sources), [shell/osshell/control/t1instal/makefile](../../shell/osshell/control/t1instal/makefile) | `t1instal` | `DYNLINK` |
| [shell/osshell/control/ups](../../shell/osshell/control/ups) | 13 | [shell/osshell/control/ups/sources](../../shell/osshell/control/ups/sources), [shell/osshell/control/ups/makefile](../../shell/osshell/control/ups/makefile) | `ups` | `DYNLINK` |
| [shell/osshell/convgrp](../../shell/osshell/convgrp) | 5 | [shell/osshell/convgrp/sources](../../shell/osshell/convgrp/sources), [shell/osshell/convgrp/makefile](../../shell/osshell/convgrp/makefile) | `convgrp` | `PROGRAM` |
| [shell/osshell/cpls](../../shell/osshell/cpls) | 1 | [shell/osshell/cpls/dirs](../../shell/osshell/cpls/dirs) | — | — |
| [shell/osshell/cpls/access](../../shell/osshell/cpls/access) | 23 | [shell/osshell/cpls/access/sources](../../shell/osshell/cpls/access/sources), [shell/osshell/cpls/access/makefile](../../shell/osshell/cpls/access/makefile) | `access` | `DYNLINK` |
| [shell/osshell/cpls/access/res](../../shell/osshell/cpls/access/res) | 2 | — | — | — |
| [shell/osshell/cpls/alertpg](../../shell/osshell/cpls/alertpg) | 9 | [shell/osshell/cpls/alertpg/sources](../../shell/osshell/cpls/alertpg/sources), [shell/osshell/cpls/alertpg/makefile](../../shell/osshell/cpls/alertpg/makefile) | `sysdm` | `DYNLINK` |
| [shell/osshell/cpls/batmeter](../../shell/osshell/cpls/batmeter) | 14 | [shell/osshell/cpls/batmeter/dirs](../../shell/osshell/cpls/batmeter/dirs) | — | — |
| [shell/osshell/cpls/batmeter/test](../../shell/osshell/cpls/batmeter/test) | 10 | [shell/osshell/cpls/batmeter/test/sources](../../shell/osshell/cpls/batmeter/test/sources), [shell/osshell/cpls/batmeter/test/makefile](../../shell/osshell/cpls/batmeter/test/makefile) | `bmtest` | `PROGRAM` |
| [shell/osshell/cpls/batmeter/win95](../../shell/osshell/cpls/batmeter/win95) | 2 | [shell/osshell/cpls/batmeter/win95/sources](../../shell/osshell/cpls/batmeter/win95/sources), [shell/osshell/cpls/batmeter/win95/makefile](../../shell/osshell/cpls/batmeter/win95/makefile) | — | — |
| [shell/osshell/cpls/batmeter/winnt](../../shell/osshell/cpls/batmeter/winnt) | 2 | [shell/osshell/cpls/batmeter/winnt/sources](../../shell/osshell/cpls/batmeter/winnt/sources), [shell/osshell/cpls/batmeter/winnt/makefile](../../shell/osshell/cpls/batmeter/winnt/makefile) | — | — |
| [shell/osshell/cpls/batt](../../shell/osshell/cpls/batt) | 9 | [shell/osshell/cpls/batt/sources](../../shell/osshell/cpls/batt/sources), [shell/osshell/cpls/batt/makefile](../../shell/osshell/cpls/batt/makefile) | `batt` | `DYNLINK` |
| [shell/osshell/cpls/intl](../../shell/osshell/cpls/intl) | 20 | [shell/osshell/cpls/intl/sources](../../shell/osshell/cpls/intl/sources), [shell/osshell/cpls/intl/makefile](../../shell/osshell/cpls/intl/makefile) | `intl` | `DYNLINK` |
| [shell/osshell/cpls/main](../../shell/osshell/cpls/main) | 38 | [shell/osshell/cpls/main/sources](../../shell/osshell/cpls/main/sources), [shell/osshell/cpls/main/makefile](../../shell/osshell/cpls/main/makefile) | `main` | `DYNLINK` |
| [shell/osshell/cpls/ports](../../shell/osshell/cpls/ports) | 21 | [shell/osshell/cpls/ports/sources](../../shell/osshell/cpls/ports/sources), [shell/osshell/cpls/ports/makefile](../../shell/osshell/cpls/ports/makefile) | `msports` | `DYNLINK` |
| [shell/osshell/cpls/powercfg](../../shell/osshell/cpls/powercfg) | 26 | [shell/osshell/cpls/powercfg/dirs](../../shell/osshell/cpls/powercfg/dirs), [shell/osshell/cpls/powercfg/makefile](../../shell/osshell/cpls/powercfg/makefile) | — | — |
| [shell/osshell/cpls/powercfg/ups](../../shell/osshell/cpls/powercfg/ups) | 24 | [shell/osshell/cpls/powercfg/ups/dirs](../../shell/osshell/cpls/powercfg/ups/dirs) | — | — |
| [shell/osshell/cpls/powercfg/ups/lib](../../shell/osshell/cpls/powercfg/ups/lib) | 2 | [shell/osshell/cpls/powercfg/ups/lib/sources](../../shell/osshell/cpls/powercfg/ups/lib/sources), [shell/osshell/cpls/powercfg/ups/lib/makefile](../../shell/osshell/cpls/powercfg/ups/lib/makefile) | — | — |
| [shell/osshell/cpls/powercfg/win95](../../shell/osshell/cpls/powercfg/win95) | 2 | [shell/osshell/cpls/powercfg/win95/sources](../../shell/osshell/cpls/powercfg/win95/sources), [shell/osshell/cpls/powercfg/win95/makefile](../../shell/osshell/cpls/powercfg/win95/makefile) | — | — |
| [shell/osshell/cpls/powercfg/winnt](../../shell/osshell/cpls/powercfg/winnt) | 2 | [shell/osshell/cpls/powercfg/winnt/sources](../../shell/osshell/cpls/powercfg/winnt/sources), [shell/osshell/cpls/powercfg/winnt/makefile](../../shell/osshell/cpls/powercfg/winnt/makefile) | — | — |
| [shell/osshell/cpls/powrprof](../../shell/osshell/cpls/powrprof) | 23 | [shell/osshell/cpls/powrprof/dirs](../../shell/osshell/cpls/powrprof/dirs), [shell/osshell/cpls/powrprof/makefile](../../shell/osshell/cpls/powrprof/makefile) | — | — |
| [shell/osshell/cpls/powrprof/inf](../../shell/osshell/cpls/powrprof/inf) | 5 | [shell/osshell/cpls/powrprof/inf/sources](../../shell/osshell/cpls/powrprof/inf/sources), [shell/osshell/cpls/powrprof/inf/makefile](../../shell/osshell/cpls/powrprof/inf/makefile) | `makeinf` | `PROGRAM` |
| [shell/osshell/cpls/powrprof/ini](../../shell/osshell/cpls/powrprof/ini) | 6 | [shell/osshell/cpls/powrprof/ini/sources](../../shell/osshell/cpls/powrprof/ini/sources), [shell/osshell/cpls/powrprof/ini/makefile](../../shell/osshell/cpls/powrprof/ini/makefile) | `makeini` | `PROGRAM` |
| [shell/osshell/cpls/powrprof/winnt](../../shell/osshell/cpls/powrprof/winnt) | 4 | [shell/osshell/cpls/powrprof/winnt/sources](../../shell/osshell/cpls/powrprof/winnt/sources), [shell/osshell/cpls/powrprof/winnt/makefile](../../shell/osshell/cpls/powrprof/winnt/makefile) | — | — |
| [shell/osshell/cpls/usb](../../shell/osshell/cpls/usb) | 41 | [shell/osshell/cpls/usb/sources](../../shell/osshell/cpls/usb/sources), [shell/osshell/cpls/usb/makefile](../../shell/osshell/cpls/usb/makefile) | `usbui` | `DYNLINK` |
| [shell/osshell/dskquota](../../shell/osshell/dskquota) | 2 | [shell/osshell/dskquota/dirs](../../shell/osshell/dskquota/dirs) | — | — |
| [shell/osshell/dskquota/common](../../shell/osshell/dskquota/common) | 43 | [shell/osshell/dskquota/common/sources](../../shell/osshell/dskquota/common/sources), [shell/osshell/dskquota/common/makefile](../../shell/osshell/dskquota/common/makefile) | `common` | `LIBRARY` |
| [shell/osshell/dskquota/control](../../shell/osshell/dskquota/control) | 30 | [shell/osshell/dskquota/control/sources](../../shell/osshell/dskquota/control/sources), [shell/osshell/dskquota/control/makefile](../../shell/osshell/dskquota/control/makefile) | `dskquota` | `DYNLINK` |
| [shell/osshell/dskquota/doc](../../shell/osshell/dskquota/doc) | 1 | — | — | — |
| [shell/osshell/dskquota/scripting](../../shell/osshell/dskquota/scripting) | 1 | — | — | — |
| [shell/osshell/dskquota/ui](../../shell/osshell/dskquota/ui) | 55 | [shell/osshell/dskquota/ui/sources](../../shell/osshell/dskquota/ui/sources), [shell/osshell/dskquota/ui/makefile](../../shell/osshell/dskquota/ui/makefile) | `dskquoui` | `DYNLINK` |
| [shell/osshell/dskquota/watchdog](../../shell/osshell/dskquota/watchdog) | 27 | [shell/osshell/dskquota/watchdog/sources](../../shell/osshell/dskquota/watchdog/sources), [shell/osshell/dskquota/watchdog/makefile](../../shell/osshell/dskquota/watchdog/makefile) | `dskquowd` | `DYNLINK` |
| [shell/osshell/encrypt](../../shell/osshell/encrypt) | 14 | [shell/osshell/encrypt/sources](../../shell/osshell/encrypt/sources), [shell/osshell/encrypt/makefile](../../shell/osshell/encrypt/makefile) | `efsadu` | `DYNLINK` |
| [shell/osshell/encrypt/res](../../shell/osshell/encrypt/res) | 1 | — | — | — |
| [shell/osshell/ep](../../shell/osshell/ep) | 1 | [shell/osshell/ep/dirs](../../shell/osshell/ep/dirs) | — | — |
| [shell/osshell/ep/aboutwep](../../shell/osshell/ep/aboutwep) | 12 | [shell/osshell/ep/aboutwep/sources](../../shell/osshell/ep/aboutwep/sources), [shell/osshell/ep/aboutwep/makefile](../../shell/osshell/ep/aboutwep/makefile) | `aboutwep` | `DYNLINK` |
| [shell/osshell/ep/carddll](../../shell/osshell/ep/carddll) | 12 | [shell/osshell/ep/carddll/sources](../../shell/osshell/ep/carddll/sources), [shell/osshell/ep/carddll/makefile](../../shell/osshell/ep/carddll/makefile) | `cards` | `DYNLINK` |
| [shell/osshell/ep/carddll/dibs](../../shell/osshell/ep/carddll/dibs) | 99 | — | — | — |
| [shell/osshell/ep/cruel](../../shell/osshell/ep/cruel) | 9 | [shell/osshell/ep/cruel/sources](../../shell/osshell/ep/cruel/sources), [shell/osshell/ep/cruel/makefile](../../shell/osshell/ep/cruel/makefile) | `cruel` | `PROGRAM` |
| [shell/osshell/ep/cruel/help](../../shell/osshell/ep/cruel/help) | 6 | — | — | — |
| [shell/osshell/ep/freecell](../../shell/osshell/ep/freecell) | 20 | [shell/osshell/ep/freecell/sources](../../shell/osshell/ep/freecell/sources), [shell/osshell/ep/freecell/makefile](../../shell/osshell/ep/freecell/makefile) | `freecell` | `PROGRAM` |
| [shell/osshell/ep/golf](../../shell/osshell/ep/golf) | 9 | [shell/osshell/ep/golf/sources](../../shell/osshell/ep/golf/sources), [shell/osshell/ep/golf/makefile](../../shell/osshell/ep/golf/makefile) | `golf` | `PROGRAM` |
| [shell/osshell/ep/golf/help](../../shell/osshell/ep/golf/help) | 6 | — | — | — |
| [shell/osshell/ep/idlewild](../../shell/osshell/ep/idlewild) | 4 | [shell/osshell/ep/idlewild/dirs](../../shell/osshell/ep/idlewild/dirs) | — | — |
| [shell/osshell/ep/idlewild/dropout](../../shell/osshell/ep/idlewild/dropout) | 5 | [shell/osshell/ep/idlewild/dropout/sources](../../shell/osshell/ep/idlewild/dropout/sources), [shell/osshell/ep/idlewild/dropout/makefile](../../shell/osshell/ep/idlewild/dropout/makefile) | `dropout` | `DYNLINK` |
| [shell/osshell/ep/idlewild/firework](../../shell/osshell/ep/idlewild/firework) | 5 | [shell/osshell/ep/idlewild/firework/sources](../../shell/osshell/ep/idlewild/firework/sources), [shell/osshell/ep/idlewild/firework/makefile](../../shell/osshell/ep/idlewild/firework/makefile) | `firework` | `DYNLINK` |
| [shell/osshell/ep/idlewild/help](../../shell/osshell/ep/idlewild/help) | 4 | — | — | — |
| [shell/osshell/ep/idlewild/idlewild](../../shell/osshell/ep/idlewild/idlewild) | 6 | [shell/osshell/ep/idlewild/idlewild/sources](../../shell/osshell/ep/idlewild/idlewild/sources), [shell/osshell/ep/idlewild/idlewild/makefile](../../shell/osshell/ep/idlewild/idlewild/makefile) | `idlewild` | `LIBRARY` |
| [shell/osshell/ep/idlewild/library](../../shell/osshell/ep/idlewild/library) | 5 | [shell/osshell/ep/idlewild/library/sources](../../shell/osshell/ep/idlewild/library/sources), [shell/osshell/ep/idlewild/library/makefile](../../shell/osshell/ep/idlewild/library/makefile) | `iwlib` | `DYNLINK` |
| [shell/osshell/ep/idlewild/life](../../shell/osshell/ep/idlewild/life) | 5 | [shell/osshell/ep/idlewild/life/sources](../../shell/osshell/ep/idlewild/life/sources), [shell/osshell/ep/idlewild/life/makefile](../../shell/osshell/ep/idlewild/life/makefile) | `life` | `DYNLINK` |
| [shell/osshell/ep/idlewild/lines](../../shell/osshell/ep/idlewild/lines) | 5 | [shell/osshell/ep/idlewild/lines/sources](../../shell/osshell/ep/idlewild/lines/sources), [shell/osshell/ep/idlewild/lines/makefile](../../shell/osshell/ep/idlewild/lines/makefile) | `lines` | `DYNLINK` |
| [shell/osshell/ep/idlewild/shuffle](../../shell/osshell/ep/idlewild/shuffle) | 5 | [shell/osshell/ep/idlewild/shuffle/sources](../../shell/osshell/ep/idlewild/shuffle/sources), [shell/osshell/ep/idlewild/shuffle/makefile](../../shell/osshell/ep/idlewild/shuffle/makefile) | `shuffle` | `DYNLINK` |
| [shell/osshell/ep/idlewild/stars](../../shell/osshell/ep/idlewild/stars) | 6 | [shell/osshell/ep/idlewild/stars/sources](../../shell/osshell/ep/idlewild/stars/sources), [shell/osshell/ep/idlewild/stars/makefile](../../shell/osshell/ep/idlewild/stars/makefile) | `stars` | `DYNLINK` |
| [shell/osshell/ep/idlewild/wipe](../../shell/osshell/ep/idlewild/wipe) | 5 | [shell/osshell/ep/idlewild/wipe/sources](../../shell/osshell/ep/idlewild/wipe/sources), [shell/osshell/ep/idlewild/wipe/makefile](../../shell/osshell/ep/idlewild/wipe/makefile) | `wipe` | `DYNLINK` |
| [shell/osshell/ep/oldtp](../../shell/osshell/ep/oldtp) | 89 | [shell/osshell/ep/oldtp/sources](../../shell/osshell/ep/oldtp/sources), [shell/osshell/ep/oldtp/makefile](../../shell/osshell/ep/oldtp/makefile) | `taipei` | `PROGRAM` |
| [shell/osshell/ep/pegged](../../shell/osshell/ep/pegged) | 8 | [shell/osshell/ep/pegged/sources](../../shell/osshell/ep/pegged/sources), [shell/osshell/ep/pegged/makefile](../../shell/osshell/ep/pegged/makefile) | `pegged` | `PROGRAM` |
| [shell/osshell/ep/pegged/help](../../shell/osshell/ep/pegged/help) | 10 | — | — | — |
| [shell/osshell/ep/snake](../../shell/osshell/ep/snake) | 25 | [shell/osshell/ep/snake/sources](../../shell/osshell/ep/snake/sources), [shell/osshell/ep/snake/makefile](../../shell/osshell/ep/snake/makefile) | `snake` | `PROGRAM` |
| [shell/osshell/ep/snake/bmp](../../shell/osshell/ep/snake/bmp) | 13 | — | — | — |
| [shell/osshell/ep/taipei](../../shell/osshell/ep/taipei) | 1 | [shell/osshell/ep/taipei/makefile](../../shell/osshell/ep/taipei/makefile) | — | — |
| [shell/osshell/ep/tetris](../../shell/osshell/ep/tetris) | 1 | [shell/osshell/ep/tetris/makefile](../../shell/osshell/ep/tetris/makefile) | — | — |
| [shell/osshell/ep/tictac](../../shell/osshell/ep/tictac) | 22 | [shell/osshell/ep/tictac/sources](../../shell/osshell/ep/tictac/sources), [shell/osshell/ep/tictac/makefile](../../shell/osshell/ep/tictac/makefile) | `tictac` | `PROGRAM` |
| [shell/osshell/ep/tictac/bmp](../../shell/osshell/ep/tictac/bmp) | 7 | — | — | — |
| [shell/osshell/ep/tictac/help](../../shell/osshell/ep/tictac/help) | 5 | — | — | — |
| [shell/osshell/ep/winmine](../../shell/osshell/ep/winmine) | 24 | [shell/osshell/ep/winmine/sources](../../shell/osshell/ep/winmine/sources), [shell/osshell/ep/winmine/makefile](../../shell/osshell/ep/winmine/makefile) | `winmine` | `PROGRAM` |
| [shell/osshell/ep/winmine/bmp](../../shell/osshell/ep/winmine/bmp) | 10 | — | — | — |
| [shell/osshell/ep/winmine/help](../../shell/osshell/ep/winmine/help) | 18 | — | — | — |
| [shell/osshell/fontfldr](../../shell/osshell/fontfldr) | 4 | [shell/osshell/fontfldr/dirs](../../shell/osshell/fontfldr/dirs) | — | — |
| [shell/osshell/fontfldr/fontext](../../shell/osshell/fontfldr/fontext) | 3 | [shell/osshell/fontfldr/fontext/dirs](../../shell/osshell/fontfldr/fontext/dirs) | — | — |
| [shell/osshell/fontfldr/fontext/bld](../../shell/osshell/fontfldr/fontext/bld) | 3 | — | — | — |
| [shell/osshell/fontfldr/fontext/inc](../../shell/osshell/fontfldr/fontext/inc) | 31 | — | — | — |
| [shell/osshell/fontfldr/fontext/src](../../shell/osshell/fontfldr/fontext/src) | 41 | [shell/osshell/fontfldr/fontext/src/sources](../../shell/osshell/fontfldr/fontext/src/sources), [shell/osshell/fontfldr/fontext/src/makefile](../../shell/osshell/fontfldr/fontext/src/makefile) | `fontext` | `DYNLINK` |
| [shell/osshell/fontfldr/fontext/t1instal](../../shell/osshell/fontfldr/fontext/t1instal) | 51 | [shell/osshell/fontfldr/fontext/t1instal/sources](../../shell/osshell/fontfldr/fontext/t1instal/sources), [shell/osshell/fontfldr/fontext/t1instal/makefile](../../shell/osshell/fontfldr/fontext/t1instal/makefile) | `t1instal` | `LIBRARY` |
| [shell/osshell/fontfldr/fontreg](../../shell/osshell/fontfldr/fontreg) | 5 | [shell/osshell/fontfldr/fontreg/makefile](../../shell/osshell/fontfldr/fontreg/makefile) | — | — |
| [shell/osshell/fontfldr/fontview](../../shell/osshell/fontfldr/fontview) | 13 | [shell/osshell/fontfldr/fontview/sources](../../shell/osshell/fontfldr/fontview/sources), [shell/osshell/fontfldr/fontview/makefile](../../shell/osshell/fontfldr/fontview/makefile) | `fontview` | `PROGRAM` |
| [shell/osshell/fontfldr/ole2map](../../shell/osshell/fontfldr/ole2map) | 17 | [shell/osshell/fontfldr/ole2map/sources](../../shell/osshell/fontfldr/ole2map/sources), [shell/osshell/fontfldr/ole2map/makefile](../../shell/osshell/fontfldr/ole2map/makefile) | `panmap` | `DYNLINK` |
| [shell/osshell/games](../../shell/osshell/games) | 1 | [shell/osshell/games/dirs](../../shell/osshell/games/dirs) | — | — |
| [shell/osshell/games/mshearts](../../shell/osshell/games/mshearts) | 38 | [shell/osshell/games/mshearts/sources](../../shell/osshell/games/mshearts/sources), [shell/osshell/games/mshearts/makefile](../../shell/osshell/games/mshearts/makefile) | `mshearts` | `PROGRAM` |
| [shell/osshell/games/reversi](../../shell/osshell/games/reversi) | 11 | [shell/osshell/games/reversi/sources](../../shell/osshell/games/reversi/sources), [shell/osshell/games/reversi/makefile](../../shell/osshell/games/reversi/makefile) | `reversi` | `PROGRAM` |
| [shell/osshell/games/sol](../../shell/osshell/games/sol) | 40 | [shell/osshell/games/sol/sources](../../shell/osshell/games/sol/sources), [shell/osshell/games/sol/makefile](../../shell/osshell/games/sol/makefile) | `sol` | `PROGRAM` |
| [shell/osshell/games/sol/bmp](../../shell/osshell/games/sol/bmp) | 87 | — | — | — |
| [shell/osshell/grptoreg](../../shell/osshell/grptoreg) | 12 | [shell/osshell/grptoreg/sources](../../shell/osshell/grptoreg/sources), [shell/osshell/grptoreg/makefile](../../shell/osshell/grptoreg/makefile) | `grptoreg` | `PROGRAM` |
| [shell/osshell/inc](../../shell/osshell/inc) | 6 | — | — | — |
| [shell/osshell/lmui](../../shell/osshell/lmui) | 3 | [shell/osshell/lmui/dirs](../../shell/osshell/lmui/dirs) | — | — |
| [shell/osshell/lmui/debug](../../shell/osshell/lmui/debug) | 4 | [shell/osshell/lmui/debug/sources](../../shell/osshell/lmui/debug/sources), [shell/osshell/lmui/debug/makefile](../../shell/osshell/lmui/debug/makefile) | `debug` | `LIBRARY` |
| [shell/osshell/lmui/netobjs](../../shell/osshell/lmui/netobjs) | 25 | [shell/osshell/lmui/netobjs/sources](../../shell/osshell/lmui/netobjs/sources), [shell/osshell/lmui/netobjs/makefile](../../shell/osshell/lmui/netobjs/makefile) | `ntlanui2` | `DYNLINK` |
| [shell/osshell/lmui/netobjs/fixes](../../shell/osshell/lmui/netobjs/fixes) | 4 | — | — | — |
| [shell/osshell/lmui/ntshrui](../../shell/osshell/lmui/ntshrui) | 47 | [shell/osshell/lmui/ntshrui/sources](../../shell/osshell/lmui/ntshrui/sources), [shell/osshell/lmui/ntshrui/makefile](../../shell/osshell/lmui/ntshrui/makefile) | `ntshrui` | `DYNLINK` |
| [shell/osshell/lmui/shareui](../../shell/osshell/lmui/shareui) | 63 | [shell/osshell/lmui/shareui/sources](../../shell/osshell/lmui/shareui/sources), [shell/osshell/lmui/shareui/makefile](../../shell/osshell/lmui/shareui/makefile) | `shareui` | `DYNLINK` |
| [shell/osshell/migrate](../../shell/osshell/migrate) | 11 | [shell/osshell/migrate/sources](../../shell/osshell/migrate/sources), [shell/osshell/migrate/makefile](../../shell/osshell/migrate/makefile) | `shmgrate` | `PROGRAM` |
| [shell/osshell/pifmgr](../../shell/osshell/pifmgr) | 42 | [shell/osshell/pifmgr/sources](../../shell/osshell/pifmgr/sources), [shell/osshell/pifmgr/makefile](../../shell/osshell/pifmgr/makefile) | `pifmgr` | `DYNLINK` |
| [shell/osshell/progman](../../shell/osshell/progman) | 62 | [shell/osshell/progman/sources](../../shell/osshell/progman/sources), [shell/osshell/progman/makefile](../../shell/osshell/progman/makefile) | `progman` | `PROGRAM` |
| [shell/osshell/progman/icons](../../shell/osshell/progman/icons) | 0 | — | — | — |
| [shell/osshell/progman/icons/contain](../../shell/osshell/progman/icons/contain) | 11 | — | — | — |
| [shell/osshell/progman/icons/hyper](../../shell/osshell/progman/icons/hyper) | 20 | — | — | — |
| [shell/osshell/progman/icons/objects](../../shell/osshell/progman/icons/objects) | 26 | — | — | — |
| [shell/osshell/regedit.nt4](../../shell/osshell/regedit.nt4) | 2 | [shell/osshell/regedit.nt4/sources](../../shell/osshell/regedit.nt4/sources), [shell/osshell/regedit.nt4/makefile](../../shell/osshell/regedit.nt4/makefile) | `regedit` | `NOTARGET` |
| [shell/osshell/regedit.nt4/i386](../../shell/osshell/regedit.nt4/i386) | 1 | — | — | — |
| [shell/osshell/regwiz](../../shell/osshell/regwiz) | 1 | [shell/osshell/regwiz/dirs](../../shell/osshell/regwiz/dirs) | — | — |
| [shell/osshell/regwiz/include](../../shell/osshell/regwiz/include) | 22 | — | — | — |
| [shell/osshell/regwiz/phbooklib](../../shell/osshell/regwiz/phbooklib) | 21 | [shell/osshell/regwiz/phbooklib/sources](../../shell/osshell/regwiz/phbooklib/sources), [shell/osshell/regwiz/phbooklib/makefile](../../shell/osshell/regwiz/phbooklib/makefile) | `PhBookLib` | `LIBRARY` |
| [shell/osshell/regwiz/regwiz](../../shell/osshell/regwiz/regwiz) | 32 | [shell/osshell/regwiz/regwiz/sources](../../shell/osshell/regwiz/regwiz/sources), [shell/osshell/regwiz/regwiz/makefile](../../shell/osshell/regwiz/regwiz/makefile) | `RegWiz` | `LIBRARY` |
| [shell/osshell/regwiz/regwizctrl](../../shell/osshell/regwiz/regwizctrl) | 14 | [shell/osshell/regwiz/regwizctrl/sources](../../shell/osshell/regwiz/regwizctrl/sources), [shell/osshell/regwiz/regwizctrl/makefile](../../shell/osshell/regwiz/regwizctrl/makefile) | `RegWizC` | `DYNLINK` |
| [shell/osshell/regwiz/regwizexe](../../shell/osshell/regwiz/regwizexe) | 12 | [shell/osshell/regwiz/regwizexe/sources](../../shell/osshell/regwiz/regwizexe/sources), [shell/osshell/regwiz/regwizexe/makefile](../../shell/osshell/regwiz/regwizexe/makefile) | `RegWiz` | `PROGRAM` |
| [shell/osshell/regwiz/regwizpost](../../shell/osshell/regwiz/regwizpost) | 18 | [shell/osshell/regwiz/regwizpost/sources](../../shell/osshell/regwiz/regwizpost/sources), [shell/osshell/regwiz/regwizpost/makefile](../../shell/osshell/regwiz/regwizpost/makefile) | `RegWizPost` | `LIBRARY` |
| [shell/osshell/regwiz/res](../../shell/osshell/regwiz/res) | 28 | — | — | — |
| [shell/osshell/regwiz/sysinv](../../shell/osshell/regwiz/sysinv) | 8 | [shell/osshell/regwiz/sysinv/sources](../../shell/osshell/regwiz/sysinv/sources), [shell/osshell/regwiz/sysinv/makefile](../../shell/osshell/regwiz/sysinv/makefile) | `Sysinv` | `DYNLINK` |
| [shell/osshell/rundll32](../../shell/osshell/rundll32) | 9 | [shell/osshell/rundll32/sources](../../shell/osshell/rundll32/sources), [shell/osshell/rundll32/makefile](../../shell/osshell/rundll32/makefile) | `rundll32` | `PROGRAM` |
| [shell/osshell/runonce](../../shell/osshell/runonce) | 13 | [shell/osshell/runonce/sources](../../shell/osshell/runonce/sources), [shell/osshell/runonce/makefile](../../shell/osshell/runonce/makefile) | `runonce` | `PROGRAM` |
| [shell/osshell/security](../../shell/osshell/security) | 2 | [shell/osshell/security/dirs](../../shell/osshell/security/dirs) | — | — |
| [shell/osshell/security/aclui](../../shell/osshell/security/aclui) | 36 | [shell/osshell/security/aclui/dirs](../../shell/osshell/security/aclui/dirs) | — | — |
| [shell/osshell/security/aclui/winnt](../../shell/osshell/security/aclui/winnt) | 2 | [shell/osshell/security/aclui/winnt/sources](../../shell/osshell/security/aclui/winnt/sources), [shell/osshell/security/aclui/winnt/makefile](../../shell/osshell/security/aclui/winnt/makefile) | — | — |
| [shell/osshell/security/common](../../shell/osshell/security/common) | 9 | [shell/osshell/security/common/dirs](../../shell/osshell/security/common/dirs) | — | — |
| [shell/osshell/security/common/winnt](../../shell/osshell/security/common/winnt) | 2 | [shell/osshell/security/common/winnt/sources](../../shell/osshell/security/common/winnt/sources), [shell/osshell/security/common/winnt/makefile](../../shell/osshell/security/common/winnt/makefile) | — | — |
| [shell/osshell/security/dssec](../../shell/osshell/security/dssec) | 24 | [shell/osshell/security/dssec/dirs](../../shell/osshell/security/dssec/dirs) | — | — |
| [shell/osshell/security/dssec/filter](../../shell/osshell/security/dssec/filter) | 4 | [shell/osshell/security/dssec/filter/sources](../../shell/osshell/security/dssec/filter/sources), [shell/osshell/security/dssec/filter/makefile](../../shell/osshell/security/dssec/filter/makefile) | `dsfilter` | `PROGRAM` |
| [shell/osshell/security/dssec/winnt](../../shell/osshell/security/dssec/winnt) | 2 | [shell/osshell/security/dssec/winnt/sources](../../shell/osshell/security/dssec/winnt/sources), [shell/osshell/security/dssec/winnt/makefile](../../shell/osshell/security/dssec/winnt/makefile) | — | — |
| [shell/osshell/security/inc](../../shell/osshell/security/inc) | 7 | — | — | — |
| [shell/osshell/security/rshx32](../../shell/osshell/security/rshx32) | 22 | [shell/osshell/security/rshx32/dirs](../../shell/osshell/security/rshx32/dirs) | — | — |
| [shell/osshell/security/rshx32/winnt](../../shell/osshell/security/rshx32/winnt) | 2 | [shell/osshell/security/rshx32/winnt/sources](../../shell/osshell/security/rshx32/winnt/sources), [shell/osshell/security/rshx32/winnt/makefile](../../shell/osshell/security/rshx32/winnt/makefile) | — | — |
| [shell/osshell/shcompui](../../shell/osshell/shcompui) | 10 | [shell/osshell/shcompui/sources](../../shell/osshell/shcompui/sources), [shell/osshell/shcompui/makefile](../../shell/osshell/shcompui/makefile) | `shcompui` | `DYNLINK` |
| [shell/osshell/shole](../../shell/osshell/shole) | 23 | [shell/osshell/shole/sources](../../shell/osshell/shole/sources), [shell/osshell/shole/makefile](../../shell/osshell/shole/makefile) | `shscrap` | `DYNLINK` |
| [shell/osshell/snapins](../../shell/osshell/snapins) | 1 | [shell/osshell/snapins/dirs](../../shell/osshell/snapins/dirs) | — | — |
| [shell/osshell/snapins/devmgr](../../shell/osshell/snapins/devmgr) | 1 | [shell/osshell/snapins/devmgr/dirs](../../shell/osshell/snapins/devmgr/dirs) | — | — |
| [shell/osshell/snapins/devmgr/inc](../../shell/osshell/snapins/devmgr/inc) | 1 | — | — | — |
| [shell/osshell/snapins/devmgr/listdev](../../shell/osshell/snapins/devmgr/listdev) | 14 | [shell/osshell/snapins/devmgr/listdev/sources](../../shell/osshell/snapins/devmgr/listdev/sources), [shell/osshell/snapins/devmgr/listdev/makefile](../../shell/osshell/snapins/devmgr/listdev/makefile) | `listdev` | `PROGRAM` |
| [shell/osshell/snapins/devmgr/listdev/res](../../shell/osshell/snapins/devmgr/listdev/res) | 2 | — | — | — |
| [shell/osshell/snapins/devmgr/ocx](../../shell/osshell/snapins/devmgr/ocx) | 15 | [shell/osshell/snapins/devmgr/ocx/sources](../../shell/osshell/snapins/devmgr/ocx/sources), [shell/osshell/snapins/devmgr/ocx/makefile](../../shell/osshell/snapins/devmgr/ocx/makefile) | `dmocx` | `DYNLINK` |
| [shell/osshell/snapins/devmgr/snapin](../../shell/osshell/snapins/devmgr/snapin) | 77 | [shell/osshell/snapins/devmgr/snapin/sources](../../shell/osshell/snapins/devmgr/snapin/sources), [shell/osshell/snapins/devmgr/snapin/makefile](../../shell/osshell/snapins/devmgr/snapin/makefile) | `devmgr` | `DYNLINK` |
| [shell/osshell/taskman](../../shell/osshell/taskman) | 7 | [shell/osshell/taskman/sources](../../shell/osshell/taskman/sources), [shell/osshell/taskman/makefile](../../shell/osshell/taskman/makefile) | `taskman` | `PROGRAM` |
| [shell/osshell/themes](../../shell/osshell/themes) | 1 | [shell/osshell/themes/dirs](../../shell/osshell/themes/dirs) | — | — |
| [shell/osshell/themes/cpl](../../shell/osshell/themes/cpl) | 8 | [shell/osshell/themes/cpl/dirs](../../shell/osshell/themes/cpl/dirs) | — | — |
| [shell/osshell/themes/cpl/win98](../../shell/osshell/themes/cpl/win98) | 2 | [shell/osshell/themes/cpl/win98/sources](../../shell/osshell/themes/cpl/win98/sources), [shell/osshell/themes/cpl/win98/makefile](../../shell/osshell/themes/cpl/win98/makefile) | — | — |
| [shell/osshell/themes/cpl/winnt](../../shell/osshell/themes/cpl/winnt) | 2 | [shell/osshell/themes/cpl/winnt/sources](../../shell/osshell/themes/cpl/winnt/sources), [shell/osshell/themes/cpl/winnt/makefile](../../shell/osshell/themes/cpl/winnt/makefile) | — | — |
| [shell/osshell/themes/inc](../../shell/osshell/themes/inc) | 12 | — | — | — |
| [shell/osshell/themes/themesw](../../shell/osshell/themes/themesw) | 39 | [shell/osshell/themes/themesw/dirs](../../shell/osshell/themes/themesw/dirs) | — | — |
| [shell/osshell/themes/themesw/win98](../../shell/osshell/themes/themesw/win98) | 2 | [shell/osshell/themes/themesw/win98/sources](../../shell/osshell/themes/themesw/win98/sources), [shell/osshell/themes/themesw/win98/makefile](../../shell/osshell/themes/themesw/win98/makefile) | — | — |
| [shell/osshell/themes/themesw/winnt](../../shell/osshell/themes/themesw/winnt) | 2 | [shell/osshell/themes/themesw/winnt/sources](../../shell/osshell/themes/themesw/winnt/sources), [shell/osshell/themes/themesw/winnt/makefile](../../shell/osshell/themes/themesw/winnt/makefile) | — | — |
| [shell/osshell/tools](../../shell/osshell/tools) | 1 | [shell/osshell/tools/dirs](../../shell/osshell/tools/dirs) | — | — |
| [shell/osshell/tools/clipdump](../../shell/osshell/tools/clipdump) | 4 | [shell/osshell/tools/clipdump/sources](../../shell/osshell/tools/clipdump/sources), [shell/osshell/tools/clipdump/makefile](../../shell/osshell/tools/clipdump/makefile) | `clipdump` | `PROGRAM` |
| [shell/osshell/tools/fixlinks](../../shell/osshell/tools/fixlinks) | 4 | [shell/osshell/tools/fixlinks/sources](../../shell/osshell/tools/fixlinks/sources), [shell/osshell/tools/fixlinks/makefile](../../shell/osshell/tools/fixlinks/makefile) | `fixlinks` | `PROGRAM` |
| [shell/osshell/tools/lnkdump](../../shell/osshell/tools/lnkdump) | 5 | [shell/osshell/tools/lnkdump/sources](../../shell/osshell/tools/lnkdump/sources), [shell/osshell/tools/lnkdump/makefile](../../shell/osshell/tools/lnkdump/makefile) | `lnkdump` | `PROGRAM` |
| [shell/osshell/tools/pifdump](../../shell/osshell/tools/pifdump) | 5 | [shell/osshell/tools/pifdump/sources](../../shell/osshell/tools/pifdump/sources), [shell/osshell/tools/pifdump/makefile](../../shell/osshell/tools/pifdump/makefile) | `pifdump` | `PROGRAM` |
| [shell/osshell/version](../../shell/osshell/version) | 12 | [shell/osshell/version/sources](../../shell/osshell/version/sources), [shell/osshell/version/makefile](../../shell/osshell/version/makefile) | `version` | `DYNLINK` |
| [shell/osshell/version/test](../../shell/osshell/version/test) | 6 | [shell/osshell/version/test/sources](../../shell/osshell/version/test/sources), [shell/osshell/version/test/makefile](../../shell/osshell/version/test/makefile) | `test` | `PROGRAM` |
| [shell/osshell/winver](../../shell/osshell/winver) | 11 | [shell/osshell/winver/sources](../../shell/osshell/winver/sources), [shell/osshell/winver/makefile](../../shell/osshell/winver/makefile) | `winver` | `PROGRAM` |

## `shell/policies/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [shell/policies](../../shell/policies) | 5 | [shell/policies/sources](../../shell/policies/sources), [shell/policies/makefile](../../shell/policies/makefile) | — | `NOTARGET` |

## `shell/published/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [shell/published](../../shell/published) | 2 | [shell/published/dirs](../../shell/published/dirs) | — | — |
| [shell/published/dload](../../shell/published/dload) | 22 | [shell/published/dload/sources](../../shell/published/dload/sources), [shell/published/dload/makefile](../../shell/published/dload/makefile) | `dloadshell` | `LIBRARY` |
| [shell/published/inc](../../shell/published/inc) | 90 | [shell/published/inc/sources](../../shell/published/inc/sources), [shell/published/inc/makefile](../../shell/published/inc/makefile) | `shlproxy` | `LIBRARY` |
| [shell/published/inc/imapi](../../shell/published/inc/imapi) | 8 | — | — | — |
| [shell/published/uuid](../../shell/published/uuid) | 4 | [shell/published/uuid/sources](../../shell/published/uuid/sources), [shell/published/uuid/makefile](../../shell/published/uuid/makefile) | `shuuid` | `LIBRARY` |

## `shell/samplemusic/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [shell/samplemusic](../../shell/samplemusic) | 4 | [shell/samplemusic/sources](../../shell/samplemusic/sources), [shell/samplemusic/makefile](../../shell/samplemusic/makefile) | — | `NOTARGET` |

## `shell/samplemypicts/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [shell/samplemypicts](../../shell/samplemypicts) | 6 | [shell/samplemypicts/sources](../../shell/samplemypicts/sources), [shell/samplemypicts/makefile](../../shell/samplemypicts/makefile) | — | `NOTARGET` |

## `shell/services/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [shell/services](../../shell/services) | 2 | [shell/services/dirs](../../shell/services/dirs) | — | — |
| [shell/services/bamsrv](../../shell/services/bamsrv) | 27 | [shell/services/bamsrv/sources](../../shell/services/bamsrv/sources), [shell/services/bamsrv/makefile](../../shell/services/bamsrv/makefile) | `bamsrv` | `LIBRARY` |
| [shell/services/dll](../../shell/services/dll) | 6 | [shell/services/dll/sources](../../shell/services/dll/sources), [shell/services/dll/makefile](../../shell/services/dll/makefile) | `shsvcs` | `DYNLINK` |
| [shell/services/hdsrv](../../shell/services/hdsrv) | 2 | [shell/services/hdsrv/dirs](../../shell/services/hdsrv/dirs) | — | — |
| [shell/services/hdsrv/apdiag](../../shell/services/hdsrv/apdiag) | 8 | [shell/services/hdsrv/apdiag/sources](../../shell/services/hdsrv/apdiag/sources), [shell/services/hdsrv/apdiag/makefile](../../shell/services/hdsrv/apdiag/makefile) | `apdiag` | `PROGRAM` |
| [shell/services/hdsrv/apsample](../../shell/services/hdsrv/apsample) | 6 | [shell/services/hdsrv/apsample/sources](../../shell/services/hdsrv/apsample/sources), [shell/services/hdsrv/apsample/makefile](../../shell/services/hdsrv/apsample/makefile) | `apsample` | `PROGRAM` |
| [shell/services/hdsrv/idl](../../shell/services/hdsrv/idl) | 3 | [shell/services/hdsrv/idl/sources](../../shell/services/hdsrv/idl/sources), [shell/services/hdsrv/idl/makefile](../../shell/services/hdsrv/idl/makefile) | — | `NOTARGET` |
| [shell/services/hdsrv/inc](../../shell/services/hdsrv/inc) | 13 | — | — | — |
| [shell/services/hdsrv/lib](../../shell/services/hdsrv/lib) | 15 | [shell/services/hdsrv/lib/sources](../../shell/services/hdsrv/lib/sources), [shell/services/hdsrv/lib/makefile](../../shell/services/hdsrv/lib/makefile) | `shsrvice` | `LIBRARY` |
| [shell/services/hdsrv/pipeclnt](../../shell/services/hdsrv/pipeclnt) | 1 | — | — | — |
| [shell/services/hdsrv/shhwdtct](../../shell/services/hdsrv/shhwdtct) | 49 | [shell/services/hdsrv/shhwdtct/dirs](../../shell/services/hdsrv/shhwdtct/dirs) | — | — |
| [shell/services/hdsrv/shhwdtct/dll](../../shell/services/hdsrv/shhwdtct/dll) | 2 | [shell/services/hdsrv/shhwdtct/dll/sources](../../shell/services/hdsrv/shhwdtct/dll/sources), [shell/services/hdsrv/shhwdtct/dll/makefile](../../shell/services/hdsrv/shhwdtct/dll/makefile) | — | `DYNLINK` |
| [shell/services/hdsrv/shhwdtct/lib](../../shell/services/hdsrv/shhwdtct/lib) | 2 | [shell/services/hdsrv/shhwdtct/lib/sources](../../shell/services/hdsrv/shhwdtct/lib/sources), [shell/services/hdsrv/shhwdtct/lib/makefile](../../shell/services/hdsrv/shhwdtct/lib/makefile) | — | `LIBRARY` |
| [shell/services/hdsrv/shhwdtct/tstdrv](../../shell/services/hdsrv/shhwdtct/tstdrv) | 0 | — | — | — |
| [shell/services/hdsrv/shhwdtct/tstdrv/td_envlctnt](../../shell/services/hdsrv/shhwdtct/tstdrv/td_envlctnt) | 3 | [shell/services/hdsrv/shhwdtct/tstdrv/td_envlctnt/sources](../../shell/services/hdsrv/shhwdtct/tstdrv/td_envlctnt/sources), [shell/services/hdsrv/shhwdtct/tstdrv/td_envlctnt/makefile](../../shell/services/hdsrv/shhwdtct/tstdrv/td_envlctnt/makefile) | `td_envlctnt` | `PROGRAM` |
| [shell/services/hdsrv/shsrvice](../../shell/services/hdsrv/shsrvice) | 8 | [shell/services/hdsrv/shsrvice/dirs](../../shell/services/hdsrv/shsrvice/dirs) | — | — |
| [shell/services/hdsrv/shsrvice/exe](../../shell/services/hdsrv/shsrvice/exe) | 2 | [shell/services/hdsrv/shsrvice/exe/sources](../../shell/services/hdsrv/shsrvice/exe/sources), [shell/services/hdsrv/shsrvice/exe/makefile](../../shell/services/hdsrv/shsrvice/exe/makefile) | `shsrvice` | `PROGRAM` |
| [shell/services/hdsrv/shsrvice/lib](../../shell/services/hdsrv/shsrvice/lib) | 2 | [shell/services/hdsrv/shsrvice/lib/sources](../../shell/services/hdsrv/shsrvice/lib/sources), [shell/services/hdsrv/shsrvice/lib/makefile](../../shell/services/hdsrv/shsrvice/lib/makefile) | `service` | `LIBRARY` |
| [shell/services/hdsrv/shsrvice/svc](../../shell/services/hdsrv/shsrvice/svc) | 2 | [shell/services/hdsrv/shsrvice/svc/sources](../../shell/services/hdsrv/shsrvice/svc/sources), [shell/services/hdsrv/shsrvice/svc/makefile](../../shell/services/hdsrv/shsrvice/svc/makefile) | `shsrvice` | `PROGRAM` |
| [shell/services/hdsrv/shsrvice/trig](../../shell/services/hdsrv/shsrvice/trig) | 2 | [shell/services/hdsrv/shsrvice/trig/sources](../../shell/services/hdsrv/shsrvice/trig/sources), [shell/services/hdsrv/shsrvice/trig/makefile](../../shell/services/hdsrv/shsrvice/trig/makefile) | `shtrig` | `PROGRAM` |
| [shell/services/hdsrv/shsvc](../../shell/services/hdsrv/shsvc) | 6 | [shell/services/hdsrv/shsvc/sources](../../shell/services/hdsrv/shsvc/sources), [shell/services/hdsrv/shsvc/makefile](../../shell/services/hdsrv/shsvc/makefile) | `shsvc` | `DYNLINK` |
| [shell/services/hdsrv/tstdrv](../../shell/services/hdsrv/tstdrv) | 0 | — | — | — |
| [shell/services/hdsrv/tstdrv/cddiag](../../shell/services/hdsrv/tstdrv/cddiag) | 3 | [shell/services/hdsrv/tstdrv/cddiag/sources](../../shell/services/hdsrv/tstdrv/cddiag/sources), [shell/services/hdsrv/tstdrv/cddiag/makefile](../../shell/services/hdsrv/tstdrv/cddiag/makefile) | `cddiag` | `PROGRAM` |
| [shell/services/hdsrv/tstdrv/td_apsettings](../../shell/services/hdsrv/tstdrv/td_apsettings) | 3 | [shell/services/hdsrv/tstdrv/td_apsettings/sources](../../shell/services/hdsrv/tstdrv/td_apsettings/sources), [shell/services/hdsrv/tstdrv/td_apsettings/makefile](../../shell/services/hdsrv/tstdrv/td_apsettings/makefile) | `td_apsettings` | `PROGRAM` |
| [shell/services/hdsrv/tstdrv/td_devenum](../../shell/services/hdsrv/tstdrv/td_devenum) | 7 | [shell/services/hdsrv/tstdrv/td_devenum/sources](../../shell/services/hdsrv/tstdrv/td_devenum/sources), [shell/services/hdsrv/tstdrv/td_devenum/makefile](../../shell/services/hdsrv/tstdrv/td_devenum/makefile) | `td_devenum` | `PROGRAM` |
| [shell/services/hdsrv/tstdrv/td_devxprop](../../shell/services/hdsrv/tstdrv/td_devxprop) | 3 | [shell/services/hdsrv/tstdrv/td_devxprop/sources](../../shell/services/hdsrv/tstdrv/td_devxprop/sources), [shell/services/hdsrv/tstdrv/td_devxprop/makefile](../../shell/services/hdsrv/tstdrv/td_devxprop/makefile) | `td_devxprop` | `PROGRAM` |
| [shell/services/hdsrv/tstdrv/td_heh](../../shell/services/hdsrv/tstdrv/td_heh) | 7 | [shell/services/hdsrv/tstdrv/td_heh/sources](../../shell/services/hdsrv/tstdrv/td_heh/sources), [shell/services/hdsrv/tstdrv/td_heh/makefile](../../shell/services/hdsrv/tstdrv/td_heh/makefile) | `td_heh` | `PROGRAM` |
| [shell/services/hdsrv/tstdrv/td_sfstr](../../shell/services/hdsrv/tstdrv/td_sfstr) | 5 | [shell/services/hdsrv/tstdrv/td_sfstr/dirs](../../shell/services/hdsrv/tstdrv/td_sfstr/dirs) | — | — |
| [shell/services/hdsrv/tstdrv/td_sfstr/exe](../../shell/services/hdsrv/tstdrv/td_sfstr/exe) | 2 | [shell/services/hdsrv/tstdrv/td_sfstr/exe/sources](../../shell/services/hdsrv/tstdrv/td_sfstr/exe/sources), [shell/services/hdsrv/tstdrv/td_sfstr/exe/makefile](../../shell/services/hdsrv/tstdrv/td_sfstr/exe/makefile) | `td_sfstr` | `PROGRAM` |
| [shell/services/hdsrv/tstdrv/td_sfstr/shdrt](../../shell/services/hdsrv/tstdrv/td_sfstr/shdrt) | 2 | [shell/services/hdsrv/tstdrv/td_sfstr/shdrt/sources](../../shell/services/hdsrv/tstdrv/td_sfstr/shdrt/sources), [shell/services/hdsrv/tstdrv/td_sfstr/shdrt/makefile](../../shell/services/hdsrv/tstdrv/td_sfstr/shdrt/makefile) | `shdrt-sfstr` | `DYNLINK` |
| [shell/services/hdsrv/tstdrv/td_sniff](../../shell/services/hdsrv/tstdrv/td_sniff) | 3 | [shell/services/hdsrv/tstdrv/td_sniff/sources](../../shell/services/hdsrv/tstdrv/td_sniff/sources), [shell/services/hdsrv/tstdrv/td_sniff/makefile](../../shell/services/hdsrv/tstdrv/td_sniff/makefile) | `td_sniff` | `PROGRAM` |
| [shell/services/lpc](../../shell/services/lpc) | 18 | [shell/services/lpc/sources](../../shell/services/lpc/sources), [shell/services/lpc/makefile](../../shell/services/lpc/makefile) | `lpc` | `LIBRARY` |
| [shell/services/themesrv](../../shell/services/themesrv) | 18 | [shell/services/themesrv/sources](../../shell/services/themesrv/sources), [shell/services/themesrv/makefile](../../shell/services/themesrv/makefile) | `themesrv` | `LIBRARY` |

## `shell/shdocvw/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [shell/shdocvw](../../shell/shdocvw) | 356 | [shell/shdocvw/dirs](../../shell/shdocvw/dirs), [shell/shdocvw/makefile](../../shell/shdocvw/makefile) | — | — |
| [shell/shdocvw/cdfview](../../shell/shdocvw/cdfview) | 5 | [shell/shdocvw/cdfview/sources](../../shell/shdocvw/cdfview/sources), [shell/shdocvw/cdfview/makefile](../../shell/shdocvw/cdfview/makefile) | `cdfview` | `LIBRARY` |
| [shell/shdocvw/dll](../../shell/shdocvw/dll) | 10 | [shell/shdocvw/dll/sources](../../shell/shdocvw/dll/sources), [shell/shdocvw/dll/makefile](../../shell/shdocvw/dll/makefile) | `shdocvw` | `DYNLINK` |
| [shell/shdocvw/hist](../../shell/shdocvw/hist) | 16 | [shell/shdocvw/hist/sources](../../shell/shdocvw/hist/sources), [shell/shdocvw/hist/makefile](../../shell/shdocvw/hist/makefile) | `hist` | `LIBRARY` |
| [shell/shdocvw/nt5api](../../shell/shdocvw/nt5api) | 2 | [shell/shdocvw/nt5api/sources](../../shell/shdocvw/nt5api/sources), [shell/shdocvw/nt5api/makefile](../../shell/shdocvw/nt5api/makefile) | `apithk` | `LIBRARY` |
| [shell/shdocvw/resdll](../../shell/shdocvw/resdll) | 3 | [shell/shdocvw/resdll/sources](../../shell/shdocvw/resdll/sources), [shell/shdocvw/resdll/makefile](../../shell/shdocvw/resdll/makefile) | `shdoclc` | `DYNLINK` |
| [shell/shdocvw/srcc](../../shell/shdocvw/srcc) | 3 | [shell/shdocvw/srcc/sources](../../shell/shdocvw/srcc/sources), [shell/shdocvw/srcc/makefile](../../shell/shdocvw/srcc/makefile) | `srcc` | `LIBRARY` |
| [shell/shdocvw/util](../../shell/shdocvw/util) | 5 | [shell/shdocvw/util/sources](../../shell/shdocvw/util/sources), [shell/shdocvw/util/makefile](../../shell/shdocvw/util/makefile) | `util` | `LIBRARY` |

## `shell/shell32/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [shell/shell32](../../shell/shell32) | 760 | [shell/shell32/dirs](../../shell/shell32/dirs) | — | — |
| [shell/shell32/downlevel](../../shell/shell32/downlevel) | 6 | [shell/shell32/downlevel/sources](../../shell/shell32/downlevel/sources), [shell/shell32/downlevel/makefile](../../shell/shell32/downlevel/makefile) | `downlevel_shell32` | `LIBRARY` |
| [shell/shell32/menuband](../../shell/shell32/menuband) | 48 | [shell/shell32/menuband/sources](../../shell/shell32/menuband/sources), [shell/shell32/menuband/makefile](../../shell/shell32/menuband/makefile) | `menuband` | `LIBRARY` |
| [shell/shell32/ntcpp](../../shell/shell32/ntcpp) | 2 | [shell/shell32/ntcpp/sources](../../shell/shell32/ntcpp/sources), [shell/shell32/ntcpp/makefile](../../shell/shell32/ntcpp/makefile) | — | — |
| [shell/shell32/sdspatch](../../shell/shell32/sdspatch) | 14 | [shell/shell32/sdspatch/sources](../../shell/shell32/sdspatch/sources), [shell/shell32/sdspatch/makefile](../../shell/shell32/sdspatch/makefile) | `sdspatch` | `LIBRARY` |
| [shell/shell32/tngen](../../shell/shell32/tngen) | 64 | [shell/shell32/tngen/sources](../../shell/shell32/tngen/sources), [shell/shell32/tngen/makefile](../../shell/shell32/tngen/makefile) | `tngen` | `LIBRARY` |
| [shell/shell32/tngen/include](../../shell/shell32/tngen/include) | 13 | — | — | — |
| [shell/shell32/tools](../../shell/shell32/tools) | 3 | [shell/shell32/tools/sources](../../shell/shell32/tools/sources), [shell/shell32/tools/makefile](../../shell/shell32/tools/makefile) | — | `PROGRAM` |
| [shell/shell32/unicpp](../../shell/shell32/unicpp) | 55 | [shell/shell32/unicpp/dirs](../../shell/shell32/unicpp/dirs) | — | — |
| [shell/shell32/unicpp/ntcpp](../../shell/shell32/unicpp/ntcpp) | 2 | [shell/shell32/unicpp/ntcpp/sources](../../shell/shell32/unicpp/ntcpp/sources), [shell/shell32/unicpp/ntcpp/makefile](../../shell/shell32/unicpp/ntcpp/makefile) | — | — |
| [shell/shell32/unicpp/w95cpp](../../shell/shell32/unicpp/w95cpp) | 2 | [shell/shell32/unicpp/w95cpp/sources](../../shell/shell32/unicpp/w95cpp/sources), [shell/shell32/unicpp/w95cpp/makefile](../../shell/shell32/unicpp/w95cpp/makefile) | — | — |
| [shell/shell32/winnt](../../shell/shell32/winnt) | 3 | [shell/shell32/winnt/sources](../../shell/shell32/winnt/sources), [shell/shell32/winnt/makefile](../../shell/shell32/winnt/makefile) | — | — |

## `shell/shelldrt/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [shell/shelldrt](../../shell/shelldrt) | 9 | [shell/shelldrt/sources](../../shell/shelldrt/sources), [shell/shelldrt/makefile](../../shell/shelldrt/makefile) | `shelldrt` | `PROGRAM` |

## `shell/shlwapi/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [shell/shlwapi](../../shell/shlwapi) | 81 | [shell/shlwapi/dirs](../../shell/shlwapi/dirs) | — | — |
| [shell/shlwapi/dll](../../shell/shlwapi/dll) | 5 | [shell/shlwapi/dll/sources](../../shell/shlwapi/dll/sources), [shell/shlwapi/dll/makefile](../../shell/shlwapi/dll/makefile) | `shlwapi` | `DYNLINK` |
| [shell/shlwapi/nt5api](../../shell/shlwapi/nt5api) | 3 | [shell/shlwapi/nt5api/sources](../../shell/shlwapi/nt5api/sources), [shell/shlwapi/nt5api/makefile](../../shell/shlwapi/nt5api/makefile) | — | — |
| [shell/shlwapi/resdll](../../shell/shlwapi/resdll) | 3 | [shell/shlwapi/resdll/sources](../../shell/shlwapi/resdll/sources), [shell/shlwapi/resdll/makefile](../../shell/shlwapi/resdll/makefile) | `shlwaplc` | `DYNLINK` |
| [shell/shlwapi/srca](../../shell/shlwapi/srca) | 4 | [shell/shlwapi/srca/sources](../../shell/shlwapi/srca/sources), [shell/shlwapi/srca/makefile](../../shell/shlwapi/srca/makefile) | `shlwansi` | `LIBRARY` |
| [shell/shlwapi/srccpp](../../shell/shlwapi/srccpp) | 4 | [shell/shlwapi/srccpp/sources](../../shell/shlwapi/srccpp/sources), [shell/shlwapi/srccpp/makefile](../../shell/shlwapi/srccpp/makefile) | `srccpp` | `LIBRARY` |
| [shell/shlwapi/srcw](../../shell/shlwapi/srcw) | 4 | [shell/shlwapi/srcw/sources](../../shell/shlwapi/srcw/sources), [shell/shlwapi/srcw/makefile](../../shell/shlwapi/srcw/makefile) | `shlwuni` | `LIBRARY` |

## `shell/sld/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [shell/sld](../../shell/sld) | 49 | [shell/sld/sources](../../shell/sld/sources), [shell/sld/makefile](../../shell/sld/makefile) | — | `NOTARGET` |
| [shell/sld/build](../../shell/sld/build) | 21 | [shell/sld/build/sources](../../shell/sld/build/sources), [shell/sld/build/makefile](../../shell/sld/build/makefile) | — | `NOTARGET` |

## `shell/themes/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [shell/themes](../../shell/themes) | 20 | [shell/themes/dirs](../../shell/themes/dirs) | — | — |
| [shell/themes/clipper](../../shell/themes/clipper) | 45 | [shell/themes/clipper/sources](../../shell/themes/clipper/sources), [shell/themes/clipper/makefile](../../shell/themes/clipper/makefile) | `Clipper` | `PROGRAM` |
| [shell/themes/imagecon](../../shell/themes/imagecon) | 9 | [shell/themes/imagecon/sources](../../shell/themes/imagecon/sources), [shell/themes/imagecon/makefile](../../shell/themes/imagecon/makefile) | `imagecon` | `PROGRAM` |
| [shell/themes/inc](../../shell/themes/inc) | 22 | — | — | — |
| [shell/themes/packthem](../../shell/themes/packthem) | 10 | [shell/themes/packthem/sources](../../shell/themes/packthem/sources), [shell/themes/packthem/makefile](../../shell/themes/packthem/makefile) | `packthem` | `PROGRAM` |
| [shell/themes/preview](../../shell/themes/preview) | 17 | [shell/themes/preview/sources](../../shell/themes/preview/sources), [shell/themes/preview/makefile](../../shell/themes/preview/makefile) | `Preview` | `PROGRAM` |
| [shell/themes/test](../../shell/themes/test) | 0 | — | — | — |
| [shell/themes/test/apicompare](../../shell/themes/test/apicompare) | 5 | [shell/themes/test/apicompare/sources](../../shell/themes/test/apicompare/sources), [shell/themes/test/apicompare/makefile](../../shell/themes/test/apicompare/makefile) | `APICompare` | `PROGRAM` |
| [shell/themes/test/ctlperf](../../shell/themes/test/ctlperf) | 20 | [shell/themes/test/ctlperf/sources](../../shell/themes/test/ctlperf/sources), [shell/themes/test/ctlperf/makefile](../../shell/themes/test/ctlperf/makefile) | `CtlPerf` | `PROGRAM` |
| [shell/themes/test/ctlperf/res](../../shell/themes/test/ctlperf/res) | 1 | — | — | — |
| [shell/themes/test/drawedge](../../shell/themes/test/drawedge) | 7 | [shell/themes/test/drawedge/sources](../../shell/themes/test/drawedge/sources), [shell/themes/test/drawedge/makefile](../../shell/themes/test/drawedge/makefile) | `DrawEdge` | `PROGRAM` |
| [shell/themes/test/framemetrics](../../shell/themes/test/framemetrics) | 10 | [shell/themes/test/framemetrics/sources](../../shell/themes/test/framemetrics/sources), [shell/themes/test/framemetrics/makefile](../../shell/themes/test/framemetrics/makefile) | `frameMetrics` | `PROGRAM` |
| [shell/themes/test/mditest](../../shell/themes/test/mditest) | 21 | [shell/themes/test/mditest/sources](../../shell/themes/test/mditest/sources), [shell/themes/test/mditest/makefile](../../shell/themes/test/mditest/makefile) | `mditest` | `PROGRAM` |
| [shell/themes/test/mditest/res](../../shell/themes/test/mditest/res) | 4 | — | — | — |
| [shell/themes/test/ncperf](../../shell/themes/test/ncperf) | 12 | [shell/themes/test/ncperf/sources](../../shell/themes/test/ncperf/sources), [shell/themes/test/ncperf/makefile](../../shell/themes/test/ncperf/makefile) | `ncperf` | `PROGRAM` |
| [shell/themes/test/ninegrid](../../shell/themes/test/ninegrid) | 14 | [shell/themes/test/ninegrid/sources](../../shell/themes/test/ninegrid/sources), [shell/themes/test/ninegrid/makefile](../../shell/themes/test/ninegrid/makefile) | `ninegrid` | `PROGRAM` |
| [shell/themes/test/spywindows](../../shell/themes/test/spywindows) | 5 | [shell/themes/test/spywindows/sources](../../shell/themes/test/spywindows/sources), [shell/themes/test/spywindows/makefile](../../shell/themes/test/spywindows/makefile) | `SpyWindows` | `PROGRAM` |
| [shell/themes/test/threadctlperf](../../shell/themes/test/threadctlperf) | 14 | [shell/themes/test/threadctlperf/sources](../../shell/themes/test/threadctlperf/sources), [shell/themes/test/threadctlperf/makefile](../../shell/themes/test/threadctlperf/makefile) | `ThreadCtlPerf` | `PROGRAM` |
| [shell/themes/test/threadctlperf/res](../../shell/themes/test/threadctlperf/res) | 2 | — | — | — |
| [shell/themes/themedir](../../shell/themes/themedir) | 10 | [shell/themes/themedir/dirs](../../shell/themes/themedir/dirs) | — | — |
| [shell/themes/themedir/candy](../../shell/themes/themedir/candy) | 37 | [shell/themes/themedir/candy/sources](../../shell/themes/themedir/candy/sources), [shell/themes/themedir/candy/makefile](../../shell/themes/themedir/candy/makefile) | `Candy` | `NOTARGET` |
| [shell/themes/themedir/docs](../../shell/themes/themedir/docs) | 2 | — | — | — |
| [shell/themes/themedir/empty](../../shell/themes/themedir/empty) | 6 | [shell/themes/themedir/empty/sources](../../shell/themes/themedir/empty/sources), [shell/themes/themedir/empty/makefile](../../shell/themes/themedir/empty/makefile) | — | `NOTARGET` |
| [shell/themes/themedir/luna](../../shell/themes/themedir/luna) | 6 | [shell/themes/themedir/luna/sources](../../shell/themes/themedir/luna/sources), [shell/themes/themedir/luna/makefile](../../shell/themes/themedir/luna/makefile) | `Luna` | `NOTARGET` |
| [shell/themes/themedir/luna/blue](../../shell/themes/themedir/luna/blue) | 238 | — | — | — |
| [shell/themes/themedir/luna/homestead](../../shell/themes/themedir/luna/homestead) | 238 | — | — | — |
| [shell/themes/themedir/luna/metallic](../../shell/themes/themedir/luna/metallic) | 244 | — | — | — |
| [shell/themes/themedir/mallard](../../shell/themes/themedir/mallard) | 239 | [shell/themes/themedir/mallard/sources](../../shell/themes/themedir/mallard/sources), [shell/themes/themedir/mallard/makefile](../../shell/themes/themedir/mallard/makefile) | `Test` | `NOTARGET` |
| [shell/themes/themedir/native](../../shell/themes/themedir/native) | 9 | [shell/themes/themedir/native/sources](../../shell/themes/themedir/native/sources), [shell/themes/themedir/native/makefile](../../shell/themes/themedir/native/makefile) | `Native` | `NOTARGET` |
| [shell/themes/themedir/professional](../../shell/themes/themedir/professional) | 111 | [shell/themes/themedir/professional/sources](../../shell/themes/themedir/professional/sources), [shell/themes/themedir/professional/makefile](../../shell/themes/themedir/professional/makefile) | — | `NOTARGET` |
| [shell/themes/themedir/shellstyle](../../shell/themes/themedir/shellstyle) | 10 | [shell/themes/themedir/shellstyle/dirs](../../shell/themes/themedir/shellstyle/dirs) | — | — |
| [shell/themes/themedir/shellstyle/blue](../../shell/themes/themedir/shellstyle/blue) | 35 | [shell/themes/themedir/shellstyle/blue/sources](../../shell/themes/themedir/shellstyle/blue/sources), [shell/themes/themedir/shellstyle/blue/makefile](../../shell/themes/themedir/shellstyle/blue/makefile) | `blue_ss` | `DYNLINK` |
| [shell/themes/themedir/shellstyle/classic](../../shell/themes/themedir/shellstyle/classic) | 21 | [shell/themes/themedir/shellstyle/classic/sources](../../shell/themes/themedir/shellstyle/classic/sources), [shell/themes/themedir/shellstyle/classic/makefile](../../shell/themes/themedir/shellstyle/classic/makefile) | `class_ss` | `DYNLINK` |
| [shell/themes/themedir/shellstyle/homestead](../../shell/themes/themedir/shellstyle/homestead) | 35 | [shell/themes/themedir/shellstyle/homestead/sources](../../shell/themes/themedir/shellstyle/homestead/sources), [shell/themes/themedir/shellstyle/homestead/makefile](../../shell/themes/themedir/shellstyle/homestead/makefile) | `home_ss` | `DYNLINK` |
| [shell/themes/themedir/shellstyle/metallic](../../shell/themes/themedir/shellstyle/metallic) | 35 | [shell/themes/themedir/shellstyle/metallic/sources](../../shell/themes/themedir/shellstyle/metallic/sources), [shell/themes/themedir/shellstyle/metallic/makefile](../../shell/themes/themedir/shellstyle/metallic/makefile) | `metal_ss` | `DYNLINK` |
| [shell/themes/themefiles](../../shell/themes/themefiles) | 2 | [shell/themes/themefiles/dirs](../../shell/themes/themefiles/dirs) | — | — |
| [shell/themes/themefiles/bla](../../shell/themes/themefiles/bla) | 4 | [shell/themes/themefiles/bla/sources](../../shell/themes/themefiles/bla/sources), [shell/themes/themefiles/bla/makefile](../../shell/themes/themefiles/bla/makefile) | — | `NOTARGET` |
| [shell/themes/themefiles/common](../../shell/themes/themefiles/common) | 4 | [shell/themes/themefiles/common/sources](../../shell/themes/themefiles/common/sources), [shell/themes/themefiles/common/makefile](../../shell/themes/themefiles/common/makefile) | — | `NOTARGET` |
| [shell/themes/themefiles/dtc](../../shell/themes/themefiles/dtc) | 4 | [shell/themes/themefiles/dtc/sources](../../shell/themes/themefiles/dtc/sources), [shell/themes/themefiles/dtc/makefile](../../shell/themes/themefiles/dtc/makefile) | — | `NOTARGET` |
| [shell/themes/themefiles/ent](../../shell/themes/themefiles/ent) | 4 | [shell/themes/themefiles/ent/sources](../../shell/themes/themefiles/ent/sources), [shell/themes/themefiles/ent/makefile](../../shell/themes/themefiles/ent/makefile) | — | `NOTARGET` |
| [shell/themes/themefiles/per](../../shell/themes/themefiles/per) | 4 | [shell/themes/themefiles/per/sources](../../shell/themes/themefiles/per/sources), [shell/themes/themefiles/per/makefile](../../shell/themes/themefiles/per/makefile) | — | `NOTARGET` |
| [shell/themes/themefiles/pro](../../shell/themes/themefiles/pro) | 4 | [shell/themes/themefiles/pro/sources](../../shell/themes/themefiles/pro/sources), [shell/themes/themefiles/pro/makefile](../../shell/themes/themefiles/pro/makefile) | — | `NOTARGET` |
| [shell/themes/themefiles/srv](../../shell/themes/themefiles/srv) | 4 | [shell/themes/themefiles/srv/sources](../../shell/themes/themefiles/srv/sources), [shell/themes/themefiles/srv/makefile](../../shell/themes/themefiles/srv/makefile) | — | `NOTARGET` |
| [shell/themes/themeldr](../../shell/themes/themeldr) | 14 | [shell/themes/themeldr/sources](../../shell/themes/themeldr/sources), [shell/themes/themeldr/makefile](../../shell/themes/themeldr/makefile) | `ThemeLdr` | `LIBRARY` |
| [shell/themes/themesel](../../shell/themes/themesel) | 22 | [shell/themes/themesel/sources](../../shell/themes/themesel/sources), [shell/themes/themesel/makefile](../../shell/themes/themesel/makefile) | `themesel` | `PROGRAM` |
| [shell/themes/themeui](../../shell/themes/themeui) | 99 | [shell/themes/themeui/sources](../../shell/themes/themeui/sources), [shell/themes/themeui/makefile](../../shell/themes/themeui/makefile) | `ThemeUI` | `DYNLINK` |
| [shell/themes/uxbud](../../shell/themes/uxbud) | 18 | [shell/themes/uxbud/sources](../../shell/themes/uxbud/sources), [shell/themes/uxbud/makefile](../../shell/themes/uxbud/makefile) | `uxbud` | `PROGRAM` |
| [shell/themes/uxtheme](../../shell/themes/uxtheme) | 78 | [shell/themes/uxtheme/sources](../../shell/themes/uxtheme/sources), [shell/themes/uxtheme/makefile](../../shell/themes/uxtheme/makefile) | `UxTheme` | `DYNLINK` |

## `shell/thunk/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [shell/thunk](../../shell/thunk) | 19 | [shell/thunk/makefile](../../shell/thunk/makefile) | — | — |

## `shell/tools/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [shell/tools](../../shell/tools) | 1 | [shell/tools/dirs](../../shell/tools/dirs) | — | — |
| [shell/tools/balloon](../../shell/tools/balloon) | 6 | — | — | — |
| [shell/tools/blesslnk](../../shell/tools/blesslnk) | 10 | [shell/tools/blesslnk/sources](../../shell/tools/blesslnk/sources), [shell/tools/blesslnk/makefile](../../shell/tools/blesslnk/makefile) | `blesslnk` | `PROGRAM` |
| [shell/tools/chinproc](../../shell/tools/chinproc) | 9 | [shell/tools/chinproc/sources](../../shell/tools/chinproc/sources), [shell/tools/chinproc/makefile](../../shell/tools/chinproc/makefile) | `chinproc` | `PROGRAM` |
| [shell/tools/cleaninf](../../shell/tools/cleaninf) | 13 | [shell/tools/cleaninf/sources](../../shell/tools/cleaninf/sources), [shell/tools/cleaninf/makefile](../../shell/tools/cleaninf/makefile) | `cleaninf` | `PROGRAM` |
| [shell/tools/clip](../../shell/tools/clip) | 8 | — | — | — |
| [shell/tools/ddespy](../../shell/tools/ddespy) | 13 | [shell/tools/ddespy/sources](../../shell/tools/ddespy/sources), [shell/tools/ddespy/makefile](../../shell/tools/ddespy/makefile) | `ddespy` | `PROGRAM` |
| [shell/tools/drv](../../shell/tools/drv) | 3 | [shell/tools/drv/sources](../../shell/tools/drv/sources), [shell/tools/drv/makefile](../../shell/tools/drv/makefile) | `drv` | `PROGRAM` |
| [shell/tools/drvfull](../../shell/tools/drvfull) | 21 | [shell/tools/drvfull/sources](../../shell/tools/drvfull/sources), [shell/tools/drvfull/makefile](../../shell/tools/drvfull/makefile) | `drvfull` | `PROGRAM` |
| [shell/tools/extwiz](../../shell/tools/extwiz) | 24 | — | — | — |
| [shell/tools/extwiz/res](../../shell/tools/extwiz/res) | 1 | — | — | — |
| [shell/tools/extwiz/template](../../shell/tools/extwiz/template) | 25 | — | — | — |
| [shell/tools/fileassoc](../../shell/tools/fileassoc) | 1 | — | — | — |
| [shell/tools/fileassoc/stats](../../shell/tools/fileassoc/stats) | 4 | — | — | — |
| [shell/tools/fileassoc/wwwroot](../../shell/tools/fileassoc/wwwroot) | 0 | — | — | — |
| [shell/tools/fileassoc/wwwroot/fileassoc](../../shell/tools/fileassoc/wwwroot/fileassoc) | 1 | — | — | — |
| [shell/tools/fileassoc/wwwroot/fileassoc/0409](../../shell/tools/fileassoc/wwwroot/fileassoc/0409) | 5 | — | — | — |
| [shell/tools/fileassoc/wwwroot/fileassoc/0409/xml](../../shell/tools/fileassoc/wwwroot/fileassoc/0409/xml) | 47 | — | — | — |
| [shell/tools/fileassoc/wwwroot/publishwizard](../../shell/tools/fileassoc/wwwroot/publishwizard) | 5 | — | — | — |
| [shell/tools/fileassoc/wwwroot/setup](../../shell/tools/fileassoc/wwwroot/setup) | 1 | — | — | — |
| [shell/tools/hdrver](../../shell/tools/hdrver) | 9 | [shell/tools/hdrver/sources](../../shell/tools/hdrver/sources), [shell/tools/hdrver/makefile](../../shell/tools/hdrver/makefile) | `hdrver` | `PROGRAM` |
| [shell/tools/netplwiz](../../shell/tools/netplwiz) | 3 | [shell/tools/netplwiz/sources](../../shell/tools/netplwiz/sources), [shell/tools/netplwiz/makefile](../../shell/tools/netplwiz/makefile) | `netplwizexe` | `PROGRAM` |
| [shell/tools/packchk](../../shell/tools/packchk) | 7 | [shell/tools/packchk/sources](../../shell/tools/packchk/sources), [shell/tools/packchk/makefile](../../shell/tools/packchk/makefile) | `packchk` | `PROGRAM` |
| [shell/tools/regdate](../../shell/tools/regdate) | 3 | [shell/tools/regdate/sources](../../shell/tools/regdate/sources), [shell/tools/regdate/makefile](../../shell/tools/regdate/makefile) | `regdate` | `PROGRAM` |
| [shell/tools/reginst](../../shell/tools/reginst) | 9 | [shell/tools/reginst/sources](../../shell/tools/reginst/sources), [shell/tools/reginst/makefile](../../shell/tools/reginst/makefile) | `reginst` | `PROGRAM` |
| [shell/tools/shlexts](../../shell/tools/shlexts) | 17 | [shell/tools/shlexts/dirs](../../shell/tools/shlexts/dirs) | — | — |
| [shell/tools/shlexts/cpp](../../shell/tools/shlexts/cpp) | 2 | [shell/tools/shlexts/cpp/sources](../../shell/tools/shlexts/cpp/sources), [shell/tools/shlexts/cpp/makefile](../../shell/tools/shlexts/cpp/makefile) | `shlcpp` | `LIBRARY` |
| [shell/tools/shlexts/ntsd](../../shell/tools/shlexts/ntsd) | 3 | [shell/tools/shlexts/ntsd/sources](../../shell/tools/shlexts/ntsd/sources), [shell/tools/shlexts/ntsd/makefile](../../shell/tools/shlexts/ntsd/makefile) | — | — |
| [shell/tools/starbuck](../../shell/tools/starbuck) | 22 | [shell/tools/starbuck/sources](../../shell/tools/starbuck/sources), [shell/tools/starbuck/makefile](../../shell/tools/starbuck/makefile) | `Starbuck` | `DYNLINK` |
| [shell/tools/stubgen](../../shell/tools/stubgen) | 3 | [shell/tools/stubgen/sources](../../shell/tools/stubgen/sources), [shell/tools/stubgen/makefile](../../shell/tools/stubgen/makefile) | `stubgen` | `PROGRAM` |
| [shell/tools/test](../../shell/tools/test) | 3 | [shell/tools/test/sources](../../shell/tools/test/sources), [shell/tools/test/makefile](../../shell/tools/test/makefile) | `test` | `PROGRAM` |

## `shell/typebin/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [shell/typebin](../../shell/typebin) | 0 | — | — | — |
| [shell/typebin/i386](../../shell/typebin/i386) | 5 | — | — | — |

## `shell/types/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [shell/types](../../shell/types) | 6 | [shell/types/sources](../../shell/types/sources), [shell/types/makefile](../../shell/types/makefile) | — | `NOTARGET` |

## `shell/wallpaper/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [shell/wallpaper](../../shell/wallpaper) | 2 | [shell/wallpaper/dirs](../../shell/wallpaper/dirs) | — | — |
| [shell/wallpaper/bla](../../shell/wallpaper/bla) | 2 | [shell/wallpaper/bla/sources](../../shell/wallpaper/bla/sources), [shell/wallpaper/bla/makefile](../../shell/wallpaper/bla/makefile) | — | `NOTARGET` |
| [shell/wallpaper/common](../../shell/wallpaper/common) | 21 | [shell/wallpaper/common/sources](../../shell/wallpaper/common/sources), [shell/wallpaper/common/makefile](../../shell/wallpaper/common/makefile) | — | `NOTARGET` |
| [shell/wallpaper/dtc](../../shell/wallpaper/dtc) | 2 | [shell/wallpaper/dtc/sources](../../shell/wallpaper/dtc/sources), [shell/wallpaper/dtc/makefile](../../shell/wallpaper/dtc/makefile) | — | `NOTARGET` |
| [shell/wallpaper/ent](../../shell/wallpaper/ent) | 2 | [shell/wallpaper/ent/sources](../../shell/wallpaper/ent/sources), [shell/wallpaper/ent/makefile](../../shell/wallpaper/ent/makefile) | — | `NOTARGET` |
| [shell/wallpaper/per](../../shell/wallpaper/per) | 3 | [shell/wallpaper/per/sources](../../shell/wallpaper/per/sources), [shell/wallpaper/per/makefile](../../shell/wallpaper/per/makefile) | — | `NOTARGET` |
| [shell/wallpaper/pro](../../shell/wallpaper/pro) | 3 | [shell/wallpaper/pro/sources](../../shell/wallpaper/pro/sources), [shell/wallpaper/pro/makefile](../../shell/wallpaper/pro/makefile) | — | `NOTARGET` |
| [shell/wallpaper/srv](../../shell/wallpaper/srv) | 2 | [shell/wallpaper/srv/sources](../../shell/wallpaper/srv/sources), [shell/wallpaper/srv/makefile](../../shell/wallpaper/srv/makefile) | — | `NOTARGET` |
