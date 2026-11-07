import importlib.util
import json
import tempfile
import unittest
from pathlib import Path

spec = importlib.util.spec_from_file_location('generate_docs', Path(__file__).resolve().parents[1] / 'scripts/generate_docs.py')
generator = importlib.util.module_from_spec(spec)
spec.loader.exec_module(generator)


class InventoryTests(unittest.TestCase):
    def test_definitions_tests_and_variants_are_refreshed(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            for name, content in {'core/a.c': 'int add(int x) { return x + 1; }\n', 'other/b.c': 'int add(int x) { return x + 2; }\n', 'tests/test_add.c': 'void check(void) { add(1); }\n'}.items():
                path = root / name
                path.parent.mkdir(parents=True, exist_ok=True)
                path.write_text(content)
            output = root / 'out'
            paths = ['core/a.c', 'other/b.c', 'tests/test_add.c']
            generator.generate(root, output, paths)
            manifest = json.loads((output / 'manifest.json').read_text())
            self.assertEqual(manifest['stats']['functions'], 3)
            core = next(c for c in manifest['components'] if c['name'] == 'core')
            entry = json.loads((output / core['shards'][0]['file']).read_text())[0]
            self.assertEqual(entry['name'], 'add')
            self.assertEqual(entry['tests'], [['tests/test_add.c', 1]])
            self.assertEqual(len(entry['variants']), 2)
            self.assertNotEqual(entry['variants'][0][2], entry['variants'][1][2])
            # Deleted files and shards cannot remain in the next generated output.
            generator.generate(root, output, ['core/a.c'])
            manifest = json.loads((output / 'manifest.json').read_text())
            self.assertEqual(manifest['stats']['functions'], 1)
            entry = json.loads((output / manifest['components'][0]['shards'][0]['file']).read_text())[0]
            self.assertEqual(entry['tests'], [])
            self.assertEqual(len(entry['variants']), 1)

    def test_python_and_cpp_definitions(self):
        parser = generator.get_parser('cpp')
        data = b'int Widget::method(int x) { if (x) return x; return 0; }'
        node = next(n for n in generator.walk(parser.parse(data).root_node) if n.type == 'function_definition')
        self.assertEqual(generator.function_name(node, data), 'Widget::method')
        parser = generator.get_parser('python')
        data = b'def sample(x):\n    return helper(x)\n'
        node = next(n for n in generator.walk(parser.parse(data).root_node) if n.type == 'function_definition')
        self.assertEqual(generator.function_name(node, data), 'sample')
        self.assertIn('helper', [generator.call_name(n, data) for n in generator.walk(node) if n.type in generator.CALLS])


if __name__ == '__main__':
    unittest.main()
