// GitHub Pages serves project sites under /<repository>/.
const repo = process.env.GITHUB_REPOSITORY || 'havaianasdestruido/neo-nt5';
const [organizationName, projectName] = repo.split('/');
module.exports = {
  title: 'NEONT 5 documentation',
  tagline: 'Source, tests and build boundaries',
  url: `https://${organizationName}.github.io`,
  baseUrl: `/${projectName}/`,
  organizationName,
  projectName,
  onBrokenLinks: 'throw',
  onBrokenMarkdownLinks: 'throw',
  presets: [['classic', {docs: {sidebarPath: require.resolve('./sidebars.js'), routeBasePath: '/'}, blog: false, theme: {customCss: require.resolve('./src/css/custom.css')}}]],
  themeConfig: {navbar: {title: 'NEONT 5', items: [{to: '/', label: 'Guide', position: 'left'}, {to: '/reference/', label: 'Function index', position: 'left'}, {href: `https://github.com/${repo}`, label: 'GitHub', position: 'right'}]}, footer: {style: 'dark', copyright: 'NEONT 5 source documentation'}}
};
