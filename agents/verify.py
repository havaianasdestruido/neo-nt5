#!/usr/bin/env python3
"""Validate agent-doc navigation and top-level guide coverage (standard library only).

Run separately from generate_catalog.py --check: this checks the *written* Markdown,
not the source inventory generation logic. It does not build or execute NEONT sources.
"""

from __future__ import annotations

import os
from pathlib import Path
import re
import subprocess
import sys
from urllib.parse import unquote, urlsplit

ROOT = Path(__file__).resolve().parent.parent
DOCS = ROOT / "agents"
LINK = re.compile(r"\]\(([^)]+)\)")
HEADING = re.compile(r"^#{1,6}\s+(.+?)\s*#*\s*$", re.M)


def anchors(text: str) -> set[str]:
    slugs: set[str] = set()
    for heading in HEADING.findall(text):
        heading = re.sub(r"\[([^]]+)\]\([^)]+\)", r"\1", heading)
        heading = re.sub(r"<[^>]*>", "", heading).replace("`", "").lower()
        heading = re.sub(r"[^\w\- ]", "", heading, flags=re.UNICODE)
        slug = heading.replace(" ", "-")
        # GitHub-style duplicate heading slugs gain a numeric suffix.
        candidate, number = slug, 0
        while candidate in slugs:
            number += 1
            candidate = f"{slug}-{number}"
        slugs.add(candidate)
    return slugs


def main() -> int:
    # OPTIMIZATION: Performance optimization by Bolt ⚡
    # In large link sets (~56k links across docs), using `Path.resolve()` invokes syscalls
    # (`os.stat`/`realpath`) for every parent component of every link target, taking ~10s.
    # Replacing `Path.resolve()` with pure lexical normalization (`os.path.normpath`) and
    # caching markdown file texts reduces `agents/verify.py` runtime from ~10s to ~2.5s (~4x speedup).
    errors: list[str] = []
    docs = sorted(DOCS.rglob("*.md"))
    doc_texts = {p: p.read_text(encoding="utf-8") for p in docs}
    anchor_cache = {p: anchors(text) for p, text in doc_texts.items()}

    for page, text in doc_texts.items():
        page_parent = page.parent
        for target in LINK.findall(text):
            parsed = urlsplit(target)
            if parsed.scheme or parsed.netloc:
                continue
            dest = Path(os.path.normpath(os.path.join(page_parent, unquote(parsed.path)))) if parsed.path else page
            if not dest.exists():
                errors.append(f"{page.relative_to(ROOT)}: broken link {target}")
            elif parsed.fragment and dest.suffix == ".md" and unquote(parsed.fragment) not in anchor_cache.get(dest, set()):
                errors.append(f"{page.relative_to(ROOT)}: missing heading #{parsed.fragment} in {dest.relative_to(ROOT)}")

    paths = subprocess.check_output(["git", "ls-files", "-z"], cwd=ROOT).split(b"\0")
    roots = set()
    children: dict[str, set[str]] = {}
    for raw in paths:
        if not raw:
            continue
        parts = raw.decode("utf-8", "surrogateescape").split("/")
        if len(parts) < 2 or parts[0] in ("agents", ".jules"):
            continue
        roots.add(parts[0])
        if len(parts) > 2:
            children.setdefault(parts[0], set()).add(parts[1])

    entry = (DOCS / "README.md").read_text(encoding="utf-8")
    for root in sorted(roots):
        guide = DOCS / "components" / f"{root}.md"
        if not guide.exists():
            errors.append(f"missing guide: {guide.relative_to(ROOT)}")
            continue
        if f"components/{root}.md" not in entry:
            errors.append(f"agents/README.md does not link {guide.relative_to(ROOT)}")
        if not (DOCS / "catalog" / f"{root}.md").exists():
            errors.append(f"missing catalog page: catalog/{root}.md")
        # sdktools contains hundreds of command-specific tools; its page groups families
        # and explicitly delegates per-tool inventory to the generated catalog.
        if root == "sdktools":
            continue
        linked = set()
        guide_text = doc_texts.get(guide) or guide.read_text(encoding="utf-8")
        guide_parent = guide.parent
        root_dir = ROOT / root
        for target in LINK.findall(guide_text):
            parsed = urlsplit(target)
            if not parsed.scheme and parsed.path:
                dest = Path(os.path.normpath(os.path.join(guide_parent, unquote(parsed.path))))
                if dest.parent == root_dir:
                    linked.add(dest.name)
        for child in sorted(children.get(root, set()) - linked):
            errors.append(f"{guide.relative_to(ROOT)}: no direct link for {root}/{child}/")

    if errors:
        print("\n".join(errors), file=sys.stderr)
        return 1
    print(f"Verified {len(docs)} Markdown pages and {len(roots)} component guides")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
