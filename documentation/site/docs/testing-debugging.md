---
title: Tests, diagnostics and debugging
sidebar_position: 10
description: Where tests live in this tree, the naming conventions that hide them, printing and breaking from kernel code, Driver Verifier, gflags, application verifier, and the per-component debugger extensions.
---

This tree predates a single test framework. Tests exist, but they are spread across per-project
conventions, and several of them are invisible to any tool that looks for a directory called `test`.
Knowing the conventions is most of the value here.

## What "a test" looks like in this tree

| Convention | Where it appears | Example |
| --- | --- | --- |
| `drt/` directories | 42 distinct directories | `base/fs/rdr2/drt`, `com/rpc/locator/drt`, `ds/adsi/drt`, `com/ole32/stg/drt`, `base/wmi/drt` |
| `test/`, `tests/` | Some projects | `base/pnp/test`, `ds/ds/src/test`, `windows/core/ntgdi/test`, `base/testlockout` |
| `ut*.c` / `tt*.c` / `ct*.c` files | Kernel components | `base/ntos/se/utaccess.c`, `uttoken.c`, `ttseacc.c`, `ctaccess.c` |
| `*_test.py`, `test_*.py` | Python tooling | `documentation/tests/test_generate.py` |
| `samples/` | Reference and exercise code | `net/ndis/samples`, `net/sockets/samples`, `net/tcpip/samples` |
| `pnptst`, `iotest` | Component-specific exercise tools | `net/ndis/pnptst`, `base/fs/fltsamples/iotest` |

The `ut` / `tt` / `ct` prefixes are the ones that trip people up. In `base/ntos/se/`:

```bash
ls base/ntos/se | grep -E '^(ut|tt|ct)'
# ctaccess.c  ctlnpqos.c  ctlpcqos.c  ctseacc.c  ctsertl.c  cttoken.c
# ttokend.c   ttseacc.c   ttsertl.c
# utaccess.c  utlnpqos.c  utlpcqos.c  utseacc.c  utseqos.c  utsertl.c  uttoken.c
```

Those are real tests for access checking, tokens and QoS, and none of them is in a `test`-named
directory.

### Why the generated index misses them

The index generator identifies test files by **path segment**, not by name prefix:

```python
# documentation/scripts/generate.py
TEST_PATH = re.compile(r'(^|[/_.-])(tests?|testing|unittests?|testcases?)([/_.-]|$)', re.I)
```

Verified against that exact regular expression:

```python
>>> bool(TEST_PATH.search('base/ntos/se/utaccess.c'))
False
>>> bool(TEST_PATH.search('base/tests/test_foo.cpp'))
True
>>> bool(TEST_PATH.search('base/foo_test.py'))
True
>>> bool(TEST_PATH.search('base/latest/foo.cpp'))   # "latest" is not "test"
False
```

So a kernel function tested only by `base/ntos/se/utaccess.c` shows
`No matching call found in test-named files.` in the index. That line describes the *index*, not the
code. See [Using the generated function index](/function-index).

## Printing and breaking from kernel code

The debug-print family is used throughout the tree's own tests — the `ct*.c` access tests print
their results directly:

```c
// base/ntos/se/cttoken.c:1474 (and again at 1510, 1546, 1589, 1624)
DbgPrint("\n (debug) return length: 0x%lx \n", ReturnLength);
```

The official documentation for the family:
[DbgPrint, DbgPrintEx, vDbgPrintEx, vDbgPrintExWithPrefix](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-dbgprint)
documents the rules this code follows: the routine is callable at `IRQL <= DIRQL` (but only from
checked builds do most prints appear), the format string supports the `%wZ` unicode-string
extension, and the total length is capped (512 bytes on older systems). `KdPrint`/`KdPrintEx` are
the macro wrappers that compile away in free builds. For a deliberate break, `DbgBreakPoint` raises
`STATUS_BREAKPOINT` — the same effect as typing `bp` in WinDbg but from code.

