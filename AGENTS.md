# AGENTS.md — source-code-only change policy

This file is **mandatory** for every human or AI agent working in this repository.
It takes precedence over generated guides, prior notes (including `.jules/*.md`),
and any earlier instruction that encourages editing HTML or other non-source
content to "improve" the product.

---

## 1. The one rule

**Never edit `.htm` / `.html` files (any letter case) to make a visual change.**

Visual, layout, text, theme, icon, or accessibility changes must be implemented
in the **real source code** — C, C++, headers, assembly, and Batchfile — the code
that is actually compiled into the product. HTML in this tree is *shipped
content / generated output / legacy documentation*, not the place where behavior
or appearance is defined.

Editing an `.htm` file is not a fix. It does not compile, it is not validated by
the build, and it is routinely overwritten or ignored. If a change only "works"
because you edited HTML, you have not changed the product.

> Default scope for **any** task: `*.c`, `*.cpp`, `*.cxx`, `*.h`, `*.hpp`,
> `*.hxx`, `*.inc`, `*.asm`, and `*.bat` / `*.cmd`.
> If the change cannot be expressed there, stop and report instead of editing content.

---

## 2. In scope

| Kind | Examples | Notes |
| --- | --- | --- |
| C / C++ implementation | `*.c`, `*.cpp`, `*.cxx`, `*.h`, `*.hpp`, `*.hxx`, `*.inc` | Primary place for behavior, UI logic, strings built in code, performance and security fixes. |
| Assembly | `*.asm`, `*.s` | Only next to the C/C++ code it belongs to. |
| Batchfile | `*.bat`, `*.cmd` | Build, install, packaging, and environment logic. |
| Compiled resource source | `*.rc`, `*.rc2`, resource headers | Allowed **only** when a source-level change genuinely needs a resource (dialog, string table, version block). Never for pure cosmetic restyling. |
| IDL / interfaces | `*.idl` | Only when a source change alters a real interface, with consumers traced. |
| Build definitions | `sources`, `dirs`, `makefile*`, `*.mk` | Only the minimum needed to compile the source you changed. |

Headers and build definitions are support for a source change — they are not a
loophole for editing static content.

---

## 3. Out of scope — do not touch

* **`.htm` / `.html` in any casing, anywhere in the tree.**
  This includes UI pages, "web views", admin consoles, help, samples, and
  generated reports. There are ~5,200 of them and none of them is the fix.
* Web and UI payload assets: `*.css`, `*.js`, `*.xsl`, `*.gif`, `*.jpg`,
  `*.bmp`, `*.ico`, `*.png`, `*.chm`, `*.hh*`.
* Documentation and agent metadata: `*.md`, `agents/`, `agents/catalog/`,
  `.jules/`, `README.md` — unless the task is explicitly documentation work.
* Localized text dumps, spreadsheets, and data files (`*.txt`, `*.csv`,
  `*.xml`) used as content rather than as compiled source.
* Binaries, installable output, build artifacts, and generated files.
* Anything that is not directly required by the requested source change.

If a file does not compile into the product, assume it is out of scope until the
task proves otherwise.

---

## 4. Stop doing low-value work

Do **not** spend turns on changes that do not matter:

* No drive-by visual polish: colors, spacing, fonts, icon swaps, `alt=""`
  attributes in HTML, "modernized" markup, re-indented web pages.
* No "performance improvements" in non-source files (Python helper scripts,
  docs tooling, Markdown) unless the task is specifically about those scripts.
* No sweeping "security hardening" of static content, documentation, or shipped
  HTML. Real security fixes belong in C/C++ — parsing, bounds checks,
  authentication, handle/privilege handling — and must be narrow and justified.
* No mass reformatting, whitespace normalization, or file rewrites across
  unrelated paths. Do not rewrite tens of thousands of files to "clean up".

Performance and security work **is** welcome when it lands in real source code
and has a concrete, explainable effect. Speculative edits to content files are
noise and will be rejected.

---

## 5. When HTML looks like "the only way"

1. Stop. Do not edit the HTML.
2. Identify the source that produces or consumes that page: a C/C++ module, a
   resource script, a Batchfile that generates it, or a build target.
3. Change the source. If the page is generated, fix the generator or template
   **source**, never the generated output.
4. If no source-level path exists in this checkout, report the limitation and
   ask before touching any content file.

The only exception is an explicit, itemized instruction from the user that names
the exact HTML file and asks for that file itself. Vague goals such as "make it
look better", "fix the visuals", or "improve the UI" never qualify.

---

## 6. Required workflow

1. **Locate the owner.** Use `agents/README.md` and `agents/catalog/` to find the
   component; search a likely subtree (`rg -n 'Symbol' base/ntos`), not the whole
   tree.
2. **Edit source only.** Match surrounding style, calling conventions, error
   handling, and platform/SKU/locale variants.
3. **Keep it narrow.** Smallest coherent change; no unrelated refactors.
4. **Validate honestly.**
   * `git diff --check`
   * confirm every changed path is an in-scope source file
   * if the diff contains any `.htm`/`.html` hunk, revert it before submitting
   * state what was **not** built or tested (this checkout has no Linux compile
     target; do not claim a build you did not run)
5. **Report exact paths** and the reason each one had to change.

---

## 7. Quick reference

| Request | Do | Do not |
| --- | --- | --- |
| "Change how this dialog looks" | Edit the C/C++ UI code or the compiled `.rc` that owns it | Edit a `.htm` that mirrors the UI |
| "Fix this label/string" | String table in `.rc` or the C source that formats it | Find-and-replace in `.html` |
| "Improve the build/install flow" | `tools/**/*.cmd`, `*.bat` | Edit docs or static pages |
| "Make it faster" | C/C++ hot path, measured and explained | Rewrite script/doc formatting |
| "Make it safer" | C/C++ bounds/auth/handle logic | Mass-edit static content |
| "Make it prettier" | Real UI source, if the task explicitly asks for it | HTML/CSS/GIF tweaks |

---

**Summary:** only real source code. C/C++, headers, assembly, and Batchfile for
anything; compiled resources only when the source change requires them. Never
HTML for visual changes. Skip the low-value cosmetic, micro-performance, and
speculative security edits to non-source files.
