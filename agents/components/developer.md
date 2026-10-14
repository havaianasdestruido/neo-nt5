# `developer/` — historical per-developer build profiles

This small tree is **not** a runtime Windows subsystem. Its [`makefile`](../../developer/makefile) describes merging public and per-user private profile data (e.g. `netnav.ini`/`accounts.net`) for the historical build environment. [`anvil.inc`](../../developer/anvil.inc), [`anvil.mak`](../../developer/anvil.mak), and the `.pub` files are additional checked-in build/profile inputs. The expected per-user/private files and some referenced inputs are not present here; do not invoke it as a general repo setup step.

The root [`dirs`](../../dirs) does not include `developer/`. See the [directory catalog entry](../catalog/developer.md), [Razzle/build guide](../build-and-release.md) and [`tools/razzle.cmd`](../../tools/razzle.cmd) for how personal configuration could have been consumed. Never check in personal build configuration or credentials to make this historical makefile run.
