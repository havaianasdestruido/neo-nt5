#!/usr/bin/env python3
"""Generate a deterministic, evidence-based function inventory from tracked files."""
import argparse
import ast
import hashlib
from functools import lru_cache
import html
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


def esc(value):
    return html.escape(str(value))


def inline(value):
    # Inline code: whitespace collapsed, capped, HTML-escaped.
    value = ' '.join(str(value).split())[:600]
    return f'<code>{esc(value)}</code>'


def code_block(value, language='c'):
    """Render a quoted snippet as a pre block. Whitespace is collapsed (a signature is one logical line)."""
    body = ' '.join(str(value).split())[:600] or '(no signature captured)'
    return f'<pre><code>{esc(body)}</code></pre>'


def literal_block(text):
    """Render literal multi-line code, preserving newlines and escaping HTML."""
    return f'<pre><code>{esc(text.strip())}</code></pre>'


CSS = (
    'body{font-family:system-ui,-apple-system,"Segoe UI",sans-serif;max-width:62rem;'
    'margin:2rem auto;padding:0 1rem;line-height:1.55;color:#1a1a1a}'
    'nav{border-bottom:1px solid #ddd;padding-bottom:.6rem;margin-bottom:1.5rem}'
    'h1{font-size:1.7rem}h2{font-size:1.3rem;border-bottom:1px solid #eee;'
    'padding-bottom:.3rem;margin-top:2.2rem}h3{font-size:1.05rem;margin-top:1.6rem}'
    'code{background:#f2f2f2;padding:.08em .3em;border-radius:3px;font-size:.88em;'
    'font-family:ui-monospace,SFMono-Regular,Menlo,monospace}'
    'pre{background:#f6f6f6;padding:1rem;overflow-x:auto;border-radius:4px}'
    'pre code{background:none;padding:0}'
    'a{color:#275aa8}li{margin:.2rem 0}'
)


def render_page(title, body):
    """Wrap body HTML in a standalone page. Reference pages are plain static HTML
    copied verbatim by Docusaurus, so they must not depend on the site theme."""
    return (
        '<!DOCTYPE html>\n<html lang="en">\n<head>\n<meta charset="utf-8">\n'
        '<meta name="viewport" content="width=device-width, initial-scale=1">\n'
        f'<title>{esc(title)} | NEONT 5 function index</title>\n'
        f'<style>{CSS}</style>\n</head>\n<body>\n'
        '<nav><a href="../">Guides</a> &middot; <a href="index.html">Function index</a>'
        ' &middot; <a href="coverage.html">Coverage</a></nav>\n<main>\n'
        f'<h1>{esc(title)}</h1>\n{body}\n</main>\n</body>\n</html>\n'
    )


def page_faq(bucket, part, stats):
    """FAQ for one generated function-index page, built from that page's own extracted data."""
    name, path, line, signature = stats['first'] or ('', '', 0, '')
    total, dupes, tested = stats['count'], stats['variants'], stats['tests']
    untested = total - tested
    dupe_text = (f'{dupes} of the {total} entries on this page share a name with another extracted '
                 'definition elsewhere in the tree.' if dupes else
                 'No entry on this page shares its name with another extracted definition in the tree.')
    return (
        '<h2>Frequently asked questions</h2>\n'
        '<h3>What does this page show?</h3>\n'
        f'<p>Function definitions extracted from tracked C, C++ and Python files under '
        f'<code>{esc(bucket)}/</code>, page {part} of that tree. This page lists {total} definitions, '
        f'each with a source link, the signature as written, a same-name comparison, and any '
        f'syntactic calls found in test-named files. Nothing here is inferred behavior.</p>\n'
        '<h3>How was the signature captured?</h3>\n'
        '<p>Everything from the start of the definition up to the opening brace of its body, with '
        'whitespace collapsed and a 600-character cap. It is a quotation of the source text, not a '
        'normalized prototype, so macros, <code>IN</code>/<code>OUT</code> annotations and comments '
        'survive. Much of this tree writes its routine-description comment <em>between</em> the '
        'parameter list and the body, so that comment is part of the captured text and can be cut '
        f'off by the cap. The first entry on this page ({inline(name)}, {inline(path)}:{line}) was '
        f'captured as:</p>\n'
        f'{code_block(signature)}\n'
        '<h3>Why do some names appear more than once?</h3>\n'
        f'<p>{esc(dupe_text)} The comparison is by name only: C++ qualified names are reduced to '
        'their leaf, and unrelated functions in different projects can share a name. The listed '
        'body hashes tell you whether the <em>text</em> differs; identical text still does not prove '
        'identical behavior once macros, includes and build configuration differ.</p>\n'
        '<h3>Why does an entry say &ldquo;No matching call found in test-named files.&rdquo;?</h3>\n'
        '<p>Because no call expression with that leaf name was found in a file whose <em>path</em> '
        f'contains a test-related segment. {untested} of the {total} entries on this page are in '
        'that state. The detection is deliberately conservative and misses tests that are not in '
        'test-named paths, so this line describes the index rather than the code:</p>\n'
        + literal_block(
            '# documentation/scripts/generate.py\n'
            "TEST_PATH = re.compile(r'(^|[/_.-])(tests?|testing|unittests?|testcases?)([/_.-]|$)', re.I)\n"
            "bool(TEST_PATH.search('base/ntos/se/utaccess.c'))  # False, though it is a unit test"
        ) + '\n'
        '<h3>How do I get from an entry to the real answer?</h3>\n'
        '<p>Follow the source link and read the definition and its callers; follow the test links '
        'and read the assertions and setup. The index does not preprocess C/C++, resolve symbols, '
        'analyze assembly or other languages, execute anything, or explain what a function does. '
        'See the <a href="coverage.html">coverage report</a> for what could not be analyzed.</p>\n'
    )


