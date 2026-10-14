# Build and release pipeline

**Read this before running any historic build command.** This is a Windows `cmd`/NMAKE/`build.exe` source tree, not a CMake, npm, or Linux project. The [repository README](../README.md) describes the intended workflow; this guide distinguishes that workflow from what is actually checked in. The checkout has missing directories and helper scripts, so a full build or bootable ISO is **not verified** by these docs.

## Inputs and traversal

| File / tree | Function | Example |
| --- | --- | --- |
| [`tools/razzle.cmd`](../tools/razzle.cmd) and [`tools/ntenv.cmd`](../tools/ntenv.cmd) | Set paths, architecture, free/checked and toolchain variables in a Windows command session. | `RazzleToolPath`, `_NTTREE`, `BUILD_DEFAULT_TARGETS` |
| Root [`dirs`](../dirs) and nested `dirs` | Tell `build.exe` which child directories to traverse and in what order. `OPTIONAL_DIRS` and `{architecture}` qualifiers alter traversal. | [`base/dirs`](../base/dirs), [`base/ntos/dirs`](../base/ntos/dirs) |
| Leaf `sources` | Define targets, source lists, include/lib paths and custom processing for a component. These may include or defer definitions elsewhere; some are architecture/locale fragments. | [`sdktools/gflags/sources`](../sdktools/gflags/sources) |
| Leaf `makefile`, [`tools/makefile.def`](../tools/makefile.def), [`tools/makefile.plt`](../tools/makefile.plt) | Delegate NMAKE work to the shared build rules; many `makefile`s are only a one-line `!INCLUDE`. | [`sdktools/gflags/makefile`](../sdktools/gflags/makefile) |
| `project.mk`, [`tools/projects.inc`](../tools/projects.inc), component `makefile.inc` | Project-level macros, shared include/lib locations and component-specific rules. | [`base/project.mk`](../base/project.mk) |
| [`published`](../published), `*/published`, [`public`](../public) | Publication steps and shared headers/import libraries for other projects. `public/` also contains checked-in artifacts. | [`com/published`](../com/published), [`public/sdk/inc`](../public/sdk/inc) |
| [`sdktools/build`](../sdktools/build) | Source and documentation for the historical `build.exe` traversal engine. | [`sdktools/build/build.htm`](../sdktools/build/build.htm) |

Read a component **from the root down**: find each ancestor `dirs`, then its local `sources`, any includes/`project.mk`, its published headers and import libraries, and finally its setup or postbuild rules. Do not assume that all `sources` entries are targets: some set `TARGETTYPE=NOTARGET`, specify source fragments, or are unreachable from the chosen traversal. The [catalog](catalog/README.md) indexes literal metadata but does not interpret conditionals. In `sources`, `TARGETNAME` gives a declared target name; common `TARGETTYPE` values include `PROGRAM` (executable), `DYNLINK` (DLL), `LIBRARY`, `DRIVER`, `MINIPORT`, `HAL`, `GDI_DRIVER` and `NOTARGET` (no normal linked binary at that node). Other types and local overrides exist; consult [`tools/makefile.def`](../tools/makefile.def) instead of inferring a file extension solely from the declaration.

## Intended Windows workflow (not executed here)

From the repository README, in a suitably provisioned Windows build environment with source at `C:\NT`:

```bat
C:\Windows\system32\cmd.exe /k C:\NT\tools\razzle.cmd free offline
build /cZP
rem or, for an incremental pass:
build /ZP
C:\NT\tools\postbuild.cmd
```

These are **historic instructions**, not a test of this checkout. Razzle's options are parsed in [`tools/razzle.cmd`](../tools/razzle.cmd). `free` selects the free build (omitting it selects checked); `binaries_dir` changes the output location; architecture selection and tool paths vary. Its spelling for the mixed checked-kernel switch is **`ChkKernel`** in the script, while the root README says `CkhKernel`; consult the script rather than silently relying on the README. `offline` sets `BUILD_OFFLINE`; it is not a substitute for missing source/tool dependencies. Razzle is designed for a clean `cmd` session, not a Unix shell or repeated nested invocation.

A local targeted Windows build can start in a component folder with its required environment and `build` command, but project dependencies/publication must be available. `build /cZP` is the README's clean rebuild command; `build /ZP` its incremental command. Avoid claiming those flags will compile an arbitrary isolated directory. Outputs/obj dirs and staged binaries (`_NTTREE`) are **generated**, not source changes; inspect [`tools/razzle.cmd`](../tools/razzle.cmd) for their actual paths on the chosen host/architecture.

## Phases and artifacts

