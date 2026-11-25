---
title: Tests, diagnostics and debugging
sidebar_position: 10
description: Where tests live in this tree, the naming conventions that hide them, Driver Verifier, gflags, application verifier, and the per-component debugger extensions.
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
why `gflags` is the usual first step in a driver investigation.

## Diagnostic tools in `sdktools`

`sdktools/` holds 240 tool directories. The ones most often relevant:

| Tool | Purpose |
| --- | --- |
| `gflags` | Global flags: verifier settings, heap options, loader snaps |
| `appverif` | Application Verifier UI (`appverif.cpp`, `avpage.cpp`, `avsheet.cpp`, `chooseexe.cpp`) |
| `avrf` | The application-verifier runtime (`base/ntdll/avrfp.h` is the client side) |
| `debuggers` | `windbg`, `dbgsrv`, `dbgsvc`, `drwatson`, `dumpchk`, `dumpconv`, `dumpexam`, `minidump`, `savedump`, `symsrv`, `imagehlp`, `exts` |
| `crash`, `buggy`, `bootstat` | Crash and boot diagnostics |
| `build`, `buildnum`, `actools` | The build engine and its helpers |
| `checksym`, `symtodbg`, `symsrv` | Symbol handling |
| `diskperf`, `diskmon`, `dskdump`, `dskbench` | Storage instrumentation |
| `cpustres`, `clearmem`, `consume` | Resource stress for reproducing conditions |

The debugger extension sources are in `sdktools/debuggers/exts/`, split into `kextdll` (kernel),
`uextdll` (user), `extdll` and `eng`, with `getnt4ex.bat` and `getw2kex.bat` for version-specific
extension sets.

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

## Driver Verifier in detail

Verifier is not a single check. It is a set of **I/O verifier** and **DDI compliance** rules that the
kernel routes through, plus a set of **special pools**. The `gflags` / Driver Verifier Manager
settings are per-driver; the kernel reads them at driver load.

| Setting | What it turns on |
| --- | --- |
| Special pool | Allocate from a pool with guard pages, so overruns and use-after-free crash immediately |
| Force IRQL checking | Fail if a driver calls a function at the wrong IRQL |
| Pool tracking | Track every allocation by tag, so `!poolused` and the leak dumps are accurate |
| I/O verification | Route IRPs through the verifier and check `IoCallDriver`/`IoCompleteRequest` pairing |
| Deadlock detection | Build the lock-order graph and detect cycles (`vfdeadlock.c`) |
| DMA verification | Check map-register usage and buffer ownership |
| Security checks | Verify `IoCreateDeviceSecure` and device-naming rules |
| Misc checks | `IoDeleteDevice` on a device with outstanding references, `IoCompleteRequest` on an IRP twice |
| Force pending I/O | Randomly return `STATUS_PENDING` so the driver's async path is exercised |
| IRP logging | Record the last N IRPs for the driver |
| Disk integrity verification | Read back every write and compare (very slow) |

The verifier's IRP tracking database lives in `base/ntos/verifier/vfirpdb.c`; `vfirp.c` wraps
`IoCallDriver`/`IoCompleteRequest` to keep it consistent. When a verifier rule fires, it calls
`VfBugcheck` with a verifier-specific code; the `vfbugcheck.c` table maps code to bugcheck argument.

| Bugcheck | Meaning |
| --- | --- |
| `0xC4` (`DRIVER_VERIFIER_DETECTED_VIOLATION`) | A DDI compliance rule fired |
| `0xC9` (`DRIVER_VERIFIER_IOMANAGER_VIOLATION`) | An I/O manager rule fired |
| `0xC6` (`DRIVER_CAUGHT_MODIFYING_FREED_POOL`) | Special pool detected a write to freed memory |
| `0xCC` (`PAGE_FAULT_IN_FREED_SPECIAL_POOL`) | Access to freed special pool |
| `0xD6` (`PAGE_FAULT_BEYOND_END_OF_ALLOCATION`) | Overrun of a special-pool allocation |

### Using `gflags`