def index_faq(scanned, total, calls_count, errors, failed, page_count, revision):
    return (
        '<h2>Frequently asked questions</h2>\n'
        '<h3>What exactly was scanned?</h3>\n'
        f'<p>{scanned:,} tracked files whose extension is one of '
        f'<code>.c .h .cpp .cxx .cc .hpp .hxx .py</code>, yielding {total:,} definitions and '
        f'{calls_count:,} call expressions inside test-named files. {errors:,} C/C++ files parsed '
        f'with errors and {failed:,} could not be parsed at all. Headers are parsed with the C++ '
        'grammar. Assembly, resource scripts, IDL, batch files and every other language are not '
        'indexed.</p>\n'
        '<h3>Why is the index not committed to Git?</h3>\n'
        '<p>Because it is derived output. <code>documentation/.gitignore</code> excludes '
        '<code>site/static/reference/</code>, and the generator deletes the HTML files in its own '
        'output directory before writing, so a narrow regeneration never leaves stale pages '
        'behind:</p>\n'
        + literal_block(
            '# documentation/scripts/generate.py\n'
            "for old in output.glob('*.html'):\n"
            '    old.unlink()'
        ) + '\n'
        '<h3>Which revision do the source links point at?</h3>\n'
        f'<p>This run used {inline(revision)}. The value comes from <code>GITHUB_SHA</code> in the '
        'Pages workflow, or from <code>git rev-parse HEAD</code> locally, and can be overridden '
        'with <code>--revision</code>. A locally generated page therefore links to the last commit, '
        'so uncommitted changes will not appear at their links.</p>\n'
        f'<h3>How are the {page_count:,} pages split?</h3>\n'
        '<p>First by top-level tree &mdash; the part of the path before the first '
        '<code>/</code> &mdash; then into pages of at most 300 entries each, ordered by path and '
        'line. That keeps any one page small enough to open while keeping every definition '
        'reachable from a stable filename.</p>\n'
        '<h3>Can I trust a &ldquo;Variants&rdquo; line as proof of duplication?</h3>\n'
        '<p>No. It reports how many extracted definitions share a name and how many distinct body '
        'hashes they have. A body hash is a SHA-256 of the body text, so whitespace and comment '
        'changes alter it, and two semantically identical bodies written differently hash '
        'differently. It is a lead for reading code, not a behavioral comparison.</p>\n'
    )


def coverage_faq(errors, failed):
    return (
        '<h2>Frequently asked questions</h2>\n'
        '<h3>Are the listed files simply broken?</h3>\n'
        '<p>Not necessarily. A C/C++ file can fail to parse here because it depends on the '
        'preprocessor, on a compiler extension, or on a legacy construct the grammar does not '
        'accept &mdash; and still compile correctly in its own build. Partial results are kept '
        'for those files.</p>\n'
        '<h3>Why are Python failures different?</h3>\n'
        '<p>A Python file is parsed with the standard <code>ast</code> module, which is exact: a '
        'syntax error yields no results at all rather than partial ones. That is why the two '
        'lists are reported separately.</p>\n'
        '<h3>Does an empty list mean the index is complete?</h3>\n'
        '<p>No. Only files the generator attempted and failed on appear here. Files it never '
        'attempts &mdash; assembly, <code>.idl</code>, <code>.rc</code>, batch files, and anything '
        'under <code>documentation/</code> or <code>agents/</code> &mdash; are absent from both '
        'lists and from the index:</p>\n'
        + literal_block(
            '# documentation/scripts/generate.py\n'
            "if path.startswith(('documentation/', 'agents/')):\n"
            '    continue'
        ) + '\n'
        f'<p>This run recorded {errors:,} C/C++ files with parse errors and {failed:,} files that '
        'could not be parsed.</p>\n'
    )