Practical conventions used by tests in this tree:

```bash
# how the kernel security tests print and assert
rg -n 'DbgPrint|DbgBreakPoint' base/ntos/se/ct*.c | head
# checked-build-only diagnostics
rg -n '#if DBG|KdPrint' net/sockets/winsock2/wsp/afdsys/*.c | head
```

## Driver Verifier

`base/ntos/verifier/` is compiled into the kernel and provides the hooks that let I/O calls be routed
through checking code instead of the fast path. This is the source of the `Iov*` indirections
described in [Kernel and executive](/kernel#iofcalldriver-indirection).

| File | What it verifies |
| --- | --- |
| `vfirp.c`, `vfirpdb.c` | IRP handling and the IRP-tracking database |
| `vfdeadlock.c` | Lock-ordering and potential deadlocks |
| `vfddi.c`, `viddi.h` | Driver entry-point (DDI) usage rules |
| `vfpnp.c`, `vfpower.c` | PnP and power IRP sequences |
| `vfstack.c` | Stack usage and overrun detection |
| `vfdevobj.c`, `vfdriver.c` | Device object and driver object rules |
| `vfbugcheck.c` | The bugchecks it raises |
| `vfsettings.c` | Which checks are enabled |
| `vfhal.c`, `halverifier.h` | HAL verification |
| `vfmessage.c`, `vfprint.c`, `vfdebug.c` | Reporting |

Verifier is enabled per driver through the registry settings that `sdktools/gflags` writes, which is
why `gflags` is the usual first step in a driver investigation. The official overview is
[Driver Verifier](https://learn.microsoft.com/en-us/windows-hardware/drivers/devtest/driver-verifier);
the per-rule pages (such as the `ForwardedAtBadIrql` and `MarkIrpPending` rules listed against
`IoCallDriver` in [I/O](/io-storage#the-dispatch-rules-that-trip-everyone)) name the exact
`vf*.c` check behind each symptom.

## Diagnostic tools in `sdktools`

`sdktools/` holds 240 tool directories. The ones most often relevant:

| Tool | Purpose | Official documentation |
| --- | --- | --- |
| `gflags` | Global flags: verifier settings, heap options, loader snaps | [GFlags](https://learn.microsoft.com/en-us/windows-hardware/drivers/devtest/gflags) |
| `appverif` | Application Verifier UI (`appverif.cpp`, `avpage.cpp`, `avsheet.cpp`, `chooseexe.cpp`) | [Application Verifier](https://learn.microsoft.com/en-us/windows-hardware/drivers/devtest/application-verifier) |
| `avrf` | The application-verifier runtime (`base/ntdll/avrfp.h` is the client side) | same as above |
| `debuggers` | `windbg`, `dbgsrv`, `dbgsvc`, `drwatson`, `dumpchk`, `dumpconv`, `dumpexam`, `minidump`, `savedump`, `symsrv`, `imagehlp`, `exts` | [Debugging Tools for Windows](https://learn.microsoft.com/en-us/windows-hardware/drivers/debugger/) |
| `crash`, `buggy`, `bootstat` | Crash and boot diagnostics | |
| `build`, `buildnum`, `actools` | The build engine and its helpers — see [Build](/build#buildexe-is-in-this-tree) | |
| `checksym`, `symtodbg`, `symsrv` | Symbol handling | |
| `diskperf`, `diskmon`, `dskdump`, `dskbench` | Storage instrumentation | |
| `cpustres`, `clearmem`, `consume` | Resource stress for reproducing conditions | |

The debugger extension sources are in `sdktools/debuggers/exts/`, split into `kextdll` (kernel),
`uextdll` (user), `extdll` and `eng`, with `getnt4ex.bat` and `getw2kex.bat` for version-specific
extension sets. The `!analyze` and extension authoring model is documented at
[Debugger engine extensions](https://learn.microsoft.com/en-us/windows-hardware/drivers/debugger/writing-wdbgexts-extensions-).

## Per-component debugger extensions

Most subsystems ship their own `!` extensions, in a `kdext` / `kdexts` directory next to the code:

```text
base/busdrv/acpi/tools/kdext      base/fs/mup/kdext            base/fs/hsm/kdexts
base/ntos/wmi/kdexts              base/ntos/wmi/kdexts/tracing base/tools/kdexts2
drivers/storage/kdext             (+ atapi, minipkd, redbook, sbp2kdx, scsikd, stor)
drivers/wdm/usb/hcd/kdexts        drivers/ksfilter/ks/kdexts
ds/nw/rdr/kdext                   (+ ntsd, windbg variants)
net/1394/arp/kdext                net/atm/arp/kdext
net/sockets/winsock2/wsp/afdsys/kdext
net/tcpip/driver/kdext  kdext2  kdext3
windows/core/ntuser/kdexts        windows/core/ntgdi/kdexts2
```

`net/tcpip/driver` has three (`kdext`, `kdext2`, `kdext3`), which is a hint that the extension set
was revised across releases. When you change a data structure that an extension prints, the extension
is part of the change.

## References

Official Microsoft documentation for the tooling on this page:

| Topic | Official documentation |
| --- | --- |
| Driver Verifier | [https://learn.microsoft.com/en-us/windows-hardware/drivers/devtest/driver-verifier](https://learn.microsoft.com/en-us/windows-hardware/drivers/devtest/driver-verifier) |
| GFlags | [https://learn.microsoft.com/en-us/windows-hardware/drivers/devtest/gflags](https://learn.microsoft.com/en-us/windows-hardware/drivers/devtest/gflags) |
| Application Verifier | [https://learn.microsoft.com/en-us/windows-hardware/drivers/devtest/application-verifier](https://learn.microsoft.com/en-us/windows-hardware/drivers/devtest/application-verifier) |
| Special pool | [https://learn.microsoft.com/en-us/windows-hardware/drivers/devtest/special-pool](https://learn.microsoft.com/en-us/windows-hardware/drivers/devtest/special-pool) |
| PoolMon | [https://learn.microsoft.com/en-us/windows-hardware/drivers/devtest/poolmon](https://learn.microsoft.com/en-us/windows-hardware/drivers/devtest/poolmon) |
| WinDbg | [https://learn.microsoft.com/en-us/windows-hardware/drivers/debugger/debugger-download-tools](https://learn.microsoft.com/en-us/windows-hardware/drivers/debugger/debugger-download-tools) |
| `DbgPrint` / `DbgPrintEx` | [https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-dbgprint](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-dbgprint) |
| Writing debugger extensions | [https://learn.microsoft.com/en-us/windows-hardware/drivers/debugger/writing-wdbgexts-extensions-](https://learn.microsoft.com/en-us/windows-hardware/drivers/debugger/writing-wdbgexts-extensions-) |
| Checked build differences | [https://learn.microsoft.com/en-us/windows-hardware/drivers/devtest/checked-build](https://learn.microsoft.com/en-us/windows-hardware/drivers/devtest/checked-build) |

In-tree anchors:

| File | Why |
| --- | --- |
| [`base/ntos/verifier`](https://github.com/havaianasdestruido/neo-nt5/tree/main/base/ntos/verifier) | The verifier implementation |
| [`sdktools/gflags`](https://github.com/havaianasdestruido/neo-nt5/tree/main/sdktools/gflags) | The flag editor |
| [`sdktools/debuggers/exts`](https://github.com/havaianasdestruido/neo-nt5/tree/main/sdktools/debuggers/exts) | Extension sources |
| `base/ntos/se/ct*.c`, `ut*.c`, `tt*.c` | The kernel unit tests with real `DbgPrint` output |

## Frequently asked questions

### Q: How do I find every test that touches the code I changed?

Search the test-named *and* prefix-named locations, because neither set is complete alone:

```bash
# path-based conventions
rg -l 'SepAccessCheck' --glob '**/test*/**' --glob '**/drt/**'

# prefix conventions used by kernel components
rg -l 'SepAccessCheck' base/ntos/se/ut*.c base/ntos/se/tt*.c base/ntos/se/ct*.c
```

Then say explicitly which you could not run. In this checkout, none of them can be executed — there
is no Linux compile target and no target system.

### Q: Is a `drt` directory runnable?

Presence is not evidence. `drt` trees are design/regression test scaffolding for their component and
typically assume a built product, a configured environment and sometimes a second machine — see
`com/rpc/locator/drt`, which has `c/`, `s/`, `lookup/`, `dynamic/`, `export/` and `unexport/`
subtrees implying a client, a server and a locator service all running. Treat a `drt` folder as a
specification of intended behaviour until you can run it.

### Q: Which is the only test suite this repository can actually run?

The documentation generator's, because it is Python:

```sh
python3 -m pip install -r documentation/requirements.txt
python3 -m unittest discover -s documentation/tests
```

```text
test_c_definitions_and_calls ... ok
test_python_functions_and_calls ... ok
test_hash_changes_with_body ... ok
test_test_path_detection ... ok
test_generation_writes_test_evidence ... ok
test_generation_cleans_stale_pages ... ok
```

It exercises `parse_c`, `parse_python`, `is_test` and `generate` in
`documentation/scripts/generate.py`. That is a real test of the tooling that produces this site, and
it is the only automated check in the repository that runs on Linux.

### Q: I need to reproduce a bug that only appears under memory pressure. What exists here?

`clearmem`, `consume` and `cpustres` in `sdktools` are stress tools for exactly that, and
`base/ntos/mm/nolowmem.c` and `mmquota.c` are the kernel side of low-memory and quota behaviour.
Combine them with a checked build (`razzle` without `free`) so the assertions and pool checking are
live. The WDK's `poolmon` and special-pool documentation (links above) describe the kernel support
these tools drive.

### Q: How do I turn on verifier for one driver?

With `gflags` (source at `sdktools/gflags`, built as a console `PROGRAM` linking `ntdll.lib` and
`user32.lib`), which writes the registry values the kernel reads at
`base/ntos/verifier/vfsettings.c`. The relevant `sources` file is short enough to quote in full — see
[Build, package and release](/build#the-three-files-that-define-a-component).

```bat
gflags /flags +sls +soe /driver mydriver.sys
```

The exact flag names are gflags' own; check `sdktools/gflags/gflags.h` and `gflags.dlg` for the set
this build supports rather than assuming a modern flag list.

### Q: A structure changed and the debugger extension now prints garbage. Is that my problem?

Yes. The extension is compiled against the same headers:

```bash
rg -n 'PAFD_ENDPOINT' net/sockets/winsock2/wsp/afdsys/kdext
rg -n 'struct _TCB' net/tcpip/driver/kdext net/tcpip/driver/kdext2 net/tcpip/driver/kdext3
```

Updating the structure without the extension leaves the *only* tool that can inspect the live object
silently wrong — which is worse than a compile error, because it produces confident nonsense during
the next investigation.

### Q: What counts as honest evidence for a change in this tree?

The working guide's table, applied strictly:

| Environment | Acceptable evidence |
| --- | --- |
| Anywhere | `git diff --check`; reviewed changed paths; compared build-target and consumer declarations; static/text tests |
| Windows with the historic toolchain | A fresh Razzle session, explicit architecture and flavor, smallest reachable target plus dependents built, logs and symbols inspected |
| Installed test system | Actual behaviour exercised, including negative/security paths, cleanup, locales, 32/64-bit variants |

A grep result, a successful catalog regeneration, or the existence of a `sources` file is **not** a
runtime test. Report what you ran, in what environment, and what you could not test.
