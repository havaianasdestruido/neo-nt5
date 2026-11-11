import importlib.util
from pathlib import Path
import tempfile
import unittest

from tree_sitter import Language, Parser
import tree_sitter_c

spec = importlib.util.spec_from_file_location('generate', Path(__file__).parents[1] / 'scripts/generate.py')
g = importlib.util.module_from_spec(spec)
spec.loader.exec_module(g)

class GeneratorTests(unittest.TestCase):
    def test_c_definitions_and_calls(self):
        parser = Parser(Language(tree_sitter_c.language()))
        defs, calls, error = g.parse_c(b'int foo(int x) { return x + 1; }\nvoid test_it(void) { foo(1); }', parser, True)
        self.assertFalse(error)
        self.assertEqual([d[0] for d in defs], ['foo', 'test_it'])
        self.assertEqual(calls, [('foo', 2)])
        self.assertIn('int foo(int x)', defs[0][2])

    def test_python_functions_and_calls(self):
        defs, calls, _ = g.parse_python(b'def foo(x):\n return x\ndef test_foo():\n foo(1)\n', True)
        self.assertEqual([d[0] for d in defs], ['foo', 'test_foo'])
        self.assertEqual(calls, [('foo', 4)])

    def test_hash_changes_with_body(self):
        a = g.parse_python(b'def f():\n return 1\n', False)[0][0][3]
        b = g.parse_python(b'def f():\n return 2\n', False)[0][0][3]
        self.assertNotEqual(a, b)

    def test_test_path_detection(self):
        self.assertTrue(g.is_test('base/tests/test_foo.cpp'))
        self.assertTrue(g.is_test('base/foo_test.py'))
        self.assertFalse(g.is_test('base/latest/foo.cpp'))

    def test_generation_writes_test_evidence(self):
        # A definition may have zero calls, one call, or many calls in test files.
        # Each case must render a page rather than fail tuple unpacking.
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp) / 'repo'
            for sub in ('src', 'tests'):
                (root / sub).mkdir(parents=True)
            (root / 'src' / 'foo.c').write_text('int foo(int x) { return x; }\nint bar(void) { return 0; }\n')
            (root / 'tests' / 'test_foo.c').write_text('void test(void) { foo(1); foo(2); }\n')
            out = Path(temp) / 'out'
            original_root = g.ROOT
            g.ROOT = root
            try:
                g.generate(out, ['src/foo.c', 'tests/test_foo.c'], 'abc')
            finally:
                g.ROOT = original_root
            text = ''.join(p.read_text() for p in sorted(out.glob('*.md')))
            self.assertIn('Test evidence', text)
            self.assertEqual(text.count('[test call]'), 2)  # both calls to foo
            self.assertIn('No matching call found', text)  # bar is never called

    def test_generation_cleans_stale_pages(self):
        with tempfile.TemporaryDirectory() as temp:
            out = Path(temp)
            (out / 'stale.md').write_text('stale')
            g.generate(out, [], 'abc')
            self.assertFalse((out / 'stale.md').exists())
            self.assertIn('0 definitions', (out / 'index.md').read_text())

    def test_every_page_carries_a_faq(self):
        # The FAQ must be on the index, the coverage report and every bucket page,
        # not only on the hand-written guide pages.
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp) / 'repo'
            for sub in ('src', 'tests'):
                (root / sub).mkdir(parents=True)
            (root / 'src' / 'foo.c').write_text('int foo(int x) { return x; }\nint bar(void) { return 0; }\n')
            (root / 'tests' / 'test_foo.c').write_text('void test(void) { foo(1); }\n')
            out = Path(temp) / 'out'
            original_root = g.ROOT
            g.ROOT = root
            try:
                g.generate(out, ['src/foo.c', 'tests/test_foo.c'], 'abc')
            finally:
                g.ROOT = original_root
            written = sorted(out.glob('*.md'))
            self.assertTrue(written)
            for page in written:
                self.assertIn('## Frequently asked questions', page.read_text(), page.name)

    def test_page_faq_is_built_from_that_page(self):
        # Counts and the quoted signature must come from the page's own data.
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp) / 'repo'
            (root / 'src').mkdir(parents=True)
            (root / 'src' / 'foo.c').write_text('int alpha(int x) { return x; }\nint beta(void) { return 0; }\n')
            out = Path(temp) / 'out'
            original_root = g.ROOT
            g.ROOT = root
            try:
                g.generate(out, ['src/foo.c'], 'abc')
            finally:
                g.ROOT = original_root
            text = (out / 'src-0001.md').read_text()
            self.assertIn('lists 2 definitions', text)
            self.assertIn('int alpha(int x)', text)
            self.assertIn('2 of the 2 entries on this page are in that state', text)

    def test_faq_snippet_cannot_break_the_code_fence(self):
        # A backtick in a captured signature must not terminate the fenced block early.
        block = g.code_block('int a`b(int x)')
        self.assertEqual(block.count('```'), 2)
        self.assertNotIn('`b', block)


if __name__ == '__main__':
    unittest.main()