```bat
:: Enable verifier for a driver, with special pool and IRQL checking
gflags /r +sls          :: enable "Special Pool" globally (registry)
verifier /flags 0x... /driver mydriver.sys
verifier /query
verifier /reset
```

The `gflags` UI exposes the same flags as the registry:
`HKLM\SYSTEM\CurrentControlSet\Control\Session Manager\GlobalFlag` and
`...\Memory Management\PoolTagOverrides`. The `sdktools/gflags` sources are the tool; the kernel
side is `base/ntos/verifier/vfsettings.c`, which reads them.

### Application Verifier

The user-mode counterpart is `sdktools/appverif` (the UI) and the `avrf` runtime, with the client
side in `base/ntdll/avrfp.h`. It uses the same idea — instrument the heap and the API — but for
user-mode bugs: heap overruns, handle misuse, `LoadLibrary` errors, `GetProcAddress` misuse, and
locking violations.

| Fix | What it catches |
| --- | --- |
| Heaps | Overruns, underruns, use-after-free, double-free |
| Handles | Invalid handle use, handle leaks |
| Locks | `InitializeCriticalSection` on an already-initialised CS, thread termination holding a lock |
| Memory | `VirtualAlloc`/`VirtualFree` pairing, `IsBadReadPtr` misuse |
| Timers | Timer callback leaks |
| `LoadLibrary` | Load failures, incorrect `GetModuleHandle` |
| Threats | Simulated low-memory and low-resource conditions |

## Debugging techniques

### Reading a crash dump

```text
kd -z dump.dmp
> !analyze -v          the first command on any dump
> .bugcheck            the stop code and arguments
> kv                   the faulting stack
> !irp <addr>          the IRP that was in flight
> !devobj <addr>       the device object
> !drvobj <addr> 2     the driver object and its dispatch table
> !poolused 2          pool by tag, sorted
> !vm                  memory state
> !locks               held locks and owners
> !stacks 2            all kernel stacks
```

The four bugcheck arguments are the key: for `0xC4` (verifier), argument 2 is the specific rule.
Look it up in `vfbugcheck.c` before guessing.

### Debugging a hang

For a hang rather than a crash, use a **live** kernel debug or a user dump:

```text
> !locks               who owns what, and who is waiting
> !stacks 2            all threads and their stacks
> !ready               the ready queue
> !running             what is running
> !thread <addr>       a specific thread
> dt nt!EPROCESS <addr>   process fields
> dt nt!ETHREAD <addr>   thread fields
```

`!locks` prints the `ERESOURCE`/`KMUTANT` trees with owners and waiters, which is usually enough to
see the cycle. `!stacks 2` gives the full picture across all processors.

### Debugging a memory leak

```text
> !poolused 2          sort by tag; look for a growing tag
> !pool <addr>         find the allocation around a suspicious address
> !address <addr>      what is at that address, and which region
> !vm                  commit charge and page file use
> !heap -l             leaked blocks in the user-mode heap (from a user dump)
```

Pool tags are the whole game. `ExAllocatePoolWithTag(..., 'xxxx')` makes a leak visible in
`!poolused`; a tag of 0 or `'None'` makes it invisible.

### ETW tracing

Event Tracing for Windows is the system-wide tracing mechanism. A provider registers with
`EventRegister`, writes events with `EventWrite`, and a controller starts a session with
`StartTrace`/`EnableTraceEx2`. The kernel has built-in providers (`NT Kernel Logger`), and the
tree carries per-provider MOF files that describe the event schema.

```text
tracelog.exe -start MySession -f c:\trace.etl -guid #<provider-guid> -flag 0xFFFF
tracelog.exe -stop MySession
tracefmt.exe c:\trace.etl -o c:\trace.txt
tracerpt.exe c:\trace.etl -o c:\report.html -of html
```

The tools are in `sdktools/trace` (`logman`, `relog`, `tracectr`, `evntrprv`) plus
`sdktools/perfmon`/`perfmtr`. The kernel-side trace plumbing that *is* in this checkout is
`base/ntos/wmi/traceapi.c` (`WmiTraceMessage` at 1869, `WmiTraceMessageVa` at 1911) and
`base/ntos/wmi/traceapi.c`'s logger management — the WPP/`WMI` trace path. The user-mode ETW
registration API (`EtwRegister`/`EtwWrite`) is **not** present as a source directory in this
checkout; do not cite one.

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
live.

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

