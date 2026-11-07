import React from 'react';
import Layout from '@theme/Layout';
import Link from '@docusaurus/Link';
export default function Home() { return <Layout title="Home"><main className="container margin-vert--xl"><h1>NEONT 5 documentation</h1><p>Explore the source tree, build environment, and generated function inventory.</p><p><Link className="button button--primary" to="/docs/intro">Read the guide</Link>{' '}<Link className="button button--secondary" to="/reference">Browse the function reference</Link></p></main></Layout>; }
