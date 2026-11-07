// The repository Pages site lives beneath /neo-nt5/ by default.
const baseUrl = process.env.DOCS_BASE_URL || '/neo-nt5/';
module.exports = {
  title: 'NEONT 5 Documentation', tagline: 'A source-linked guide to the tree',
  url: 'https://havaianasdestruido.github.io', baseUrl,
  organizationName: 'havaianasdestruido', projectName: 'neo-nt5',
  onBrokenLinks: 'throw', onBrokenMarkdownLinks: 'warn',
  presets: [['classic', {docs: {sidebarPath: require.resolve('./sidebars.js')}, blog: false, theme: {customCss: require.resolve('./src/css/custom.css')}}]],
  themeConfig: {navbar: {title: 'NEONT 5', items: [{to: '/docs/intro', label: 'Guide', position: 'left'}, {to: '/reference', label: 'Function reference', position: 'left'}, {href: 'https://github.com/havaianasdestruido/neo-nt5', label: 'GitHub', position: 'right'}]}, footer: {style: 'dark', copyright: 'NEONT 5 source documentation'}}
};