### Q: What does `!analyze -v` actually do?

It runs a heuristic analysis of the dump: it identifies the bugcheck, decodes the four arguments,
finds the faulting stack, maps every frame to a symbol, and then searches a database of known
patterns. Its conclusion is a **starting hypothesis**, not a proof — "Probably caused by" is the
word the tool itself uses. Confirm by reading the stack and the IRP/lock state yourself.

### Q: Why is my driver's bugcheck argument 2 a number I cannot find?

Because the verifier's rule codes live in `base/ntos/verifier/vfbugcheck.c`, not in a public
header. The mapping from code to description is that file. Grep the number in
`base/ntos/verifier` to find the rule that fired.

### Q: How do I get a dump of a hang without a debugger attached?

Use a keyboard-initiated crash: enable the `CrashOnCtrlScroll` registry value under
`HKLM\SYSTEM\CurrentControlSet\Services\i8042prt\Parameters` (or `kbdhid`), then press
Right-Ctrl + Scroll Lock twice. The kernel bugchecks with `0xE2` (`MANUALLY_INITIATED_CRASH`) and
writes a dump. `sdktools/crash` has the tooling that configures it.

### Q: What is the difference between a kernel dump and a minidump?

A **complete/kernel dump** contains all of physical memory (kernel) or a subset; a **minidump**
contains the stacks, the loaded module list, the thread list and the faulting context. Minidumps are
small and portable but cannot answer questions about arbitrary memory. `sdktools/debuggers/minidump`
and `dumpchk` validate them.

### Q: How do I find which driver leaked pool?

Enable pool tracking, reproduce the leak, then `!poolused 2` sorted by tag. The growing tag is the
culprit; `!pool <addr>` finds the allocation around a suspect address, and the tag's four characters
tell you which component allocated it. If the tag is 0 or `'None'`, you have to bisect by disabling
drivers.

### Q: Can Driver Verifier be enabled for a driver that is already loaded?

No. Verifier's settings are read when the driver loads, so you must enable them, then reboot (or
reload the driver). `verifier /standard /driver mydriver.sys` followed by a reboot is the normal
sequence. Applying it to a boot-start driver can make the system unbootable if the driver fails the
checks — enable one driver at a time.

### Q: What is `gflags` doing that the registry does not?

Nothing, functionally — `gflags` is the UI over the `GlobalFlag` value and the
`VerifierDrivers`/`VerifyDriverLevel` values. What it adds is the list of friendly names for the
flags. The actual enforcement is in `base/ntos/verifier/vfsettings.c` and the heap's flag checks.

### Q: Why does my `!irp` show `IRP_CANCELLED` when nothing cancelled it?

Because the IRP was completed and freed, and the memory was reused — `!irp` is reading stale data.
The IRP tracking database (`vfirpdb.c`) keeps the real history if IRP logging is enabled. Enable
"IRP Logging" in Verifier and use `!irpfind`/`!verifier 3` to read the log instead of the freed IRP.

### Q: How do I trace a `STATUS_ACCESS_DENIED` from a kernel service?

First determine the caller's token and the object's DACL, then check the access mask. In the
debugger: `!token <addr>` and `dt nt!SECURITY_DESCRIPTOR`. The kernel's decision is in
`SeAccessCheck` (`base/ntos/se/accessck.c`); a quick way to confirm is to enable the "Audit Object
Access" policy and read the failure audit record in the event log, which names the right that was
missing.

### Q: Where do I add a test for a new kernel path?

Under the component's own test directory, following the `ut*.c` convention the index already
recognises — `base/ntos/se/utaccess.c` is the canonical example. Name it `ut<subject>.c`, give it
its own `sources` with `TARGETTYPE=PROGRAM`, and link against the same libraries the component
uses. A test that is not in the tree is not a test the index or the build can see.
