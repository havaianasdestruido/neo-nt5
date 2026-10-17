## 2024-10-17 - Decorative Icon Alt Attributes in Legacy HTML
**Learning:** Default unhelpful image alt text (such as `alt="search.gif (114 bytes)"`) or missing `alt` attributes on inline icons adjacent to text links cause screen readers to announce repetitive or distracting file info instead of the actual link label.
**Action:** Always set `alt=""` on decorative icons embedded inside or beside link anchors so screen readers cleanly announce only the descriptive text label.
