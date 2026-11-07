#!/usr/bin/env python3
"""Generate a deterministic, evidence-based function inventory from tracked files."""
import argparse
import ast
import hashlib
from functools import lru_cache
import os
from pathlib import Path
import re
import sqlite3
import subprocess
import tempfile
from urllib.parse import quote

from tree_sitter import Language, Parser
import tree_sitter_c
import tree_sitter_cpp

ROOT = Path(__file__).resolve().parents[2]
EXTENSIONS = {'.c': 'c', '.h': 'cpp', '.cpp': 'cpp', '.cxx': 'cpp', '.cc': 'cpp', '.hpp': 'cpp', '.hxx': 'cpp', '.py': 'python'}
TEST_PATH = re.compile(r'(^|[/_.-])(tests?|testing|unittests?|testcases?)([/_.-]|$)', re.I)
REPO = 'https://github.com/havaianasdestruido/neo-nt5'


def tracked_files():
    data = subprocess.check_output(['git', 'ls-files', '-z', '--cached', '--others', '--exclude-standard'], cwd=ROOT)
    return sorted(set(os.fsdecode(x) for x in data.split(b'\0') if x))


def is_test(path):
    return bool(TEST_PATH.search(path))


def source_link(path, line, revision):
    return f'{REPO}/blob/{quote(revision, safe="")}/{quote(path, safe="/")}#L{line}'


def walk(node):
    stack = [node]
    while stack:
        current = stack.pop()
        yield current
        stack.extend(reversed(current.named_children))


def declarator_name(node, data):
    # Descend through pointer/function/qualified declarators, not argument names.
    while node:
        if node.type in ('identifier', 'field_identifier', 'type_identifier', 'operator_name', 'destructor_name'):
            return data[node.start_byte:node.end_byte].decode('utf-8', 'replace')
        if node.type == 'qualified_identifier':
            return data[node.start_byte:node.end_byte].decode('utf-8', 'replace')
        node = node.child_by_field_name('declarator')
    return None


def parse_c(data, parser, test):
    tree = parser.parse(data)
    definitions, calls = [], []
    for node in walk(tree.root_node):
        if node.type == 'function_definition':
            decl = node.child_by_field_name('declarator')
            body = node.child_by_field_name('body')
            name = declarator_name(decl, data)
            if name and body:
                signature = data[node.start_byte:body.start_byte].decode('utf-8', 'replace').strip()
                body_text = data[body.start_byte:body.end_byte]
                definitions.append((name, node.start_point.row + 1, signature, hashlib.sha256(body_text).hexdigest()))
        elif test and node.type == 'call_expression':
            func = node.child_by_field_name('function')
            if func:
                text = data[func.start_byte:func.end_byte].decode('utf-8', 'replace')
                name = re.split(r'::|->|\.', text)[-1].strip()
                if re.fullmatch(r'[A-Za-z_]\w*', name):
                    calls.append((name, node.start_point.row + 1))
    return definitions, calls, tree.root_node.has_error


def parse_python(data, test):
    tree = ast.parse(data)
    definitions, calls = [], []
    for node in ast.walk(tree):
        if isinstance(node, (ast.FunctionDef, ast.AsyncFunctionDef)):
            signature = ('async ' if isinstance(node, ast.AsyncFunctionDef) else '') + 'def ' + node.name + '(' + ast.unparse(node.args) + ')'
            if node.returns:
                signature += ' -> ' + ast.unparse(node.returns)
            body = ast.dump(ast.Module(body=node.body, type_ignores=[]), include_attributes=False)
            definitions.append((node.name, node.lineno, signature, hashlib.sha256(body.encode()).hexdigest()))
        elif test and isinstance(node, ast.Call):
            if isinstance(node.func, ast.Name):
                calls.append((node.func.id, node.lineno))
            elif isinstance(node.func, ast.Attribute):
                calls.append((node.func.attr, node.lineno))
    return definitions, calls, False


def inline(value):
    # Markdown code spans can contain backticks if the fence is longer.
    value = ' '.join(value.split())[:600]
    fence = '`' * (max((len(x) for x in re.findall(r'`+', value)), default=0) + 1)
    return f'{fence} {value} {fence}'