1. **Configuration:** Razzle establishes target architecture (x86, AMD64/Win64, IA64 and legacy variants referenced in the tree), free/checked mode, compiler paths, source root and binaries tree. Not every architecture branch is supported by the files or tools present here.
2. **Traversal and compilation:** root `dirs` orders projects, then child `dirs`; `build.exe`/NMAKE consume `sources` and shared rules, generate objects/IDL/resources, link binaries and place files/libraries. Order is significant: for example [`com/dirs`](../com/dirs) warns that IDL must be early, and [`admin/dirs`](../admin/dirs) specifies `burnslib`/`dsadminlib` before dependent projects.
3. **Version and published interfaces:** root [`makefil0`](../makefil0) contains clean, build-date/build-number and publication-related targets. [`public/sdk/inc/ntverp.h`](../public/sdk/inc/ntverp.h) holds version macros. Headers, IDL output and import libs published by one project feed other targets; see [interfaces](interfaces.md).
4. **Postbuild/staging:** [`tools/postbuild.cmd`](../tools/postbuild.cmd) invokes the data-driven runner in [`tools/postbuildscripts`](../tools/postbuildscripts); [`pbuild.dat`](../tools/postbuildscripts/pbuild.dat) sequences layout, packaging, signing, catalogs, SFC manifests, compression, symbol/image/file checks and other steps using `BEGIN`/`END` barriers and mode tags. This is more than copying EXEs. Some operations expect build-lab infrastructure and may alter temp/staging directories.
5. **Media/SKUs:** setup/INF and SKU-specific files come from [`base/ntsetup`](../base/ntsetup) and many project `setup`/`sld` folders; [`tools/postbuildscripts/cdimage.cmd`](../tools/postbuildscripts/cdimage.cmd) is in the postbuild sequence. The root README lists SKU codes `srv`, `sbs`, `ads`, `dtc`, `bla`, `per`, `pro`; these codes do **not** prove every SKU image can be produced here. Its referenced `tools\oscdimg.cmd` is absent in this checkout.

## Choice points to check for every change

* **Architecture:** `dirs` can contain entries like `foo{x86}` or `foo{ia64,x86}`; `sources` may vary by `i386`, `amd64`, `ia64`, `wow6432`, `up`, `mp`, `pae`, etc. `wow64` is an interface/compatibility path, not a second native OS.
* **Build flavor and locale:** free vs checked, language/resource directories and international build scripts can change selected files. A language folder under `bldr` or a resource tree is not a separate executable feature.
* **SKU/role:** setup INFs, hives, packages, `sld` descriptions and postbuild filters can decide what is installed or shipped even when a target compiles.
* **Optional/missing:** `DIRS`, `OPTIONAL_DIRS`, `!IF` macros and publication order determine reachability. A file's presence in Git does not make it a root build target.
* **Output vs source:** published interfaces under `public/`, generated IDL/resource artifacts, tools/binaries and packaging steps are different artifacts. Avoid committing local build outputs or modifying a published copy without locating its owner.

## Checkout limitations

This is an *observed*, non-exhaustive set of mismatches; verify again when the tree changes:

* Root [`dirs`](../dirs) names `QFE`, but there is no root `QFE/` directory; it does **not** name the present `termsrv/`, `public/`, `tools/`, or `developer/` trees. On a Windows filesystem its `Base`/`base` capitalization is normal; on Linux do not treat it as a working case-sensitive build manifest.
* Some nested `dirs` reference folders absent from this checkout: e.g. [`com/dirs`](../com/dirs) includes `OleAutomation` and `netfx`; [`inetcore/dirs`](../inetcore/dirs) includes `java` and `vml`; [`termsrv/dirs`](../termsrv/dirs) includes `newclient`; [`drivers/dirs`](../drivers/dirs) includes `oem`. Many other historical dependencies may also be unavailable.
* The root README calls for `tools\missing.cmd` and `tools\oscdimg.cmd`, neither of which is present. Do not replace them with an unrelated tool and then call the product build reproduced. [`tools/postbuildscripts/cdimage.cmd`](../tools/postbuildscripts/cdimage.cmd) exists but is a different postbuild component.
* Some checked-in binaries/data are present, and the README itself disclaims provenance. These guides neither certify licensing nor guarantee the availability of original compilers, signing services, servers, or installation media. No full build, installation, or boot test was run in this Linux workspace.

For a safe documentation check here: `python3 agents/generate_catalog.py --check`, `python3 agents/verify.py`, and `git diff --check`. For actual compilation use a correctly configured Windows environment, explicitly record architecture/flavor/SKU and dependencies, and report missing pieces rather than masking them.
