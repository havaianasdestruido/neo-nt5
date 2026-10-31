#!/usr/bin/env python3
"""Count task statuses in PLAN.md so the snapshot in section 0.6 stays accurate.

Usage:
    python3 agents/plan_stats.py           # print counts
    python3 agents/plan_stats.py --write   # also rewrite the snapshot line

The parser is intentionally strict: a task line must look like

    - `[ ]` **P1 `NET-010`** — title ...

Anything else (prose, subtasks, table rows) is ignored. This keeps the numbers
honest: if a task is malformed, it is not counted, and the totals drop.
"""
from __future__ import annotations

import argparse
import re
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
PLAN = ROOT / "PLAN.md"

TASK_RE = re.compile(
    r"^- `\[(?P<status>.)\]` \*\*(?P<pri>P\d) `(?P<id>[A-Z]+-\d{3}[a-z]?)`\*\*", re.MULTILINE
)
BLOCKED_RE = re.compile(r"^\| `\[!\]` \| \*\*BLK-", re.MULTILINE)
SNAPSHOT_RE = re.compile(
    r"^\*\*Task-count snapshot \(\d{4}-\d{2}-\d{2}\):\*\*.*?$", re.MULTILINE
)


def collect(text: str):
    tasks = [m.groupdict() for m in TASK_RE.finditer(text)]
    blocked = len(BLOCKED_RE.findall(text))
    ids = [t["id"] for t in tasks]
    dupes = sorted({i for i, n in Counter(ids).items() if n > 1})
    return tasks, blocked, dupes


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--write", action="store_true", help="update the snapshot line")
    ap.add_argument("--date", default="2026-10-31")
    args = ap.parse_args()

    text = PLAN.read_text(encoding="utf-8")
    tasks, blocked, dupes = collect(text)
    status = Counter(t["status"] for t in tasks)
    pri = Counter(t["pri"] for t in tasks)

    line = (
        f"**Task-count snapshot ({args.date}):** {len(tasks)} scheduled tasks — "
        f"{status.get('x', 0)} `[x]`, {status.get(' ', 0)} `[ ]`; "
        f"plus {blocked} `[!]` blocked items tracked centrally in §10 (`BLK-001…BLK-{blocked:03d}`). "
        "Counts are regenerated with `python3 agents/plan_stats.py --write`."
    )

    print(f"tasks: {len(tasks)}")
    print("by status:", dict(status))
    print("by priority:", dict(sorted(pri.items())))
    print("blocked items:", blocked)
    if dupes:
        print("DUPLICATE IDS:", ", ".join(dupes))
    else:
        print("duplicate ids: none")

    if args.write:
        if not SNAPSHOT_RE.search(text):
            raise SystemExit("snapshot line not found in PLAN.md")
        text = SNAPSHOT_RE.sub(line, text, count=1)
        PLAN.write_text(text, encoding="utf-8")
        print("snapshot updated")

    return 1 if dupes else 0


if __name__ == "__main__":
    raise SystemExit(main())