def generate(output, paths, revision):
    output.mkdir(parents=True, exist_ok=True)
    # No stale pages on a regeneration. Only remove our own generated HTML.
    for old in output.glob('*.html'):
        old.unlink()
    # Pages used to be Markdown under docs/reference/, where Docusaurus built them.
    # Remove any leftovers so a stale tree is not picked up as docs again.
    legacy = ROOT / 'documentation/site/docs/reference'
    if legacy.is_dir():
        for old in legacy.glob('*.md'):
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
            stats = {'count': 0, 'variants': 0, 'tests': 0, 'first': None}
            def flush():
                nonlocal part, page, stats
                if not page: return
                part += 1
                filename = f'{bucket.lower()}-{part:04d}.html'
                title = f'{bucket} functions · {part}'
                (output / filename).write_text(render_page(title, '\n'.join(page) + '\n' + page_faq(bucket, part, stats)), encoding='utf-8')
                pages.append((title, filename))
                page = []
                stats = {'count': 0, 'variants': 0, 'tests': 0, 'first': None}
            for name, path, line, signature, digest in rows:
                # C++ qualified names are compared by leaf name, so the association is intentionally conservative.
                leaf = name.split('::')[-1]
                variants = variants_for(name)
                tests, test_total = tests_for(leaf)
                test_text = ', '.join(f'<a href="{esc(source_link(p,l,revision))}">test call</a>' for p,l in tests) or 'No matching call found in test-named files.'
                if test_total > len(tests): test_text += f' (showing {len(tests)} of {test_total})'
                difference = (f'{variants[0]} definitions with this exact name; {variants[1]} distinct body hashes. '
                              'Different hashes indicate text differences, not necessarily different behavior.' if variants[0] > 1 else 'No other extracted definition with this exact name.')
                stats['count'] += 1
                if stats['first'] is None: stats['first'] = (name, path, line, signature)
                if variants[0] > 1: stats['variants'] += 1
                if tests: stats['tests'] += 1
                page.append(
                    f'<h2>{inline(name)}</h2>\n<ul>\n'
                    f'<li>Source: <a href="{esc(source_link(path,line,revision))}">{inline(path)}:{line}</a></li>\n'
                    f'<li>Signature: {inline(signature)}</li>\n'
                    '<li>Implementation: inspect the linked definition and body; this index does not infer runtime behavior.</li>\n'
                    f'<li>Variants: {esc(difference)}</li>\n'
                    f'<li>Test evidence: {test_text}</li>\n</ul>\n'
                )
                if len(page) >= 300: flush()
            flush()
        summary = (f'<p>Source revision: {inline(revision)}. Scanned {scanned:,} supported files; '
                   f'found {total:,} definitions and {calls_count:,} syntactic calls in test-named files. '
                   f'{len(errors):,} C/C++ files had parse errors; {len(failed):,} files could not be parsed. '
                   f'See the <a href="coverage.html">coverage report</a>.</p>\n'
                   '<p>This is a syntactic inventory, not proof of behavior or coverage. Test matches are by '
                   'unqualified name, may be unrelated, and do not show execution or assertions. '
                   'Definitions can be missed by macros, conditional compilation, parser errors, or unsupported '
                   'languages. Body hashes compare text, not semantics. Follow source links to understand '
                   'control flow, configuration and actual test assertions.</p>\n'
                   '<h2>Browse</h2>\n<ul>\n' + ''.join(f'<li><a href="{esc(filename)}">{esc(title)}</a></li>\n' for title, filename in pages) + '</ul>\n' +
                   index_faq(scanned, total, calls_count, len(errors), len(failed), len(pages), revision))
        (output / 'index.html').write_text(render_page('Generated function index', summary), encoding='utf-8')
        report = ('<p>C/C++ parse errors may still yield partial results. Python syntax errors yield no '
                  'results. Headers are parsed as C++. Only C, C++ and Python definitions are indexed; '
                  'assembly, scripts and other languages are not. Preprocessing, generated code, '
                  'declarations without bodies and dynamic calls are not resolved. The documentation and '
                  'agent directories are excluded to prevent self-indexing. Test files are identified by '
                  'test-related path segments, not execution metadata.</p>\n')
        report += '<h2>C/C++ files with parse errors</h2>\n<ul>\n' + (''.join(f'<li><a href="{esc(REPO)}/blob/{quote(revision, safe="")}/{quote(p, safe="/")}">{inline(p)}</a></li>\n' for p in errors) or '<li>None.</li>\n') + '</ul>\n'
        report += '<h2>Files that could not be parsed</h2>\n<ul>\n' + (''.join(f'<li>{inline(p)}: {inline(e)}</li>\n' for p,e in failed) or '<li>None.</li>\n') + '</ul>\n'
        report += coverage_faq(len(errors), len(failed))
        (output / 'coverage.html').write_text(render_page('Extraction coverage', report), encoding='utf-8')
        print(f'Scanned {scanned} files, {total} definitions, {calls_count} test calls, {len(errors)} partial parses, {len(failed)} failures; wrote {len(pages)} pages.')


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--output', type=Path, default=ROOT / 'documentation/site/static/reference')
    parser.add_argument('--revision', default=os.environ.get('GITHUB_SHA'))
    parser.add_argument('--prefix', action='append', help='Limit to tracked paths with this prefix (repeatable; useful for development).')
    args = parser.parse_args()
    revision = args.revision or subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=ROOT, text=True).strip()
    paths = tracked_files()
    if args.prefix: paths = [p for p in paths if any(p.startswith(x) for x in args.prefix)]
    generate(args.output, paths, revision)

if __name__ == '__main__':
    main()