def generate(output, paths, revision):
    output.mkdir(parents=True, exist_ok=True)
    # No stale pages on a regeneration. Only remove our own generated Markdown.
    for old in output.glob('*.md'):
        old.unlink()
    parsers = {'c': Parser(Language(tree_sitter_c.language())), 'cpp': Parser(Language(tree_sitter_cpp.language()))}
    with tempfile.TemporaryDirectory() as temp:
        db = sqlite3.connect(str(Path(temp) / 'index.db'))
        db.executescript('CREATE TABLE defs (name TEXT, path TEXT, line INTEGER, signature TEXT, hash TEXT); CREATE TABLE calls (name TEXT, path TEXT, line INTEGER);')
        errors, scanned, failed = [], 0, []
        for path in paths:
            if path.startswith(('documentation/', 'agents/')):
                continue
            lang = EXTENSIONS.get(Path(path).suffix.lower())
            if not lang or not (ROOT / path).is_file():
                continue
            try:
                data = (ROOT / path).read_bytes()
                if lang == 'python':
                    defs, calls, has_errors = parse_python(data, is_test(path))
                else:
                    defs, calls, has_errors = parse_c(data, parsers[lang], is_test(path))
                db.executemany('INSERT INTO defs VALUES (?,?,?,?,?)', ((n, path, l, s, h) for n, l, s, h in defs))
                db.executemany('INSERT INTO calls VALUES (?,?,?)', ((n, path, l) for n, l in calls))
                scanned += 1
                if has_errors:
                    errors.append(path)
            except (OSError, SyntaxError, ValueError, UnicodeError) as exc:
                failed.append((path, str(exc).splitlines()[0]))
        db.executescript('CREATE INDEX defs_name ON defs(name); CREATE INDEX calls_name ON calls(name);')
        db.commit()
        total = db.execute('SELECT count(*) FROM defs').fetchone()[0]
        calls_count = db.execute('SELECT count(*) FROM calls').fetchone()[0]
        @lru_cache(maxsize=50000)
        def variants_for(name):
            return db.execute('SELECT count(*), count(DISTINCT hash) FROM defs WHERE name=?', (name,)).fetchone()

        @lru_cache(maxsize=50000)
        def tests_for(name):
            rows = db.execute('SELECT path,line FROM calls WHERE name=? ORDER BY path,line LIMIT 20', (name,)).fetchall()
            count = db.execute('SELECT count(*) FROM calls WHERE name=?', (name,)).fetchone()[0]
            return rows, count

        # Bucket by top-level tree and stable sorted chunks to avoid a single enormous page.
        buckets = db.execute("SELECT DISTINCT CASE WHEN instr(path, '/') > 0 THEN substr(path, 1, instr(path, '/') - 1) ELSE 'root' END FROM defs ORDER BY 1").fetchall()
        pages = []
        for (bucket,) in buckets:
            rows = db.execute("SELECT name,path,line,signature,hash FROM defs WHERE (CASE WHEN instr(path, '/') > 0 THEN substr(path, 1, instr(path, '/') - 1) ELSE 'root' END)=? ORDER BY path,line,name", (bucket,))
            page = []
            part = 0
            def flush():
                nonlocal part, page
                if not page: return
                part += 1
                filename = f'{bucket.lower()}-{part:04d}.md'
                title = f'{bucket} functions · {part}'
                (output / filename).write_text('---\ntitle: ' + title + '\nsidebar_position: 2\n---\n\n' + '\n'.join(page), encoding='utf-8')
                pages.append((title, filename[:-3]))
                page = []
            for name, path, line, signature, digest in rows:
                # C++ qualified names are compared by leaf name, so the association is intentionally conservative.
                leaf = name.split('::')[-1]
                variants = variants_for(name)
                tests, test_total = tests_for(leaf)
                test_text = ', '.join(f'[test call]({source_link(p,l,revision)})' for p,l in tests) or 'No matching call found in test-named files.'
                if test_total > len(tests): test_text += f' (showing {len(tests)} of {test_total})'
                difference = (f'{variants[0]} definitions with this exact name; {variants[1]} distinct body hashes. '
                              'Different hashes indicate text differences, not necessarily different behavior.' if variants[0] > 1 else 'No other extracted definition with this exact name.')
                page.append(f'## {inline(name)}\n\n- Source: [{inline(path)}:{line}]({source_link(path,line,revision)})\n- Signature: {inline(signature)}\n- Implementation: inspect the linked definition and body; this index does not infer runtime behavior.\n- Variants: {difference}\n- Test evidence: {test_text}\n')
                if len(page) >= 300: flush()
            flush()
        summary = (f'---\ntitle: Generated function index\nsidebar_position: 1\n---\n\n'
                   f'Source revision: {inline(revision)}. Scanned {scanned:,} supported files; found {total:,} definitions and {calls_count:,} syntactic calls in test-named files. '
                   f'{len(errors):,} C/C++ files had parse errors; {len(failed):,} files could not be parsed. See the [coverage report](coverage).\n\n'
                   'This is a syntactic inventory, not proof of behavior or coverage. Test matches are by unqualified name, may be unrelated, and do not show execution or assertions. '
                   'Definitions can be missed by macros, conditional compilation, parser errors, or unsupported languages. Body hashes compare text, not semantics. '
                   'Follow source links to understand control flow, configuration and actual test assertions.\n\n## Browse\n\n' + ''.join(f'- [{title}]({slug})\n' for title, slug in pages))
        (output / 'index.md').write_text(summary, encoding='utf-8')
        report = '---\ntitle: Extraction coverage\n---\n\nC/C++ parse errors may still yield partial results. Python syntax errors yield no results. Headers are parsed as C++. Only C, C++ and Python definitions are indexed; assembly, scripts and other languages are not. Preprocessing, generated code, declarations without bodies and dynamic calls are not resolved. The documentation and agent directories are excluded to prevent self-indexing. Test files are identified by test-related path segments, not execution metadata.\n\n'
        report += '## C/C++ files with parse errors\n\n' + (''.join(f'- [{inline(p)}]({REPO}/blob/{quote(revision, safe="")}/{quote(p, safe="/")})\n' for p in errors) or 'None.\n')
        report += '\n## Files that could not be parsed\n\n' + (''.join(f'- {inline(p)}: {inline(e)}\n' for p,e in failed) or 'None.\n')
        (output / 'coverage.md').write_text(report, encoding='utf-8')
        print(f'Scanned {scanned} files, {total} definitions, {calls_count} test calls, {len(errors)} partial parses, {len(failed)} failures; wrote {len(pages)} pages.')


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--output', type=Path, default=ROOT / 'documentation/site/docs/reference')
    parser.add_argument('--revision', default=os.environ.get('GITHUB_SHA'))
    parser.add_argument('--prefix', action='append', help='Limit to tracked paths with this prefix (repeatable; useful for development).')
    args = parser.parse_args()
    revision = args.revision or subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=ROOT, text=True).strip()
    paths = tracked_files()
    if args.prefix: paths = [p for p in paths if any(p.startswith(x) for x in args.prefix)]
    generate(args.output, paths, revision)

if __name__ == '__main__':
    main()
