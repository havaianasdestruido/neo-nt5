#!/usr/bin/env python3
"""Validate agent-doc navigation and top-level guide coverage (standard library only).

Run separately from generate_catalog.py --check: this checks the *written* Markdown,
not the source inventory generation logic. It does not build or execute NT sources.
"""

from __future__ import annotations

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
    errors: list[str] = []
    docs = sorted(DOCS.rglob("*.md"))
    anchor_cache = {p: anchors(p.read_text(encoding="utf-8")) for p in docs}
    for page in docs:
        for target in LINK.findall(page.read_text(encoding="utf-8")):
            parsed = urlsplit(target)
            if parsed.scheme or parsed.netloc:
                continue
            dest = (page.parent / unquote(parsed.path)).resolve() if parsed.path else page
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
        if len(parts) < 2 or parts[0] == "agents":
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
        for target in LINK.findall(guide.read_text(encoding="utf-8")):
            parsed = urlsplit(target)
            if not parsed.scheme and parsed.path:
                dest = (guide.parent / unquote(parsed.path)).resolve()
                if dest.parent == ROOT / root:
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
