# `base/` — directory and build-definition inventory

**4307 tracked directories; 2791 directories with `sources`.**
Read the [explanation of `base/`](../components/base.md),
the [catalog key](README.md), or the [agent guide](../README.md).
This is a literal inventory, not a resolved build graph or a claim that every
directory is shipped. Paths and metadata reflect tracked files at generation time.

## `base/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [base](../../base) | 3 | [base/dirs](../../base/dirs) | — | — |

## `base/basedrv/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [base/basedrv](../../base/basedrv) | 1 | [base/basedrv/dirs](../../base/basedrv/dirs) | — | — |
| [base/basedrv/pnpmem](../../base/basedrv/pnpmem) | 9 | [base/basedrv/pnpmem/sources](../../base/basedrv/pnpmem/sources), [base/basedrv/pnpmem/makefile](../../base/basedrv/pnpmem/makefile) | `pnpmem` | `DRIVER` |

## `base/boot/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [base/boot](../../base/boot) | 6 | [base/boot/dirs](../../base/boot/dirs) | — | — |
| [base/boot/bd](../../base/boot/bd) | 13 | [base/boot/bd/dirs](../../base/boot/bd/dirs) | — | — |
| [base/boot/bd/daytona](../../base/boot/bd/daytona) | 2 | [base/boot/bd/daytona/sources](../../base/boot/bd/daytona/sources), [base/boot/bd/daytona/makefile](../../base/boot/bd/daytona/makefile) | — | — |
| [base/boot/bd/daytona_dbg](../../base/boot/bd/daytona_dbg) | 2 | [base/boot/bd/daytona_dbg/sources](../../base/boot/bd/daytona_dbg/sources), [base/boot/bd/daytona_dbg/makefile](../../base/boot/bd/daytona_dbg/makefile) | — | — |
| [base/boot/bd/i386](../../base/boot/bd/i386) | 10 | [base/boot/bd/i386/sources](../../base/boot/bd/i386/sources) | — | — |
| [base/boot/bd/ia64](../../base/boot/bd/ia64) | 11 | [base/boot/bd/ia64/sources](../../base/boot/bd/ia64/sources) | — | — |
| [base/boot/bldr](../../base/boot/bldr) | 35 | [base/boot/bldr/dirs](../../base/boot/bldr/dirs) | — | — |
| [base/boot/bldr/br](../../base/boot/bldr/br) | 3 | [base/boot/bldr/br/sources](../../base/boot/bldr/br/sources), [base/boot/bldr/br/makefile](../../base/boot/bldr/br/makefile) | — | — |
| [base/boot/bldr/br/i386](../../base/boot/bldr/br/i386) | 2 | [base/boot/bldr/br/i386/sources](../../base/boot/bldr/br/i386/sources) | — | — |
| [base/boot/bldr/chs](../../base/boot/bldr/chs) | 3 | [base/boot/bldr/chs/sources](../../base/boot/bldr/chs/sources), [base/boot/bldr/chs/makefile](../../base/boot/bldr/chs/makefile) | — | — |
| [base/boot/bldr/chs/i386](../../base/boot/bldr/chs/i386) | 2 | [base/boot/bldr/chs/i386/sources](../../base/boot/bldr/chs/i386/sources) | — | — |
| [base/boot/bldr/cht](../../base/boot/bldr/cht) | 3 | [base/boot/bldr/cht/sources](../../base/boot/bldr/cht/sources), [base/boot/bldr/cht/makefile](../../base/boot/bldr/cht/makefile) | — | — |
| [base/boot/bldr/cht/i386](../../base/boot/bldr/cht/i386) | 2 | [base/boot/bldr/cht/i386/sources](../../base/boot/bldr/cht/i386/sources) | — | — |
| [base/boot/bldr/cs](../../base/boot/bldr/cs) | 3 | [base/boot/bldr/cs/sources](../../base/boot/bldr/cs/sources), [base/boot/bldr/cs/makefile](../../base/boot/bldr/cs/makefile) | — | — |
| [base/boot/bldr/cs/i386](../../base/boot/bldr/cs/i386) | 2 | [base/boot/bldr/cs/i386/sources](../../base/boot/bldr/cs/i386/sources) | — | — |
| [base/boot/bldr/da](../../base/boot/bldr/da) | 3 | [base/boot/bldr/da/sources](../../base/boot/bldr/da/sources), [base/boot/bldr/da/makefile](../../base/boot/bldr/da/makefile) | — | — |
| [base/boot/bldr/da/i386](../../base/boot/bldr/da/i386) | 2 | [base/boot/bldr/da/i386/sources](../../base/boot/bldr/da/i386/sources) | — | — |
| [base/boot/bldr/daytona](../../base/boot/bldr/daytona) | 3 | [base/boot/bldr/daytona/sources](../../base/boot/bldr/daytona/sources), [base/boot/bldr/daytona/makefile](../../base/boot/bldr/daytona/makefile) | — | — |
| [base/boot/bldr/daytona/i386](../../base/boot/bldr/daytona/i386) | 2 | [base/boot/bldr/daytona/i386/sources](../../base/boot/bldr/daytona/i386/sources) | — | — |
| [base/boot/bldr/daytona_dbg](../../base/boot/bldr/daytona_dbg) | 3 | [base/boot/bldr/daytona_dbg/sources](../../base/boot/bldr/daytona_dbg/sources), [base/boot/bldr/daytona_dbg/makefile](../../base/boot/bldr/daytona_dbg/makefile) | — | — |
| [base/boot/bldr/daytona_dbg/i386](../../base/boot/bldr/daytona_dbg/i386) | 1 | [base/boot/bldr/daytona_dbg/i386/sources](../../base/boot/bldr/daytona_dbg/i386/sources) | — | — |
| [base/boot/bldr/el](../../base/boot/bldr/el) | 3 | [base/boot/bldr/el/sources](../../base/boot/bldr/el/sources), [base/boot/bldr/el/makefile](../../base/boot/bldr/el/makefile) | — | — |
| [base/boot/bldr/el/i386](../../base/boot/bldr/el/i386) | 2 | [base/boot/bldr/el/i386/sources](../../base/boot/bldr/el/i386/sources) | — | — |
| [base/boot/bldr/el_dbg](../../base/boot/bldr/el_dbg) | 3 | [base/boot/bldr/el_dbg/sources](../../base/boot/bldr/el_dbg/sources), [base/boot/bldr/el_dbg/makefile](../../base/boot/bldr/el_dbg/makefile) | — | — |
| [base/boot/bldr/el_dbg/i386](../../base/boot/bldr/el_dbg/i386) | 2 | [base/boot/bldr/el_dbg/i386/sources](../../base/boot/bldr/el_dbg/i386/sources) | — | — |
| [base/boot/bldr/es](../../base/boot/bldr/es) | 3 | [base/boot/bldr/es/sources](../../base/boot/bldr/es/sources), [base/boot/bldr/es/makefile](../../base/boot/bldr/es/makefile) | — | — |
| [base/boot/bldr/es/i386](../../base/boot/bldr/es/i386) | 2 | [base/boot/bldr/es/i386/sources](../../base/boot/bldr/es/i386/sources) | — | — |
| [base/boot/bldr/fi](../../base/boot/bldr/fi) | 3 | [base/boot/bldr/fi/sources](../../base/boot/bldr/fi/sources), [base/boot/bldr/fi/makefile](../../base/boot/bldr/fi/makefile) | — | — |
| [base/boot/bldr/fi/i386](../../base/boot/bldr/fi/i386) | 2 | [base/boot/bldr/fi/i386/sources](../../base/boot/bldr/fi/i386/sources) | — | — |
| [base/boot/bldr/fr](../../base/boot/bldr/fr) | 3 | [base/boot/bldr/fr/sources](../../base/boot/bldr/fr/sources), [base/boot/bldr/fr/makefile](../../base/boot/bldr/fr/makefile) | — | — |
| [base/boot/bldr/fr/i386](../../base/boot/bldr/fr/i386) | 2 | [base/boot/bldr/fr/i386/sources](../../base/boot/bldr/fr/i386/sources) | — | — |
| [base/boot/bldr/ger](../../base/boot/bldr/ger) | 3 | [base/boot/bldr/ger/sources](../../base/boot/bldr/ger/sources), [base/boot/bldr/ger/makefile](../../base/boot/bldr/ger/makefile) | — | — |
| [base/boot/bldr/ger/i386](../../base/boot/bldr/ger/i386) | 2 | [base/boot/bldr/ger/i386/sources](../../base/boot/bldr/ger/i386/sources) | — | — |
| [base/boot/bldr/hu](../../base/boot/bldr/hu) | 3 | [base/boot/bldr/hu/sources](../../base/boot/bldr/hu/sources), [base/boot/bldr/hu/makefile](../../base/boot/bldr/hu/makefile) | — | — |
| [base/boot/bldr/hu/i386](../../base/boot/bldr/hu/i386) | 2 | [base/boot/bldr/hu/i386/sources](../../base/boot/bldr/hu/i386/sources) | — | — |
| [base/boot/bldr/i386](../../base/boot/bldr/i386) | 3 | — | — | — |
| [base/boot/bldr/ia64](../../base/boot/bldr/ia64) | 2 | [base/boot/bldr/ia64/sources](../../base/boot/bldr/ia64/sources) | — | — |
| [base/boot/bldr/it](../../base/boot/bldr/it) | 3 | [base/boot/bldr/it/sources](../../base/boot/bldr/it/sources), [base/boot/bldr/it/makefile](../../base/boot/bldr/it/makefile) | — | — |
| [base/boot/bldr/it/i386](../../base/boot/bldr/it/i386) | 2 | [base/boot/bldr/it/i386/sources](../../base/boot/bldr/it/i386/sources) | — | — |
| [base/boot/bldr/jpn](../../base/boot/bldr/jpn) | 3 | [base/boot/bldr/jpn/sources](../../base/boot/bldr/jpn/sources), [base/boot/bldr/jpn/makefile](../../base/boot/bldr/jpn/makefile) | — | — |
| [base/boot/bldr/jpn/i386](../../base/boot/bldr/jpn/i386) | 2 | [base/boot/bldr/jpn/i386/sources](../../base/boot/bldr/jpn/i386/sources) | — | — |
| [base/boot/bldr/kor](../../base/boot/bldr/kor) | 3 | [base/boot/bldr/kor/sources](../../base/boot/bldr/kor/sources), [base/boot/bldr/kor/makefile](../../base/boot/bldr/kor/makefile) | — | — |
| [base/boot/bldr/kor/i386](../../base/boot/bldr/kor/i386) | 2 | [base/boot/bldr/kor/i386/sources](../../base/boot/bldr/kor/i386/sources) | — | — |
| [base/boot/bldr/nl](../../base/boot/bldr/nl) | 3 | [base/boot/bldr/nl/sources](../../base/boot/bldr/nl/sources), [base/boot/bldr/nl/makefile](../../base/boot/bldr/nl/makefile) | — | — |
| [base/boot/bldr/nl/i386](../../base/boot/bldr/nl/i386) | 2 | [base/boot/bldr/nl/i386/sources](../../base/boot/bldr/nl/i386/sources) | — | — |
| [base/boot/bldr/nl_dbg](../../base/boot/bldr/nl_dbg) | 3 | [base/boot/bldr/nl_dbg/sources](../../base/boot/bldr/nl_dbg/sources), [base/boot/bldr/nl_dbg/makefile](../../base/boot/bldr/nl_dbg/makefile) | — | — |
| [base/boot/bldr/nl_dbg/i386](../../base/boot/bldr/nl_dbg/i386) | 2 | [base/boot/bldr/nl_dbg/i386/sources](../../base/boot/bldr/nl_dbg/i386/sources) | — | — |
| [base/boot/bldr/no](../../base/boot/bldr/no) | 3 | [base/boot/bldr/no/sources](../../base/boot/bldr/no/sources), [base/boot/bldr/no/makefile](../../base/boot/bldr/no/makefile) | — | — |
| [base/boot/bldr/no/i386](../../base/boot/bldr/no/i386) | 2 | [base/boot/bldr/no/i386/sources](../../base/boot/bldr/no/i386/sources) | — | — |
| [base/boot/bldr/pl](../../base/boot/bldr/pl) | 3 | [base/boot/bldr/pl/sources](../../base/boot/bldr/pl/sources), [base/boot/bldr/pl/makefile](../../base/boot/bldr/pl/makefile) | — | — |
| [base/boot/bldr/pl/i386](../../base/boot/bldr/pl/i386) | 2 | [base/boot/bldr/pl/i386/sources](../../base/boot/bldr/pl/i386/sources) | — | — |
| [base/boot/bldr/psu](../../base/boot/bldr/psu) | 3 | [base/boot/bldr/psu/sources](../../base/boot/bldr/psu/sources), [base/boot/bldr/psu/makefile](../../base/boot/bldr/psu/makefile) | — | — |
| [base/boot/bldr/psu/i386](../../base/boot/bldr/psu/i386) | 2 | [base/boot/bldr/psu/i386/sources](../../base/boot/bldr/psu/i386/sources) | — | — |
| [base/boot/bldr/pt](../../base/boot/bldr/pt) | 3 | [base/boot/bldr/pt/sources](../../base/boot/bldr/pt/sources), [base/boot/bldr/pt/makefile](../../base/boot/bldr/pt/makefile) | — | — |
| [base/boot/bldr/pt/i386](../../base/boot/bldr/pt/i386) | 2 | [base/boot/bldr/pt/i386/sources](../../base/boot/bldr/pt/i386/sources) | — | — |
| [base/boot/bldr/ru](../../base/boot/bldr/ru) | 3 | [base/boot/bldr/ru/sources](../../base/boot/bldr/ru/sources), [base/boot/bldr/ru/makefile](../../base/boot/bldr/ru/makefile) | — | — |
| [base/boot/bldr/ru/i386](../../base/boot/bldr/ru/i386) | 2 | [base/boot/bldr/ru/i386/sources](../../base/boot/bldr/ru/i386/sources) | — | — |
| [base/boot/bldr/spcrtest](../../base/boot/bldr/spcrtest) | 4 | [base/boot/bldr/spcrtest/sources](../../base/boot/bldr/spcrtest/sources), [base/boot/bldr/spcrtest/makefile](../../base/boot/bldr/spcrtest/makefile) | — | — |
| [base/boot/bldr/spcrtest/i386](../../base/boot/bldr/spcrtest/i386) | 1 | [base/boot/bldr/spcrtest/i386/sources](../../base/boot/bldr/spcrtest/i386/sources) | — | — |
| [base/boot/bldr/sv](../../base/boot/bldr/sv) | 3 | [base/boot/bldr/sv/sources](../../base/boot/bldr/sv/sources), [base/boot/bldr/sv/makefile](../../base/boot/bldr/sv/makefile) | — | — |
| [base/boot/bldr/sv/i386](../../base/boot/bldr/sv/i386) | 2 | [base/boot/bldr/sv/i386/sources](../../base/boot/bldr/sv/i386/sources) | — | — |
| [base/boot/bldr/tr](../../base/boot/bldr/tr) | 3 | [base/boot/bldr/tr/sources](../../base/boot/bldr/tr/sources), [base/boot/bldr/tr/makefile](../../base/boot/bldr/tr/makefile) | — | — |
| [base/boot/bldr/tr/i386](../../base/boot/bldr/tr/i386) | 2 | [base/boot/bldr/tr/i386/sources](../../base/boot/bldr/tr/i386/sources) | — | — |
| [base/boot/bldr/tst](../../base/boot/bldr/tst) | 3 | [base/boot/bldr/tst/sources](../../base/boot/bldr/tst/sources), [base/boot/bldr/tst/makefile](../../base/boot/bldr/tst/makefile) | — | — |
| [base/boot/bldr/tst/i386](../../base/boot/bldr/tst/i386) | 2 | [base/boot/bldr/tst/i386/sources](../../base/boot/bldr/tst/i386/sources) | — | — |
| [base/boot/bootcode](../../base/boot/bootcode) | 1 | [base/boot/bootcode/dirs](../../base/boot/bootcode/dirs) | — | — |
| [base/boot/bootcode/etfs](../../base/boot/bootcode/etfs) | 3 | [base/boot/bootcode/etfs/sources](../../base/boot/bootcode/etfs/sources), [base/boot/bootcode/etfs/makefile](../../base/boot/bootcode/etfs/makefile) | `bootfix` | `NOTARGET` |
| [base/boot/bootcode/etfs.br](../../base/boot/bootcode/etfs.br) | 3 | [base/boot/bootcode/etfs.br/sources](../../base/boot/bootcode/etfs.br/sources), [base/boot/bootcode/etfs.br/makefile](../../base/boot/bootcode/etfs.br/makefile) | — | — |
| [base/boot/bootcode/etfs.cs](../../base/boot/bootcode/etfs.cs) | 3 | [base/boot/bootcode/etfs.cs/sources](../../base/boot/bootcode/etfs.cs/sources), [base/boot/bootcode/etfs.cs/makefile](../../base/boot/bootcode/etfs.cs/makefile) | — | — |
| [base/boot/bootcode/etfs.da](../../base/boot/bootcode/etfs.da) | 3 | [base/boot/bootcode/etfs.da/sources](../../base/boot/bootcode/etfs.da/sources), [base/boot/bootcode/etfs.da/makefile](../../base/boot/bootcode/etfs.da/makefile) | — | — |
| [base/boot/bootcode/etfs.el](../../base/boot/bootcode/etfs.el) | 3 | [base/boot/bootcode/etfs.el/sources](../../base/boot/bootcode/etfs.el/sources), [base/boot/bootcode/etfs.el/makefile](../../base/boot/bootcode/etfs.el/makefile) | — | — |
| [base/boot/bootcode/etfs.es](../../base/boot/bootcode/etfs.es) | 3 | [base/boot/bootcode/etfs.es/sources](../../base/boot/bootcode/etfs.es/sources), [base/boot/bootcode/etfs.es/makefile](../../base/boot/bootcode/etfs.es/makefile) | — | — |
| [base/boot/bootcode/etfs.fi](../../base/boot/bootcode/etfs.fi) | 3 | [base/boot/bootcode/etfs.fi/sources](../../base/boot/bootcode/etfs.fi/sources), [base/boot/bootcode/etfs.fi/makefile](../../base/boot/bootcode/etfs.fi/makefile) | — | — |
| [base/boot/bootcode/etfs.fr](../../base/boot/bootcode/etfs.fr) | 3 | [base/boot/bootcode/etfs.fr/sources](../../base/boot/bootcode/etfs.fr/sources), [base/boot/bootcode/etfs.fr/makefile](../../base/boot/bootcode/etfs.fr/makefile) | — | — |
| [base/boot/bootcode/etfs.ger](../../base/boot/bootcode/etfs.ger) | 3 | [base/boot/bootcode/etfs.ger/sources](../../base/boot/bootcode/etfs.ger/sources), [base/boot/bootcode/etfs.ger/makefile](../../base/boot/bootcode/etfs.ger/makefile) | — | — |
| [base/boot/bootcode/etfs.hu](../../base/boot/bootcode/etfs.hu) | 3 | [base/boot/bootcode/etfs.hu/sources](../../base/boot/bootcode/etfs.hu/sources), [base/boot/bootcode/etfs.hu/makefile](../../base/boot/bootcode/etfs.hu/makefile) | — | — |
| [base/boot/bootcode/etfs.it](../../base/boot/bootcode/etfs.it) | 3 | [base/boot/bootcode/etfs.it/sources](../../base/boot/bootcode/etfs.it/sources), [base/boot/bootcode/etfs.it/makefile](../../base/boot/bootcode/etfs.it/makefile) | — | — |
| [base/boot/bootcode/etfs.nl](../../base/boot/bootcode/etfs.nl) | 3 | [base/boot/bootcode/etfs.nl/sources](../../base/boot/bootcode/etfs.nl/sources), [base/boot/bootcode/etfs.nl/makefile](../../base/boot/bootcode/etfs.nl/makefile) | — | — |
| [base/boot/bootcode/etfs.no](../../base/boot/bootcode/etfs.no) | 3 | [base/boot/bootcode/etfs.no/sources](../../base/boot/bootcode/etfs.no/sources), [base/boot/bootcode/etfs.no/makefile](../../base/boot/bootcode/etfs.no/makefile) | — | — |
| [base/boot/bootcode/etfs.pl](../../base/boot/bootcode/etfs.pl) | 3 | [base/boot/bootcode/etfs.pl/sources](../../base/boot/bootcode/etfs.pl/sources), [base/boot/bootcode/etfs.pl/makefile](../../base/boot/bootcode/etfs.pl/makefile) | — | — |
| [base/boot/bootcode/etfs.pt](../../base/boot/bootcode/etfs.pt) | 3 | [base/boot/bootcode/etfs.pt/sources](../../base/boot/bootcode/etfs.pt/sources), [base/boot/bootcode/etfs.pt/makefile](../../base/boot/bootcode/etfs.pt/makefile) | — | — |
| [base/boot/bootcode/etfs.ru](../../base/boot/bootcode/etfs.ru) | 3 | [base/boot/bootcode/etfs.ru/sources](../../base/boot/bootcode/etfs.ru/sources), [base/boot/bootcode/etfs.ru/makefile](../../base/boot/bootcode/etfs.ru/makefile) | — | — |
| [base/boot/bootcode/etfs.sv](../../base/boot/bootcode/etfs.sv) | 3 | [base/boot/bootcode/etfs.sv/sources](../../base/boot/bootcode/etfs.sv/sources), [base/boot/bootcode/etfs.sv/makefile](../../base/boot/bootcode/etfs.sv/makefile) | — | — |
| [base/boot/bootcode/etfs.tr](../../base/boot/bootcode/etfs.tr) | 3 | [base/boot/bootcode/etfs.tr/sources](../../base/boot/bootcode/etfs.tr/sources), [base/boot/bootcode/etfs.tr/makefile](../../base/boot/bootcode/etfs.tr/makefile) | — | — |
| [base/boot/bootcode/etfs/i386](../../base/boot/bootcode/etfs/i386) | 2 | — | — | — |
| [base/boot/bootcode/etfs/i386/br](../../base/boot/bootcode/etfs/i386/br) | 1 | — | — | — |
| [base/boot/bootcode/etfs/i386/cs](../../base/boot/bootcode/etfs/i386/cs) | 1 | — | — | — |
| [base/boot/bootcode/etfs/i386/da](../../base/boot/bootcode/etfs/i386/da) | 1 | — | — | — |
| [base/boot/bootcode/etfs/i386/es](../../base/boot/bootcode/etfs/i386/es) | 1 | — | — | — |
| [base/boot/bootcode/etfs/i386/fi](../../base/boot/bootcode/etfs/i386/fi) | 1 | — | — | — |
| [base/boot/bootcode/etfs/i386/fr](../../base/boot/bootcode/etfs/i386/fr) | 1 | — | — | — |
| [base/boot/bootcode/etfs/i386/ger](../../base/boot/bootcode/etfs/i386/ger) | 1 | — | — | — |
| [base/boot/bootcode/etfs/i386/hu](../../base/boot/bootcode/etfs/i386/hu) | 1 | — | — | — |
| [base/boot/bootcode/etfs/i386/it](../../base/boot/bootcode/etfs/i386/it) | 1 | — | — | — |
| [base/boot/bootcode/etfs/i386/nl](../../base/boot/bootcode/etfs/i386/nl) | 1 | — | — | — |
| [base/boot/bootcode/etfs/i386/no](../../base/boot/bootcode/etfs/i386/no) | 1 | — | — | — |
| [base/boot/bootcode/etfs/i386/pl](../../base/boot/bootcode/etfs/i386/pl) | 1 | — | — | — |
| [base/boot/bootcode/etfs/i386/pt](../../base/boot/bootcode/etfs/i386/pt) | 1 | — | — | — |
| [base/boot/bootcode/etfs/i386/sv](../../base/boot/bootcode/etfs/i386/sv) | 1 | — | — | — |
| [base/boot/bootcode/etfs/i386/tr](../../base/boot/bootcode/etfs/i386/tr) | 1 | — | — | — |
| [base/boot/bootcode/etfs/i386/usa](../../base/boot/bootcode/etfs/i386/usa) | 2 | — | — | — |
| [base/boot/bootcode/fat](../../base/boot/bootcode/fat) | 0 | — | — | — |
| [base/boot/bootcode/fat/i386](../../base/boot/bootcode/fat/i386) | 13 | — | — | — |
| [base/boot/bootcode/mbr](../../base/boot/bootcode/mbr) | 0 | — | — | — |
| [base/boot/bootcode/mbr/i386](../../base/boot/bootcode/mbr/i386) | 2 | — | — | — |
| [base/boot/bootcode/nlspatch](../../base/boot/bootcode/nlspatch) | 3 | [base/boot/bootcode/nlspatch/sources](../../base/boot/bootcode/nlspatch/sources), [base/boot/bootcode/nlspatch/makefile](../../base/boot/bootcode/nlspatch/makefile) | `patchbc` | `LIBRARY` |
| [base/boot/bootcode/ntfs](../../base/boot/bootcode/ntfs) | 0 | — | — | — |
| [base/boot/bootcode/ntfs/i386](../../base/boot/bootcode/ntfs/i386) | 5 | — | — | — |
| [base/boot/bootcode/ntfs/ia64](../../base/boot/bootcode/ntfs/ia64) | 14 | [base/boot/bootcode/ntfs/ia64/sources](../../base/boot/bootcode/ntfs/ia64/sources), [base/boot/bootcode/ntfs/ia64/makefile](../../base/boot/bootcode/ntfs/ia64/makefile) | `ntfsboot` | `LIBRARY` |
| [base/boot/bootfont](../../base/boot/bootfont) | 3 | [base/boot/bootfont/dirs](../../base/boot/bootfont/dirs) | — | — |
| [base/boot/bootfont/br](../../base/boot/bootfont/br) | 3 | [base/boot/bootfont/br/sources](../../base/boot/bootfont/br/sources), [base/boot/bootfont/br/makefile](../../base/boot/bootfont/br/makefile) | — | — |
| [base/boot/bootfont/br/win2k_ver](../../base/boot/bootfont/br/win2k_ver) | 1 | — | — | — |
| [base/boot/bootfont/btgen](../../base/boot/bootfont/btgen) | 1 | — | — | — |
| [base/boot/bootfont/btgen/i386](../../base/boot/bootfont/btgen/i386) | 1 | — | — | — |
| [base/boot/bootfont/chs](../../base/boot/bootfont/chs) | 4 | [base/boot/bootfont/chs/sources](../../base/boot/bootfont/chs/sources), [base/boot/bootfont/chs/makefile](../../base/boot/bootfont/chs/makefile) | — | — |
| [base/boot/bootfont/chs/win2k_ver](../../base/boot/bootfont/chs/win2k_ver) | 1 | — | — | — |
| [base/boot/bootfont/cht](../../base/boot/bootfont/cht) | 4 | [base/boot/bootfont/cht/sources](../../base/boot/bootfont/cht/sources), [base/boot/bootfont/cht/makefile](../../base/boot/bootfont/cht/makefile) | — | — |
| [base/boot/bootfont/cht/win2k_ver](../../base/boot/bootfont/cht/win2k_ver) | 1 | — | — | — |
| [base/boot/bootfont/convert](../../base/boot/bootfont/convert) | 3 | [base/boot/bootfont/convert/sources](../../base/boot/bootfont/convert/sources), [base/boot/bootfont/convert/makefile](../../base/boot/bootfont/convert/makefile) | `convfont` | `PROGRAM` |
| [base/boot/bootfont/cs](../../base/boot/bootfont/cs) | 3 | [base/boot/bootfont/cs/sources](../../base/boot/bootfont/cs/sources), [base/boot/bootfont/cs/makefile](../../base/boot/bootfont/cs/makefile) | — | — |
| [base/boot/bootfont/cs/win2k_ver](../../base/boot/bootfont/cs/win2k_ver) | 1 | — | — | — |
| [base/boot/bootfont/da](../../base/boot/bootfont/da) | 3 | [base/boot/bootfont/da/sources](../../base/boot/bootfont/da/sources), [base/boot/bootfont/da/makefile](../../base/boot/bootfont/da/makefile) | — | — |
| [base/boot/bootfont/da/win2k_ver](../../base/boot/bootfont/da/win2k_ver) | 1 | — | — | — |
| [base/boot/bootfont/el](../../base/boot/bootfont/el) | 3 | [base/boot/bootfont/el/sources](../../base/boot/bootfont/el/sources), [base/boot/bootfont/el/makefile](../../base/boot/bootfont/el/makefile) | — | — |
| [base/boot/bootfont/el/win2k_ver](../../base/boot/bootfont/el/win2k_ver) | 1 | — | — | — |
| [base/boot/bootfont/es](../../base/boot/bootfont/es) | 3 | [base/boot/bootfont/es/sources](../../base/boot/bootfont/es/sources), [base/boot/bootfont/es/makefile](../../base/boot/bootfont/es/makefile) | — | — |
| [base/boot/bootfont/es/win2k_ver](../../base/boot/bootfont/es/win2k_ver) | 1 | — | — | — |
| [base/boot/bootfont/fi](../../base/boot/bootfont/fi) | 3 | [base/boot/bootfont/fi/sources](../../base/boot/bootfont/fi/sources), [base/boot/bootfont/fi/makefile](../../base/boot/bootfont/fi/makefile) | — | — |
| [base/boot/bootfont/fi/win2k_ver](../../base/boot/bootfont/fi/win2k_ver) | 1 | — | — | — |
| [base/boot/bootfont/fr](../../base/boot/bootfont/fr) | 3 | [base/boot/bootfont/fr/sources](../../base/boot/bootfont/fr/sources), [base/boot/bootfont/fr/makefile](../../base/boot/bootfont/fr/makefile) | — | — |
| [base/boot/bootfont/fr/win2k_ver](../../base/boot/bootfont/fr/win2k_ver) | 1 | — | — | — |
| [base/boot/bootfont/genfont](../../base/boot/bootfont/genfont) | 3 | [base/boot/bootfont/genfont/sources](../../base/boot/bootfont/genfont/sources), [base/boot/bootfont/genfont/makefile](../../base/boot/bootfont/genfont/makefile) | `genfont` | `PROGRAM` |
| [base/boot/bootfont/ger](../../base/boot/bootfont/ger) | 3 | [base/boot/bootfont/ger/sources](../../base/boot/bootfont/ger/sources), [base/boot/bootfont/ger/makefile](../../base/boot/bootfont/ger/makefile) | — | — |
| [base/boot/bootfont/ger/win2k_ver](../../base/boot/bootfont/ger/win2k_ver) | 1 | — | — | — |
| [base/boot/bootfont/hu](../../base/boot/bootfont/hu) | 3 | [base/boot/bootfont/hu/sources](../../base/boot/bootfont/hu/sources), [base/boot/bootfont/hu/makefile](../../base/boot/bootfont/hu/makefile) | — | — |
| [base/boot/bootfont/hu/win2k_ver](../../base/boot/bootfont/hu/win2k_ver) | 1 | — | — | — |
| [base/boot/bootfont/it](../../base/boot/bootfont/it) | 3 | [base/boot/bootfont/it/sources](../../base/boot/bootfont/it/sources), [base/boot/bootfont/it/makefile](../../base/boot/bootfont/it/makefile) | — | — |
| [base/boot/bootfont/it/win2k_ver](../../base/boot/bootfont/it/win2k_ver) | 1 | — | — | — |
| [base/boot/bootfont/jpn](../../base/boot/bootfont/jpn) | 4 | [base/boot/bootfont/jpn/sources](../../base/boot/bootfont/jpn/sources), [base/boot/bootfont/jpn/makefile](../../base/boot/bootfont/jpn/makefile) | — | — |
| [base/boot/bootfont/jpn/win2k_ver](../../base/boot/bootfont/jpn/win2k_ver) | 1 | — | — | — |
| [base/boot/bootfont/kor](../../base/boot/bootfont/kor) | 4 | [base/boot/bootfont/kor/sources](../../base/boot/bootfont/kor/sources), [base/boot/bootfont/kor/makefile](../../base/boot/bootfont/kor/makefile) | — | — |
| [base/boot/bootfont/kor/win2k_ver](../../base/boot/bootfont/kor/win2k_ver) | 1 | — | — | — |
| [base/boot/bootfont/nl](../../base/boot/bootfont/nl) | 3 | [base/boot/bootfont/nl/sources](../../base/boot/bootfont/nl/sources), [base/boot/bootfont/nl/makefile](../../base/boot/bootfont/nl/makefile) | — | — |
| [base/boot/bootfont/nl/win2k_ver](../../base/boot/bootfont/nl/win2k_ver) | 1 | — | — | — |
| [base/boot/bootfont/no](../../base/boot/bootfont/no) | 3 | [base/boot/bootfont/no/sources](../../base/boot/bootfont/no/sources), [base/boot/bootfont/no/makefile](../../base/boot/bootfont/no/makefile) | — | — |
| [base/boot/bootfont/no/win2k_ver](../../base/boot/bootfont/no/win2k_ver) | 1 | — | — | — |
| [base/boot/bootfont/pl](../../base/boot/bootfont/pl) | 3 | [base/boot/bootfont/pl/sources](../../base/boot/bootfont/pl/sources), [base/boot/bootfont/pl/makefile](../../base/boot/bootfont/pl/makefile) | — | — |
| [base/boot/bootfont/pl/win2k_ver](../../base/boot/bootfont/pl/win2k_ver) | 1 | — | — | — |
| [base/boot/bootfont/pt](../../base/boot/bootfont/pt) | 3 | [base/boot/bootfont/pt/sources](../../base/boot/bootfont/pt/sources), [base/boot/bootfont/pt/makefile](../../base/boot/bootfont/pt/makefile) | — | — |
| [base/boot/bootfont/pt/win2k_ver](../../base/boot/bootfont/pt/win2k_ver) | 1 | — | — | — |
| [base/boot/bootfont/ru](../../base/boot/bootfont/ru) | 3 | [base/boot/bootfont/ru/sources](../../base/boot/bootfont/ru/sources), [base/boot/bootfont/ru/makefile](../../base/boot/bootfont/ru/makefile) | — | — |
| [base/boot/bootfont/ru/win2k_ver](../../base/boot/bootfont/ru/win2k_ver) | 1 | — | — | — |
| [base/boot/bootfont/sv](../../base/boot/bootfont/sv) | 3 | [base/boot/bootfont/sv/sources](../../base/boot/bootfont/sv/sources), [base/boot/bootfont/sv/makefile](../../base/boot/bootfont/sv/makefile) | — | — |
| [base/boot/bootfont/sv/win2k_ver](../../base/boot/bootfont/sv/win2k_ver) | 1 | — | — | — |
| [base/boot/bootfont/tr](../../base/boot/bootfont/tr) | 3 | [base/boot/bootfont/tr/sources](../../base/boot/bootfont/tr/sources), [base/boot/bootfont/tr/makefile](../../base/boot/bootfont/tr/makefile) | — | — |
| [base/boot/bootfont/tr/win2k_ver](../../base/boot/bootfont/tr/win2k_ver) | 1 | — | — | — |
| [base/boot/bootssp](../../base/boot/bootssp) | 19 | [base/boot/bootssp/dirs](../../base/boot/bootssp/dirs) | — | — |
| [base/boot/bootssp/boot](../../base/boot/bootssp/boot) | 6 | [base/boot/bootssp/boot/sources](../../base/boot/bootssp/boot/sources), [base/boot/bootssp/boot/makefile](../../base/boot/bootssp/boot/makefile) | `bootssp` | `LIBRARY` |
| [base/boot/bootvid](../../base/boot/bootvid) | 9 | [base/boot/bootvid/dirs](../../base/boot/bootvid/dirs) | — | — |
| [base/boot/bootvid/daytona](../../base/boot/bootvid/daytona) | 2 | [base/boot/bootvid/daytona/sources](../../base/boot/bootvid/daytona/sources), [base/boot/bootvid/daytona/makefile](../../base/boot/bootvid/daytona/makefile) | — | — |
| [base/boot/detect](../../base/boot/detect) | 1 | [base/boot/detect/dirs](../../base/boot/detect/dirs) | — | — |
| [base/boot/detect/chk](../../base/boot/detect/chk) | 4 | [base/boot/detect/chk/sources](../../base/boot/detect/chk/sources), [base/boot/detect/chk/makefile](../../base/boot/detect/chk/makefile) | — | — |
| [base/boot/detect/fre](../../base/boot/detect/fre) | 4 | [base/boot/detect/fre/sources](../../base/boot/detect/fre/sources), [base/boot/detect/fre/makefile](../../base/boot/detect/fre/makefile) | — | — |
| [base/boot/detect/i386](../../base/boot/detect/i386) | 49 | — | — | — |
| [base/boot/detect/ia64](../../base/boot/detect/ia64) | 30 | — | — | — |
| [base/boot/efi](../../base/boot/efi) | 18 | [base/boot/efi/dirs](../../base/boot/efi/dirs) | — | — |
| [base/boot/efi/daytona](../../base/boot/efi/daytona) | 2 | [base/boot/efi/daytona/sources](../../base/boot/efi/daytona/sources), [base/boot/efi/daytona/makefile](../../base/boot/efi/daytona/makefile) | — | — |
| [base/boot/efi/daytona_dbg](../../base/boot/efi/daytona_dbg) | 2 | [base/boot/efi/daytona_dbg/sources](../../base/boot/efi/daytona_dbg/sources), [base/boot/efi/daytona_dbg/makefile](../../base/boot/efi/daytona_dbg/makefile) | — | — |
| [base/boot/efi/ia64](../../base/boot/efi/ia64) | 28 | [base/boot/efi/ia64/sources](../../base/boot/efi/ia64/sources) | — | — |
| [base/boot/efi/inc](../../base/boot/efi/inc) | 4 | — | — | — |
| [base/boot/inc](../../base/boot/inc) | 30 | — | — | — |
| [base/boot/kd1394](../../base/boot/kd1394) | 11 | [base/boot/kd1394/sources](../../base/boot/kd1394/sources), [base/boot/kd1394/makefile](../../base/boot/kd1394/makefile) | `kd1394` | `HAL` |
| [base/boot/kdcom](../../base/boot/kdcom) | 9 | [base/boot/kdcom/sources](../../base/boot/kdcom/sources), [base/boot/kdcom/makefile](../../base/boot/kdcom/makefile) | `kdcom` | `HAL` |
| [base/boot/lib](../../base/boot/lib) | 41 | [base/boot/lib/dirs](../../base/boot/lib/dirs) | — | — |
| [base/boot/lib/amd64](../../base/boot/lib/amd64) | 6 | — | — | — |
| [base/boot/lib/axp64](../../base/boot/lib/axp64) | 2 | [base/boot/lib/axp64/sources](../../base/boot/lib/axp64/sources) | — | — |
| [base/boot/lib/daytona](../../base/boot/lib/daytona) | 3 | [base/boot/lib/daytona/sources](../../base/boot/lib/daytona/sources), [base/boot/lib/daytona/makefile](../../base/boot/lib/daytona/makefile) | — | — |
| [base/boot/lib/daytona_dbg](../../base/boot/lib/daytona_dbg) | 3 | [base/boot/lib/daytona_dbg/sources](../../base/boot/lib/daytona_dbg/sources), [base/boot/lib/daytona_dbg/makefile](../../base/boot/lib/daytona_dbg/makefile) | — | — |
| [base/boot/lib/i386](../../base/boot/lib/i386) | 44 | [base/boot/lib/i386/sources](../../base/boot/lib/i386/sources) | — | — |
| [base/boot/lib/ia64](../../base/boot/lib/ia64) | 1 | [base/boot/lib/ia64/sources](../../base/boot/lib/ia64/sources) | — | — |
| [base/boot/lib/mips](../../base/boot/lib/mips) | 5 | [base/boot/lib/mips/sources](../../base/boot/lib/mips/sources) | — | — |
| [base/boot/oschoice](../../base/boot/oschoice) | 13 | [base/boot/oschoice/sources](../../base/boot/oschoice/sources), [base/boot/oschoice/makefile](../../base/boot/oschoice/makefile) | `oscldr` | `LIBRARY` |
| [base/boot/oschoice/i386](../../base/boot/oschoice/i386) | 1 | — | — | — |
| [base/boot/oschoice/ia64](../../base/boot/oschoice/ia64) | 1 | — | — | — |
| [base/boot/setup](../../base/boot/setup) | 33 | [base/boot/setup/dirs](../../base/boot/setup/dirs) | — | — |
| [base/boot/setup/axp64](../../base/boot/setup/axp64) | 1 | [base/boot/setup/axp64/sources](../../base/boot/setup/axp64/sources) | — | — |
| [base/boot/setup/br](../../base/boot/setup/br) | 3 | [base/boot/setup/br/sources](../../base/boot/setup/br/sources), [base/boot/setup/br/makefile](../../base/boot/setup/br/makefile) | — | — |
| [base/boot/setup/br/i386](../../base/boot/setup/br/i386) | 1 | [base/boot/setup/br/i386/sources](../../base/boot/setup/br/i386/sources) | — | — |
| [base/boot/setup/chs](../../base/boot/setup/chs) | 3 | [base/boot/setup/chs/sources](../../base/boot/setup/chs/sources), [base/boot/setup/chs/makefile](../../base/boot/setup/chs/makefile) | — | — |
| [base/boot/setup/chs/i386](../../base/boot/setup/chs/i386) | 1 | [base/boot/setup/chs/i386/sources](../../base/boot/setup/chs/i386/sources) | — | — |
| [base/boot/setup/cht](../../base/boot/setup/cht) | 3 | [base/boot/setup/cht/sources](../../base/boot/setup/cht/sources), [base/boot/setup/cht/makefile](../../base/boot/setup/cht/makefile) | — | — |
| [base/boot/setup/cht/i386](../../base/boot/setup/cht/i386) | 1 | [base/boot/setup/cht/i386/sources](../../base/boot/setup/cht/i386/sources) | — | — |
| [base/boot/setup/cs](../../base/boot/setup/cs) | 3 | [base/boot/setup/cs/sources](../../base/boot/setup/cs/sources), [base/boot/setup/cs/makefile](../../base/boot/setup/cs/makefile) | — | — |
| [base/boot/setup/cs/i386](../../base/boot/setup/cs/i386) | 1 | [base/boot/setup/cs/i386/sources](../../base/boot/setup/cs/i386/sources) | — | — |
| [base/boot/setup/da](../../base/boot/setup/da) | 3 | [base/boot/setup/da/sources](../../base/boot/setup/da/sources), [base/boot/setup/da/makefile](../../base/boot/setup/da/makefile) | — | — |
| [base/boot/setup/da/i386](../../base/boot/setup/da/i386) | 1 | [base/boot/setup/da/i386/sources](../../base/boot/setup/da/i386/sources) | — | — |
| [base/boot/setup/daytona](../../base/boot/setup/daytona) | 3 | [base/boot/setup/daytona/sources](../../base/boot/setup/daytona/sources), [base/boot/setup/daytona/makefile](../../base/boot/setup/daytona/makefile) | — | — |
| [base/boot/setup/daytona/i386](../../base/boot/setup/daytona/i386) | 1 | [base/boot/setup/daytona/i386/sources](../../base/boot/setup/daytona/i386/sources) | — | — |
| [base/boot/setup/daytona_dbg](../../base/boot/setup/daytona_dbg) | 3 | [base/boot/setup/daytona_dbg/sources](../../base/boot/setup/daytona_dbg/sources), [base/boot/setup/daytona_dbg/makefile](../../base/boot/setup/daytona_dbg/makefile) | — | — |
| [base/boot/setup/daytona_dbg/i386](../../base/boot/setup/daytona_dbg/i386) | 1 | [base/boot/setup/daytona_dbg/i386/sources](../../base/boot/setup/daytona_dbg/i386/sources) | — | — |
| [base/boot/setup/el](../../base/boot/setup/el) | 3 | [base/boot/setup/el/sources](../../base/boot/setup/el/sources), [base/boot/setup/el/makefile](../../base/boot/setup/el/makefile) | — | — |
| [base/boot/setup/el/i386](../../base/boot/setup/el/i386) | 1 | [base/boot/setup/el/i386/sources](../../base/boot/setup/el/i386/sources) | — | — |
| [base/boot/setup/es](../../base/boot/setup/es) | 3 | [base/boot/setup/es/sources](../../base/boot/setup/es/sources), [base/boot/setup/es/makefile](../../base/boot/setup/es/makefile) | — | — |
| [base/boot/setup/es/i386](../../base/boot/setup/es/i386) | 1 | [base/boot/setup/es/i386/sources](../../base/boot/setup/es/i386/sources) | — | — |
| [base/boot/setup/fi](../../base/boot/setup/fi) | 3 | [base/boot/setup/fi/sources](../../base/boot/setup/fi/sources), [base/boot/setup/fi/makefile](../../base/boot/setup/fi/makefile) | — | — |
| [base/boot/setup/fi/i386](../../base/boot/setup/fi/i386) | 1 | [base/boot/setup/fi/i386/sources](../../base/boot/setup/fi/i386/sources) | — | — |
| [base/boot/setup/fr](../../base/boot/setup/fr) | 3 | [base/boot/setup/fr/sources](../../base/boot/setup/fr/sources), [base/boot/setup/fr/makefile](../../base/boot/setup/fr/makefile) | — | — |
| [base/boot/setup/fr/i386](../../base/boot/setup/fr/i386) | 1 | [base/boot/setup/fr/i386/sources](../../base/boot/setup/fr/i386/sources) | — | — |
| [base/boot/setup/ger](../../base/boot/setup/ger) | 3 | [base/boot/setup/ger/sources](../../base/boot/setup/ger/sources), [base/boot/setup/ger/makefile](../../base/boot/setup/ger/makefile) | — | — |
| [base/boot/setup/ger/i386](../../base/boot/setup/ger/i386) | 1 | [base/boot/setup/ger/i386/sources](../../base/boot/setup/ger/i386/sources) | — | — |
| [base/boot/setup/hu](../../base/boot/setup/hu) | 3 | [base/boot/setup/hu/sources](../../base/boot/setup/hu/sources), [base/boot/setup/hu/makefile](../../base/boot/setup/hu/makefile) | — | — |
| [base/boot/setup/hu/i386](../../base/boot/setup/hu/i386) | 1 | [base/boot/setup/hu/i386/sources](../../base/boot/setup/hu/i386/sources) | — | — |
| [base/boot/setup/i386](../../base/boot/setup/i386) | 3 | [base/boot/setup/i386/sources](../../base/boot/setup/i386/sources) | — | — |
| [base/boot/setup/ia64](../../base/boot/setup/ia64) | 5 | [base/boot/setup/ia64/sources](../../base/boot/setup/ia64/sources) | — | — |
| [base/boot/setup/it](../../base/boot/setup/it) | 3 | [base/boot/setup/it/sources](../../base/boot/setup/it/sources), [base/boot/setup/it/makefile](../../base/boot/setup/it/makefile) | — | — |
| [base/boot/setup/it/i386](../../base/boot/setup/it/i386) | 1 | [base/boot/setup/it/i386/sources](../../base/boot/setup/it/i386/sources) | — | — |
| [base/boot/setup/jpn](../../base/boot/setup/jpn) | 3 | [base/boot/setup/jpn/sources](../../base/boot/setup/jpn/sources), [base/boot/setup/jpn/makefile](../../base/boot/setup/jpn/makefile) | — | — |
| [base/boot/setup/jpn/i386](../../base/boot/setup/jpn/i386) | 1 | [base/boot/setup/jpn/i386/sources](../../base/boot/setup/jpn/i386/sources) | — | — |
| [base/boot/setup/kor](../../base/boot/setup/kor) | 3 | [base/boot/setup/kor/sources](../../base/boot/setup/kor/sources), [base/boot/setup/kor/makefile](../../base/boot/setup/kor/makefile) | — | — |
| [base/boot/setup/kor/i386](../../base/boot/setup/kor/i386) | 1 | [base/boot/setup/kor/i386/sources](../../base/boot/setup/kor/i386/sources) | — | — |
| [base/boot/setup/mips](../../base/boot/setup/mips) | 1 | [base/boot/setup/mips/sources](../../base/boot/setup/mips/sources) | — | — |
| [base/boot/setup/nl](../../base/boot/setup/nl) | 3 | [base/boot/setup/nl/sources](../../base/boot/setup/nl/sources), [base/boot/setup/nl/makefile](../../base/boot/setup/nl/makefile) | — | — |
| [base/boot/setup/nl/i386](../../base/boot/setup/nl/i386) | 1 | [base/boot/setup/nl/i386/sources](../../base/boot/setup/nl/i386/sources) | — | — |
| [base/boot/setup/no](../../base/boot/setup/no) | 3 | [base/boot/setup/no/sources](../../base/boot/setup/no/sources), [base/boot/setup/no/makefile](../../base/boot/setup/no/makefile) | — | — |
| [base/boot/setup/no/i386](../../base/boot/setup/no/i386) | 1 | [base/boot/setup/no/i386/sources](../../base/boot/setup/no/i386/sources) | — | — |
| [base/boot/setup/pl](../../base/boot/setup/pl) | 3 | [base/boot/setup/pl/sources](../../base/boot/setup/pl/sources), [base/boot/setup/pl/makefile](../../base/boot/setup/pl/makefile) | — | — |
| [base/boot/setup/pl/i386](../../base/boot/setup/pl/i386) | 1 | [base/boot/setup/pl/i386/sources](../../base/boot/setup/pl/i386/sources) | — | — |
| [base/boot/setup/psu](../../base/boot/setup/psu) | 3 | [base/boot/setup/psu/sources](../../base/boot/setup/psu/sources), [base/boot/setup/psu/makefile](../../base/boot/setup/psu/makefile) | — | — |
| [base/boot/setup/psu/i386](../../base/boot/setup/psu/i386) | 1 | [base/boot/setup/psu/i386/sources](../../base/boot/setup/psu/i386/sources) | — | — |
| [base/boot/setup/pt](../../base/boot/setup/pt) | 3 | [base/boot/setup/pt/sources](../../base/boot/setup/pt/sources), [base/boot/setup/pt/makefile](../../base/boot/setup/pt/makefile) | — | — |
| [base/boot/setup/pt/i386](../../base/boot/setup/pt/i386) | 1 | [base/boot/setup/pt/i386/sources](../../base/boot/setup/pt/i386/sources) | — | — |
| [base/boot/setup/ru](../../base/boot/setup/ru) | 3 | [base/boot/setup/ru/sources](../../base/boot/setup/ru/sources), [base/boot/setup/ru/makefile](../../base/boot/setup/ru/makefile) | — | — |
| [base/boot/setup/ru/i386](../../base/boot/setup/ru/i386) | 1 | [base/boot/setup/ru/i386/sources](../../base/boot/setup/ru/i386/sources) | — | — |
| [base/boot/setup/sv](../../base/boot/setup/sv) | 3 | [base/boot/setup/sv/sources](../../base/boot/setup/sv/sources), [base/boot/setup/sv/makefile](../../base/boot/setup/sv/makefile) | — | — |
| [base/boot/setup/sv/i386](../../base/boot/setup/sv/i386) | 1 | [base/boot/setup/sv/i386/sources](../../base/boot/setup/sv/i386/sources) | — | — |
| [base/boot/setup/tr](../../base/boot/setup/tr) | 3 | [base/boot/setup/tr/sources](../../base/boot/setup/tr/sources), [base/boot/setup/tr/makefile](../../base/boot/setup/tr/makefile) | — | — |
| [base/boot/setup/tr/i386](../../base/boot/setup/tr/i386) | 1 | [base/boot/setup/tr/i386/sources](../../base/boot/setup/tr/i386/sources) | — | — |
| [base/boot/setup/tst](../../base/boot/setup/tst) | 3 | [base/boot/setup/tst/sources](../../base/boot/setup/tst/sources), [base/boot/setup/tst/makefile](../../base/boot/setup/tst/makefile) | — | — |
| [base/boot/setup/tst/i386](../../base/boot/setup/tst/i386) | 1 | [base/boot/setup/tst/i386/sources](../../base/boot/setup/tst/i386/sources) | — | — |
| [base/boot/startrom](../../base/boot/startrom) | 3 | [base/boot/startrom/dirs](../../base/boot/startrom/dirs) | — | — |
| [base/boot/startrom/daytona](../../base/boot/startrom/daytona) | 3 | [base/boot/startrom/daytona/sources](../../base/boot/startrom/daytona/sources), [base/boot/startrom/daytona/makefile](../../base/boot/startrom/daytona/makefile) | — | — |
| [base/boot/startrom/daytona.n12](../../base/boot/startrom/daytona.n12) | 3 | [base/boot/startrom/daytona.n12/sources](../../base/boot/startrom/daytona.n12/sources), [base/boot/startrom/daytona.n12/makefile](../../base/boot/startrom/daytona.n12/makefile) | — | — |
| [base/boot/startrom/hdlscom1](../../base/boot/startrom/hdlscom1) | 3 | [base/boot/startrom/hdlscom1/sources](../../base/boot/startrom/hdlscom1/sources), [base/boot/startrom/hdlscom1/makefile](../../base/boot/startrom/hdlscom1/makefile) | — | — |
| [base/boot/startrom/hdlscom1.n12](../../base/boot/startrom/hdlscom1.n12) | 3 | [base/boot/startrom/hdlscom1.n12/sources](../../base/boot/startrom/hdlscom1.n12/sources), [base/boot/startrom/hdlscom1.n12/makefile](../../base/boot/startrom/hdlscom1.n12/makefile) | — | — |
| [base/boot/startrom/hdlscom2](../../base/boot/startrom/hdlscom2) | 3 | [base/boot/startrom/hdlscom2/sources](../../base/boot/startrom/hdlscom2/sources), [base/boot/startrom/hdlscom2/makefile](../../base/boot/startrom/hdlscom2/makefile) | — | — |
| [base/boot/startrom/hdlscom2.n12](../../base/boot/startrom/hdlscom2.n12) | 3 | [base/boot/startrom/hdlscom2.n12/sources](../../base/boot/startrom/hdlscom2.n12/sources), [base/boot/startrom/hdlscom2.n12/makefile](../../base/boot/startrom/hdlscom2.n12/makefile) | — | — |
| [base/boot/startrom/hdlstst1.n12](../../base/boot/startrom/hdlstst1.n12) | 3 | [base/boot/startrom/hdlstst1.n12/sources](../../base/boot/startrom/hdlstst1.n12/sources), [base/boot/startrom/hdlstst1.n12/makefile](../../base/boot/startrom/hdlstst1.n12/makefile) | — | — |
| [base/boot/startrom/hdlstst2.n12](../../base/boot/startrom/hdlstst2.n12) | 3 | [base/boot/startrom/hdlstst2.n12/sources](../../base/boot/startrom/hdlstst2.n12/sources), [base/boot/startrom/hdlstst2.n12/makefile](../../base/boot/startrom/hdlstst2.n12/makefile) | — | — |
| [base/boot/startrom/i386](../../base/boot/startrom/i386) | 24 | — | — | — |
| [base/boot/startrom/i386/usa](../../base/boot/startrom/i386/usa) | 1 | — | — | — |
| [base/boot/startup](../../base/boot/startup) | 4 | [base/boot/startup/dirs](../../base/boot/startup/dirs) | — | — |
| [base/boot/startup/br](../../base/boot/startup/br) | 3 | [base/boot/startup/br/sources](../../base/boot/startup/br/sources), [base/boot/startup/br/makefile](../../base/boot/startup/br/makefile) | — | — |
| [base/boot/startup/cs](../../base/boot/startup/cs) | 3 | [base/boot/startup/cs/sources](../../base/boot/startup/cs/sources), [base/boot/startup/cs/makefile](../../base/boot/startup/cs/makefile) | — | — |
| [base/boot/startup/da](../../base/boot/startup/da) | 3 | [base/boot/startup/da/sources](../../base/boot/startup/da/sources), [base/boot/startup/da/makefile](../../base/boot/startup/da/makefile) | — | — |
| [base/boot/startup/daytona](../../base/boot/startup/daytona) | 3 | [base/boot/startup/daytona/sources](../../base/boot/startup/daytona/sources), [base/boot/startup/daytona/makefile](../../base/boot/startup/daytona/makefile) | — | — |
| [base/boot/startup/el](../../base/boot/startup/el) | 3 | [base/boot/startup/el/sources](../../base/boot/startup/el/sources), [base/boot/startup/el/makefile](../../base/boot/startup/el/makefile) | — | — |
| [base/boot/startup/es](../../base/boot/startup/es) | 3 | [base/boot/startup/es/sources](../../base/boot/startup/es/sources), [base/boot/startup/es/makefile](../../base/boot/startup/es/makefile) | — | — |
| [base/boot/startup/fi](../../base/boot/startup/fi) | 3 | [base/boot/startup/fi/sources](../../base/boot/startup/fi/sources), [base/boot/startup/fi/makefile](../../base/boot/startup/fi/makefile) | — | — |
| [base/boot/startup/fr](../../base/boot/startup/fr) | 3 | [base/boot/startup/fr/sources](../../base/boot/startup/fr/sources), [base/boot/startup/fr/makefile](../../base/boot/startup/fr/makefile) | — | — |
| [base/boot/startup/ger](../../base/boot/startup/ger) | 3 | [base/boot/startup/ger/sources](../../base/boot/startup/ger/sources), [base/boot/startup/ger/makefile](../../base/boot/startup/ger/makefile) | — | — |
| [base/boot/startup/hu](../../base/boot/startup/hu) | 3 | [base/boot/startup/hu/sources](../../base/boot/startup/hu/sources), [base/boot/startup/hu/makefile](../../base/boot/startup/hu/makefile) | — | — |
| [base/boot/startup/i386](../../base/boot/startup/i386) | 22 | — | — | — |
| [base/boot/startup/i386/br](../../base/boot/startup/i386/br) | 1 | — | — | — |
| [base/boot/startup/i386/cs](../../base/boot/startup/i386/cs) | 1 | — | — | — |
| [base/boot/startup/i386/da](../../base/boot/startup/i386/da) | 1 | — | — | — |
| [base/boot/startup/i386/el](../../base/boot/startup/i386/el) | 1 | — | — | — |
| [base/boot/startup/i386/es](../../base/boot/startup/i386/es) | 1 | — | — | — |
| [base/boot/startup/i386/fi](../../base/boot/startup/i386/fi) | 1 | — | — | — |
| [base/boot/startup/i386/fr](../../base/boot/startup/i386/fr) | 1 | — | — | — |
| [base/boot/startup/i386/ger](../../base/boot/startup/i386/ger) | 1 | — | — | — |
| [base/boot/startup/i386/hu](../../base/boot/startup/i386/hu) | 1 | — | — | — |
| [base/boot/startup/i386/it](../../base/boot/startup/i386/it) | 1 | — | — | — |
| [base/boot/startup/i386/nl](../../base/boot/startup/i386/nl) | 1 | — | — | — |
| [base/boot/startup/i386/no](../../base/boot/startup/i386/no) | 1 | — | — | — |
| [base/boot/startup/i386/pl](../../base/boot/startup/i386/pl) | 1 | — | — | — |
| [base/boot/startup/i386/pt](../../base/boot/startup/i386/pt) | 1 | — | — | — |
| [base/boot/startup/i386/ru](../../base/boot/startup/i386/ru) | 1 | — | — | — |
| [base/boot/startup/i386/sv](../../base/boot/startup/i386/sv) | 1 | — | — | — |
| [base/boot/startup/i386/tr](../../base/boot/startup/i386/tr) | 1 | — | — | — |
| [base/boot/startup/i386/usa](../../base/boot/startup/i386/usa) | 1 | — | — | — |
| [base/boot/startup/it](../../base/boot/startup/it) | 3 | [base/boot/startup/it/sources](../../base/boot/startup/it/sources), [base/boot/startup/it/makefile](../../base/boot/startup/it/makefile) | — | — |
| [base/boot/startup/nl](../../base/boot/startup/nl) | 3 | [base/boot/startup/nl/sources](../../base/boot/startup/nl/sources), [base/boot/startup/nl/makefile](../../base/boot/startup/nl/makefile) | — | — |
| [base/boot/startup/no](../../base/boot/startup/no) | 3 | [base/boot/startup/no/sources](../../base/boot/startup/no/sources), [base/boot/startup/no/makefile](../../base/boot/startup/no/makefile) | — | — |
| [base/boot/startup/pl](../../base/boot/startup/pl) | 3 | [base/boot/startup/pl/sources](../../base/boot/startup/pl/sources), [base/boot/startup/pl/makefile](../../base/boot/startup/pl/makefile) | — | — |
| [base/boot/startup/psu](../../base/boot/startup/psu) | 3 | [base/boot/startup/psu/sources](../../base/boot/startup/psu/sources), [base/boot/startup/psu/makefile](../../base/boot/startup/psu/makefile) | — | — |
| [base/boot/startup/pt](../../base/boot/startup/pt) | 3 | [base/boot/startup/pt/sources](../../base/boot/startup/pt/sources), [base/boot/startup/pt/makefile](../../base/boot/startup/pt/makefile) | — | — |
| [base/boot/startup/ru](../../base/boot/startup/ru) | 3 | [base/boot/startup/ru/sources](../../base/boot/startup/ru/sources), [base/boot/startup/ru/makefile](../../base/boot/startup/ru/makefile) | — | — |
| [base/boot/startup/sv](../../base/boot/startup/sv) | 3 | [base/boot/startup/sv/sources](../../base/boot/startup/sv/sources), [base/boot/startup/sv/makefile](../../base/boot/startup/sv/makefile) | — | — |
| [base/boot/startup/tr](../../base/boot/startup/tr) | 3 | [base/boot/startup/tr/sources](../../base/boot/startup/tr/sources), [base/boot/startup/tr/makefile](../../base/boot/startup/tr/makefile) | — | — |
| [base/boot/startup/tst](../../base/boot/startup/tst) | 3 | [base/boot/startup/tst/sources](../../base/boot/startup/tst/sources), [base/boot/startup/tst/makefile](../../base/boot/startup/tst/makefile) | — | — |
| [base/boot/tftplib](../../base/boot/tftplib) | 7 | [base/boot/tftplib/sources](../../base/boot/tftplib/sources), [base/boot/tftplib/makefile](../../base/boot/tftplib/makefile) | `tftplib` | `LIBRARY` |
| [base/boot/tftplib/alpha](../../base/boot/tftplib/alpha) | 1 | — | — | — |
| [base/boot/tftplib/i386](../../base/boot/tftplib/i386) | 2 | — | — | — |
| [base/boot/tftplib/ia64](../../base/boot/tftplib/ia64) | 2 | [base/boot/tftplib/ia64/sources](../../base/boot/tftplib/ia64/sources) | — | — |

## `base/busdrv/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [base/busdrv](../../base/busdrv) | 1 | [base/busdrv/dirs](../../base/busdrv/dirs) | — | — |
| [base/busdrv/acpi](../../base/busdrv/acpi) | 2 | [base/busdrv/acpi/dirs](../../base/busdrv/acpi/dirs), [base/busdrv/acpi/makefile](../../base/busdrv/acpi/makefile) | — | — |
| [base/busdrv/acpi/acpienab](../../base/busdrv/acpi/acpienab) | 11 | [base/busdrv/acpi/acpienab/sources](../../base/busdrv/acpi/acpienab/sources), [base/busdrv/acpi/acpienab/makefile](../../base/busdrv/acpi/acpienab/makefile) | `acpienab` | `PROGRAM` |
| [base/busdrv/acpi/acpitab](../../base/busdrv/acpi/acpitab) | 8 | [base/busdrv/acpi/acpitab/makefile](../../base/busdrv/acpi/acpitab/makefile) | — | — |
| [base/busdrv/acpi/acpiver_stub](../../base/busdrv/acpi/acpiver_stub) | 4 | [base/busdrv/acpi/acpiver_stub/sources](../../base/busdrv/acpi/acpiver_stub/sources), [base/busdrv/acpi/acpiver_stub/makefile](../../base/busdrv/acpi/acpiver_stub/makefile) | `acpiver` | `DRIVER` |
| [base/busdrv/acpi/asl](../../base/busdrv/acpi/asl) | 43 | [base/busdrv/acpi/asl/sources](../../base/busdrv/acpi/asl/sources), [base/busdrv/acpi/asl/makefile](../../base/busdrv/acpi/asl/makefile) | `asl` | `PROGRAM` |
| [base/busdrv/acpi/asl/new](../../base/busdrv/acpi/asl/new) | 13 | [base/busdrv/acpi/asl/new/sources](../../base/busdrv/acpi/asl/new/sources) | `asl` | `PROGRAM` |
| [base/busdrv/acpi/battc](../../base/busdrv/acpi/battc) | 11 | [base/busdrv/acpi/battc/sources](../../base/busdrv/acpi/battc/sources), [base/busdrv/acpi/battc/makefile](../../base/busdrv/acpi/battc/makefile) | `battc` | `EXPORT_DRIVER` |
| [base/busdrv/acpi/battc/app](../../base/busdrv/acpi/battc/app) | 4 | [base/busdrv/acpi/battc/app/sources](../../base/busdrv/acpi/battc/app/sources), [base/busdrv/acpi/battc/app/makefile](../../base/busdrv/acpi/battc/app/makefile) | `compbatt` | `LIBRARY` |
| [base/busdrv/acpi/cmbatt](../../base/busdrv/acpi/cmbatt) | 13 | [base/busdrv/acpi/cmbatt/sources](../../base/busdrv/acpi/cmbatt/sources), [base/busdrv/acpi/cmbatt/makefile](../../base/busdrv/acpi/cmbatt/makefile) | `cmbatt` | `DRIVER` |
| [base/busdrv/acpi/cmbatt/cmbtest](../../base/busdrv/acpi/cmbatt/cmbtest) | 4 | [base/busdrv/acpi/cmbatt/cmbtest/sources](../../base/busdrv/acpi/cmbatt/cmbtest/sources), [base/busdrv/acpi/cmbatt/cmbtest/makefile](../../base/busdrv/acpi/cmbatt/cmbtest/makefile) | `cmbtest` | `PROGRAM` |
| [base/busdrv/acpi/cmbatt/testapp](../../base/busdrv/acpi/cmbatt/testapp) | 4 | [base/busdrv/acpi/cmbatt/testapp/sources](../../base/busdrv/acpi/cmbatt/testapp/sources), [base/busdrv/acpi/cmbatt/testapp/makefile](../../base/busdrv/acpi/cmbatt/testapp/makefile) | `cmbattst` | `PROGRAM` |
| [base/busdrv/acpi/compbatt](../../base/busdrv/acpi/compbatt) | 9 | [base/busdrv/acpi/compbatt/sources](../../base/busdrv/acpi/compbatt/sources), [base/busdrv/acpi/compbatt/makefile](../../base/busdrv/acpi/compbatt/makefile) | `compbatt` | `DRIVER` |
| [base/busdrv/acpi/doc](../../base/busdrv/acpi/doc) | 6 | — | — | — |
| [base/busdrv/acpi/driver](../../base/busdrv/acpi/driver) | 2 | [base/busdrv/acpi/driver/dirs](../../base/busdrv/acpi/driver/dirs) | — | — |
| [base/busdrv/acpi/driver/acpisym](../../base/busdrv/acpi/driver/acpisym) | 4 | [base/busdrv/acpi/driver/acpisym/sources](../../base/busdrv/acpi/driver/acpisym/sources), [base/busdrv/acpi/driver/acpisym/makefile](../../base/busdrv/acpi/driver/acpisym/makefile) | — | `NOTARGET` |
| [base/busdrv/acpi/driver/amlinew](../../base/busdrv/acpi/driver/amlinew) | 41 | [base/busdrv/acpi/driver/amlinew/sources](../../base/busdrv/acpi/driver/amlinew/sources), [base/busdrv/acpi/driver/amlinew/makefile](../../base/busdrv/acpi/driver/amlinew/makefile) | `amli` | `LIBRARY` |
| [base/busdrv/acpi/driver/inc](../../base/busdrv/acpi/driver/inc) | 12 | — | — | — |
| [base/busdrv/acpi/driver/nt](../../base/busdrv/acpi/driver/nt) | 92 | [base/busdrv/acpi/driver/nt/sources](../../base/busdrv/acpi/driver/nt/sources), [base/busdrv/acpi/driver/nt/makefile](../../base/busdrv/acpi/driver/nt/makefile) | `acpi` | `DRIVER` |
| [base/busdrv/acpi/driver/shared](../../base/busdrv/acpi/driver/shared) | 28 | [base/busdrv/acpi/driver/shared/sources](../../base/busdrv/acpi/driver/shared/sources), [base/busdrv/acpi/driver/shared/makefile](../../base/busdrv/acpi/driver/shared/makefile) | `acpi` | `LIBRARY` |
| [base/busdrv/acpi/ec](../../base/busdrv/acpi/ec) | 15 | [base/busdrv/acpi/ec/sources](../../base/busdrv/acpi/ec/sources), [base/busdrv/acpi/ec/makefile](../../base/busdrv/acpi/ec/makefile) | `acpiec` | `DRIVER` |
| [base/busdrv/acpi/ec/app](../../base/busdrv/acpi/ec/app) | 4 | [base/busdrv/acpi/ec/app/sources](../../base/busdrv/acpi/ec/app/sources), [base/busdrv/acpi/ec/app/makefile](../../base/busdrv/acpi/ec/app/makefile) | `ec` | `LIBRARY` |
| [base/busdrv/acpi/hidbatt](../../base/busdrv/acpi/hidbatt) | 18 | [base/busdrv/acpi/hidbatt/sources](../../base/busdrv/acpi/hidbatt/sources), [base/busdrv/acpi/hidbatt/makefile](../../base/busdrv/acpi/hidbatt/makefile) | `hidbatt` | `DRIVER` |
| [base/busdrv/acpi/inc](../../base/busdrv/acpi/inc) | 5 | — | — | — |
| [base/busdrv/acpi/oprghdlr](../../base/busdrv/acpi/oprghdlr) | 5 | [base/busdrv/acpi/oprghdlr/sources](../../base/busdrv/acpi/oprghdlr/sources), [base/busdrv/acpi/oprghdlr/makefile](../../base/busdrv/acpi/oprghdlr/makefile) | `oprghdlr` | `EXPORT_DRIVER` |
| [base/busdrv/acpi/sld](../../base/busdrv/acpi/sld) | 11 | [base/busdrv/acpi/sld/sources](../../base/busdrv/acpi/sld/sources), [base/busdrv/acpi/sld/makefile](../../base/busdrv/acpi/sld/makefile) | `acpi` | `NOTARGET` |
| [base/busdrv/acpi/smbus](../../base/busdrv/acpi/smbus) | 2 | [base/busdrv/acpi/smbus/dirs](../../base/busdrv/acpi/smbus/dirs), [base/busdrv/acpi/smbus/makefile](../../base/busdrv/acpi/smbus/makefile) | — | — |
| [base/busdrv/acpi/smbus/smbali](../../base/busdrv/acpi/smbus/smbali) | 7 | [base/busdrv/acpi/smbus/smbali/sources](../../base/busdrv/acpi/smbus/smbali/sources), [base/busdrv/acpi/smbus/smbali/makefile](../../base/busdrv/acpi/smbus/smbali/makefile) | `smbali` | `DRIVER` |
| [base/busdrv/acpi/smbus/smbbatt](../../base/busdrv/acpi/smbus/smbbatt) | 9 | [base/busdrv/acpi/smbus/smbbatt/sources](../../base/busdrv/acpi/smbus/smbbatt/sources), [base/busdrv/acpi/smbus/smbbatt/makefile](../../base/busdrv/acpi/smbus/smbbatt/makefile) | `smbbatt` | `DRIVER` |
| [base/busdrv/acpi/smbus/smbclass](../../base/busdrv/acpi/smbus/smbclass) | 10 | [base/busdrv/acpi/smbus/smbclass/sources](../../base/busdrv/acpi/smbus/smbclass/sources), [base/busdrv/acpi/smbus/smbclass/makefile](../../base/busdrv/acpi/smbus/smbclass/makefile) | `smbclass` | `EXPORT_DRIVER` |
| [base/busdrv/acpi/smbus/smbhc](../../base/busdrv/acpi/smbus/smbhc) | 8 | [base/busdrv/acpi/smbus/smbhc/sources](../../base/busdrv/acpi/smbus/smbhc/sources), [base/busdrv/acpi/smbus/smbhc/makefile](../../base/busdrv/acpi/smbus/smbhc/makefile) | `smbhc` | `DRIVER` |
| [base/busdrv/acpi/tools](../../base/busdrv/acpi/tools) | 1 | [base/busdrv/acpi/tools/dirs](../../base/busdrv/acpi/tools/dirs) | — | — |
| [base/busdrv/acpi/tools/a5parse](../../base/busdrv/acpi/tools/a5parse) | 4 | [base/busdrv/acpi/tools/a5parse/sources](../../base/busdrv/acpi/tools/a5parse/sources), [base/busdrv/acpi/tools/a5parse/makefile](../../base/busdrv/acpi/tools/a5parse/makefile) | `a5parse` | `DRIVER` |
| [base/busdrv/acpi/tools/acpiload](../../base/busdrv/acpi/tools/acpiload) | 5 | [base/busdrv/acpi/tools/acpiload/sources](../../base/busdrv/acpi/tools/acpiload/sources), [base/busdrv/acpi/tools/acpiload/makefile](../../base/busdrv/acpi/tools/acpiload/makefile) | `acpiload` | `LIBRARY` |
| [base/busdrv/acpi/tools/acpisim](../../base/busdrv/acpi/tools/acpisim) | 2 | [base/busdrv/acpi/tools/acpisim/dirs](../../base/busdrv/acpi/tools/acpisim/dirs) | — | — |
| [base/busdrv/acpi/tools/acpisim/asl](../../base/busdrv/acpi/tools/acpisim/asl) | 1 | — | — | — |
| [base/busdrv/acpi/tools/acpisim/driver](../../base/busdrv/acpi/tools/acpisim/driver) | 6 | [base/busdrv/acpi/tools/acpisim/driver/sources](../../base/busdrv/acpi/tools/acpisim/driver/sources), [base/busdrv/acpi/tools/acpisim/driver/makefile](../../base/busdrv/acpi/tools/acpisim/driver/makefile) | `acpisim` | `DRIVER` |
| [base/busdrv/acpi/tools/acpisim/inc](../../base/busdrv/acpi/tools/acpisim/inc) | 1 | — | — | — |
| [base/busdrv/acpi/tools/acpisim/inf](../../base/busdrv/acpi/tools/acpisim/inf) | 1 | — | — | — |
| [base/busdrv/acpi/tools/acpisim/lib](../../base/busdrv/acpi/tools/acpisim/lib) | 8 | [base/busdrv/acpi/tools/acpisim/lib/sources](../../base/busdrv/acpi/tools/acpisim/lib/sources), [base/busdrv/acpi/tools/acpisim/lib/makefile](../../base/busdrv/acpi/tools/acpisim/lib/makefile) | `acpisim` | `DRIVER_LIBRARY` |
| [base/busdrv/acpi/tools/acpisim/simulation](../../base/busdrv/acpi/tools/acpisim/simulation) | 1 | — | — | — |
| [base/busdrv/acpi/tools/acpisim/simulation/app](../../base/busdrv/acpi/tools/acpisim/simulation/app) | 1 | — | — | — |
| [base/busdrv/acpi/tools/acpisim/simulation/app/asapp1](../../base/busdrv/acpi/tools/acpisim/simulation/app/asapp1) | 3 | [base/busdrv/acpi/tools/acpisim/simulation/app/asapp1/sources](../../base/busdrv/acpi/tools/acpisim/simulation/app/asapp1/sources), [base/busdrv/acpi/tools/acpisim/simulation/app/asapp1/makefile](../../base/busdrv/acpi/tools/acpisim/simulation/app/asapp1/makefile) | `ASAPP1` | `PROGRAM` |
| [base/busdrv/acpi/tools/acpisim/simulation/app/asldtb](../../base/busdrv/acpi/tools/acpisim/simulation/app/asldtb) | 3 | [base/busdrv/acpi/tools/acpisim/simulation/app/asldtb/sources](../../base/busdrv/acpi/tools/acpisim/simulation/app/asldtb/sources), [base/busdrv/acpi/tools/acpisim/simulation/app/asldtb/makefile](../../base/busdrv/acpi/tools/acpisim/simulation/app/asldtb/makefile) | `ASLDTB` | `PROGRAM` |
| [base/busdrv/acpi/tools/acpisim/simulation/app/asntfy](../../base/busdrv/acpi/tools/acpisim/simulation/app/asntfy) | 3 | [base/busdrv/acpi/tools/acpisim/simulation/app/asntfy/sources](../../base/busdrv/acpi/tools/acpisim/simulation/app/asntfy/sources), [base/busdrv/acpi/tools/acpisim/simulation/app/asntfy/makefile](../../base/busdrv/acpi/tools/acpisim/simulation/app/asntfy/makefile) | `ASNTFY` | `PROGRAM` |
| [base/busdrv/acpi/tools/acpisim/simulation/app/asunld](../../base/busdrv/acpi/tools/acpisim/simulation/app/asunld) | 3 | [base/busdrv/acpi/tools/acpisim/simulation/app/asunld/sources](../../base/busdrv/acpi/tools/acpisim/simulation/app/asunld/sources), [base/busdrv/acpi/tools/acpisim/simulation/app/asunld/makefile](../../base/busdrv/acpi/tools/acpisim/simulation/app/asunld/makefile) | `ASUNLD` | `PROGRAM` |
| [base/busdrv/acpi/tools/acpisim/simulation/asl](../../base/busdrv/acpi/tools/acpisim/simulation/asl) | 0 | — | — | — |
| [base/busdrv/acpi/tools/acpisim/simulation/asl/acpi20voltagestates](../../base/busdrv/acpi/tools/acpisim/simulation/asl/acpi20voltagestates) | 1 | — | — | — |
| [base/busdrv/acpi/tools/acpisim/simulation/asl/basetable](../../base/busdrv/acpi/tools/acpisim/simulation/asl/basetable) | 1 | — | — | — |
| [base/busdrv/acpi/tools/acpisim/simulation/asl/battery](../../base/busdrv/acpi/tools/acpisim/simulation/asl/battery) | 1 | — | — | — |
| [base/busdrv/acpi/tools/acpisim/simulation/asl/tableloader](../../base/busdrv/acpi/tools/acpisim/simulation/asl/tableloader) | 1 | — | — | — |
| [base/busdrv/acpi/tools/acpisim/simulation/driver](../../base/busdrv/acpi/tools/acpisim/simulation/driver) | 8 | [base/busdrv/acpi/tools/acpisim/simulation/driver/sources](../../base/busdrv/acpi/tools/acpisim/simulation/driver/sources), [base/busdrv/acpi/tools/acpisim/simulation/driver/makefile](../../base/busdrv/acpi/tools/acpisim/simulation/driver/makefile) | `acpisim` | `DRIVER` |
| [base/busdrv/acpi/tools/acpisim/simulation/inc](../../base/busdrv/acpi/tools/acpisim/simulation/inc) | 1 | — | — | — |
| [base/busdrv/acpi/tools/acpisim/simulation/inf](../../base/busdrv/acpi/tools/acpisim/simulation/inf) | 1 | — | — | — |
| [base/busdrv/acpi/tools/acpiuasm](../../base/busdrv/acpi/tools/acpiuasm) | 5 | [base/busdrv/acpi/tools/acpiuasm/sources](../../base/busdrv/acpi/tools/acpiuasm/sources), [base/busdrv/acpi/tools/acpiuasm/makefile](../../base/busdrv/acpi/tools/acpiuasm/makefile) | `acpiuasm` | `PROGRAM` |
| [base/busdrv/acpi/tools/acpiwake](../../base/busdrv/acpi/tools/acpiwake) | 5 | [base/busdrv/acpi/tools/acpiwake/sources](../../base/busdrv/acpi/tools/acpiwake/sources), [base/busdrv/acpi/tools/acpiwake/makefile](../../base/busdrv/acpi/tools/acpiwake/makefile) | `acpiwake` | `PROGRAM` |
| [base/busdrv/acpi/tools/inc](../../base/busdrv/acpi/tools/inc) | 2 | — | — | — |
| [base/busdrv/acpi/tools/kdext](../../base/busdrv/acpi/tools/kdext) | 38 | [base/busdrv/acpi/tools/kdext/sources](../../base/busdrv/acpi/tools/kdext/sources), [base/busdrv/acpi/tools/kdext/makefile](../../base/busdrv/acpi/tools/kdext/makefile) | `acpikd` | `DYNLINK` |
| [base/busdrv/acpi/tools/ntsdext](../../base/busdrv/acpi/tools/ntsdext) | 6 | [base/busdrv/acpi/tools/ntsdext/sources](../../base/busdrv/acpi/tools/ntsdext/sources), [base/busdrv/acpi/tools/ntsdext/makefile](../../base/busdrv/acpi/tools/ntsdext/makefile) | `acpintsd` | `DYNLINK` |
| [base/busdrv/acpi/tools/pmte](../../base/busdrv/acpi/tools/pmte) | 56 | — | — | — |
| [base/busdrv/acpi/tools/sleeper](../../base/busdrv/acpi/tools/sleeper) | 2 | — | — | — |
| [base/busdrv/acpi/tools/spsim](../../base/busdrv/acpi/tools/spsim) | 2 | [base/busdrv/acpi/tools/spsim/dirs](../../base/busdrv/acpi/tools/spsim/dirs) | — | — |
| [base/busdrv/acpi/tools/spsim/asl](../../base/busdrv/acpi/tools/spsim/asl) | 2 | [base/busdrv/acpi/tools/spsim/asl/makefile](../../base/busdrv/acpi/tools/spsim/asl/makefile) | — | — |
| [base/busdrv/acpi/tools/spsim/client](../../base/busdrv/acpi/tools/spsim/client) | 3 | [base/busdrv/acpi/tools/spsim/client/sources](../../base/busdrv/acpi/tools/spsim/client/sources), [base/busdrv/acpi/tools/spsim/client/makefile](../../base/busdrv/acpi/tools/spsim/client/makefile) | `spctl` | `PROGRAM` |
| [base/busdrv/acpi/tools/spsim/driver](../../base/busdrv/acpi/tools/spsim/driver) | 14 | [base/busdrv/acpi/tools/spsim/driver/sources](../../base/busdrv/acpi/tools/spsim/driver/sources), [base/busdrv/acpi/tools/spsim/driver/makefile](../../base/busdrv/acpi/tools/spsim/driver/makefile) | `spsim` | `DRIVER` |
| [base/busdrv/acpi/tools/spsim/inc](../../base/busdrv/acpi/tools/spsim/inc) | 1 | — | — | — |
| [base/busdrv/acpi/tools/tztool](../../base/busdrv/acpi/tools/tztool) | 6 | [base/busdrv/acpi/tools/tztool/sources](../../base/busdrv/acpi/tools/tztool/sources), [base/busdrv/acpi/tools/tztool/makefile](../../base/busdrv/acpi/tools/tztool/makefile) | `tztool` | `PROGRAM` |
| [base/busdrv/acpi/tools/unasm](../../base/busdrv/acpi/tools/unasm) | 16 | [base/busdrv/acpi/tools/unasm/sources](../../base/busdrv/acpi/tools/unasm/sources), [base/busdrv/acpi/tools/unasm/makefile](../../base/busdrv/acpi/tools/unasm/makefile) | `unasm` | `LIBRARY` |
| [base/busdrv/acpi/tools/unasm2](../../base/busdrv/acpi/tools/unasm2) | 19 | [base/busdrv/acpi/tools/unasm2/sources](../../base/busdrv/acpi/tools/unasm2/sources), [base/busdrv/acpi/tools/unasm2/makefile](../../base/busdrv/acpi/tools/unasm2/makefile) | `acpike` | `DYNLINK` |
| [base/busdrv/acpi/wmiacpi](../../base/busdrv/acpi/wmiacpi) | 5 | [base/busdrv/acpi/wmiacpi/sources](../../base/busdrv/acpi/wmiacpi/sources), [base/busdrv/acpi/wmiacpi/makefile](../../base/busdrv/acpi/wmiacpi/makefile) | `wmiacpi` | `DRIVER` |
| [base/busdrv/acpi/wmiacpi/sample](../../base/busdrv/acpi/wmiacpi/sample) | 9 | [base/busdrv/acpi/wmiacpi/sample/sources](../../base/busdrv/acpi/wmiacpi/sample/sources), [base/busdrv/acpi/wmiacpi/sample/makefile](../../base/busdrv/acpi/wmiacpi/sample/makefile) | `acpimof` | `DYNLINK` |
| [base/busdrv/agp](../../base/busdrv/agp) | 1 | [base/busdrv/agp/dirs](../../base/busdrv/agp/dirs) | — | — |
| [base/busdrv/agp/agp440](../../base/busdrv/agp/agp440) | 8 | [base/busdrv/agp/agp440/sources](../../base/busdrv/agp/agp440/sources), [base/busdrv/agp/agp440/makefile](../../base/busdrv/agp/agp440/makefile) | `agp440` | `DRIVER` |
| [base/busdrv/agp/agp460](../../base/busdrv/agp/agp460) | 6 | [base/busdrv/agp/agp460/sources](../../base/busdrv/agp/agp460/sources), [base/busdrv/agp/agp460/makefile](../../base/busdrv/agp/agp460/makefile) | `agp460` | `DRIVER` |
| [base/busdrv/agp/agpcpq](../../base/busdrv/agp/agpcpq) | 6 | [base/busdrv/agp/agpcpq/sources](../../base/busdrv/agp/agpcpq/sources), [base/busdrv/agp/agpcpq/makefile](../../base/busdrv/agp/agpcpq/makefile) | `agpcpq` | `DRIVER` |
| [base/busdrv/agp/agplib](../../base/busdrv/agp/agplib) | 10 | [base/busdrv/agp/agplib/sources](../../base/busdrv/agp/agplib/sources), [base/busdrv/agp/agplib/makefile](../../base/busdrv/agp/agplib/makefile) | `agplib` | `DRIVER_LIBRARY` |
| [base/busdrv/agp/alim1541](../../base/busdrv/agp/alim1541) | 6 | [base/busdrv/agp/alim1541/sources](../../base/busdrv/agp/alim1541/sources), [base/busdrv/agp/alim1541/makefile](../../base/busdrv/agp/alim1541/makefile) | `ALiM1541` | `DRIVER` |
| [base/busdrv/agp/inc](../../base/busdrv/agp/inc) | 1 | — | — | — |
| [base/busdrv/agp/viaagp](../../base/busdrv/agp/viaagp) | 6 | [base/busdrv/agp/viaagp/sources](../../base/busdrv/agp/viaagp/sources), [base/busdrv/agp/viaagp/makefile](../../base/busdrv/agp/viaagp/makefile) | `viaagp` | `DRIVER` |
| [base/busdrv/isapnp](../../base/busdrv/isapnp) | 19 | [base/busdrv/isapnp/sources](../../base/busdrv/isapnp/sources), [base/busdrv/isapnp/makefile](../../base/busdrv/isapnp/makefile) | `isapnp` | `DRIVER` |
| [base/busdrv/mf](../../base/busdrv/mf) | 17 | [base/busdrv/mf/sources](../../base/busdrv/mf/sources), [base/busdrv/mf/makefile](../../base/busdrv/mf/makefile) | `mf` | `DRIVER` |
| [base/busdrv/pccard](../../base/busdrv/pccard) | 3 | [base/busdrv/pccard/dirs](../../base/busdrv/pccard/dirs) | — | — |
| [base/busdrv/pccard/inc](../../base/busdrv/pccard/inc) | 12 | — | — | — |
| [base/busdrv/pccard/memcard](../../base/busdrv/pccard/memcard) | 15 | [base/busdrv/pccard/memcard/sources](../../base/busdrv/pccard/memcard/sources), [base/busdrv/pccard/memcard/makefile](../../base/busdrv/pccard/memcard/makefile) | `memcard` | `DRIVER` |
| [base/busdrv/pccard/pcmcibus](../../base/busdrv/pccard/pcmcibus) | 34 | [base/busdrv/pccard/pcmcibus/sources](../../base/busdrv/pccard/pcmcibus/sources), [base/busdrv/pccard/pcmcibus/makefile](../../base/busdrv/pccard/pcmcibus/makefile) | `pcmcia` | `DRIVER` |
| [base/busdrv/pci](../../base/busdrv/pci) | 40 | [base/busdrv/pci/sources](../../base/busdrv/pci/sources), [base/busdrv/pci/makefile](../../base/busdrv/pci/makefile) | `pci` | `DRIVER` |
| [base/busdrv/pcidump](../../base/busdrv/pcidump) | 4 | [base/busdrv/pcidump/sources](../../base/busdrv/pcidump/sources), [base/busdrv/pcidump/makefile](../../base/busdrv/pcidump/makefile) | `pcidump` | `DRIVER` |

## `base/cluster/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [base/cluster](../../base/cluster) | 9 | [base/cluster/dirs](../../base/cluster/dirs) | — | — |
| [base/cluster/admin](../../base/cluster/admin) | 3 | [base/cluster/admin/dirs](../../base/cluster/admin/dirs) | — | — |
| [base/cluster/admin/cladmwiz](../../base/cluster/admin/cladmwiz) | 1 | [base/cluster/admin/cladmwiz/dirs](../../base/cluster/admin/cladmwiz/dirs) | — | — |
| [base/cluster/admin/cladmwiz/src](../../base/cluster/admin/cladmwiz/src) | 75 | [base/cluster/admin/cladmwiz/src/sources](../../base/cluster/admin/cladmwiz/src/sources), [base/cluster/admin/cladmwiz/src/makefile](../../base/cluster/admin/cladmwiz/src/makefile) | `ClAdmWiz` | `DYNLINK` |
| [base/cluster/admin/cladmwiz/src/res](../../base/cluster/admin/cladmwiz/src/res) | 5 | — | — | — |
| [base/cluster/admin/cladmwiz/types](../../base/cluster/admin/cladmwiz/types) | 1 | [base/cluster/admin/cladmwiz/types/dirs](../../base/cluster/admin/cladmwiz/types/dirs) | — | — |
| [base/cluster/admin/cladmwiz/types/idl](../../base/cluster/admin/cladmwiz/types/idl) | 4 | [base/cluster/admin/cladmwiz/types/idl/sources](../../base/cluster/admin/cladmwiz/types/idl/sources), [base/cluster/admin/cladmwiz/types/idl/makefile](../../base/cluster/admin/cladmwiz/types/idl/makefile) | — | `NOTARGET` |
| [base/cluster/admin/cladmwiz/types/uuid](../../base/cluster/admin/cladmwiz/types/uuid) | 2 | [base/cluster/admin/cladmwiz/types/uuid/sources](../../base/cluster/admin/cladmwiz/types/uuid/sources), [base/cluster/admin/cladmwiz/types/uuid/makefile](../../base/cluster/admin/cladmwiz/types/uuid/makefile) | `ClAdmWiz` | `LIBRARY` |
| [base/cluster/admin/cluadmex](../../base/cluster/admin/cluadmex) | 72 | [base/cluster/admin/cluadmex/sources](../../base/cluster/admin/cluadmex/sources), [base/cluster/admin/cluadmex/makefile](../../base/cluster/admin/cluadmex/makefile) | `cluadmex` | `DYNLINK` |
| [base/cluster/admin/cluadmex/res](../../base/cluster/admin/cluadmex/res) | 2 | — | — | — |
| [base/cluster/admin/cluadmin](../../base/cluster/admin/cluadmin) | 155 | [base/cluster/admin/cluadmin/sources](../../base/cluster/admin/cluadmin/sources), [base/cluster/admin/cluadmin/makefile](../../base/cluster/admin/cluadmin/makefile) | `cluadmin` | `PROGRAM` |
| [base/cluster/admin/cluadmin/hlp](../../base/cluster/admin/cluadmin/hlp) | 27 | — | — | — |
| [base/cluster/admin/cluadmin/res](../../base/cluster/admin/cluadmin/res) | 79 | — | — | — |
| [base/cluster/admin/cluadmmc](../../base/cluster/admin/cluadmmc) | 1 | [base/cluster/admin/cluadmmc/dirs](../../base/cluster/admin/cluadmmc/dirs) | — | — |
| [base/cluster/admin/cluadmmc/src](../../base/cluster/admin/cluadmmc/src) | 31 | [base/cluster/admin/cluadmmc/src/sources](../../base/cluster/admin/cluadmmc/src/sources), [base/cluster/admin/cluadmmc/src/makefile](../../base/cluster/admin/cluadmmc/src/makefile) | `CluAdMMC` | `DYNLINK` |
| [base/cluster/admin/cluadmmc/src/res](../../base/cluster/admin/cluadmmc/src/res) | 5 | — | — | — |
| [base/cluster/admin/cluadmmc/types](../../base/cluster/admin/cluadmmc/types) | 1 | [base/cluster/admin/cluadmmc/types/dirs](../../base/cluster/admin/cluadmmc/types/dirs) | — | — |
| [base/cluster/admin/cluadmmc/types/idl](../../base/cluster/admin/cluadmmc/types/idl) | 4 | [base/cluster/admin/cluadmmc/types/idl/sources](../../base/cluster/admin/cluadmmc/types/idl/sources), [base/cluster/admin/cluadmmc/types/idl/makefile](../../base/cluster/admin/cluadmmc/types/idl/makefile) | — | `NOTARGET` |
| [base/cluster/admin/cluadmmc/types/uuid](../../base/cluster/admin/cluadmmc/types/uuid) | 2 | [base/cluster/admin/cluadmmc/types/uuid/sources](../../base/cluster/admin/cluadmmc/types/uuid/sources), [base/cluster/admin/cluadmmc/types/uuid/makefile](../../base/cluster/admin/cluadmmc/types/uuid/makefile) | `CluAdMMCguid` | `LIBRARY` |
| [base/cluster/admin/cluster](../../base/cluster/admin/cluster) | 43 | [base/cluster/admin/cluster/sources](../../base/cluster/admin/cluster/sources), [base/cluster/admin/cluster/makefile](../../base/cluster/admin/cluster/makefile) | `cluster` | `PROGRAM` |
| [base/cluster/admin/common](../../base/cluster/admin/common) | 53 | [base/cluster/admin/common/sources](../../base/cluster/admin/common/sources), [base/cluster/admin/common/makefile](../../base/cluster/admin/common/makefile) | `common` | `LIBRARY` |
| [base/cluster/admin/debugex](../../base/cluster/admin/debugex) | 32 | [base/cluster/admin/debugex/sources](../../base/cluster/admin/debugex/sources), [base/cluster/admin/debugex/makefile](../../base/cluster/admin/debugex/makefile) | `debugex` | `DYNLINK` |
| [base/cluster/admin/debugex/res](../../base/cluster/admin/debugex/res) | 1 | — | — | — |
| [base/cluster/admin/iisclex3](../../base/cluster/admin/iisclex3) | 38 | [base/cluster/admin/iisclex3/sources](../../base/cluster/admin/iisclex3/sources), [base/cluster/admin/iisclex3/makefile](../../base/cluster/admin/iisclex3/makefile) | `iisclex3` | `DYNLINK` |
| [base/cluster/admin/iisclex3/res](../../base/cluster/admin/iisclex3/res) | 1 | — | — | — |
| [base/cluster/admin/msclus](../../base/cluster/admin/msclus) | 50 | [base/cluster/admin/msclus/sources](../../base/cluster/admin/msclus/sources), [base/cluster/admin/msclus/makefile](../../base/cluster/admin/msclus/makefile) | `msclus` | `DYNLINK` |
| [base/cluster/admin/msclus/asp](../../base/cluster/admin/msclus/asp) | 7 | — | — | — |
| [base/cluster/admin/msclus/asp/images](../../base/cluster/admin/msclus/asp/images) | 1 | — | — | — |
| [base/cluster/admin/msclus/html](../../base/cluster/admin/msclus/html) | 12 | — | — | — |
| [base/cluster/admin/msclus/vbscript](../../base/cluster/admin/msclus/vbscript) | 26 | — | — | — |
| [base/cluster/admin/msclus/vbtest](../../base/cluster/admin/msclus/vbtest) | 4 | — | — | — |
| [base/cluster/admin/msclus/vctest](../../base/cluster/admin/msclus/vctest) | 15 | — | — | — |
| [base/cluster/admin/msclus/vctest/res](../../base/cluster/admin/msclus/vctest/res) | 2 | — | — | — |
| [base/cluster/admin/msclus/wsf](../../base/cluster/admin/msclus/wsf) | 12 | — | — | — |
| [base/cluster/admin/types](../../base/cluster/admin/types) | 1 | [base/cluster/admin/types/dirs](../../base/cluster/admin/types/dirs) | — | — |
| [base/cluster/admin/types/idl](../../base/cluster/admin/types/idl) | 3 | [base/cluster/admin/types/idl/sources](../../base/cluster/admin/types/idl/sources), [base/cluster/admin/types/idl/makefile](../../base/cluster/admin/types/idl/makefile) | — | `NOTARGET` |
| [base/cluster/admin/types/uuid](../../base/cluster/admin/types/uuid) | 2 | [base/cluster/admin/types/uuid/sources](../../base/cluster/admin/types/uuid/sources), [base/cluster/admin/types/uuid/makefile](../../base/cluster/admin/types/uuid/makefile) | `cluadmex` | `LIBRARY` |
| [base/cluster/bh](../../base/cluster/bh) | 1 | — | — | — |
| [base/cluster/bh/build](../../base/cluster/bh/build) | 9 | — | — | — |
| [base/cluster/bh/parsers](../../base/cluster/bh/parsers) | 1 | [base/cluster/bh/parsers/dirs](../../base/cluster/bh/parsers/dirs) | — | — |
| [base/cluster/bh/parsers/clusnet](../../base/cluster/bh/parsers/clusnet) | 13 | [base/cluster/bh/parsers/clusnet/sources](../../base/cluster/bh/parsers/clusnet/sources), [base/cluster/bh/parsers/clusnet/makefile](../../base/cluster/bh/parsers/clusnet/makefile) | `clusnet` | `DYNLINK` |
| [base/cluster/bh/parsers/clusrpc](../../base/cluster/bh/parsers/clusrpc) | 15 | [base/cluster/bh/parsers/clusrpc/sources](../../base/cluster/bh/parsers/clusrpc/sources), [base/cluster/bh/parsers/clusrpc/makefile](../../base/cluster/bh/parsers/clusrpc/makefile) | `clusrpc` | `DYNLINK` |
| [base/cluster/bh/parsers/msrpc](../../base/cluster/bh/parsers/msrpc) | 12 | [base/cluster/bh/parsers/msrpc/sources](../../base/cluster/bh/parsers/msrpc/sources), [base/cluster/bh/parsers/msrpc/makefile](../../base/cluster/bh/parsers/msrpc/makefile) | `msrpc` | `DYNLINK` |
| [base/cluster/bh/parsers/rescmon](../../base/cluster/bh/parsers/rescmon) | 13 | [base/cluster/bh/parsers/rescmon/sources](../../base/cluster/bh/parsers/rescmon/sources), [base/cluster/bh/parsers/rescmon/makefile](../../base/cluster/bh/parsers/rescmon/makefile) | `rescmon` | `DYNLINK` |
| [base/cluster/clnetcfg](../../base/cluster/clnetcfg) | 4 | [base/cluster/clnetcfg/sources](../../base/cluster/clnetcfg/sources), [base/cluster/clnetcfg/makefile](../../base/cluster/clnetcfg/makefile) | `clnetcfg` | `LIBRARY` |
| [base/cluster/clusapi](../../base/cluster/clusapi) | 35 | [base/cluster/clusapi/sources](../../base/cluster/clusapi/sources), [base/cluster/clusapi/makefile](../../base/cluster/clusapi/makefile) | `clusapi` | `DYNLINK` |
| [base/cluster/clusdisk](../../base/cluster/clusdisk) | 10 | [base/cluster/clusdisk/sources](../../base/cluster/clusdisk/sources), [base/cluster/clusdisk/makefile](../../base/cluster/clusdisk/makefile) | `clusdisk` | `DRIVER` |
| [base/cluster/clusdisk/kdcd](../../base/cluster/clusdisk/kdcd) | 6 | [base/cluster/clusdisk/kdcd/sources](../../base/cluster/clusdisk/kdcd/sources), [base/cluster/clusdisk/kdcd/makefile](../../base/cluster/clusdisk/kdcd/makefile) | `kdcd` | `DYNLINK` |
| [base/cluster/clusdisk/test](../../base/cluster/clusdisk/test) | 10 | [base/cluster/clusdisk/test/sources](../../base/cluster/clusdisk/test/sources), [base/cluster/clusdisk/test/makefile](../../base/cluster/clusdisk/test/makefile) | `disktest` | `PROGRAM` |
| [base/cluster/clusexts](../../base/cluster/clusexts) | 1 | [base/cluster/clusexts/dirs](../../base/cluster/clusexts/dirs) | — | — |
| [base/cluster/clusexts/clusexts](../../base/cluster/clusexts/clusexts) | 14 | [base/cluster/clusexts/clusexts/sources](../../base/cluster/clusexts/clusexts/sources), [base/cluster/clusexts/clusexts/makefile](../../base/cluster/clusexts/clusexts/makefile) | `clusexts` | `DYNLINK` |
| [base/cluster/clusexts/leaks](../../base/cluster/clusexts/leaks) | 6 | [base/cluster/clusexts/leaks/sources](../../base/cluster/clusexts/leaks/sources), [base/cluster/clusexts/leaks/makefile](../../base/cluster/clusexts/leaks/makefile) | `leaks` | `DYNLINK` |
| [base/cluster/clusnet](../../base/cluster/clusnet) | 2 | [base/cluster/clusnet/dirs](../../base/cluster/clusnet/dirs) | — | — |
| [base/cluster/clusnet/api](../../base/cluster/clusnet/api) | 3 | [base/cluster/clusnet/api/sources](../../base/cluster/clusnet/api/sources), [base/cluster/clusnet/api/makefile](../../base/cluster/clusnet/api/makefile) | `cnetapi` | `LIBRARY` |
| [base/cluster/clusnet/driver](../../base/cluster/clusnet/driver) | 11 | [base/cluster/clusnet/driver/sources](../../base/cluster/clusnet/driver/sources), [base/cluster/clusnet/driver/makefile](../../base/cluster/clusnet/driver/makefile) | `clusnet` | `DRIVER` |
| [base/cluster/clusnet/inc](../../base/cluster/clusnet/inc) | 12 | — | — | — |
| [base/cluster/clusnet/kdcn](../../base/cluster/clusnet/kdcn) | 6 | [base/cluster/clusnet/kdcn/sources](../../base/cluster/clusnet/kdcn/sources), [base/cluster/clusnet/kdcn/makefile](../../base/cluster/clusnet/kdcn/makefile) | `kdcn` | `DYNLINK` |
| [base/cluster/clusnet/ntemgmt](../../base/cluster/clusnet/ntemgmt) | 4 | [base/cluster/clusnet/ntemgmt/sources](../../base/cluster/clusnet/ntemgmt/sources), [base/cluster/clusnet/ntemgmt/makefile](../../base/cluster/clusnet/ntemgmt/makefile) | `ntemgmt` | `DRIVER_LIBRARY` |
| [base/cluster/clusnet/rpcep](../../base/cluster/clusnet/rpcep) | 4 | [base/cluster/clusnet/rpcep/sources](../../base/cluster/clusnet/rpcep/sources), [base/cluster/clusnet/rpcep/makefile](../../base/cluster/clusnet/rpcep/makefile) | `rpcep` | `PROGRAM` |
| [base/cluster/clusnet/test](../../base/cluster/clusnet/test) | 5 | [base/cluster/clusnet/test/sources](../../base/cluster/clusnet/test/sources), [base/cluster/clusnet/test/makefile](../../base/cluster/clusnet/test/makefile) | `cntest` | `UMAPPL_NOLIB` |
| [base/cluster/clusnet/wshclus](../../base/cluster/clusnet/wshclus) | 5 | [base/cluster/clusnet/wshclus/sources](../../base/cluster/clusnet/wshclus/sources), [base/cluster/clusnet/wshclus/makefile](../../base/cluster/clusnet/wshclus/makefile) | `wshclus` | `DYNLINK` |
| [base/cluster/clusnet/xport](../../base/cluster/clusnet/xport) | 22 | [base/cluster/clusnet/xport/sources](../../base/cluster/clusnet/xport/sources), [base/cluster/clusnet/xport/makefile](../../base/cluster/clusnet/xport/makefile) | `cluxport` | `DRIVER_LIBRARY` |
| [base/cluster/clusrtl](../../base/cluster/clusrtl) | 35 | [base/cluster/clusrtl/sources](../../base/cluster/clusrtl/sources), [base/cluster/clusrtl/makefile](../../base/cluster/clusrtl/makefile) | `clusrtl` | `LIBRARY` |
| [base/cluster/clussprt](../../base/cluster/clussprt) | 7 | [base/cluster/clussprt/sources](../../base/cluster/clussprt/sources), [base/cluster/clussprt/makefile](../../base/cluster/clussprt/makefile) | `clussprt` | `DYNLINK` |
| [base/cluster/ext](../../base/cluster/ext) | 2 | [base/cluster/ext/sources](../../base/cluster/ext/sources), [base/cluster/ext/makefile](../../base/cluster/ext/makefile) | — | `NOTARGET` |
| [base/cluster/ext/atlsnap](../../base/cluster/ext/atlsnap) | 0 | — | — | — |
| [base/cluster/ext/atlsnap/inc](../../base/cluster/ext/atlsnap/inc) | 2 | — | — | — |
| [base/cluster/ext/gc](../../base/cluster/ext/gc) | 0 | — | — | — |
| [base/cluster/ext/gc/inc](../../base/cluster/ext/gc/inc) | 2 | — | — | — |
| [base/cluster/ext/mfcapwz](../../base/cluster/ext/mfcapwz) | 0 | — | — | — |
| [base/cluster/ext/mfcapwz/inc](../../base/cluster/ext/mfcapwz/inc) | 1 | — | — | — |
| [base/cluster/ext/mfcapwz/inc5](../../base/cluster/ext/mfcapwz/inc5) | 1 | — | — | — |
| [base/cluster/inc](../../base/cluster/inc) | 12 | — | — | — |
| [base/cluster/mgmt](../../base/cluster/mgmt) | 2 | [base/cluster/mgmt/dirs](../../base/cluster/mgmt/dirs) | — | — |
| [base/cluster/mgmt/cluscfg](../../base/cluster/mgmt/cluscfg) | 3 | [base/cluster/mgmt/cluscfg/dirs](../../base/cluster/mgmt/cluscfg/dirs) | — | — |
| [base/cluster/mgmt/cluscfg/basecluster](../../base/cluster/mgmt/cluscfg/basecluster) | 79 | [base/cluster/mgmt/cluscfg/basecluster/sources](../../base/cluster/mgmt/cluscfg/basecluster/sources), [base/cluster/mgmt/cluscfg/basecluster/makefile](../../base/cluster/mgmt/cluscfg/basecluster/makefile) | `BaseCluster` | `LIBRARY` |
| [base/cluster/mgmt/cluscfg/basecluster/listtest](../../base/cluster/mgmt/cluscfg/basecluster/listtest) | 4 | [base/cluster/mgmt/cluscfg/basecluster/listtest/sources](../../base/cluster/mgmt/cluscfg/basecluster/listtest/sources), [base/cluster/mgmt/cluscfg/basecluster/listtest/makefile](../../base/cluster/mgmt/cluscfg/basecluster/listtest/makefile) | `ListTest` | `PROGRAM` |
| [base/cluster/mgmt/cluscfg/basecluster/test](../../base/cluster/mgmt/cluscfg/basecluster/test) | 7 | [base/cluster/mgmt/cluscfg/basecluster/test/sources](../../base/cluster/mgmt/cluscfg/basecluster/test/sources), [base/cluster/mgmt/cluscfg/basecluster/test/makefile](../../base/cluster/mgmt/cluscfg/basecluster/test/makefile) | `BaseClusterTest` | `PROGRAM` |
| [base/cluster/mgmt/cluscfg/common](../../base/cluster/mgmt/cluscfg/common) | 17 | [base/cluster/mgmt/cluscfg/common/sources](../../base/cluster/mgmt/cluscfg/common/sources), [base/cluster/mgmt/cluscfg/common/makefile](../../base/cluster/mgmt/cluscfg/common/makefile) | `Common` | `LIBRARY` |
| [base/cluster/mgmt/cluscfg/dll](../../base/cluster/mgmt/cluscfg/dll) | 15 | [base/cluster/mgmt/cluscfg/dll/sources](../../base/cluster/mgmt/cluscfg/dll/sources), [base/cluster/mgmt/cluscfg/dll/makefile](../../base/cluster/mgmt/cluscfg/dll/makefile) | `ClCfgSrv` | `DYNLINK` |
| [base/cluster/mgmt/cluscfg/evictcleanup](../../base/cluster/mgmt/cluscfg/evictcleanup) | 7 | [base/cluster/mgmt/cluscfg/evictcleanup/sources](../../base/cluster/mgmt/cluscfg/evictcleanup/sources), [base/cluster/mgmt/cluscfg/evictcleanup/makefile](../../base/cluster/mgmt/cluscfg/evictcleanup/makefile) | `ClusCfgEvictCleanup` | `LIBRARY` |
| [base/cluster/mgmt/cluscfg/evictcleanup/testevict](../../base/cluster/mgmt/cluscfg/evictcleanup/testevict) | 5 | [base/cluster/mgmt/cluscfg/evictcleanup/testevict/sources](../../base/cluster/mgmt/cluscfg/evictcleanup/testevict/sources), [base/cluster/mgmt/cluscfg/evictcleanup/testevict/makefile](../../base/cluster/mgmt/cluscfg/evictcleanup/testevict/makefile) | `TestEvict` | `PROGRAM` |
| [base/cluster/mgmt/cluscfg/exe](../../base/cluster/mgmt/cluscfg/exe) | 7 | [base/cluster/mgmt/cluscfg/exe/sources](../../base/cluster/mgmt/cluscfg/exe/sources), [base/cluster/mgmt/cluscfg/exe/makefile](../../base/cluster/mgmt/cluscfg/exe/makefile) | `ClusCfg` | `PROGRAM` |
| [base/cluster/mgmt/cluscfg/inc](../../base/cluster/mgmt/cluscfg/inc) | 14 | [base/cluster/mgmt/cluscfg/inc/sources](../../base/cluster/mgmt/cluscfg/inc/sources), [base/cluster/mgmt/cluscfg/inc/makefile](../../base/cluster/mgmt/cluscfg/inc/makefile) | `ClusCfgProxy` | `LIBRARY` |
| [base/cluster/mgmt/cluscfg/middletier](../../base/cluster/mgmt/cluscfg/middletier) | 75 | [base/cluster/mgmt/cluscfg/middletier/sources](../../base/cluster/mgmt/cluscfg/middletier/sources), [base/cluster/mgmt/cluscfg/middletier/makefile](../../base/cluster/mgmt/cluscfg/middletier/makefile) | `MiddleTierComponents` | `LIBRARY` |
| [base/cluster/mgmt/cluscfg/middletier/test](../../base/cluster/mgmt/cluscfg/middletier/test) | 12 | [base/cluster/mgmt/cluscfg/middletier/test/sources](../../base/cluster/mgmt/cluscfg/middletier/test/sources), [base/cluster/mgmt/cluscfg/middletier/test/makefile](../../base/cluster/mgmt/cluscfg/middletier/test/makefile) | `MiddleTierTest` | `PROGRAM` |
| [base/cluster/mgmt/cluscfg/postcfg](../../base/cluster/mgmt/cluscfg/postcfg) | 33 | [base/cluster/mgmt/cluscfg/postcfg/sources](../../base/cluster/mgmt/cluscfg/postcfg/sources), [base/cluster/mgmt/cluscfg/postcfg/makefile](../../base/cluster/mgmt/cluscfg/postcfg/makefile) | `ClusCfgPostCfg` | `LIBRARY` |
| [base/cluster/mgmt/cluscfg/postcfg/test](../../base/cluster/mgmt/cluscfg/postcfg/test) | 9 | [base/cluster/mgmt/cluscfg/postcfg/test/sources](../../base/cluster/mgmt/cluscfg/postcfg/test/sources), [base/cluster/mgmt/cluscfg/postcfg/test/makefile](../../base/cluster/mgmt/cluscfg/postcfg/test/makefile) | `PostCfgTest` | `PROGRAM` |
| [base/cluster/mgmt/cluscfg/server](../../base/cluster/mgmt/cluscfg/server) | 54 | [base/cluster/mgmt/cluscfg/server/sources](../../base/cluster/mgmt/cluscfg/server/sources), [base/cluster/mgmt/cluscfg/server/makefile](../../base/cluster/mgmt/cluscfg/server/makefile) | `ClusCfgServerComponents` | `LIBRARY` |
| [base/cluster/mgmt/cluscfg/server/test](../../base/cluster/mgmt/cluscfg/server/test) | 12 | [base/cluster/mgmt/cluscfg/server/test/sources](../../base/cluster/mgmt/cluscfg/server/test/sources), [base/cluster/mgmt/cluscfg/server/test/makefile](../../base/cluster/mgmt/cluscfg/server/test/makefile) | `ClusCfgServerTest` | `PROGRAM` |
| [base/cluster/mgmt/cluscfg/startup](../../base/cluster/mgmt/cluscfg/startup) | 5 | [base/cluster/mgmt/cluscfg/startup/sources](../../base/cluster/mgmt/cluscfg/startup/sources), [base/cluster/mgmt/cluscfg/startup/makefile](../../base/cluster/mgmt/cluscfg/startup/makefile) | `ClusCfgStartup` | `LIBRARY` |
| [base/cluster/mgmt/cluscfg/uuid](../../base/cluster/mgmt/cluscfg/uuid) | 3 | [base/cluster/mgmt/cluscfg/uuid/sources](../../base/cluster/mgmt/cluscfg/uuid/sources), [base/cluster/mgmt/cluscfg/uuid/makefile](../../base/cluster/mgmt/cluscfg/uuid/makefile) | `ClusCfgUuid` | `LIBRARY` |
| [base/cluster/mgmt/cluscfg/w2kproxy](../../base/cluster/mgmt/cluscfg/w2kproxy) | 24 | [base/cluster/mgmt/cluscfg/w2kproxy/sources](../../base/cluster/mgmt/cluscfg/w2kproxy/sources), [base/cluster/mgmt/cluscfg/w2kproxy/makefile](../../base/cluster/mgmt/cluscfg/w2kproxy/makefile) | `W2kConfigProxy` | `LIBRARY` |
| [base/cluster/mgmt/cluscfg/w2kproxy/test](../../base/cluster/mgmt/cluscfg/w2kproxy/test) | 8 | [base/cluster/mgmt/cluscfg/w2kproxy/test/sources](../../base/cluster/mgmt/cluscfg/w2kproxy/test/sources), [base/cluster/mgmt/cluscfg/w2kproxy/test/makefile](../../base/cluster/mgmt/cluscfg/w2kproxy/test/makefile) | `W2KProxyTest` | `PROGRAM` |
| [base/cluster/mgmt/cluscfg/wizard](../../base/cluster/mgmt/cluscfg/wizard) | 46 | [base/cluster/mgmt/cluscfg/wizard/sources](../../base/cluster/mgmt/cluscfg/wizard/sources), [base/cluster/mgmt/cluscfg/wizard/makefile](../../base/cluster/mgmt/cluscfg/wizard/makefile) | `ClusCfgWizard` | `LIBRARY` |
| [base/cluster/mgmt/cluscfg/wizard/res](../../base/cluster/mgmt/cluscfg/wizard/res) | 18 | — | — | — |
| [base/cluster/mgmt/cluscfg/wizard/test](../../base/cluster/mgmt/cluscfg/wizard/test) | 8 | [base/cluster/mgmt/cluscfg/wizard/test/sources](../../base/cluster/mgmt/cluscfg/wizard/test/sources), [base/cluster/mgmt/cluscfg/wizard/test/makefile](../../base/cluster/mgmt/cluscfg/wizard/test/makefile) | `WizardTest` | `PROGRAM` |
| [base/cluster/mgmt/cluscomp](../../base/cluster/mgmt/cluscomp) | 12 | [base/cluster/mgmt/cluscomp/sources](../../base/cluster/mgmt/cluscomp/sources), [base/cluster/mgmt/cluscomp/makefile](../../base/cluster/mgmt/cluscomp/makefile) | `ClusCOMP` | `DYNLINK` |
| [base/cluster/mgmt/clusocm](../../base/cluster/mgmt/clusocm) | 33 | [base/cluster/mgmt/clusocm/sources](../../base/cluster/mgmt/clusocm/sources), [base/cluster/mgmt/clusocm/makefile](../../base/cluster/mgmt/clusocm/makefile) | `ClusOCM` | `DYNLINK` |
| [base/cluster/mgmt/common](../../base/cluster/mgmt/common) | 8 | [base/cluster/mgmt/common/sources](../../base/cluster/mgmt/common/sources), [base/cluster/mgmt/common/makefile](../../base/cluster/mgmt/common/makefile) | `Common` | `LIBRARY` |
| [base/cluster/mgmt/component](../../base/cluster/mgmt/component) | 5 | [base/cluster/mgmt/component/sources](../../base/cluster/mgmt/component/sources), [base/cluster/mgmt/component/makefile](../../base/cluster/mgmt/component/makefile) | `Component` | `NOTARGET` |
| [base/cluster/mgmt/inc](../../base/cluster/mgmt/inc) | 22 | — | — | — |
| [base/cluster/resdll](../../base/cluster/resdll) | 1 | [base/cluster/resdll/dirs](../../base/cluster/resdll/dirs) | — | — |
| [base/cluster/resdll/clnetres](../../base/cluster/resdll/clnetres) | 2 | [base/cluster/resdll/clnetres/dirs](../../base/cluster/resdll/clnetres/dirs) | — | — |
| [base/cluster/resdll/clnetres/clnetres](../../base/cluster/resdll/clnetres/clnetres) | 12 | [base/cluster/resdll/clnetres/clnetres/sources](../../base/cluster/resdll/clnetres/clnetres/sources), [base/cluster/resdll/clnetres/clnetres/makefile](../../base/cluster/resdll/clnetres/clnetres/makefile) | `clnetres` | `DYNLINK` |
| [base/cluster/resdll/clnetres/clnetresex](../../base/cluster/resdll/clnetres/clnetresex) | 35 | [base/cluster/resdll/clnetres/clnetresex/sources](../../base/cluster/resdll/clnetres/clnetresex/sources), [base/cluster/resdll/clnetres/clnetresex/makefile](../../base/cluster/resdll/clnetres/clnetresex/makefile) | `clnetrex` | `DYNLINK` |
| [base/cluster/resdll/clnetres/clnetresex/res](../../base/cluster/resdll/clnetres/clnetresex/res) | 1 | — | — | — |
| [base/cluster/resdll/clusres](../../base/cluster/resdll/clusres) | 6 | [base/cluster/resdll/clusres/sources](../../base/cluster/resdll/clusres/sources), [base/cluster/resdll/clusres/makefile](../../base/cluster/resdll/clusres/makefile) | `clusres` | `DYNLINK` |
| [base/cluster/resdll/common](../../base/cluster/resdll/common) | 2 | — | — | — |
| [base/cluster/resdll/disks](../../base/cluster/resdll/disks) | 14 | [base/cluster/resdll/disks/sources](../../base/cluster/resdll/disks/sources), [base/cluster/resdll/disks/makefile](../../base/cluster/resdll/disks/makefile) | `disks` | `LIBRARY` |
| [base/cluster/resdll/disks/extdll](../../base/cluster/resdll/disks/extdll) | 1 | [base/cluster/resdll/disks/extdll/dirs](../../base/cluster/resdll/disks/extdll/dirs) | — | — |
| [base/cluster/resdll/disks/extdll/dll](../../base/cluster/resdll/disks/extdll/dll) | 5 | [base/cluster/resdll/disks/extdll/dll/sources](../../base/cluster/resdll/disks/extdll/dll/sources), [base/cluster/resdll/disks/extdll/dll/makefile](../../base/cluster/resdll/disks/extdll/dll/makefile) | `passthru` | `DYNLINK` |
| [base/cluster/resdll/disks/extdll/exe](../../base/cluster/resdll/disks/extdll/exe) | 4 | [base/cluster/resdll/disks/extdll/exe/sources](../../base/cluster/resdll/disks/extdll/exe/sources), [base/cluster/resdll/disks/extdll/exe/makefile](../../base/cluster/resdll/disks/extdll/exe/makefile) | `tstdllex` | `PROGRAM` |
| [base/cluster/resdll/dummy](../../base/cluster/resdll/dummy) | 6 | [base/cluster/resdll/dummy/sources](../../base/cluster/resdll/dummy/sources), [base/cluster/resdll/dummy/makefile](../../base/cluster/resdll/dummy/makefile) | `dummy` | `DYNLINK` |
| [base/cluster/resdll/dummyex](../../base/cluster/resdll/dummyex) | 26 | [base/cluster/resdll/dummyex/sources](../../base/cluster/resdll/dummyex/sources), [base/cluster/resdll/dummyex/makefile](../../base/cluster/resdll/dummyex/makefile) | `dummyex` | `DYNLINK` |
| [base/cluster/resdll/dummyex/res](../../base/cluster/resdll/dummyex/res) | 1 | — | — | — |
| [base/cluster/resdll/exchange](../../base/cluster/resdll/exchange) | 9 | [base/cluster/resdll/exchange/sources](../../base/cluster/resdll/exchange/sources), [base/cluster/resdll/exchange/makefile](../../base/cluster/resdll/exchange/makefile) | `xchgclus` | `DYNLINK` |
| [base/cluster/resdll/genapp](../../base/cluster/resdll/genapp) | 4 | [base/cluster/resdll/genapp/sources](../../base/cluster/resdll/genapp/sources), [base/cluster/resdll/genapp/makefile](../../base/cluster/resdll/genapp/makefile) | `genapp` | `LIBRARY` |
| [base/cluster/resdll/gencmd](../../base/cluster/resdll/gencmd) | 5 | [base/cluster/resdll/gencmd/sources](../../base/cluster/resdll/gencmd/sources), [base/cluster/resdll/gencmd/makefile](../../base/cluster/resdll/gencmd/makefile) | `gencmd` | `DYNLINK` |
| [base/cluster/resdll/genjob](../../base/cluster/resdll/genjob) | 1 | [base/cluster/resdll/genjob/dirs](../../base/cluster/resdll/genjob/dirs) | — | — |
| [base/cluster/resdll/genjob/dll](../../base/cluster/resdll/genjob/dll) | 9 | [base/cluster/resdll/genjob/dll/sources](../../base/cluster/resdll/genjob/dll/sources), [base/cluster/resdll/genjob/dll/makefile](../../base/cluster/resdll/genjob/dll/makefile) | `genjob` | `DYNLINK` |
| [base/cluster/resdll/genscript](../../base/cluster/resdll/genscript) | 19 | [base/cluster/resdll/genscript/sources](../../base/cluster/resdll/genscript/sources), [base/cluster/resdll/genscript/makefile](../../base/cluster/resdll/genscript/makefile) | `genscript` | `LIBRARY` |
| [base/cluster/resdll/genscript/test](../../base/cluster/resdll/genscript/test) | 1 | — | — | — |
| [base/cluster/resdll/gensvc](../../base/cluster/resdll/gensvc) | 4 | [base/cluster/resdll/gensvc/sources](../../base/cluster/resdll/gensvc/sources), [base/cluster/resdll/gensvc/makefile](../../base/cluster/resdll/gensvc/makefile) | `gensvc` | `LIBRARY` |
| [base/cluster/resdll/iis](../../base/cluster/resdll/iis) | 10 | [base/cluster/resdll/iis/sources](../../base/cluster/resdll/iis/sources), [base/cluster/resdll/iis/makefile](../../base/cluster/resdll/iis/makefile) | `iisclus3` | `DYNLINK` |
| [base/cluster/resdll/inc](../../base/cluster/resdll/inc) | 2 | — | — | — |
| [base/cluster/resdll/ipaddr](../../base/cluster/resdll/ipaddr) | 8 | [base/cluster/resdll/ipaddr/sources](../../base/cluster/resdll/ipaddr/sources), [base/cluster/resdll/ipaddr/makefile](../../base/cluster/resdll/ipaddr/makefile) | `ipaddr` | `LIBRARY` |
| [base/cluster/resdll/lkquorum](../../base/cluster/resdll/lkquorum) | 3 | [base/cluster/resdll/lkquorum/sources](../../base/cluster/resdll/lkquorum/sources), [base/cluster/resdll/lkquorum/makefile](../../base/cluster/resdll/lkquorum/makefile) | `LkQuorum` | `LIBRARY` |
| [base/cluster/resdll/msmq](../../base/cluster/resdll/msmq) | 6 | [base/cluster/resdll/msmq/sources](../../base/cluster/resdll/msmq/sources), [base/cluster/resdll/msmq/makefile](../../base/cluster/resdll/msmq/makefile) | `msmq` | `LIBRARY` |
| [base/cluster/resdll/ndquorum](../../base/cluster/resdll/ndquorum) | 22 | [base/cluster/resdll/ndquorum/sources](../../base/cluster/resdll/ndquorum/sources), [base/cluster/resdll/ndquorum/makefile](../../base/cluster/resdll/ndquorum/makefile) | `NodeQuorum` | `LIBRARY` |
| [base/cluster/resdll/ndquorum/standalone](../../base/cluster/resdll/ndquorum/standalone) | 3 | [base/cluster/resdll/ndquorum/standalone/sources](../../base/cluster/resdll/ndquorum/standalone/sources), [base/cluster/resdll/ndquorum/standalone/makefile](../../base/cluster/resdll/ndquorum/standalone/makefile) | `fscrs` | `PROGRAM` |
| [base/cluster/resdll/netname](../../base/cluster/resdll/netname) | 13 | [base/cluster/resdll/netname/sources](../../base/cluster/resdll/netname/sources), [base/cluster/resdll/netname/makefile](../../base/cluster/resdll/netname/makefile) | `netname` | `LIBRARY` |
| [base/cluster/resdll/resutils](../../base/cluster/resdll/resutils) | 6 | [base/cluster/resdll/resutils/sources](../../base/cluster/resdll/resutils/sources), [base/cluster/resdll/resutils/makefile](../../base/cluster/resdll/resutils/makefile) | `resutils` | `DYNLINK` |
| [base/cluster/resdll/smbshare](../../base/cluster/resdll/smbshare) | 6 | [base/cluster/resdll/smbshare/sources](../../base/cluster/resdll/smbshare/sources), [base/cluster/resdll/smbshare/makefile](../../base/cluster/resdll/smbshare/makefile) | `smbshare` | `LIBRARY` |
| [base/cluster/resdll/spooler](../../base/cluster/resdll/spooler) | 1 | [base/cluster/resdll/spooler/dirs](../../base/cluster/resdll/spooler/dirs) | — | — |
| [base/cluster/resdll/spooler/splsvc](../../base/cluster/resdll/spooler/splsvc) | 16 | [base/cluster/resdll/spooler/splsvc/sources](../../base/cluster/resdll/spooler/splsvc/sources), [base/cluster/resdll/spooler/splsvc/makefile](../../base/cluster/resdll/spooler/splsvc/makefile) | `splsvc` | `LIBRARY` |
| [base/cluster/resdll/spooler/spltest](../../base/cluster/resdll/spooler/spltest) | 4 | [base/cluster/resdll/spooler/spltest/sources](../../base/cluster/resdll/spooler/spltest/sources), [base/cluster/resdll/spooler/spltest/makefile](../../base/cluster/resdll/spooler/spltest/makefile) | `spltest` | `PROGRAM` |
| [base/cluster/resdll/timesvc](../../base/cluster/resdll/timesvc) | 4 | [base/cluster/resdll/timesvc/sources](../../base/cluster/resdll/timesvc/sources), [base/cluster/resdll/timesvc/makefile](../../base/cluster/resdll/timesvc/makefile) | `timesvc` | `LIBRARY` |
| [base/cluster/resmon](../../base/cluster/resmon) | 14 | [base/cluster/resmon/sources](../../base/cluster/resmon/sources), [base/cluster/resmon/makefile](../../base/cluster/resmon/makefile) | `resrcmon` | `PROGRAM` |
| [base/cluster/resmon/test](../../base/cluster/resmon/test) | 3 | — | — | — |
| [base/cluster/service](../../base/cluster/service) | 1 | [base/cluster/service/dirs](../../base/cluster/service/dirs) | — | — |
| [base/cluster/service/api](../../base/cluster/service/api) | 15 | [base/cluster/service/api/sources](../../base/cluster/service/api/sources), [base/cluster/service/api/makefile](../../base/cluster/service/api/makefile) | `api` | `LIBRARY` |
| [base/cluster/service/cp](../../base/cluster/service/cp) | 10 | [base/cluster/service/cp/sources](../../base/cluster/service/cp/sources), [base/cluster/service/cp/makefile](../../base/cluster/service/cp/makefile) | `cp` | `LIBRARY` |
| [base/cluster/service/dm](../../base/cluster/service/dm) | 10 | [base/cluster/service/dm/sources](../../base/cluster/service/dm/sources), [base/cluster/service/dm/makefile](../../base/cluster/service/dm/makefile) | `dm` | `LIBRARY` |
| [base/cluster/service/ep](../../base/cluster/service/ep) | 4 | [base/cluster/service/ep/sources](../../base/cluster/service/ep/sources), [base/cluster/service/ep/makefile](../../base/cluster/service/ep/makefile) | `ep` | `LIBRARY` |
| [base/cluster/service/evtlog](../../base/cluster/service/evtlog) | 6 | [base/cluster/service/evtlog/sources](../../base/cluster/service/evtlog/sources), [base/cluster/service/evtlog/makefile](../../base/cluster/service/evtlog/makefile) | `evtlog` | `LIBRARY` |
| [base/cluster/service/fm](../../base/cluster/service/fm) | 28 | [base/cluster/service/fm/sources](../../base/cluster/service/fm/sources), [base/cluster/service/fm/makefile](../../base/cluster/service/fm/makefile) | `fm` | `LIBRARY` |
| [base/cluster/service/gs](../../base/cluster/service/gs) | 16 | [base/cluster/service/gs/sources](../../base/cluster/service/gs/sources), [base/cluster/service/gs/makefile](../../base/cluster/service/gs/makefile) | `gs` | `LIBRARY` |
| [base/cluster/service/gum](../../base/cluster/service/gum) | 11 | [base/cluster/service/gum/sources](../../base/cluster/service/gum/sources), [base/cluster/service/gum/makefile](../../base/cluster/service/gum/makefile) | `gum` | `LIBRARY` |
| [base/cluster/service/idl](../../base/cluster/service/idl) | 9 | [base/cluster/service/idl/sources](../../base/cluster/service/idl/sources), [base/cluster/service/idl/makefile](../../base/cluster/service/idl/makefile) | `idl` | `LIBRARY` |
| [base/cluster/service/inc](../../base/cluster/service/inc) | 19 | — | — | — |
| [base/cluster/service/init](../../base/cluster/service/init) | 13 | [base/cluster/service/init/sources](../../base/cluster/service/init/sources), [base/cluster/service/init/makefile](../../base/cluster/service/init/makefile) | `clussvc` | `PROGRAM` |
| [base/cluster/service/lm](../../base/cluster/service/lm) | 10 | [base/cluster/service/lm/sources](../../base/cluster/service/lm/sources), [base/cluster/service/lm/makefile](../../base/cluster/service/lm/makefile) | `lm` | `LIBRARY` |
| [base/cluster/service/mm](../../base/cluster/service/mm) | 13 | [base/cluster/service/mm/sources](../../base/cluster/service/mm/sources), [base/cluster/service/mm/makefile](../../base/cluster/service/mm/makefile) | `mm` | `LIBRARY` |
| [base/cluster/service/nm](../../base/cluster/service/nm) | 18 | [base/cluster/service/nm/sources](../../base/cluster/service/nm/sources), [base/cluster/service/nm/makefile](../../base/cluster/service/nm/makefile) | `nm` | `LIBRARY` |
| [base/cluster/service/om](../../base/cluster/service/om) | 7 | [base/cluster/service/om/sources](../../base/cluster/service/om/sources), [base/cluster/service/om/makefile](../../base/cluster/service/om/makefile) | `om` | `LIBRARY` |
| [base/cluster/service/vss](../../base/cluster/service/vss) | 4 | [base/cluster/service/vss/sources](../../base/cluster/service/vss/sources), [base/cluster/service/vss/makefile](../../base/cluster/service/vss/makefile) | `VssCluster` | `LIBRARY` |
| [base/cluster/setup](../../base/cluster/setup) | 1 | [base/cluster/setup/dirs](../../base/cluster/setup/dirs) | — | — |
| [base/cluster/setup/cluscfg](../../base/cluster/setup/cluscfg) | 0 | — | — | — |
| [base/cluster/setup/cluscfg/res](../../base/cluster/setup/cluscfg/res) | 2 | — | — | — |
| [base/cluster/setup/cluscomp](../../base/cluster/setup/cluscomp) | 13 | [base/cluster/setup/cluscomp/sources](../../base/cluster/setup/cluscomp/sources), [base/cluster/setup/cluscomp/makefile](../../base/cluster/setup/cluscomp/makefile) | `cluscomp` | `DYNLINK` |
| [base/cluster/setup/cluscomp/res](../../base/cluster/setup/cluscomp/res) | 1 | — | — | — |
| [base/cluster/setup/clusocm](../../base/cluster/setup/clusocm) | 13 | [base/cluster/setup/clusocm/sources](../../base/cluster/setup/clusocm/sources), [base/cluster/setup/clusocm/makefile](../../base/cluster/setup/clusocm/makefile) | `clusocm` | `DYNLINK` |
| [base/cluster/setup/clusocm/res](../../base/cluster/setup/clusocm/res) | 1 | — | — | — |
| [base/cluster/setup/common](../../base/cluster/setup/common) | 19 | [base/cluster/setup/common/sources](../../base/cluster/setup/common/sources), [base/cluster/setup/common/makefile](../../base/cluster/setup/common/makefile) | `SetupCommon` | `LIBRARY` |
| [base/cluster/setup/inc](../../base/cluster/setup/inc) | 1 | — | — | — |
| [base/cluster/test](../../base/cluster/test) | 3 | [base/cluster/test/dirs](../../base/cluster/test/dirs) | — | — |
| [base/cluster/test/bin](../../base/cluster/test/bin) | 2 | [base/cluster/test/bin/sources](../../base/cluster/test/bin/sources), [base/cluster/test/bin/makefile](../../base/cluster/test/bin/makefile) | — | `NOTARGET` |
| [base/cluster/test/bin/i386](../../base/cluster/test/bin/i386) | 4 | — | — | — |
| [base/cluster/test/bugreprt](../../base/cluster/test/bugreprt) | 3 | [base/cluster/test/bugreprt/sources](../../base/cluster/test/bugreprt/sources), [base/cluster/test/bugreprt/makefile](../../base/cluster/test/bugreprt/makefile) | — | `NOTARGET` |
| [base/cluster/test/castest](../../base/cluster/test/castest) | 8 | [base/cluster/test/castest/sources](../../base/cluster/test/castest/sources), [base/cluster/test/castest/makefile](../../base/cluster/test/castest/makefile) | — | `NOTARGET` |
| [base/cluster/test/clusbvt](../../base/cluster/test/clusbvt) | 3 | — | — | — |
| [base/cluster/test/evtview](../../base/cluster/test/evtview) | 46 | [base/cluster/test/evtview/sources](../../base/cluster/test/evtview/sources), [base/cluster/test/evtview/makefile](../../base/cluster/test/evtview/makefile) | `evtview` | `PROGRAM` |
| [base/cluster/test/evtview/res](../../base/cluster/test/evtview/res) | 4 | — | — | — |
| [base/cluster/test/leaks](../../base/cluster/test/leaks) | 6 | [base/cluster/test/leaks/sources](../../base/cluster/test/leaks/sources), [base/cluster/test/leaks/makefile](../../base/cluster/test/leaks/makefile) | `leaks` | `DYNLINK` |
| [base/cluster/test/tstpoint](../../base/cluster/test/tstpoint) | 4 | [base/cluster/test/tstpoint/sources](../../base/cluster/test/tstpoint/sources), [base/cluster/test/tstpoint/makefile](../../base/cluster/test/tstpoint/makefile) | `tstpoint` | `PROGRAM` |
| [base/cluster/timeserv](../../base/cluster/timeserv) | 1 | [base/cluster/timeserv/dirs](../../base/cluster/timeserv/dirs) | — | — |
| [base/cluster/timeserv/inc](../../base/cluster/timeserv/inc) | 5 | — | — | — |
| [base/cluster/timeserv/test](../../base/cluster/timeserv/test) | 4 | [base/cluster/timeserv/test/sources](../../base/cluster/timeserv/test/sources), [base/cluster/timeserv/test/makefile](../../base/cluster/timeserv/test/makefile) | `tsremote` | `LIBRARY` |
| [base/cluster/timeserv/timeserv](../../base/cluster/timeserv/timeserv) | 7 | [base/cluster/timeserv/timeserv/sources](../../base/cluster/timeserv/timeserv/sources), [base/cluster/timeserv/timeserv/makefile](../../base/cluster/timeserv/timeserv/makefile) | `timeserv` | `PROGRAM` |
| [base/cluster/utils](../../base/cluster/utils) | 1 | [base/cluster/utils/dirs](../../base/cluster/utils/dirs) | — | — |
| [base/cluster/utils/clusbrow](../../base/cluster/utils/clusbrow) | 4 | [base/cluster/utils/clusbrow/sources](../../base/cluster/utils/clusbrow/sources), [base/cluster/utils/clusbrow/makefile](../../base/cluster/utils/clusbrow/makefile) | `clusbrow` | `PROGRAM` |
| [base/cluster/utils/cluslog](../../base/cluster/utils/cluslog) | 21 | [base/cluster/utils/cluslog/sources](../../base/cluster/utils/cluslog/sources), [base/cluster/utils/cluslog/makefile](../../base/cluster/utils/cluslog/makefile) | `cluslog` | `PROGRAM` |
| [base/cluster/utils/cluspw](../../base/cluster/utils/cluspw) | 8 | [base/cluster/utils/cluspw/sources](../../base/cluster/utils/cluspw/sources), [base/cluster/utils/cluspw/makefile](../../base/cluster/utils/cluspw/makefile) | `cluspw` | `PROGRAM` |
| [base/cluster/utils/compobj](../../base/cluster/utils/compobj) | 4 | [base/cluster/utils/compobj/sources](../../base/cluster/utils/compobj/sources), [base/cluster/utils/compobj/makefile](../../base/cluster/utils/compobj/makefile) | `compobj` | `PROGRAM` |
| [base/cluster/utils/dsrole](../../base/cluster/utils/dsrole) | 4 | [base/cluster/utils/dsrole/sources](../../base/cluster/utils/dsrole/sources), [base/cluster/utils/dsrole/makefile](../../base/cluster/utils/dsrole/makefile) | `dsrole` | `PROGRAM` |
| [base/cluster/utils/gethname](../../base/cluster/utils/gethname) | 2 | — | — | — |
| [base/cluster/utils/holdrpc](../../base/cluster/utils/holdrpc) | 6 | [base/cluster/utils/holdrpc/sources](../../base/cluster/utils/holdrpc/sources), [base/cluster/utils/holdrpc/makefile](../../base/cluster/utils/holdrpc/makefile) | `cluspw` | `PROGRAM` |
| [base/cluster/utils/ipaddr](../../base/cluster/utils/ipaddr) | 4 | [base/cluster/utils/ipaddr/sources](../../base/cluster/utils/ipaddr/sources), [base/cluster/utils/ipaddr/makefile](../../base/cluster/utils/ipaddr/makefile) | `ipaddr` | `PROGRAM` |
| [base/cluster/utils/whackspn](../../base/cluster/utils/whackspn) | 4 | [base/cluster/utils/whackspn/sources](../../base/cluster/utils/whackspn/sources), [base/cluster/utils/whackspn/makefile](../../base/cluster/utils/whackspn/makefile) | `whackspn` | `PROGRAM` |
| [base/cluster/wmiprovider](../../base/cluster/wmiprovider) | 56 | [base/cluster/wmiprovider/sources](../../base/cluster/wmiprovider/sources), [base/cluster/wmiprovider/makefile](../../base/cluster/wmiprovider/makefile) | `ClusWMI` | `DYNLINK` |
| [base/cluster/wml](../../base/cluster/wml) | 1 | [base/cluster/wml/dirs](../../base/cluster/wml/dirs) | — | — |
| [base/cluster/wml/inc](../../base/cluster/wml/inc) | 5 | — | — | — |
| [base/cluster/wml/km](../../base/cluster/wml/km) | 3 | [base/cluster/wml/km/sources](../../base/cluster/wml/km/sources), [base/cluster/wml/km/makefile](../../base/cluster/wml/km/makefile) | `wmlkm` | `LIBRARY` |
| [base/cluster/wml/um](../../base/cluster/wml/um) | 5 | [base/cluster/wml/um/sources](../../base/cluster/wml/um/sources), [base/cluster/wml/um/makefile](../../base/cluster/wml/um/makefile) | `wmlum` | `DYNLINK` |
| [base/cluster/wml/um/test](../../base/cluster/wml/um/test) | 3 | [base/cluster/wml/um/test/sources](../../base/cluster/wml/um/test/sources), [base/cluster/wml/um/test/makefile](../../base/cluster/wml/um/test/makefile) | `wmltest` | `PROGRAM` |

## `base/cmd/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [base/cmd](../../base/cmd) | 47 | [base/cmd/dirs](../../base/cmd/dirs) | — | — |
| [base/cmd/cmd](../../base/cmd/cmd) | 3 | [base/cmd/cmd/sources](../../base/cmd/cmd/sources), [base/cmd/cmd/makefile](../../base/cmd/cmd/makefile) | `cmd` | — |
| [base/cmd/dos](../../base/cmd/dos) | 5 | [base/cmd/dos/makefile](../../base/cmd/dos/makefile) | — | — |
| [base/cmd/win95](../../base/cmd/win95) | 3 | [base/cmd/win95/sources](../../base/cmd/win95/sources), [base/cmd/win95/makefile](../../base/cmd/win95/makefile) | `win95cmd` | — |

## `base/crts/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [base/crts](../../base/crts) | 23 | [base/crts/dirs](../../base/crts/dirs), [base/crts/makefile](../../base/crts/makefile) | — | — |
| [base/crts/asms](../../base/crts/asms) | 1 | [base/crts/asms/dirs](../../base/crts/asms/dirs) | — | — |
| [base/crts/asms/policy_7.0](../../base/crts/asms/policy_7.0) | 3 | [base/crts/asms/policy_7.0/sources](../../base/crts/asms/policy_7.0/sources), [base/crts/asms/policy_7.0/makefile](../../base/crts/asms/policy_7.0/makefile) | — | `NOTARGET` |
| [base/crts/asms/whistler](../../base/crts/asms/whistler) | 3 | [base/crts/asms/whistler/sources](../../base/crts/asms/whistler/sources), [base/crts/asms/whistler/makefile](../../base/crts/asms/whistler/makefile) | — | `NOTARGET` |
| [base/crts/crtw32](../../base/crts/crtw32) | 3 | [base/crts/crtw32/dirs](../../base/crts/crtw32/dirs) | — | — |
| [base/crts/crtw32/bsku](../../base/crts/crtw32/bsku) | 2 | — | — | — |
| [base/crts/crtw32/convert](../../base/crts/crtw32/convert) | 35 | [base/crts/crtw32/convert/dirs](../../base/crts/crtw32/convert/dirs) | — | — |
| [base/crts/crtw32/convert/dll](../../base/crts/crtw32/convert/dll) | 2 | [base/crts/crtw32/convert/dll/sources](../../base/crts/crtw32/convert/dll/sources), [base/crts/crtw32/convert/dll/makefile](../../base/crts/crtw32/convert/dll/makefile) | — | — |
| [base/crts/crtw32/convert/mt](../../base/crts/crtw32/convert/mt) | 2 | [base/crts/crtw32/convert/mt/sources](../../base/crts/crtw32/convert/mt/sources), [base/crts/crtw32/convert/mt/makefile](../../base/crts/crtw32/convert/mt/makefile) | — | — |
| [base/crts/crtw32/convert/nt](../../base/crts/crtw32/convert/nt) | 2 | [base/crts/crtw32/convert/nt/sources](../../base/crts/crtw32/convert/nt/sources), [base/crts/crtw32/convert/nt/makefile](../../base/crts/crtw32/convert/nt/makefile) | — | — |
| [base/crts/crtw32/convert/psx](../../base/crts/crtw32/convert/psx) | 2 | [base/crts/crtw32/convert/psx/sources](../../base/crts/crtw32/convert/psx/sources), [base/crts/crtw32/convert/psx/makefile](../../base/crts/crtw32/convert/psx/makefile) | — | — |
| [base/crts/crtw32/convert/st](../../base/crts/crtw32/convert/st) | 2 | [base/crts/crtw32/convert/st/sources](../../base/crts/crtw32/convert/st/sources), [base/crts/crtw32/convert/st/makefile](../../base/crts/crtw32/convert/st/makefile) | — | — |
| [base/crts/crtw32/direct](../../base/crts/crtw32/direct) | 13 | [base/crts/crtw32/direct/dirs](../../base/crts/crtw32/direct/dirs) | — | — |
| [base/crts/crtw32/direct/dll](../../base/crts/crtw32/direct/dll) | 2 | [base/crts/crtw32/direct/dll/sources](../../base/crts/crtw32/direct/dll/sources), [base/crts/crtw32/direct/dll/makefile](../../base/crts/crtw32/direct/dll/makefile) | — | — |
| [base/crts/crtw32/direct/i386](../../base/crts/crtw32/direct/i386) | 1 | — | — | — |
| [base/crts/crtw32/direct/mt](../../base/crts/crtw32/direct/mt) | 2 | [base/crts/crtw32/direct/mt/sources](../../base/crts/crtw32/direct/mt/sources), [base/crts/crtw32/direct/mt/makefile](../../base/crts/crtw32/direct/mt/makefile) | — | — |
| [base/crts/crtw32/direct/st](../../base/crts/crtw32/direct/st) | 2 | [base/crts/crtw32/direct/st/sources](../../base/crts/crtw32/direct/st/sources), [base/crts/crtw32/direct/st/makefile](../../base/crts/crtw32/direct/st/makefile) | — | — |
| [base/crts/crtw32/dllstuff](../../base/crts/crtw32/dllstuff) | 24 | [base/crts/crtw32/dllstuff/dirs](../../base/crts/crtw32/dllstuff/dirs) | — | — |
| [base/crts/crtw32/dllstuff/amd64](../../base/crts/crtw32/dllstuff/amd64) | 1 | — | — | — |
| [base/crts/crtw32/dllstuff/dll](../../base/crts/crtw32/dllstuff/dll) | 2 | [base/crts/crtw32/dllstuff/dll/sources](../../base/crts/crtw32/dllstuff/dll/sources), [base/crts/crtw32/dllstuff/dll/makefile](../../base/crts/crtw32/dllstuff/dll/makefile) | — | — |
| [base/crts/crtw32/dllstuff/dll_ios](../../base/crts/crtw32/dllstuff/dll_ios) | 2 | [base/crts/crtw32/dllstuff/dll_ios/sources](../../base/crts/crtw32/dllstuff/dll_ios/sources), [base/crts/crtw32/dllstuff/dll_ios/makefile](../../base/crts/crtw32/dllstuff/dll_ios/makefile) | — | — |
| [base/crts/crtw32/dllstuff/dlllib](../../base/crts/crtw32/dllstuff/dlllib) | 2 | [base/crts/crtw32/dllstuff/dlllib/sources](../../base/crts/crtw32/dllstuff/dlllib/sources), [base/crts/crtw32/dllstuff/dlllib/makefile](../../base/crts/crtw32/dllstuff/dlllib/makefile) | — | — |
| [base/crts/crtw32/dllstuff/i386](../../base/crts/crtw32/dllstuff/i386) | 1 | — | — | — |
| [base/crts/crtw32/dllstuff/ia64](../../base/crts/crtw32/dllstuff/ia64) | 1 | — | — | — |
| [base/crts/crtw32/dos](../../base/crts/crtw32/dos) | 31 | [base/crts/crtw32/dos/dirs](../../base/crts/crtw32/dos/dirs) | — | — |
| [base/crts/crtw32/dos/dll](../../base/crts/crtw32/dos/dll) | 2 | [base/crts/crtw32/dos/dll/sources](../../base/crts/crtw32/dos/dll/sources), [base/crts/crtw32/dos/dll/makefile](../../base/crts/crtw32/dos/dll/makefile) | — | — |
| [base/crts/crtw32/dos/mt](../../base/crts/crtw32/dos/mt) | 2 | [base/crts/crtw32/dos/mt/sources](../../base/crts/crtw32/dos/mt/sources), [base/crts/crtw32/dos/mt/makefile](../../base/crts/crtw32/dos/mt/makefile) | — | — |
| [base/crts/crtw32/dos/st](../../base/crts/crtw32/dos/st) | 2 | [base/crts/crtw32/dos/st/sources](../../base/crts/crtw32/dos/st/sources), [base/crts/crtw32/dos/st/makefile](../../base/crts/crtw32/dos/st/makefile) | — | — |
| [base/crts/crtw32/eh](../../base/crts/crtw32/eh) | 25 | [base/crts/crtw32/eh/dirs](../../base/crts/crtw32/eh/dirs) | — | — |
| [base/crts/crtw32/eh/amd64](../../base/crts/crtw32/eh/amd64) | 3 | — | — | — |
| [base/crts/crtw32/eh/dll](../../base/crts/crtw32/eh/dll) | 2 | [base/crts/crtw32/eh/dll/sources](../../base/crts/crtw32/eh/dll/sources), [base/crts/crtw32/eh/dll/makefile](../../base/crts/crtw32/eh/dll/makefile) | — | — |
| [base/crts/crtw32/eh/dll_ios](../../base/crts/crtw32/eh/dll_ios) | 2 | [base/crts/crtw32/eh/dll_ios/sources](../../base/crts/crtw32/eh/dll_ios/sources), [base/crts/crtw32/eh/dll_ios/makefile](../../base/crts/crtw32/eh/dll_ios/makefile) | — | — |
| [base/crts/crtw32/eh/dlllib](../../base/crts/crtw32/eh/dlllib) | 2 | [base/crts/crtw32/eh/dlllib/sources](../../base/crts/crtw32/eh/dlllib/sources), [base/crts/crtw32/eh/dlllib/makefile](../../base/crts/crtw32/eh/dlllib/makefile) | — | — |
| [base/crts/crtw32/eh/i386](../../base/crts/crtw32/eh/i386) | 5 | — | — | — |
| [base/crts/crtw32/eh/ia64](../../base/crts/crtw32/eh/ia64) | 5 | — | — | — |
| [base/crts/crtw32/eh/mt](../../base/crts/crtw32/eh/mt) | 2 | [base/crts/crtw32/eh/mt/sources](../../base/crts/crtw32/eh/mt/sources), [base/crts/crtw32/eh/mt/makefile](../../base/crts/crtw32/eh/mt/makefile) | — | — |
| [base/crts/crtw32/eh/st](../../base/crts/crtw32/eh/st) | 2 | [base/crts/crtw32/eh/st/sources](../../base/crts/crtw32/eh/st/sources), [base/crts/crtw32/eh/st/makefile](../../base/crts/crtw32/eh/st/makefile) | — | — |
| [base/crts/crtw32/exec](../../base/crts/crtw32/exec) | 46 | [base/crts/crtw32/exec/dirs](../../base/crts/crtw32/exec/dirs) | — | — |
| [base/crts/crtw32/exec/dll](../../base/crts/crtw32/exec/dll) | 2 | [base/crts/crtw32/exec/dll/sources](../../base/crts/crtw32/exec/dll/sources), [base/crts/crtw32/exec/dll/makefile](../../base/crts/crtw32/exec/dll/makefile) | — | — |
| [base/crts/crtw32/exec/mt](../../base/crts/crtw32/exec/mt) | 2 | [base/crts/crtw32/exec/mt/sources](../../base/crts/crtw32/exec/mt/sources), [base/crts/crtw32/exec/mt/makefile](../../base/crts/crtw32/exec/mt/makefile) | — | — |
| [base/crts/crtw32/exec/st](../../base/crts/crtw32/exec/st) | 2 | [base/crts/crtw32/exec/st/sources](../../base/crts/crtw32/exec/st/sources), [base/crts/crtw32/exec/st/makefile](../../base/crts/crtw32/exec/st/makefile) | — | — |
| [base/crts/crtw32/h](../../base/crts/crtw32/h) | 91 | — | — | — |
| [base/crts/crtw32/h/i386](../../base/crts/crtw32/h/i386) | 7 | — | — | — |
| [base/crts/crtw32/h/sys](../../base/crts/crtw32/h/sys) | 5 | — | — | — |
| [base/crts/crtw32/hack](../../base/crts/crtw32/hack) | 4 | [base/crts/crtw32/hack/dirs](../../base/crts/crtw32/hack/dirs) | — | — |
| [base/crts/crtw32/hack/nt](../../base/crts/crtw32/hack/nt) | 2 | [base/crts/crtw32/hack/nt/sources](../../base/crts/crtw32/hack/nt/sources), [base/crts/crtw32/hack/nt/makefile](../../base/crts/crtw32/hack/nt/makefile) | — | — |
| [base/crts/crtw32/heap](../../base/crts/crtw32/heap) | 35 | [base/crts/crtw32/heap/dirs](../../base/crts/crtw32/heap/dirs) | — | — |
| [base/crts/crtw32/heap/dll](../../base/crts/crtw32/heap/dll) | 2 | [base/crts/crtw32/heap/dll/sources](../../base/crts/crtw32/heap/dll/sources), [base/crts/crtw32/heap/dll/makefile](../../base/crts/crtw32/heap/dll/makefile) | — | — |
| [base/crts/crtw32/heap/dlllib](../../base/crts/crtw32/heap/dlllib) | 2 | [base/crts/crtw32/heap/dlllib/sources](../../base/crts/crtw32/heap/dlllib/sources), [base/crts/crtw32/heap/dlllib/makefile](../../base/crts/crtw32/heap/dlllib/makefile) | — | — |
| [base/crts/crtw32/heap/mt](../../base/crts/crtw32/heap/mt) | 2 | [base/crts/crtw32/heap/mt/sources](../../base/crts/crtw32/heap/mt/sources), [base/crts/crtw32/heap/mt/makefile](../../base/crts/crtw32/heap/mt/makefile) | — | — |
| [base/crts/crtw32/heap/psx](../../base/crts/crtw32/heap/psx) | 2 | [base/crts/crtw32/heap/psx/sources](../../base/crts/crtw32/heap/psx/sources), [base/crts/crtw32/heap/psx/makefile](../../base/crts/crtw32/heap/psx/makefile) | — | — |
| [base/crts/crtw32/heap/st](../../base/crts/crtw32/heap/st) | 2 | [base/crts/crtw32/heap/st/sources](../../base/crts/crtw32/heap/st/sources), [base/crts/crtw32/heap/st/makefile](../../base/crts/crtw32/heap/st/makefile) | — | — |
| [base/crts/crtw32/helper](../../base/crts/crtw32/helper) | 4 | [base/crts/crtw32/helper/dirs](../../base/crts/crtw32/helper/dirs) | — | — |
| [base/crts/crtw32/helper/dll](../../base/crts/crtw32/helper/dll) | 2 | [base/crts/crtw32/helper/dll/sources](../../base/crts/crtw32/helper/dll/sources), [base/crts/crtw32/helper/dll/makefile](../../base/crts/crtw32/helper/dll/makefile) | — | — |
| [base/crts/crtw32/helper/dlllib](../../base/crts/crtw32/helper/dlllib) | 2 | [base/crts/crtw32/helper/dlllib/sources](../../base/crts/crtw32/helper/dlllib/sources), [base/crts/crtw32/helper/dlllib/makefile](../../base/crts/crtw32/helper/dlllib/makefile) | — | — |
| [base/crts/crtw32/helper/i386](../../base/crts/crtw32/helper/i386) | 10 | — | — | — |
| [base/crts/crtw32/helper/mt](../../base/crts/crtw32/helper/mt) | 2 | [base/crts/crtw32/helper/mt/sources](../../base/crts/crtw32/helper/mt/sources), [base/crts/crtw32/helper/mt/makefile](../../base/crts/crtw32/helper/mt/makefile) | — | — |
| [base/crts/crtw32/helper/nt](../../base/crts/crtw32/helper/nt) | 3 | [base/crts/crtw32/helper/nt/sources](../../base/crts/crtw32/helper/nt/sources), [base/crts/crtw32/helper/nt/makefile](../../base/crts/crtw32/helper/nt/makefile) | — | — |
| [base/crts/crtw32/helper/psx](../../base/crts/crtw32/helper/psx) | 2 | [base/crts/crtw32/helper/psx/sources](../../base/crts/crtw32/helper/psx/sources), [base/crts/crtw32/helper/psx/makefile](../../base/crts/crtw32/helper/psx/makefile) | — | — |
| [base/crts/crtw32/helper/st](../../base/crts/crtw32/helper/st) | 2 | [base/crts/crtw32/helper/st/sources](../../base/crts/crtw32/helper/st/sources), [base/crts/crtw32/helper/st/makefile](../../base/crts/crtw32/helper/st/makefile) | — | — |
| [base/crts/crtw32/iostream](../../base/crts/crtw32/iostream) | 49 | [base/crts/crtw32/iostream/dirs](../../base/crts/crtw32/iostream/dirs) | — | — |
| [base/crts/crtw32/iostream/dll](../../base/crts/crtw32/iostream/dll) | 4 | [base/crts/crtw32/iostream/dll/sources](../../base/crts/crtw32/iostream/dll/sources), [base/crts/crtw32/iostream/dll/makefile](../../base/crts/crtw32/iostream/dll/makefile) | `msvcirt` | `DYNLINK` |
| [base/crts/crtw32/iostream/mt](../../base/crts/crtw32/iostream/mt) | 2 | [base/crts/crtw32/iostream/mt/sources](../../base/crts/crtw32/iostream/mt/sources), [base/crts/crtw32/iostream/mt/makefile](../../base/crts/crtw32/iostream/mt/makefile) | `libcimt` | — |
| [base/crts/crtw32/iostream/st](../../base/crts/crtw32/iostream/st) | 2 | [base/crts/crtw32/iostream/st/sources](../../base/crts/crtw32/iostream/st/sources), [base/crts/crtw32/iostream/st/makefile](../../base/crts/crtw32/iostream/st/makefile) | `libci` | — |
| [base/crts/crtw32/linkopts](../../base/crts/crtw32/linkopts) | 14 | [base/crts/crtw32/linkopts/sources](../../base/crts/crtw32/linkopts/sources), [base/crts/crtw32/linkopts/makefile](../../base/crts/crtw32/linkopts/makefile) | `linkopts` | — |
| [base/crts/crtw32/lowio](../../base/crts/crtw32/lowio) | 41 | [base/crts/crtw32/lowio/dirs](../../base/crts/crtw32/lowio/dirs) | — | — |
| [base/crts/crtw32/lowio/dll](../../base/crts/crtw32/lowio/dll) | 2 | [base/crts/crtw32/lowio/dll/sources](../../base/crts/crtw32/lowio/dll/sources), [base/crts/crtw32/lowio/dll/makefile](../../base/crts/crtw32/lowio/dll/makefile) | — | — |
| [base/crts/crtw32/lowio/dlllib](../../base/crts/crtw32/lowio/dlllib) | 2 | [base/crts/crtw32/lowio/dlllib/sources](../../base/crts/crtw32/lowio/dlllib/sources), [base/crts/crtw32/lowio/dlllib/makefile](../../base/crts/crtw32/lowio/dlllib/makefile) | — | — |
| [base/crts/crtw32/lowio/i386](../../base/crts/crtw32/lowio/i386) | 2 | — | — | — |
| [base/crts/crtw32/lowio/mt](../../base/crts/crtw32/lowio/mt) | 2 | [base/crts/crtw32/lowio/mt/sources](../../base/crts/crtw32/lowio/mt/sources), [base/crts/crtw32/lowio/mt/makefile](../../base/crts/crtw32/lowio/mt/makefile) | — | — |
| [base/crts/crtw32/lowio/st](../../base/crts/crtw32/lowio/st) | 2 | [base/crts/crtw32/lowio/st/sources](../../base/crts/crtw32/lowio/st/sources), [base/crts/crtw32/lowio/st/makefile](../../base/crts/crtw32/lowio/st/makefile) | — | — |
| [base/crts/crtw32/mbstring](../../base/crts/crtw32/mbstring) | 66 | [base/crts/crtw32/mbstring/dirs](../../base/crts/crtw32/mbstring/dirs) | — | — |
| [base/crts/crtw32/mbstring/dll](../../base/crts/crtw32/mbstring/dll) | 2 | [base/crts/crtw32/mbstring/dll/sources](../../base/crts/crtw32/mbstring/dll/sources), [base/crts/crtw32/mbstring/dll/makefile](../../base/crts/crtw32/mbstring/dll/makefile) | — | — |
| [base/crts/crtw32/mbstring/mt](../../base/crts/crtw32/mbstring/mt) | 2 | [base/crts/crtw32/mbstring/mt/sources](../../base/crts/crtw32/mbstring/mt/sources), [base/crts/crtw32/mbstring/mt/makefile](../../base/crts/crtw32/mbstring/mt/makefile) | — | — |
| [base/crts/crtw32/mbstring/psx](../../base/crts/crtw32/mbstring/psx) | 2 | [base/crts/crtw32/mbstring/psx/sources](../../base/crts/crtw32/mbstring/psx/sources), [base/crts/crtw32/mbstring/psx/makefile](../../base/crts/crtw32/mbstring/psx/makefile) | — | — |
| [base/crts/crtw32/mbstring/st](../../base/crts/crtw32/mbstring/st) | 2 | [base/crts/crtw32/mbstring/st/sources](../../base/crts/crtw32/mbstring/st/sources), [base/crts/crtw32/mbstring/st/makefile](../../base/crts/crtw32/mbstring/st/makefile) | — | — |
| [base/crts/crtw32/misc](../../base/crts/crtw32/misc) | 88 | [base/crts/crtw32/misc/dirs](../../base/crts/crtw32/misc/dirs) | — | — |
| [base/crts/crtw32/misc/amd64](../../base/crts/crtw32/misc/amd64) | 5 | — | — | — |
| [base/crts/crtw32/misc/ddk](../../base/crts/crtw32/misc/ddk) | 2 | [base/crts/crtw32/misc/ddk/sources](../../base/crts/crtw32/misc/ddk/sources), [base/crts/crtw32/misc/ddk/makefile](../../base/crts/crtw32/misc/ddk/makefile) | `sehupd` | `LIBRARY` |
| [base/crts/crtw32/misc/dll](../../base/crts/crtw32/misc/dll) | 2 | [base/crts/crtw32/misc/dll/sources](../../base/crts/crtw32/misc/dll/sources), [base/crts/crtw32/misc/dll/makefile](../../base/crts/crtw32/misc/dll/makefile) | — | — |
| [base/crts/crtw32/misc/dlllib](../../base/crts/crtw32/misc/dlllib) | 2 | [base/crts/crtw32/misc/dlllib/sources](../../base/crts/crtw32/misc/dlllib/sources), [base/crts/crtw32/misc/dlllib/makefile](../../base/crts/crtw32/misc/dlllib/makefile) | — | — |
| [base/crts/crtw32/misc/i386](../../base/crts/crtw32/misc/i386) | 10 | — | — | — |
| [base/crts/crtw32/misc/ia64](../../base/crts/crtw32/misc/ia64) | 7 | — | — | — |
| [base/crts/crtw32/misc/mt](../../base/crts/crtw32/misc/mt) | 2 | [base/crts/crtw32/misc/mt/sources](../../base/crts/crtw32/misc/mt/sources), [base/crts/crtw32/misc/mt/makefile](../../base/crts/crtw32/misc/mt/makefile) | — | — |
| [base/crts/crtw32/misc/nt](../../base/crts/crtw32/misc/nt) | 2 | [base/crts/crtw32/misc/nt/sources](../../base/crts/crtw32/misc/nt/sources), [base/crts/crtw32/misc/nt/makefile](../../base/crts/crtw32/misc/nt/makefile) | — | — |
| [base/crts/crtw32/misc/psx](../../base/crts/crtw32/misc/psx) | 2 | [base/crts/crtw32/misc/psx/sources](../../base/crts/crtw32/misc/psx/sources), [base/crts/crtw32/misc/psx/makefile](../../base/crts/crtw32/misc/psx/makefile) | — | — |
| [base/crts/crtw32/misc/st](../../base/crts/crtw32/misc/st) | 2 | [base/crts/crtw32/misc/st/sources](../../base/crts/crtw32/misc/st/sources), [base/crts/crtw32/misc/st/makefile](../../base/crts/crtw32/misc/st/makefile) | — | — |
| [base/crts/crtw32/rtc](../../base/crts/crtw32/rtc) | 15 | — | — | — |
| [base/crts/crtw32/startup](../../base/crts/crtw32/startup) | 30 | [base/crts/crtw32/startup/dirs](../../base/crts/crtw32/startup/dirs) | — | — |
| [base/crts/crtw32/startup/amd64](../../base/crts/crtw32/startup/amd64) | 1 | — | — | — |
| [base/crts/crtw32/startup/dll](../../base/crts/crtw32/startup/dll) | 3 | [base/crts/crtw32/startup/dll/sources](../../base/crts/crtw32/startup/dll/sources), [base/crts/crtw32/startup/dll/makefile](../../base/crts/crtw32/startup/dll/makefile) | — | — |
| [base/crts/crtw32/startup/dlllib](../../base/crts/crtw32/startup/dlllib) | 3 | [base/crts/crtw32/startup/dlllib/sources](../../base/crts/crtw32/startup/dlllib/sources), [base/crts/crtw32/startup/dlllib/makefile](../../base/crts/crtw32/startup/dlllib/makefile) | — | — |
| [base/crts/crtw32/startup/i386](../../base/crts/crtw32/startup/i386) | 3 | — | — | — |
| [base/crts/crtw32/startup/ia64](../../base/crts/crtw32/startup/ia64) | 2 | — | — | — |
| [base/crts/crtw32/startup/mt](../../base/crts/crtw32/startup/mt) | 3 | [base/crts/crtw32/startup/mt/sources](../../base/crts/crtw32/startup/mt/sources), [base/crts/crtw32/startup/mt/makefile](../../base/crts/crtw32/startup/mt/makefile) | — | — |
| [base/crts/crtw32/startup/nt](../../base/crts/crtw32/startup/nt) | 3 | [base/crts/crtw32/startup/nt/sources](../../base/crts/crtw32/startup/nt/sources), [base/crts/crtw32/startup/nt/makefile](../../base/crts/crtw32/startup/nt/makefile) | — | — |
| [base/crts/crtw32/startup/psx](../../base/crts/crtw32/startup/psx) | 3 | [base/crts/crtw32/startup/psx/sources](../../base/crts/crtw32/startup/psx/sources), [base/crts/crtw32/startup/psx/makefile](../../base/crts/crtw32/startup/psx/makefile) | — | — |
| [base/crts/crtw32/startup/st](../../base/crts/crtw32/startup/st) | 3 | [base/crts/crtw32/startup/st/sources](../../base/crts/crtw32/startup/st/sources), [base/crts/crtw32/startup/st/makefile](../../base/crts/crtw32/startup/st/makefile) | — | — |
| [base/crts/crtw32/stdcpp](../../base/crts/crtw32/stdcpp) | 92 | [base/crts/crtw32/stdcpp/dirs](../../base/crts/crtw32/stdcpp/dirs) | — | — |
| [base/crts/crtw32/stdcpp/stp](../../base/crts/crtw32/stdcpp/stp) | 2 | [base/crts/crtw32/stdcpp/stp/sources](../../base/crts/crtw32/stdcpp/stp/sources), [base/crts/crtw32/stdcpp/stp/makefile](../../base/crts/crtw32/stdcpp/stp/makefile) | — | — |
| [base/crts/crtw32/stdcpp64](../../base/crts/crtw32/stdcpp64) | 61 | [base/crts/crtw32/stdcpp64/dirs](../../base/crts/crtw32/stdcpp64/dirs) | — | — |
| [base/crts/crtw32/stdhpp](../../base/crts/crtw32/stdhpp) | 75 | — | — | — |
| [base/crts/crtw32/stdhpp64](../../base/crts/crtw32/stdhpp64) | 70 | — | — | — |
| [base/crts/crtw32/stdio](../../base/crts/crtw32/stdio) | 103 | [base/crts/crtw32/stdio/dirs](../../base/crts/crtw32/stdio/dirs) | — | — |
| [base/crts/crtw32/stdio/dll](../../base/crts/crtw32/stdio/dll) | 3 | [base/crts/crtw32/stdio/dll/sources](../../base/crts/crtw32/stdio/dll/sources), [base/crts/crtw32/stdio/dll/makefile](../../base/crts/crtw32/stdio/dll/makefile) | — | — |
| [base/crts/crtw32/stdio/dlllib](../../base/crts/crtw32/stdio/dlllib) | 3 | [base/crts/crtw32/stdio/dlllib/sources](../../base/crts/crtw32/stdio/dlllib/sources), [base/crts/crtw32/stdio/dlllib/makefile](../../base/crts/crtw32/stdio/dlllib/makefile) | — | — |
| [base/crts/crtw32/stdio/mt](../../base/crts/crtw32/stdio/mt) | 3 | [base/crts/crtw32/stdio/mt/sources](../../base/crts/crtw32/stdio/mt/sources), [base/crts/crtw32/stdio/mt/makefile](../../base/crts/crtw32/stdio/mt/makefile) | — | — |
| [base/crts/crtw32/stdio/nt](../../base/crts/crtw32/stdio/nt) | 3 | [base/crts/crtw32/stdio/nt/sources](../../base/crts/crtw32/stdio/nt/sources), [base/crts/crtw32/stdio/nt/makefile](../../base/crts/crtw32/stdio/nt/makefile) | — | — |
| [base/crts/crtw32/stdio/psx](../../base/crts/crtw32/stdio/psx) | 3 | [base/crts/crtw32/stdio/psx/sources](../../base/crts/crtw32/stdio/psx/sources), [base/crts/crtw32/stdio/psx/makefile](../../base/crts/crtw32/stdio/psx/makefile) | — | — |
| [base/crts/crtw32/stdio/st](../../base/crts/crtw32/stdio/st) | 3 | [base/crts/crtw32/stdio/st/sources](../../base/crts/crtw32/stdio/st/sources), [base/crts/crtw32/stdio/st/makefile](../../base/crts/crtw32/stdio/st/makefile) | — | — |
| [base/crts/crtw32/string](../../base/crts/crtw32/string) | 63 | [base/crts/crtw32/string/dirs](../../base/crts/crtw32/string/dirs) | — | — |
| [base/crts/crtw32/string/dll](../../base/crts/crtw32/string/dll) | 3 | [base/crts/crtw32/string/dll/sources](../../base/crts/crtw32/string/dll/sources), [base/crts/crtw32/string/dll/makefile](../../base/crts/crtw32/string/dll/makefile) | — | — |
| [base/crts/crtw32/string/i386](../../base/crts/crtw32/string/i386) | 24 | — | — | — |
| [base/crts/crtw32/string/ia64](../../base/crts/crtw32/string/ia64) | 7 | — | — | — |
| [base/crts/crtw32/string/mt](../../base/crts/crtw32/string/mt) | 3 | [base/crts/crtw32/string/mt/sources](../../base/crts/crtw32/string/mt/sources), [base/crts/crtw32/string/mt/makefile](../../base/crts/crtw32/string/mt/makefile) | — | — |
| [base/crts/crtw32/string/nt](../../base/crts/crtw32/string/nt) | 3 | [base/crts/crtw32/string/nt/sources](../../base/crts/crtw32/string/nt/sources), [base/crts/crtw32/string/nt/makefile](../../base/crts/crtw32/string/nt/makefile) | — | — |
| [base/crts/crtw32/string/psx](../../base/crts/crtw32/string/psx) | 3 | [base/crts/crtw32/string/psx/sources](../../base/crts/crtw32/string/psx/sources), [base/crts/crtw32/string/psx/makefile](../../base/crts/crtw32/string/psx/makefile) | — | — |
| [base/crts/crtw32/string/st](../../base/crts/crtw32/string/st) | 3 | [base/crts/crtw32/string/st/sources](../../base/crts/crtw32/string/st/sources), [base/crts/crtw32/string/st/makefile](../../base/crts/crtw32/string/st/makefile) | — | — |
| [base/crts/crtw32/time](../../base/crts/crtw32/time) | 37 | [base/crts/crtw32/time/dirs](../../base/crts/crtw32/time/dirs) | — | — |
| [base/crts/crtw32/time/dll](../../base/crts/crtw32/time/dll) | 2 | [base/crts/crtw32/time/dll/sources](../../base/crts/crtw32/time/dll/sources), [base/crts/crtw32/time/dll/makefile](../../base/crts/crtw32/time/dll/makefile) | — | — |
| [base/crts/crtw32/time/mt](../../base/crts/crtw32/time/mt) | 2 | [base/crts/crtw32/time/mt/sources](../../base/crts/crtw32/time/mt/sources), [base/crts/crtw32/time/mt/makefile](../../base/crts/crtw32/time/mt/makefile) | — | — |
| [base/crts/crtw32/time/psx](../../base/crts/crtw32/time/psx) | 2 | [base/crts/crtw32/time/psx/sources](../../base/crts/crtw32/time/psx/sources), [base/crts/crtw32/time/psx/makefile](../../base/crts/crtw32/time/psx/makefile) | — | — |
| [base/crts/crtw32/time/st](../../base/crts/crtw32/time/st) | 2 | [base/crts/crtw32/time/st/sources](../../base/crts/crtw32/time/st/sources), [base/crts/crtw32/time/st/makefile](../../base/crts/crtw32/time/st/makefile) | — | — |
| [base/crts/crtw32/tools](../../base/crts/crtw32/tools) | 5 | — | — | — |
| [base/crts/crtw32/tools/win32](../../base/crts/crtw32/tools/win32) | 8 | — | — | — |
| [base/crts/doc](../../base/crts/doc) | 6 | — | — | — |
| [base/crts/doc/pjp](../../base/crts/doc/pjp) | 11 | [base/crts/doc/pjp/makefile](../../base/crts/doc/pjp/makefile) | — | — |
| [base/crts/fpw32](../../base/crts/fpw32) | 3 | [base/crts/fpw32/dirs](../../base/crts/fpw32/dirs) | — | — |
| [base/crts/fpw32/conv](../../base/crts/fpw32/conv) | 15 | [base/crts/fpw32/conv/dirs](../../base/crts/fpw32/conv/dirs) | — | — |
| [base/crts/fpw32/conv/dll](../../base/crts/fpw32/conv/dll) | 2 | [base/crts/fpw32/conv/dll/sources](../../base/crts/fpw32/conv/dll/sources), [base/crts/fpw32/conv/dll/makefile](../../base/crts/fpw32/conv/dll/makefile) | — | — |
| [base/crts/fpw32/conv/mt](../../base/crts/fpw32/conv/mt) | 2 | [base/crts/fpw32/conv/mt/sources](../../base/crts/fpw32/conv/mt/sources), [base/crts/fpw32/conv/mt/makefile](../../base/crts/fpw32/conv/mt/makefile) | — | — |
| [base/crts/fpw32/conv/psx](../../base/crts/fpw32/conv/psx) | 2 | [base/crts/fpw32/conv/psx/sources](../../base/crts/fpw32/conv/psx/sources), [base/crts/fpw32/conv/psx/makefile](../../base/crts/fpw32/conv/psx/makefile) | — | — |
| [base/crts/fpw32/conv/st](../../base/crts/fpw32/conv/st) | 2 | [base/crts/fpw32/conv/st/sources](../../base/crts/fpw32/conv/st/sources), [base/crts/fpw32/conv/st/makefile](../../base/crts/fpw32/conv/st/makefile) | — | — |
| [base/crts/fpw32/inc](../../base/crts/fpw32/inc) | 0 | — | — | — |
| [base/crts/fpw32/inc/i386](../../base/crts/fpw32/inc/i386) | 10 | — | — | — |
| [base/crts/fpw32/include](../../base/crts/fpw32/include) | 3 | — | — | — |
| [base/crts/fpw32/tran](../../base/crts/fpw32/tran) | 27 | [base/crts/fpw32/tran/dirs](../../base/crts/fpw32/tran/dirs) | — | — |
| [base/crts/fpw32/tran/amd64](../../base/crts/fpw32/tran/amd64) | 4 | — | — | — |
| [base/crts/fpw32/tran/dll](../../base/crts/fpw32/tran/dll) | 2 | [base/crts/fpw32/tran/dll/sources](../../base/crts/fpw32/tran/dll/sources), [base/crts/fpw32/tran/dll/makefile](../../base/crts/fpw32/tran/dll/makefile) | — | — |
| [base/crts/fpw32/tran/i386](../../base/crts/fpw32/tran/i386) | 61 | — | — | — |
| [base/crts/fpw32/tran/ia64](../../base/crts/fpw32/tran/ia64) | 70 | — | — | — |
| [base/crts/fpw32/tran/mt](../../base/crts/fpw32/tran/mt) | 2 | [base/crts/fpw32/tran/mt/sources](../../base/crts/fpw32/tran/mt/sources), [base/crts/fpw32/tran/mt/makefile](../../base/crts/fpw32/tran/mt/makefile) | — | — |
| [base/crts/fpw32/tran/nt](../../base/crts/fpw32/tran/nt) | 2 | [base/crts/fpw32/tran/nt/sources](../../base/crts/fpw32/tran/nt/sources), [base/crts/fpw32/tran/nt/makefile](../../base/crts/fpw32/tran/nt/makefile) | — | — |
| [base/crts/fpw32/tran/psx](../../base/crts/fpw32/tran/psx) | 2 | [base/crts/fpw32/tran/psx/sources](../../base/crts/fpw32/tran/psx/sources), [base/crts/fpw32/tran/psx/makefile](../../base/crts/fpw32/tran/psx/makefile) | — | — |
| [base/crts/fpw32/tran/st](../../base/crts/fpw32/tran/st) | 2 | [base/crts/fpw32/tran/st/sources](../../base/crts/fpw32/tran/st/sources), [base/crts/fpw32/tran/st/makefile](../../base/crts/fpw32/tran/st/makefile) | — | — |
| [base/crts/langapi](../../base/crts/langapi) | 0 | — | — | — |
| [base/crts/langapi/include](../../base/crts/langapi/include) | 3 | — | — | — |
| [base/crts/langapi/undname](../../base/crts/langapi/undname) | 4 | — | — | — |
| [base/crts/libw32](../../base/crts/libw32) | 22 | [base/crts/libw32/dirs](../../base/crts/libw32/dirs) | — | — |
| [base/crts/libw32/inc64](../../base/crts/libw32/inc64) | 121 | — | — | — |
| [base/crts/libw32/inc64/sys](../../base/crts/libw32/inc64/sys) | 5 | — | — | — |
| [base/crts/libw32/include](../../base/crts/libw32/include) | 133 | — | — | — |
| [base/crts/libw32/include/sys](../../base/crts/libw32/include/sys) | 5 | — | — | — |
| [base/crts/libw32/lib](../../base/crts/libw32/lib) | 2 | [base/crts/libw32/lib/dirs](../../base/crts/libw32/lib/dirs) | — | — |
| [base/crts/libw32/lib/dll](../../base/crts/libw32/lib/dll) | 4 | [base/crts/libw32/lib/dll/sources](../../base/crts/libw32/lib/dll/sources), [base/crts/libw32/lib/dll/makefile](../../base/crts/libw32/lib/dll/makefile) | — | `DYNLINK` |
| [base/crts/libw32/lib/dll40](../../base/crts/libw32/lib/dll40) | 4 | [base/crts/libw32/lib/dll40/sources](../../base/crts/libw32/lib/dll40/sources), [base/crts/libw32/lib/dll40/makefile](../../base/crts/libw32/lib/dll40/makefile) | `msvcrt40` | `DYNLINK` |
| [base/crts/libw32/lib/dlllib](../../base/crts/libw32/lib/dlllib) | 2 | [base/crts/libw32/lib/dlllib/sources](../../base/crts/libw32/lib/dlllib/sources), [base/crts/libw32/lib/dlllib/makefile](../../base/crts/libw32/lib/dlllib/makefile) | — | — |
| [base/crts/libw32/lib/exsup](../../base/crts/libw32/lib/exsup) | 2 | [base/crts/libw32/lib/exsup/sources](../../base/crts/libw32/lib/exsup/sources), [base/crts/libw32/lib/exsup/makefile](../../base/crts/libw32/lib/exsup/makefile) | — | — |
| [base/crts/libw32/lib/mt](../../base/crts/libw32/lib/mt) | 2 | [base/crts/libw32/lib/mt/sources](../../base/crts/libw32/lib/mt/sources), [base/crts/libw32/lib/mt/makefile](../../base/crts/libw32/lib/mt/makefile) | — | — |
| [base/crts/libw32/lib/nt](../../base/crts/libw32/lib/nt) | 2 | [base/crts/libw32/lib/nt/sources](../../base/crts/libw32/lib/nt/sources), [base/crts/libw32/lib/nt/makefile](../../base/crts/libw32/lib/nt/makefile) | — | — |
| [base/crts/libw32/lib/nt/ia64](../../base/crts/libw32/lib/nt/ia64) | 1 | — | — | — |
| [base/crts/libw32/lib/posix](../../base/crts/libw32/lib/posix) | 2 | [base/crts/libw32/lib/posix/sources](../../base/crts/libw32/lib/posix/sources), [base/crts/libw32/lib/posix/makefile](../../base/crts/libw32/lib/posix/makefile) | — | — |
| [base/crts/libw32/lib/st](../../base/crts/libw32/lib/st) | 2 | [base/crts/libw32/lib/st/sources](../../base/crts/libw32/lib/st/sources), [base/crts/libw32/lib/st/makefile](../../base/crts/libw32/lib/st/makefile) | — | — |
| [base/crts/libw32/lib/stp](../../base/crts/libw32/lib/stp) | 2 | [base/crts/libw32/lib/stp/sources](../../base/crts/libw32/lib/stp/sources), [base/crts/libw32/lib/stp/makefile](../../base/crts/libw32/lib/stp/makefile) | — | — |
| [base/crts/libw32/oldnames](../../base/crts/libw32/oldnames) | 1 | — | — | — |
| [base/crts/libw32/tools](../../base/crts/libw32/tools) | 0 | — | — | — |
| [base/crts/libw32/tools/i386](../../base/crts/libw32/tools/i386) | 8 | — | — | — |
| [base/crts/libw32/tools/ia64](../../base/crts/libw32/tools/ia64) | 8 | — | — | — |
| [base/crts/libw32/tools/source](../../base/crts/libw32/tools/source) | 6 | — | — | — |
| [base/crts/libw32/tools/source/ifstrip](../../base/crts/libw32/tools/source/ifstrip) | 7 | — | — | — |
| [base/crts/libw32/tools/source/striphdr](../../base/crts/libw32/tools/source/striphdr) | 1 | — | — | — |
| [base/crts/srcrel](../../base/crts/srcrel) | 24 | [base/crts/srcrel/makefile](../../base/crts/srcrel/makefile) | — | — |

## `base/ddk/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [base/ddk](../../base/ddk) | 7 | [base/ddk/sources](../../base/ddk/sources), [base/ddk/makefile](../../base/ddk/makefile) | — | `NOTARGET` |

## `base/dload/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [base/dload](../../base/dload) | 14 | [base/dload/sources](../../base/dload/sources), [base/dload/makefile](../../base/dload/makefile) | `dloadbase` | `LIBRARY` |

## `base/dloadhandler/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [base/dloadhandler](../../base/dloadhandler) | 3 | [base/dloadhandler/sources](../../base/dloadhandler/sources), [base/dloadhandler/makefile](../../base/dloadhandler/makefile) | — | `NOTARGET` |

## `base/efiutil/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [base/efiutil](../../base/efiutil) | 3 | [base/efiutil/dirs](../../base/efiutil/dirs) | — | — |
| [base/efiutil/bins](../../base/efiutil/bins) | 2 | [base/efiutil/bins/sources](../../base/efiutil/bins/sources), [base/efiutil/bins/makefile](../../base/efiutil/bins/makefile) | — | `NOTARGET` |
| [base/efiutil/bins/ia64](../../base/efiutil/bins/ia64) | 12 | — | — | — |
| [base/efiutil/cdboot](../../base/efiutil/cdboot) | 5 | [base/efiutil/cdboot/sources](../../base/efiutil/cdboot/sources), [base/efiutil/cdboot/makefile](../../base/efiutil/cdboot/makefile) | `cdboot` | `LIBRARY` |
| [base/efiutil/cpuid](../../base/efiutil/cpuid) | 4 | [base/efiutil/cpuid/sources](../../base/efiutil/cpuid/sources), [base/efiutil/cpuid/makefile](../../base/efiutil/cpuid/makefile) | `cpuid` | `LIBRARY` |
| [base/efiutil/diskpart](../../base/efiutil/diskpart) | 22 | [base/efiutil/diskpart/sources](../../base/efiutil/diskpart/sources), [base/efiutil/diskpart/makefile](../../base/efiutil/diskpart/makefile) | `diskpart` | `LIBRARY` |
| [base/efiutil/efichk](../../base/efiutil/efichk) | 4 | [base/efiutil/efichk/dirs](../../base/efiutil/efichk/dirs) | — | — |
| [base/efiutil/efichk/usa](../../base/efiutil/efichk/usa) | 3 | [base/efiutil/efichk/usa/sources](../../base/efiutil/efichk/usa/sources), [base/efiutil/efichk/usa/makefile](../../base/efiutil/efichk/usa/makefile) | — | — |
| [base/efiutil/efifmt](../../base/efiutil/efifmt) | 4 | [base/efiutil/efifmt/dirs](../../base/efiutil/efifmt/dirs) | — | — |
| [base/efiutil/efifmt/usa](../../base/efiutil/efifmt/usa) | 3 | [base/efiutil/efifmt/usa/sources](../../base/efiutil/efifmt/usa/sources), [base/efiutil/efifmt/usa/makefile](../../base/efiutil/efifmt/usa/makefile) | — | — |
| [base/efiutil/efilib](../../base/efiutil/efilib) | 1 | [base/efiutil/efilib/dirs](../../base/efiutil/efilib/dirs) | — | — |
| [base/efiutil/efilib/efiinc](../../base/efiutil/efilib/efiinc) | 7 | — | — | — |
| [base/efiutil/efilib/efisrc](../../base/efiutil/efilib/efisrc) | 14 | — | — | — |
| [base/efiutil/efilib/inc](../../base/efiutil/efilib/inc) | 56 | — | — | — |
| [base/efiutil/efilib/src](../../base/efiutil/efilib/src) | 4 | [base/efiutil/efilib/src/dirs](../../base/efiutil/efilib/src/dirs) | — | — |
| [base/efiutil/efilib/src/usa](../../base/efiutil/efilib/src/usa) | 44 | [base/efiutil/efilib/src/usa/sources](../../base/efiutil/efilib/src/usa/sources), [base/efiutil/efilib/src/usa/makefile](../../base/efiutil/efilib/src/usa/makefile) | — | — |
| [base/efiutil/efintldr](../../base/efiutil/efintldr) | 10 | [base/efiutil/efintldr/sources](../../base/efiutil/efintldr/sources), [base/efiutil/efintldr/makefile](../../base/efiutil/efintldr/makefile) | `efintldr` | `LIBRARY` |
| [base/efiutil/efinvram](../../base/efiutil/efinvram) | 16 | [base/efiutil/efinvram/sources](../../base/efiutil/efinvram/sources), [base/efiutil/efinvram/makefile](../../base/efiutil/efinvram/makefile) | `nvrboot` | `LIBRARY` |
| [base/efiutil/hello](../../base/efiutil/hello) | 4 | [base/efiutil/hello/sources](../../base/efiutil/hello/sources), [base/efiutil/hello/makefile](../../base/efiutil/hello/makefile) | `hello` | `LIBRARY` |
| [base/efiutil/launcher](../../base/efiutil/launcher) | 5 | [base/efiutil/launcher/sources](../../base/efiutil/launcher/sources), [base/efiutil/launcher/makefile](../../base/efiutil/launcher/makefile) | `launcher` | `LIBRARY` |
| [base/efiutil/sdk](../../base/efiutil/sdk) | 1 | — | — | — |
| [base/efiutil/sdk/build](../../base/efiutil/sdk/build) | 1 | — | — | — |
| [base/efiutil/sdk/build/bios32](../../base/efiutil/sdk/build/bios32) | 5 | [base/efiutil/sdk/build/bios32/makefile](../../base/efiutil/sdk/build/bios32/makefile) | — | — |
| [base/efiutil/sdk/build/ia-32emb](../../base/efiutil/sdk/build/ia-32emb) | 4 | [base/efiutil/sdk/build/ia-32emb/makefile](../../base/efiutil/sdk/build/ia-32emb/makefile) | — | — |
| [base/efiutil/sdk/build/sal64](../../base/efiutil/sdk/build/sal64) | 6 | [base/efiutil/sdk/build/sal64/makefile](../../base/efiutil/sdk/build/sal64/makefile) | — | — |
| [base/efiutil/sdk/build/tools](../../base/efiutil/sdk/build/tools) | 0 | — | — | — |
| [base/efiutil/sdk/build/tools/bin](../../base/efiutil/sdk/build/tools/bin) | 8 | — | — | — |
| [base/efiutil/sdk/build/tools/src](../../base/efiutil/sdk/build/tools/src) | 1 | [base/efiutil/sdk/build/tools/src/makefile](../../base/efiutil/sdk/build/tools/src/makefile) | — | — |
| [base/efiutil/sdk/build/tools/src/adpatch](../../base/efiutil/sdk/build/tools/src/adpatch) | 1 | — | — | — |
| [base/efiutil/sdk/build/tools/src/col](../../base/efiutil/sdk/build/tools/src/col) | 1 | — | — | — |
| [base/efiutil/sdk/build/tools/src/cribi](../../base/efiutil/sdk/build/tools/src/cribi) | 1 | — | — | — |
| [base/efiutil/sdk/build/tools/src/efildrimage](../../base/efiutil/sdk/build/tools/src/efildrimage) | 1 | — | — | — |
| [base/efiutil/sdk/build/tools/src/fwimage](../../base/efiutil/sdk/build/tools/src/fwimage) | 1 | — | — | — |
| [base/efiutil/sdk/build/tools/src/genmake](../../base/efiutil/sdk/build/tools/src/genmake) | 1 | — | — | — |
| [base/efiutil/sdk/build/tools/src/splitfile](../../base/efiutil/sdk/build/tools/src/splitfile) | 2 | — | — | — |
| [base/efiutil/sdk/inc](../../base/efiutil/sdk/inc) | 22 | — | — | — |
| [base/efiutil/sdk/inc/ia32](../../base/efiutil/sdk/inc/ia32) | 3 | — | — | — |
| [base/efiutil/sdk/inc/ia64](../../base/efiutil/sdk/inc/ia64) | 4 | — | — | — |
| [base/efiutil/sdk/inc/protocol](../../base/efiutil/sdk/inc/protocol) | 8 | — | — | — |
| [base/efiutil/sdk/lib](../../base/efiutil/sdk/lib) | 19 | — | — | — |
| [base/efiutil/sdk/lib/ia32](../../base/efiutil/sdk/lib/ia32) | 2 | — | — | — |
| [base/efiutil/sdk/lib/ia64](../../base/efiutil/sdk/lib/ia64) | 5 | — | — | — |
| [base/efiutil/sdk/lib/runtime](../../base/efiutil/sdk/lib/runtime) | 5 | — | — | — |
| [base/efiutil/sdk/notes](../../base/efiutil/sdk/notes) | 5 | — | — | — |
| [base/efiutil/sdk/notes/samples](../../base/efiutil/sdk/notes/samples) | 0 | — | — | — |
| [base/efiutil/sdk/notes/samples/apps](../../base/efiutil/sdk/notes/samples/apps) | 0 | — | — | — |
| [base/efiutil/sdk/notes/samples/apps/hello](../../base/efiutil/sdk/notes/samples/apps/hello) | 2 | — | — | — |
| [base/efiutil/sdk/notes/samples/apps/hellolib](../../base/efiutil/sdk/notes/samples/apps/hellolib) | 2 | — | — | — |
| [base/efiutil/sdk/notes/samples/shell](../../base/efiutil/sdk/notes/samples/shell) | 0 | — | — | — |
| [base/efiutil/sdk/notes/samples/shell/etestcmd](../../base/efiutil/sdk/notes/samples/shell/etestcmd) | 2 | — | — | — |
| [base/efiutil/sdk/notes/samples/shell/itestcmd](../../base/efiutil/sdk/notes/samples/shell/itestcmd) | 2 | — | — | — |
| [base/efiutil/sdk/shell](../../base/efiutil/sdk/shell) | 1 | — | — | — |
| [base/efiutil/sdk/shell/attrib](../../base/efiutil/sdk/shell/attrib) | 4 | — | — | — |
| [base/efiutil/sdk/shell/bcfg](../../base/efiutil/sdk/shell/bcfg) | 4 | — | — | — |
| [base/efiutil/sdk/shell/cls](../../base/efiutil/sdk/shell/cls) | 4 | — | — | — |
| [base/efiutil/sdk/shell/comp](../../base/efiutil/sdk/shell/comp) | 4 | — | — | — |
| [base/efiutil/sdk/shell/cp](../../base/efiutil/sdk/shell/cp) | 4 | — | — | — |
| [base/efiutil/sdk/shell/date](../../base/efiutil/sdk/shell/date) | 4 | — | — | — |
| [base/efiutil/sdk/shell/debug](../../base/efiutil/sdk/shell/debug) | 6 | — | — | — |
| [base/efiutil/sdk/shell/dmpstore](../../base/efiutil/sdk/shell/dmpstore) | 4 | — | — | — |
| [base/efiutil/sdk/shell/echo](../../base/efiutil/sdk/shell/echo) | 2 | — | — | — |
| [base/efiutil/sdk/shell/edit](../../base/efiutil/sdk/shell/edit) | 14 | — | — | — |
| [base/efiutil/sdk/shell/err](../../base/efiutil/sdk/shell/err) | 4 | — | — | — |
| [base/efiutil/sdk/shell/getmtc](../../base/efiutil/sdk/shell/getmtc) | 4 | — | — | — |
| [base/efiutil/sdk/shell/hexedit](../../base/efiutil/sdk/shell/hexedit) | 18 | — | — | — |
| [base/efiutil/sdk/shell/inc](../../base/efiutil/sdk/shell/inc) | 4 | — | — | — |
| [base/efiutil/sdk/shell/iomod](../../base/efiutil/sdk/shell/iomod) | 4 | — | — | — |
| [base/efiutil/sdk/shell/lib](../../base/efiutil/sdk/shell/lib) | 7 | — | — | — |
| [base/efiutil/sdk/shell/load](../../base/efiutil/sdk/shell/load) | 4 | — | — | — |
| [base/efiutil/sdk/shell/ls](../../base/efiutil/sdk/shell/ls) | 4 | — | — | — |
| [base/efiutil/sdk/shell/mem](../../base/efiutil/sdk/shell/mem) | 4 | — | — | — |
| [base/efiutil/sdk/shell/memmap](../../base/efiutil/sdk/shell/memmap) | 4 | — | — | — |
| [base/efiutil/sdk/shell/mkdir](../../base/efiutil/sdk/shell/mkdir) | 4 | — | — | — |
| [base/efiutil/sdk/shell/mode](../../base/efiutil/sdk/shell/mode) | 4 | — | — | — |
| [base/efiutil/sdk/shell/mv](../../base/efiutil/sdk/shell/mv) | 4 | — | — | — |
| [base/efiutil/sdk/shell/newshell](../../base/efiutil/sdk/shell/newshell) | 5 | — | — | — |
| [base/efiutil/sdk/shell/pci](../../base/efiutil/sdk/shell/pci) | 4 | — | — | — |
| [base/efiutil/sdk/shell/reset](../../base/efiutil/sdk/shell/reset) | 4 | — | — | — |
| [base/efiutil/sdk/shell/rm](../../base/efiutil/sdk/shell/rm) | 4 | — | — | — |
| [base/efiutil/sdk/shell/setsize](../../base/efiutil/sdk/shell/setsize) | 4 | — | — | — |
| [base/efiutil/sdk/shell/shellenv](../../base/efiutil/sdk/shell/shellenv) | 25 | — | — | — |
| [base/efiutil/sdk/shell/stall](../../base/efiutil/sdk/shell/stall) | 4 | — | — | — |
| [base/efiutil/sdk/shell/time](../../base/efiutil/sdk/shell/time) | 4 | — | — | — |
| [base/efiutil/sdk/shell/touch](../../base/efiutil/sdk/shell/touch) | 4 | — | — | — |
| [base/efiutil/sdk/shell/type](../../base/efiutil/sdk/shell/type) | 4 | — | — | — |
| [base/efiutil/sdk/shell/ver](../../base/efiutil/sdk/shell/ver) | 5 | — | — | — |
| [base/efiutil/sdk/shell/ver/ia32](../../base/efiutil/sdk/shell/ver/ia32) | 1 | — | — | — |
| [base/efiutil/sdk/shell/ver/ia64](../../base/efiutil/sdk/shell/ver/ia64) | 1 | — | — | — |
| [base/efiutil/sdk/shell/vol](../../base/efiutil/sdk/shell/vol) | 4 | — | — | — |

## `base/eventlog/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [base/eventlog](../../base/eventlog) | 9 | [base/eventlog/dirs](../../base/eventlog/dirs) | — | — |
| [base/eventlog/elfclnt](../../base/eventlog/elfclnt) | 6 | [base/eventlog/elfclnt/sources](../../base/eventlog/elfclnt/sources), [base/eventlog/elfclnt/makefile](../../base/eventlog/elfclnt/makefile) | `elfapi` | `LIBRARY` |
| [base/eventlog/eltest](../../base/eventlog/eltest) | 3 | [base/eventlog/eltest/sources](../../base/eventlog/eltest/sources), [base/eventlog/eltest/makefile](../../base/eventlog/eltest/makefile) | `eltest` | `PROGRAM` |
| [base/eventlog/ntsdexts](../../base/eventlog/ntsdexts) | 5 | [base/eventlog/ntsdexts/sources](../../base/eventlog/ntsdexts/sources), [base/eventlog/ntsdexts/makefile](../../base/eventlog/ntsdexts/makefile) | `elfexts` | `DYNLINK` |
| [base/eventlog/server](../../base/eventlog/server) | 28 | [base/eventlog/server/sources](../../base/eventlog/server/sources), [base/eventlog/server/makefile](../../base/eventlog/server/makefile) | `eventlog` | `DYNLINK` |
| [base/eventlog/test](../../base/eventlog/test) | 6 | [base/eventlog/test/sources](../../base/eventlog/test/sources), [base/eventlog/test/makefile](../../base/eventlog/test/makefile) | `elftest` | `PROGRAM` |

## `base/firmware/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [base/firmware](../../base/firmware) | 1 | [base/firmware/dirs](../../base/firmware/dirs) | — | — |
| [base/firmware/efi](../../base/firmware/efi) | 2 | [base/firmware/efi/sources](../../base/firmware/efi/sources), [base/firmware/efi/makefile](../../base/firmware/efi/makefile) | — | `NOTARGET` |
| [base/firmware/efi/ia64](../../base/firmware/efi/ia64) | 0 | — | — | — |
| [base/firmware/efi/ia64/debug](../../base/firmware/efi/ia64/debug) | 2 | — | — | — |
| [base/firmware/efi/ia64/retail](../../base/firmware/efi/ia64/retail) | 2 | — | — | — |

## `base/fs/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [base/fs](../../base/fs) | 2 | [base/fs/dirs](../../base/fs/dirs) | — | — |
| [base/fs/cdfs](../../base/fs/cdfs) | 35 | [base/fs/cdfs/sources](../../base/fs/cdfs/sources), [base/fs/cdfs/makefile](../../base/fs/cdfs/makefile) | `cdfs` | `DRIVER` |
| [base/fs/clfs](../../base/fs/clfs) | 1 | — | — | — |
| [base/fs/dfs](../../base/fs/dfs) | 3 | [base/fs/dfs/dirs](../../base/fs/dfs/dirs) | — | — |
| [base/fs/dfs/debug](../../base/fs/dfs/debug) | 4 | [base/fs/dfs/debug/sources](../../base/fs/dfs/debug/sources), [base/fs/dfs/debug/makefile](../../base/fs/dfs/debug/makefile) | `debug` | `LIBRARY` |
| [base/fs/dfs/dfsinit](../../base/fs/dfs/dfsinit) | 4 | [base/fs/dfs/dfsinit/sources](../../base/fs/dfs/dfsinit/sources), [base/fs/dfs/dfsinit/makefile](../../base/fs/dfs/dfsinit/makefile) | `dfsinit` | `PROGRAM` |
| [base/fs/dfs/dfsm](../../base/fs/dfs/dfsm) | 1 | [base/fs/dfs/dfsm/dirs](../../base/fs/dfs/dfsm/dirs) | — | — |
| [base/fs/dfs/dfsm/h](../../base/fs/dfs/dfsm/h) | 2 | — | — | — |
| [base/fs/dfs/dfsm/server](../../base/fs/dfs/dfsm/server) | 60 | [base/fs/dfs/dfsm/server/sources](../../base/fs/dfs/dfsm/server/sources), [base/fs/dfs/dfsm/server/makefile](../../base/fs/dfs/dfsm/server/makefile) | `dfssrv` | `LIBRARY` |
| [base/fs/dfs/dfssvc](../../base/fs/dfs/dfssvc) | 13 | [base/fs/dfs/dfssvc/sources](../../base/fs/dfs/dfssvc/sources), [base/fs/dfs/dfssvc/makefile](../../base/fs/dfs/dfssvc/makefile) | `dfssvc` | `PROGRAM` |
| [base/fs/dfs/driver](../../base/fs/dfs/driver) | 71 | [base/fs/dfs/driver/sources](../../base/fs/dfs/driver/sources), [base/fs/dfs/driver/makefile](../../base/fs/dfs/driver/makefile) | `dfs` | `DRIVER` |
| [base/fs/dfs/h](../../base/fs/dfs/h) | 14 | — | — | — |
| [base/fs/dfs/lib](../../base/fs/dfs/lib) | 7 | [base/fs/dfs/lib/sources](../../base/fs/dfs/lib/sources), [base/fs/dfs/lib/makefile](../../base/fs/dfs/lib/makefile) | `dfs` | `LIBRARY` |
| [base/fs/dfs/setup](../../base/fs/dfs/setup) | 20 | [base/fs/dfs/setup/sources](../../base/fs/dfs/setup/sources), [base/fs/dfs/setup/makefile](../../base/fs/dfs/setup/makefile) | `dfssetup` | `DYNLINK` |
| [base/fs/dfs/ui](../../base/fs/dfs/ui) | 7 | [base/fs/dfs/ui/dirs](../../base/fs/dfs/ui/dirs) | — | — |
| [base/fs/dfs/ui/dfscmd](../../base/fs/dfs/ui/dfscmd) | 14 | [base/fs/dfs/ui/dfscmd/sources](../../base/fs/dfs/ui/dfscmd/sources), [base/fs/dfs/ui/dfscmd/makefile](../../base/fs/dfs/ui/dfscmd/makefile) | `dfscmd` | `PROGRAM` |
| [base/fs/dfs/ui/dfsutil](../../base/fs/dfs/ui/dfsutil) | 22 | [base/fs/dfs/ui/dfsutil/dirs](../../base/fs/dfs/ui/dfsutil/dirs) | — | — |
| [base/fs/dfs/ui/dfsutil/du](../../base/fs/dfs/ui/dfsutil/du) | 2 | [base/fs/dfs/ui/dfsutil/du/sources](../../base/fs/dfs/ui/dfsutil/du/sources), [base/fs/dfs/ui/dfsutil/du/makefile](../../base/fs/dfs/ui/dfsutil/du/makefile) | `dfsutil` | `PROGRAM` |
| [base/fs/dfs/ui/dfsutil/dumb](../../base/fs/dfs/ui/dfsutil/dumb) | 2 | [base/fs/dfs/ui/dfsutil/dumb/sources](../../base/fs/dfs/ui/dfsutil/dumb/sources), [base/fs/dfs/ui/dfsutil/dumb/makefile](../../base/fs/dfs/ui/dfsutil/dumb/makefile) | `dumb` | `PROGRAM` |
| [base/fs/dfs/ui/inc](../../base/fs/dfs/ui/inc) | 5 | — | — | — |
| [base/fs/dfs/util](../../base/fs/dfs/util) | 1 | [base/fs/dfs/util/dirs](../../base/fs/dfs/util/dirs) | — | — |
| [base/fs/dfs/util/dfsdump](../../base/fs/dfs/util/dfsdump) | 7 | [base/fs/dfs/util/dfsdump/sources](../../base/fs/dfs/util/dfsdump/sources), [base/fs/dfs/util/dfsdump/makefile](../../base/fs/dfs/util/dfsdump/makefile) | `dfsdump` | `PROGRAM` |
| [base/fs/dfs/util/dfskd](../../base/fs/dfs/util/dfskd) | 9 | [base/fs/dfs/util/dfskd/sources](../../base/fs/dfs/util/dfskd/sources), [base/fs/dfs/util/dfskd/makefile](../../base/fs/dfs/util/dfskd/makefile) | `dfskd` | `DYNLINK` |
| [base/fs/efs](../../base/fs/efs) | 12 | [base/fs/efs/sources](../../base/fs/efs/sources), [base/fs/efs/makefile](../../base/fs/efs/makefile) | `efs` | `LIBRARY` |
| [base/fs/fastfat](../../base/fs/fastfat) | 43 | [base/fs/fastfat/dirs](../../base/fs/fastfat/dirs) | — | — |
| [base/fs/fastfat/fskd](../../base/fs/fastfat/fskd) | 15 | [base/fs/fastfat/fskd/sources](../../base/fs/fastfat/fskd/sources), [base/fs/fastfat/fskd/makefile](../../base/fs/fastfat/fskd/makefile) | `fskd` | `DYNLINK` |
| [base/fs/fastfat/mp](../../base/fs/fastfat/mp) | 3 | [base/fs/fastfat/mp/sources](../../base/fs/fastfat/mp/sources), [base/fs/fastfat/mp/makefile](../../base/fs/fastfat/mp/makefile) | `fastfat` | `DRIVER` |
| [base/fs/fastfat/spec](../../base/fs/fastfat/spec) | 9 | — | — | — |
| [base/fs/fastfat/tests](../../base/fs/fastfat/tests) | 4 | — | — | — |
| [base/fs/fltsamples](../../base/fs/fltsamples) | 1 | [base/fs/fltsamples/dirs](../../base/fs/fltsamples/dirs) | — | — |
| [base/fs/fltsamples/filespy](../../base/fs/fltsamples/filespy) | 7 | [base/fs/fltsamples/filespy/dirs](../../base/fs/fltsamples/filespy/dirs) | — | — |
| [base/fs/fltsamples/filespy/docs](../../base/fs/fltsamples/filespy/docs) | 2 | — | — | — |
| [base/fs/fltsamples/filespy/filter](../../base/fs/fltsamples/filespy/filter) | 10 | [base/fs/fltsamples/filespy/filter/sources](../../base/fs/fltsamples/filespy/filter/sources), [base/fs/fltsamples/filespy/filter/makefile](../../base/fs/fltsamples/filespy/filter/makefile) | `filespy` | `DRIVER` |
| [base/fs/fltsamples/filespy/fspykd](../../base/fs/fltsamples/filespy/fspykd) | 7 | [base/fs/fltsamples/filespy/fspykd/sources](../../base/fs/fltsamples/filespy/fspykd/sources), [base/fs/fltsamples/filespy/fspykd/makefile](../../base/fs/fltsamples/filespy/fspykd/makefile) | `fspykd` | `DYNLINK` |
| [base/fs/fltsamples/filespy/install](../../base/fs/fltsamples/filespy/install) | 4 | [base/fs/fltsamples/filespy/install/sources](../../base/fs/fltsamples/filespy/install/sources), [base/fs/fltsamples/filespy/install/makefile](../../base/fs/fltsamples/filespy/install/makefile) | `fspyInst` | `PROGRAM` |
| [base/fs/fltsamples/filespy/lib](../../base/fs/fltsamples/filespy/lib) | 7 | [base/fs/fltsamples/filespy/lib/sources](../../base/fs/fltsamples/filespy/lib/sources), [base/fs/fltsamples/filespy/lib/makefile](../../base/fs/fltsamples/filespy/lib/makefile) | `filespyLib` | `LIBRARY` |
| [base/fs/fltsamples/filespy/user](../../base/fs/fltsamples/filespy/user) | 6 | [base/fs/fltsamples/filespy/user/sources](../../base/fs/fltsamples/filespy/user/sources), [base/fs/fltsamples/filespy/user/makefile](../../base/fs/fltsamples/filespy/user/makefile) | `filespy` | `PROGRAM` |
| [base/fs/fltsamples/filespy/usergui](../../base/fs/fltsamples/filespy/usergui) | 40 | [base/fs/fltsamples/filespy/usergui/sources](../../base/fs/fltsamples/filespy/usergui/sources), [base/fs/fltsamples/filespy/usergui/makefile](../../base/fs/fltsamples/filespy/usergui/makefile) | `fsGui` | `PROGRAM` |
| [base/fs/fltsamples/filespy/usergui/res](../../base/fs/fltsamples/filespy/usergui/res) | 6 | — | — | — |
| [base/fs/fltsamples/iotest](../../base/fs/fltsamples/iotest) | 3 | [base/fs/fltsamples/iotest/dirs](../../base/fs/fltsamples/iotest/dirs) | — | — |
| [base/fs/fltsamples/iotest/filter](../../base/fs/fltsamples/iotest/filter) | 8 | [base/fs/fltsamples/iotest/filter/sources](../../base/fs/fltsamples/iotest/filter/sources), [base/fs/fltsamples/iotest/filter/makefile](../../base/fs/fltsamples/iotest/filter/makefile) | `ioTest` | `DRIVER` |
| [base/fs/fltsamples/iotest/lib](../../base/fs/fltsamples/iotest/lib) | 7 | [base/fs/fltsamples/iotest/lib/sources](../../base/fs/fltsamples/iotest/lib/sources), [base/fs/fltsamples/iotest/lib/makefile](../../base/fs/fltsamples/iotest/lib/makefile) | `ioTestLib` | `LIBRARY` |
| [base/fs/fltsamples/iotest/user](../../base/fs/fltsamples/iotest/user) | 7 | [base/fs/fltsamples/iotest/user/sources](../../base/fs/fltsamples/iotest/user/sources), [base/fs/fltsamples/iotest/user/makefile](../../base/fs/fltsamples/iotest/user/makefile) | `ioTest` | `PROGRAM` |
| [base/fs/fltsamples/latency](../../base/fs/fltsamples/latency) | 1 | [base/fs/fltsamples/latency/dirs](../../base/fs/fltsamples/latency/dirs) | — | — |
| [base/fs/fltsamples/latency/filter](../../base/fs/fltsamples/latency/filter) | 7 | [base/fs/fltsamples/latency/filter/sources](../../base/fs/fltsamples/latency/filter/sources), [base/fs/fltsamples/latency/filter/makefile](../../base/fs/fltsamples/latency/filter/makefile) | `latencyFilter` | `DRIVER` |
| [base/fs/fltsamples/latency/inc](../../base/fs/fltsamples/latency/inc) | 1 | — | — | — |
| [base/fs/fltsamples/sfilter](../../base/fs/fltsamples/sfilter) | 8 | [base/fs/fltsamples/sfilter/sources](../../base/fs/fltsamples/sfilter/sources), [base/fs/fltsamples/sfilter/makefile](../../base/fs/fltsamples/sfilter/makefile) | `sfilter` | `DRIVER` |
| [base/fs/hsm](../../base/fs/hsm) | 2 | [base/fs/hsm/dirs](../../base/fs/hsm/dirs) | — | — |
| [base/fs/hsm/cli](../../base/fs/hsm/cli) | 17 | [base/fs/hsm/cli/dirs](../../base/fs/hsm/cli/dirs) | — | — |
| [base/fs/hsm/cli/dll](../../base/fs/hsm/cli/dll) | 4 | [base/fs/hsm/cli/dll/sources](../../base/fs/hsm/cli/dll/sources), [base/fs/hsm/cli/dll/makefile](../../base/fs/hsm/cli/dll/makefile) | `RsCli` | `DYNLINK` |
| [base/fs/hsm/cli/exe](../../base/fs/hsm/cli/exe) | 4 | [base/fs/hsm/cli/exe/sources](../../base/fs/hsm/cli/exe/sources), [base/fs/hsm/cli/exe/makefile](../../base/fs/hsm/cli/exe/makefile) | `Rss` | `PROGRAM` |
| [base/fs/hsm/cluster](../../base/fs/hsm/cluster) | 1 | [base/fs/hsm/cluster/dirs](../../base/fs/hsm/cluster/dirs) | — | — |
| [base/fs/hsm/cluster/rsclustr](../../base/fs/hsm/cluster/rsclustr) | 9 | [base/fs/hsm/cluster/rsclustr/sources](../../base/fs/hsm/cluster/rsclustr/sources), [base/fs/hsm/cluster/rsclustr/makefile](../../base/fs/hsm/cluster/rsclustr/makefile) | `clusrss` | `DYNLINK` |
| [base/fs/hsm/engine](../../base/fs/hsm/engine) | 1 | [base/fs/hsm/engine/dirs](../../base/fs/hsm/engine/dirs) | — | — |
| [base/fs/hsm/engine/hsmeng](../../base/fs/hsm/engine/hsmeng) | 31 | [base/fs/hsm/engine/hsmeng/sources](../../base/fs/hsm/engine/hsmeng/sources), [base/fs/hsm/engine/hsmeng/makefile](../../base/fs/hsm/engine/hsmeng/makefile) | `RsEng` | `DYNLINK` |
| [base/fs/hsm/engine/inc](../../base/fs/hsm/engine/inc) | 1 | — | — | — |
| [base/fs/hsm/engine/task](../../base/fs/hsm/engine/task) | 36 | [base/fs/hsm/engine/task/sources](../../base/fs/hsm/engine/task/sources), [base/fs/hsm/engine/task/makefile](../../base/fs/hsm/engine/task/makefile) | `RsTask` | `DYNLINK` |
| [base/fs/hsm/filter](../../base/fs/hsm/filter) | 12 | [base/fs/hsm/filter/sources](../../base/fs/hsm/filter/sources), [base/fs/hsm/filter/makefile](../../base/fs/hsm/filter/makefile) | `RsFilter` | `DRIVER` |
| [base/fs/hsm/fsa](../../base/fs/hsm/fsa) | 47 | [base/fs/hsm/fsa/dirs](../../base/fs/hsm/fsa/dirs) | — | — |
| [base/fs/hsm/fsa/dll](../../base/fs/hsm/fsa/dll) | 3 | [base/fs/hsm/fsa/dll/sources](../../base/fs/hsm/fsa/dll/sources), [base/fs/hsm/fsa/dll/makefile](../../base/fs/hsm/fsa/dll/makefile) | `RsFsa` | `DYNLINK` |
| [base/fs/hsm/fsa/service](../../base/fs/hsm/fsa/service) | 3 | [base/fs/hsm/fsa/service/sources](../../base/fs/hsm/fsa/service/sources), [base/fs/hsm/fsa/service/makefile](../../base/fs/hsm/fsa/service/makefile) | `RsFsa` | `PROGRAM` |
| [base/fs/hsm/gui](../../base/fs/hsm/gui) | 1 | [base/fs/hsm/gui/dirs](../../base/fs/hsm/gui/dirs) | — | — |
| [base/fs/hsm/gui/hsmadmin](../../base/fs/hsm/gui/hsmadmin) | 40 | [base/fs/hsm/gui/hsmadmin/dirs](../../base/fs/hsm/gui/hsmadmin/dirs) | — | — |
| [base/fs/hsm/gui/hsmadmin/computer](../../base/fs/hsm/gui/hsmadmin/computer) | 8 | [base/fs/hsm/gui/hsmadmin/computer/sources](../../base/fs/hsm/gui/hsmadmin/computer/sources), [base/fs/hsm/gui/hsmadmin/computer/makefile](../../base/fs/hsm/gui/hsmadmin/computer/makefile) | `computer` | `LIBRARY` |
| [base/fs/hsm/gui/hsmadmin/device](../../base/fs/hsm/gui/hsmadmin/device) | 12 | [base/fs/hsm/gui/hsmadmin/device/sources](../../base/fs/hsm/gui/hsmadmin/device/sources), [base/fs/hsm/gui/hsmadmin/device/makefile](../../base/fs/hsm/gui/hsmadmin/device/makefile) | `device` | `LIBRARY` |
| [base/fs/hsm/gui/hsmadmin/dll](../../base/fs/hsm/gui/hsmadmin/dll) | 4 | [base/fs/hsm/gui/hsmadmin/dll/sources](../../base/fs/hsm/gui/hsmadmin/dll/sources), [base/fs/hsm/gui/hsmadmin/dll/makefile](../../base/fs/hsm/gui/hsmadmin/dll/makefile) | `RsAdmin` | `DYNLINK` |
| [base/fs/hsm/gui/hsmadmin/idl](../../base/fs/hsm/gui/hsmadmin/idl) | 3 | [base/fs/hsm/gui/hsmadmin/idl/sources](../../base/fs/hsm/gui/hsmadmin/idl/sources), [base/fs/hsm/gui/hsmadmin/idl/makefile](../../base/fs/hsm/gui/hsmadmin/idl/makefile) | — | `NOTARGET` |
| [base/fs/hsm/gui/hsmadmin/mergeps](../../base/fs/hsm/gui/hsmadmin/mergeps) | 3 | [base/fs/hsm/gui/hsmadmin/mergeps/sources](../../base/fs/hsm/gui/hsmadmin/mergeps/sources), [base/fs/hsm/gui/hsmadmin/mergeps/makefile](../../base/fs/hsm/gui/hsmadmin/mergeps/makefile) | `mergeps` | `LIBRARY` |
| [base/fs/hsm/gui/hsmadmin/res](../../base/fs/hsm/gui/hsmadmin/res) | 44 | — | — | — |
| [base/fs/hsm/gui/hsmadmin/volume](../../base/fs/hsm/gui/hsmadmin/volume) | 26 | [base/fs/hsm/gui/hsmadmin/volume/sources](../../base/fs/hsm/gui/hsmadmin/volume/sources), [base/fs/hsm/gui/hsmadmin/volume/makefile](../../base/fs/hsm/gui/hsmadmin/volume/makefile) | `volume` | `LIBRARY` |
| [base/fs/hsm/gui/inc](../../base/fs/hsm/gui/inc) | 6 | — | — | — |
| [base/fs/hsm/gui/rsntfy](../../base/fs/hsm/gui/rsntfy) | 23 | [base/fs/hsm/gui/rsntfy/dirs](../../base/fs/hsm/gui/rsntfy/dirs) | — | — |
| [base/fs/hsm/gui/rsntfy/dll](../../base/fs/hsm/gui/rsntfy/dll) | 3 | [base/fs/hsm/gui/rsntfy/dll/sources](../../base/fs/hsm/gui/rsntfy/dll/sources), [base/fs/hsm/gui/rsntfy/dll/makefile](../../base/fs/hsm/gui/rsntfy/dll/makefile) | `RsNtfy` | `DYNLINK` |
| [base/fs/hsm/gui/rsntfy/exe](../../base/fs/hsm/gui/rsntfy/exe) | 3 | [base/fs/hsm/gui/rsntfy/exe/sources](../../base/fs/hsm/gui/rsntfy/exe/sources), [base/fs/hsm/gui/rsntfy/exe/makefile](../../base/fs/hsm/gui/rsntfy/exe/makefile) | `RsNotify` | `PROGRAM` |
| [base/fs/hsm/gui/rsoptcom](../../base/fs/hsm/gui/rsoptcom) | 22 | [base/fs/hsm/gui/rsoptcom/dirs](../../base/fs/hsm/gui/rsoptcom/dirs) | — | — |
| [base/fs/hsm/gui/rsoptcom/dll](../../base/fs/hsm/gui/rsoptcom/dll) | 3 | [base/fs/hsm/gui/rsoptcom/dll/sources](../../base/fs/hsm/gui/rsoptcom/dll/sources), [base/fs/hsm/gui/rsoptcom/dll/makefile](../../base/fs/hsm/gui/rsoptcom/dll/makefile) | `RsOptCom` | `DYNLINK` |
| [base/fs/hsm/gui/rsoptcom/res](../../base/fs/hsm/gui/rsoptcom/res) | 3 | — | — | — |
| [base/fs/hsm/gui/rsoptcom/rscln](../../base/fs/hsm/gui/rsoptcom/rscln) | 9 | [base/fs/hsm/gui/rsoptcom/rscln/sources](../../base/fs/hsm/gui/rsoptcom/rscln/sources), [base/fs/hsm/gui/rsoptcom/rscln/makefile](../../base/fs/hsm/gui/rsoptcom/rscln/makefile) | `RsCln` | `LIBRARY` |
| [base/fs/hsm/gui/shellext](../../base/fs/hsm/gui/shellext) | 10 | [base/fs/hsm/gui/shellext/dirs](../../base/fs/hsm/gui/shellext/dirs) | — | — |
| [base/fs/hsm/gui/shellext/dll](../../base/fs/hsm/gui/shellext/dll) | 3 | [base/fs/hsm/gui/shellext/dll/sources](../../base/fs/hsm/gui/shellext/dll/sources), [base/fs/hsm/gui/shellext/dll/makefile](../../base/fs/hsm/gui/shellext/dll/makefile) | `RsShell` | `DYNLINK` |
| [base/fs/hsm/gui/shellext/idl](../../base/fs/hsm/gui/shellext/idl) | 3 | [base/fs/hsm/gui/shellext/idl/sources](../../base/fs/hsm/gui/shellext/idl/sources), [base/fs/hsm/gui/shellext/idl/makefile](../../base/fs/hsm/gui/shellext/idl/makefile) | — | `NOTARGET` |
| [base/fs/hsm/gui/shellext/proppage](../../base/fs/hsm/gui/shellext/proppage) | 4 | [base/fs/hsm/gui/shellext/proppage/sources](../../base/fs/hsm/gui/shellext/proppage/sources), [base/fs/hsm/gui/shellext/proppage/makefile](../../base/fs/hsm/gui/shellext/proppage/makefile) | `PropPage` | `LIBRARY` |
| [base/fs/hsm/gui/shellext/res](../../base/fs/hsm/gui/shellext/res) | 3 | — | — | — |
| [base/fs/hsm/gui/utility](../../base/fs/hsm/gui/utility) | 5 | [base/fs/hsm/gui/utility/sources](../../base/fs/hsm/gui/utility/sources), [base/fs/hsm/gui/utility/makefile](../../base/fs/hsm/gui/utility/makefile) | `guiutil` | `LIBRARY` |
| [base/fs/hsm/gui/utility/res](../../base/fs/hsm/gui/utility/res) | 1 | — | — | — |
| [base/fs/hsm/hsmconn](../../base/fs/hsm/hsmconn) | 9 | [base/fs/hsm/hsmconn/sources](../../base/fs/hsm/hsmconn/sources), [base/fs/hsm/hsmconn/makefile](../../base/fs/hsm/hsmconn/makefile) | `RsConn` | `DYNLINK` |
| [base/fs/hsm/hsmservr](../../base/fs/hsm/hsmservr) | 14 | [base/fs/hsm/hsmservr/dirs](../../base/fs/hsm/hsmservr/dirs) | — | — |
| [base/fs/hsm/hsmservr/service](../../base/fs/hsm/hsmservr/service) | 3 | [base/fs/hsm/hsmservr/service/sources](../../base/fs/hsm/hsmservr/service/sources), [base/fs/hsm/hsmservr/service/makefile](../../base/fs/hsm/hsmservr/service/makefile) | `RsServ` | `PROGRAM` |
| [base/fs/hsm/idb](../../base/fs/hsm/idb) | 20 | [base/fs/hsm/idb/sources](../../base/fs/hsm/idb/sources), [base/fs/hsm/idb/makefile](../../base/fs/hsm/idb/makefile) | `RsIdb` | `DYNLINK` |
| [base/fs/hsm/idl](../../base/fs/hsm/idl) | 2 | [base/fs/hsm/idl/dirs](../../base/fs/hsm/idl/dirs) | — | — |
| [base/fs/hsm/idl/fsaguid](../../base/fs/hsm/idl/fsaguid) | 4 | [base/fs/hsm/idl/fsaguid/sources](../../base/fs/hsm/idl/fsaguid/sources), [base/fs/hsm/idl/fsaguid/makefile](../../base/fs/hsm/idl/fsaguid/makefile) | `FsaGuid` | `LIBRARY` |
| [base/fs/hsm/idl/fsaps](../../base/fs/hsm/idl/fsaps) | 3 | [base/fs/hsm/idl/fsaps/sources](../../base/fs/hsm/idl/fsaps/sources), [base/fs/hsm/idl/fsaps/makefile](../../base/fs/hsm/idl/fsaps/makefile) | `RsFsaPs` | `DYNLINK` |
| [base/fs/hsm/idl/hsmguid](../../base/fs/hsm/idl/hsmguid) | 4 | [base/fs/hsm/idl/hsmguid/sources](../../base/fs/hsm/idl/hsmguid/sources), [base/fs/hsm/idl/hsmguid/makefile](../../base/fs/hsm/idl/hsmguid/makefile) | `HsmGuid` | `LIBRARY` |
| [base/fs/hsm/idl/hsmps](../../base/fs/hsm/idl/hsmps) | 3 | [base/fs/hsm/idl/hsmps/sources](../../base/fs/hsm/idl/hsmps/sources), [base/fs/hsm/idl/hsmps/makefile](../../base/fs/hsm/idl/hsmps/makefile) | `RsEngPs` | `DYNLINK` |
| [base/fs/hsm/idl/hsmsguid](../../base/fs/hsm/idl/hsmsguid) | 3 | [base/fs/hsm/idl/hsmsguid/sources](../../base/fs/hsm/idl/hsmsguid/sources), [base/fs/hsm/idl/hsmsguid/makefile](../../base/fs/hsm/idl/hsmsguid/makefile) | `HsmSGuid` | `LIBRARY` |
| [base/fs/hsm/idl/hsmsps](../../base/fs/hsm/idl/hsmsps) | 3 | [base/fs/hsm/idl/hsmsps/sources](../../base/fs/hsm/idl/hsmsps/sources), [base/fs/hsm/idl/hsmsps/makefile](../../base/fs/hsm/idl/hsmsps/makefile) | `RsServPs` | `DYNLINK` |
| [base/fs/hsm/idl/jobguid](../../base/fs/hsm/idl/jobguid) | 2 | [base/fs/hsm/idl/jobguid/sources](../../base/fs/hsm/idl/jobguid/sources), [base/fs/hsm/idl/jobguid/makefile](../../base/fs/hsm/idl/jobguid/makefile) | `JobGuid` | `LIBRARY` |
| [base/fs/hsm/idl/mvrguid](../../base/fs/hsm/idl/mvrguid) | 4 | [base/fs/hsm/idl/mvrguid/sources](../../base/fs/hsm/idl/mvrguid/sources), [base/fs/hsm/idl/mvrguid/makefile](../../base/fs/hsm/idl/mvrguid/makefile) | `MvrGuid` | `LIBRARY` |
| [base/fs/hsm/idl/rmsguid](../../base/fs/hsm/idl/rmsguid) | 4 | [base/fs/hsm/idl/rmsguid/sources](../../base/fs/hsm/idl/rmsguid/sources), [base/fs/hsm/idl/rmsguid/makefile](../../base/fs/hsm/idl/rmsguid/makefile) | `RmsGuid` | `LIBRARY` |
| [base/fs/hsm/idl/rmsps](../../base/fs/hsm/idl/rmsps) | 6 | [base/fs/hsm/idl/rmsps/sources](../../base/fs/hsm/idl/rmsps/sources), [base/fs/hsm/idl/rmsps/makefile](../../base/fs/hsm/idl/rmsps/makefile) | `RsSubPs` | `DYNLINK` |
| [base/fs/hsm/idl/wsbguid](../../base/fs/hsm/idl/wsbguid) | 4 | [base/fs/hsm/idl/wsbguid/sources](../../base/fs/hsm/idl/wsbguid/sources), [base/fs/hsm/idl/wsbguid/makefile](../../base/fs/hsm/idl/wsbguid/makefile) | `WsbGuid` | `LIBRARY` |
| [base/fs/hsm/inc](../../base/fs/hsm/inc) | 46 | — | — | — |
| [base/fs/hsm/inf](../../base/fs/hsm/inf) | 1 | — | — | — |
| [base/fs/hsm/infs](../../base/fs/hsm/infs) | 5 | — | — | — |
| [base/fs/hsm/job](../../base/fs/hsm/job) | 79 | [base/fs/hsm/job/dirs](../../base/fs/hsm/job/dirs) | — | — |
| [base/fs/hsm/job/dll](../../base/fs/hsm/job/dll) | 3 | [base/fs/hsm/job/dll/sources](../../base/fs/hsm/job/dll/sources), [base/fs/hsm/job/dll/makefile](../../base/fs/hsm/job/dll/makefile) | `RsJob` | `DYNLINK` |
| [base/fs/hsm/kdexts](../../base/fs/hsm/kdexts) | 11 | [base/fs/hsm/kdexts/sources](../../base/fs/hsm/kdexts/sources), [base/fs/hsm/kdexts/makefile](../../base/fs/hsm/kdexts/makefile) | `hsmkd` | `DYNLINK` |
| [base/fs/hsm/launch](../../base/fs/hsm/launch) | 8 | [base/fs/hsm/launch/sources](../../base/fs/hsm/launch/sources), [base/fs/hsm/launch/makefile](../../base/fs/hsm/launch/makefile) | `RsLaunch` | `PROGRAM` |
| [base/fs/hsm/mover](../../base/fs/hsm/mover) | 2 | [base/fs/hsm/mover/dirs](../../base/fs/hsm/mover/dirs) | — | — |
| [base/fs/hsm/mover/server](../../base/fs/hsm/mover/server) | 28 | [base/fs/hsm/mover/server/sources](../../base/fs/hsm/mover/server/sources), [base/fs/hsm/mover/server/makefile](../../base/fs/hsm/mover/server/makefile) | `RsMover` | `DYNLINK` |
| [base/fs/hsm/rms](../../base/fs/hsm/rms) | 2 | [base/fs/hsm/rms/dirs](../../base/fs/hsm/rms/dirs) | — | — |
| [base/fs/hsm/rms/server](../../base/fs/hsm/rms/server) | 64 | [base/fs/hsm/rms/server/sources](../../base/fs/hsm/rms/server/sources), [base/fs/hsm/rms/server/makefile](../../base/fs/hsm/rms/server/makefile) | `RsSub` | `DYNLINK` |
| [base/fs/hsm/rstore](../../base/fs/hsm/rstore) | 4 | [base/fs/hsm/rstore/sources](../../base/fs/hsm/rstore/sources), [base/fs/hsm/rstore/makefile](../../base/fs/hsm/rstore/makefile) | `RsTore` | `PROGRAM` |
| [base/fs/hsm/sld](../../base/fs/hsm/sld) | 7 | [base/fs/hsm/sld/sources](../../base/fs/hsm/sld/sources), [base/fs/hsm/sld/makefile](../../base/fs/hsm/sld/makefile) | `Component` | `NOTARGET` |
| [base/fs/hsm/types](../../base/fs/hsm/types) | 1 | [base/fs/hsm/types/dirs](../../base/fs/hsm/types/dirs) | — | — |
| [base/fs/hsm/types/fsa](../../base/fs/hsm/types/fsa) | 6 | [base/fs/hsm/types/fsa/sources](../../base/fs/hsm/types/fsa/sources), [base/fs/hsm/types/fsa/makefile](../../base/fs/hsm/types/fsa/makefile) | — | `NOTARGET` |
| [base/fs/hsm/types/hsm](../../base/fs/hsm/types/hsm) | 9 | [base/fs/hsm/types/hsm/sources](../../base/fs/hsm/types/hsm/sources), [base/fs/hsm/types/hsm/makefile](../../base/fs/hsm/types/hsm/makefile) | — | `NOTARGET` |
| [base/fs/hsm/types/hsmservr](../../base/fs/hsm/types/hsmservr) | 3 | [base/fs/hsm/types/hsmservr/sources](../../base/fs/hsm/types/hsmservr/sources), [base/fs/hsm/types/hsmservr/makefile](../../base/fs/hsm/types/hsmservr/makefile) | — | `NOTARGET` |
| [base/fs/hsm/types/job](../../base/fs/hsm/types/job) | 6 | [base/fs/hsm/types/job/sources](../../base/fs/hsm/types/job/sources), [base/fs/hsm/types/job/makefile](../../base/fs/hsm/types/job/makefile) | — | `NOTARGET` |
| [base/fs/hsm/types/mover](../../base/fs/hsm/types/mover) | 5 | [base/fs/hsm/types/mover/sources](../../base/fs/hsm/types/mover/sources), [base/fs/hsm/types/mover/makefile](../../base/fs/hsm/types/mover/makefile) | — | `NOTARGET` |
| [base/fs/hsm/types/rms](../../base/fs/hsm/types/rms) | 5 | [base/fs/hsm/types/rms/sources](../../base/fs/hsm/types/rms/sources), [base/fs/hsm/types/rms/makefile](../../base/fs/hsm/types/rms/makefile) | — | `NOTARGET` |
| [base/fs/hsm/types/wsb](../../base/fs/hsm/types/wsb) | 7 | [base/fs/hsm/types/wsb/sources](../../base/fs/hsm/types/wsb/sources), [base/fs/hsm/types/wsb/makefile](../../base/fs/hsm/types/wsb/makefile) | — | `NOTARGET` |
| [base/fs/hsm/wsb](../../base/fs/hsm/wsb) | 64 | [base/fs/hsm/wsb/sources](../../base/fs/hsm/wsb/sources), [base/fs/hsm/wsb/makefile](../../base/fs/hsm/wsb/makefile) | `RsCommon` | `DYNLINK` |
| [base/fs/lfs](../../base/fs/lfs) | 22 | [base/fs/lfs/dirs](../../base/fs/lfs/dirs) | — | — |
| [base/fs/lfs/mp](../../base/fs/lfs/mp) | 2 | [base/fs/lfs/mp/sources](../../base/fs/lfs/mp/sources), [base/fs/lfs/mp/makefile](../../base/fs/lfs/mp/makefile) | — | — |
| [base/fs/lfs/up](../../base/fs/lfs/up) | 2 | [base/fs/lfs/up/sources](../../base/fs/lfs/up/sources), [base/fs/lfs/up/makefile](../../base/fs/lfs/up/makefile) | — | — |
| [base/fs/mailslot](../../base/fs/mailslot) | 37 | [base/fs/mailslot/sources](../../base/fs/mailslot/sources), [base/fs/mailslot/makefile](../../base/fs/mailslot/makefile) | `msfs` | `DRIVER` |
| [base/fs/mup](../../base/fs/mup) | 78 | [base/fs/mup/dirs](../../base/fs/mup/dirs) | — | — |
| [base/fs/mup/daytona](../../base/fs/mup/daytona) | 2 | [base/fs/mup/daytona/sources](../../base/fs/mup/daytona/sources), [base/fs/mup/daytona/makefile](../../base/fs/mup/daytona/makefile) | `mup` | `DRIVER` |
| [base/fs/mup/hydra](../../base/fs/mup/hydra) | 2 | [base/fs/mup/hydra/sources](../../base/fs/mup/hydra/sources), [base/fs/mup/hydra/makefile](../../base/fs/mup/hydra/makefile) | — | — |
| [base/fs/mup/kdext](../../base/fs/mup/kdext) | 9 | [base/fs/mup/kdext/sources](../../base/fs/mup/kdext/sources), [base/fs/mup/kdext/makefile](../../base/fs/mup/kdext/makefile) | `mupkd` | `DYNLINK` |
| [base/fs/mup/wml](../../base/fs/mup/wml) | 2 | [base/fs/mup/wml/dirs](../../base/fs/mup/wml/dirs) | — | — |
| [base/fs/mup/wml/inc](../../base/fs/mup/wml/inc) | 5 | — | — | — |
| [base/fs/mup/wml/km](../../base/fs/mup/wml/km) | 3 | [base/fs/mup/wml/km/sources](../../base/fs/mup/wml/km/sources), [base/fs/mup/wml/km/makefile](../../base/fs/mup/wml/km/makefile) | `wmlkm` | `LIBRARY` |
| [base/fs/mup/wml/um](../../base/fs/mup/wml/um) | 5 | [base/fs/mup/wml/um/sources](../../base/fs/mup/wml/um/sources), [base/fs/mup/wml/um/makefile](../../base/fs/mup/wml/um/makefile) | `wmlum` | `LIBRARY` |
| [base/fs/npfs](../../base/fs/npfs) | 36 | [base/fs/npfs/dirs](../../base/fs/npfs/dirs) | — | — |
| [base/fs/npfs/mp](../../base/fs/npfs/mp) | 2 | [base/fs/npfs/mp/sources](../../base/fs/npfs/mp/sources), [base/fs/npfs/mp/makefile](../../base/fs/npfs/mp/makefile) | — | — |
| [base/fs/npfs/npfskd](../../base/fs/npfs/npfskd) | 6 | [base/fs/npfs/npfskd/sources](../../base/fs/npfs/npfskd/sources), [base/fs/npfs/npfskd/makefile](../../base/fs/npfs/npfskd/makefile) | `npfskd` | `DYNLINK` |
| [base/fs/ntfs](../../base/fs/ntfs) | 65 | [base/fs/ntfs/dirs](../../base/fs/ntfs/dirs) | — | — |
| [base/fs/ntfs/fu](../../base/fs/ntfs/fu) | 21 | [base/fs/ntfs/fu/sources](../../base/fs/ntfs/fu/sources), [base/fs/ntfs/fu/makefile](../../base/fs/ntfs/fu/makefile) | `fsutil` | `PROGRAM` |
| [base/fs/ntfs/mp](../../base/fs/ntfs/mp) | 3 | [base/fs/ntfs/mp/sources](../../base/fs/ntfs/mp/sources), [base/fs/ntfs/mp/makefile](../../base/fs/ntfs/mp/makefile) | — | — |
| [base/fs/ntfs/ntfskd](../../base/fs/ntfs/ntfskd) | 10 | [base/fs/ntfs/ntfskd/sources](../../base/fs/ntfs/ntfskd/sources), [base/fs/ntfs/ntfskd/makefile](../../base/fs/ntfs/ntfskd/makefile) | `ntfskd` | `DYNLINK` |
| [base/fs/ntfs/tests](../../base/fs/ntfs/tests) | 8 | [base/fs/ntfs/tests/sources](../../base/fs/ntfs/tests/sources), [base/fs/ntfs/tests/makefile](../../base/fs/ntfs/tests/makefile) | `ntfstest` | `LIBRARY` |
| [base/fs/ntfs/tests/analyze](../../base/fs/ntfs/tests/analyze) | 3 | [base/fs/ntfs/tests/analyze/sources](../../base/fs/ntfs/tests/analyze/sources), [base/fs/ntfs/tests/analyze/makefile](../../base/fs/ntfs/tests/analyze/makefile) | `analyze` | `PROGRAM` |
| [base/fs/ntfs/tests/bshell](../../base/fs/ntfs/tests/bshell) | 32 | [base/fs/ntfs/tests/bshell/sources](../../base/fs/ntfs/tests/bshell/sources), [base/fs/ntfs/tests/bshell/makefile](../../base/fs/ntfs/tests/bshell/makefile) | `bshell` | `PROGRAM` |
| [base/fs/ntfs/tests/dismount](../../base/fs/ntfs/tests/dismount) | 3 | [base/fs/ntfs/tests/dismount/sources](../../base/fs/ntfs/tests/dismount/sources), [base/fs/ntfs/tests/dismount/makefile](../../base/fs/ntfs/tests/dismount/makefile) | `dismount` | `UMAPPL_NOLIB` |
| [base/fs/ntfs/tests/fastfind](../../base/fs/ntfs/tests/fastfind) | 4 | [base/fs/ntfs/tests/fastfind/sources](../../base/fs/ntfs/tests/fastfind/sources), [base/fs/ntfs/tests/fastfind/makefile](../../base/fs/ntfs/tests/fastfind/makefile) | `fastfind` | `UMAPPL_NOLIB` |
| [base/fs/ntfs/tests/logfile](../../base/fs/ntfs/tests/logfile) | 11 | [base/fs/ntfs/tests/logfile/sources](../../base/fs/ntfs/tests/logfile/sources), [base/fs/ntfs/tests/logfile/makefile](../../base/fs/ntfs/tests/logfile/makefile) | `dumplog` | `PROGRAM` |
| [base/fs/ntfs/tests/objectid](../../base/fs/ntfs/tests/objectid) | 2 | [base/fs/ntfs/tests/objectid/dirs](../../base/fs/ntfs/tests/objectid/dirs) | — | — |
| [base/fs/ntfs/tests/objectid/deloid](../../base/fs/ntfs/tests/objectid/deloid) | 3 | [base/fs/ntfs/tests/objectid/deloid/sources](../../base/fs/ntfs/tests/objectid/deloid/sources), [base/fs/ntfs/tests/objectid/deloid/makefile](../../base/fs/ntfs/tests/objectid/deloid/makefile) | `deloid` | `UMAPPL_NOLIB` |
| [base/fs/ntfs/tests/objectid/enumoid](../../base/fs/ntfs/tests/objectid/enumoid) | 3 | [base/fs/ntfs/tests/objectid/enumoid/sources](../../base/fs/ntfs/tests/objectid/enumoid/sources), [base/fs/ntfs/tests/objectid/enumoid/makefile](../../base/fs/ntfs/tests/objectid/enumoid/makefile) | `enumoid` | `UMAPPL_NOLIB` |
| [base/fs/ntfs/tests/objectid/enumq](../../base/fs/ntfs/tests/objectid/enumq) | 3 | [base/fs/ntfs/tests/objectid/enumq/sources](../../base/fs/ntfs/tests/objectid/enumq/sources), [base/fs/ntfs/tests/objectid/enumq/makefile](../../base/fs/ntfs/tests/objectid/enumq/makefile) | `enumq` | `UMAPPL_NOLIB` |
| [base/fs/ntfs/tests/objectid/enumr](../../base/fs/ntfs/tests/objectid/enumr) | 3 | [base/fs/ntfs/tests/objectid/enumr/sources](../../base/fs/ntfs/tests/objectid/enumr/sources), [base/fs/ntfs/tests/objectid/enumr/makefile](../../base/fs/ntfs/tests/objectid/enumr/makefile) | `enumr` | `UMAPPL_NOLIB` |
| [base/fs/ntfs/tests/objectid/genoid](../../base/fs/ntfs/tests/objectid/genoid) | 3 | [base/fs/ntfs/tests/objectid/genoid/sources](../../base/fs/ntfs/tests/objectid/genoid/sources), [base/fs/ntfs/tests/objectid/genoid/makefile](../../base/fs/ntfs/tests/objectid/genoid/makefile) | `genoid` | `UMAPPL_NOLIB` |
| [base/fs/ntfs/tests/objectid/getoid](../../base/fs/ntfs/tests/objectid/getoid) | 4 | [base/fs/ntfs/tests/objectid/getoid/sources](../../base/fs/ntfs/tests/objectid/getoid/sources), [base/fs/ntfs/tests/objectid/getoid/makefile](../../base/fs/ntfs/tests/objectid/getoid/makefile) | `getoid` | `UMAPPL_NOLIB` |
| [base/fs/ntfs/tests/objectid/getvid](../../base/fs/ntfs/tests/objectid/getvid) | 3 | [base/fs/ntfs/tests/objectid/getvid/sources](../../base/fs/ntfs/tests/objectid/getvid/sources), [base/fs/ntfs/tests/objectid/getvid/makefile](../../base/fs/ntfs/tests/objectid/getvid/makefile) | `getvid` | `UMAPPL_NOLIB` |
| [base/fs/ntfs/tests/objectid/inc](../../base/fs/ntfs/tests/objectid/inc) | 1 | — | — | — |
| [base/fs/ntfs/tests/objectid/notify](../../base/fs/ntfs/tests/objectid/notify) | 3 | [base/fs/ntfs/tests/objectid/notify/sources](../../base/fs/ntfs/tests/objectid/notify/sources), [base/fs/ntfs/tests/objectid/notify/makefile](../../base/fs/ntfs/tests/objectid/notify/makefile) | `notify` | `UMAPPL_NOLIB` |
| [base/fs/ntfs/tests/objectid/oboid](../../base/fs/ntfs/tests/objectid/oboid) | 3 | [base/fs/ntfs/tests/objectid/oboid/sources](../../base/fs/ntfs/tests/objectid/oboid/sources), [base/fs/ntfs/tests/objectid/oboid/makefile](../../base/fs/ntfs/tests/objectid/oboid/makefile) | `oboid` | `PROGRAM` |
| [base/fs/ntfs/tests/objectid/offline](../../base/fs/ntfs/tests/objectid/offline) | 4 | [base/fs/ntfs/tests/objectid/offline/sources](../../base/fs/ntfs/tests/objectid/offline/sources), [base/fs/ntfs/tests/objectid/offline/makefile](../../base/fs/ntfs/tests/objectid/offline/makefile) | `offline` | `UMAPPL_NOLIB` |
| [base/fs/ntfs/tests/objectid/setext](../../base/fs/ntfs/tests/objectid/setext) | 3 | [base/fs/ntfs/tests/objectid/setext/sources](../../base/fs/ntfs/tests/objectid/setext/sources), [base/fs/ntfs/tests/objectid/setext/makefile](../../base/fs/ntfs/tests/objectid/setext/makefile) | `setext` | `UMAPPL_NOLIB` |
| [base/fs/ntfs/tests/objectid/setoid](../../base/fs/ntfs/tests/objectid/setoid) | 3 | [base/fs/ntfs/tests/objectid/setoid/sources](../../base/fs/ntfs/tests/objectid/setoid/sources), [base/fs/ntfs/tests/objectid/setoid/makefile](../../base/fs/ntfs/tests/objectid/setoid/makefile) | `setoid` | `UMAPPL_NOLIB` |
| [base/fs/ntfs/tests/objectid/setvid](../../base/fs/ntfs/tests/objectid/setvid) | 3 | [base/fs/ntfs/tests/objectid/setvid/sources](../../base/fs/ntfs/tests/objectid/setvid/sources), [base/fs/ntfs/tests/objectid/setvid/makefile](../../base/fs/ntfs/tests/objectid/setvid/makefile) | `setvid` | `UMAPPL_NOLIB` |
| [base/fs/ntfs/tests/rootattr](../../base/fs/ntfs/tests/rootattr) | 3 | [base/fs/ntfs/tests/rootattr/sources](../../base/fs/ntfs/tests/rootattr/sources), [base/fs/ntfs/tests/rootattr/makefile](../../base/fs/ntfs/tests/rootattr/makefile) | `rootattr` | `UMAPPL_NOLIB` |
| [base/fs/ntfs/tests/syscache](../../base/fs/ntfs/tests/syscache) | 3 | [base/fs/ntfs/tests/syscache/sources](../../base/fs/ntfs/tests/syscache/sources), [base/fs/ntfs/tests/syscache/makefile](../../base/fs/ntfs/tests/syscache/makefile) | `dumpsyscachelog` | `PROGRAM` |
| [base/fs/ntfs/tests/usntest](../../base/fs/ntfs/tests/usntest) | 4 | [base/fs/ntfs/tests/usntest/sources](../../base/fs/ntfs/tests/usntest/sources), [base/fs/ntfs/tests/usntest/makefile](../../base/fs/ntfs/tests/usntest/makefile) | `xxxxx` | `UMAPPL_NOLIB` |
| [base/fs/rdr2](../../base/fs/rdr2) | 8 | [base/fs/rdr2/dirs](../../base/fs/rdr2/dirs) | — | — |
| [base/fs/rdr2/bowser](../../base/fs/rdr2/bowser) | 49 | [base/fs/rdr2/bowser/sources](../../base/fs/rdr2/bowser/sources), [base/fs/rdr2/bowser/makefile](../../base/fs/rdr2/bowser/makefile) | `bowser` | `DRIVER_LIBRARY` |
| [base/fs/rdr2/csc](../../base/fs/rdr2/csc) | 6 | [base/fs/rdr2/csc/dirs](../../base/fs/rdr2/csc/dirs) | — | — |
| [base/fs/rdr2/csc/inc](../../base/fs/rdr2/csc/inc) | 14 | [base/fs/rdr2/csc/inc/sources](../../base/fs/rdr2/csc/inc/sources), [base/fs/rdr2/csc/inc/makefile](../../base/fs/rdr2/csc/inc/makefile) | — | `LIBRARY` |
| [base/fs/rdr2/csc/record.mgr](../../base/fs/rdr2/csc/record.mgr) | 37 | [base/fs/rdr2/csc/record.mgr/dirs](../../base/fs/rdr2/csc/record.mgr/dirs) | — | — |
| [base/fs/rdr2/csc/record.mgr/bmreclib](../../base/fs/rdr2/csc/record.mgr/bmreclib) | 7 | [base/fs/rdr2/csc/record.mgr/bmreclib/sources](../../base/fs/rdr2/csc/record.mgr/bmreclib/sources), [base/fs/rdr2/csc/record.mgr/bmreclib/makefile](../../base/fs/rdr2/csc/record.mgr/bmreclib/makefile) | `bmlayer` | `LIBRARY` |
| [base/fs/rdr2/csc/record.mgr/daytona](../../base/fs/rdr2/csc/record.mgr/daytona) | 5 | [base/fs/rdr2/csc/record.mgr/daytona/sources](../../base/fs/rdr2/csc/record.mgr/daytona/sources), [base/fs/rdr2/csc/record.mgr/daytona/makefile](../../base/fs/rdr2/csc/record.mgr/daytona/makefile) | `rec_mngr` | `LIBRARY` |
| [base/fs/rdr2/csc/record.mgr/daytona/nullincs.tmp](../../base/fs/rdr2/csc/record.mgr/daytona/nullincs.tmp) | 11 | — | — | — |
| [base/fs/rdr2/csc/record.mgr/inc.tmp](../../base/fs/rdr2/csc/record.mgr/inc.tmp) | 1 | — | — | — |
| [base/fs/rdr2/csc/record.mgr/umreclib](../../base/fs/rdr2/csc/record.mgr/umreclib) | 8 | [base/fs/rdr2/csc/record.mgr/umreclib/sources](../../base/fs/rdr2/csc/record.mgr/umreclib/sources), [base/fs/rdr2/csc/record.mgr/umreclib/makefile](../../base/fs/rdr2/csc/record.mgr/umreclib/makefile) | `oslayeru` | `LIBRARY` |
| [base/fs/rdr2/csc/usermode](../../base/fs/rdr2/csc/usermode) | 6 | [base/fs/rdr2/csc/usermode/dirs](../../base/fs/rdr2/csc/usermode/dirs) | — | — |
| [base/fs/rdr2/csc/usermode/db](../../base/fs/rdr2/csc/usermode/db) | 6 | [base/fs/rdr2/csc/usermode/db/dirs](../../base/fs/rdr2/csc/usermode/db/dirs) | — | — |
| [base/fs/rdr2/csc/usermode/db/daytona](../../base/fs/rdr2/csc/usermode/db/daytona) | 3 | [base/fs/rdr2/csc/usermode/db/daytona/sources](../../base/fs/rdr2/csc/usermode/db/daytona/sources), [base/fs/rdr2/csc/usermode/db/daytona/makefile](../../base/fs/rdr2/csc/usermode/db/daytona/makefile) | `db` | `PROGRAM` |
| [base/fs/rdr2/csc/usermode/lib3](../../base/fs/rdr2/csc/usermode/lib3) | 9 | [base/fs/rdr2/csc/usermode/lib3/dirs](../../base/fs/rdr2/csc/usermode/lib3/dirs) | — | — |
| [base/fs/rdr2/csc/usermode/lib3/daytona](../../base/fs/rdr2/csc/usermode/lib3/daytona) | 2 | [base/fs/rdr2/csc/usermode/lib3/daytona/sources](../../base/fs/rdr2/csc/usermode/lib3/daytona/sources), [base/fs/rdr2/csc/usermode/lib3/daytona/makefile](../../base/fs/rdr2/csc/usermode/lib3/daytona/makefile) | `lib3` | `LIBRARY` |
| [base/fs/rdr2/csc/usermode/reint](../../base/fs/rdr2/csc/usermode/reint) | 64 | [base/fs/rdr2/csc/usermode/reint/dirs](../../base/fs/rdr2/csc/usermode/reint/dirs) | — | — |
| [base/fs/rdr2/csc/usermode/reint/daytona](../../base/fs/rdr2/csc/usermode/reint/daytona) | 3 | [base/fs/rdr2/csc/usermode/reint/daytona/sources](../../base/fs/rdr2/csc/usermode/reint/daytona/sources), [base/fs/rdr2/csc/usermode/reint/daytona/makefile](../../base/fs/rdr2/csc/usermode/reint/daytona/makefile) | `cscdll` | `DYNLINK` |
| [base/fs/rdr2/csc/usermode/reint/test](../../base/fs/rdr2/csc/usermode/reint/test) | 7 | [base/fs/rdr2/csc/usermode/reint/test/sources](../../base/fs/rdr2/csc/usermode/reint/test/sources), [base/fs/rdr2/csc/usermode/reint/test/makefile](../../base/fs/rdr2/csc/usermode/reint/test/makefile) | `apitst` | `PROGRAM` |
| [base/fs/rdr2/csc/util](../../base/fs/rdr2/csc/util) | 1 | [base/fs/rdr2/csc/util/dirs](../../base/fs/rdr2/csc/util/dirs) | — | — |
| [base/fs/rdr2/csc/util/cscgetinfo](../../base/fs/rdr2/csc/util/cscgetinfo) | 4 | [base/fs/rdr2/csc/util/cscgetinfo/sources](../../base/fs/rdr2/csc/util/cscgetinfo/sources), [base/fs/rdr2/csc/util/cscgetinfo/makefile](../../base/fs/rdr2/csc/util/cscgetinfo/makefile) | `cscgetinfo` | `PROGRAM` |
| [base/fs/rdr2/csc/util/cscgetloc](../../base/fs/rdr2/csc/util/cscgetloc) | 4 | [base/fs/rdr2/csc/util/cscgetloc/sources](../../base/fs/rdr2/csc/util/cscgetloc/sources), [base/fs/rdr2/csc/util/cscgetloc/makefile](../../base/fs/rdr2/csc/util/cscgetloc/makefile) | `cscgetloc` | `PROGRAM` |
| [base/fs/rdr2/csc/util/cscqueryinfo](../../base/fs/rdr2/csc/util/cscqueryinfo) | 4 | [base/fs/rdr2/csc/util/cscqueryinfo/sources](../../base/fs/rdr2/csc/util/cscqueryinfo/sources), [base/fs/rdr2/csc/util/cscqueryinfo/makefile](../../base/fs/rdr2/csc/util/cscqueryinfo/makefile) | `cscqueryinfo` | `PROGRAM` |
| [base/fs/rdr2/csc/util/cscutil](../../base/fs/rdr2/csc/util/cscutil) | 9 | [base/fs/rdr2/csc/util/cscutil/dirs](../../base/fs/rdr2/csc/util/cscutil/dirs) | — | — |
| [base/fs/rdr2/csc/util/cscutil/external](../../base/fs/rdr2/csc/util/cscutil/external) | 2 | [base/fs/rdr2/csc/util/cscutil/external/sources](../../base/fs/rdr2/csc/util/cscutil/external/sources), [base/fs/rdr2/csc/util/cscutil/external/makefile](../../base/fs/rdr2/csc/util/cscutil/external/makefile) | `cscutil2` | `PROGRAM` |
| [base/fs/rdr2/csc/util/cscutil/internal](../../base/fs/rdr2/csc/util/cscutil/internal) | 2 | [base/fs/rdr2/csc/util/cscutil/internal/sources](../../base/fs/rdr2/csc/util/cscutil/internal/sources), [base/fs/rdr2/csc/util/cscutil/internal/makefile](../../base/fs/rdr2/csc/util/cscutil/internal/makefile) | `cscutil` | `PROGRAM` |
| [base/fs/rdr2/csc/util/rovdo](../../base/fs/rdr2/csc/util/rovdo) | 4 | [base/fs/rdr2/csc/util/rovdo/sources](../../base/fs/rdr2/csc/util/rovdo/sources), [base/fs/rdr2/csc/util/rovdo/makefile](../../base/fs/rdr2/csc/util/rovdo/makefile) | `rovdo` | `PROGRAM` |
| [base/fs/rdr2/drt](../../base/fs/rdr2/drt) | 1 | [base/fs/rdr2/drt/dirs](../../base/fs/rdr2/drt/dirs) | — | — |
| [base/fs/rdr2/drt/daytona](../../base/fs/rdr2/drt/daytona) | 8 | [base/fs/rdr2/drt/daytona/sources](../../base/fs/rdr2/drt/daytona/sources), [base/fs/rdr2/drt/daytona/makefile](../../base/fs/rdr2/drt/daytona/makefile) | `rxdrt` | `PROGRAM` |
| [base/fs/rdr2/inc](../../base/fs/rdr2/inc) | 37 | — | — | — |
| [base/fs/rdr2/rdbss](../../base/fs/rdr2/rdbss) | 36 | [base/fs/rdr2/rdbss/dirs](../../base/fs/rdr2/rdbss/dirs) | — | — |
| [base/fs/rdr2/rdbss/cairo](../../base/fs/rdr2/rdbss/cairo) | 2 | [base/fs/rdr2/rdbss/cairo/sources](../../base/fs/rdr2/rdbss/cairo/sources), [base/fs/rdr2/rdbss/cairo/makefile](../../base/fs/rdr2/rdbss/cairo/makefile) | `rdbss` | `EXPORT_DRIVER` |
| [base/fs/rdr2/rdbss/copysup.nt](../../base/fs/rdr2/rdbss/copysup.nt) | 3 | [base/fs/rdr2/rdbss/copysup.nt/dirs](../../base/fs/rdr2/rdbss/copysup.nt/dirs) | — | — |
| [base/fs/rdr2/rdbss/copysup.nt/daytona](../../base/fs/rdr2/rdbss/copysup.nt/daytona) | 3 | [base/fs/rdr2/rdbss/copysup.nt/daytona/sources](../../base/fs/rdr2/rdbss/copysup.nt/daytona/sources), [base/fs/rdr2/rdbss/copysup.nt/daytona/makefile](../../base/fs/rdr2/rdbss/copysup.nt/daytona/makefile) | `copysup` | `LIBRARY` |
| [base/fs/rdr2/rdbss/dav.mrx](../../base/fs/rdr2/rdbss/dav.mrx) | 1 | [base/fs/rdr2/rdbss/dav.mrx/dirs](../../base/fs/rdr2/rdbss/dav.mrx/dirs) | — | — |
| [base/fs/rdr2/rdbss/dav.mrx/dav2kd](../../base/fs/rdr2/rdbss/dav.mrx/dav2kd) | 10 | [base/fs/rdr2/rdbss/dav.mrx/dav2kd/sources](../../base/fs/rdr2/rdbss/dav.mrx/dav2kd/sources), [base/fs/rdr2/rdbss/dav.mrx/dav2kd/makefile](../../base/fs/rdr2/rdbss/dav.mrx/dav2kd/makefile) | `dav2kd` | `DYNLINK` |
| [base/fs/rdr2/rdbss/dav.mrx/inc](../../base/fs/rdr2/rdbss/dav.mrx/inc) | 2 | — | — | — |
| [base/fs/rdr2/rdbss/dav.mrx/reflector](../../base/fs/rdr2/rdbss/dav.mrx/reflector) | 1 | [base/fs/rdr2/rdbss/dav.mrx/reflector/dirs](../../base/fs/rdr2/rdbss/dav.mrx/reflector/dirs) | — | — |
| [base/fs/rdr2/rdbss/dav.mrx/reflector/kernel](../../base/fs/rdr2/rdbss/dav.mrx/reflector/kernel) | 5 | [base/fs/rdr2/rdbss/dav.mrx/reflector/kernel/sources](../../base/fs/rdr2/rdbss/dav.mrx/reflector/kernel/sources), [base/fs/rdr2/rdbss/dav.mrx/reflector/kernel/makefile](../../base/fs/rdr2/rdbss/dav.mrx/reflector/kernel/makefile) | `umrx` | `LIBRARY` |
| [base/fs/rdr2/rdbss/dav.mrx/reflector/user](../../base/fs/rdr2/rdbss/dav.mrx/reflector/user) | 8 | [base/fs/rdr2/rdbss/dav.mrx/reflector/user/sources](../../base/fs/rdr2/rdbss/dav.mrx/reflector/user/sources), [base/fs/rdr2/rdbss/dav.mrx/reflector/user/makefile](../../base/fs/rdr2/rdbss/dav.mrx/reflector/user/makefile) | `reflctor` | `LIBRARY` |
| [base/fs/rdr2/rdbss/dav.mrx/scripts](../../base/fs/rdr2/rdbss/dav.mrx/scripts) | 4 | — | — | — |
| [base/fs/rdr2/rdbss/dav.mrx/test](../../base/fs/rdr2/rdbss/dav.mrx/test) | 3 | [base/fs/rdr2/rdbss/dav.mrx/test/sources](../../base/fs/rdr2/rdbss/dav.mrx/test/sources), [base/fs/rdr2/rdbss/dav.mrx/test/makefile](../../base/fs/rdr2/rdbss/dav.mrx/test/makefile) | `davtest` | `PROGRAM` |
| [base/fs/rdr2/rdbss/dav.mrx/webdav](../../base/fs/rdr2/rdbss/dav.mrx/webdav) | 4 | [base/fs/rdr2/rdbss/dav.mrx/webdav/dirs](../../base/fs/rdr2/rdbss/dav.mrx/webdav/dirs) | — | — |
| [base/fs/rdr2/rdbss/dav.mrx/webdav/client](../../base/fs/rdr2/rdbss/dav.mrx/webdav/client) | 15 | [base/fs/rdr2/rdbss/dav.mrx/webdav/client/sources](../../base/fs/rdr2/rdbss/dav.mrx/webdav/client/sources), [base/fs/rdr2/rdbss/dav.mrx/webdav/client/makefile](../../base/fs/rdr2/rdbss/dav.mrx/webdav/client/makefile) | `davclnt` | `DYNLINK` |
| [base/fs/rdr2/rdbss/dav.mrx/webdav/inc](../../base/fs/rdr2/rdbss/dav.mrx/webdav/inc) | 5 | [base/fs/rdr2/rdbss/dav.mrx/webdav/inc/sources](../../base/fs/rdr2/rdbss/dav.mrx/webdav/inc/sources), [base/fs/rdr2/rdbss/dav.mrx/webdav/inc/makefile](../../base/fs/rdr2/rdbss/dav.mrx/webdav/inc/makefile) | — | `LIBRARY` |
| [base/fs/rdr2/rdbss/dav.mrx/webdav/inf](../../base/fs/rdr2/rdbss/dav.mrx/webdav/inf) | 4 | [base/fs/rdr2/rdbss/dav.mrx/webdav/inf/sources](../../base/fs/rdr2/rdbss/dav.mrx/webdav/inf/sources), [base/fs/rdr2/rdbss/dav.mrx/webdav/inf/makefile](../../base/fs/rdr2/rdbss/dav.mrx/webdav/inf/makefile) | `inf` | `notarget` |
| [base/fs/rdr2/rdbss/dav.mrx/webdav/inf/usa](../../base/fs/rdr2/rdbss/dav.mrx/webdav/inf/usa) | 1 | — | — | — |
| [base/fs/rdr2/rdbss/dav.mrx/webdav/kernel](../../base/fs/rdr2/rdbss/dav.mrx/webdav/kernel) | 29 | [base/fs/rdr2/rdbss/dav.mrx/webdav/kernel/sources](../../base/fs/rdr2/rdbss/dav.mrx/webdav/kernel/sources), [base/fs/rdr2/rdbss/dav.mrx/webdav/kernel/makefile](../../base/fs/rdr2/rdbss/dav.mrx/webdav/kernel/makefile) | `mrxdav` | `EXPORT_DRIVER` |
| [base/fs/rdr2/rdbss/dav.mrx/webdav/server](../../base/fs/rdr2/rdbss/dav.mrx/webdav/server) | 30 | [base/fs/rdr2/rdbss/dav.mrx/webdav/server/sources](../../base/fs/rdr2/rdbss/dav.mrx/webdav/server/sources), [base/fs/rdr2/rdbss/dav.mrx/webdav/server/makefile](../../base/fs/rdr2/rdbss/dav.mrx/webdav/server/makefile) | `WebClnt` | `DYNLINK` |
| [base/fs/rdr2/rdbss/dav.mrx/webdav/util](../../base/fs/rdr2/rdbss/dav.mrx/webdav/util) | 3 | [base/fs/rdr2/rdbss/dav.mrx/webdav/util/sources](../../base/fs/rdr2/rdbss/dav.mrx/webdav/util/sources), [base/fs/rdr2/rdbss/dav.mrx/webdav/util/makefile](../../base/fs/rdr2/rdbss/dav.mrx/webdav/util/makefile) | `credavsrv` | `PROGRAM` |
| [base/fs/rdr2/rdbss/daytona](../../base/fs/rdr2/rdbss/daytona) | 2 | [base/fs/rdr2/rdbss/daytona/sources](../../base/fs/rdr2/rdbss/daytona/sources), [base/fs/rdr2/rdbss/daytona/makefile](../../base/fs/rdr2/rdbss/daytona/makefile) | `rdbss` | `LIBRARY` |
| [base/fs/rdr2/rdbss/ifs.mrx](../../base/fs/rdr2/rdbss/ifs.mrx) | 1 | [base/fs/rdr2/rdbss/ifs.mrx/dirs](../../base/fs/rdr2/rdbss/ifs.mrx/dirs) | — | — |
| [base/fs/rdr2/rdbss/ifs.mrx/inc](../../base/fs/rdr2/rdbss/ifs.mrx/inc) | 1 | — | — | — |
| [base/fs/rdr2/rdbss/ifs.mrx/npdll](../../base/fs/rdr2/rdbss/ifs.mrx/npdll) | 7 | [base/fs/rdr2/rdbss/ifs.mrx/npdll/sources](../../base/fs/rdr2/rdbss/ifs.mrx/npdll/sources), [base/fs/rdr2/rdbss/ifs.mrx/npdll/makefile](../../base/fs/rdr2/rdbss/ifs.mrx/npdll/makefile) | `ifsmrxnp` | `DYNLINK` |
| [base/fs/rdr2/rdbss/ifs.mrx/sys](../../base/fs/rdr2/rdbss/ifs.mrx/sys) | 46 | [base/fs/rdr2/rdbss/ifs.mrx/sys/sources](../../base/fs/rdr2/rdbss/ifs.mrx/sys/sources), [base/fs/rdr2/rdbss/ifs.mrx/sys/makefile](../../base/fs/rdr2/rdbss/ifs.mrx/sys/makefile) | — | — |
| [base/fs/rdr2/rdbss/ifs.mrx/util](../../base/fs/rdr2/rdbss/ifs.mrx/util) | 0 | — | — | — |
| [base/fs/rdr2/rdbss/ifs.mrx/util/ifsrdr](../../base/fs/rdr2/rdbss/ifs.mrx/util/ifsrdr) | 5 | [base/fs/rdr2/rdbss/ifs.mrx/util/ifsrdr/sources](../../base/fs/rdr2/rdbss/ifs.mrx/util/ifsrdr/sources), [base/fs/rdr2/rdbss/ifs.mrx/util/ifsrdr/makefile](../../base/fs/rdr2/rdbss/ifs.mrx/util/ifsrdr/makefile) | `ifsrdr` | `LIBRARY` |
| [base/fs/rdr2/rdbss/ifskit.mrx](../../base/fs/rdr2/rdbss/ifskit.mrx) | 1 | [base/fs/rdr2/rdbss/ifskit.mrx/dirs](../../base/fs/rdr2/rdbss/ifskit.mrx/dirs) | — | — |
| [base/fs/rdr2/rdbss/ifskit.mrx/nulmrx](../../base/fs/rdr2/rdbss/ifskit.mrx/nulmrx) | 2 | [base/fs/rdr2/rdbss/ifskit.mrx/nulmrx/dirs](../../base/fs/rdr2/rdbss/ifskit.mrx/nulmrx/dirs) | — | — |
| [base/fs/rdr2/rdbss/ifskit.mrx/nulmrx/dll](../../base/fs/rdr2/rdbss/ifskit.mrx/nulmrx/dll) | 7 | [base/fs/rdr2/rdbss/ifskit.mrx/nulmrx/dll/sources](../../base/fs/rdr2/rdbss/ifskit.mrx/nulmrx/dll/sources), [base/fs/rdr2/rdbss/ifskit.mrx/nulmrx/dll/makefile](../../base/fs/rdr2/rdbss/ifskit.mrx/nulmrx/dll/makefile) | `nulmrxnp` | `DYNLINK` |
| [base/fs/rdr2/rdbss/ifskit.mrx/nulmrx/sys](../../base/fs/rdr2/rdbss/ifskit.mrx/nulmrx/sys) | 29 | [base/fs/rdr2/rdbss/ifskit.mrx/nulmrx/sys/sources](../../base/fs/rdr2/rdbss/ifskit.mrx/nulmrx/sys/sources), [base/fs/rdr2/rdbss/ifskit.mrx/nulmrx/sys/makefile](../../base/fs/rdr2/rdbss/ifskit.mrx/nulmrx/sys/makefile) | — | — |
| [base/fs/rdr2/rdbss/ifskit.mrx/smbmrx](../../base/fs/rdr2/rdbss/ifskit.mrx/smbmrx) | 2 | [base/fs/rdr2/rdbss/ifskit.mrx/smbmrx/dirs](../../base/fs/rdr2/rdbss/ifskit.mrx/smbmrx/dirs) | — | — |
| [base/fs/rdr2/rdbss/ifskit.mrx/smbmrx/dll](../../base/fs/rdr2/rdbss/ifskit.mrx/smbmrx/dll) | 7 | [base/fs/rdr2/rdbss/ifskit.mrx/smbmrx/dll/sources](../../base/fs/rdr2/rdbss/ifskit.mrx/smbmrx/dll/sources), [base/fs/rdr2/rdbss/ifskit.mrx/smbmrx/dll/makefile](../../base/fs/rdr2/rdbss/ifskit.mrx/smbmrx/dll/makefile) | `smbmrxnp` | `DYNLINK` |
| [base/fs/rdr2/rdbss/ifskit.mrx/smbmrx/exe](../../base/fs/rdr2/rdbss/ifskit.mrx/smbmrx/exe) | 8 | [base/fs/rdr2/rdbss/ifskit.mrx/smbmrx/exe/sources](../../base/fs/rdr2/rdbss/ifskit.mrx/smbmrx/exe/sources), [base/fs/rdr2/rdbss/ifskit.mrx/smbmrx/exe/makefile](../../base/fs/rdr2/rdbss/ifskit.mrx/smbmrx/exe/makefile) | `smbrdr` | `PROGRAM` |
| [base/fs/rdr2/rdbss/ifskit.mrx/smbmrx/sys](../../base/fs/rdr2/rdbss/ifskit.mrx/smbmrx/sys) | 60 | [base/fs/rdr2/rdbss/ifskit.mrx/smbmrx/sys/sources](../../base/fs/rdr2/rdbss/ifskit.mrx/smbmrx/sys/sources), [base/fs/rdr2/rdbss/ifskit.mrx/smbmrx/sys/makefile](../../base/fs/rdr2/rdbss/ifskit.mrx/smbmrx/sys/makefile) | — | — |
| [base/fs/rdr2/rdbss/local_nt.mrx](../../base/fs/rdr2/rdbss/local_nt.mrx) | 11 | [base/fs/rdr2/rdbss/local_nt.mrx/sources](../../base/fs/rdr2/rdbss/local_nt.mrx/sources), [base/fs/rdr2/rdbss/local_nt.mrx/makefile](../../base/fs/rdr2/rdbss/local_nt.mrx/makefile) | `mrxlocal` | `DRIVER` |
| [base/fs/rdr2/rdbss/monolithic](../../base/fs/rdr2/rdbss/monolithic) | 3 | [base/fs/rdr2/rdbss/monolithic/sources](../../base/fs/rdr2/rdbss/monolithic/sources), [base/fs/rdr2/rdbss/monolithic/makefile](../../base/fs/rdr2/rdbss/monolithic/makefile) | `rdbsslib` | `LIBRARY` |
| [base/fs/rdr2/rdbss/obsolete](../../base/fs/rdr2/rdbss/obsolete) | 20 | — | — | — |
| [base/fs/rdr2/rdbss/proxy.mrx](../../base/fs/rdr2/rdbss/proxy.mrx) | 26 | [base/fs/rdr2/rdbss/proxy.mrx/dirs](../../base/fs/rdr2/rdbss/proxy.mrx/dirs) | — | — |
| [base/fs/rdr2/rdbss/proxy.mrx/daytona](../../base/fs/rdr2/rdbss/proxy.mrx/daytona) | 2 | [base/fs/rdr2/rdbss/proxy.mrx/daytona/sources](../../base/fs/rdr2/rdbss/proxy.mrx/daytona/sources), [base/fs/rdr2/rdbss/proxy.mrx/daytona/makefile](../../base/fs/rdr2/rdbss/proxy.mrx/daytona/makefile) | — | — |
| [base/fs/rdr2/rdbss/proxy.mrx/nulldir](../../base/fs/rdr2/rdbss/proxy.mrx/nulldir) | 1 | — | — | — |
| [base/fs/rdr2/rdbss/smb.mrx](../../base/fs/rdr2/rdbss/smb.mrx) | 85 | [base/fs/rdr2/rdbss/smb.mrx/dirs](../../base/fs/rdr2/rdbss/smb.mrx/dirs) | — | — |
| [base/fs/rdr2/rdbss/smb.mrx/cairo](../../base/fs/rdr2/rdbss/smb.mrx/cairo) | 2 | [base/fs/rdr2/rdbss/smb.mrx/cairo/sources](../../base/fs/rdr2/rdbss/smb.mrx/cairo/sources), [base/fs/rdr2/rdbss/smb.mrx/cairo/makefile](../../base/fs/rdr2/rdbss/smb.mrx/cairo/makefile) | — | — |
| [base/fs/rdr2/rdbss/smb.mrx/csc.nt5](../../base/fs/rdr2/rdbss/smb.mrx/csc.nt5) | 11 | [base/fs/rdr2/rdbss/smb.mrx/csc.nt5/sources](../../base/fs/rdr2/rdbss/smb.mrx/csc.nt5/sources), [base/fs/rdr2/rdbss/smb.mrx/csc.nt5/makefile](../../base/fs/rdr2/rdbss/smb.mrx/csc.nt5/makefile) | `nt5csc` | `DRIVER_LIBRARY` |
| [base/fs/rdr2/rdbss/smb.mrx/daytona](../../base/fs/rdr2/rdbss/smb.mrx/daytona) | 4 | [base/fs/rdr2/rdbss/smb.mrx/daytona/sources](../../base/fs/rdr2/rdbss/smb.mrx/daytona/sources), [base/fs/rdr2/rdbss/smb.mrx/daytona/makefile](../../base/fs/rdr2/rdbss/smb.mrx/daytona/makefile) | — | — |
| [base/fs/rdr2/rdbss/smb.mrx/rdrssp](../../base/fs/rdr2/rdbss/smb.mrx/rdrssp) | 22 | [base/fs/rdr2/rdbss/smb.mrx/rdrssp/sources](../../base/fs/rdr2/rdbss/smb.mrx/rdrssp/sources), [base/fs/rdr2/rdbss/smb.mrx/rdrssp/makefile](../../base/fs/rdr2/rdbss/smb.mrx/rdrssp/makefile) | `rdrssp` | `LIBRARY` |
| [base/fs/rdr2/rdbss/smb.mrx/umt_stff](../../base/fs/rdr2/rdbss/smb.mrx/umt_stff) | 7 | [base/fs/rdr2/rdbss/smb.mrx/umt_stff/sources](../../base/fs/rdr2/rdbss/smb.mrx/umt_stff/sources), [base/fs/rdr2/rdbss/smb.mrx/umt_stff/makefile](../../base/fs/rdr2/rdbss/smb.mrx/umt_stff/makefile) | `umt_stff` | `LIBRARY` |
| [base/fs/rdr2/rdbss/wrapper.sav](../../base/fs/rdr2/rdbss/wrapper.sav) | 6 | — | — | — |
| [base/fs/rdr2/rdr2kd](../../base/fs/rdr2/rdr2kd) | 11 | [base/fs/rdr2/rdr2kd/sources](../../base/fs/rdr2/rdr2kd/sources), [base/fs/rdr2/rdr2kd/makefile](../../base/fs/rdr2/rdr2kd/makefile) | `rdr2kd` | `DYNLINK` |
| [base/fs/rdr2/rxce](../../base/fs/rdr2/rxce) | 27 | [base/fs/rdr2/rxce/dirs](../../base/fs/rdr2/rxce/dirs) | — | — |
| [base/fs/rdr2/rxce/daytona](../../base/fs/rdr2/rxce/daytona) | 11 | [base/fs/rdr2/rxce/daytona/sources](../../base/fs/rdr2/rxce/daytona/sources), [base/fs/rdr2/rxce/daytona/makefile](../../base/fs/rdr2/rxce/daytona/makefile) | `rxce` | `DRIVER_LIBRARY` |
| [base/fs/rdr2/setup](../../base/fs/rdr2/setup) | 10 | [base/fs/rdr2/setup/dirs](../../base/fs/rdr2/setup/dirs) | — | — |
| [base/fs/rdr2/setup/daytona](../../base/fs/rdr2/setup/daytona) | 3 | [base/fs/rdr2/setup/daytona/sources](../../base/fs/rdr2/setup/daytona/sources), [base/fs/rdr2/setup/daytona/makefile](../../base/fs/rdr2/setup/daytona/makefile) | — | — |
| [base/fs/rdr2/smbrdr](../../base/fs/rdr2/smbrdr) | 7 | [base/fs/rdr2/smbrdr/sources](../../base/fs/rdr2/smbrdr/sources), [base/fs/rdr2/smbrdr/makefile](../../base/fs/rdr2/smbrdr/makefile) | `smbrdr` | `LIBRARY` |
| [base/fs/rdr2/wmi](../../base/fs/rdr2/wmi) | 8 | [base/fs/rdr2/wmi/sources](../../base/fs/rdr2/wmi/sources), [base/fs/rdr2/wmi/makefile](../../base/fs/rdr2/wmi/makefile) | `wmlkm` | `LIBRARY` |
| [base/fs/remotefs](../../base/fs/remotefs) | 2 | [base/fs/remotefs/dirs](../../base/fs/remotefs/dirs) | — | — |
| [base/fs/remotefs/dfs](../../base/fs/remotefs/dfs) | 2 | [base/fs/remotefs/dfs/dirs](../../base/fs/remotefs/dfs/dirs) | — | — |
| [base/fs/remotefs/dfs/dfsinit](../../base/fs/remotefs/dfs/dfsinit) | 4 | [base/fs/remotefs/dfs/dfsinit/sources](../../base/fs/remotefs/dfs/dfsinit/sources), [base/fs/remotefs/dfs/dfsinit/makefile](../../base/fs/remotefs/dfs/dfsinit/makefile) | `dfsinit` | `PROGRAM` |
| [base/fs/remotefs/dfs/dfsserver](../../base/fs/remotefs/dfs/dfsserver) | 1 | [base/fs/remotefs/dfs/dfsserver/dirs](../../base/fs/remotefs/dfs/dfsserver/dirs) | — | — |
| [base/fs/remotefs/dfs/dfsserver/referralserver](../../base/fs/remotefs/dfs/dfsserver/referralserver) | 8 | [base/fs/remotefs/dfs/dfsserver/referralserver/sources](../../base/fs/remotefs/dfs/dfsserver/referralserver/sources), [base/fs/remotefs/dfs/dfsserver/referralserver/makefile](../../base/fs/remotefs/dfs/dfsserver/referralserver/makefile) | `DfsSvc` | `PROGRAM` |
| [base/fs/remotefs/dfs/dfsserver/reflector](../../base/fs/remotefs/dfs/dfsserver/reflector) | 1 | [base/fs/remotefs/dfs/dfsserver/reflector/dirs](../../base/fs/remotefs/dfs/dfsserver/reflector/dirs) | — | — |
| [base/fs/remotefs/dfs/dfsserver/reflector/kernel](../../base/fs/remotefs/dfs/dfsserver/reflector/kernel) | 8 | [base/fs/remotefs/dfs/dfsserver/reflector/kernel/sources](../../base/fs/remotefs/dfs/dfsserver/reflector/kernel/sources), [base/fs/remotefs/dfs/dfsserver/reflector/kernel/makefile](../../base/fs/remotefs/dfs/dfsserver/reflector/kernel/makefile) | `umrx` | `LIBRARY` |
| [base/fs/remotefs/dfs/dfsserver/serverfilter](../../base/fs/remotefs/dfs/dfsserver/serverfilter) | 9 | [base/fs/remotefs/dfs/dfsserver/serverfilter/sources](../../base/fs/remotefs/dfs/dfsserver/serverfilter/sources), [base/fs/remotefs/dfs/dfsserver/serverfilter/makefile](../../base/fs/remotefs/dfs/dfsserver/serverfilter/makefile) | `dfs` | `DRIVER` |
| [base/fs/remotefs/dfs/dfsserver/serverfilterapi](../../base/fs/remotefs/dfs/dfsserver/serverfilterapi) | 3 | [base/fs/remotefs/dfs/dfsserver/serverfilterapi/sources](../../base/fs/remotefs/dfs/dfsserver/serverfilterapi/sources), [base/fs/remotefs/dfs/dfsserver/serverfilterapi/makefile](../../base/fs/remotefs/dfs/dfsserver/serverfilterapi/makefile) | `dfsFilterApi` | `LIBRARY` |
| [base/fs/remotefs/dfs/dfsserver/serverlibrary](../../base/fs/remotefs/dfs/dfsserver/serverlibrary) | 55 | [base/fs/remotefs/dfs/dfsserver/serverlibrary/sources](../../base/fs/remotefs/dfs/dfsserver/serverlibrary/sources), [base/fs/remotefs/dfs/dfsserver/serverlibrary/makefile](../../base/fs/remotefs/dfs/dfsserver/serverlibrary/makefile) | `dfssrv` | `LIBRARY` |
| [base/fs/remotefs/dfs/inc](../../base/fs/remotefs/dfs/inc) | 21 | — | — | — |
| [base/fs/remotefs/dfs/lib](../../base/fs/remotefs/dfs/lib) | 1 | [base/fs/remotefs/dfs/lib/dirs](../../base/fs/remotefs/dfs/lib/dirs) | — | — |
| [base/fs/remotefs/dfs/lib/misc](../../base/fs/remotefs/dfs/lib/misc) | 6 | [base/fs/remotefs/dfs/lib/misc/sources](../../base/fs/remotefs/dfs/lib/misc/sources), [base/fs/remotefs/dfs/lib/misc/makefile](../../base/fs/remotefs/dfs/lib/misc/makefile) | `dfsmisc` | `LIBRARY` |
| [base/fs/remotefs/dfs/lib/prefix](../../base/fs/remotefs/dfs/lib/prefix) | 7 | [base/fs/remotefs/dfs/lib/prefix/dirs](../../base/fs/remotefs/dfs/lib/prefix/dirs) | — | — |
| [base/fs/remotefs/dfs/lib/prefix/km](../../base/fs/remotefs/dfs/lib/prefix/km) | 2 | [base/fs/remotefs/dfs/lib/prefix/km/sources](../../base/fs/remotefs/dfs/lib/prefix/km/sources), [base/fs/remotefs/dfs/lib/prefix/km/makefile](../../base/fs/remotefs/dfs/lib/prefix/km/makefile) | `dfskmprefix` | `LIBRARY` |
| [base/fs/remotefs/dfs/lib/prefix/um](../../base/fs/remotefs/dfs/lib/prefix/um) | 2 | [base/fs/remotefs/dfs/lib/prefix/um/sources](../../base/fs/remotefs/dfs/lib/prefix/um/sources), [base/fs/remotefs/dfs/lib/prefix/um/makefile](../../base/fs/remotefs/dfs/lib/prefix/um/makefile) | `dfsumprefix` | `LIBRARY` |
| [base/fs/remotefs/dfs/lib/shash](../../base/fs/remotefs/dfs/lib/shash) | 4 | [base/fs/remotefs/dfs/lib/shash/dirs](../../base/fs/remotefs/dfs/lib/shash/dirs) | — | — |
| [base/fs/remotefs/dfs/lib/shash/um](../../base/fs/remotefs/dfs/lib/shash/um) | 2 | [base/fs/remotefs/dfs/lib/shash/um/sources](../../base/fs/remotefs/dfs/lib/shash/um/sources), [base/fs/remotefs/dfs/lib/shash/um/makefile](../../base/fs/remotefs/dfs/lib/shash/um/makefile) | `dfshashum` | `LIBRARY` |
| [base/fs/remotefs/dfs/setup](../../base/fs/remotefs/dfs/setup) | 16 | [base/fs/remotefs/dfs/setup/sources](../../base/fs/remotefs/dfs/setup/sources), [base/fs/remotefs/dfs/setup/makefile](../../base/fs/remotefs/dfs/setup/makefile) | `dfssetup` | `DYNLINK` |
| [base/fs/remotefs/dfs/tests](../../base/fs/remotefs/dfs/tests) | 1 | [base/fs/remotefs/dfs/tests/dirs](../../base/fs/remotefs/dfs/tests/dirs) | — | — |
| [base/fs/remotefs/dfs/tests/apitest](../../base/fs/remotefs/dfs/tests/apitest) | 3 | [base/fs/remotefs/dfs/tests/apitest/sources](../../base/fs/remotefs/dfs/tests/apitest/sources), [base/fs/remotefs/dfs/tests/apitest/makefile](../../base/fs/remotefs/dfs/tests/apitest/makefile) | `ApiTest` | `PROGRAM` |
| [base/fs/remotefs/dfs/tests/referral](../../base/fs/remotefs/dfs/tests/referral) | 4 | [base/fs/remotefs/dfs/tests/referral/sources](../../base/fs/remotefs/dfs/tests/referral/sources), [base/fs/remotefs/dfs/tests/referral/makefile](../../base/fs/remotefs/dfs/tests/referral/makefile) | `ReferralTest` | `PROGRAM` |
| [base/fs/remotefs/dfs/tools](../../base/fs/remotefs/dfs/tools) | 1 | [base/fs/remotefs/dfs/tools/dirs](../../base/fs/remotefs/dfs/tools/dirs) | — | — |
| [base/fs/remotefs/dfs/tools/debug](../../base/fs/remotefs/dfs/tools/debug) | 4 | [base/fs/remotefs/dfs/tools/debug/sources](../../base/fs/remotefs/dfs/tools/debug/sources), [base/fs/remotefs/dfs/tools/debug/makefile](../../base/fs/remotefs/dfs/tools/debug/makefile) | `debug` | `LIBRARY` |
| [base/fs/remotefs/dfs/tools/dfsadmin](../../base/fs/remotefs/dfs/tools/dfsadmin) | 10 | [base/fs/remotefs/dfs/tools/dfsadmin/sources](../../base/fs/remotefs/dfs/tools/dfsadmin/sources), [base/fs/remotefs/dfs/tools/dfsadmin/makefile](../../base/fs/remotefs/dfs/tools/dfsadmin/makefile) | `dfsadmin` | `PROGRAM` |
| [base/fs/remotefs/dfs/tools/dfsapi](../../base/fs/remotefs/dfs/tools/dfsapi) | 3 | [base/fs/remotefs/dfs/tools/dfsapi/sources](../../base/fs/remotefs/dfs/tools/dfsapi/sources), [base/fs/remotefs/dfs/tools/dfsapi/makefile](../../base/fs/remotefs/dfs/tools/dfsapi/makefile) | `dfsapi` | `PROGRAM` |
| [base/fs/remotefs/dfs/tools/dfscmd](../../base/fs/remotefs/dfs/tools/dfscmd) | 15 | [base/fs/remotefs/dfs/tools/dfscmd/sources](../../base/fs/remotefs/dfs/tools/dfscmd/sources), [base/fs/remotefs/dfs/tools/dfscmd/makefile](../../base/fs/remotefs/dfs/tools/dfscmd/makefile) | `dfscmd` | `PROGRAM` |
| [base/fs/remotefs/dfs/tools/dfsutil](../../base/fs/remotefs/dfs/tools/dfsutil) | 12 | [base/fs/remotefs/dfs/tools/dfsutil/sources](../../base/fs/remotefs/dfs/tools/dfsutil/sources), [base/fs/remotefs/dfs/tools/dfsutil/makefile](../../base/fs/remotefs/dfs/tools/dfsutil/makefile) | `dfsutil` | `PROGRAM` |
| [base/fs/sis](../../base/fs/sis) | 1 | [base/fs/sis/dirs](../../base/fs/sis/dirs) | — | — |
| [base/fs/sis/filter](../../base/fs/sis/filter) | 28 | [base/fs/sis/filter/sources](../../base/fs/sis/filter/sources), [base/fs/sis/filter/makefile](../../base/fs/sis/filter/makefile) | `sis` | `DRIVER` |
| [base/fs/sis/groveler](../../base/fs/sis/groveler) | 67 | [base/fs/sis/groveler/dirs](../../base/fs/sis/groveler/dirs) | — | — |
| [base/fs/sis/groveler/grovctrl](../../base/fs/sis/groveler/grovctrl) | 4 | [base/fs/sis/groveler/grovctrl/sources](../../base/fs/sis/groveler/grovctrl/sources), [base/fs/sis/groveler/grovctrl/makefile](../../base/fs/sis/groveler/grovctrl/makefile) | `grovctrl` | `PROGRAM` |
| [base/fs/sis/groveler/groveler](../../base/fs/sis/groveler/groveler) | 4 | [base/fs/sis/groveler/groveler/sources](../../base/fs/sis/groveler/groveler/sources), [base/fs/sis/groveler/groveler/makefile](../../base/fs/sis/groveler/groveler/makefile) | `grovel` | `PROGRAM` |
| [base/fs/sis/groveler/grovmsg](../../base/fs/sis/groveler/grovmsg) | 3 | [base/fs/sis/groveler/grovmsg/sources](../../base/fs/sis/groveler/grovmsg/sources), [base/fs/sis/groveler/grovmsg/makefile](../../base/fs/sis/groveler/grovmsg/makefile) | `grovmsg` | `DYNLINK` |
| [base/fs/sis/groveler/grovperf](../../base/fs/sis/groveler/grovperf) | 5 | [base/fs/sis/groveler/grovperf/sources](../../base/fs/sis/groveler/grovperf/sources), [base/fs/sis/groveler/grovperf/makefile](../../base/fs/sis/groveler/grovperf/makefile) | `grovperf` | `DYNLINK` |
| [base/fs/sis/sisbkup](../../base/fs/sis/sisbkup) | 9 | [base/fs/sis/sisbkup/sources](../../base/fs/sis/sisbkup/sources), [base/fs/sis/sisbkup/makefile](../../base/fs/sis/sisbkup/makefile) | `sisbkup` | `DYNLINK` |
| [base/fs/sis/spec](../../base/fs/sis/spec) | 6 | — | — | — |
| [base/fs/sis/tools](../../base/fs/sis/tools) | 1 | [base/fs/sis/tools/dirs](../../base/fs/sis/tools/dirs) | — | — |
| [base/fs/sis/tools/cf](../../base/fs/sis/tools/cf) | 5 | [base/fs/sis/tools/cf/sources](../../base/fs/sis/tools/cf/sources), [base/fs/sis/tools/cf/makefile](../../base/fs/sis/tools/cf/makefile) | `cf` | `PROGRAM` |
| [base/fs/sis/tools/chksis](../../base/fs/sis/tools/chksis) | 4 | [base/fs/sis/tools/chksis/sources](../../base/fs/sis/tools/chksis/sources), [base/fs/sis/tools/chksis/makefile](../../base/fs/sis/tools/chksis/makefile) | `chksis` | `PROGRAM` |
| [base/fs/sis/tools/refcount](../../base/fs/sis/tools/refcount) | 4 | [base/fs/sis/tools/refcount/sources](../../base/fs/sis/tools/refcount/sources), [base/fs/sis/tools/refcount/makefile](../../base/fs/sis/tools/refcount/makefile) | `refcount` | `PROGRAM` |
| [base/fs/sis/tools/rpget](../../base/fs/sis/tools/rpget) | 3 | — | — | — |
| [base/fs/sis/tools/sisenum](../../base/fs/sis/tools/sisenum) | 5 | [base/fs/sis/tools/sisenum/sources](../../base/fs/sis/tools/sisenum/sources), [base/fs/sis/tools/sisenum/makefile](../../base/fs/sis/tools/sisenum/makefile) | `sisenum` | `PROGRAM` |
| [base/fs/sis/tools/sissetup](../../base/fs/sis/tools/sissetup) | 4 | [base/fs/sis/tools/sissetup/sources](../../base/fs/sis/tools/sissetup/sources), [base/fs/sis/tools/sissetup/makefile](../../base/fs/sis/tools/sissetup/makefile) | `sisSetup` | `PROGRAM` |
| [base/fs/sis/tools/volreparsetest](../../base/fs/sis/tools/volreparsetest) | 4 | [base/fs/sis/tools/volreparsetest/sources](../../base/fs/sis/tools/volreparsetest/sources), [base/fs/sis/tools/volreparsetest/makefile](../../base/fs/sis/tools/volreparsetest/makefile) | `volReparseTest` | `PROGRAM` |
| [base/fs/smbtrsup](../../base/fs/smbtrsup) | 6 | [base/fs/smbtrsup/sources](../../base/fs/smbtrsup/sources), [base/fs/smbtrsup/makefile](../../base/fs/smbtrsup/makefile) | `smbtrsup` | `LIBRARY` |
| [base/fs/srv](../../base/fs/srv) | 107 | [base/fs/srv/dirs](../../base/fs/srv/dirs) | — | — |
| [base/fs/srv/daytonam](../../base/fs/srv/daytonam) | 6 | [base/fs/srv/daytonam/sources](../../base/fs/srv/daytonam/sources), [base/fs/srv/daytonam/makefile](../../base/fs/srv/daytonam/makefile) | — | — |
| [base/fs/srv/srvkd](../../base/fs/srv/srvkd) | 5 | [base/fs/srv/srvkd/sources](../../base/fs/srv/srvkd/sources), [base/fs/srv/srvkd/makefile](../../base/fs/srv/srvkd/makefile) | `srvkd` | `DYNLINK` |
| [base/fs/udfs](../../base/fs/udfs) | 37 | [base/fs/udfs/sources](../../base/fs/udfs/sources), [base/fs/udfs/makefile](../../base/fs/udfs/makefile) | `udfs` | `DRIVER` |
| [base/fs/utils](../../base/fs/utils) | 1 | [base/fs/utils/dirs](../../base/fs/utils/dirs) | — | — |
| [base/fs/utils/aclconv](../../base/fs/utils/aclconv) | 1 | — | — | — |
| [base/fs/utils/asr_fmt](../../base/fs/utils/asr_fmt) | 8 | [base/fs/utils/asr_fmt/sources](../../base/fs/utils/asr_fmt/sources), [base/fs/utils/asr_fmt/makefile](../../base/fs/utils/asr_fmt/makefile) | `asr_fmt` | `PROGRAM` |
| [base/fs/utils/asr_fmt/inc](../../base/fs/utils/asr_fmt/inc) | 4 | — | — | — |
| [base/fs/utils/asrtools](../../base/fs/utils/asrtools) | 1 | [base/fs/utils/asrtools/dirs](../../base/fs/utils/asrtools/dirs) | — | — |
| [base/fs/utils/asrtools/asr_app](../../base/fs/utils/asrtools/asr_app) | 3 | [base/fs/utils/asrtools/asr_app/sources](../../base/fs/utils/asrtools/asr_app/sources), [base/fs/utils/asrtools/asr_app/makefile](../../base/fs/utils/asrtools/asr_app/makefile) | `asr_app` | `PROGRAM` |
| [base/fs/utils/asrtools/asr_pfu](../../base/fs/utils/asrtools/asr_pfu) | 4 | [base/fs/utils/asrtools/asr_pfu/sources](../../base/fs/utils/asrtools/asr_pfu/sources), [base/fs/utils/asrtools/asr_pfu/makefile](../../base/fs/utils/asrtools/asr_pfu/makefile) | `asr_pfu` | `PROGRAM` |
| [base/fs/utils/asrtools/asrsfgen](../../base/fs/utils/asrtools/asrsfgen) | 7 | [base/fs/utils/asrtools/asrsfgen/sources](../../base/fs/utils/asrtools/asrsfgen/sources), [base/fs/utils/asrtools/asrsfgen/makefile](../../base/fs/utils/asrtools/asrsfgen/makefile) | `asrsfgen` | `PROGRAM` |
| [base/fs/utils/asrtools/confdisk](../../base/fs/utils/asrtools/confdisk) | 8 | [base/fs/utils/asrtools/confdisk/sources](../../base/fs/utils/asrtools/confdisk/sources), [base/fs/utils/asrtools/confdisk/makefile](../../base/fs/utils/asrtools/confdisk/makefile) | `confdisk` | `PROGRAM` |
| [base/fs/utils/asrtools/wipedisk](../../base/fs/utils/asrtools/wipedisk) | 3 | [base/fs/utils/asrtools/wipedisk/sources](../../base/fs/utils/asrtools/wipedisk/sources), [base/fs/utils/asrtools/wipedisk/makefile](../../base/fs/utils/asrtools/wipedisk/makefile) | `wipedisk` | `PROGRAM` |
| [base/fs/utils/attrib](../../base/fs/utils/attrib) | 5 | [base/fs/utils/attrib/dirs](../../base/fs/utils/attrib/dirs) | — | — |
| [base/fs/utils/attrib/usa](../../base/fs/utils/attrib/usa) | 2 | [base/fs/utils/attrib/usa/sources](../../base/fs/utils/attrib/usa/sources), [base/fs/utils/attrib/usa/makefile](../../base/fs/utils/attrib/usa/makefile) | — | — |
| [base/fs/utils/autochk](../../base/fs/utils/autochk) | 4 | [base/fs/utils/autochk/dirs](../../base/fs/utils/autochk/dirs) | — | — |
| [base/fs/utils/autochk/daytona](../../base/fs/utils/autochk/daytona) | 2 | [base/fs/utils/autochk/daytona/sources](../../base/fs/utils/autochk/daytona/sources), [base/fs/utils/autochk/daytona/makefile](../../base/fs/utils/autochk/daytona/makefile) | — | — |
| [base/fs/utils/autoconv](../../base/fs/utils/autoconv) | 4 | [base/fs/utils/autoconv/dirs](../../base/fs/utils/autoconv/dirs) | — | — |
| [base/fs/utils/autoconv/daytona](../../base/fs/utils/autoconv/daytona) | 2 | [base/fs/utils/autoconv/daytona/sources](../../base/fs/utils/autoconv/daytona/sources), [base/fs/utils/autoconv/daytona/makefile](../../base/fs/utils/autoconv/daytona/makefile) | — | — |
| [base/fs/utils/autofmt](../../base/fs/utils/autofmt) | 4 | [base/fs/utils/autofmt/dirs](../../base/fs/utils/autofmt/dirs) | — | — |
| [base/fs/utils/autofmt/usa](../../base/fs/utils/autofmt/usa) | 2 | [base/fs/utils/autofmt/usa/sources](../../base/fs/utils/autofmt/usa/sources), [base/fs/utils/autofmt/usa/makefile](../../base/fs/utils/autofmt/usa/makefile) | — | — |
| [base/fs/utils/chcp](../../base/fs/utils/chcp) | 6 | [base/fs/utils/chcp/dirs](../../base/fs/utils/chcp/dirs) | — | — |
| [base/fs/utils/chcp/usa](../../base/fs/utils/chcp/usa) | 2 | [base/fs/utils/chcp/usa/sources](../../base/fs/utils/chcp/usa/sources), [base/fs/utils/chcp/usa/makefile](../../base/fs/utils/chcp/usa/makefile) | — | — |
| [base/fs/utils/chkdsk](../../base/fs/utils/chkdsk) | 4 | [base/fs/utils/chkdsk/dirs](../../base/fs/utils/chkdsk/dirs) | — | — |
| [base/fs/utils/chkdsk/usa](../../base/fs/utils/chkdsk/usa) | 2 | [base/fs/utils/chkdsk/usa/sources](../../base/fs/utils/chkdsk/usa/sources), [base/fs/utils/chkdsk/usa/makefile](../../base/fs/utils/chkdsk/usa/makefile) | — | — |
| [base/fs/utils/chkntfs](../../base/fs/utils/chkntfs) | 5 | [base/fs/utils/chkntfs/dirs](../../base/fs/utils/chkntfs/dirs) | — | — |
| [base/fs/utils/chkntfs/usa](../../base/fs/utils/chkntfs/usa) | 2 | [base/fs/utils/chkntfs/usa/sources](../../base/fs/utils/chkntfs/usa/sources), [base/fs/utils/chkntfs/usa/makefile](../../base/fs/utils/chkntfs/usa/makefile) | — | — |
| [base/fs/utils/cipher](../../base/fs/utils/cipher) | 8 | [base/fs/utils/cipher/sources](../../base/fs/utils/cipher/sources), [base/fs/utils/cipher/makefile](../../base/fs/utils/cipher/makefile) | `cipher` | `PROGRAM` |
| [base/fs/utils/cipher/obj](../../base/fs/utils/cipher/obj) | 0 | — | — | — |
| [base/fs/utils/cipher/obj/i386](../../base/fs/utils/cipher/obj/i386) | 2 | — | — | — |
| [base/fs/utils/comp](../../base/fs/utils/comp) | 5 | [base/fs/utils/comp/dirs](../../base/fs/utils/comp/dirs) | — | — |
| [base/fs/utils/comp/usa](../../base/fs/utils/comp/usa) | 2 | [base/fs/utils/comp/usa/sources](../../base/fs/utils/comp/usa/sources), [base/fs/utils/comp/usa/makefile](../../base/fs/utils/comp/usa/makefile) | — | — |
| [base/fs/utils/compact](../../base/fs/utils/compact) | 8 | [base/fs/utils/compact/sources](../../base/fs/utils/compact/sources), [base/fs/utils/compact/makefile](../../base/fs/utils/compact/makefile) | `compact` | `PROGRAM` |
| [base/fs/utils/compact/sdk](../../base/fs/utils/compact/sdk) | 3 | [base/fs/utils/compact/sdk/makefile](../../base/fs/utils/compact/sdk/makefile) | — | — |
| [base/fs/utils/component](../../base/fs/utils/component) | 16 | [base/fs/utils/component/sources](../../base/fs/utils/component/sources), [base/fs/utils/component/makefile](../../base/fs/utils/component/makefile) | — | `NOTARGET` |
| [base/fs/utils/convert](../../base/fs/utils/convert) | 5 | [base/fs/utils/convert/dirs](../../base/fs/utils/convert/dirs) | — | — |
| [base/fs/utils/convert/usa](../../base/fs/utils/convert/usa) | 2 | [base/fs/utils/convert/usa/sources](../../base/fs/utils/convert/usa/sources), [base/fs/utils/convert/usa/makefile](../../base/fs/utils/convert/usa/makefile) | — | — |
| [base/fs/utils/cryptmnu](../../base/fs/utils/cryptmnu) | 12 | [base/fs/utils/cryptmnu/sources](../../base/fs/utils/cryptmnu/sources), [base/fs/utils/cryptmnu/makefile](../../base/fs/utils/cryptmnu/makefile) | `cryptmnu` | `DYNLINK` |
| [base/fs/utils/cufat](../../base/fs/utils/cufat) | 1 | [base/fs/utils/cufat/dirs](../../base/fs/utils/cufat/dirs) | — | — |
| [base/fs/utils/cufat/inc](../../base/fs/utils/cufat/inc) | 3 | — | — | — |
| [base/fs/utils/cufat/src](../../base/fs/utils/cufat/src) | 8 | [base/fs/utils/cufat/src/dirs](../../base/fs/utils/cufat/src/dirs) | — | — |
| [base/fs/utils/cufat/src/usa](../../base/fs/utils/cufat/src/usa) | 2 | [base/fs/utils/cufat/src/usa/sources](../../base/fs/utils/cufat/src/usa/sources), [base/fs/utils/cufat/src/usa/makefile](../../base/fs/utils/cufat/src/usa/makefile) | — | — |
| [base/fs/utils/dfrg](../../base/fs/utils/dfrg) | 45 | [base/fs/utils/dfrg/dirs](../../base/fs/utils/dfrg/dirs) | — | — |
| [base/fs/utils/dfrg/defrag](../../base/fs/utils/dfrg/defrag) | 8 | [base/fs/utils/dfrg/defrag/sources](../../base/fs/utils/dfrg/defrag/sources), [base/fs/utils/dfrg/defrag/makefile](../../base/fs/utils/dfrg/defrag/makefile) | `Defrag` | `PROGRAM` |
| [base/fs/utils/dfrg/dfrgfat](../../base/fs/utils/dfrg/dfrgfat) | 7 | [base/fs/utils/dfrg/dfrgfat/sources](../../base/fs/utils/dfrg/dfrgfat/sources), [base/fs/utils/dfrg/dfrgfat/makefile](../../base/fs/utils/dfrg/dfrgfat/makefile) | — | — |
| [base/fs/utils/dfrg/dfrgntfs](../../base/fs/utils/dfrg/dfrgntfs) | 8 | [base/fs/utils/dfrg/dfrgntfs/sources](../../base/fs/utils/dfrg/dfrgntfs/sources), [base/fs/utils/dfrg/dfrgntfs/makefile](../../base/fs/utils/dfrg/dfrgntfs/makefile) | — | — |
| [base/fs/utils/dfrg/dfrgres](../../base/fs/utils/dfrg/dfrgres) | 19 | [base/fs/utils/dfrg/dfrgres/sources](../../base/fs/utils/dfrg/dfrgres/sources), [base/fs/utils/dfrg/dfrgres/makefile](../../base/fs/utils/dfrg/dfrgres/makefile) | `DfrgRes` | `DYNLINK` |
| [base/fs/utils/dfrg/dfrgsnap](../../base/fs/utils/dfrg/dfrgsnap) | 16 | [base/fs/utils/dfrg/dfrgsnap/sources](../../base/fs/utils/dfrg/dfrgsnap/sources), [base/fs/utils/dfrg/dfrgsnap/makefile](../../base/fs/utils/dfrg/dfrgsnap/makefile) | `DfrgSnap` | `DYNLINK` |
| [base/fs/utils/dfrg/dfrgui](../../base/fs/utils/dfrg/dfrgui) | 34 | [base/fs/utils/dfrg/dfrgui/sources](../../base/fs/utils/dfrg/dfrgui/sources), [base/fs/utils/dfrg/dfrgui/makefile](../../base/fs/utils/dfrg/dfrgui/makefile) | `DfrgUI` | `DYNLINK` |
| [base/fs/utils/dfrg/inc](../../base/fs/utils/dfrg/inc) | 62 | — | — | — |
| [base/fs/utils/dfrg/sld](../../base/fs/utils/dfrg/sld) | 5 | [base/fs/utils/dfrg/sld/sources](../../base/fs/utils/dfrg/sld/sources), [base/fs/utils/dfrg/sld/makefile](../../base/fs/utils/dfrg/sld/makefile) | `Component` | `NOTARGET` |
| [base/fs/utils/diskcomp](../../base/fs/utils/diskcomp) | 4 | [base/fs/utils/diskcomp/dirs](../../base/fs/utils/diskcomp/dirs) | — | — |
| [base/fs/utils/diskcomp/usa](../../base/fs/utils/diskcomp/usa) | 2 | [base/fs/utils/diskcomp/usa/sources](../../base/fs/utils/diskcomp/usa/sources), [base/fs/utils/diskcomp/usa/makefile](../../base/fs/utils/diskcomp/usa/makefile) | — | — |
| [base/fs/utils/diskcopy](../../base/fs/utils/diskcopy) | 4 | [base/fs/utils/diskcopy/dirs](../../base/fs/utils/diskcopy/dirs) | — | — |
| [base/fs/utils/diskcopy/usa](../../base/fs/utils/diskcopy/usa) | 2 | [base/fs/utils/diskcopy/usa/sources](../../base/fs/utils/diskcopy/usa/sources), [base/fs/utils/diskcopy/usa/makefile](../../base/fs/utils/diskcopy/usa/makefile) | — | — |
| [base/fs/utils/diskedit](../../base/fs/utils/diskedit) | 62 | [base/fs/utils/diskedit/dirs](../../base/fs/utils/diskedit/dirs) | — | — |
| [base/fs/utils/diskedit/usa](../../base/fs/utils/diskedit/usa) | 2 | [base/fs/utils/diskedit/usa/sources](../../base/fs/utils/diskedit/usa/sources), [base/fs/utils/diskedit/usa/makefile](../../base/fs/utils/diskedit/usa/makefile) | — | — |
| [base/fs/utils/doskey](../../base/fs/utils/doskey) | 4 | [base/fs/utils/doskey/dirs](../../base/fs/utils/doskey/dirs) | — | — |
| [base/fs/utils/doskey/usa](../../base/fs/utils/doskey/usa) | 2 | [base/fs/utils/doskey/usa/sources](../../base/fs/utils/doskey/usa/sources), [base/fs/utils/doskey/usa/makefile](../../base/fs/utils/doskey/usa/makefile) | — | — |
| [base/fs/utils/driverquery](../../base/fs/utils/driverquery) | 8 | [base/fs/utils/driverquery/sources](../../base/fs/utils/driverquery/sources), [base/fs/utils/driverquery/makefile](../../base/fs/utils/driverquery/makefile) | `DrvQry` | `PROGRAM` |
| [base/fs/utils/fc](../../base/fs/utils/fc) | 5 | [base/fs/utils/fc/dirs](../../base/fs/utils/fc/dirs) | — | — |
| [base/fs/utils/fc/usa](../../base/fs/utils/fc/usa) | 2 | [base/fs/utils/fc/usa/sources](../../base/fs/utils/fc/usa/sources), [base/fs/utils/fc/usa/makefile](../../base/fs/utils/fc/usa/makefile) | — | — |
| [base/fs/utils/fdisk](../../base/fs/utils/fdisk) | 44 | [base/fs/utils/fdisk/sources](../../base/fs/utils/fdisk/sources), [base/fs/utils/fdisk/makefile](../../base/fs/utils/fdisk/makefile) | `windisk` | `PROGRAM` |
| [base/fs/utils/find](../../base/fs/utils/find) | 5 | [base/fs/utils/find/dirs](../../base/fs/utils/find/dirs) | — | — |
| [base/fs/utils/find/usa](../../base/fs/utils/find/usa) | 2 | [base/fs/utils/find/usa/sources](../../base/fs/utils/find/usa/sources), [base/fs/utils/find/usa/makefile](../../base/fs/utils/find/usa/makefile) | — | — |
| [base/fs/utils/findstr](../../base/fs/utils/findstr) | 8 | [base/fs/utils/findstr/sources](../../base/fs/utils/findstr/sources), [base/fs/utils/findstr/makefile](../../base/fs/utils/findstr/makefile) | `findstr` | `PROGRAM` |
| [base/fs/utils/fmifs](../../base/fs/utils/fmifs) | 1 | [base/fs/utils/fmifs/dirs](../../base/fs/utils/fmifs/dirs) | — | — |
| [base/fs/utils/fmifs/inc](../../base/fs/utils/fmifs/inc) | 2 | — | — | — |
| [base/fs/utils/fmifs/src](../../base/fs/utils/fmifs/src) | 12 | [base/fs/utils/fmifs/src/dirs](../../base/fs/utils/fmifs/src/dirs) | — | — |
| [base/fs/utils/fmifs/src/usa](../../base/fs/utils/fmifs/src/usa) | 2 | [base/fs/utils/fmifs/src/usa/sources](../../base/fs/utils/fmifs/src/usa/sources), [base/fs/utils/fmifs/src/usa/makefile](../../base/fs/utils/fmifs/src/usa/makefile) | — | — |
| [base/fs/utils/format](../../base/fs/utils/format) | 6 | [base/fs/utils/format/dirs](../../base/fs/utils/format/dirs) | — | — |
| [base/fs/utils/format/usa](../../base/fs/utils/format/usa) | 2 | [base/fs/utils/format/usa/sources](../../base/fs/utils/format/usa/sources), [base/fs/utils/format/usa/makefile](../../base/fs/utils/format/usa/makefile) | — | — |
| [base/fs/utils/help](../../base/fs/utils/help) | 6 | [base/fs/utils/help/sources](../../base/fs/utils/help/sources), [base/fs/utils/help/makefile](../../base/fs/utils/help/makefile) | `help` | `PROGRAM` |
| [base/fs/utils/ifsutil](../../base/fs/utils/ifsutil) | 1 | [base/fs/utils/ifsutil/dirs](../../base/fs/utils/ifsutil/dirs) | — | — |
| [base/fs/utils/ifsutil/inc](../../base/fs/utils/ifsutil/inc) | 24 | — | — | — |
| [base/fs/utils/ifsutil/src](../../base/fs/utils/ifsutil/src) | 27 | [base/fs/utils/ifsutil/src/dirs](../../base/fs/utils/ifsutil/src/dirs) | — | — |
| [base/fs/utils/ifsutil/src/usa](../../base/fs/utils/ifsutil/src/usa) | 2 | [base/fs/utils/ifsutil/src/usa/sources](../../base/fs/utils/ifsutil/src/usa/sources), [base/fs/utils/ifsutil/src/usa/makefile](../../base/fs/utils/ifsutil/src/usa/makefile) | — | — |
| [base/fs/utils/label](../../base/fs/utils/label) | 4 | [base/fs/utils/label/dirs](../../base/fs/utils/label/dirs) | — | — |
| [base/fs/utils/label/usa](../../base/fs/utils/label/usa) | 2 | [base/fs/utils/label/usa/sources](../../base/fs/utils/label/usa/sources), [base/fs/utils/label/usa/makefile](../../base/fs/utils/label/usa/makefile) | — | — |
| [base/fs/utils/mode](../../base/fs/utils/mode) | 18 | [base/fs/utils/mode/dirs](../../base/fs/utils/mode/dirs) | — | — |
| [base/fs/utils/mode/usa](../../base/fs/utils/mode/usa) | 2 | [base/fs/utils/mode/usa/sources](../../base/fs/utils/mode/usa/sources), [base/fs/utils/mode/usa/makefile](../../base/fs/utils/mode/usa/makefile) | — | — |
| [base/fs/utils/more](../../base/fs/utils/more) | 8 | [base/fs/utils/more/dirs](../../base/fs/utils/more/dirs) | — | — |
| [base/fs/utils/more/usa](../../base/fs/utils/more/usa) | 2 | [base/fs/utils/more/usa/sources](../../base/fs/utils/more/usa/sources), [base/fs/utils/more/usa/makefile](../../base/fs/utils/more/usa/makefile) | — | — |
| [base/fs/utils/mountvol](../../base/fs/utils/mountvol) | 5 | [base/fs/utils/mountvol/sources](../../base/fs/utils/mountvol/sources), [base/fs/utils/mountvol/makefile](../../base/fs/utils/mountvol/makefile) | `mountvol` | `PROGRAM` |
| [base/fs/utils/ntlib](../../base/fs/utils/ntlib) | 1 | [base/fs/utils/ntlib/dirs](../../base/fs/utils/ntlib/dirs) | — | — |
| [base/fs/utils/ntlib/src](../../base/fs/utils/ntlib/src) | 111 | [base/fs/utils/ntlib/src/dirs](../../base/fs/utils/ntlib/src/dirs) | — | — |
| [base/fs/utils/ntlib/src/usa](../../base/fs/utils/ntlib/src/usa) | 3 | [base/fs/utils/ntlib/src/usa/sources](../../base/fs/utils/ntlib/src/usa/sources), [base/fs/utils/ntlib/src/usa/makefile](../../base/fs/utils/ntlib/src/usa/makefile) | — | — |
| [base/fs/utils/openfiles](../../base/fs/utils/openfiles) | 13 | [base/fs/utils/openfiles/sources](../../base/fs/utils/openfiles/sources), [base/fs/utils/openfiles/makefile](../../base/fs/utils/openfiles/makefile) | `OpnFiles` | `PROGRAM` |
| [base/fs/utils/pentbug](../../base/fs/utils/pentbug) | 6 | [base/fs/utils/pentbug/sources](../../base/fs/utils/pentbug/sources), [base/fs/utils/pentbug/makefile](../../base/fs/utils/pentbug/makefile) | `pentnt` | `UMAPPL_NOLIB` |
| [base/fs/utils/pentbug/i386](../../base/fs/utils/pentbug/i386) | 1 | [base/fs/utils/pentbug/i386/sources](../../base/fs/utils/pentbug/i386/sources) | `pentnt` | `PROGRAM` |
| [base/fs/utils/print](../../base/fs/utils/print) | 5 | [base/fs/utils/print/dirs](../../base/fs/utils/print/dirs) | — | — |
| [base/fs/utils/print/usa](../../base/fs/utils/print/usa) | 2 | [base/fs/utils/print/usa/sources](../../base/fs/utils/print/usa/sources), [base/fs/utils/print/usa/makefile](../../base/fs/utils/print/usa/makefile) | — | — |
| [base/fs/utils/recover](../../base/fs/utils/recover) | 4 | [base/fs/utils/recover/dirs](../../base/fs/utils/recover/dirs) | — | — |
| [base/fs/utils/recover/usa](../../base/fs/utils/recover/usa) | 2 | [base/fs/utils/recover/usa/sources](../../base/fs/utils/recover/usa/sources), [base/fs/utils/recover/usa/makefile](../../base/fs/utils/recover/usa/makefile) | — | — |
| [base/fs/utils/reg](../../base/fs/utils/reg) | 24 | [base/fs/utils/reg/sources](../../base/fs/utils/reg/sources), [base/fs/utils/reg/makefile](../../base/fs/utils/reg/makefile) | `reg` | `PROGRAM` |
| [base/fs/utils/regedit](../../base/fs/utils/regedit) | 76 | [base/fs/utils/regedit/sources](../../base/fs/utils/regedit/sources), [base/fs/utils/regedit/makefile](../../base/fs/utils/regedit/makefile) | `regedit` | `PROGRAM` |
| [base/fs/utils/regedit/inc](../../base/fs/utils/regedit/inc) | 1 | — | — | — |
| [base/fs/utils/regedt32](../../base/fs/utils/regedt32) | 8 | [base/fs/utils/regedt32/sources](../../base/fs/utils/regedt32/sources), [base/fs/utils/regedt32/makefile](../../base/fs/utils/regedt32/makefile) | `regedt32` | `PROGRAM` |
| [base/fs/utils/regedt32/src](../../base/fs/utils/regedt32/src) | 0 | — | — | — |
| [base/fs/utils/regedt32/src/usa](../../base/fs/utils/regedt32/src/usa) | 2 | [base/fs/utils/regedt32/src/usa/sources](../../base/fs/utils/regedt32/src/usa/sources), [base/fs/utils/regedt32/src/usa/makefile](../../base/fs/utils/regedt32/src/usa/makefile) | — | — |
| [base/fs/utils/replace](../../base/fs/utils/replace) | 7 | [base/fs/utils/replace/dirs](../../base/fs/utils/replace/dirs) | — | — |
| [base/fs/utils/replace/usa](../../base/fs/utils/replace/usa) | 2 | [base/fs/utils/replace/usa/sources](../../base/fs/utils/replace/usa/sources), [base/fs/utils/replace/usa/makefile](../../base/fs/utils/replace/usa/makefile) | — | — |
| [base/fs/utils/runas](../../base/fs/utils/runas) | 11 | [base/fs/utils/runas/sources](../../base/fs/utils/runas/sources), [base/fs/utils/runas/makefile](../../base/fs/utils/runas/makefile) | `runas` | `PROGRAM` |
| [base/fs/utils/scandisk](../../base/fs/utils/scandisk) | 15 | [base/fs/utils/scandisk/sources](../../base/fs/utils/scandisk/sources), [base/fs/utils/scandisk/makefile](../../base/fs/utils/scandisk/makefile) | `scandisk` | `PROGRAM` |
| [base/fs/utils/scandisk/res](../../base/fs/utils/scandisk/res) | 5 | — | — | — |
| [base/fs/utils/seclist](../../base/fs/utils/seclist) | 4 | [base/fs/utils/seclist/dirs](../../base/fs/utils/seclist/dirs) | — | — |
| [base/fs/utils/seclist/usa](../../base/fs/utils/seclist/usa) | 2 | [base/fs/utils/seclist/usa/sources](../../base/fs/utils/seclist/usa/sources), [base/fs/utils/seclist/usa/makefile](../../base/fs/utils/seclist/usa/makefile) | — | — |
| [base/fs/utils/sigverif](../../base/fs/utils/sigverif) | 18 | [base/fs/utils/sigverif/dirs](../../base/fs/utils/sigverif/dirs) | — | — |
| [base/fs/utils/sigverif/sigtab](../../base/fs/utils/sigverif/sigtab) | 7 | [base/fs/utils/sigverif/sigtab/sources](../../base/fs/utils/sigverif/sigtab/sources), [base/fs/utils/sigverif/sigtab/makefile](../../base/fs/utils/sigverif/sigtab/makefile) | `sigtab` | `DYNLINK` |
| [base/fs/utils/sigverif/sigverif](../../base/fs/utils/sigverif/sigverif) | 3 | [base/fs/utils/sigverif/sigverif/sources](../../base/fs/utils/sigverif/sigverif/sources), [base/fs/utils/sigverif/sigverif/makefile](../../base/fs/utils/sigverif/sigverif/makefile) | `sigverif` | `PROGRAM` |
| [base/fs/utils/sigverif/sld](../../base/fs/utils/sigverif/sld) | 4 | [base/fs/utils/sigverif/sld/sources](../../base/fs/utils/sigverif/sld/sources), [base/fs/utils/sigverif/sld/makefile](../../base/fs/utils/sigverif/sld/makefile) | `sigverif` | `NOTARGET` |
| [base/fs/utils/sort](../../base/fs/utils/sort) | 7 | [base/fs/utils/sort/dirs](../../base/fs/utils/sort/dirs) | — | — |
| [base/fs/utils/sort/usa](../../base/fs/utils/sort/usa) | 3 | [base/fs/utils/sort/usa/sources](../../base/fs/utils/sort/usa/sources), [base/fs/utils/sort/usa/makefile](../../base/fs/utils/sort/usa/makefile) | — | — |
| [base/fs/utils/subst](../../base/fs/utils/subst) | 5 | [base/fs/utils/subst/dirs](../../base/fs/utils/subst/dirs) | — | — |
| [base/fs/utils/subst/usa](../../base/fs/utils/subst/usa) | 2 | [base/fs/utils/subst/usa/sources](../../base/fs/utils/subst/usa/sources), [base/fs/utils/subst/usa/makefile](../../base/fs/utils/subst/usa/makefile) | — | — |
| [base/fs/utils/tree](../../base/fs/utils/tree) | 5 | [base/fs/utils/tree/dirs](../../base/fs/utils/tree/dirs) | — | — |
| [base/fs/utils/tree/usa](../../base/fs/utils/tree/usa) | 2 | [base/fs/utils/tree/usa/sources](../../base/fs/utils/tree/usa/sources), [base/fs/utils/tree/usa/makefile](../../base/fs/utils/tree/usa/makefile) | — | — |
| [base/fs/utils/tuneup](../../base/fs/utils/tuneup) | 33 | [base/fs/utils/tuneup/sources](../../base/fs/utils/tuneup/sources), [base/fs/utils/tuneup/makefile](../../base/fs/utils/tuneup/makefile) | `tuneup` | `PROGRAM` |
| [base/fs/utils/tuneup/res](../../base/fs/utils/tuneup/res) | 5 | — | — | — |
| [base/fs/utils/ufat](../../base/fs/utils/ufat) | 1 | [base/fs/utils/ufat/dirs](../../base/fs/utils/ufat/dirs) | — | — |
| [base/fs/utils/ufat/inc](../../base/fs/utils/ufat/inc) | 16 | — | — | — |
| [base/fs/utils/ufat/src](../../base/fs/utils/ufat/src) | 26 | [base/fs/utils/ufat/src/dirs](../../base/fs/utils/ufat/src/dirs) | — | — |
| [base/fs/utils/ufat/src/usa](../../base/fs/utils/ufat/src/usa) | 2 | [base/fs/utils/ufat/src/usa/sources](../../base/fs/utils/ufat/src/usa/sources), [base/fs/utils/ufat/src/usa/makefile](../../base/fs/utils/ufat/src/usa/makefile) | — | — |
| [base/fs/utils/ulib](../../base/fs/utils/ulib) | 1 | [base/fs/utils/ulib/dirs](../../base/fs/utils/ulib/dirs) | — | — |
| [base/fs/utils/ulib/inc](../../base/fs/utils/ulib/inc) | 64 | — | — | — |
| [base/fs/utils/ulib/memtrace](../../base/fs/utils/ulib/memtrace) | 5 | [base/fs/utils/ulib/memtrace/sources](../../base/fs/utils/ulib/memtrace/sources), [base/fs/utils/ulib/memtrace/makefile](../../base/fs/utils/ulib/memtrace/makefile) | `memtrace` | `DYNLINK` |
| [base/fs/utils/ulib/src](../../base/fs/utils/ulib/src) | 64 | [base/fs/utils/ulib/src/dirs](../../base/fs/utils/ulib/src/dirs) | — | — |
| [base/fs/utils/ulib/src/i386](../../base/fs/utils/ulib/src/i386) | 1 | — | — | — |
| [base/fs/utils/ulib/src/usa](../../base/fs/utils/ulib/src/usa) | 3 | [base/fs/utils/ulib/src/usa/sources](../../base/fs/utils/ulib/src/usa/sources), [base/fs/utils/ulib/src/usa/makefile](../../base/fs/utils/ulib/src/usa/makefile) | — | — |
| [base/fs/utils/untfs](../../base/fs/utils/untfs) | 1 | [base/fs/utils/untfs/dirs](../../base/fs/utils/untfs/dirs) | — | — |
| [base/fs/utils/untfs/inc](../../base/fs/utils/untfs/inc) | 31 | — | — | — |
| [base/fs/utils/untfs/src](../../base/fs/utils/untfs/src) | 42 | [base/fs/utils/untfs/src/dirs](../../base/fs/utils/untfs/src/dirs) | — | — |
| [base/fs/utils/untfs/src/usa](../../base/fs/utils/untfs/src/usa) | 2 | [base/fs/utils/untfs/src/usa/sources](../../base/fs/utils/untfs/src/usa/sources), [base/fs/utils/untfs/src/usa/makefile](../../base/fs/utils/untfs/src/usa/makefile) | — | — |
| [base/fs/utils/ureg](../../base/fs/utils/ureg) | 1 | [base/fs/utils/ureg/dirs](../../base/fs/utils/ureg/dirs) | — | — |
| [base/fs/utils/ureg/inc](../../base/fs/utils/ureg/inc) | 3 | — | — | — |
| [base/fs/utils/ureg/src](../../base/fs/utils/ureg/src) | 18 | [base/fs/utils/ureg/src/dirs](../../base/fs/utils/ureg/src/dirs) | — | — |
| [base/fs/utils/ureg/src/usa](../../base/fs/utils/ureg/src/usa) | 3 | [base/fs/utils/ureg/src/usa/sources](../../base/fs/utils/ureg/src/usa/sources), [base/fs/utils/ureg/src/usa/makefile](../../base/fs/utils/ureg/src/usa/makefile) | — | — |
| [base/fs/utils/uudf](../../base/fs/utils/uudf) | 1 | [base/fs/utils/uudf/dirs](../../base/fs/utils/uudf/dirs) | — | — |
| [base/fs/utils/uudf/inc](../../base/fs/utils/uudf/inc) | 8 | — | — | — |
| [base/fs/utils/uudf/src](../../base/fs/utils/uudf/src) | 20 | [base/fs/utils/uudf/src/dirs](../../base/fs/utils/uudf/src/dirs) | — | — |
| [base/fs/utils/uudf/src/usa](../../base/fs/utils/uudf/src/usa) | 2 | [base/fs/utils/uudf/src/usa/sources](../../base/fs/utils/uudf/src/usa/sources), [base/fs/utils/uudf/src/usa/makefile](../../base/fs/utils/uudf/src/usa/makefile) | — | — |
| [base/fs/utils/wintools](../../base/fs/utils/wintools) | 1 | [base/fs/utils/wintools/dirs](../../base/fs/utils/wintools/dirs) | — | — |
| [base/fs/utils/wintools/clb](../../base/fs/utils/wintools/clb) | 9 | [base/fs/utils/wintools/clb/sources](../../base/fs/utils/wintools/clb/sources), [base/fs/utils/wintools/clb/makefile](../../base/fs/utils/wintools/clb/makefile) | `clb` | `DYNLINK` |
| [base/fs/utils/wintools/lib](../../base/fs/utils/wintools/lib) | 9 | [base/fs/utils/wintools/lib/sources](../../base/fs/utils/wintools/lib/sources), [base/fs/utils/wintools/lib/makefile](../../base/fs/utils/wintools/lib/makefile) | `wintools` | `LIBRARY` |
| [base/fs/utils/xcopy](../../base/fs/utils/xcopy) | 7 | [base/fs/utils/xcopy/dirs](../../base/fs/utils/xcopy/dirs) | — | — |
| [base/fs/utils/xcopy/usa](../../base/fs/utils/xcopy/usa) | 2 | [base/fs/utils/xcopy/usa/sources](../../base/fs/utils/xcopy/usa/sources), [base/fs/utils/xcopy/usa/makefile](../../base/fs/utils/xcopy/usa/makefile) | — | — |

## `base/fsrec/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [base/fsrec](../../base/fsrec) | 12 | [base/fsrec/sources](../../base/fsrec/sources), [base/fsrec/makefile](../../base/fsrec/makefile) | `fs_rec` | `DRIVER` |

## `base/hals/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [base/hals](../../base/hals) | 9 | [base/hals/dirs](../../base/hals/dirs) | — | — |
| [base/hals/halacpi](../../base/hals/halacpi) | 67 | [base/hals/halacpi/dirs](../../base/hals/halacpi/dirs) | — | — |
| [base/hals/halacpi/amd64](../../base/hals/halacpi/amd64) | 30 | — | — | — |
| [base/hals/halacpi/apic](../../base/hals/halacpi/apic) | 3 | [base/hals/halacpi/apic/sources](../../base/hals/halacpi/apic/sources), [base/hals/halacpi/apic/makefile](../../base/hals/halacpi/apic/makefile) | `halaacpi` | `HAL` |
| [base/hals/halacpi/i386](../../base/hals/halacpi/i386) | 33 | — | — | — |
| [base/hals/halacpi/mpapic](../../base/hals/halacpi/mpapic) | 3 | [base/hals/halacpi/mpapic/sources](../../base/hals/halacpi/mpapic/sources), [base/hals/halacpi/mpapic/makefile](../../base/hals/halacpi/mpapic/makefile) | `halmacpi` | `HAL` |
| [base/hals/halacpi/picacpi](../../base/hals/halacpi/picacpi) | 3 | [base/hals/halacpi/picacpi/sources](../../base/hals/halacpi/picacpi/sources), [base/hals/halacpi/picacpi/makefile](../../base/hals/halacpi/picacpi/makefile) | `halacpi` | `HAL` |
| [base/hals/halia64](../../base/hals/halia64) | 7 | [base/hals/halia64/dirs](../../base/hals/halia64/dirs) | — | — |
| [base/hals/halia64/ia64](../../base/hals/halia64/ia64) | 77 | — | — | — |
| [base/hals/halia64/mpapic](../../base/hals/halia64/mpapic) | 2 | [base/hals/halia64/mpapic/sources](../../base/hals/halia64/mpapic/sources), [base/hals/halia64/mpapic/makefile](../../base/hals/halia64/mpapic/makefile) | `hal` | — |
| [base/hals/halmps](../../base/hals/halmps) | 5 | [base/hals/halmps/dirs](../../base/hals/halmps/dirs) | — | — |
| [base/hals/halmps/i386](../../base/hals/halmps/i386) | 75 | [base/hals/halmps/i386/sources](../../base/hals/halmps/i386/sources) | — | — |
| [base/hals/halmps/mp](../../base/hals/halmps/mp) | 3 | [base/hals/halmps/mp/sources](../../base/hals/halmps/mp/sources), [base/hals/halmps/mp/makefile](../../base/hals/halmps/mp/makefile) | `halmps` | `HAL` |
| [base/hals/halmps/mpmca](../../base/hals/halmps/mpmca) | 2 | [base/hals/halmps/mpmca/sources](../../base/hals/halmps/mpmca/sources), [base/hals/halmps/mpmca/makefile](../../base/hals/halmps/mpmca/makefile) | `halmpsm` | `HAL` |
| [base/hals/halmps/up](../../base/hals/halmps/up) | 3 | [base/hals/halmps/up/sources](../../base/hals/halmps/up/sources), [base/hals/halmps/up/makefile](../../base/hals/halmps/up/makefile) | `halapic` | `HAL` |
| [base/hals/halmps/upmca](../../base/hals/halmps/upmca) | 2 | [base/hals/halmps/upmca/sources](../../base/hals/halmps/upmca/sources), [base/hals/halmps/upmca/makefile](../../base/hals/halmps/upmca/makefile) | `halapicm` | `HAL` |
| [base/hals/halsp](../../base/hals/halsp) | 5 | [base/hals/halsp/sources](../../base/hals/halsp/sources), [base/hals/halsp/makefile](../../base/hals/halsp/makefile) | `halsp` | `HAL` |
| [base/hals/halsp/i386](../../base/hals/halsp/i386) | 59 | — | — | — |
| [base/hals/halssc](../../base/hals/halssc) | 4 | [base/hals/halssc/sources](../../base/hals/halssc/sources), [base/hals/halssc/makefile](../../base/hals/halssc/makefile) | `halssc` | `HAL` |
| [base/hals/halssc/ia64](../../base/hals/halssc/ia64) | 14 | — | — | — |
| [base/hals/halsym](../../base/hals/halsym) | 3 | [base/hals/halsym/dirs](../../base/hals/halsym/dirs) | — | — |
| [base/hals/halsym/acpimpapic](../../base/hals/halsym/acpimpapic) | 3 | [base/hals/halsym/acpimpapic/sources](../../base/hals/halsym/acpimpapic/sources), [base/hals/halsym/acpimpapic/makefile](../../base/hals/halsym/acpimpapic/makefile) | — | `NOTARGET` |
| [base/hals/halsym/acpiupapic](../../base/hals/halsym/acpiupapic) | 3 | [base/hals/halsym/acpiupapic/sources](../../base/hals/halsym/acpiupapic/sources), [base/hals/halsym/acpiupapic/makefile](../../base/hals/halsym/acpiupapic/makefile) | — | `NOTARGET` |
| [base/hals/halsym/acpiuppic](../../base/hals/halsym/acpiuppic) | 3 | [base/hals/halsym/acpiuppic/sources](../../base/hals/halsym/acpiuppic/sources), [base/hals/halsym/acpiuppic/makefile](../../base/hals/halsym/acpiuppic/makefile) | — | `NOTARGET` |
| [base/hals/halsym/halia64](../../base/hals/halsym/halia64) | 3 | [base/hals/halsym/halia64/sources](../../base/hals/halsym/halia64/sources), [base/hals/halsym/halia64/makefile](../../base/hals/halsym/halia64/makefile) | — | `NOTARGET` |
| [base/hals/halsym/mpsmp](../../base/hals/halsym/mpsmp) | 3 | [base/hals/halsym/mpsmp/sources](../../base/hals/halsym/mpsmp/sources), [base/hals/halsym/mpsmp/makefile](../../base/hals/halsym/mpsmp/makefile) | — | `NOTARGET` |
| [base/hals/halsym/mpsup](../../base/hals/halsym/mpsup) | 3 | [base/hals/halsym/mpsup/sources](../../base/hals/halsym/mpsup/sources), [base/hals/halsym/mpsup/makefile](../../base/hals/halsym/mpsup/makefile) | — | `NOTARGET` |
| [base/hals/halx86](../../base/hals/halx86) | 4 | [base/hals/halx86/sources](../../base/hals/halx86/sources), [base/hals/halx86/makefile](../../base/hals/halx86/makefile) | `hal` | `HAL` |
| [base/hals/halx86/i386](../../base/hals/halx86/i386) | 60 | — | — | — |
| [base/hals/inc](../../base/hals/inc) | 4 | — | — | — |
| [base/hals/intfilter](../../base/hals/intfilter) | 2 | — | — | — |
| [base/hals/intfilter/config](../../base/hals/intfilter/config) | 1 | — | — | — |
| [base/hals/intfilter/install](../../base/hals/intfilter/install) | 2 | — | — | — |
| [base/hals/intfilter/src](../../base/hals/intfilter/src) | 0 | — | — | — |
| [base/hals/intfilter/src/config](../../base/hals/intfilter/src/config) | 9 | [base/hals/intfilter/src/config/sources](../../base/hals/intfilter/src/config/sources), [base/hals/intfilter/src/config/makefile](../../base/hals/intfilter/src/config/makefile) | `intfiltr` | `PROGRAM` |
| [base/hals/intfilter/src/filter](../../base/hals/intfilter/src/filter) | 10 | [base/hals/intfilter/src/filter/sources](../../base/hals/intfilter/src/filter/sources), [base/hals/intfilter/src/filter/makefile](../../base/hals/intfilter/src/filter/makefile) | `intfiltr` | `DRIVER` |
| [base/hals/mcasample](../../base/hals/mcasample) | 1 | [base/hals/mcasample/dirs](../../base/hals/mcasample/dirs) | — | — |
| [base/hals/mcasample/imca](../../base/hals/mcasample/imca) | 4 | [base/hals/mcasample/imca/dirs](../../base/hals/mcasample/imca/dirs) | — | — |
| [base/hals/mcasample/imca/exe](../../base/hals/mcasample/imca/exe) | 4 | [base/hals/mcasample/imca/exe/sources](../../base/hals/mcasample/imca/exe/sources), [base/hals/mcasample/imca/exe/makefile](../../base/hals/mcasample/imca/exe/makefile) | `mcalog` | `PROGRAM` |
| [base/hals/mcasample/imca/sys](../../base/hals/mcasample/imca/sys) | 6 | [base/hals/mcasample/imca/sys/sources](../../base/hals/mcasample/imca/sys/sources), [base/hals/mcasample/imca/sys/makefile](../../base/hals/mcasample/imca/sys/makefile) | `imca` | `DRIVER` |
| [base/hals/pciirqmp](../../base/hals/pciirqmp) | 2 | [base/hals/pciirqmp/sources](../../base/hals/pciirqmp/sources), [base/hals/pciirqmp/makefile](../../base/hals/pciirqmp/makefile) | `pciirqmp` | `LIBRARY` |
| [base/hals/pciirqmp/i386](../../base/hals/pciirqmp/i386) | 22 | [base/hals/pciirqmp/i386/makefile](../../base/hals/pciirqmp/i386/makefile) | — | — |
| [base/hals/processor](../../base/hals/processor) | 3 | [base/hals/processor/dirs](../../base/hals/processor/dirs) | — | — |
| [base/hals/processor/amdk6](../../base/hals/processor/amdk6) | 7 | [base/hals/processor/amdk6/sources](../../base/hals/processor/amdk6/sources), [base/hals/processor/amdk6/makefile](../../base/hals/processor/amdk6/makefile) | `amdk6` | `DRIVER` |
| [base/hals/processor/amdk7](../../base/hals/processor/amdk7) | 8 | [base/hals/processor/amdk7/sources](../../base/hals/processor/amdk7/sources), [base/hals/processor/amdk7/makefile](../../base/hals/processor/amdk7/makefile) | `amdk7` | `DRIVER` |
| [base/hals/processor/amdk7/inf](../../base/hals/processor/amdk7/inf) | 4 | [base/hals/processor/amdk7/inf/sources](../../base/hals/processor/amdk7/inf/sources), [base/hals/processor/amdk7/inf/makefile](../../base/hals/processor/amdk7/inf/makefile) | `inf` | `notarget` |
| [base/hals/processor/amdk7/inf/usa](../../base/hals/processor/amdk7/inf/usa) | 1 | — | — | — |
| [base/hals/processor/crusoe](../../base/hals/processor/crusoe) | 6 | [base/hals/processor/crusoe/sources](../../base/hals/processor/crusoe/sources), [base/hals/processor/crusoe/makefile](../../base/hals/processor/crusoe/makefile) | `crusoe` | `DRIVER` |
| [base/hals/processor/generic](../../base/hals/processor/generic) | 4 | [base/hals/processor/generic/sources](../../base/hals/processor/generic/sources), [base/hals/processor/generic/makefile](../../base/hals/processor/generic/makefile) | `processr` | `DRIVER` |
| [base/hals/processor/lib](../../base/hals/processor/lib) | 14 | [base/hals/processor/lib/sources](../../base/hals/processor/lib/sources), [base/hals/processor/lib/makefile](../../base/hals/processor/lib/makefile) | `proclib` | `DRIVER_LIBRARY` |
| [base/hals/processor/lib/amd64](../../base/hals/processor/lib/amd64) | 2 | [base/hals/processor/lib/amd64/sources](../../base/hals/processor/lib/amd64/sources) | — | — |
| [base/hals/processor/lib/axp64](../../base/hals/processor/lib/axp64) | 2 | [base/hals/processor/lib/axp64/sources](../../base/hals/processor/lib/axp64/sources) | — | — |
| [base/hals/processor/lib/i386](../../base/hals/processor/lib/i386) | 6 | [base/hals/processor/lib/i386/sources](../../base/hals/processor/lib/i386/sources) | — | — |
| [base/hals/processor/lib/ia64](../../base/hals/processor/lib/ia64) | 2 | [base/hals/processor/lib/ia64/sources](../../base/hals/processor/lib/ia64/sources) | — | — |
| [base/hals/processor/p3](../../base/hals/processor/p3) | 7 | [base/hals/processor/p3/sources](../../base/hals/processor/p3/sources), [base/hals/processor/p3/makefile](../../base/hals/processor/p3/makefile) | `p3` | `DRIVER` |
| [base/hals/processor/procsym](../../base/hals/processor/procsym) | 3 | [base/hals/processor/procsym/dirs](../../base/hals/processor/procsym/dirs) | — | — |
| [base/hals/processor/procsym/amdk6](../../base/hals/processor/procsym/amdk6) | 3 | [base/hals/processor/procsym/amdk6/sources](../../base/hals/processor/procsym/amdk6/sources), [base/hals/processor/procsym/amdk6/makefile](../../base/hals/processor/procsym/amdk6/makefile) | — | `NOTARGET` |
| [base/hals/processor/procsym/crusoe](../../base/hals/processor/procsym/crusoe) | 3 | [base/hals/processor/procsym/crusoe/sources](../../base/hals/processor/procsym/crusoe/sources), [base/hals/processor/procsym/crusoe/makefile](../../base/hals/processor/procsym/crusoe/makefile) | — | `NOTARGET` |
| [base/hals/processor/procsym/p3](../../base/hals/processor/procsym/p3) | 3 | [base/hals/processor/procsym/p3/sources](../../base/hals/processor/procsym/p3/sources), [base/hals/processor/procsym/p3/makefile](../../base/hals/processor/procsym/p3/makefile) | — | `NOTARGET` |
| [base/hals/processor/procsym/processr](../../base/hals/processor/procsym/processr) | 3 | [base/hals/processor/procsym/processr/sources](../../base/hals/processor/procsym/processr/sources), [base/hals/processor/procsym/processr/makefile](../../base/hals/processor/procsym/processr/makefile) | — | `NOTARGET` |
| [base/hals/processor/tools](../../base/hals/processor/tools) | 3 | [base/hals/processor/tools/dirs](../../base/hals/processor/tools/dirs) | — | — |
| [base/hals/processor/tools/cpuevent](../../base/hals/processor/tools/cpuevent) | 4 | [base/hals/processor/tools/cpuevent/sources](../../base/hals/processor/tools/cpuevent/sources), [base/hals/processor/tools/cpuevent/makefile](../../base/hals/processor/tools/cpuevent/makefile) | `cpuevent` | `PROGRAM` |
| [base/hals/processor/tools/cpuperf](../../base/hals/processor/tools/cpuperf) | 4 | [base/hals/processor/tools/cpuperf/sources](../../base/hals/processor/tools/cpuperf/sources), [base/hals/processor/tools/cpuperf/makefile](../../base/hals/processor/tools/cpuperf/makefile) | `cpuperf` | `PROGRAM` |
| [base/hals/processor/tools/finde980](../../base/hals/processor/tools/finde980) | 4 | [base/hals/processor/tools/finde980/sources](../../base/hals/processor/tools/finde980/sources), [base/hals/processor/tools/finde980/makefile](../../base/hals/processor/tools/finde980/makefile) | `finde980` | `PROGRAM` |
| [base/hals/processor/viac3](../../base/hals/processor/viac3) | 7 | [base/hals/processor/viac3/sources](../../base/hals/processor/viac3/sources), [base/hals/processor/viac3/makefile](../../base/hals/processor/viac3/makefile) | `viac3` | `DRIVER` |
| [base/hals/processor/viac3/inf](../../base/hals/processor/viac3/inf) | 4 | [base/hals/processor/viac3/inf/sources](../../base/hals/processor/viac3/inf/sources), [base/hals/processor/viac3/inf/makefile](../../base/hals/processor/viac3/inf/makefile) | `inf` | `notarget` |
| [base/hals/processor/viac3/inf/usa](../../base/hals/processor/viac3/inf/usa) | 1 | — | — | — |
| [base/hals/x86new](../../base/hals/x86new) | 30 | [base/hals/x86new/sources](../../base/hals/x86new/sources), [base/hals/x86new/makefile](../../base/hals/x86new/makefile) | `x86new` | `LIBRARY` |
| [base/hals/x86new/alpha](../../base/hals/x86new/alpha) | 1 | [base/hals/x86new/alpha/sources](../../base/hals/x86new/alpha/sources) | — | — |
| [base/hals/x86new/amd64](../../base/hals/x86new/amd64) | 1 | [base/hals/x86new/amd64/sources](../../base/hals/x86new/amd64/sources) | — | — |
| [base/hals/x86new/axp64](../../base/hals/x86new/axp64) | 1 | [base/hals/x86new/axp64/sources](../../base/hals/x86new/axp64/sources) | — | — |
| [base/hals/x86new/i386](../../base/hals/x86new/i386) | 1 | [base/hals/x86new/i386/sources](../../base/hals/x86new/i386/sources) | — | — |
| [base/hals/x86new/ia64](../../base/hals/x86new/ia64) | 1 | [base/hals/x86new/ia64/sources](../../base/hals/x86new/ia64/sources) | — | — |

## `base/headless/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [base/headless](../../base/headless) | 1 | [base/headless/dirs](../../base/headless/dirs) | — | — |
| [base/headless/bootprov](../../base/headless/bootprov) | 13 | [base/headless/bootprov/sources](../../base/headless/bootprov/sources), [base/headless/bootprov/makefile](../../base/headless/bootprov/makefile) | `bootinstprov` | `DYNLINK` |
| [base/headless/docs](../../base/headless/docs) | 3 | — | — | — |
| [base/headless/ems](../../base/headless/ems) | 0 | — | — | — |
| [base/headless/ems/sac](../../base/headless/ems/sac) | 0 | — | — | — |
| [base/headless/ems/sac/saccommunicator](../../base/headless/ems/sac/saccommunicator) | 2 | — | — | — |
| [base/headless/ems/sac/sacrunner](../../base/headless/ems/sac/sacrunner) | 14 | [base/headless/ems/sac/sacrunner/sources](../../base/headless/ems/sac/sacrunner/sources), [base/headless/ems/sac/sacrunner/makefile](../../base/headless/ems/sac/sacrunner/makefile) | `sacrunner` | `PROGRAM` |
| [base/headless/ems/sac/sacrunner/out](../../base/headless/ems/sac/sacrunner/out) | 1 | — | — | — |
| [base/headless/tcsrv](../../base/headless/tcsrv) | 1 | [base/headless/tcsrv/dirs](../../base/headless/tcsrv/dirs) | — | — |
| [base/headless/tcsrv/admin](../../base/headless/tcsrv/admin) | 1 | [base/headless/tcsrv/admin/dirs](../../base/headless/tcsrv/admin/dirs) | — | — |
| [base/headless/tcsrv/admin/console](../../base/headless/tcsrv/admin/console) | 7 | [base/headless/tcsrv/admin/console/sources](../../base/headless/tcsrv/admin/console/sources), [base/headless/tcsrv/admin/console/makefile](../../base/headless/tcsrv/admin/console/makefile) | `tcadmin` | `PROGRAM` |
| [base/headless/tcsrv/admin/data](../../base/headless/tcsrv/admin/data) | 6 | [base/headless/tcsrv/admin/data/sources](../../base/headless/tcsrv/admin/data/sources), [base/headless/tcsrv/admin/data/makefile](../../base/headless/tcsrv/admin/data/makefile) | `tcdata` | `DYNLINK` |
| [base/headless/tcsrv/client](../../base/headless/tcsrv/client) | 8 | [base/headless/tcsrv/client/sources](../../base/headless/tcsrv/client/sources), [base/headless/tcsrv/client/makefile](../../base/headless/tcsrv/client/makefile) | `tcclnt` | `PROGRAM` |
| [base/headless/tcsrv/inc](../../base/headless/tcsrv/inc) | 1 | — | — | — |
| [base/headless/tcsrv/server](../../base/headless/tcsrv/server) | 14 | [base/headless/tcsrv/server/sources](../../base/headless/tcsrv/server/sources), [base/headless/tcsrv/server/makefile](../../base/headless/tcsrv/server/makefile) | `tcsrv` | `PROGRAM` |
| [base/headless/test](../../base/headless/test) | 0 | — | — | — |
| [base/headless/test/cpuhog](../../base/headless/test/cpuhog) | 4 | [base/headless/test/cpuhog/sources](../../base/headless/test/cpuhog/sources), [base/headless/test/cpuhog/makefile](../../base/headless/test/cpuhog/makefile) | `cpuhog` | `PROGRAM` |
| [base/headless/watcher](../../base/headless/watcher) | 29 | [base/headless/watcher/sources](../../base/headless/watcher/sources), [base/headless/watcher/makefile](../../base/headless/watcher/makefile) | `watcher` | `PROGRAM` |
| [base/headless/watcher/res](../../base/headless/watcher/res) | 4 | — | — | — |

## `base/inc/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [base/inc](../../base/inc) | 5 | — | — | — |

## `base/mspatch/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [base/mspatch](../../base/mspatch) | 1 | [base/mspatch/dirs](../../base/mspatch/dirs) | — | — |
| [base/mspatch/api](../../base/mspatch/api) | 18 | [base/mspatch/api/dirs](../../base/mspatch/api/dirs) | — | — |
| [base/mspatch/api/i386](../../base/mspatch/api/i386) | 5 | — | — | — |
| [base/mspatch/api/mspatch](../../base/mspatch/api/mspatch) | 5 | [base/mspatch/api/mspatch/sources](../../base/mspatch/api/mspatch/sources), [base/mspatch/api/mspatch/makefile](../../base/mspatch/api/mspatch/makefile) | `mspatch` | — |
| [base/mspatch/api/mspatcha](../../base/mspatch/api/mspatcha) | 5 | [base/mspatch/api/mspatcha/sources](../../base/mspatch/api/mspatcha/sources), [base/mspatch/api/mspatcha/makefile](../../base/mspatch/api/mspatcha/makefile) | `mspatcha` | — |
| [base/mspatch/api/mspatchc](../../base/mspatch/api/mspatchc) | 5 | [base/mspatch/api/mspatchc/sources](../../base/mspatch/api/mspatchc/sources), [base/mspatch/api/mspatchc/makefile](../../base/mspatch/api/mspatchc/makefile) | `mspatchc` | — |
| [base/mspatch/api/samples](../../base/mspatch/api/samples) | 1 | [base/mspatch/api/samples/dirs](../../base/mspatch/api/samples/dirs) | — | — |
| [base/mspatch/api/samples/apatch](../../base/mspatch/api/samples/apatch) | 6 | [base/mspatch/api/samples/apatch/sources](../../base/mspatch/api/samples/apatch/sources), [base/mspatch/api/samples/apatch/makefile](../../base/mspatch/api/samples/apatch/makefile) | `apatch` | `PROGRAM` |
| [base/mspatch/api/samples/mpatch](../../base/mspatch/api/samples/mpatch) | 5 | [base/mspatch/api/samples/mpatch/sources](../../base/mspatch/api/samples/mpatch/sources), [base/mspatch/api/samples/mpatch/makefile](../../base/mspatch/api/samples/mpatch/makefile) | `mpatch` | `PROGRAM` |
| [base/mspatch/api/samples/wpatch](../../base/mspatch/api/samples/wpatch) | 7 | [base/mspatch/api/samples/wpatch/sources](../../base/mspatch/api/samples/wpatch/sources), [base/mspatch/api/samples/wpatch/makefile](../../base/mspatch/api/samples/wpatch/makefile) | `wpatch` | `PROGRAM` |
| [base/mspatch/api/static](../../base/mspatch/api/static) | 2 | [base/mspatch/api/static/sources](../../base/mspatch/api/static/sources), [base/mspatch/api/static/makefile](../../base/mspatch/api/static/makefile) | `mspatchl` | `LIBRARY` |
| [base/mspatch/api/statica](../../base/mspatch/api/statica) | 2 | [base/mspatch/api/statica/sources](../../base/mspatch/api/statica/sources), [base/mspatch/api/statica/makefile](../../base/mspatch/api/statica/makefile) | `mspatchz` | `LIBRARY` |
| [base/mspatch/lzx](../../base/mspatch/lzx) | 1 | [base/mspatch/lzx/dirs](../../base/mspatch/lzx/dirs) | — | — |
| [base/mspatch/lzx/common](../../base/mspatch/lzx/common) | 2 | — | — | — |
| [base/mspatch/lzx/decoder](../../base/mspatch/lzx/decoder) | 19 | [base/mspatch/lzx/decoder/sources](../../base/mspatch/lzx/decoder/sources), [base/mspatch/lzx/decoder/makefile](../../base/mspatch/lzx/decoder/makefile) | `lzxpd` | `LIBRARY` |
| [base/mspatch/lzx/encoder](../../base/mspatch/lzx/encoder) | 19 | [base/mspatch/lzx/encoder/sources](../../base/mspatch/lzx/encoder/sources), [base/mspatch/lzx/encoder/makefile](../../base/mspatch/lzx/encoder/makefile) | `lzxpc` | `LIBRARY` |

## `base/mvdm/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [base/mvdm](../../base/mvdm) | 1 | [base/mvdm/dirs](../../base/mvdm/dirs) | — | — |
| [base/mvdm/bin86](../../base/mvdm/bin86) | 24 | [base/mvdm/bin86/dirs](../../base/mvdm/bin86/dirs) | — | — |
| [base/mvdm/bin86/chp](../../base/mvdm/bin86/chp) | 12 | [base/mvdm/bin86/chp/sources](../../base/mvdm/bin86/chp/sources), [base/mvdm/bin86/chp/makefile](../../base/mvdm/bin86/chp/makefile) | — | — |
| [base/mvdm/bin86/chs](../../base/mvdm/bin86/chs) | 12 | [base/mvdm/bin86/chs/sources](../../base/mvdm/bin86/chs/sources), [base/mvdm/bin86/chs/makefile](../../base/mvdm/bin86/chs/makefile) | — | — |
| [base/mvdm/bin86/cht](../../base/mvdm/bin86/cht) | 12 | [base/mvdm/bin86/cht/sources](../../base/mvdm/bin86/cht/sources), [base/mvdm/bin86/cht/makefile](../../base/mvdm/bin86/cht/makefile) | — | — |
| [base/mvdm/bin86/i386](../../base/mvdm/bin86/i386) | 1 | — | — | — |
| [base/mvdm/bin86/jpn](../../base/mvdm/bin86/jpn) | 37 | [base/mvdm/bin86/jpn/sources](../../base/mvdm/bin86/jpn/sources), [base/mvdm/bin86/jpn/makefile](../../base/mvdm/bin86/jpn/makefile) | — | — |
| [base/mvdm/bin86/kor](../../base/mvdm/bin86/kor) | 21 | [base/mvdm/bin86/kor/sources](../../base/mvdm/bin86/kor/sources), [base/mvdm/bin86/kor/makefile](../../base/mvdm/bin86/kor/makefile) | — | — |
| [base/mvdm/bin86/usa](../../base/mvdm/bin86/usa) | 2 | [base/mvdm/bin86/usa/sources](../../base/mvdm/bin86/usa/sources), [base/mvdm/bin86/usa/makefile](../../base/mvdm/bin86/usa/makefile) | — | — |
| [base/mvdm/dbg](../../base/mvdm/dbg) | 3 | [base/mvdm/dbg/dirs](../../base/mvdm/dbg/dirs) | — | — |
| [base/mvdm/dbg/daytona](../../base/mvdm/dbg/daytona) | 2 | [base/mvdm/dbg/daytona/sources](../../base/mvdm/dbg/daytona/sources), [base/mvdm/dbg/daytona/makefile](../../base/mvdm/dbg/daytona/makefile) | — | — |
| [base/mvdm/dbg/nec_98](../../base/mvdm/dbg/nec_98) | 2 | [base/mvdm/dbg/nec_98/sources](../../base/mvdm/dbg/nec_98/sources), [base/mvdm/dbg/nec_98/makefile](../../base/mvdm/dbg/nec_98/makefile) | — | — |
| [base/mvdm/dbgdll](../../base/mvdm/dbgdll) | 12 | [base/mvdm/dbgdll/sources](../../base/mvdm/dbgdll/sources), [base/mvdm/dbgdll/makefile](../../base/mvdm/dbgdll/makefile) | `ntvdmd` | `DYNLINK` |
| [base/mvdm/dos](../../base/mvdm/dos) | 1 | [base/mvdm/dos/dirs](../../base/mvdm/dos/dirs) | — | — |
| [base/mvdm/dos/command](../../base/mvdm/dos/command) | 16 | [base/mvdm/dos/command/dirs](../../base/mvdm/dos/command/dirs) | — | — |
| [base/mvdm/dos/command/chp](../../base/mvdm/dos/command/chp) | 2 | [base/mvdm/dos/command/chp/sources](../../base/mvdm/dos/command/chp/sources), [base/mvdm/dos/command/chp/makefile](../../base/mvdm/dos/command/chp/makefile) | — | — |
| [base/mvdm/dos/command/chs](../../base/mvdm/dos/command/chs) | 2 | [base/mvdm/dos/command/chs/sources](../../base/mvdm/dos/command/chs/sources), [base/mvdm/dos/command/chs/makefile](../../base/mvdm/dos/command/chs/makefile) | — | — |
| [base/mvdm/dos/command/cht](../../base/mvdm/dos/command/cht) | 2 | [base/mvdm/dos/command/cht/sources](../../base/mvdm/dos/command/cht/sources), [base/mvdm/dos/command/cht/makefile](../../base/mvdm/dos/command/cht/makefile) | — | — |
| [base/mvdm/dos/command/daytona](../../base/mvdm/dos/command/daytona) | 2 | [base/mvdm/dos/command/daytona/sources](../../base/mvdm/dos/command/daytona/sources), [base/mvdm/dos/command/daytona/makefile](../../base/mvdm/dos/command/daytona/makefile) | — | — |
| [base/mvdm/dos/command/jpn](../../base/mvdm/dos/command/jpn) | 2 | [base/mvdm/dos/command/jpn/sources](../../base/mvdm/dos/command/jpn/sources), [base/mvdm/dos/command/jpn/makefile](../../base/mvdm/dos/command/jpn/makefile) | — | — |
| [base/mvdm/dos/command/kor](../../base/mvdm/dos/command/kor) | 2 | [base/mvdm/dos/command/kor/sources](../../base/mvdm/dos/command/kor/sources), [base/mvdm/dos/command/kor/makefile](../../base/mvdm/dos/command/kor/makefile) | — | — |
| [base/mvdm/dos/command/nec_98](../../base/mvdm/dos/command/nec_98) | 2 | [base/mvdm/dos/command/nec_98/sources](../../base/mvdm/dos/command/nec_98/sources), [base/mvdm/dos/command/nec_98/makefile](../../base/mvdm/dos/command/nec_98/makefile) | — | — |
| [base/mvdm/dos/dem](../../base/mvdm/dos/dem) | 24 | [base/mvdm/dos/dem/dirs](../../base/mvdm/dos/dem/dirs) | — | — |
| [base/mvdm/dos/dem/chp](../../base/mvdm/dos/dem/chp) | 2 | [base/mvdm/dos/dem/chp/sources](../../base/mvdm/dos/dem/chp/sources), [base/mvdm/dos/dem/chp/makefile](../../base/mvdm/dos/dem/chp/makefile) | — | — |
| [base/mvdm/dos/dem/chs](../../base/mvdm/dos/dem/chs) | 2 | [base/mvdm/dos/dem/chs/sources](../../base/mvdm/dos/dem/chs/sources), [base/mvdm/dos/dem/chs/makefile](../../base/mvdm/dos/dem/chs/makefile) | — | — |
| [base/mvdm/dos/dem/cht](../../base/mvdm/dos/dem/cht) | 2 | [base/mvdm/dos/dem/cht/sources](../../base/mvdm/dos/dem/cht/sources), [base/mvdm/dos/dem/cht/makefile](../../base/mvdm/dos/dem/cht/makefile) | — | — |
| [base/mvdm/dos/dem/daytona](../../base/mvdm/dos/dem/daytona) | 2 | [base/mvdm/dos/dem/daytona/sources](../../base/mvdm/dos/dem/daytona/sources), [base/mvdm/dos/dem/daytona/makefile](../../base/mvdm/dos/dem/daytona/makefile) | — | — |
| [base/mvdm/dos/dem/jpn](../../base/mvdm/dos/dem/jpn) | 2 | [base/mvdm/dos/dem/jpn/sources](../../base/mvdm/dos/dem/jpn/sources), [base/mvdm/dos/dem/jpn/makefile](../../base/mvdm/dos/dem/jpn/makefile) | — | — |
| [base/mvdm/dos/dem/kor](../../base/mvdm/dos/dem/kor) | 2 | [base/mvdm/dos/dem/kor/sources](../../base/mvdm/dos/dem/kor/sources), [base/mvdm/dos/dem/kor/makefile](../../base/mvdm/dos/dem/kor/makefile) | — | — |
| [base/mvdm/dos/dem/nec_98](../../base/mvdm/dos/dem/nec_98) | 2 | [base/mvdm/dos/dem/nec_98/sources](../../base/mvdm/dos/dem/nec_98/sources), [base/mvdm/dos/dem/nec_98/makefile](../../base/mvdm/dos/dem/nec_98/makefile) | — | — |
| [base/mvdm/dos/test](../../base/mvdm/dos/test) | 1 | — | — | — |
| [base/mvdm/dos/v86](../../base/mvdm/dos/v86) | 3 | [base/mvdm/dos/v86/dirs](../../base/mvdm/dos/v86/dirs) | — | — |
| [base/mvdm/dos/v86/cmd](../../base/mvdm/dos/v86/cmd) | 1 | [base/mvdm/dos/v86/cmd/dirs](../../base/mvdm/dos/v86/cmd/dirs) | — | — |
| [base/mvdm/dos/v86/cmd/append](../../base/mvdm/dos/v86/cmd/append) | 7 | [base/mvdm/dos/v86/cmd/append/dirs](../../base/mvdm/dos/v86/cmd/append/dirs) | — | — |
| [base/mvdm/dos/v86/cmd/append/br](../../base/mvdm/dos/v86/cmd/append/br) | 3 | [base/mvdm/dos/v86/cmd/append/br/sources](../../base/mvdm/dos/v86/cmd/append/br/sources), [base/mvdm/dos/v86/cmd/append/br/makefile](../../base/mvdm/dos/v86/cmd/append/br/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/append/chp](../../base/mvdm/dos/v86/cmd/append/chp) | 4 | [base/mvdm/dos/v86/cmd/append/chp/sources](../../base/mvdm/dos/v86/cmd/append/chp/sources), [base/mvdm/dos/v86/cmd/append/chp/makefile](../../base/mvdm/dos/v86/cmd/append/chp/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/append/chs](../../base/mvdm/dos/v86/cmd/append/chs) | 4 | [base/mvdm/dos/v86/cmd/append/chs/sources](../../base/mvdm/dos/v86/cmd/append/chs/sources), [base/mvdm/dos/v86/cmd/append/chs/makefile](../../base/mvdm/dos/v86/cmd/append/chs/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/append/cht](../../base/mvdm/dos/v86/cmd/append/cht) | 4 | [base/mvdm/dos/v86/cmd/append/cht/sources](../../base/mvdm/dos/v86/cmd/append/cht/sources), [base/mvdm/dos/v86/cmd/append/cht/makefile](../../base/mvdm/dos/v86/cmd/append/cht/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/append/cs](../../base/mvdm/dos/v86/cmd/append/cs) | 3 | [base/mvdm/dos/v86/cmd/append/cs/sources](../../base/mvdm/dos/v86/cmd/append/cs/sources), [base/mvdm/dos/v86/cmd/append/cs/makefile](../../base/mvdm/dos/v86/cmd/append/cs/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/append/da](../../base/mvdm/dos/v86/cmd/append/da) | 3 | [base/mvdm/dos/v86/cmd/append/da/sources](../../base/mvdm/dos/v86/cmd/append/da/sources), [base/mvdm/dos/v86/cmd/append/da/makefile](../../base/mvdm/dos/v86/cmd/append/da/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/append/el](../../base/mvdm/dos/v86/cmd/append/el) | 3 | [base/mvdm/dos/v86/cmd/append/el/sources](../../base/mvdm/dos/v86/cmd/append/el/sources), [base/mvdm/dos/v86/cmd/append/el/makefile](../../base/mvdm/dos/v86/cmd/append/el/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/append/es](../../base/mvdm/dos/v86/cmd/append/es) | 3 | [base/mvdm/dos/v86/cmd/append/es/sources](../../base/mvdm/dos/v86/cmd/append/es/sources), [base/mvdm/dos/v86/cmd/append/es/makefile](../../base/mvdm/dos/v86/cmd/append/es/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/append/fi](../../base/mvdm/dos/v86/cmd/append/fi) | 3 | [base/mvdm/dos/v86/cmd/append/fi/sources](../../base/mvdm/dos/v86/cmd/append/fi/sources), [base/mvdm/dos/v86/cmd/append/fi/makefile](../../base/mvdm/dos/v86/cmd/append/fi/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/append/fr](../../base/mvdm/dos/v86/cmd/append/fr) | 3 | [base/mvdm/dos/v86/cmd/append/fr/sources](../../base/mvdm/dos/v86/cmd/append/fr/sources), [base/mvdm/dos/v86/cmd/append/fr/makefile](../../base/mvdm/dos/v86/cmd/append/fr/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/append/ger](../../base/mvdm/dos/v86/cmd/append/ger) | 3 | [base/mvdm/dos/v86/cmd/append/ger/sources](../../base/mvdm/dos/v86/cmd/append/ger/sources), [base/mvdm/dos/v86/cmd/append/ger/makefile](../../base/mvdm/dos/v86/cmd/append/ger/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/append/hu](../../base/mvdm/dos/v86/cmd/append/hu) | 3 | [base/mvdm/dos/v86/cmd/append/hu/sources](../../base/mvdm/dos/v86/cmd/append/hu/sources), [base/mvdm/dos/v86/cmd/append/hu/makefile](../../base/mvdm/dos/v86/cmd/append/hu/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/append/it](../../base/mvdm/dos/v86/cmd/append/it) | 3 | [base/mvdm/dos/v86/cmd/append/it/sources](../../base/mvdm/dos/v86/cmd/append/it/sources), [base/mvdm/dos/v86/cmd/append/it/makefile](../../base/mvdm/dos/v86/cmd/append/it/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/append/jpn](../../base/mvdm/dos/v86/cmd/append/jpn) | 4 | [base/mvdm/dos/v86/cmd/append/jpn/sources](../../base/mvdm/dos/v86/cmd/append/jpn/sources), [base/mvdm/dos/v86/cmd/append/jpn/makefile](../../base/mvdm/dos/v86/cmd/append/jpn/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/append/kor](../../base/mvdm/dos/v86/cmd/append/kor) | 4 | [base/mvdm/dos/v86/cmd/append/kor/sources](../../base/mvdm/dos/v86/cmd/append/kor/sources), [base/mvdm/dos/v86/cmd/append/kor/makefile](../../base/mvdm/dos/v86/cmd/append/kor/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/append/nl](../../base/mvdm/dos/v86/cmd/append/nl) | 3 | [base/mvdm/dos/v86/cmd/append/nl/sources](../../base/mvdm/dos/v86/cmd/append/nl/sources), [base/mvdm/dos/v86/cmd/append/nl/makefile](../../base/mvdm/dos/v86/cmd/append/nl/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/append/no](../../base/mvdm/dos/v86/cmd/append/no) | 3 | [base/mvdm/dos/v86/cmd/append/no/sources](../../base/mvdm/dos/v86/cmd/append/no/sources), [base/mvdm/dos/v86/cmd/append/no/makefile](../../base/mvdm/dos/v86/cmd/append/no/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/append/pl](../../base/mvdm/dos/v86/cmd/append/pl) | 3 | [base/mvdm/dos/v86/cmd/append/pl/sources](../../base/mvdm/dos/v86/cmd/append/pl/sources), [base/mvdm/dos/v86/cmd/append/pl/makefile](../../base/mvdm/dos/v86/cmd/append/pl/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/append/psu](../../base/mvdm/dos/v86/cmd/append/psu) | 3 | [base/mvdm/dos/v86/cmd/append/psu/sources](../../base/mvdm/dos/v86/cmd/append/psu/sources), [base/mvdm/dos/v86/cmd/append/psu/makefile](../../base/mvdm/dos/v86/cmd/append/psu/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/append/pt](../../base/mvdm/dos/v86/cmd/append/pt) | 3 | [base/mvdm/dos/v86/cmd/append/pt/sources](../../base/mvdm/dos/v86/cmd/append/pt/sources), [base/mvdm/dos/v86/cmd/append/pt/makefile](../../base/mvdm/dos/v86/cmd/append/pt/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/append/ru](../../base/mvdm/dos/v86/cmd/append/ru) | 3 | [base/mvdm/dos/v86/cmd/append/ru/sources](../../base/mvdm/dos/v86/cmd/append/ru/sources), [base/mvdm/dos/v86/cmd/append/ru/makefile](../../base/mvdm/dos/v86/cmd/append/ru/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/append/sv](../../base/mvdm/dos/v86/cmd/append/sv) | 3 | [base/mvdm/dos/v86/cmd/append/sv/sources](../../base/mvdm/dos/v86/cmd/append/sv/sources), [base/mvdm/dos/v86/cmd/append/sv/makefile](../../base/mvdm/dos/v86/cmd/append/sv/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/append/tr](../../base/mvdm/dos/v86/cmd/append/tr) | 3 | [base/mvdm/dos/v86/cmd/append/tr/sources](../../base/mvdm/dos/v86/cmd/append/tr/sources), [base/mvdm/dos/v86/cmd/append/tr/makefile](../../base/mvdm/dos/v86/cmd/append/tr/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/append/tst](../../base/mvdm/dos/v86/cmd/append/tst) | 3 | [base/mvdm/dos/v86/cmd/append/tst/sources](../../base/mvdm/dos/v86/cmd/append/tst/sources), [base/mvdm/dos/v86/cmd/append/tst/makefile](../../base/mvdm/dos/v86/cmd/append/tst/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/append/usa](../../base/mvdm/dos/v86/cmd/append/usa) | 4 | [base/mvdm/dos/v86/cmd/append/usa/sources](../../base/mvdm/dos/v86/cmd/append/usa/sources), [base/mvdm/dos/v86/cmd/append/usa/makefile](../../base/mvdm/dos/v86/cmd/append/usa/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/backup](../../base/mvdm/dos/v86/cmd/backup) | 3 | [base/mvdm/dos/v86/cmd/backup/dirs](../../base/mvdm/dos/v86/cmd/backup/dirs) | — | — |
| [base/mvdm/dos/v86/cmd/backup/chp](../../base/mvdm/dos/v86/cmd/backup/chp) | 4 | [base/mvdm/dos/v86/cmd/backup/chp/sources](../../base/mvdm/dos/v86/cmd/backup/chp/sources), [base/mvdm/dos/v86/cmd/backup/chp/makefile](../../base/mvdm/dos/v86/cmd/backup/chp/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/backup/chs](../../base/mvdm/dos/v86/cmd/backup/chs) | 4 | [base/mvdm/dos/v86/cmd/backup/chs/sources](../../base/mvdm/dos/v86/cmd/backup/chs/sources), [base/mvdm/dos/v86/cmd/backup/chs/makefile](../../base/mvdm/dos/v86/cmd/backup/chs/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/backup/cht](../../base/mvdm/dos/v86/cmd/backup/cht) | 4 | [base/mvdm/dos/v86/cmd/backup/cht/sources](../../base/mvdm/dos/v86/cmd/backup/cht/sources), [base/mvdm/dos/v86/cmd/backup/cht/makefile](../../base/mvdm/dos/v86/cmd/backup/cht/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/backup/ger](../../base/mvdm/dos/v86/cmd/backup/ger) | 4 | [base/mvdm/dos/v86/cmd/backup/ger/sources](../../base/mvdm/dos/v86/cmd/backup/ger/sources), [base/mvdm/dos/v86/cmd/backup/ger/makefile](../../base/mvdm/dos/v86/cmd/backup/ger/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/backup/jpn](../../base/mvdm/dos/v86/cmd/backup/jpn) | 3 | [base/mvdm/dos/v86/cmd/backup/jpn/sources](../../base/mvdm/dos/v86/cmd/backup/jpn/sources) | — | — |
| [base/mvdm/dos/v86/cmd/backup/kor](../../base/mvdm/dos/v86/cmd/backup/kor) | 4 | [base/mvdm/dos/v86/cmd/backup/kor/sources](../../base/mvdm/dos/v86/cmd/backup/kor/sources), [base/mvdm/dos/v86/cmd/backup/kor/makefile](../../base/mvdm/dos/v86/cmd/backup/kor/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/backup/usa](../../base/mvdm/dos/v86/cmd/backup/usa) | 4 | [base/mvdm/dos/v86/cmd/backup/usa/sources](../../base/mvdm/dos/v86/cmd/backup/usa/sources), [base/mvdm/dos/v86/cmd/backup/usa/makefile](../../base/mvdm/dos/v86/cmd/backup/usa/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/command](../../base/mvdm/dos/v86/cmd/command) | 48 | [base/mvdm/dos/v86/cmd/command/dirs](../../base/mvdm/dos/v86/cmd/command/dirs) | — | — |
| [base/mvdm/dos/v86/cmd/command/br](../../base/mvdm/dos/v86/cmd/command/br) | 4 | [base/mvdm/dos/v86/cmd/command/br/sources](../../base/mvdm/dos/v86/cmd/command/br/sources), [base/mvdm/dos/v86/cmd/command/br/makefile](../../base/mvdm/dos/v86/cmd/command/br/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/command/chp](../../base/mvdm/dos/v86/cmd/command/chp) | 5 | [base/mvdm/dos/v86/cmd/command/chp/sources](../../base/mvdm/dos/v86/cmd/command/chp/sources), [base/mvdm/dos/v86/cmd/command/chp/makefile](../../base/mvdm/dos/v86/cmd/command/chp/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/command/chs](../../base/mvdm/dos/v86/cmd/command/chs) | 5 | [base/mvdm/dos/v86/cmd/command/chs/sources](../../base/mvdm/dos/v86/cmd/command/chs/sources), [base/mvdm/dos/v86/cmd/command/chs/makefile](../../base/mvdm/dos/v86/cmd/command/chs/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/command/cht](../../base/mvdm/dos/v86/cmd/command/cht) | 5 | [base/mvdm/dos/v86/cmd/command/cht/sources](../../base/mvdm/dos/v86/cmd/command/cht/sources), [base/mvdm/dos/v86/cmd/command/cht/makefile](../../base/mvdm/dos/v86/cmd/command/cht/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/command/cs](../../base/mvdm/dos/v86/cmd/command/cs) | 4 | [base/mvdm/dos/v86/cmd/command/cs/sources](../../base/mvdm/dos/v86/cmd/command/cs/sources), [base/mvdm/dos/v86/cmd/command/cs/makefile](../../base/mvdm/dos/v86/cmd/command/cs/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/command/da](../../base/mvdm/dos/v86/cmd/command/da) | 4 | [base/mvdm/dos/v86/cmd/command/da/sources](../../base/mvdm/dos/v86/cmd/command/da/sources), [base/mvdm/dos/v86/cmd/command/da/makefile](../../base/mvdm/dos/v86/cmd/command/da/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/command/el](../../base/mvdm/dos/v86/cmd/command/el) | 4 | [base/mvdm/dos/v86/cmd/command/el/sources](../../base/mvdm/dos/v86/cmd/command/el/sources), [base/mvdm/dos/v86/cmd/command/el/makefile](../../base/mvdm/dos/v86/cmd/command/el/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/command/es](../../base/mvdm/dos/v86/cmd/command/es) | 4 | [base/mvdm/dos/v86/cmd/command/es/sources](../../base/mvdm/dos/v86/cmd/command/es/sources), [base/mvdm/dos/v86/cmd/command/es/makefile](../../base/mvdm/dos/v86/cmd/command/es/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/command/fi](../../base/mvdm/dos/v86/cmd/command/fi) | 4 | [base/mvdm/dos/v86/cmd/command/fi/sources](../../base/mvdm/dos/v86/cmd/command/fi/sources), [base/mvdm/dos/v86/cmd/command/fi/makefile](../../base/mvdm/dos/v86/cmd/command/fi/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/command/fr](../../base/mvdm/dos/v86/cmd/command/fr) | 4 | [base/mvdm/dos/v86/cmd/command/fr/sources](../../base/mvdm/dos/v86/cmd/command/fr/sources), [base/mvdm/dos/v86/cmd/command/fr/makefile](../../base/mvdm/dos/v86/cmd/command/fr/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/command/ger](../../base/mvdm/dos/v86/cmd/command/ger) | 4 | [base/mvdm/dos/v86/cmd/command/ger/sources](../../base/mvdm/dos/v86/cmd/command/ger/sources), [base/mvdm/dos/v86/cmd/command/ger/makefile](../../base/mvdm/dos/v86/cmd/command/ger/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/command/hu](../../base/mvdm/dos/v86/cmd/command/hu) | 4 | [base/mvdm/dos/v86/cmd/command/hu/sources](../../base/mvdm/dos/v86/cmd/command/hu/sources), [base/mvdm/dos/v86/cmd/command/hu/makefile](../../base/mvdm/dos/v86/cmd/command/hu/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/command/it](../../base/mvdm/dos/v86/cmd/command/it) | 4 | [base/mvdm/dos/v86/cmd/command/it/sources](../../base/mvdm/dos/v86/cmd/command/it/sources), [base/mvdm/dos/v86/cmd/command/it/makefile](../../base/mvdm/dos/v86/cmd/command/it/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/command/jpn](../../base/mvdm/dos/v86/cmd/command/jpn) | 6 | [base/mvdm/dos/v86/cmd/command/jpn/sources](../../base/mvdm/dos/v86/cmd/command/jpn/sources), [base/mvdm/dos/v86/cmd/command/jpn/makefile](../../base/mvdm/dos/v86/cmd/command/jpn/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/command/kor](../../base/mvdm/dos/v86/cmd/command/kor) | 5 | [base/mvdm/dos/v86/cmd/command/kor/sources](../../base/mvdm/dos/v86/cmd/command/kor/sources), [base/mvdm/dos/v86/cmd/command/kor/makefile](../../base/mvdm/dos/v86/cmd/command/kor/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/command/nec_98](../../base/mvdm/dos/v86/cmd/command/nec_98) | 10 | [base/mvdm/dos/v86/cmd/command/nec_98/sources](../../base/mvdm/dos/v86/cmd/command/nec_98/sources), [base/mvdm/dos/v86/cmd/command/nec_98/makefile](../../base/mvdm/dos/v86/cmd/command/nec_98/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/command/nl](../../base/mvdm/dos/v86/cmd/command/nl) | 4 | [base/mvdm/dos/v86/cmd/command/nl/sources](../../base/mvdm/dos/v86/cmd/command/nl/sources), [base/mvdm/dos/v86/cmd/command/nl/makefile](../../base/mvdm/dos/v86/cmd/command/nl/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/command/no](../../base/mvdm/dos/v86/cmd/command/no) | 4 | [base/mvdm/dos/v86/cmd/command/no/sources](../../base/mvdm/dos/v86/cmd/command/no/sources), [base/mvdm/dos/v86/cmd/command/no/makefile](../../base/mvdm/dos/v86/cmd/command/no/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/command/pl](../../base/mvdm/dos/v86/cmd/command/pl) | 4 | [base/mvdm/dos/v86/cmd/command/pl/sources](../../base/mvdm/dos/v86/cmd/command/pl/sources), [base/mvdm/dos/v86/cmd/command/pl/makefile](../../base/mvdm/dos/v86/cmd/command/pl/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/command/psu](../../base/mvdm/dos/v86/cmd/command/psu) | 4 | [base/mvdm/dos/v86/cmd/command/psu/sources](../../base/mvdm/dos/v86/cmd/command/psu/sources), [base/mvdm/dos/v86/cmd/command/psu/makefile](../../base/mvdm/dos/v86/cmd/command/psu/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/command/pt](../../base/mvdm/dos/v86/cmd/command/pt) | 4 | [base/mvdm/dos/v86/cmd/command/pt/sources](../../base/mvdm/dos/v86/cmd/command/pt/sources), [base/mvdm/dos/v86/cmd/command/pt/makefile](../../base/mvdm/dos/v86/cmd/command/pt/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/command/ru](../../base/mvdm/dos/v86/cmd/command/ru) | 4 | [base/mvdm/dos/v86/cmd/command/ru/sources](../../base/mvdm/dos/v86/cmd/command/ru/sources), [base/mvdm/dos/v86/cmd/command/ru/makefile](../../base/mvdm/dos/v86/cmd/command/ru/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/command/sv](../../base/mvdm/dos/v86/cmd/command/sv) | 4 | [base/mvdm/dos/v86/cmd/command/sv/sources](../../base/mvdm/dos/v86/cmd/command/sv/sources), [base/mvdm/dos/v86/cmd/command/sv/makefile](../../base/mvdm/dos/v86/cmd/command/sv/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/command/tr](../../base/mvdm/dos/v86/cmd/command/tr) | 4 | [base/mvdm/dos/v86/cmd/command/tr/sources](../../base/mvdm/dos/v86/cmd/command/tr/sources), [base/mvdm/dos/v86/cmd/command/tr/makefile](../../base/mvdm/dos/v86/cmd/command/tr/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/command/tst](../../base/mvdm/dos/v86/cmd/command/tst) | 4 | [base/mvdm/dos/v86/cmd/command/tst/sources](../../base/mvdm/dos/v86/cmd/command/tst/sources), [base/mvdm/dos/v86/cmd/command/tst/makefile](../../base/mvdm/dos/v86/cmd/command/tst/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/command/usa](../../base/mvdm/dos/v86/cmd/command/usa) | 5 | [base/mvdm/dos/v86/cmd/command/usa/sources](../../base/mvdm/dos/v86/cmd/command/usa/sources), [base/mvdm/dos/v86/cmd/command/usa/makefile](../../base/mvdm/dos/v86/cmd/command/usa/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/debug](../../base/mvdm/dos/v86/cmd/debug) | 19 | [base/mvdm/dos/v86/cmd/debug/dirs](../../base/mvdm/dos/v86/cmd/debug/dirs) | — | — |
| [base/mvdm/dos/v86/cmd/debug/br](../../base/mvdm/dos/v86/cmd/debug/br) | 3 | [base/mvdm/dos/v86/cmd/debug/br/sources](../../base/mvdm/dos/v86/cmd/debug/br/sources), [base/mvdm/dos/v86/cmd/debug/br/makefile](../../base/mvdm/dos/v86/cmd/debug/br/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/debug/chp](../../base/mvdm/dos/v86/cmd/debug/chp) | 4 | [base/mvdm/dos/v86/cmd/debug/chp/sources](../../base/mvdm/dos/v86/cmd/debug/chp/sources), [base/mvdm/dos/v86/cmd/debug/chp/makefile](../../base/mvdm/dos/v86/cmd/debug/chp/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/debug/chs](../../base/mvdm/dos/v86/cmd/debug/chs) | 4 | [base/mvdm/dos/v86/cmd/debug/chs/sources](../../base/mvdm/dos/v86/cmd/debug/chs/sources), [base/mvdm/dos/v86/cmd/debug/chs/makefile](../../base/mvdm/dos/v86/cmd/debug/chs/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/debug/cht](../../base/mvdm/dos/v86/cmd/debug/cht) | 4 | [base/mvdm/dos/v86/cmd/debug/cht/sources](../../base/mvdm/dos/v86/cmd/debug/cht/sources), [base/mvdm/dos/v86/cmd/debug/cht/makefile](../../base/mvdm/dos/v86/cmd/debug/cht/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/debug/cs](../../base/mvdm/dos/v86/cmd/debug/cs) | 3 | [base/mvdm/dos/v86/cmd/debug/cs/sources](../../base/mvdm/dos/v86/cmd/debug/cs/sources), [base/mvdm/dos/v86/cmd/debug/cs/makefile](../../base/mvdm/dos/v86/cmd/debug/cs/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/debug/da](../../base/mvdm/dos/v86/cmd/debug/da) | 3 | [base/mvdm/dos/v86/cmd/debug/da/sources](../../base/mvdm/dos/v86/cmd/debug/da/sources), [base/mvdm/dos/v86/cmd/debug/da/makefile](../../base/mvdm/dos/v86/cmd/debug/da/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/debug/dosdebug](../../base/mvdm/dos/v86/cmd/debug/dosdebug) | 12 | — | — | — |
| [base/mvdm/dos/v86/cmd/debug/el](../../base/mvdm/dos/v86/cmd/debug/el) | 3 | [base/mvdm/dos/v86/cmd/debug/el/sources](../../base/mvdm/dos/v86/cmd/debug/el/sources), [base/mvdm/dos/v86/cmd/debug/el/makefile](../../base/mvdm/dos/v86/cmd/debug/el/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/debug/es](../../base/mvdm/dos/v86/cmd/debug/es) | 3 | [base/mvdm/dos/v86/cmd/debug/es/sources](../../base/mvdm/dos/v86/cmd/debug/es/sources), [base/mvdm/dos/v86/cmd/debug/es/makefile](../../base/mvdm/dos/v86/cmd/debug/es/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/debug/fi](../../base/mvdm/dos/v86/cmd/debug/fi) | 3 | [base/mvdm/dos/v86/cmd/debug/fi/sources](../../base/mvdm/dos/v86/cmd/debug/fi/sources), [base/mvdm/dos/v86/cmd/debug/fi/makefile](../../base/mvdm/dos/v86/cmd/debug/fi/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/debug/fr](../../base/mvdm/dos/v86/cmd/debug/fr) | 3 | [base/mvdm/dos/v86/cmd/debug/fr/sources](../../base/mvdm/dos/v86/cmd/debug/fr/sources), [base/mvdm/dos/v86/cmd/debug/fr/makefile](../../base/mvdm/dos/v86/cmd/debug/fr/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/debug/ger](../../base/mvdm/dos/v86/cmd/debug/ger) | 3 | [base/mvdm/dos/v86/cmd/debug/ger/sources](../../base/mvdm/dos/v86/cmd/debug/ger/sources), [base/mvdm/dos/v86/cmd/debug/ger/makefile](../../base/mvdm/dos/v86/cmd/debug/ger/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/debug/hu](../../base/mvdm/dos/v86/cmd/debug/hu) | 3 | [base/mvdm/dos/v86/cmd/debug/hu/sources](../../base/mvdm/dos/v86/cmd/debug/hu/sources), [base/mvdm/dos/v86/cmd/debug/hu/makefile](../../base/mvdm/dos/v86/cmd/debug/hu/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/debug/it](../../base/mvdm/dos/v86/cmd/debug/it) | 3 | [base/mvdm/dos/v86/cmd/debug/it/sources](../../base/mvdm/dos/v86/cmd/debug/it/sources), [base/mvdm/dos/v86/cmd/debug/it/makefile](../../base/mvdm/dos/v86/cmd/debug/it/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/debug/jpn](../../base/mvdm/dos/v86/cmd/debug/jpn) | 4 | [base/mvdm/dos/v86/cmd/debug/jpn/sources](../../base/mvdm/dos/v86/cmd/debug/jpn/sources), [base/mvdm/dos/v86/cmd/debug/jpn/makefile](../../base/mvdm/dos/v86/cmd/debug/jpn/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/debug/kor](../../base/mvdm/dos/v86/cmd/debug/kor) | 4 | [base/mvdm/dos/v86/cmd/debug/kor/sources](../../base/mvdm/dos/v86/cmd/debug/kor/sources), [base/mvdm/dos/v86/cmd/debug/kor/makefile](../../base/mvdm/dos/v86/cmd/debug/kor/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/debug/nl](../../base/mvdm/dos/v86/cmd/debug/nl) | 3 | [base/mvdm/dos/v86/cmd/debug/nl/sources](../../base/mvdm/dos/v86/cmd/debug/nl/sources), [base/mvdm/dos/v86/cmd/debug/nl/makefile](../../base/mvdm/dos/v86/cmd/debug/nl/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/debug/no](../../base/mvdm/dos/v86/cmd/debug/no) | 3 | [base/mvdm/dos/v86/cmd/debug/no/sources](../../base/mvdm/dos/v86/cmd/debug/no/sources), [base/mvdm/dos/v86/cmd/debug/no/makefile](../../base/mvdm/dos/v86/cmd/debug/no/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/debug/pl](../../base/mvdm/dos/v86/cmd/debug/pl) | 3 | [base/mvdm/dos/v86/cmd/debug/pl/sources](../../base/mvdm/dos/v86/cmd/debug/pl/sources), [base/mvdm/dos/v86/cmd/debug/pl/makefile](../../base/mvdm/dos/v86/cmd/debug/pl/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/debug/psu](../../base/mvdm/dos/v86/cmd/debug/psu) | 3 | [base/mvdm/dos/v86/cmd/debug/psu/sources](../../base/mvdm/dos/v86/cmd/debug/psu/sources), [base/mvdm/dos/v86/cmd/debug/psu/makefile](../../base/mvdm/dos/v86/cmd/debug/psu/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/debug/pt](../../base/mvdm/dos/v86/cmd/debug/pt) | 3 | [base/mvdm/dos/v86/cmd/debug/pt/sources](../../base/mvdm/dos/v86/cmd/debug/pt/sources), [base/mvdm/dos/v86/cmd/debug/pt/makefile](../../base/mvdm/dos/v86/cmd/debug/pt/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/debug/ru](../../base/mvdm/dos/v86/cmd/debug/ru) | 3 | [base/mvdm/dos/v86/cmd/debug/ru/sources](../../base/mvdm/dos/v86/cmd/debug/ru/sources), [base/mvdm/dos/v86/cmd/debug/ru/makefile](../../base/mvdm/dos/v86/cmd/debug/ru/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/debug/sv](../../base/mvdm/dos/v86/cmd/debug/sv) | 3 | [base/mvdm/dos/v86/cmd/debug/sv/sources](../../base/mvdm/dos/v86/cmd/debug/sv/sources), [base/mvdm/dos/v86/cmd/debug/sv/makefile](../../base/mvdm/dos/v86/cmd/debug/sv/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/debug/tr](../../base/mvdm/dos/v86/cmd/debug/tr) | 3 | [base/mvdm/dos/v86/cmd/debug/tr/sources](../../base/mvdm/dos/v86/cmd/debug/tr/sources), [base/mvdm/dos/v86/cmd/debug/tr/makefile](../../base/mvdm/dos/v86/cmd/debug/tr/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/debug/tst](../../base/mvdm/dos/v86/cmd/debug/tst) | 3 | [base/mvdm/dos/v86/cmd/debug/tst/sources](../../base/mvdm/dos/v86/cmd/debug/tst/sources), [base/mvdm/dos/v86/cmd/debug/tst/makefile](../../base/mvdm/dos/v86/cmd/debug/tst/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/debug/usa](../../base/mvdm/dos/v86/cmd/debug/usa) | 4 | [base/mvdm/dos/v86/cmd/debug/usa/sources](../../base/mvdm/dos/v86/cmd/debug/usa/sources), [base/mvdm/dos/v86/cmd/debug/usa/makefile](../../base/mvdm/dos/v86/cmd/debug/usa/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/edit](../../base/mvdm/dos/v86/cmd/edit) | 5 | [base/mvdm/dos/v86/cmd/edit/dirs](../../base/mvdm/dos/v86/cmd/edit/dirs) | — | — |
| [base/mvdm/dos/v86/cmd/edit/usa](../../base/mvdm/dos/v86/cmd/edit/usa) | 3 | [base/mvdm/dos/v86/cmd/edit/usa/sources](../../base/mvdm/dos/v86/cmd/edit/usa/sources), [base/mvdm/dos/v86/cmd/edit/usa/makefile](../../base/mvdm/dos/v86/cmd/edit/usa/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/edlin](../../base/mvdm/dos/v86/cmd/edlin) | 10 | [base/mvdm/dos/v86/cmd/edlin/dirs](../../base/mvdm/dos/v86/cmd/edlin/dirs) | — | — |
| [base/mvdm/dos/v86/cmd/edlin/br](../../base/mvdm/dos/v86/cmd/edlin/br) | 3 | [base/mvdm/dos/v86/cmd/edlin/br/sources](../../base/mvdm/dos/v86/cmd/edlin/br/sources), [base/mvdm/dos/v86/cmd/edlin/br/makefile](../../base/mvdm/dos/v86/cmd/edlin/br/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/edlin/chp](../../base/mvdm/dos/v86/cmd/edlin/chp) | 4 | [base/mvdm/dos/v86/cmd/edlin/chp/sources](../../base/mvdm/dos/v86/cmd/edlin/chp/sources), [base/mvdm/dos/v86/cmd/edlin/chp/makefile](../../base/mvdm/dos/v86/cmd/edlin/chp/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/edlin/chs](../../base/mvdm/dos/v86/cmd/edlin/chs) | 4 | [base/mvdm/dos/v86/cmd/edlin/chs/sources](../../base/mvdm/dos/v86/cmd/edlin/chs/sources), [base/mvdm/dos/v86/cmd/edlin/chs/makefile](../../base/mvdm/dos/v86/cmd/edlin/chs/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/edlin/cht](../../base/mvdm/dos/v86/cmd/edlin/cht) | 4 | [base/mvdm/dos/v86/cmd/edlin/cht/sources](../../base/mvdm/dos/v86/cmd/edlin/cht/sources), [base/mvdm/dos/v86/cmd/edlin/cht/makefile](../../base/mvdm/dos/v86/cmd/edlin/cht/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/edlin/cs](../../base/mvdm/dos/v86/cmd/edlin/cs) | 3 | [base/mvdm/dos/v86/cmd/edlin/cs/sources](../../base/mvdm/dos/v86/cmd/edlin/cs/sources), [base/mvdm/dos/v86/cmd/edlin/cs/makefile](../../base/mvdm/dos/v86/cmd/edlin/cs/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/edlin/da](../../base/mvdm/dos/v86/cmd/edlin/da) | 3 | [base/mvdm/dos/v86/cmd/edlin/da/sources](../../base/mvdm/dos/v86/cmd/edlin/da/sources), [base/mvdm/dos/v86/cmd/edlin/da/makefile](../../base/mvdm/dos/v86/cmd/edlin/da/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/edlin/el](../../base/mvdm/dos/v86/cmd/edlin/el) | 3 | [base/mvdm/dos/v86/cmd/edlin/el/sources](../../base/mvdm/dos/v86/cmd/edlin/el/sources), [base/mvdm/dos/v86/cmd/edlin/el/makefile](../../base/mvdm/dos/v86/cmd/edlin/el/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/edlin/es](../../base/mvdm/dos/v86/cmd/edlin/es) | 3 | [base/mvdm/dos/v86/cmd/edlin/es/sources](../../base/mvdm/dos/v86/cmd/edlin/es/sources), [base/mvdm/dos/v86/cmd/edlin/es/makefile](../../base/mvdm/dos/v86/cmd/edlin/es/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/edlin/fi](../../base/mvdm/dos/v86/cmd/edlin/fi) | 3 | [base/mvdm/dos/v86/cmd/edlin/fi/sources](../../base/mvdm/dos/v86/cmd/edlin/fi/sources), [base/mvdm/dos/v86/cmd/edlin/fi/makefile](../../base/mvdm/dos/v86/cmd/edlin/fi/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/edlin/fr](../../base/mvdm/dos/v86/cmd/edlin/fr) | 3 | [base/mvdm/dos/v86/cmd/edlin/fr/sources](../../base/mvdm/dos/v86/cmd/edlin/fr/sources), [base/mvdm/dos/v86/cmd/edlin/fr/makefile](../../base/mvdm/dos/v86/cmd/edlin/fr/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/edlin/ger](../../base/mvdm/dos/v86/cmd/edlin/ger) | 3 | [base/mvdm/dos/v86/cmd/edlin/ger/sources](../../base/mvdm/dos/v86/cmd/edlin/ger/sources), [base/mvdm/dos/v86/cmd/edlin/ger/makefile](../../base/mvdm/dos/v86/cmd/edlin/ger/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/edlin/hu](../../base/mvdm/dos/v86/cmd/edlin/hu) | 3 | [base/mvdm/dos/v86/cmd/edlin/hu/sources](../../base/mvdm/dos/v86/cmd/edlin/hu/sources), [base/mvdm/dos/v86/cmd/edlin/hu/makefile](../../base/mvdm/dos/v86/cmd/edlin/hu/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/edlin/it](../../base/mvdm/dos/v86/cmd/edlin/it) | 3 | [base/mvdm/dos/v86/cmd/edlin/it/sources](../../base/mvdm/dos/v86/cmd/edlin/it/sources), [base/mvdm/dos/v86/cmd/edlin/it/makefile](../../base/mvdm/dos/v86/cmd/edlin/it/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/edlin/jpn](../../base/mvdm/dos/v86/cmd/edlin/jpn) | 4 | [base/mvdm/dos/v86/cmd/edlin/jpn/sources](../../base/mvdm/dos/v86/cmd/edlin/jpn/sources), [base/mvdm/dos/v86/cmd/edlin/jpn/makefile](../../base/mvdm/dos/v86/cmd/edlin/jpn/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/edlin/kor](../../base/mvdm/dos/v86/cmd/edlin/kor) | 4 | [base/mvdm/dos/v86/cmd/edlin/kor/sources](../../base/mvdm/dos/v86/cmd/edlin/kor/sources), [base/mvdm/dos/v86/cmd/edlin/kor/makefile](../../base/mvdm/dos/v86/cmd/edlin/kor/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/edlin/nl](../../base/mvdm/dos/v86/cmd/edlin/nl) | 3 | [base/mvdm/dos/v86/cmd/edlin/nl/sources](../../base/mvdm/dos/v86/cmd/edlin/nl/sources), [base/mvdm/dos/v86/cmd/edlin/nl/makefile](../../base/mvdm/dos/v86/cmd/edlin/nl/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/edlin/no](../../base/mvdm/dos/v86/cmd/edlin/no) | 3 | [base/mvdm/dos/v86/cmd/edlin/no/sources](../../base/mvdm/dos/v86/cmd/edlin/no/sources), [base/mvdm/dos/v86/cmd/edlin/no/makefile](../../base/mvdm/dos/v86/cmd/edlin/no/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/edlin/pl](../../base/mvdm/dos/v86/cmd/edlin/pl) | 3 | [base/mvdm/dos/v86/cmd/edlin/pl/sources](../../base/mvdm/dos/v86/cmd/edlin/pl/sources), [base/mvdm/dos/v86/cmd/edlin/pl/makefile](../../base/mvdm/dos/v86/cmd/edlin/pl/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/edlin/psu](../../base/mvdm/dos/v86/cmd/edlin/psu) | 3 | [base/mvdm/dos/v86/cmd/edlin/psu/sources](../../base/mvdm/dos/v86/cmd/edlin/psu/sources), [base/mvdm/dos/v86/cmd/edlin/psu/makefile](../../base/mvdm/dos/v86/cmd/edlin/psu/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/edlin/pt](../../base/mvdm/dos/v86/cmd/edlin/pt) | 3 | [base/mvdm/dos/v86/cmd/edlin/pt/sources](../../base/mvdm/dos/v86/cmd/edlin/pt/sources), [base/mvdm/dos/v86/cmd/edlin/pt/makefile](../../base/mvdm/dos/v86/cmd/edlin/pt/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/edlin/ru](../../base/mvdm/dos/v86/cmd/edlin/ru) | 3 | [base/mvdm/dos/v86/cmd/edlin/ru/sources](../../base/mvdm/dos/v86/cmd/edlin/ru/sources), [base/mvdm/dos/v86/cmd/edlin/ru/makefile](../../base/mvdm/dos/v86/cmd/edlin/ru/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/edlin/sv](../../base/mvdm/dos/v86/cmd/edlin/sv) | 3 | [base/mvdm/dos/v86/cmd/edlin/sv/sources](../../base/mvdm/dos/v86/cmd/edlin/sv/sources), [base/mvdm/dos/v86/cmd/edlin/sv/makefile](../../base/mvdm/dos/v86/cmd/edlin/sv/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/edlin/tr](../../base/mvdm/dos/v86/cmd/edlin/tr) | 3 | [base/mvdm/dos/v86/cmd/edlin/tr/sources](../../base/mvdm/dos/v86/cmd/edlin/tr/sources), [base/mvdm/dos/v86/cmd/edlin/tr/makefile](../../base/mvdm/dos/v86/cmd/edlin/tr/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/edlin/tst](../../base/mvdm/dos/v86/cmd/edlin/tst) | 3 | [base/mvdm/dos/v86/cmd/edlin/tst/sources](../../base/mvdm/dos/v86/cmd/edlin/tst/sources), [base/mvdm/dos/v86/cmd/edlin/tst/makefile](../../base/mvdm/dos/v86/cmd/edlin/tst/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/edlin/usa](../../base/mvdm/dos/v86/cmd/edlin/usa) | 4 | [base/mvdm/dos/v86/cmd/edlin/usa/sources](../../base/mvdm/dos/v86/cmd/edlin/usa/sources), [base/mvdm/dos/v86/cmd/edlin/usa/makefile](../../base/mvdm/dos/v86/cmd/edlin/usa/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/exe2bin](../../base/mvdm/dos/v86/cmd/exe2bin) | 11 | [base/mvdm/dos/v86/cmd/exe2bin/dirs](../../base/mvdm/dos/v86/cmd/exe2bin/dirs) | — | — |
| [base/mvdm/dos/v86/cmd/exe2bin/br](../../base/mvdm/dos/v86/cmd/exe2bin/br) | 3 | [base/mvdm/dos/v86/cmd/exe2bin/br/sources](../../base/mvdm/dos/v86/cmd/exe2bin/br/sources), [base/mvdm/dos/v86/cmd/exe2bin/br/makefile](../../base/mvdm/dos/v86/cmd/exe2bin/br/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/exe2bin/chp](../../base/mvdm/dos/v86/cmd/exe2bin/chp) | 4 | [base/mvdm/dos/v86/cmd/exe2bin/chp/sources](../../base/mvdm/dos/v86/cmd/exe2bin/chp/sources), [base/mvdm/dos/v86/cmd/exe2bin/chp/makefile](../../base/mvdm/dos/v86/cmd/exe2bin/chp/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/exe2bin/chs](../../base/mvdm/dos/v86/cmd/exe2bin/chs) | 4 | [base/mvdm/dos/v86/cmd/exe2bin/chs/sources](../../base/mvdm/dos/v86/cmd/exe2bin/chs/sources), [base/mvdm/dos/v86/cmd/exe2bin/chs/makefile](../../base/mvdm/dos/v86/cmd/exe2bin/chs/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/exe2bin/cht](../../base/mvdm/dos/v86/cmd/exe2bin/cht) | 4 | [base/mvdm/dos/v86/cmd/exe2bin/cht/sources](../../base/mvdm/dos/v86/cmd/exe2bin/cht/sources), [base/mvdm/dos/v86/cmd/exe2bin/cht/makefile](../../base/mvdm/dos/v86/cmd/exe2bin/cht/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/exe2bin/cs](../../base/mvdm/dos/v86/cmd/exe2bin/cs) | 3 | [base/mvdm/dos/v86/cmd/exe2bin/cs/sources](../../base/mvdm/dos/v86/cmd/exe2bin/cs/sources), [base/mvdm/dos/v86/cmd/exe2bin/cs/makefile](../../base/mvdm/dos/v86/cmd/exe2bin/cs/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/exe2bin/da](../../base/mvdm/dos/v86/cmd/exe2bin/da) | 3 | [base/mvdm/dos/v86/cmd/exe2bin/da/sources](../../base/mvdm/dos/v86/cmd/exe2bin/da/sources), [base/mvdm/dos/v86/cmd/exe2bin/da/makefile](../../base/mvdm/dos/v86/cmd/exe2bin/da/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/exe2bin/el](../../base/mvdm/dos/v86/cmd/exe2bin/el) | 3 | [base/mvdm/dos/v86/cmd/exe2bin/el/sources](../../base/mvdm/dos/v86/cmd/exe2bin/el/sources), [base/mvdm/dos/v86/cmd/exe2bin/el/makefile](../../base/mvdm/dos/v86/cmd/exe2bin/el/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/exe2bin/es](../../base/mvdm/dos/v86/cmd/exe2bin/es) | 3 | [base/mvdm/dos/v86/cmd/exe2bin/es/sources](../../base/mvdm/dos/v86/cmd/exe2bin/es/sources), [base/mvdm/dos/v86/cmd/exe2bin/es/makefile](../../base/mvdm/dos/v86/cmd/exe2bin/es/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/exe2bin/fi](../../base/mvdm/dos/v86/cmd/exe2bin/fi) | 3 | [base/mvdm/dos/v86/cmd/exe2bin/fi/sources](../../base/mvdm/dos/v86/cmd/exe2bin/fi/sources), [base/mvdm/dos/v86/cmd/exe2bin/fi/makefile](../../base/mvdm/dos/v86/cmd/exe2bin/fi/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/exe2bin/fr](../../base/mvdm/dos/v86/cmd/exe2bin/fr) | 3 | [base/mvdm/dos/v86/cmd/exe2bin/fr/sources](../../base/mvdm/dos/v86/cmd/exe2bin/fr/sources), [base/mvdm/dos/v86/cmd/exe2bin/fr/makefile](../../base/mvdm/dos/v86/cmd/exe2bin/fr/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/exe2bin/ger](../../base/mvdm/dos/v86/cmd/exe2bin/ger) | 3 | [base/mvdm/dos/v86/cmd/exe2bin/ger/sources](../../base/mvdm/dos/v86/cmd/exe2bin/ger/sources), [base/mvdm/dos/v86/cmd/exe2bin/ger/makefile](../../base/mvdm/dos/v86/cmd/exe2bin/ger/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/exe2bin/hu](../../base/mvdm/dos/v86/cmd/exe2bin/hu) | 3 | [base/mvdm/dos/v86/cmd/exe2bin/hu/sources](../../base/mvdm/dos/v86/cmd/exe2bin/hu/sources), [base/mvdm/dos/v86/cmd/exe2bin/hu/makefile](../../base/mvdm/dos/v86/cmd/exe2bin/hu/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/exe2bin/it](../../base/mvdm/dos/v86/cmd/exe2bin/it) | 3 | [base/mvdm/dos/v86/cmd/exe2bin/it/sources](../../base/mvdm/dos/v86/cmd/exe2bin/it/sources), [base/mvdm/dos/v86/cmd/exe2bin/it/makefile](../../base/mvdm/dos/v86/cmd/exe2bin/it/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/exe2bin/jpn](../../base/mvdm/dos/v86/cmd/exe2bin/jpn) | 4 | [base/mvdm/dos/v86/cmd/exe2bin/jpn/sources](../../base/mvdm/dos/v86/cmd/exe2bin/jpn/sources), [base/mvdm/dos/v86/cmd/exe2bin/jpn/makefile](../../base/mvdm/dos/v86/cmd/exe2bin/jpn/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/exe2bin/kor](../../base/mvdm/dos/v86/cmd/exe2bin/kor) | 4 | [base/mvdm/dos/v86/cmd/exe2bin/kor/sources](../../base/mvdm/dos/v86/cmd/exe2bin/kor/sources), [base/mvdm/dos/v86/cmd/exe2bin/kor/makefile](../../base/mvdm/dos/v86/cmd/exe2bin/kor/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/exe2bin/nl](../../base/mvdm/dos/v86/cmd/exe2bin/nl) | 3 | [base/mvdm/dos/v86/cmd/exe2bin/nl/sources](../../base/mvdm/dos/v86/cmd/exe2bin/nl/sources), [base/mvdm/dos/v86/cmd/exe2bin/nl/makefile](../../base/mvdm/dos/v86/cmd/exe2bin/nl/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/exe2bin/no](../../base/mvdm/dos/v86/cmd/exe2bin/no) | 3 | [base/mvdm/dos/v86/cmd/exe2bin/no/sources](../../base/mvdm/dos/v86/cmd/exe2bin/no/sources), [base/mvdm/dos/v86/cmd/exe2bin/no/makefile](../../base/mvdm/dos/v86/cmd/exe2bin/no/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/exe2bin/pl](../../base/mvdm/dos/v86/cmd/exe2bin/pl) | 3 | [base/mvdm/dos/v86/cmd/exe2bin/pl/sources](../../base/mvdm/dos/v86/cmd/exe2bin/pl/sources), [base/mvdm/dos/v86/cmd/exe2bin/pl/makefile](../../base/mvdm/dos/v86/cmd/exe2bin/pl/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/exe2bin/psu](../../base/mvdm/dos/v86/cmd/exe2bin/psu) | 3 | [base/mvdm/dos/v86/cmd/exe2bin/psu/sources](../../base/mvdm/dos/v86/cmd/exe2bin/psu/sources), [base/mvdm/dos/v86/cmd/exe2bin/psu/makefile](../../base/mvdm/dos/v86/cmd/exe2bin/psu/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/exe2bin/pt](../../base/mvdm/dos/v86/cmd/exe2bin/pt) | 3 | [base/mvdm/dos/v86/cmd/exe2bin/pt/sources](../../base/mvdm/dos/v86/cmd/exe2bin/pt/sources), [base/mvdm/dos/v86/cmd/exe2bin/pt/makefile](../../base/mvdm/dos/v86/cmd/exe2bin/pt/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/exe2bin/ru](../../base/mvdm/dos/v86/cmd/exe2bin/ru) | 3 | [base/mvdm/dos/v86/cmd/exe2bin/ru/sources](../../base/mvdm/dos/v86/cmd/exe2bin/ru/sources), [base/mvdm/dos/v86/cmd/exe2bin/ru/makefile](../../base/mvdm/dos/v86/cmd/exe2bin/ru/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/exe2bin/sv](../../base/mvdm/dos/v86/cmd/exe2bin/sv) | 3 | [base/mvdm/dos/v86/cmd/exe2bin/sv/sources](../../base/mvdm/dos/v86/cmd/exe2bin/sv/sources), [base/mvdm/dos/v86/cmd/exe2bin/sv/makefile](../../base/mvdm/dos/v86/cmd/exe2bin/sv/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/exe2bin/tr](../../base/mvdm/dos/v86/cmd/exe2bin/tr) | 3 | [base/mvdm/dos/v86/cmd/exe2bin/tr/sources](../../base/mvdm/dos/v86/cmd/exe2bin/tr/sources), [base/mvdm/dos/v86/cmd/exe2bin/tr/makefile](../../base/mvdm/dos/v86/cmd/exe2bin/tr/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/exe2bin/tst](../../base/mvdm/dos/v86/cmd/exe2bin/tst) | 3 | [base/mvdm/dos/v86/cmd/exe2bin/tst/sources](../../base/mvdm/dos/v86/cmd/exe2bin/tst/sources), [base/mvdm/dos/v86/cmd/exe2bin/tst/makefile](../../base/mvdm/dos/v86/cmd/exe2bin/tst/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/exe2bin/usa](../../base/mvdm/dos/v86/cmd/exe2bin/usa) | 4 | [base/mvdm/dos/v86/cmd/exe2bin/usa/sources](../../base/mvdm/dos/v86/cmd/exe2bin/usa/sources), [base/mvdm/dos/v86/cmd/exe2bin/usa/makefile](../../base/mvdm/dos/v86/cmd/exe2bin/usa/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/fastopen](../../base/mvdm/dos/v86/cmd/fastopen) | 5 | [base/mvdm/dos/v86/cmd/fastopen/dirs](../../base/mvdm/dos/v86/cmd/fastopen/dirs) | — | — |
| [base/mvdm/dos/v86/cmd/fastopen/usa](../../base/mvdm/dos/v86/cmd/fastopen/usa) | 3 | [base/mvdm/dos/v86/cmd/fastopen/usa/sources](../../base/mvdm/dos/v86/cmd/fastopen/usa/sources), [base/mvdm/dos/v86/cmd/fastopen/usa/makefile](../../base/mvdm/dos/v86/cmd/fastopen/usa/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/graphics](../../base/mvdm/dos/v86/cmd/graphics) | 37 | [base/mvdm/dos/v86/cmd/graphics/dirs](../../base/mvdm/dos/v86/cmd/graphics/dirs) | — | — |
| [base/mvdm/dos/v86/cmd/graphics/br](../../base/mvdm/dos/v86/cmd/graphics/br) | 3 | [base/mvdm/dos/v86/cmd/graphics/br/sources](../../base/mvdm/dos/v86/cmd/graphics/br/sources), [base/mvdm/dos/v86/cmd/graphics/br/makefile](../../base/mvdm/dos/v86/cmd/graphics/br/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/graphics/chp](../../base/mvdm/dos/v86/cmd/graphics/chp) | 4 | [base/mvdm/dos/v86/cmd/graphics/chp/sources](../../base/mvdm/dos/v86/cmd/graphics/chp/sources), [base/mvdm/dos/v86/cmd/graphics/chp/makefile](../../base/mvdm/dos/v86/cmd/graphics/chp/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/graphics/chs](../../base/mvdm/dos/v86/cmd/graphics/chs) | 4 | [base/mvdm/dos/v86/cmd/graphics/chs/sources](../../base/mvdm/dos/v86/cmd/graphics/chs/sources), [base/mvdm/dos/v86/cmd/graphics/chs/makefile](../../base/mvdm/dos/v86/cmd/graphics/chs/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/graphics/cht](../../base/mvdm/dos/v86/cmd/graphics/cht) | 4 | [base/mvdm/dos/v86/cmd/graphics/cht/sources](../../base/mvdm/dos/v86/cmd/graphics/cht/sources), [base/mvdm/dos/v86/cmd/graphics/cht/makefile](../../base/mvdm/dos/v86/cmd/graphics/cht/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/graphics/cs](../../base/mvdm/dos/v86/cmd/graphics/cs) | 3 | [base/mvdm/dos/v86/cmd/graphics/cs/sources](../../base/mvdm/dos/v86/cmd/graphics/cs/sources), [base/mvdm/dos/v86/cmd/graphics/cs/makefile](../../base/mvdm/dos/v86/cmd/graphics/cs/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/graphics/da](../../base/mvdm/dos/v86/cmd/graphics/da) | 3 | [base/mvdm/dos/v86/cmd/graphics/da/sources](../../base/mvdm/dos/v86/cmd/graphics/da/sources), [base/mvdm/dos/v86/cmd/graphics/da/makefile](../../base/mvdm/dos/v86/cmd/graphics/da/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/graphics/el](../../base/mvdm/dos/v86/cmd/graphics/el) | 3 | [base/mvdm/dos/v86/cmd/graphics/el/sources](../../base/mvdm/dos/v86/cmd/graphics/el/sources), [base/mvdm/dos/v86/cmd/graphics/el/makefile](../../base/mvdm/dos/v86/cmd/graphics/el/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/graphics/es](../../base/mvdm/dos/v86/cmd/graphics/es) | 3 | [base/mvdm/dos/v86/cmd/graphics/es/sources](../../base/mvdm/dos/v86/cmd/graphics/es/sources), [base/mvdm/dos/v86/cmd/graphics/es/makefile](../../base/mvdm/dos/v86/cmd/graphics/es/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/graphics/fi](../../base/mvdm/dos/v86/cmd/graphics/fi) | 3 | [base/mvdm/dos/v86/cmd/graphics/fi/sources](../../base/mvdm/dos/v86/cmd/graphics/fi/sources), [base/mvdm/dos/v86/cmd/graphics/fi/makefile](../../base/mvdm/dos/v86/cmd/graphics/fi/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/graphics/fr](../../base/mvdm/dos/v86/cmd/graphics/fr) | 3 | [base/mvdm/dos/v86/cmd/graphics/fr/sources](../../base/mvdm/dos/v86/cmd/graphics/fr/sources), [base/mvdm/dos/v86/cmd/graphics/fr/makefile](../../base/mvdm/dos/v86/cmd/graphics/fr/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/graphics/ger](../../base/mvdm/dos/v86/cmd/graphics/ger) | 3 | [base/mvdm/dos/v86/cmd/graphics/ger/sources](../../base/mvdm/dos/v86/cmd/graphics/ger/sources), [base/mvdm/dos/v86/cmd/graphics/ger/makefile](../../base/mvdm/dos/v86/cmd/graphics/ger/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/graphics/hu](../../base/mvdm/dos/v86/cmd/graphics/hu) | 3 | [base/mvdm/dos/v86/cmd/graphics/hu/sources](../../base/mvdm/dos/v86/cmd/graphics/hu/sources), [base/mvdm/dos/v86/cmd/graphics/hu/makefile](../../base/mvdm/dos/v86/cmd/graphics/hu/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/graphics/it](../../base/mvdm/dos/v86/cmd/graphics/it) | 3 | [base/mvdm/dos/v86/cmd/graphics/it/sources](../../base/mvdm/dos/v86/cmd/graphics/it/sources), [base/mvdm/dos/v86/cmd/graphics/it/makefile](../../base/mvdm/dos/v86/cmd/graphics/it/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/graphics/jpn](../../base/mvdm/dos/v86/cmd/graphics/jpn) | 4 | [base/mvdm/dos/v86/cmd/graphics/jpn/sources](../../base/mvdm/dos/v86/cmd/graphics/jpn/sources), [base/mvdm/dos/v86/cmd/graphics/jpn/makefile](../../base/mvdm/dos/v86/cmd/graphics/jpn/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/graphics/kor](../../base/mvdm/dos/v86/cmd/graphics/kor) | 4 | [base/mvdm/dos/v86/cmd/graphics/kor/sources](../../base/mvdm/dos/v86/cmd/graphics/kor/sources), [base/mvdm/dos/v86/cmd/graphics/kor/makefile](../../base/mvdm/dos/v86/cmd/graphics/kor/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/graphics/nl](../../base/mvdm/dos/v86/cmd/graphics/nl) | 3 | [base/mvdm/dos/v86/cmd/graphics/nl/sources](../../base/mvdm/dos/v86/cmd/graphics/nl/sources), [base/mvdm/dos/v86/cmd/graphics/nl/makefile](../../base/mvdm/dos/v86/cmd/graphics/nl/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/graphics/no](../../base/mvdm/dos/v86/cmd/graphics/no) | 3 | [base/mvdm/dos/v86/cmd/graphics/no/sources](../../base/mvdm/dos/v86/cmd/graphics/no/sources), [base/mvdm/dos/v86/cmd/graphics/no/makefile](../../base/mvdm/dos/v86/cmd/graphics/no/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/graphics/pl](../../base/mvdm/dos/v86/cmd/graphics/pl) | 3 | [base/mvdm/dos/v86/cmd/graphics/pl/sources](../../base/mvdm/dos/v86/cmd/graphics/pl/sources), [base/mvdm/dos/v86/cmd/graphics/pl/makefile](../../base/mvdm/dos/v86/cmd/graphics/pl/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/graphics/psu](../../base/mvdm/dos/v86/cmd/graphics/psu) | 3 | [base/mvdm/dos/v86/cmd/graphics/psu/sources](../../base/mvdm/dos/v86/cmd/graphics/psu/sources), [base/mvdm/dos/v86/cmd/graphics/psu/makefile](../../base/mvdm/dos/v86/cmd/graphics/psu/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/graphics/pt](../../base/mvdm/dos/v86/cmd/graphics/pt) | 3 | [base/mvdm/dos/v86/cmd/graphics/pt/sources](../../base/mvdm/dos/v86/cmd/graphics/pt/sources), [base/mvdm/dos/v86/cmd/graphics/pt/makefile](../../base/mvdm/dos/v86/cmd/graphics/pt/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/graphics/ru](../../base/mvdm/dos/v86/cmd/graphics/ru) | 3 | [base/mvdm/dos/v86/cmd/graphics/ru/sources](../../base/mvdm/dos/v86/cmd/graphics/ru/sources), [base/mvdm/dos/v86/cmd/graphics/ru/makefile](../../base/mvdm/dos/v86/cmd/graphics/ru/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/graphics/sv](../../base/mvdm/dos/v86/cmd/graphics/sv) | 3 | [base/mvdm/dos/v86/cmd/graphics/sv/sources](../../base/mvdm/dos/v86/cmd/graphics/sv/sources), [base/mvdm/dos/v86/cmd/graphics/sv/makefile](../../base/mvdm/dos/v86/cmd/graphics/sv/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/graphics/tr](../../base/mvdm/dos/v86/cmd/graphics/tr) | 3 | [base/mvdm/dos/v86/cmd/graphics/tr/sources](../../base/mvdm/dos/v86/cmd/graphics/tr/sources), [base/mvdm/dos/v86/cmd/graphics/tr/makefile](../../base/mvdm/dos/v86/cmd/graphics/tr/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/graphics/tst](../../base/mvdm/dos/v86/cmd/graphics/tst) | 3 | [base/mvdm/dos/v86/cmd/graphics/tst/sources](../../base/mvdm/dos/v86/cmd/graphics/tst/sources), [base/mvdm/dos/v86/cmd/graphics/tst/makefile](../../base/mvdm/dos/v86/cmd/graphics/tst/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/graphics/usa](../../base/mvdm/dos/v86/cmd/graphics/usa) | 4 | [base/mvdm/dos/v86/cmd/graphics/usa/sources](../../base/mvdm/dos/v86/cmd/graphics/usa/sources), [base/mvdm/dos/v86/cmd/graphics/usa/makefile](../../base/mvdm/dos/v86/cmd/graphics/usa/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/keyb](../../base/mvdm/dos/v86/cmd/keyb) | 28 | [base/mvdm/dos/v86/cmd/keyb/dirs](../../base/mvdm/dos/v86/cmd/keyb/dirs) | — | — |
| [base/mvdm/dos/v86/cmd/keyb/br](../../base/mvdm/dos/v86/cmd/keyb/br) | 3 | [base/mvdm/dos/v86/cmd/keyb/br/sources](../../base/mvdm/dos/v86/cmd/keyb/br/sources), [base/mvdm/dos/v86/cmd/keyb/br/makefile](../../base/mvdm/dos/v86/cmd/keyb/br/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/keyb/chp](../../base/mvdm/dos/v86/cmd/keyb/chp) | 4 | [base/mvdm/dos/v86/cmd/keyb/chp/sources](../../base/mvdm/dos/v86/cmd/keyb/chp/sources), [base/mvdm/dos/v86/cmd/keyb/chp/makefile](../../base/mvdm/dos/v86/cmd/keyb/chp/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/keyb/chs](../../base/mvdm/dos/v86/cmd/keyb/chs) | 4 | [base/mvdm/dos/v86/cmd/keyb/chs/sources](../../base/mvdm/dos/v86/cmd/keyb/chs/sources), [base/mvdm/dos/v86/cmd/keyb/chs/makefile](../../base/mvdm/dos/v86/cmd/keyb/chs/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/keyb/cht](../../base/mvdm/dos/v86/cmd/keyb/cht) | 4 | [base/mvdm/dos/v86/cmd/keyb/cht/sources](../../base/mvdm/dos/v86/cmd/keyb/cht/sources), [base/mvdm/dos/v86/cmd/keyb/cht/makefile](../../base/mvdm/dos/v86/cmd/keyb/cht/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/keyb/cs](../../base/mvdm/dos/v86/cmd/keyb/cs) | 3 | [base/mvdm/dos/v86/cmd/keyb/cs/sources](../../base/mvdm/dos/v86/cmd/keyb/cs/sources), [base/mvdm/dos/v86/cmd/keyb/cs/makefile](../../base/mvdm/dos/v86/cmd/keyb/cs/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/keyb/da](../../base/mvdm/dos/v86/cmd/keyb/da) | 3 | [base/mvdm/dos/v86/cmd/keyb/da/sources](../../base/mvdm/dos/v86/cmd/keyb/da/sources), [base/mvdm/dos/v86/cmd/keyb/da/makefile](../../base/mvdm/dos/v86/cmd/keyb/da/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/keyb/el](../../base/mvdm/dos/v86/cmd/keyb/el) | 3 | [base/mvdm/dos/v86/cmd/keyb/el/sources](../../base/mvdm/dos/v86/cmd/keyb/el/sources), [base/mvdm/dos/v86/cmd/keyb/el/makefile](../../base/mvdm/dos/v86/cmd/keyb/el/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/keyb/es](../../base/mvdm/dos/v86/cmd/keyb/es) | 3 | [base/mvdm/dos/v86/cmd/keyb/es/sources](../../base/mvdm/dos/v86/cmd/keyb/es/sources), [base/mvdm/dos/v86/cmd/keyb/es/makefile](../../base/mvdm/dos/v86/cmd/keyb/es/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/keyb/fi](../../base/mvdm/dos/v86/cmd/keyb/fi) | 3 | [base/mvdm/dos/v86/cmd/keyb/fi/sources](../../base/mvdm/dos/v86/cmd/keyb/fi/sources), [base/mvdm/dos/v86/cmd/keyb/fi/makefile](../../base/mvdm/dos/v86/cmd/keyb/fi/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/keyb/fr](../../base/mvdm/dos/v86/cmd/keyb/fr) | 3 | [base/mvdm/dos/v86/cmd/keyb/fr/sources](../../base/mvdm/dos/v86/cmd/keyb/fr/sources), [base/mvdm/dos/v86/cmd/keyb/fr/makefile](../../base/mvdm/dos/v86/cmd/keyb/fr/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/keyb/ger](../../base/mvdm/dos/v86/cmd/keyb/ger) | 3 | [base/mvdm/dos/v86/cmd/keyb/ger/sources](../../base/mvdm/dos/v86/cmd/keyb/ger/sources), [base/mvdm/dos/v86/cmd/keyb/ger/makefile](../../base/mvdm/dos/v86/cmd/keyb/ger/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/keyb/hu](../../base/mvdm/dos/v86/cmd/keyb/hu) | 3 | [base/mvdm/dos/v86/cmd/keyb/hu/sources](../../base/mvdm/dos/v86/cmd/keyb/hu/sources), [base/mvdm/dos/v86/cmd/keyb/hu/makefile](../../base/mvdm/dos/v86/cmd/keyb/hu/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/keyb/it](../../base/mvdm/dos/v86/cmd/keyb/it) | 3 | [base/mvdm/dos/v86/cmd/keyb/it/sources](../../base/mvdm/dos/v86/cmd/keyb/it/sources), [base/mvdm/dos/v86/cmd/keyb/it/makefile](../../base/mvdm/dos/v86/cmd/keyb/it/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/keyb/jpn](../../base/mvdm/dos/v86/cmd/keyb/jpn) | 4 | [base/mvdm/dos/v86/cmd/keyb/jpn/sources](../../base/mvdm/dos/v86/cmd/keyb/jpn/sources), [base/mvdm/dos/v86/cmd/keyb/jpn/makefile](../../base/mvdm/dos/v86/cmd/keyb/jpn/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/keyb/kor](../../base/mvdm/dos/v86/cmd/keyb/kor) | 4 | [base/mvdm/dos/v86/cmd/keyb/kor/sources](../../base/mvdm/dos/v86/cmd/keyb/kor/sources), [base/mvdm/dos/v86/cmd/keyb/kor/makefile](../../base/mvdm/dos/v86/cmd/keyb/kor/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/keyb/nl](../../base/mvdm/dos/v86/cmd/keyb/nl) | 3 | [base/mvdm/dos/v86/cmd/keyb/nl/sources](../../base/mvdm/dos/v86/cmd/keyb/nl/sources), [base/mvdm/dos/v86/cmd/keyb/nl/makefile](../../base/mvdm/dos/v86/cmd/keyb/nl/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/keyb/no](../../base/mvdm/dos/v86/cmd/keyb/no) | 3 | [base/mvdm/dos/v86/cmd/keyb/no/sources](../../base/mvdm/dos/v86/cmd/keyb/no/sources), [base/mvdm/dos/v86/cmd/keyb/no/makefile](../../base/mvdm/dos/v86/cmd/keyb/no/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/keyb/pl](../../base/mvdm/dos/v86/cmd/keyb/pl) | 3 | [base/mvdm/dos/v86/cmd/keyb/pl/sources](../../base/mvdm/dos/v86/cmd/keyb/pl/sources), [base/mvdm/dos/v86/cmd/keyb/pl/makefile](../../base/mvdm/dos/v86/cmd/keyb/pl/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/keyb/psu](../../base/mvdm/dos/v86/cmd/keyb/psu) | 3 | [base/mvdm/dos/v86/cmd/keyb/psu/sources](../../base/mvdm/dos/v86/cmd/keyb/psu/sources), [base/mvdm/dos/v86/cmd/keyb/psu/makefile](../../base/mvdm/dos/v86/cmd/keyb/psu/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/keyb/pt](../../base/mvdm/dos/v86/cmd/keyb/pt) | 3 | [base/mvdm/dos/v86/cmd/keyb/pt/sources](../../base/mvdm/dos/v86/cmd/keyb/pt/sources), [base/mvdm/dos/v86/cmd/keyb/pt/makefile](../../base/mvdm/dos/v86/cmd/keyb/pt/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/keyb/ru](../../base/mvdm/dos/v86/cmd/keyb/ru) | 3 | [base/mvdm/dos/v86/cmd/keyb/ru/sources](../../base/mvdm/dos/v86/cmd/keyb/ru/sources), [base/mvdm/dos/v86/cmd/keyb/ru/makefile](../../base/mvdm/dos/v86/cmd/keyb/ru/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/keyb/sv](../../base/mvdm/dos/v86/cmd/keyb/sv) | 3 | [base/mvdm/dos/v86/cmd/keyb/sv/sources](../../base/mvdm/dos/v86/cmd/keyb/sv/sources), [base/mvdm/dos/v86/cmd/keyb/sv/makefile](../../base/mvdm/dos/v86/cmd/keyb/sv/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/keyb/tr](../../base/mvdm/dos/v86/cmd/keyb/tr) | 3 | [base/mvdm/dos/v86/cmd/keyb/tr/sources](../../base/mvdm/dos/v86/cmd/keyb/tr/sources), [base/mvdm/dos/v86/cmd/keyb/tr/makefile](../../base/mvdm/dos/v86/cmd/keyb/tr/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/keyb/tst](../../base/mvdm/dos/v86/cmd/keyb/tst) | 3 | [base/mvdm/dos/v86/cmd/keyb/tst/sources](../../base/mvdm/dos/v86/cmd/keyb/tst/sources), [base/mvdm/dos/v86/cmd/keyb/tst/makefile](../../base/mvdm/dos/v86/cmd/keyb/tst/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/keyb/usa](../../base/mvdm/dos/v86/cmd/keyb/usa) | 4 | [base/mvdm/dos/v86/cmd/keyb/usa/sources](../../base/mvdm/dos/v86/cmd/keyb/usa/sources), [base/mvdm/dos/v86/cmd/keyb/usa/makefile](../../base/mvdm/dos/v86/cmd/keyb/usa/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/loadfix](../../base/mvdm/dos/v86/cmd/loadfix) | 4 | [base/mvdm/dos/v86/cmd/loadfix/dirs](../../base/mvdm/dos/v86/cmd/loadfix/dirs) | — | — |
| [base/mvdm/dos/v86/cmd/loadfix/br](../../base/mvdm/dos/v86/cmd/loadfix/br) | 3 | [base/mvdm/dos/v86/cmd/loadfix/br/sources](../../base/mvdm/dos/v86/cmd/loadfix/br/sources), [base/mvdm/dos/v86/cmd/loadfix/br/makefile](../../base/mvdm/dos/v86/cmd/loadfix/br/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/loadfix/chp](../../base/mvdm/dos/v86/cmd/loadfix/chp) | 3 | [base/mvdm/dos/v86/cmd/loadfix/chp/sources](../../base/mvdm/dos/v86/cmd/loadfix/chp/sources), [base/mvdm/dos/v86/cmd/loadfix/chp/makefile](../../base/mvdm/dos/v86/cmd/loadfix/chp/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/loadfix/chs](../../base/mvdm/dos/v86/cmd/loadfix/chs) | 3 | [base/mvdm/dos/v86/cmd/loadfix/chs/sources](../../base/mvdm/dos/v86/cmd/loadfix/chs/sources), [base/mvdm/dos/v86/cmd/loadfix/chs/makefile](../../base/mvdm/dos/v86/cmd/loadfix/chs/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/loadfix/cht](../../base/mvdm/dos/v86/cmd/loadfix/cht) | 3 | [base/mvdm/dos/v86/cmd/loadfix/cht/sources](../../base/mvdm/dos/v86/cmd/loadfix/cht/sources), [base/mvdm/dos/v86/cmd/loadfix/cht/makefile](../../base/mvdm/dos/v86/cmd/loadfix/cht/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/loadfix/cs](../../base/mvdm/dos/v86/cmd/loadfix/cs) | 3 | [base/mvdm/dos/v86/cmd/loadfix/cs/sources](../../base/mvdm/dos/v86/cmd/loadfix/cs/sources), [base/mvdm/dos/v86/cmd/loadfix/cs/makefile](../../base/mvdm/dos/v86/cmd/loadfix/cs/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/loadfix/da](../../base/mvdm/dos/v86/cmd/loadfix/da) | 3 | [base/mvdm/dos/v86/cmd/loadfix/da/sources](../../base/mvdm/dos/v86/cmd/loadfix/da/sources), [base/mvdm/dos/v86/cmd/loadfix/da/makefile](../../base/mvdm/dos/v86/cmd/loadfix/da/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/loadfix/el](../../base/mvdm/dos/v86/cmd/loadfix/el) | 3 | [base/mvdm/dos/v86/cmd/loadfix/el/sources](../../base/mvdm/dos/v86/cmd/loadfix/el/sources), [base/mvdm/dos/v86/cmd/loadfix/el/makefile](../../base/mvdm/dos/v86/cmd/loadfix/el/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/loadfix/es](../../base/mvdm/dos/v86/cmd/loadfix/es) | 3 | [base/mvdm/dos/v86/cmd/loadfix/es/sources](../../base/mvdm/dos/v86/cmd/loadfix/es/sources), [base/mvdm/dos/v86/cmd/loadfix/es/makefile](../../base/mvdm/dos/v86/cmd/loadfix/es/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/loadfix/fi](../../base/mvdm/dos/v86/cmd/loadfix/fi) | 3 | [base/mvdm/dos/v86/cmd/loadfix/fi/sources](../../base/mvdm/dos/v86/cmd/loadfix/fi/sources), [base/mvdm/dos/v86/cmd/loadfix/fi/makefile](../../base/mvdm/dos/v86/cmd/loadfix/fi/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/loadfix/fr](../../base/mvdm/dos/v86/cmd/loadfix/fr) | 3 | [base/mvdm/dos/v86/cmd/loadfix/fr/sources](../../base/mvdm/dos/v86/cmd/loadfix/fr/sources), [base/mvdm/dos/v86/cmd/loadfix/fr/makefile](../../base/mvdm/dos/v86/cmd/loadfix/fr/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/loadfix/ger](../../base/mvdm/dos/v86/cmd/loadfix/ger) | 3 | [base/mvdm/dos/v86/cmd/loadfix/ger/sources](../../base/mvdm/dos/v86/cmd/loadfix/ger/sources), [base/mvdm/dos/v86/cmd/loadfix/ger/makefile](../../base/mvdm/dos/v86/cmd/loadfix/ger/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/loadfix/hu](../../base/mvdm/dos/v86/cmd/loadfix/hu) | 3 | [base/mvdm/dos/v86/cmd/loadfix/hu/sources](../../base/mvdm/dos/v86/cmd/loadfix/hu/sources), [base/mvdm/dos/v86/cmd/loadfix/hu/makefile](../../base/mvdm/dos/v86/cmd/loadfix/hu/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/loadfix/it](../../base/mvdm/dos/v86/cmd/loadfix/it) | 3 | [base/mvdm/dos/v86/cmd/loadfix/it/sources](../../base/mvdm/dos/v86/cmd/loadfix/it/sources), [base/mvdm/dos/v86/cmd/loadfix/it/makefile](../../base/mvdm/dos/v86/cmd/loadfix/it/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/loadfix/jpn](../../base/mvdm/dos/v86/cmd/loadfix/jpn) | 3 | [base/mvdm/dos/v86/cmd/loadfix/jpn/sources](../../base/mvdm/dos/v86/cmd/loadfix/jpn/sources), [base/mvdm/dos/v86/cmd/loadfix/jpn/makefile](../../base/mvdm/dos/v86/cmd/loadfix/jpn/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/loadfix/kor](../../base/mvdm/dos/v86/cmd/loadfix/kor) | 3 | [base/mvdm/dos/v86/cmd/loadfix/kor/sources](../../base/mvdm/dos/v86/cmd/loadfix/kor/sources), [base/mvdm/dos/v86/cmd/loadfix/kor/makefile](../../base/mvdm/dos/v86/cmd/loadfix/kor/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/loadfix/nl](../../base/mvdm/dos/v86/cmd/loadfix/nl) | 3 | [base/mvdm/dos/v86/cmd/loadfix/nl/sources](../../base/mvdm/dos/v86/cmd/loadfix/nl/sources), [base/mvdm/dos/v86/cmd/loadfix/nl/makefile](../../base/mvdm/dos/v86/cmd/loadfix/nl/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/loadfix/no](../../base/mvdm/dos/v86/cmd/loadfix/no) | 3 | [base/mvdm/dos/v86/cmd/loadfix/no/sources](../../base/mvdm/dos/v86/cmd/loadfix/no/sources), [base/mvdm/dos/v86/cmd/loadfix/no/makefile](../../base/mvdm/dos/v86/cmd/loadfix/no/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/loadfix/pl](../../base/mvdm/dos/v86/cmd/loadfix/pl) | 3 | [base/mvdm/dos/v86/cmd/loadfix/pl/sources](../../base/mvdm/dos/v86/cmd/loadfix/pl/sources), [base/mvdm/dos/v86/cmd/loadfix/pl/makefile](../../base/mvdm/dos/v86/cmd/loadfix/pl/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/loadfix/psu](../../base/mvdm/dos/v86/cmd/loadfix/psu) | 3 | [base/mvdm/dos/v86/cmd/loadfix/psu/sources](../../base/mvdm/dos/v86/cmd/loadfix/psu/sources), [base/mvdm/dos/v86/cmd/loadfix/psu/makefile](../../base/mvdm/dos/v86/cmd/loadfix/psu/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/loadfix/pt](../../base/mvdm/dos/v86/cmd/loadfix/pt) | 3 | [base/mvdm/dos/v86/cmd/loadfix/pt/sources](../../base/mvdm/dos/v86/cmd/loadfix/pt/sources), [base/mvdm/dos/v86/cmd/loadfix/pt/makefile](../../base/mvdm/dos/v86/cmd/loadfix/pt/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/loadfix/ru](../../base/mvdm/dos/v86/cmd/loadfix/ru) | 3 | [base/mvdm/dos/v86/cmd/loadfix/ru/sources](../../base/mvdm/dos/v86/cmd/loadfix/ru/sources), [base/mvdm/dos/v86/cmd/loadfix/ru/makefile](../../base/mvdm/dos/v86/cmd/loadfix/ru/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/loadfix/sv](../../base/mvdm/dos/v86/cmd/loadfix/sv) | 3 | [base/mvdm/dos/v86/cmd/loadfix/sv/sources](../../base/mvdm/dos/v86/cmd/loadfix/sv/sources), [base/mvdm/dos/v86/cmd/loadfix/sv/makefile](../../base/mvdm/dos/v86/cmd/loadfix/sv/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/loadfix/tr](../../base/mvdm/dos/v86/cmd/loadfix/tr) | 3 | [base/mvdm/dos/v86/cmd/loadfix/tr/sources](../../base/mvdm/dos/v86/cmd/loadfix/tr/sources), [base/mvdm/dos/v86/cmd/loadfix/tr/makefile](../../base/mvdm/dos/v86/cmd/loadfix/tr/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/loadfix/tst](../../base/mvdm/dos/v86/cmd/loadfix/tst) | 3 | [base/mvdm/dos/v86/cmd/loadfix/tst/sources](../../base/mvdm/dos/v86/cmd/loadfix/tst/sources), [base/mvdm/dos/v86/cmd/loadfix/tst/makefile](../../base/mvdm/dos/v86/cmd/loadfix/tst/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/loadfix/usa](../../base/mvdm/dos/v86/cmd/loadfix/usa) | 3 | [base/mvdm/dos/v86/cmd/loadfix/usa/sources](../../base/mvdm/dos/v86/cmd/loadfix/usa/sources), [base/mvdm/dos/v86/cmd/loadfix/usa/makefile](../../base/mvdm/dos/v86/cmd/loadfix/usa/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/mem](../../base/mvdm/dos/v86/cmd/mem) | 17 | [base/mvdm/dos/v86/cmd/mem/dirs](../../base/mvdm/dos/v86/cmd/mem/dirs) | — | — |
| [base/mvdm/dos/v86/cmd/mem/br](../../base/mvdm/dos/v86/cmd/mem/br) | 3 | [base/mvdm/dos/v86/cmd/mem/br/sources](../../base/mvdm/dos/v86/cmd/mem/br/sources), [base/mvdm/dos/v86/cmd/mem/br/makefile](../../base/mvdm/dos/v86/cmd/mem/br/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/mem/chp](../../base/mvdm/dos/v86/cmd/mem/chp) | 4 | [base/mvdm/dos/v86/cmd/mem/chp/sources](../../base/mvdm/dos/v86/cmd/mem/chp/sources), [base/mvdm/dos/v86/cmd/mem/chp/makefile](../../base/mvdm/dos/v86/cmd/mem/chp/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/mem/chs](../../base/mvdm/dos/v86/cmd/mem/chs) | 4 | [base/mvdm/dos/v86/cmd/mem/chs/sources](../../base/mvdm/dos/v86/cmd/mem/chs/sources), [base/mvdm/dos/v86/cmd/mem/chs/makefile](../../base/mvdm/dos/v86/cmd/mem/chs/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/mem/cht](../../base/mvdm/dos/v86/cmd/mem/cht) | 4 | [base/mvdm/dos/v86/cmd/mem/cht/sources](../../base/mvdm/dos/v86/cmd/mem/cht/sources), [base/mvdm/dos/v86/cmd/mem/cht/makefile](../../base/mvdm/dos/v86/cmd/mem/cht/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/mem/cs](../../base/mvdm/dos/v86/cmd/mem/cs) | 3 | [base/mvdm/dos/v86/cmd/mem/cs/sources](../../base/mvdm/dos/v86/cmd/mem/cs/sources), [base/mvdm/dos/v86/cmd/mem/cs/makefile](../../base/mvdm/dos/v86/cmd/mem/cs/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/mem/da](../../base/mvdm/dos/v86/cmd/mem/da) | 3 | [base/mvdm/dos/v86/cmd/mem/da/sources](../../base/mvdm/dos/v86/cmd/mem/da/sources), [base/mvdm/dos/v86/cmd/mem/da/makefile](../../base/mvdm/dos/v86/cmd/mem/da/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/mem/el](../../base/mvdm/dos/v86/cmd/mem/el) | 3 | [base/mvdm/dos/v86/cmd/mem/el/sources](../../base/mvdm/dos/v86/cmd/mem/el/sources), [base/mvdm/dos/v86/cmd/mem/el/makefile](../../base/mvdm/dos/v86/cmd/mem/el/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/mem/es](../../base/mvdm/dos/v86/cmd/mem/es) | 3 | [base/mvdm/dos/v86/cmd/mem/es/sources](../../base/mvdm/dos/v86/cmd/mem/es/sources), [base/mvdm/dos/v86/cmd/mem/es/makefile](../../base/mvdm/dos/v86/cmd/mem/es/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/mem/fi](../../base/mvdm/dos/v86/cmd/mem/fi) | 3 | [base/mvdm/dos/v86/cmd/mem/fi/sources](../../base/mvdm/dos/v86/cmd/mem/fi/sources), [base/mvdm/dos/v86/cmd/mem/fi/makefile](../../base/mvdm/dos/v86/cmd/mem/fi/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/mem/fr](../../base/mvdm/dos/v86/cmd/mem/fr) | 3 | [base/mvdm/dos/v86/cmd/mem/fr/sources](../../base/mvdm/dos/v86/cmd/mem/fr/sources), [base/mvdm/dos/v86/cmd/mem/fr/makefile](../../base/mvdm/dos/v86/cmd/mem/fr/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/mem/ger](../../base/mvdm/dos/v86/cmd/mem/ger) | 3 | [base/mvdm/dos/v86/cmd/mem/ger/sources](../../base/mvdm/dos/v86/cmd/mem/ger/sources), [base/mvdm/dos/v86/cmd/mem/ger/makefile](../../base/mvdm/dos/v86/cmd/mem/ger/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/mem/hu](../../base/mvdm/dos/v86/cmd/mem/hu) | 3 | [base/mvdm/dos/v86/cmd/mem/hu/sources](../../base/mvdm/dos/v86/cmd/mem/hu/sources), [base/mvdm/dos/v86/cmd/mem/hu/makefile](../../base/mvdm/dos/v86/cmd/mem/hu/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/mem/it](../../base/mvdm/dos/v86/cmd/mem/it) | 3 | [base/mvdm/dos/v86/cmd/mem/it/sources](../../base/mvdm/dos/v86/cmd/mem/it/sources), [base/mvdm/dos/v86/cmd/mem/it/makefile](../../base/mvdm/dos/v86/cmd/mem/it/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/mem/jpn](../../base/mvdm/dos/v86/cmd/mem/jpn) | 4 | [base/mvdm/dos/v86/cmd/mem/jpn/sources](../../base/mvdm/dos/v86/cmd/mem/jpn/sources), [base/mvdm/dos/v86/cmd/mem/jpn/makefile](../../base/mvdm/dos/v86/cmd/mem/jpn/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/mem/kor](../../base/mvdm/dos/v86/cmd/mem/kor) | 4 | [base/mvdm/dos/v86/cmd/mem/kor/sources](../../base/mvdm/dos/v86/cmd/mem/kor/sources), [base/mvdm/dos/v86/cmd/mem/kor/makefile](../../base/mvdm/dos/v86/cmd/mem/kor/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/mem/nl](../../base/mvdm/dos/v86/cmd/mem/nl) | 3 | [base/mvdm/dos/v86/cmd/mem/nl/sources](../../base/mvdm/dos/v86/cmd/mem/nl/sources), [base/mvdm/dos/v86/cmd/mem/nl/makefile](../../base/mvdm/dos/v86/cmd/mem/nl/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/mem/no](../../base/mvdm/dos/v86/cmd/mem/no) | 3 | [base/mvdm/dos/v86/cmd/mem/no/sources](../../base/mvdm/dos/v86/cmd/mem/no/sources), [base/mvdm/dos/v86/cmd/mem/no/makefile](../../base/mvdm/dos/v86/cmd/mem/no/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/mem/pl](../../base/mvdm/dos/v86/cmd/mem/pl) | 3 | [base/mvdm/dos/v86/cmd/mem/pl/sources](../../base/mvdm/dos/v86/cmd/mem/pl/sources), [base/mvdm/dos/v86/cmd/mem/pl/makefile](../../base/mvdm/dos/v86/cmd/mem/pl/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/mem/psu](../../base/mvdm/dos/v86/cmd/mem/psu) | 3 | [base/mvdm/dos/v86/cmd/mem/psu/sources](../../base/mvdm/dos/v86/cmd/mem/psu/sources), [base/mvdm/dos/v86/cmd/mem/psu/makefile](../../base/mvdm/dos/v86/cmd/mem/psu/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/mem/pt](../../base/mvdm/dos/v86/cmd/mem/pt) | 3 | [base/mvdm/dos/v86/cmd/mem/pt/sources](../../base/mvdm/dos/v86/cmd/mem/pt/sources), [base/mvdm/dos/v86/cmd/mem/pt/makefile](../../base/mvdm/dos/v86/cmd/mem/pt/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/mem/ru](../../base/mvdm/dos/v86/cmd/mem/ru) | 3 | [base/mvdm/dos/v86/cmd/mem/ru/sources](../../base/mvdm/dos/v86/cmd/mem/ru/sources), [base/mvdm/dos/v86/cmd/mem/ru/makefile](../../base/mvdm/dos/v86/cmd/mem/ru/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/mem/sv](../../base/mvdm/dos/v86/cmd/mem/sv) | 3 | [base/mvdm/dos/v86/cmd/mem/sv/sources](../../base/mvdm/dos/v86/cmd/mem/sv/sources), [base/mvdm/dos/v86/cmd/mem/sv/makefile](../../base/mvdm/dos/v86/cmd/mem/sv/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/mem/tr](../../base/mvdm/dos/v86/cmd/mem/tr) | 3 | [base/mvdm/dos/v86/cmd/mem/tr/sources](../../base/mvdm/dos/v86/cmd/mem/tr/sources), [base/mvdm/dos/v86/cmd/mem/tr/makefile](../../base/mvdm/dos/v86/cmd/mem/tr/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/mem/tst](../../base/mvdm/dos/v86/cmd/mem/tst) | 3 | [base/mvdm/dos/v86/cmd/mem/tst/sources](../../base/mvdm/dos/v86/cmd/mem/tst/sources), [base/mvdm/dos/v86/cmd/mem/tst/makefile](../../base/mvdm/dos/v86/cmd/mem/tst/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/mem/usa](../../base/mvdm/dos/v86/cmd/mem/usa) | 4 | [base/mvdm/dos/v86/cmd/mem/usa/sources](../../base/mvdm/dos/v86/cmd/mem/usa/sources), [base/mvdm/dos/v86/cmd/mem/usa/makefile](../../base/mvdm/dos/v86/cmd/mem/usa/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/nlsfunc](../../base/mvdm/dos/v86/cmd/nlsfunc) | 9 | [base/mvdm/dos/v86/cmd/nlsfunc/dirs](../../base/mvdm/dos/v86/cmd/nlsfunc/dirs) | — | — |
| [base/mvdm/dos/v86/cmd/nlsfunc/br](../../base/mvdm/dos/v86/cmd/nlsfunc/br) | 3 | [base/mvdm/dos/v86/cmd/nlsfunc/br/sources](../../base/mvdm/dos/v86/cmd/nlsfunc/br/sources), [base/mvdm/dos/v86/cmd/nlsfunc/br/makefile](../../base/mvdm/dos/v86/cmd/nlsfunc/br/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/nlsfunc/chp](../../base/mvdm/dos/v86/cmd/nlsfunc/chp) | 4 | [base/mvdm/dos/v86/cmd/nlsfunc/chp/sources](../../base/mvdm/dos/v86/cmd/nlsfunc/chp/sources), [base/mvdm/dos/v86/cmd/nlsfunc/chp/makefile](../../base/mvdm/dos/v86/cmd/nlsfunc/chp/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/nlsfunc/chs](../../base/mvdm/dos/v86/cmd/nlsfunc/chs) | 4 | [base/mvdm/dos/v86/cmd/nlsfunc/chs/sources](../../base/mvdm/dos/v86/cmd/nlsfunc/chs/sources), [base/mvdm/dos/v86/cmd/nlsfunc/chs/makefile](../../base/mvdm/dos/v86/cmd/nlsfunc/chs/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/nlsfunc/cht](../../base/mvdm/dos/v86/cmd/nlsfunc/cht) | 4 | [base/mvdm/dos/v86/cmd/nlsfunc/cht/sources](../../base/mvdm/dos/v86/cmd/nlsfunc/cht/sources), [base/mvdm/dos/v86/cmd/nlsfunc/cht/makefile](../../base/mvdm/dos/v86/cmd/nlsfunc/cht/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/nlsfunc/cs](../../base/mvdm/dos/v86/cmd/nlsfunc/cs) | 3 | [base/mvdm/dos/v86/cmd/nlsfunc/cs/sources](../../base/mvdm/dos/v86/cmd/nlsfunc/cs/sources), [base/mvdm/dos/v86/cmd/nlsfunc/cs/makefile](../../base/mvdm/dos/v86/cmd/nlsfunc/cs/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/nlsfunc/da](../../base/mvdm/dos/v86/cmd/nlsfunc/da) | 3 | [base/mvdm/dos/v86/cmd/nlsfunc/da/sources](../../base/mvdm/dos/v86/cmd/nlsfunc/da/sources), [base/mvdm/dos/v86/cmd/nlsfunc/da/makefile](../../base/mvdm/dos/v86/cmd/nlsfunc/da/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/nlsfunc/el](../../base/mvdm/dos/v86/cmd/nlsfunc/el) | 3 | [base/mvdm/dos/v86/cmd/nlsfunc/el/sources](../../base/mvdm/dos/v86/cmd/nlsfunc/el/sources), [base/mvdm/dos/v86/cmd/nlsfunc/el/makefile](../../base/mvdm/dos/v86/cmd/nlsfunc/el/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/nlsfunc/es](../../base/mvdm/dos/v86/cmd/nlsfunc/es) | 3 | [base/mvdm/dos/v86/cmd/nlsfunc/es/sources](../../base/mvdm/dos/v86/cmd/nlsfunc/es/sources), [base/mvdm/dos/v86/cmd/nlsfunc/es/makefile](../../base/mvdm/dos/v86/cmd/nlsfunc/es/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/nlsfunc/fi](../../base/mvdm/dos/v86/cmd/nlsfunc/fi) | 3 | [base/mvdm/dos/v86/cmd/nlsfunc/fi/sources](../../base/mvdm/dos/v86/cmd/nlsfunc/fi/sources), [base/mvdm/dos/v86/cmd/nlsfunc/fi/makefile](../../base/mvdm/dos/v86/cmd/nlsfunc/fi/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/nlsfunc/fr](../../base/mvdm/dos/v86/cmd/nlsfunc/fr) | 3 | [base/mvdm/dos/v86/cmd/nlsfunc/fr/sources](../../base/mvdm/dos/v86/cmd/nlsfunc/fr/sources), [base/mvdm/dos/v86/cmd/nlsfunc/fr/makefile](../../base/mvdm/dos/v86/cmd/nlsfunc/fr/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/nlsfunc/ger](../../base/mvdm/dos/v86/cmd/nlsfunc/ger) | 3 | [base/mvdm/dos/v86/cmd/nlsfunc/ger/sources](../../base/mvdm/dos/v86/cmd/nlsfunc/ger/sources), [base/mvdm/dos/v86/cmd/nlsfunc/ger/makefile](../../base/mvdm/dos/v86/cmd/nlsfunc/ger/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/nlsfunc/hu](../../base/mvdm/dos/v86/cmd/nlsfunc/hu) | 3 | [base/mvdm/dos/v86/cmd/nlsfunc/hu/sources](../../base/mvdm/dos/v86/cmd/nlsfunc/hu/sources), [base/mvdm/dos/v86/cmd/nlsfunc/hu/makefile](../../base/mvdm/dos/v86/cmd/nlsfunc/hu/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/nlsfunc/it](../../base/mvdm/dos/v86/cmd/nlsfunc/it) | 3 | [base/mvdm/dos/v86/cmd/nlsfunc/it/sources](../../base/mvdm/dos/v86/cmd/nlsfunc/it/sources), [base/mvdm/dos/v86/cmd/nlsfunc/it/makefile](../../base/mvdm/dos/v86/cmd/nlsfunc/it/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/nlsfunc/jpn](../../base/mvdm/dos/v86/cmd/nlsfunc/jpn) | 4 | [base/mvdm/dos/v86/cmd/nlsfunc/jpn/sources](../../base/mvdm/dos/v86/cmd/nlsfunc/jpn/sources), [base/mvdm/dos/v86/cmd/nlsfunc/jpn/makefile](../../base/mvdm/dos/v86/cmd/nlsfunc/jpn/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/nlsfunc/kor](../../base/mvdm/dos/v86/cmd/nlsfunc/kor) | 4 | [base/mvdm/dos/v86/cmd/nlsfunc/kor/sources](../../base/mvdm/dos/v86/cmd/nlsfunc/kor/sources), [base/mvdm/dos/v86/cmd/nlsfunc/kor/makefile](../../base/mvdm/dos/v86/cmd/nlsfunc/kor/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/nlsfunc/nl](../../base/mvdm/dos/v86/cmd/nlsfunc/nl) | 3 | [base/mvdm/dos/v86/cmd/nlsfunc/nl/sources](../../base/mvdm/dos/v86/cmd/nlsfunc/nl/sources), [base/mvdm/dos/v86/cmd/nlsfunc/nl/makefile](../../base/mvdm/dos/v86/cmd/nlsfunc/nl/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/nlsfunc/no](../../base/mvdm/dos/v86/cmd/nlsfunc/no) | 3 | [base/mvdm/dos/v86/cmd/nlsfunc/no/sources](../../base/mvdm/dos/v86/cmd/nlsfunc/no/sources), [base/mvdm/dos/v86/cmd/nlsfunc/no/makefile](../../base/mvdm/dos/v86/cmd/nlsfunc/no/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/nlsfunc/pl](../../base/mvdm/dos/v86/cmd/nlsfunc/pl) | 3 | [base/mvdm/dos/v86/cmd/nlsfunc/pl/sources](../../base/mvdm/dos/v86/cmd/nlsfunc/pl/sources), [base/mvdm/dos/v86/cmd/nlsfunc/pl/makefile](../../base/mvdm/dos/v86/cmd/nlsfunc/pl/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/nlsfunc/psu](../../base/mvdm/dos/v86/cmd/nlsfunc/psu) | 3 | [base/mvdm/dos/v86/cmd/nlsfunc/psu/sources](../../base/mvdm/dos/v86/cmd/nlsfunc/psu/sources), [base/mvdm/dos/v86/cmd/nlsfunc/psu/makefile](../../base/mvdm/dos/v86/cmd/nlsfunc/psu/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/nlsfunc/pt](../../base/mvdm/dos/v86/cmd/nlsfunc/pt) | 3 | [base/mvdm/dos/v86/cmd/nlsfunc/pt/sources](../../base/mvdm/dos/v86/cmd/nlsfunc/pt/sources), [base/mvdm/dos/v86/cmd/nlsfunc/pt/makefile](../../base/mvdm/dos/v86/cmd/nlsfunc/pt/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/nlsfunc/ru](../../base/mvdm/dos/v86/cmd/nlsfunc/ru) | 3 | [base/mvdm/dos/v86/cmd/nlsfunc/ru/sources](../../base/mvdm/dos/v86/cmd/nlsfunc/ru/sources), [base/mvdm/dos/v86/cmd/nlsfunc/ru/makefile](../../base/mvdm/dos/v86/cmd/nlsfunc/ru/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/nlsfunc/sv](../../base/mvdm/dos/v86/cmd/nlsfunc/sv) | 3 | [base/mvdm/dos/v86/cmd/nlsfunc/sv/sources](../../base/mvdm/dos/v86/cmd/nlsfunc/sv/sources), [base/mvdm/dos/v86/cmd/nlsfunc/sv/makefile](../../base/mvdm/dos/v86/cmd/nlsfunc/sv/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/nlsfunc/tr](../../base/mvdm/dos/v86/cmd/nlsfunc/tr) | 3 | [base/mvdm/dos/v86/cmd/nlsfunc/tr/sources](../../base/mvdm/dos/v86/cmd/nlsfunc/tr/sources), [base/mvdm/dos/v86/cmd/nlsfunc/tr/makefile](../../base/mvdm/dos/v86/cmd/nlsfunc/tr/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/nlsfunc/tst](../../base/mvdm/dos/v86/cmd/nlsfunc/tst) | 3 | [base/mvdm/dos/v86/cmd/nlsfunc/tst/sources](../../base/mvdm/dos/v86/cmd/nlsfunc/tst/sources), [base/mvdm/dos/v86/cmd/nlsfunc/tst/makefile](../../base/mvdm/dos/v86/cmd/nlsfunc/tst/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/nlsfunc/usa](../../base/mvdm/dos/v86/cmd/nlsfunc/usa) | 4 | [base/mvdm/dos/v86/cmd/nlsfunc/usa/sources](../../base/mvdm/dos/v86/cmd/nlsfunc/usa/sources), [base/mvdm/dos/v86/cmd/nlsfunc/usa/makefile](../../base/mvdm/dos/v86/cmd/nlsfunc/usa/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/qbasic](../../base/mvdm/dos/v86/cmd/qbasic) | 12 | [base/mvdm/dos/v86/cmd/qbasic/dirs](../../base/mvdm/dos/v86/cmd/qbasic/dirs) | — | — |
| [base/mvdm/dos/v86/cmd/qbasic/chp](../../base/mvdm/dos/v86/cmd/qbasic/chp) | 3 | [base/mvdm/dos/v86/cmd/qbasic/chp/sources](../../base/mvdm/dos/v86/cmd/qbasic/chp/sources), [base/mvdm/dos/v86/cmd/qbasic/chp/makefile](../../base/mvdm/dos/v86/cmd/qbasic/chp/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/qbasic/chs](../../base/mvdm/dos/v86/cmd/qbasic/chs) | 3 | [base/mvdm/dos/v86/cmd/qbasic/chs/sources](../../base/mvdm/dos/v86/cmd/qbasic/chs/sources), [base/mvdm/dos/v86/cmd/qbasic/chs/makefile](../../base/mvdm/dos/v86/cmd/qbasic/chs/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/qbasic/cht](../../base/mvdm/dos/v86/cmd/qbasic/cht) | 3 | [base/mvdm/dos/v86/cmd/qbasic/cht/sources](../../base/mvdm/dos/v86/cmd/qbasic/cht/sources), [base/mvdm/dos/v86/cmd/qbasic/cht/makefile](../../base/mvdm/dos/v86/cmd/qbasic/cht/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/qbasic/jpn](../../base/mvdm/dos/v86/cmd/qbasic/jpn) | 3 | [base/mvdm/dos/v86/cmd/qbasic/jpn/sources](../../base/mvdm/dos/v86/cmd/qbasic/jpn/sources), [base/mvdm/dos/v86/cmd/qbasic/jpn/makefile](../../base/mvdm/dos/v86/cmd/qbasic/jpn/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/qbasic/kor](../../base/mvdm/dos/v86/cmd/qbasic/kor) | 3 | [base/mvdm/dos/v86/cmd/qbasic/kor/sources](../../base/mvdm/dos/v86/cmd/qbasic/kor/sources), [base/mvdm/dos/v86/cmd/qbasic/kor/makefile](../../base/mvdm/dos/v86/cmd/qbasic/kor/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/qbasic/usa](../../base/mvdm/dos/v86/cmd/qbasic/usa) | 3 | [base/mvdm/dos/v86/cmd/qbasic/usa/sources](../../base/mvdm/dos/v86/cmd/qbasic/usa/sources), [base/mvdm/dos/v86/cmd/qbasic/usa/makefile](../../base/mvdm/dos/v86/cmd/qbasic/usa/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/setver](../../base/mvdm/dos/v86/cmd/setver) | 10 | [base/mvdm/dos/v86/cmd/setver/dirs](../../base/mvdm/dos/v86/cmd/setver/dirs) | — | — |
| [base/mvdm/dos/v86/cmd/setver/br](../../base/mvdm/dos/v86/cmd/setver/br) | 4 | [base/mvdm/dos/v86/cmd/setver/br/sources](../../base/mvdm/dos/v86/cmd/setver/br/sources), [base/mvdm/dos/v86/cmd/setver/br/makefile](../../base/mvdm/dos/v86/cmd/setver/br/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/setver/chp](../../base/mvdm/dos/v86/cmd/setver/chp) | 4 | [base/mvdm/dos/v86/cmd/setver/chp/sources](../../base/mvdm/dos/v86/cmd/setver/chp/sources), [base/mvdm/dos/v86/cmd/setver/chp/makefile](../../base/mvdm/dos/v86/cmd/setver/chp/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/setver/chs](../../base/mvdm/dos/v86/cmd/setver/chs) | 4 | [base/mvdm/dos/v86/cmd/setver/chs/sources](../../base/mvdm/dos/v86/cmd/setver/chs/sources), [base/mvdm/dos/v86/cmd/setver/chs/makefile](../../base/mvdm/dos/v86/cmd/setver/chs/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/setver/cht](../../base/mvdm/dos/v86/cmd/setver/cht) | 4 | [base/mvdm/dos/v86/cmd/setver/cht/sources](../../base/mvdm/dos/v86/cmd/setver/cht/sources), [base/mvdm/dos/v86/cmd/setver/cht/makefile](../../base/mvdm/dos/v86/cmd/setver/cht/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/setver/cs](../../base/mvdm/dos/v86/cmd/setver/cs) | 4 | [base/mvdm/dos/v86/cmd/setver/cs/sources](../../base/mvdm/dos/v86/cmd/setver/cs/sources), [base/mvdm/dos/v86/cmd/setver/cs/makefile](../../base/mvdm/dos/v86/cmd/setver/cs/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/setver/da](../../base/mvdm/dos/v86/cmd/setver/da) | 4 | [base/mvdm/dos/v86/cmd/setver/da/sources](../../base/mvdm/dos/v86/cmd/setver/da/sources), [base/mvdm/dos/v86/cmd/setver/da/makefile](../../base/mvdm/dos/v86/cmd/setver/da/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/setver/el](../../base/mvdm/dos/v86/cmd/setver/el) | 4 | [base/mvdm/dos/v86/cmd/setver/el/sources](../../base/mvdm/dos/v86/cmd/setver/el/sources), [base/mvdm/dos/v86/cmd/setver/el/makefile](../../base/mvdm/dos/v86/cmd/setver/el/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/setver/es](../../base/mvdm/dos/v86/cmd/setver/es) | 4 | [base/mvdm/dos/v86/cmd/setver/es/sources](../../base/mvdm/dos/v86/cmd/setver/es/sources), [base/mvdm/dos/v86/cmd/setver/es/makefile](../../base/mvdm/dos/v86/cmd/setver/es/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/setver/fi](../../base/mvdm/dos/v86/cmd/setver/fi) | 4 | [base/mvdm/dos/v86/cmd/setver/fi/sources](../../base/mvdm/dos/v86/cmd/setver/fi/sources), [base/mvdm/dos/v86/cmd/setver/fi/makefile](../../base/mvdm/dos/v86/cmd/setver/fi/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/setver/fr](../../base/mvdm/dos/v86/cmd/setver/fr) | 4 | [base/mvdm/dos/v86/cmd/setver/fr/sources](../../base/mvdm/dos/v86/cmd/setver/fr/sources), [base/mvdm/dos/v86/cmd/setver/fr/makefile](../../base/mvdm/dos/v86/cmd/setver/fr/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/setver/ger](../../base/mvdm/dos/v86/cmd/setver/ger) | 4 | [base/mvdm/dos/v86/cmd/setver/ger/sources](../../base/mvdm/dos/v86/cmd/setver/ger/sources), [base/mvdm/dos/v86/cmd/setver/ger/makefile](../../base/mvdm/dos/v86/cmd/setver/ger/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/setver/hu](../../base/mvdm/dos/v86/cmd/setver/hu) | 4 | [base/mvdm/dos/v86/cmd/setver/hu/sources](../../base/mvdm/dos/v86/cmd/setver/hu/sources), [base/mvdm/dos/v86/cmd/setver/hu/makefile](../../base/mvdm/dos/v86/cmd/setver/hu/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/setver/it](../../base/mvdm/dos/v86/cmd/setver/it) | 4 | [base/mvdm/dos/v86/cmd/setver/it/sources](../../base/mvdm/dos/v86/cmd/setver/it/sources), [base/mvdm/dos/v86/cmd/setver/it/makefile](../../base/mvdm/dos/v86/cmd/setver/it/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/setver/jpn](../../base/mvdm/dos/v86/cmd/setver/jpn) | 4 | [base/mvdm/dos/v86/cmd/setver/jpn/sources](../../base/mvdm/dos/v86/cmd/setver/jpn/sources), [base/mvdm/dos/v86/cmd/setver/jpn/makefile](../../base/mvdm/dos/v86/cmd/setver/jpn/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/setver/kor](../../base/mvdm/dos/v86/cmd/setver/kor) | 4 | [base/mvdm/dos/v86/cmd/setver/kor/sources](../../base/mvdm/dos/v86/cmd/setver/kor/sources), [base/mvdm/dos/v86/cmd/setver/kor/makefile](../../base/mvdm/dos/v86/cmd/setver/kor/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/setver/nl](../../base/mvdm/dos/v86/cmd/setver/nl) | 4 | [base/mvdm/dos/v86/cmd/setver/nl/sources](../../base/mvdm/dos/v86/cmd/setver/nl/sources), [base/mvdm/dos/v86/cmd/setver/nl/makefile](../../base/mvdm/dos/v86/cmd/setver/nl/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/setver/no](../../base/mvdm/dos/v86/cmd/setver/no) | 4 | [base/mvdm/dos/v86/cmd/setver/no/sources](../../base/mvdm/dos/v86/cmd/setver/no/sources), [base/mvdm/dos/v86/cmd/setver/no/makefile](../../base/mvdm/dos/v86/cmd/setver/no/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/setver/pl](../../base/mvdm/dos/v86/cmd/setver/pl) | 4 | [base/mvdm/dos/v86/cmd/setver/pl/sources](../../base/mvdm/dos/v86/cmd/setver/pl/sources), [base/mvdm/dos/v86/cmd/setver/pl/makefile](../../base/mvdm/dos/v86/cmd/setver/pl/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/setver/psu](../../base/mvdm/dos/v86/cmd/setver/psu) | 4 | [base/mvdm/dos/v86/cmd/setver/psu/sources](../../base/mvdm/dos/v86/cmd/setver/psu/sources), [base/mvdm/dos/v86/cmd/setver/psu/makefile](../../base/mvdm/dos/v86/cmd/setver/psu/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/setver/pt](../../base/mvdm/dos/v86/cmd/setver/pt) | 4 | [base/mvdm/dos/v86/cmd/setver/pt/sources](../../base/mvdm/dos/v86/cmd/setver/pt/sources), [base/mvdm/dos/v86/cmd/setver/pt/makefile](../../base/mvdm/dos/v86/cmd/setver/pt/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/setver/ru](../../base/mvdm/dos/v86/cmd/setver/ru) | 4 | [base/mvdm/dos/v86/cmd/setver/ru/sources](../../base/mvdm/dos/v86/cmd/setver/ru/sources), [base/mvdm/dos/v86/cmd/setver/ru/makefile](../../base/mvdm/dos/v86/cmd/setver/ru/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/setver/sv](../../base/mvdm/dos/v86/cmd/setver/sv) | 4 | [base/mvdm/dos/v86/cmd/setver/sv/sources](../../base/mvdm/dos/v86/cmd/setver/sv/sources), [base/mvdm/dos/v86/cmd/setver/sv/makefile](../../base/mvdm/dos/v86/cmd/setver/sv/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/setver/tr](../../base/mvdm/dos/v86/cmd/setver/tr) | 4 | [base/mvdm/dos/v86/cmd/setver/tr/sources](../../base/mvdm/dos/v86/cmd/setver/tr/sources), [base/mvdm/dos/v86/cmd/setver/tr/makefile](../../base/mvdm/dos/v86/cmd/setver/tr/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/setver/tst](../../base/mvdm/dos/v86/cmd/setver/tst) | 4 | [base/mvdm/dos/v86/cmd/setver/tst/sources](../../base/mvdm/dos/v86/cmd/setver/tst/sources), [base/mvdm/dos/v86/cmd/setver/tst/makefile](../../base/mvdm/dos/v86/cmd/setver/tst/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/setver/usa](../../base/mvdm/dos/v86/cmd/setver/usa) | 4 | [base/mvdm/dos/v86/cmd/setver/usa/sources](../../base/mvdm/dos/v86/cmd/setver/usa/sources), [base/mvdm/dos/v86/cmd/setver/usa/makefile](../../base/mvdm/dos/v86/cmd/setver/usa/makefile) | — | — |
| [base/mvdm/dos/v86/cmd/share](../../base/mvdm/dos/v86/cmd/share) | 5 | [base/mvdm/dos/v86/cmd/share/dirs](../../base/mvdm/dos/v86/cmd/share/dirs) | — | — |
| [base/mvdm/dos/v86/cmd/share/usa](../../base/mvdm/dos/v86/cmd/share/usa) | 3 | [base/mvdm/dos/v86/cmd/share/usa/sources](../../base/mvdm/dos/v86/cmd/share/usa/sources), [base/mvdm/dos/v86/cmd/share/usa/makefile](../../base/mvdm/dos/v86/cmd/share/usa/makefile) | — | — |
| [base/mvdm/dos/v86/dev](../../base/mvdm/dos/v86/dev) | 1 | [base/mvdm/dos/v86/dev/dirs](../../base/mvdm/dos/v86/dev/dirs) | — | — |
| [base/mvdm/dos/v86/dev/ansi](../../base/mvdm/dos/v86/dev/ansi) | 11 | [base/mvdm/dos/v86/dev/ansi/dirs](../../base/mvdm/dos/v86/dev/ansi/dirs) | — | — |
| [base/mvdm/dos/v86/dev/ansi/br](../../base/mvdm/dos/v86/dev/ansi/br) | 3 | [base/mvdm/dos/v86/dev/ansi/br/sources](../../base/mvdm/dos/v86/dev/ansi/br/sources), [base/mvdm/dos/v86/dev/ansi/br/makefile](../../base/mvdm/dos/v86/dev/ansi/br/makefile) | — | — |
| [base/mvdm/dos/v86/dev/ansi/chp](../../base/mvdm/dos/v86/dev/ansi/chp) | 4 | [base/mvdm/dos/v86/dev/ansi/chp/sources](../../base/mvdm/dos/v86/dev/ansi/chp/sources), [base/mvdm/dos/v86/dev/ansi/chp/makefile](../../base/mvdm/dos/v86/dev/ansi/chp/makefile) | — | — |
| [base/mvdm/dos/v86/dev/ansi/chs](../../base/mvdm/dos/v86/dev/ansi/chs) | 4 | [base/mvdm/dos/v86/dev/ansi/chs/sources](../../base/mvdm/dos/v86/dev/ansi/chs/sources), [base/mvdm/dos/v86/dev/ansi/chs/makefile](../../base/mvdm/dos/v86/dev/ansi/chs/makefile) | — | — |
| [base/mvdm/dos/v86/dev/ansi/cht](../../base/mvdm/dos/v86/dev/ansi/cht) | 4 | [base/mvdm/dos/v86/dev/ansi/cht/sources](../../base/mvdm/dos/v86/dev/ansi/cht/sources), [base/mvdm/dos/v86/dev/ansi/cht/makefile](../../base/mvdm/dos/v86/dev/ansi/cht/makefile) | — | — |
| [base/mvdm/dos/v86/dev/ansi/cs](../../base/mvdm/dos/v86/dev/ansi/cs) | 3 | [base/mvdm/dos/v86/dev/ansi/cs/sources](../../base/mvdm/dos/v86/dev/ansi/cs/sources), [base/mvdm/dos/v86/dev/ansi/cs/makefile](../../base/mvdm/dos/v86/dev/ansi/cs/makefile) | — | — |
| [base/mvdm/dos/v86/dev/ansi/da](../../base/mvdm/dos/v86/dev/ansi/da) | 3 | [base/mvdm/dos/v86/dev/ansi/da/sources](../../base/mvdm/dos/v86/dev/ansi/da/sources), [base/mvdm/dos/v86/dev/ansi/da/makefile](../../base/mvdm/dos/v86/dev/ansi/da/makefile) | — | — |
| [base/mvdm/dos/v86/dev/ansi/el](../../base/mvdm/dos/v86/dev/ansi/el) | 3 | [base/mvdm/dos/v86/dev/ansi/el/sources](../../base/mvdm/dos/v86/dev/ansi/el/sources), [base/mvdm/dos/v86/dev/ansi/el/makefile](../../base/mvdm/dos/v86/dev/ansi/el/makefile) | — | — |
| [base/mvdm/dos/v86/dev/ansi/es](../../base/mvdm/dos/v86/dev/ansi/es) | 3 | [base/mvdm/dos/v86/dev/ansi/es/sources](../../base/mvdm/dos/v86/dev/ansi/es/sources), [base/mvdm/dos/v86/dev/ansi/es/makefile](../../base/mvdm/dos/v86/dev/ansi/es/makefile) | — | — |
| [base/mvdm/dos/v86/dev/ansi/fi](../../base/mvdm/dos/v86/dev/ansi/fi) | 3 | [base/mvdm/dos/v86/dev/ansi/fi/sources](../../base/mvdm/dos/v86/dev/ansi/fi/sources), [base/mvdm/dos/v86/dev/ansi/fi/makefile](../../base/mvdm/dos/v86/dev/ansi/fi/makefile) | — | — |
| [base/mvdm/dos/v86/dev/ansi/fr](../../base/mvdm/dos/v86/dev/ansi/fr) | 3 | [base/mvdm/dos/v86/dev/ansi/fr/sources](../../base/mvdm/dos/v86/dev/ansi/fr/sources), [base/mvdm/dos/v86/dev/ansi/fr/makefile](../../base/mvdm/dos/v86/dev/ansi/fr/makefile) | — | — |
| [base/mvdm/dos/v86/dev/ansi/ger](../../base/mvdm/dos/v86/dev/ansi/ger) | 3 | [base/mvdm/dos/v86/dev/ansi/ger/sources](../../base/mvdm/dos/v86/dev/ansi/ger/sources), [base/mvdm/dos/v86/dev/ansi/ger/makefile](../../base/mvdm/dos/v86/dev/ansi/ger/makefile) | — | — |
| [base/mvdm/dos/v86/dev/ansi/hu](../../base/mvdm/dos/v86/dev/ansi/hu) | 3 | [base/mvdm/dos/v86/dev/ansi/hu/sources](../../base/mvdm/dos/v86/dev/ansi/hu/sources), [base/mvdm/dos/v86/dev/ansi/hu/makefile](../../base/mvdm/dos/v86/dev/ansi/hu/makefile) | — | — |
| [base/mvdm/dos/v86/dev/ansi/it](../../base/mvdm/dos/v86/dev/ansi/it) | 3 | [base/mvdm/dos/v86/dev/ansi/it/sources](../../base/mvdm/dos/v86/dev/ansi/it/sources), [base/mvdm/dos/v86/dev/ansi/it/makefile](../../base/mvdm/dos/v86/dev/ansi/it/makefile) | — | — |
| [base/mvdm/dos/v86/dev/ansi/jpn](../../base/mvdm/dos/v86/dev/ansi/jpn) | 4 | [base/mvdm/dos/v86/dev/ansi/jpn/sources](../../base/mvdm/dos/v86/dev/ansi/jpn/sources), [base/mvdm/dos/v86/dev/ansi/jpn/makefile](../../base/mvdm/dos/v86/dev/ansi/jpn/makefile) | — | — |
| [base/mvdm/dos/v86/dev/ansi/kor](../../base/mvdm/dos/v86/dev/ansi/kor) | 4 | [base/mvdm/dos/v86/dev/ansi/kor/sources](../../base/mvdm/dos/v86/dev/ansi/kor/sources), [base/mvdm/dos/v86/dev/ansi/kor/makefile](../../base/mvdm/dos/v86/dev/ansi/kor/makefile) | — | — |
| [base/mvdm/dos/v86/dev/ansi/nl](../../base/mvdm/dos/v86/dev/ansi/nl) | 3 | [base/mvdm/dos/v86/dev/ansi/nl/sources](../../base/mvdm/dos/v86/dev/ansi/nl/sources), [base/mvdm/dos/v86/dev/ansi/nl/makefile](../../base/mvdm/dos/v86/dev/ansi/nl/makefile) | — | — |
| [base/mvdm/dos/v86/dev/ansi/no](../../base/mvdm/dos/v86/dev/ansi/no) | 3 | [base/mvdm/dos/v86/dev/ansi/no/sources](../../base/mvdm/dos/v86/dev/ansi/no/sources), [base/mvdm/dos/v86/dev/ansi/no/makefile](../../base/mvdm/dos/v86/dev/ansi/no/makefile) | — | — |
| [base/mvdm/dos/v86/dev/ansi/pl](../../base/mvdm/dos/v86/dev/ansi/pl) | 3 | [base/mvdm/dos/v86/dev/ansi/pl/sources](../../base/mvdm/dos/v86/dev/ansi/pl/sources), [base/mvdm/dos/v86/dev/ansi/pl/makefile](../../base/mvdm/dos/v86/dev/ansi/pl/makefile) | — | — |
| [base/mvdm/dos/v86/dev/ansi/psu](../../base/mvdm/dos/v86/dev/ansi/psu) | 3 | [base/mvdm/dos/v86/dev/ansi/psu/sources](../../base/mvdm/dos/v86/dev/ansi/psu/sources), [base/mvdm/dos/v86/dev/ansi/psu/makefile](../../base/mvdm/dos/v86/dev/ansi/psu/makefile) | — | — |
| [base/mvdm/dos/v86/dev/ansi/pt](../../base/mvdm/dos/v86/dev/ansi/pt) | 3 | [base/mvdm/dos/v86/dev/ansi/pt/sources](../../base/mvdm/dos/v86/dev/ansi/pt/sources), [base/mvdm/dos/v86/dev/ansi/pt/makefile](../../base/mvdm/dos/v86/dev/ansi/pt/makefile) | — | — |
| [base/mvdm/dos/v86/dev/ansi/ru](../../base/mvdm/dos/v86/dev/ansi/ru) | 3 | [base/mvdm/dos/v86/dev/ansi/ru/sources](../../base/mvdm/dos/v86/dev/ansi/ru/sources), [base/mvdm/dos/v86/dev/ansi/ru/makefile](../../base/mvdm/dos/v86/dev/ansi/ru/makefile) | — | — |
| [base/mvdm/dos/v86/dev/ansi/sv](../../base/mvdm/dos/v86/dev/ansi/sv) | 3 | [base/mvdm/dos/v86/dev/ansi/sv/sources](../../base/mvdm/dos/v86/dev/ansi/sv/sources), [base/mvdm/dos/v86/dev/ansi/sv/makefile](../../base/mvdm/dos/v86/dev/ansi/sv/makefile) | — | — |
| [base/mvdm/dos/v86/dev/ansi/tr](../../base/mvdm/dos/v86/dev/ansi/tr) | 3 | [base/mvdm/dos/v86/dev/ansi/tr/sources](../../base/mvdm/dos/v86/dev/ansi/tr/sources), [base/mvdm/dos/v86/dev/ansi/tr/makefile](../../base/mvdm/dos/v86/dev/ansi/tr/makefile) | — | — |
| [base/mvdm/dos/v86/dev/ansi/tst](../../base/mvdm/dos/v86/dev/ansi/tst) | 3 | [base/mvdm/dos/v86/dev/ansi/tst/sources](../../base/mvdm/dos/v86/dev/ansi/tst/sources), [base/mvdm/dos/v86/dev/ansi/tst/makefile](../../base/mvdm/dos/v86/dev/ansi/tst/makefile) | — | — |
| [base/mvdm/dos/v86/dev/ansi/usa](../../base/mvdm/dos/v86/dev/ansi/usa) | 4 | [base/mvdm/dos/v86/dev/ansi/usa/sources](../../base/mvdm/dos/v86/dev/ansi/usa/sources), [base/mvdm/dos/v86/dev/ansi/usa/makefile](../../base/mvdm/dos/v86/dev/ansi/usa/makefile) | — | — |
| [base/mvdm/dos/v86/dev/country](../../base/mvdm/dos/v86/dev/country) | 22 | [base/mvdm/dos/v86/dev/country/dirs](../../base/mvdm/dos/v86/dev/country/dirs) | — | — |
| [base/mvdm/dos/v86/dev/country/usa](../../base/mvdm/dos/v86/dev/country/usa) | 3 | [base/mvdm/dos/v86/dev/country/usa/sources](../../base/mvdm/dos/v86/dev/country/usa/sources), [base/mvdm/dos/v86/dev/country/usa/makefile](../../base/mvdm/dos/v86/dev/country/usa/makefile) | — | — |
| [base/mvdm/dos/v86/dev/disp_win](../../base/mvdm/dos/v86/dev/disp_win) | 5 | [base/mvdm/dos/v86/dev/disp_win/dirs](../../base/mvdm/dos/v86/dev/disp_win/dirs) | — | — |
| [base/mvdm/dos/v86/dev/disp_win/jpn](../../base/mvdm/dos/v86/dev/disp_win/jpn) | 3 | [base/mvdm/dos/v86/dev/disp_win/jpn/sources](../../base/mvdm/dos/v86/dev/disp_win/jpn/sources), [base/mvdm/dos/v86/dev/disp_win/jpn/makefile](../../base/mvdm/dos/v86/dev/disp_win/jpn/makefile) | — | — |
| [base/mvdm/dos/v86/dev/disp_win/kor](../../base/mvdm/dos/v86/dev/disp_win/kor) | 3 | [base/mvdm/dos/v86/dev/disp_win/kor/sources](../../base/mvdm/dos/v86/dev/disp_win/kor/sources), [base/mvdm/dos/v86/dev/disp_win/kor/makefile](../../base/mvdm/dos/v86/dev/disp_win/kor/makefile) | — | — |
| [base/mvdm/dos/v86/dev/font_win](../../base/mvdm/dos/v86/dev/font_win) | 5 | [base/mvdm/dos/v86/dev/font_win/dirs](../../base/mvdm/dos/v86/dev/font_win/dirs) | — | — |
| [base/mvdm/dos/v86/dev/font_win/jpn](../../base/mvdm/dos/v86/dev/font_win/jpn) | 3 | [base/mvdm/dos/v86/dev/font_win/jpn/sources](../../base/mvdm/dos/v86/dev/font_win/jpn/sources), [base/mvdm/dos/v86/dev/font_win/jpn/makefile](../../base/mvdm/dos/v86/dev/font_win/jpn/makefile) | — | — |
| [base/mvdm/dos/v86/dev/font_win/kor](../../base/mvdm/dos/v86/dev/font_win/kor) | 3 | [base/mvdm/dos/v86/dev/font_win/kor/sources](../../base/mvdm/dos/v86/dev/font_win/kor/sources), [base/mvdm/dos/v86/dev/font_win/kor/makefile](../../base/mvdm/dos/v86/dev/font_win/kor/makefile) | — | — |
| [base/mvdm/dos/v86/dev/hbios](../../base/mvdm/dos/v86/dev/hbios) | 33 | [base/mvdm/dos/v86/dev/hbios/dirs](../../base/mvdm/dos/v86/dev/hbios/dirs) | — | — |
| [base/mvdm/dos/v86/dev/hbios/kor](../../base/mvdm/dos/v86/dev/hbios/kor) | 3 | [base/mvdm/dos/v86/dev/hbios/kor/sources](../../base/mvdm/dos/v86/dev/hbios/kor/sources), [base/mvdm/dos/v86/dev/hbios/kor/makefile](../../base/mvdm/dos/v86/dev/hbios/kor/makefile) | — | — |
| [base/mvdm/dos/v86/dev/himem](../../base/mvdm/dos/v86/dev/himem) | 9 | [base/mvdm/dos/v86/dev/himem/dirs](../../base/mvdm/dos/v86/dev/himem/dirs) | — | — |
| [base/mvdm/dos/v86/dev/himem/br](../../base/mvdm/dos/v86/dev/himem/br) | 4 | [base/mvdm/dos/v86/dev/himem/br/sources](../../base/mvdm/dos/v86/dev/himem/br/sources), [base/mvdm/dos/v86/dev/himem/br/makefile](../../base/mvdm/dos/v86/dev/himem/br/makefile) | — | — |
| [base/mvdm/dos/v86/dev/himem/chp](../../base/mvdm/dos/v86/dev/himem/chp) | 4 | [base/mvdm/dos/v86/dev/himem/chp/sources](../../base/mvdm/dos/v86/dev/himem/chp/sources), [base/mvdm/dos/v86/dev/himem/chp/makefile](../../base/mvdm/dos/v86/dev/himem/chp/makefile) | — | — |
| [base/mvdm/dos/v86/dev/himem/chs](../../base/mvdm/dos/v86/dev/himem/chs) | 4 | [base/mvdm/dos/v86/dev/himem/chs/sources](../../base/mvdm/dos/v86/dev/himem/chs/sources), [base/mvdm/dos/v86/dev/himem/chs/makefile](../../base/mvdm/dos/v86/dev/himem/chs/makefile) | — | — |
| [base/mvdm/dos/v86/dev/himem/cht](../../base/mvdm/dos/v86/dev/himem/cht) | 4 | [base/mvdm/dos/v86/dev/himem/cht/sources](../../base/mvdm/dos/v86/dev/himem/cht/sources), [base/mvdm/dos/v86/dev/himem/cht/makefile](../../base/mvdm/dos/v86/dev/himem/cht/makefile) | — | — |
| [base/mvdm/dos/v86/dev/himem/cs](../../base/mvdm/dos/v86/dev/himem/cs) | 4 | [base/mvdm/dos/v86/dev/himem/cs/sources](../../base/mvdm/dos/v86/dev/himem/cs/sources), [base/mvdm/dos/v86/dev/himem/cs/makefile](../../base/mvdm/dos/v86/dev/himem/cs/makefile) | — | — |
| [base/mvdm/dos/v86/dev/himem/da](../../base/mvdm/dos/v86/dev/himem/da) | 4 | [base/mvdm/dos/v86/dev/himem/da/sources](../../base/mvdm/dos/v86/dev/himem/da/sources), [base/mvdm/dos/v86/dev/himem/da/makefile](../../base/mvdm/dos/v86/dev/himem/da/makefile) | — | — |
| [base/mvdm/dos/v86/dev/himem/el](../../base/mvdm/dos/v86/dev/himem/el) | 4 | [base/mvdm/dos/v86/dev/himem/el/sources](../../base/mvdm/dos/v86/dev/himem/el/sources), [base/mvdm/dos/v86/dev/himem/el/makefile](../../base/mvdm/dos/v86/dev/himem/el/makefile) | — | — |
| [base/mvdm/dos/v86/dev/himem/es](../../base/mvdm/dos/v86/dev/himem/es) | 4 | [base/mvdm/dos/v86/dev/himem/es/sources](../../base/mvdm/dos/v86/dev/himem/es/sources), [base/mvdm/dos/v86/dev/himem/es/makefile](../../base/mvdm/dos/v86/dev/himem/es/makefile) | — | — |
| [base/mvdm/dos/v86/dev/himem/fi](../../base/mvdm/dos/v86/dev/himem/fi) | 4 | [base/mvdm/dos/v86/dev/himem/fi/sources](../../base/mvdm/dos/v86/dev/himem/fi/sources), [base/mvdm/dos/v86/dev/himem/fi/makefile](../../base/mvdm/dos/v86/dev/himem/fi/makefile) | — | — |
| [base/mvdm/dos/v86/dev/himem/fr](../../base/mvdm/dos/v86/dev/himem/fr) | 4 | [base/mvdm/dos/v86/dev/himem/fr/sources](../../base/mvdm/dos/v86/dev/himem/fr/sources), [base/mvdm/dos/v86/dev/himem/fr/makefile](../../base/mvdm/dos/v86/dev/himem/fr/makefile) | — | — |
| [base/mvdm/dos/v86/dev/himem/ger](../../base/mvdm/dos/v86/dev/himem/ger) | 4 | [base/mvdm/dos/v86/dev/himem/ger/sources](../../base/mvdm/dos/v86/dev/himem/ger/sources), [base/mvdm/dos/v86/dev/himem/ger/makefile](../../base/mvdm/dos/v86/dev/himem/ger/makefile) | — | — |
| [base/mvdm/dos/v86/dev/himem/hu](../../base/mvdm/dos/v86/dev/himem/hu) | 4 | [base/mvdm/dos/v86/dev/himem/hu/sources](../../base/mvdm/dos/v86/dev/himem/hu/sources), [base/mvdm/dos/v86/dev/himem/hu/makefile](../../base/mvdm/dos/v86/dev/himem/hu/makefile) | — | — |
| [base/mvdm/dos/v86/dev/himem/it](../../base/mvdm/dos/v86/dev/himem/it) | 4 | [base/mvdm/dos/v86/dev/himem/it/sources](../../base/mvdm/dos/v86/dev/himem/it/sources), [base/mvdm/dos/v86/dev/himem/it/makefile](../../base/mvdm/dos/v86/dev/himem/it/makefile) | — | — |
| [base/mvdm/dos/v86/dev/himem/jpn](../../base/mvdm/dos/v86/dev/himem/jpn) | 4 | [base/mvdm/dos/v86/dev/himem/jpn/sources](../../base/mvdm/dos/v86/dev/himem/jpn/sources), [base/mvdm/dos/v86/dev/himem/jpn/makefile](../../base/mvdm/dos/v86/dev/himem/jpn/makefile) | — | — |
| [base/mvdm/dos/v86/dev/himem/kor](../../base/mvdm/dos/v86/dev/himem/kor) | 4 | [base/mvdm/dos/v86/dev/himem/kor/sources](../../base/mvdm/dos/v86/dev/himem/kor/sources), [base/mvdm/dos/v86/dev/himem/kor/makefile](../../base/mvdm/dos/v86/dev/himem/kor/makefile) | — | — |
| [base/mvdm/dos/v86/dev/himem/nec_98](../../base/mvdm/dos/v86/dev/himem/nec_98) | 4 | [base/mvdm/dos/v86/dev/himem/nec_98/sources](../../base/mvdm/dos/v86/dev/himem/nec_98/sources), [base/mvdm/dos/v86/dev/himem/nec_98/makefile](../../base/mvdm/dos/v86/dev/himem/nec_98/makefile) | — | — |
| [base/mvdm/dos/v86/dev/himem/nl](../../base/mvdm/dos/v86/dev/himem/nl) | 4 | [base/mvdm/dos/v86/dev/himem/nl/sources](../../base/mvdm/dos/v86/dev/himem/nl/sources), [base/mvdm/dos/v86/dev/himem/nl/makefile](../../base/mvdm/dos/v86/dev/himem/nl/makefile) | — | — |
| [base/mvdm/dos/v86/dev/himem/no](../../base/mvdm/dos/v86/dev/himem/no) | 4 | [base/mvdm/dos/v86/dev/himem/no/sources](../../base/mvdm/dos/v86/dev/himem/no/sources), [base/mvdm/dos/v86/dev/himem/no/makefile](../../base/mvdm/dos/v86/dev/himem/no/makefile) | — | — |
| [base/mvdm/dos/v86/dev/himem/pl](../../base/mvdm/dos/v86/dev/himem/pl) | 4 | [base/mvdm/dos/v86/dev/himem/pl/sources](../../base/mvdm/dos/v86/dev/himem/pl/sources), [base/mvdm/dos/v86/dev/himem/pl/makefile](../../base/mvdm/dos/v86/dev/himem/pl/makefile) | — | — |
| [base/mvdm/dos/v86/dev/himem/psu](../../base/mvdm/dos/v86/dev/himem/psu) | 4 | [base/mvdm/dos/v86/dev/himem/psu/sources](../../base/mvdm/dos/v86/dev/himem/psu/sources), [base/mvdm/dos/v86/dev/himem/psu/makefile](../../base/mvdm/dos/v86/dev/himem/psu/makefile) | — | — |
| [base/mvdm/dos/v86/dev/himem/pt](../../base/mvdm/dos/v86/dev/himem/pt) | 4 | [base/mvdm/dos/v86/dev/himem/pt/sources](../../base/mvdm/dos/v86/dev/himem/pt/sources), [base/mvdm/dos/v86/dev/himem/pt/makefile](../../base/mvdm/dos/v86/dev/himem/pt/makefile) | — | — |
| [base/mvdm/dos/v86/dev/himem/ru](../../base/mvdm/dos/v86/dev/himem/ru) | 4 | [base/mvdm/dos/v86/dev/himem/ru/sources](../../base/mvdm/dos/v86/dev/himem/ru/sources), [base/mvdm/dos/v86/dev/himem/ru/makefile](../../base/mvdm/dos/v86/dev/himem/ru/makefile) | — | — |
| [base/mvdm/dos/v86/dev/himem/sv](../../base/mvdm/dos/v86/dev/himem/sv) | 4 | [base/mvdm/dos/v86/dev/himem/sv/sources](../../base/mvdm/dos/v86/dev/himem/sv/sources), [base/mvdm/dos/v86/dev/himem/sv/makefile](../../base/mvdm/dos/v86/dev/himem/sv/makefile) | — | — |
| [base/mvdm/dos/v86/dev/himem/tr](../../base/mvdm/dos/v86/dev/himem/tr) | 4 | [base/mvdm/dos/v86/dev/himem/tr/sources](../../base/mvdm/dos/v86/dev/himem/tr/sources), [base/mvdm/dos/v86/dev/himem/tr/makefile](../../base/mvdm/dos/v86/dev/himem/tr/makefile) | — | — |
| [base/mvdm/dos/v86/dev/himem/tst](../../base/mvdm/dos/v86/dev/himem/tst) | 4 | [base/mvdm/dos/v86/dev/himem/tst/sources](../../base/mvdm/dos/v86/dev/himem/tst/sources), [base/mvdm/dos/v86/dev/himem/tst/makefile](../../base/mvdm/dos/v86/dev/himem/tst/makefile) | — | — |
| [base/mvdm/dos/v86/dev/himem/usa](../../base/mvdm/dos/v86/dev/himem/usa) | 4 | [base/mvdm/dos/v86/dev/himem/usa/sources](../../base/mvdm/dos/v86/dev/himem/usa/sources), [base/mvdm/dos/v86/dev/himem/usa/makefile](../../base/mvdm/dos/v86/dev/himem/usa/makefile) | — | — |
| [base/mvdm/dos/v86/dev/keyboard](../../base/mvdm/dos/v86/dev/keyboard) | 73 | [base/mvdm/dos/v86/dev/keyboard/dirs](../../base/mvdm/dos/v86/dev/keyboard/dirs) | — | — |
| [base/mvdm/dos/v86/dev/keyboard/jpn](../../base/mvdm/dos/v86/dev/keyboard/jpn) | 3 | [base/mvdm/dos/v86/dev/keyboard/jpn/sources](../../base/mvdm/dos/v86/dev/keyboard/jpn/sources), [base/mvdm/dos/v86/dev/keyboard/jpn/makefile](../../base/mvdm/dos/v86/dev/keyboard/jpn/makefile) | — | — |
| [base/mvdm/dos/v86/dev/keyboard/usa](../../base/mvdm/dos/v86/dev/keyboard/usa) | 3 | [base/mvdm/dos/v86/dev/keyboard/usa/sources](../../base/mvdm/dos/v86/dev/keyboard/usa/sources), [base/mvdm/dos/v86/dev/keyboard/usa/makefile](../../base/mvdm/dos/v86/dev/keyboard/usa/makefile) | — | — |
| [base/mvdm/dos/v86/dev/ntfont](../../base/mvdm/dos/v86/dev/ntfont) | 5 | [base/mvdm/dos/v86/dev/ntfont/dirs](../../base/mvdm/dos/v86/dev/ntfont/dirs) | — | — |
| [base/mvdm/dos/v86/dev/ntfont/jpn](../../base/mvdm/dos/v86/dev/ntfont/jpn) | 3 | [base/mvdm/dos/v86/dev/ntfont/jpn/sources](../../base/mvdm/dos/v86/dev/ntfont/jpn/sources), [base/mvdm/dos/v86/dev/ntfont/jpn/makefile](../../base/mvdm/dos/v86/dev/ntfont/jpn/makefile) | — | — |
| [base/mvdm/dos/v86/doskrnl](../../base/mvdm/dos/v86/doskrnl) | 1 | [base/mvdm/dos/v86/doskrnl/dirs](../../base/mvdm/dos/v86/doskrnl/dirs) | — | — |
| [base/mvdm/dos/v86/doskrnl/bios](../../base/mvdm/dos/v86/doskrnl/bios) | 37 | [base/mvdm/dos/v86/doskrnl/bios/dirs](../../base/mvdm/dos/v86/doskrnl/bios/dirs) | — | — |
| [base/mvdm/dos/v86/doskrnl/bios/br](../../base/mvdm/dos/v86/doskrnl/bios/br) | 3 | [base/mvdm/dos/v86/doskrnl/bios/br/sources](../../base/mvdm/dos/v86/doskrnl/bios/br/sources), [base/mvdm/dos/v86/doskrnl/bios/br/makefile](../../base/mvdm/dos/v86/doskrnl/bios/br/makefile) | — | — |
| [base/mvdm/dos/v86/doskrnl/bios/chp](../../base/mvdm/dos/v86/doskrnl/bios/chp) | 4 | [base/mvdm/dos/v86/doskrnl/bios/chp/sources](../../base/mvdm/dos/v86/doskrnl/bios/chp/sources), [base/mvdm/dos/v86/doskrnl/bios/chp/makefile](../../base/mvdm/dos/v86/doskrnl/bios/chp/makefile) | — | — |
| [base/mvdm/dos/v86/doskrnl/bios/chs](../../base/mvdm/dos/v86/doskrnl/bios/chs) | 4 | [base/mvdm/dos/v86/doskrnl/bios/chs/sources](../../base/mvdm/dos/v86/doskrnl/bios/chs/sources), [base/mvdm/dos/v86/doskrnl/bios/chs/makefile](../../base/mvdm/dos/v86/doskrnl/bios/chs/makefile) | — | — |
| [base/mvdm/dos/v86/doskrnl/bios/cht](../../base/mvdm/dos/v86/doskrnl/bios/cht) | 4 | [base/mvdm/dos/v86/doskrnl/bios/cht/sources](../../base/mvdm/dos/v86/doskrnl/bios/cht/sources), [base/mvdm/dos/v86/doskrnl/bios/cht/makefile](../../base/mvdm/dos/v86/doskrnl/bios/cht/makefile) | — | — |
| [base/mvdm/dos/v86/doskrnl/bios/cs](../../base/mvdm/dos/v86/doskrnl/bios/cs) | 3 | [base/mvdm/dos/v86/doskrnl/bios/cs/sources](../../base/mvdm/dos/v86/doskrnl/bios/cs/sources), [base/mvdm/dos/v86/doskrnl/bios/cs/makefile](../../base/mvdm/dos/v86/doskrnl/bios/cs/makefile) | — | — |
| [base/mvdm/dos/v86/doskrnl/bios/da](../../base/mvdm/dos/v86/doskrnl/bios/da) | 3 | [base/mvdm/dos/v86/doskrnl/bios/da/sources](../../base/mvdm/dos/v86/doskrnl/bios/da/sources), [base/mvdm/dos/v86/doskrnl/bios/da/makefile](../../base/mvdm/dos/v86/doskrnl/bios/da/makefile) | — | — |
| [base/mvdm/dos/v86/doskrnl/bios/el](../../base/mvdm/dos/v86/doskrnl/bios/el) | 3 | [base/mvdm/dos/v86/doskrnl/bios/el/sources](../../base/mvdm/dos/v86/doskrnl/bios/el/sources), [base/mvdm/dos/v86/doskrnl/bios/el/makefile](../../base/mvdm/dos/v86/doskrnl/bios/el/makefile) | — | — |
| [base/mvdm/dos/v86/doskrnl/bios/es](../../base/mvdm/dos/v86/doskrnl/bios/es) | 3 | [base/mvdm/dos/v86/doskrnl/bios/es/sources](../../base/mvdm/dos/v86/doskrnl/bios/es/sources), [base/mvdm/dos/v86/doskrnl/bios/es/makefile](../../base/mvdm/dos/v86/doskrnl/bios/es/makefile) | — | — |
| [base/mvdm/dos/v86/doskrnl/bios/fi](../../base/mvdm/dos/v86/doskrnl/bios/fi) | 3 | [base/mvdm/dos/v86/doskrnl/bios/fi/sources](../../base/mvdm/dos/v86/doskrnl/bios/fi/sources), [base/mvdm/dos/v86/doskrnl/bios/fi/makefile](../../base/mvdm/dos/v86/doskrnl/bios/fi/makefile) | — | — |
| [base/mvdm/dos/v86/doskrnl/bios/fr](../../base/mvdm/dos/v86/doskrnl/bios/fr) | 3 | [base/mvdm/dos/v86/doskrnl/bios/fr/sources](../../base/mvdm/dos/v86/doskrnl/bios/fr/sources), [base/mvdm/dos/v86/doskrnl/bios/fr/makefile](../../base/mvdm/dos/v86/doskrnl/bios/fr/makefile) | — | — |
| [base/mvdm/dos/v86/doskrnl/bios/ger](../../base/mvdm/dos/v86/doskrnl/bios/ger) | 3 | [base/mvdm/dos/v86/doskrnl/bios/ger/sources](../../base/mvdm/dos/v86/doskrnl/bios/ger/sources), [base/mvdm/dos/v86/doskrnl/bios/ger/makefile](../../base/mvdm/dos/v86/doskrnl/bios/ger/makefile) | — | — |
| [base/mvdm/dos/v86/doskrnl/bios/hu](../../base/mvdm/dos/v86/doskrnl/bios/hu) | 3 | [base/mvdm/dos/v86/doskrnl/bios/hu/sources](../../base/mvdm/dos/v86/doskrnl/bios/hu/sources), [base/mvdm/dos/v86/doskrnl/bios/hu/makefile](../../base/mvdm/dos/v86/doskrnl/bios/hu/makefile) | — | — |
| [base/mvdm/dos/v86/doskrnl/bios/it](../../base/mvdm/dos/v86/doskrnl/bios/it) | 3 | [base/mvdm/dos/v86/doskrnl/bios/it/sources](../../base/mvdm/dos/v86/doskrnl/bios/it/sources), [base/mvdm/dos/v86/doskrnl/bios/it/makefile](../../base/mvdm/dos/v86/doskrnl/bios/it/makefile) | — | — |
| [base/mvdm/dos/v86/doskrnl/bios/jpn](../../base/mvdm/dos/v86/doskrnl/bios/jpn) | 4 | [base/mvdm/dos/v86/doskrnl/bios/jpn/sources](../../base/mvdm/dos/v86/doskrnl/bios/jpn/sources), [base/mvdm/dos/v86/doskrnl/bios/jpn/makefile](../../base/mvdm/dos/v86/doskrnl/bios/jpn/makefile) | — | — |
| [base/mvdm/dos/v86/doskrnl/bios/kor](../../base/mvdm/dos/v86/doskrnl/bios/kor) | 4 | [base/mvdm/dos/v86/doskrnl/bios/kor/sources](../../base/mvdm/dos/v86/doskrnl/bios/kor/sources), [base/mvdm/dos/v86/doskrnl/bios/kor/makefile](../../base/mvdm/dos/v86/doskrnl/bios/kor/makefile) | — | — |
| [base/mvdm/dos/v86/doskrnl/bios/nec_98](../../base/mvdm/dos/v86/doskrnl/bios/nec_98) | 4 | [base/mvdm/dos/v86/doskrnl/bios/nec_98/sources](../../base/mvdm/dos/v86/doskrnl/bios/nec_98/sources), [base/mvdm/dos/v86/doskrnl/bios/nec_98/makefile](../../base/mvdm/dos/v86/doskrnl/bios/nec_98/makefile) | — | — |
| [base/mvdm/dos/v86/doskrnl/bios/nl](../../base/mvdm/dos/v86/doskrnl/bios/nl) | 3 | [base/mvdm/dos/v86/doskrnl/bios/nl/sources](../../base/mvdm/dos/v86/doskrnl/bios/nl/sources), [base/mvdm/dos/v86/doskrnl/bios/nl/makefile](../../base/mvdm/dos/v86/doskrnl/bios/nl/makefile) | — | — |
| [base/mvdm/dos/v86/doskrnl/bios/no](../../base/mvdm/dos/v86/doskrnl/bios/no) | 3 | [base/mvdm/dos/v86/doskrnl/bios/no/sources](../../base/mvdm/dos/v86/doskrnl/bios/no/sources), [base/mvdm/dos/v86/doskrnl/bios/no/makefile](../../base/mvdm/dos/v86/doskrnl/bios/no/makefile) | — | — |
| [base/mvdm/dos/v86/doskrnl/bios/pl](../../base/mvdm/dos/v86/doskrnl/bios/pl) | 3 | [base/mvdm/dos/v86/doskrnl/bios/pl/sources](../../base/mvdm/dos/v86/doskrnl/bios/pl/sources), [base/mvdm/dos/v86/doskrnl/bios/pl/makefile](../../base/mvdm/dos/v86/doskrnl/bios/pl/makefile) | — | — |
| [base/mvdm/dos/v86/doskrnl/bios/psu](../../base/mvdm/dos/v86/doskrnl/bios/psu) | 3 | [base/mvdm/dos/v86/doskrnl/bios/psu/sources](../../base/mvdm/dos/v86/doskrnl/bios/psu/sources), [base/mvdm/dos/v86/doskrnl/bios/psu/makefile](../../base/mvdm/dos/v86/doskrnl/bios/psu/makefile) | — | — |
| [base/mvdm/dos/v86/doskrnl/bios/pt](../../base/mvdm/dos/v86/doskrnl/bios/pt) | 3 | [base/mvdm/dos/v86/doskrnl/bios/pt/sources](../../base/mvdm/dos/v86/doskrnl/bios/pt/sources), [base/mvdm/dos/v86/doskrnl/bios/pt/makefile](../../base/mvdm/dos/v86/doskrnl/bios/pt/makefile) | — | — |
| [base/mvdm/dos/v86/doskrnl/bios/ru](../../base/mvdm/dos/v86/doskrnl/bios/ru) | 3 | [base/mvdm/dos/v86/doskrnl/bios/ru/sources](../../base/mvdm/dos/v86/doskrnl/bios/ru/sources), [base/mvdm/dos/v86/doskrnl/bios/ru/makefile](../../base/mvdm/dos/v86/doskrnl/bios/ru/makefile) | — | — |
| [base/mvdm/dos/v86/doskrnl/bios/sv](../../base/mvdm/dos/v86/doskrnl/bios/sv) | 3 | [base/mvdm/dos/v86/doskrnl/bios/sv/sources](../../base/mvdm/dos/v86/doskrnl/bios/sv/sources), [base/mvdm/dos/v86/doskrnl/bios/sv/makefile](../../base/mvdm/dos/v86/doskrnl/bios/sv/makefile) | — | — |
| [base/mvdm/dos/v86/doskrnl/bios/tr](../../base/mvdm/dos/v86/doskrnl/bios/tr) | 3 | [base/mvdm/dos/v86/doskrnl/bios/tr/sources](../../base/mvdm/dos/v86/doskrnl/bios/tr/sources), [base/mvdm/dos/v86/doskrnl/bios/tr/makefile](../../base/mvdm/dos/v86/doskrnl/bios/tr/makefile) | — | — |
| [base/mvdm/dos/v86/doskrnl/bios/tst](../../base/mvdm/dos/v86/doskrnl/bios/tst) | 3 | [base/mvdm/dos/v86/doskrnl/bios/tst/sources](../../base/mvdm/dos/v86/doskrnl/bios/tst/sources), [base/mvdm/dos/v86/doskrnl/bios/tst/makefile](../../base/mvdm/dos/v86/doskrnl/bios/tst/makefile) | — | — |
| [base/mvdm/dos/v86/doskrnl/bios/usa](../../base/mvdm/dos/v86/doskrnl/bios/usa) | 4 | [base/mvdm/dos/v86/doskrnl/bios/usa/sources](../../base/mvdm/dos/v86/doskrnl/bios/usa/sources), [base/mvdm/dos/v86/doskrnl/bios/usa/makefile](../../base/mvdm/dos/v86/doskrnl/bios/usa/makefile) | — | — |
| [base/mvdm/dos/v86/doskrnl/dos](../../base/mvdm/dos/v86/doskrnl/dos) | 56 | [base/mvdm/dos/v86/doskrnl/dos/dirs](../../base/mvdm/dos/v86/doskrnl/dos/dirs) | — | — |
| [base/mvdm/dos/v86/doskrnl/dos/br](../../base/mvdm/dos/v86/doskrnl/dos/br) | 3 | [base/mvdm/dos/v86/doskrnl/dos/br/sources](../../base/mvdm/dos/v86/doskrnl/dos/br/sources), [base/mvdm/dos/v86/doskrnl/dos/br/makefile](../../base/mvdm/dos/v86/doskrnl/dos/br/makefile) | — | — |
| [base/mvdm/dos/v86/doskrnl/dos/chp](../../base/mvdm/dos/v86/doskrnl/dos/chp) | 4 | [base/mvdm/dos/v86/doskrnl/dos/chp/sources](../../base/mvdm/dos/v86/doskrnl/dos/chp/sources), [base/mvdm/dos/v86/doskrnl/dos/chp/makefile](../../base/mvdm/dos/v86/doskrnl/dos/chp/makefile) | — | — |
| [base/mvdm/dos/v86/doskrnl/dos/chs](../../base/mvdm/dos/v86/doskrnl/dos/chs) | 4 | [base/mvdm/dos/v86/doskrnl/dos/chs/sources](../../base/mvdm/dos/v86/doskrnl/dos/chs/sources), [base/mvdm/dos/v86/doskrnl/dos/chs/makefile](../../base/mvdm/dos/v86/doskrnl/dos/chs/makefile) | — | — |
| [base/mvdm/dos/v86/doskrnl/dos/cht](../../base/mvdm/dos/v86/doskrnl/dos/cht) | 4 | [base/mvdm/dos/v86/doskrnl/dos/cht/sources](../../base/mvdm/dos/v86/doskrnl/dos/cht/sources), [base/mvdm/dos/v86/doskrnl/dos/cht/makefile](../../base/mvdm/dos/v86/doskrnl/dos/cht/makefile) | — | — |
| [base/mvdm/dos/v86/doskrnl/dos/cs](../../base/mvdm/dos/v86/doskrnl/dos/cs) | 3 | [base/mvdm/dos/v86/doskrnl/dos/cs/sources](../../base/mvdm/dos/v86/doskrnl/dos/cs/sources), [base/mvdm/dos/v86/doskrnl/dos/cs/makefile](../../base/mvdm/dos/v86/doskrnl/dos/cs/makefile) | — | — |
| [base/mvdm/dos/v86/doskrnl/dos/da](../../base/mvdm/dos/v86/doskrnl/dos/da) | 3 | [base/mvdm/dos/v86/doskrnl/dos/da/sources](../../base/mvdm/dos/v86/doskrnl/dos/da/sources), [base/mvdm/dos/v86/doskrnl/dos/da/makefile](../../base/mvdm/dos/v86/doskrnl/dos/da/makefile) | — | — |
| [base/mvdm/dos/v86/doskrnl/dos/el](../../base/mvdm/dos/v86/doskrnl/dos/el) | 3 | [base/mvdm/dos/v86/doskrnl/dos/el/sources](../../base/mvdm/dos/v86/doskrnl/dos/el/sources), [base/mvdm/dos/v86/doskrnl/dos/el/makefile](../../base/mvdm/dos/v86/doskrnl/dos/el/makefile) | — | — |
| [base/mvdm/dos/v86/doskrnl/dos/es](../../base/mvdm/dos/v86/doskrnl/dos/es) | 3 | [base/mvdm/dos/v86/doskrnl/dos/es/sources](../../base/mvdm/dos/v86/doskrnl/dos/es/sources), [base/mvdm/dos/v86/doskrnl/dos/es/makefile](../../base/mvdm/dos/v86/doskrnl/dos/es/makefile) | — | — |
| [base/mvdm/dos/v86/doskrnl/dos/fi](../../base/mvdm/dos/v86/doskrnl/dos/fi) | 3 | [base/mvdm/dos/v86/doskrnl/dos/fi/sources](../../base/mvdm/dos/v86/doskrnl/dos/fi/sources), [base/mvdm/dos/v86/doskrnl/dos/fi/makefile](../../base/mvdm/dos/v86/doskrnl/dos/fi/makefile) | — | — |
| [base/mvdm/dos/v86/doskrnl/dos/fr](../../base/mvdm/dos/v86/doskrnl/dos/fr) | 3 | [base/mvdm/dos/v86/doskrnl/dos/fr/sources](../../base/mvdm/dos/v86/doskrnl/dos/fr/sources), [base/mvdm/dos/v86/doskrnl/dos/fr/makefile](../../base/mvdm/dos/v86/doskrnl/dos/fr/makefile) | — | — |
| [base/mvdm/dos/v86/doskrnl/dos/ger](../../base/mvdm/dos/v86/doskrnl/dos/ger) | 3 | [base/mvdm/dos/v86/doskrnl/dos/ger/sources](../../base/mvdm/dos/v86/doskrnl/dos/ger/sources), [base/mvdm/dos/v86/doskrnl/dos/ger/makefile](../../base/mvdm/dos/v86/doskrnl/dos/ger/makefile) | — | — |
| [base/mvdm/dos/v86/doskrnl/dos/hu](../../base/mvdm/dos/v86/doskrnl/dos/hu) | 3 | [base/mvdm/dos/v86/doskrnl/dos/hu/sources](../../base/mvdm/dos/v86/doskrnl/dos/hu/sources), [base/mvdm/dos/v86/doskrnl/dos/hu/makefile](../../base/mvdm/dos/v86/doskrnl/dos/hu/makefile) | — | — |
| [base/mvdm/dos/v86/doskrnl/dos/it](../../base/mvdm/dos/v86/doskrnl/dos/it) | 3 | [base/mvdm/dos/v86/doskrnl/dos/it/sources](../../base/mvdm/dos/v86/doskrnl/dos/it/sources), [base/mvdm/dos/v86/doskrnl/dos/it/makefile](../../base/mvdm/dos/v86/doskrnl/dos/it/makefile) | — | — |
| [base/mvdm/dos/v86/doskrnl/dos/jpn](../../base/mvdm/dos/v86/doskrnl/dos/jpn) | 4 | [base/mvdm/dos/v86/doskrnl/dos/jpn/sources](../../base/mvdm/dos/v86/doskrnl/dos/jpn/sources), [base/mvdm/dos/v86/doskrnl/dos/jpn/makefile](../../base/mvdm/dos/v86/doskrnl/dos/jpn/makefile) | — | — |
| [base/mvdm/dos/v86/doskrnl/dos/kor](../../base/mvdm/dos/v86/doskrnl/dos/kor) | 4 | [base/mvdm/dos/v86/doskrnl/dos/kor/sources](../../base/mvdm/dos/v86/doskrnl/dos/kor/sources), [base/mvdm/dos/v86/doskrnl/dos/kor/makefile](../../base/mvdm/dos/v86/doskrnl/dos/kor/makefile) | — | — |
| [base/mvdm/dos/v86/doskrnl/dos/nec_98](../../base/mvdm/dos/v86/doskrnl/dos/nec_98) | 4 | [base/mvdm/dos/v86/doskrnl/dos/nec_98/sources](../../base/mvdm/dos/v86/doskrnl/dos/nec_98/sources), [base/mvdm/dos/v86/doskrnl/dos/nec_98/makefile](../../base/mvdm/dos/v86/doskrnl/dos/nec_98/makefile) | — | — |
| [base/mvdm/dos/v86/doskrnl/dos/nl](../../base/mvdm/dos/v86/doskrnl/dos/nl) | 3 | [base/mvdm/dos/v86/doskrnl/dos/nl/sources](../../base/mvdm/dos/v86/doskrnl/dos/nl/sources), [base/mvdm/dos/v86/doskrnl/dos/nl/makefile](../../base/mvdm/dos/v86/doskrnl/dos/nl/makefile) | — | — |
| [base/mvdm/dos/v86/doskrnl/dos/no](../../base/mvdm/dos/v86/doskrnl/dos/no) | 3 | [base/mvdm/dos/v86/doskrnl/dos/no/sources](../../base/mvdm/dos/v86/doskrnl/dos/no/sources), [base/mvdm/dos/v86/doskrnl/dos/no/makefile](../../base/mvdm/dos/v86/doskrnl/dos/no/makefile) | — | — |
| [base/mvdm/dos/v86/doskrnl/dos/pl](../../base/mvdm/dos/v86/doskrnl/dos/pl) | 3 | [base/mvdm/dos/v86/doskrnl/dos/pl/sources](../../base/mvdm/dos/v86/doskrnl/dos/pl/sources), [base/mvdm/dos/v86/doskrnl/dos/pl/makefile](../../base/mvdm/dos/v86/doskrnl/dos/pl/makefile) | — | — |
| [base/mvdm/dos/v86/doskrnl/dos/psu](../../base/mvdm/dos/v86/doskrnl/dos/psu) | 3 | [base/mvdm/dos/v86/doskrnl/dos/psu/sources](../../base/mvdm/dos/v86/doskrnl/dos/psu/sources), [base/mvdm/dos/v86/doskrnl/dos/psu/makefile](../../base/mvdm/dos/v86/doskrnl/dos/psu/makefile) | — | — |
| [base/mvdm/dos/v86/doskrnl/dos/pt](../../base/mvdm/dos/v86/doskrnl/dos/pt) | 3 | [base/mvdm/dos/v86/doskrnl/dos/pt/sources](../../base/mvdm/dos/v86/doskrnl/dos/pt/sources), [base/mvdm/dos/v86/doskrnl/dos/pt/makefile](../../base/mvdm/dos/v86/doskrnl/dos/pt/makefile) | — | — |
| [base/mvdm/dos/v86/doskrnl/dos/ru](../../base/mvdm/dos/v86/doskrnl/dos/ru) | 3 | [base/mvdm/dos/v86/doskrnl/dos/ru/sources](../../base/mvdm/dos/v86/doskrnl/dos/ru/sources), [base/mvdm/dos/v86/doskrnl/dos/ru/makefile](../../base/mvdm/dos/v86/doskrnl/dos/ru/makefile) | — | — |
| [base/mvdm/dos/v86/doskrnl/dos/sv](../../base/mvdm/dos/v86/doskrnl/dos/sv) | 3 | [base/mvdm/dos/v86/doskrnl/dos/sv/sources](../../base/mvdm/dos/v86/doskrnl/dos/sv/sources), [base/mvdm/dos/v86/doskrnl/dos/sv/makefile](../../base/mvdm/dos/v86/doskrnl/dos/sv/makefile) | — | — |
| [base/mvdm/dos/v86/doskrnl/dos/tr](../../base/mvdm/dos/v86/doskrnl/dos/tr) | 3 | [base/mvdm/dos/v86/doskrnl/dos/tr/sources](../../base/mvdm/dos/v86/doskrnl/dos/tr/sources), [base/mvdm/dos/v86/doskrnl/dos/tr/makefile](../../base/mvdm/dos/v86/doskrnl/dos/tr/makefile) | — | — |
| [base/mvdm/dos/v86/doskrnl/dos/tst](../../base/mvdm/dos/v86/doskrnl/dos/tst) | 3 | [base/mvdm/dos/v86/doskrnl/dos/tst/sources](../../base/mvdm/dos/v86/doskrnl/dos/tst/sources), [base/mvdm/dos/v86/doskrnl/dos/tst/makefile](../../base/mvdm/dos/v86/doskrnl/dos/tst/makefile) | — | — |
| [base/mvdm/dos/v86/doskrnl/dos/usa](../../base/mvdm/dos/v86/doskrnl/dos/usa) | 4 | [base/mvdm/dos/v86/doskrnl/dos/usa/sources](../../base/mvdm/dos/v86/doskrnl/dos/usa/sources), [base/mvdm/dos/v86/doskrnl/dos/usa/makefile](../../base/mvdm/dos/v86/doskrnl/dos/usa/makefile) | — | — |
| [base/mvdm/dos/v86/h](../../base/mvdm/dos/v86/h) | 33 | — | — | — |
| [base/mvdm/dos/v86/inc](../../base/mvdm/dos/v86/inc) | 76 | — | — | — |
| [base/mvdm/dos/v86/lib](../../base/mvdm/dos/v86/lib) | 6 | [base/mvdm/dos/v86/lib/dirs](../../base/mvdm/dos/v86/lib/dirs) | — | — |
| [base/mvdm/dos/v86/lib/xmm](../../base/mvdm/dos/v86/lib/xmm) | 4 | [base/mvdm/dos/v86/lib/xmm/dirs](../../base/mvdm/dos/v86/lib/xmm/dirs) | — | — |
| [base/mvdm/dos/v86/lib/xmm/usa](../../base/mvdm/dos/v86/lib/xmm/usa) | 3 | [base/mvdm/dos/v86/lib/xmm/usa/sources](../../base/mvdm/dos/v86/lib/xmm/usa/sources), [base/mvdm/dos/v86/lib/xmm/usa/makefile](../../base/mvdm/dos/v86/lib/xmm/usa/makefile) | — | — |
| [base/mvdm/dos/v86/messages](../../base/mvdm/dos/v86/messages) | 3 | [base/mvdm/dos/v86/messages/dirs](../../base/mvdm/dos/v86/messages/dirs) | — | — |
| [base/mvdm/dos/v86/messages/br](../../base/mvdm/dos/v86/messages/br) | 8 | [base/mvdm/dos/v86/messages/br/sources](../../base/mvdm/dos/v86/messages/br/sources), [base/mvdm/dos/v86/messages/br/makefile](../../base/mvdm/dos/v86/messages/br/makefile) | — | — |
| [base/mvdm/dos/v86/messages/chp](../../base/mvdm/dos/v86/messages/chp) | 5 | — | — | — |
| [base/mvdm/dos/v86/messages/chs](../../base/mvdm/dos/v86/messages/chs) | 5 | — | — | — |
| [base/mvdm/dos/v86/messages/cht](../../base/mvdm/dos/v86/messages/cht) | 5 | — | — | — |
| [base/mvdm/dos/v86/messages/cs](../../base/mvdm/dos/v86/messages/cs) | 8 | [base/mvdm/dos/v86/messages/cs/sources](../../base/mvdm/dos/v86/messages/cs/sources), [base/mvdm/dos/v86/messages/cs/makefile](../../base/mvdm/dos/v86/messages/cs/makefile) | — | — |
| [base/mvdm/dos/v86/messages/da](../../base/mvdm/dos/v86/messages/da) | 8 | [base/mvdm/dos/v86/messages/da/sources](../../base/mvdm/dos/v86/messages/da/sources), [base/mvdm/dos/v86/messages/da/makefile](../../base/mvdm/dos/v86/messages/da/makefile) | — | — |
| [base/mvdm/dos/v86/messages/el](../../base/mvdm/dos/v86/messages/el) | 8 | [base/mvdm/dos/v86/messages/el/sources](../../base/mvdm/dos/v86/messages/el/sources), [base/mvdm/dos/v86/messages/el/makefile](../../base/mvdm/dos/v86/messages/el/makefile) | — | — |
| [base/mvdm/dos/v86/messages/es](../../base/mvdm/dos/v86/messages/es) | 8 | [base/mvdm/dos/v86/messages/es/sources](../../base/mvdm/dos/v86/messages/es/sources), [base/mvdm/dos/v86/messages/es/makefile](../../base/mvdm/dos/v86/messages/es/makefile) | — | — |
| [base/mvdm/dos/v86/messages/fi](../../base/mvdm/dos/v86/messages/fi) | 8 | [base/mvdm/dos/v86/messages/fi/sources](../../base/mvdm/dos/v86/messages/fi/sources), [base/mvdm/dos/v86/messages/fi/makefile](../../base/mvdm/dos/v86/messages/fi/makefile) | — | — |
| [base/mvdm/dos/v86/messages/fr](../../base/mvdm/dos/v86/messages/fr) | 8 | [base/mvdm/dos/v86/messages/fr/sources](../../base/mvdm/dos/v86/messages/fr/sources), [base/mvdm/dos/v86/messages/fr/makefile](../../base/mvdm/dos/v86/messages/fr/makefile) | — | — |
| [base/mvdm/dos/v86/messages/ger](../../base/mvdm/dos/v86/messages/ger) | 8 | [base/mvdm/dos/v86/messages/ger/sources](../../base/mvdm/dos/v86/messages/ger/sources), [base/mvdm/dos/v86/messages/ger/makefile](../../base/mvdm/dos/v86/messages/ger/makefile) | — | — |
| [base/mvdm/dos/v86/messages/hu](../../base/mvdm/dos/v86/messages/hu) | 8 | [base/mvdm/dos/v86/messages/hu/sources](../../base/mvdm/dos/v86/messages/hu/sources), [base/mvdm/dos/v86/messages/hu/makefile](../../base/mvdm/dos/v86/messages/hu/makefile) | — | — |
| [base/mvdm/dos/v86/messages/it](../../base/mvdm/dos/v86/messages/it) | 8 | [base/mvdm/dos/v86/messages/it/sources](../../base/mvdm/dos/v86/messages/it/sources), [base/mvdm/dos/v86/messages/it/makefile](../../base/mvdm/dos/v86/messages/it/makefile) | — | — |
| [base/mvdm/dos/v86/messages/jpn](../../base/mvdm/dos/v86/messages/jpn) | 5 | — | — | — |
| [base/mvdm/dos/v86/messages/kor](../../base/mvdm/dos/v86/messages/kor) | 5 | — | — | — |
| [base/mvdm/dos/v86/messages/nec_98](../../base/mvdm/dos/v86/messages/nec_98) | 5 | — | — | — |
| [base/mvdm/dos/v86/messages/nl](../../base/mvdm/dos/v86/messages/nl) | 8 | [base/mvdm/dos/v86/messages/nl/sources](../../base/mvdm/dos/v86/messages/nl/sources), [base/mvdm/dos/v86/messages/nl/makefile](../../base/mvdm/dos/v86/messages/nl/makefile) | — | — |
| [base/mvdm/dos/v86/messages/no](../../base/mvdm/dos/v86/messages/no) | 8 | [base/mvdm/dos/v86/messages/no/sources](../../base/mvdm/dos/v86/messages/no/sources), [base/mvdm/dos/v86/messages/no/makefile](../../base/mvdm/dos/v86/messages/no/makefile) | — | — |
| [base/mvdm/dos/v86/messages/pl](../../base/mvdm/dos/v86/messages/pl) | 8 | [base/mvdm/dos/v86/messages/pl/sources](../../base/mvdm/dos/v86/messages/pl/sources), [base/mvdm/dos/v86/messages/pl/makefile](../../base/mvdm/dos/v86/messages/pl/makefile) | — | — |
| [base/mvdm/dos/v86/messages/pt](../../base/mvdm/dos/v86/messages/pt) | 8 | [base/mvdm/dos/v86/messages/pt/sources](../../base/mvdm/dos/v86/messages/pt/sources), [base/mvdm/dos/v86/messages/pt/makefile](../../base/mvdm/dos/v86/messages/pt/makefile) | — | — |
| [base/mvdm/dos/v86/messages/ru](../../base/mvdm/dos/v86/messages/ru) | 8 | [base/mvdm/dos/v86/messages/ru/sources](../../base/mvdm/dos/v86/messages/ru/sources), [base/mvdm/dos/v86/messages/ru/makefile](../../base/mvdm/dos/v86/messages/ru/makefile) | — | — |
| [base/mvdm/dos/v86/messages/sv](../../base/mvdm/dos/v86/messages/sv) | 8 | [base/mvdm/dos/v86/messages/sv/sources](../../base/mvdm/dos/v86/messages/sv/sources), [base/mvdm/dos/v86/messages/sv/makefile](../../base/mvdm/dos/v86/messages/sv/makefile) | — | — |
| [base/mvdm/dos/v86/messages/tr](../../base/mvdm/dos/v86/messages/tr) | 8 | [base/mvdm/dos/v86/messages/tr/sources](../../base/mvdm/dos/v86/messages/tr/sources), [base/mvdm/dos/v86/messages/tr/makefile](../../base/mvdm/dos/v86/messages/tr/makefile) | — | — |
| [base/mvdm/dos/v86/messages/usa](../../base/mvdm/dos/v86/messages/usa) | 5 | — | — | — |
| [base/mvdm/dos/v86/publish](../../base/mvdm/dos/v86/publish) | 2 | [base/mvdm/dos/v86/publish/sources](../../base/mvdm/dos/v86/publish/sources), [base/mvdm/dos/v86/publish/makefile](../../base/mvdm/dos/v86/publish/makefile) | — | `LIBRARY` |
| [base/mvdm/dos/v86/redir](../../base/mvdm/dos/v86/redir) | 21 | [base/mvdm/dos/v86/redir/dirs](../../base/mvdm/dos/v86/redir/dirs) | — | — |
| [base/mvdm/dos/v86/redir/br](../../base/mvdm/dos/v86/redir/br) | 4 | [base/mvdm/dos/v86/redir/br/sources](../../base/mvdm/dos/v86/redir/br/sources), [base/mvdm/dos/v86/redir/br/makefile](../../base/mvdm/dos/v86/redir/br/makefile) | — | — |
| [base/mvdm/dos/v86/redir/chp](../../base/mvdm/dos/v86/redir/chp) | 4 | [base/mvdm/dos/v86/redir/chp/sources](../../base/mvdm/dos/v86/redir/chp/sources), [base/mvdm/dos/v86/redir/chp/makefile](../../base/mvdm/dos/v86/redir/chp/makefile) | — | — |
| [base/mvdm/dos/v86/redir/chs](../../base/mvdm/dos/v86/redir/chs) | 4 | [base/mvdm/dos/v86/redir/chs/sources](../../base/mvdm/dos/v86/redir/chs/sources), [base/mvdm/dos/v86/redir/chs/makefile](../../base/mvdm/dos/v86/redir/chs/makefile) | — | — |
| [base/mvdm/dos/v86/redir/cht](../../base/mvdm/dos/v86/redir/cht) | 4 | [base/mvdm/dos/v86/redir/cht/sources](../../base/mvdm/dos/v86/redir/cht/sources), [base/mvdm/dos/v86/redir/cht/makefile](../../base/mvdm/dos/v86/redir/cht/makefile) | — | — |
| [base/mvdm/dos/v86/redir/cs](../../base/mvdm/dos/v86/redir/cs) | 4 | [base/mvdm/dos/v86/redir/cs/sources](../../base/mvdm/dos/v86/redir/cs/sources), [base/mvdm/dos/v86/redir/cs/makefile](../../base/mvdm/dos/v86/redir/cs/makefile) | — | — |
| [base/mvdm/dos/v86/redir/da](../../base/mvdm/dos/v86/redir/da) | 4 | [base/mvdm/dos/v86/redir/da/sources](../../base/mvdm/dos/v86/redir/da/sources), [base/mvdm/dos/v86/redir/da/makefile](../../base/mvdm/dos/v86/redir/da/makefile) | — | — |
| [base/mvdm/dos/v86/redir/el](../../base/mvdm/dos/v86/redir/el) | 4 | [base/mvdm/dos/v86/redir/el/sources](../../base/mvdm/dos/v86/redir/el/sources), [base/mvdm/dos/v86/redir/el/makefile](../../base/mvdm/dos/v86/redir/el/makefile) | — | — |
| [base/mvdm/dos/v86/redir/es](../../base/mvdm/dos/v86/redir/es) | 4 | [base/mvdm/dos/v86/redir/es/sources](../../base/mvdm/dos/v86/redir/es/sources), [base/mvdm/dos/v86/redir/es/makefile](../../base/mvdm/dos/v86/redir/es/makefile) | — | — |
| [base/mvdm/dos/v86/redir/fi](../../base/mvdm/dos/v86/redir/fi) | 4 | [base/mvdm/dos/v86/redir/fi/sources](../../base/mvdm/dos/v86/redir/fi/sources), [base/mvdm/dos/v86/redir/fi/makefile](../../base/mvdm/dos/v86/redir/fi/makefile) | — | — |
| [base/mvdm/dos/v86/redir/fr](../../base/mvdm/dos/v86/redir/fr) | 4 | [base/mvdm/dos/v86/redir/fr/sources](../../base/mvdm/dos/v86/redir/fr/sources), [base/mvdm/dos/v86/redir/fr/makefile](../../base/mvdm/dos/v86/redir/fr/makefile) | — | — |
| [base/mvdm/dos/v86/redir/ger](../../base/mvdm/dos/v86/redir/ger) | 4 | [base/mvdm/dos/v86/redir/ger/sources](../../base/mvdm/dos/v86/redir/ger/sources), [base/mvdm/dos/v86/redir/ger/makefile](../../base/mvdm/dos/v86/redir/ger/makefile) | — | — |
| [base/mvdm/dos/v86/redir/hu](../../base/mvdm/dos/v86/redir/hu) | 4 | [base/mvdm/dos/v86/redir/hu/sources](../../base/mvdm/dos/v86/redir/hu/sources), [base/mvdm/dos/v86/redir/hu/makefile](../../base/mvdm/dos/v86/redir/hu/makefile) | — | — |
| [base/mvdm/dos/v86/redir/it](../../base/mvdm/dos/v86/redir/it) | 4 | [base/mvdm/dos/v86/redir/it/sources](../../base/mvdm/dos/v86/redir/it/sources), [base/mvdm/dos/v86/redir/it/makefile](../../base/mvdm/dos/v86/redir/it/makefile) | — | — |
| [base/mvdm/dos/v86/redir/jpn](../../base/mvdm/dos/v86/redir/jpn) | 4 | [base/mvdm/dos/v86/redir/jpn/sources](../../base/mvdm/dos/v86/redir/jpn/sources), [base/mvdm/dos/v86/redir/jpn/makefile](../../base/mvdm/dos/v86/redir/jpn/makefile) | — | — |
| [base/mvdm/dos/v86/redir/kor](../../base/mvdm/dos/v86/redir/kor) | 4 | [base/mvdm/dos/v86/redir/kor/sources](../../base/mvdm/dos/v86/redir/kor/sources), [base/mvdm/dos/v86/redir/kor/makefile](../../base/mvdm/dos/v86/redir/kor/makefile) | — | — |
| [base/mvdm/dos/v86/redir/nec_98](../../base/mvdm/dos/v86/redir/nec_98) | 4 | [base/mvdm/dos/v86/redir/nec_98/sources](../../base/mvdm/dos/v86/redir/nec_98/sources), [base/mvdm/dos/v86/redir/nec_98/makefile](../../base/mvdm/dos/v86/redir/nec_98/makefile) | — | — |
| [base/mvdm/dos/v86/redir/nl](../../base/mvdm/dos/v86/redir/nl) | 4 | [base/mvdm/dos/v86/redir/nl/sources](../../base/mvdm/dos/v86/redir/nl/sources), [base/mvdm/dos/v86/redir/nl/makefile](../../base/mvdm/dos/v86/redir/nl/makefile) | — | — |
| [base/mvdm/dos/v86/redir/no](../../base/mvdm/dos/v86/redir/no) | 4 | [base/mvdm/dos/v86/redir/no/sources](../../base/mvdm/dos/v86/redir/no/sources), [base/mvdm/dos/v86/redir/no/makefile](../../base/mvdm/dos/v86/redir/no/makefile) | — | — |
| [base/mvdm/dos/v86/redir/pl](../../base/mvdm/dos/v86/redir/pl) | 4 | [base/mvdm/dos/v86/redir/pl/sources](../../base/mvdm/dos/v86/redir/pl/sources), [base/mvdm/dos/v86/redir/pl/makefile](../../base/mvdm/dos/v86/redir/pl/makefile) | — | — |
| [base/mvdm/dos/v86/redir/psu](../../base/mvdm/dos/v86/redir/psu) | 4 | [base/mvdm/dos/v86/redir/psu/sources](../../base/mvdm/dos/v86/redir/psu/sources), [base/mvdm/dos/v86/redir/psu/makefile](../../base/mvdm/dos/v86/redir/psu/makefile) | — | — |
| [base/mvdm/dos/v86/redir/pt](../../base/mvdm/dos/v86/redir/pt) | 4 | [base/mvdm/dos/v86/redir/pt/sources](../../base/mvdm/dos/v86/redir/pt/sources), [base/mvdm/dos/v86/redir/pt/makefile](../../base/mvdm/dos/v86/redir/pt/makefile) | — | — |
| [base/mvdm/dos/v86/redir/ru](../../base/mvdm/dos/v86/redir/ru) | 4 | [base/mvdm/dos/v86/redir/ru/sources](../../base/mvdm/dos/v86/redir/ru/sources), [base/mvdm/dos/v86/redir/ru/makefile](../../base/mvdm/dos/v86/redir/ru/makefile) | — | — |
| [base/mvdm/dos/v86/redir/sv](../../base/mvdm/dos/v86/redir/sv) | 4 | [base/mvdm/dos/v86/redir/sv/sources](../../base/mvdm/dos/v86/redir/sv/sources), [base/mvdm/dos/v86/redir/sv/makefile](../../base/mvdm/dos/v86/redir/sv/makefile) | — | — |
| [base/mvdm/dos/v86/redir/tr](../../base/mvdm/dos/v86/redir/tr) | 4 | [base/mvdm/dos/v86/redir/tr/sources](../../base/mvdm/dos/v86/redir/tr/sources), [base/mvdm/dos/v86/redir/tr/makefile](../../base/mvdm/dos/v86/redir/tr/makefile) | — | — |
| [base/mvdm/dos/v86/redir/tst](../../base/mvdm/dos/v86/redir/tst) | 4 | [base/mvdm/dos/v86/redir/tst/sources](../../base/mvdm/dos/v86/redir/tst/sources), [base/mvdm/dos/v86/redir/tst/makefile](../../base/mvdm/dos/v86/redir/tst/makefile) | — | — |
| [base/mvdm/dos/v86/redir/usa](../../base/mvdm/dos/v86/redir/usa) | 4 | [base/mvdm/dos/v86/redir/usa/sources](../../base/mvdm/dos/v86/redir/usa/sources), [base/mvdm/dos/v86/redir/usa/makefile](../../base/mvdm/dos/v86/redir/usa/makefile) | — | — |
| [base/mvdm/dos/v86/tools](../../base/mvdm/dos/v86/tools) | 5 | — | — | — |
| [base/mvdm/dos/v86/tools/src](../../base/mvdm/dos/v86/tools/src) | 0 | — | — | — |
| [base/mvdm/dos/v86/tools/src/buildidx](../../base/mvdm/dos/v86/tools/src/buildidx) | 4 | [base/mvdm/dos/v86/tools/src/buildidx/sources](../../base/mvdm/dos/v86/tools/src/buildidx/sources), [base/mvdm/dos/v86/tools/src/buildidx/makefile](../../base/mvdm/dos/v86/tools/src/buildidx/makefile) | `buildidx` | — |
| [base/mvdm/dos/v86/tools/src/getsize](../../base/mvdm/dos/v86/tools/src/getsize) | 4 | [base/mvdm/dos/v86/tools/src/getsize/sources](../../base/mvdm/dos/v86/tools/src/getsize/sources), [base/mvdm/dos/v86/tools/src/getsize/makefile](../../base/mvdm/dos/v86/tools/src/getsize/makefile) | `getsize` | — |
| [base/mvdm/dos/v86/tools/src/h2inc](../../base/mvdm/dos/v86/tools/src/h2inc) | 4 | — | — | — |
| [base/mvdm/dos/v86/tools/src/stripdd](../../base/mvdm/dos/v86/tools/src/stripdd) | 4 | [base/mvdm/dos/v86/tools/src/stripdd/sources](../../base/mvdm/dos/v86/tools/src/stripdd/sources), [base/mvdm/dos/v86/tools/src/stripdd/makefile](../../base/mvdm/dos/v86/tools/src/stripdd/makefile) | `stripdd` | — |
| [base/mvdm/dos/v86/tools/src/stripz](../../base/mvdm/dos/v86/tools/src/stripz) | 4 | [base/mvdm/dos/v86/tools/src/stripz/sources](../../base/mvdm/dos/v86/tools/src/stripz/sources), [base/mvdm/dos/v86/tools/src/stripz/makefile](../../base/mvdm/dos/v86/tools/src/stripz/makefile) | `stripz` | — |
| [base/mvdm/dpmi](../../base/mvdm/dpmi) | 48 | [base/mvdm/dpmi/dirs](../../base/mvdm/dpmi/dirs) | — | — |
| [base/mvdm/dpmi/br](../../base/mvdm/dpmi/br) | 4 | [base/mvdm/dpmi/br/sources](../../base/mvdm/dpmi/br/sources), [base/mvdm/dpmi/br/makefile](../../base/mvdm/dpmi/br/makefile) | — | — |
| [base/mvdm/dpmi/chp](../../base/mvdm/dpmi/chp) | 4 | [base/mvdm/dpmi/chp/sources](../../base/mvdm/dpmi/chp/sources), [base/mvdm/dpmi/chp/makefile](../../base/mvdm/dpmi/chp/makefile) | — | — |
| [base/mvdm/dpmi/chs](../../base/mvdm/dpmi/chs) | 4 | [base/mvdm/dpmi/chs/sources](../../base/mvdm/dpmi/chs/sources), [base/mvdm/dpmi/chs/makefile](../../base/mvdm/dpmi/chs/makefile) | — | — |
| [base/mvdm/dpmi/cht](../../base/mvdm/dpmi/cht) | 4 | [base/mvdm/dpmi/cht/sources](../../base/mvdm/dpmi/cht/sources), [base/mvdm/dpmi/cht/makefile](../../base/mvdm/dpmi/cht/makefile) | — | — |
| [base/mvdm/dpmi/cs](../../base/mvdm/dpmi/cs) | 4 | [base/mvdm/dpmi/cs/sources](../../base/mvdm/dpmi/cs/sources), [base/mvdm/dpmi/cs/makefile](../../base/mvdm/dpmi/cs/makefile) | — | — |
| [base/mvdm/dpmi/da](../../base/mvdm/dpmi/da) | 4 | [base/mvdm/dpmi/da/sources](../../base/mvdm/dpmi/da/sources), [base/mvdm/dpmi/da/makefile](../../base/mvdm/dpmi/da/makefile) | — | — |
| [base/mvdm/dpmi/el](../../base/mvdm/dpmi/el) | 4 | [base/mvdm/dpmi/el/sources](../../base/mvdm/dpmi/el/sources), [base/mvdm/dpmi/el/makefile](../../base/mvdm/dpmi/el/makefile) | — | — |
| [base/mvdm/dpmi/es](../../base/mvdm/dpmi/es) | 4 | [base/mvdm/dpmi/es/sources](../../base/mvdm/dpmi/es/sources), [base/mvdm/dpmi/es/makefile](../../base/mvdm/dpmi/es/makefile) | — | — |
| [base/mvdm/dpmi/fi](../../base/mvdm/dpmi/fi) | 4 | [base/mvdm/dpmi/fi/sources](../../base/mvdm/dpmi/fi/sources), [base/mvdm/dpmi/fi/makefile](../../base/mvdm/dpmi/fi/makefile) | — | — |
| [base/mvdm/dpmi/fr](../../base/mvdm/dpmi/fr) | 4 | [base/mvdm/dpmi/fr/sources](../../base/mvdm/dpmi/fr/sources), [base/mvdm/dpmi/fr/makefile](../../base/mvdm/dpmi/fr/makefile) | — | — |
| [base/mvdm/dpmi/ger](../../base/mvdm/dpmi/ger) | 4 | [base/mvdm/dpmi/ger/sources](../../base/mvdm/dpmi/ger/sources), [base/mvdm/dpmi/ger/makefile](../../base/mvdm/dpmi/ger/makefile) | — | — |
| [base/mvdm/dpmi/hu](../../base/mvdm/dpmi/hu) | 4 | [base/mvdm/dpmi/hu/sources](../../base/mvdm/dpmi/hu/sources), [base/mvdm/dpmi/hu/makefile](../../base/mvdm/dpmi/hu/makefile) | — | — |
| [base/mvdm/dpmi/it](../../base/mvdm/dpmi/it) | 4 | [base/mvdm/dpmi/it/sources](../../base/mvdm/dpmi/it/sources), [base/mvdm/dpmi/it/makefile](../../base/mvdm/dpmi/it/makefile) | — | — |
| [base/mvdm/dpmi/jpn](../../base/mvdm/dpmi/jpn) | 4 | [base/mvdm/dpmi/jpn/sources](../../base/mvdm/dpmi/jpn/sources), [base/mvdm/dpmi/jpn/makefile](../../base/mvdm/dpmi/jpn/makefile) | — | — |
| [base/mvdm/dpmi/kor](../../base/mvdm/dpmi/kor) | 4 | [base/mvdm/dpmi/kor/sources](../../base/mvdm/dpmi/kor/sources), [base/mvdm/dpmi/kor/makefile](../../base/mvdm/dpmi/kor/makefile) | — | — |
| [base/mvdm/dpmi/nec_98](../../base/mvdm/dpmi/nec_98) | 4 | [base/mvdm/dpmi/nec_98/sources](../../base/mvdm/dpmi/nec_98/sources), [base/mvdm/dpmi/nec_98/makefile](../../base/mvdm/dpmi/nec_98/makefile) | — | — |
| [base/mvdm/dpmi/nl](../../base/mvdm/dpmi/nl) | 4 | [base/mvdm/dpmi/nl/sources](../../base/mvdm/dpmi/nl/sources), [base/mvdm/dpmi/nl/makefile](../../base/mvdm/dpmi/nl/makefile) | — | — |
| [base/mvdm/dpmi/no](../../base/mvdm/dpmi/no) | 4 | [base/mvdm/dpmi/no/sources](../../base/mvdm/dpmi/no/sources), [base/mvdm/dpmi/no/makefile](../../base/mvdm/dpmi/no/makefile) | — | — |
| [base/mvdm/dpmi/pl](../../base/mvdm/dpmi/pl) | 4 | [base/mvdm/dpmi/pl/sources](../../base/mvdm/dpmi/pl/sources), [base/mvdm/dpmi/pl/makefile](../../base/mvdm/dpmi/pl/makefile) | — | — |
| [base/mvdm/dpmi/psu](../../base/mvdm/dpmi/psu) | 4 | [base/mvdm/dpmi/psu/sources](../../base/mvdm/dpmi/psu/sources), [base/mvdm/dpmi/psu/makefile](../../base/mvdm/dpmi/psu/makefile) | — | — |
| [base/mvdm/dpmi/pt](../../base/mvdm/dpmi/pt) | 4 | [base/mvdm/dpmi/pt/sources](../../base/mvdm/dpmi/pt/sources), [base/mvdm/dpmi/pt/makefile](../../base/mvdm/dpmi/pt/makefile) | — | — |
| [base/mvdm/dpmi/ru](../../base/mvdm/dpmi/ru) | 4 | [base/mvdm/dpmi/ru/sources](../../base/mvdm/dpmi/ru/sources), [base/mvdm/dpmi/ru/makefile](../../base/mvdm/dpmi/ru/makefile) | — | — |
| [base/mvdm/dpmi/sv](../../base/mvdm/dpmi/sv) | 4 | [base/mvdm/dpmi/sv/sources](../../base/mvdm/dpmi/sv/sources), [base/mvdm/dpmi/sv/makefile](../../base/mvdm/dpmi/sv/makefile) | — | — |
| [base/mvdm/dpmi/tr](../../base/mvdm/dpmi/tr) | 4 | [base/mvdm/dpmi/tr/sources](../../base/mvdm/dpmi/tr/sources), [base/mvdm/dpmi/tr/makefile](../../base/mvdm/dpmi/tr/makefile) | — | — |
| [base/mvdm/dpmi/tst](../../base/mvdm/dpmi/tst) | 4 | [base/mvdm/dpmi/tst/sources](../../base/mvdm/dpmi/tst/sources), [base/mvdm/dpmi/tst/makefile](../../base/mvdm/dpmi/tst/makefile) | — | — |
| [base/mvdm/dpmi/usa](../../base/mvdm/dpmi/usa) | 4 | [base/mvdm/dpmi/usa/sources](../../base/mvdm/dpmi/usa/sources), [base/mvdm/dpmi/usa/makefile](../../base/mvdm/dpmi/usa/makefile) | — | — |
| [base/mvdm/dpmi32](../../base/mvdm/dpmi32) | 25 | [base/mvdm/dpmi32/dirs](../../base/mvdm/dpmi32/dirs) | — | — |
| [base/mvdm/dpmi32/daytona](../../base/mvdm/dpmi32/daytona) | 3 | [base/mvdm/dpmi32/daytona/sources](../../base/mvdm/dpmi32/daytona/sources), [base/mvdm/dpmi32/daytona/makefile](../../base/mvdm/dpmi32/daytona/makefile) | — | — |
| [base/mvdm/dpmi32/fe](../../base/mvdm/dpmi32/fe) | 3 | [base/mvdm/dpmi32/fe/sources](../../base/mvdm/dpmi32/fe/sources), [base/mvdm/dpmi32/fe/makefile](../../base/mvdm/dpmi32/fe/makefile) | — | — |
| [base/mvdm/dpmi32/i386](../../base/mvdm/dpmi32/i386) | 2 | — | — | — |
| [base/mvdm/dpmi32/nec_98](../../base/mvdm/dpmi32/nec_98) | 3 | [base/mvdm/dpmi32/nec_98/sources](../../base/mvdm/dpmi32/nec_98/sources), [base/mvdm/dpmi32/nec_98/makefile](../../base/mvdm/dpmi32/nec_98/makefile) | — | — |
| [base/mvdm/fax](../../base/mvdm/fax) | 5 | [base/mvdm/fax/dirs](../../base/mvdm/fax/dirs) | — | — |
| [base/mvdm/fax/wowfax](../../base/mvdm/fax/wowfax) | 6 | [base/mvdm/fax/wowfax/sources](../../base/mvdm/fax/wowfax/sources), [base/mvdm/fax/wowfax/makefile](../../base/mvdm/fax/wowfax/makefile) | `wowfax` | `GDI_DRIVER` |
| [base/mvdm/fax/wowfaxui](../../base/mvdm/fax/wowfaxui) | 10 | [base/mvdm/fax/wowfaxui/dirs](../../base/mvdm/fax/wowfaxui/dirs) | — | — |
| [base/mvdm/fax/wowfaxui/daytona](../../base/mvdm/fax/wowfaxui/daytona) | 3 | [base/mvdm/fax/wowfaxui/daytona/sources](../../base/mvdm/fax/wowfaxui/daytona/sources), [base/mvdm/fax/wowfaxui/daytona/makefile](../../base/mvdm/fax/wowfaxui/daytona/makefile) | — | — |
| [base/mvdm/fax/wowfaxui/fe](../../base/mvdm/fax/wowfaxui/fe) | 3 | [base/mvdm/fax/wowfaxui/fe/sources](../../base/mvdm/fax/wowfaxui/fe/sources), [base/mvdm/fax/wowfaxui/fe/makefile](../../base/mvdm/fax/wowfaxui/fe/makefile) | — | — |
| [base/mvdm/inc](../../base/mvdm/inc) | 66 | [base/mvdm/inc/dirs](../../base/mvdm/inc/dirs) | — | — |
| [base/mvdm/inc/usa](../../base/mvdm/inc/usa) | 3 | [base/mvdm/inc/usa/sources](../../base/mvdm/inc/usa/sources), [base/mvdm/inc/usa/makefile](../../base/mvdm/inc/usa/makefile) | — | — |
| [base/mvdm/meinc](../../base/mvdm/meinc) | 57 | [base/mvdm/meinc/dirs](../../base/mvdm/meinc/dirs) | — | — |
| [base/mvdm/meinc/usa](../../base/mvdm/meinc/usa) | 3 | [base/mvdm/meinc/usa/sources](../../base/mvdm/meinc/usa/sources), [base/mvdm/meinc/usa/makefile](../../base/mvdm/meinc/usa/makefile) | — | — |
| [base/mvdm/oemuni](../../base/mvdm/oemuni) | 6 | [base/mvdm/oemuni/dirs](../../base/mvdm/oemuni/dirs) | — | — |
| [base/mvdm/oemuni/daytona](../../base/mvdm/oemuni/daytona) | 2 | [base/mvdm/oemuni/daytona/sources](../../base/mvdm/oemuni/daytona/sources), [base/mvdm/oemuni/daytona/makefile](../../base/mvdm/oemuni/daytona/makefile) | — | — |
| [base/mvdm/oemuni/fe](../../base/mvdm/oemuni/fe) | 2 | [base/mvdm/oemuni/fe/sources](../../base/mvdm/oemuni/fe/sources), [base/mvdm/oemuni/fe/makefile](../../base/mvdm/oemuni/fe/makefile) | — | — |
| [base/mvdm/oemuni/nec_98](../../base/mvdm/oemuni/nec_98) | 2 | [base/mvdm/oemuni/nec_98/sources](../../base/mvdm/oemuni/nec_98/sources), [base/mvdm/oemuni/nec_98/makefile](../../base/mvdm/oemuni/nec_98/makefile) | — | — |
| [base/mvdm/setup](../../base/mvdm/setup) | 5 | [base/mvdm/setup/sources](../../base/mvdm/setup/sources), [base/mvdm/setup/makefile](../../base/mvdm/setup/makefile) | — | `NOTARGET` |
| [base/mvdm/sim16](../../base/mvdm/sim16) | 8 | [base/mvdm/sim16/makefile](../../base/mvdm/sim16/makefile) | — | — |
| [base/mvdm/sim32](../../base/mvdm/sim32) | 5 | [base/mvdm/sim32/sources](../../base/mvdm/sim32/sources), [base/mvdm/sim32/makefile](../../base/mvdm/sim32/makefile) | `sim32` | `LIBRARY` |
| [base/mvdm/softpc.new](../../base/mvdm/softpc.new) | 1 | [base/mvdm/softpc.new/dirs](../../base/mvdm/softpc.new/dirs) | — | — |
| [base/mvdm/softpc.new/base](../../base/mvdm/softpc.new/base) | 2 | [base/mvdm/softpc.new/base/dirs](../../base/mvdm/softpc.new/base/dirs) | — | — |
| [base/mvdm/softpc.new/base/bios](../../base/mvdm/softpc.new/base/bios) | 17 | [base/mvdm/softpc.new/base/bios/dirs](../../base/mvdm/softpc.new/base/bios/dirs) | — | — |
| [base/mvdm/softpc.new/base/bios/chp](../../base/mvdm/softpc.new/base/bios/chp) | 2 | [base/mvdm/softpc.new/base/bios/chp/sources](../../base/mvdm/softpc.new/base/bios/chp/sources), [base/mvdm/softpc.new/base/bios/chp/makefile](../../base/mvdm/softpc.new/base/bios/chp/makefile) | — | — |
| [base/mvdm/softpc.new/base/bios/chs](../../base/mvdm/softpc.new/base/bios/chs) | 2 | [base/mvdm/softpc.new/base/bios/chs/sources](../../base/mvdm/softpc.new/base/bios/chs/sources), [base/mvdm/softpc.new/base/bios/chs/makefile](../../base/mvdm/softpc.new/base/bios/chs/makefile) | — | — |
| [base/mvdm/softpc.new/base/bios/cht](../../base/mvdm/softpc.new/base/bios/cht) | 2 | [base/mvdm/softpc.new/base/bios/cht/sources](../../base/mvdm/softpc.new/base/bios/cht/sources), [base/mvdm/softpc.new/base/bios/cht/makefile](../../base/mvdm/softpc.new/base/bios/cht/makefile) | — | — |
| [base/mvdm/softpc.new/base/bios/daytona](../../base/mvdm/softpc.new/base/bios/daytona) | 2 | [base/mvdm/softpc.new/base/bios/daytona/sources](../../base/mvdm/softpc.new/base/bios/daytona/sources), [base/mvdm/softpc.new/base/bios/daytona/makefile](../../base/mvdm/softpc.new/base/bios/daytona/makefile) | — | — |
| [base/mvdm/softpc.new/base/bios/jpn](../../base/mvdm/softpc.new/base/bios/jpn) | 2 | [base/mvdm/softpc.new/base/bios/jpn/sources](../../base/mvdm/softpc.new/base/bios/jpn/sources), [base/mvdm/softpc.new/base/bios/jpn/makefile](../../base/mvdm/softpc.new/base/bios/jpn/makefile) | — | — |
| [base/mvdm/softpc.new/base/bios/kor](../../base/mvdm/softpc.new/base/bios/kor) | 2 | [base/mvdm/softpc.new/base/bios/kor/sources](../../base/mvdm/softpc.new/base/bios/kor/sources), [base/mvdm/softpc.new/base/bios/kor/makefile](../../base/mvdm/softpc.new/base/bios/kor/makefile) | — | — |
| [base/mvdm/softpc.new/base/bios/nec_98](../../base/mvdm/softpc.new/base/bios/nec_98) | 2 | [base/mvdm/softpc.new/base/bios/nec_98/sources](../../base/mvdm/softpc.new/base/bios/nec_98/sources), [base/mvdm/softpc.new/base/bios/nec_98/makefile](../../base/mvdm/softpc.new/base/bios/nec_98/makefile) | — | — |
| [base/mvdm/softpc.new/base/ccpu386](../../base/mvdm/softpc.new/base/ccpu386) | 274 | [base/mvdm/softpc.new/base/ccpu386/sources](../../base/mvdm/softpc.new/base/ccpu386/sources), [base/mvdm/softpc.new/base/ccpu386/makefile](../../base/mvdm/softpc.new/base/ccpu386/makefile) | `ccpu386` | `LIBRARY` |
| [base/mvdm/softpc.new/base/comms](../../base/mvdm/softpc.new/base/comms) | 7 | [base/mvdm/softpc.new/base/comms/dirs](../../base/mvdm/softpc.new/base/comms/dirs) | — | — |
| [base/mvdm/softpc.new/base/comms/daytona](../../base/mvdm/softpc.new/base/comms/daytona) | 2 | [base/mvdm/softpc.new/base/comms/daytona/sources](../../base/mvdm/softpc.new/base/comms/daytona/sources), [base/mvdm/softpc.new/base/comms/daytona/makefile](../../base/mvdm/softpc.new/base/comms/daytona/makefile) | — | — |
| [base/mvdm/softpc.new/base/comms/nec_98](../../base/mvdm/softpc.new/base/comms/nec_98) | 2 | [base/mvdm/softpc.new/base/comms/nec_98/sources](../../base/mvdm/softpc.new/base/comms/nec_98/sources), [base/mvdm/softpc.new/base/comms/nec_98/makefile](../../base/mvdm/softpc.new/base/comms/nec_98/makefile) | — | — |
| [base/mvdm/softpc.new/base/cpu](../../base/mvdm/softpc.new/base/cpu) | 0 | — | — | — |
| [base/mvdm/softpc.new/base/cpu/src](../../base/mvdm/softpc.new/base/cpu/src) | 0 | — | — | — |
| [base/mvdm/softpc.new/base/cpu/src/evid](../../base/mvdm/softpc.new/base/cpu/src/evid) | 3 | — | — | — |
| [base/mvdm/softpc.new/base/cvidc](../../base/mvdm/softpc.new/base/cvidc) | 145 | [base/mvdm/softpc.new/base/cvidc/sources](../../base/mvdm/softpc.new/base/cvidc/sources), [base/mvdm/softpc.new/base/cvidc/makefile](../../base/mvdm/softpc.new/base/cvidc/makefile) | `Cvidc` | `LIBRARY` |
| [base/mvdm/softpc.new/base/dasm386](../../base/mvdm/softpc.new/base/dasm386) | 5 | [base/mvdm/softpc.new/base/dasm386/sources](../../base/mvdm/softpc.new/base/dasm386/sources), [base/mvdm/softpc.new/base/dasm386/makefile](../../base/mvdm/softpc.new/base/dasm386/makefile) | `dasm386` | `LIBRARY` |
| [base/mvdm/softpc.new/base/debug](../../base/mvdm/softpc.new/base/debug) | 11 | [base/mvdm/softpc.new/base/debug/dirs](../../base/mvdm/softpc.new/base/debug/dirs) | — | — |
| [base/mvdm/softpc.new/base/debug/daytona](../../base/mvdm/softpc.new/base/debug/daytona) | 2 | [base/mvdm/softpc.new/base/debug/daytona/sources](../../base/mvdm/softpc.new/base/debug/daytona/sources), [base/mvdm/softpc.new/base/debug/daytona/makefile](../../base/mvdm/softpc.new/base/debug/daytona/makefile) | — | — |
| [base/mvdm/softpc.new/base/debug/nec_98](../../base/mvdm/softpc.new/base/debug/nec_98) | 2 | [base/mvdm/softpc.new/base/debug/nec_98/sources](../../base/mvdm/softpc.new/base/debug/nec_98/sources), [base/mvdm/softpc.new/base/debug/nec_98/makefile](../../base/mvdm/softpc.new/base/debug/nec_98/makefile) | — | — |
| [base/mvdm/softpc.new/base/disks](../../base/mvdm/softpc.new/base/disks) | 12 | [base/mvdm/softpc.new/base/disks/dirs](../../base/mvdm/softpc.new/base/disks/dirs) | — | — |
| [base/mvdm/softpc.new/base/disks/daytona](../../base/mvdm/softpc.new/base/disks/daytona) | 2 | [base/mvdm/softpc.new/base/disks/daytona/sources](../../base/mvdm/softpc.new/base/disks/daytona/sources), [base/mvdm/softpc.new/base/disks/daytona/makefile](../../base/mvdm/softpc.new/base/disks/daytona/makefile) | — | — |
| [base/mvdm/softpc.new/base/disks/nec_98](../../base/mvdm/softpc.new/base/disks/nec_98) | 2 | [base/mvdm/softpc.new/base/disks/nec_98/sources](../../base/mvdm/softpc.new/base/disks/nec_98/sources), [base/mvdm/softpc.new/base/disks/nec_98/makefile](../../base/mvdm/softpc.new/base/disks/nec_98/makefile) | — | — |
| [base/mvdm/softpc.new/base/dos](../../base/mvdm/softpc.new/base/dos) | 3 | [base/mvdm/softpc.new/base/dos/dirs](../../base/mvdm/softpc.new/base/dos/dirs) | — | — |
| [base/mvdm/softpc.new/base/dos/daytona](../../base/mvdm/softpc.new/base/dos/daytona) | 2 | [base/mvdm/softpc.new/base/dos/daytona/sources](../../base/mvdm/softpc.new/base/dos/daytona/sources), [base/mvdm/softpc.new/base/dos/daytona/makefile](../../base/mvdm/softpc.new/base/dos/daytona/makefile) | — | — |
| [base/mvdm/softpc.new/base/dos/nec_98](../../base/mvdm/softpc.new/base/dos/nec_98) | 2 | [base/mvdm/softpc.new/base/dos/nec_98/sources](../../base/mvdm/softpc.new/base/dos/nec_98/sources), [base/mvdm/softpc.new/base/dos/nec_98/makefile](../../base/mvdm/softpc.new/base/dos/nec_98/makefile) | — | — |
| [base/mvdm/softpc.new/base/inc](../../base/mvdm/softpc.new/base/inc) | 161 | — | — | — |
| [base/mvdm/softpc.new/base/keymouse](../../base/mvdm/softpc.new/base/keymouse) | 7 | [base/mvdm/softpc.new/base/keymouse/dirs](../../base/mvdm/softpc.new/base/keymouse/dirs) | — | — |
| [base/mvdm/softpc.new/base/keymouse/chp](../../base/mvdm/softpc.new/base/keymouse/chp) | 2 | [base/mvdm/softpc.new/base/keymouse/chp/sources](../../base/mvdm/softpc.new/base/keymouse/chp/sources), [base/mvdm/softpc.new/base/keymouse/chp/makefile](../../base/mvdm/softpc.new/base/keymouse/chp/makefile) | — | — |
| [base/mvdm/softpc.new/base/keymouse/chs](../../base/mvdm/softpc.new/base/keymouse/chs) | 2 | [base/mvdm/softpc.new/base/keymouse/chs/sources](../../base/mvdm/softpc.new/base/keymouse/chs/sources), [base/mvdm/softpc.new/base/keymouse/chs/makefile](../../base/mvdm/softpc.new/base/keymouse/chs/makefile) | — | — |
| [base/mvdm/softpc.new/base/keymouse/cht](../../base/mvdm/softpc.new/base/keymouse/cht) | 2 | [base/mvdm/softpc.new/base/keymouse/cht/sources](../../base/mvdm/softpc.new/base/keymouse/cht/sources), [base/mvdm/softpc.new/base/keymouse/cht/makefile](../../base/mvdm/softpc.new/base/keymouse/cht/makefile) | — | — |
| [base/mvdm/softpc.new/base/keymouse/daytona](../../base/mvdm/softpc.new/base/keymouse/daytona) | 2 | [base/mvdm/softpc.new/base/keymouse/daytona/sources](../../base/mvdm/softpc.new/base/keymouse/daytona/sources), [base/mvdm/softpc.new/base/keymouse/daytona/makefile](../../base/mvdm/softpc.new/base/keymouse/daytona/makefile) | — | — |
| [base/mvdm/softpc.new/base/keymouse/jpn](../../base/mvdm/softpc.new/base/keymouse/jpn) | 2 | [base/mvdm/softpc.new/base/keymouse/jpn/sources](../../base/mvdm/softpc.new/base/keymouse/jpn/sources), [base/mvdm/softpc.new/base/keymouse/jpn/makefile](../../base/mvdm/softpc.new/base/keymouse/jpn/makefile) | — | — |
| [base/mvdm/softpc.new/base/keymouse/kor](../../base/mvdm/softpc.new/base/keymouse/kor) | 2 | [base/mvdm/softpc.new/base/keymouse/kor/sources](../../base/mvdm/softpc.new/base/keymouse/kor/sources), [base/mvdm/softpc.new/base/keymouse/kor/makefile](../../base/mvdm/softpc.new/base/keymouse/kor/makefile) | — | — |
| [base/mvdm/softpc.new/base/keymouse/nec_98](../../base/mvdm/softpc.new/base/keymouse/nec_98) | 2 | [base/mvdm/softpc.new/base/keymouse/nec_98/sources](../../base/mvdm/softpc.new/base/keymouse/nec_98/sources), [base/mvdm/softpc.new/base/keymouse/nec_98/makefile](../../base/mvdm/softpc.new/base/keymouse/nec_98/makefile) | — | — |
| [base/mvdm/softpc.new/base/support](../../base/mvdm/softpc.new/base/support) | 8 | [base/mvdm/softpc.new/base/support/dirs](../../base/mvdm/softpc.new/base/support/dirs) | — | — |
| [base/mvdm/softpc.new/base/support/daytona](../../base/mvdm/softpc.new/base/support/daytona) | 2 | [base/mvdm/softpc.new/base/support/daytona/sources](../../base/mvdm/softpc.new/base/support/daytona/sources), [base/mvdm/softpc.new/base/support/daytona/makefile](../../base/mvdm/softpc.new/base/support/daytona/makefile) | — | — |
| [base/mvdm/softpc.new/base/support/nec_98](../../base/mvdm/softpc.new/base/support/nec_98) | 2 | [base/mvdm/softpc.new/base/support/nec_98/sources](../../base/mvdm/softpc.new/base/support/nec_98/sources), [base/mvdm/softpc.new/base/support/nec_98/makefile](../../base/mvdm/softpc.new/base/support/nec_98/makefile) | — | — |
| [base/mvdm/softpc.new/base/system](../../base/mvdm/softpc.new/base/system) | 16 | [base/mvdm/softpc.new/base/system/dirs](../../base/mvdm/softpc.new/base/system/dirs) | — | — |
| [base/mvdm/softpc.new/base/system/daytona](../../base/mvdm/softpc.new/base/system/daytona) | 2 | [base/mvdm/softpc.new/base/system/daytona/sources](../../base/mvdm/softpc.new/base/system/daytona/sources), [base/mvdm/softpc.new/base/system/daytona/makefile](../../base/mvdm/softpc.new/base/system/daytona/makefile) | — | — |
| [base/mvdm/softpc.new/base/system/nec_98](../../base/mvdm/softpc.new/base/system/nec_98) | 2 | [base/mvdm/softpc.new/base/system/nec_98/sources](../../base/mvdm/softpc.new/base/system/nec_98/sources), [base/mvdm/softpc.new/base/system/nec_98/makefile](../../base/mvdm/softpc.new/base/system/nec_98/makefile) | — | — |
| [base/mvdm/softpc.new/base/unix](../../base/mvdm/softpc.new/base/unix) | 2 | [base/mvdm/softpc.new/base/unix/sources](../../base/mvdm/softpc.new/base/unix/sources), [base/mvdm/softpc.new/base/unix/makefile](../../base/mvdm/softpc.new/base/unix/makefile) | `unix` | `LIBRARY` |
| [base/mvdm/softpc.new/base/video](../../base/mvdm/softpc.new/base/video) | 26 | [base/mvdm/softpc.new/base/video/dirs](../../base/mvdm/softpc.new/base/video/dirs) | — | — |
| [base/mvdm/softpc.new/base/video/chp](../../base/mvdm/softpc.new/base/video/chp) | 2 | [base/mvdm/softpc.new/base/video/chp/sources](../../base/mvdm/softpc.new/base/video/chp/sources), [base/mvdm/softpc.new/base/video/chp/makefile](../../base/mvdm/softpc.new/base/video/chp/makefile) | — | — |
| [base/mvdm/softpc.new/base/video/chs](../../base/mvdm/softpc.new/base/video/chs) | 2 | [base/mvdm/softpc.new/base/video/chs/sources](../../base/mvdm/softpc.new/base/video/chs/sources), [base/mvdm/softpc.new/base/video/chs/makefile](../../base/mvdm/softpc.new/base/video/chs/makefile) | — | — |
| [base/mvdm/softpc.new/base/video/cht](../../base/mvdm/softpc.new/base/video/cht) | 2 | [base/mvdm/softpc.new/base/video/cht/sources](../../base/mvdm/softpc.new/base/video/cht/sources), [base/mvdm/softpc.new/base/video/cht/makefile](../../base/mvdm/softpc.new/base/video/cht/makefile) | — | — |
| [base/mvdm/softpc.new/base/video/daytona](../../base/mvdm/softpc.new/base/video/daytona) | 2 | [base/mvdm/softpc.new/base/video/daytona/sources](../../base/mvdm/softpc.new/base/video/daytona/sources), [base/mvdm/softpc.new/base/video/daytona/makefile](../../base/mvdm/softpc.new/base/video/daytona/makefile) | — | — |
| [base/mvdm/softpc.new/base/video/i386](../../base/mvdm/softpc.new/base/video/i386) | 1 | — | — | — |
| [base/mvdm/softpc.new/base/video/jpn](../../base/mvdm/softpc.new/base/video/jpn) | 2 | [base/mvdm/softpc.new/base/video/jpn/sources](../../base/mvdm/softpc.new/base/video/jpn/sources), [base/mvdm/softpc.new/base/video/jpn/makefile](../../base/mvdm/softpc.new/base/video/jpn/makefile) | — | — |
| [base/mvdm/softpc.new/base/video/kor](../../base/mvdm/softpc.new/base/video/kor) | 2 | [base/mvdm/softpc.new/base/video/kor/sources](../../base/mvdm/softpc.new/base/video/kor/sources), [base/mvdm/softpc.new/base/video/kor/makefile](../../base/mvdm/softpc.new/base/video/kor/makefile) | — | — |
| [base/mvdm/softpc.new/base/video/nec_98](../../base/mvdm/softpc.new/base/video/nec_98) | 2 | [base/mvdm/softpc.new/base/video/nec_98/sources](../../base/mvdm/softpc.new/base/video/nec_98/sources), [base/mvdm/softpc.new/base/video/nec_98/makefile](../../base/mvdm/softpc.new/base/video/nec_98/makefile) | — | — |
| [base/mvdm/softpc.new/bios](../../base/mvdm/softpc.new/bios) | 27 | [base/mvdm/softpc.new/bios/makefile](../../base/mvdm/softpc.new/bios/makefile) | — | — |
| [base/mvdm/softpc.new/convert](../../base/mvdm/softpc.new/convert) | 2 | [base/mvdm/softpc.new/convert/sources](../../base/mvdm/softpc.new/convert/sources) | `convert` | `PROGRAM` |
| [base/mvdm/softpc.new/dat2obj](../../base/mvdm/softpc.new/dat2obj) | 3 | [base/mvdm/softpc.new/dat2obj/sources](../../base/mvdm/softpc.new/dat2obj/sources), [base/mvdm/softpc.new/dat2obj/makefile](../../base/mvdm/softpc.new/dat2obj/makefile) | `dat2obj` | `PROGRAM` |
| [base/mvdm/softpc.new/data](../../base/mvdm/softpc.new/data) | 7 | [base/mvdm/softpc.new/data/sources](../../base/mvdm/softpc.new/data/sources), [base/mvdm/softpc.new/data/makefile](../../base/mvdm/softpc.new/data/makefile) | `foo` | `NOTARGET` |
| [base/mvdm/softpc.new/debugger](../../base/mvdm/softpc.new/debugger) | 3 | [base/mvdm/softpc.new/debugger/sources](../../base/mvdm/softpc.new/debugger/sources), [base/mvdm/softpc.new/debugger/makefile](../../base/mvdm/softpc.new/debugger/makefile) | `vdmdebug` | `PROGRAM` |
| [base/mvdm/softpc.new/host](../../base/mvdm/softpc.new/host) | 1 | [base/mvdm/softpc.new/host/dirs](../../base/mvdm/softpc.new/host/dirs) | — | — |
| [base/mvdm/softpc.new/host/inc](../../base/mvdm/softpc.new/host/inc) | 55 | — | — | — |
| [base/mvdm/softpc.new/host/link](../../base/mvdm/softpc.new/host/link) | 8 | [base/mvdm/softpc.new/host/link/sources](../../base/mvdm/softpc.new/host/link/sources), [base/mvdm/softpc.new/host/link/makefile](../../base/mvdm/softpc.new/host/link/makefile) | `resource` | `LIBRARY` |
| [base/mvdm/softpc.new/host/src](../../base/mvdm/softpc.new/host/src) | 68 | [base/mvdm/softpc.new/host/src/dirs](../../base/mvdm/softpc.new/host/src/dirs) | — | — |
| [base/mvdm/softpc.new/host/src/chp](../../base/mvdm/softpc.new/host/src/chp) | 2 | [base/mvdm/softpc.new/host/src/chp/sources](../../base/mvdm/softpc.new/host/src/chp/sources), [base/mvdm/softpc.new/host/src/chp/makefile](../../base/mvdm/softpc.new/host/src/chp/makefile) | — | — |
| [base/mvdm/softpc.new/host/src/chs](../../base/mvdm/softpc.new/host/src/chs) | 2 | [base/mvdm/softpc.new/host/src/chs/sources](../../base/mvdm/softpc.new/host/src/chs/sources), [base/mvdm/softpc.new/host/src/chs/makefile](../../base/mvdm/softpc.new/host/src/chs/makefile) | — | — |
| [base/mvdm/softpc.new/host/src/cht](../../base/mvdm/softpc.new/host/src/cht) | 2 | [base/mvdm/softpc.new/host/src/cht/sources](../../base/mvdm/softpc.new/host/src/cht/sources), [base/mvdm/softpc.new/host/src/cht/makefile](../../base/mvdm/softpc.new/host/src/cht/makefile) | — | — |
| [base/mvdm/softpc.new/host/src/daytona](../../base/mvdm/softpc.new/host/src/daytona) | 2 | [base/mvdm/softpc.new/host/src/daytona/sources](../../base/mvdm/softpc.new/host/src/daytona/sources), [base/mvdm/softpc.new/host/src/daytona/makefile](../../base/mvdm/softpc.new/host/src/daytona/makefile) | — | — |
| [base/mvdm/softpc.new/host/src/jpn](../../base/mvdm/softpc.new/host/src/jpn) | 2 | [base/mvdm/softpc.new/host/src/jpn/sources](../../base/mvdm/softpc.new/host/src/jpn/sources), [base/mvdm/softpc.new/host/src/jpn/makefile](../../base/mvdm/softpc.new/host/src/jpn/makefile) | — | — |
| [base/mvdm/softpc.new/host/src/kor](../../base/mvdm/softpc.new/host/src/kor) | 2 | [base/mvdm/softpc.new/host/src/kor/sources](../../base/mvdm/softpc.new/host/src/kor/sources), [base/mvdm/softpc.new/host/src/kor/makefile](../../base/mvdm/softpc.new/host/src/kor/makefile) | — | — |
| [base/mvdm/softpc.new/host/src/nec_98](../../base/mvdm/softpc.new/host/src/nec_98) | 2 | [base/mvdm/softpc.new/host/src/nec_98/sources](../../base/mvdm/softpc.new/host/src/nec_98/sources), [base/mvdm/softpc.new/host/src/nec_98/makefile](../../base/mvdm/softpc.new/host/src/nec_98/makefile) | — | — |
| [base/mvdm/softpc.new/obj.vdm](../../base/mvdm/softpc.new/obj.vdm) | 11 | [base/mvdm/softpc.new/obj.vdm/dirs](../../base/mvdm/softpc.new/obj.vdm/dirs) | — | — |
| [base/mvdm/softpc.new/obj.vdm/chp](../../base/mvdm/softpc.new/obj.vdm/chp) | 3 | [base/mvdm/softpc.new/obj.vdm/chp/sources](../../base/mvdm/softpc.new/obj.vdm/chp/sources), [base/mvdm/softpc.new/obj.vdm/chp/makefile](../../base/mvdm/softpc.new/obj.vdm/chp/makefile) | — | — |
| [base/mvdm/softpc.new/obj.vdm/chs](../../base/mvdm/softpc.new/obj.vdm/chs) | 3 | [base/mvdm/softpc.new/obj.vdm/chs/sources](../../base/mvdm/softpc.new/obj.vdm/chs/sources), [base/mvdm/softpc.new/obj.vdm/chs/makefile](../../base/mvdm/softpc.new/obj.vdm/chs/makefile) | — | — |
| [base/mvdm/softpc.new/obj.vdm/cht](../../base/mvdm/softpc.new/obj.vdm/cht) | 3 | [base/mvdm/softpc.new/obj.vdm/cht/sources](../../base/mvdm/softpc.new/obj.vdm/cht/sources), [base/mvdm/softpc.new/obj.vdm/cht/makefile](../../base/mvdm/softpc.new/obj.vdm/cht/makefile) | — | — |
| [base/mvdm/softpc.new/obj.vdm/daytona](../../base/mvdm/softpc.new/obj.vdm/daytona) | 3 | [base/mvdm/softpc.new/obj.vdm/daytona/sources](../../base/mvdm/softpc.new/obj.vdm/daytona/sources), [base/mvdm/softpc.new/obj.vdm/daytona/makefile](../../base/mvdm/softpc.new/obj.vdm/daytona/makefile) | — | — |
| [base/mvdm/softpc.new/obj.vdm/jpn](../../base/mvdm/softpc.new/obj.vdm/jpn) | 3 | [base/mvdm/softpc.new/obj.vdm/jpn/sources](../../base/mvdm/softpc.new/obj.vdm/jpn/sources), [base/mvdm/softpc.new/obj.vdm/jpn/makefile](../../base/mvdm/softpc.new/obj.vdm/jpn/makefile) | — | — |
| [base/mvdm/softpc.new/obj.vdm/kor](../../base/mvdm/softpc.new/obj.vdm/kor) | 3 | [base/mvdm/softpc.new/obj.vdm/kor/sources](../../base/mvdm/softpc.new/obj.vdm/kor/sources), [base/mvdm/softpc.new/obj.vdm/kor/makefile](../../base/mvdm/softpc.new/obj.vdm/kor/makefile) | — | — |
| [base/mvdm/softpc.new/obj.vdm/nec_98](../../base/mvdm/softpc.new/obj.vdm/nec_98) | 3 | [base/mvdm/softpc.new/obj.vdm/nec_98/sources](../../base/mvdm/softpc.new/obj.vdm/nec_98/sources), [base/mvdm/softpc.new/obj.vdm/nec_98/makefile](../../base/mvdm/softpc.new/obj.vdm/nec_98/makefile) | — | — |
| [base/mvdm/softpc.new/rename](../../base/mvdm/softpc.new/rename) | 2 | [base/mvdm/softpc.new/rename/sources](../../base/mvdm/softpc.new/rename/sources) | `rename` | `PROGRAM` |
| [base/mvdm/softpc.new/roms](../../base/mvdm/softpc.new/roms) | 8 | — | — | — |
| [base/mvdm/suballoc](../../base/mvdm/suballoc) | 8 | [base/mvdm/suballoc/sources](../../base/mvdm/suballoc/sources), [base/mvdm/suballoc/makefile](../../base/mvdm/suballoc/makefile) | `suballoc` | `LIBRARY` |
| [base/mvdm/thunk](../../base/mvdm/thunk) | 120 | [base/mvdm/thunk/dirs](../../base/mvdm/thunk/dirs) | — | — |
| [base/mvdm/thunk/me](../../base/mvdm/thunk/me) | 3 | [base/mvdm/thunk/me/sources](../../base/mvdm/thunk/me/sources), [base/mvdm/thunk/me/makefile](../../base/mvdm/thunk/me/makefile) | — | — |
| [base/mvdm/thunk/meow](../../base/mvdm/thunk/meow) | 3 | [base/mvdm/thunk/meow/sources](../../base/mvdm/thunk/meow/sources), [base/mvdm/thunk/meow/makefile](../../base/mvdm/thunk/meow/makefile) | — | — |
| [base/mvdm/thunk/usa](../../base/mvdm/thunk/usa) | 3 | [base/mvdm/thunk/usa/sources](../../base/mvdm/thunk/usa/sources), [base/mvdm/thunk/usa/makefile](../../base/mvdm/thunk/usa/makefile) | — | — |
| [base/mvdm/thunk/user](../../base/mvdm/thunk/user) | 8 | — | — | — |
| [base/mvdm/tools](../../base/mvdm/tools) | 8 | — | — | — |
| [base/mvdm/tools.os2](../../base/mvdm/tools.os2) | 4 | — | — | — |
| [base/mvdm/tools/c1032](../../base/mvdm/tools/c1032) | 0 | — | — | — |
| [base/mvdm/tools/c1032/bin](../../base/mvdm/tools/c1032/bin) | 40 | — | — | — |
| [base/mvdm/tools/c1032/inc](../../base/mvdm/tools/c1032/inc) | 104 | — | — | — |
| [base/mvdm/tools/c1032/lib](../../base/mvdm/tools/c1032/lib) | 36 | — | — | — |
| [base/mvdm/tools/c816](../../base/mvdm/tools/c816) | 0 | — | — | — |
| [base/mvdm/tools/c816/bin](../../base/mvdm/tools/c816/bin) | 44 | — | — | — |
| [base/mvdm/tools/c816/inc](../../base/mvdm/tools/c816/inc) | 45 | — | — | — |
| [base/mvdm/tools/c816/inc/sys](../../base/mvdm/tools/c816/inc/sys) | 5 | — | — | — |
| [base/mvdm/tools/c816/lib](../../base/mvdm/tools/c816/lib) | 39 | — | — | — |
| [base/mvdm/tools/c932](../../base/mvdm/tools/c932) | 0 | — | — | — |
| [base/mvdm/tools/c932/bin](../../base/mvdm/tools/c932/bin) | 35 | — | — | — |
| [base/mvdm/tools/c932/inc](../../base/mvdm/tools/c932/inc) | 109 | — | — | — |
| [base/mvdm/tools/c932/lib](../../base/mvdm/tools/c932/lib) | 34 | — | — | — |
| [base/mvdm/tools/masm61](../../base/mvdm/tools/masm61) | 9 | — | — | — |
| [base/mvdm/tools/rc40](../../base/mvdm/tools/rc40) | 2 | — | — | — |
| [base/mvdm/v86](../../base/mvdm/v86) | 1 | [base/mvdm/v86/dirs](../../base/mvdm/v86/dirs) | — | — |
| [base/mvdm/v86/monitor](../../base/mvdm/v86/monitor) | 2 | [base/mvdm/v86/monitor/dirs](../../base/mvdm/v86/monitor/dirs) | — | — |
| [base/mvdm/v86/monitor/daytona](../../base/mvdm/v86/monitor/daytona) | 2 | [base/mvdm/v86/monitor/daytona/sources](../../base/mvdm/v86/monitor/daytona/sources), [base/mvdm/v86/monitor/daytona/makefile](../../base/mvdm/v86/monitor/daytona/makefile) | — | — |
| [base/mvdm/v86/monitor/i386](../../base/mvdm/v86/monitor/i386) | 9 | — | — | — |
| [base/mvdm/v86/monitor/nec_98](../../base/mvdm/v86/monitor/nec_98) | 2 | [base/mvdm/v86/monitor/nec_98/sources](../../base/mvdm/v86/monitor/nec_98/sources), [base/mvdm/v86/monitor/nec_98/makefile](../../base/mvdm/v86/monitor/nec_98/makefile) | — | — |
| [base/mvdm/v86/scaffold](../../base/mvdm/v86/scaffold) | 6 | [base/mvdm/v86/scaffold/sources](../../base/mvdm/v86/scaffold/sources), [base/mvdm/v86/scaffold/makefile](../../base/mvdm/v86/scaffold/makefile) | `ntvdm` | `PROGLIB` |
| [base/mvdm/v86/scaffold/i386](../../base/mvdm/v86/scaffold/i386) | 15 | [base/mvdm/v86/scaffold/i386/sources](../../base/mvdm/v86/scaffold/i386/sources) | — | — |
| [base/mvdm/v86/util](../../base/mvdm/v86/util) | 2 | [base/mvdm/v86/util/makefile](../../base/mvdm/v86/util/makefile) | — | — |
| [base/mvdm/vdd](../../base/mvdm/vdd) | 2 | [base/mvdm/vdd/dirs](../../base/mvdm/vdd/dirs) | — | — |
| [base/mvdm/vdd/hpscan](../../base/mvdm/vdd/hpscan) | 5 | [base/mvdm/vdd/hpscan/dirs](../../base/mvdm/vdd/hpscan/dirs) | — | — |
| [base/mvdm/vdd/hpscan/usa](../../base/mvdm/vdd/hpscan/usa) | 3 | [base/mvdm/vdd/hpscan/usa/sources](../../base/mvdm/vdd/hpscan/usa/sources), [base/mvdm/vdd/hpscan/usa/makefile](../../base/mvdm/vdd/hpscan/usa/makefile) | — | — |
| [base/mvdm/vdd/mscdex](../../base/mvdm/vdd/mscdex) | 1 | [base/mvdm/vdd/mscdex/dirs](../../base/mvdm/vdd/mscdex/dirs) | — | — |
| [base/mvdm/vdd/mscdex/tsr](../../base/mvdm/vdd/mscdex/tsr) | 5 | [base/mvdm/vdd/mscdex/tsr/dirs](../../base/mvdm/vdd/mscdex/tsr/dirs) | — | — |
| [base/mvdm/vdd/mscdex/tsr/messages](../../base/mvdm/vdd/mscdex/tsr/messages) | 0 | — | — | — |
| [base/mvdm/vdd/mscdex/tsr/messages/usa](../../base/mvdm/vdd/mscdex/tsr/messages/usa) | 1 | — | — | — |
| [base/mvdm/vdd/mscdex/tsr/usa](../../base/mvdm/vdd/mscdex/tsr/usa) | 3 | [base/mvdm/vdd/mscdex/tsr/usa/sources](../../base/mvdm/vdd/mscdex/tsr/usa/sources), [base/mvdm/vdd/mscdex/tsr/usa/makefile](../../base/mvdm/vdd/mscdex/tsr/usa/makefile) | — | — |
| [base/mvdm/vdd/mscdex/vdd](../../base/mvdm/vdd/mscdex/vdd) | 7 | [base/mvdm/vdd/mscdex/vdd/sources](../../base/mvdm/vdd/mscdex/vdd/sources), [base/mvdm/vdd/mscdex/vdd/makefile](../../base/mvdm/vdd/mscdex/vdd/makefile) | `vcdex` | `DYNLINK` |
| [base/mvdm/vdd/samples](../../base/mvdm/vdd/samples) | 2 | [base/mvdm/vdd/samples/dirs](../../base/mvdm/vdd/samples/dirs) | — | — |
| [base/mvdm/vdd/samples/adlibvdd](../../base/mvdm/vdd/samples/adlibvdd) | 5 | [base/mvdm/vdd/samples/adlibvdd/sources](../../base/mvdm/vdd/samples/adlibvdd/sources), [base/mvdm/vdd/samples/adlibvdd/makefile](../../base/mvdm/vdd/samples/adlibvdd/makefile) | `adlibvdd` | `DYNLINK` |
| [base/mvdm/vdd/samples/sample1](../../base/mvdm/vdd/samples/sample1) | 1 | [base/mvdm/vdd/samples/sample1/dirs](../../base/mvdm/vdd/samples/sample1/dirs) | — | — |
| [base/mvdm/vdd/samples/sample1/fax16](../../base/mvdm/vdd/samples/sample1/fax16) | 2 | [base/mvdm/vdd/samples/sample1/fax16/makefile](../../base/mvdm/vdd/samples/sample1/fax16/makefile) | — | — |
| [base/mvdm/vdd/samples/sample1/fax32](../../base/mvdm/vdd/samples/sample1/fax32) | 5 | [base/mvdm/vdd/samples/sample1/fax32/sources](../../base/mvdm/vdd/samples/sample1/fax32/sources), [base/mvdm/vdd/samples/sample1/fax32/makefile](../../base/mvdm/vdd/samples/sample1/fax32/makefile) | `fax32` | `DYNLINK` |
| [base/mvdm/vdd/samples/sample2](../../base/mvdm/vdd/samples/sample2) | 1 | [base/mvdm/vdd/samples/sample2/dirs](../../base/mvdm/vdd/samples/sample2/dirs) | — | — |
| [base/mvdm/vdd/samples/sample2/16bits](../../base/mvdm/vdd/samples/sample2/16bits) | 3 | [base/mvdm/vdd/samples/sample2/16bits/makefile](../../base/mvdm/vdd/samples/sample2/16bits/makefile) | — | — |
| [base/mvdm/vdd/samples/sample2/vdd](../../base/mvdm/vdd/samples/sample2/vdd) | 5 | [base/mvdm/vdd/samples/sample2/vdd/sources](../../base/mvdm/vdd/samples/sample2/vdd/sources), [base/mvdm/vdd/samples/sample2/vdd/makefile](../../base/mvdm/vdd/samples/sample2/vdd/makefile) | `vdd` | `DYNLINK` |
| [base/mvdm/vdd/vjoy](../../base/mvdm/vdd/vjoy) | 6 | [base/mvdm/vdd/vjoy/sources](../../base/mvdm/vdd/vjoy/sources), [base/mvdm/vdd/vjoy/makefile](../../base/mvdm/vdd/vjoy/makefile) | `vjoy` | `DYNLINK` |
| [base/mvdm/vdd/vsndblst](../../base/mvdm/vdd/vsndblst) | 12 | [base/mvdm/vdd/vsndblst/sources](../../base/mvdm/vdd/vsndblst/sources), [base/mvdm/vdd/vsndblst/makefile](../../base/mvdm/vdd/vsndblst/makefile) | `vsndblst` | `DYNLINK` |
| [base/mvdm/vdmdbg](../../base/mvdm/vdmdbg) | 15 | [base/mvdm/vdmdbg/sources](../../base/mvdm/vdmdbg/sources), [base/mvdm/vdmdbg/makefile](../../base/mvdm/vdmdbg/makefile) | `vdmdbg` | `DYNLINK` |
| [base/mvdm/vdmexts](../../base/mvdm/vdmexts) | 25 | [base/mvdm/vdmexts/sources](../../base/mvdm/vdmexts/sources), [base/mvdm/vdmexts/makefile](../../base/mvdm/vdmexts/makefile) | `vdmexts` | `DYNLINK` |
| [base/mvdm/vdmexts/i386](../../base/mvdm/vdmexts/i386) | 3 | — | — | — |
| [base/mvdm/vdmredir](../../base/mvdm/vdmredir) | 25 | [base/mvdm/vdmredir/dirs](../../base/mvdm/vdmredir/dirs) | — | — |
| [base/mvdm/vdmredir/daytona](../../base/mvdm/vdmredir/daytona) | 3 | [base/mvdm/vdmredir/daytona/sources](../../base/mvdm/vdmredir/daytona/sources), [base/mvdm/vdmredir/daytona/makefile](../../base/mvdm/vdmredir/daytona/makefile) | — | — |
| [base/mvdm/vdmredir/nec_98](../../base/mvdm/vdmredir/nec_98) | 3 | [base/mvdm/vdmredir/nec_98/sources](../../base/mvdm/vdmredir/nec_98/sources), [base/mvdm/vdmredir/nec_98/makefile](../../base/mvdm/vdmredir/nec_98/makefile) | — | — |
| [base/mvdm/vdmutils](../../base/mvdm/vdmutils) | 1 | [base/mvdm/vdmutils/dirs](../../base/mvdm/vdmutils/dirs) | — | — |
| [base/mvdm/vdmutils/forcedos](../../base/mvdm/vdmutils/forcedos) | 6 | [base/mvdm/vdmutils/forcedos/dirs](../../base/mvdm/vdmutils/forcedos/dirs) | — | — |
| [base/mvdm/vdmutils/forcedos/daytona](../../base/mvdm/vdmutils/forcedos/daytona) | 2 | [base/mvdm/vdmutils/forcedos/daytona/sources](../../base/mvdm/vdmutils/forcedos/daytona/sources), [base/mvdm/vdmutils/forcedos/daytona/makefile](../../base/mvdm/vdmutils/forcedos/daytona/makefile) | — | — |
| [base/mvdm/vdmutils/forcedos/fe](../../base/mvdm/vdmutils/forcedos/fe) | 2 | [base/mvdm/vdmutils/forcedos/fe/sources](../../base/mvdm/vdmutils/forcedos/fe/sources), [base/mvdm/vdmutils/forcedos/fe/makefile](../../base/mvdm/vdmutils/forcedos/fe/makefile) | — | — |
| [base/mvdm/vdmutils/graftabl](../../base/mvdm/vdmutils/graftabl) | 5 | [base/mvdm/vdmutils/graftabl/dirs](../../base/mvdm/vdmutils/graftabl/dirs) | — | — |
| [base/mvdm/vdmutils/graftabl/daytona](../../base/mvdm/vdmutils/graftabl/daytona) | 2 | [base/mvdm/vdmutils/graftabl/daytona/sources](../../base/mvdm/vdmutils/graftabl/daytona/sources), [base/mvdm/vdmutils/graftabl/daytona/makefile](../../base/mvdm/vdmutils/graftabl/daytona/makefile) | — | — |
| [base/mvdm/vdmutils/graftabl/fe](../../base/mvdm/vdmutils/graftabl/fe) | 2 | [base/mvdm/vdmutils/graftabl/fe/sources](../../base/mvdm/vdmutils/graftabl/fe/sources), [base/mvdm/vdmutils/graftabl/fe/makefile](../../base/mvdm/vdmutils/graftabl/fe/makefile) | — | — |
| [base/mvdm/vdmutils/pifedit](../../base/mvdm/vdmutils/pifedit) | 12 | [base/mvdm/vdmutils/pifedit/sources](../../base/mvdm/vdmutils/pifedit/sources), [base/mvdm/vdmutils/pifedit/makefile](../../base/mvdm/vdmutils/pifedit/makefile) | `pifedit` | `LIBRARY` |
| [base/mvdm/vdmutils/pifedit/messages](../../base/mvdm/vdmutils/pifedit/messages) | 0 | — | — | — |
| [base/mvdm/vdmutils/pifedit/messages/usa](../../base/mvdm/vdmutils/pifedit/messages/usa) | 2 | — | — | — |
| [base/mvdm/vdmutils/win](../../base/mvdm/vdmutils/win) | 4 | [base/mvdm/vdmutils/win/sources](../../base/mvdm/vdmutils/win/sources), [base/mvdm/vdmutils/win/makefile](../../base/mvdm/vdmutils/win/makefile) | `win` | `UMAPPL_NOLIB` |
| [base/mvdm/wow16](../../base/mvdm/wow16) | 2 | [base/mvdm/wow16/dirs](../../base/mvdm/wow16/dirs) | — | — |
| [base/mvdm/wow16/bin](../../base/mvdm/wow16/bin) | 5 | — | — | — |
| [base/mvdm/wow16/commdlg](../../base/mvdm/wow16/commdlg) | 50 | [base/mvdm/wow16/commdlg/dirs](../../base/mvdm/wow16/commdlg/dirs) | — | — |
| [base/mvdm/wow16/commdlg/usa](../../base/mvdm/wow16/commdlg/usa) | 3 | [base/mvdm/wow16/commdlg/usa/sources](../../base/mvdm/wow16/commdlg/usa/sources), [base/mvdm/wow16/commdlg/usa/makefile](../../base/mvdm/wow16/commdlg/usa/makefile) | — | — |
| [base/mvdm/wow16/ctl3dv2](../../base/mvdm/wow16/ctl3dv2) | 17 | — | — | — |
| [base/mvdm/wow16/ddeml](../../base/mvdm/wow16/ddeml) | 22 | [base/mvdm/wow16/ddeml/dirs](../../base/mvdm/wow16/ddeml/dirs) | — | — |
| [base/mvdm/wow16/ddeml/messages](../../base/mvdm/wow16/ddeml/messages) | 0 | — | — | — |
| [base/mvdm/wow16/ddeml/messages/usa](../../base/mvdm/wow16/ddeml/messages/usa) | 3 | — | — | — |
| [base/mvdm/wow16/ddeml/tests](../../base/mvdm/wow16/ddeml/tests) | 7 | — | — | — |
| [base/mvdm/wow16/ddeml/tests/ddestrs](../../base/mvdm/wow16/ddeml/tests/ddestrs) | 20 | [base/mvdm/wow16/ddeml/tests/ddestrs/sources](../../base/mvdm/wow16/ddeml/tests/ddestrs/sources), [base/mvdm/wow16/ddeml/tests/ddestrs/makefile](../../base/mvdm/wow16/ddeml/tests/ddestrs/makefile) | `ddestrs` | `LIBRARY` |
| [base/mvdm/wow16/ddeml/tests/ddestrs/obj](../../base/mvdm/wow16/ddeml/tests/ddestrs/obj) | 0 | — | — | — |
| [base/mvdm/wow16/ddeml/tests/ddestrs/obj/i386](../../base/mvdm/wow16/ddeml/tests/ddestrs/obj/i386) | 9 | — | — | — |
| [base/mvdm/wow16/ddeml/tests/src](../../base/mvdm/wow16/ddeml/tests/src) | 3 | [base/mvdm/wow16/ddeml/tests/src/dirs](../../base/mvdm/wow16/ddeml/tests/src/dirs) | — | — |
| [base/mvdm/wow16/ddeml/tests/src/client](../../base/mvdm/wow16/ddeml/tests/src/client) | 23 | [base/mvdm/wow16/ddeml/tests/src/client/sources](../../base/mvdm/wow16/ddeml/tests/src/client/sources), [base/mvdm/wow16/ddeml/tests/src/client/makefile](../../base/mvdm/wow16/ddeml/tests/src/client/makefile) | `ddemlcl` | `LIBRARY` |
| [base/mvdm/wow16/ddeml/tests/src/ddemo](../../base/mvdm/wow16/ddeml/tests/src/ddemo) | 6 | [base/mvdm/wow16/ddeml/tests/src/ddemo/sources](../../base/mvdm/wow16/ddeml/tests/src/ddemo/sources), [base/mvdm/wow16/ddeml/tests/src/ddemo/makefile](../../base/mvdm/wow16/ddeml/tests/src/ddemo/makefile) | `ddemo` | `LIBRARY` |
| [base/mvdm/wow16/ddeml/tests/src/server](../../base/mvdm/wow16/ddeml/tests/src/server) | 15 | [base/mvdm/wow16/ddeml/tests/src/server/sources](../../base/mvdm/wow16/ddeml/tests/src/server/sources), [base/mvdm/wow16/ddeml/tests/src/server/makefile](../../base/mvdm/wow16/ddeml/tests/src/server/makefile) | `ddemlsv` | `LIBRARY` |
| [base/mvdm/wow16/ddeml/usa](../../base/mvdm/wow16/ddeml/usa) | 3 | [base/mvdm/wow16/ddeml/usa/sources](../../base/mvdm/wow16/ddeml/usa/sources), [base/mvdm/wow16/ddeml/usa/makefile](../../base/mvdm/wow16/ddeml/usa/makefile) | — | — |
| [base/mvdm/wow16/drivers](../../base/mvdm/wow16/drivers) | 1 | [base/mvdm/wow16/drivers/dirs](../../base/mvdm/wow16/drivers/dirs) | — | — |
| [base/mvdm/wow16/drivers/comm](../../base/mvdm/wow16/drivers/comm) | 20 | [base/mvdm/wow16/drivers/comm/dirs](../../base/mvdm/wow16/drivers/comm/dirs) | — | — |
| [base/mvdm/wow16/drivers/comm/chp](../../base/mvdm/wow16/drivers/comm/chp) | 3 | [base/mvdm/wow16/drivers/comm/chp/sources](../../base/mvdm/wow16/drivers/comm/chp/sources), [base/mvdm/wow16/drivers/comm/chp/makefile](../../base/mvdm/wow16/drivers/comm/chp/makefile) | — | — |
| [base/mvdm/wow16/drivers/comm/chs](../../base/mvdm/wow16/drivers/comm/chs) | 3 | [base/mvdm/wow16/drivers/comm/chs/sources](../../base/mvdm/wow16/drivers/comm/chs/sources), [base/mvdm/wow16/drivers/comm/chs/makefile](../../base/mvdm/wow16/drivers/comm/chs/makefile) | — | — |
| [base/mvdm/wow16/drivers/comm/cht](../../base/mvdm/wow16/drivers/comm/cht) | 3 | [base/mvdm/wow16/drivers/comm/cht/sources](../../base/mvdm/wow16/drivers/comm/cht/sources), [base/mvdm/wow16/drivers/comm/cht/makefile](../../base/mvdm/wow16/drivers/comm/cht/makefile) | — | — |
| [base/mvdm/wow16/drivers/comm/jpn](../../base/mvdm/wow16/drivers/comm/jpn) | 3 | [base/mvdm/wow16/drivers/comm/jpn/sources](../../base/mvdm/wow16/drivers/comm/jpn/sources), [base/mvdm/wow16/drivers/comm/jpn/makefile](../../base/mvdm/wow16/drivers/comm/jpn/makefile) | — | — |
| [base/mvdm/wow16/drivers/comm/kor](../../base/mvdm/wow16/drivers/comm/kor) | 3 | [base/mvdm/wow16/drivers/comm/kor/sources](../../base/mvdm/wow16/drivers/comm/kor/sources), [base/mvdm/wow16/drivers/comm/kor/makefile](../../base/mvdm/wow16/drivers/comm/kor/makefile) | — | — |
| [base/mvdm/wow16/drivers/comm/usa](../../base/mvdm/wow16/drivers/comm/usa) | 3 | [base/mvdm/wow16/drivers/comm/usa/sources](../../base/mvdm/wow16/drivers/comm/usa/sources), [base/mvdm/wow16/drivers/comm/usa/makefile](../../base/mvdm/wow16/drivers/comm/usa/makefile) | — | — |
| [base/mvdm/wow16/drivers/display](../../base/mvdm/wow16/drivers/display) | 8 | [base/mvdm/wow16/drivers/display/dirs](../../base/mvdm/wow16/drivers/display/dirs) | — | — |
| [base/mvdm/wow16/drivers/display/usa](../../base/mvdm/wow16/drivers/display/usa) | 3 | [base/mvdm/wow16/drivers/display/usa/sources](../../base/mvdm/wow16/drivers/display/usa/sources), [base/mvdm/wow16/drivers/display/usa/makefile](../../base/mvdm/wow16/drivers/display/usa/makefile) | — | — |
| [base/mvdm/wow16/drivers/keyboard](../../base/mvdm/wow16/drivers/keyboard) | 9 | [base/mvdm/wow16/drivers/keyboard/dirs](../../base/mvdm/wow16/drivers/keyboard/dirs) | — | — |
| [base/mvdm/wow16/drivers/keyboard/chp](../../base/mvdm/wow16/drivers/keyboard/chp) | 3 | [base/mvdm/wow16/drivers/keyboard/chp/sources](../../base/mvdm/wow16/drivers/keyboard/chp/sources), [base/mvdm/wow16/drivers/keyboard/chp/makefile](../../base/mvdm/wow16/drivers/keyboard/chp/makefile) | — | — |
| [base/mvdm/wow16/drivers/keyboard/chs](../../base/mvdm/wow16/drivers/keyboard/chs) | 3 | [base/mvdm/wow16/drivers/keyboard/chs/sources](../../base/mvdm/wow16/drivers/keyboard/chs/sources), [base/mvdm/wow16/drivers/keyboard/chs/makefile](../../base/mvdm/wow16/drivers/keyboard/chs/makefile) | — | — |
| [base/mvdm/wow16/drivers/keyboard/cht](../../base/mvdm/wow16/drivers/keyboard/cht) | 3 | [base/mvdm/wow16/drivers/keyboard/cht/sources](../../base/mvdm/wow16/drivers/keyboard/cht/sources), [base/mvdm/wow16/drivers/keyboard/cht/makefile](../../base/mvdm/wow16/drivers/keyboard/cht/makefile) | — | — |
| [base/mvdm/wow16/drivers/keyboard/jpn](../../base/mvdm/wow16/drivers/keyboard/jpn) | 3 | [base/mvdm/wow16/drivers/keyboard/jpn/sources](../../base/mvdm/wow16/drivers/keyboard/jpn/sources), [base/mvdm/wow16/drivers/keyboard/jpn/makefile](../../base/mvdm/wow16/drivers/keyboard/jpn/makefile) | — | — |
| [base/mvdm/wow16/drivers/keyboard/kor](../../base/mvdm/wow16/drivers/keyboard/kor) | 3 | [base/mvdm/wow16/drivers/keyboard/kor/sources](../../base/mvdm/wow16/drivers/keyboard/kor/sources), [base/mvdm/wow16/drivers/keyboard/kor/makefile](../../base/mvdm/wow16/drivers/keyboard/kor/makefile) | — | — |
| [base/mvdm/wow16/drivers/keyboard/nec_98](../../base/mvdm/wow16/drivers/keyboard/nec_98) | 3 | [base/mvdm/wow16/drivers/keyboard/nec_98/sources](../../base/mvdm/wow16/drivers/keyboard/nec_98/sources), [base/mvdm/wow16/drivers/keyboard/nec_98/makefile](../../base/mvdm/wow16/drivers/keyboard/nec_98/makefile) | — | — |
| [base/mvdm/wow16/drivers/keyboard/usa](../../base/mvdm/wow16/drivers/keyboard/usa) | 3 | [base/mvdm/wow16/drivers/keyboard/usa/sources](../../base/mvdm/wow16/drivers/keyboard/usa/sources), [base/mvdm/wow16/drivers/keyboard/usa/makefile](../../base/mvdm/wow16/drivers/keyboard/usa/makefile) | — | — |
| [base/mvdm/wow16/drivers/mouse](../../base/mvdm/wow16/drivers/mouse) | 7 | [base/mvdm/wow16/drivers/mouse/dirs](../../base/mvdm/wow16/drivers/mouse/dirs) | — | — |
| [base/mvdm/wow16/drivers/mouse/usa](../../base/mvdm/wow16/drivers/mouse/usa) | 3 | [base/mvdm/wow16/drivers/mouse/usa/sources](../../base/mvdm/wow16/drivers/mouse/usa/sources), [base/mvdm/wow16/drivers/mouse/usa/makefile](../../base/mvdm/wow16/drivers/mouse/usa/makefile) | — | — |
| [base/mvdm/wow16/drivers/neccomm](../../base/mvdm/wow16/drivers/neccomm) | 7 | [base/mvdm/wow16/drivers/neccomm/dirs](../../base/mvdm/wow16/drivers/neccomm/dirs) | — | — |
| [base/mvdm/wow16/drivers/neccomm/nec_98](../../base/mvdm/wow16/drivers/neccomm/nec_98) | 3 | [base/mvdm/wow16/drivers/neccomm/nec_98/sources](../../base/mvdm/wow16/drivers/neccomm/nec_98/sources), [base/mvdm/wow16/drivers/neccomm/nec_98/makefile](../../base/mvdm/wow16/drivers/neccomm/nec_98/makefile) | — | — |
| [base/mvdm/wow16/drivers/neccomm1](../../base/mvdm/wow16/drivers/neccomm1) | 21 | [base/mvdm/wow16/drivers/neccomm1/dirs](../../base/mvdm/wow16/drivers/neccomm1/dirs) | — | — |
| [base/mvdm/wow16/drivers/neccomm1/nec_98](../../base/mvdm/wow16/drivers/neccomm1/nec_98) | 3 | [base/mvdm/wow16/drivers/neccomm1/nec_98/sources](../../base/mvdm/wow16/drivers/neccomm1/nec_98/sources), [base/mvdm/wow16/drivers/neccomm1/nec_98/makefile](../../base/mvdm/wow16/drivers/neccomm1/nec_98/makefile) | — | — |
| [base/mvdm/wow16/drivers/neccomm2](../../base/mvdm/wow16/drivers/neccomm2) | 21 | [base/mvdm/wow16/drivers/neccomm2/dirs](../../base/mvdm/wow16/drivers/neccomm2/dirs) | — | — |
| [base/mvdm/wow16/drivers/neccomm2/nec_98](../../base/mvdm/wow16/drivers/neccomm2/nec_98) | 3 | [base/mvdm/wow16/drivers/neccomm2/nec_98/sources](../../base/mvdm/wow16/drivers/neccomm2/nec_98/sources), [base/mvdm/wow16/drivers/neccomm2/nec_98/makefile](../../base/mvdm/wow16/drivers/neccomm2/nec_98/makefile) | — | — |
| [base/mvdm/wow16/drivers/sound](../../base/mvdm/wow16/drivers/sound) | 7 | [base/mvdm/wow16/drivers/sound/dirs](../../base/mvdm/wow16/drivers/sound/dirs) | — | — |
| [base/mvdm/wow16/drivers/sound/usa](../../base/mvdm/wow16/drivers/sound/usa) | 3 | [base/mvdm/wow16/drivers/sound/usa/sources](../../base/mvdm/wow16/drivers/sound/usa/sources), [base/mvdm/wow16/drivers/sound/usa/makefile](../../base/mvdm/wow16/drivers/sound/usa/makefile) | — | — |
| [base/mvdm/wow16/gdi](../../base/mvdm/wow16/gdi) | 19 | [base/mvdm/wow16/gdi/dirs](../../base/mvdm/wow16/gdi/dirs) | — | — |
| [base/mvdm/wow16/gdi/chp](../../base/mvdm/wow16/gdi/chp) | 4 | [base/mvdm/wow16/gdi/chp/sources](../../base/mvdm/wow16/gdi/chp/sources), [base/mvdm/wow16/gdi/chp/makefile](../../base/mvdm/wow16/gdi/chp/makefile) | — | — |
| [base/mvdm/wow16/gdi/chs](../../base/mvdm/wow16/gdi/chs) | 4 | [base/mvdm/wow16/gdi/chs/sources](../../base/mvdm/wow16/gdi/chs/sources), [base/mvdm/wow16/gdi/chs/makefile](../../base/mvdm/wow16/gdi/chs/makefile) | — | — |
| [base/mvdm/wow16/gdi/cht](../../base/mvdm/wow16/gdi/cht) | 4 | [base/mvdm/wow16/gdi/cht/sources](../../base/mvdm/wow16/gdi/cht/sources), [base/mvdm/wow16/gdi/cht/makefile](../../base/mvdm/wow16/gdi/cht/makefile) | — | — |
| [base/mvdm/wow16/gdi/jpn](../../base/mvdm/wow16/gdi/jpn) | 4 | [base/mvdm/wow16/gdi/jpn/sources](../../base/mvdm/wow16/gdi/jpn/sources), [base/mvdm/wow16/gdi/jpn/makefile](../../base/mvdm/wow16/gdi/jpn/makefile) | — | — |
| [base/mvdm/wow16/gdi/kor](../../base/mvdm/wow16/gdi/kor) | 4 | [base/mvdm/wow16/gdi/kor/sources](../../base/mvdm/wow16/gdi/kor/sources), [base/mvdm/wow16/gdi/kor/makefile](../../base/mvdm/wow16/gdi/kor/makefile) | — | — |
| [base/mvdm/wow16/gdi/nec_98](../../base/mvdm/wow16/gdi/nec_98) | 4 | [base/mvdm/wow16/gdi/nec_98/sources](../../base/mvdm/wow16/gdi/nec_98/sources), [base/mvdm/wow16/gdi/nec_98/makefile](../../base/mvdm/wow16/gdi/nec_98/makefile) | — | — |
| [base/mvdm/wow16/gdi/usa](../../base/mvdm/wow16/gdi/usa) | 4 | [base/mvdm/wow16/gdi/usa/sources](../../base/mvdm/wow16/gdi/usa/sources), [base/mvdm/wow16/gdi/usa/makefile](../../base/mvdm/wow16/gdi/usa/makefile) | — | — |
| [base/mvdm/wow16/inc](../../base/mvdm/wow16/inc) | 69 | — | — | — |
| [base/mvdm/wow16/kernel31](../../base/mvdm/wow16/kernel31) | 120 | [base/mvdm/wow16/kernel31/dirs](../../base/mvdm/wow16/kernel31/dirs) | — | — |
| [base/mvdm/wow16/kernel31/br](../../base/mvdm/wow16/kernel31/br) | 3 | [base/mvdm/wow16/kernel31/br/sources](../../base/mvdm/wow16/kernel31/br/sources), [base/mvdm/wow16/kernel31/br/makefile](../../base/mvdm/wow16/kernel31/br/makefile) | — | — |
| [base/mvdm/wow16/kernel31/chp](../../base/mvdm/wow16/kernel31/chp) | 3 | [base/mvdm/wow16/kernel31/chp/sources](../../base/mvdm/wow16/kernel31/chp/sources), [base/mvdm/wow16/kernel31/chp/makefile](../../base/mvdm/wow16/kernel31/chp/makefile) | — | — |
| [base/mvdm/wow16/kernel31/chs](../../base/mvdm/wow16/kernel31/chs) | 3 | [base/mvdm/wow16/kernel31/chs/sources](../../base/mvdm/wow16/kernel31/chs/sources), [base/mvdm/wow16/kernel31/chs/makefile](../../base/mvdm/wow16/kernel31/chs/makefile) | — | — |
| [base/mvdm/wow16/kernel31/cht](../../base/mvdm/wow16/kernel31/cht) | 3 | [base/mvdm/wow16/kernel31/cht/sources](../../base/mvdm/wow16/kernel31/cht/sources), [base/mvdm/wow16/kernel31/cht/makefile](../../base/mvdm/wow16/kernel31/cht/makefile) | — | — |
| [base/mvdm/wow16/kernel31/cs](../../base/mvdm/wow16/kernel31/cs) | 3 | [base/mvdm/wow16/kernel31/cs/sources](../../base/mvdm/wow16/kernel31/cs/sources), [base/mvdm/wow16/kernel31/cs/makefile](../../base/mvdm/wow16/kernel31/cs/makefile) | — | — |
| [base/mvdm/wow16/kernel31/da](../../base/mvdm/wow16/kernel31/da) | 3 | [base/mvdm/wow16/kernel31/da/sources](../../base/mvdm/wow16/kernel31/da/sources), [base/mvdm/wow16/kernel31/da/makefile](../../base/mvdm/wow16/kernel31/da/makefile) | — | — |
| [base/mvdm/wow16/kernel31/el](../../base/mvdm/wow16/kernel31/el) | 3 | [base/mvdm/wow16/kernel31/el/sources](../../base/mvdm/wow16/kernel31/el/sources), [base/mvdm/wow16/kernel31/el/makefile](../../base/mvdm/wow16/kernel31/el/makefile) | — | — |
| [base/mvdm/wow16/kernel31/es](../../base/mvdm/wow16/kernel31/es) | 3 | [base/mvdm/wow16/kernel31/es/sources](../../base/mvdm/wow16/kernel31/es/sources), [base/mvdm/wow16/kernel31/es/makefile](../../base/mvdm/wow16/kernel31/es/makefile) | — | — |
| [base/mvdm/wow16/kernel31/fi](../../base/mvdm/wow16/kernel31/fi) | 3 | [base/mvdm/wow16/kernel31/fi/sources](../../base/mvdm/wow16/kernel31/fi/sources), [base/mvdm/wow16/kernel31/fi/makefile](../../base/mvdm/wow16/kernel31/fi/makefile) | — | — |
| [base/mvdm/wow16/kernel31/fr](../../base/mvdm/wow16/kernel31/fr) | 3 | [base/mvdm/wow16/kernel31/fr/sources](../../base/mvdm/wow16/kernel31/fr/sources), [base/mvdm/wow16/kernel31/fr/makefile](../../base/mvdm/wow16/kernel31/fr/makefile) | — | — |
| [base/mvdm/wow16/kernel31/ger](../../base/mvdm/wow16/kernel31/ger) | 3 | [base/mvdm/wow16/kernel31/ger/sources](../../base/mvdm/wow16/kernel31/ger/sources), [base/mvdm/wow16/kernel31/ger/makefile](../../base/mvdm/wow16/kernel31/ger/makefile) | — | — |
| [base/mvdm/wow16/kernel31/hu](../../base/mvdm/wow16/kernel31/hu) | 3 | [base/mvdm/wow16/kernel31/hu/sources](../../base/mvdm/wow16/kernel31/hu/sources), [base/mvdm/wow16/kernel31/hu/makefile](../../base/mvdm/wow16/kernel31/hu/makefile) | — | — |
| [base/mvdm/wow16/kernel31/it](../../base/mvdm/wow16/kernel31/it) | 3 | [base/mvdm/wow16/kernel31/it/sources](../../base/mvdm/wow16/kernel31/it/sources), [base/mvdm/wow16/kernel31/it/makefile](../../base/mvdm/wow16/kernel31/it/makefile) | — | — |
| [base/mvdm/wow16/kernel31/jpn](../../base/mvdm/wow16/kernel31/jpn) | 3 | [base/mvdm/wow16/kernel31/jpn/sources](../../base/mvdm/wow16/kernel31/jpn/sources), [base/mvdm/wow16/kernel31/jpn/makefile](../../base/mvdm/wow16/kernel31/jpn/makefile) | — | — |
| [base/mvdm/wow16/kernel31/kor](../../base/mvdm/wow16/kernel31/kor) | 3 | [base/mvdm/wow16/kernel31/kor/sources](../../base/mvdm/wow16/kernel31/kor/sources), [base/mvdm/wow16/kernel31/kor/makefile](../../base/mvdm/wow16/kernel31/kor/makefile) | — | — |
| [base/mvdm/wow16/kernel31/messages](../../base/mvdm/wow16/kernel31/messages) | 0 | — | — | — |
| [base/mvdm/wow16/kernel31/messages/br](../../base/mvdm/wow16/kernel31/messages/br) | 1 | — | — | — |
| [base/mvdm/wow16/kernel31/messages/chp](../../base/mvdm/wow16/kernel31/messages/chp) | 1 | — | — | — |
| [base/mvdm/wow16/kernel31/messages/chs](../../base/mvdm/wow16/kernel31/messages/chs) | 1 | — | — | — |
| [base/mvdm/wow16/kernel31/messages/cht](../../base/mvdm/wow16/kernel31/messages/cht) | 1 | — | — | — |
| [base/mvdm/wow16/kernel31/messages/cs](../../base/mvdm/wow16/kernel31/messages/cs) | 1 | — | — | — |
| [base/mvdm/wow16/kernel31/messages/da](../../base/mvdm/wow16/kernel31/messages/da) | 1 | — | — | — |
| [base/mvdm/wow16/kernel31/messages/el](../../base/mvdm/wow16/kernel31/messages/el) | 1 | — | — | — |
| [base/mvdm/wow16/kernel31/messages/es](../../base/mvdm/wow16/kernel31/messages/es) | 1 | — | — | — |
| [base/mvdm/wow16/kernel31/messages/fi](../../base/mvdm/wow16/kernel31/messages/fi) | 1 | — | — | — |
| [base/mvdm/wow16/kernel31/messages/fr](../../base/mvdm/wow16/kernel31/messages/fr) | 1 | — | — | — |
| [base/mvdm/wow16/kernel31/messages/ger](../../base/mvdm/wow16/kernel31/messages/ger) | 1 | — | — | — |
| [base/mvdm/wow16/kernel31/messages/hu](../../base/mvdm/wow16/kernel31/messages/hu) | 1 | — | — | — |
| [base/mvdm/wow16/kernel31/messages/it](../../base/mvdm/wow16/kernel31/messages/it) | 1 | — | — | — |
| [base/mvdm/wow16/kernel31/messages/jpn](../../base/mvdm/wow16/kernel31/messages/jpn) | 1 | — | — | — |
| [base/mvdm/wow16/kernel31/messages/kor](../../base/mvdm/wow16/kernel31/messages/kor) | 1 | — | — | — |
| [base/mvdm/wow16/kernel31/messages/nec_98](../../base/mvdm/wow16/kernel31/messages/nec_98) | 1 | — | — | — |
| [base/mvdm/wow16/kernel31/messages/nl](../../base/mvdm/wow16/kernel31/messages/nl) | 1 | — | — | — |
| [base/mvdm/wow16/kernel31/messages/no](../../base/mvdm/wow16/kernel31/messages/no) | 1 | — | — | — |
| [base/mvdm/wow16/kernel31/messages/pl](../../base/mvdm/wow16/kernel31/messages/pl) | 1 | — | — | — |
| [base/mvdm/wow16/kernel31/messages/pt](../../base/mvdm/wow16/kernel31/messages/pt) | 1 | — | — | — |
| [base/mvdm/wow16/kernel31/messages/ru](../../base/mvdm/wow16/kernel31/messages/ru) | 1 | — | — | — |
| [base/mvdm/wow16/kernel31/messages/sv](../../base/mvdm/wow16/kernel31/messages/sv) | 1 | — | — | — |
| [base/mvdm/wow16/kernel31/messages/tr](../../base/mvdm/wow16/kernel31/messages/tr) | 1 | — | — | — |
| [base/mvdm/wow16/kernel31/messages/usa](../../base/mvdm/wow16/kernel31/messages/usa) | 1 | — | — | — |
| [base/mvdm/wow16/kernel31/nec_98](../../base/mvdm/wow16/kernel31/nec_98) | 3 | [base/mvdm/wow16/kernel31/nec_98/sources](../../base/mvdm/wow16/kernel31/nec_98/sources), [base/mvdm/wow16/kernel31/nec_98/makefile](../../base/mvdm/wow16/kernel31/nec_98/makefile) | — | — |
| [base/mvdm/wow16/kernel31/nl](../../base/mvdm/wow16/kernel31/nl) | 3 | [base/mvdm/wow16/kernel31/nl/sources](../../base/mvdm/wow16/kernel31/nl/sources), [base/mvdm/wow16/kernel31/nl/makefile](../../base/mvdm/wow16/kernel31/nl/makefile) | — | — |
| [base/mvdm/wow16/kernel31/no](../../base/mvdm/wow16/kernel31/no) | 3 | [base/mvdm/wow16/kernel31/no/sources](../../base/mvdm/wow16/kernel31/no/sources), [base/mvdm/wow16/kernel31/no/makefile](../../base/mvdm/wow16/kernel31/no/makefile) | — | — |
| [base/mvdm/wow16/kernel31/pl](../../base/mvdm/wow16/kernel31/pl) | 3 | [base/mvdm/wow16/kernel31/pl/sources](../../base/mvdm/wow16/kernel31/pl/sources), [base/mvdm/wow16/kernel31/pl/makefile](../../base/mvdm/wow16/kernel31/pl/makefile) | — | — |
| [base/mvdm/wow16/kernel31/psu](../../base/mvdm/wow16/kernel31/psu) | 3 | [base/mvdm/wow16/kernel31/psu/sources](../../base/mvdm/wow16/kernel31/psu/sources), [base/mvdm/wow16/kernel31/psu/makefile](../../base/mvdm/wow16/kernel31/psu/makefile) | — | — |
| [base/mvdm/wow16/kernel31/pt](../../base/mvdm/wow16/kernel31/pt) | 3 | [base/mvdm/wow16/kernel31/pt/sources](../../base/mvdm/wow16/kernel31/pt/sources), [base/mvdm/wow16/kernel31/pt/makefile](../../base/mvdm/wow16/kernel31/pt/makefile) | — | — |
| [base/mvdm/wow16/kernel31/ru](../../base/mvdm/wow16/kernel31/ru) | 3 | [base/mvdm/wow16/kernel31/ru/sources](../../base/mvdm/wow16/kernel31/ru/sources), [base/mvdm/wow16/kernel31/ru/makefile](../../base/mvdm/wow16/kernel31/ru/makefile) | — | — |
| [base/mvdm/wow16/kernel31/sv](../../base/mvdm/wow16/kernel31/sv) | 3 | [base/mvdm/wow16/kernel31/sv/sources](../../base/mvdm/wow16/kernel31/sv/sources), [base/mvdm/wow16/kernel31/sv/makefile](../../base/mvdm/wow16/kernel31/sv/makefile) | — | — |
| [base/mvdm/wow16/kernel31/swappro](../../base/mvdm/wow16/kernel31/swappro) | 3 | [base/mvdm/wow16/kernel31/swappro/makefile](../../base/mvdm/wow16/kernel31/swappro/makefile) | — | — |
| [base/mvdm/wow16/kernel31/tr](../../base/mvdm/wow16/kernel31/tr) | 3 | [base/mvdm/wow16/kernel31/tr/sources](../../base/mvdm/wow16/kernel31/tr/sources), [base/mvdm/wow16/kernel31/tr/makefile](../../base/mvdm/wow16/kernel31/tr/makefile) | — | — |
| [base/mvdm/wow16/kernel31/tst](../../base/mvdm/wow16/kernel31/tst) | 3 | [base/mvdm/wow16/kernel31/tst/sources](../../base/mvdm/wow16/kernel31/tst/sources), [base/mvdm/wow16/kernel31/tst/makefile](../../base/mvdm/wow16/kernel31/tst/makefile) | — | — |
| [base/mvdm/wow16/kernel31/usa](../../base/mvdm/wow16/kernel31/usa) | 3 | [base/mvdm/wow16/kernel31/usa/sources](../../base/mvdm/wow16/kernel31/usa/sources), [base/mvdm/wow16/kernel31/usa/makefile](../../base/mvdm/wow16/kernel31/usa/makefile) | — | — |
| [base/mvdm/wow16/killwow](../../base/mvdm/wow16/killwow) | 7 | [base/mvdm/wow16/killwow/dirs](../../base/mvdm/wow16/killwow/dirs) | — | — |
| [base/mvdm/wow16/killwow/usa](../../base/mvdm/wow16/killwow/usa) | 3 | [base/mvdm/wow16/killwow/usa/sources](../../base/mvdm/wow16/killwow/usa/sources), [base/mvdm/wow16/killwow/usa/makefile](../../base/mvdm/wow16/killwow/usa/makefile) | — | — |
| [base/mvdm/wow16/lib](../../base/mvdm/wow16/lib) | 22 | [base/mvdm/wow16/lib/dirs](../../base/mvdm/wow16/lib/dirs) | — | — |
| [base/mvdm/wow16/lib/chp](../../base/mvdm/wow16/lib/chp) | 4 | [base/mvdm/wow16/lib/chp/sources](../../base/mvdm/wow16/lib/chp/sources), [base/mvdm/wow16/lib/chp/makefile](../../base/mvdm/wow16/lib/chp/makefile) | — | — |
| [base/mvdm/wow16/lib/chs](../../base/mvdm/wow16/lib/chs) | 4 | [base/mvdm/wow16/lib/chs/sources](../../base/mvdm/wow16/lib/chs/sources), [base/mvdm/wow16/lib/chs/makefile](../../base/mvdm/wow16/lib/chs/makefile) | — | — |
| [base/mvdm/wow16/lib/cht](../../base/mvdm/wow16/lib/cht) | 4 | [base/mvdm/wow16/lib/cht/sources](../../base/mvdm/wow16/lib/cht/sources), [base/mvdm/wow16/lib/cht/makefile](../../base/mvdm/wow16/lib/cht/makefile) | — | — |
| [base/mvdm/wow16/lib/jpn](../../base/mvdm/wow16/lib/jpn) | 4 | [base/mvdm/wow16/lib/jpn/sources](../../base/mvdm/wow16/lib/jpn/sources), [base/mvdm/wow16/lib/jpn/makefile](../../base/mvdm/wow16/lib/jpn/makefile) | — | — |
| [base/mvdm/wow16/lib/kor](../../base/mvdm/wow16/lib/kor) | 4 | [base/mvdm/wow16/lib/kor/sources](../../base/mvdm/wow16/lib/kor/sources), [base/mvdm/wow16/lib/kor/makefile](../../base/mvdm/wow16/lib/kor/makefile) | — | — |
| [base/mvdm/wow16/lib/nec_98](../../base/mvdm/wow16/lib/nec_98) | 4 | [base/mvdm/wow16/lib/nec_98/sources](../../base/mvdm/wow16/lib/nec_98/sources), [base/mvdm/wow16/lib/nec_98/makefile](../../base/mvdm/wow16/lib/nec_98/makefile) | — | — |
| [base/mvdm/wow16/lib/usa](../../base/mvdm/wow16/lib/usa) | 4 | [base/mvdm/wow16/lib/usa/sources](../../base/mvdm/wow16/lib/usa/sources), [base/mvdm/wow16/lib/usa/makefile](../../base/mvdm/wow16/lib/usa/makefile) | — | — |
| [base/mvdm/wow16/mciole](../../base/mvdm/wow16/mciole) | 12 | [base/mvdm/wow16/mciole/dirs](../../base/mvdm/wow16/mciole/dirs) | — | — |
| [base/mvdm/wow16/mciole/usa](../../base/mvdm/wow16/mciole/usa) | 3 | [base/mvdm/wow16/mciole/usa/sources](../../base/mvdm/wow16/mciole/usa/sources), [base/mvdm/wow16/mciole/usa/makefile](../../base/mvdm/wow16/mciole/usa/makefile) | — | — |
| [base/mvdm/wow16/mmsystem](../../base/mvdm/wow16/mmsystem) | 55 | [base/mvdm/wow16/mmsystem/dirs](../../base/mvdm/wow16/mmsystem/dirs) | — | — |
| [base/mvdm/wow16/mmsystem/messages](../../base/mvdm/wow16/mmsystem/messages) | 0 | — | — | — |
| [base/mvdm/wow16/mmsystem/messages/usa](../../base/mvdm/wow16/mmsystem/messages/usa) | 5 | — | — | — |
| [base/mvdm/wow16/mmsystem/mmtask](../../base/mvdm/wow16/mmsystem/mmtask) | 4 | [base/mvdm/wow16/mmsystem/mmtask/makefile](../../base/mvdm/wow16/mmsystem/mmtask/makefile) | — | — |
| [base/mvdm/wow16/mmsystem/nec_98](../../base/mvdm/wow16/mmsystem/nec_98) | 3 | [base/mvdm/wow16/mmsystem/nec_98/sources](../../base/mvdm/wow16/mmsystem/nec_98/sources), [base/mvdm/wow16/mmsystem/nec_98/makefile](../../base/mvdm/wow16/mmsystem/nec_98/makefile) | — | — |
| [base/mvdm/wow16/mmsystem/rinc](../../base/mvdm/wow16/mmsystem/rinc) | 1 | — | — | — |
| [base/mvdm/wow16/mmsystem/usa](../../base/mvdm/wow16/mmsystem/usa) | 3 | [base/mvdm/wow16/mmsystem/usa/sources](../../base/mvdm/wow16/mmsystem/usa/sources), [base/mvdm/wow16/mmsystem/usa/makefile](../../base/mvdm/wow16/mmsystem/usa/makefile) | — | — |
| [base/mvdm/wow16/ole](../../base/mvdm/wow16/ole) | 1 | [base/mvdm/wow16/ole/dirs](../../base/mvdm/wow16/ole/dirs) | — | — |
| [base/mvdm/wow16/ole/client](../../base/mvdm/wow16/ole/client) | 29 | [base/mvdm/wow16/ole/client/makefile](../../base/mvdm/wow16/ole/client/makefile) | — | — |
| [base/mvdm/wow16/ole/client/messages](../../base/mvdm/wow16/ole/client/messages) | 0 | — | — | — |
| [base/mvdm/wow16/ole/client/messages/usa](../../base/mvdm/wow16/ole/client/messages/usa) | 2 | — | — | — |
| [base/mvdm/wow16/ole/server](../../base/mvdm/wow16/ole/server) | 16 | [base/mvdm/wow16/ole/server/dirs](../../base/mvdm/wow16/ole/server/dirs) | — | — |
| [base/mvdm/wow16/ole/server/chp](../../base/mvdm/wow16/ole/server/chp) | 3 | [base/mvdm/wow16/ole/server/chp/sources](../../base/mvdm/wow16/ole/server/chp/sources), [base/mvdm/wow16/ole/server/chp/makefile](../../base/mvdm/wow16/ole/server/chp/makefile) | — | — |
| [base/mvdm/wow16/ole/server/chs](../../base/mvdm/wow16/ole/server/chs) | 3 | [base/mvdm/wow16/ole/server/chs/sources](../../base/mvdm/wow16/ole/server/chs/sources), [base/mvdm/wow16/ole/server/chs/makefile](../../base/mvdm/wow16/ole/server/chs/makefile) | — | — |
| [base/mvdm/wow16/ole/server/cht](../../base/mvdm/wow16/ole/server/cht) | 3 | [base/mvdm/wow16/ole/server/cht/sources](../../base/mvdm/wow16/ole/server/cht/sources), [base/mvdm/wow16/ole/server/cht/makefile](../../base/mvdm/wow16/ole/server/cht/makefile) | — | — |
| [base/mvdm/wow16/ole/server/jpn](../../base/mvdm/wow16/ole/server/jpn) | 3 | [base/mvdm/wow16/ole/server/jpn/sources](../../base/mvdm/wow16/ole/server/jpn/sources), [base/mvdm/wow16/ole/server/jpn/makefile](../../base/mvdm/wow16/ole/server/jpn/makefile) | — | — |
| [base/mvdm/wow16/ole/server/kor](../../base/mvdm/wow16/ole/server/kor) | 3 | [base/mvdm/wow16/ole/server/kor/sources](../../base/mvdm/wow16/ole/server/kor/sources), [base/mvdm/wow16/ole/server/kor/makefile](../../base/mvdm/wow16/ole/server/kor/makefile) | — | — |
| [base/mvdm/wow16/ole/server/usa](../../base/mvdm/wow16/ole/server/usa) | 3 | [base/mvdm/wow16/ole/server/usa/sources](../../base/mvdm/wow16/ole/server/usa/sources), [base/mvdm/wow16/ole/server/usa/makefile](../../base/mvdm/wow16/ole/server/usa/makefile) | — | — |
| [base/mvdm/wow16/publish](../../base/mvdm/wow16/publish) | 2 | [base/mvdm/wow16/publish/sources](../../base/mvdm/wow16/publish/sources), [base/mvdm/wow16/publish/makefile](../../base/mvdm/wow16/publish/makefile) | — | `LIBRARY` |
| [base/mvdm/wow16/rasapi16](../../base/mvdm/wow16/rasapi16) | 9 | [base/mvdm/wow16/rasapi16/dirs](../../base/mvdm/wow16/rasapi16/dirs) | — | — |
| [base/mvdm/wow16/rasapi16/usa](../../base/mvdm/wow16/rasapi16/usa) | 3 | [base/mvdm/wow16/rasapi16/usa/sources](../../base/mvdm/wow16/rasapi16/usa/sources), [base/mvdm/wow16/rasapi16/usa/makefile](../../base/mvdm/wow16/rasapi16/usa/makefile) | — | — |
| [base/mvdm/wow16/regedit](../../base/mvdm/wow16/regedit) | 27 | [base/mvdm/wow16/regedit/dirs](../../base/mvdm/wow16/regedit/dirs) | — | — |
| [base/mvdm/wow16/regedit/messages](../../base/mvdm/wow16/regedit/messages) | 0 | — | — | — |
| [base/mvdm/wow16/regedit/messages/usa](../../base/mvdm/wow16/regedit/messages/usa) | 4 | — | — | — |
| [base/mvdm/wow16/regedit/usa](../../base/mvdm/wow16/regedit/usa) | 3 | [base/mvdm/wow16/regedit/usa/sources](../../base/mvdm/wow16/regedit/usa/sources), [base/mvdm/wow16/regedit/usa/makefile](../../base/mvdm/wow16/regedit/usa/makefile) | — | — |
| [base/mvdm/wow16/shell](../../base/mvdm/wow16/shell) | 8 | [base/mvdm/wow16/shell/dirs](../../base/mvdm/wow16/shell/dirs) | — | — |
| [base/mvdm/wow16/shell/library](../../base/mvdm/wow16/shell/library) | 1 | — | — | — |
| [base/mvdm/wow16/shell/usa](../../base/mvdm/wow16/shell/usa) | 3 | [base/mvdm/wow16/shell/usa/sources](../../base/mvdm/wow16/shell/usa/sources), [base/mvdm/wow16/shell/usa/makefile](../../base/mvdm/wow16/shell/usa/makefile) | — | — |
| [base/mvdm/wow16/sherlock](../../base/mvdm/wow16/sherlock) | 18 | [base/mvdm/wow16/sherlock/dirs](../../base/mvdm/wow16/sherlock/dirs) | — | — |
| [base/mvdm/wow16/sherlock/messages](../../base/mvdm/wow16/sherlock/messages) | 0 | — | — | — |
| [base/mvdm/wow16/sherlock/messages/usa](../../base/mvdm/wow16/sherlock/messages/usa) | 2 | — | — | — |
| [base/mvdm/wow16/sherlock/usa](../../base/mvdm/wow16/sherlock/usa) | 3 | [base/mvdm/wow16/sherlock/usa/sources](../../base/mvdm/wow16/sherlock/usa/sources), [base/mvdm/wow16/sherlock/usa/makefile](../../base/mvdm/wow16/sherlock/usa/makefile) | — | — |
| [base/mvdm/wow16/system](../../base/mvdm/wow16/system) | 22 | [base/mvdm/wow16/system/dirs](../../base/mvdm/wow16/system/dirs) | — | — |
| [base/mvdm/wow16/system/chp](../../base/mvdm/wow16/system/chp) | 4 | [base/mvdm/wow16/system/chp/sources](../../base/mvdm/wow16/system/chp/sources), [base/mvdm/wow16/system/chp/makefile](../../base/mvdm/wow16/system/chp/makefile) | — | — |
| [base/mvdm/wow16/system/chs](../../base/mvdm/wow16/system/chs) | 4 | [base/mvdm/wow16/system/chs/sources](../../base/mvdm/wow16/system/chs/sources), [base/mvdm/wow16/system/chs/makefile](../../base/mvdm/wow16/system/chs/makefile) | — | — |
| [base/mvdm/wow16/system/cht](../../base/mvdm/wow16/system/cht) | 4 | [base/mvdm/wow16/system/cht/sources](../../base/mvdm/wow16/system/cht/sources), [base/mvdm/wow16/system/cht/makefile](../../base/mvdm/wow16/system/cht/makefile) | — | — |
| [base/mvdm/wow16/system/jpn](../../base/mvdm/wow16/system/jpn) | 4 | [base/mvdm/wow16/system/jpn/sources](../../base/mvdm/wow16/system/jpn/sources), [base/mvdm/wow16/system/jpn/makefile](../../base/mvdm/wow16/system/jpn/makefile) | — | — |
| [base/mvdm/wow16/system/kor](../../base/mvdm/wow16/system/kor) | 4 | [base/mvdm/wow16/system/kor/sources](../../base/mvdm/wow16/system/kor/sources), [base/mvdm/wow16/system/kor/makefile](../../base/mvdm/wow16/system/kor/makefile) | — | — |
| [base/mvdm/wow16/system/nec_98](../../base/mvdm/wow16/system/nec_98) | 4 | [base/mvdm/wow16/system/nec_98/sources](../../base/mvdm/wow16/system/nec_98/sources), [base/mvdm/wow16/system/nec_98/makefile](../../base/mvdm/wow16/system/nec_98/makefile) | — | — |
| [base/mvdm/wow16/system/usa](../../base/mvdm/wow16/system/usa) | 4 | [base/mvdm/wow16/system/usa/sources](../../base/mvdm/wow16/system/usa/sources), [base/mvdm/wow16/system/usa/makefile](../../base/mvdm/wow16/system/usa/makefile) | — | — |
| [base/mvdm/wow16/test](../../base/mvdm/wow16/test) | 1 | [base/mvdm/wow16/test/dirs](../../base/mvdm/wow16/test/dirs) | — | — |
| [base/mvdm/wow16/test/hello](../../base/mvdm/wow16/test/hello) | 8 | [base/mvdm/wow16/test/hello/dirs](../../base/mvdm/wow16/test/hello/dirs), [base/mvdm/wow16/test/hello/makefile](../../base/mvdm/wow16/test/hello/makefile) | — | — |
| [base/mvdm/wow16/test/hello/usa](../../base/mvdm/wow16/test/hello/usa) | 3 | [base/mvdm/wow16/test/hello/usa/sources](../../base/mvdm/wow16/test/hello/usa/sources), [base/mvdm/wow16/test/hello/usa/makefile](../../base/mvdm/wow16/test/hello/usa/makefile) | — | — |
| [base/mvdm/wow16/test/shell](../../base/mvdm/wow16/test/shell) | 10 | [base/mvdm/wow16/test/shell/dirs](../../base/mvdm/wow16/test/shell/dirs) | — | — |
| [base/mvdm/wow16/test/shell/chp](../../base/mvdm/wow16/test/shell/chp) | 3 | [base/mvdm/wow16/test/shell/chp/sources](../../base/mvdm/wow16/test/shell/chp/sources), [base/mvdm/wow16/test/shell/chp/makefile](../../base/mvdm/wow16/test/shell/chp/makefile) | — | — |
| [base/mvdm/wow16/test/shell/chs](../../base/mvdm/wow16/test/shell/chs) | 3 | [base/mvdm/wow16/test/shell/chs/sources](../../base/mvdm/wow16/test/shell/chs/sources), [base/mvdm/wow16/test/shell/chs/makefile](../../base/mvdm/wow16/test/shell/chs/makefile) | — | — |
| [base/mvdm/wow16/test/shell/cht](../../base/mvdm/wow16/test/shell/cht) | 3 | [base/mvdm/wow16/test/shell/cht/sources](../../base/mvdm/wow16/test/shell/cht/sources), [base/mvdm/wow16/test/shell/cht/makefile](../../base/mvdm/wow16/test/shell/cht/makefile) | — | — |
| [base/mvdm/wow16/test/shell/jpn](../../base/mvdm/wow16/test/shell/jpn) | 3 | [base/mvdm/wow16/test/shell/jpn/sources](../../base/mvdm/wow16/test/shell/jpn/sources), [base/mvdm/wow16/test/shell/jpn/makefile](../../base/mvdm/wow16/test/shell/jpn/makefile) | — | — |
| [base/mvdm/wow16/test/shell/kor](../../base/mvdm/wow16/test/shell/kor) | 3 | [base/mvdm/wow16/test/shell/kor/sources](../../base/mvdm/wow16/test/shell/kor/sources), [base/mvdm/wow16/test/shell/kor/makefile](../../base/mvdm/wow16/test/shell/kor/makefile) | — | — |
| [base/mvdm/wow16/test/shell/usa](../../base/mvdm/wow16/test/shell/usa) | 3 | [base/mvdm/wow16/test/shell/usa/sources](../../base/mvdm/wow16/test/shell/usa/sources), [base/mvdm/wow16/test/shell/usa/makefile](../../base/mvdm/wow16/test/shell/usa/makefile) | — | — |
| [base/mvdm/wow16/timer](../../base/mvdm/wow16/timer) | 13 | [base/mvdm/wow16/timer/dirs](../../base/mvdm/wow16/timer/dirs) | — | — |
| [base/mvdm/wow16/timer/messages](../../base/mvdm/wow16/timer/messages) | 0 | — | — | — |
| [base/mvdm/wow16/timer/messages/usa](../../base/mvdm/wow16/timer/messages/usa) | 2 | — | — | — |
| [base/mvdm/wow16/timer/nec_98](../../base/mvdm/wow16/timer/nec_98) | 3 | [base/mvdm/wow16/timer/nec_98/sources](../../base/mvdm/wow16/timer/nec_98/sources), [base/mvdm/wow16/timer/nec_98/makefile](../../base/mvdm/wow16/timer/nec_98/makefile) | — | — |
| [base/mvdm/wow16/timer/usa](../../base/mvdm/wow16/timer/usa) | 3 | [base/mvdm/wow16/timer/usa/sources](../../base/mvdm/wow16/timer/usa/sources), [base/mvdm/wow16/timer/usa/makefile](../../base/mvdm/wow16/timer/usa/makefile) | — | — |
| [base/mvdm/wow16/toolhelp](../../base/mvdm/wow16/toolhelp) | 37 | [base/mvdm/wow16/toolhelp/dirs](../../base/mvdm/wow16/toolhelp/dirs) | — | — |
| [base/mvdm/wow16/toolhelp/nec_98](../../base/mvdm/wow16/toolhelp/nec_98) | 3 | [base/mvdm/wow16/toolhelp/nec_98/sources](../../base/mvdm/wow16/toolhelp/nec_98/sources), [base/mvdm/wow16/toolhelp/nec_98/makefile](../../base/mvdm/wow16/toolhelp/nec_98/makefile) | — | — |
| [base/mvdm/wow16/toolhelp/usa](../../base/mvdm/wow16/toolhelp/usa) | 3 | [base/mvdm/wow16/toolhelp/usa/sources](../../base/mvdm/wow16/toolhelp/usa/sources), [base/mvdm/wow16/toolhelp/usa/makefile](../../base/mvdm/wow16/toolhelp/usa/makefile) | — | — |
| [base/mvdm/wow16/user](../../base/mvdm/wow16/user) | 72 | [base/mvdm/wow16/user/dirs](../../base/mvdm/wow16/user/dirs) | — | — |
| [base/mvdm/wow16/user/chp](../../base/mvdm/wow16/user/chp) | 3 | [base/mvdm/wow16/user/chp/sources](../../base/mvdm/wow16/user/chp/sources), [base/mvdm/wow16/user/chp/makefile](../../base/mvdm/wow16/user/chp/makefile) | — | — |
| [base/mvdm/wow16/user/chs](../../base/mvdm/wow16/user/chs) | 3 | [base/mvdm/wow16/user/chs/sources](../../base/mvdm/wow16/user/chs/sources), [base/mvdm/wow16/user/chs/makefile](../../base/mvdm/wow16/user/chs/makefile) | — | — |
| [base/mvdm/wow16/user/cht](../../base/mvdm/wow16/user/cht) | 3 | [base/mvdm/wow16/user/cht/sources](../../base/mvdm/wow16/user/cht/sources), [base/mvdm/wow16/user/cht/makefile](../../base/mvdm/wow16/user/cht/makefile) | — | — |
| [base/mvdm/wow16/user/jpn](../../base/mvdm/wow16/user/jpn) | 3 | [base/mvdm/wow16/user/jpn/sources](../../base/mvdm/wow16/user/jpn/sources), [base/mvdm/wow16/user/jpn/makefile](../../base/mvdm/wow16/user/jpn/makefile) | — | — |
| [base/mvdm/wow16/user/kor](../../base/mvdm/wow16/user/kor) | 3 | [base/mvdm/wow16/user/kor/sources](../../base/mvdm/wow16/user/kor/sources), [base/mvdm/wow16/user/kor/makefile](../../base/mvdm/wow16/user/kor/makefile) | — | — |
| [base/mvdm/wow16/user/usa](../../base/mvdm/wow16/user/usa) | 3 | [base/mvdm/wow16/user/usa/sources](../../base/mvdm/wow16/user/usa/sources), [base/mvdm/wow16/user/usa/makefile](../../base/mvdm/wow16/user/usa/makefile) | — | — |
| [base/mvdm/wow16/wfwnet](../../base/mvdm/wow16/wfwnet) | 15 | [base/mvdm/wow16/wfwnet/dirs](../../base/mvdm/wow16/wfwnet/dirs) | — | — |
| [base/mvdm/wow16/wfwnet/nec_98](../../base/mvdm/wow16/wfwnet/nec_98) | 3 | [base/mvdm/wow16/wfwnet/nec_98/sources](../../base/mvdm/wow16/wfwnet/nec_98/sources), [base/mvdm/wow16/wfwnet/nec_98/makefile](../../base/mvdm/wow16/wfwnet/nec_98/makefile) | — | — |
| [base/mvdm/wow16/wfwnet/usa](../../base/mvdm/wow16/wfwnet/usa) | 3 | [base/mvdm/wow16/wfwnet/usa/sources](../../base/mvdm/wow16/wfwnet/usa/sources), [base/mvdm/wow16/wfwnet/usa/makefile](../../base/mvdm/wow16/wfwnet/usa/makefile) | — | — |
| [base/mvdm/wow16/wifeman](../../base/mvdm/wow16/wifeman) | 11 | [base/mvdm/wow16/wifeman/dirs](../../base/mvdm/wow16/wifeman/dirs) | — | — |
| [base/mvdm/wow16/wifeman/chp](../../base/mvdm/wow16/wifeman/chp) | 3 | [base/mvdm/wow16/wifeman/chp/sources](../../base/mvdm/wow16/wifeman/chp/sources), [base/mvdm/wow16/wifeman/chp/makefile](../../base/mvdm/wow16/wifeman/chp/makefile) | — | — |
| [base/mvdm/wow16/wifeman/chs](../../base/mvdm/wow16/wifeman/chs) | 3 | [base/mvdm/wow16/wifeman/chs/sources](../../base/mvdm/wow16/wifeman/chs/sources), [base/mvdm/wow16/wifeman/chs/makefile](../../base/mvdm/wow16/wifeman/chs/makefile) | — | — |
| [base/mvdm/wow16/wifeman/cht](../../base/mvdm/wow16/wifeman/cht) | 3 | [base/mvdm/wow16/wifeman/cht/sources](../../base/mvdm/wow16/wifeman/cht/sources), [base/mvdm/wow16/wifeman/cht/makefile](../../base/mvdm/wow16/wifeman/cht/makefile) | — | — |
| [base/mvdm/wow16/wifeman/jpn](../../base/mvdm/wow16/wifeman/jpn) | 3 | [base/mvdm/wow16/wifeman/jpn/sources](../../base/mvdm/wow16/wifeman/jpn/sources), [base/mvdm/wow16/wifeman/jpn/makefile](../../base/mvdm/wow16/wifeman/jpn/makefile) | — | — |
| [base/mvdm/wow16/wifeman/kor](../../base/mvdm/wow16/wifeman/kor) | 3 | [base/mvdm/wow16/wifeman/kor/sources](../../base/mvdm/wow16/wifeman/kor/sources), [base/mvdm/wow16/wifeman/kor/makefile](../../base/mvdm/wow16/wifeman/kor/makefile) | — | — |
| [base/mvdm/wow16/wifeman/usa](../../base/mvdm/wow16/wifeman/usa) | 3 | [base/mvdm/wow16/wifeman/usa/sources](../../base/mvdm/wow16/wifeman/usa/sources), [base/mvdm/wow16/wifeman/usa/makefile](../../base/mvdm/wow16/wifeman/usa/makefile) | — | — |
| [base/mvdm/wow16/win87em](../../base/mvdm/wow16/win87em) | 63 | [base/mvdm/wow16/win87em/makefile](../../base/mvdm/wow16/win87em/makefile) | — | — |
| [base/mvdm/wow16/winnls](../../base/mvdm/wow16/winnls) | 8 | [base/mvdm/wow16/winnls/dirs](../../base/mvdm/wow16/winnls/dirs) | — | — |
| [base/mvdm/wow16/winnls/chs](../../base/mvdm/wow16/winnls/chs) | 3 | [base/mvdm/wow16/winnls/chs/sources](../../base/mvdm/wow16/winnls/chs/sources), [base/mvdm/wow16/winnls/chs/makefile](../../base/mvdm/wow16/winnls/chs/makefile) | — | — |
| [base/mvdm/wow16/winnls/cht](../../base/mvdm/wow16/winnls/cht) | 3 | [base/mvdm/wow16/winnls/cht/sources](../../base/mvdm/wow16/winnls/cht/sources), [base/mvdm/wow16/winnls/cht/makefile](../../base/mvdm/wow16/winnls/cht/makefile) | — | — |
| [base/mvdm/wow16/winnls/jpn](../../base/mvdm/wow16/winnls/jpn) | 3 | [base/mvdm/wow16/winnls/jpn/sources](../../base/mvdm/wow16/winnls/jpn/sources), [base/mvdm/wow16/winnls/jpn/makefile](../../base/mvdm/wow16/winnls/jpn/makefile) | — | — |
| [base/mvdm/wow16/winnls/kor](../../base/mvdm/wow16/winnls/kor) | 3 | [base/mvdm/wow16/winnls/kor/sources](../../base/mvdm/wow16/winnls/kor/sources), [base/mvdm/wow16/winnls/kor/makefile](../../base/mvdm/wow16/winnls/kor/makefile) | — | — |
| [base/mvdm/wow16/winnls/usa](../../base/mvdm/wow16/winnls/usa) | 3 | [base/mvdm/wow16/winnls/usa/sources](../../base/mvdm/wow16/winnls/usa/sources), [base/mvdm/wow16/winnls/usa/makefile](../../base/mvdm/wow16/winnls/usa/makefile) | — | — |
| [base/mvdm/wow16/winoldap](../../base/mvdm/wow16/winoldap) | 6 | [base/mvdm/wow16/winoldap/dirs](../../base/mvdm/wow16/winoldap/dirs) | — | — |
| [base/mvdm/wow16/winoldap/usa](../../base/mvdm/wow16/winoldap/usa) | 3 | [base/mvdm/wow16/winoldap/usa/sources](../../base/mvdm/wow16/winoldap/usa/sources), [base/mvdm/wow16/winoldap/usa/makefile](../../base/mvdm/wow16/winoldap/usa/makefile) | — | — |
| [base/mvdm/wow16/winsock](../../base/mvdm/wow16/winsock) | 7 | [base/mvdm/wow16/winsock/dirs](../../base/mvdm/wow16/winsock/dirs) | — | — |
| [base/mvdm/wow16/winsock/usa](../../base/mvdm/wow16/winsock/usa) | 3 | [base/mvdm/wow16/winsock/usa/sources](../../base/mvdm/wow16/winsock/usa/sources), [base/mvdm/wow16/winsock/usa/makefile](../../base/mvdm/wow16/winsock/usa/makefile) | — | — |
| [base/mvdm/wow16/winspool](../../base/mvdm/wow16/winspool) | 7 | [base/mvdm/wow16/winspool/dirs](../../base/mvdm/wow16/winspool/dirs) | — | — |
| [base/mvdm/wow16/winspool/usa](../../base/mvdm/wow16/winspool/usa) | 3 | [base/mvdm/wow16/winspool/usa/sources](../../base/mvdm/wow16/winspool/usa/sources), [base/mvdm/wow16/winspool/usa/makefile](../../base/mvdm/wow16/winspool/usa/makefile) | — | — |
| [base/mvdm/wow16/wowdeb](../../base/mvdm/wow16/wowdeb) | 6 | [base/mvdm/wow16/wowdeb/dirs](../../base/mvdm/wow16/wowdeb/dirs) | — | — |
| [base/mvdm/wow16/wowdeb/usa](../../base/mvdm/wow16/wowdeb/usa) | 3 | [base/mvdm/wow16/wowdeb/usa/sources](../../base/mvdm/wow16/wowdeb/usa/sources), [base/mvdm/wow16/wowdeb/usa/makefile](../../base/mvdm/wow16/wowdeb/usa/makefile) | — | — |
| [base/mvdm/wow16/write](../../base/mvdm/wow16/write) | 184 | [base/mvdm/wow16/write/makefile](../../base/mvdm/wow16/write/makefile) | — | — |
| [base/mvdm/wow16/write/messages](../../base/mvdm/wow16/write/messages) | 0 | — | — | — |
| [base/mvdm/wow16/write/messages/usa](../../base/mvdm/wow16/write/messages/usa) | 4 | — | — | — |
| [base/mvdm/wow32](../../base/mvdm/wow32) | 215 | [base/mvdm/wow32/dirs](../../base/mvdm/wow32/dirs) | — | — |
| [base/mvdm/wow32/chp](../../base/mvdm/wow32/chp) | 3 | [base/mvdm/wow32/chp/sources](../../base/mvdm/wow32/chp/sources), [base/mvdm/wow32/chp/makefile](../../base/mvdm/wow32/chp/makefile) | — | — |
| [base/mvdm/wow32/chs](../../base/mvdm/wow32/chs) | 3 | [base/mvdm/wow32/chs/sources](../../base/mvdm/wow32/chs/sources), [base/mvdm/wow32/chs/makefile](../../base/mvdm/wow32/chs/makefile) | — | — |
| [base/mvdm/wow32/cht](../../base/mvdm/wow32/cht) | 3 | [base/mvdm/wow32/cht/sources](../../base/mvdm/wow32/cht/sources), [base/mvdm/wow32/cht/makefile](../../base/mvdm/wow32/cht/makefile) | — | — |
| [base/mvdm/wow32/daytona](../../base/mvdm/wow32/daytona) | 3 | [base/mvdm/wow32/daytona/sources](../../base/mvdm/wow32/daytona/sources), [base/mvdm/wow32/daytona/makefile](../../base/mvdm/wow32/daytona/makefile) | — | — |
| [base/mvdm/wow32/i386](../../base/mvdm/wow32/i386) | 3 | [base/mvdm/wow32/i386/sources](../../base/mvdm/wow32/i386/sources) | — | — |
| [base/mvdm/wow32/jpn](../../base/mvdm/wow32/jpn) | 3 | [base/mvdm/wow32/jpn/sources](../../base/mvdm/wow32/jpn/sources), [base/mvdm/wow32/jpn/makefile](../../base/mvdm/wow32/jpn/makefile) | — | — |
| [base/mvdm/wow32/kor](../../base/mvdm/wow32/kor) | 3 | [base/mvdm/wow32/kor/sources](../../base/mvdm/wow32/kor/sources), [base/mvdm/wow32/kor/makefile](../../base/mvdm/wow32/kor/makefile) | — | — |
| [base/mvdm/wow32/nec_98](../../base/mvdm/wow32/nec_98) | 3 | [base/mvdm/wow32/nec_98/sources](../../base/mvdm/wow32/nec_98/sources), [base/mvdm/wow32/nec_98/makefile](../../base/mvdm/wow32/nec_98/makefile) | — | — |
| [base/mvdm/xms.486](../../base/mvdm/xms.486) | 10 | [base/mvdm/xms.486/dirs](../../base/mvdm/xms.486/dirs) | — | — |
| [base/mvdm/xms.486/daytona](../../base/mvdm/xms.486/daytona) | 2 | [base/mvdm/xms.486/daytona/sources](../../base/mvdm/xms.486/daytona/sources), [base/mvdm/xms.486/daytona/makefile](../../base/mvdm/xms.486/daytona/makefile) | — | — |
| [base/mvdm/xms.486/i386](../../base/mvdm/xms.486/i386) | 1 | — | — | — |
| [base/mvdm/xms.486/nec_98](../../base/mvdm/xms.486/nec_98) | 2 | [base/mvdm/xms.486/nec_98/sources](../../base/mvdm/xms.486/nec_98/sources), [base/mvdm/xms.486/nec_98/makefile](../../base/mvdm/xms.486/nec_98/makefile) | — | — |

## `base/ntdll/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [base/ntdll](../../base/ntdll) | 65 | [base/ntdll/dirs](../../base/ntdll/dirs) | — | — |
| [base/ntdll/alpha](../../base/ntdll/alpha) | 5 | [base/ntdll/alpha/sources](../../base/ntdll/alpha/sources) | — | — |
| [base/ntdll/amd64](../../base/ntdll/amd64) | 4 | [base/ntdll/amd64/sources](../../base/ntdll/amd64/sources) | — | — |
| [base/ntdll/axp64](../../base/ntdll/axp64) | 1 | [base/ntdll/axp64/sources](../../base/ntdll/axp64/sources) | — | — |
| [base/ntdll/daytona](../../base/ntdll/daytona) | 3 | [base/ntdll/daytona/sources](../../base/ntdll/daytona/sources), [base/ntdll/daytona/makefile](../../base/ntdll/daytona/makefile) | `ntdll` | `DYNLINK` |
| [base/ntdll/i386](../../base/ntdll/i386) | 33 | [base/ntdll/i386/sources](../../base/ntdll/i386/sources) | — | — |
| [base/ntdll/ia64](../../base/ntdll/ia64) | 4 | [base/ntdll/ia64/sources](../../base/ntdll/ia64/sources) | — | — |
| [base/ntdll/wow6432](../../base/ntdll/wow6432) | 7 | [base/ntdll/wow6432/sources](../../base/ntdll/wow6432/sources), [base/ntdll/wow6432/makefile](../../base/ntdll/wow6432/makefile) | `ntdll` | `DYNLINK` |
| [base/ntdll/wow6432/amd64](../../base/ntdll/wow6432/amd64) | 1 | — | — | — |
| [base/ntdll/wow6432/i386](../../base/ntdll/wow6432/i386) | 2 | — | — | — |

## `base/ntdllsym/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [base/ntdllsym](../../base/ntdllsym) | 4 | [base/ntdllsym/sources](../../base/ntdllsym/sources), [base/ntdllsym/makefile](../../base/ntdllsym/makefile) | — | `NOTARGET` |

## `base/ntos/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [base/ntos](../../base/ntos) | 5 | [base/ntos/dirs](../../base/ntos/dirs) | — | — |
| [base/ntos/arb](../../base/ntos/arb) | 5 | [base/ntos/arb/dirs](../../base/ntos/arb/dirs) | — | — |
| [base/ntos/arb/hal](../../base/ntos/arb/hal) | 2 | [base/ntos/arb/hal/sources](../../base/ntos/arb/hal/sources), [base/ntos/arb/hal/makefile](../../base/ntos/arb/hal/makefile) | `halarbiter` | `LIBRARY` |
| [base/ntos/arb/lib](../../base/ntos/arb/lib) | 2 | [base/ntos/arb/lib/sources](../../base/ntos/arb/lib/sources), [base/ntos/arb/lib/makefile](../../base/ntos/arb/lib/makefile) | `arbiter` | `LIBRARY` |
| [base/ntos/arb/mp](../../base/ntos/arb/mp) | 2 | [base/ntos/arb/mp/sources](../../base/ntos/arb/mp/sources), [base/ntos/arb/mp/makefile](../../base/ntos/arb/mp/makefile) | — | — |
| [base/ntos/arb/up](../../base/ntos/arb/up) | 2 | [base/ntos/arb/up/sources](../../base/ntos/arb/up/sources), [base/ntos/arb/up/makefile](../../base/ntos/arb/up/makefile) | — | — |
| [base/ntos/cache](../../base/ntos/cache) | 17 | [base/ntos/cache/dirs](../../base/ntos/cache/dirs) | — | — |
| [base/ntos/cache/mp](../../base/ntos/cache/mp) | 2 | [base/ntos/cache/mp/sources](../../base/ntos/cache/mp/sources), [base/ntos/cache/mp/makefile](../../base/ntos/cache/mp/makefile) | — | — |
| [base/ntos/cache/spec](../../base/ntos/cache/spec) | 1 | — | — | — |
| [base/ntos/cache/up](../../base/ntos/cache/up) | 2 | [base/ntos/cache/up/sources](../../base/ntos/cache/up/sources), [base/ntos/cache/up/makefile](../../base/ntos/cache/up/makefile) | — | — |
| [base/ntos/config](../../base/ntos/config) | 62 | [base/ntos/config/dirs](../../base/ntos/config/dirs) | — | — |
| [base/ntos/config/alpha](../../base/ntos/config/alpha) | 2 | [base/ntos/config/alpha/sources](../../base/ntos/config/alpha/sources) | — | — |
| [base/ntos/config/amd64](../../base/ntos/config/amd64) | 6 | [base/ntos/config/amd64/sources](../../base/ntos/config/amd64/sources) | — | — |
| [base/ntos/config/axp64](../../base/ntos/config/axp64) | 1 | [base/ntos/config/axp64/sources](../../base/ntos/config/axp64/sources) | — | — |
| [base/ntos/config/boot](../../base/ntos/config/boot) | 2 | [base/ntos/config/boot/sources](../../base/ntos/config/boot/sources), [base/ntos/config/boot/makefile](../../base/ntos/config/boot/makefile) | `bconfig` | `LIBRARY` |
| [base/ntos/config/chkreg](../../base/ntos/config/chkreg) | 16 | [base/ntos/config/chkreg/sources](../../base/ntos/config/chkreg/sources), [base/ntos/config/chkreg/makefile](../../base/ntos/config/chkreg/makefile) | `chkreg` | `PROGRAM` |
| [base/ntos/config/cmkd](../../base/ntos/config/cmkd) | 10 | [base/ntos/config/cmkd/sources](../../base/ntos/config/cmkd/sources), [base/ntos/config/cmkd/makefile](../../base/ntos/config/cmkd/makefile) | `cmkd51` | `DYNLINK` |
| [base/ntos/config/i386](../../base/ntos/config/i386) | 9 | [base/ntos/config/i386/sources](../../base/ntos/config/i386/sources) | — | — |
| [base/ntos/config/ia64](../../base/ntos/config/ia64) | 3 | [base/ntos/config/ia64/sources](../../base/ntos/config/ia64/sources) | — | — |
| [base/ntos/config/mp](../../base/ntos/config/mp) | 2 | [base/ntos/config/mp/sources](../../base/ntos/config/mp/sources), [base/ntos/config/mp/makefile](../../base/ntos/config/mp/makefile) | — | — |
| [base/ntos/config/test](../../base/ntos/config/test) | 35 | [base/ntos/config/test/sources](../../base/ntos/config/test/sources), [base/ntos/config/test/makefile](../../base/ntos/config/test/makefile) | `regext` | `DYNLINK` |
| [base/ntos/config/up](../../base/ntos/config/up) | 2 | [base/ntos/config/up/sources](../../base/ntos/config/up/sources), [base/ntos/config/up/makefile](../../base/ntos/config/up/makefile) | — | — |
| [base/ntos/config/utils](../../base/ntos/config/utils) | 12 | [base/ntos/config/utils/sources](../../base/ntos/config/utils/sources), [base/ntos/config/utils/makefile](../../base/ntos/config/utils/makefile) | `hiveutil` | `LIBRARY` |
| [base/ntos/dbgk](../../base/ntos/dbgk) | 7 | [base/ntos/dbgk/dirs](../../base/ntos/dbgk/dirs) | — | — |
| [base/ntos/dbgk/mp](../../base/ntos/dbgk/mp) | 2 | [base/ntos/dbgk/mp/sources](../../base/ntos/dbgk/mp/sources), [base/ntos/dbgk/mp/makefile](../../base/ntos/dbgk/mp/makefile) | — | — |
| [base/ntos/dbgk/up](../../base/ntos/dbgk/up) | 2 | [base/ntos/dbgk/up/sources](../../base/ntos/dbgk/up/sources), [base/ntos/dbgk/up/makefile](../../base/ntos/dbgk/up/makefile) | — | — |
| [base/ntos/ex](../../base/ntos/ex) | 44 | [base/ntos/ex/dirs](../../base/ntos/ex/dirs) | — | — |
| [base/ntos/ex/alpha](../../base/ntos/ex/alpha) | 8 | [base/ntos/ex/alpha/sources](../../base/ntos/ex/alpha/sources) | — | — |
| [base/ntos/ex/amd64](../../base/ntos/ex/amd64) | 5 | [base/ntos/ex/amd64/sources](../../base/ntos/ex/amd64/sources) | — | — |
| [base/ntos/ex/axp64](../../base/ntos/ex/axp64) | 1 | [base/ntos/ex/axp64/sources](../../base/ntos/ex/axp64/sources) | — | — |
| [base/ntos/ex/i386](../../base/ntos/ex/i386) | 7 | [base/ntos/ex/i386/sources](../../base/ntos/ex/i386/sources) | — | — |
| [base/ntos/ex/ia64](../../base/ntos/ex/ia64) | 8 | [base/ntos/ex/ia64/sources](../../base/ntos/ex/ia64/sources) | — | — |
| [base/ntos/ex/mp](../../base/ntos/ex/mp) | 2 | [base/ntos/ex/mp/sources](../../base/ntos/ex/mp/sources), [base/ntos/ex/mp/makefile](../../base/ntos/ex/mp/makefile) | — | — |
| [base/ntos/ex/mp/obj](../../base/ntos/ex/mp/obj) | 0 | — | — | — |
| [base/ntos/ex/mp/obj/i386](../../base/ntos/ex/mp/obj/i386) | 2 | — | — | — |
| [base/ntos/ex/mp/obj/ia64](../../base/ntos/ex/mp/obj/ia64) | 2 | — | — | — |
| [base/ntos/ex/up](../../base/ntos/ex/up) | 2 | [base/ntos/ex/up/sources](../../base/ntos/ex/up/sources), [base/ntos/ex/up/makefile](../../base/ntos/ex/up/makefile) | — | — |
| [base/ntos/ex/up/obj](../../base/ntos/ex/up/obj) | 0 | — | — | — |
| [base/ntos/ex/up/obj/i386](../../base/ntos/ex/up/obj/i386) | 2 | — | — | — |
| [base/ntos/ex/up/obj/ia64](../../base/ntos/ex/up/obj/ia64) | 2 | — | — | — |
| [base/ntos/fsrtl](../../base/ntos/fsrtl) | 20 | [base/ntos/fsrtl/dirs](../../base/ntos/fsrtl/dirs) | — | — |
| [base/ntos/fsrtl/mp](../../base/ntos/fsrtl/mp) | 2 | [base/ntos/fsrtl/mp/sources](../../base/ntos/fsrtl/mp/sources), [base/ntos/fsrtl/mp/makefile](../../base/ntos/fsrtl/mp/makefile) | — | — |
| [base/ntos/fsrtl/up](../../base/ntos/fsrtl/up) | 2 | [base/ntos/fsrtl/up/sources](../../base/ntos/fsrtl/up/sources), [base/ntos/fsrtl/up/makefile](../../base/ntos/fsrtl/up/makefile) | — | — |
| [base/ntos/fstub](../../base/ntos/fstub) | 11 | [base/ntos/fstub/dirs](../../base/ntos/fstub/dirs) | — | — |
| [base/ntos/fstub/mp](../../base/ntos/fstub/mp) | 2 | [base/ntos/fstub/mp/sources](../../base/ntos/fstub/mp/sources), [base/ntos/fstub/mp/makefile](../../base/ntos/fstub/mp/makefile) | — | — |
| [base/ntos/fstub/up](../../base/ntos/fstub/up) | 2 | [base/ntos/fstub/up/sources](../../base/ntos/fstub/up/sources), [base/ntos/fstub/up/makefile](../../base/ntos/fstub/up/makefile) | — | — |
| [base/ntos/inc](../../base/ntos/inc) | 88 | — | — | — |
| [base/ntos/init](../../base/ntos/init) | 49 | [base/ntos/init/dirs](../../base/ntos/init/dirs) | — | — |
| [base/ntos/init/i386](../../base/ntos/init/i386) | 3 | [base/ntos/init/i386/sources](../../base/ntos/init/i386/sources) | — | — |
| [base/ntos/init/mp](../../base/ntos/init/mp) | 10 | [base/ntos/init/mp/sources](../../base/ntos/init/mp/sources), [base/ntos/init/mp/makefile](../../base/ntos/init/mp/makefile) | — | — |
| [base/ntos/init/pae](../../base/ntos/init/pae) | 3 | [base/ntos/init/pae/sources](../../base/ntos/init/pae/sources), [base/ntos/init/pae/makefile](../../base/ntos/init/pae/makefile) | — | — |
| [base/ntos/init/paemp](../../base/ntos/init/paemp) | 3 | [base/ntos/init/paemp/sources](../../base/ntos/init/paemp/sources), [base/ntos/init/paemp/makefile](../../base/ntos/init/paemp/makefile) | — | — |
| [base/ntos/init/up](../../base/ntos/init/up) | 11 | [base/ntos/init/up/sources](../../base/ntos/init/up/sources), [base/ntos/init/up/makefile](../../base/ntos/init/up/makefile) | — | — |
| [base/ntos/io](../../base/ntos/io) | 14 | [base/ntos/io/dirs](../../base/ntos/io/dirs) | — | — |
| [base/ntos/io/iomgr](../../base/ntos/io/iomgr) | 34 | [base/ntos/io/iomgr/dirs](../../base/ntos/io/iomgr/dirs) | — | — |
| [base/ntos/io/iomgr/ddk](../../base/ntos/io/iomgr/ddk) | 3 | [base/ntos/io/iomgr/ddk/sources](../../base/ntos/io/iomgr/ddk/sources), [base/ntos/io/iomgr/ddk/makefile](../../base/ntos/io/iomgr/ddk/makefile) | `CSQ` | `LIBRARY` |
| [base/ntos/io/iomgr/mp](../../base/ntos/io/iomgr/mp) | 2 | [base/ntos/io/iomgr/mp/sources](../../base/ntos/io/iomgr/mp/sources), [base/ntos/io/iomgr/mp/makefile](../../base/ntos/io/iomgr/mp/makefile) | — | — |
| [base/ntos/io/iomgr/up](../../base/ntos/io/iomgr/up) | 2 | [base/ntos/io/iomgr/up/sources](../../base/ntos/io/iomgr/up/sources), [base/ntos/io/iomgr/up/makefile](../../base/ntos/io/iomgr/up/makefile) | — | — |
| [base/ntos/io/mp](../../base/ntos/io/mp) | 2 | [base/ntos/io/mp/sources](../../base/ntos/io/mp/sources), [base/ntos/io/mp/makefile](../../base/ntos/io/mp/makefile) | — | — |
| [base/ntos/io/pnpmgr](../../base/ntos/io/pnpmgr) | 63 | [base/ntos/io/pnpmgr/dirs](../../base/ntos/io/pnpmgr/dirs) | — | — |
| [base/ntos/io/pnpmgr/i386](../../base/ntos/io/pnpmgr/i386) | 3 | [base/ntos/io/pnpmgr/i386/sources](../../base/ntos/io/pnpmgr/i386/sources) | — | — |
| [base/ntos/io/pnpmgr/mp](../../base/ntos/io/pnpmgr/mp) | 2 | [base/ntos/io/pnpmgr/mp/sources](../../base/ntos/io/pnpmgr/mp/sources), [base/ntos/io/pnpmgr/mp/makefile](../../base/ntos/io/pnpmgr/mp/makefile) | — | — |
| [base/ntos/io/pnpmgr/up](../../base/ntos/io/pnpmgr/up) | 2 | [base/ntos/io/pnpmgr/up/sources](../../base/ntos/io/pnpmgr/up/sources), [base/ntos/io/pnpmgr/up/makefile](../../base/ntos/io/pnpmgr/up/makefile) | — | — |
| [base/ntos/io/up](../../base/ntos/io/up) | 2 | [base/ntos/io/up/sources](../../base/ntos/io/up/sources), [base/ntos/io/up/makefile](../../base/ntos/io/up/makefile) | — | — |
| [base/ntos/kd64](../../base/ntos/kd64) | 13 | [base/ntos/kd64/dirs](../../base/ntos/kd64/dirs) | — | — |
| [base/ntos/kd64/amd64](../../base/ntos/kd64/amd64) | 4 | [base/ntos/kd64/amd64/sources](../../base/ntos/kd64/amd64/sources) | — | — |
| [base/ntos/kd64/i386](../../base/ntos/kd64/i386) | 4 | [base/ntos/kd64/i386/sources](../../base/ntos/kd64/i386/sources) | — | — |
| [base/ntos/kd64/ia64](../../base/ntos/kd64/ia64) | 4 | [base/ntos/kd64/ia64/sources](../../base/ntos/kd64/ia64/sources) | — | — |
| [base/ntos/kd64/mp](../../base/ntos/kd64/mp) | 2 | [base/ntos/kd64/mp/sources](../../base/ntos/kd64/mp/sources), [base/ntos/kd64/mp/makefile](../../base/ntos/kd64/mp/makefile) | — | — |
| [base/ntos/kd64/pae](../../base/ntos/kd64/pae) | 3 | [base/ntos/kd64/pae/sources](../../base/ntos/kd64/pae/sources), [base/ntos/kd64/pae/makefile](../../base/ntos/kd64/pae/makefile) | — | — |
| [base/ntos/kd64/paemp](../../base/ntos/kd64/paemp) | 3 | [base/ntos/kd64/paemp/sources](../../base/ntos/kd64/paemp/sources), [base/ntos/kd64/paemp/makefile](../../base/ntos/kd64/paemp/makefile) | — | — |
| [base/ntos/kd64/up](../../base/ntos/kd64/up) | 2 | [base/ntos/kd64/up/sources](../../base/ntos/kd64/up/sources), [base/ntos/kd64/up/makefile](../../base/ntos/kd64/up/makefile) | — | — |
| [base/ntos/ke](../../base/ntos/ke) | 37 | [base/ntos/ke/dirs](../../base/ntos/ke/dirs) | — | — |
| [base/ntos/ke/alpha](../../base/ntos/ke/alpha) | 39 | [base/ntos/ke/alpha/sources](../../base/ntos/ke/alpha/sources) | — | — |
| [base/ntos/ke/amd64](../../base/ntos/ke/amd64) | 42 | [base/ntos/ke/amd64/sources](../../base/ntos/ke/amd64/sources) | — | — |
| [base/ntos/ke/axp64](../../base/ntos/ke/axp64) | 4 | [base/ntos/ke/axp64/sources](../../base/ntos/ke/axp64/sources) | — | — |
| [base/ntos/ke/i386](../../base/ntos/ke/i386) | 60 | [base/ntos/ke/i386/sources](../../base/ntos/ke/i386/sources) | — | — |
| [base/ntos/ke/ia64](../../base/ntos/ke/ia64) | 70 | [base/ntos/ke/ia64/sources](../../base/ntos/ke/ia64/sources) | — | — |
| [base/ntos/ke/mp](../../base/ntos/ke/mp) | 3 | [base/ntos/ke/mp/sources](../../base/ntos/ke/mp/sources), [base/ntos/ke/mp/makefile](../../base/ntos/ke/mp/makefile) | — | — |
| [base/ntos/ke/mp/i386](../../base/ntos/ke/mp/i386) | 1 | [base/ntos/ke/mp/i386/sources](../../base/ntos/ke/mp/i386/sources) | — | — |
| [base/ntos/ke/pae](../../base/ntos/ke/pae) | 3 | [base/ntos/ke/pae/sources](../../base/ntos/ke/pae/sources), [base/ntos/ke/pae/makefile](../../base/ntos/ke/pae/makefile) | — | — |
| [base/ntos/ke/paemp](../../base/ntos/ke/paemp) | 3 | [base/ntos/ke/paemp/sources](../../base/ntos/ke/paemp/sources), [base/ntos/ke/paemp/makefile](../../base/ntos/ke/paemp/makefile) | — | — |
| [base/ntos/ke/tests](../../base/ntos/ke/tests) | 0 | — | — | — |
| [base/ntos/ke/tests/npxstres](../../base/ntos/ke/tests/npxstres) | 2 | [base/ntos/ke/tests/npxstres/sources](../../base/ntos/ke/tests/npxstres/sources), [base/ntos/ke/tests/npxstres/makefile](../../base/ntos/ke/tests/npxstres/makefile) | `NPXSTRES` | `PROGRAM` |
| [base/ntos/ke/tests/npxstres/i386](../../base/ntos/ke/tests/npxstres/i386) | 8 | — | — | — |
| [base/ntos/ke/tests/x86div](../../base/ntos/ke/tests/x86div) | 2 | [base/ntos/ke/tests/x86div/sources](../../base/ntos/ke/tests/x86div/sources), [base/ntos/ke/tests/x86div/makefile](../../base/ntos/ke/tests/x86div/makefile) | `test` | `LIBRARY` |
| [base/ntos/ke/tests/x86div/i386](../../base/ntos/ke/tests/x86div/i386) | 2 | — | — | — |
| [base/ntos/ke/tests/xcphnd](../../base/ntos/ke/tests/xcphnd) | 3 | [base/ntos/ke/tests/xcphnd/sources](../../base/ntos/ke/tests/xcphnd/sources), [base/ntos/ke/tests/xcphnd/makefile](../../base/ntos/ke/tests/xcphnd/makefile) | `xcpt` | `PROGRAM` |
| [base/ntos/ke/up](../../base/ntos/ke/up) | 3 | [base/ntos/ke/up/sources](../../base/ntos/ke/up/sources), [base/ntos/ke/up/makefile](../../base/ntos/ke/up/makefile) | — | — |
| [base/ntos/ke/up/amd64](../../base/ntos/ke/up/amd64) | 1 | — | — | — |
| [base/ntos/lpc](../../base/ntos/lpc) | 18 | [base/ntos/lpc/dirs](../../base/ntos/lpc/dirs) | — | — |
| [base/ntos/lpc/alpha](../../base/ntos/lpc/alpha) | 2 | [base/ntos/lpc/alpha/sources](../../base/ntos/lpc/alpha/sources) | — | — |
| [base/ntos/lpc/amd64](../../base/ntos/lpc/amd64) | 2 | [base/ntos/lpc/amd64/sources](../../base/ntos/lpc/amd64/sources) | — | — |
| [base/ntos/lpc/axp64](../../base/ntos/lpc/axp64) | 1 | [base/ntos/lpc/axp64/sources](../../base/ntos/lpc/axp64/sources) | — | — |
| [base/ntos/lpc/i386](../../base/ntos/lpc/i386) | 2 | [base/ntos/lpc/i386/sources](../../base/ntos/lpc/i386/sources) | — | — |
| [base/ntos/lpc/ia64](../../base/ntos/lpc/ia64) | 2 | [base/ntos/lpc/ia64/sources](../../base/ntos/lpc/ia64/sources) | — | — |
| [base/ntos/lpc/mp](../../base/ntos/lpc/mp) | 3 | [base/ntos/lpc/mp/sources](../../base/ntos/lpc/mp/sources), [base/ntos/lpc/mp/makefile](../../base/ntos/lpc/mp/makefile) | — | — |
| [base/ntos/lpc/up](../../base/ntos/lpc/up) | 3 | [base/ntos/lpc/up/sources](../../base/ntos/lpc/up/sources), [base/ntos/lpc/up/makefile](../../base/ntos/lpc/up/makefile) | — | — |
| [base/ntos/mm](../../base/ntos/mm) | 62 | [base/ntos/mm/dirs](../../base/ntos/mm/dirs) | — | — |
| [base/ntos/mm/alpha](../../base/ntos/mm/alpha) | 8 | [base/ntos/mm/alpha/sources](../../base/ntos/mm/alpha/sources) | — | — |
| [base/ntos/mm/amd64](../../base/ntos/mm/amd64) | 4 | [base/ntos/mm/amd64/sources](../../base/ntos/mm/amd64/sources) | — | — |
| [base/ntos/mm/axp64](../../base/ntos/mm/axp64) | 8 | [base/ntos/mm/axp64/sources](../../base/ntos/mm/axp64/sources) | — | — |
| [base/ntos/mm/i386](../../base/ntos/mm/i386) | 7 | [base/ntos/mm/i386/sources](../../base/ntos/mm/i386/sources) | — | — |
| [base/ntos/mm/ia64](../../base/ntos/mm/ia64) | 6 | [base/ntos/mm/ia64/sources](../../base/ntos/mm/ia64/sources) | — | — |
| [base/ntos/mm/mp](../../base/ntos/mm/mp) | 2 | [base/ntos/mm/mp/sources](../../base/ntos/mm/mp/sources), [base/ntos/mm/mp/makefile](../../base/ntos/mm/mp/makefile) | — | — |
| [base/ntos/mm/pae](../../base/ntos/mm/pae) | 2 | [base/ntos/mm/pae/sources](../../base/ntos/mm/pae/sources), [base/ntos/mm/pae/makefile](../../base/ntos/mm/pae/makefile) | — | — |
| [base/ntos/mm/paemp](../../base/ntos/mm/paemp) | 2 | [base/ntos/mm/paemp/sources](../../base/ntos/mm/paemp/sources), [base/ntos/mm/paemp/makefile](../../base/ntos/mm/paemp/makefile) | — | — |
| [base/ntos/mm/up](../../base/ntos/mm/up) | 4 | [base/ntos/mm/up/sources](../../base/ntos/mm/up/sources), [base/ntos/mm/up/makefile](../../base/ntos/mm/up/makefile) | — | — |
| [base/ntos/nls](../../base/ntos/nls) | 6 | [base/ntos/nls/sources](../../base/ntos/nls/sources), [base/ntos/nls/makefile](../../base/ntos/nls/makefile) | `ntoshdrs` | `NOTARGET` |
| [base/ntos/ntsym](../../base/ntos/ntsym) | 3 | [base/ntos/ntsym/dirs](../../base/ntos/ntsym/dirs) | — | — |
| [base/ntos/ntsym/mp](../../base/ntos/ntsym/mp) | 3 | [base/ntos/ntsym/mp/sources](../../base/ntos/ntsym/mp/sources), [base/ntos/ntsym/mp/makefile](../../base/ntos/ntsym/mp/makefile) | — | — |
| [base/ntos/ntsym/pae](../../base/ntos/ntsym/pae) | 3 | [base/ntos/ntsym/pae/sources](../../base/ntos/ntsym/pae/sources), [base/ntos/ntsym/pae/makefile](../../base/ntos/ntsym/pae/makefile) | — | — |
| [base/ntos/ntsym/paemp](../../base/ntos/ntsym/paemp) | 3 | [base/ntos/ntsym/paemp/sources](../../base/ntos/ntsym/paemp/sources), [base/ntos/ntsym/paemp/makefile](../../base/ntos/ntsym/paemp/makefile) | — | — |
| [base/ntos/ntsym/up](../../base/ntos/ntsym/up) | 3 | [base/ntos/ntsym/up/sources](../../base/ntos/ntsym/up/sources), [base/ntos/ntsym/up/makefile](../../base/ntos/ntsym/up/makefile) | — | — |
| [base/ntos/ob](../../base/ntos/ob) | 24 | [base/ntos/ob/dirs](../../base/ntos/ob/dirs) | — | — |
| [base/ntos/ob/mp](../../base/ntos/ob/mp) | 2 | [base/ntos/ob/mp/sources](../../base/ntos/ob/mp/sources), [base/ntos/ob/mp/makefile](../../base/ntos/ob/mp/makefile) | — | — |
| [base/ntos/ob/up](../../base/ntos/ob/up) | 2 | [base/ntos/ob/up/sources](../../base/ntos/ob/up/sources), [base/ntos/ob/up/makefile](../../base/ntos/ob/up/makefile) | — | — |
| [base/ntos/perf](../../base/ntos/perf) | 8 | [base/ntos/perf/dirs](../../base/ntos/perf/dirs) | — | — |
| [base/ntos/perf/mp](../../base/ntos/perf/mp) | 2 | [base/ntos/perf/mp/sources](../../base/ntos/perf/mp/sources), [base/ntos/perf/mp/makefile](../../base/ntos/perf/mp/makefile) | — | — |
| [base/ntos/perf/up](../../base/ntos/perf/up) | 2 | [base/ntos/perf/up/sources](../../base/ntos/perf/up/sources), [base/ntos/perf/up/makefile](../../base/ntos/perf/up/makefile) | — | — |
| [base/ntos/po](../../base/ntos/po) | 29 | [base/ntos/po/dirs](../../base/ntos/po/dirs) | — | — |
| [base/ntos/po/alpha](../../base/ntos/po/alpha) | 2 | [base/ntos/po/alpha/sources](../../base/ntos/po/alpha/sources) | — | — |
| [base/ntos/po/amd64](../../base/ntos/po/amd64) | 2 | [base/ntos/po/amd64/sources](../../base/ntos/po/amd64/sources) | — | — |
| [base/ntos/po/axp64](../../base/ntos/po/axp64) | 1 | [base/ntos/po/axp64/sources](../../base/ntos/po/axp64/sources) | — | — |
| [base/ntos/po/i386](../../base/ntos/po/i386) | 2 | [base/ntos/po/i386/sources](../../base/ntos/po/i386/sources) | — | — |
| [base/ntos/po/ia64](../../base/ntos/po/ia64) | 2 | [base/ntos/po/ia64/sources](../../base/ntos/po/ia64/sources) | — | — |
| [base/ntos/po/mp](../../base/ntos/po/mp) | 2 | [base/ntos/po/mp/sources](../../base/ntos/po/mp/sources), [base/ntos/po/mp/makefile](../../base/ntos/po/mp/makefile) | — | — |
| [base/ntos/po/tests](../../base/ntos/po/tests) | 1 | [base/ntos/po/tests/dirs](../../base/ntos/po/tests/dirs) | — | — |
| [base/ntos/po/tests/bfile](../../base/ntos/po/tests/bfile) | 3 | [base/ntos/po/tests/bfile/sources](../../base/ntos/po/tests/bfile/sources), [base/ntos/po/tests/bfile/makefile](../../base/ntos/po/tests/bfile/makefile) | `bfile` | `LIBRARY` |
| [base/ntos/po/tests/ehib](../../base/ntos/po/tests/ehib) | 3 | [base/ntos/po/tests/ehib/sources](../../base/ntos/po/tests/ehib/sources), [base/ntos/po/tests/ehib/makefile](../../base/ntos/po/tests/ehib/makefile) | `ehib` | `LIBRARY` |
| [base/ntos/po/tests/qtime](../../base/ntos/po/tests/qtime) | 3 | [base/ntos/po/tests/qtime/sources](../../base/ntos/po/tests/qtime/sources), [base/ntos/po/tests/qtime/makefile](../../base/ntos/po/tests/qtime/makefile) | `qtime` | `LIBRARY` |
| [base/ntos/po/tests/shd](../../base/ntos/po/tests/shd) | 4 | [base/ntos/po/tests/shd/sources](../../base/ntos/po/tests/shd/sources), [base/ntos/po/tests/shd/makefile](../../base/ntos/po/tests/shd/makefile) | `shd` | `PROGRAM` |
| [base/ntos/po/tests/thrd](../../base/ntos/po/tests/thrd) | 3 | [base/ntos/po/tests/thrd/sources](../../base/ntos/po/tests/thrd/sources), [base/ntos/po/tests/thrd/makefile](../../base/ntos/po/tests/thrd/makefile) | `thrd` | `LIBRARY` |
| [base/ntos/po/tests/usermsg](../../base/ntos/po/tests/usermsg) | 11 | [base/ntos/po/tests/usermsg/sources](../../base/ntos/po/tests/usermsg/sources), [base/ntos/po/tests/usermsg/makefile](../../base/ntos/po/tests/usermsg/makefile) | `usermsg` | `LIBRARY` |
| [base/ntos/po/tests/vhib](../../base/ntos/po/tests/vhib) | 3 | [base/ntos/po/tests/vhib/sources](../../base/ntos/po/tests/vhib/sources), [base/ntos/po/tests/vhib/makefile](../../base/ntos/po/tests/vhib/makefile) | `vhib` | `LIBRARY` |
| [base/ntos/po/tests/wtime](../../base/ntos/po/tests/wtime) | 3 | [base/ntos/po/tests/wtime/sources](../../base/ntos/po/tests/wtime/sources), [base/ntos/po/tests/wtime/makefile](../../base/ntos/po/tests/wtime/makefile) | `wtime` | `LIBRARY` |
| [base/ntos/po/up](../../base/ntos/po/up) | 2 | [base/ntos/po/up/sources](../../base/ntos/po/up/sources), [base/ntos/po/up/makefile](../../base/ntos/po/up/makefile) | — | — |
| [base/ntos/ps](../../base/ntos/ps) | 19 | [base/ntos/ps/dirs](../../base/ntos/ps/dirs) | — | — |
| [base/ntos/ps/alpha](../../base/ntos/ps/alpha) | 5 | [base/ntos/ps/alpha/sources](../../base/ntos/ps/alpha/sources) | — | — |
| [base/ntos/ps/amd64](../../base/ntos/ps/amd64) | 4 | [base/ntos/ps/amd64/sources](../../base/ntos/ps/amd64/sources) | — | — |
| [base/ntos/ps/axp64](../../base/ntos/ps/axp64) | 1 | [base/ntos/ps/axp64/sources](../../base/ntos/ps/axp64/sources) | — | — |
| [base/ntos/ps/i386](../../base/ntos/ps/i386) | 4 | [base/ntos/ps/i386/sources](../../base/ntos/ps/i386/sources) | — | — |
| [base/ntos/ps/ia64](../../base/ntos/ps/ia64) | 5 | [base/ntos/ps/ia64/sources](../../base/ntos/ps/ia64/sources) | — | — |
| [base/ntos/ps/mp](../../base/ntos/ps/mp) | 2 | [base/ntos/ps/mp/sources](../../base/ntos/ps/mp/sources), [base/ntos/ps/mp/makefile](../../base/ntos/ps/mp/makefile) | — | — |
| [base/ntos/ps/up](../../base/ntos/ps/up) | 2 | [base/ntos/ps/up/sources](../../base/ntos/ps/up/sources), [base/ntos/ps/up/makefile](../../base/ntos/ps/up/makefile) | — | — |
| [base/ntos/raw](../../base/ntos/raw) | 15 | [base/ntos/raw/dirs](../../base/ntos/raw/dirs) | — | — |
| [base/ntos/raw/mp](../../base/ntos/raw/mp) | 2 | [base/ntos/raw/mp/sources](../../base/ntos/raw/mp/sources), [base/ntos/raw/mp/makefile](../../base/ntos/raw/mp/makefile) | — | — |
| [base/ntos/raw/up](../../base/ntos/raw/up) | 2 | [base/ntos/raw/up/sources](../../base/ntos/raw/up/sources), [base/ntos/raw/up/makefile](../../base/ntos/raw/up/makefile) | — | — |
| [base/ntos/rtl](../../base/ntos/rtl) | 107 | [base/ntos/rtl/dirs](../../base/ntos/rtl/dirs) | — | — |
| [base/ntos/rtl/amd64](../../base/ntos/rtl/amd64) | 12 | — | — | — |
| [base/ntos/rtl/boot](../../base/ntos/rtl/boot) | 2 | [base/ntos/rtl/boot/sources](../../base/ntos/rtl/boot/sources), [base/ntos/rtl/boot/makefile](../../base/ntos/rtl/boot/makefile) | `bldrrtl` | `LIBRARY` |
| [base/ntos/rtl/boot/alpha](../../base/ntos/rtl/boot/alpha) | 1 | [base/ntos/rtl/boot/alpha/sources](../../base/ntos/rtl/boot/alpha/sources) | — | — |
| [base/ntos/rtl/boot/axp64](../../base/ntos/rtl/boot/axp64) | 1 | [base/ntos/rtl/boot/axp64/sources](../../base/ntos/rtl/boot/axp64/sources) | — | — |
| [base/ntos/rtl/boot/i386](../../base/ntos/rtl/boot/i386) | 1 | [base/ntos/rtl/boot/i386/sources](../../base/ntos/rtl/boot/i386/sources) | — | — |
| [base/ntos/rtl/boot/ia64](../../base/ntos/rtl/boot/ia64) | 1 | [base/ntos/rtl/boot/ia64/sources](../../base/ntos/rtl/boot/ia64/sources) | — | — |
| [base/ntos/rtl/boot_dbg](../../base/ntos/rtl/boot_dbg) | 2 | [base/ntos/rtl/boot_dbg/sources](../../base/ntos/rtl/boot_dbg/sources), [base/ntos/rtl/boot_dbg/makefile](../../base/ntos/rtl/boot_dbg/makefile) | `bldrrtl_dbg` | `LIBRARY` |
| [base/ntos/rtl/boot_dbg/alpha](../../base/ntos/rtl/boot_dbg/alpha) | 1 | [base/ntos/rtl/boot_dbg/alpha/sources](../../base/ntos/rtl/boot_dbg/alpha/sources) | — | — |
| [base/ntos/rtl/boot_dbg/axp64](../../base/ntos/rtl/boot_dbg/axp64) | 1 | [base/ntos/rtl/boot_dbg/axp64/sources](../../base/ntos/rtl/boot_dbg/axp64/sources) | — | — |
| [base/ntos/rtl/boot_dbg/i386](../../base/ntos/rtl/boot_dbg/i386) | 1 | [base/ntos/rtl/boot_dbg/i386/sources](../../base/ntos/rtl/boot_dbg/i386/sources) | — | — |
| [base/ntos/rtl/boot_dbg/ia64](../../base/ntos/rtl/boot_dbg/ia64) | 1 | [base/ntos/rtl/boot_dbg/ia64/sources](../../base/ntos/rtl/boot_dbg/ia64/sources) | — | — |
| [base/ntos/rtl/i386](../../base/ntos/rtl/i386) | 21 | — | — | — |
| [base/ntos/rtl/ia64](../../base/ntos/rtl/ia64) | 16 | — | — | — |
| [base/ntos/rtl/mp](../../base/ntos/rtl/mp) | 3 | [base/ntos/rtl/mp/sources](../../base/ntos/rtl/mp/sources), [base/ntos/rtl/mp/makefile](../../base/ntos/rtl/mp/makefile) | `ntosrtl` | `LIBRARY` |
| [base/ntos/rtl/mp/alpha](../../base/ntos/rtl/mp/alpha) | 1 | [base/ntos/rtl/mp/alpha/sources](../../base/ntos/rtl/mp/alpha/sources) | — | — |
| [base/ntos/rtl/mp/amd64](../../base/ntos/rtl/mp/amd64) | 1 | [base/ntos/rtl/mp/amd64/sources](../../base/ntos/rtl/mp/amd64/sources) | — | — |
| [base/ntos/rtl/mp/axp64](../../base/ntos/rtl/mp/axp64) | 1 | [base/ntos/rtl/mp/axp64/sources](../../base/ntos/rtl/mp/axp64/sources) | — | — |
| [base/ntos/rtl/mp/i386](../../base/ntos/rtl/mp/i386) | 1 | [base/ntos/rtl/mp/i386/sources](../../base/ntos/rtl/mp/i386/sources) | — | — |
| [base/ntos/rtl/mp/ia64](../../base/ntos/rtl/mp/ia64) | 1 | [base/ntos/rtl/mp/ia64/sources](../../base/ntos/rtl/mp/ia64/sources) | — | — |
| [base/ntos/rtl/up](../../base/ntos/rtl/up) | 3 | [base/ntos/rtl/up/sources](../../base/ntos/rtl/up/sources), [base/ntos/rtl/up/makefile](../../base/ntos/rtl/up/makefile) | `ntosrtl` | `LIBRARY` |
| [base/ntos/rtl/up/alpha](../../base/ntos/rtl/up/alpha) | 1 | [base/ntos/rtl/up/alpha/sources](../../base/ntos/rtl/up/alpha/sources) | — | — |
| [base/ntos/rtl/up/amd64](../../base/ntos/rtl/up/amd64) | 1 | [base/ntos/rtl/up/amd64/sources](../../base/ntos/rtl/up/amd64/sources) | — | — |
| [base/ntos/rtl/up/axp64](../../base/ntos/rtl/up/axp64) | 1 | [base/ntos/rtl/up/axp64/sources](../../base/ntos/rtl/up/axp64/sources) | — | — |
| [base/ntos/rtl/up/i386](../../base/ntos/rtl/up/i386) | 1 | [base/ntos/rtl/up/i386/sources](../../base/ntos/rtl/up/i386/sources) | — | — |
| [base/ntos/rtl/up/ia64](../../base/ntos/rtl/up/ia64) | 1 | [base/ntos/rtl/up/ia64/sources](../../base/ntos/rtl/up/ia64/sources) | — | — |
| [base/ntos/rtl/user](../../base/ntos/rtl/user) | 4 | [base/ntos/rtl/user/sources](../../base/ntos/rtl/user/sources), [base/ntos/rtl/user/makefile](../../base/ntos/rtl/user/makefile) | `rtl` | `LIBRARY` |
| [base/ntos/rtl/user/alpha](../../base/ntos/rtl/user/alpha) | 1 | [base/ntos/rtl/user/alpha/sources](../../base/ntos/rtl/user/alpha/sources) | — | — |
| [base/ntos/rtl/user/amd64](../../base/ntos/rtl/user/amd64) | 1 | [base/ntos/rtl/user/amd64/sources](../../base/ntos/rtl/user/amd64/sources) | — | — |
| [base/ntos/rtl/user/axp64](../../base/ntos/rtl/user/axp64) | 1 | [base/ntos/rtl/user/axp64/sources](../../base/ntos/rtl/user/axp64/sources) | — | — |
| [base/ntos/rtl/user/i386](../../base/ntos/rtl/user/i386) | 1 | [base/ntos/rtl/user/i386/sources](../../base/ntos/rtl/user/i386/sources) | — | — |
| [base/ntos/rtl/user/ia64](../../base/ntos/rtl/user/ia64) | 1 | [base/ntos/rtl/user/ia64/sources](../../base/ntos/rtl/user/ia64/sources) | — | — |
| [base/ntos/rtl/userlib](../../base/ntos/rtl/userlib) | 3 | [base/ntos/rtl/userlib/sources](../../base/ntos/rtl/userlib/sources), [base/ntos/rtl/userlib/makefile](../../base/ntos/rtl/userlib/makefile) | `ntslist` | `LIBRARY` |
| [base/ntos/rtl/userlib/amd64](../../base/ntos/rtl/userlib/amd64) | 1 | [base/ntos/rtl/userlib/amd64/sources](../../base/ntos/rtl/userlib/amd64/sources) | — | — |
| [base/ntos/rtl/userlib/i386](../../base/ntos/rtl/userlib/i386) | 1 | [base/ntos/rtl/userlib/i386/sources](../../base/ntos/rtl/userlib/i386/sources) | — | — |
| [base/ntos/rtl/userlib/ia64](../../base/ntos/rtl/userlib/ia64) | 1 | [base/ntos/rtl/userlib/ia64/sources](../../base/ntos/rtl/userlib/ia64/sources) | — | — |
| [base/ntos/rtl/wow6432](../../base/ntos/rtl/wow6432) | 3 | [base/ntos/rtl/wow6432/sources](../../base/ntos/rtl/wow6432/sources), [base/ntos/rtl/wow6432/makefile](../../base/ntos/rtl/wow6432/makefile) | `rtl` | `LIBRARY` |
| [base/ntos/rtl/wow6432/alpha](../../base/ntos/rtl/wow6432/alpha) | 1 | [base/ntos/rtl/wow6432/alpha/sources](../../base/ntos/rtl/wow6432/alpha/sources) | — | — |
| [base/ntos/rtl/wow6432/i386](../../base/ntos/rtl/wow6432/i386) | 1 | [base/ntos/rtl/wow6432/i386/sources](../../base/ntos/rtl/wow6432/i386/sources) | — | — |
| [base/ntos/se](../../base/ntos/se) | 59 | [base/ntos/se/dirs](../../base/ntos/se/dirs) | — | — |
| [base/ntos/se/embedded](../../base/ntos/se/embedded) | 4 | [base/ntos/se/embedded/sources](../../base/ntos/se/embedded/sources), [base/ntos/se/embedded/makefile](../../base/ntos/se/embedded/makefile) | — | `NOTARGET` |
| [base/ntos/se/mp](../../base/ntos/se/mp) | 2 | [base/ntos/se/mp/sources](../../base/ntos/se/mp/sources), [base/ntos/se/mp/makefile](../../base/ntos/se/mp/makefile) | — | — |
| [base/ntos/se/nls](../../base/ntos/se/nls) | 1 | — | — | — |
| [base/ntos/se/up](../../base/ntos/se/up) | 2 | [base/ntos/se/up/sources](../../base/ntos/se/up/sources), [base/ntos/se/up/makefile](../../base/ntos/se/up/makefile) | — | — |
| [base/ntos/vdm](../../base/ntos/vdm) | 4 | [base/ntos/vdm/dirs](../../base/ntos/vdm/dirs) | — | — |
| [base/ntos/vdm/i386](../../base/ntos/vdm/i386) | 18 | — | — | — |
| [base/ntos/vdm/mp](../../base/ntos/vdm/mp) | 3 | [base/ntos/vdm/mp/sources](../../base/ntos/vdm/mp/sources), [base/ntos/vdm/mp/makefile](../../base/ntos/vdm/mp/makefile) | — | — |
| [base/ntos/vdm/up](../../base/ntos/vdm/up) | 3 | [base/ntos/vdm/up/sources](../../base/ntos/vdm/up/sources), [base/ntos/vdm/up/makefile](../../base/ntos/vdm/up/makefile) | — | — |
| [base/ntos/verifier](../../base/ntos/verifier) | 60 | [base/ntos/verifier/dirs](../../base/ntos/verifier/dirs) | — | — |
| [base/ntos/verifier/mp](../../base/ntos/verifier/mp) | 2 | [base/ntos/verifier/mp/sources](../../base/ntos/verifier/mp/sources), [base/ntos/verifier/mp/makefile](../../base/ntos/verifier/mp/makefile) | — | — |
| [base/ntos/verifier/up](../../base/ntos/verifier/up) | 2 | [base/ntos/verifier/up/sources](../../base/ntos/verifier/up/sources), [base/ntos/verifier/up/makefile](../../base/ntos/verifier/up/makefile) | — | — |
| [base/ntos/wmi](../../base/ntos/wmi) | 25 | [base/ntos/wmi/dirs](../../base/ntos/wmi/dirs) | — | — |
| [base/ntos/wmi/kdexts](../../base/ntos/wmi/kdexts) | 1 | [base/ntos/wmi/kdexts/dirs](../../base/ntos/wmi/kdexts/dirs) | — | — |
| [base/ntos/wmi/kdexts/tracing](../../base/ntos/wmi/kdexts/tracing) | 9 | [base/ntos/wmi/kdexts/tracing/sources](../../base/ntos/wmi/kdexts/tracing/sources), [base/ntos/wmi/kdexts/tracing/makefile](../../base/ntos/wmi/kdexts/tracing/makefile) | `wmiTrace` | `DYNLINK` |
| [base/ntos/wmi/mp](../../base/ntos/wmi/mp) | 2 | [base/ntos/wmi/mp/sources](../../base/ntos/wmi/mp/sources), [base/ntos/wmi/mp/makefile](../../base/ntos/wmi/mp/makefile) | — | — |
| [base/ntos/wmi/sample](../../base/ntos/wmi/sample) | 0 | — | — | — |
| [base/ntos/wmi/sample/mcahct](../../base/ntos/wmi/sample/mcahct) | 3 | [base/ntos/wmi/sample/mcahct/sources](../../base/ntos/wmi/sample/mcahct/sources), [base/ntos/wmi/sample/mcahct/makefile](../../base/ntos/wmi/sample/mcahct/makefile) | `mcahct` | `DRIVER` |
| [base/ntos/wmi/sample/mcahct/ia64](../../base/ntos/wmi/sample/mcahct/ia64) | 1 | — | — | — |
| [base/ntos/wmi/sample/wmifilt](../../base/ntos/wmi/sample/wmifilt) | 14 | [base/ntos/wmi/sample/wmifilt/sources](../../base/ntos/wmi/sample/wmifilt/sources), [base/ntos/wmi/sample/wmifilt/makefile](../../base/ntos/wmi/sample/wmifilt/makefile) | `wmifilt` | `DRIVER` |
| [base/ntos/wmi/sample/wmilib](../../base/ntos/wmi/sample/wmilib) | 7 | [base/ntos/wmi/sample/wmilib/sources](../../base/ntos/wmi/sample/wmilib/sources), [base/ntos/wmi/sample/wmilib/makefile](../../base/ntos/wmi/sample/wmilib/makefile) | `wmisamp` | `DRIVER` |
| [base/ntos/wmi/up](../../base/ntos/wmi/up) | 2 | [base/ntos/wmi/up/sources](../../base/ntos/wmi/up/sources), [base/ntos/wmi/up/makefile](../../base/ntos/wmi/up/makefile) | — | — |

## `base/ntsetup/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [base/ntsetup](../../base/ntsetup) | 2 | [base/ntsetup/dirs](../../base/ntsetup/dirs) | — | — |
| [base/ntsetup/_winnt](../../base/ntsetup/_winnt) | 5 | [base/ntsetup/_winnt/sources](../../base/ntsetup/_winnt/sources), [base/ntsetup/_winnt/makefile](../../base/ntsetup/_winnt/makefile) | `_winnt` | `PROGRAM` |
| [base/ntsetup/basewin](../../base/ntsetup/basewin) | 3 | [base/ntsetup/basewin/sources](../../base/ntsetup/basewin/sources), [base/ntsetup/basewin/makefile](../../base/ntsetup/basewin/makefile) | `basewin` | `PROGRAM` |
| [base/ntsetup/billbrd](../../base/ntsetup/billbrd) | 47 | [base/ntsetup/billbrd/dirs](../../base/ntsetup/billbrd/dirs) | — | — |
| [base/ntsetup/billbrd/ansi](../../base/ntsetup/billbrd/ansi) | 3 | [base/ntsetup/billbrd/ansi/sources](../../base/ntsetup/billbrd/ansi/sources), [base/ntsetup/billbrd/ansi/makefile](../../base/ntsetup/billbrd/ansi/makefile) | `winntbba` | — |
| [base/ntsetup/billbrd/res](../../base/ntsetup/billbrd/res) | 0 | — | — | — |
| [base/ntsetup/billbrd/res/16bitcolor](../../base/ntsetup/billbrd/res/16bitcolor) | 14 | — | — | — |
| [base/ntsetup/billbrd/res/4bitcolor](../../base/ntsetup/billbrd/res/4bitcolor) | 11 | — | — | — |
| [base/ntsetup/billbrd/unicode](../../base/ntsetup/billbrd/unicode) | 3 | [base/ntsetup/billbrd/unicode/sources](../../base/ntsetup/billbrd/unicode/sources), [base/ntsetup/billbrd/unicode/makefile](../../base/ntsetup/billbrd/unicode/makefile) | `winntbbu` | — |
| [base/ntsetup/bmps](../../base/ntsetup/bmps) | 8 | [base/ntsetup/bmps/sources](../../base/ntsetup/bmps/sources), [base/ntsetup/bmps/makefile](../../base/ntsetup/bmps/makefile) | — | `NOTARGET` |
| [base/ntsetup/bom](../../base/ntsetup/bom) | 21 | [base/ntsetup/bom/dirs](../../base/ntsetup/bom/dirs) | — | — |
| [base/ntsetup/bom/acllist](../../base/ntsetup/bom/acllist) | 4 | [base/ntsetup/bom/acllist/sources](../../base/ntsetup/bom/acllist/sources), [base/ntsetup/bom/acllist/makefile](../../base/ntsetup/bom/acllist/makefile) | `acllist` | `PROGRAM` |
| [base/ntsetup/bom/autorun](../../base/ntsetup/bom/autorun) | 1 | — | — | — |
| [base/ntsetup/bom/boot](../../base/ntsetup/bom/boot) | 4 | [base/ntsetup/bom/boot/sources](../../base/ntsetup/bom/boot/sources), [base/ntsetup/bom/boot/makefile](../../base/ntsetup/bom/boot/makefile) | `boot` | `PROGRAM` |
| [base/ntsetup/bom/cats](../../base/ntsetup/bom/cats) | 4 | [base/ntsetup/bom/cats/sources](../../base/ntsetup/bom/cats/sources), [base/ntsetup/bom/cats/makefile](../../base/ntsetup/bom/cats/makefile) | `cats` | `PROGRAM` |
| [base/ntsetup/bom/checkhiv](../../base/ntsetup/bom/checkhiv) | 4 | [base/ntsetup/bom/checkhiv/sources](../../base/ntsetup/bom/checkhiv/sources), [base/ntsetup/bom/checkhiv/makefile](../../base/ntsetup/bom/checkhiv/makefile) | `checkhiv` | `PROGRAM` |
| [base/ntsetup/bom/dcomp](../../base/ntsetup/bom/dcomp) | 4 | [base/ntsetup/bom/dcomp/sources](../../base/ntsetup/bom/dcomp/sources), [base/ntsetup/bom/dcomp/makefile](../../base/ntsetup/bom/dcomp/makefile) | `dcomp` | `PROGRAM` |
| [base/ntsetup/bom/files](../../base/ntsetup/bom/files) | 5 | [base/ntsetup/bom/files/sources](../../base/ntsetup/bom/files/sources), [base/ntsetup/bom/files/makefile](../../base/ntsetup/bom/files/makefile) | `files` | `PROGRAM` |
| [base/ntsetup/bom/filter](../../base/ntsetup/bom/filter) | 4 | [base/ntsetup/bom/filter/sources](../../base/ntsetup/bom/filter/sources), [base/ntsetup/bom/filter/makefile](../../base/ntsetup/bom/filter/makefile) | `filter` | `PROGRAM` |
| [base/ntsetup/bom/general](../../base/ntsetup/bom/general) | 5 | [base/ntsetup/bom/general/sources](../../base/ntsetup/bom/general/sources), [base/ntsetup/bom/general/makefile](../../base/ntsetup/bom/general/makefile) | `general` | `LIBRARY` |
| [base/ntsetup/bom/infs](../../base/ntsetup/bom/infs) | 4 | [base/ntsetup/bom/infs/sources](../../base/ntsetup/bom/infs/sources), [base/ntsetup/bom/infs/makefile](../../base/ntsetup/bom/infs/makefile) | `infs` | `PROGRAM` |
| [base/ntsetup/bom/infsize](../../base/ntsetup/bom/infsize) | 4 | [base/ntsetup/bom/infsize/sources](../../base/ntsetup/bom/infsize/sources), [base/ntsetup/bom/infsize/makefile](../../base/ntsetup/bom/infsize/makefile) | `infsize` | `PROGRAM` |
| [base/ntsetup/bom/layout](../../base/ntsetup/bom/layout) | 5 | [base/ntsetup/bom/layout/sources](../../base/ntsetup/bom/layout/sources), [base/ntsetup/bom/layout/makefile](../../base/ntsetup/bom/layout/makefile) | `layout` | `PROGRAM` |
| [base/ntsetup/bom/makeboot](../../base/ntsetup/bom/makeboot) | 2 | [base/ntsetup/bom/makeboot/dirs](../../base/ntsetup/bom/makeboot/dirs) | — | — |
| [base/ntsetup/bom/makeboot/16bit](../../base/ntsetup/bom/makeboot/16bit) | 5 | [base/ntsetup/bom/makeboot/16bit/dirs](../../base/ntsetup/bom/makeboot/16bit/dirs) | — | — |
| [base/ntsetup/bom/makeboot/16bit/_br](../../base/ntsetup/bom/makeboot/16bit/_br) | 3 | [base/ntsetup/bom/makeboot/16bit/_br/sources](../../base/ntsetup/bom/makeboot/16bit/_br/sources), [base/ntsetup/bom/makeboot/16bit/_br/makefile](../../base/ntsetup/bom/makeboot/16bit/_br/makefile) | — | — |
| [base/ntsetup/bom/makeboot/16bit/_cs](../../base/ntsetup/bom/makeboot/16bit/_cs) | 3 | [base/ntsetup/bom/makeboot/16bit/_cs/sources](../../base/ntsetup/bom/makeboot/16bit/_cs/sources), [base/ntsetup/bom/makeboot/16bit/_cs/makefile](../../base/ntsetup/bom/makeboot/16bit/_cs/makefile) | — | — |
| [base/ntsetup/bom/makeboot/16bit/br](../../base/ntsetup/bom/makeboot/16bit/br) | 4 | [base/ntsetup/bom/makeboot/16bit/br/sources](../../base/ntsetup/bom/makeboot/16bit/br/sources), [base/ntsetup/bom/makeboot/16bit/br/makefile](../../base/ntsetup/bom/makeboot/16bit/br/makefile) | — | — |
| [base/ntsetup/bom/makeboot/16bit/cs](../../base/ntsetup/bom/makeboot/16bit/cs) | 4 | [base/ntsetup/bom/makeboot/16bit/cs/sources](../../base/ntsetup/bom/makeboot/16bit/cs/sources), [base/ntsetup/bom/makeboot/16bit/cs/makefile](../../base/ntsetup/bom/makeboot/16bit/cs/makefile) | — | — |
| [base/ntsetup/bom/makeboot/16bit/da](../../base/ntsetup/bom/makeboot/16bit/da) | 4 | [base/ntsetup/bom/makeboot/16bit/da/sources](../../base/ntsetup/bom/makeboot/16bit/da/sources), [base/ntsetup/bom/makeboot/16bit/da/makefile](../../base/ntsetup/bom/makeboot/16bit/da/makefile) | — | — |
| [base/ntsetup/bom/makeboot/16bit/el](../../base/ntsetup/bom/makeboot/16bit/el) | 4 | [base/ntsetup/bom/makeboot/16bit/el/sources](../../base/ntsetup/bom/makeboot/16bit/el/sources), [base/ntsetup/bom/makeboot/16bit/el/makefile](../../base/ntsetup/bom/makeboot/16bit/el/makefile) | — | — |
| [base/ntsetup/bom/makeboot/16bit/es](../../base/ntsetup/bom/makeboot/16bit/es) | 4 | [base/ntsetup/bom/makeboot/16bit/es/sources](../../base/ntsetup/bom/makeboot/16bit/es/sources), [base/ntsetup/bom/makeboot/16bit/es/makefile](../../base/ntsetup/bom/makeboot/16bit/es/makefile) | — | — |
| [base/ntsetup/bom/makeboot/16bit/fi](../../base/ntsetup/bom/makeboot/16bit/fi) | 4 | [base/ntsetup/bom/makeboot/16bit/fi/sources](../../base/ntsetup/bom/makeboot/16bit/fi/sources), [base/ntsetup/bom/makeboot/16bit/fi/makefile](../../base/ntsetup/bom/makeboot/16bit/fi/makefile) | — | — |
| [base/ntsetup/bom/makeboot/16bit/fr](../../base/ntsetup/bom/makeboot/16bit/fr) | 4 | [base/ntsetup/bom/makeboot/16bit/fr/sources](../../base/ntsetup/bom/makeboot/16bit/fr/sources), [base/ntsetup/bom/makeboot/16bit/fr/makefile](../../base/ntsetup/bom/makeboot/16bit/fr/makefile) | — | — |
| [base/ntsetup/bom/makeboot/16bit/gb](../../base/ntsetup/bom/makeboot/16bit/gb) | 3 | [base/ntsetup/bom/makeboot/16bit/gb/sources](../../base/ntsetup/bom/makeboot/16bit/gb/sources), [base/ntsetup/bom/makeboot/16bit/gb/makefile](../../base/ntsetup/bom/makeboot/16bit/gb/makefile) | — | — |
| [base/ntsetup/bom/makeboot/16bit/ger](../../base/ntsetup/bom/makeboot/16bit/ger) | 4 | [base/ntsetup/bom/makeboot/16bit/ger/sources](../../base/ntsetup/bom/makeboot/16bit/ger/sources), [base/ntsetup/bom/makeboot/16bit/ger/makefile](../../base/ntsetup/bom/makeboot/16bit/ger/makefile) | — | — |
| [base/ntsetup/bom/makeboot/16bit/hu](../../base/ntsetup/bom/makeboot/16bit/hu) | 4 | [base/ntsetup/bom/makeboot/16bit/hu/sources](../../base/ntsetup/bom/makeboot/16bit/hu/sources), [base/ntsetup/bom/makeboot/16bit/hu/makefile](../../base/ntsetup/bom/makeboot/16bit/hu/makefile) | — | — |
| [base/ntsetup/bom/makeboot/16bit/it](../../base/ntsetup/bom/makeboot/16bit/it) | 4 | [base/ntsetup/bom/makeboot/16bit/it/sources](../../base/ntsetup/bom/makeboot/16bit/it/sources), [base/ntsetup/bom/makeboot/16bit/it/makefile](../../base/ntsetup/bom/makeboot/16bit/it/makefile) | — | — |
| [base/ntsetup/bom/makeboot/16bit/jpn](../../base/ntsetup/bom/makeboot/16bit/jpn) | 4 | [base/ntsetup/bom/makeboot/16bit/jpn/sources](../../base/ntsetup/bom/makeboot/16bit/jpn/sources), [base/ntsetup/bom/makeboot/16bit/jpn/makefile](../../base/ntsetup/bom/makeboot/16bit/jpn/makefile) | — | — |
| [base/ntsetup/bom/makeboot/16bit/nl](../../base/ntsetup/bom/makeboot/16bit/nl) | 4 | [base/ntsetup/bom/makeboot/16bit/nl/sources](../../base/ntsetup/bom/makeboot/16bit/nl/sources), [base/ntsetup/bom/makeboot/16bit/nl/makefile](../../base/ntsetup/bom/makeboot/16bit/nl/makefile) | — | — |
| [base/ntsetup/bom/makeboot/16bit/no](../../base/ntsetup/bom/makeboot/16bit/no) | 4 | [base/ntsetup/bom/makeboot/16bit/no/sources](../../base/ntsetup/bom/makeboot/16bit/no/sources), [base/ntsetup/bom/makeboot/16bit/no/makefile](../../base/ntsetup/bom/makeboot/16bit/no/makefile) | — | — |
| [base/ntsetup/bom/makeboot/16bit/pl](../../base/ntsetup/bom/makeboot/16bit/pl) | 4 | [base/ntsetup/bom/makeboot/16bit/pl/sources](../../base/ntsetup/bom/makeboot/16bit/pl/sources), [base/ntsetup/bom/makeboot/16bit/pl/makefile](../../base/ntsetup/bom/makeboot/16bit/pl/makefile) | — | — |
| [base/ntsetup/bom/makeboot/16bit/psu](../../base/ntsetup/bom/makeboot/16bit/psu) | 3 | [base/ntsetup/bom/makeboot/16bit/psu/sources](../../base/ntsetup/bom/makeboot/16bit/psu/sources), [base/ntsetup/bom/makeboot/16bit/psu/makefile](../../base/ntsetup/bom/makeboot/16bit/psu/makefile) | — | — |
| [base/ntsetup/bom/makeboot/16bit/pt](../../base/ntsetup/bom/makeboot/16bit/pt) | 4 | [base/ntsetup/bom/makeboot/16bit/pt/sources](../../base/ntsetup/bom/makeboot/16bit/pt/sources), [base/ntsetup/bom/makeboot/16bit/pt/makefile](../../base/ntsetup/bom/makeboot/16bit/pt/makefile) | — | — |
| [base/ntsetup/bom/makeboot/16bit/ru](../../base/ntsetup/bom/makeboot/16bit/ru) | 4 | [base/ntsetup/bom/makeboot/16bit/ru/sources](../../base/ntsetup/bom/makeboot/16bit/ru/sources), [base/ntsetup/bom/makeboot/16bit/ru/makefile](../../base/ntsetup/bom/makeboot/16bit/ru/makefile) | — | — |
| [base/ntsetup/bom/makeboot/16bit/sv](../../base/ntsetup/bom/makeboot/16bit/sv) | 4 | [base/ntsetup/bom/makeboot/16bit/sv/sources](../../base/ntsetup/bom/makeboot/16bit/sv/sources), [base/ntsetup/bom/makeboot/16bit/sv/makefile](../../base/ntsetup/bom/makeboot/16bit/sv/makefile) | — | — |
| [base/ntsetup/bom/makeboot/16bit/tr](../../base/ntsetup/bom/makeboot/16bit/tr) | 4 | [base/ntsetup/bom/makeboot/16bit/tr/sources](../../base/ntsetup/bom/makeboot/16bit/tr/sources), [base/ntsetup/bom/makeboot/16bit/tr/makefile](../../base/ntsetup/bom/makeboot/16bit/tr/makefile) | — | — |
| [base/ntsetup/bom/makeboot/16bit/tst](../../base/ntsetup/bom/makeboot/16bit/tst) | 3 | [base/ntsetup/bom/makeboot/16bit/tst/sources](../../base/ntsetup/bom/makeboot/16bit/tst/sources), [base/ntsetup/bom/makeboot/16bit/tst/makefile](../../base/ntsetup/bom/makeboot/16bit/tst/makefile) | — | — |
| [base/ntsetup/bom/makeboot/16bit/usa](../../base/ntsetup/bom/makeboot/16bit/usa) | 5 | [base/ntsetup/bom/makeboot/16bit/usa/sources](../../base/ntsetup/bom/makeboot/16bit/usa/sources), [base/ntsetup/bom/makeboot/16bit/usa/makefile](../../base/ntsetup/bom/makeboot/16bit/usa/makefile) | — | — |
| [base/ntsetup/bom/makeboot/32bit](../../base/ntsetup/bom/makeboot/32bit) | 5 | [base/ntsetup/bom/makeboot/32bit/sources](../../base/ntsetup/bom/makeboot/32bit/sources), [base/ntsetup/bom/makeboot/32bit/makefile](../../base/ntsetup/bom/makeboot/32bit/makefile) | `makebt32` | `PROGRAM` |
| [base/ntsetup/bom/makeboot/32bit/i386](../../base/ntsetup/bom/makeboot/32bit/i386) | 1 | [base/ntsetup/bom/makeboot/32bit/i386/sources](../../base/ntsetup/bom/makeboot/32bit/i386/sources) | — | — |
| [base/ntsetup/bom/makeboot/eulas](../../base/ntsetup/bom/makeboot/eulas) | 2 | [base/ntsetup/bom/makeboot/eulas/dirs](../../base/ntsetup/bom/makeboot/eulas/dirs) | — | — |
| [base/ntsetup/bom/makeboot/eulas/ara](../../base/ntsetup/bom/makeboot/eulas/ara) | 3 | [base/ntsetup/bom/makeboot/eulas/ara/sources](../../base/ntsetup/bom/makeboot/eulas/ara/sources), [base/ntsetup/bom/makeboot/eulas/ara/makefile](../../base/ntsetup/bom/makeboot/eulas/ara/makefile) | — | — |
| [base/ntsetup/bom/makeboot/eulas/br](../../base/ntsetup/bom/makeboot/eulas/br) | 3 | [base/ntsetup/bom/makeboot/eulas/br/sources](../../base/ntsetup/bom/makeboot/eulas/br/sources), [base/ntsetup/bom/makeboot/eulas/br/makefile](../../base/ntsetup/bom/makeboot/eulas/br/makefile) | — | — |
| [base/ntsetup/bom/makeboot/eulas/chh](../../base/ntsetup/bom/makeboot/eulas/chh) | 3 | [base/ntsetup/bom/makeboot/eulas/chh/sources](../../base/ntsetup/bom/makeboot/eulas/chh/sources), [base/ntsetup/bom/makeboot/eulas/chh/makefile](../../base/ntsetup/bom/makeboot/eulas/chh/makefile) | — | — |
| [base/ntsetup/bom/makeboot/eulas/chp](../../base/ntsetup/bom/makeboot/eulas/chp) | 3 | [base/ntsetup/bom/makeboot/eulas/chp/sources](../../base/ntsetup/bom/makeboot/eulas/chp/sources), [base/ntsetup/bom/makeboot/eulas/chp/makefile](../../base/ntsetup/bom/makeboot/eulas/chp/makefile) | — | — |
| [base/ntsetup/bom/makeboot/eulas/chs](../../base/ntsetup/bom/makeboot/eulas/chs) | 3 | [base/ntsetup/bom/makeboot/eulas/chs/sources](../../base/ntsetup/bom/makeboot/eulas/chs/sources), [base/ntsetup/bom/makeboot/eulas/chs/makefile](../../base/ntsetup/bom/makeboot/eulas/chs/makefile) | — | — |
| [base/ntsetup/bom/makeboot/eulas/cht](../../base/ntsetup/bom/makeboot/eulas/cht) | 3 | [base/ntsetup/bom/makeboot/eulas/cht/sources](../../base/ntsetup/bom/makeboot/eulas/cht/sources), [base/ntsetup/bom/makeboot/eulas/cht/makefile](../../base/ntsetup/bom/makeboot/eulas/cht/makefile) | — | — |
| [base/ntsetup/bom/makeboot/eulas/cs](../../base/ntsetup/bom/makeboot/eulas/cs) | 3 | [base/ntsetup/bom/makeboot/eulas/cs/sources](../../base/ntsetup/bom/makeboot/eulas/cs/sources), [base/ntsetup/bom/makeboot/eulas/cs/makefile](../../base/ntsetup/bom/makeboot/eulas/cs/makefile) | — | — |
| [base/ntsetup/bom/makeboot/eulas/da](../../base/ntsetup/bom/makeboot/eulas/da) | 3 | [base/ntsetup/bom/makeboot/eulas/da/sources](../../base/ntsetup/bom/makeboot/eulas/da/sources), [base/ntsetup/bom/makeboot/eulas/da/makefile](../../base/ntsetup/bom/makeboot/eulas/da/makefile) | — | — |
| [base/ntsetup/bom/makeboot/eulas/el](../../base/ntsetup/bom/makeboot/eulas/el) | 3 | [base/ntsetup/bom/makeboot/eulas/el/sources](../../base/ntsetup/bom/makeboot/eulas/el/sources), [base/ntsetup/bom/makeboot/eulas/el/makefile](../../base/ntsetup/bom/makeboot/eulas/el/makefile) | — | — |
| [base/ntsetup/bom/makeboot/eulas/es](../../base/ntsetup/bom/makeboot/eulas/es) | 3 | [base/ntsetup/bom/makeboot/eulas/es/sources](../../base/ntsetup/bom/makeboot/eulas/es/sources), [base/ntsetup/bom/makeboot/eulas/es/makefile](../../base/ntsetup/bom/makeboot/eulas/es/makefile) | — | — |
| [base/ntsetup/bom/makeboot/eulas/fi](../../base/ntsetup/bom/makeboot/eulas/fi) | 3 | [base/ntsetup/bom/makeboot/eulas/fi/sources](../../base/ntsetup/bom/makeboot/eulas/fi/sources), [base/ntsetup/bom/makeboot/eulas/fi/makefile](../../base/ntsetup/bom/makeboot/eulas/fi/makefile) | — | — |
| [base/ntsetup/bom/makeboot/eulas/fr](../../base/ntsetup/bom/makeboot/eulas/fr) | 3 | [base/ntsetup/bom/makeboot/eulas/fr/sources](../../base/ntsetup/bom/makeboot/eulas/fr/sources), [base/ntsetup/bom/makeboot/eulas/fr/makefile](../../base/ntsetup/bom/makeboot/eulas/fr/makefile) | — | — |
| [base/ntsetup/bom/makeboot/eulas/ger](../../base/ntsetup/bom/makeboot/eulas/ger) | 3 | [base/ntsetup/bom/makeboot/eulas/ger/sources](../../base/ntsetup/bom/makeboot/eulas/ger/sources), [base/ntsetup/bom/makeboot/eulas/ger/makefile](../../base/ntsetup/bom/makeboot/eulas/ger/makefile) | — | — |
| [base/ntsetup/bom/makeboot/eulas/heb](../../base/ntsetup/bom/makeboot/eulas/heb) | 3 | [base/ntsetup/bom/makeboot/eulas/heb/sources](../../base/ntsetup/bom/makeboot/eulas/heb/sources), [base/ntsetup/bom/makeboot/eulas/heb/makefile](../../base/ntsetup/bom/makeboot/eulas/heb/makefile) | — | — |
| [base/ntsetup/bom/makeboot/eulas/hu](../../base/ntsetup/bom/makeboot/eulas/hu) | 3 | [base/ntsetup/bom/makeboot/eulas/hu/sources](../../base/ntsetup/bom/makeboot/eulas/hu/sources), [base/ntsetup/bom/makeboot/eulas/hu/makefile](../../base/ntsetup/bom/makeboot/eulas/hu/makefile) | — | — |
| [base/ntsetup/bom/makeboot/eulas/it](../../base/ntsetup/bom/makeboot/eulas/it) | 3 | [base/ntsetup/bom/makeboot/eulas/it/sources](../../base/ntsetup/bom/makeboot/eulas/it/sources), [base/ntsetup/bom/makeboot/eulas/it/makefile](../../base/ntsetup/bom/makeboot/eulas/it/makefile) | — | — |
| [base/ntsetup/bom/makeboot/eulas/jpn](../../base/ntsetup/bom/makeboot/eulas/jpn) | 3 | [base/ntsetup/bom/makeboot/eulas/jpn/sources](../../base/ntsetup/bom/makeboot/eulas/jpn/sources), [base/ntsetup/bom/makeboot/eulas/jpn/makefile](../../base/ntsetup/bom/makeboot/eulas/jpn/makefile) | — | — |
| [base/ntsetup/bom/makeboot/eulas/kor](../../base/ntsetup/bom/makeboot/eulas/kor) | 3 | [base/ntsetup/bom/makeboot/eulas/kor/sources](../../base/ntsetup/bom/makeboot/eulas/kor/sources), [base/ntsetup/bom/makeboot/eulas/kor/makefile](../../base/ntsetup/bom/makeboot/eulas/kor/makefile) | — | — |
| [base/ntsetup/bom/makeboot/eulas/nl](../../base/ntsetup/bom/makeboot/eulas/nl) | 3 | [base/ntsetup/bom/makeboot/eulas/nl/sources](../../base/ntsetup/bom/makeboot/eulas/nl/sources), [base/ntsetup/bom/makeboot/eulas/nl/makefile](../../base/ntsetup/bom/makeboot/eulas/nl/makefile) | — | — |
| [base/ntsetup/bom/makeboot/eulas/no](../../base/ntsetup/bom/makeboot/eulas/no) | 3 | [base/ntsetup/bom/makeboot/eulas/no/sources](../../base/ntsetup/bom/makeboot/eulas/no/sources), [base/ntsetup/bom/makeboot/eulas/no/makefile](../../base/ntsetup/bom/makeboot/eulas/no/makefile) | — | — |
| [base/ntsetup/bom/makeboot/eulas/pl](../../base/ntsetup/bom/makeboot/eulas/pl) | 3 | [base/ntsetup/bom/makeboot/eulas/pl/sources](../../base/ntsetup/bom/makeboot/eulas/pl/sources), [base/ntsetup/bom/makeboot/eulas/pl/makefile](../../base/ntsetup/bom/makeboot/eulas/pl/makefile) | — | — |
| [base/ntsetup/bom/makeboot/eulas/pt](../../base/ntsetup/bom/makeboot/eulas/pt) | 3 | [base/ntsetup/bom/makeboot/eulas/pt/sources](../../base/ntsetup/bom/makeboot/eulas/pt/sources), [base/ntsetup/bom/makeboot/eulas/pt/makefile](../../base/ntsetup/bom/makeboot/eulas/pt/makefile) | — | — |
| [base/ntsetup/bom/makeboot/eulas/ru](../../base/ntsetup/bom/makeboot/eulas/ru) | 3 | [base/ntsetup/bom/makeboot/eulas/ru/sources](../../base/ntsetup/bom/makeboot/eulas/ru/sources), [base/ntsetup/bom/makeboot/eulas/ru/makefile](../../base/ntsetup/bom/makeboot/eulas/ru/makefile) | — | — |
| [base/ntsetup/bom/makeboot/eulas/sv](../../base/ntsetup/bom/makeboot/eulas/sv) | 3 | [base/ntsetup/bom/makeboot/eulas/sv/sources](../../base/ntsetup/bom/makeboot/eulas/sv/sources), [base/ntsetup/bom/makeboot/eulas/sv/makefile](../../base/ntsetup/bom/makeboot/eulas/sv/makefile) | — | — |
| [base/ntsetup/bom/makeboot/eulas/tr](../../base/ntsetup/bom/makeboot/eulas/tr) | 3 | [base/ntsetup/bom/makeboot/eulas/tr/sources](../../base/ntsetup/bom/makeboot/eulas/tr/sources), [base/ntsetup/bom/makeboot/eulas/tr/makefile](../../base/ntsetup/bom/makeboot/eulas/tr/makefile) | — | — |
| [base/ntsetup/bom/makeboot/eulas/usa](../../base/ntsetup/bom/makeboot/eulas/usa) | 3 | [base/ntsetup/bom/makeboot/eulas/usa/sources](../../base/ntsetup/bom/makeboot/eulas/usa/sources), [base/ntsetup/bom/makeboot/eulas/usa/makefile](../../base/ntsetup/bom/makeboot/eulas/usa/makefile) | — | — |
| [base/ntsetup/bom/makedisk](../../base/ntsetup/bom/makedisk) | 4 | [base/ntsetup/bom/makedisk/sources](../../base/ntsetup/bom/makedisk/sources), [base/ntsetup/bom/makedisk/makefile](../../base/ntsetup/bom/makedisk/makefile) | `makedisk` | `PROGRAM` |
| [base/ntsetup/bom/makeimg](../../base/ntsetup/bom/makeimg) | 1 | — | — | — |
| [base/ntsetup/bom/mbytes](../../base/ntsetup/bom/mbytes) | 4 | [base/ntsetup/bom/mbytes/sources](../../base/ntsetup/bom/mbytes/sources), [base/ntsetup/bom/mbytes/makefile](../../base/ntsetup/bom/mbytes/makefile) | `mbytes` | `PROGRAM` |
| [base/ntsetup/bom/mcopy](../../base/ntsetup/bom/mcopy) | 5 | [base/ntsetup/bom/mcopy/sources](../../base/ntsetup/bom/mcopy/sources), [base/ntsetup/bom/mcopy/makefile](../../base/ntsetup/bom/mcopy/makefile) | `mcopy` | `PROGRAM` |
| [base/ntsetup/bom/mcpyfile](../../base/ntsetup/bom/mcpyfile) | 6 | [base/ntsetup/bom/mcpyfile/sources](../../base/ntsetup/bom/mcpyfile/sources), [base/ntsetup/bom/mcpyfile/makefile](../../base/ntsetup/bom/mcpyfile/makefile) | `mcpyfile` | `PROGRAM` |
| [base/ntsetup/bom/mlayout](../../base/ntsetup/bom/mlayout) | 4 | [base/ntsetup/bom/mlayout/sources](../../base/ntsetup/bom/mlayout/sources), [base/ntsetup/bom/mlayout/makefile](../../base/ntsetup/bom/mlayout/makefile) | `mlayout` | `PROGRAM` |
| [base/ntsetup/bom/msize](../../base/ntsetup/bom/msize) | 5 | [base/ntsetup/bom/msize/sources](../../base/ntsetup/bom/msize/sources), [base/ntsetup/bom/msize/makefile](../../base/ntsetup/bom/msize/makefile) | `msize` | `PROGRAM` |
| [base/ntsetup/bom/mtc](../../base/ntsetup/bom/mtc) | 4 | [base/ntsetup/bom/mtc/sources](../../base/ntsetup/bom/mtc/sources), [base/ntsetup/bom/mtc/makefile](../../base/ntsetup/bom/mtc/makefile) | `mtc` | `PROGRAM` |
| [base/ntsetup/bom/oem](../../base/ntsetup/bom/oem) | 0 | — | — | — |
| [base/ntsetup/bom/oem/s](../../base/ntsetup/bom/oem/s) | 2 | — | — | — |
| [base/ntsetup/bom/oem/w](../../base/ntsetup/bom/oem/w) | 2 | — | — | — |
| [base/ntsetup/bom/openall](../../base/ntsetup/bom/openall) | 4 | [base/ntsetup/bom/openall/sources](../../base/ntsetup/bom/openall/sources), [base/ntsetup/bom/openall/makefile](../../base/ntsetup/bom/openall/makefile) | `openall` | `PROGRAM` |
| [base/ntsetup/bom/size](../../base/ntsetup/bom/size) | 4 | [base/ntsetup/bom/size/sources](../../base/ntsetup/bom/size/sources), [base/ntsetup/bom/size/makefile](../../base/ntsetup/bom/size/makefile) | `size` | `PROGRAM` |
| [base/ntsetup/books](../../base/ntsetup/books) | 19 | [base/ntsetup/books/sources](../../base/ntsetup/books/sources), [base/ntsetup/books/makefile](../../base/ntsetup/books/makefile) | `ntbooks` | `PROGRAM` |
| [base/ntsetup/bootent](../../base/ntsetup/bootent) | 3 | [base/ntsetup/bootent/dirs](../../base/ntsetup/bootent/dirs) | — | — |
| [base/ntsetup/bootent/bootini](../../base/ntsetup/bootent/bootini) | 6 | [base/ntsetup/bootent/bootini/sources](../../base/ntsetup/bootent/bootini/sources), [base/ntsetup/bootent/bootini/makefile](../../base/ntsetup/bootent/bootini/makefile) | `bootent` | `LIBRARY` |
| [base/ntsetup/bootent/efi](../../base/ntsetup/bootent/efi) | 4 | [base/ntsetup/bootent/efi/sources](../../base/ntsetup/bootent/efi/sources), [base/ntsetup/bootent/efi/makefile](../../base/ntsetup/bootent/efi/makefile) | `bootent` | `LIBRARY` |
| [base/ntsetup/bootent/test](../../base/ntsetup/bootent/test) | 3 | [base/ntsetup/bootent/test/sources](../../base/ntsetup/bootent/test/sources), [base/ntsetup/bootent/test/makefile](../../base/ntsetup/bootent/test/makefile) | `boottest` | `PROGRAM` |
| [base/ntsetup/cfgmgrf](../../base/ntsetup/cfgmgrf) | 1 | — | — | — |
| [base/ntsetup/complnce](../../base/ntsetup/complnce) | 6 | [base/ntsetup/complnce/dirs](../../base/ntsetup/complnce/dirs) | — | — |
| [base/ntsetup/complnce/ansiuser](../../base/ntsetup/complnce/ansiuser) | 2 | [base/ntsetup/complnce/ansiuser/sources](../../base/ntsetup/complnce/ansiuser/sources), [base/ntsetup/complnce/ansiuser/makefile](../../base/ntsetup/complnce/ansiuser/makefile) | `compuser_a` | `LIBRARY` |
| [base/ntsetup/complnce/ansiuser/i386](../../base/ntsetup/complnce/ansiuser/i386) | 2 | [base/ntsetup/complnce/ansiuser/i386/sources](../../base/ntsetup/complnce/ansiuser/i386/sources), [base/ntsetup/complnce/ansiuser/i386/makefile](../../base/ntsetup/complnce/ansiuser/i386/makefile) | `compuser_a` | `LIBRARY` |
| [base/ntsetup/complnce/comptest](../../base/ntsetup/complnce/comptest) | 25 | [base/ntsetup/complnce/comptest/sources](../../base/ntsetup/complnce/comptest/sources), [base/ntsetup/complnce/comptest/makefile](../../base/ntsetup/complnce/comptest/makefile) | `comptest` | `PROGRAM` |
| [base/ntsetup/complnce/kernel](../../base/ntsetup/complnce/kernel) | 2 | [base/ntsetup/complnce/kernel/sources](../../base/ntsetup/complnce/kernel/sources), [base/ntsetup/complnce/kernel/makefile](../../base/ntsetup/complnce/kernel/makefile) | `complnce_k` | `LIBRARY` |
| [base/ntsetup/complnce/pidinit](../../base/ntsetup/complnce/pidinit) | 8 | [base/ntsetup/complnce/pidinit/sources](../../base/ntsetup/complnce/pidinit/sources), [base/ntsetup/complnce/pidinit/makefile](../../base/ntsetup/complnce/pidinit/makefile) | `pidinit` | `PROGRAM` |
| [base/ntsetup/complnce/uniuser](../../base/ntsetup/complnce/uniuser) | 2 | [base/ntsetup/complnce/uniuser/sources](../../base/ntsetup/complnce/uniuser/sources), [base/ntsetup/complnce/uniuser/makefile](../../base/ntsetup/complnce/uniuser/makefile) | `compuser_u` | `LIBRARY` |
| [base/ntsetup/encrypt](../../base/ntsetup/encrypt) | 6 | [base/ntsetup/encrypt/sources](../../base/ntsetup/encrypt/sources), [base/ntsetup/encrypt/makefile](../../base/ntsetup/encrypt/makefile) | `encrypt` | `LIBRARY` |
| [base/ntsetup/eulas_etc](../../base/ntsetup/eulas_etc) | 1 | [base/ntsetup/eulas_etc/dirs](../../base/ntsetup/eulas_etc/dirs) | — | — |
| [base/ntsetup/eulas_etc/blaonly](../../base/ntsetup/eulas_etc/blaonly) | 1 | [base/ntsetup/eulas_etc/blaonly/dirs](../../base/ntsetup/eulas_etc/blaonly/dirs) | — | — |
| [base/ntsetup/eulas_etc/blaonly/common](../../base/ntsetup/eulas_etc/blaonly/common) | 4 | [base/ntsetup/eulas_etc/blaonly/common/sources](../../base/ntsetup/eulas_etc/blaonly/common/sources), [base/ntsetup/eulas_etc/blaonly/common/makefile](../../base/ntsetup/eulas_etc/blaonly/common/makefile) | — | `NOTARGET` |
| [base/ntsetup/eulas_etc/blaonly/export](../../base/ntsetup/eulas_etc/blaonly/export) | 4 | [base/ntsetup/eulas_etc/blaonly/export/sources](../../base/ntsetup/eulas_etc/blaonly/export/sources), [base/ntsetup/eulas_etc/blaonly/export/makefile](../../base/ntsetup/eulas_etc/blaonly/export/makefile) | — | `NOTARGET` |
| [base/ntsetup/eulas_etc/dtconly](../../base/ntsetup/eulas_etc/dtconly) | 1 | [base/ntsetup/eulas_etc/dtconly/dirs](../../base/ntsetup/eulas_etc/dtconly/dirs) | — | — |
| [base/ntsetup/eulas_etc/dtconly/common](../../base/ntsetup/eulas_etc/dtconly/common) | 4 | [base/ntsetup/eulas_etc/dtconly/common/sources](../../base/ntsetup/eulas_etc/dtconly/common/sources), [base/ntsetup/eulas_etc/dtconly/common/makefile](../../base/ntsetup/eulas_etc/dtconly/common/makefile) | — | `NOTARGET` |
| [base/ntsetup/eulas_etc/entonly](../../base/ntsetup/eulas_etc/entonly) | 1 | [base/ntsetup/eulas_etc/entonly/dirs](../../base/ntsetup/eulas_etc/entonly/dirs) | — | — |
| [base/ntsetup/eulas_etc/entonly/common](../../base/ntsetup/eulas_etc/entonly/common) | 4 | [base/ntsetup/eulas_etc/entonly/common/sources](../../base/ntsetup/eulas_etc/entonly/common/sources), [base/ntsetup/eulas_etc/entonly/common/makefile](../../base/ntsetup/eulas_etc/entonly/common/makefile) | — | `NOTARGET` |
| [base/ntsetup/eulas_etc/sbsonly](../../base/ntsetup/eulas_etc/sbsonly) | 1 | [base/ntsetup/eulas_etc/sbsonly/dirs](../../base/ntsetup/eulas_etc/sbsonly/dirs) | — | — |
| [base/ntsetup/eulas_etc/sbsonly/common](../../base/ntsetup/eulas_etc/sbsonly/common) | 4 | [base/ntsetup/eulas_etc/sbsonly/common/sources](../../base/ntsetup/eulas_etc/sbsonly/common/sources), [base/ntsetup/eulas_etc/sbsonly/common/makefile](../../base/ntsetup/eulas_etc/sbsonly/common/makefile) | — | `NOTARGET` |
| [base/ntsetup/eulas_etc/sbsonly/export](../../base/ntsetup/eulas_etc/sbsonly/export) | 4 | [base/ntsetup/eulas_etc/sbsonly/export/sources](../../base/ntsetup/eulas_etc/sbsonly/export/sources), [base/ntsetup/eulas_etc/sbsonly/export/makefile](../../base/ntsetup/eulas_etc/sbsonly/export/makefile) | — | `NOTARGET` |
| [base/ntsetup/excppkg](../../base/ntsetup/excppkg) | 3 | [base/ntsetup/excppkg/sources](../../base/ntsetup/excppkg/sources), [base/ntsetup/excppkg/makefile](../../base/ntsetup/excppkg/makefile) | `excppkg` | `LIBRARY` |
| [base/ntsetup/excppkg/test](../../base/ntsetup/excppkg/test) | 3 | [base/ntsetup/excppkg/test/sources](../../base/ntsetup/excppkg/test/sources), [base/ntsetup/excppkg/test/makefile](../../base/ntsetup/excppkg/test/makefile) | `test` | `PROGRAM` |
| [base/ntsetup/excppkg/test2](../../base/ntsetup/excppkg/test2) | 5 | [base/ntsetup/excppkg/test2/sources](../../base/ntsetup/excppkg/test2/sources), [base/ntsetup/excppkg/test2/makefile](../../base/ntsetup/excppkg/test2/makefile) | `test` | `PROGRAM` |
| [base/ntsetup/excppkg/test3](../../base/ntsetup/excppkg/test3) | 4 | [base/ntsetup/excppkg/test3/sources](../../base/ntsetup/excppkg/test3/sources), [base/ntsetup/excppkg/test3/makefile](../../base/ntsetup/excppkg/test3/makefile) | `test` | `PROGRAM` |
| [base/ntsetup/hives](../../base/ntsetup/hives) | 8 | [base/ntsetup/hives/dirs](../../base/ntsetup/hives/dirs) | — | — |
| [base/ntsetup/hives/blade](../../base/ntsetup/hives/blade) | 3 | [base/ntsetup/hives/blade/sources](../../base/ntsetup/hives/blade/sources), [base/ntsetup/hives/blade/makefile](../../base/ntsetup/hives/blade/makefile) | — | `NOTARGET` |
| [base/ntsetup/hives/datacenter](../../base/ntsetup/hives/datacenter) | 3 | [base/ntsetup/hives/datacenter/sources](../../base/ntsetup/hives/datacenter/sources), [base/ntsetup/hives/datacenter/makefile](../../base/ntsetup/hives/datacenter/makefile) | — | `NOTARGET` |
| [base/ntsetup/hives/enterprise](../../base/ntsetup/hives/enterprise) | 3 | [base/ntsetup/hives/enterprise/sources](../../base/ntsetup/hives/enterprise/sources), [base/ntsetup/hives/enterprise/makefile](../../base/ntsetup/hives/enterprise/makefile) | — | `NOTARGET` |
| [base/ntsetup/hives/personal](../../base/ntsetup/hives/personal) | 3 | [base/ntsetup/hives/personal/sources](../../base/ntsetup/hives/personal/sources), [base/ntsetup/hives/personal/makefile](../../base/ntsetup/hives/personal/makefile) | — | `NOTARGET` |
| [base/ntsetup/hives/retail](../../base/ntsetup/hives/retail) | 3 | [base/ntsetup/hives/retail/sources](../../base/ntsetup/hives/retail/sources), [base/ntsetup/hives/retail/makefile](../../base/ntsetup/hives/retail/makefile) | — | `NOTARGET` |
| [base/ntsetup/hives/server](../../base/ntsetup/hives/server) | 3 | [base/ntsetup/hives/server/sources](../../base/ntsetup/hives/server/sources), [base/ntsetup/hives/server/makefile](../../base/ntsetup/hives/server/makefile) | — | `NOTARGET` |
| [base/ntsetup/hives/smallbiz](../../base/ntsetup/hives/smallbiz) | 3 | [base/ntsetup/hives/smallbiz/sources](../../base/ntsetup/hives/smallbiz/sources), [base/ntsetup/hives/smallbiz/makefile](../../base/ntsetup/hives/smallbiz/makefile) | — | `NOTARGET` |
| [base/ntsetup/hwdb](../../base/ntsetup/hwdb) | 7 | [base/ntsetup/hwdb/dirs](../../base/ntsetup/hwdb/dirs) | — | — |
| [base/ntsetup/hwdb/hwdb](../../base/ntsetup/hwdb/hwdb) | 4 | [base/ntsetup/hwdb/hwdb/sources](../../base/ntsetup/hwdb/hwdb/sources), [base/ntsetup/hwdb/hwdb/makefile](../../base/ntsetup/hwdb/hwdb/makefile) | `hwdb` | `DYNLINK` |
| [base/ntsetup/hwdb/hwdblib](../../base/ntsetup/hwdb/hwdblib) | 2 | [base/ntsetup/hwdb/hwdblib/sources](../../base/ntsetup/hwdb/hwdblib/sources), [base/ntsetup/hwdb/hwdblib/makefile](../../base/ntsetup/hwdb/hwdblib/makefile) | `hwdblib` | `LIBRARY` |
| [base/ntsetup/hwdb/inc](../../base/ntsetup/hwdb/inc) | 3 | — | — | — |
| [base/ntsetup/hwdb/utils](../../base/ntsetup/hwdb/utils) | 2 | [base/ntsetup/hwdb/utils/dirs](../../base/ntsetup/hwdb/utils/dirs) | — | — |
| [base/ntsetup/hwdb/utils/inc](../../base/ntsetup/hwdb/utils/inc) | 25 | — | — | — |
| [base/ntsetup/hwdb/utils/main](../../base/ntsetup/hwdb/utils/main) | 21 | [base/ntsetup/hwdb/utils/main/sources](../../base/ntsetup/hwdb/utils/main/sources), [base/ntsetup/hwdb/utils/main/makefile](../../base/ntsetup/hwdb/utils/main/makefile) | `utils` | `LIBRARY` |
| [base/ntsetup/hwdb/utils/pch](../../base/ntsetup/hwdb/utils/pch) | 4 | [base/ntsetup/hwdb/utils/pch/sources](../../base/ntsetup/hwdb/utils/pch/sources), [base/ntsetup/hwdb/utils/pch/makefile](../../base/ntsetup/hwdb/utils/pch/makefile) | `pch` | `LIBRARY` |
| [base/ntsetup/hwlog](../../base/ntsetup/hwlog) | 3 | [base/ntsetup/hwlog/sources](../../base/ntsetup/hwlog/sources), [base/ntsetup/hwlog/makefile](../../base/ntsetup/hwlog/makefile) | `hwlog` | `LIBRARY` |
| [base/ntsetup/inc](../../base/ntsetup/inc) | 11 | — | — | — |
| [base/ntsetup/inf](../../base/ntsetup/inf) | 10 | [base/ntsetup/inf/dirs](../../base/ntsetup/inf/dirs) | — | — |
| [base/ntsetup/inf/beta](../../base/ntsetup/inf/beta) | 118 | — | — | — |
| [base/ntsetup/inf/beta/i386](../../base/ntsetup/inf/beta/i386) | 17 | — | — | — |
| [base/ntsetup/inf/daytona](../../base/ntsetup/inf/daytona) | 3 | [base/ntsetup/inf/daytona/sources](../../base/ntsetup/inf/daytona/sources), [base/ntsetup/inf/daytona/makefile](../../base/ntsetup/inf/daytona/makefile) | — | — |
| [base/ntsetup/inf/filelist](../../base/ntsetup/inf/filelist) | 0 | — | — | — |
| [base/ntsetup/inf/filelist/lmcd](../../base/ntsetup/inf/filelist/lmcd) | 0 | — | — | — |
| [base/ntsetup/inf/filelist/lmcd/i386](../../base/ntsetup/inf/filelist/lmcd/i386) | 9 | — | — | — |
| [base/ntsetup/inf/filelist/ntcd](../../base/ntsetup/inf/filelist/ntcd) | 0 | — | — | — |
| [base/ntsetup/inf/filelist/ntcd/i386](../../base/ntsetup/inf/filelist/ntcd/i386) | 11 | — | — | — |
| [base/ntsetup/inf/newinf](../../base/ntsetup/inf/newinf) | 0 | — | — | — |
| [base/ntsetup/inf/newinf/daytona](../../base/ntsetup/inf/newinf/daytona) | 0 | — | — | — |
| [base/ntsetup/inf/newinf/daytona/lmcd](../../base/ntsetup/inf/newinf/daytona/lmcd) | 0 | — | — | — |
| [base/ntsetup/inf/newinf/daytona/lmcd/i386](../../base/ntsetup/inf/newinf/daytona/lmcd/i386) | 2 | — | — | — |
| [base/ntsetup/inf/newinf/daytona/lmcd/ia64](../../base/ntsetup/inf/newinf/daytona/lmcd/ia64) | 1 | — | — | — |
| [base/ntsetup/inf/newinf/daytona/ntcd](../../base/ntsetup/inf/newinf/daytona/ntcd) | 0 | — | — | — |
| [base/ntsetup/inf/newinf/daytona/ntcd/i386](../../base/ntsetup/inf/newinf/daytona/ntcd/i386) | 2 | — | — | — |
| [base/ntsetup/inf/newinf/daytona/ntcd/ia64](../../base/ntsetup/inf/newinf/daytona/ntcd/ia64) | 1 | — | — | — |
| [base/ntsetup/inf/win4](../../base/ntsetup/inf/win4) | 1 | [base/ntsetup/inf/win4/dirs](../../base/ntsetup/inf/win4/dirs) | — | — |
| [base/ntsetup/inf/win4/inf](../../base/ntsetup/inf/win4/inf) | 1 | — | — | — |
| [base/ntsetup/inf/win4/inf/chs](../../base/ntsetup/inf/win4/inf/chs) | 1 | — | — | — |
| [base/ntsetup/inf/win4/inf/cht](../../base/ntsetup/inf/win4/inf/cht) | 1 | — | — | — |
| [base/ntsetup/inf/win4/inf/jpn](../../base/ntsetup/inf/win4/inf/jpn) | 1 | — | — | — |
| [base/ntsetup/inf/win4/inf/kor](../../base/ntsetup/inf/win4/inf/kor) | 1 | — | — | — |
| [base/ntsetup/inf/win4/inf/usa](../../base/ntsetup/inf/win4/inf/usa) | 1 | — | — | — |
| [base/ntsetup/inf/win4/tools](../../base/ntsetup/inf/win4/tools) | 2 | [base/ntsetup/inf/win4/tools/dirs](../../base/ntsetup/inf/win4/tools/dirs) | — | — |
| [base/ntsetup/inf/win4/tools/cabcheck](../../base/ntsetup/inf/win4/tools/cabcheck) | 6 | [base/ntsetup/inf/win4/tools/cabcheck/sources](../../base/ntsetup/inf/win4/tools/cabcheck/sources), [base/ntsetup/inf/win4/tools/cabcheck/makefile](../../base/ntsetup/inf/win4/tools/cabcheck/makefile) | `cabcheck` | `PROGRAM` |
| [base/ntsetup/inf/win4/tools/escpeinf](../../base/ntsetup/inf/win4/tools/escpeinf) | 5 | [base/ntsetup/inf/win4/tools/escpeinf/sources](../../base/ntsetup/inf/win4/tools/escpeinf/sources), [base/ntsetup/inf/win4/tools/escpeinf/makefile](../../base/ntsetup/inf/win4/tools/escpeinf/makefile) | `escpeinf` | `PROGRAM` |
| [base/ntsetup/inf/win4/tools/inc](../../base/ntsetup/inf/win4/tools/inc) | 2 | — | — | — |
| [base/ntsetup/inf/win4/tools/infdump](../../base/ntsetup/inf/win4/tools/infdump) | 6 | [base/ntsetup/inf/win4/tools/infdump/sources](../../base/ntsetup/inf/win4/tools/infdump/sources), [base/ntsetup/inf/win4/tools/infdump/makefile](../../base/ntsetup/inf/win4/tools/infdump/makefile) | `infdump` | `PROGRAM` |
| [base/ntsetup/inf/win4/tools/inflib](../../base/ntsetup/inf/win4/tools/inflib) | 3 | [base/ntsetup/inf/win4/tools/inflib/sources](../../base/ntsetup/inf/win4/tools/inflib/sources), [base/ntsetup/inf/win4/tools/inflib/makefile](../../base/ntsetup/inf/win4/tools/inflib/makefile) | `inflib` | `LIBRARY` |
| [base/ntsetup/inf/win4/tools/infmerge](../../base/ntsetup/inf/win4/tools/infmerge) | 4 | [base/ntsetup/inf/win4/tools/infmerge/sources](../../base/ntsetup/inf/win4/tools/infmerge/sources), [base/ntsetup/inf/win4/tools/infmerge/makefile](../../base/ntsetup/inf/win4/tools/infmerge/makefile) | `infmerge` | `PROGRAM` |
| [base/ntsetup/inf/win4/tools/inftest](../../base/ntsetup/inf/win4/tools/inftest) | 7 | [base/ntsetup/inf/win4/tools/inftest/sources](../../base/ntsetup/inf/win4/tools/inftest/sources), [base/ntsetup/inf/win4/tools/inftest/makefile](../../base/ntsetup/inf/win4/tools/inftest/makefile) | `inftest` | `PROGRAM` |
| [base/ntsetup/inf/win4/tools/ocinf](../../base/ntsetup/inf/win4/tools/ocinf) | 4 | [base/ntsetup/inf/win4/tools/ocinf/sources](../../base/ntsetup/inf/win4/tools/ocinf/sources), [base/ntsetup/inf/win4/tools/ocinf/makefile](../../base/ntsetup/inf/win4/tools/ocinf/makefile) | `ocinf` | `PROGRAM` |
| [base/ntsetup/inf/win4/tools/prodfilt](../../base/ntsetup/inf/win4/tools/prodfilt) | 4 | [base/ntsetup/inf/win4/tools/prodfilt/sources](../../base/ntsetup/inf/win4/tools/prodfilt/sources), [base/ntsetup/inf/win4/tools/prodfilt/makefile](../../base/ntsetup/inf/win4/tools/prodfilt/makefile) | `prodfilt` | `PROGRAM` |
| [base/ntsetup/inf/win4/tools/recab](../../base/ntsetup/inf/win4/tools/recab) | 4 | [base/ntsetup/inf/win4/tools/recab/sources](../../base/ntsetup/inf/win4/tools/recab/sources), [base/ntsetup/inf/win4/tools/recab/makefile](../../base/ntsetup/inf/win4/tools/recab/makefile) | `recab` | `PROGRAM` |
| [base/ntsetup/inf/win4/tools/sizes](../../base/ntsetup/inf/win4/tools/sizes) | 5 | [base/ntsetup/inf/win4/tools/sizes/sources](../../base/ntsetup/inf/win4/tools/sizes/sources), [base/ntsetup/inf/win4/tools/sizes/makefile](../../base/ntsetup/inf/win4/tools/sizes/makefile) | `sizes` | `PROGRAM` |
| [base/ntsetup/inf/win4/tools/stampinf](../../base/ntsetup/inf/win4/tools/stampinf) | 5 | [base/ntsetup/inf/win4/tools/stampinf/sources](../../base/ntsetup/inf/win4/tools/stampinf/sources), [base/ntsetup/inf/win4/tools/stampinf/makefile](../../base/ntsetup/inf/win4/tools/stampinf/makefile) | `stampinf` | `PROGRAM` |
| [base/ntsetup/inf/win4/tools/unitext](../../base/ntsetup/inf/win4/tools/unitext) | 12 | [base/ntsetup/inf/win4/tools/unitext/sources](../../base/ntsetup/inf/win4/tools/unitext/sources), [base/ntsetup/inf/win4/tools/unitext/makefile](../../base/ntsetup/inf/win4/tools/unitext/makefile) | `unitext` | `PROGRAM` |
| [base/ntsetup/inf/win4/tools/wowlist](../../base/ntsetup/inf/win4/tools/wowlist) | 4 | [base/ntsetup/inf/win4/tools/wowlist/sources](../../base/ntsetup/inf/win4/tools/wowlist/sources), [base/ntsetup/inf/win4/tools/wowlist/makefile](../../base/ntsetup/inf/win4/tools/wowlist/makefile) | `wowlist` | `PROGRAM` |
| [base/ntsetup/inf/win4/tools/xdosnet](../../base/ntsetup/inf/win4/tools/xdosnet) | 4 | [base/ntsetup/inf/win4/tools/xdosnet/sources](../../base/ntsetup/inf/win4/tools/xdosnet/sources), [base/ntsetup/inf/win4/tools/xdosnet/makefile](../../base/ntsetup/inf/win4/tools/xdosnet/makefile) | `xdosnet` | `PROGRAM` |
| [base/ntsetup/legacy](../../base/ntsetup/legacy) | 2 | [base/ntsetup/legacy/dirs](../../base/ntsetup/legacy/dirs) | — | — |
| [base/ntsetup/legacy/dll](../../base/ntsetup/legacy/dll) | 126 | [base/ntsetup/legacy/dll/sources](../../base/ntsetup/legacy/dll/sources), [base/ntsetup/legacy/dll/makefile](../../base/ntsetup/legacy/dll/makefile) | `setupdll` | `DYNLINK` |
| [base/ntsetup/legacy/dll/i386](../../base/ntsetup/legacy/dll/i386) | 4 | [base/ntsetup/legacy/dll/i386/sources](../../base/ntsetup/legacy/dll/i386/sources) | — | — |
| [base/ntsetup/legacy/dll/resource](../../base/ntsetup/legacy/dll/resource) | 14 | — | — | — |
| [base/ntsetup/legacy/dll/resource/usa](../../base/ntsetup/legacy/dll/resource/usa) | 12 | — | — | — |
| [base/ntsetup/legacy/exe](../../base/ntsetup/legacy/exe) | 5 | [base/ntsetup/legacy/exe/sources](../../base/ntsetup/legacy/exe/sources), [base/ntsetup/legacy/exe/makefile](../../base/ntsetup/legacy/exe/makefile) | `setup` | `PROGRAM` |
| [base/ntsetup/libmsg](../../base/ntsetup/libmsg) | 4 | [base/ntsetup/libmsg/sources](../../base/ntsetup/libmsg/sources), [base/ntsetup/libmsg/makefile](../../base/ntsetup/libmsg/makefile) | `libmsg` | `LIBRARY` |
| [base/ntsetup/localinf](../../base/ntsetup/localinf) | 5 | [base/ntsetup/localinf/sources](../../base/ntsetup/localinf/sources), [base/ntsetup/localinf/makefile](../../base/ntsetup/localinf/makefile) | `local` | `PROGRAM` |
| [base/ntsetup/migdlls](../../base/ntsetup/migdlls) | 1 | [base/ntsetup/migdlls/dirs](../../base/ntsetup/migdlls/dirs) | — | — |
| [base/ntsetup/migdlls/src](../../base/ntsetup/migdlls/src) | 1 | [base/ntsetup/migdlls/src/dirs](../../base/ntsetup/migdlls/src/dirs) | — | — |
| [base/ntsetup/migdlls/src/inc](../../base/ntsetup/migdlls/src/inc) | 3 | — | — | — |
| [base/ntsetup/migdlls/src/miglib](../../base/ntsetup/migdlls/src/miglib) | 8 | [base/ntsetup/migdlls/src/miglib/dirs](../../base/ntsetup/migdlls/src/miglib/dirs) | — | — |
| [base/ntsetup/migdlls/src/miglib/dll](../../base/ntsetup/migdlls/src/miglib/dll) | 5 | [base/ntsetup/migdlls/src/miglib/dll/sources](../../base/ntsetup/migdlls/src/miglib/dll/sources), [base/ntsetup/migdlls/src/miglib/dll/makefile](../../base/ntsetup/migdlls/src/miglib/dll/makefile) | `miglibnt` | `DYNLINK` |
| [base/ntsetup/migdlls/src/miglib/lib](../../base/ntsetup/migdlls/src/miglib/lib) | 2 | [base/ntsetup/migdlls/src/miglib/lib/sources](../../base/ntsetup/migdlls/src/miglib/lib/sources), [base/ntsetup/migdlls/src/miglib/lib/makefile](../../base/ntsetup/migdlls/src/miglib/lib/makefile) | `miglib` | `LIBRARY` |
| [base/ntsetup/migdlls/src/utils](../../base/ntsetup/migdlls/src/utils) | 2 | [base/ntsetup/migdlls/src/utils/dirs](../../base/ntsetup/migdlls/src/utils/dirs) | — | — |
| [base/ntsetup/migdlls/src/utils/file](../../base/ntsetup/migdlls/src/utils/file) | 4 | [base/ntsetup/migdlls/src/utils/file/sources](../../base/ntsetup/migdlls/src/utils/file/sources), [base/ntsetup/migdlls/src/utils/file/makefile](../../base/ntsetup/migdlls/src/utils/file/makefile) | `file` | `LIBRARY` |
| [base/ntsetup/migdlls/src/utils/inc](../../base/ntsetup/migdlls/src/utils/inc) | 25 | — | — | — |
| [base/ntsetup/migdlls/src/utils/inf](../../base/ntsetup/migdlls/src/utils/inf) | 4 | [base/ntsetup/migdlls/src/utils/inf/sources](../../base/ntsetup/migdlls/src/utils/inf/sources), [base/ntsetup/migdlls/src/utils/inf/makefile](../../base/ntsetup/migdlls/src/utils/inf/makefile) | `inf` | `LIBRARY` |
| [base/ntsetup/migdlls/src/utils/ini](../../base/ntsetup/migdlls/src/utils/ini) | 3 | [base/ntsetup/migdlls/src/utils/ini/sources](../../base/ntsetup/migdlls/src/utils/ini/sources), [base/ntsetup/migdlls/src/utils/ini/makefile](../../base/ntsetup/migdlls/src/utils/ini/makefile) | `ini` | `LIBRARY` |
| [base/ntsetup/migdlls/src/utils/ipc](../../base/ntsetup/migdlls/src/utils/ipc) | 3 | [base/ntsetup/migdlls/src/utils/ipc/sources](../../base/ntsetup/migdlls/src/utils/ipc/sources), [base/ntsetup/migdlls/src/utils/ipc/makefile](../../base/ntsetup/migdlls/src/utils/ipc/makefile) | `ipc` | `LIBRARY` |
| [base/ntsetup/migdlls/src/utils/main](../../base/ntsetup/migdlls/src/utils/main) | 21 | [base/ntsetup/migdlls/src/utils/main/sources](../../base/ntsetup/migdlls/src/utils/main/sources), [base/ntsetup/migdlls/src/utils/main/makefile](../../base/ntsetup/migdlls/src/utils/main/makefile) | `utils` | `LIBRARY` |
| [base/ntsetup/migdlls/src/utils/memdb](../../base/ntsetup/migdlls/src/utils/memdb) | 17 | [base/ntsetup/migdlls/src/utils/memdb/sources](../../base/ntsetup/migdlls/src/utils/memdb/sources), [base/ntsetup/migdlls/src/utils/memdb/makefile](../../base/ntsetup/migdlls/src/utils/memdb/makefile) | `memdb` | `LIBRARY` |
| [base/ntsetup/migdlls/src/utils/pch](../../base/ntsetup/migdlls/src/utils/pch) | 4 | [base/ntsetup/migdlls/src/utils/pch/sources](../../base/ntsetup/migdlls/src/utils/pch/sources), [base/ntsetup/migdlls/src/utils/pch/makefile](../../base/ntsetup/migdlls/src/utils/pch/makefile) | `pch` | `LIBRARY` |
| [base/ntsetup/migdlls/src/utils/reg](../../base/ntsetup/migdlls/src/utils/reg) | 5 | [base/ntsetup/migdlls/src/utils/reg/sources](../../base/ntsetup/migdlls/src/utils/reg/sources), [base/ntsetup/migdlls/src/utils/reg/makefile](../../base/ntsetup/migdlls/src/utils/reg/makefile) | `reg` | `LIBRARY` |
| [base/ntsetup/migdlls/src/utils/sandbox](../../base/ntsetup/migdlls/src/utils/sandbox) | 3 | [base/ntsetup/migdlls/src/utils/sandbox/sources](../../base/ntsetup/migdlls/src/utils/sandbox/sources), [base/ntsetup/migdlls/src/utils/sandbox/makefile](../../base/ntsetup/migdlls/src/utils/sandbox/makefile) | `utils` | `LIBRARY` |
| [base/ntsetup/moricons](../../base/ntsetup/moricons) | 118 | [base/ntsetup/moricons/sources](../../base/ntsetup/moricons/sources), [base/ntsetup/moricons/makefile](../../base/ntsetup/moricons/makefile) | `moricons` | `DYNLINK` |
| [base/ntsetup/mpk](../../base/ntsetup/mpk) | 2 | — | — | — |
| [base/ntsetup/mpk/diskstat](../../base/ntsetup/mpk/diskstat) | 3 | [base/ntsetup/mpk/diskstat/makefile](../../base/ntsetup/mpk/diskstat/makefile) | — | — |
| [base/ntsetup/mpk/displib](../../base/ntsetup/mpk/displib) | 5 | [base/ntsetup/mpk/displib/makefile](../../base/ntsetup/mpk/displib/makefile) | — | — |
| [base/ntsetup/mpk/doc](../../base/ntsetup/mpk/doc) | 1 | — | — | — |
| [base/ntsetup/mpk/enduser](../../base/ntsetup/mpk/enduser) | 13 | [base/ntsetup/mpk/enduser/makefile](../../base/ntsetup/mpk/enduser/makefile) | — | — |
| [base/ntsetup/mpk/imagpart](../../base/ntsetup/mpk/imagpart) | 8 | [base/ntsetup/mpk/imagpart/makefile](../../base/ntsetup/mpk/imagpart/makefile) | — | — |
| [base/ntsetup/mpk/inc](../../base/ntsetup/mpk/inc) | 8 | — | — | — |
| [base/ntsetup/mpk/iolib](../../base/ntsetup/mpk/iolib) | 8 | [base/ntsetup/mpk/iolib/makefile](../../base/ntsetup/mpk/iolib/makefile) | — | — |
| [base/ntsetup/mpk/makemast](../../base/ntsetup/mpk/makemast) | 5 | [base/ntsetup/mpk/makemast/makefile](../../base/ntsetup/mpk/makemast/makefile) | — | — |
| [base/ntsetup/mpk/misclib](../../base/ntsetup/mpk/misclib) | 17 | [base/ntsetup/mpk/misclib/makefile](../../base/ntsetup/mpk/misclib/makefile) | — | — |
| [base/ntsetup/msoobci](../../base/ntsetup/msoobci) | 13 | [base/ntsetup/msoobci/sources](../../base/ntsetup/msoobci/sources), [base/ntsetup/msoobci/makefile](../../base/ntsetup/msoobci/makefile) | `msoobci` | `DYNLINK` |
| [base/ntsetup/ntcab](../../base/ntsetup/ntcab) | 1 | [base/ntsetup/ntcab/dirs](../../base/ntsetup/ntcab/dirs) | — | — |
| [base/ntsetup/ntcab/inc](../../base/ntsetup/ntcab/inc) | 1 | — | — | — |
| [base/ntsetup/ntcab/lib](../../base/ntsetup/ntcab/lib) | 10 | [base/ntsetup/ntcab/lib/sources](../../base/ntsetup/ntcab/lib/sources), [base/ntsetup/ntcab/lib/makefile](../../base/ntsetup/ntcab/lib/makefile) | `ntcab` | `LIBRARY` |
| [base/ntsetup/ntcab/tool](../../base/ntsetup/ntcab/tool) | 3 | [base/ntsetup/ntcab/tool/sources](../../base/ntsetup/ntcab/tool/sources), [base/ntsetup/ntcab/tool/makefile](../../base/ntsetup/ntcab/tool/makefile) | `ntcab` | `PROGRAM` |
| [base/ntsetup/ntoc](../../base/ntsetup/ntoc) | 18 | [base/ntsetup/ntoc/sources](../../base/ntsetup/ntoc/sources), [base/ntsetup/ntoc/makefile](../../base/ntsetup/ntoc/makefile) | `ntoc` | `DYNLINK` |
| [base/ntsetup/ocmanage](../../base/ntsetup/ocmanage) | 1 | [base/ntsetup/ocmanage/dirs](../../base/ntsetup/ocmanage/dirs) | — | — |
| [base/ntsetup/ocmanage/common](../../base/ntsetup/ocmanage/common) | 19 | [base/ntsetup/ocmanage/common/dirs](../../base/ntsetup/ocmanage/common/dirs) | — | — |
| [base/ntsetup/ocmanage/common/ansi](../../base/ntsetup/ocmanage/common/ansi) | 4 | [base/ntsetup/ocmanage/common/ansi/sources](../../base/ntsetup/ocmanage/common/ansi/sources), [base/ntsetup/ocmanage/common/ansi/makefile](../../base/ntsetup/ocmanage/common/ansi/makefile) | `ocmanaga` | — |
| [base/ntsetup/ocmanage/common/unicode](../../base/ntsetup/ocmanage/common/unicode) | 5 | [base/ntsetup/ocmanage/common/unicode/sources](../../base/ntsetup/ocmanage/common/unicode/sources), [base/ntsetup/ocmanage/common/unicode/makefile](../../base/ntsetup/ocmanage/common/unicode/makefile) | `ocmanage` | — |
| [base/ntsetup/ocmanage/generic](../../base/ntsetup/ocmanage/generic) | 8 | [base/ntsetup/ocmanage/generic/dirs](../../base/ntsetup/ocmanage/generic/dirs) | — | — |
| [base/ntsetup/ocmanage/generic/ansi](../../base/ntsetup/ocmanage/generic/ansi) | 2 | [base/ntsetup/ocmanage/generic/ansi/sources](../../base/ntsetup/ocmanage/generic/ansi/sources), [base/ntsetup/ocmanage/generic/ansi/makefile](../../base/ntsetup/ocmanage/generic/ansi/makefile) | `ocgena` | — |
| [base/ntsetup/ocmanage/generic/res](../../base/ntsetup/ocmanage/generic/res) | 3 | — | — | — |
| [base/ntsetup/ocmanage/generic/unicode](../../base/ntsetup/ocmanage/generic/unicode) | 2 | [base/ntsetup/ocmanage/generic/unicode/sources](../../base/ntsetup/ocmanage/generic/unicode/sources), [base/ntsetup/ocmanage/generic/unicode/makefile](../../base/ntsetup/ocmanage/generic/unicode/makefile) | `ocgen` | — |
| [base/ntsetup/ocmanage/sysocmgr](../../base/ntsetup/ocmanage/sysocmgr) | 16 | [base/ntsetup/ocmanage/sysocmgr/dirs](../../base/ntsetup/ocmanage/sysocmgr/dirs) | — | — |
| [base/ntsetup/ocmanage/sysocmgr/ansi](../../base/ntsetup/ocmanage/sysocmgr/ansi) | 3 | [base/ntsetup/ocmanage/sysocmgr/ansi/sources](../../base/ntsetup/ocmanage/sysocmgr/ansi/sources), [base/ntsetup/ocmanage/sysocmgr/ansi/makefile](../../base/ntsetup/ocmanage/sysocmgr/ansi/makefile) | `sysocmga` | `PROGRAM` |
| [base/ntsetup/ocmanage/sysocmgr/unicode](../../base/ntsetup/ocmanage/sysocmgr/unicode) | 4 | [base/ntsetup/ocmanage/sysocmgr/unicode/sources](../../base/ntsetup/ocmanage/sysocmgr/unicode/sources), [base/ntsetup/ocmanage/sysocmgr/unicode/makefile](../../base/ntsetup/ocmanage/sysocmgr/unicode/makefile) | `sysocmgr` | `PROGRAM` |
| [base/ntsetup/ocmanage/testoc](../../base/ntsetup/ocmanage/testoc) | 20 | [base/ntsetup/ocmanage/testoc/dirs](../../base/ntsetup/ocmanage/testoc/dirs) | — | — |
| [base/ntsetup/ocmanage/testoc/ansi](../../base/ntsetup/ocmanage/testoc/ansi) | 6 | [base/ntsetup/ocmanage/testoc/ansi/sources](../../base/ntsetup/ocmanage/testoc/ansi/sources), [base/ntsetup/ocmanage/testoc/ansi/makefile](../../base/ntsetup/ocmanage/testoc/ansi/makefile) | `octest_a` | — |
| [base/ntsetup/ocmanage/testoc/checkinf](../../base/ntsetup/ocmanage/testoc/checkinf) | 9 | [base/ntsetup/ocmanage/testoc/checkinf/sources](../../base/ntsetup/ocmanage/testoc/checkinf/sources), [base/ntsetup/ocmanage/testoc/checkinf/makefile](../../base/ntsetup/ocmanage/testoc/checkinf/makefile) | `checkinf` | `PROGRAM` |
| [base/ntsetup/ocmanage/testoc/cleanreg](../../base/ntsetup/ocmanage/testoc/cleanreg) | 3 | [base/ntsetup/ocmanage/testoc/cleanreg/sources](../../base/ntsetup/ocmanage/testoc/cleanreg/sources), [base/ntsetup/ocmanage/testoc/cleanreg/makefile](../../base/ntsetup/ocmanage/testoc/cleanreg/makefile) | `cleanreg` | `PROGRAM` |
| [base/ntsetup/ocmanage/testoc/hctlib](../../base/ntsetup/ocmanage/testoc/hctlib) | 8 | [base/ntsetup/ocmanage/testoc/hctlib/dirs](../../base/ntsetup/ocmanage/testoc/hctlib/dirs) | — | — |
| [base/ntsetup/ocmanage/testoc/hctlib/ansi](../../base/ntsetup/ocmanage/testoc/hctlib/ansi) | 2 | [base/ntsetup/ocmanage/testoc/hctlib/ansi/sources](../../base/ntsetup/ocmanage/testoc/hctlib/ansi/sources), [base/ntsetup/ocmanage/testoc/hctlib/ansi/makefile](../../base/ntsetup/ocmanage/testoc/hctlib/ansi/makefile) | `hctlib_a` | — |
| [base/ntsetup/ocmanage/testoc/hctlib/unicode](../../base/ntsetup/ocmanage/testoc/hctlib/unicode) | 2 | [base/ntsetup/ocmanage/testoc/hctlib/unicode/sources](../../base/ntsetup/ocmanage/testoc/hctlib/unicode/sources), [base/ntsetup/ocmanage/testoc/hctlib/unicode/makefile](../../base/ntsetup/ocmanage/testoc/hctlib/unicode/makefile) | `hctlib_u` | — |
| [base/ntsetup/ocmanage/testoc/octest](../../base/ntsetup/ocmanage/testoc/octest) | 14 | — | — | — |
| [base/ntsetup/ocmanage/testoc/octest/inf](../../base/ntsetup/ocmanage/testoc/octest/inf) | 2 | — | — | — |
| [base/ntsetup/ocmanage/testoc/octest/inf/1](../../base/ntsetup/ocmanage/testoc/octest/inf/1) | 4 | — | — | — |
| [base/ntsetup/ocmanage/testoc/octest/inf/2](../../base/ntsetup/ocmanage/testoc/octest/inf/2) | 2 | — | — | — |
| [base/ntsetup/ocmanage/testoc/octest/inf/3](../../base/ntsetup/ocmanage/testoc/octest/inf/3) | 6 | — | — | — |
| [base/ntsetup/ocmanage/testoc/octest/inf/4](../../base/ntsetup/ocmanage/testoc/octest/inf/4) | 3 | — | — | — |
| [base/ntsetup/ocmanage/testoc/octest/inf/5](../../base/ntsetup/ocmanage/testoc/octest/inf/5) | 3 | — | — | — |
| [base/ntsetup/ocmanage/testoc/octest/inf/6](../../base/ntsetup/ocmanage/testoc/octest/inf/6) | 6 | — | — | — |
| [base/ntsetup/ocmanage/testoc/octest/inf/7](../../base/ntsetup/ocmanage/testoc/octest/inf/7) | 4 | — | — | — |
| [base/ntsetup/ocmanage/testoc/octest/inf/8](../../base/ntsetup/ocmanage/testoc/octest/inf/8) | 4 | — | — | — |
| [base/ntsetup/ocmanage/testoc/octest/inf/d1](../../base/ntsetup/ocmanage/testoc/octest/inf/d1) | 4 | — | — | — |
| [base/ntsetup/ocmanage/testoc/octest/inf/d11](../../base/ntsetup/ocmanage/testoc/octest/inf/d11) | 4 | — | — | — |
| [base/ntsetup/ocmanage/testoc/octest/inf/d12](../../base/ntsetup/ocmanage/testoc/octest/inf/d12) | 4 | — | — | — |
| [base/ntsetup/ocmanage/testoc/octest/inf/d13](../../base/ntsetup/ocmanage/testoc/octest/inf/d13) | 4 | — | — | — |
| [base/ntsetup/ocmanage/testoc/octest/inf/d14](../../base/ntsetup/ocmanage/testoc/octest/inf/d14) | 4 | — | — | — |
| [base/ntsetup/ocmanage/testoc/octest/inf/d17](../../base/ntsetup/ocmanage/testoc/octest/inf/d17) | 4 | — | — | — |
| [base/ntsetup/ocmanage/testoc/octest/inf/d18](../../base/ntsetup/ocmanage/testoc/octest/inf/d18) | 4 | — | — | — |
| [base/ntsetup/ocmanage/testoc/octest/inf/d19](../../base/ntsetup/ocmanage/testoc/octest/inf/d19) | 4 | — | — | — |
| [base/ntsetup/ocmanage/testoc/octest/inf/d2](../../base/ntsetup/ocmanage/testoc/octest/inf/d2) | 4 | — | — | — |
| [base/ntsetup/ocmanage/testoc/octest/inf/d21](../../base/ntsetup/ocmanage/testoc/octest/inf/d21) | 4 | — | — | — |
| [base/ntsetup/ocmanage/testoc/octest/inf/d23](../../base/ntsetup/ocmanage/testoc/octest/inf/d23) | 4 | — | — | — |
| [base/ntsetup/ocmanage/testoc/octest/inf/d24](../../base/ntsetup/ocmanage/testoc/octest/inf/d24) | 4 | — | — | — |
| [base/ntsetup/ocmanage/testoc/octest/inf/d25](../../base/ntsetup/ocmanage/testoc/octest/inf/d25) | 5 | — | — | — |
| [base/ntsetup/ocmanage/testoc/octest/inf/d26](../../base/ntsetup/ocmanage/testoc/octest/inf/d26) | 5 | — | — | — |
| [base/ntsetup/ocmanage/testoc/octest/inf/d28](../../base/ntsetup/ocmanage/testoc/octest/inf/d28) | 3 | — | — | — |
| [base/ntsetup/ocmanage/testoc/octest/inf/d29](../../base/ntsetup/ocmanage/testoc/octest/inf/d29) | 4 | — | — | — |
| [base/ntsetup/ocmanage/testoc/octest/inf/d3](../../base/ntsetup/ocmanage/testoc/octest/inf/d3) | 4 | — | — | — |
| [base/ntsetup/ocmanage/testoc/octest/inf/d31](../../base/ntsetup/ocmanage/testoc/octest/inf/d31) | 4 | — | — | — |
| [base/ntsetup/ocmanage/testoc/octest/inf/d34](../../base/ntsetup/ocmanage/testoc/octest/inf/d34) | 19 | — | — | — |
| [base/ntsetup/ocmanage/testoc/octest/inf/d35](../../base/ntsetup/ocmanage/testoc/octest/inf/d35) | 3 | — | — | — |
| [base/ntsetup/ocmanage/testoc/octest/inf/d39](../../base/ntsetup/ocmanage/testoc/octest/inf/d39) | 3 | — | — | — |
| [base/ntsetup/ocmanage/testoc/octest/inf/d4](../../base/ntsetup/ocmanage/testoc/octest/inf/d4) | 4 | — | — | — |
| [base/ntsetup/ocmanage/testoc/octest/inf/d40](../../base/ntsetup/ocmanage/testoc/octest/inf/d40) | 3 | — | — | — |
| [base/ntsetup/ocmanage/testoc/octest/inf/d42](../../base/ntsetup/ocmanage/testoc/octest/inf/d42) | 3 | — | — | — |
| [base/ntsetup/ocmanage/testoc/octest/inf/d43](../../base/ntsetup/ocmanage/testoc/octest/inf/d43) | 3 | — | — | — |
| [base/ntsetup/ocmanage/testoc/octest/inf/d45](../../base/ntsetup/ocmanage/testoc/octest/inf/d45) | 4 | — | — | — |
| [base/ntsetup/ocmanage/testoc/octest/inf/d47](../../base/ntsetup/ocmanage/testoc/octest/inf/d47) | 3 | — | — | — |
| [base/ntsetup/ocmanage/testoc/octest/inf/d48](../../base/ntsetup/ocmanage/testoc/octest/inf/d48) | 3 | — | — | — |
| [base/ntsetup/ocmanage/testoc/octest/inf/d5](../../base/ntsetup/ocmanage/testoc/octest/inf/d5) | 4 | — | — | — |
| [base/ntsetup/ocmanage/testoc/octest/inf/d52](../../base/ntsetup/ocmanage/testoc/octest/inf/d52) | 3 | — | — | — |
| [base/ntsetup/ocmanage/testoc/octest/inf/d54](../../base/ntsetup/ocmanage/testoc/octest/inf/d54) | 3 | — | — | — |
| [base/ntsetup/ocmanage/testoc/octest/inf/d56](../../base/ntsetup/ocmanage/testoc/octest/inf/d56) | 4 | — | — | — |
| [base/ntsetup/ocmanage/testoc/octest/inf/d6](../../base/ntsetup/ocmanage/testoc/octest/inf/d6) | 4 | — | — | — |
| [base/ntsetup/ocmanage/testoc/octest/inf/d7](../../base/ntsetup/ocmanage/testoc/octest/inf/d7) | 3 | — | — | — |
| [base/ntsetup/ocmanage/testoc/octest/inf/g4](../../base/ntsetup/ocmanage/testoc/octest/inf/g4) | 3 | — | — | — |
| [base/ntsetup/ocmanage/testoc/octest/inf/g6](../../base/ntsetup/ocmanage/testoc/octest/inf/g6) | 3 | — | — | — |
| [base/ntsetup/ocmanage/testoc/octest/inf/i1](../../base/ntsetup/ocmanage/testoc/octest/inf/i1) | 3 | — | — | — |
| [base/ntsetup/ocmanage/testoc/octest/inf/i2](../../base/ntsetup/ocmanage/testoc/octest/inf/i2) | 17 | — | — | — |
| [base/ntsetup/ocmanage/testoc/octest/inf/i7](../../base/ntsetup/ocmanage/testoc/octest/inf/i7) | 3 | — | — | — |
| [base/ntsetup/ocmanage/testoc/octest/inf/s1](../../base/ntsetup/ocmanage/testoc/octest/inf/s1) | 5 | — | — | — |
| [base/ntsetup/ocmanage/testoc/octest/inf/s6](../../base/ntsetup/ocmanage/testoc/octest/inf/s6) | 8 | — | — | — |
| [base/ntsetup/ocmanage/testoc/unicode](../../base/ntsetup/ocmanage/testoc/unicode) | 6 | [base/ntsetup/ocmanage/testoc/unicode/sources](../../base/ntsetup/ocmanage/testoc/unicode/sources), [base/ntsetup/ocmanage/testoc/unicode/makefile](../../base/ntsetup/ocmanage/testoc/unicode/makefile) | `octest_u` | — |
| [base/ntsetup/oeminf](../../base/ntsetup/oeminf) | 9 | [base/ntsetup/oeminf/sources](../../base/ntsetup/oeminf/sources), [base/ntsetup/oeminf/makefile](../../base/ntsetup/oeminf/makefile) | `oeminf` | `PROGRAM` |
| [base/ntsetup/oempre](../../base/ntsetup/oempre) | 0 | — | — | — |
| [base/ntsetup/oempre/chkupgrd](../../base/ntsetup/oempre/chkupgrd) | 3 | [base/ntsetup/oempre/chkupgrd/sources](../../base/ntsetup/oempre/chkupgrd/sources), [base/ntsetup/oempre/chkupgrd/makefile](../../base/ntsetup/oempre/chkupgrd/makefile) | — | `NOTARGET` |
| [base/ntsetup/oempre/eventclear](../../base/ntsetup/oempre/eventclear) | 4 | [base/ntsetup/oempre/eventclear/sources](../../base/ntsetup/oempre/eventclear/sources), [base/ntsetup/oempre/eventclear/makefile](../../base/ntsetup/oempre/eventclear/makefile) | `eventclear` | `PROGRAM` |
| [base/ntsetup/oemtools](../../base/ntsetup/oemtools) | 0 | — | — | — |
| [base/ntsetup/oemtools/oemapply](../../base/ntsetup/oemtools/oemapply) | 0 | — | — | — |
| [base/ntsetup/oemtools/oemapply/ntnative](../../base/ntsetup/oemtools/oemapply/ntnative) | 4 | [base/ntsetup/oemtools/oemapply/ntnative/sources](../../base/ntsetup/oemtools/oemapply/ntnative/sources), [base/ntsetup/oemtools/oemapply/ntnative/makefile](../../base/ntsetup/oemtools/oemapply/ntnative/makefile) | `oemapply` | `PROGRAM` |
| [base/ntsetup/oemtools/oemapply/usermod](../../base/ntsetup/oemtools/oemapply/usermod) | 4 | [base/ntsetup/oemtools/oemapply/usermod/sources](../../base/ntsetup/oemtools/oemapply/usermod/sources), [base/ntsetup/oemtools/oemapply/usermod/makefile](../../base/ntsetup/oemtools/oemapply/usermod/makefile) | `oemapply` | `PROGRAM` |
| [base/ntsetup/oemtools/oempatch](../../base/ntsetup/oemtools/oempatch) | 12 | [base/ntsetup/oemtools/oempatch/sources](../../base/ntsetup/oemtools/oempatch/sources), [base/ntsetup/oemtools/oempatch/makefile](../../base/ntsetup/oemtools/oempatch/makefile) | `oempatch` | `PROGRAM` |
| [base/ntsetup/oemtools/oemshare](../../base/ntsetup/oemtools/oemshare) | 1 | — | — | — |
| [base/ntsetup/oobe](../../base/ntsetup/oobe) | 4 | [base/ntsetup/oobe/dirs](../../base/ntsetup/oobe/dirs) | — | — |
| [base/ntsetup/oobe/common](../../base/ntsetup/oobe/common) | 7 | [base/ntsetup/oobe/common/sources](../../base/ntsetup/oobe/common/sources), [base/ntsetup/oobe/common/makefile](../../base/ntsetup/oobe/common/makefile) | `obcommon` | `LIBRARY` |
| [base/ntsetup/oobe/data](../../base/ntsetup/oobe/data) | 16 | [base/ntsetup/oobe/data/sources](../../base/ntsetup/oobe/data/sources), [base/ntsetup/oobe/data/makefile](../../base/ntsetup/oobe/data/makefile) | — | `NOTARGET` |
| [base/ntsetup/oobe/docs](../../base/ntsetup/oobe/docs) | 3 | — | — | — |
| [base/ntsetup/oobe/html](../../base/ntsetup/oobe/html) | 26 | [base/ntsetup/oobe/html/sources](../../base/ntsetup/oobe/html/sources), [base/ntsetup/oobe/html/makefile](../../base/ntsetup/oobe/html/makefile) | — | `NOTARGET` |
| [base/ntsetup/oobe/html/actsetup](../../base/ntsetup/oobe/html/actsetup) | 16 | — | — | — |
| [base/ntsetup/oobe/html/agentsource](../../base/ntsetup/oobe/html/agentsource) | 1 | — | — | — |
| [base/ntsetup/oobe/html/error](../../base/ntsetup/oobe/html/error) | 9 | — | — | — |
| [base/ntsetup/oobe/html/html](../../base/ntsetup/oobe/html/html) | 0 | — | — | — |
| [base/ntsetup/oobe/html/html/dslmain](../../base/ntsetup/oobe/html/html/dslmain) | 4 | — | — | — |
| [base/ntsetup/oobe/html/html/iconnect](../../base/ntsetup/oobe/html/html/iconnect) | 2 | — | — | — |
| [base/ntsetup/oobe/html/html/ispsgnup](../../base/ntsetup/oobe/html/html/ispsgnup) | 6 | — | — | — |
| [base/ntsetup/oobe/html/html/isptype](../../base/ntsetup/oobe/html/html/isptype) | 1 | — | — | — |
| [base/ntsetup/oobe/html/html/migwiz](../../base/ntsetup/oobe/html/html/migwiz) | 6 | — | — | — |
| [base/ntsetup/oobe/html/html/mouse](../../base/ntsetup/oobe/html/html/mouse) | 12 | — | — | — |
| [base/ntsetup/oobe/html/html/mouse/images](../../base/ntsetup/oobe/html/html/mouse/images) | 32 | — | — | — |
| [base/ntsetup/oobe/html/html/oemcust](../../base/ntsetup/oobe/html/html/oemcust) | 5 | — | — | — |
| [base/ntsetup/oobe/html/html/oemhw](../../base/ntsetup/oobe/html/html/oemhw) | 1 | — | — | — |
| [base/ntsetup/oobe/html/html/oemreg](../../base/ntsetup/oobe/html/html/oemreg) | 3 | — | — | — |
| [base/ntsetup/oobe/html/html/sconnect](../../base/ntsetup/oobe/html/html/sconnect) | 2 | — | — | — |
| [base/ntsetup/oobe/html/icserror](../../base/ntsetup/oobe/html/icserror) | 1 | — | — | — |
| [base/ntsetup/oobe/html/images](../../base/ntsetup/oobe/html/images) | 112 | — | — | — |
| [base/ntsetup/oobe/html/isperror](../../base/ntsetup/oobe/html/isperror) | 8 | — | — | — |
| [base/ntsetup/oobe/html/msn](../../base/ntsetup/oobe/html/msn) | 6 | — | — | — |
| [base/ntsetup/oobe/html/msnerror](../../base/ntsetup/oobe/html/msnerror) | 13 | — | — | — |
| [base/ntsetup/oobe/html/msnhtml](../../base/ntsetup/oobe/html/msnhtml) | 0 | — | — | — |
| [base/ntsetup/oobe/html/msnhtml/ispsgnup](../../base/ntsetup/oobe/html/msnhtml/ispsgnup) | 6 | — | — | — |
| [base/ntsetup/oobe/html/msnhtml/mouse](../../base/ntsetup/oobe/html/msnhtml/mouse) | 1 | — | — | — |
| [base/ntsetup/oobe/html/msnhtml/oemhw](../../base/ntsetup/oobe/html/msnhtml/oemhw) | 1 | — | — | — |
| [base/ntsetup/oobe/html/msnhtml/oemreg](../../base/ntsetup/oobe/html/msnhtml/oemreg) | 3 | — | — | — |
| [base/ntsetup/oobe/html/msnsetup](../../base/ntsetup/oobe/html/msnsetup) | 33 | — | — | — |
| [base/ntsetup/oobe/html/newoobe](../../base/ntsetup/oobe/html/newoobe) | 45 | — | — | — |
| [base/ntsetup/oobe/html/newoobe/images](../../base/ntsetup/oobe/html/newoobe/images) | 8 | — | — | — |
| [base/ntsetup/oobe/html/passport](../../base/ntsetup/oobe/html/passport) | 3 | — | — | — |
| [base/ntsetup/oobe/html/regerror](../../base/ntsetup/oobe/html/regerror) | 8 | — | — | — |
| [base/ntsetup/oobe/html/regsetup](../../base/ntsetup/oobe/html/regsetup) | 11 | — | — | — |
| [base/ntsetup/oobe/html/sample](../../base/ntsetup/oobe/html/sample) | 4 | — | — | — |
| [base/ntsetup/oobe/html/setup](../../base/ntsetup/oobe/html/setup) | 17 | — | — | — |
| [base/ntsetup/oobe/html/template](../../base/ntsetup/oobe/html/template) | 4 | — | — | — |
| [base/ntsetup/oobe/html/win98se](../../base/ntsetup/oobe/html/win98se) | 0 | — | — | — |
| [base/ntsetup/oobe/html/win98se/msn](../../base/ntsetup/oobe/html/win98se/msn) | 6 | — | — | — |
| [base/ntsetup/oobe/html/win98se/passport](../../base/ntsetup/oobe/html/win98se/passport) | 3 | — | — | — |
| [base/ntsetup/oobe/html/win98se/setup](../../base/ntsetup/oobe/html/win98se/setup) | 17 | — | — | — |
| [base/ntsetup/oobe/idl](../../base/ntsetup/oobe/idl) | 6 | [base/ntsetup/oobe/idl/sources](../../base/ntsetup/oobe/idl/sources), [base/ntsetup/oobe/idl/makefile](../../base/ntsetup/oobe/idl/makefile) | `obidl` | `LIBRARY` |
| [base/ntsetup/oobe/inc](../../base/ntsetup/oobe/inc) | 11 | — | — | — |
| [base/ntsetup/oobe/msobcomm](../../base/ntsetup/oobe/msobcomm) | 50 | [base/ntsetup/oobe/msobcomm/sources](../../base/ntsetup/oobe/msobcomm/sources), [base/ntsetup/oobe/msobcomm/makefile](../../base/ntsetup/oobe/msobcomm/makefile) | `msobcomm` | `DYNLINK` |
| [base/ntsetup/oobe/msobdl](../../base/ntsetup/oobe/msobdl) | 14 | [base/ntsetup/oobe/msobdl/sources](../../base/ntsetup/oobe/msobdl/sources), [base/ntsetup/oobe/msobdl/makefile](../../base/ntsetup/oobe/msobdl/makefile) | `msobdl` | `DYNLINK` |
| [base/ntsetup/oobe/msobmain](../../base/ntsetup/oobe/msobmain) | 43 | [base/ntsetup/oobe/msobmain/sources](../../base/ntsetup/oobe/msobmain/sources), [base/ntsetup/oobe/msobmain/makefile](../../base/ntsetup/oobe/msobmain/makefile) | `msobmain` | `DYNLINK` |
| [base/ntsetup/oobe/msobmain/res](../../base/ntsetup/oobe/msobmain/res) | 5 | — | — | — |
| [base/ntsetup/oobe/msobshel](../../base/ntsetup/oobe/msobshel) | 11 | [base/ntsetup/oobe/msobshel/sources](../../base/ntsetup/oobe/msobshel/sources), [base/ntsetup/oobe/msobshel/makefile](../../base/ntsetup/oobe/msobshel/makefile) | `msobshel` | `DYNLINK` |
| [base/ntsetup/oobe/msobshel/res](../../base/ntsetup/oobe/msobshel/res) | 42 | — | — | — |
| [base/ntsetup/oobe/msobweb](../../base/ntsetup/oobe/msobweb) | 17 | [base/ntsetup/oobe/msobweb/sources](../../base/ntsetup/oobe/msobweb/sources), [base/ntsetup/oobe/msobweb/makefile](../../base/ntsetup/oobe/msobweb/makefile) | `msobweb` | `DYNLINK` |
| [base/ntsetup/oobe/msoobe](../../base/ntsetup/oobe/msoobe) | 7 | [base/ntsetup/oobe/msoobe/sources](../../base/ntsetup/oobe/msoobe/sources), [base/ntsetup/oobe/msoobe/makefile](../../base/ntsetup/oobe/msoobe/makefile) | `msoobe` | `PROGRAM` |
| [base/ntsetup/oobe/oobebaln](../../base/ntsetup/oobe/oobebaln) | 7 | [base/ntsetup/oobe/oobebaln/sources](../../base/ntsetup/oobe/oobebaln/sources), [base/ntsetup/oobe/oobebaln/makefile](../../base/ntsetup/oobe/oobebaln/makefile) | `oobebaln` | `PROGRAM` |
| [base/ntsetup/opktools](../../base/ntsetup/opktools) | 3 | [base/ntsetup/opktools/dirs](../../base/ntsetup/opktools/dirs) | — | — |
| [base/ntsetup/opktools/amd64](../../base/ntsetup/opktools/amd64) | 1 | — | — | — |
| [base/ntsetup/opktools/autorun](../../base/ntsetup/opktools/autorun) | 15 | [base/ntsetup/opktools/autorun/sources](../../base/ntsetup/opktools/autorun/sources), [base/ntsetup/opktools/autorun/makefile](../../base/ntsetup/opktools/autorun/makefile) | `setup` | `PROGRAM` |
| [base/ntsetup/opktools/autorun/res](../../base/ntsetup/opktools/autorun/res) | 17 | — | — | — |
| [base/ntsetup/opktools/autorun/res/nep](../../base/ntsetup/opktools/autorun/res/nep) | 2 | — | — | — |
| [base/ntsetup/opktools/bioslock](../../base/ntsetup/opktools/bioslock) | 7 | [base/ntsetup/opktools/bioslock/sources](../../base/ntsetup/opktools/bioslock/sources), [base/ntsetup/opktools/bioslock/makefile](../../base/ntsetup/opktools/bioslock/makefile) | `bioschk` | `NOTARGET` |
| [base/ntsetup/opktools/buildhive](../../base/ntsetup/opktools/buildhive) | 14 | [base/ntsetup/opktools/buildhive/sources](../../base/ntsetup/opktools/buildhive/sources), [base/ntsetup/opktools/buildhive/makefile](../../base/ntsetup/opktools/buildhive/makefile) | `bldhives` | `PROGRAM` |
| [base/ntsetup/opktools/cvtarea](../../base/ntsetup/opktools/cvtarea) | 19 | [base/ntsetup/opktools/cvtarea/sources](../../base/ntsetup/opktools/cvtarea/sources), [base/ntsetup/opktools/cvtarea/makefile](../../base/ntsetup/opktools/cvtarea/makefile) | `cvtarea` | `NOTARGET` |
| [base/ntsetup/opktools/cvtarea/i386](../../base/ntsetup/opktools/cvtarea/i386) | 1 | — | — | — |
| [base/ntsetup/opktools/depend](../../base/ntsetup/opktools/depend) | 17 | [base/ntsetup/opktools/depend/sources](../../base/ntsetup/opktools/depend/sources), [base/ntsetup/opktools/depend/makefile](../../base/ntsetup/opktools/depend/makefile) | `depend` | `PROGRAM` |
| [base/ntsetup/opktools/deploycb](../../base/ntsetup/opktools/deploycb) | 4 | [base/ntsetup/opktools/deploycb/sources](../../base/ntsetup/opktools/deploycb/sources), [base/ntsetup/opktools/deploycb/makefile](../../base/ntsetup/opktools/deploycb/makefile) | — | `NOTARGET` |
| [base/ntsetup/opktools/docs](../../base/ntsetup/opktools/docs) | 28 | [base/ntsetup/opktools/docs/sources](../../base/ntsetup/opktools/docs/sources), [base/ntsetup/opktools/docs/makefile](../../base/ntsetup/opktools/docs/makefile) | — | `NOTARGET` |
| [base/ntsetup/opktools/docs/winpe](../../base/ntsetup/opktools/docs/winpe) | 2 | — | — | — |
| [base/ntsetup/opktools/dskimage](../../base/ntsetup/opktools/dskimage) | 4 | [base/ntsetup/opktools/dskimage/sources](../../base/ntsetup/opktools/dskimage/sources), [base/ntsetup/opktools/dskimage/makefile](../../base/ntsetup/opktools/dskimage/makefile) | `dskimage` | `PROGRAM` |
| [base/ntsetup/opktools/efinvram](../../base/ntsetup/opktools/efinvram) | 4 | [base/ntsetup/opktools/efinvram/sources](../../base/ntsetup/opktools/efinvram/sources), [base/ntsetup/opktools/efinvram/makefile](../../base/ntsetup/opktools/efinvram/makefile) | `efinvr` | `PROGRAM` |
| [base/ntsetup/opktools/factory](../../base/ntsetup/opktools/factory) | 41 | [base/ntsetup/opktools/factory/sources](../../base/ntsetup/opktools/factory/sources), [base/ntsetup/opktools/factory/makefile](../../base/ntsetup/opktools/factory/makefile) | `factory` | `PROGRAM` |
| [base/ntsetup/opktools/files](../../base/ntsetup/opktools/files) | 1 | [base/ntsetup/opktools/files/dirs](../../base/ntsetup/opktools/files/dirs) | — | — |
| [base/ntsetup/opktools/files/autorun](../../base/ntsetup/opktools/files/autorun) | 3 | [base/ntsetup/opktools/files/autorun/sources](../../base/ntsetup/opktools/files/autorun/sources), [base/ntsetup/opktools/files/autorun/makefile](../../base/ntsetup/opktools/files/autorun/makefile) | — | `NOTARGET` |
| [base/ntsetup/opktools/files/wizard](../../base/ntsetup/opktools/files/wizard) | 9 | [base/ntsetup/opktools/files/wizard/sources](../../base/ntsetup/opktools/files/wizard/sources), [base/ntsetup/opktools/files/wizard/makefile](../../base/ntsetup/opktools/files/wizard/makefile) | — | `NOTARGET` |
| [base/ntsetup/opktools/i386](../../base/ntsetup/opktools/i386) | 1 | — | — | — |
| [base/ntsetup/opktools/ia64](../../base/ntsetup/opktools/ia64) | 1 | — | — | — |
| [base/ntsetup/opktools/inc](../../base/ntsetup/opktools/inc) | 5 | — | — | — |
| [base/ntsetup/opktools/langinst](../../base/ntsetup/opktools/langinst) | 6 | [base/ntsetup/opktools/langinst/sources](../../base/ntsetup/opktools/langinst/sources), [base/ntsetup/opktools/langinst/makefile](../../base/ntsetup/opktools/langinst/makefile) | `langinst` | `PROGRAM` |
| [base/ntsetup/opktools/lfn](../../base/ntsetup/opktools/lfn) | 8 | [base/ntsetup/opktools/lfn/sources](../../base/ntsetup/opktools/lfn/sources), [base/ntsetup/opktools/lfn/makefile](../../base/ntsetup/opktools/lfn/makefile) | `autolfn` | `PROGRAM` |
| [base/ntsetup/opktools/lib](../../base/ntsetup/opktools/lib) | 1 | [base/ntsetup/opktools/lib/dirs](../../base/ntsetup/opktools/lib/dirs) | — | — |
| [base/ntsetup/opktools/lib/i386](../../base/ntsetup/opktools/lib/i386) | 1 | — | — | — |
| [base/ntsetup/opktools/lib/msdinst](../../base/ntsetup/opktools/lib/msdinst) | 9 | [base/ntsetup/opktools/lib/msdinst/sources](../../base/ntsetup/opktools/lib/msdinst/sources), [base/ntsetup/opktools/lib/msdinst/makefile](../../base/ntsetup/opktools/lib/msdinst/makefile) | `msdinst` | `LIBRARY` |
| [base/ntsetup/opktools/msdinst](../../base/ntsetup/opktools/msdinst) | 6 | [base/ntsetup/opktools/msdinst/sources](../../base/ntsetup/opktools/msdinst/sources), [base/ntsetup/opktools/msdinst/makefile](../../base/ntsetup/opktools/msdinst/makefile) | `msdinst` | `PROGRAM` |
| [base/ntsetup/opktools/msdinst/res](../../base/ntsetup/opktools/msdinst/res) | 1 | — | — | — |
| [base/ntsetup/opktools/netcfg](../../base/ntsetup/opktools/netcfg) | 10 | [base/ntsetup/opktools/netcfg/sources](../../base/ntsetup/opktools/netcfg/sources), [base/ntsetup/opktools/netcfg/makefile](../../base/ntsetup/opktools/netcfg/makefile) | `netcfg` | `PROGRAM` |
| [base/ntsetup/opktools/oemmint](../../base/ntsetup/opktools/oemmint) | 5 | [base/ntsetup/opktools/oemmint/sources](../../base/ntsetup/opktools/oemmint/sources), [base/ntsetup/opktools/oemmint/makefile](../../base/ntsetup/opktools/oemmint/makefile) | `oemmint` | `PROGRAM` |
| [base/ntsetup/opktools/oformat](../../base/ntsetup/opktools/oformat) | 32 | [base/ntsetup/opktools/oformat/sources](../../base/ntsetup/opktools/oformat/sources), [base/ntsetup/opktools/oformat/makefile](../../base/ntsetup/opktools/oformat/makefile) | `oformat` | `NOTARGET` |
| [base/ntsetup/opktools/oformat/i386](../../base/ntsetup/opktools/oformat/i386) | 1 | — | — | — |
| [base/ntsetup/opktools/oformat/messages](../../base/ntsetup/opktools/oformat/messages) | 0 | — | — | — |
| [base/ntsetup/opktools/oformat/messages/usa-ms](../../base/ntsetup/opktools/oformat/messages/usa-ms) | 1 | — | — | — |
| [base/ntsetup/opktools/opklib](../../base/ntsetup/opktools/opklib) | 11 | [base/ntsetup/opktools/opklib/sources](../../base/ntsetup/opktools/opklib/sources), [base/ntsetup/opktools/opklib/makefile](../../base/ntsetup/opktools/opklib/makefile) | `opklib` | `LIBRARY` |
| [base/ntsetup/opktools/rcpatch](../../base/ntsetup/opktools/rcpatch) | 4 | [base/ntsetup/opktools/rcpatch/sources](../../base/ntsetup/opktools/rcpatch/sources), [base/ntsetup/opktools/rcpatch/makefile](../../base/ntsetup/opktools/rcpatch/makefile) | `rcpatch` | `PROGRAM` |
| [base/ntsetup/opktools/samples](../../base/ntsetup/opktools/samples) | 3 | [base/ntsetup/opktools/samples/sources](../../base/ntsetup/opktools/samples/sources), [base/ntsetup/opktools/samples/makefile](../../base/ntsetup/opktools/samples/makefile) | — | `NOTARGET` |
| [base/ntsetup/opktools/samples/branding](../../base/ntsetup/opktools/samples/branding) | 1 | — | — | — |
| [base/ntsetup/opktools/samples/graphics](../../base/ntsetup/opktools/samples/graphics) | 3 | — | — | — |
| [base/ntsetup/opktools/samples/setup](../../base/ntsetup/opktools/samples/setup) | 5 | — | — | — |
| [base/ntsetup/opktools/samples/sysprep_factory](../../base/ntsetup/opktools/samples/sysprep_factory) | 10 | — | — | — |
| [base/ntsetup/opktools/sbsi](../../base/ntsetup/opktools/sbsi) | 5 | [base/ntsetup/opktools/sbsi/dirs](../../base/ntsetup/opktools/sbsi/dirs) | — | — |
| [base/ntsetup/opktools/sbsi/per](../../base/ntsetup/opktools/sbsi/per) | 5 | [base/ntsetup/opktools/sbsi/per/sources](../../base/ntsetup/opktools/sbsi/per/sources), [base/ntsetup/opktools/sbsi/per/makefile](../../base/ntsetup/opktools/sbsi/per/makefile) | — | `NOTARGET` |
| [base/ntsetup/opktools/sbsi/per/setup](../../base/ntsetup/opktools/sbsi/per/setup) | 22 | — | — | — |
| [base/ntsetup/opktools/sbsi/per/setup/cbz](../../base/ntsetup/opktools/sbsi/per/setup/cbz) | 98 | — | — | — |
| [base/ntsetup/opktools/sbsi/per/setup/dbmerge](../../base/ntsetup/opktools/sbsi/per/setup/dbmerge) | 6 | — | — | — |
| [base/ntsetup/opktools/sbsi/per/setup/lib](../../base/ntsetup/opktools/sbsi/per/setup/lib) | 214 | — | — | — |
| [base/ntsetup/opktools/sbsi/per/setup/wave](../../base/ntsetup/opktools/sbsi/per/setup/wave) | 58 | — | — | — |
| [base/ntsetup/opktools/sbsi/perset](../../base/ntsetup/opktools/sbsi/perset) | 2 | [base/ntsetup/opktools/sbsi/perset/sources](../../base/ntsetup/opktools/sbsi/perset/sources), [base/ntsetup/opktools/sbsi/perset/makefile](../../base/ntsetup/opktools/sbsi/perset/makefile) | — | `NOTARGET` |
| [base/ntsetup/opktools/sbsi/pro](../../base/ntsetup/opktools/sbsi/pro) | 5 | [base/ntsetup/opktools/sbsi/pro/sources](../../base/ntsetup/opktools/sbsi/pro/sources), [base/ntsetup/opktools/sbsi/pro/makefile](../../base/ntsetup/opktools/sbsi/pro/makefile) | — | `NOTARGET` |
| [base/ntsetup/opktools/sbsi/pro/setup](../../base/ntsetup/opktools/sbsi/pro/setup) | 22 | — | — | — |
| [base/ntsetup/opktools/sbsi/pro/setup/cbz](../../base/ntsetup/opktools/sbsi/pro/setup/cbz) | 114 | — | — | — |
| [base/ntsetup/opktools/sbsi/pro/setup/dbmerge](../../base/ntsetup/opktools/sbsi/pro/setup/dbmerge) | 6 | — | — | — |
| [base/ntsetup/opktools/sbsi/pro/setup/lib](../../base/ntsetup/opktools/sbsi/pro/setup/lib) | 246 | — | — | — |
| [base/ntsetup/opktools/sbsi/pro/setup/wave](../../base/ntsetup/opktools/sbsi/pro/setup/wave) | 62 | — | — | — |
| [base/ntsetup/opktools/sbsi/proset](../../base/ntsetup/opktools/sbsi/proset) | 2 | [base/ntsetup/opktools/sbsi/proset/sources](../../base/ntsetup/opktools/sbsi/proset/sources), [base/ntsetup/opktools/sbsi/proset/makefile](../../base/ntsetup/opktools/sbsi/proset/makefile) | — | `NOTARGET` |
| [base/ntsetup/opktools/setact](../../base/ntsetup/opktools/setact) | 3 | [base/ntsetup/opktools/setact/sources](../../base/ntsetup/opktools/setact/sources), [base/ntsetup/opktools/setact/makefile](../../base/ntsetup/opktools/setact/makefile) | `setactive` | `PROGRAM` |
| [base/ntsetup/opktools/setup](../../base/ntsetup/opktools/setup) | 11 | [base/ntsetup/opktools/setup/sources](../../base/ntsetup/opktools/setup/sources), [base/ntsetup/opktools/setup/makefile](../../base/ntsetup/opktools/setup/makefile) | `inf` | `LIBRARY` |
| [base/ntsetup/opktools/setupcl](../../base/ntsetup/opktools/setupcl) | 8 | [base/ntsetup/opktools/setupcl/sources](../../base/ntsetup/opktools/setupcl/sources), [base/ntsetup/opktools/setupcl/makefile](../../base/ntsetup/opktools/setupcl/makefile) | `setupcl` | `PROGRAM` |
| [base/ntsetup/opktools/setupmgr](../../base/ntsetup/opktools/setupmgr) | 1 | [base/ntsetup/opktools/setupmgr/dirs](../../base/ntsetup/opktools/setupmgr/dirs) | — | — |
| [base/ntsetup/opktools/setupmgr/base](../../base/ntsetup/opktools/setupmgr/base) | 23 | [base/ntsetup/opktools/setupmgr/base/sources](../../base/ntsetup/opktools/setupmgr/base/sources), [base/ntsetup/opktools/setupmgr/base/makefile](../../base/ntsetup/opktools/setupmgr/base/makefile) | `base` | `LIBRARY` |
| [base/ntsetup/opktools/setupmgr/common](../../base/ntsetup/opktools/setupmgr/common) | 17 | [base/ntsetup/opktools/setupmgr/common/sources](../../base/ntsetup/opktools/setupmgr/common/sources), [base/ntsetup/opktools/setupmgr/common/makefile](../../base/ntsetup/opktools/setupmgr/common/makefile) | `common` | `LIBRARY` |
| [base/ntsetup/opktools/setupmgr/exe](../../base/ntsetup/opktools/setupmgr/exe) | 7 | [base/ntsetup/opktools/setupmgr/exe/sources](../../base/ntsetup/opktools/setupmgr/exe/sources), [base/ntsetup/opktools/setupmgr/exe/makefile](../../base/ntsetup/opktools/setupmgr/exe/makefile) | `setupmgr` | `PROGRAM` |
| [base/ntsetup/opktools/setupmgr/include](../../base/ntsetup/opktools/setupmgr/include) | 15 | — | — | — |
| [base/ntsetup/opktools/setupmgr/main](../../base/ntsetup/opktools/setupmgr/main) | 18 | [base/ntsetup/opktools/setupmgr/main/sources](../../base/ntsetup/opktools/setupmgr/main/sources), [base/ntsetup/opktools/setupmgr/main/makefile](../../base/ntsetup/opktools/setupmgr/main/makefile) | `main` | `LIBRARY` |
| [base/ntsetup/opktools/setupmgr/net](../../base/ntsetup/opktools/setupmgr/net) | 24 | [base/ntsetup/opktools/setupmgr/net/sources](../../base/ntsetup/opktools/setupmgr/net/sources), [base/ntsetup/opktools/setupmgr/net/makefile](../../base/ntsetup/opktools/setupmgr/net/makefile) | `net` | `LIBRARY` |
| [base/ntsetup/opktools/setupmgr/oc](../../base/ntsetup/opktools/setupmgr/oc) | 19 | [base/ntsetup/opktools/setupmgr/oc/sources](../../base/ntsetup/opktools/setupmgr/oc/sources), [base/ntsetup/opktools/setupmgr/oc/makefile](../../base/ntsetup/opktools/setupmgr/oc/makefile) | `oc` | `LIBRARY` |
| [base/ntsetup/opktools/setupmgr/oem](../../base/ntsetup/opktools/setupmgr/oem) | 42 | [base/ntsetup/opktools/setupmgr/oem/sources](../../base/ntsetup/opktools/setupmgr/oem/sources), [base/ntsetup/opktools/setupmgr/oem/makefile](../../base/ntsetup/opktools/setupmgr/oem/makefile) | `oem` | `LIBRARY` |
| [base/ntsetup/opktools/setupmgr/resource](../../base/ntsetup/opktools/setupmgr/resource) | 18 | — | — | — |
| [base/ntsetup/opktools/setupmgr/supplib](../../base/ntsetup/opktools/setupmgr/supplib) | 13 | [base/ntsetup/opktools/setupmgr/supplib/sources](../../base/ntsetup/opktools/setupmgr/supplib/sources), [base/ntsetup/opktools/setupmgr/supplib/makefile](../../base/ntsetup/opktools/setupmgr/supplib/makefile) | `supplib` | `LIBRARY` |
| [base/ntsetup/opktools/sprestrt](../../base/ntsetup/opktools/sprestrt) | 8 | [base/ntsetup/opktools/sprestrt/sources](../../base/ntsetup/opktools/sprestrt/sources), [base/ntsetup/opktools/sprestrt/makefile](../../base/ntsetup/opktools/sprestrt/makefile) | `sprestrt` | `PROGRAM` |
| [base/ntsetup/opktools/sys](../../base/ntsetup/opktools/sys) | 6 | [base/ntsetup/opktools/sys/sources](../../base/ntsetup/opktools/sys/sources), [base/ntsetup/opktools/sys/makefile](../../base/ntsetup/opktools/sys/makefile) | `sys` | `PROGRAM` |
| [base/ntsetup/opktools/syslib](../../base/ntsetup/opktools/syslib) | 5 | [base/ntsetup/opktools/syslib/sources](../../base/ntsetup/opktools/syslib/sources), [base/ntsetup/opktools/syslib/makefile](../../base/ntsetup/opktools/syslib/makefile) | `spsyslib` | `LIBRARY` |
| [base/ntsetup/opktools/sysprep](../../base/ntsetup/opktools/sysprep) | 11 | [base/ntsetup/opktools/sysprep/sources](../../base/ntsetup/opktools/sysprep/sources), [base/ntsetup/opktools/sysprep/makefile](../../base/ntsetup/opktools/sysprep/makefile) | `sysprep` | `PROGRAM` |
| [base/ntsetup/opktools/winpeoc](../../base/ntsetup/opktools/winpeoc) | 0 | — | — | — |
| [base/ntsetup/opktools/winpeoc/imgbld](../../base/ntsetup/opktools/winpeoc/imgbld) | 12 | — | — | — |
| [base/ntsetup/opktools/winpeoc/imgbld/images](../../base/ntsetup/opktools/winpeoc/imgbld/images) | 2 | — | — | — |
| [base/ntsetup/opktools/winpeoc/xwinpe](../../base/ntsetup/opktools/winpeoc/xwinpe) | 20 | — | — | — |
| [base/ntsetup/opktools/winpeoc/xwinpe/docs](../../base/ntsetup/opktools/winpeoc/xwinpe/docs) | 9 | — | — | — |
| [base/ntsetup/opktools/wpebins](../../base/ntsetup/opktools/wpebins) | 9 | [base/ntsetup/opktools/wpebins/sources](../../base/ntsetup/opktools/wpebins/sources), [base/ntsetup/opktools/wpebins/makefile](../../base/ntsetup/opktools/wpebins/makefile) | — | `NOTARGET` |
| [base/ntsetup/opktools/wpebins/x86](../../base/ntsetup/opktools/wpebins/x86) | 2 | — | — | — |
| [base/ntsetup/patch](../../base/ntsetup/patch) | 4 | [base/ntsetup/patch/sources](../../base/ntsetup/patch/sources), [base/ntsetup/patch/makefile](../../base/ntsetup/patch/makefile) | `update` | `PROGRAM` |
| [base/ntsetup/patchdll](../../base/ntsetup/patchdll) | 9 | [base/ntsetup/patchdll/sources](../../base/ntsetup/patchdll/sources), [base/ntsetup/patchdll/makefile](../../base/ntsetup/patchdll/makefile) | `patchdll` | `DYNLINK` |
| [base/ntsetup/patchdll/i386](../../base/ntsetup/patchdll/i386) | 2 | [base/ntsetup/patchdll/i386/sources](../../base/ntsetup/patchdll/i386/sources) | — | — |
| [base/ntsetup/patching](../../base/ntsetup/patching) | 0 | — | — | — |
| [base/ntsetup/patching/bldtools](../../base/ntsetup/patching/bldtools) | 99 | — | — | — |
| [base/ntsetup/patching/bldtools/ar](../../base/ntsetup/patching/bldtools/ar) | 0 | — | — | — |
| [base/ntsetup/patching/bldtools/ar/x86](../../base/ntsetup/patching/bldtools/ar/x86) | 1 | — | — | — |
| [base/ntsetup/patching/bldtools/br](../../base/ntsetup/patching/bldtools/br) | 0 | — | — | — |
| [base/ntsetup/patching/bldtools/br/x86](../../base/ntsetup/patching/bldtools/br/x86) | 1 | — | — | — |
| [base/ntsetup/patching/bldtools/cn](../../base/ntsetup/patching/bldtools/cn) | 0 | — | — | — |
| [base/ntsetup/patching/bldtools/cn/x86](../../base/ntsetup/patching/bldtools/cn/x86) | 1 | — | — | — |
| [base/ntsetup/patching/bldtools/cs](../../base/ntsetup/patching/bldtools/cs) | 0 | — | — | — |
| [base/ntsetup/patching/bldtools/cs/x86](../../base/ntsetup/patching/bldtools/cs/x86) | 1 | — | — | — |
| [base/ntsetup/patching/bldtools/da](../../base/ntsetup/patching/bldtools/da) | 0 | — | — | — |
| [base/ntsetup/patching/bldtools/da/x86](../../base/ntsetup/patching/bldtools/da/x86) | 1 | — | — | — |
| [base/ntsetup/patching/bldtools/de](../../base/ntsetup/patching/bldtools/de) | 0 | — | — | — |
| [base/ntsetup/patching/bldtools/de/x86](../../base/ntsetup/patching/bldtools/de/x86) | 1 | — | — | — |
| [base/ntsetup/patching/bldtools/el](../../base/ntsetup/patching/bldtools/el) | 0 | — | — | — |
| [base/ntsetup/patching/bldtools/el/x86](../../base/ntsetup/patching/bldtools/el/x86) | 1 | — | — | — |
| [base/ntsetup/patching/bldtools/en](../../base/ntsetup/patching/bldtools/en) | 0 | — | — | — |
| [base/ntsetup/patching/bldtools/en/x86](../../base/ntsetup/patching/bldtools/en/x86) | 1 | — | — | — |
| [base/ntsetup/patching/bldtools/es](../../base/ntsetup/patching/bldtools/es) | 0 | — | — | — |
| [base/ntsetup/patching/bldtools/es/x86](../../base/ntsetup/patching/bldtools/es/x86) | 1 | — | — | — |
| [base/ntsetup/patching/bldtools/fi](../../base/ntsetup/patching/bldtools/fi) | 0 | — | — | — |
| [base/ntsetup/patching/bldtools/fi/x86](../../base/ntsetup/patching/bldtools/fi/x86) | 1 | — | — | — |
| [base/ntsetup/patching/bldtools/fr](../../base/ntsetup/patching/bldtools/fr) | 0 | — | — | — |
| [base/ntsetup/patching/bldtools/fr/x86](../../base/ntsetup/patching/bldtools/fr/x86) | 1 | — | — | — |
| [base/ntsetup/patching/bldtools/he](../../base/ntsetup/patching/bldtools/he) | 0 | — | — | — |
| [base/ntsetup/patching/bldtools/he/x86](../../base/ntsetup/patching/bldtools/he/x86) | 1 | — | — | — |
| [base/ntsetup/patching/bldtools/hk](../../base/ntsetup/patching/bldtools/hk) | 0 | — | — | — |
| [base/ntsetup/patching/bldtools/hk/x86](../../base/ntsetup/patching/bldtools/hk/x86) | 1 | — | — | — |
| [base/ntsetup/patching/bldtools/hu](../../base/ntsetup/patching/bldtools/hu) | 0 | — | — | — |
| [base/ntsetup/patching/bldtools/hu/x86](../../base/ntsetup/patching/bldtools/hu/x86) | 1 | — | — | — |
| [base/ntsetup/patching/bldtools/it](../../base/ntsetup/patching/bldtools/it) | 0 | — | — | — |
| [base/ntsetup/patching/bldtools/it/x86](../../base/ntsetup/patching/bldtools/it/x86) | 1 | — | — | — |
| [base/ntsetup/patching/bldtools/ja](../../base/ntsetup/patching/bldtools/ja) | 0 | — | — | — |
| [base/ntsetup/patching/bldtools/ja/nec98](../../base/ntsetup/patching/bldtools/ja/nec98) | 1 | — | — | — |
| [base/ntsetup/patching/bldtools/ja/x86](../../base/ntsetup/patching/bldtools/ja/x86) | 1 | — | — | — |
| [base/ntsetup/patching/bldtools/ko](../../base/ntsetup/patching/bldtools/ko) | 0 | — | — | — |
| [base/ntsetup/patching/bldtools/ko/x86](../../base/ntsetup/patching/bldtools/ko/x86) | 1 | — | — | — |
| [base/ntsetup/patching/bldtools/nl](../../base/ntsetup/patching/bldtools/nl) | 0 | — | — | — |
| [base/ntsetup/patching/bldtools/nl/x86](../../base/ntsetup/patching/bldtools/nl/x86) | 1 | — | — | — |
| [base/ntsetup/patching/bldtools/no](../../base/ntsetup/patching/bldtools/no) | 0 | — | — | — |
| [base/ntsetup/patching/bldtools/no/x86](../../base/ntsetup/patching/bldtools/no/x86) | 1 | — | — | — |
| [base/ntsetup/patching/bldtools/pl](../../base/ntsetup/patching/bldtools/pl) | 0 | — | — | — |
| [base/ntsetup/patching/bldtools/pl/x86](../../base/ntsetup/patching/bldtools/pl/x86) | 1 | — | — | — |
| [base/ntsetup/patching/bldtools/pt](../../base/ntsetup/patching/bldtools/pt) | 0 | — | — | — |
| [base/ntsetup/patching/bldtools/pt/x86](../../base/ntsetup/patching/bldtools/pt/x86) | 1 | — | — | — |
| [base/ntsetup/patching/bldtools/ru](../../base/ntsetup/patching/bldtools/ru) | 0 | — | — | — |
| [base/ntsetup/patching/bldtools/ru/x86](../../base/ntsetup/patching/bldtools/ru/x86) | 1 | — | — | — |
| [base/ntsetup/patching/bldtools/sv](../../base/ntsetup/patching/bldtools/sv) | 0 | — | — | — |
| [base/ntsetup/patching/bldtools/sv/x86](../../base/ntsetup/patching/bldtools/sv/x86) | 1 | — | — | — |
| [base/ntsetup/patching/bldtools/tr](../../base/ntsetup/patching/bldtools/tr) | 0 | — | — | — |
| [base/ntsetup/patching/bldtools/tr/x86](../../base/ntsetup/patching/bldtools/tr/x86) | 1 | — | — | — |
| [base/ntsetup/patching/bldtools/tw](../../base/ntsetup/patching/bldtools/tw) | 0 | — | — | — |
| [base/ntsetup/patching/bldtools/tw/x86](../../base/ntsetup/patching/bldtools/tw/x86) | 1 | — | — | — |
| [base/ntsetup/pencrypt](../../base/ntsetup/pencrypt) | 3 | [base/ntsetup/pencrypt/sources](../../base/ntsetup/pencrypt/sources), [base/ntsetup/pencrypt/makefile](../../base/ntsetup/pencrypt/makefile) | `pencrypt` | `LIBRARY` |
| [base/ntsetup/pidgen](../../base/ntsetup/pidgen) | 1 | [base/ntsetup/pidgen/dirs](../../base/ntsetup/pidgen/dirs) | — | — |
| [base/ntsetup/pidgen/inc](../../base/ntsetup/pidgen/inc) | 2 | — | — | — |
| [base/ntsetup/pidgen/lib](../../base/ntsetup/pidgen/lib) | 0 | — | — | — |
| [base/ntsetup/pidgen/lib/amd64](../../base/ntsetup/pidgen/lib/amd64) | 1 | — | — | — |
| [base/ntsetup/pidgen/lib/i386](../../base/ntsetup/pidgen/lib/i386) | 1 | — | — | — |
| [base/ntsetup/pidgen/lib/ia64](../../base/ntsetup/pidgen/lib/ia64) | 1 | — | — | — |
| [base/ntsetup/pidgen/pgentest](../../base/ntsetup/pidgen/pgentest) | 3 | [base/ntsetup/pidgen/pgentest/sources](../../base/ntsetup/pidgen/pgentest/sources), [base/ntsetup/pidgen/pgentest/makefile](../../base/ntsetup/pidgen/pgentest/makefile) | `pgentest` | `PROGRAM` |
| [base/ntsetup/pidgen/pidgen](../../base/ntsetup/pidgen/pidgen) | 41 | [base/ntsetup/pidgen/pidgen/dirs](../../base/ntsetup/pidgen/pidgen/dirs) | — | — |
| [base/ntsetup/pidgen/pidgen/ddk](../../base/ntsetup/pidgen/pidgen/ddk) | 2 | [base/ntsetup/pidgen/pidgen/ddk/sources](../../base/ntsetup/pidgen/pidgen/ddk/sources), [base/ntsetup/pidgen/pidgen/ddk/makefile](../../base/ntsetup/pidgen/pidgen/ddk/makefile) | `pidgen` | `DYNLINK` |
| [base/ntsetup/pidgen/pidgen/dll](../../base/ntsetup/pidgen/pidgen/dll) | 2 | [base/ntsetup/pidgen/pidgen/dll/sources](../../base/ntsetup/pidgen/pidgen/dll/sources), [base/ntsetup/pidgen/pidgen/dll/makefile](../../base/ntsetup/pidgen/pidgen/dll/makefile) | `pidgen` | `DYNLINK` |
| [base/ntsetup/pidgen/pidgen/eval](../../base/ntsetup/pidgen/pidgen/eval) | 2 | [base/ntsetup/pidgen/pidgen/eval/sources](../../base/ntsetup/pidgen/pidgen/eval/sources), [base/ntsetup/pidgen/pidgen/eval/makefile](../../base/ntsetup/pidgen/pidgen/eval/makefile) | `epidgen` | `DYNLINK` |
| [base/ntsetup/pidgen/pidgen/lib](../../base/ntsetup/pidgen/pidgen/lib) | 2 | [base/ntsetup/pidgen/pidgen/lib/sources](../../base/ntsetup/pidgen/pidgen/lib/sources), [base/ntsetup/pidgen/pidgen/lib/makefile](../../base/ntsetup/pidgen/pidgen/lib/makefile) | `pidgen` | `LIBRARY` |
| [base/ntsetup/pidgen/pidgen/per](../../base/ntsetup/pidgen/pidgen/per) | 2 | [base/ntsetup/pidgen/pidgen/per/sources](../../base/ntsetup/pidgen/pidgen/per/sources), [base/ntsetup/pidgen/pidgen/per/makefile](../../base/ntsetup/pidgen/pidgen/per/makefile) | `pidgen` | `DYNLINK` |
| [base/ntsetup/pidgen/pidgen/srv](../../base/ntsetup/pidgen/pidgen/srv) | 2 | [base/ntsetup/pidgen/pidgen/srv/sources](../../base/ntsetup/pidgen/pidgen/srv/sources), [base/ntsetup/pidgen/pidgen/srv/makefile](../../base/ntsetup/pidgen/pidgen/srv/makefile) | `pidgen` | `DYNLINK` |
| [base/ntsetup/pidgen/pidgen/trial](../../base/ntsetup/pidgen/pidgen/trial) | 2 | [base/ntsetup/pidgen/pidgen/trial/sources](../../base/ntsetup/pidgen/pidgen/trial/sources), [base/ntsetup/pidgen/pidgen/trial/makefile](../../base/ntsetup/pidgen/pidgen/trial/makefile) | `pidgen` | `DYNLINK` |
| [base/ntsetup/pidgen/pidgen/vol](../../base/ntsetup/pidgen/pidgen/vol) | 2 | [base/ntsetup/pidgen/pidgen/vol/sources](../../base/ntsetup/pidgen/pidgen/vol/sources), [base/ntsetup/pidgen/pidgen/vol/makefile](../../base/ntsetup/pidgen/pidgen/vol/makefile) | `vpidgen` | `DYNLINK` |
| [base/ntsetup/pidgen/pidgen/wks](../../base/ntsetup/pidgen/pidgen/wks) | 2 | [base/ntsetup/pidgen/pidgen/wks/sources](../../base/ntsetup/pidgen/pidgen/wks/sources), [base/ntsetup/pidgen/pidgen/wks/makefile](../../base/ntsetup/pidgen/pidgen/wks/makefile) | `pidgen` | `DYNLINK` |
| [base/ntsetup/pidgen/pidset](../../base/ntsetup/pidgen/pidset) | 13 | [base/ntsetup/pidgen/pidset/sources](../../base/ntsetup/pidgen/pidset/sources), [base/ntsetup/pidgen/pidset/makefile](../../base/ntsetup/pidgen/pidset/makefile) | `pidset` | `LIBRARY` |
| [base/ntsetup/pnpsif](../../base/ntsetup/pnpsif) | 11 | [base/ntsetup/pnpsif/sources](../../base/ntsetup/pnpsif/sources), [base/ntsetup/pnpsif/makefile](../../base/ntsetup/pnpsif/makefile) | `pnpsif` | `LIBRARY` |
| [base/ntsetup/readme](../../base/ntsetup/readme) | 8 | [base/ntsetup/readme/sources](../../base/ntsetup/readme/sources), [base/ntsetup/readme/makefile](../../base/ntsetup/readme/makefile) | — | `NOTARGET` |
| [base/ntsetup/setexts](../../base/ntsetup/setexts) | 10 | [base/ntsetup/setexts/sources](../../base/ntsetup/setexts/sources), [base/ntsetup/setexts/makefile](../../base/ntsetup/setexts/makefile) | `setupexts` | `DYNLINK` |
| [base/ntsetup/setupapi](../../base/ntsetup/setupapi) | 2 | [base/ntsetup/setupapi/dirs](../../base/ntsetup/setupapi/dirs) | — | — |
| [base/ntsetup/setupapi/wrapper](../../base/ntsetup/setupapi/wrapper) | 5 | [base/ntsetup/setupapi/wrapper/sources](../../base/ntsetup/setupapi/wrapper/sources), [base/ntsetup/setupapi/wrapper/makefile](../../base/ntsetup/setupapi/wrapper/makefile) | `setupwrp` | `LIBRARY` |
| [base/ntsetup/setupapi/wrapper/test](../../base/ntsetup/setupapi/wrapper/test) | 4 | [base/ntsetup/setupapi/wrapper/test/sources](../../base/ntsetup/setupapi/wrapper/test/sources), [base/ntsetup/setupapi/wrapper/test/makefile](../../base/ntsetup/setupapi/wrapper/test/makefile) | `testwrap` | `PROGRAM` |
| [base/ntsetup/setuplog](../../base/ntsetup/setuplog) | 5 | [base/ntsetup/setuplog/dirs](../../base/ntsetup/setuplog/dirs) | — | — |
| [base/ntsetup/setuplog/ansi](../../base/ntsetup/setuplog/ansi) | 2 | [base/ntsetup/setuplog/ansi/sources](../../base/ntsetup/setuplog/ansi/sources), [base/ntsetup/setuplog/ansi/makefile](../../base/ntsetup/setuplog/ansi/makefile) | `setuplga` | — |
| [base/ntsetup/setuplog/unicode](../../base/ntsetup/setuplog/unicode) | 2 | [base/ntsetup/setuplog/unicode/sources](../../base/ntsetup/setuplog/unicode/sources), [base/ntsetup/setuplog/unicode/makefile](../../base/ntsetup/setuplog/unicode/makefile) | `setuplgu` | — |
| [base/ntsetup/setupmsi](../../base/ntsetup/setupmsi) | 13 | [base/ntsetup/setupmsi/sources](../../base/ntsetup/setupmsi/sources), [base/ntsetup/setupmsi/makefile](../../base/ntsetup/setupmsi/makefile) | — | `NOTARGET` |
| [base/ntsetup/srvpack_binary_release](../../base/ntsetup/srvpack_binary_release) | 5 | [base/ntsetup/srvpack_binary_release/dirs](../../base/ntsetup/srvpack_binary_release/dirs) | — | — |
| [base/ntsetup/srvpack_binary_release/ar](../../base/ntsetup/srvpack_binary_release/ar) | 1 | [base/ntsetup/srvpack_binary_release/ar/dirs](../../base/ntsetup/srvpack_binary_release/ar/dirs) | — | — |
| [base/ntsetup/srvpack_binary_release/ar/i386](../../base/ntsetup/srvpack_binary_release/ar/i386) | 2 | [base/ntsetup/srvpack_binary_release/ar/i386/sources](../../base/ntsetup/srvpack_binary_release/ar/i386/sources), [base/ntsetup/srvpack_binary_release/ar/i386/makefile](../../base/ntsetup/srvpack_binary_release/ar/i386/makefile) | — | — |
| [base/ntsetup/srvpack_binary_release/ar/i386/fre](../../base/ntsetup/srvpack_binary_release/ar/i386/fre) | 7 | — | — | — |
| [base/ntsetup/srvpack_binary_release/ar/ia64](../../base/ntsetup/srvpack_binary_release/ar/ia64) | 2 | [base/ntsetup/srvpack_binary_release/ar/ia64/sources](../../base/ntsetup/srvpack_binary_release/ar/ia64/sources), [base/ntsetup/srvpack_binary_release/ar/ia64/makefile](../../base/ntsetup/srvpack_binary_release/ar/ia64/makefile) | — | — |
| [base/ntsetup/srvpack_binary_release/ar/ia64/fre](../../base/ntsetup/srvpack_binary_release/ar/ia64/fre) | 7 | — | — | — |
| [base/ntsetup/srvpack_binary_release/autorun](../../base/ntsetup/srvpack_binary_release/autorun) | 5 | [base/ntsetup/srvpack_binary_release/autorun/sources](../../base/ntsetup/srvpack_binary_release/autorun/sources), [base/ntsetup/srvpack_binary_release/autorun/makefile](../../base/ntsetup/srvpack_binary_release/autorun/makefile) | — | `NOTARGET` |
| [base/ntsetup/srvpack_binary_release/br](../../base/ntsetup/srvpack_binary_release/br) | 1 | [base/ntsetup/srvpack_binary_release/br/dirs](../../base/ntsetup/srvpack_binary_release/br/dirs) | — | — |
| [base/ntsetup/srvpack_binary_release/br/i386](../../base/ntsetup/srvpack_binary_release/br/i386) | 2 | [base/ntsetup/srvpack_binary_release/br/i386/sources](../../base/ntsetup/srvpack_binary_release/br/i386/sources), [base/ntsetup/srvpack_binary_release/br/i386/makefile](../../base/ntsetup/srvpack_binary_release/br/i386/makefile) | — | — |
| [base/ntsetup/srvpack_binary_release/br/i386/fre](../../base/ntsetup/srvpack_binary_release/br/i386/fre) | 7 | — | — | — |
| [base/ntsetup/srvpack_binary_release/br/ia64](../../base/ntsetup/srvpack_binary_release/br/ia64) | 2 | [base/ntsetup/srvpack_binary_release/br/ia64/sources](../../base/ntsetup/srvpack_binary_release/br/ia64/sources), [base/ntsetup/srvpack_binary_release/br/ia64/makefile](../../base/ntsetup/srvpack_binary_release/br/ia64/makefile) | — | — |
| [base/ntsetup/srvpack_binary_release/br/ia64/fre](../../base/ntsetup/srvpack_binary_release/br/ia64/fre) | 7 | — | — | — |
| [base/ntsetup/srvpack_binary_release/cn](../../base/ntsetup/srvpack_binary_release/cn) | 1 | [base/ntsetup/srvpack_binary_release/cn/dirs](../../base/ntsetup/srvpack_binary_release/cn/dirs) | — | — |
| [base/ntsetup/srvpack_binary_release/cn/i386](../../base/ntsetup/srvpack_binary_release/cn/i386) | 2 | [base/ntsetup/srvpack_binary_release/cn/i386/sources](../../base/ntsetup/srvpack_binary_release/cn/i386/sources), [base/ntsetup/srvpack_binary_release/cn/i386/makefile](../../base/ntsetup/srvpack_binary_release/cn/i386/makefile) | — | — |
| [base/ntsetup/srvpack_binary_release/cn/i386/fre](../../base/ntsetup/srvpack_binary_release/cn/i386/fre) | 7 | — | — | — |
| [base/ntsetup/srvpack_binary_release/cn/ia64](../../base/ntsetup/srvpack_binary_release/cn/ia64) | 2 | [base/ntsetup/srvpack_binary_release/cn/ia64/sources](../../base/ntsetup/srvpack_binary_release/cn/ia64/sources), [base/ntsetup/srvpack_binary_release/cn/ia64/makefile](../../base/ntsetup/srvpack_binary_release/cn/ia64/makefile) | — | — |
| [base/ntsetup/srvpack_binary_release/cn/ia64/fre](../../base/ntsetup/srvpack_binary_release/cn/ia64/fre) | 7 | — | — | — |
| [base/ntsetup/srvpack_binary_release/cs](../../base/ntsetup/srvpack_binary_release/cs) | 1 | [base/ntsetup/srvpack_binary_release/cs/dirs](../../base/ntsetup/srvpack_binary_release/cs/dirs) | — | — |
| [base/ntsetup/srvpack_binary_release/cs/i386](../../base/ntsetup/srvpack_binary_release/cs/i386) | 2 | [base/ntsetup/srvpack_binary_release/cs/i386/sources](../../base/ntsetup/srvpack_binary_release/cs/i386/sources), [base/ntsetup/srvpack_binary_release/cs/i386/makefile](../../base/ntsetup/srvpack_binary_release/cs/i386/makefile) | — | — |
| [base/ntsetup/srvpack_binary_release/cs/i386/fre](../../base/ntsetup/srvpack_binary_release/cs/i386/fre) | 7 | — | — | — |
| [base/ntsetup/srvpack_binary_release/cs/ia64](../../base/ntsetup/srvpack_binary_release/cs/ia64) | 2 | [base/ntsetup/srvpack_binary_release/cs/ia64/sources](../../base/ntsetup/srvpack_binary_release/cs/ia64/sources), [base/ntsetup/srvpack_binary_release/cs/ia64/makefile](../../base/ntsetup/srvpack_binary_release/cs/ia64/makefile) | — | — |
| [base/ntsetup/srvpack_binary_release/cs/ia64/fre](../../base/ntsetup/srvpack_binary_release/cs/ia64/fre) | 7 | — | — | — |
| [base/ntsetup/srvpack_binary_release/da](../../base/ntsetup/srvpack_binary_release/da) | 1 | [base/ntsetup/srvpack_binary_release/da/dirs](../../base/ntsetup/srvpack_binary_release/da/dirs) | — | — |
| [base/ntsetup/srvpack_binary_release/da/i386](../../base/ntsetup/srvpack_binary_release/da/i386) | 2 | [base/ntsetup/srvpack_binary_release/da/i386/sources](../../base/ntsetup/srvpack_binary_release/da/i386/sources), [base/ntsetup/srvpack_binary_release/da/i386/makefile](../../base/ntsetup/srvpack_binary_release/da/i386/makefile) | — | — |
| [base/ntsetup/srvpack_binary_release/da/i386/fre](../../base/ntsetup/srvpack_binary_release/da/i386/fre) | 7 | — | — | — |
| [base/ntsetup/srvpack_binary_release/da/ia64](../../base/ntsetup/srvpack_binary_release/da/ia64) | 2 | [base/ntsetup/srvpack_binary_release/da/ia64/sources](../../base/ntsetup/srvpack_binary_release/da/ia64/sources), [base/ntsetup/srvpack_binary_release/da/ia64/makefile](../../base/ntsetup/srvpack_binary_release/da/ia64/makefile) | — | — |
| [base/ntsetup/srvpack_binary_release/da/ia64/fre](../../base/ntsetup/srvpack_binary_release/da/ia64/fre) | 7 | — | — | — |
| [base/ntsetup/srvpack_binary_release/de](../../base/ntsetup/srvpack_binary_release/de) | 1 | [base/ntsetup/srvpack_binary_release/de/dirs](../../base/ntsetup/srvpack_binary_release/de/dirs) | — | — |
| [base/ntsetup/srvpack_binary_release/de/i386](../../base/ntsetup/srvpack_binary_release/de/i386) | 2 | [base/ntsetup/srvpack_binary_release/de/i386/sources](../../base/ntsetup/srvpack_binary_release/de/i386/sources), [base/ntsetup/srvpack_binary_release/de/i386/makefile](../../base/ntsetup/srvpack_binary_release/de/i386/makefile) | — | — |
| [base/ntsetup/srvpack_binary_release/de/i386/fre](../../base/ntsetup/srvpack_binary_release/de/i386/fre) | 7 | — | — | — |
| [base/ntsetup/srvpack_binary_release/de/ia64](../../base/ntsetup/srvpack_binary_release/de/ia64) | 2 | [base/ntsetup/srvpack_binary_release/de/ia64/sources](../../base/ntsetup/srvpack_binary_release/de/ia64/sources), [base/ntsetup/srvpack_binary_release/de/ia64/makefile](../../base/ntsetup/srvpack_binary_release/de/ia64/makefile) | — | — |
| [base/ntsetup/srvpack_binary_release/de/ia64/fre](../../base/ntsetup/srvpack_binary_release/de/ia64/fre) | 7 | — | — | — |
| [base/ntsetup/srvpack_binary_release/el](../../base/ntsetup/srvpack_binary_release/el) | 1 | [base/ntsetup/srvpack_binary_release/el/dirs](../../base/ntsetup/srvpack_binary_release/el/dirs) | — | — |
| [base/ntsetup/srvpack_binary_release/el/i386](../../base/ntsetup/srvpack_binary_release/el/i386) | 2 | [base/ntsetup/srvpack_binary_release/el/i386/sources](../../base/ntsetup/srvpack_binary_release/el/i386/sources), [base/ntsetup/srvpack_binary_release/el/i386/makefile](../../base/ntsetup/srvpack_binary_release/el/i386/makefile) | — | — |
| [base/ntsetup/srvpack_binary_release/el/i386/fre](../../base/ntsetup/srvpack_binary_release/el/i386/fre) | 7 | — | — | — |
| [base/ntsetup/srvpack_binary_release/el/ia64](../../base/ntsetup/srvpack_binary_release/el/ia64) | 2 | [base/ntsetup/srvpack_binary_release/el/ia64/sources](../../base/ntsetup/srvpack_binary_release/el/ia64/sources), [base/ntsetup/srvpack_binary_release/el/ia64/makefile](../../base/ntsetup/srvpack_binary_release/el/ia64/makefile) | — | — |
| [base/ntsetup/srvpack_binary_release/el/ia64/fre](../../base/ntsetup/srvpack_binary_release/el/ia64/fre) | 7 | — | — | — |
| [base/ntsetup/srvpack_binary_release/en](../../base/ntsetup/srvpack_binary_release/en) | 1 | [base/ntsetup/srvpack_binary_release/en/dirs](../../base/ntsetup/srvpack_binary_release/en/dirs) | — | — |
| [base/ntsetup/srvpack_binary_release/en/i386](../../base/ntsetup/srvpack_binary_release/en/i386) | 2 | [base/ntsetup/srvpack_binary_release/en/i386/sources](../../base/ntsetup/srvpack_binary_release/en/i386/sources), [base/ntsetup/srvpack_binary_release/en/i386/makefile](../../base/ntsetup/srvpack_binary_release/en/i386/makefile) | — | — |
| [base/ntsetup/srvpack_binary_release/en/i386/chk](../../base/ntsetup/srvpack_binary_release/en/i386/chk) | 7 | — | — | — |
| [base/ntsetup/srvpack_binary_release/en/i386/fre](../../base/ntsetup/srvpack_binary_release/en/i386/fre) | 7 | — | — | — |
| [base/ntsetup/srvpack_binary_release/en/ia64](../../base/ntsetup/srvpack_binary_release/en/ia64) | 2 | [base/ntsetup/srvpack_binary_release/en/ia64/sources](../../base/ntsetup/srvpack_binary_release/en/ia64/sources), [base/ntsetup/srvpack_binary_release/en/ia64/makefile](../../base/ntsetup/srvpack_binary_release/en/ia64/makefile) | — | — |
| [base/ntsetup/srvpack_binary_release/en/ia64/chk](../../base/ntsetup/srvpack_binary_release/en/ia64/chk) | 7 | — | — | — |
| [base/ntsetup/srvpack_binary_release/en/ia64/fre](../../base/ntsetup/srvpack_binary_release/en/ia64/fre) | 7 | — | — | — |
| [base/ntsetup/srvpack_binary_release/es](../../base/ntsetup/srvpack_binary_release/es) | 1 | [base/ntsetup/srvpack_binary_release/es/dirs](../../base/ntsetup/srvpack_binary_release/es/dirs) | — | — |
| [base/ntsetup/srvpack_binary_release/es/i386](../../base/ntsetup/srvpack_binary_release/es/i386) | 2 | [base/ntsetup/srvpack_binary_release/es/i386/sources](../../base/ntsetup/srvpack_binary_release/es/i386/sources), [base/ntsetup/srvpack_binary_release/es/i386/makefile](../../base/ntsetup/srvpack_binary_release/es/i386/makefile) | — | — |
| [base/ntsetup/srvpack_binary_release/es/i386/fre](../../base/ntsetup/srvpack_binary_release/es/i386/fre) | 7 | — | — | — |
| [base/ntsetup/srvpack_binary_release/es/ia64](../../base/ntsetup/srvpack_binary_release/es/ia64) | 2 | [base/ntsetup/srvpack_binary_release/es/ia64/sources](../../base/ntsetup/srvpack_binary_release/es/ia64/sources), [base/ntsetup/srvpack_binary_release/es/ia64/makefile](../../base/ntsetup/srvpack_binary_release/es/ia64/makefile) | — | — |
| [base/ntsetup/srvpack_binary_release/es/ia64/fre](../../base/ntsetup/srvpack_binary_release/es/ia64/fre) | 7 | — | — | — |
| [base/ntsetup/srvpack_binary_release/fi](../../base/ntsetup/srvpack_binary_release/fi) | 1 | [base/ntsetup/srvpack_binary_release/fi/dirs](../../base/ntsetup/srvpack_binary_release/fi/dirs) | — | — |
| [base/ntsetup/srvpack_binary_release/fi/i386](../../base/ntsetup/srvpack_binary_release/fi/i386) | 2 | [base/ntsetup/srvpack_binary_release/fi/i386/sources](../../base/ntsetup/srvpack_binary_release/fi/i386/sources), [base/ntsetup/srvpack_binary_release/fi/i386/makefile](../../base/ntsetup/srvpack_binary_release/fi/i386/makefile) | — | — |
| [base/ntsetup/srvpack_binary_release/fi/i386/fre](../../base/ntsetup/srvpack_binary_release/fi/i386/fre) | 7 | — | — | — |
| [base/ntsetup/srvpack_binary_release/fi/ia64](../../base/ntsetup/srvpack_binary_release/fi/ia64) | 2 | [base/ntsetup/srvpack_binary_release/fi/ia64/sources](../../base/ntsetup/srvpack_binary_release/fi/ia64/sources), [base/ntsetup/srvpack_binary_release/fi/ia64/makefile](../../base/ntsetup/srvpack_binary_release/fi/ia64/makefile) | — | — |
| [base/ntsetup/srvpack_binary_release/fi/ia64/fre](../../base/ntsetup/srvpack_binary_release/fi/ia64/fre) | 7 | — | — | — |
| [base/ntsetup/srvpack_binary_release/fr](../../base/ntsetup/srvpack_binary_release/fr) | 1 | [base/ntsetup/srvpack_binary_release/fr/dirs](../../base/ntsetup/srvpack_binary_release/fr/dirs) | — | — |
| [base/ntsetup/srvpack_binary_release/fr/i386](../../base/ntsetup/srvpack_binary_release/fr/i386) | 2 | [base/ntsetup/srvpack_binary_release/fr/i386/sources](../../base/ntsetup/srvpack_binary_release/fr/i386/sources), [base/ntsetup/srvpack_binary_release/fr/i386/makefile](../../base/ntsetup/srvpack_binary_release/fr/i386/makefile) | — | — |
| [base/ntsetup/srvpack_binary_release/fr/i386/fre](../../base/ntsetup/srvpack_binary_release/fr/i386/fre) | 7 | — | — | — |
| [base/ntsetup/srvpack_binary_release/fr/ia64](../../base/ntsetup/srvpack_binary_release/fr/ia64) | 2 | [base/ntsetup/srvpack_binary_release/fr/ia64/sources](../../base/ntsetup/srvpack_binary_release/fr/ia64/sources), [base/ntsetup/srvpack_binary_release/fr/ia64/makefile](../../base/ntsetup/srvpack_binary_release/fr/ia64/makefile) | — | — |
| [base/ntsetup/srvpack_binary_release/fr/ia64/fre](../../base/ntsetup/srvpack_binary_release/fr/ia64/fre) | 7 | — | — | — |
| [base/ntsetup/srvpack_binary_release/gb](../../base/ntsetup/srvpack_binary_release/gb) | 1 | [base/ntsetup/srvpack_binary_release/gb/dirs](../../base/ntsetup/srvpack_binary_release/gb/dirs) | — | — |
| [base/ntsetup/srvpack_binary_release/gb/i386](../../base/ntsetup/srvpack_binary_release/gb/i386) | 2 | [base/ntsetup/srvpack_binary_release/gb/i386/sources](../../base/ntsetup/srvpack_binary_release/gb/i386/sources), [base/ntsetup/srvpack_binary_release/gb/i386/makefile](../../base/ntsetup/srvpack_binary_release/gb/i386/makefile) | — | — |
| [base/ntsetup/srvpack_binary_release/gb/i386/fre](../../base/ntsetup/srvpack_binary_release/gb/i386/fre) | 7 | — | — | — |
| [base/ntsetup/srvpack_binary_release/gb/ia64](../../base/ntsetup/srvpack_binary_release/gb/ia64) | 2 | [base/ntsetup/srvpack_binary_release/gb/ia64/sources](../../base/ntsetup/srvpack_binary_release/gb/ia64/sources), [base/ntsetup/srvpack_binary_release/gb/ia64/makefile](../../base/ntsetup/srvpack_binary_release/gb/ia64/makefile) | — | — |
| [base/ntsetup/srvpack_binary_release/gb/ia64/fre](../../base/ntsetup/srvpack_binary_release/gb/ia64/fre) | 7 | — | — | — |
| [base/ntsetup/srvpack_binary_release/he](../../base/ntsetup/srvpack_binary_release/he) | 1 | [base/ntsetup/srvpack_binary_release/he/dirs](../../base/ntsetup/srvpack_binary_release/he/dirs) | — | — |
| [base/ntsetup/srvpack_binary_release/he/i386](../../base/ntsetup/srvpack_binary_release/he/i386) | 2 | [base/ntsetup/srvpack_binary_release/he/i386/sources](../../base/ntsetup/srvpack_binary_release/he/i386/sources), [base/ntsetup/srvpack_binary_release/he/i386/makefile](../../base/ntsetup/srvpack_binary_release/he/i386/makefile) | — | — |
| [base/ntsetup/srvpack_binary_release/he/i386/fre](../../base/ntsetup/srvpack_binary_release/he/i386/fre) | 7 | — | — | — |
| [base/ntsetup/srvpack_binary_release/he/ia64](../../base/ntsetup/srvpack_binary_release/he/ia64) | 2 | [base/ntsetup/srvpack_binary_release/he/ia64/sources](../../base/ntsetup/srvpack_binary_release/he/ia64/sources), [base/ntsetup/srvpack_binary_release/he/ia64/makefile](../../base/ntsetup/srvpack_binary_release/he/ia64/makefile) | — | — |
| [base/ntsetup/srvpack_binary_release/he/ia64/fre](../../base/ntsetup/srvpack_binary_release/he/ia64/fre) | 7 | — | — | — |
| [base/ntsetup/srvpack_binary_release/hu](../../base/ntsetup/srvpack_binary_release/hu) | 1 | [base/ntsetup/srvpack_binary_release/hu/dirs](../../base/ntsetup/srvpack_binary_release/hu/dirs) | — | — |
| [base/ntsetup/srvpack_binary_release/hu/i386](../../base/ntsetup/srvpack_binary_release/hu/i386) | 2 | [base/ntsetup/srvpack_binary_release/hu/i386/sources](../../base/ntsetup/srvpack_binary_release/hu/i386/sources), [base/ntsetup/srvpack_binary_release/hu/i386/makefile](../../base/ntsetup/srvpack_binary_release/hu/i386/makefile) | — | — |
| [base/ntsetup/srvpack_binary_release/hu/i386/fre](../../base/ntsetup/srvpack_binary_release/hu/i386/fre) | 7 | — | — | — |
| [base/ntsetup/srvpack_binary_release/hu/ia64](../../base/ntsetup/srvpack_binary_release/hu/ia64) | 2 | [base/ntsetup/srvpack_binary_release/hu/ia64/sources](../../base/ntsetup/srvpack_binary_release/hu/ia64/sources), [base/ntsetup/srvpack_binary_release/hu/ia64/makefile](../../base/ntsetup/srvpack_binary_release/hu/ia64/makefile) | — | — |
| [base/ntsetup/srvpack_binary_release/hu/ia64/fre](../../base/ntsetup/srvpack_binary_release/hu/ia64/fre) | 7 | — | — | — |
| [base/ntsetup/srvpack_binary_release/it](../../base/ntsetup/srvpack_binary_release/it) | 1 | [base/ntsetup/srvpack_binary_release/it/dirs](../../base/ntsetup/srvpack_binary_release/it/dirs) | — | — |
| [base/ntsetup/srvpack_binary_release/it/i386](../../base/ntsetup/srvpack_binary_release/it/i386) | 2 | [base/ntsetup/srvpack_binary_release/it/i386/sources](../../base/ntsetup/srvpack_binary_release/it/i386/sources), [base/ntsetup/srvpack_binary_release/it/i386/makefile](../../base/ntsetup/srvpack_binary_release/it/i386/makefile) | — | — |
| [base/ntsetup/srvpack_binary_release/it/i386/fre](../../base/ntsetup/srvpack_binary_release/it/i386/fre) | 7 | — | — | — |
| [base/ntsetup/srvpack_binary_release/it/ia64](../../base/ntsetup/srvpack_binary_release/it/ia64) | 2 | [base/ntsetup/srvpack_binary_release/it/ia64/sources](../../base/ntsetup/srvpack_binary_release/it/ia64/sources), [base/ntsetup/srvpack_binary_release/it/ia64/makefile](../../base/ntsetup/srvpack_binary_release/it/ia64/makefile) | — | — |
| [base/ntsetup/srvpack_binary_release/it/ia64/fre](../../base/ntsetup/srvpack_binary_release/it/ia64/fre) | 7 | — | — | — |
| [base/ntsetup/srvpack_binary_release/ja](../../base/ntsetup/srvpack_binary_release/ja) | 1 | [base/ntsetup/srvpack_binary_release/ja/dirs](../../base/ntsetup/srvpack_binary_release/ja/dirs) | — | — |
| [base/ntsetup/srvpack_binary_release/ja/i386](../../base/ntsetup/srvpack_binary_release/ja/i386) | 2 | [base/ntsetup/srvpack_binary_release/ja/i386/sources](../../base/ntsetup/srvpack_binary_release/ja/i386/sources), [base/ntsetup/srvpack_binary_release/ja/i386/makefile](../../base/ntsetup/srvpack_binary_release/ja/i386/makefile) | — | — |
| [base/ntsetup/srvpack_binary_release/ja/i386/fre](../../base/ntsetup/srvpack_binary_release/ja/i386/fre) | 7 | — | — | — |
| [base/ntsetup/srvpack_binary_release/ja/ia64](../../base/ntsetup/srvpack_binary_release/ja/ia64) | 2 | [base/ntsetup/srvpack_binary_release/ja/ia64/sources](../../base/ntsetup/srvpack_binary_release/ja/ia64/sources), [base/ntsetup/srvpack_binary_release/ja/ia64/makefile](../../base/ntsetup/srvpack_binary_release/ja/ia64/makefile) | — | — |
| [base/ntsetup/srvpack_binary_release/ja/ia64/fre](../../base/ntsetup/srvpack_binary_release/ja/ia64/fre) | 7 | — | — | — |
| [base/ntsetup/srvpack_binary_release/ko](../../base/ntsetup/srvpack_binary_release/ko) | 1 | [base/ntsetup/srvpack_binary_release/ko/dirs](../../base/ntsetup/srvpack_binary_release/ko/dirs) | — | — |
| [base/ntsetup/srvpack_binary_release/ko/i386](../../base/ntsetup/srvpack_binary_release/ko/i386) | 2 | [base/ntsetup/srvpack_binary_release/ko/i386/sources](../../base/ntsetup/srvpack_binary_release/ko/i386/sources), [base/ntsetup/srvpack_binary_release/ko/i386/makefile](../../base/ntsetup/srvpack_binary_release/ko/i386/makefile) | — | — |
| [base/ntsetup/srvpack_binary_release/ko/i386/fre](../../base/ntsetup/srvpack_binary_release/ko/i386/fre) | 7 | — | — | — |
| [base/ntsetup/srvpack_binary_release/ko/ia64](../../base/ntsetup/srvpack_binary_release/ko/ia64) | 2 | [base/ntsetup/srvpack_binary_release/ko/ia64/sources](../../base/ntsetup/srvpack_binary_release/ko/ia64/sources), [base/ntsetup/srvpack_binary_release/ko/ia64/makefile](../../base/ntsetup/srvpack_binary_release/ko/ia64/makefile) | — | — |
| [base/ntsetup/srvpack_binary_release/ko/ia64/fre](../../base/ntsetup/srvpack_binary_release/ko/ia64/fre) | 7 | — | — | — |
| [base/ntsetup/srvpack_binary_release/nl](../../base/ntsetup/srvpack_binary_release/nl) | 1 | [base/ntsetup/srvpack_binary_release/nl/dirs](../../base/ntsetup/srvpack_binary_release/nl/dirs) | — | — |
| [base/ntsetup/srvpack_binary_release/nl/i386](../../base/ntsetup/srvpack_binary_release/nl/i386) | 2 | [base/ntsetup/srvpack_binary_release/nl/i386/sources](../../base/ntsetup/srvpack_binary_release/nl/i386/sources), [base/ntsetup/srvpack_binary_release/nl/i386/makefile](../../base/ntsetup/srvpack_binary_release/nl/i386/makefile) | — | — |
| [base/ntsetup/srvpack_binary_release/nl/i386/fre](../../base/ntsetup/srvpack_binary_release/nl/i386/fre) | 7 | — | — | — |
| [base/ntsetup/srvpack_binary_release/nl/ia64](../../base/ntsetup/srvpack_binary_release/nl/ia64) | 2 | [base/ntsetup/srvpack_binary_release/nl/ia64/sources](../../base/ntsetup/srvpack_binary_release/nl/ia64/sources), [base/ntsetup/srvpack_binary_release/nl/ia64/makefile](../../base/ntsetup/srvpack_binary_release/nl/ia64/makefile) | — | — |
| [base/ntsetup/srvpack_binary_release/nl/ia64/fre](../../base/ntsetup/srvpack_binary_release/nl/ia64/fre) | 7 | — | — | — |
| [base/ntsetup/srvpack_binary_release/no](../../base/ntsetup/srvpack_binary_release/no) | 1 | [base/ntsetup/srvpack_binary_release/no/dirs](../../base/ntsetup/srvpack_binary_release/no/dirs) | — | — |
| [base/ntsetup/srvpack_binary_release/no/i386](../../base/ntsetup/srvpack_binary_release/no/i386) | 2 | [base/ntsetup/srvpack_binary_release/no/i386/sources](../../base/ntsetup/srvpack_binary_release/no/i386/sources), [base/ntsetup/srvpack_binary_release/no/i386/makefile](../../base/ntsetup/srvpack_binary_release/no/i386/makefile) | — | — |
| [base/ntsetup/srvpack_binary_release/no/i386/fre](../../base/ntsetup/srvpack_binary_release/no/i386/fre) | 7 | — | — | — |
| [base/ntsetup/srvpack_binary_release/no/ia64](../../base/ntsetup/srvpack_binary_release/no/ia64) | 2 | [base/ntsetup/srvpack_binary_release/no/ia64/sources](../../base/ntsetup/srvpack_binary_release/no/ia64/sources), [base/ntsetup/srvpack_binary_release/no/ia64/makefile](../../base/ntsetup/srvpack_binary_release/no/ia64/makefile) | — | — |
| [base/ntsetup/srvpack_binary_release/no/ia64/fre](../../base/ntsetup/srvpack_binary_release/no/ia64/fre) | 7 | — | — | — |
| [base/ntsetup/srvpack_binary_release/pl](../../base/ntsetup/srvpack_binary_release/pl) | 1 | [base/ntsetup/srvpack_binary_release/pl/dirs](../../base/ntsetup/srvpack_binary_release/pl/dirs) | — | — |
| [base/ntsetup/srvpack_binary_release/pl/i386](../../base/ntsetup/srvpack_binary_release/pl/i386) | 2 | [base/ntsetup/srvpack_binary_release/pl/i386/sources](../../base/ntsetup/srvpack_binary_release/pl/i386/sources), [base/ntsetup/srvpack_binary_release/pl/i386/makefile](../../base/ntsetup/srvpack_binary_release/pl/i386/makefile) | — | — |
| [base/ntsetup/srvpack_binary_release/pl/i386/fre](../../base/ntsetup/srvpack_binary_release/pl/i386/fre) | 7 | — | — | — |
| [base/ntsetup/srvpack_binary_release/pl/ia64](../../base/ntsetup/srvpack_binary_release/pl/ia64) | 2 | [base/ntsetup/srvpack_binary_release/pl/ia64/sources](../../base/ntsetup/srvpack_binary_release/pl/ia64/sources), [base/ntsetup/srvpack_binary_release/pl/ia64/makefile](../../base/ntsetup/srvpack_binary_release/pl/ia64/makefile) | — | — |
| [base/ntsetup/srvpack_binary_release/pl/ia64/fre](../../base/ntsetup/srvpack_binary_release/pl/ia64/fre) | 7 | — | — | — |
| [base/ntsetup/srvpack_binary_release/pt](../../base/ntsetup/srvpack_binary_release/pt) | 1 | [base/ntsetup/srvpack_binary_release/pt/dirs](../../base/ntsetup/srvpack_binary_release/pt/dirs) | — | — |
| [base/ntsetup/srvpack_binary_release/pt/i386](../../base/ntsetup/srvpack_binary_release/pt/i386) | 2 | [base/ntsetup/srvpack_binary_release/pt/i386/sources](../../base/ntsetup/srvpack_binary_release/pt/i386/sources), [base/ntsetup/srvpack_binary_release/pt/i386/makefile](../../base/ntsetup/srvpack_binary_release/pt/i386/makefile) | — | — |
| [base/ntsetup/srvpack_binary_release/pt/i386/fre](../../base/ntsetup/srvpack_binary_release/pt/i386/fre) | 7 | — | — | — |
| [base/ntsetup/srvpack_binary_release/pt/ia64](../../base/ntsetup/srvpack_binary_release/pt/ia64) | 2 | [base/ntsetup/srvpack_binary_release/pt/ia64/sources](../../base/ntsetup/srvpack_binary_release/pt/ia64/sources), [base/ntsetup/srvpack_binary_release/pt/ia64/makefile](../../base/ntsetup/srvpack_binary_release/pt/ia64/makefile) | — | — |
| [base/ntsetup/srvpack_binary_release/pt/ia64/fre](../../base/ntsetup/srvpack_binary_release/pt/ia64/fre) | 7 | — | — | — |
| [base/ntsetup/srvpack_binary_release/ru](../../base/ntsetup/srvpack_binary_release/ru) | 1 | [base/ntsetup/srvpack_binary_release/ru/dirs](../../base/ntsetup/srvpack_binary_release/ru/dirs) | — | — |
| [base/ntsetup/srvpack_binary_release/ru/i386](../../base/ntsetup/srvpack_binary_release/ru/i386) | 2 | [base/ntsetup/srvpack_binary_release/ru/i386/sources](../../base/ntsetup/srvpack_binary_release/ru/i386/sources), [base/ntsetup/srvpack_binary_release/ru/i386/makefile](../../base/ntsetup/srvpack_binary_release/ru/i386/makefile) | — | — |
| [base/ntsetup/srvpack_binary_release/ru/i386/fre](../../base/ntsetup/srvpack_binary_release/ru/i386/fre) | 7 | — | — | — |
| [base/ntsetup/srvpack_binary_release/ru/ia64](../../base/ntsetup/srvpack_binary_release/ru/ia64) | 2 | [base/ntsetup/srvpack_binary_release/ru/ia64/sources](../../base/ntsetup/srvpack_binary_release/ru/ia64/sources), [base/ntsetup/srvpack_binary_release/ru/ia64/makefile](../../base/ntsetup/srvpack_binary_release/ru/ia64/makefile) | — | — |
| [base/ntsetup/srvpack_binary_release/ru/ia64/fre](../../base/ntsetup/srvpack_binary_release/ru/ia64/fre) | 7 | — | — | — |
| [base/ntsetup/srvpack_binary_release/sv](../../base/ntsetup/srvpack_binary_release/sv) | 1 | [base/ntsetup/srvpack_binary_release/sv/dirs](../../base/ntsetup/srvpack_binary_release/sv/dirs) | — | — |
| [base/ntsetup/srvpack_binary_release/sv/i386](../../base/ntsetup/srvpack_binary_release/sv/i386) | 2 | [base/ntsetup/srvpack_binary_release/sv/i386/sources](../../base/ntsetup/srvpack_binary_release/sv/i386/sources), [base/ntsetup/srvpack_binary_release/sv/i386/makefile](../../base/ntsetup/srvpack_binary_release/sv/i386/makefile) | — | — |
| [base/ntsetup/srvpack_binary_release/sv/i386/fre](../../base/ntsetup/srvpack_binary_release/sv/i386/fre) | 7 | — | — | — |
| [base/ntsetup/srvpack_binary_release/sv/ia64](../../base/ntsetup/srvpack_binary_release/sv/ia64) | 2 | [base/ntsetup/srvpack_binary_release/sv/ia64/sources](../../base/ntsetup/srvpack_binary_release/sv/ia64/sources), [base/ntsetup/srvpack_binary_release/sv/ia64/makefile](../../base/ntsetup/srvpack_binary_release/sv/ia64/makefile) | — | — |
| [base/ntsetup/srvpack_binary_release/sv/ia64/fre](../../base/ntsetup/srvpack_binary_release/sv/ia64/fre) | 7 | — | — | — |
| [base/ntsetup/srvpack_binary_release/tr](../../base/ntsetup/srvpack_binary_release/tr) | 1 | [base/ntsetup/srvpack_binary_release/tr/dirs](../../base/ntsetup/srvpack_binary_release/tr/dirs) | — | — |
| [base/ntsetup/srvpack_binary_release/tr/i386](../../base/ntsetup/srvpack_binary_release/tr/i386) | 2 | [base/ntsetup/srvpack_binary_release/tr/i386/sources](../../base/ntsetup/srvpack_binary_release/tr/i386/sources), [base/ntsetup/srvpack_binary_release/tr/i386/makefile](../../base/ntsetup/srvpack_binary_release/tr/i386/makefile) | — | — |
| [base/ntsetup/srvpack_binary_release/tr/i386/fre](../../base/ntsetup/srvpack_binary_release/tr/i386/fre) | 7 | — | — | — |
| [base/ntsetup/srvpack_binary_release/tr/ia64](../../base/ntsetup/srvpack_binary_release/tr/ia64) | 2 | [base/ntsetup/srvpack_binary_release/tr/ia64/sources](../../base/ntsetup/srvpack_binary_release/tr/ia64/sources), [base/ntsetup/srvpack_binary_release/tr/ia64/makefile](../../base/ntsetup/srvpack_binary_release/tr/ia64/makefile) | — | — |
| [base/ntsetup/srvpack_binary_release/tr/ia64/fre](../../base/ntsetup/srvpack_binary_release/tr/ia64/fre) | 7 | — | — | — |
| [base/ntsetup/srvpack_binary_release/tw](../../base/ntsetup/srvpack_binary_release/tw) | 1 | [base/ntsetup/srvpack_binary_release/tw/dirs](../../base/ntsetup/srvpack_binary_release/tw/dirs) | — | — |
| [base/ntsetup/srvpack_binary_release/tw/i386](../../base/ntsetup/srvpack_binary_release/tw/i386) | 2 | [base/ntsetup/srvpack_binary_release/tw/i386/sources](../../base/ntsetup/srvpack_binary_release/tw/i386/sources), [base/ntsetup/srvpack_binary_release/tw/i386/makefile](../../base/ntsetup/srvpack_binary_release/tw/i386/makefile) | — | — |
| [base/ntsetup/srvpack_binary_release/tw/i386/fre](../../base/ntsetup/srvpack_binary_release/tw/i386/fre) | 7 | — | — | — |
| [base/ntsetup/srvpack_binary_release/tw/ia64](../../base/ntsetup/srvpack_binary_release/tw/ia64) | 2 | [base/ntsetup/srvpack_binary_release/tw/ia64/sources](../../base/ntsetup/srvpack_binary_release/tw/ia64/sources), [base/ntsetup/srvpack_binary_release/tw/ia64/makefile](../../base/ntsetup/srvpack_binary_release/tw/ia64/makefile) | — | — |
| [base/ntsetup/srvpack_binary_release/tw/ia64/fre](../../base/ntsetup/srvpack_binary_release/tw/ia64/fre) | 7 | — | — | — |
| [base/ntsetup/stripinf](../../base/ntsetup/stripinf) | 5 | [base/ntsetup/stripinf/sources](../../base/ntsetup/stripinf/sources), [base/ntsetup/stripinf/makefile](../../base/ntsetup/stripinf/makefile) | `stripinf` | `PROGRAM` |
| [base/ntsetup/svcpack](../../base/ntsetup/svcpack) | 7 | [base/ntsetup/svcpack/sources](../../base/ntsetup/svcpack/sources), [base/ntsetup/svcpack/makefile](../../base/ntsetup/svcpack/makefile) | `svcpack` | `DYNLINK` |
| [base/ntsetup/syssetup](../../base/ntsetup/syssetup) | 103 | [base/ntsetup/syssetup/sources](../../base/ntsetup/syssetup/sources), [base/ntsetup/syssetup/makefile](../../base/ntsetup/syssetup/makefile) | `syssetup` | `DYNLINK` |
| [base/ntsetup/syssetup/amd64](../../base/ntsetup/syssetup/amd64) | 6 | [base/ntsetup/syssetup/amd64/sources](../../base/ntsetup/syssetup/amd64/sources) | — | — |
| [base/ntsetup/syssetup/i386](../../base/ntsetup/syssetup/i386) | 8 | [base/ntsetup/syssetup/i386/sources](../../base/ntsetup/syssetup/i386/sources) | — | — |
| [base/ntsetup/syssetup/ia64](../../base/ntsetup/syssetup/ia64) | 2 | [base/ntsetup/syssetup/ia64/sources](../../base/ntsetup/syssetup/ia64/sources) | — | — |
| [base/ntsetup/testtool](../../base/ntsetup/testtool) | 3 | [base/ntsetup/testtool/sources](../../base/ntsetup/testtool/sources), [base/ntsetup/testtool/makefile](../../base/ntsetup/testtool/makefile) | `x` | `PROGRAM` |
| [base/ntsetup/textmode](../../base/ntsetup/textmode) | 1 | [base/ntsetup/textmode/dirs](../../base/ntsetup/textmode/dirs) | — | — |
| [base/ntsetup/textmode/cmdcons](../../base/ntsetup/textmode/cmdcons) | 24 | [base/ntsetup/textmode/cmdcons/sources](../../base/ntsetup/textmode/cmdcons/sources), [base/ntsetup/textmode/cmdcons/makefile](../../base/ntsetup/textmode/cmdcons/makefile) | `spcmdcon` | `DRIVER` |
| [base/ntsetup/textmode/disksig](../../base/ntsetup/textmode/disksig) | 3 | [base/ntsetup/textmode/disksig/sources](../../base/ntsetup/textmode/disksig/sources), [base/ntsetup/textmode/disksig/makefile](../../base/ntsetup/textmode/disksig/makefile) | `disksig` | `PROGRAM` |
| [base/ntsetup/textmode/inc](../../base/ntsetup/textmode/inc) | 3 | [base/ntsetup/textmode/inc/sources](../../base/ntsetup/textmode/inc/sources), [base/ntsetup/textmode/inc/makefile](../../base/ntsetup/textmode/inc/makefile) | — | `LIBRARY` |
| [base/ntsetup/textmode/kernel](../../base/ntsetup/textmode/kernel) | 116 | [base/ntsetup/textmode/kernel/dirs](../../base/ntsetup/textmode/kernel/dirs) | — | — |
| [base/ntsetup/textmode/kernel/cabtest](../../base/ntsetup/textmode/kernel/cabtest) | 3 | [base/ntsetup/textmode/kernel/cabtest/sources](../../base/ntsetup/textmode/kernel/cabtest/sources), [base/ntsetup/textmode/kernel/cabtest/makefile](../../base/ntsetup/textmode/kernel/cabtest/makefile) | `spcabtest` | `PROGRAM` |
| [base/ntsetup/textmode/kernel/daytona](../../base/ntsetup/textmode/kernel/daytona) | 2 | [base/ntsetup/textmode/kernel/daytona/sources](../../base/ntsetup/textmode/kernel/daytona/sources), [base/ntsetup/textmode/kernel/daytona/makefile](../../base/ntsetup/textmode/kernel/daytona/makefile) | — | — |
| [base/ntsetup/textmode/kernel/i386](../../base/ntsetup/textmode/kernel/i386) | 9 | [base/ntsetup/textmode/kernel/i386/sources](../../base/ntsetup/textmode/kernel/i386/sources) | — | — |
| [base/ntsetup/textmode/kernel/nec_98](../../base/ntsetup/textmode/kernel/nec_98) | 2 | [base/ntsetup/textmode/kernel/nec_98/sources](../../base/ntsetup/textmode/kernel/nec_98/sources), [base/ntsetup/textmode/kernel/nec_98/makefile](../../base/ntsetup/textmode/kernel/nec_98/makefile) | — | — |
| [base/ntsetup/textmode/spddlang](../../base/ntsetup/textmode/spddlang) | 3 | [base/ntsetup/textmode/spddlang/dirs](../../base/ntsetup/textmode/spddlang/dirs) | — | — |
| [base/ntsetup/textmode/spddlang/fe](../../base/ntsetup/textmode/spddlang/fe) | 18 | [base/ntsetup/textmode/spddlang/fe/sources](../../base/ntsetup/textmode/spddlang/fe/sources), [base/ntsetup/textmode/spddlang/fe/makefile](../../base/ntsetup/textmode/spddlang/fe/makefile) | `spddlang` | `EXPORT_DRIVER` |
| [base/ntsetup/textmode/spddlang/sbcs](../../base/ntsetup/textmode/spddlang/sbcs) | 4 | [base/ntsetup/textmode/spddlang/sbcs/sources](../../base/ntsetup/textmode/spddlang/sbcs/sources), [base/ntsetup/textmode/spddlang/sbcs/makefile](../../base/ntsetup/textmode/spddlang/sbcs/makefile) | `spddlang` | `EXPORT_DRIVER` |
| [base/ntsetup/textmode/user](../../base/ntsetup/textmode/user) | 37 | [base/ntsetup/textmode/user/sources](../../base/ntsetup/textmode/user/sources), [base/ntsetup/textmode/user/makefile](../../base/ntsetup/textmode/user/makefile) | `usetup` | `PROGRAM` |
| [base/ntsetup/textmode/winnt](../../base/ntsetup/textmode/winnt) | 22 | [base/ntsetup/textmode/winnt/dirs](../../base/ntsetup/textmode/winnt/dirs) | — | — |
| [base/ntsetup/textmode/winnt/br](../../base/ntsetup/textmode/winnt/br) | 4 | [base/ntsetup/textmode/winnt/br/sources](../../base/ntsetup/textmode/winnt/br/sources), [base/ntsetup/textmode/winnt/br/makefile](../../base/ntsetup/textmode/winnt/br/makefile) | — | — |
| [base/ntsetup/textmode/winnt/c6](../../base/ntsetup/textmode/winnt/c6) | 0 | — | — | — |
| [base/ntsetup/textmode/winnt/c6/help](../../base/ntsetup/textmode/winnt/c6/help) | 9 | — | — | — |
| [base/ntsetup/textmode/winnt/c6/inc](../../base/ntsetup/textmode/winnt/c6/inc) | 19 | — | — | — |
| [base/ntsetup/textmode/winnt/c6/inc/sys](../../base/ntsetup/textmode/winnt/c6/inc/sys) | 2 | — | — | — |
| [base/ntsetup/textmode/winnt/c6/init](../../base/ntsetup/textmode/winnt/c6/init) | 1 | — | — | — |
| [base/ntsetup/textmode/winnt/c6/lib](../../base/ntsetup/textmode/winnt/c6/lib) | 27 | — | — | — |
| [base/ntsetup/textmode/winnt/cs](../../base/ntsetup/textmode/winnt/cs) | 4 | [base/ntsetup/textmode/winnt/cs/sources](../../base/ntsetup/textmode/winnt/cs/sources), [base/ntsetup/textmode/winnt/cs/makefile](../../base/ntsetup/textmode/winnt/cs/makefile) | — | — |
| [base/ntsetup/textmode/winnt/da](../../base/ntsetup/textmode/winnt/da) | 4 | [base/ntsetup/textmode/winnt/da/sources](../../base/ntsetup/textmode/winnt/da/sources), [base/ntsetup/textmode/winnt/da/makefile](../../base/ntsetup/textmode/winnt/da/makefile) | — | — |
| [base/ntsetup/textmode/winnt/el](../../base/ntsetup/textmode/winnt/el) | 4 | [base/ntsetup/textmode/winnt/el/sources](../../base/ntsetup/textmode/winnt/el/sources), [base/ntsetup/textmode/winnt/el/makefile](../../base/ntsetup/textmode/winnt/el/makefile) | — | — |
| [base/ntsetup/textmode/winnt/es](../../base/ntsetup/textmode/winnt/es) | 4 | [base/ntsetup/textmode/winnt/es/sources](../../base/ntsetup/textmode/winnt/es/sources), [base/ntsetup/textmode/winnt/es/makefile](../../base/ntsetup/textmode/winnt/es/makefile) | — | — |
| [base/ntsetup/textmode/winnt/fi](../../base/ntsetup/textmode/winnt/fi) | 4 | [base/ntsetup/textmode/winnt/fi/sources](../../base/ntsetup/textmode/winnt/fi/sources), [base/ntsetup/textmode/winnt/fi/makefile](../../base/ntsetup/textmode/winnt/fi/makefile) | — | — |
| [base/ntsetup/textmode/winnt/fr](../../base/ntsetup/textmode/winnt/fr) | 4 | [base/ntsetup/textmode/winnt/fr/sources](../../base/ntsetup/textmode/winnt/fr/sources), [base/ntsetup/textmode/winnt/fr/makefile](../../base/ntsetup/textmode/winnt/fr/makefile) | — | — |
| [base/ntsetup/textmode/winnt/ger](../../base/ntsetup/textmode/winnt/ger) | 4 | [base/ntsetup/textmode/winnt/ger/sources](../../base/ntsetup/textmode/winnt/ger/sources), [base/ntsetup/textmode/winnt/ger/makefile](../../base/ntsetup/textmode/winnt/ger/makefile) | — | — |
| [base/ntsetup/textmode/winnt/hu](../../base/ntsetup/textmode/winnt/hu) | 4 | [base/ntsetup/textmode/winnt/hu/sources](../../base/ntsetup/textmode/winnt/hu/sources), [base/ntsetup/textmode/winnt/hu/makefile](../../base/ntsetup/textmode/winnt/hu/makefile) | — | — |
| [base/ntsetup/textmode/winnt/it](../../base/ntsetup/textmode/winnt/it) | 4 | [base/ntsetup/textmode/winnt/it/sources](../../base/ntsetup/textmode/winnt/it/sources), [base/ntsetup/textmode/winnt/it/makefile](../../base/ntsetup/textmode/winnt/it/makefile) | — | — |
| [base/ntsetup/textmode/winnt/jpn](../../base/ntsetup/textmode/winnt/jpn) | 4 | [base/ntsetup/textmode/winnt/jpn/sources](../../base/ntsetup/textmode/winnt/jpn/sources), [base/ntsetup/textmode/winnt/jpn/makefile](../../base/ntsetup/textmode/winnt/jpn/makefile) | — | — |
| [base/ntsetup/textmode/winnt/nl](../../base/ntsetup/textmode/winnt/nl) | 4 | [base/ntsetup/textmode/winnt/nl/sources](../../base/ntsetup/textmode/winnt/nl/sources), [base/ntsetup/textmode/winnt/nl/makefile](../../base/ntsetup/textmode/winnt/nl/makefile) | — | — |
| [base/ntsetup/textmode/winnt/no](../../base/ntsetup/textmode/winnt/no) | 4 | [base/ntsetup/textmode/winnt/no/sources](../../base/ntsetup/textmode/winnt/no/sources), [base/ntsetup/textmode/winnt/no/makefile](../../base/ntsetup/textmode/winnt/no/makefile) | — | — |
| [base/ntsetup/textmode/winnt/pl](../../base/ntsetup/textmode/winnt/pl) | 4 | [base/ntsetup/textmode/winnt/pl/sources](../../base/ntsetup/textmode/winnt/pl/sources), [base/ntsetup/textmode/winnt/pl/makefile](../../base/ntsetup/textmode/winnt/pl/makefile) | — | — |
| [base/ntsetup/textmode/winnt/psu](../../base/ntsetup/textmode/winnt/psu) | 3 | [base/ntsetup/textmode/winnt/psu/sources](../../base/ntsetup/textmode/winnt/psu/sources), [base/ntsetup/textmode/winnt/psu/makefile](../../base/ntsetup/textmode/winnt/psu/makefile) | — | — |
| [base/ntsetup/textmode/winnt/pt](../../base/ntsetup/textmode/winnt/pt) | 4 | [base/ntsetup/textmode/winnt/pt/sources](../../base/ntsetup/textmode/winnt/pt/sources), [base/ntsetup/textmode/winnt/pt/makefile](../../base/ntsetup/textmode/winnt/pt/makefile) | — | — |
| [base/ntsetup/textmode/winnt/ru](../../base/ntsetup/textmode/winnt/ru) | 4 | [base/ntsetup/textmode/winnt/ru/sources](../../base/ntsetup/textmode/winnt/ru/sources), [base/ntsetup/textmode/winnt/ru/makefile](../../base/ntsetup/textmode/winnt/ru/makefile) | — | — |
| [base/ntsetup/textmode/winnt/sv](../../base/ntsetup/textmode/winnt/sv) | 4 | [base/ntsetup/textmode/winnt/sv/sources](../../base/ntsetup/textmode/winnt/sv/sources), [base/ntsetup/textmode/winnt/sv/makefile](../../base/ntsetup/textmode/winnt/sv/makefile) | — | — |
| [base/ntsetup/textmode/winnt/tr](../../base/ntsetup/textmode/winnt/tr) | 4 | [base/ntsetup/textmode/winnt/tr/sources](../../base/ntsetup/textmode/winnt/tr/sources), [base/ntsetup/textmode/winnt/tr/makefile](../../base/ntsetup/textmode/winnt/tr/makefile) | — | — |
| [base/ntsetup/textmode/winnt/tst](../../base/ntsetup/textmode/winnt/tst) | 3 | [base/ntsetup/textmode/winnt/tst/sources](../../base/ntsetup/textmode/winnt/tst/sources), [base/ntsetup/textmode/winnt/tst/makefile](../../base/ntsetup/textmode/winnt/tst/makefile) | — | — |
| [base/ntsetup/textmode/winnt/us2](../../base/ntsetup/textmode/winnt/us2) | 4 | [base/ntsetup/textmode/winnt/us2/sources](../../base/ntsetup/textmode/winnt/us2/sources), [base/ntsetup/textmode/winnt/us2/makefile](../../base/ntsetup/textmode/winnt/us2/makefile) | — | — |
| [base/ntsetup/textmode/winnt/usa](../../base/ntsetup/textmode/winnt/usa) | 4 | [base/ntsetup/textmode/winnt/usa/sources](../../base/ntsetup/textmode/winnt/usa/sources), [base/ntsetup/textmode/winnt/usa/makefile](../../base/ntsetup/textmode/winnt/usa/makefile) | — | — |
| [base/ntsetup/tools](../../base/ntsetup/tools) | 1 | [base/ntsetup/tools/dirs](../../base/ntsetup/tools/dirs) | — | — |
| [base/ntsetup/tools/dbcsfchk](../../base/ntsetup/tools/dbcsfchk) | 3 | [base/ntsetup/tools/dbcsfchk/sources](../../base/ntsetup/tools/dbcsfchk/sources), [base/ntsetup/tools/dbcsfchk/makefile](../../base/ntsetup/tools/dbcsfchk/makefile) | `dbcsfchk` | `PROGRAM` |
| [base/ntsetup/tools/dt](../../base/ntsetup/tools/dt) | 3 | [base/ntsetup/tools/dt/sources](../../base/ntsetup/tools/dt/sources), [base/ntsetup/tools/dt/makefile](../../base/ntsetup/tools/dt/makefile) | `dt` | `PROGRAM` |
| [base/ntsetup/tools/html2bmp](../../base/ntsetup/tools/html2bmp) | 16 | [base/ntsetup/tools/html2bmp/sources](../../base/ntsetup/tools/html2bmp/sources), [base/ntsetup/tools/html2bmp/makefile](../../base/ntsetup/tools/html2bmp/makefile) | `html2bmp` | `PROGRAM` |
| [base/ntsetup/tools/html2bmp/res](../../base/ntsetup/tools/html2bmp/res) | 2 | — | — | — |
| [base/ntsetup/tools/imgdt](../../base/ntsetup/tools/imgdt) | 3 | [base/ntsetup/tools/imgdt/sources](../../base/ntsetup/tools/imgdt/sources), [base/ntsetup/tools/imgdt/makefile](../../base/ntsetup/tools/imgdt/makefile) | `imgdt` | `PROGRAM` |
| [base/ntsetup/tools/lockmem](../../base/ntsetup/tools/lockmem) | 3 | [base/ntsetup/tools/lockmem/sources](../../base/ntsetup/tools/lockmem/sources), [base/ntsetup/tools/lockmem/makefile](../../base/ntsetup/tools/lockmem/makefile) | `lockmem` | `PROGRAM` |
| [base/ntsetup/undostub](../../base/ntsetup/undostub) | 5 | [base/ntsetup/undostub/sources](../../base/ntsetup/undostub/sources), [base/ntsetup/undostub/makefile](../../base/ntsetup/undostub/makefile) | `OSUNINST` | `DYNLINK` |
| [base/ntsetup/updatemsi](../../base/ntsetup/updatemsi) | 3 | [base/ntsetup/updatemsi/sources](../../base/ntsetup/updatemsi/sources), [base/ntsetup/updatemsi/makefile](../../base/ntsetup/updatemsi/makefile) | — | `NOTARGET` |
| [base/ntsetup/updatemsi/i386](../../base/ntsetup/updatemsi/i386) | 1 | — | — | — |
| [base/ntsetup/updatemsi/ia64](../../base/ntsetup/updatemsi/ia64) | 1 | — | — | — |
| [base/ntsetup/win95upg](../../base/ntsetup/win95upg) | 2 | [base/ntsetup/win95upg/dirs](../../base/ntsetup/win95upg/dirs) | — | — |
| [base/ntsetup/win95upg/common](../../base/ntsetup/win95upg/common) | 2 | [base/ntsetup/win95upg/common/dirs](../../base/ntsetup/win95upg/common/dirs) | — | — |
| [base/ntsetup/win95upg/common/fileenum](../../base/ntsetup/win95upg/common/fileenum) | 9 | [base/ntsetup/win95upg/common/fileenum/sources](../../base/ntsetup/win95upg/common/fileenum/sources), [base/ntsetup/win95upg/common/fileenum/makefile](../../base/ntsetup/win95upg/common/fileenum/makefile) | `fileenum` | `LIBRARY` |
| [base/ntsetup/win95upg/common/memdb](../../base/ntsetup/win95upg/common/memdb) | 11 | [base/ntsetup/win95upg/common/memdb/sources](../../base/ntsetup/win95upg/common/memdb/sources), [base/ntsetup/win95upg/common/memdb/makefile](../../base/ntsetup/win95upg/common/memdb/makefile) | `memdb` | `LIBRARY` |
| [base/ntsetup/win95upg/common/migutil](../../base/ntsetup/win95upg/common/migutil) | 36 | [base/ntsetup/win95upg/common/migutil/sources](../../base/ntsetup/win95upg/common/migutil/sources), [base/ntsetup/win95upg/common/migutil/makefile](../../base/ntsetup/win95upg/common/migutil/makefile) | `migutil` | `LIBRARY` |
| [base/ntsetup/win95upg/common/progbar](../../base/ntsetup/win95upg/common/progbar) | 4 | [base/ntsetup/win95upg/common/progbar/sources](../../base/ntsetup/win95upg/common/progbar/sources), [base/ntsetup/win95upg/common/progbar/makefile](../../base/ntsetup/win95upg/common/progbar/makefile) | `progbar` | `LIBRARY` |
| [base/ntsetup/win95upg/common/regw32d](../../base/ntsetup/win95upg/common/regw32d) | 40 | [base/ntsetup/win95upg/common/regw32d/sources](../../base/ntsetup/win95upg/common/regw32d/sources), [base/ntsetup/win95upg/common/regw32d/makefile](../../base/ntsetup/win95upg/common/regw32d/makefile) | `regw32d` | `LIBRARY` |
| [base/ntsetup/win95upg/common/snapshot](../../base/ntsetup/win95upg/common/snapshot) | 4 | [base/ntsetup/win95upg/common/snapshot/sources](../../base/ntsetup/win95upg/common/snapshot/sources), [base/ntsetup/win95upg/common/snapshot/makefile](../../base/ntsetup/win95upg/common/snapshot/makefile) | `snapshot` | `LIBRARY` |
| [base/ntsetup/win95upg/common/win95reg](../../base/ntsetup/win95upg/common/win95reg) | 6 | [base/ntsetup/win95upg/common/win95reg/sources](../../base/ntsetup/win95upg/common/win95reg/sources), [base/ntsetup/win95upg/common/win95reg/makefile](../../base/ntsetup/win95upg/common/win95reg/makefile) | `win95reg` | `LIBRARY` |
| [base/ntsetup/win95upg/dvdcheck](../../base/ntsetup/win95upg/dvdcheck) | 2 | [base/ntsetup/win95upg/dvdcheck/dirs](../../base/ntsetup/win95upg/dvdcheck/dirs) | — | — |
| [base/ntsetup/win95upg/dvdcheck/dvdcheck](../../base/ntsetup/win95upg/dvdcheck/dvdcheck) | 6 | [base/ntsetup/win95upg/dvdcheck/dvdcheck/sources](../../base/ntsetup/win95upg/dvdcheck/dvdcheck/sources), [base/ntsetup/win95upg/dvdcheck/dvdcheck/makefile](../../base/ntsetup/win95upg/dvdcheck/dvdcheck/makefile) | `dvdcheck` | `PROGRAM` |
| [base/ntsetup/win95upg/dvdcheck/dvddetect](../../base/ntsetup/win95upg/dvdcheck/dvddetect) | 6 | [base/ntsetup/win95upg/dvdcheck/dvddetect/sources](../../base/ntsetup/win95upg/dvdcheck/dvddetect/sources), [base/ntsetup/win95upg/dvdcheck/dvddetect/makefile](../../base/ntsetup/win95upg/dvdcheck/dvddetect/makefile) | `dvddetect` | `LIBRARY` |
| [base/ntsetup/win95upg/dvdcheck/dvdupgrd](../../base/ntsetup/win95upg/dvdcheck/dvdupgrd) | 9 | [base/ntsetup/win95upg/dvdcheck/dvdupgrd/sources](../../base/ntsetup/win95upg/dvdcheck/dvdupgrd/sources), [base/ntsetup/win95upg/dvdcheck/dvdupgrd/makefile](../../base/ntsetup/win95upg/dvdcheck/dvdupgrd/makefile) | `dvdupgrd` | `PROGRAM` |
| [base/ntsetup/win95upg/inc](../../base/ntsetup/win95upg/inc) | 72 | — | — | — |
| [base/ntsetup/win95upg/lnkstub](../../base/ntsetup/win95upg/lnkstub) | 9 | [base/ntsetup/win95upg/lnkstub/sources](../../base/ntsetup/win95upg/lnkstub/sources), [base/ntsetup/win95upg/lnkstub/makefile](../../base/ntsetup/win95upg/lnkstub/makefile) | `lnkstub` | `PROGRAM` |
| [base/ntsetup/win95upg/migdlls](../../base/ntsetup/win95upg/migdlls) | 2 | [base/ntsetup/win95upg/migdlls/dirs](../../base/ntsetup/win95upg/migdlls/dirs) | — | — |
| [base/ntsetup/win95upg/migdlls/devupgrd](../../base/ntsetup/win95upg/migdlls/devupgrd) | 10 | [base/ntsetup/win95upg/migdlls/devupgrd/sources](../../base/ntsetup/win95upg/migdlls/devupgrd/sources), [base/ntsetup/win95upg/migdlls/devupgrd/makefile](../../base/ntsetup/win95upg/migdlls/devupgrd/makefile) | `migrate` | `DYNLINK` |
| [base/ntsetup/win95upg/migdlls/pview](../../base/ntsetup/win95upg/migdlls/pview) | 10 | — | — | — |
| [base/ntsetup/win95upg/migdlls/pview/nt5](../../base/ntsetup/win95upg/migdlls/pview/nt5) | 2 | — | — | — |
| [base/ntsetup/win95upg/migdlls/scrnsamp](../../base/ntsetup/win95upg/migdlls/scrnsamp) | 15 | — | — | — |
| [base/ntsetup/win95upg/migdlls/setup](../../base/ntsetup/win95upg/migdlls/setup) | 19 | [base/ntsetup/win95upg/migdlls/setup/sources](../../base/ntsetup/win95upg/migdlls/setup/sources), [base/ntsetup/win95upg/migdlls/setup/makefile](../../base/ntsetup/win95upg/migdlls/setup/makefile) | `migrate` | `DYNLINK` |
| [base/ntsetup/win95upg/migdlls/test](../../base/ntsetup/win95upg/migdlls/test) | 8 | [base/ntsetup/win95upg/migdlls/test/sources](../../base/ntsetup/win95upg/migdlls/test/sources), [base/ntsetup/win95upg/migdlls/test/makefile](../../base/ntsetup/win95upg/migdlls/test/makefile) | `migrate` | `DYNLINK` |
| [base/ntsetup/win95upg/migisol](../../base/ntsetup/win95upg/migisol) | 7 | [base/ntsetup/win95upg/migisol/sources](../../base/ntsetup/win95upg/migisol/sources), [base/ntsetup/win95upg/migisol/makefile](../../base/ntsetup/win95upg/migisol/makefile) | `migisol` | `PROGRAM` |
| [base/ntsetup/win95upg/miglib](../../base/ntsetup/win95upg/miglib) | 3 | [base/ntsetup/win95upg/miglib/sources](../../base/ntsetup/win95upg/miglib/sources), [base/ntsetup/win95upg/miglib/makefile](../../base/ntsetup/win95upg/miglib/makefile) | `miglib` | `LIBRARY` |
| [base/ntsetup/win95upg/migpwd](../../base/ntsetup/win95upg/migpwd) | 10 | [base/ntsetup/win95upg/migpwd/sources](../../base/ntsetup/win95upg/migpwd/sources), [base/ntsetup/win95upg/migpwd/makefile](../../base/ntsetup/win95upg/migpwd/makefile) | `migpwd` | `PROGRAM` |
| [base/ntsetup/win95upg/msg](../../base/ntsetup/win95upg/msg) | 8 | [base/ntsetup/win95upg/msg/sources](../../base/ntsetup/win95upg/msg/sources), [base/ntsetup/win95upg/msg/makefile](../../base/ntsetup/win95upg/msg/makefile) | `cmnmsg` | `LIBRARY` |
| [base/ntsetup/win95upg/reqdlls](../../base/ntsetup/win95upg/reqdlls) | 5 | [base/ntsetup/win95upg/reqdlls/sources](../../base/ntsetup/win95upg/reqdlls/sources), [base/ntsetup/win95upg/reqdlls/makefile](../../base/ntsetup/win95upg/reqdlls/makefile) | — | `NOTARGET` |
| [base/ntsetup/win95upg/reqdlls/i386](../../base/ntsetup/win95upg/reqdlls/i386) | 6 | — | — | — |
| [base/ntsetup/win95upg/tools](../../base/ntsetup/win95upg/tools) | 2 | [base/ntsetup/win95upg/tools/dirs](../../base/ntsetup/win95upg/tools/dirs) | — | — |
| [base/ntsetup/win95upg/tools/appc_cnv](../../base/ntsetup/win95upg/tools/appc_cnv) | 5 | [base/ntsetup/win95upg/tools/appc_cnv/sources](../../base/ntsetup/win95upg/tools/appc_cnv/sources), [base/ntsetup/win95upg/tools/appc_cnv/makefile](../../base/ntsetup/win95upg/tools/appc_cnv/makefile) | `appc_cnv` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/appc_ta](../../base/ntsetup/win95upg/tools/appc_ta) | 5 | [base/ntsetup/win95upg/tools/appc_ta/sources](../../base/ntsetup/win95upg/tools/appc_ta/sources), [base/ntsetup/win95upg/tools/appc_ta/makefile](../../base/ntsetup/win95upg/tools/appc_ta/makefile) | `appc_ta` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/appc_tu](../../base/ntsetup/win95upg/tools/appc_tu) | 5 | [base/ntsetup/win95upg/tools/appc_tu/sources](../../base/ntsetup/win95upg/tools/appc_tu/sources), [base/ntsetup/win95upg/tools/appc_tu/makefile](../../base/ntsetup/win95upg/tools/appc_tu/makefile) | `appc_tu` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/appdiff](../../base/ntsetup/win95upg/tools/appdiff) | 5 | [base/ntsetup/win95upg/tools/appdiff/sources](../../base/ntsetup/win95upg/tools/appdiff/sources), [base/ntsetup/win95upg/tools/appdiff/makefile](../../base/ntsetup/win95upg/tools/appdiff/makefile) | `appdiffu` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/appwiz](../../base/ntsetup/win95upg/tools/appwiz) | 6 | [base/ntsetup/win95upg/tools/appwiz/sources](../../base/ntsetup/win95upg/tools/appwiz/sources), [base/ntsetup/win95upg/tools/appwiz/makefile](../../base/ntsetup/win95upg/tools/appwiz/makefile) | `appwiz` | `DYNLINK` |
| [base/ntsetup/win95upg/tools/badappid](../../base/ntsetup/win95upg/tools/badappid) | 8 | [base/ntsetup/win95upg/tools/badappid/sources](../../base/ntsetup/win95upg/tools/badappid/sources), [base/ntsetup/win95upg/tools/badappid/makefile](../../base/ntsetup/win95upg/tools/badappid/makefile) | `badappid` | `DYNLINK` |
| [base/ntsetup/win95upg/tools/cmntool](../../base/ntsetup/win95upg/tools/cmntool) | 4 | [base/ntsetup/win95upg/tools/cmntool/sources](../../base/ntsetup/win95upg/tools/cmntool/sources), [base/ntsetup/win95upg/tools/cmntool/makefile](../../base/ntsetup/win95upg/tools/cmntool/makefile) | `cmntool` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/collapse](../../base/ntsetup/win95upg/tools/collapse) | 4 | [base/ntsetup/win95upg/tools/collapse/sources](../../base/ntsetup/win95upg/tools/collapse/sources), [base/ntsetup/win95upg/tools/collapse/makefile](../../base/ntsetup/win95upg/tools/collapse/makefile) | `collapse` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/cue](../../base/ntsetup/win95upg/tools/cue) | 5 | [base/ntsetup/win95upg/tools/cue/sources](../../base/ntsetup/win95upg/tools/cue/sources), [base/ntsetup/win95upg/tools/cue/makefile](../../base/ntsetup/win95upg/tools/cue/makefile) | `cue` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/datafilt](../../base/ntsetup/win95upg/tools/datafilt) | 6 | [base/ntsetup/win95upg/tools/datafilt/sources](../../base/ntsetup/win95upg/tools/datafilt/sources), [base/ntsetup/win95upg/tools/datafilt/makefile](../../base/ntsetup/win95upg/tools/datafilt/makefile) | `datafilt` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/domain](../../base/ntsetup/win95upg/tools/domain) | 6 | [base/ntsetup/win95upg/tools/domain/sources](../../base/ntsetup/win95upg/tools/domain/sources), [base/ntsetup/win95upg/tools/domain/makefile](../../base/ntsetup/win95upg/tools/domain/makefile) | `domain` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/doswiz](../../base/ntsetup/win95upg/tools/doswiz) | 7 | [base/ntsetup/win95upg/tools/doswiz/sources](../../base/ntsetup/win95upg/tools/doswiz/sources), [base/ntsetup/win95upg/tools/doswiz/makefile](../../base/ntsetup/win95upg/tools/doswiz/makefile) | `doswiz` | `DYNLINK` |
| [base/ntsetup/win95upg/tools/dynupdt](../../base/ntsetup/win95upg/tools/dynupdt) | 6 | [base/ntsetup/win95upg/tools/dynupdt/sources](../../base/ntsetup/win95upg/tools/dynupdt/sources), [base/ntsetup/win95upg/tools/dynupdt/makefile](../../base/ntsetup/win95upg/tools/dynupdt/makefile) | `dynupdt` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/enumtree](../../base/ntsetup/win95upg/tools/enumtree) | 5 | [base/ntsetup/win95upg/tools/enumtree/sources](../../base/ntsetup/win95upg/tools/enumtree/sources), [base/ntsetup/win95upg/tools/enumtree/makefile](../../base/ntsetup/win95upg/tools/enumtree/makefile) | `enumtreeu` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/exports](../../base/ntsetup/win95upg/tools/exports) | 5 | [base/ntsetup/win95upg/tools/exports/sources](../../base/ntsetup/win95upg/tools/exports/sources), [base/ntsetup/win95upg/tools/exports/makefile](../../base/ntsetup/win95upg/tools/exports/makefile) | `exports` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/extract](../../base/ntsetup/win95upg/tools/extract) | 8 | [base/ntsetup/win95upg/tools/extract/sources](../../base/ntsetup/win95upg/tools/extract/sources), [base/ntsetup/win95upg/tools/extract/makefile](../../base/ntsetup/win95upg/tools/extract/makefile) | `icontoolu` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/filegen](../../base/ntsetup/win95upg/tools/filegen) | 6 | [base/ntsetup/win95upg/tools/filegen/sources](../../base/ntsetup/win95upg/tools/filegen/sources), [base/ntsetup/win95upg/tools/filegen/makefile](../../base/ntsetup/win95upg/tools/filegen/makefile) | `filegen` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/ftp](../../base/ntsetup/win95upg/tools/ftp) | 7 | [base/ntsetup/win95upg/tools/ftp/sources](../../base/ntsetup/win95upg/tools/ftp/sources), [base/ntsetup/win95upg/tools/ftp/makefile](../../base/ntsetup/win95upg/tools/ftp/makefile) | `ftp` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/hashpwd](../../base/ntsetup/win95upg/tools/hashpwd) | 5 | [base/ntsetup/win95upg/tools/hashpwd/sources](../../base/ntsetup/win95upg/tools/hashpwd/sources), [base/ntsetup/win95upg/tools/hashpwd/makefile](../../base/ntsetup/win95upg/tools/hashpwd/makefile) | `hashpwd` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/hkcrtool](../../base/ntsetup/win95upg/tools/hkcrtool) | 5 | [base/ntsetup/win95upg/tools/hkcrtool/sources](../../base/ntsetup/win95upg/tools/hkcrtool/sources), [base/ntsetup/win95upg/tools/hkcrtool/makefile](../../base/ntsetup/win95upg/tools/hkcrtool/makefile) | `hkcrtool` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/hugecopy](../../base/ntsetup/win95upg/tools/hugecopy) | 4 | [base/ntsetup/win95upg/tools/hugecopy/sources](../../base/ntsetup/win95upg/tools/hugecopy/sources), [base/ntsetup/win95upg/tools/hugecopy/makefile](../../base/ntsetup/win95upg/tools/hugecopy/makefile) | `hugecopy` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/hwdatdmp](../../base/ntsetup/win95upg/tools/hwdatdmp) | 5 | [base/ntsetup/win95upg/tools/hwdatdmp/sources](../../base/ntsetup/win95upg/tools/hwdatdmp/sources), [base/ntsetup/win95upg/tools/hwdatdmp/makefile](../../base/ntsetup/win95upg/tools/hwdatdmp/makefile) | `hwdatdmp` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/hwdatgen](../../base/ntsetup/win95upg/tools/hwdatgen) | 6 | [base/ntsetup/win95upg/tools/hwdatgen/sources](../../base/ntsetup/win95upg/tools/hwdatgen/sources), [base/ntsetup/win95upg/tools/hwdatgen/makefile](../../base/ntsetup/win95upg/tools/hwdatgen/makefile) | `hwdatgen` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/hwwiz](../../base/ntsetup/win95upg/tools/hwwiz) | 7 | [base/ntsetup/win95upg/tools/hwwiz/sources](../../base/ntsetup/win95upg/tools/hwwiz/sources), [base/ntsetup/win95upg/tools/hwwiz/makefile](../../base/ntsetup/win95upg/tools/hwwiz/makefile) | `hwwiz` | `DYNLINK` |
| [base/ntsetup/win95upg/tools/inc](../../base/ntsetup/win95upg/tools/inc) | 2 | — | — | — |
| [base/ntsetup/win95upg/tools/initool](../../base/ntsetup/win95upg/tools/initool) | 6 | [base/ntsetup/win95upg/tools/initool/sources](../../base/ntsetup/win95upg/tools/initool/sources), [base/ntsetup/win95upg/tools/initool/makefile](../../base/ntsetup/win95upg/tools/initool/makefile) | `initool` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/isudump](../../base/ntsetup/win95upg/tools/isudump) | 4 | [base/ntsetup/win95upg/tools/isudump/sources](../../base/ntsetup/win95upg/tools/isudump/sources), [base/ntsetup/win95upg/tools/isudump/makefile](../../base/ntsetup/win95upg/tools/isudump/makefile) | `isudump` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/killfile](../../base/ntsetup/win95upg/tools/killfile) | 5 | [base/ntsetup/win95upg/tools/killfile/sources](../../base/ntsetup/win95upg/tools/killfile/sources), [base/ntsetup/win95upg/tools/killfile/makefile](../../base/ntsetup/win95upg/tools/killfile/makefile) | `killfileu` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/locinfo](../../base/ntsetup/win95upg/tools/locinfo) | 4 | [base/ntsetup/win95upg/tools/locinfo/sources](../../base/ntsetup/win95upg/tools/locinfo/sources), [base/ntsetup/win95upg/tools/locinfo/makefile](../../base/ntsetup/win95upg/tools/locinfo/makefile) | `locinfo` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/loctool](../../base/ntsetup/win95upg/tools/loctool) | 4 | [base/ntsetup/win95upg/tools/loctool/sources](../../base/ntsetup/win95upg/tools/loctool/sources), [base/ntsetup/win95upg/tools/loctool/makefile](../../base/ntsetup/win95upg/tools/loctool/makefile) | `loctool` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/lookup](../../base/ntsetup/win95upg/tools/lookup) | 10 | [base/ntsetup/win95upg/tools/lookup/sources](../../base/ntsetup/win95upg/tools/lookup/sources), [base/ntsetup/win95upg/tools/lookup/makefile](../../base/ntsetup/win95upg/tools/lookup/makefile) | `lookup` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/memdbren](../../base/ntsetup/win95upg/tools/memdbren) | 6 | [base/ntsetup/win95upg/tools/memdbren/sources](../../base/ntsetup/win95upg/tools/memdbren/sources), [base/ntsetup/win95upg/tools/memdbren/makefile](../../base/ntsetup/win95upg/tools/memdbren/makefile) | `memdbren` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/memdbt](../../base/ntsetup/win95upg/tools/memdbt) | 4 | [base/ntsetup/win95upg/tools/memdbt/sources](../../base/ntsetup/win95upg/tools/memdbt/sources), [base/ntsetup/win95upg/tools/memdbt/makefile](../../base/ntsetup/win95upg/tools/memdbt/makefile) | `memdbt` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/migfiles](../../base/ntsetup/win95upg/tools/migfiles) | 6 | [base/ntsetup/win95upg/tools/migfiles/sources](../../base/ntsetup/win95upg/tools/migfiles/sources), [base/ntsetup/win95upg/tools/migfiles/makefile](../../base/ntsetup/win95upg/tools/migfiles/makefile) | `migfiles` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/migid](../../base/ntsetup/win95upg/tools/migid) | 7 | [base/ntsetup/win95upg/tools/migid/sources](../../base/ntsetup/win95upg/tools/migid/sources), [base/ntsetup/win95upg/tools/migid/makefile](../../base/ntsetup/win95upg/tools/migid/makefile) | `migid` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/migupd](../../base/ntsetup/win95upg/tools/migupd) | 6 | [base/ntsetup/win95upg/tools/migupd/sources](../../base/ntsetup/win95upg/tools/migupd/sources), [base/ntsetup/win95upg/tools/migupd/makefile](../../base/ntsetup/win95upg/tools/migupd/makefile) | `MigUpd` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/nttool](../../base/ntsetup/win95upg/tools/nttool) | 6 | [base/ntsetup/win95upg/tools/nttool/sources](../../base/ntsetup/win95upg/tools/nttool/sources), [base/ntsetup/win95upg/tools/nttool/makefile](../../base/ntsetup/win95upg/tools/nttool/makefile) | `nttool` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/pipe](../../base/ntsetup/win95upg/tools/pipe) | 4 | [base/ntsetup/win95upg/tools/pipe/sources](../../base/ntsetup/win95upg/tools/pipe/sources), [base/ntsetup/win95upg/tools/pipe/makefile](../../base/ntsetup/win95upg/tools/pipe/makefile) | `pipe` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/pnpids](../../base/ntsetup/win95upg/tools/pnpids) | 4 | [base/ntsetup/win95upg/tools/pnpids/sources](../../base/ntsetup/win95upg/tools/pnpids/sources), [base/ntsetup/win95upg/tools/pnpids/makefile](../../base/ntsetup/win95upg/tools/pnpids/makefile) | `pnpids` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/pnprept](../../base/ntsetup/win95upg/tools/pnprept) | 5 | [base/ntsetup/win95upg/tools/pnprept/sources](../../base/ntsetup/win95upg/tools/pnprept/sources), [base/ntsetup/win95upg/tools/pnprept/makefile](../../base/ntsetup/win95upg/tools/pnprept/makefile) | `pnprept` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/rasdump](../../base/ntsetup/win95upg/tools/rasdump) | 6 | [base/ntsetup/win95upg/tools/rasdump/sources](../../base/ntsetup/win95upg/tools/rasdump/sources), [base/ntsetup/win95upg/tools/rasdump/makefile](../../base/ntsetup/win95upg/tools/rasdump/makefile) | `rasdump` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/regdmp95](../../base/ntsetup/win95upg/tools/regdmp95) | 7 | [base/ntsetup/win95upg/tools/regdmp95/sources](../../base/ntsetup/win95upg/tools/regdmp95/sources), [base/ntsetup/win95upg/tools/regdmp95/makefile](../../base/ntsetup/win95upg/tools/regdmp95/makefile) | `regdmp95` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/regdump](../../base/ntsetup/win95upg/tools/regdump) | 3 | [base/ntsetup/win95upg/tools/regdump/sources](../../base/ntsetup/win95upg/tools/regdump/sources), [base/ntsetup/win95upg/tools/regdump/makefile](../../base/ntsetup/win95upg/tools/regdump/makefile) | `regdump` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/reged95](../../base/ntsetup/win95upg/tools/reged95) | 0 | — | — | — |
| [base/ntsetup/win95upg/tools/reged95/ansi](../../base/ntsetup/win95upg/tools/reged95/ansi) | 3 | [base/ntsetup/win95upg/tools/reged95/ansi/sources](../../base/ntsetup/win95upg/tools/reged95/ansi/sources), [base/ntsetup/win95upg/tools/reged95/ansi/makefile](../../base/ntsetup/win95upg/tools/reged95/ansi/makefile) | `reged95a` | — |
| [base/ntsetup/win95upg/tools/reged95/unicode](../../base/ntsetup/win95upg/tools/reged95/unicode) | 3 | [base/ntsetup/win95upg/tools/reged95/unicode/sources](../../base/ntsetup/win95upg/tools/reged95/unicode/sources), [base/ntsetup/win95upg/tools/reged95/unicode/makefile](../../base/ntsetup/win95upg/tools/reged95/unicode/makefile) | `reged95u` | — |
| [base/ntsetup/win95upg/tools/regrep](../../base/ntsetup/win95upg/tools/regrep) | 4 | [base/ntsetup/win95upg/tools/regrep/sources](../../base/ntsetup/win95upg/tools/regrep/sources), [base/ntsetup/win95upg/tools/regrep/makefile](../../base/ntsetup/win95upg/tools/regrep/makefile) | `regrep` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/report](../../base/ntsetup/win95upg/tools/report) | 6 | [base/ntsetup/win95upg/tools/report/sources](../../base/ntsetup/win95upg/tools/report/sources), [base/ntsetup/win95upg/tools/report/makefile](../../base/ntsetup/win95upg/tools/report/makefile) | `report` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/sethashpwd](../../base/ntsetup/win95upg/tools/sethashpwd) | 5 | [base/ntsetup/win95upg/tools/sethashpwd/sources](../../base/ntsetup/win95upg/tools/sethashpwd/sources), [base/ntsetup/win95upg/tools/sethashpwd/makefile](../../base/ntsetup/win95upg/tools/sethashpwd/makefile) | `SetPwd` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/sfspace](../../base/ntsetup/win95upg/tools/sfspace) | 4 | [base/ntsetup/win95upg/tools/sfspace/sources](../../base/ntsetup/win95upg/tools/sfspace/sources), [base/ntsetup/win95upg/tools/sfspace/makefile](../../base/ntsetup/win95upg/tools/sfspace/makefile) | `sfspace` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/sharegen](../../base/ntsetup/win95upg/tools/sharegen) | 6 | [base/ntsetup/win95upg/tools/sharegen/sources](../../base/ntsetup/win95upg/tools/sharegen/sources), [base/ntsetup/win95upg/tools/sharegen/makefile](../../base/ntsetup/win95upg/tools/sharegen/makefile) | `sharegen` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/signcabs](../../base/ntsetup/win95upg/tools/signcabs) | 6 | [base/ntsetup/win95upg/tools/signcabs/sources](../../base/ntsetup/win95upg/tools/signcabs/sources), [base/ntsetup/win95upg/tools/signcabs/makefile](../../base/ntsetup/win95upg/tools/signcabs/makefile) | `signcabs` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/stftest](../../base/ntsetup/win95upg/tools/stftest) | 6 | [base/ntsetup/win95upg/tools/stftest/sources](../../base/ntsetup/win95upg/tools/stftest/sources), [base/ntsetup/win95upg/tools/stftest/makefile](../../base/ntsetup/win95upg/tools/stftest/makefile) | `stftest` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/strmap](../../base/ntsetup/win95upg/tools/strmap) | 4 | [base/ntsetup/win95upg/tools/strmap/sources](../../base/ntsetup/win95upg/tools/strmap/sources), [base/ntsetup/win95upg/tools/strmap/makefile](../../base/ntsetup/win95upg/tools/strmap/makefile) | `strmap` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/strtabs](../../base/ntsetup/win95upg/tools/strtabs) | 6 | [base/ntsetup/win95upg/tools/strtabs/sources](../../base/ntsetup/win95upg/tools/strtabs/sources), [base/ntsetup/win95upg/tools/strtabs/makefile](../../base/ntsetup/win95upg/tools/strtabs/makefile) | `strtabs` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/sysmig](../../base/ntsetup/win95upg/tools/sysmig) | 6 | [base/ntsetup/win95upg/tools/sysmig/sources](../../base/ntsetup/win95upg/tools/sysmig/sources), [base/ntsetup/win95upg/tools/sysmig/makefile](../../base/ntsetup/win95upg/tools/sysmig/makefile) | `sysmig` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/tztest](../../base/ntsetup/win95upg/tools/tztest) | 6 | [base/ntsetup/win95upg/tools/tztest/sources](../../base/ntsetup/win95upg/tools/tztest/sources), [base/ntsetup/win95upg/tools/tztest/makefile](../../base/ntsetup/win95upg/tools/tztest/makefile) | `tztest` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/upgwiz](../../base/ntsetup/win95upg/tools/upgwiz) | 9 | [base/ntsetup/win95upg/tools/upgwiz/sources](../../base/ntsetup/win95upg/tools/upgwiz/sources), [base/ntsetup/win95upg/tools/upgwiz/makefile](../../base/ntsetup/win95upg/tools/upgwiz/makefile) | `upgwiz` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/usermig](../../base/ntsetup/win95upg/tools/usermig) | 6 | [base/ntsetup/win95upg/tools/usermig/sources](../../base/ntsetup/win95upg/tools/usermig/sources), [base/ntsetup/win95upg/tools/usermig/makefile](../../base/ntsetup/win95upg/tools/usermig/makefile) | `usermig` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/utilslib](../../base/ntsetup/win95upg/tools/utilslib) | 24 | [base/ntsetup/win95upg/tools/utilslib/sources](../../base/ntsetup/win95upg/tools/utilslib/sources), [base/ntsetup/win95upg/tools/utilslib/makefile](../../base/ntsetup/win95upg/tools/utilslib/makefile) | `utils` | `LIBRARY` |
| [base/ntsetup/win95upg/tools/vcc](../../base/ntsetup/win95upg/tools/vcc) | 6 | [base/ntsetup/win95upg/tools/vcc/sources](../../base/ntsetup/win95upg/tools/vcc/sources), [base/ntsetup/win95upg/tools/vcc/makefile](../../base/ntsetup/win95upg/tools/vcc/makefile) | `vcc` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/vswiz](../../base/ntsetup/win95upg/tools/vswiz) | 7 | [base/ntsetup/win95upg/tools/vswiz/sources](../../base/ntsetup/win95upg/tools/vswiz/sources), [base/ntsetup/win95upg/tools/vswiz/makefile](../../base/ntsetup/win95upg/tools/vswiz/makefile) | `vswiz` | `DYNLINK` |
| [base/ntsetup/win95upg/tools/w9xtool](../../base/ntsetup/win95upg/tools/w9xtool) | 6 | [base/ntsetup/win95upg/tools/w9xtool/sources](../../base/ntsetup/win95upg/tools/w9xtool/sources), [base/ntsetup/win95upg/tools/w9xtool/makefile](../../base/ntsetup/win95upg/tools/w9xtool/makefile) | `w9xtool` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/winntsif](../../base/ntsetup/win95upg/tools/winntsif) | 6 | [base/ntsetup/win95upg/tools/winntsif/sources](../../base/ntsetup/win95upg/tools/winntsif/sources), [base/ntsetup/win95upg/tools/winntsif/makefile](../../base/ntsetup/win95upg/tools/winntsif/makefile) | `winntsif` | `PROGRAM` |
| [base/ntsetup/win95upg/tools/wiztools](../../base/ntsetup/win95upg/tools/wiztools) | 11 | [base/ntsetup/win95upg/tools/wiztools/sources](../../base/ntsetup/win95upg/tools/wiztools/sources), [base/ntsetup/win95upg/tools/wiztools/makefile](../../base/ntsetup/win95upg/tools/wiztools/makefile) | `wiztools` | `DYNLINK` |
| [base/ntsetup/win95upg/undo](../../base/ntsetup/win95upg/undo) | 1 | [base/ntsetup/win95upg/undo/dirs](../../base/ntsetup/win95upg/undo/dirs) | — | — |
| [base/ntsetup/win95upg/undo/dll](../../base/ntsetup/win95upg/undo/dll) | 21 | [base/ntsetup/win95upg/undo/dll/sources](../../base/ntsetup/win95upg/undo/dll/sources), [base/ntsetup/win95upg/undo/dll/makefile](../../base/ntsetup/win95upg/undo/dll/makefile) | `osuninst` | `DYNLINK` |
| [base/ntsetup/win95upg/undo/exe](../../base/ntsetup/win95upg/undo/exe) | 9 | [base/ntsetup/win95upg/undo/exe/sources](../../base/ntsetup/win95upg/undo/exe/sources), [base/ntsetup/win95upg/undo/exe/makefile](../../base/ntsetup/win95upg/undo/exe/makefile) | `OSUNINST` | `PROGRAM` |
| [base/ntsetup/win95upg/undo/pch](../../base/ntsetup/win95upg/undo/pch) | 4 | [base/ntsetup/win95upg/undo/pch/sources](../../base/ntsetup/win95upg/undo/pch/sources), [base/ntsetup/win95upg/undo/pch/makefile](../../base/ntsetup/win95upg/undo/pch/makefile) | `pch` | `LIBRARY` |
| [base/ntsetup/win95upg/w95upg](../../base/ntsetup/win95upg/w95upg) | 3 | [base/ntsetup/win95upg/w95upg/dirs](../../base/ntsetup/win95upg/w95upg/dirs) | — | — |
| [base/ntsetup/win95upg/w95upg/common9x](../../base/ntsetup/win95upg/w95upg/common9x) | 8 | [base/ntsetup/win95upg/w95upg/common9x/sources](../../base/ntsetup/win95upg/w95upg/common9x/sources), [base/ntsetup/win95upg/w95upg/common9x/makefile](../../base/ntsetup/win95upg/w95upg/common9x/makefile) | `common9x` | `LIBRARY` |
| [base/ntsetup/win95upg/w95upg/dll](../../base/ntsetup/win95upg/w95upg/dll) | 6 | [base/ntsetup/win95upg/w95upg/dll/sources](../../base/ntsetup/win95upg/w95upg/dll/sources), [base/ntsetup/win95upg/w95upg/dll/makefile](../../base/ntsetup/win95upg/w95upg/dll/makefile) | `w95upg` | `DYNLINK` |
| [base/ntsetup/win95upg/w95upg/hwcomp](../../base/ntsetup/win95upg/w95upg/hwcomp) | 9 | [base/ntsetup/win95upg/w95upg/hwcomp/sources](../../base/ntsetup/win95upg/w95upg/hwcomp/sources), [base/ntsetup/win95upg/w95upg/hwcomp/makefile](../../base/ntsetup/win95upg/w95upg/hwcomp/makefile) | `hwcomp` | `LIBRARY` |
| [base/ntsetup/win95upg/w95upg/init9x](../../base/ntsetup/win95upg/w95upg/init9x) | 6 | [base/ntsetup/win95upg/w95upg/init9x/sources](../../base/ntsetup/win95upg/w95upg/init9x/sources), [base/ntsetup/win95upg/w95upg/init9x/makefile](../../base/ntsetup/win95upg/w95upg/init9x/makefile) | `init9x` | `LIBRARY` |
| [base/ntsetup/win95upg/w95upg/migapp](../../base/ntsetup/win95upg/w95upg/migapp) | 16 | [base/ntsetup/win95upg/w95upg/migapp/sources](../../base/ntsetup/win95upg/w95upg/migapp/sources), [base/ntsetup/win95upg/w95upg/migapp/makefile](../../base/ntsetup/win95upg/w95upg/migapp/makefile) | `migapp` | `LIBRARY` |
| [base/ntsetup/win95upg/w95upg/migdll9x](../../base/ntsetup/win95upg/w95upg/migdll9x) | 5 | [base/ntsetup/win95upg/w95upg/migdll9x/sources](../../base/ntsetup/win95upg/w95upg/migdll9x/sources), [base/ntsetup/win95upg/w95upg/migdll9x/makefile](../../base/ntsetup/win95upg/w95upg/migdll9x/makefile) | `migdll9x` | `LIBRARY` |
| [base/ntsetup/win95upg/w95upg/pch](../../base/ntsetup/win95upg/w95upg/pch) | 4 | [base/ntsetup/win95upg/w95upg/pch/sources](../../base/ntsetup/win95upg/w95upg/pch/sources), [base/ntsetup/win95upg/w95upg/pch/makefile](../../base/ntsetup/win95upg/w95upg/pch/makefile) | `pch` | `LIBRARY` |
| [base/ntsetup/win95upg/w95upg/sysmig](../../base/ntsetup/win95upg/w95upg/sysmig) | 18 | [base/ntsetup/win95upg/w95upg/sysmig/sources](../../base/ntsetup/win95upg/w95upg/sysmig/sources), [base/ntsetup/win95upg/w95upg/sysmig/makefile](../../base/ntsetup/win95upg/w95upg/sysmig/makefile) | `sysmig` | `LIBRARY` |
| [base/ntsetup/win95upg/w95upg/ui](../../base/ntsetup/win95upg/w95upg/ui) | 37 | [base/ntsetup/win95upg/w95upg/ui/sources](../../base/ntsetup/win95upg/w95upg/ui/sources), [base/ntsetup/win95upg/w95upg/ui/makefile](../../base/ntsetup/win95upg/w95upg/ui/makefile) | `ui` | `LIBRARY` |
| [base/ntsetup/win95upg/w95upg/winntsif](../../base/ntsetup/win95upg/w95upg/winntsif) | 4 | [base/ntsetup/win95upg/w95upg/winntsif/sources](../../base/ntsetup/win95upg/w95upg/winntsif/sources), [base/ntsetup/win95upg/w95upg/winntsif/makefile](../../base/ntsetup/win95upg/w95upg/winntsif/makefile) | `winntsif` | `LIBRARY` |
| [base/ntsetup/win95upg/w95upgnt](../../base/ntsetup/win95upg/w95upgnt) | 3 | [base/ntsetup/win95upg/w95upgnt/dirs](../../base/ntsetup/win95upg/w95upgnt/dirs) | — | — |
| [base/ntsetup/win95upg/w95upgnt/commonnt](../../base/ntsetup/win95upg/w95upgnt/commonnt) | 4 | [base/ntsetup/win95upg/w95upgnt/commonnt/sources](../../base/ntsetup/win95upg/w95upgnt/commonnt/sources), [base/ntsetup/win95upg/w95upgnt/commonnt/makefile](../../base/ntsetup/win95upg/w95upgnt/commonnt/makefile) | `commonnt` | `LIBRARY` |
| [base/ntsetup/win95upg/w95upgnt/dll](../../base/ntsetup/win95upg/w95upgnt/dll) | 6 | [base/ntsetup/win95upg/w95upgnt/dll/sources](../../base/ntsetup/win95upg/w95upgnt/dll/sources), [base/ntsetup/win95upg/w95upgnt/dll/makefile](../../base/ntsetup/win95upg/w95upgnt/dll/makefile) | `w95upgnt` | `DYNLINK` |
| [base/ntsetup/win95upg/w95upgnt/initnt](../../base/ntsetup/win95upg/w95upgnt/initnt) | 3 | [base/ntsetup/win95upg/w95upgnt/initnt/sources](../../base/ntsetup/win95upg/w95upgnt/initnt/sources), [base/ntsetup/win95upg/w95upgnt/initnt/makefile](../../base/ntsetup/win95upg/w95upgnt/initnt/makefile) | `initnt` | `LIBRARY` |
| [base/ntsetup/win95upg/w95upgnt/merge](../../base/ntsetup/win95upg/w95upgnt/merge) | 8 | [base/ntsetup/win95upg/w95upgnt/merge/sources](../../base/ntsetup/win95upg/w95upgnt/merge/sources), [base/ntsetup/win95upg/w95upgnt/merge/makefile](../../base/ntsetup/win95upg/w95upgnt/merge/makefile) | `merge` | `LIBRARY` |
| [base/ntsetup/win95upg/w95upgnt/migmain](../../base/ntsetup/win95upg/w95upgnt/migmain) | 34 | [base/ntsetup/win95upg/w95upgnt/migmain/sources](../../base/ntsetup/win95upg/w95upgnt/migmain/sources), [base/ntsetup/win95upg/w95upgnt/migmain/makefile](../../base/ntsetup/win95upg/w95upgnt/migmain/makefile) | `migmain` | `LIBRARY` |
| [base/ntsetup/win95upg/w95upgnt/ntui](../../base/ntsetup/win95upg/w95upgnt/ntui) | 4 | [base/ntsetup/win95upg/w95upgnt/ntui/sources](../../base/ntsetup/win95upg/w95upgnt/ntui/sources), [base/ntsetup/win95upg/w95upgnt/ntui/makefile](../../base/ntsetup/win95upg/w95upgnt/ntui/makefile) | `ntui` | `LIBRARY` |
| [base/ntsetup/win95upg/w95upgnt/pch](../../base/ntsetup/win95upg/w95upgnt/pch) | 4 | [base/ntsetup/win95upg/w95upgnt/pch/sources](../../base/ntsetup/win95upg/w95upgnt/pch/sources), [base/ntsetup/win95upg/w95upgnt/pch/makefile](../../base/ntsetup/win95upg/w95upgnt/pch/makefile) | `pch` | `LIBRARY` |
| [base/ntsetup/win95upg/w95upgnt/rulehlpr](../../base/ntsetup/win95upg/w95upgnt/rulehlpr) | 8 | [base/ntsetup/win95upg/w95upgnt/rulehlpr/sources](../../base/ntsetup/win95upg/w95upgnt/rulehlpr/sources), [base/ntsetup/win95upg/w95upgnt/rulehlpr/makefile](../../base/ntsetup/win95upg/w95upgnt/rulehlpr/makefile) | `rulehlpr` | `LIBRARY` |
| [base/ntsetup/winbrand](../../base/ntsetup/winbrand) | 5 | [base/ntsetup/winbrand/sources](../../base/ntsetup/winbrand/sources), [base/ntsetup/winbrand/makefile](../../base/ntsetup/winbrand/makefile) | `winbrand` | `DYNLINK` |
| [base/ntsetup/winbrand/res](../../base/ntsetup/winbrand/res) | 0 | — | — | — |
| [base/ntsetup/winbrand/res/explorer_exe](../../base/ntsetup/winbrand/res/explorer_exe) | 2 | — | — | — |
| [base/ntsetup/winbrand/res/logon_scr](../../base/ntsetup/winbrand/res/logon_scr) | 2 | — | — | — |
| [base/ntsetup/winbrand/res/msgina_dll](../../base/ntsetup/winbrand/res/msgina_dll) | 8 | — | — | — |
| [base/ntsetup/winbrand/res/shell32_dll](../../base/ntsetup/winbrand/res/shell32_dll) | 4 | — | — | — |
| [base/ntsetup/winnt32](../../base/ntsetup/winnt32) | 1 | [base/ntsetup/winnt32/dirs](../../base/ntsetup/winnt32/dirs) | — | — |
| [base/ntsetup/winnt32/apmupgrd](../../base/ntsetup/winnt32/apmupgrd) | 9 | [base/ntsetup/winnt32/apmupgrd/sources](../../base/ntsetup/winnt32/apmupgrd/sources), [base/ntsetup/winnt32/apmupgrd/makefile](../../base/ntsetup/winnt32/apmupgrd/makefile) | `apmupgrd` | `DYNLINK` |
| [base/ntsetup/winnt32/boscomp](../../base/ntsetup/winnt32/boscomp) | 7 | [base/ntsetup/winnt32/boscomp/sources](../../base/ntsetup/winnt32/boscomp/sources), [base/ntsetup/winnt32/boscomp/makefile](../../base/ntsetup/winnt32/boscomp/makefile) | `boscomp` | `DYNLINK` |
| [base/ntsetup/winnt32/dll](../../base/ntsetup/winnt32/dll) | 69 | [base/ntsetup/winnt32/dll/dirs](../../base/ntsetup/winnt32/dll/dirs) | — | — |
| [base/ntsetup/winnt32/dll/amd64](../../base/ntsetup/winnt32/dll/amd64) | 7 | [base/ntsetup/winnt32/dll/amd64/sources](../../base/ntsetup/winnt32/dll/amd64/sources) | — | — |
| [base/ntsetup/winnt32/dll/ansi](../../base/ntsetup/winnt32/dll/ansi) | 4 | [base/ntsetup/winnt32/dll/ansi/sources](../../base/ntsetup/winnt32/dll/ansi/sources), [base/ntsetup/winnt32/dll/ansi/makefile](../../base/ntsetup/winnt32/dll/ansi/makefile) | `winnt32a` | — |
| [base/ntsetup/winnt32/dll/i386](../../base/ntsetup/winnt32/dll/i386) | 9 | [base/ntsetup/winnt32/dll/i386/sources](../../base/ntsetup/winnt32/dll/i386/sources) | — | — |
| [base/ntsetup/winnt32/dll/ia64](../../base/ntsetup/winnt32/dll/ia64) | 1 | [base/ntsetup/winnt32/dll/ia64/sources](../../base/ntsetup/winnt32/dll/ia64/sources) | — | — |
| [base/ntsetup/winnt32/dll/unicode](../../base/ntsetup/winnt32/dll/unicode) | 4 | [base/ntsetup/winnt32/dll/unicode/sources](../../base/ntsetup/winnt32/dll/unicode/sources), [base/ntsetup/winnt32/dll/unicode/makefile](../../base/ntsetup/winnt32/dll/unicode/makefile) | `winnt32u` | — |
| [base/ntsetup/winnt32/exe](../../base/ntsetup/winnt32/exe) | 5 | [base/ntsetup/winnt32/exe/sources](../../base/ntsetup/winnt32/exe/sources), [base/ntsetup/winnt32/exe/makefile](../../base/ntsetup/winnt32/exe/makefile) | `winnt32` | `PROGRAM` |
| [base/ntsetup/winnt32/exe/i386](../../base/ntsetup/winnt32/exe/i386) | 4 | [base/ntsetup/winnt32/exe/i386/sources](../../base/ntsetup/winnt32/exe/i386/sources) | — | — |
| [base/ntsetup/winnt32/faulth](../../base/ntsetup/winnt32/faulth) | 8 | [base/ntsetup/winnt32/faulth/sources](../../base/ntsetup/winnt32/faulth/sources), [base/ntsetup/winnt32/faulth/makefile](../../base/ntsetup/winnt32/faulth/makefile) | `faulth` | `DYNLINK` |
| [base/ntsetup/winnt32/fsfilter](../../base/ntsetup/winnt32/fsfilter) | 8 | [base/ntsetup/winnt32/fsfilter/sources](../../base/ntsetup/winnt32/fsfilter/sources), [base/ntsetup/winnt32/fsfilter/makefile](../../base/ntsetup/winnt32/fsfilter/makefile) | `fsfilter` | `DYNLINK` |
| [base/ntsetup/winnt32/ftcomp](../../base/ntsetup/winnt32/ftcomp) | 7 | [base/ntsetup/winnt32/ftcomp/sources](../../base/ntsetup/winnt32/ftcomp/sources), [base/ntsetup/winnt32/ftcomp/makefile](../../base/ntsetup/winnt32/ftcomp/makefile) | `ftcomp` | `DYNLINK` |
| [base/ntsetup/winnt32/scripts](../../base/ntsetup/winnt32/scripts) | 3 | [base/ntsetup/winnt32/scripts/sources](../../base/ntsetup/winnt32/scripts/sources), [base/ntsetup/winnt32/scripts/makefile](../../base/ntsetup/winnt32/scripts/makefile) | — | `NOTARGET` |

## `base/pnp/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [base/pnp](../../base/pnp) | 2 | [base/pnp/dirs](../../base/pnp/dirs) | — | — |
| [base/pnp/cfgmgr32](../../base/pnp/cfgmgr32) | 21 | [base/pnp/cfgmgr32/sources](../../base/pnp/cfgmgr32/sources), [base/pnp/cfgmgr32/makefile](../../base/pnp/cfgmgr32/makefile) | `cfgmgr` | `LIBRARY` |
| [base/pnp/cfgmgrf](../../base/pnp/cfgmgrf) | 4 | [base/pnp/cfgmgrf/sources](../../base/pnp/cfgmgrf/sources), [base/pnp/cfgmgrf/makefile](../../base/pnp/cfgmgrf/makefile) | `cfgmgr32` | `DYNLINK` |
| [base/pnp/hdwwiz](../../base/pnp/hdwwiz) | 26 | [base/pnp/hdwwiz/sources](../../base/pnp/hdwwiz/sources), [base/pnp/hdwwiz/makefile](../../base/pnp/hdwwiz/makefile) | `hdwwiz` | `DYNLINK` |
| [base/pnp/hotplug](../../base/pnp/hotplug) | 28 | [base/pnp/hotplug/sources](../../base/pnp/hotplug/sources), [base/pnp/hotplug/makefile](../../base/pnp/hotplug/makefile) | `HOTPLUG` | `DYNLINK` |
| [base/pnp/idl](../../base/pnp/idl) | 6 | [base/pnp/idl/sources](../../base/pnp/idl/sources), [base/pnp/idl/makefile](../../base/pnp/idl/makefile) | — | `NOTARGET` |
| [base/pnp/inc](../../base/pnp/inc) | 3 | — | — | — |
| [base/pnp/lib](../../base/pnp/lib) | 6 | [base/pnp/lib/sources](../../base/pnp/lib/sources), [base/pnp/lib/makefile](../../base/pnp/lib/makefile) | `umpnplib` | `LIBRARY` |
| [base/pnp/newdev](../../base/pnp/newdev) | 28 | [base/pnp/newdev/sources](../../base/pnp/newdev/sources), [base/pnp/newdev/makefile](../../base/pnp/newdev/makefile) | `newdev` | `DYNLINK` |
| [base/pnp/setupapi](../../base/pnp/setupapi) | 76 | [base/pnp/setupapi/dirs](../../base/pnp/setupapi/dirs) | — | — |
| [base/pnp/setupapi/ansi](../../base/pnp/setupapi/ansi) | 6 | [base/pnp/setupapi/ansi/sources](../../base/pnp/setupapi/ansi/sources), [base/pnp/setupapi/ansi/makefile](../../base/pnp/setupapi/ansi/makefile) | `setupapi` | `NOTARGET` |
| [base/pnp/setupapi/ansi/i386](../../base/pnp/setupapi/ansi/i386) | 1 | — | — | — |
| [base/pnp/setupapi/resource](../../base/pnp/setupapi/resource) | 40 | — | — | — |
| [base/pnp/setupapi/sputils](../../base/pnp/setupapi/sputils) | 12 | [base/pnp/setupapi/sputils/dirs](../../base/pnp/setupapi/sputils/dirs) | — | — |
| [base/pnp/setupapi/sputils/ansi](../../base/pnp/setupapi/sputils/ansi) | 3 | [base/pnp/setupapi/sputils/ansi/sources](../../base/pnp/setupapi/sputils/ansi/sources), [base/pnp/setupapi/sputils/ansi/makefile](../../base/pnp/setupapi/sputils/ansi/makefile) | `sputilsa` | — |
| [base/pnp/setupapi/sputils/extended](../../base/pnp/setupapi/sputils/extended) | 3 | [base/pnp/setupapi/sputils/extended/sources](../../base/pnp/setupapi/sputils/extended/sources), [base/pnp/setupapi/sputils/extended/makefile](../../base/pnp/setupapi/sputils/extended/makefile) | `sputilsw` | — |
| [base/pnp/setupapi/sputils/unicode](../../base/pnp/setupapi/sputils/unicode) | 3 | [base/pnp/setupapi/sputils/unicode/sources](../../base/pnp/setupapi/sputils/unicode/sources), [base/pnp/setupapi/sputils/unicode/makefile](../../base/pnp/setupapi/sputils/unicode/makefile) | `sputilsu` | — |
| [base/pnp/setupapi/tools](../../base/pnp/setupapi/tools) | 1 | [base/pnp/setupapi/tools/dirs](../../base/pnp/setupapi/tools/dirs) | — | — |
| [base/pnp/setupapi/tools/cabprep](../../base/pnp/setupapi/tools/cabprep) | 5 | [base/pnp/setupapi/tools/cabprep/sources](../../base/pnp/setupapi/tools/cabprep/sources), [base/pnp/setupapi/tools/cabprep/makefile](../../base/pnp/setupapi/tools/cabprep/makefile) | `cabprep` | `PROGRAM` |
| [base/pnp/setupapi/unicode](../../base/pnp/setupapi/unicode) | 5 | [base/pnp/setupapi/unicode/sources](../../base/pnp/setupapi/unicode/sources), [base/pnp/setupapi/unicode/makefile](../../base/pnp/setupapi/unicode/makefile) | `setupapi` | — |
| [base/pnp/setupapi/wowreg32](../../base/pnp/setupapi/wowreg32) | 5 | [base/pnp/setupapi/wowreg32/sources](../../base/pnp/setupapi/wowreg32/sources), [base/pnp/setupapi/wowreg32/makefile](../../base/pnp/setupapi/wowreg32/makefile) | `wowreg32` | `PROGRAM` |
| [base/pnp/test](../../base/pnp/test) | 14 | [base/pnp/test/sources](../../base/pnp/test/sources), [base/pnp/test/makefile](../../base/pnp/test/makefile) | `cmtest` | `LIBRARY` |
| [base/pnp/test/pnptest](../../base/pnp/test/pnptest) | 1 | — | — | — |
| [base/pnp/tools](../../base/pnp/tools) | 1 | [base/pnp/tools/dirs](../../base/pnp/tools/dirs) | — | — |
| [base/pnp/tools/chnghal](../../base/pnp/tools/chnghal) | 6 | [base/pnp/tools/chnghal/sources](../../base/pnp/tools/chnghal/sources), [base/pnp/tools/chnghal/makefile](../../base/pnp/tools/chnghal/makefile) | `chnghal` | `PROGRAM` |
| [base/pnp/tools/devcon](../../base/pnp/tools/devcon) | 10 | [base/pnp/tools/devcon/sources](../../base/pnp/tools/devcon/sources), [base/pnp/tools/devcon/makefile](../../base/pnp/tools/devcon/makefile) | `devcon` | `PROGRAM` |
| [base/pnp/tools/devcon/bin](../../base/pnp/tools/devcon/bin) | 1 | — | — | — |
| [base/pnp/tools/devcon2](../../base/pnp/tools/devcon2) | 56 | [base/pnp/tools/devcon2/sources](../../base/pnp/tools/devcon2/sources), [base/pnp/tools/devcon2/makefile](../../base/pnp/tools/devcon2/makefile) | `devcon2` | `DYNLINK` |
| [base/pnp/tools/devcon2/scripts](../../base/pnp/tools/devcon2/scripts) | 17 | — | — | — |
| [base/pnp/tools/devcon2/scripts/devmgr](../../base/pnp/tools/devcon2/scripts/devmgr) | 7 | — | — | — |
| [base/pnp/tools/devprop](../../base/pnp/tools/devprop) | 6 | [base/pnp/tools/devprop/sources](../../base/pnp/tools/devprop/sources), [base/pnp/tools/devprop/makefile](../../base/pnp/tools/devprop/makefile) | `devprop` | `PROGRAM` |
| [base/pnp/tools/dock](../../base/pnp/tools/dock) | 5 | [base/pnp/tools/dock/sources](../../base/pnp/tools/dock/sources), [base/pnp/tools/dock/makefile](../../base/pnp/tools/dock/makefile) | `dock` | `PROGRAM` |
| [base/pnp/tools/drvlist](../../base/pnp/tools/drvlist) | 6 | [base/pnp/tools/drvlist/sources](../../base/pnp/tools/drvlist/sources), [base/pnp/tools/drvlist/makefile](../../base/pnp/tools/drvlist/makefile) | `drvlist` | `PROGRAM` |
| [base/pnp/tools/pnpreg](../../base/pnp/tools/pnpreg) | 4 | [base/pnp/tools/pnpreg/sources](../../base/pnp/tools/pnpreg/sources), [base/pnp/tools/pnpreg/makefile](../../base/pnp/tools/pnpreg/makefile) | `pnpreg` | `PROGRAM` |
| [base/pnp/tools/scrubber](../../base/pnp/tools/scrubber) | 6 | [base/pnp/tools/scrubber/sources](../../base/pnp/tools/scrubber/sources), [base/pnp/tools/scrubber/makefile](../../base/pnp/tools/scrubber/makefile) | `scrubber` | `PROGRAM` |
| [base/pnp/tools/stopall](../../base/pnp/tools/stopall) | 6 | [base/pnp/tools/stopall/sources](../../base/pnp/tools/stopall/sources), [base/pnp/tools/stopall/makefile](../../base/pnp/tools/stopall/makefile) | `stopall` | `PROGRAM` |
| [base/pnp/tools/stopdevs](../../base/pnp/tools/stopdevs) | 6 | [base/pnp/tools/stopdevs/sources](../../base/pnp/tools/stopdevs/sources), [base/pnp/tools/stopdevs/makefile](../../base/pnp/tools/stopdevs/makefile) | `stopdevs` | `PROGRAM` |
| [base/pnp/umpnpmgr](../../base/pnp/umpnpmgr) | 23 | [base/pnp/umpnpmgr/sources](../../base/pnp/umpnpmgr/sources), [base/pnp/umpnpmgr/makefile](../../base/pnp/umpnpmgr/makefile) | `umpnpmgr` | `DYNLINK` |

## `base/published/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [base/published](../../base/published) | 189 | [base/published/sources](../../base/published/sources), [base/published/makefile](../../base/published/makefile) | — | `LIBRARY` |
| [base/published/posix](../../base/published/posix) | 12 | — | — | — |
| [base/published/posix/sys](../../base/published/posix/sys) | 6 | — | — | — |

## `base/qfe/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [base/qfe](../../base/qfe) | 0 | — | — | — |
| [base/qfe/resourcedll](../../base/qfe/resourcedll) | 2 | [base/qfe/resourcedll/dirs](../../base/qfe/resourcedll/dirs) | — | — |
| [base/qfe/resourcedll/sp1](../../base/qfe/resourcedll/sp1) | 8 | [base/qfe/resourcedll/sp1/sources](../../base/qfe/resourcedll/sp1/sources), [base/qfe/resourcedll/sp1/makefile](../../base/qfe/resourcedll/sp1/makefile) | `sp1res` | `DYNLINK` |

## `base/remoteboot/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [base/remoteboot](../../base/remoteboot) | 1 | [base/remoteboot/dirs](../../base/remoteboot/dirs) | — | — |
| [base/remoteboot/admin](../../base/remoteboot/admin) | 78 | [base/remoteboot/admin/sources](../../base/remoteboot/admin/sources), [base/remoteboot/admin/makefile](../../base/remoteboot/admin/makefile) | `imadmui` | `DYNLINK` |
| [base/remoteboot/binaries](../../base/remoteboot/binaries) | 1 | [base/remoteboot/binaries/dirs](../../base/remoteboot/binaries/dirs) | — | — |
| [base/remoteboot/binaries/i386](../../base/remoteboot/binaries/i386) | 4 | [base/remoteboot/binaries/i386/sources](../../base/remoteboot/binaries/i386/sources), [base/remoteboot/binaries/i386/makefile](../../base/remoteboot/binaries/i386/makefile) | — | `NOTARGET` |
| [base/remoteboot/bootfloppy](../../base/remoteboot/bootfloppy) | 1 | [base/remoteboot/bootfloppy/dirs](../../base/remoteboot/bootfloppy/dirs) | — | — |
| [base/remoteboot/bootfloppy/bin](../../base/remoteboot/bootfloppy/bin) | 4 | [base/remoteboot/bootfloppy/bin/sources](../../base/remoteboot/bootfloppy/bin/sources), [base/remoteboot/bootfloppy/bin/makefile](../../base/remoteboot/bootfloppy/bin/makefile) | — | `NOTARGET` |
| [base/remoteboot/bootfloppy/src](../../base/remoteboot/bootfloppy/src) | 1 | — | — | — |
| [base/remoteboot/bootfloppy/src/bootsec](../../base/remoteboot/bootfloppy/src/bootsec) | 3 | — | — | — |
| [base/remoteboot/bootfloppy/src/bootware](../../base/remoteboot/bootfloppy/src/bootware) | 5 | — | — | — |
| [base/remoteboot/bootfloppy/src/bootware/ai](../../base/remoteboot/bootfloppy/src/bootware/ai) | 3 | — | — | — |
| [base/remoteboot/bootfloppy/src/bootware/common](../../base/remoteboot/bootfloppy/src/bootware/common) | 2 | — | — | — |
| [base/remoteboot/bootfloppy/src/bootware/include](../../base/remoteboot/bootfloppy/src/bootware/include) | 7 | — | — | — |
| [base/remoteboot/bootfloppy/src/bootware/pxe](../../base/remoteboot/bootfloppy/src/bootware/pxe) | 7 | — | — | — |
| [base/remoteboot/bootfloppy/src/bootware/tcpip](../../base/remoteboot/bootfloppy/src/bootware/tcpip) | 5 | — | — | — |
| [base/remoteboot/bootfloppy/src/language](../../base/remoteboot/bootfloppy/src/language) | 3 | — | — | — |
| [base/remoteboot/bootfloppy/src/loader](../../base/remoteboot/bootfloppy/src/loader) | 6 | — | — | — |
| [base/remoteboot/bootfloppy/src/rbfg](../../base/remoteboot/bootfloppy/src/rbfg) | 5 | — | — | — |
| [base/remoteboot/bootfloppy/src/rbfg/rbf1](../../base/remoteboot/bootfloppy/src/rbfg/rbf1) | 20 | — | — | — |
| [base/remoteboot/bootfloppy/src/rbfg/rbf2](../../base/remoteboot/bootfloppy/src/rbfg/rbf2) | 8 | — | — | — |
| [base/remoteboot/bootfloppy/src/undi](../../base/remoteboot/bootfloppy/src/undi) | 0 | — | — | — |
| [base/remoteboot/bootfloppy/src/undi/3c5x9](../../base/remoteboot/bootfloppy/src/undi/3c5x9) | 15 | — | — | — |
| [base/remoteboot/bootfloppy/src/undi/3c90x](../../base/remoteboot/bootfloppy/src/undi/3c90x) | 17 | — | — | — |
| [base/remoteboot/bootfloppy/src/undi/3c90xb](../../base/remoteboot/bootfloppy/src/undi/3c90xb) | 17 | — | — | — |
| [base/remoteboot/bootfloppy/src/undi/amd](../../base/remoteboot/bootfloppy/src/undi/amd) | 21 | — | — | — |
| [base/remoteboot/bootfloppy/src/undi/smc9432](../../base/remoteboot/bootfloppy/src/undi/smc9432) | 18 | — | — | — |
| [base/remoteboot/cleanri](../../base/remoteboot/cleanri) | 5 | [base/remoteboot/cleanri/sources](../../base/remoteboot/cleanri/sources), [base/remoteboot/cleanri/makefile](../../base/remoteboot/cleanri/makefile) | `cleanri` | `PROGRAM` |
| [base/remoteboot/clearacl](../../base/remoteboot/clearacl) | 3 | [base/remoteboot/clearacl/sources](../../base/remoteboot/clearacl/sources), [base/remoteboot/clearacl/makefile](../../base/remoteboot/clearacl/makefile) | `clearacl` | `LIBRARY` |
| [base/remoteboot/data](../../base/remoteboot/data) | 3 | [base/remoteboot/data/dirs](../../base/remoteboot/data/dirs) | — | — |
| [base/remoteboot/data/ara](../../base/remoteboot/data/ara) | 3 | [base/remoteboot/data/ara/dirs](../../base/remoteboot/data/ara/dirs) | — | — |
| [base/remoteboot/data/ara/per](../../base/remoteboot/data/ara/per) | 3 | [base/remoteboot/data/ara/per/sources](../../base/remoteboot/data/ara/per/sources), [base/remoteboot/data/ara/per/makefile](../../base/remoteboot/data/ara/per/makefile) | — | — |
| [base/remoteboot/data/ara/wks](../../base/remoteboot/data/ara/wks) | 3 | [base/remoteboot/data/ara/wks/sources](../../base/remoteboot/data/ara/wks/sources), [base/remoteboot/data/ara/wks/makefile](../../base/remoteboot/data/ara/wks/makefile) | — | — |
| [base/remoteboot/data/br](../../base/remoteboot/data/br) | 1 | [base/remoteboot/data/br/dirs](../../base/remoteboot/data/br/dirs) | — | — |
| [base/remoteboot/data/br/dat](../../base/remoteboot/data/br/dat) | 3 | [base/remoteboot/data/br/dat/sources](../../base/remoteboot/data/br/dat/sources), [base/remoteboot/data/br/dat/makefile](../../base/remoteboot/data/br/dat/makefile) | — | — |
| [base/remoteboot/data/br/ent](../../base/remoteboot/data/br/ent) | 3 | [base/remoteboot/data/br/ent/sources](../../base/remoteboot/data/br/ent/sources), [base/remoteboot/data/br/ent/makefile](../../base/remoteboot/data/br/ent/makefile) | — | — |
| [base/remoteboot/data/br/per](../../base/remoteboot/data/br/per) | 3 | [base/remoteboot/data/br/per/sources](../../base/remoteboot/data/br/per/sources), [base/remoteboot/data/br/per/makefile](../../base/remoteboot/data/br/per/makefile) | — | — |
| [base/remoteboot/data/br/srv](../../base/remoteboot/data/br/srv) | 3 | [base/remoteboot/data/br/srv/sources](../../base/remoteboot/data/br/srv/sources), [base/remoteboot/data/br/srv/makefile](../../base/remoteboot/data/br/srv/makefile) | — | — |
| [base/remoteboot/data/br/wks](../../base/remoteboot/data/br/wks) | 3 | [base/remoteboot/data/br/wks/sources](../../base/remoteboot/data/br/wks/sources), [base/remoteboot/data/br/wks/makefile](../../base/remoteboot/data/br/wks/makefile) | — | — |
| [base/remoteboot/data/chs](../../base/remoteboot/data/chs) | 1 | [base/remoteboot/data/chs/dirs](../../base/remoteboot/data/chs/dirs) | — | — |
| [base/remoteboot/data/chs/dat](../../base/remoteboot/data/chs/dat) | 3 | [base/remoteboot/data/chs/dat/sources](../../base/remoteboot/data/chs/dat/sources), [base/remoteboot/data/chs/dat/makefile](../../base/remoteboot/data/chs/dat/makefile) | — | — |
| [base/remoteboot/data/chs/ent](../../base/remoteboot/data/chs/ent) | 3 | [base/remoteboot/data/chs/ent/sources](../../base/remoteboot/data/chs/ent/sources), [base/remoteboot/data/chs/ent/makefile](../../base/remoteboot/data/chs/ent/makefile) | — | — |
| [base/remoteboot/data/chs/per](../../base/remoteboot/data/chs/per) | 3 | [base/remoteboot/data/chs/per/sources](../../base/remoteboot/data/chs/per/sources), [base/remoteboot/data/chs/per/makefile](../../base/remoteboot/data/chs/per/makefile) | — | — |
| [base/remoteboot/data/chs/srv](../../base/remoteboot/data/chs/srv) | 3 | [base/remoteboot/data/chs/srv/sources](../../base/remoteboot/data/chs/srv/sources), [base/remoteboot/data/chs/srv/makefile](../../base/remoteboot/data/chs/srv/makefile) | — | — |
| [base/remoteboot/data/chs/wks](../../base/remoteboot/data/chs/wks) | 3 | [base/remoteboot/data/chs/wks/sources](../../base/remoteboot/data/chs/wks/sources), [base/remoteboot/data/chs/wks/makefile](../../base/remoteboot/data/chs/wks/makefile) | — | — |
| [base/remoteboot/data/cht](../../base/remoteboot/data/cht) | 1 | [base/remoteboot/data/cht/dirs](../../base/remoteboot/data/cht/dirs) | — | — |
| [base/remoteboot/data/cht/dat](../../base/remoteboot/data/cht/dat) | 3 | [base/remoteboot/data/cht/dat/sources](../../base/remoteboot/data/cht/dat/sources), [base/remoteboot/data/cht/dat/makefile](../../base/remoteboot/data/cht/dat/makefile) | — | — |
| [base/remoteboot/data/cht/ent](../../base/remoteboot/data/cht/ent) | 3 | [base/remoteboot/data/cht/ent/sources](../../base/remoteboot/data/cht/ent/sources), [base/remoteboot/data/cht/ent/makefile](../../base/remoteboot/data/cht/ent/makefile) | — | — |
| [base/remoteboot/data/cht/per](../../base/remoteboot/data/cht/per) | 3 | [base/remoteboot/data/cht/per/sources](../../base/remoteboot/data/cht/per/sources), [base/remoteboot/data/cht/per/makefile](../../base/remoteboot/data/cht/per/makefile) | — | — |
| [base/remoteboot/data/cht/srv](../../base/remoteboot/data/cht/srv) | 3 | [base/remoteboot/data/cht/srv/sources](../../base/remoteboot/data/cht/srv/sources), [base/remoteboot/data/cht/srv/makefile](../../base/remoteboot/data/cht/srv/makefile) | — | — |
| [base/remoteboot/data/cht/wks](../../base/remoteboot/data/cht/wks) | 3 | [base/remoteboot/data/cht/wks/sources](../../base/remoteboot/data/cht/wks/sources), [base/remoteboot/data/cht/wks/makefile](../../base/remoteboot/data/cht/wks/makefile) | — | — |
| [base/remoteboot/data/cs](../../base/remoteboot/data/cs) | 1 | [base/remoteboot/data/cs/dirs](../../base/remoteboot/data/cs/dirs) | — | — |
| [base/remoteboot/data/cs/dat](../../base/remoteboot/data/cs/dat) | 3 | [base/remoteboot/data/cs/dat/sources](../../base/remoteboot/data/cs/dat/sources), [base/remoteboot/data/cs/dat/makefile](../../base/remoteboot/data/cs/dat/makefile) | — | — |
| [base/remoteboot/data/cs/ent](../../base/remoteboot/data/cs/ent) | 3 | [base/remoteboot/data/cs/ent/sources](../../base/remoteboot/data/cs/ent/sources), [base/remoteboot/data/cs/ent/makefile](../../base/remoteboot/data/cs/ent/makefile) | — | — |
| [base/remoteboot/data/cs/per](../../base/remoteboot/data/cs/per) | 3 | [base/remoteboot/data/cs/per/sources](../../base/remoteboot/data/cs/per/sources), [base/remoteboot/data/cs/per/makefile](../../base/remoteboot/data/cs/per/makefile) | — | — |
| [base/remoteboot/data/cs/srv](../../base/remoteboot/data/cs/srv) | 3 | [base/remoteboot/data/cs/srv/sources](../../base/remoteboot/data/cs/srv/sources), [base/remoteboot/data/cs/srv/makefile](../../base/remoteboot/data/cs/srv/makefile) | — | — |
| [base/remoteboot/data/cs/wks](../../base/remoteboot/data/cs/wks) | 3 | [base/remoteboot/data/cs/wks/sources](../../base/remoteboot/data/cs/wks/sources), [base/remoteboot/data/cs/wks/makefile](../../base/remoteboot/data/cs/wks/makefile) | — | — |
| [base/remoteboot/data/da](../../base/remoteboot/data/da) | 1 | [base/remoteboot/data/da/dirs](../../base/remoteboot/data/da/dirs) | — | — |
| [base/remoteboot/data/da/dat](../../base/remoteboot/data/da/dat) | 3 | [base/remoteboot/data/da/dat/sources](../../base/remoteboot/data/da/dat/sources), [base/remoteboot/data/da/dat/makefile](../../base/remoteboot/data/da/dat/makefile) | — | — |
| [base/remoteboot/data/da/ent](../../base/remoteboot/data/da/ent) | 3 | [base/remoteboot/data/da/ent/sources](../../base/remoteboot/data/da/ent/sources), [base/remoteboot/data/da/ent/makefile](../../base/remoteboot/data/da/ent/makefile) | — | — |
| [base/remoteboot/data/da/per](../../base/remoteboot/data/da/per) | 3 | [base/remoteboot/data/da/per/sources](../../base/remoteboot/data/da/per/sources), [base/remoteboot/data/da/per/makefile](../../base/remoteboot/data/da/per/makefile) | — | — |
| [base/remoteboot/data/da/srv](../../base/remoteboot/data/da/srv) | 3 | [base/remoteboot/data/da/srv/sources](../../base/remoteboot/data/da/srv/sources), [base/remoteboot/data/da/srv/makefile](../../base/remoteboot/data/da/srv/makefile) | — | — |
| [base/remoteboot/data/da/wks](../../base/remoteboot/data/da/wks) | 3 | [base/remoteboot/data/da/wks/sources](../../base/remoteboot/data/da/wks/sources), [base/remoteboot/data/da/wks/makefile](../../base/remoteboot/data/da/wks/makefile) | — | — |
| [base/remoteboot/data/el](../../base/remoteboot/data/el) | 1 | [base/remoteboot/data/el/dirs](../../base/remoteboot/data/el/dirs) | — | — |
| [base/remoteboot/data/el/dat](../../base/remoteboot/data/el/dat) | 3 | [base/remoteboot/data/el/dat/sources](../../base/remoteboot/data/el/dat/sources), [base/remoteboot/data/el/dat/makefile](../../base/remoteboot/data/el/dat/makefile) | — | — |
| [base/remoteboot/data/el/ent](../../base/remoteboot/data/el/ent) | 3 | [base/remoteboot/data/el/ent/sources](../../base/remoteboot/data/el/ent/sources), [base/remoteboot/data/el/ent/makefile](../../base/remoteboot/data/el/ent/makefile) | — | — |
| [base/remoteboot/data/el/per](../../base/remoteboot/data/el/per) | 3 | [base/remoteboot/data/el/per/sources](../../base/remoteboot/data/el/per/sources), [base/remoteboot/data/el/per/makefile](../../base/remoteboot/data/el/per/makefile) | — | — |
| [base/remoteboot/data/el/srv](../../base/remoteboot/data/el/srv) | 3 | [base/remoteboot/data/el/srv/sources](../../base/remoteboot/data/el/srv/sources), [base/remoteboot/data/el/srv/makefile](../../base/remoteboot/data/el/srv/makefile) | — | — |
| [base/remoteboot/data/el/wks](../../base/remoteboot/data/el/wks) | 3 | [base/remoteboot/data/el/wks/sources](../../base/remoteboot/data/el/wks/sources), [base/remoteboot/data/el/wks/makefile](../../base/remoteboot/data/el/wks/makefile) | — | — |
| [base/remoteboot/data/es](../../base/remoteboot/data/es) | 1 | [base/remoteboot/data/es/dirs](../../base/remoteboot/data/es/dirs) | — | — |
| [base/remoteboot/data/es/dat](../../base/remoteboot/data/es/dat) | 3 | [base/remoteboot/data/es/dat/sources](../../base/remoteboot/data/es/dat/sources), [base/remoteboot/data/es/dat/makefile](../../base/remoteboot/data/es/dat/makefile) | — | — |
| [base/remoteboot/data/es/ent](../../base/remoteboot/data/es/ent) | 3 | [base/remoteboot/data/es/ent/sources](../../base/remoteboot/data/es/ent/sources), [base/remoteboot/data/es/ent/makefile](../../base/remoteboot/data/es/ent/makefile) | — | — |
| [base/remoteboot/data/es/per](../../base/remoteboot/data/es/per) | 3 | [base/remoteboot/data/es/per/sources](../../base/remoteboot/data/es/per/sources), [base/remoteboot/data/es/per/makefile](../../base/remoteboot/data/es/per/makefile) | — | — |
| [base/remoteboot/data/es/srv](../../base/remoteboot/data/es/srv) | 3 | [base/remoteboot/data/es/srv/sources](../../base/remoteboot/data/es/srv/sources), [base/remoteboot/data/es/srv/makefile](../../base/remoteboot/data/es/srv/makefile) | — | — |
| [base/remoteboot/data/es/wks](../../base/remoteboot/data/es/wks) | 3 | [base/remoteboot/data/es/wks/sources](../../base/remoteboot/data/es/wks/sources), [base/remoteboot/data/es/wks/makefile](../../base/remoteboot/data/es/wks/makefile) | — | — |
| [base/remoteboot/data/fi](../../base/remoteboot/data/fi) | 1 | [base/remoteboot/data/fi/dirs](../../base/remoteboot/data/fi/dirs) | — | — |
| [base/remoteboot/data/fi/dat](../../base/remoteboot/data/fi/dat) | 3 | [base/remoteboot/data/fi/dat/sources](../../base/remoteboot/data/fi/dat/sources), [base/remoteboot/data/fi/dat/makefile](../../base/remoteboot/data/fi/dat/makefile) | — | — |
| [base/remoteboot/data/fi/ent](../../base/remoteboot/data/fi/ent) | 3 | [base/remoteboot/data/fi/ent/sources](../../base/remoteboot/data/fi/ent/sources), [base/remoteboot/data/fi/ent/makefile](../../base/remoteboot/data/fi/ent/makefile) | — | — |
| [base/remoteboot/data/fi/per](../../base/remoteboot/data/fi/per) | 3 | [base/remoteboot/data/fi/per/sources](../../base/remoteboot/data/fi/per/sources), [base/remoteboot/data/fi/per/makefile](../../base/remoteboot/data/fi/per/makefile) | — | — |
| [base/remoteboot/data/fi/srv](../../base/remoteboot/data/fi/srv) | 3 | [base/remoteboot/data/fi/srv/sources](../../base/remoteboot/data/fi/srv/sources), [base/remoteboot/data/fi/srv/makefile](../../base/remoteboot/data/fi/srv/makefile) | — | — |
| [base/remoteboot/data/fi/wks](../../base/remoteboot/data/fi/wks) | 3 | [base/remoteboot/data/fi/wks/sources](../../base/remoteboot/data/fi/wks/sources), [base/remoteboot/data/fi/wks/makefile](../../base/remoteboot/data/fi/wks/makefile) | — | — |
| [base/remoteboot/data/fr](../../base/remoteboot/data/fr) | 1 | [base/remoteboot/data/fr/dirs](../../base/remoteboot/data/fr/dirs) | — | — |
| [base/remoteboot/data/fr/dat](../../base/remoteboot/data/fr/dat) | 3 | [base/remoteboot/data/fr/dat/sources](../../base/remoteboot/data/fr/dat/sources), [base/remoteboot/data/fr/dat/makefile](../../base/remoteboot/data/fr/dat/makefile) | — | — |
| [base/remoteboot/data/fr/ent](../../base/remoteboot/data/fr/ent) | 3 | [base/remoteboot/data/fr/ent/sources](../../base/remoteboot/data/fr/ent/sources), [base/remoteboot/data/fr/ent/makefile](../../base/remoteboot/data/fr/ent/makefile) | — | — |
| [base/remoteboot/data/fr/per](../../base/remoteboot/data/fr/per) | 3 | [base/remoteboot/data/fr/per/sources](../../base/remoteboot/data/fr/per/sources), [base/remoteboot/data/fr/per/makefile](../../base/remoteboot/data/fr/per/makefile) | — | — |
| [base/remoteboot/data/fr/srv](../../base/remoteboot/data/fr/srv) | 3 | [base/remoteboot/data/fr/srv/sources](../../base/remoteboot/data/fr/srv/sources), [base/remoteboot/data/fr/srv/makefile](../../base/remoteboot/data/fr/srv/makefile) | — | — |
| [base/remoteboot/data/fr/wks](../../base/remoteboot/data/fr/wks) | 3 | [base/remoteboot/data/fr/wks/sources](../../base/remoteboot/data/fr/wks/sources), [base/remoteboot/data/fr/wks/makefile](../../base/remoteboot/data/fr/wks/makefile) | — | — |
| [base/remoteboot/data/ger](../../base/remoteboot/data/ger) | 1 | [base/remoteboot/data/ger/dirs](../../base/remoteboot/data/ger/dirs) | — | — |
| [base/remoteboot/data/ger/dat](../../base/remoteboot/data/ger/dat) | 3 | [base/remoteboot/data/ger/dat/sources](../../base/remoteboot/data/ger/dat/sources), [base/remoteboot/data/ger/dat/makefile](../../base/remoteboot/data/ger/dat/makefile) | — | — |
| [base/remoteboot/data/ger/ent](../../base/remoteboot/data/ger/ent) | 3 | [base/remoteboot/data/ger/ent/sources](../../base/remoteboot/data/ger/ent/sources), [base/remoteboot/data/ger/ent/makefile](../../base/remoteboot/data/ger/ent/makefile) | — | — |
| [base/remoteboot/data/ger/per](../../base/remoteboot/data/ger/per) | 3 | [base/remoteboot/data/ger/per/sources](../../base/remoteboot/data/ger/per/sources), [base/remoteboot/data/ger/per/makefile](../../base/remoteboot/data/ger/per/makefile) | — | — |
| [base/remoteboot/data/ger/srv](../../base/remoteboot/data/ger/srv) | 3 | [base/remoteboot/data/ger/srv/sources](../../base/remoteboot/data/ger/srv/sources), [base/remoteboot/data/ger/srv/makefile](../../base/remoteboot/data/ger/srv/makefile) | — | — |
| [base/remoteboot/data/ger/wks](../../base/remoteboot/data/ger/wks) | 3 | [base/remoteboot/data/ger/wks/sources](../../base/remoteboot/data/ger/wks/sources), [base/remoteboot/data/ger/wks/makefile](../../base/remoteboot/data/ger/wks/makefile) | — | — |
| [base/remoteboot/data/heb](../../base/remoteboot/data/heb) | 1 | [base/remoteboot/data/heb/dirs](../../base/remoteboot/data/heb/dirs) | — | — |
| [base/remoteboot/data/heb/per](../../base/remoteboot/data/heb/per) | 3 | [base/remoteboot/data/heb/per/sources](../../base/remoteboot/data/heb/per/sources), [base/remoteboot/data/heb/per/makefile](../../base/remoteboot/data/heb/per/makefile) | — | — |
| [base/remoteboot/data/heb/wks](../../base/remoteboot/data/heb/wks) | 3 | [base/remoteboot/data/heb/wks/sources](../../base/remoteboot/data/heb/wks/sources), [base/remoteboot/data/heb/wks/makefile](../../base/remoteboot/data/heb/wks/makefile) | — | — |
| [base/remoteboot/data/hu](../../base/remoteboot/data/hu) | 1 | [base/remoteboot/data/hu/dirs](../../base/remoteboot/data/hu/dirs) | — | — |
| [base/remoteboot/data/hu/dat](../../base/remoteboot/data/hu/dat) | 3 | [base/remoteboot/data/hu/dat/sources](../../base/remoteboot/data/hu/dat/sources), [base/remoteboot/data/hu/dat/makefile](../../base/remoteboot/data/hu/dat/makefile) | — | — |
| [base/remoteboot/data/hu/ent](../../base/remoteboot/data/hu/ent) | 3 | [base/remoteboot/data/hu/ent/sources](../../base/remoteboot/data/hu/ent/sources), [base/remoteboot/data/hu/ent/makefile](../../base/remoteboot/data/hu/ent/makefile) | — | — |
| [base/remoteboot/data/hu/per](../../base/remoteboot/data/hu/per) | 3 | [base/remoteboot/data/hu/per/sources](../../base/remoteboot/data/hu/per/sources), [base/remoteboot/data/hu/per/makefile](../../base/remoteboot/data/hu/per/makefile) | — | — |
| [base/remoteboot/data/hu/srv](../../base/remoteboot/data/hu/srv) | 3 | [base/remoteboot/data/hu/srv/sources](../../base/remoteboot/data/hu/srv/sources), [base/remoteboot/data/hu/srv/makefile](../../base/remoteboot/data/hu/srv/makefile) | — | — |
| [base/remoteboot/data/hu/wks](../../base/remoteboot/data/hu/wks) | 3 | [base/remoteboot/data/hu/wks/sources](../../base/remoteboot/data/hu/wks/sources), [base/remoteboot/data/hu/wks/makefile](../../base/remoteboot/data/hu/wks/makefile) | — | — |
| [base/remoteboot/data/it](../../base/remoteboot/data/it) | 1 | [base/remoteboot/data/it/dirs](../../base/remoteboot/data/it/dirs) | — | — |
| [base/remoteboot/data/it/dat](../../base/remoteboot/data/it/dat) | 3 | [base/remoteboot/data/it/dat/sources](../../base/remoteboot/data/it/dat/sources), [base/remoteboot/data/it/dat/makefile](../../base/remoteboot/data/it/dat/makefile) | — | — |
| [base/remoteboot/data/it/ent](../../base/remoteboot/data/it/ent) | 3 | [base/remoteboot/data/it/ent/sources](../../base/remoteboot/data/it/ent/sources), [base/remoteboot/data/it/ent/makefile](../../base/remoteboot/data/it/ent/makefile) | — | — |
| [base/remoteboot/data/it/per](../../base/remoteboot/data/it/per) | 3 | [base/remoteboot/data/it/per/sources](../../base/remoteboot/data/it/per/sources), [base/remoteboot/data/it/per/makefile](../../base/remoteboot/data/it/per/makefile) | — | — |
| [base/remoteboot/data/it/srv](../../base/remoteboot/data/it/srv) | 3 | [base/remoteboot/data/it/srv/sources](../../base/remoteboot/data/it/srv/sources), [base/remoteboot/data/it/srv/makefile](../../base/remoteboot/data/it/srv/makefile) | — | — |
| [base/remoteboot/data/it/wks](../../base/remoteboot/data/it/wks) | 3 | [base/remoteboot/data/it/wks/sources](../../base/remoteboot/data/it/wks/sources), [base/remoteboot/data/it/wks/makefile](../../base/remoteboot/data/it/wks/makefile) | — | — |
| [base/remoteboot/data/jpn](../../base/remoteboot/data/jpn) | 1 | [base/remoteboot/data/jpn/dirs](../../base/remoteboot/data/jpn/dirs) | — | — |
| [base/remoteboot/data/jpn/dat](../../base/remoteboot/data/jpn/dat) | 3 | [base/remoteboot/data/jpn/dat/sources](../../base/remoteboot/data/jpn/dat/sources), [base/remoteboot/data/jpn/dat/makefile](../../base/remoteboot/data/jpn/dat/makefile) | — | — |
| [base/remoteboot/data/jpn/ent](../../base/remoteboot/data/jpn/ent) | 3 | [base/remoteboot/data/jpn/ent/sources](../../base/remoteboot/data/jpn/ent/sources), [base/remoteboot/data/jpn/ent/makefile](../../base/remoteboot/data/jpn/ent/makefile) | — | — |
| [base/remoteboot/data/jpn/per](../../base/remoteboot/data/jpn/per) | 3 | [base/remoteboot/data/jpn/per/sources](../../base/remoteboot/data/jpn/per/sources), [base/remoteboot/data/jpn/per/makefile](../../base/remoteboot/data/jpn/per/makefile) | — | — |
| [base/remoteboot/data/jpn/srv](../../base/remoteboot/data/jpn/srv) | 3 | [base/remoteboot/data/jpn/srv/sources](../../base/remoteboot/data/jpn/srv/sources), [base/remoteboot/data/jpn/srv/makefile](../../base/remoteboot/data/jpn/srv/makefile) | — | — |
| [base/remoteboot/data/jpn/wks](../../base/remoteboot/data/jpn/wks) | 3 | [base/remoteboot/data/jpn/wks/sources](../../base/remoteboot/data/jpn/wks/sources), [base/remoteboot/data/jpn/wks/makefile](../../base/remoteboot/data/jpn/wks/makefile) | — | — |
| [base/remoteboot/data/kor](../../base/remoteboot/data/kor) | 1 | [base/remoteboot/data/kor/dirs](../../base/remoteboot/data/kor/dirs) | — | — |
| [base/remoteboot/data/kor/dat](../../base/remoteboot/data/kor/dat) | 3 | [base/remoteboot/data/kor/dat/sources](../../base/remoteboot/data/kor/dat/sources), [base/remoteboot/data/kor/dat/makefile](../../base/remoteboot/data/kor/dat/makefile) | — | — |
| [base/remoteboot/data/kor/ent](../../base/remoteboot/data/kor/ent) | 3 | [base/remoteboot/data/kor/ent/sources](../../base/remoteboot/data/kor/ent/sources), [base/remoteboot/data/kor/ent/makefile](../../base/remoteboot/data/kor/ent/makefile) | — | — |
| [base/remoteboot/data/kor/per](../../base/remoteboot/data/kor/per) | 3 | [base/remoteboot/data/kor/per/sources](../../base/remoteboot/data/kor/per/sources), [base/remoteboot/data/kor/per/makefile](../../base/remoteboot/data/kor/per/makefile) | — | — |
| [base/remoteboot/data/kor/srv](../../base/remoteboot/data/kor/srv) | 3 | [base/remoteboot/data/kor/srv/sources](../../base/remoteboot/data/kor/srv/sources), [base/remoteboot/data/kor/srv/makefile](../../base/remoteboot/data/kor/srv/makefile) | — | — |
| [base/remoteboot/data/kor/wks](../../base/remoteboot/data/kor/wks) | 3 | [base/remoteboot/data/kor/wks/sources](../../base/remoteboot/data/kor/wks/sources), [base/remoteboot/data/kor/wks/makefile](../../base/remoteboot/data/kor/wks/makefile) | — | — |
| [base/remoteboot/data/nl](../../base/remoteboot/data/nl) | 1 | [base/remoteboot/data/nl/dirs](../../base/remoteboot/data/nl/dirs) | — | — |
| [base/remoteboot/data/nl/dat](../../base/remoteboot/data/nl/dat) | 3 | [base/remoteboot/data/nl/dat/sources](../../base/remoteboot/data/nl/dat/sources), [base/remoteboot/data/nl/dat/makefile](../../base/remoteboot/data/nl/dat/makefile) | — | — |
| [base/remoteboot/data/nl/ent](../../base/remoteboot/data/nl/ent) | 3 | [base/remoteboot/data/nl/ent/sources](../../base/remoteboot/data/nl/ent/sources), [base/remoteboot/data/nl/ent/makefile](../../base/remoteboot/data/nl/ent/makefile) | — | — |
| [base/remoteboot/data/nl/per](../../base/remoteboot/data/nl/per) | 3 | [base/remoteboot/data/nl/per/sources](../../base/remoteboot/data/nl/per/sources), [base/remoteboot/data/nl/per/makefile](../../base/remoteboot/data/nl/per/makefile) | — | — |
| [base/remoteboot/data/nl/srv](../../base/remoteboot/data/nl/srv) | 3 | [base/remoteboot/data/nl/srv/sources](../../base/remoteboot/data/nl/srv/sources), [base/remoteboot/data/nl/srv/makefile](../../base/remoteboot/data/nl/srv/makefile) | — | — |
| [base/remoteboot/data/nl/wks](../../base/remoteboot/data/nl/wks) | 3 | [base/remoteboot/data/nl/wks/sources](../../base/remoteboot/data/nl/wks/sources), [base/remoteboot/data/nl/wks/makefile](../../base/remoteboot/data/nl/wks/makefile) | — | — |
| [base/remoteboot/data/no](../../base/remoteboot/data/no) | 1 | [base/remoteboot/data/no/dirs](../../base/remoteboot/data/no/dirs) | — | — |
| [base/remoteboot/data/no/dat](../../base/remoteboot/data/no/dat) | 3 | [base/remoteboot/data/no/dat/sources](../../base/remoteboot/data/no/dat/sources), [base/remoteboot/data/no/dat/makefile](../../base/remoteboot/data/no/dat/makefile) | — | — |
| [base/remoteboot/data/no/ent](../../base/remoteboot/data/no/ent) | 3 | [base/remoteboot/data/no/ent/sources](../../base/remoteboot/data/no/ent/sources), [base/remoteboot/data/no/ent/makefile](../../base/remoteboot/data/no/ent/makefile) | — | — |
| [base/remoteboot/data/no/per](../../base/remoteboot/data/no/per) | 3 | [base/remoteboot/data/no/per/sources](../../base/remoteboot/data/no/per/sources), [base/remoteboot/data/no/per/makefile](../../base/remoteboot/data/no/per/makefile) | — | — |
| [base/remoteboot/data/no/srv](../../base/remoteboot/data/no/srv) | 3 | [base/remoteboot/data/no/srv/sources](../../base/remoteboot/data/no/srv/sources), [base/remoteboot/data/no/srv/makefile](../../base/remoteboot/data/no/srv/makefile) | — | — |
| [base/remoteboot/data/no/wks](../../base/remoteboot/data/no/wks) | 3 | [base/remoteboot/data/no/wks/sources](../../base/remoteboot/data/no/wks/sources), [base/remoteboot/data/no/wks/makefile](../../base/remoteboot/data/no/wks/makefile) | — | — |
| [base/remoteboot/data/pl](../../base/remoteboot/data/pl) | 1 | [base/remoteboot/data/pl/dirs](../../base/remoteboot/data/pl/dirs) | — | — |
| [base/remoteboot/data/pl/dat](../../base/remoteboot/data/pl/dat) | 3 | [base/remoteboot/data/pl/dat/sources](../../base/remoteboot/data/pl/dat/sources), [base/remoteboot/data/pl/dat/makefile](../../base/remoteboot/data/pl/dat/makefile) | — | — |
| [base/remoteboot/data/pl/ent](../../base/remoteboot/data/pl/ent) | 3 | [base/remoteboot/data/pl/ent/sources](../../base/remoteboot/data/pl/ent/sources), [base/remoteboot/data/pl/ent/makefile](../../base/remoteboot/data/pl/ent/makefile) | — | — |
| [base/remoteboot/data/pl/per](../../base/remoteboot/data/pl/per) | 3 | [base/remoteboot/data/pl/per/sources](../../base/remoteboot/data/pl/per/sources), [base/remoteboot/data/pl/per/makefile](../../base/remoteboot/data/pl/per/makefile) | — | — |
| [base/remoteboot/data/pl/srv](../../base/remoteboot/data/pl/srv) | 3 | [base/remoteboot/data/pl/srv/sources](../../base/remoteboot/data/pl/srv/sources), [base/remoteboot/data/pl/srv/makefile](../../base/remoteboot/data/pl/srv/makefile) | — | — |
| [base/remoteboot/data/pl/wks](../../base/remoteboot/data/pl/wks) | 3 | [base/remoteboot/data/pl/wks/sources](../../base/remoteboot/data/pl/wks/sources), [base/remoteboot/data/pl/wks/makefile](../../base/remoteboot/data/pl/wks/makefile) | — | — |
| [base/remoteboot/data/psu](../../base/remoteboot/data/psu) | 1 | [base/remoteboot/data/psu/dirs](../../base/remoteboot/data/psu/dirs) | — | — |
| [base/remoteboot/data/psu/dat](../../base/remoteboot/data/psu/dat) | 3 | [base/remoteboot/data/psu/dat/sources](../../base/remoteboot/data/psu/dat/sources), [base/remoteboot/data/psu/dat/makefile](../../base/remoteboot/data/psu/dat/makefile) | — | — |
| [base/remoteboot/data/psu/ent](../../base/remoteboot/data/psu/ent) | 3 | [base/remoteboot/data/psu/ent/sources](../../base/remoteboot/data/psu/ent/sources), [base/remoteboot/data/psu/ent/makefile](../../base/remoteboot/data/psu/ent/makefile) | — | — |
| [base/remoteboot/data/psu/per](../../base/remoteboot/data/psu/per) | 3 | [base/remoteboot/data/psu/per/sources](../../base/remoteboot/data/psu/per/sources), [base/remoteboot/data/psu/per/makefile](../../base/remoteboot/data/psu/per/makefile) | — | — |
| [base/remoteboot/data/psu/srv](../../base/remoteboot/data/psu/srv) | 3 | [base/remoteboot/data/psu/srv/sources](../../base/remoteboot/data/psu/srv/sources), [base/remoteboot/data/psu/srv/makefile](../../base/remoteboot/data/psu/srv/makefile) | — | — |
| [base/remoteboot/data/psu/wks](../../base/remoteboot/data/psu/wks) | 3 | [base/remoteboot/data/psu/wks/sources](../../base/remoteboot/data/psu/wks/sources), [base/remoteboot/data/psu/wks/makefile](../../base/remoteboot/data/psu/wks/makefile) | — | — |
| [base/remoteboot/data/pt](../../base/remoteboot/data/pt) | 1 | [base/remoteboot/data/pt/dirs](../../base/remoteboot/data/pt/dirs) | — | — |
| [base/remoteboot/data/pt/dat](../../base/remoteboot/data/pt/dat) | 3 | [base/remoteboot/data/pt/dat/sources](../../base/remoteboot/data/pt/dat/sources), [base/remoteboot/data/pt/dat/makefile](../../base/remoteboot/data/pt/dat/makefile) | — | — |
| [base/remoteboot/data/pt/ent](../../base/remoteboot/data/pt/ent) | 3 | [base/remoteboot/data/pt/ent/sources](../../base/remoteboot/data/pt/ent/sources), [base/remoteboot/data/pt/ent/makefile](../../base/remoteboot/data/pt/ent/makefile) | — | — |
| [base/remoteboot/data/pt/per](../../base/remoteboot/data/pt/per) | 3 | [base/remoteboot/data/pt/per/sources](../../base/remoteboot/data/pt/per/sources), [base/remoteboot/data/pt/per/makefile](../../base/remoteboot/data/pt/per/makefile) | — | — |
| [base/remoteboot/data/pt/srv](../../base/remoteboot/data/pt/srv) | 3 | [base/remoteboot/data/pt/srv/sources](../../base/remoteboot/data/pt/srv/sources), [base/remoteboot/data/pt/srv/makefile](../../base/remoteboot/data/pt/srv/makefile) | — | — |
| [base/remoteboot/data/pt/wks](../../base/remoteboot/data/pt/wks) | 3 | [base/remoteboot/data/pt/wks/sources](../../base/remoteboot/data/pt/wks/sources), [base/remoteboot/data/pt/wks/makefile](../../base/remoteboot/data/pt/wks/makefile) | — | — |
| [base/remoteboot/data/ru](../../base/remoteboot/data/ru) | 1 | [base/remoteboot/data/ru/dirs](../../base/remoteboot/data/ru/dirs) | — | — |
| [base/remoteboot/data/ru/dat](../../base/remoteboot/data/ru/dat) | 3 | [base/remoteboot/data/ru/dat/sources](../../base/remoteboot/data/ru/dat/sources), [base/remoteboot/data/ru/dat/makefile](../../base/remoteboot/data/ru/dat/makefile) | — | — |
| [base/remoteboot/data/ru/ent](../../base/remoteboot/data/ru/ent) | 3 | [base/remoteboot/data/ru/ent/sources](../../base/remoteboot/data/ru/ent/sources), [base/remoteboot/data/ru/ent/makefile](../../base/remoteboot/data/ru/ent/makefile) | — | — |
| [base/remoteboot/data/ru/per](../../base/remoteboot/data/ru/per) | 3 | [base/remoteboot/data/ru/per/sources](../../base/remoteboot/data/ru/per/sources), [base/remoteboot/data/ru/per/makefile](../../base/remoteboot/data/ru/per/makefile) | — | — |
| [base/remoteboot/data/ru/srv](../../base/remoteboot/data/ru/srv) | 3 | [base/remoteboot/data/ru/srv/sources](../../base/remoteboot/data/ru/srv/sources), [base/remoteboot/data/ru/srv/makefile](../../base/remoteboot/data/ru/srv/makefile) | — | — |
| [base/remoteboot/data/ru/wks](../../base/remoteboot/data/ru/wks) | 3 | [base/remoteboot/data/ru/wks/sources](../../base/remoteboot/data/ru/wks/sources), [base/remoteboot/data/ru/wks/makefile](../../base/remoteboot/data/ru/wks/makefile) | — | — |
| [base/remoteboot/data/sv](../../base/remoteboot/data/sv) | 1 | [base/remoteboot/data/sv/dirs](../../base/remoteboot/data/sv/dirs) | — | — |
| [base/remoteboot/data/sv/dat](../../base/remoteboot/data/sv/dat) | 3 | [base/remoteboot/data/sv/dat/sources](../../base/remoteboot/data/sv/dat/sources), [base/remoteboot/data/sv/dat/makefile](../../base/remoteboot/data/sv/dat/makefile) | — | — |
| [base/remoteboot/data/sv/ent](../../base/remoteboot/data/sv/ent) | 3 | [base/remoteboot/data/sv/ent/sources](../../base/remoteboot/data/sv/ent/sources), [base/remoteboot/data/sv/ent/makefile](../../base/remoteboot/data/sv/ent/makefile) | — | — |
| [base/remoteboot/data/sv/per](../../base/remoteboot/data/sv/per) | 3 | [base/remoteboot/data/sv/per/sources](../../base/remoteboot/data/sv/per/sources), [base/remoteboot/data/sv/per/makefile](../../base/remoteboot/data/sv/per/makefile) | — | — |
| [base/remoteboot/data/sv/srv](../../base/remoteboot/data/sv/srv) | 3 | [base/remoteboot/data/sv/srv/sources](../../base/remoteboot/data/sv/srv/sources), [base/remoteboot/data/sv/srv/makefile](../../base/remoteboot/data/sv/srv/makefile) | — | — |
| [base/remoteboot/data/sv/wks](../../base/remoteboot/data/sv/wks) | 3 | [base/remoteboot/data/sv/wks/sources](../../base/remoteboot/data/sv/wks/sources), [base/remoteboot/data/sv/wks/makefile](../../base/remoteboot/data/sv/wks/makefile) | — | — |
| [base/remoteboot/data/tr](../../base/remoteboot/data/tr) | 1 | [base/remoteboot/data/tr/dirs](../../base/remoteboot/data/tr/dirs) | — | — |
| [base/remoteboot/data/tr/dat](../../base/remoteboot/data/tr/dat) | 3 | [base/remoteboot/data/tr/dat/sources](../../base/remoteboot/data/tr/dat/sources), [base/remoteboot/data/tr/dat/makefile](../../base/remoteboot/data/tr/dat/makefile) | — | — |
| [base/remoteboot/data/tr/ent](../../base/remoteboot/data/tr/ent) | 3 | [base/remoteboot/data/tr/ent/sources](../../base/remoteboot/data/tr/ent/sources), [base/remoteboot/data/tr/ent/makefile](../../base/remoteboot/data/tr/ent/makefile) | — | — |
| [base/remoteboot/data/tr/per](../../base/remoteboot/data/tr/per) | 3 | [base/remoteboot/data/tr/per/sources](../../base/remoteboot/data/tr/per/sources), [base/remoteboot/data/tr/per/makefile](../../base/remoteboot/data/tr/per/makefile) | — | — |
| [base/remoteboot/data/tr/srv](../../base/remoteboot/data/tr/srv) | 3 | [base/remoteboot/data/tr/srv/sources](../../base/remoteboot/data/tr/srv/sources), [base/remoteboot/data/tr/srv/makefile](../../base/remoteboot/data/tr/srv/makefile) | — | — |
| [base/remoteboot/data/tr/wks](../../base/remoteboot/data/tr/wks) | 3 | [base/remoteboot/data/tr/wks/sources](../../base/remoteboot/data/tr/wks/sources), [base/remoteboot/data/tr/wks/makefile](../../base/remoteboot/data/tr/wks/makefile) | — | — |
| [base/remoteboot/data/tst](../../base/remoteboot/data/tst) | 1 | [base/remoteboot/data/tst/dirs](../../base/remoteboot/data/tst/dirs) | — | — |
| [base/remoteboot/data/tst/dat](../../base/remoteboot/data/tst/dat) | 3 | [base/remoteboot/data/tst/dat/sources](../../base/remoteboot/data/tst/dat/sources), [base/remoteboot/data/tst/dat/makefile](../../base/remoteboot/data/tst/dat/makefile) | — | — |
| [base/remoteboot/data/tst/ent](../../base/remoteboot/data/tst/ent) | 3 | [base/remoteboot/data/tst/ent/sources](../../base/remoteboot/data/tst/ent/sources), [base/remoteboot/data/tst/ent/makefile](../../base/remoteboot/data/tst/ent/makefile) | — | — |
| [base/remoteboot/data/tst/per](../../base/remoteboot/data/tst/per) | 3 | [base/remoteboot/data/tst/per/sources](../../base/remoteboot/data/tst/per/sources), [base/remoteboot/data/tst/per/makefile](../../base/remoteboot/data/tst/per/makefile) | — | — |
| [base/remoteboot/data/tst/srv](../../base/remoteboot/data/tst/srv) | 3 | [base/remoteboot/data/tst/srv/sources](../../base/remoteboot/data/tst/srv/sources), [base/remoteboot/data/tst/srv/makefile](../../base/remoteboot/data/tst/srv/makefile) | — | — |
| [base/remoteboot/data/tst/wks](../../base/remoteboot/data/tst/wks) | 3 | [base/remoteboot/data/tst/wks/sources](../../base/remoteboot/data/tst/wks/sources), [base/remoteboot/data/tst/wks/makefile](../../base/remoteboot/data/tst/wks/makefile) | — | — |
| [base/remoteboot/data/usa](../../base/remoteboot/data/usa) | 3 | [base/remoteboot/data/usa/dirs](../../base/remoteboot/data/usa/dirs) | — | — |
| [base/remoteboot/data/usa/dat](../../base/remoteboot/data/usa/dat) | 3 | [base/remoteboot/data/usa/dat/sources](../../base/remoteboot/data/usa/dat/sources), [base/remoteboot/data/usa/dat/makefile](../../base/remoteboot/data/usa/dat/makefile) | — | — |
| [base/remoteboot/data/usa/ent](../../base/remoteboot/data/usa/ent) | 3 | [base/remoteboot/data/usa/ent/sources](../../base/remoteboot/data/usa/ent/sources), [base/remoteboot/data/usa/ent/makefile](../../base/remoteboot/data/usa/ent/makefile) | — | — |
| [base/remoteboot/data/usa/per](../../base/remoteboot/data/usa/per) | 3 | [base/remoteboot/data/usa/per/sources](../../base/remoteboot/data/usa/per/sources), [base/remoteboot/data/usa/per/makefile](../../base/remoteboot/data/usa/per/makefile) | — | — |
| [base/remoteboot/data/usa/srv](../../base/remoteboot/data/usa/srv) | 3 | [base/remoteboot/data/usa/srv/sources](../../base/remoteboot/data/usa/srv/sources), [base/remoteboot/data/usa/srv/makefile](../../base/remoteboot/data/usa/srv/makefile) | — | — |
| [base/remoteboot/data/usa/wks](../../base/remoteboot/data/usa/wks) | 3 | [base/remoteboot/data/usa/wks/sources](../../base/remoteboot/data/usa/wks/sources), [base/remoteboot/data/usa/wks/makefile](../../base/remoteboot/data/usa/wks/makefile) | — | — |
| [base/remoteboot/imirror](../../base/remoteboot/imirror) | 19 | [base/remoteboot/imirror/sources](../../base/remoteboot/imirror/sources), [base/remoteboot/imirror/makefile](../../base/remoteboot/imirror/makefile) | `imirror` | `DYNLINK` |
| [base/remoteboot/newrb](../../base/remoteboot/newrb) | 12 | [base/remoteboot/newrb/sources](../../base/remoteboot/newrb/sources), [base/remoteboot/newrb/makefile](../../base/remoteboot/newrb/makefile) | `newrb` | `PROGRAM` |
| [base/remoteboot/osdisp](../../base/remoteboot/osdisp) | 3 | [base/remoteboot/osdisp/sources](../../base/remoteboot/osdisp/sources), [base/remoteboot/osdisp/makefile](../../base/remoteboot/osdisp/makefile) | `osdisp` | `LIBRARY` |
| [base/remoteboot/pin](../../base/remoteboot/pin) | 3 | [base/remoteboot/pin/sources](../../base/remoteboot/pin/sources), [base/remoteboot/pin/makefile](../../base/remoteboot/pin/makefile) | `pin` | `UMAPPL_NOLIB` |
| [base/remoteboot/rbinstal](../../base/remoteboot/rbinstal) | 22 | [base/remoteboot/rbinstal/sources](../../base/remoteboot/rbinstal/sources), [base/remoteboot/rbinstal/makefile](../../base/remoteboot/rbinstal/makefile) | `rbinstal` | `PROGRAM` |
| [base/remoteboot/rbsetup](../../base/remoteboot/rbsetup) | 2 | [base/remoteboot/rbsetup/dirs](../../base/remoteboot/rbsetup/dirs) | — | — |
| [base/remoteboot/rbsetup/client](../../base/remoteboot/rbsetup/client) | 10 | [base/remoteboot/rbsetup/client/sources](../../base/remoteboot/rbsetup/client/sources), [base/remoteboot/rbsetup/client/makefile](../../base/remoteboot/rbsetup/client/makefile) | `rbclient` | `PROGRAM` |
| [base/remoteboot/rbsetup/server](../../base/remoteboot/rbsetup/server) | 31 | [base/remoteboot/rbsetup/server/sources](../../base/remoteboot/rbsetup/server/sources), [base/remoteboot/rbsetup/server/makefile](../../base/remoteboot/rbsetup/server/makefile) | `risetup` | `PROGRAM` |
| [base/remoteboot/rbsetup/server/i386](../../base/remoteboot/rbsetup/server/i386) | 2 | [base/remoteboot/rbsetup/server/i386/sources](../../base/remoteboot/rbsetup/server/i386/sources) | — | — |
| [base/remoteboot/rcc](../../base/remoteboot/rcc) | 1 | [base/remoteboot/rcc/dirs](../../base/remoteboot/rcc/dirs) | — | — |
| [base/remoteboot/rcc/cpuhold](../../base/remoteboot/rcc/cpuhold) | 5 | [base/remoteboot/rcc/cpuhold/sources](../../base/remoteboot/rcc/cpuhold/sources), [base/remoteboot/rcc/cpuhold/makefile](../../base/remoteboot/rcc/cpuhold/makefile) | `cpuhold` | `PROGRAM` |
| [base/remoteboot/rcc/inc](../../base/remoteboot/rcc/inc) | 1 | — | — | — |
| [base/remoteboot/rcc/lib](../../base/remoteboot/rcc/lib) | 7 | [base/remoteboot/rcc/lib/sources](../../base/remoteboot/rcc/lib/sources), [base/remoteboot/rcc/lib/makefile](../../base/remoteboot/rcc/lib/makefile) | `rcclib` | `LIBRARY` |
| [base/remoteboot/rcc/net](../../base/remoteboot/rcc/net) | 1 | [base/remoteboot/rcc/net/dirs](../../base/remoteboot/rcc/net/dirs) | — | — |
| [base/remoteboot/rcc/net/client](../../base/remoteboot/rcc/net/client) | 5 | [base/remoteboot/rcc/net/client/sources](../../base/remoteboot/rcc/net/client/sources), [base/remoteboot/rcc/net/client/makefile](../../base/remoteboot/rcc/net/client/makefile) | `rccclnt` | `DYNLINK` |
| [base/remoteboot/rcc/net/client/testexe](../../base/remoteboot/rcc/net/client/testexe) | 4 | [base/remoteboot/rcc/net/client/testexe/sources](../../base/remoteboot/rcc/net/client/testexe/sources), [base/remoteboot/rcc/net/client/testexe/makefile](../../base/remoteboot/rcc/net/client/testexe/makefile) | `rcccl` | `PROGRAM` |
| [base/remoteboot/rcc/net/server](../../base/remoteboot/rcc/net/server) | 6 | [base/remoteboot/rcc/net/server/sources](../../base/remoteboot/rcc/net/server/sources), [base/remoteboot/rcc/net/server/makefile](../../base/remoteboot/rcc/net/server/makefile) | `rccnet` | `PROGRAM` |
| [base/remoteboot/rcc/serial](../../base/remoteboot/rcc/serial) | 6 | [base/remoteboot/rcc/serial/sources](../../base/remoteboot/rcc/serial/sources), [base/remoteboot/rcc/serial/makefile](../../base/remoteboot/rcc/serial/makefile) | `rccser` | `PROGRAM` |
| [base/remoteboot/rigpsnap](../../base/remoteboot/rigpsnap) | 26 | [base/remoteboot/rigpsnap/sources](../../base/remoteboot/rigpsnap/sources), [base/remoteboot/rigpsnap/makefile](../../base/remoteboot/rigpsnap/makefile) | `rigpsnap` | `DYNLINK` |
| [base/remoteboot/riprep](../../base/remoteboot/riprep) | 54 | [base/remoteboot/riprep/sources](../../base/remoteboot/riprep/sources), [base/remoteboot/riprep/makefile](../../base/remoteboot/riprep/makefile) | `riprep` | `PROGLIB` |
| [base/remoteboot/riprep/inf](../../base/remoteboot/riprep/inf) | 1 | — | — | — |
| [base/remoteboot/screens](../../base/remoteboot/screens) | 67 | [base/remoteboot/screens/sources](../../base/remoteboot/screens/sources), [base/remoteboot/screens/makefile](../../base/remoteboot/screens/makefile) | — | `NOTARGET` |
| [base/remoteboot/showacl](../../base/remoteboot/showacl) | 3 | [base/remoteboot/showacl/sources](../../base/remoteboot/showacl/sources), [base/remoteboot/showacl/makefile](../../base/remoteboot/showacl/makefile) | `showacl` | `LIBRARY` |
| [base/remoteboot/udplogin](../../base/remoteboot/udplogin) | 3 | [base/remoteboot/udplogin/sources](../../base/remoteboot/udplogin/sources), [base/remoteboot/udplogin/makefile](../../base/remoteboot/udplogin/makefile) | `udplogin` | `LIBRARY` |

## `base/screg/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [base/screg](../../base/screg) | 1 | [base/screg/dirs](../../base/screg/dirs) | — | — |
| [base/screg/sc](../../base/screg/sc) | 5 | [base/screg/sc/dirs](../../base/screg/sc/dirs) | — | — |
| [base/screg/sc/bootok](../../base/screg/sc/bootok) | 4 | [base/screg/sc/bootok/sources](../../base/screg/sc/bootok/sources), [base/screg/sc/bootok/makefile](../../base/screg/sc/bootok/makefile) | `bootok` | `PROGRAM` |
| [base/screg/sc/bootvrfy](../../base/screg/sc/bootvrfy) | 4 | [base/screg/sc/bootvrfy/sources](../../base/screg/sc/bootvrfy/sources), [base/screg/sc/bootvrfy/makefile](../../base/screg/sc/bootvrfy/makefile) | `bootvrfy` | `PROGRAM` |
| [base/screg/sc/client](../../base/screg/sc/client) | 12 | [base/screg/sc/client/sources](../../base/screg/sc/client/sources), [base/screg/sc/client/makefile](../../base/screg/sc/client/makefile) | `svcctrl` | `LIBRARY` |
| [base/screg/sc/inc](../../base/screg/sc/inc) | 11 | — | — | — |
| [base/screg/sc/lib](../../base/screg/sc/lib) | 12 | [base/screg/sc/lib/sources](../../base/screg/sc/lib/sources), [base/screg/sc/lib/makefile](../../base/screg/sc/lib/makefile) | `sclib` | `LIBRARY` |
| [base/screg/sc/ntsdexts](../../base/screg/sc/ntsdexts) | 6 | [base/screg/sc/ntsdexts/sources](../../base/screg/sc/ntsdexts/sources), [base/screg/sc/ntsdexts/makefile](../../base/screg/sc/ntsdexts/makefile) | `scexts` | `DYNLINK` |
| [base/screg/sc/sc](../../base/screg/sc/sc) | 6 | [base/screg/sc/sc/sources](../../base/screg/sc/sc/sources), [base/screg/sc/sc/makefile](../../base/screg/sc/sc/makefile) | `sc` | `PROGRAM` |
| [base/screg/sc/sctest](../../base/screg/sc/sctest) | 6 | [base/screg/sc/sctest/sources](../../base/screg/sc/sctest/sources), [base/screg/sc/sctest/makefile](../../base/screg/sc/sctest/makefile) | `apitest` | `PROGRAM` |
| [base/screg/sc/server](../../base/screg/sc/server) | 49 | [base/screg/sc/server/sources](../../base/screg/sc/server/sources), [base/screg/sc/server/makefile](../../base/screg/sc/server/makefile) | `services` | `PROGRAM` |
| [base/screg/sc/simservice](../../base/screg/sc/simservice) | 3 | [base/screg/sc/simservice/sources](../../base/screg/sc/simservice/sources), [base/screg/sc/simservice/makefile](../../base/screg/sc/simservice/makefile) | `simservice` | `PROGRAM` |
| [base/screg/sc/svchost](../../base/screg/sc/svchost) | 17 | [base/screg/sc/svchost/sources](../../base/screg/sc/svchost/sources), [base/screg/sc/svchost/makefile](../../base/screg/sc/svchost/makefile) | `svchost` | `PROGRAM` |
| [base/screg/sc/svchost/sample](../../base/screg/sc/svchost/sample) | 2 | [base/screg/sc/svchost/sample/dirs](../../base/screg/sc/svchost/sample/dirs) | — | — |
| [base/screg/sc/svchost/sample/client](../../base/screg/sc/svchost/sample/client) | 9 | [base/screg/sc/svchost/sample/client/sources](../../base/screg/sc/svchost/sample/client/sources), [base/screg/sc/svchost/sample/client/makefile](../../base/screg/sc/svchost/sample/client/makefile) | `sampcli` | `DYNLINK` |
| [base/screg/sc/svchost/sample/inc](../../base/screg/sc/svchost/sample/inc) | 1 | — | — | — |
| [base/screg/sc/svchost/sample/pch](../../base/screg/sc/svchost/sample/pch) | 2 | [base/screg/sc/svchost/sample/pch/sources](../../base/screg/sc/svchost/sample/pch/sources), [base/screg/sc/svchost/sample/pch/makefile](../../base/screg/sc/svchost/sample/pch/makefile) | `pch` | `LIBRARY` |
| [base/screg/sc/svchost/sample/server](../../base/screg/sc/svchost/sample/server) | 10 | [base/screg/sc/svchost/sample/server/sources](../../base/screg/sc/svchost/sample/server/sources), [base/screg/sc/svchost/sample/server/makefile](../../base/screg/sc/svchost/sample/server/makefile) | `sampsrv` | `DYNLINK` |
| [base/screg/sc/svcslib](../../base/screg/sc/svcslib) | 4 | [base/screg/sc/svcslib/sources](../../base/screg/sc/svcslib/sources), [base/screg/sc/svcslib/makefile](../../base/screg/sc/svcslib/makefile) | `svcslib` | `LIBRARY` |
| [base/screg/winreg](../../base/screg/winreg) | 7 | [base/screg/winreg/dirs](../../base/screg/winreg/dirs) | — | — |
| [base/screg/winreg/client](../../base/screg/winreg/client) | 25 | [base/screg/winreg/client/sources](../../base/screg/winreg/client/sources), [base/screg/winreg/client/makefile](../../base/screg/winreg/client/makefile) | `winreg` | `LIBRARY` |
| [base/screg/winreg/cntrtext](../../base/screg/winreg/cntrtext) | 2 | [base/screg/winreg/cntrtext/dirs](../../base/screg/winreg/cntrtext/dirs) | — | — |
| [base/screg/winreg/cntrtext/common](../../base/screg/winreg/cntrtext/common) | 18 | [base/screg/winreg/cntrtext/common/sources](../../base/screg/winreg/cntrtext/common/sources), [base/screg/winreg/cntrtext/common/makefile](../../base/screg/winreg/cntrtext/common/makefile) | `loadperf` | `DYNLINK` |
| [base/screg/winreg/cntrtext/ctrlist](../../base/screg/winreg/cntrtext/ctrlist) | 4 | [base/screg/winreg/cntrtext/ctrlist/sources](../../base/screg/winreg/cntrtext/ctrlist/sources), [base/screg/winreg/cntrtext/ctrlist/makefile](../../base/screg/winreg/cntrtext/ctrlist/makefile) | `ctrlist` | `PROGRAM` |
| [base/screg/winreg/cntrtext/initodat](../../base/screg/winreg/cntrtext/initodat) | 10 | [base/screg/winreg/cntrtext/initodat/sources](../../base/screg/winreg/cntrtext/initodat/sources), [base/screg/winreg/cntrtext/initodat/makefile](../../base/screg/winreg/cntrtext/initodat/makefile) | `initodat` | `PROGRAM` |
| [base/screg/winreg/cntrtext/lodctr](../../base/screg/winreg/cntrtext/lodctr) | 4 | [base/screg/winreg/cntrtext/lodctr/sources](../../base/screg/winreg/cntrtext/lodctr/sources), [base/screg/winreg/cntrtext/lodctr/makefile](../../base/screg/winreg/cntrtext/lodctr/makefile) | `lodctr` | `PROGRAM` |
| [base/screg/winreg/cntrtext/perfini](../../base/screg/winreg/cntrtext/perfini) | 4 | [base/screg/winreg/cntrtext/perfini/dirs](../../base/screg/winreg/cntrtext/perfini/dirs) | — | — |
| [base/screg/winreg/cntrtext/perfini/ara](../../base/screg/winreg/cntrtext/perfini/ara) | 5 | [base/screg/winreg/cntrtext/perfini/ara/sources](../../base/screg/winreg/cntrtext/perfini/ara/sources), [base/screg/winreg/cntrtext/perfini/ara/makefile](../../base/screg/winreg/cntrtext/perfini/ara/makefile) | — | — |
| [base/screg/winreg/cntrtext/perfini/br](../../base/screg/winreg/cntrtext/perfini/br) | 5 | [base/screg/winreg/cntrtext/perfini/br/sources](../../base/screg/winreg/cntrtext/perfini/br/sources), [base/screg/winreg/cntrtext/perfini/br/makefile](../../base/screg/winreg/cntrtext/perfini/br/makefile) | — | — |
| [base/screg/winreg/cntrtext/perfini/chs](../../base/screg/winreg/cntrtext/perfini/chs) | 5 | [base/screg/winreg/cntrtext/perfini/chs/sources](../../base/screg/winreg/cntrtext/perfini/chs/sources), [base/screg/winreg/cntrtext/perfini/chs/makefile](../../base/screg/winreg/cntrtext/perfini/chs/makefile) | — | — |
| [base/screg/winreg/cntrtext/perfini/cht](../../base/screg/winreg/cntrtext/perfini/cht) | 5 | [base/screg/winreg/cntrtext/perfini/cht/sources](../../base/screg/winreg/cntrtext/perfini/cht/sources), [base/screg/winreg/cntrtext/perfini/cht/makefile](../../base/screg/winreg/cntrtext/perfini/cht/makefile) | — | — |
| [base/screg/winreg/cntrtext/perfini/cs](../../base/screg/winreg/cntrtext/perfini/cs) | 5 | [base/screg/winreg/cntrtext/perfini/cs/sources](../../base/screg/winreg/cntrtext/perfini/cs/sources), [base/screg/winreg/cntrtext/perfini/cs/makefile](../../base/screg/winreg/cntrtext/perfini/cs/makefile) | — | — |
| [base/screg/winreg/cntrtext/perfini/da](../../base/screg/winreg/cntrtext/perfini/da) | 5 | [base/screg/winreg/cntrtext/perfini/da/sources](../../base/screg/winreg/cntrtext/perfini/da/sources), [base/screg/winreg/cntrtext/perfini/da/makefile](../../base/screg/winreg/cntrtext/perfini/da/makefile) | — | — |
| [base/screg/winreg/cntrtext/perfini/el](../../base/screg/winreg/cntrtext/perfini/el) | 5 | [base/screg/winreg/cntrtext/perfini/el/sources](../../base/screg/winreg/cntrtext/perfini/el/sources), [base/screg/winreg/cntrtext/perfini/el/makefile](../../base/screg/winreg/cntrtext/perfini/el/makefile) | — | — |
| [base/screg/winreg/cntrtext/perfini/es](../../base/screg/winreg/cntrtext/perfini/es) | 5 | [base/screg/winreg/cntrtext/perfini/es/sources](../../base/screg/winreg/cntrtext/perfini/es/sources), [base/screg/winreg/cntrtext/perfini/es/makefile](../../base/screg/winreg/cntrtext/perfini/es/makefile) | — | — |
| [base/screg/winreg/cntrtext/perfini/fi](../../base/screg/winreg/cntrtext/perfini/fi) | 5 | [base/screg/winreg/cntrtext/perfini/fi/sources](../../base/screg/winreg/cntrtext/perfini/fi/sources), [base/screg/winreg/cntrtext/perfini/fi/makefile](../../base/screg/winreg/cntrtext/perfini/fi/makefile) | — | — |
| [base/screg/winreg/cntrtext/perfini/fr](../../base/screg/winreg/cntrtext/perfini/fr) | 5 | [base/screg/winreg/cntrtext/perfini/fr/sources](../../base/screg/winreg/cntrtext/perfini/fr/sources), [base/screg/winreg/cntrtext/perfini/fr/makefile](../../base/screg/winreg/cntrtext/perfini/fr/makefile) | — | — |
| [base/screg/winreg/cntrtext/perfini/ger](../../base/screg/winreg/cntrtext/perfini/ger) | 5 | [base/screg/winreg/cntrtext/perfini/ger/sources](../../base/screg/winreg/cntrtext/perfini/ger/sources), [base/screg/winreg/cntrtext/perfini/ger/makefile](../../base/screg/winreg/cntrtext/perfini/ger/makefile) | — | — |
| [base/screg/winreg/cntrtext/perfini/heb](../../base/screg/winreg/cntrtext/perfini/heb) | 5 | [base/screg/winreg/cntrtext/perfini/heb/sources](../../base/screg/winreg/cntrtext/perfini/heb/sources), [base/screg/winreg/cntrtext/perfini/heb/makefile](../../base/screg/winreg/cntrtext/perfini/heb/makefile) | — | — |
| [base/screg/winreg/cntrtext/perfini/hu](../../base/screg/winreg/cntrtext/perfini/hu) | 5 | [base/screg/winreg/cntrtext/perfini/hu/sources](../../base/screg/winreg/cntrtext/perfini/hu/sources), [base/screg/winreg/cntrtext/perfini/hu/makefile](../../base/screg/winreg/cntrtext/perfini/hu/makefile) | — | — |
| [base/screg/winreg/cntrtext/perfini/it](../../base/screg/winreg/cntrtext/perfini/it) | 5 | [base/screg/winreg/cntrtext/perfini/it/sources](../../base/screg/winreg/cntrtext/perfini/it/sources), [base/screg/winreg/cntrtext/perfini/it/makefile](../../base/screg/winreg/cntrtext/perfini/it/makefile) | — | — |
| [base/screg/winreg/cntrtext/perfini/jpn](../../base/screg/winreg/cntrtext/perfini/jpn) | 5 | [base/screg/winreg/cntrtext/perfini/jpn/sources](../../base/screg/winreg/cntrtext/perfini/jpn/sources), [base/screg/winreg/cntrtext/perfini/jpn/makefile](../../base/screg/winreg/cntrtext/perfini/jpn/makefile) | — | — |
| [base/screg/winreg/cntrtext/perfini/kor](../../base/screg/winreg/cntrtext/perfini/kor) | 5 | [base/screg/winreg/cntrtext/perfini/kor/sources](../../base/screg/winreg/cntrtext/perfini/kor/sources), [base/screg/winreg/cntrtext/perfini/kor/makefile](../../base/screg/winreg/cntrtext/perfini/kor/makefile) | — | — |
| [base/screg/winreg/cntrtext/perfini/nl](../../base/screg/winreg/cntrtext/perfini/nl) | 5 | [base/screg/winreg/cntrtext/perfini/nl/sources](../../base/screg/winreg/cntrtext/perfini/nl/sources), [base/screg/winreg/cntrtext/perfini/nl/makefile](../../base/screg/winreg/cntrtext/perfini/nl/makefile) | — | — |
| [base/screg/winreg/cntrtext/perfini/no](../../base/screg/winreg/cntrtext/perfini/no) | 5 | [base/screg/winreg/cntrtext/perfini/no/sources](../../base/screg/winreg/cntrtext/perfini/no/sources), [base/screg/winreg/cntrtext/perfini/no/makefile](../../base/screg/winreg/cntrtext/perfini/no/makefile) | — | — |
| [base/screg/winreg/cntrtext/perfini/pl](../../base/screg/winreg/cntrtext/perfini/pl) | 5 | [base/screg/winreg/cntrtext/perfini/pl/sources](../../base/screg/winreg/cntrtext/perfini/pl/sources), [base/screg/winreg/cntrtext/perfini/pl/makefile](../../base/screg/winreg/cntrtext/perfini/pl/makefile) | — | — |
| [base/screg/winreg/cntrtext/perfini/psu](../../base/screg/winreg/cntrtext/perfini/psu) | 3 | [base/screg/winreg/cntrtext/perfini/psu/sources](../../base/screg/winreg/cntrtext/perfini/psu/sources), [base/screg/winreg/cntrtext/perfini/psu/makefile](../../base/screg/winreg/cntrtext/perfini/psu/makefile) | — | — |
| [base/screg/winreg/cntrtext/perfini/pt](../../base/screg/winreg/cntrtext/perfini/pt) | 5 | [base/screg/winreg/cntrtext/perfini/pt/sources](../../base/screg/winreg/cntrtext/perfini/pt/sources), [base/screg/winreg/cntrtext/perfini/pt/makefile](../../base/screg/winreg/cntrtext/perfini/pt/makefile) | — | — |
| [base/screg/winreg/cntrtext/perfini/ru](../../base/screg/winreg/cntrtext/perfini/ru) | 5 | [base/screg/winreg/cntrtext/perfini/ru/sources](../../base/screg/winreg/cntrtext/perfini/ru/sources), [base/screg/winreg/cntrtext/perfini/ru/makefile](../../base/screg/winreg/cntrtext/perfini/ru/makefile) | — | — |
| [base/screg/winreg/cntrtext/perfini/sv](../../base/screg/winreg/cntrtext/perfini/sv) | 5 | [base/screg/winreg/cntrtext/perfini/sv/sources](../../base/screg/winreg/cntrtext/perfini/sv/sources), [base/screg/winreg/cntrtext/perfini/sv/makefile](../../base/screg/winreg/cntrtext/perfini/sv/makefile) | — | — |
| [base/screg/winreg/cntrtext/perfini/tr](../../base/screg/winreg/cntrtext/perfini/tr) | 5 | [base/screg/winreg/cntrtext/perfini/tr/sources](../../base/screg/winreg/cntrtext/perfini/tr/sources), [base/screg/winreg/cntrtext/perfini/tr/makefile](../../base/screg/winreg/cntrtext/perfini/tr/makefile) | — | — |
| [base/screg/winreg/cntrtext/perfini/tst](../../base/screg/winreg/cntrtext/perfini/tst) | 3 | [base/screg/winreg/cntrtext/perfini/tst/sources](../../base/screg/winreg/cntrtext/perfini/tst/sources), [base/screg/winreg/cntrtext/perfini/tst/makefile](../../base/screg/winreg/cntrtext/perfini/tst/makefile) | — | — |
| [base/screg/winreg/cntrtext/perfini/usa](../../base/screg/winreg/cntrtext/perfini/usa) | 7 | [base/screg/winreg/cntrtext/perfini/usa/sources](../../base/screg/winreg/cntrtext/perfini/usa/sources), [base/screg/winreg/cntrtext/perfini/usa/makefile](../../base/screg/winreg/cntrtext/perfini/usa/makefile) | — | — |
| [base/screg/winreg/cntrtext/showperf](../../base/screg/winreg/cntrtext/showperf) | 14 | [base/screg/winreg/cntrtext/showperf/sources](../../base/screg/winreg/cntrtext/showperf/sources), [base/screg/winreg/cntrtext/showperf/makefile](../../base/screg/winreg/cntrtext/showperf/makefile) | `showperf` | `PROGRAM` |
| [base/screg/winreg/cntrtext/unlodctr](../../base/screg/winreg/cntrtext/unlodctr) | 4 | [base/screg/winreg/cntrtext/unlodctr/sources](../../base/screg/winreg/cntrtext/unlodctr/sources), [base/screg/winreg/cntrtext/unlodctr/makefile](../../base/screg/winreg/cntrtext/unlodctr/makefile) | `unlodctr` | `PROGRAM` |
| [base/screg/winreg/exts](../../base/screg/winreg/exts) | 6 | [base/screg/winreg/exts/sources](../../base/screg/winreg/exts/sources), [base/screg/winreg/exts/makefile](../../base/screg/winreg/exts/makefile) | `regexts` | `DYNLINK` |
| [base/screg/winreg/lib](../../base/screg/winreg/lib) | 3 | [base/screg/winreg/lib/sources](../../base/screg/winreg/lib/sources), [base/screg/winreg/lib/makefile](../../base/screg/winreg/lib/makefile) | `wrlib` | `LIBRARY` |
| [base/screg/winreg/local](../../base/screg/winreg/local) | 7 | [base/screg/winreg/local/sources](../../base/screg/winreg/local/sources), [base/screg/winreg/local/makefile](../../base/screg/winreg/local/makefile) | `localreg` | `LIBRARY` |
| [base/screg/winreg/perfdlls](../../base/screg/winreg/perfdlls) | 1 | [base/screg/winreg/perfdlls/dirs](../../base/screg/winreg/perfdlls/dirs) | — | — |
| [base/screg/winreg/perfdlls/common](../../base/screg/winreg/perfdlls/common) | 5 | [base/screg/winreg/perfdlls/common/sources](../../base/screg/winreg/perfdlls/common/sources), [base/screg/winreg/perfdlls/common/makefile](../../base/screg/winreg/perfdlls/common/makefile) | `perfutil` | `LIBRARY` |
| [base/screg/winreg/perfdlls/disk](../../base/screg/winreg/perfdlls/disk) | 17 | [base/screg/winreg/perfdlls/disk/sources](../../base/screg/winreg/perfdlls/disk/sources), [base/screg/winreg/perfdlls/disk/makefile](../../base/screg/winreg/perfdlls/disk/makefile) | `perfdisk` | `DYNLINK` |
| [base/screg/winreg/perfdlls/netsvcs](../../base/screg/winreg/perfdlls/netsvcs) | 20 | [base/screg/winreg/perfdlls/netsvcs/sources](../../base/screg/winreg/perfdlls/netsvcs/sources), [base/screg/winreg/perfdlls/netsvcs/makefile](../../base/screg/winreg/perfdlls/netsvcs/makefile) | `perfnet` | `DYNLINK` |
| [base/screg/winreg/perfdlls/os](../../base/screg/winreg/perfdlls/os) | 29 | [base/screg/winreg/perfdlls/os/sources](../../base/screg/winreg/perfdlls/os/sources), [base/screg/winreg/perfdlls/os/makefile](../../base/screg/winreg/perfdlls/os/makefile) | `perfos` | `DYNLINK` |
| [base/screg/winreg/perfdlls/perfctrs](../../base/screg/winreg/perfdlls/perfctrs) | 25 | [base/screg/winreg/perfdlls/perfctrs/sources](../../base/screg/winreg/perfdlls/perfctrs/sources), [base/screg/winreg/perfdlls/perfctrs/makefile](../../base/screg/winreg/perfdlls/perfctrs/makefile) | `perfctrs` | `DYNLINK` |
| [base/screg/winreg/perfdlls/process](../../base/screg/winreg/perfdlls/process) | 30 | [base/screg/winreg/perfdlls/process/sources](../../base/screg/winreg/perfdlls/process/sources), [base/screg/winreg/perfdlls/process/makefile](../../base/screg/winreg/perfdlls/process/makefile) | `perfproc` | `DYNLINK` |
| [base/screg/winreg/perflib](../../base/screg/winreg/perflib) | 11 | [base/screg/winreg/perflib/dirs](../../base/screg/winreg/perflib/dirs) | — | — |
| [base/screg/winreg/perflib/daytona](../../base/screg/winreg/perflib/daytona) | 2 | [base/screg/winreg/perflib/daytona/sources](../../base/screg/winreg/perflib/daytona/sources), [base/screg/winreg/perflib/daytona/makefile](../../base/screg/winreg/perflib/daytona/makefile) | — | — |
| [base/screg/winreg/perflib/hydra](../../base/screg/winreg/perflib/hydra) | 2 | [base/screg/winreg/perflib/hydra/sources](../../base/screg/winreg/perflib/hydra/sources), [base/screg/winreg/perflib/hydra/makefile](../../base/screg/winreg/perflib/hydra/makefile) | — | — |
| [base/screg/winreg/perflib/tests](../../base/screg/winreg/perflib/tests) | 3 | [base/screg/winreg/perflib/tests/sources](../../base/screg/winreg/perflib/tests/sources), [base/screg/winreg/perflib/tests/makefile](../../base/screg/winreg/perflib/tests/makefile) | `testperf` | `PROGRAM` |
| [base/screg/winreg/prflbmsg](../../base/screg/winreg/prflbmsg) | 6 | [base/screg/winreg/prflbmsg/sources](../../base/screg/winreg/prflbmsg/sources), [base/screg/winreg/prflbmsg/makefile](../../base/screg/winreg/prflbmsg/makefile) | `prflbmsg` | `DYNLINK` |
| [base/screg/winreg/regconn](../../base/screg/winreg/regconn) | 9 | [base/screg/winreg/regconn/sources](../../base/screg/winreg/regconn/sources), [base/screg/winreg/regconn/makefile](../../base/screg/winreg/regconn/makefile) | `regconn` | `LIBRARY` |
| [base/screg/winreg/regsvc](../../base/screg/winreg/regsvc) | 8 | [base/screg/winreg/regsvc/sources](../../base/screg/winreg/regsvc/sources), [base/screg/winreg/regsvc/makefile](../../base/screg/winreg/regsvc/makefile) | `regsvc` | `DYNLINK` |
| [base/screg/winreg/server](../../base/screg/winreg/server) | 31 | [base/screg/winreg/server/sources](../../base/screg/winreg/server/sources), [base/screg/winreg/server/makefile](../../base/screg/winreg/server/makefile) | `winreg` | `LIBRARY` |
| [base/screg/winreg/tools](../../base/screg/winreg/tools) | 1 | [base/screg/winreg/tools/dirs](../../base/screg/winreg/tools/dirs) | — | — |
| [base/screg/winreg/tools/apitest](../../base/screg/winreg/tools/apitest) | 4 | [base/screg/winreg/tools/apitest/sources](../../base/screg/winreg/tools/apitest/sources), [base/screg/winreg/tools/apitest/makefile](../../base/screg/winreg/tools/apitest/makefile) | `apitest` | `UMAPPL_NOLIB` |
| [base/screg/winreg/tools/crdel](../../base/screg/winreg/tools/crdel) | 3 | [base/screg/winreg/tools/crdel/sources](../../base/screg/winreg/tools/crdel/sources), [base/screg/winreg/tools/crdel/makefile](../../base/screg/winreg/tools/crdel/makefile) | `crdel` | `UMAPPL_NOLIB` |
| [base/screg/winreg/tools/crdump](../../base/screg/winreg/tools/crdump) | 3 | [base/screg/winreg/tools/crdump/sources](../../base/screg/winreg/tools/crdump/sources), [base/screg/winreg/tools/crdump/makefile](../../base/screg/winreg/tools/crdump/makefile) | `crdump` | `UMAPPL_NOLIB` |
| [base/screg/winreg/tools/lib](../../base/screg/winreg/tools/lib) | 1 | [base/screg/winreg/tools/lib/dirs](../../base/screg/winreg/tools/lib/dirs) | — | — |
| [base/screg/winreg/tools/lib/inc](../../base/screg/winreg/tools/lib/inc) | 1 | — | — | — |
| [base/screg/winreg/tools/lib/src](../../base/screg/winreg/tools/lib/src) | 14 | [base/screg/winreg/tools/lib/src/sources](../../base/screg/winreg/tools/lib/src/sources), [base/screg/winreg/tools/lib/src/makefile](../../base/screg/winreg/tools/lib/src/makefile) | `crtools` | `LIBRARY` |

## `base/seaudit/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [base/seaudit](../../base/seaudit) | 1 | [base/seaudit/dirs](../../base/seaudit/dirs) | — | — |
| [base/seaudit/msaudite](../../base/seaudit/msaudite) | 6 | [base/seaudit/msaudite/sources](../../base/seaudit/msaudite/sources), [base/seaudit/msaudite/makefile](../../base/seaudit/msaudite/makefile) | `msaudite` | `DYNLINK` |
| [base/seaudit/msobjs](../../base/seaudit/msobjs) | 6 | [base/seaudit/msobjs/sources](../../base/seaudit/msobjs/sources), [base/seaudit/msobjs/makefile](../../base/seaudit/msobjs/makefile) | `msobjs` | `DYNLINK` |

## `base/strsafe/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [base/strsafe](../../base/strsafe) | 1 | [base/strsafe/dirs](../../base/strsafe/dirs) | — | — |
| [base/strsafe/ntstrsafe](../../base/strsafe/ntstrsafe) | 3 | [base/strsafe/ntstrsafe/sources](../../base/strsafe/ntstrsafe/sources), [base/strsafe/ntstrsafe/makefile](../../base/strsafe/ntstrsafe/makefile) | `ntstrsafe` | `DRIVER_LIBRARY` |
| [base/strsafe/strsafe](../../base/strsafe/strsafe) | 3 | [base/strsafe/strsafe/sources](../../base/strsafe/strsafe/sources), [base/strsafe/strsafe/makefile](../../base/strsafe/strsafe/makefile) | `strsafe` | `LIBRARY` |

## `base/stublibs/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [base/stublibs](../../base/stublibs) | 3 | [base/stublibs/dirs](../../base/stublibs/dirs) | — | — |
| [base/stublibs/delay](../../base/stublibs/delay) | 3 | [base/stublibs/delay/sources](../../base/stublibs/delay/sources), [base/stublibs/delay/makefile](../../base/stublibs/delay/makefile) | `delayimp` | `LIBRARY` |
| [base/stublibs/rsa32](../../base/stublibs/rsa32) | 3 | [base/stublibs/rsa32/sources](../../base/stublibs/rsa32/sources), [base/stublibs/rsa32/makefile](../../base/stublibs/rsa32/makefile) | `RSA32` | — |
| [base/stublibs/rsa32k](../../base/stublibs/rsa32k) | 3 | [base/stublibs/rsa32k/sources](../../base/stublibs/rsa32k/sources), [base/stublibs/rsa32k/makefile](../../base/stublibs/rsa32k/makefile) | `RSA32K` | — |

## `base/subsys/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [base/subsys](../../base/subsys) | 1 | [base/subsys/dirs](../../base/subsys/dirs) | — | — |
| [base/subsys/csr](../../base/subsys/csr) | 1 | [base/subsys/csr/dirs](../../base/subsys/csr/dirs) | — | — |
| [base/subsys/csr/csrss](../../base/subsys/csr/csrss) | 4 | [base/subsys/csr/csrss/sources](../../base/subsys/csr/csrss/sources), [base/subsys/csr/csrss/makefile](../../base/subsys/csr/csrss/makefile) | `csrss` | `PROGRAM` |
| [base/subsys/csr/server](../../base/subsys/csr/server) | 16 | [base/subsys/csr/server/sources](../../base/subsys/csr/server/sources), [base/subsys/csr/server/makefile](../../base/subsys/csr/server/makefile) | `csrsrv` | `DYNLINK` |
| [base/subsys/posix](../../base/subsys/posix) | 6 | [base/subsys/posix/dirs](../../base/subsys/posix/dirs) | — | — |
| [base/subsys/posix/ballot](../../base/subsys/posix/ballot) | 4 | — | — | — |
| [base/subsys/posix/client](../../base/subsys/posix/client) | 22 | [base/subsys/posix/client/sources](../../base/subsys/posix/client/sources), [base/subsys/posix/client/makefile](../../base/subsys/posix/client/makefile) | `psxdll` | `DYNLINK` |
| [base/subsys/posix/client/alpha](../../base/subsys/posix/client/alpha) | 2 | [base/subsys/posix/client/alpha/sources](../../base/subsys/posix/client/alpha/sources) | — | — |
| [base/subsys/posix/client/axp64](../../base/subsys/posix/client/axp64) | 1 | [base/subsys/posix/client/axp64/sources](../../base/subsys/posix/client/axp64/sources) | — | — |
| [base/subsys/posix/client/i386](../../base/subsys/posix/client/i386) | 2 | [base/subsys/posix/client/i386/sources](../../base/subsys/posix/client/i386/sources) | — | — |
| [base/subsys/posix/client/ia64](../../base/subsys/posix/client/ia64) | 2 | [base/subsys/posix/client/ia64/sources](../../base/subsys/posix/client/ia64/sources) | — | — |
| [base/subsys/posix/client/tst](../../base/subsys/posix/client/tst) | 20 | — | — | — |
| [base/subsys/posix/inc](../../base/subsys/posix/inc) | 10 | — | — | — |
| [base/subsys/posix/programs](../../base/subsys/posix/programs) | 1 | [base/subsys/posix/programs/dirs](../../base/subsys/posix/programs/dirs) | — | — |
| [base/subsys/posix/programs/bsdlib](../../base/subsys/posix/programs/bsdlib) | 26 | [base/subsys/posix/programs/bsdlib/sources](../../base/subsys/posix/programs/bsdlib/sources), [base/subsys/posix/programs/bsdlib/makefile](../../base/subsys/posix/programs/bsdlib/makefile) | `bsdpsx` | `LIBRARY` |
| [base/subsys/posix/programs/hello](../../base/subsys/posix/programs/hello) | 3 | [base/subsys/posix/programs/hello/sources](../../base/subsys/posix/programs/hello/sources), [base/subsys/posix/programs/hello/makefile](../../base/subsys/posix/programs/hello/makefile) | `psxhellp` | `PROGRAM` |
| [base/subsys/posix/programs/inc](../../base/subsys/posix/programs/inc) | 2 | — | — | — |
| [base/subsys/posix/programs/inc/bsd](../../base/subsys/posix/programs/inc/bsd) | 5 | — | — | — |
| [base/subsys/posix/programs/inc/bsd/sys](../../base/subsys/posix/programs/inc/bsd/sys) | 2 | — | — | — |
| [base/subsys/posix/programs/inc/df](../../base/subsys/posix/programs/inc/df) | 2 | — | — | — |
| [base/subsys/posix/programs/pax](../../base/subsys/posix/programs/pax) | 33 | [base/subsys/posix/programs/pax/sources](../../base/subsys/posix/programs/pax/sources), [base/subsys/posix/programs/pax/makefile](../../base/subsys/posix/programs/pax/makefile) | `pax` | `PROGRAM` |
| [base/subsys/posix/programs/psxarc](../../base/subsys/posix/programs/psxarc) | 15 | [base/subsys/posix/programs/psxarc/sources](../../base/subsys/posix/programs/psxarc/sources), [base/subsys/posix/programs/psxarc/makefile](../../base/subsys/posix/programs/psxarc/makefile) | `psxarc` | `LIBRARY` |
| [base/subsys/posix/programs/psxses](../../base/subsys/posix/programs/psxses) | 20 | [base/subsys/posix/programs/psxses/sources](../../base/subsys/posix/programs/psxses/sources), [base/subsys/posix/programs/psxses/makefile](../../base/subsys/posix/programs/psxses/makefile) | `posix` | `PROGRAM` |
| [base/subsys/posix/psxss](../../base/subsys/posix/psxss) | 36 | [base/subsys/posix/psxss/sources](../../base/subsys/posix/psxss/sources), [base/subsys/posix/psxss/makefile](../../base/subsys/posix/psxss/makefile) | `psxss` | `PROGRAM` |
| [base/subsys/posix/rtl](../../base/subsys/posix/rtl) | 4 | [base/subsys/posix/rtl/sources](../../base/subsys/posix/rtl/sources), [base/subsys/posix/rtl/makefile](../../base/subsys/posix/rtl/makefile) | `psxrtl` | `LIBRARY` |
| [base/subsys/sm](../../base/subsys/sm) | 1 | [base/subsys/sm/dirs](../../base/subsys/sm/dirs) | — | — |
| [base/subsys/sm/client](../../base/subsys/sm/client) | 5 | [base/subsys/sm/client/sources](../../base/subsys/sm/client/sources), [base/subsys/sm/client/makefile](../../base/subsys/sm/client/makefile) | `smdll` | `LIBRARY` |
| [base/subsys/sm/inc](../../base/subsys/sm/inc) | 1 | — | — | — |
| [base/subsys/sm/server](../../base/subsys/sm/server) | 17 | [base/subsys/sm/server/sources](../../base/subsys/sm/server/sources), [base/subsys/sm/server/makefile](../../base/subsys/sm/server/makefile) | `smss` | `PROGRAM` |
| [base/subsys/sm/sfc](../../base/subsys/sm/sfc) | 1 | [base/subsys/sm/sfc/dirs](../../base/subsys/sm/sfc/dirs) | — | — |
| [base/subsys/sm/sfc/cpl](../../base/subsys/sm/sfc/cpl) | 9 | [base/subsys/sm/sfc/cpl/sources](../../base/subsys/sm/sfc/cpl/sources), [base/subsys/sm/sfc/cpl/makefile](../../base/subsys/sm/sfc/cpl/makefile) | `sfccpl` | `DYNLINK` |
| [base/subsys/sm/sfc/dll](../../base/subsys/sm/sfc/dll) | 30 | [base/subsys/sm/sfc/dll/sources](../../base/subsys/sm/sfc/dll/sources), [base/subsys/sm/sfc/dll/makefile](../../base/subsys/sm/sfc/dll/makefile) | `sfc_os` | `DYNLINK` |
| [base/subsys/sm/sfc/exe](../../base/subsys/sm/sfc/exe) | 6 | [base/subsys/sm/sfc/exe/sources](../../base/subsys/sm/sfc/exe/sources), [base/subsys/sm/sfc/exe/makefile](../../base/subsys/sm/sfc/exe/makefile) | `sfc` | `PROGRAM` |
| [base/subsys/sm/sfc/files](../../base/subsys/sm/sfc/files) | 5 | [base/subsys/sm/sfc/files/dirs](../../base/subsys/sm/sfc/files/dirs) | — | — |
| [base/subsys/sm/sfc/files/ara](../../base/subsys/sm/sfc/files/ara) | 6 | [base/subsys/sm/sfc/files/ara/sources](../../base/subsys/sm/sfc/files/ara/sources), [base/subsys/sm/sfc/files/ara/makefile](../../base/subsys/sm/sfc/files/ara/makefile) | — | — |
| [base/subsys/sm/sfc/files/br](../../base/subsys/sm/sfc/files/br) | 6 | [base/subsys/sm/sfc/files/br/sources](../../base/subsys/sm/sfc/files/br/sources), [base/subsys/sm/sfc/files/br/makefile](../../base/subsys/sm/sfc/files/br/makefile) | — | — |
| [base/subsys/sm/sfc/files/chh](../../base/subsys/sm/sfc/files/chh) | 7 | [base/subsys/sm/sfc/files/chh/sources](../../base/subsys/sm/sfc/files/chh/sources), [base/subsys/sm/sfc/files/chh/makefile](../../base/subsys/sm/sfc/files/chh/makefile) | — | — |
| [base/subsys/sm/sfc/files/chs](../../base/subsys/sm/sfc/files/chs) | 7 | [base/subsys/sm/sfc/files/chs/sources](../../base/subsys/sm/sfc/files/chs/sources), [base/subsys/sm/sfc/files/chs/makefile](../../base/subsys/sm/sfc/files/chs/makefile) | — | — |
| [base/subsys/sm/sfc/files/cht](../../base/subsys/sm/sfc/files/cht) | 6 | [base/subsys/sm/sfc/files/cht/sources](../../base/subsys/sm/sfc/files/cht/sources), [base/subsys/sm/sfc/files/cht/makefile](../../base/subsys/sm/sfc/files/cht/makefile) | — | — |
| [base/subsys/sm/sfc/files/cs](../../base/subsys/sm/sfc/files/cs) | 6 | [base/subsys/sm/sfc/files/cs/sources](../../base/subsys/sm/sfc/files/cs/sources), [base/subsys/sm/sfc/files/cs/makefile](../../base/subsys/sm/sfc/files/cs/makefile) | — | — |
| [base/subsys/sm/sfc/files/da](../../base/subsys/sm/sfc/files/da) | 6 | [base/subsys/sm/sfc/files/da/sources](../../base/subsys/sm/sfc/files/da/sources), [base/subsys/sm/sfc/files/da/makefile](../../base/subsys/sm/sfc/files/da/makefile) | — | — |
| [base/subsys/sm/sfc/files/el](../../base/subsys/sm/sfc/files/el) | 6 | [base/subsys/sm/sfc/files/el/sources](../../base/subsys/sm/sfc/files/el/sources), [base/subsys/sm/sfc/files/el/makefile](../../base/subsys/sm/sfc/files/el/makefile) | — | — |
| [base/subsys/sm/sfc/files/es](../../base/subsys/sm/sfc/files/es) | 6 | [base/subsys/sm/sfc/files/es/sources](../../base/subsys/sm/sfc/files/es/sources), [base/subsys/sm/sfc/files/es/makefile](../../base/subsys/sm/sfc/files/es/makefile) | — | — |
| [base/subsys/sm/sfc/files/fi](../../base/subsys/sm/sfc/files/fi) | 6 | [base/subsys/sm/sfc/files/fi/sources](../../base/subsys/sm/sfc/files/fi/sources), [base/subsys/sm/sfc/files/fi/makefile](../../base/subsys/sm/sfc/files/fi/makefile) | — | — |
| [base/subsys/sm/sfc/files/fr](../../base/subsys/sm/sfc/files/fr) | 7 | [base/subsys/sm/sfc/files/fr/sources](../../base/subsys/sm/sfc/files/fr/sources), [base/subsys/sm/sfc/files/fr/makefile](../../base/subsys/sm/sfc/files/fr/makefile) | — | — |
| [base/subsys/sm/sfc/files/ger](../../base/subsys/sm/sfc/files/ger) | 7 | [base/subsys/sm/sfc/files/ger/sources](../../base/subsys/sm/sfc/files/ger/sources), [base/subsys/sm/sfc/files/ger/makefile](../../base/subsys/sm/sfc/files/ger/makefile) | — | — |
| [base/subsys/sm/sfc/files/heb](../../base/subsys/sm/sfc/files/heb) | 6 | [base/subsys/sm/sfc/files/heb/sources](../../base/subsys/sm/sfc/files/heb/sources), [base/subsys/sm/sfc/files/heb/makefile](../../base/subsys/sm/sfc/files/heb/makefile) | — | — |
| [base/subsys/sm/sfc/files/hu](../../base/subsys/sm/sfc/files/hu) | 6 | [base/subsys/sm/sfc/files/hu/sources](../../base/subsys/sm/sfc/files/hu/sources), [base/subsys/sm/sfc/files/hu/makefile](../../base/subsys/sm/sfc/files/hu/makefile) | — | — |
| [base/subsys/sm/sfc/files/it](../../base/subsys/sm/sfc/files/it) | 7 | [base/subsys/sm/sfc/files/it/sources](../../base/subsys/sm/sfc/files/it/sources), [base/subsys/sm/sfc/files/it/makefile](../../base/subsys/sm/sfc/files/it/makefile) | — | — |
| [base/subsys/sm/sfc/files/jpn](../../base/subsys/sm/sfc/files/jpn) | 7 | [base/subsys/sm/sfc/files/jpn/sources](../../base/subsys/sm/sfc/files/jpn/sources), [base/subsys/sm/sfc/files/jpn/makefile](../../base/subsys/sm/sfc/files/jpn/makefile) | — | — |
| [base/subsys/sm/sfc/files/kor](../../base/subsys/sm/sfc/files/kor) | 7 | [base/subsys/sm/sfc/files/kor/sources](../../base/subsys/sm/sfc/files/kor/sources), [base/subsys/sm/sfc/files/kor/makefile](../../base/subsys/sm/sfc/files/kor/makefile) | — | — |
| [base/subsys/sm/sfc/files/nl](../../base/subsys/sm/sfc/files/nl) | 6 | [base/subsys/sm/sfc/files/nl/sources](../../base/subsys/sm/sfc/files/nl/sources), [base/subsys/sm/sfc/files/nl/makefile](../../base/subsys/sm/sfc/files/nl/makefile) | — | — |
| [base/subsys/sm/sfc/files/no](../../base/subsys/sm/sfc/files/no) | 6 | [base/subsys/sm/sfc/files/no/sources](../../base/subsys/sm/sfc/files/no/sources), [base/subsys/sm/sfc/files/no/makefile](../../base/subsys/sm/sfc/files/no/makefile) | — | — |
| [base/subsys/sm/sfc/files/pl](../../base/subsys/sm/sfc/files/pl) | 6 | [base/subsys/sm/sfc/files/pl/sources](../../base/subsys/sm/sfc/files/pl/sources), [base/subsys/sm/sfc/files/pl/makefile](../../base/subsys/sm/sfc/files/pl/makefile) | — | — |
| [base/subsys/sm/sfc/files/psu](../../base/subsys/sm/sfc/files/psu) | 6 | [base/subsys/sm/sfc/files/psu/sources](../../base/subsys/sm/sfc/files/psu/sources), [base/subsys/sm/sfc/files/psu/makefile](../../base/subsys/sm/sfc/files/psu/makefile) | — | — |
| [base/subsys/sm/sfc/files/pt](../../base/subsys/sm/sfc/files/pt) | 6 | [base/subsys/sm/sfc/files/pt/sources](../../base/subsys/sm/sfc/files/pt/sources), [base/subsys/sm/sfc/files/pt/makefile](../../base/subsys/sm/sfc/files/pt/makefile) | — | — |
| [base/subsys/sm/sfc/files/ru](../../base/subsys/sm/sfc/files/ru) | 6 | [base/subsys/sm/sfc/files/ru/sources](../../base/subsys/sm/sfc/files/ru/sources), [base/subsys/sm/sfc/files/ru/makefile](../../base/subsys/sm/sfc/files/ru/makefile) | — | — |
| [base/subsys/sm/sfc/files/sv](../../base/subsys/sm/sfc/files/sv) | 6 | [base/subsys/sm/sfc/files/sv/sources](../../base/subsys/sm/sfc/files/sv/sources), [base/subsys/sm/sfc/files/sv/makefile](../../base/subsys/sm/sfc/files/sv/makefile) | — | — |
| [base/subsys/sm/sfc/files/tr](../../base/subsys/sm/sfc/files/tr) | 6 | [base/subsys/sm/sfc/files/tr/sources](../../base/subsys/sm/sfc/files/tr/sources), [base/subsys/sm/sfc/files/tr/makefile](../../base/subsys/sm/sfc/files/tr/makefile) | — | — |
| [base/subsys/sm/sfc/files/usa](../../base/subsys/sm/sfc/files/usa) | 7 | [base/subsys/sm/sfc/files/usa/sources](../../base/subsys/sm/sfc/files/usa/sources), [base/subsys/sm/sfc/files/usa/makefile](../../base/subsys/sm/sfc/files/usa/makefile) | — | — |
| [base/subsys/sm/sfc/postbuild](../../base/subsys/sm/sfc/postbuild) | 3 | [base/subsys/sm/sfc/postbuild/sources](../../base/subsys/sm/sfc/postbuild/sources), [base/subsys/sm/sfc/postbuild/makefile](../../base/subsys/sm/sfc/postbuild/makefile) | — | `NOTARGET` |
| [base/subsys/sm/sfc/postbuild/src](../../base/subsys/sm/sfc/postbuild/src) | 5 | [base/subsys/sm/sfc/postbuild/src/sources](../../base/subsys/sm/sfc/postbuild/src/sources), [base/subsys/sm/sfc/postbuild/src/makefile](../../base/subsys/sm/sfc/postbuild/src/makefile) | `sfcfiles` | `DYNLINK` |
| [base/subsys/sm/sfc/publish](../../base/subsys/sm/sfc/publish) | 6 | [base/subsys/sm/sfc/publish/sources](../../base/subsys/sm/sfc/publish/sources), [base/subsys/sm/sfc/publish/makefile](../../base/subsys/sm/sfc/publish/makefile) | — | `LIBRARY` |
| [base/subsys/sm/sfc/rpc](../../base/subsys/sm/sfc/rpc) | 1 | [base/subsys/sm/sfc/rpc/dirs](../../base/subsys/sm/sfc/rpc/dirs) | — | — |
| [base/subsys/sm/sfc/rpc/cli](../../base/subsys/sm/sfc/rpc/cli) | 3 | [base/subsys/sm/sfc/rpc/cli/sources](../../base/subsys/sm/sfc/rpc/cli/sources), [base/subsys/sm/sfc/rpc/cli/makefile](../../base/subsys/sm/sfc/rpc/cli/makefile) | `sfccli` | `LIBRARY` |
| [base/subsys/sm/sfc/rpc/idl](../../base/subsys/sm/sfc/rpc/idl) | 6 | [base/subsys/sm/sfc/rpc/idl/sources](../../base/subsys/sm/sfc/rpc/idl/sources), [base/subsys/sm/sfc/rpc/idl/makefile](../../base/subsys/sm/sfc/rpc/idl/makefile) | — | `LIBRARY` |
| [base/subsys/sm/sfc/rpc/srv](../../base/subsys/sm/sfc/rpc/srv) | 3 | [base/subsys/sm/sfc/rpc/srv/sources](../../base/subsys/sm/sfc/rpc/srv/sources), [base/subsys/sm/sfc/rpc/srv/makefile](../../base/subsys/sm/sfc/rpc/srv/makefile) | `sfcsrv` | `LIBRARY` |
| [base/subsys/sm/sfc/sfc_fwd](../../base/subsys/sm/sfc/sfc_fwd) | 5 | [base/subsys/sm/sfc/sfc_fwd/sources](../../base/subsys/sm/sfc/sfc_fwd/sources), [base/subsys/sm/sfc/sfc_fwd/makefile](../../base/subsys/sm/sfc/sfc_fwd/makefile) | `sfc` | `DYNLINK` |
| [base/subsys/sm/sfc/sfcexts](../../base/subsys/sm/sfc/sfcexts) | 5 | [base/subsys/sm/sfc/sfcexts/sources](../../base/subsys/sm/sfc/sfcexts/sources), [base/subsys/sm/sfc/sfcexts/makefile](../../base/subsys/sm/sfc/sfcexts/makefile) | `sfcexts` | `DYNLINK` |
| [base/subsys/sm/sfc/sfpcopy](../../base/subsys/sm/sfc/sfpcopy) | 4 | [base/subsys/sm/sfc/sfpcopy/sources](../../base/subsys/sm/sfc/sfpcopy/sources), [base/subsys/sm/sfc/sfpcopy/makefile](../../base/subsys/sm/sfc/sfpcopy/makefile) | `sfpcopy` | `PROGRAM` |
| [base/subsys/sm/sfc/stress](../../base/subsys/sm/sfc/stress) | 5 | [base/subsys/sm/sfc/stress/sources](../../base/subsys/sm/sfc/stress/sources), [base/subsys/sm/sfc/stress/makefile](../../base/subsys/sm/sfc/stress/makefile) | `sfcstress` | `PROGRAM` |
| [base/subsys/sm/sfc/test](../../base/subsys/sm/sfc/test) | 9 | [base/subsys/sm/sfc/test/sources](../../base/subsys/sm/sfc/test/sources), [base/subsys/sm/sfc/test/makefile](../../base/subsys/sm/sfc/test/makefile) | `sfctest` | `PROGRAM` |

## `base/testlockout/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [base/testlockout](../../base/testlockout) | 1 | — | — | — |

## `base/tools/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [base/tools](../../base/tools) | 1 | [base/tools/dirs](../../base/tools/dirs) | — | — |
| [base/tools/bldrthnk](../../base/tools/bldrthnk) | 5 | [base/tools/bldrthnk/sources](../../base/tools/bldrthnk/sources), [base/tools/bldrthnk/makefile](../../base/tools/bldrthnk/makefile) | `bldrthnk` | `PROGRAM` |
| [base/tools/devctl](../../base/tools/devctl) | 14 | [base/tools/devctl/sources](../../base/tools/devctl/sources), [base/tools/devctl/makefile](../../base/tools/devctl/makefile) | — | `UMAPPL_NOLIB` |
| [base/tools/dmpobj](../../base/tools/dmpobj) | 3 | [base/tools/dmpobj/sources](../../base/tools/dmpobj/sources), [base/tools/dmpobj/makefile](../../base/tools/dmpobj/makefile) | `dmpobj` | `PROGRAM` |
| [base/tools/genxx](../../base/tools/genxx) | 4 | [base/tools/genxx/sources](../../base/tools/genxx/sources), [base/tools/genxx/makefile](../../base/tools/genxx/makefile) | `genxx` | `PROGRAM` |
| [base/tools/gs_support](../../base/tools/gs_support) | 3 | [base/tools/gs_support/sources](../../base/tools/gs_support/sources), [base/tools/gs_support/makefile](../../base/tools/gs_support/makefile) | `bufferoverflow` | `LIBRARY` |
| [base/tools/instaler](../../base/tools/instaler) | 39 | [base/tools/instaler/sources](../../base/tools/instaler/sources), [base/tools/instaler/makefile](../../base/tools/instaler/makefile) | `instaler` | `LIBRARY` |
| [base/tools/instaler/i386](../../base/tools/instaler/i386) | 2 | [base/tools/instaler/i386/sources](../../base/tools/instaler/i386/sources) | — | — |
| [base/tools/kdexts2](../../base/tools/kdexts2) | 93 | [base/tools/kdexts2/sources](../../base/tools/kdexts2/sources), [base/tools/kdexts2/makefile](../../base/tools/kdexts2/makefile) | `kdexts` | `DYNLINK` |
| [base/tools/kdlog](../../base/tools/kdlog) | 2 | [base/tools/kdlog/dirs](../../base/tools/kdlog/dirs) | — | — |
| [base/tools/kdlog/app](../../base/tools/kdlog/app) | 4 | [base/tools/kdlog/app/sources](../../base/tools/kdlog/app/sources), [base/tools/kdlog/app/makefile](../../base/tools/kdlog/app/makefile) | `kdlog` | `PROGRAM` |
| [base/tools/kdlog/driver](../../base/tools/kdlog/driver) | 4 | [base/tools/kdlog/driver/sources](../../base/tools/kdlog/driver/sources), [base/tools/kdlog/driver/makefile](../../base/tools/kdlog/driver/makefile) | `kdlog` | `DRIVER` |
| [base/tools/kernprof](../../base/tools/kernprof) | 5 | [base/tools/kernprof/sources](../../base/tools/kernprof/sources), [base/tools/kernprof/makefile](../../base/tools/kernprof/makefile) | `kernprof` | `PROGRAM` |
| [base/tools/kernrate](../../base/tools/kernrate) | 6 | [base/tools/kernrate/sources](../../base/tools/kernrate/sources), [base/tools/kernrate/makefile](../../base/tools/kernrate/makefile) | `kernrate` | `PROGRAM` |
| [base/tools/ntsdexts](../../base/tools/ntsdexts) | 12 | [base/tools/ntsdexts/sources](../../base/tools/ntsdexts/sources), [base/tools/ntsdexts/makefile](../../base/tools/ntsdexts/makefile) | `ntsdexts` | `DYNLINK` |
| [base/tools/pperf](../../base/tools/pperf) | 4 | [base/tools/pperf/dirs](../../base/tools/pperf/dirs) | — | — |
| [base/tools/pperf/app](../../base/tools/pperf/app) | 11 | [base/tools/pperf/app/sources](../../base/tools/pperf/app/sources), [base/tools/pperf/app/makefile](../../base/tools/pperf/app/makefile) | `pperf` | `PROGRAM` |
| [base/tools/pperf/app/i386](../../base/tools/pperf/app/i386) | 1 | [base/tools/pperf/app/i386/sources](../../base/tools/pperf/app/i386/sources) | — | — |
| [base/tools/pperf/dll](../../base/tools/pperf/dll) | 18 | [base/tools/pperf/dll/sources](../../base/tools/pperf/dll/sources), [base/tools/pperf/dll/makefile](../../base/tools/pperf/dll/makefile) | `p5ctrs` | `DYNLINK` |
| [base/tools/pperf/dll/i386](../../base/tools/pperf/dll/i386) | 1 | [base/tools/pperf/dll/i386/sources](../../base/tools/pperf/dll/i386/sources) | — | — |
| [base/tools/pperf/driver](../../base/tools/pperf/driver) | 4 | [base/tools/pperf/driver/sources](../../base/tools/pperf/driver/sources), [base/tools/pperf/driver/makefile](../../base/tools/pperf/driver/makefile) | `pstat` | `DRIVER` |
| [base/tools/pperf/driver/i386](../../base/tools/pperf/driver/i386) | 5 | [base/tools/pperf/driver/i386/sources](../../base/tools/pperf/driver/i386/sources) | — | — |
| [base/tools/pperf/pdump](../../base/tools/pperf/pdump) | 4 | [base/tools/pperf/pdump/sources](../../base/tools/pperf/pdump/sources), [base/tools/pperf/pdump/makefile](../../base/tools/pperf/pdump/makefile) | `pdump` | `PROGRAM` |
| [base/tools/qsys](../../base/tools/qsys) | 6 | [base/tools/qsys/sources](../../base/tools/qsys/sources), [base/tools/qsys/makefile](../../base/tools/qsys/makefile) | `qsys` | `PROGRAM` |
| [base/tools/resmon](../../base/tools/resmon) | 23 | [base/tools/resmon/sources](../../base/tools/resmon/sources), [base/tools/resmon/makefile](../../base/tools/resmon/makefile) | `resmon` | `UMAPPL_NOLIB` |
| [base/tools/setupext](../../base/tools/setupext) | 5 | [base/tools/setupext/sources](../../base/tools/setupext/sources), [base/tools/setupext/makefile](../../base/tools/setupext/makefile) | `setupext` | `DYNLINK` |
| [base/tools/umdh](../../base/tools/umdh) | 15 | [base/tools/umdh/sources](../../base/tools/umdh/sources), [base/tools/umdh/makefile](../../base/tools/umdh/makefile) | `umdh` | `PROGRAM` |
| [base/tools/vadump](../../base/tools/vadump) | 4 | [base/tools/vadump/sources](../../base/tools/vadump/sources), [base/tools/vadump/makefile](../../base/tools/vadump/makefile) | `vadump` | `PROGRAM` |
| [base/tools/winerror](../../base/tools/winerror) | 4 | [base/tools/winerror/sources](../../base/tools/winerror/sources), [base/tools/winerror/makefile](../../base/tools/winerror/makefile) | `winerror` | `PROGRAM` |

## `base/urtl/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [base/urtl](../../base/urtl) | 6 | [base/urtl/sources](../../base/urtl/sources), [base/urtl/makefile](../../base/urtl/makefile) | `nt` | `LIBRARY` |

## `base/wdmdrv/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [base/wdmdrv](../../base/wdmdrv) | 14 | [base/wdmdrv/sources](../../base/wdmdrv/sources), [base/wdmdrv/makefile](../../base/wdmdrv/makefile) | `wdmguid` | `LIBRARY` |

## `base/wdmlib/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [base/wdmlib](../../base/wdmlib) | 1 | [base/wdmlib/dirs](../../base/wdmlib/dirs) | — | — |
| [base/wdmlib/wdmsec](../../base/wdmlib/wdmsec) | 1 | [base/wdmlib/wdmsec/dirs](../../base/wdmlib/wdmsec/dirs) | — | — |
| [base/wdmlib/wdmsec/cm](../../base/wdmlib/wdmsec/cm) | 5 | [base/wdmlib/wdmsec/cm/sources](../../base/wdmlib/wdmsec/cm/sources), [base/wdmlib/wdmsec/cm/makefile](../../base/wdmlib/wdmsec/cm/makefile) | `cm` | `LIBRARY` |
| [base/wdmlib/wdmsec/inc](../../base/wdmlib/wdmsec/inc) | 4 | [base/wdmlib/wdmsec/inc/sources](../../base/wdmlib/wdmsec/inc/sources), [base/wdmlib/wdmsec/inc/makefile](../../base/wdmlib/wdmsec/inc/makefile) | `inc` | `LIBRARY` |
| [base/wdmlib/wdmsec/io](../../base/wdmlib/wdmsec/io) | 6 | [base/wdmlib/wdmsec/io/sources](../../base/wdmlib/wdmsec/io/sources), [base/wdmlib/wdmsec/io/makefile](../../base/wdmlib/wdmsec/io/makefile) | `io` | `LIBRARY` |
| [base/wdmlib/wdmsec/pp](../../base/wdmlib/wdmsec/pp) | 5 | [base/wdmlib/wdmsec/pp/sources](../../base/wdmlib/wdmsec/pp/sources), [base/wdmlib/wdmsec/pp/makefile](../../base/wdmlib/wdmsec/pp/makefile) | `pp` | `LIBRARY` |
| [base/wdmlib/wdmsec/published](../../base/wdmlib/wdmsec/published) | 4 | [base/wdmlib/wdmsec/published/sources](../../base/wdmlib/wdmsec/published/sources), [base/wdmlib/wdmsec/published/makefile](../../base/wdmlib/wdmsec/published/makefile) | — | `NOTARGET` |
| [base/wdmlib/wdmsec/se](../../base/wdmlib/wdmsec/se) | 7 | [base/wdmlib/wdmsec/se/sources](../../base/wdmlib/wdmsec/se/sources), [base/wdmlib/wdmsec/se/makefile](../../base/wdmlib/wdmsec/se/makefile) | `se` | `LIBRARY` |
| [base/wdmlib/wdmsec/wl](../../base/wdmlib/wdmsec/wl) | 5 | [base/wdmlib/wdmsec/wl/sources](../../base/wdmlib/wdmsec/wl/sources), [base/wdmlib/wdmsec/wl/makefile](../../base/wdmlib/wdmsec/wl/makefile) | `wl` | `LIBRARY` |

## `base/win32/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [base/win32](../../base/win32) | 1 | [base/win32/dirs](../../base/win32/dirs) | — | — |
| [base/win32/client](../../base/win32/client) | 112 | [base/win32/client/dirs](../../base/win32/client/dirs) | — | — |
| [base/win32/client/alpha](../../base/win32/client/alpha) | 4 | [base/win32/client/alpha/sources](../../base/win32/client/alpha/sources) | — | — |
| [base/win32/client/amd64](../../base/win32/client/amd64) | 3 | [base/win32/client/amd64/sources](../../base/win32/client/amd64/sources) | — | — |
| [base/win32/client/axp64](../../base/win32/client/axp64) | 1 | [base/win32/client/axp64/sources](../../base/win32/client/axp64/sources) | — | — |
| [base/win32/client/bt](../../base/win32/client/bt) | 0 | — | — | — |
| [base/win32/client/bt/char](../../base/win32/client/bt/char) | 8 | [base/win32/client/bt/char/sources](../../base/win32/client/bt/char/sources), [base/win32/client/bt/char/makefile](../../base/win32/client/bt/char/makefile) | `bm` | `PROGRAM` |
| [base/win32/client/bt/char/i386](../../base/win32/client/bt/char/i386) | 2 | [base/win32/client/bt/char/i386/sources](../../base/win32/client/bt/char/i386/sources) | — | — |
| [base/win32/client/bt/intrlk](../../base/win32/client/bt/intrlk) | 3 | [base/win32/client/bt/intrlk/sources](../../base/win32/client/bt/intrlk/sources), [base/win32/client/bt/intrlk/makefile](../../base/win32/client/bt/intrlk/makefile) | `intrlk` | `PROGRAM` |
| [base/win32/client/bt/nbqueue](../../base/win32/client/bt/nbqueue) | 4 | [base/win32/client/bt/nbqueue/sources](../../base/win32/client/bt/nbqueue/sources), [base/win32/client/bt/nbqueue/makefile](../../base/win32/client/bt/nbqueue/makefile) | `nbtest` | `PROGRAM` |
| [base/win32/client/bt/nbqueue/i386](../../base/win32/client/bt/nbqueue/i386) | 2 | [base/win32/client/bt/nbqueue/i386/sources](../../base/win32/client/bt/nbqueue/i386/sources) | — | — |
| [base/win32/client/bt/nt](../../base/win32/client/bt/nt) | 4 | [base/win32/client/bt/nt/sources](../../base/win32/client/bt/nt/sources), [base/win32/client/bt/nt/makefile](../../base/win32/client/bt/nt/makefile) | `ntbm` | `PROGRAM` |
| [base/win32/client/bt/single](../../base/win32/client/bt/single) | 3 | [base/win32/client/bt/single/sources](../../base/win32/client/bt/single/sources), [base/win32/client/bt/single/makefile](../../base/win32/client/bt/single/makefile) | `single` | `PROGRAM` |
| [base/win32/client/bt/size](../../base/win32/client/bt/size) | 2 | [base/win32/client/bt/size/sources](../../base/win32/client/bt/size/sources), [base/win32/client/bt/size/makefile](../../base/win32/client/bt/size/makefile) | `size` | `PROGRAM` |
| [base/win32/client/bt/slist](../../base/win32/client/bt/slist) | 4 | [base/win32/client/bt/slist/sources](../../base/win32/client/bt/slist/sources), [base/win32/client/bt/slist/makefile](../../base/win32/client/bt/slist/makefile) | `sl` | `PROGRAM` |
| [base/win32/client/bt/slist/amd64](../../base/win32/client/bt/slist/amd64) | 2 | [base/win32/client/bt/slist/amd64/sources](../../base/win32/client/bt/slist/amd64/sources) | — | — |
| [base/win32/client/bt/throw](../../base/win32/client/bt/throw) | 3 | [base/win32/client/bt/throw/sources](../../base/win32/client/bt/throw/sources), [base/win32/client/bt/throw/makefile](../../base/win32/client/bt/throw/makefile) | `throw` | `PROGRAM` |
| [base/win32/client/daytona](../../base/win32/client/daytona) | 3 | [base/win32/client/daytona/sources](../../base/win32/client/daytona/sources), [base/win32/client/daytona/makefile](../../base/win32/client/daytona/makefile) | — | — |
| [base/win32/client/i386](../../base/win32/client/i386) | 4 | [base/win32/client/i386/sources](../../base/win32/client/i386/sources) | — | — |
| [base/win32/client/ia64](../../base/win32/client/ia64) | 3 | [base/win32/client/ia64/sources](../../base/win32/client/ia64/sources) | — | — |
| [base/win32/client/wow64](../../base/win32/client/wow64) | 2 | [base/win32/client/wow64/sources](../../base/win32/client/wow64/sources), [base/win32/client/wow64/makefile](../../base/win32/client/wow64/makefile) | `csrbase` | `LIBRARY` |
| [base/win32/client/wow6432](../../base/win32/client/wow6432) | 4 | [base/win32/client/wow6432/sources](../../base/win32/client/wow6432/sources), [base/win32/client/wow6432/makefile](../../base/win32/client/wow6432/makefile) | — | — |
| [base/win32/client/wow6432/i386](../../base/win32/client/wow6432/i386) | 1 | — | — | — |
| [base/win32/fusion](../../base/win32/fusion) | 8 | [base/win32/fusion/dirs](../../base/win32/fusion/dirs) | — | — |
| [base/win32/fusion/app](../../base/win32/fusion/app) | 12 | [base/win32/fusion/app/sources](../../base/win32/fusion/app/sources), [base/win32/fusion/app/makefile](../../base/win32/fusion/app/makefile) | `app` | `DYNLINK` |
| [base/win32/fusion/app/asmexec](../../base/win32/fusion/app/asmexec) | 1 | — | — | — |
| [base/win32/fusion/app/conexec](../../base/win32/fusion/app/conexec) | 9 | — | — | — |
| [base/win32/fusion/app/manifest](../../base/win32/fusion/app/manifest) | 1 | [base/win32/fusion/app/manifest/dirs](../../base/win32/fusion/app/manifest/dirs) | — | — |
| [base/win32/fusion/app/manifest/dll](../../base/win32/fusion/app/manifest/dll) | 6 | [base/win32/fusion/app/manifest/dll/sources](../../base/win32/fusion/app/manifest/dll/sources), [base/win32/fusion/app/manifest/dll/makefile](../../base/win32/fusion/app/manifest/dll/makefile) | `manifest` | `DYNLINK` |
| [base/win32/fusion/app/manifest/filehost](../../base/win32/fusion/app/manifest/filehost) | 4 | [base/win32/fusion/app/manifest/filehost/sources](../../base/win32/fusion/app/manifest/filehost/sources), [base/win32/fusion/app/manifest/filehost/makefile](../../base/win32/fusion/app/manifest/filehost/makefile) | `manhost` | `PROGRAM` |
| [base/win32/fusion/app/manifest/inc](../../base/win32/fusion/app/manifest/inc) | 5 | — | — | — |
| [base/win32/fusion/app/manifest/mimefilt](../../base/win32/fusion/app/manifest/mimefilt) | 6 | [base/win32/fusion/app/manifest/mimefilt/sources](../../base/win32/fusion/app/manifest/mimefilt/sources), [base/win32/fusion/app/manifest/mimefilt/makefile](../../base/win32/fusion/app/manifest/mimefilt/makefile) | `manmime` | `DYNLINK` |
| [base/win32/fusion/app/manifest/util](../../base/win32/fusion/app/manifest/util) | 1 | [base/win32/fusion/app/manifest/util/dirs](../../base/win32/fusion/app/manifest/util/dirs) | — | — |
| [base/win32/fusion/app/manifest/util/mangen](../../base/win32/fusion/app/manifest/util/mangen) | 6 | [base/win32/fusion/app/manifest/util/mangen/sources](../../base/win32/fusion/app/manifest/util/mangen/sources), [base/win32/fusion/app/manifest/util/mangen/makefile](../../base/win32/fusion/app/manifest/util/mangen/makefile) | `mangen` | `PROGRAM` |
| [base/win32/fusion/app/manifest/util/shortcut](../../base/win32/fusion/app/manifest/util/shortcut) | 22 | [base/win32/fusion/app/manifest/util/shortcut/sources](../../base/win32/fusion/app/manifest/util/shortcut/sources), [base/win32/fusion/app/manifest/util/shortcut/makefile](../../base/win32/fusion/app/manifest/util/shortcut/makefile) | `appsc` | `DYNLINK` |
| [base/win32/fusion/appweek](../../base/win32/fusion/appweek) | 4 | [base/win32/fusion/appweek/dirs](../../base/win32/fusion/appweek/dirs) | — | — |
| [base/win32/fusion/appweek/common](../../base/win32/fusion/appweek/common) | 7 | [base/win32/fusion/appweek/common/sources](../../base/win32/fusion/appweek/common/sources), [base/win32/fusion/appweek/common/makefile](../../base/win32/fusion/appweek/common/makefile) | `sxapwlib` | `LIBRARY` |
| [base/win32/fusion/appweek/dmgr](../../base/win32/fusion/appweek/dmgr) | 6 | [base/win32/fusion/appweek/dmgr/sources](../../base/win32/fusion/appweek/dmgr/sources), [base/win32/fusion/appweek/dmgr/makefile](../../base/win32/fusion/appweek/dmgr/makefile) | `sxapwdmgr` | `DYNLINK` |
| [base/win32/fusion/appweek/dsources](../../base/win32/fusion/appweek/dsources) | 2 | [base/win32/fusion/appweek/dsources/dirs](../../base/win32/fusion/appweek/dsources/dirs) | — | — |
| [base/win32/fusion/appweek/dsources/db](../../base/win32/fusion/appweek/dsources/db) | 8 | [base/win32/fusion/appweek/dsources/db/sources](../../base/win32/fusion/appweek/dsources/db/sources), [base/win32/fusion/appweek/dsources/db/makefile](../../base/win32/fusion/appweek/dsources/db/makefile) | `sxapwdb` | `DYNLINK` |
| [base/win32/fusion/appweek/dsources/dir](../../base/win32/fusion/appweek/dsources/dir) | 6 | [base/win32/fusion/appweek/dsources/dir/sources](../../base/win32/fusion/appweek/dsources/dir/sources), [base/win32/fusion/appweek/dsources/dir/makefile](../../base/win32/fusion/appweek/dsources/dir/makefile) | `sxapwdir` | `DYNLINK` |
| [base/win32/fusion/appweek/host](../../base/win32/fusion/appweek/host) | 25 | [base/win32/fusion/appweek/host/sources](../../base/win32/fusion/appweek/host/sources), [base/win32/fusion/appweek/host/makefile](../../base/win32/fusion/appweek/host/makefile) | `sxapwhost` | `PROGRAM` |
| [base/win32/fusion/appweek/host1](../../base/win32/fusion/appweek/host1) | 6 | [base/win32/fusion/appweek/host1/sources](../../base/win32/fusion/appweek/host1/sources), [base/win32/fusion/appweek/host1/makefile](../../base/win32/fusion/appweek/host1/makefile) | `sxapwhost1` | `PROGRAM` |
| [base/win32/fusion/appweek/host2](../../base/win32/fusion/appweek/host2) | 14 | [base/win32/fusion/appweek/host2/sources](../../base/win32/fusion/appweek/host2/sources), [base/win32/fusion/appweek/host2/makefile](../../base/win32/fusion/appweek/host2/makefile) | `sxapwhost2` | `PROGRAM` |
| [base/win32/fusion/appweek/idl](../../base/win32/fusion/appweek/idl) | 9 | [base/win32/fusion/appweek/idl/sources](../../base/win32/fusion/appweek/idl/sources), [base/win32/fusion/appweek/idl/makefile](../../base/win32/fusion/appweek/idl/makefile) | `sxapwguids` | `LIBRARY` |
| [base/win32/fusion/appweek/inc](../../base/win32/fusion/appweek/inc) | 16 | — | — | — |
| [base/win32/fusion/appweek/stdinc](../../base/win32/fusion/appweek/stdinc) | 4 | [base/win32/fusion/appweek/stdinc/sources](../../base/win32/fusion/appweek/stdinc/sources), [base/win32/fusion/appweek/stdinc/makefile](../../base/win32/fusion/appweek/stdinc/makefile) | `sxapwstdinc` | `LIBRARY` |
| [base/win32/fusion/appweek/uimgr](../../base/win32/fusion/appweek/uimgr) | 6 | [base/win32/fusion/appweek/uimgr/sources](../../base/win32/fusion/appweek/uimgr/sources), [base/win32/fusion/appweek/uimgr/makefile](../../base/win32/fusion/appweek/uimgr/makefile) | `sxapwuimgr` | `DYNLINK` |
| [base/win32/fusion/appweek/uiviews](../../base/win32/fusion/appweek/uiviews) | 2 | [base/win32/fusion/appweek/uiviews/dirs](../../base/win32/fusion/appweek/uiviews/dirs) | — | — |
| [base/win32/fusion/appweek/uiviews/comctl32](../../base/win32/fusion/appweek/uiviews/comctl32) | 8 | [base/win32/fusion/appweek/uiviews/comctl32/dirs](../../base/win32/fusion/appweek/uiviews/comctl32/dirs) | — | — |
| [base/win32/fusion/appweek/uiviews/comctl32/resouces](../../base/win32/fusion/appweek/uiviews/comctl32/resouces) | 0 | — | — | — |
| [base/win32/fusion/appweek/uiviews/comctl32/resouces/bins](../../base/win32/fusion/appweek/uiviews/comctl32/resouces/bins) | 1 | — | — | — |
| [base/win32/fusion/appweek/uiviews/comctl32/resouces/icons](../../base/win32/fusion/appweek/uiviews/comctl32/resouces/icons) | 13 | — | — | — |
| [base/win32/fusion/appweek/uiviews/comctl32/v5](../../base/win32/fusion/appweek/uiviews/comctl32/v5) | 2 | [base/win32/fusion/appweek/uiviews/comctl32/v5/sources](../../base/win32/fusion/appweek/uiviews/comctl32/v5/sources), [base/win32/fusion/appweek/uiviews/comctl32/v5/makefile](../../base/win32/fusion/appweek/uiviews/comctl32/v5/makefile) | `sxapwcomctl32_v5` | — |
| [base/win32/fusion/appweek/uiviews/comctl32/v6](../../base/win32/fusion/appweek/uiviews/comctl32/v6) | 3 | [base/win32/fusion/appweek/uiviews/comctl32/v6/sources](../../base/win32/fusion/appweek/uiviews/comctl32/v6/sources), [base/win32/fusion/appweek/uiviews/comctl32/v6/makefile](../../base/win32/fusion/appweek/uiviews/comctl32/v6/makefile) | `sxapwcomctl32_v6` | — |
| [base/win32/fusion/appweek/uiviews/controller](../../base/win32/fusion/appweek/uiviews/controller) | 10 | [base/win32/fusion/appweek/uiviews/controller/sources](../../base/win32/fusion/appweek/uiviews/controller/sources), [base/win32/fusion/appweek/uiviews/controller/makefile](../../base/win32/fusion/appweek/uiviews/controller/makefile) | `sxapwcontroller` | `DYNLINK` |
| [base/win32/fusion/appweek/uiviews/duser](../../base/win32/fusion/appweek/uiviews/duser) | 11 | [base/win32/fusion/appweek/uiviews/duser/sources](../../base/win32/fusion/appweek/uiviews/duser/sources), [base/win32/fusion/appweek/uiviews/duser/makefile](../../base/win32/fusion/appweek/uiviews/duser/makefile) | `sxapwduser` | `DYNLINK` |
| [base/win32/fusion/appweek/uiviews/edit](../../base/win32/fusion/appweek/uiviews/edit) | 6 | [base/win32/fusion/appweek/uiviews/edit/sources](../../base/win32/fusion/appweek/uiviews/edit/sources), [base/win32/fusion/appweek/uiviews/edit/makefile](../../base/win32/fusion/appweek/uiviews/edit/makefile) | `sxapwedit` | `DYNLINK` |
| [base/win32/fusion/appweek/uiviews/gdiplus](../../base/win32/fusion/appweek/uiviews/gdiplus) | 8 | [base/win32/fusion/appweek/uiviews/gdiplus/dirs](../../base/win32/fusion/appweek/uiviews/gdiplus/dirs) | — | — |
| [base/win32/fusion/appweek/uiviews/gdiplus/v0_9](../../base/win32/fusion/appweek/uiviews/gdiplus/v0_9) | 3 | [base/win32/fusion/appweek/uiviews/gdiplus/v0_9/sources](../../base/win32/fusion/appweek/uiviews/gdiplus/v0_9/sources), [base/win32/fusion/appweek/uiviews/gdiplus/v0_9/makefile](../../base/win32/fusion/appweek/uiviews/gdiplus/v0_9/makefile) | `sxapwgdiplus_v0_9` | — |
| [base/win32/fusion/appweek/uiviews/gdiplus/v0_9/i386](../../base/win32/fusion/appweek/uiviews/gdiplus/v0_9/i386) | 2 | — | — | — |
| [base/win32/fusion/appweek/uiviews/gdiplus/v0_9/ia64](../../base/win32/fusion/appweek/uiviews/gdiplus/v0_9/ia64) | 2 | — | — | — |
| [base/win32/fusion/appweek/uiviews/gdiplus/v1_0](../../base/win32/fusion/appweek/uiviews/gdiplus/v1_0) | 3 | [base/win32/fusion/appweek/uiviews/gdiplus/v1_0/sources](../../base/win32/fusion/appweek/uiviews/gdiplus/v1_0/sources), [base/win32/fusion/appweek/uiviews/gdiplus/v1_0/makefile](../../base/win32/fusion/appweek/uiviews/gdiplus/v1_0/makefile) | `sxapwgdiplus_v1_0` | — |
| [base/win32/fusion/appweek/uiviews/gdiplus/vsd](../../base/win32/fusion/appweek/uiviews/gdiplus/vsd) | 2 | [base/win32/fusion/appweek/uiviews/gdiplus/vsd/sources](../../base/win32/fusion/appweek/uiviews/gdiplus/vsd/sources), [base/win32/fusion/appweek/uiviews/gdiplus/vsd/makefile](../../base/win32/fusion/appweek/uiviews/gdiplus/vsd/makefile) | `sxapwgdiplus_vsd` | — |
| [base/win32/fusion/appweek/uiviews/stdout](../../base/win32/fusion/appweek/uiviews/stdout) | 6 | [base/win32/fusion/appweek/uiviews/stdout/sources](../../base/win32/fusion/appweek/uiviews/stdout/sources), [base/win32/fusion/appweek/uiviews/stdout/makefile](../../base/win32/fusion/appweek/uiviews/stdout/makefile) | `sxapwstdout` | `DYNLINK` |
| [base/win32/fusion/debugexts](../../base/win32/fusion/debugexts) | 8 | [base/win32/fusion/debugexts/dirs](../../base/win32/fusion/debugexts/dirs) | — | — |
| [base/win32/fusion/debugexts/dll](../../base/win32/fusion/debugexts/dll) | 3 | [base/win32/fusion/debugexts/dll/sources](../../base/win32/fusion/debugexts/dll/sources), [base/win32/fusion/debugexts/dll/makefile](../../base/win32/fusion/debugexts/dll/makefile) | `fusiondbg` | `DYNLINK` |
| [base/win32/fusion/debugexts/lib](../../base/win32/fusion/debugexts/lib) | 2 | [base/win32/fusion/debugexts/lib/sources](../../base/win32/fusion/debugexts/lib/sources), [base/win32/fusion/debugexts/lib/makefile](../../base/win32/fusion/debugexts/lib/makefile) | `fusiondbglib` | `LIBRARY` |
| [base/win32/fusion/dll](../../base/win32/fusion/dll) | 9 | [base/win32/fusion/dll/dirs](../../base/win32/fusion/dll/dirs) | — | — |
| [base/win32/fusion/dll/whistler](../../base/win32/fusion/dll/whistler) | 15 | [base/win32/fusion/dll/whistler/sources](../../base/win32/fusion/dll/whistler/sources), [base/win32/fusion/dll/whistler/makefile](../../base/win32/fusion/dll/whistler/makefile) | `sxs` | `DYNLINK` |
| [base/win32/fusion/dll/whistler/i386](../../base/win32/fusion/dll/whistler/i386) | 3 | — | — | — |
| [base/win32/fusion/dll/win2000](../../base/win32/fusion/dll/win2000) | 6 | [base/win32/fusion/dll/win2000/sources](../../base/win32/fusion/dll/win2000/sources), [base/win32/fusion/dll/win2000/makefile](../../base/win32/fusion/dll/win2000/makefile) | `sxs2000` | `DYNLINK` |
| [base/win32/fusion/dlldrain](../../base/win32/fusion/dlldrain) | 2 | [base/win32/fusion/dlldrain/sources](../../base/win32/fusion/dlldrain/sources), [base/win32/fusion/dlldrain/makefile](../../base/win32/fusion/dlldrain/makefile) | — | — |
| [base/win32/fusion/eventlog](../../base/win32/fusion/eventlog) | 5 | [base/win32/fusion/eventlog/dirs](../../base/win32/fusion/eventlog/dirs) | — | — |
| [base/win32/fusion/eventlog/whistler](../../base/win32/fusion/eventlog/whistler) | 3 | [base/win32/fusion/eventlog/whistler/sources](../../base/win32/fusion/eventlog/whistler/sources), [base/win32/fusion/eventlog/whistler/makefile](../../base/win32/fusion/eventlog/whistler/makefile) | — | — |
| [base/win32/fusion/eventlog/win2000](../../base/win32/fusion/eventlog/win2000) | 3 | [base/win32/fusion/eventlog/win2000/sources](../../base/win32/fusion/eventlog/win2000/sources), [base/win32/fusion/eventlog/win2000/makefile](../../base/win32/fusion/eventlog/win2000/makefile) | — | — |
| [base/win32/fusion/gencomctlt](../../base/win32/fusion/gencomctlt) | 5 | [base/win32/fusion/gencomctlt/sources](../../base/win32/fusion/gencomctlt/sources), [base/win32/fusion/gencomctlt/makefile](../../base/win32/fusion/gencomctlt/makefile) | `gencomctlt` | `PROGRAM` |
| [base/win32/fusion/id](../../base/win32/fusion/id) | 8 | [base/win32/fusion/id/dirs](../../base/win32/fusion/id/dirs) | — | — |
| [base/win32/fusion/id/whistler](../../base/win32/fusion/id/whistler) | 2 | [base/win32/fusion/id/whistler/sources](../../base/win32/fusion/id/whistler/sources), [base/win32/fusion/id/whistler/makefile](../../base/win32/fusion/id/whistler/makefile) | — | — |
| [base/win32/fusion/id/win2000](../../base/win32/fusion/id/win2000) | 2 | [base/win32/fusion/id/win2000/sources](../../base/win32/fusion/id/win2000/sources), [base/win32/fusion/id/win2000/makefile](../../base/win32/fusion/id/win2000/makefile) | — | — |
| [base/win32/fusion/idl](../../base/win32/fusion/idl) | 4 | [base/win32/fusion/idl/sources](../../base/win32/fusion/idl/sources), [base/win32/fusion/idl/makefile](../../base/win32/fusion/idl/makefile) | — | `NOTARGET` |
| [base/win32/fusion/inc](../../base/win32/fusion/inc) | 74 | — | — | — |
| [base/win32/fusion/installer](../../base/win32/fusion/installer) | 2 | [base/win32/fusion/installer/dirs](../../base/win32/fusion/installer/dirs) | — | — |
| [base/win32/fusion/installer/cache](../../base/win32/fusion/installer/cache) | 3 | [base/win32/fusion/installer/cache/sources](../../base/win32/fusion/installer/cache/sources), [base/win32/fusion/installer/cache/makefile](../../base/win32/fusion/installer/cache/makefile) | `cache` | `LIBRARY` |
| [base/win32/fusion/installer/clrhost](../../base/win32/fusion/installer/clrhost) | 3 | — | — | — |
| [base/win32/fusion/installer/dll](../../base/win32/fusion/installer/dll) | 8 | [base/win32/fusion/installer/dll/sources](../../base/win32/fusion/installer/dll/sources), [base/win32/fusion/installer/dll/makefile](../../base/win32/fusion/installer/dll/makefile) | `fusenet` | `DYNLINK` |
| [base/win32/fusion/installer/download](../../base/win32/fusion/installer/download) | 4 | [base/win32/fusion/installer/download/sources](../../base/win32/fusion/installer/download/sources), [base/win32/fusion/installer/download/makefile](../../base/win32/fusion/installer/download/makefile) | `download` | `LIBRARY` |
| [base/win32/fusion/installer/file](../../base/win32/fusion/installer/file) | 3 | [base/win32/fusion/installer/file/sources](../../base/win32/fusion/installer/file/sources), [base/win32/fusion/installer/file/makefile](../../base/win32/fusion/installer/file/makefile) | `file` | `LIBRARY` |
| [base/win32/fusion/installer/id](../../base/win32/fusion/installer/id) | 10 | [base/win32/fusion/installer/id/sources](../../base/win32/fusion/installer/id/sources), [base/win32/fusion/installer/id/makefile](../../base/win32/fusion/installer/id/makefile) | `id` | `LIBRARY` |
| [base/win32/fusion/installer/idl](../../base/win32/fusion/installer/idl) | 3 | [base/win32/fusion/installer/idl/sources](../../base/win32/fusion/installer/idl/sources), [base/win32/fusion/installer/idl/makefile](../../base/win32/fusion/installer/idl/makefile) | — | `NOTARGET` |
| [base/win32/fusion/installer/includes](../../base/win32/fusion/installer/includes) | 19 | — | — | — |
| [base/win32/fusion/installer/manifest](../../base/win32/fusion/installer/manifest) | 4 | [base/win32/fusion/installer/manifest/sources](../../base/win32/fusion/installer/manifest/sources), [base/win32/fusion/installer/manifest/makefile](../../base/win32/fusion/installer/manifest/makefile) | `manifest` | `LIBRARY` |
| [base/win32/fusion/installer/service](../../base/win32/fusion/installer/service) | 1 | [base/win32/fusion/installer/service/dirs](../../base/win32/fusion/installer/service/dirs) | — | — |
| [base/win32/fusion/installer/service/client](../../base/win32/fusion/installer/service/client) | 3 | [base/win32/fusion/installer/service/client/sources](../../base/win32/fusion/installer/service/client/sources), [base/win32/fusion/installer/service/client/makefile](../../base/win32/fusion/installer/service/client/makefile) | `client` | `PROGRAM` |
| [base/win32/fusion/installer/service/idl](../../base/win32/fusion/installer/service/idl) | 3 | [base/win32/fusion/installer/service/idl/sources](../../base/win32/fusion/installer/service/idl/sources), [base/win32/fusion/installer/service/idl/makefile](../../base/win32/fusion/installer/service/idl/makefile) | — | `NOTARGET` |
| [base/win32/fusion/installer/service/proxy](../../base/win32/fusion/installer/service/proxy) | 6 | [base/win32/fusion/installer/service/proxy/sources](../../base/win32/fusion/installer/service/proxy/sources), [base/win32/fusion/installer/service/proxy/makefile](../../base/win32/fusion/installer/service/proxy/makefile) | `proxy` | `DYNLINK` |
| [base/win32/fusion/installer/service/server](../../base/win32/fusion/installer/service/server) | 16 | [base/win32/fusion/installer/service/server/sources](../../base/win32/fusion/installer/service/server/sources), [base/win32/fusion/installer/service/server/makefile](../../base/win32/fusion/installer/service/server/makefile) | `server` | `PROGRAM` |
| [base/win32/fusion/installer/shell](../../base/win32/fusion/installer/shell) | 1 | [base/win32/fusion/installer/shell/dirs](../../base/win32/fusion/installer/shell/dirs) | — | — |
| [base/win32/fusion/installer/shell/dll](../../base/win32/fusion/installer/shell/dll) | 5 | [base/win32/fusion/installer/shell/dll/sources](../../base/win32/fusion/installer/shell/dll/sources), [base/win32/fusion/installer/shell/dll/makefile](../../base/win32/fusion/installer/shell/dll/makefile) | `fnsshell` | `DYNLINK` |
| [base/win32/fusion/installer/shell/host](../../base/win32/fusion/installer/shell/host) | 3 | [base/win32/fusion/installer/shell/host/sources](../../base/win32/fusion/installer/shell/host/sources), [base/win32/fusion/installer/shell/host/makefile](../../base/win32/fusion/installer/shell/host/makefile) | `host` | `LIBRARY` |
| [base/win32/fusion/installer/shell/includes](../../base/win32/fusion/installer/shell/includes) | 7 | — | — | — |
| [base/win32/fusion/installer/shell/mimefilter](../../base/win32/fusion/installer/shell/mimefilter) | 3 | [base/win32/fusion/installer/shell/mimefilter/sources](../../base/win32/fusion/installer/shell/mimefilter/sources), [base/win32/fusion/installer/shell/mimefilter/makefile](../../base/win32/fusion/installer/shell/mimefilter/makefile) | `mimefilt` | `LIBRARY` |
| [base/win32/fusion/installer/shell/shortcut](../../base/win32/fusion/installer/shell/shortcut) | 13 | [base/win32/fusion/installer/shell/shortcut/sources](../../base/win32/fusion/installer/shell/shortcut/sources), [base/win32/fusion/installer/shell/shortcut/makefile](../../base/win32/fusion/installer/shell/shortcut/makefile) | `shortcut` | `LIBRARY` |
| [base/win32/fusion/installer/tools](../../base/win32/fusion/installer/tools) | 0 | — | — | — |
| [base/win32/fusion/installer/tools/mangen](../../base/win32/fusion/installer/tools/mangen) | 7 | [base/win32/fusion/installer/tools/mangen/sources](../../base/win32/fusion/installer/tools/mangen/sources), [base/win32/fusion/installer/tools/mangen/makefile](../../base/win32/fusion/installer/tools/mangen/makefile) | `mangen` | `PROGRAM` |
| [base/win32/fusion/installer/tools/test](../../base/win32/fusion/installer/tools/test) | 3 | [base/win32/fusion/installer/tools/test/sources](../../base/win32/fusion/installer/tools/test/sources), [base/win32/fusion/installer/tools/test/makefile](../../base/win32/fusion/installer/tools/test/makefile) | `test` | `PROGRAM` |
| [base/win32/fusion/installer/util](../../base/win32/fusion/installer/util) | 4 | [base/win32/fusion/installer/util/sources](../../base/win32/fusion/installer/util/sources), [base/win32/fusion/installer/util/makefile](../../base/win32/fusion/installer/util/makefile) | `util` | `LIBRARY` |
| [base/win32/fusion/oleaut32](../../base/win32/fusion/oleaut32) | 2 | [base/win32/fusion/oleaut32/dirs](../../base/win32/fusion/oleaut32/dirs) | — | — |
| [base/win32/fusion/oleaut32/whistler](../../base/win32/fusion/oleaut32/whistler) | 8 | [base/win32/fusion/oleaut32/whistler/sources](../../base/win32/fusion/oleaut32/whistler/sources), [base/win32/fusion/oleaut32/whistler/makefile](../../base/win32/fusion/oleaut32/whistler/makefile) | `oleaut32` | `DYNLINK` |
| [base/win32/fusion/settings](../../base/win32/fusion/settings) | 8 | [base/win32/fusion/settings/dirs](../../base/win32/fusion/settings/dirs) | — | — |
| [base/win32/fusion/settings/whistler](../../base/win32/fusion/settings/whistler) | 2 | [base/win32/fusion/settings/whistler/sources](../../base/win32/fusion/settings/whistler/sources), [base/win32/fusion/settings/whistler/makefile](../../base/win32/fusion/settings/whistler/makefile) | — | — |
| [base/win32/fusion/sxs](../../base/win32/fusion/sxs) | 115 | [base/win32/fusion/sxs/dirs](../../base/win32/fusion/sxs/dirs) | — | — |
| [base/win32/fusion/sxs/drain](../../base/win32/fusion/sxs/drain) | 3 | [base/win32/fusion/sxs/drain/sources](../../base/win32/fusion/sxs/drain/sources), [base/win32/fusion/sxs/drain/makefile](../../base/win32/fusion/sxs/drain/makefile) | `$(FUSION_BUILD_TYPE_PREFIX)drain` | `LIBRARY` |
| [base/win32/fusion/sxs/whistler](../../base/win32/fusion/sxs/whistler) | 2 | [base/win32/fusion/sxs/whistler/sources](../../base/win32/fusion/sxs/whistler/sources), [base/win32/fusion/sxs/whistler/makefile](../../base/win32/fusion/sxs/whistler/makefile) | — | — |
| [base/win32/fusion/sxs/whistler_2](../../base/win32/fusion/sxs/whistler_2) | 2 | [base/win32/fusion/sxs/whistler_2/sources](../../base/win32/fusion/sxs/whistler_2/sources), [base/win32/fusion/sxs/whistler_2/makefile](../../base/win32/fusion/sxs/whistler_2/makefile) | — | — |
| [base/win32/fusion/sxs/win2000](../../base/win32/fusion/sxs/win2000) | 2 | [base/win32/fusion/sxs/win2000/sources](../../base/win32/fusion/sxs/win2000/sources), [base/win32/fusion/sxs/win2000/makefile](../../base/win32/fusion/sxs/win2000/makefile) | — | — |
| [base/win32/fusion/sxs/win2000_2](../../base/win32/fusion/sxs/win2000_2) | 2 | [base/win32/fusion/sxs/win2000_2/sources](../../base/win32/fusion/sxs/win2000_2/sources), [base/win32/fusion/sxs/win2000_2/makefile](../../base/win32/fusion/sxs/win2000_2/makefile) | — | — |
| [base/win32/fusion/sxsmain](../../base/win32/fusion/sxsmain) | 3 | [base/win32/fusion/sxsmain/dirs](../../base/win32/fusion/sxsmain/dirs) | — | — |
| [base/win32/fusion/sxsmain/whistler](../../base/win32/fusion/sxsmain/whistler) | 2 | [base/win32/fusion/sxsmain/whistler/sources](../../base/win32/fusion/sxsmain/whistler/sources), [base/win32/fusion/sxsmain/whistler/makefile](../../base/win32/fusion/sxsmain/whistler/makefile) | — | — |
| [base/win32/fusion/sxsmain/win2000](../../base/win32/fusion/sxsmain/win2000) | 2 | [base/win32/fusion/sxsmain/win2000/sources](../../base/win32/fusion/sxsmain/win2000/sources), [base/win32/fusion/sxsmain/win2000/makefile](../../base/win32/fusion/sxsmain/win2000/makefile) | — | — |
| [base/win32/fusion/syscompact](../../base/win32/fusion/syscompact) | 3 | [base/win32/fusion/syscompact/sources](../../base/win32/fusion/syscompact/sources), [base/win32/fusion/syscompact/makefile](../../base/win32/fusion/syscompact/makefile) | — | `NOTARGET` |
| [base/win32/fusion/tests](../../base/win32/fusion/tests) | 1 | [base/win32/fusion/tests/dirs](../../base/win32/fusion/tests/dirs) | — | — |
| [base/win32/fusion/tests/jonwis](../../base/win32/fusion/tests/jonwis) | 0 | — | — | — |
| [base/win32/fusion/tests/jonwis/catalogs](../../base/win32/fusion/tests/jonwis/catalogs) | 3 | [base/win32/fusion/tests/jonwis/catalogs/sources](../../base/win32/fusion/tests/jonwis/catalogs/sources), [base/win32/fusion/tests/jonwis/catalogs/makefile](../../base/win32/fusion/tests/jonwis/catalogs/makefile) | `catalogstuff` | `PROGRAM` |
| [base/win32/fusion/tests/jonwis/fastsha1](../../base/win32/fusion/tests/jonwis/fastsha1) | 5 | [base/win32/fusion/tests/jonwis/fastsha1/sources](../../base/win32/fusion/tests/jonwis/fastsha1/sources), [base/win32/fusion/tests/jonwis/fastsha1/makefile](../../base/win32/fusion/tests/jonwis/fastsha1/makefile) | `fastsha1` | `PROGRAM` |
| [base/win32/fusion/tests/jonwis/interop](../../base/win32/fusion/tests/jonwis/interop) | 3 | [base/win32/fusion/tests/jonwis/interop/sources](../../base/win32/fusion/tests/jonwis/interop/sources), [base/win32/fusion/tests/jonwis/interop/makefile](../../base/win32/fusion/tests/jonwis/interop/makefile) | `interoptests` | `PROGRAM` |
| [base/win32/fusion/tests/sxstest](../../base/win32/fusion/tests/sxstest) | 12 | [base/win32/fusion/tests/sxstest/dirs](../../base/win32/fusion/tests/sxstest/dirs) | — | — |
| [base/win32/fusion/tests/sxstest/lib](../../base/win32/fusion/tests/sxstest/lib) | 3 | [base/win32/fusion/tests/sxstest/lib/sources](../../base/win32/fusion/tests/sxstest/lib/sources), [base/win32/fusion/tests/sxstest/lib/makefile](../../base/win32/fusion/tests/sxstest/lib/makefile) | `sxstestlib` | `LIBRARY` |
| [base/win32/fusion/tests/sxstest/testdata](../../base/win32/fusion/tests/sxstest/testdata) | 0 | — | — | — |
| [base/win32/fusion/tests/sxstest/testdata/buildmultifileassembly](../../base/win32/fusion/tests/sxstest/testdata/buildmultifileassembly) | 3 | [base/win32/fusion/tests/sxstest/testdata/buildmultifileassembly/dirs](../../base/win32/fusion/tests/sxstest/testdata/buildmultifileassembly/dirs) | — | — |
| [base/win32/fusion/tests/sxstest/testdata/buildmultifileassembly/1of2](../../base/win32/fusion/tests/sxstest/testdata/buildmultifileassembly/1of2) | 2 | [base/win32/fusion/tests/sxstest/testdata/buildmultifileassembly/1of2/sources](../../base/win32/fusion/tests/sxstest/testdata/buildmultifileassembly/1of2/sources), [base/win32/fusion/tests/sxstest/testdata/buildmultifileassembly/1of2/makefile](../../base/win32/fusion/tests/sxstest/testdata/buildmultifileassembly/1of2/makefile) | `1Of2` | `DYNLINK` |
| [base/win32/fusion/tests/sxstest/testdata/buildmultifileassembly/2of2andmanifest](../../base/win32/fusion/tests/sxstest/testdata/buildmultifileassembly/2of2andmanifest) | 3 | [base/win32/fusion/tests/sxstest/testdata/buildmultifileassembly/2of2andmanifest/sources](../../base/win32/fusion/tests/sxstest/testdata/buildmultifileassembly/2of2andmanifest/sources), [base/win32/fusion/tests/sxstest/testdata/buildmultifileassembly/2of2andmanifest/makefile](../../base/win32/fusion/tests/sxstest/testdata/buildmultifileassembly/2of2andmanifest/makefile) | `2Of2` | `DYNLINK` |
| [base/win32/fusion/tests/sxstest/testdata/hello](../../base/win32/fusion/tests/sxstest/testdata/hello) | 9 | [base/win32/fusion/tests/sxstest/testdata/hello/dirs](../../base/win32/fusion/tests/sxstest/testdata/hello/dirs) | — | — |
| [base/win32/fusion/tests/sxstest/testdata/hello/dll1](../../base/win32/fusion/tests/sxstest/testdata/hello/dll1) | 4 | [base/win32/fusion/tests/sxstest/testdata/hello/dll1/sources](../../base/win32/fusion/tests/sxstest/testdata/hello/dll1/sources), [base/win32/fusion/tests/sxstest/testdata/hello/dll1/makefile](../../base/win32/fusion/tests/sxstest/testdata/hello/dll1/makefile) | — | — |
| [base/win32/fusion/tests/sxstest/testdata/hello/dll2](../../base/win32/fusion/tests/sxstest/testdata/hello/dll2) | 4 | [base/win32/fusion/tests/sxstest/testdata/hello/dll2/sources](../../base/win32/fusion/tests/sxstest/testdata/hello/dll2/sources), [base/win32/fusion/tests/sxstest/testdata/hello/dll2/makefile](../../base/win32/fusion/tests/sxstest/testdata/hello/dll2/makefile) | — | — |
| [base/win32/fusion/tests/sxstest/testdata/hello/exeman1](../../base/win32/fusion/tests/sxstest/testdata/hello/exeman1) | 2 | [base/win32/fusion/tests/sxstest/testdata/hello/exeman1/sources](../../base/win32/fusion/tests/sxstest/testdata/hello/exeman1/sources), [base/win32/fusion/tests/sxstest/testdata/hello/exeman1/makefile](../../base/win32/fusion/tests/sxstest/testdata/hello/exeman1/makefile) | — | — |
| [base/win32/fusion/tests/sxstest/testdata/hello/exeman2](../../base/win32/fusion/tests/sxstest/testdata/hello/exeman2) | 2 | [base/win32/fusion/tests/sxstest/testdata/hello/exeman2/sources](../../base/win32/fusion/tests/sxstest/testdata/hello/exeman2/sources), [base/win32/fusion/tests/sxstest/testdata/hello/exeman2/makefile](../../base/win32/fusion/tests/sxstest/testdata/hello/exeman2/makefile) | — | — |
| [base/win32/fusion/tests/sxstest/testdata/hello/exemultires](../../base/win32/fusion/tests/sxstest/testdata/hello/exemultires) | 8 | [base/win32/fusion/tests/sxstest/testdata/hello/exemultires/sources](../../base/win32/fusion/tests/sxstest/testdata/hello/exemultires/sources), [base/win32/fusion/tests/sxstest/testdata/hello/exemultires/makefile](../../base/win32/fusion/tests/sxstest/testdata/hello/exemultires/makefile) | `MultiExe` | `PROGRAM` |
| [base/win32/fusion/tests/sxstest/testdata/hello/exeres1](../../base/win32/fusion/tests/sxstest/testdata/hello/exeres1) | 2 | [base/win32/fusion/tests/sxstest/testdata/hello/exeres1/sources](../../base/win32/fusion/tests/sxstest/testdata/hello/exeres1/sources), [base/win32/fusion/tests/sxstest/testdata/hello/exeres1/makefile](../../base/win32/fusion/tests/sxstest/testdata/hello/exeres1/makefile) | — | — |
| [base/win32/fusion/tests/sxstest/testdata/hello/exeres2](../../base/win32/fusion/tests/sxstest/testdata/hello/exeres2) | 2 | [base/win32/fusion/tests/sxstest/testdata/hello/exeres2/sources](../../base/win32/fusion/tests/sxstest/testdata/hello/exeres2/sources), [base/win32/fusion/tests/sxstest/testdata/hello/exeres2/makefile](../../base/win32/fusion/tests/sxstest/testdata/hello/exeres2/makefile) | — | — |
| [base/win32/fusion/tests/sxstest/testdata/installs](../../base/win32/fusion/tests/sxstest/testdata/installs) | 0 | — | — | — |
| [base/win32/fusion/tests/sxstest/testdata/installs/bad-1](../../base/win32/fusion/tests/sxstest/testdata/installs/bad-1) | 1 | — | — | — |
| [base/win32/fusion/tests/sxstest/testdata/installs/good-1](../../base/win32/fusion/tests/sxstest/testdata/installs/good-1) | 2 | — | — | — |
| [base/win32/fusion/tests/sxstest/testdata/sxid12](../../base/win32/fusion/tests/sxstest/testdata/sxid12) | 4 | [base/win32/fusion/tests/sxstest/testdata/sxid12/dirs](../../base/win32/fusion/tests/sxstest/testdata/sxid12/dirs), [base/win32/fusion/tests/sxstest/testdata/sxid12/makefile](../../base/win32/fusion/tests/sxstest/testdata/sxid12/makefile) | — | — |
| [base/win32/fusion/tests/sxstest/whistler](../../base/win32/fusion/tests/sxstest/whistler) | 3 | [base/win32/fusion/tests/sxstest/whistler/sources](../../base/win32/fusion/tests/sxstest/whistler/sources), [base/win32/fusion/tests/sxstest/whistler/makefile](../../base/win32/fusion/tests/sxstest/whistler/makefile) | `sxstest` | `PROGLIB` |
| [base/win32/fusion/tests/sxstest/whistler/gauntlet](../../base/win32/fusion/tests/sxstest/whistler/gauntlet) | 1 | — | — | — |
| [base/win32/fusion/tests/sxstest/xpman1](../../base/win32/fusion/tests/sxstest/xpman1) | 3 | [base/win32/fusion/tests/sxstest/xpman1/sources](../../base/win32/fusion/tests/sxstest/xpman1/sources), [base/win32/fusion/tests/sxstest/xpman1/makefile](../../base/win32/fusion/tests/sxstest/xpman1/makefile) | — | — |
| [base/win32/fusion/tests/sxstest/xpman12](../../base/win32/fusion/tests/sxstest/xpman12) | 3 | [base/win32/fusion/tests/sxstest/xpman12/sources](../../base/win32/fusion/tests/sxstest/xpman12/sources), [base/win32/fusion/tests/sxstest/xpman12/makefile](../../base/win32/fusion/tests/sxstest/xpman12/makefile) | — | — |
| [base/win32/fusion/tests/sxstest/xpman13](../../base/win32/fusion/tests/sxstest/xpman13) | 3 | [base/win32/fusion/tests/sxstest/xpman13/sources](../../base/win32/fusion/tests/sxstest/xpman13/sources), [base/win32/fusion/tests/sxstest/xpman13/makefile](../../base/win32/fusion/tests/sxstest/xpman13/makefile) | — | — |
| [base/win32/fusion/tests/sxstest/xpman2](../../base/win32/fusion/tests/sxstest/xpman2) | 3 | [base/win32/fusion/tests/sxstest/xpman2/sources](../../base/win32/fusion/tests/sxstest/xpman2/sources), [base/win32/fusion/tests/sxstest/xpman2/makefile](../../base/win32/fusion/tests/sxstest/xpman2/makefile) | — | — |
| [base/win32/fusion/tests/sxstest/xpman23](../../base/win32/fusion/tests/sxstest/xpman23) | 3 | [base/win32/fusion/tests/sxstest/xpman23/sources](../../base/win32/fusion/tests/sxstest/xpman23/sources), [base/win32/fusion/tests/sxstest/xpman23/makefile](../../base/win32/fusion/tests/sxstest/xpman23/makefile) | — | — |
| [base/win32/fusion/tests/sxstest/xpman3](../../base/win32/fusion/tests/sxstest/xpman3) | 3 | [base/win32/fusion/tests/sxstest/xpman3/sources](../../base/win32/fusion/tests/sxstest/xpman3/sources), [base/win32/fusion/tests/sxstest/xpman3/makefile](../../base/win32/fusion/tests/sxstest/xpman3/makefile) | — | — |
| [base/win32/fusion/tests/sxstest/xpmanfile](../../base/win32/fusion/tests/sxstest/xpmanfile) | 3 | [base/win32/fusion/tests/sxstest/xpmanfile/sources](../../base/win32/fusion/tests/sxstest/xpmanfile/sources), [base/win32/fusion/tests/sxstest/xpmanfile/makefile](../../base/win32/fusion/tests/sxstest/xpmanfile/makefile) | — | — |
| [base/win32/fusion/tools](../../base/win32/fusion/tools) | 8 | [base/win32/fusion/tools/dirs](../../base/win32/fusion/tools/dirs) | — | — |
| [base/win32/fusion/tools/append](../../base/win32/fusion/tools/append) | 3 | [base/win32/fusion/tools/append/sources](../../base/win32/fusion/tools/append/sources), [base/win32/fusion/tools/append/makefile](../../base/win32/fusion/tools/append/makefile) | `appendtool` | `PROGRAM` |
| [base/win32/fusion/tools/buildtool](../../base/win32/fusion/tools/buildtool) | 10 | [base/win32/fusion/tools/buildtool/sources](../../base/win32/fusion/tools/buildtool/sources), [base/win32/fusion/tools/buildtool/makefile](../../base/win32/fusion/tools/buildtool/makefile) | `mt` | `PROGRAM` |
| [base/win32/fusion/tools/catinfo](../../base/win32/fusion/tools/catinfo) | 3 | [base/win32/fusion/tools/catinfo/sources](../../base/win32/fusion/tools/catinfo/sources), [base/win32/fusion/tools/catinfo/makefile](../../base/win32/fusion/tools/catinfo/makefile) | `catinfo` | `PROGRAM` |
| [base/win32/fusion/tools/certinfo](../../base/win32/fusion/tools/certinfo) | 3 | [base/win32/fusion/tools/certinfo/sources](../../base/win32/fusion/tools/certinfo/sources), [base/win32/fusion/tools/certinfo/makefile](../../base/win32/fusion/tools/certinfo/makefile) | `certtool` | `PROGRAM` |
| [base/win32/fusion/tools/clean](../../base/win32/fusion/tools/clean) | 3 | [base/win32/fusion/tools/clean/sources](../../base/win32/fusion/tools/clean/sources), [base/win32/fusion/tools/clean/makefile](../../base/win32/fusion/tools/clean/makefile) | `clean` | `PROGRAM` |
| [base/win32/fusion/tools/copy_bigpath](../../base/win32/fusion/tools/copy_bigpath) | 3 | [base/win32/fusion/tools/copy_bigpath/sources](../../base/win32/fusion/tools/copy_bigpath/sources), [base/win32/fusion/tools/copy_bigpath/makefile](../../base/win32/fusion/tools/copy_bigpath/makefile) | `copy_bigpath` | `PROGRAM` |
| [base/win32/fusion/tools/dir_bigpath](../../base/win32/fusion/tools/dir_bigpath) | 3 | [base/win32/fusion/tools/dir_bigpath/sources](../../base/win32/fusion/tools/dir_bigpath/sources), [base/win32/fusion/tools/dir_bigpath/makefile](../../base/win32/fusion/tools/dir_bigpath/makefile) | `dir_bigpath` | `PROGRAM` |
| [base/win32/fusion/tools/filehasher](../../base/win32/fusion/tools/filehasher) | 3 | [base/win32/fusion/tools/filehasher/sources](../../base/win32/fusion/tools/filehasher/sources), [base/win32/fusion/tools/filehasher/makefile](../../base/win32/fusion/tools/filehasher/makefile) | `shahasher` | `PROGRAM` |
| [base/win32/fusion/tools/fusionmanifestvalidator](../../base/win32/fusion/tools/fusionmanifestvalidator) | 8 | [base/win32/fusion/tools/fusionmanifestvalidator/sources](../../base/win32/fusion/tools/fusionmanifestvalidator/sources), [base/win32/fusion/tools/fusionmanifestvalidator/makefile](../../base/win32/fusion/tools/fusionmanifestvalidator/makefile) | `FusionManifestValidator` | `PROGRAM` |
| [base/win32/fusion/tools/fuslogvw](../../base/win32/fusion/tools/fuslogvw) | 4 | [base/win32/fusion/tools/fuslogvw/dirs](../../base/win32/fusion/tools/fuslogvw/dirs) | — | — |
| [base/win32/fusion/tools/fuslogvw/daytona](../../base/win32/fusion/tools/fuslogvw/daytona) | 2 | [base/win32/fusion/tools/fuslogvw/daytona/sources](../../base/win32/fusion/tools/fuslogvw/daytona/sources), [base/win32/fusion/tools/fuslogvw/daytona/makefile](../../base/win32/fusion/tools/fuslogvw/daytona/makefile) | `FUSLOGVW` | `PROGRAM` |
| [base/win32/fusion/tools/mjgcopy](../../base/win32/fusion/tools/mjgcopy) | 4 | [base/win32/fusion/tools/mjgcopy/dirs](../../base/win32/fusion/tools/mjgcopy/dirs) | — | — |
| [base/win32/fusion/tools/mjgcopy/whistler](../../base/win32/fusion/tools/mjgcopy/whistler) | 2 | [base/win32/fusion/tools/mjgcopy/whistler/sources](../../base/win32/fusion/tools/mjgcopy/whistler/sources), [base/win32/fusion/tools/mjgcopy/whistler/makefile](../../base/win32/fusion/tools/mjgcopy/whistler/makefile) | `mjgcopy` | `PROGRAM` |
| [base/win32/fusion/tools/mjgcopy/win2000](../../base/win32/fusion/tools/mjgcopy/win2000) | 2 | [base/win32/fusion/tools/mjgcopy/win2000/sources](../../base/win32/fusion/tools/mjgcopy/win2000/sources), [base/win32/fusion/tools/mjgcopy/win2000/makefile](../../base/win32/fusion/tools/mjgcopy/win2000/makefile) | `mjgcopy` | `PROGRAM` |
| [base/win32/fusion/tools/mkdir_bigpath](../../base/win32/fusion/tools/mkdir_bigpath) | 3 | [base/win32/fusion/tools/mkdir_bigpath/sources](../../base/win32/fusion/tools/mkdir_bigpath/sources), [base/win32/fusion/tools/mkdir_bigpath/makefile](../../base/win32/fusion/tools/mkdir_bigpath/makefile) | `mkdir_bigpath` | `PROGRAM` |
| [base/win32/fusion/tools/mt](../../base/win32/fusion/tools/mt) | 1 | [base/win32/fusion/tools/mt/dirs](../../base/win32/fusion/tools/mt/dirs) | — | — |
| [base/win32/fusion/tools/mt/whistler](../../base/win32/fusion/tools/mt/whistler) | 2 | [base/win32/fusion/tools/mt/whistler/sources](../../base/win32/fusion/tools/mt/whistler/sources), [base/win32/fusion/tools/mt/whistler/makefile](../../base/win32/fusion/tools/mt/whistler/makefile) | `mt` | `PROGRAM` |
| [base/win32/fusion/tools/pktextract](../../base/win32/fusion/tools/pktextract) | 1 | [base/win32/fusion/tools/pktextract/dirs](../../base/win32/fusion/tools/pktextract/dirs) | — | — |
| [base/win32/fusion/tools/pktextract/bin](../../base/win32/fusion/tools/pktextract/bin) | 3 | [base/win32/fusion/tools/pktextract/bin/sources](../../base/win32/fusion/tools/pktextract/bin/sources), [base/win32/fusion/tools/pktextract/bin/makefile](../../base/win32/fusion/tools/pktextract/bin/makefile) | — | `NOTARGET` |
| [base/win32/fusion/tools/pktextract/ntdll_hak](../../base/win32/fusion/tools/pktextract/ntdll_hak) | 4 | [base/win32/fusion/tools/pktextract/ntdll_hak/sources](../../base/win32/fusion/tools/pktextract/ntdll_hak/sources), [base/win32/fusion/tools/pktextract/ntdll_hak/makefile](../../base/win32/fusion/tools/pktextract/ntdll_hak/makefile) | `ntdll` | `DYNLINK` |
| [base/win32/fusion/tools/pktextract/patch](../../base/win32/fusion/tools/pktextract/patch) | 3 | [base/win32/fusion/tools/pktextract/patch/sources](../../base/win32/fusion/tools/pktextract/patch/sources), [base/win32/fusion/tools/pktextract/patch/makefile](../../base/win32/fusion/tools/pktextract/patch/makefile) | `patch` | `PROGRAM` |
| [base/win32/fusion/tools/popcopy](../../base/win32/fusion/tools/popcopy) | 4 | [base/win32/fusion/tools/popcopy/sources](../../base/win32/fusion/tools/popcopy/sources), [base/win32/fusion/tools/popcopy/makefile](../../base/win32/fusion/tools/popcopy/makefile) | `popcopy` | `PROGRAM` |
| [base/win32/fusion/tools/powercopy](../../base/win32/fusion/tools/powercopy) | 3 | [base/win32/fusion/tools/powercopy/sources](../../base/win32/fusion/tools/powercopy/sources), [base/win32/fusion/tools/powercopy/makefile](../../base/win32/fusion/tools/powercopy/makefile) | `powercopy` | `PROGRAM` |
| [base/win32/fusion/tools/preprocessor](../../base/win32/fusion/tools/preprocessor) | 6 | [base/win32/fusion/tools/preprocessor/sources](../../base/win32/fusion/tools/preprocessor/sources), [base/win32/fusion/tools/preprocessor/makefile](../../base/win32/fusion/tools/preprocessor/makefile) | `preprocessor` | `PROGRAM` |
| [base/win32/fusion/tools/resourcetool](../../base/win32/fusion/tools/resourcetool) | 7 | [base/win32/fusion/tools/resourcetool/sources](../../base/win32/fusion/tools/resourcetool/sources), [base/win32/fusion/tools/resourcetool/makefile](../../base/win32/fusion/tools/resourcetool/makefile) | `resourcetool` | `PROGRAM` |
| [base/win32/fusion/tools/sharinghazardcheck](../../base/win32/fusion/tools/sharinghazardcheck) | 6 | [base/win32/fusion/tools/sharinghazardcheck/sources](../../base/win32/fusion/tools/sharinghazardcheck/sources), [base/win32/fusion/tools/sharinghazardcheck/makefile](../../base/win32/fusion/tools/sharinghazardcheck/makefile) | `ShHazChk` | `PROGRAM` |
| [base/win32/fusion/tools/st](../../base/win32/fusion/tools/st) | 18 | [base/win32/fusion/tools/st/dirs](../../base/win32/fusion/tools/st/dirs) | — | — |
| [base/win32/fusion/tools/st/whistler](../../base/win32/fusion/tools/st/whistler) | 2 | [base/win32/fusion/tools/st/whistler/sources](../../base/win32/fusion/tools/st/whistler/sources), [base/win32/fusion/tools/st/whistler/makefile](../../base/win32/fusion/tools/st/whistler/makefile) | `st` | `PROGRAM` |
| [base/win32/fusion/tools/sxspad](../../base/win32/fusion/tools/sxspad) | 17 | [base/win32/fusion/tools/sxspad/sources](../../base/win32/fusion/tools/sxspad/sources), [base/win32/fusion/tools/sxspad/makefile](../../base/win32/fusion/tools/sxspad/makefile) | `SxSPad` | `PROGRAM` |
| [base/win32/fusion/tools/tabstospaces](../../base/win32/fusion/tools/tabstospaces) | 3 | [base/win32/fusion/tools/tabstospaces/sources](../../base/win32/fusion/tools/tabstospaces/sources), [base/win32/fusion/tools/tabstospaces/makefile](../../base/win32/fusion/tools/tabstospaces/makefile) | `tabstospaces` | `PROGRAM` |
| [base/win32/fusion/tools/template](../../base/win32/fusion/tools/template) | 4 | [base/win32/fusion/tools/template/dirs](../../base/win32/fusion/tools/template/dirs) | — | — |
| [base/win32/fusion/tools/template/whistler](../../base/win32/fusion/tools/template/whistler) | 2 | [base/win32/fusion/tools/template/whistler/sources](../../base/win32/fusion/tools/template/whistler/sources), [base/win32/fusion/tools/template/whistler/makefile](../../base/win32/fusion/tools/template/whistler/makefile) | `tool` | `PROGRAM` |
| [base/win32/fusion/utils](../../base/win32/fusion/utils) | 23 | [base/win32/fusion/utils/dirs](../../base/win32/fusion/utils/dirs) | — | — |
| [base/win32/fusion/utils/whistler](../../base/win32/fusion/utils/whistler) | 2 | [base/win32/fusion/utils/whistler/sources](../../base/win32/fusion/utils/whistler/sources), [base/win32/fusion/utils/whistler/makefile](../../base/win32/fusion/utils/whistler/makefile) | — | — |
| [base/win32/fusion/utils/win2000](../../base/win32/fusion/utils/win2000) | 2 | [base/win32/fusion/utils/win2000/sources](../../base/win32/fusion/utils/win2000/sources), [base/win32/fusion/utils/win2000/makefile](../../base/win32/fusion/utils/win2000/makefile) | — | — |
| [base/win32/fusion/uuid](../../base/win32/fusion/uuid) | 6 | [base/win32/fusion/uuid/dirs](../../base/win32/fusion/uuid/dirs) | — | — |
| [base/win32/fusion/uuid/whistler](../../base/win32/fusion/uuid/whistler) | 2 | [base/win32/fusion/uuid/whistler/sources](../../base/win32/fusion/uuid/whistler/sources), [base/win32/fusion/uuid/whistler/makefile](../../base/win32/fusion/uuid/whistler/makefile) | — | — |
| [base/win32/fusion/uuid/win2000](../../base/win32/fusion/uuid/win2000) | 2 | [base/win32/fusion/uuid/win2000/sources](../../base/win32/fusion/uuid/win2000/sources), [base/win32/fusion/uuid/win2000/makefile](../../base/win32/fusion/uuid/win2000/makefile) | — | — |
| [base/win32/fusion/viewer](../../base/win32/fusion/viewer) | 0 | — | — | — |
| [base/win32/fusion/viewer/assembly](../../base/win32/fusion/viewer/assembly) | 1 | — | — | — |
| [base/win32/fusion/viewer/res](../../base/win32/fusion/viewer/res) | 9 | — | — | — |
| [base/win32/fusion/w32](../../base/win32/fusion/w32) | 17 | [base/win32/fusion/w32/dirs](../../base/win32/fusion/w32/dirs) | — | — |
| [base/win32/fusion/w32/whistler](../../base/win32/fusion/w32/whistler) | 2 | [base/win32/fusion/w32/whistler/sources](../../base/win32/fusion/w32/whistler/sources), [base/win32/fusion/w32/whistler/makefile](../../base/win32/fusion/w32/whistler/makefile) | — | — |
| [base/win32/fusion/xml](../../base/win32/fusion/xml) | 4 | [base/win32/fusion/xml/dirs](../../base/win32/fusion/xml/dirs) | — | — |
| [base/win32/fusion/xml/whistler](../../base/win32/fusion/xml/whistler) | 2 | [base/win32/fusion/xml/whistler/sources](../../base/win32/fusion/xml/whistler/sources), [base/win32/fusion/xml/whistler/makefile](../../base/win32/fusion/xml/whistler/makefile) | — | — |
| [base/win32/fusion/xml/win2000](../../base/win32/fusion/xml/win2000) | 2 | [base/win32/fusion/xml/win2000/sources](../../base/win32/fusion/xml/win2000/sources), [base/win32/fusion/xml/win2000/makefile](../../base/win32/fusion/xml/win2000/makefile) | — | — |
| [base/win32/fusion/xmlparser](../../base/win32/fusion/xmlparser) | 24 | [base/win32/fusion/xmlparser/dirs](../../base/win32/fusion/xmlparser/dirs) | — | — |
| [base/win32/fusion/xmlparser/whistler](../../base/win32/fusion/xmlparser/whistler) | 2 | [base/win32/fusion/xmlparser/whistler/sources](../../base/win32/fusion/xmlparser/whistler/sources), [base/win32/fusion/xmlparser/whistler/makefile](../../base/win32/fusion/xmlparser/whistler/makefile) | — | — |
| [base/win32/fusion/xmlparser/win2000](../../base/win32/fusion/xmlparser/win2000) | 2 | [base/win32/fusion/xmlparser/win2000/sources](../../base/win32/fusion/xmlparser/win2000/sources), [base/win32/fusion/xmlparser/win2000/makefile](../../base/win32/fusion/xmlparser/win2000/makefile) | — | — |
| [base/win32/inc](../../base/win32/inc) | 3 | — | — | — |
| [base/win32/lz32](../../base/win32/lz32) | 1 | [base/win32/lz32/dirs](../../base/win32/lz32/dirs) | — | — |
| [base/win32/lz32/embedded](../../base/win32/lz32/embedded) | 3 | [base/win32/lz32/embedded/sources](../../base/win32/lz32/embedded/sources), [base/win32/lz32/embedded/makefile](../../base/win32/lz32/embedded/makefile) | — | `NOTARGET` |
| [base/win32/lz32/lz32_forwarder](../../base/win32/lz32/lz32_forwarder) | 4 | [base/win32/lz32/lz32_forwarder/sources](../../base/win32/lz32/lz32_forwarder/sources), [base/win32/lz32/lz32_forwarder/makefile](../../base/win32/lz32/lz32_forwarder/makefile) | `lz32` | `DYNLINK` |
| [base/win32/lz32/tools](../../base/win32/lz32/tools) | 4 | [base/win32/lz32/tools/dirs](../../base/win32/lz32/tools/dirs) | — | — |
| [base/win32/lz32/tools/compress](../../base/win32/lz32/tools/compress) | 7 | [base/win32/lz32/tools/compress/sources](../../base/win32/lz32/tools/compress/sources), [base/win32/lz32/tools/compress/makefile](../../base/win32/lz32/tools/compress/makefile) | `compress` | `PROGRAM` |
| [base/win32/lz32/tools/expand](../../base/win32/lz32/tools/expand) | 7 | [base/win32/lz32/tools/expand/sources](../../base/win32/lz32/tools/expand/sources), [base/win32/lz32/tools/expand/makefile](../../base/win32/lz32/tools/expand/makefile) | `expand` | `PROGRAM` |
| [base/win32/lz32/winlza](../../base/win32/lz32/winlza) | 19 | [base/win32/lz32/winlza/sources](../../base/win32/lz32/winlza/sources), [base/win32/lz32/winlza/makefile](../../base/win32/lz32/winlza/makefile) | `winlza` | `LIBRARY` |
| [base/win32/server](../../base/win32/server) | 17 | [base/win32/server/sources](../../base/win32/server/sources), [base/win32/server/makefile](../../base/win32/server/makefile) | `basesrv` | `DYNLINK` |
| [base/win32/verifier](../../base/win32/verifier) | 20 | [base/win32/verifier/sources](../../base/win32/verifier/sources), [base/win32/verifier/makefile](../../base/win32/verifier/makefile) | `verifier` | `DYNLINK` |
| [base/win32/winnls](../../base/win32/winnls) | 26 | [base/win32/winnls/dirs](../../base/win32/winnls/dirs) | — | — |
| [base/win32/winnls/cht](../../base/win32/winnls/cht) | 4 | [base/win32/winnls/cht/sources](../../base/win32/winnls/cht/sources), [base/win32/winnls/cht/makefile](../../base/win32/winnls/cht/makefile) | — | `NOTARGET` |
| [base/win32/winnls/data](../../base/win32/winnls/data) | 1 | [base/win32/winnls/data/dirs](../../base/win32/winnls/data/dirs) | — | — |
| [base/win32/winnls/data/codepage](../../base/win32/winnls/data/codepage) | 2 | [base/win32/winnls/data/codepage/sources](../../base/win32/winnls/data/codepage/sources), [base/win32/winnls/data/codepage/makefile](../../base/win32/winnls/data/codepage/makefile) | — | `NOTARGET` |
| [base/win32/winnls/data/codepage/ansi](../../base/win32/winnls/data/codepage/ansi) | 28 | — | — | — |
| [base/win32/winnls/data/codepage/ebcdic](../../base/win32/winnls/data/codepage/ebcdic) | 68 | — | — | — |
| [base/win32/winnls/data/codepage/extra](../../base/win32/winnls/data/codepage/extra) | 30 | — | — | — |
| [base/win32/winnls/data/codepage/ia5](../../base/win32/winnls/data/codepage/ia5) | 8 | — | — | — |
| [base/win32/winnls/data/codepage/iso](../../base/win32/winnls/data/codepage/iso) | 24 | — | — | — |
| [base/win32/winnls/data/codepage/mac](../../base/win32/winnls/data/codepage/mac) | 32 | — | — | — |
| [base/win32/winnls/data/codepage/oem](../../base/win32/winnls/data/codepage/oem) | 32 | — | — | — |
| [base/win32/winnls/data/dlls](../../base/win32/winnls/data/dlls) | 2 | [base/win32/winnls/data/dlls/dirs](../../base/win32/winnls/data/dlls/dirs) | — | — |
| [base/win32/winnls/data/dlls/euc_db](../../base/win32/winnls/data/dlls/euc_db) | 5 | [base/win32/winnls/data/dlls/euc_db/sources](../../base/win32/winnls/data/dlls/euc_db/sources), [base/win32/winnls/data/dlls/euc_db/makefile](../../base/win32/winnls/data/dlls/euc_db/makefile) | `c_eucdb` | `DYNLINK` |
| [base/win32/winnls/data/dlls/gb18030](../../base/win32/winnls/data/dlls/gb18030) | 8 | [base/win32/winnls/data/dlls/gb18030/sources](../../base/win32/winnls/data/dlls/gb18030/sources), [base/win32/winnls/data/dlls/gb18030/makefile](../../base/win32/winnls/data/dlls/gb18030/makefile) | `c_g18030` | `DYNLINK` |
| [base/win32/winnls/data/dlls/gb18030/scripts](../../base/win32/winnls/data/dlls/gb18030/scripts) | 4 | — | — | — |
| [base/win32/winnls/data/dlls/iscii](../../base/win32/winnls/data/dlls/iscii) | 7 | [base/win32/winnls/data/dlls/iscii/sources](../../base/win32/winnls/data/dlls/iscii/sources), [base/win32/winnls/data/dlls/iscii/makefile](../../base/win32/winnls/data/dlls/iscii/makefile) | `c_iscii` | `DYNLINK` |
| [base/win32/winnls/data/dlls/iso_2022](../../base/win32/winnls/data/dlls/iso_2022) | 5 | [base/win32/winnls/data/dlls/iso_2022/sources](../../base/win32/winnls/data/dlls/iso_2022/sources), [base/win32/winnls/data/dlls/iso_2022/makefile](../../base/win32/winnls/data/dlls/iso_2022/makefile) | `c_is2022` | `DYNLINK` |
| [base/win32/winnls/data/dlls/nls](../../base/win32/winnls/data/dlls/nls) | 22 | [base/win32/winnls/data/dlls/nls/sources](../../base/win32/winnls/data/dlls/nls/sources), [base/win32/winnls/data/dlls/nls/makefile](../../base/win32/winnls/data/dlls/nls/makefile) | — | `NOTARGET` |
| [base/win32/winnls/data/dlls/sna_db](../../base/win32/winnls/data/dlls/sna_db) | 5 | [base/win32/winnls/data/dlls/sna_db/sources](../../base/win32/winnls/data/dlls/sna_db/sources), [base/win32/winnls/data/dlls/sna_db/makefile](../../base/win32/winnls/data/dlls/sna_db/makefile) | `c_snadb` | `DYNLINK` |
| [base/win32/winnls/data/dlls/template](../../base/win32/winnls/data/dlls/template) | 5 | [base/win32/winnls/data/dlls/template/sources](../../base/win32/winnls/data/dlls/template/sources), [base/win32/winnls/data/dlls/template/makefile](../../base/win32/winnls/data/dlls/template/makefile) | `c_other` | `DYNLINK` |
| [base/win32/winnls/data/dlls/tools](../../base/win32/winnls/data/dlls/tools) | 1 | [base/win32/winnls/data/dlls/tools/dirs](../../base/win32/winnls/data/dlls/tools/dirs) | — | — |
| [base/win32/winnls/data/dlls/tools/gb18030](../../base/win32/winnls/data/dlls/tools/gb18030) | 1 | [base/win32/winnls/data/dlls/tools/gb18030/dirs](../../base/win32/winnls/data/dlls/tools/gb18030/dirs) | — | — |
| [base/win32/winnls/data/dlls/tools/gb18030/gbunicnv](../../base/win32/winnls/data/dlls/tools/gb18030/gbunicnv) | 24 | [base/win32/winnls/data/dlls/tools/gb18030/gbunicnv/sources](../../base/win32/winnls/data/dlls/tools/gb18030/gbunicnv/sources), [base/win32/winnls/data/dlls/tools/gb18030/gbunicnv/makefile](../../base/win32/winnls/data/dlls/tools/gb18030/gbunicnv/makefile) | `GBUniCnv` | `PROGRAM` |
| [base/win32/winnls/data/dlls/tools/gb18030/gbunicnv/res](../../base/win32/winnls/data/dlls/tools/gb18030/gbunicnv/res) | 2 | — | — | — |
| [base/win32/winnls/data/embedded](../../base/win32/winnls/data/embedded) | 2 | [base/win32/winnls/data/embedded/sources](../../base/win32/winnls/data/embedded/sources), [base/win32/winnls/data/embedded/makefile](../../base/win32/winnls/data/embedded/makefile) | — | `NOTARGET` |
| [base/win32/winnls/data/embedded/cp](../../base/win32/winnls/data/embedded/cp) | 123 | — | — | — |
| [base/win32/winnls/data/embedded/lang](../../base/win32/winnls/data/embedded/lang) | 138 | — | — | — |
| [base/win32/winnls/data/embedded/langsupport](../../base/win32/winnls/data/embedded/langsupport) | 24 | — | — | — |
| [base/win32/winnls/data/embedded/nls](../../base/win32/winnls/data/embedded/nls) | 3 | — | — | — |
| [base/win32/winnls/data/embedded/prototypes](../../base/win32/winnls/data/embedded/prototypes) | 4 | — | — | — |
| [base/win32/winnls/data/embedded/userlocale](../../base/win32/winnls/data/embedded/userlocale) | 135 | — | — | — |
| [base/win32/winnls/data/other](../../base/win32/winnls/data/other) | 16 | [base/win32/winnls/data/other/sources](../../base/win32/winnls/data/other/sources), [base/win32/winnls/data/other/makefile](../../base/win32/winnls/data/other/makefile) | — | `NOTARGET` |
| [base/win32/winnls/data/sorting](../../base/win32/winnls/data/sorting) | 17 | [base/win32/winnls/data/sorting/sources](../../base/win32/winnls/data/sorting/sources), [base/win32/winnls/data/sorting/makefile](../../base/win32/winnls/data/sorting/makefile) | — | `NOTARGET` |
| [base/win32/winnls/data/tools](../../base/win32/winnls/data/tools) | 0 | — | — | — |
| [base/win32/winnls/data/tools/nlsplus](../../base/win32/winnls/data/tools/nlsplus) | 0 | — | — | — |
| [base/win32/winnls/data/tools/nlsplus/casing](../../base/win32/winnls/data/tools/nlsplus/casing) | 4 | — | — | — |
| [base/win32/winnls/data/tools/nlsplus/culture](../../base/win32/winnls/data/tools/nlsplus/culture) | 10 | — | — | — |
| [base/win32/winnls/data/tools/nlsplus/encodingtable](../../base/win32/winnls/data/tools/nlsplus/encodingtable) | 7 | [base/win32/winnls/data/tools/nlsplus/encodingtable/sources](../../base/win32/winnls/data/tools/nlsplus/encodingtable/sources), [base/win32/winnls/data/tools/nlsplus/encodingtable/makefile](../../base/win32/winnls/data/tools/nlsplus/encodingtable/makefile) | `GenEncodingCpp` | `PROGRAM` |
| [base/win32/winnls/data/tools/nlsplus/nlstrans](../../base/win32/winnls/data/tools/nlsplus/nlstrans) | 2 | — | — | — |
| [base/win32/winnls/data/tools/nlsplus/sorting](../../base/win32/winnls/data/tools/nlsplus/sorting) | 3 | — | — | — |
| [base/win32/winnls/data/tools/nlsplus/unicodecategory](../../base/win32/winnls/data/tools/nlsplus/unicodecategory) | 6 | — | — | — |
| [base/win32/winnls/daytona](../../base/win32/winnls/daytona) | 2 | [base/win32/winnls/daytona/sources](../../base/win32/winnls/daytona/sources), [base/win32/winnls/daytona/makefile](../../base/win32/winnls/daytona/makefile) | — | — |
| [base/win32/winnls/fontsup](../../base/win32/winnls/fontsup) | 3 | — | — | — |
| [base/win32/winnls/fontsup/appfonts](../../base/win32/winnls/fontsup/appfonts) | 8 | — | — | — |
| [base/win32/winnls/fontsup/system](../../base/win32/winnls/fontsup/system) | 42 | — | — | — |
| [base/win32/winnls/fontsup/system32](../../base/win32/winnls/fontsup/system32) | 1 | — | — | — |
| [base/win32/winnls/fontsup/x86](../../base/win32/winnls/fontsup/x86) | 5 | — | — | — |
| [base/win32/winnls/hydra](../../base/win32/winnls/hydra) | 2 | [base/win32/winnls/hydra/sources](../../base/win32/winnls/hydra/sources), [base/win32/winnls/hydra/makefile](../../base/win32/winnls/hydra/makefile) | — | — |
| [base/win32/winnls/nlstrans](../../base/win32/winnls/nlstrans) | 15 | [base/win32/winnls/nlstrans/sources](../../base/win32/winnls/nlstrans/sources), [base/win32/winnls/nlstrans/makefile](../../base/win32/winnls/nlstrans/makefile) | `nlstrans` | `PROGRAM` |
| [base/win32/winnls/test](../../base/win32/winnls/test) | 0 | — | — | — |
| [base/win32/winnls/test/gb18030](../../base/win32/winnls/test/gb18030) | 3 | [base/win32/winnls/test/gb18030/sources](../../base/win32/winnls/test/gb18030/sources), [base/win32/winnls/test/gb18030/makefile](../../base/win32/winnls/test/gb18030/makefile) | `gb18030Regressions` | `LIBRARY` |
| [base/win32/winnls/test/nlstest](../../base/win32/winnls/test/nlstest) | 31 | [base/win32/winnls/test/nlstest/sources](../../base/win32/winnls/test/nlstest/sources), [base/win32/winnls/test/nlstest/makefile](../../base/win32/winnls/test/nlstest/makefile) | `nlstest` | `LIBRARY` |
| [base/win32/winnls/wow64](../../base/win32/winnls/wow64) | 2 | [base/win32/winnls/wow64/sources](../../base/win32/winnls/wow64/sources), [base/win32/winnls/wow64/makefile](../../base/win32/winnls/wow64/makefile) | `csrnls` | `LIBRARY` |
| [base/win32/winnls/wow6432](../../base/win32/winnls/wow6432) | 2 | [base/win32/winnls/wow6432/sources](../../base/win32/winnls/wow6432/sources), [base/win32/winnls/wow6432/makefile](../../base/win32/winnls/wow6432/makefile) | — | — |

## `base/wmi/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [base/wmi](../../base/wmi) | 1 | [base/wmi/dirs](../../base/wmi/dirs) | — | — |
| [base/wmi/bmf2mof](../../base/wmi/bmf2mof) | 5 | [base/wmi/bmf2mof/sources](../../base/wmi/bmf2mof/sources), [base/wmi/bmf2mof/makefile](../../base/wmi/bmf2mof/makefile) | `bmf2mof` | `PROGRAM` |
| [base/wmi/bmof](../../base/wmi/bmof) | 5 | [base/wmi/bmof/dirs](../../base/wmi/bmof/dirs) | — | — |
| [base/wmi/bmof/ansi](../../base/wmi/bmof/ansi) | 2 | [base/wmi/bmof/ansi/sources](../../base/wmi/bmof/ansi/sources), [base/wmi/bmof/ansi/makefile](../../base/wmi/bmof/ansi/makefile) | — | — |
| [base/wmi/bmof/daytona](../../base/wmi/bmof/daytona) | 2 | [base/wmi/bmof/daytona/sources](../../base/wmi/bmof/daytona/sources), [base/wmi/bmof/daytona/makefile](../../base/wmi/bmof/daytona/makefile) | — | — |
| [base/wmi/bmoflocparser](../../base/wmi/bmoflocparser) | 22 | [base/wmi/bmoflocparser/sources](../../base/wmi/bmoflocparser/sources), [base/wmi/bmoflocparser/makefile](../../base/wmi/bmoflocparser/makefile) | `bmofpars` | `DYNLINK` |
| [base/wmi/bmoflocparser/inc](../../base/wmi/bmoflocparser/inc) | 18 | — | — | — |
| [base/wmi/bmoflocparser/inc/esputil](../../base/wmi/bmoflocparser/inc/esputil) | 67 | — | — | — |
| [base/wmi/bmoflocparser/inc/locutil](../../base/wmi/bmoflocparser/inc/locutil) | 60 | — | — | — |
| [base/wmi/bmoflocparser/inc/mit](../../base/wmi/bmoflocparser/inc/mit) | 0 | — | — | — |
| [base/wmi/bmoflocparser/inc/mit/inc](../../base/wmi/bmoflocparser/inc/mit/inc) | 12 | — | — | — |
| [base/wmi/bmoflocparser/inc/mit/mitutil](../../base/wmi/bmoflocparser/inc/mit/mitutil) | 57 | — | — | — |
| [base/wmi/bmoflocparser/inc/parseman](../../base/wmi/bmoflocparser/inc/parseman) | 6 | — | — | — |
| [base/wmi/bmoflocparser/inc/parsers](../../base/wmi/bmoflocparser/inc/parsers) | 0 | — | — | — |
| [base/wmi/bmoflocparser/inc/parsers/parsutil](../../base/wmi/bmoflocparser/inc/parsers/parsutil) | 8 | — | — | — |
| [base/wmi/bmoflocparser/inc/pbase](../../base/wmi/bmoflocparser/inc/pbase) | 12 | — | — | — |
| [base/wmi/bmoflocparser/inc/prodver](../../base/wmi/bmoflocparser/inc/prodver) | 4 | — | — | — |
| [base/wmi/bmoflocparser/lib](../../base/wmi/bmoflocparser/lib) | 0 | — | — | — |
| [base/wmi/bmoflocparser/lib/debug](../../base/wmi/bmoflocparser/lib/debug) | 0 | — | — | — |
| [base/wmi/bmoflocparser/lib/debug/i386](../../base/wmi/bmoflocparser/lib/debug/i386) | 7 | — | — | — |
| [base/wmi/bmoflocparser/lib/retail](../../base/wmi/bmoflocparser/lib/retail) | 0 | — | — | — |
| [base/wmi/bmoflocparser/lib/retail/i386](../../base/wmi/bmoflocparser/lib/retail/i386) | 7 | — | — | — |
| [base/wmi/bmoflocparser/mofd](../../base/wmi/bmoflocparser/mofd) | 1 | — | — | — |
| [base/wmi/bmoflocparser/res](../../base/wmi/bmoflocparser/res) | 1 | — | — | — |
| [base/wmi/bmoflocparser/testdrv](../../base/wmi/bmoflocparser/testdrv) | 5 | [base/wmi/bmoflocparser/testdrv/sources](../../base/wmi/bmoflocparser/testdrv/sources), [base/wmi/bmoflocparser/testdrv/makefile](../../base/wmi/bmoflocparser/testdrv/makefile) | `bmoftest` | `PROGRAM` |
| [base/wmi/bmoflocparser/win32rt](../../base/wmi/bmoflocparser/win32rt) | 8 | — | — | — |
| [base/wmi/cdmprov](../../base/wmi/cdmprov) | 23 | [base/wmi/cdmprov/sources](../../base/wmi/cdmprov/sources), [base/wmi/cdmprov/makefile](../../base/wmi/cdmprov/makefile) | `cdmprov` | `DYNLINK` |
| [base/wmi/cdmprov/driver](../../base/wmi/cdmprov/driver) | 15 | [base/wmi/cdmprov/driver/sources](../../base/wmi/cdmprov/driver/sources), [base/wmi/cdmprov/driver/makefile](../../base/wmi/cdmprov/driver/makefile) | `diagfilt` | `DRIVER` |
| [base/wmi/cdmprov/tests](../../base/wmi/cdmprov/tests) | 3 | — | — | — |
| [base/wmi/cimmap](../../base/wmi/cimmap) | 11 | [base/wmi/cimmap/sources](../../base/wmi/cimmap/sources) | `wmimap` | `DYNLINK` |
| [base/wmi/core](../../base/wmi/core) | 15 | [base/wmi/core/dirs](../../base/wmi/core/dirs) | — | — |
| [base/wmi/core/daytona](../../base/wmi/core/daytona) | 2 | [base/wmi/core/daytona/sources](../../base/wmi/core/daytona/sources), [base/wmi/core/daytona/makefile](../../base/wmi/core/daytona/makefile) | — | — |
| [base/wmi/core/memphis](../../base/wmi/core/memphis) | 2 | [base/wmi/core/memphis/sources](../../base/wmi/core/memphis/sources), [base/wmi/core/memphis/makefile](../../base/wmi/core/memphis/makefile) | — | — |
| [base/wmi/dll](../../base/wmi/dll) | 23 | [base/wmi/dll/dirs](../../base/wmi/dll/dirs) | — | — |
| [base/wmi/dll/daytona](../../base/wmi/dll/daytona) | 2 | [base/wmi/dll/daytona/sources](../../base/wmi/dll/daytona/sources), [base/wmi/dll/daytona/makefile](../../base/wmi/dll/daytona/makefile) | `wmiclnt` | `LIBRARY` |
| [base/wmi/dll/memphis](../../base/wmi/dll/memphis) | 2 | [base/wmi/dll/memphis/sources](../../base/wmi/dll/memphis/sources), [base/wmi/dll/memphis/makefile](../../base/wmi/dll/memphis/makefile) | `wmi` | `DYNLINK` |
| [base/wmi/doc](../../base/wmi/doc) | 2 | — | — | — |
| [base/wmi/drt](../../base/wmi/drt) | 0 | — | — | — |
| [base/wmi/drt/tracelog](../../base/wmi/drt/tracelog) | 2 | — | — | — |
| [base/wmi/drt/tracelog/evntrace](../../base/wmi/drt/tracelog/evntrace) | 3 | [base/wmi/drt/tracelog/evntrace/dirs](../../base/wmi/drt/tracelog/evntrace/dirs) | — | — |
| [base/wmi/drt/tracelog/evntrace/ansi](../../base/wmi/drt/tracelog/evntrace/ansi) | 3 | [base/wmi/drt/tracelog/evntrace/ansi/sources](../../base/wmi/drt/tracelog/evntrace/ansi/sources), [base/wmi/drt/tracelog/evntrace/ansi/makefile](../../base/wmi/drt/tracelog/evntrace/ansi/makefile) | — | — |
| [base/wmi/drt/tracelog/evntrace/unicode](../../base/wmi/drt/tracelog/evntrace/unicode) | 3 | [base/wmi/drt/tracelog/evntrace/unicode/sources](../../base/wmi/drt/tracelog/evntrace/unicode/sources), [base/wmi/drt/tracelog/evntrace/unicode/makefile](../../base/wmi/drt/tracelog/evntrace/unicode/makefile) | — | — |
| [base/wmi/drt/tracelog/provider](../../base/wmi/drt/tracelog/provider) | 5 | [base/wmi/drt/tracelog/provider/dirs](../../base/wmi/drt/tracelog/provider/dirs) | — | — |
| [base/wmi/drt/tracelog/provider/ansi](../../base/wmi/drt/tracelog/provider/ansi) | 3 | [base/wmi/drt/tracelog/provider/ansi/sources](../../base/wmi/drt/tracelog/provider/ansi/sources), [base/wmi/drt/tracelog/provider/ansi/makefile](../../base/wmi/drt/tracelog/provider/ansi/makefile) | — | — |
| [base/wmi/drt/tracelog/provider/unicode](../../base/wmi/drt/tracelog/provider/unicode) | 3 | [base/wmi/drt/tracelog/provider/unicode/sources](../../base/wmi/drt/tracelog/provider/unicode/sources), [base/wmi/drt/tracelog/provider/unicode/makefile](../../base/wmi/drt/tracelog/provider/unicode/makefile) | — | — |
| [base/wmi/drt/tracelog/regress](../../base/wmi/drt/tracelog/regress) | 10 | — | — | — |
| [base/wmi/drt/wmi](../../base/wmi/drt/wmi) | 0 | — | — | — |
| [base/wmi/drt/wmi/sniff](../../base/wmi/drt/wmi/sniff) | 1 | — | — | — |
| [base/wmi/drt/wmi/sniff/i386](../../base/wmi/drt/wmi/sniff/i386) | 8 | — | — | — |
| [base/wmi/enumguid](../../base/wmi/enumguid) | 23 | [base/wmi/enumguid/sources](../../base/wmi/enumguid/sources), [base/wmi/enumguid/makefile](../../base/wmi/enumguid/makefile) | `enumguid` | `PROGRAM` |
| [base/wmi/enumguid/res](../../base/wmi/enumguid/res) | 2 | — | — | — |
| [base/wmi/exe](../../base/wmi/exe) | 4 | [base/wmi/exe/dirs](../../base/wmi/exe/dirs) | — | — |
| [base/wmi/exe/daytona](../../base/wmi/exe/daytona) | 2 | [base/wmi/exe/daytona/sources](../../base/wmi/exe/daytona/sources), [base/wmi/exe/daytona/makefile](../../base/wmi/exe/daytona/makefile) | — | — |
| [base/wmi/exe/memphis](../../base/wmi/exe/memphis) | 2 | [base/wmi/exe/memphis/sources](../../base/wmi/exe/memphis/sources), [base/wmi/exe/memphis/makefile](../../base/wmi/exe/memphis/makefile) | — | — |
| [base/wmi/fchba](../../base/wmi/fchba) | 0 | — | — | — |
| [base/wmi/fchba/driver](../../base/wmi/fchba/driver) | 10 | [base/wmi/fchba/driver/sources](../../base/wmi/fchba/driver/sources), [base/wmi/fchba/driver/makefile](../../base/wmi/fchba/driver/makefile) | `hbatest` | `DRIVER` |
| [base/wmi/fchba/hbaapi](../../base/wmi/fchba/hbaapi) | 8 | [base/wmi/fchba/hbaapi/makefile](../../base/wmi/fchba/hbaapi/makefile) | — | — |
| [base/wmi/fchba/inc](../../base/wmi/fchba/inc) | 2 | — | — | — |
| [base/wmi/fchba/mof](../../base/wmi/fchba/mof) | 3 | — | — | — |
| [base/wmi/fchba/testapp](../../base/wmi/fchba/testapp) | 3 | [base/wmi/fchba/testapp/sources](../../base/wmi/fchba/testapp/sources), [base/wmi/fchba/testapp/makefile](../../base/wmi/fchba/testapp/makefile) | `hbatest` | `PROGRAM` |
| [base/wmi/inc](../../base/wmi/inc) | 7 | — | — | — |
| [base/wmi/mof](../../base/wmi/mof) | 3 | — | — | — |
| [base/wmi/mofcheck](../../base/wmi/mofcheck) | 5 | [base/wmi/mofcheck/sources](../../base/wmi/mofcheck/sources), [base/wmi/mofcheck/makefile](../../base/wmi/mofcheck/makefile) | `wmimofck` | `PROGRAM` |
| [base/wmi/mofread](../../base/wmi/mofread) | 3 | [base/wmi/mofread/sources](../../base/wmi/mofread/sources), [base/wmi/mofread/makefile](../../base/wmi/mofread/makefile) | `mofread` | `PROGRAM` |
| [base/wmi/ntdll](../../base/wmi/ntdll) | 18 | [base/wmi/ntdll/sources](../../base/wmi/ntdll/sources), [base/wmi/ntdll/makefile](../../base/wmi/ntdll/makefile) | `etwclnt` | `LIBRARY` |
| [base/wmi/proppage](../../base/wmi/proppage) | 9 | [base/wmi/proppage/sources](../../base/wmi/proppage/sources), [base/wmi/proppage/makefile](../../base/wmi/proppage/makefile) | `wmiprop` | `DYNLINK` |
| [base/wmi/tests](../../base/wmi/tests) | 1 | [base/wmi/tests/dirs](../../base/wmi/tests/dirs) | — | — |
| [base/wmi/tests/acpimap](../../base/wmi/tests/acpimap) | 5 | [base/wmi/tests/acpimap/sources](../../base/wmi/tests/acpimap/sources), [base/wmi/tests/acpimap/makefile](../../base/wmi/tests/acpimap/makefile) | `acpimap` | `PROGRAM` |
| [base/wmi/tests/dc1](../../base/wmi/tests/dc1) | 3 | [base/wmi/tests/dc1/sources](../../base/wmi/tests/dc1/sources), [base/wmi/tests/dc1/makefile](../../base/wmi/tests/dc1/makefile) | `dc1` | `PROGRAM` |
| [base/wmi/tests/devinst](../../base/wmi/tests/devinst) | 3 | [base/wmi/tests/devinst/sources](../../base/wmi/tests/devinst/sources), [base/wmi/tests/devinst/makefile](../../base/wmi/tests/devinst/makefile) | `devinst` | `PROGRAM` |
| [base/wmi/tests/diskperf](../../base/wmi/tests/diskperf) | 3 | [base/wmi/tests/diskperf/sources](../../base/wmi/tests/diskperf/sources), [base/wmi/tests/diskperf/makefile](../../base/wmi/tests/diskperf/makefile) | `dpdump` | `PROGRAM` |
| [base/wmi/tests/docs](../../base/wmi/tests/docs) | 3 | — | — | — |
| [base/wmi/tests/genmcas](../../base/wmi/tests/genmcas) | 3 | [base/wmi/tests/genmcas/sources](../../base/wmi/tests/genmcas/sources), [base/wmi/tests/genmcas/makefile](../../base/wmi/tests/genmcas/makefile) | `genmcas` | `PROGRAM` |
| [base/wmi/tests/logger](../../base/wmi/tests/logger) | 38 | [base/wmi/tests/logger/sources](../../base/wmi/tests/logger/sources), [base/wmi/tests/logger/makefile](../../base/wmi/tests/logger/makefile) | `CollectionControl` | `PROGRAM` |
| [base/wmi/tests/mcegen](../../base/wmi/tests/mcegen) | 3 | [base/wmi/tests/mcegen/sources](../../base/wmi/tests/mcegen/sources), [base/wmi/tests/mcegen/makefile](../../base/wmi/tests/mcegen/makefile) | `mcegen` | `PROGRAM` |
| [base/wmi/tests/perfhit](../../base/wmi/tests/perfhit) | 3 | [base/wmi/tests/perfhit/sources](../../base/wmi/tests/perfhit/sources), [base/wmi/tests/perfhit/makefile](../../base/wmi/tests/perfhit/makefile) | `perfhit` | `PROGRAM` |
| [base/wmi/tests/rcvevent](../../base/wmi/tests/rcvevent) | 3 | [base/wmi/tests/rcvevent/sources](../../base/wmi/tests/rcvevent/sources), [base/wmi/tests/rcvevent/makefile](../../base/wmi/tests/rcvevent/makefile) | `getevent` | `PROGRAM` |
| [base/wmi/tests/reducer](../../base/wmi/tests/reducer) | 4 | [base/wmi/tests/reducer/sources](../../base/wmi/tests/reducer/sources), [base/wmi/tests/reducer/makefile](../../base/wmi/tests/reducer/makefile) | `reducer` | `UMAPPL_NOLIB` |
| [base/wmi/tests/testqm](../../base/wmi/tests/testqm) | 3 | [base/wmi/tests/testqm/sources](../../base/wmi/tests/testqm/sources), [base/wmi/tests/testqm/makefile](../../base/wmi/tests/testqm/makefile) | `testqm` | `PROGRAM` |
| [base/wmi/tests/umtrprov](../../base/wmi/tests/umtrprov) | 39 | [base/wmi/tests/umtrprov/sources](../../base/wmi/tests/umtrprov/sources), [base/wmi/tests/umtrprov/makefile](../../base/wmi/tests/umtrprov/makefile) | `umprovider` | `PROGRAM` |
| [base/wmi/tests/umtrprov/datafiles](../../base/wmi/tests/umtrprov/datafiles) | 20 | — | — | — |
| [base/wmi/tests/wbemsamp](../../base/wmi/tests/wbemsamp) | 1 | — | — | — |
| [base/wmi/tests/wmisecur](../../base/wmi/tests/wmisecur) | 3 | [base/wmi/tests/wmisecur/sources](../../base/wmi/tests/wmisecur/sources), [base/wmi/tests/wmisecur/makefile](../../base/wmi/tests/wmisecur/makefile) | `wmisecur` | `PROGRAM` |
| [base/wmi/wbemlib](../../base/wmi/wbemlib) | 6 | [base/wmi/wbemlib/sources](../../base/wmi/wbemlib/sources), [base/wmi/wbemlib/makefile](../../base/wmi/wbemlib/makefile) | `wbemlib` | `LIBRARY` |

## `base/wow64/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [base/wow64](../../base/wow64) | 2 | [base/wow64/dirs](../../base/wow64/dirs) | — | — |
| [base/wow64/cgen](../../base/wow64/cgen) | 6 | [base/wow64/cgen/sources](../../base/wow64/cgen/sources), [base/wow64/cgen/makefile](../../base/wow64/cgen/makefile) | `winbld` | `LIBRARY` |
| [base/wow64/cpu](../../base/wow64/cpu) | 1 | [base/wow64/cpu/dirs](../../base/wow64/cpu/dirs) | — | — |
| [base/wow64/cpu/amd64](../../base/wow64/cpu/amd64) | 1 | [base/wow64/cpu/amd64/dirs](../../base/wow64/cpu/amd64/dirs) | — | — |
| [base/wow64/cpu/amd64/context](../../base/wow64/cpu/amd64/context) | 5 | [base/wow64/cpu/amd64/context/sources](../../base/wow64/cpu/amd64/context/sources), [base/wow64/cpu/amd64/context/makefile](../../base/wow64/cpu/amd64/context/makefile) | `wow64context` | `LIBRARY` |
| [base/wow64/cpu/amd64/cpu](../../base/wow64/cpu/amd64/cpu) | 6 | [base/wow64/cpu/amd64/cpu/sources](../../base/wow64/cpu/amd64/cpu/sources), [base/wow64/cpu/amd64/cpu/makefile](../../base/wow64/cpu/amd64/cpu/makefile) | `wow64cpu` | `DYNLINK` |
| [base/wow64/cpu/amd64/dbgexts](../../base/wow64/cpu/amd64/dbgexts) | 5 | [base/wow64/cpu/amd64/dbgexts/sources](../../base/wow64/cpu/amd64/dbgexts/sources), [base/wow64/cpu/amd64/dbgexts/makefile](../../base/wow64/cpu/amd64/dbgexts/makefile) | `wamd64cpuex` | `DYNLINK` |
| [base/wow64/cpu/amd64/inc](../../base/wow64/cpu/amd64/inc) | 1 | — | — | — |
| [base/wow64/cpu/context](../../base/wow64/cpu/context) | 0 | — | — | — |
| [base/wow64/cpu/context/ia64](../../base/wow64/cpu/context/ia64) | 1 | [base/wow64/cpu/context/ia64/sources](../../base/wow64/cpu/context/ia64/sources) | — | — |
| [base/wow64/cpu/cpu](../../base/wow64/cpu/cpu) | 2 | [base/wow64/cpu/cpu/sources](../../base/wow64/cpu/cpu/sources), [base/wow64/cpu/cpu/makefile](../../base/wow64/cpu/cpu/makefile) | `wow64cpu` | `DYNLINK` |
| [base/wow64/cpu/cpu/amd64](../../base/wow64/cpu/cpu/amd64) | 1 | [base/wow64/cpu/cpu/amd64/sources](../../base/wow64/cpu/cpu/amd64/sources) | — | — |
| [base/wow64/cpu/cpu/ia64](../../base/wow64/cpu/cpu/ia64) | 1 | [base/wow64/cpu/cpu/ia64/sources](../../base/wow64/cpu/cpu/ia64/sources) | — | — |
| [base/wow64/cpu/ia64](../../base/wow64/cpu/ia64) | 1 | [base/wow64/cpu/ia64/dirs](../../base/wow64/cpu/ia64/dirs) | — | — |
| [base/wow64/cpu/ia64/bintrans](../../base/wow64/cpu/ia64/bintrans) | 6 | [base/wow64/cpu/ia64/bintrans/sources](../../base/wow64/cpu/ia64/bintrans/sources), [base/wow64/cpu/ia64/bintrans/makefile](../../base/wow64/cpu/ia64/bintrans/makefile) | `bintrans` | `DYNLINK` |
| [base/wow64/cpu/ia64/context](../../base/wow64/cpu/ia64/context) | 5 | [base/wow64/cpu/ia64/context/sources](../../base/wow64/cpu/ia64/context/sources), [base/wow64/cpu/ia64/context/makefile](../../base/wow64/cpu/ia64/context/makefile) | `wow64context` | `LIBRARY` |
| [base/wow64/cpu/ia64/cpu](../../base/wow64/cpu/ia64/cpu) | 6 | [base/wow64/cpu/ia64/cpu/sources](../../base/wow64/cpu/ia64/cpu/sources), [base/wow64/cpu/ia64/cpu/makefile](../../base/wow64/cpu/ia64/cpu/makefile) | `wow64cpu` | `DYNLINK` |
| [base/wow64/cpu/ia64/cpu/ia64](../../base/wow64/cpu/ia64/cpu/ia64) | 1 | — | — | — |
| [base/wow64/cpu/ia64/dbgexts](../../base/wow64/cpu/ia64/dbgexts) | 5 | [base/wow64/cpu/ia64/dbgexts/sources](../../base/wow64/cpu/ia64/dbgexts/sources), [base/wow64/cpu/ia64/dbgexts/makefile](../../base/wow64/cpu/ia64/dbgexts/makefile) | `w64cpuex` | `DYNLINK` |
| [base/wow64/cpu/ia64/inc](../../base/wow64/cpu/ia64/inc) | 2 | — | — | — |
| [base/wow64/dbgexts](../../base/wow64/dbgexts) | 1 | [base/wow64/dbgexts/dirs](../../base/wow64/dbgexts/dirs) | — | — |
| [base/wow64/dbgexts/wow64](../../base/wow64/dbgexts/wow64) | 10 | [base/wow64/dbgexts/wow64/sources](../../base/wow64/dbgexts/wow64/sources), [base/wow64/dbgexts/wow64/makefile](../../base/wow64/dbgexts/wow64/makefile) | `wow64exts` | `DYNLINK` |
| [base/wow64/inc](../../base/wow64/inc) | 8 | — | — | — |
| [base/wow64/mscpu](../../base/wow64/mscpu) | 1 | [base/wow64/mscpu/dirs](../../base/wow64/mscpu/dirs) | — | — |
| [base/wow64/mscpu/analysis](../../base/wow64/mscpu/analysis) | 3 | [base/wow64/mscpu/analysis/sources](../../base/wow64/mscpu/analysis/sources), [base/wow64/mscpu/analysis/makefile](../../base/wow64/mscpu/analysis/makefile) | `analysis` | `LIBRARY` |
| [base/wow64/mscpu/compiler](../../base/wow64/mscpu/compiler) | 8 | [base/wow64/mscpu/compiler/sources](../../base/wow64/mscpu/compiler/sources), [base/wow64/mscpu/compiler/makefile](../../base/wow64/mscpu/compiler/makefile) | `compiler` | `LIBRARY` |
| [base/wow64/mscpu/compiler/axp64](../../base/wow64/mscpu/compiler/axp64) | 1 | — | — | — |
| [base/wow64/mscpu/cpumain](../../base/wow64/mscpu/cpumain) | 8 | [base/wow64/mscpu/cpumain/sources](../../base/wow64/mscpu/cpumain/sources), [base/wow64/mscpu/cpumain/makefile](../../base/wow64/mscpu/cpumain/makefile) | `wow64cpu` | `DYNLINK` |
| [base/wow64/mscpu/dbgexts](../../base/wow64/mscpu/dbgexts) | 6 | [base/wow64/mscpu/dbgexts/sources](../../base/wow64/mscpu/dbgexts/sources), [base/wow64/mscpu/dbgexts/makefile](../../base/wow64/mscpu/dbgexts/makefile) | `w64cpuex` | `DYNLINK` |
| [base/wow64/mscpu/decoder](../../base/wow64/mscpu/decoder) | 23 | [base/wow64/mscpu/decoder/sources](../../base/wow64/mscpu/decoder/sources), [base/wow64/mscpu/decoder/makefile](../../base/wow64/mscpu/decoder/makefile) | `decoder` | `LIBRARY` |
| [base/wow64/mscpu/entrypt](../../base/wow64/mscpu/entrypt) | 7 | [base/wow64/mscpu/entrypt/sources](../../base/wow64/mscpu/entrypt/sources), [base/wow64/mscpu/entrypt/makefile](../../base/wow64/mscpu/entrypt/makefile) | `entrypt` | `LIBRARY` |
| [base/wow64/mscpu/fraglib](../../base/wow64/mscpu/fraglib) | 39 | [base/wow64/mscpu/fraglib/dirs](../../base/wow64/mscpu/fraglib/dirs) | — | — |
| [base/wow64/mscpu/fraglib/axp64](../../base/wow64/mscpu/fraglib/axp64) | 2 | — | — | — |
| [base/wow64/mscpu/fraglib/cpu](../../base/wow64/mscpu/fraglib/cpu) | 12 | [base/wow64/mscpu/fraglib/cpu/sources](../../base/wow64/mscpu/fraglib/cpu/sources), [base/wow64/mscpu/fraglib/cpu/makefile](../../base/wow64/mscpu/fraglib/cpu/makefile) | `fraglib` | `LIBRARY` |
| [base/wow64/mscpu/fraglib/cpu/axp64](../../base/wow64/mscpu/fraglib/cpu/axp64) | 10 | — | — | — |
| [base/wow64/mscpu/inc](../../base/wow64/mscpu/inc) | 22 | — | — | — |
| [base/wow64/mscpu/math](../../base/wow64/mscpu/math) | 12 | [base/wow64/mscpu/math/sources](../../base/wow64/mscpu/math/sources), [base/wow64/mscpu/math/makefile](../../base/wow64/mscpu/math/makefile) | `cpumath` | `LIBRARY` |
| [base/wow64/mscpu/math/axp64](../../base/wow64/mscpu/math/axp64) | 2 | — | — | — |
| [base/wow64/ntvdm64](../../base/wow64/ntvdm64) | 5 | [base/wow64/ntvdm64/sources](../../base/wow64/ntvdm64/sources), [base/wow64/ntvdm64/makefile](../../base/wow64/ntvdm64/makefile) | `ntvdm64` | `DYNLINK` |
| [base/wow64/regremap](../../base/wow64/regremap) | 6 | [base/wow64/regremap/dirs](../../base/wow64/regremap/dirs) | — | — |
| [base/wow64/regremap/regsetup](../../base/wow64/regremap/regsetup) | 5 | [base/wow64/regremap/regsetup/sources](../../base/wow64/regremap/regsetup/sources), [base/wow64/regremap/regsetup/makefile](../../base/wow64/regremap/regsetup/makefile) | `w64setup` | `PROGRAM` |
| [base/wow64/regremap/test](../../base/wow64/regremap/test) | 4 | [base/wow64/regremap/test/sources](../../base/wow64/regremap/test/sources), [base/wow64/regremap/test/makefile](../../base/wow64/regremap/test/makefile) | `RegTest` | `PROGRAM` |
| [base/wow64/regremap/thunk](../../base/wow64/regremap/thunk) | 2 | [base/wow64/regremap/thunk/sources](../../base/wow64/regremap/thunk/sources), [base/wow64/regremap/thunk/makefile](../../base/wow64/regremap/thunk/makefile) | `regremap` | `LIBRARY` |
| [base/wow64/regremap/wow64reg](../../base/wow64/regremap/wow64reg) | 9 | [base/wow64/regremap/wow64reg/sources](../../base/wow64/regremap/wow64reg/sources), [base/wow64/regremap/wow64reg/makefile](../../base/wow64/regremap/wow64reg/makefile) | `wow64reg` | `LIBRARY` |
| [base/wow64/setup](../../base/wow64/setup) | 4 | [base/wow64/setup/dirs](../../base/wow64/setup/dirs) | — | — |
| [base/wow64/setup/boot](../../base/wow64/setup/boot) | 11 | [base/wow64/setup/boot/sources](../../base/wow64/setup/boot/sources), [base/wow64/setup/boot/makefile](../../base/wow64/setup/boot/makefile) | `setup16` | `PROGRAM` |
| [base/wow64/setup/inc](../../base/wow64/setup/inc) | 10 | — | — | — |
| [base/wow64/setup/installshield](../../base/wow64/setup/installshield) | 35 | [base/wow64/setup/installshield/sources](../../base/wow64/setup/installshield/sources), [base/wow64/setup/installshield/makefile](../../base/wow64/setup/installshield/makefile) | — | `NOTARGET` |
| [base/wow64/setup/intl](../../base/wow64/setup/intl) | 1 | [base/wow64/setup/intl/dirs](../../base/wow64/setup/intl/dirs) | — | — |
| [base/wow64/setup/intl/usa](../../base/wow64/setup/intl/usa) | 6 | [base/wow64/setup/intl/usa/sources](../../base/wow64/setup/intl/usa/sources), [base/wow64/setup/intl/usa/makefile](../../base/wow64/setup/intl/usa/makefile) | — | `NOTARGET` |
| [base/wow64/tests](../../base/wow64/tests) | 0 | — | — | — |
| [base/wow64/tests/apc](../../base/wow64/tests/apc) | 5 | [base/wow64/tests/apc/sources](../../base/wow64/tests/apc/sources), [base/wow64/tests/apc/makefile](../../base/wow64/tests/apc/makefile) | `apc` | `PROGRAM` |
| [base/wow64/tests/bvt](../../base/wow64/tests/bvt) | 6 | [base/wow64/tests/bvt/sources](../../base/wow64/tests/bvt/sources), [base/wow64/tests/bvt/makefile](../../base/wow64/tests/bvt/makefile) | `wow64bvt` | `PROGRAM` |
| [base/wow64/tests/crash](../../base/wow64/tests/crash) | 5 | [base/wow64/tests/crash/sources](../../base/wow64/tests/crash/sources), [base/wow64/tests/crash/makefile](../../base/wow64/tests/crash/makefile) | `crash` | `PROGRAM` |
| [base/wow64/tests/generic](../../base/wow64/tests/generic) | 19 | [base/wow64/tests/generic/sources](../../base/wow64/tests/generic/sources), [base/wow64/tests/generic/makefile](../../base/wow64/tests/generic/makefile) | `generic` | `PROGRAM` |
| [base/wow64/tools](../../base/wow64/tools) | 2 | [base/wow64/tools/dirs](../../base/wow64/tools/dirs) | — | — |
| [base/wow64/tools/genlib](../../base/wow64/tools/genlib) | 4 | [base/wow64/tools/genlib/sources](../../base/wow64/tools/genlib/sources), [base/wow64/tools/genlib/makefile](../../base/wow64/tools/genlib/makefile) | `genlib` | `LIBRARY` |
| [base/wow64/tools/gennt32t](../../base/wow64/tools/gennt32t) | 4 | [base/wow64/tools/gennt32t/sources](../../base/wow64/tools/gennt32t/sources), [base/wow64/tools/gennt32t/makefile](../../base/wow64/tools/gennt32t/makefile) | `gennt32t` | `PROGRAM` |
| [base/wow64/tools/genthnk](../../base/wow64/tools/genthnk) | 4 | [base/wow64/tools/genthnk/sources](../../base/wow64/tools/genthnk/sources), [base/wow64/tools/genthnk/makefile](../../base/wow64/tools/genthnk/makefile) | `genthnk` | `PROGRAM` |
| [base/wow64/tools/idlclean](../../base/wow64/tools/idlclean) | 4 | [base/wow64/tools/idlclean/sources](../../base/wow64/tools/idlclean/sources), [base/wow64/tools/idlclean/makefile](../../base/wow64/tools/idlclean/makefile) | `idlclean` | `PROGRAM` |
| [base/wow64/tools/ppm2pps](../../base/wow64/tools/ppm2pps) | 4 | [base/wow64/tools/ppm2pps/sources](../../base/wow64/tools/ppm2pps/sources), [base/wow64/tools/ppm2pps/makefile](../../base/wow64/tools/ppm2pps/makefile) | `ppm2pps` | `PROGRAM` |
| [base/wow64/tools/sortpp](../../base/wow64/tools/sortpp) | 4 | [base/wow64/tools/sortpp/sources](../../base/wow64/tools/sortpp/sources), [base/wow64/tools/sortpp/makefile](../../base/wow64/tools/sortpp/makefile) | `sortpp` | `PROGRAM` |
| [base/wow64/whbase](../../base/wow64/whbase) | 5 | [base/wow64/whbase/sources](../../base/wow64/whbase/sources), [base/wow64/whbase/makefile](../../base/wow64/whbase/makefile) | `whbase` | `LIBRARY` |
| [base/wow64/whnt32](../../base/wow64/whnt32) | 5 | [base/wow64/whnt32/sources](../../base/wow64/whnt32/sources), [base/wow64/whnt32/makefile](../../base/wow64/whnt32/makefile) | `whnt32` | `LIBRARY` |
| [base/wow64/wow64](../../base/wow64/wow64) | 14 | [base/wow64/wow64/sources](../../base/wow64/wow64/sources), [base/wow64/wow64/makefile](../../base/wow64/wow64/makefile) | `wow64` | `DYNLINK` |
| [base/wow64/wow64/alpha](../../base/wow64/wow64/alpha) | 4 | — | — | — |
| [base/wow64/wow64/amd64](../../base/wow64/wow64/amd64) | 4 | [base/wow64/wow64/amd64/sources](../../base/wow64/wow64/amd64/sources) | — | — |
| [base/wow64/wow64/axp64](../../base/wow64/wow64/axp64) | 1 | [base/wow64/wow64/axp64/sources](../../base/wow64/wow64/axp64/sources) | — | — |
| [base/wow64/wow64/ia64](../../base/wow64/wow64/ia64) | 4 | [base/wow64/wow64/ia64/sources](../../base/wow64/wow64/ia64/sources) | — | — |
| [base/wow64/wow64log](../../base/wow64/wow64log) | 7 | [base/wow64/wow64log/sources](../../base/wow64/wow64log/sources), [base/wow64/wow64log/makefile](../../base/wow64/wow64log/makefile) | `wow64log` | `DYNLINK` |
| [base/wow64/wow64svc](../../base/wow64/wow64svc) | 1 | [base/wow64/wow64svc/dirs](../../base/wow64/wow64svc/dirs) | — | — |
| [base/wow64/wow64svc/server](../../base/wow64/wow64svc/server) | 6 | [base/wow64/wow64svc/server/sources](../../base/wow64/wow64svc/server/sources), [base/wow64/wow64svc/server/makefile](../../base/wow64/wow64svc/server/makefile) | `wow64` | `PROGRAM` |

## `base/xip/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [base/xip](../../base/xip) | 1 | [base/xip/dirs](../../base/xip/dirs) | — | — |
| [base/xip/doc](../../base/xip/doc) | 1 | — | — | — |
| [base/xip/xipdisk](../../base/xip/xipdisk) | 6 | [base/xip/xipdisk/sources](../../base/xip/xipdisk/sources), [base/xip/xipdisk/makefile](../../base/xip/xipdisk/makefile) | `xipdisk` | `DRIVER` |

## `base/zlib/`

| Directory | Files | Build definitions | Declared `TARGETNAME` | Declared `TARGETTYPE` |
| --- | ---: | --- | --- | --- |
| [base/zlib](../../base/zlib) | 42 | [base/zlib/sources](../../base/zlib/sources), [base/zlib/makefile](../../base/zlib/makefile) | `zlib` | `LIBRARY` |
