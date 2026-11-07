#!/usr/bin/env python3
"""Build a navigable, source-linked syntactic inventory from tracked files."""
import argparse
import hashlib
import json
import re
import sqlite3
import subprocess
import tempfile
from collections import Counter
from pathlib import Path

from tree_sitter_language_pack import get_parser

ROOT = Path(__file__).resolve().parents[1]
LANGS = {'.c': 'c', '.h': 'cpp', '.cpp': 'cpp', '.cxx': 'cpp', '.cc': 'cpp', '.hpp': 'cpp', '.hxx': 'cpp', '.py': 'python', '.js': 'javascript', '.java': 'java', '.cs': 'csharp'}
DEFS = {'function_definition', 'method_definition', 'method_declaration', 'constructor_declaration', 'function_declaration', 'generator_function_declaration'}
CALLS = {'call', 'call_expression', 'method_invocation', 'invocation_expression'}
CONTROLS = {'if_statement', 'for_statement', 'for_in_statement', 'while_statement', 'switch_statement', 'return_statement', 'try_statement', 'throw_statement'}
TEST = re.compile(r'(^|[/_.-])(tests?|testing|unittest|unittests|spec|specs)([/_.-]|$)', re.I)


def text(node, data):
    return data[node.start_byte:node.end_byte].decode('utf-8', 'replace') if node else ''


def walk(node):
    stack = [node]
    while stack:
        n = stack.pop()
        yield n
        stack.extend(reversed(n.named_children))


def function_name(node, data):
    name = node.child_by_field_name('name')
    if name:
        return text(name, data)
    decl = node.child_by_field_name('declarator')
    if decl:
        # Follow the declarator chain, rather than picking an argument identifier.
        while decl.child_by_field_name('declarator'):
            decl = decl.child_by_field_name('declarator')
        return text(decl, data)
    return ''


def call_name(node, data):
    target = node.child_by_field_name('function') or node.child_by_field_name('name')
    if not target:
        return ''
    value = text(target, data)
    match = re.search(r'([A-Za-z_][A-Za-z_0-9]*)\s*$', value)
    return match.group(1) if match else ''


def read_source(path):
    raw = path.read_bytes()
    if raw.startswith((b'\xff\xfe', b'\xfe\xff')):
        return raw.decode('utf-16', 'replace').encode('utf-8')
    # Most of this tree predates UTF-8. Preserve line breaks and valid UTF-8.
    return raw.decode('utf-8-sig', 'replace').encode('utf-8')


def tracked(root):
    data = subprocess.check_output(['git', 'ls-files', '-z'], cwd=root)
    return [p.decode('utf-8', 'surrogateescape') for p in data.split(b'\0') if p]


def generate(root, output, paths):
    output.mkdir(parents=True, exist_ok=True)
    # Never leave stale shards behind after a regeneration.
    for p in output.glob('*.json'):
        p.unlink()
    parsers = {}
    stats = Counter()
    with tempfile.TemporaryDirectory() as temp:
        db = sqlite3.connect(str(Path(temp) / 'inventory.sqlite'))
        db.executescript('CREATE TABLE defs (name TEXT, path TEXT, line INTEGER, end INTEGER, signature TEXT, digest TEXT, calls TEXT, controls TEXT); CREATE TABLE uses (name TEXT, path TEXT, line INTEGER);')
        for path in sorted(paths):
            ext = Path(path).suffix.lower()
            language = LANGS.get(ext)
            if not language or path.startswith(('website/', 'node_modules/')):
                continue
            file = root / path
            if not file.is_file():
                continue
            try:
                data = read_source(file)
                parser = parsers.setdefault(language, get_parser(language)) if language not in parsers else parsers[language]
                tree = parser.parse(data)
            except (OSError, ValueError) as exc:
                stats['unreadable'] += 1
                print(f'Skipped {path}: {exc}')
                continue
            stats['files'] += 1
            if tree.root_node.has_error:
                stats['files_with_parse_errors'] += 1
            is_test = bool(TEST.search(path))
            if is_test:
                stats['test_files'] += 1
            for node in walk(tree.root_node):
                if node.type in DEFS:
                    name = function_name(node, data)
                    body = node.child_by_field_name('body')
                    if not name or not body:
                        continue
                    sig = data[node.start_byte:body.start_byte].decode('utf-8', 'replace').strip()
                    descendants = list(walk(body))
                    calls = sorted({call_name(n, data) for n in descendants if n.type in CALLS} - {''})
                    controls = Counter(n.type.replace('_statement', '') for n in descendants if n.type in CONTROLS)
                    digest = hashlib.sha256(data[body.start_byte:body.end_byte]).hexdigest()
                    db.execute('INSERT INTO defs VALUES (?,?,?,?,?,?,?,?)', (name, path, node.start_point.row + 1, node.end_point.row + 1, sig[:1000], digest, json.dumps(calls), json.dumps(controls)))
                    stats['functions'] += 1
                if is_test and node.type in CALLS:
                    name = call_name(node, data)
                    if name:
                        db.execute('INSERT INTO uses VALUES (?,?,?)', (name, path, node.start_point.row + 1))
                        stats['test_calls'] += 1
        db.commit()
        db.executescript('CREATE INDEX defs_name ON defs(name,path,line); CREATE INDEX uses_name ON uses(name,path,line);')
        manifest = {'stats': dict(stats), 'components': []}
        components = [x[0] for x in db.execute("SELECT DISTINCT CASE WHEN instr(path, '/') > 0 THEN substr(path,1,instr(path,'/')-1) ELSE '(root)' END FROM defs ORDER BY 1")]
        for component in components:
            condition = "path NOT LIKE '%/%'" if component == '(root)' else 'substr(path,1,?) = ?'
            args = () if component == '(root)' else (len(component) + 1, component + '/')
            cursor = db.execute('SELECT name,path,line,end,signature,digest,calls,controls FROM defs WHERE ' + condition + ' ORDER BY path,line', args)
            shards = []
            while True:
                rows = cursor.fetchmany(500)
                if not rows:
                    break
                entries = []
                for name, path, line, end, sig, digest, calls, controls in rows:
                    # Matching is lexical, not symbol resolution; include totals when truncated.
                    variants = db.execute('SELECT path,line,digest FROM defs WHERE name=? ORDER BY path,line LIMIT 21', (name,)).fetchall()
                    uses = db.execute('SELECT path,line FROM uses WHERE name=? ORDER BY path,line LIMIT 21', (name.split('::')[-1],)).fetchall()
                    entries.append({'name': name, 'path': path, 'line': line, 'end': end, 'signature': sig, 'hash': digest, 'calls': json.loads(calls), 'controls': json.loads(controls), 'variants': variants[:20], 'variantsMore': len(variants) > 20, 'tests': uses[:20], 'testsMore': len(uses) > 20})
                filename = f'{len(manifest["components"])}-{len(shards)}.json'
                (output / filename).write_text(json.dumps(entries, ensure_ascii=True, separators=(',', ':')), encoding='utf-8')
                shards.append({'file': filename, 'first': rows[0][1], 'last': rows[-1][1], 'count': len(rows)})
            manifest['components'].append({'name': component, 'shards': shards})
        (output / 'manifest.json').write_text(json.dumps(manifest, ensure_ascii=True), encoding='utf-8')
        db.close()
    print('Inventory:', dict(stats))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--root', type=Path, default=ROOT)
    parser.add_argument('--output', type=Path, default=ROOT / 'website/static/inventory')
    args = parser.parse_args()
    generate(args.root, args.output, tracked(args.root))


if __name__ == '__main__':
    main()
