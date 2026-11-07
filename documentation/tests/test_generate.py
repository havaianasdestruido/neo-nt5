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

    def test_generation_cleans_stale_pages(self):
        with tempfile.TemporaryDirectory() as temp:
            out = Path(temp)
            (out / 'stale.md').write_text('stale')
            g.generate(out, [], 'abc')
            self.assertFalse((out / 'stale.md').exists())
            self.assertIn('0 definitions', (out / 'index.md').read_text())

if __name__ == '__main__':
    unittest.main()
