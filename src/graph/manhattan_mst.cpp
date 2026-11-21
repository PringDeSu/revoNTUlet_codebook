#define x first
#define y second
struct Qt: pii {
	int u;
	auto operator<(const Qt& b) const {
		return x != b.x? x < b.x: u < b.u;
	}
};
ll dist(Qt a, Qt b) { return (ll)abs(a.x - b.x) + abs(a.y - b.y); }
vector<tiii> es;
void solve(Qt *a, int n) {
	sort(a, a + n, [](const Qt &p, const Qt &q) {
			return p.x + p.y < q.x + q.y;
			});
	set<Qt, greater<Qt>> st; // greater<Qt::x>
	for (int i = 0; i < n; ++i) {
		for (auto it = st.lower_bound(a[i]); it != st.end(); it = st.erase(it)) {
			if (it -> x - it -> y < a[i].x - a[i].y) break;
			es.push_back({it -> u, a[i].u, dist(*it, a[i])});
		}
		st.insert(a[i]);
	}
}
vector<tiii> MST(Qt *a, int n) {
	es.clear();
	for (int t = 0; t < 2; ++t) {
		solve(a, n);
		for (int i = 0; i < n; ++i) swap(a[i].x, a[i].y);
		solve(a, n);
		for (int i = 0; i < n; ++i) a[i].x = -a[i].x;
	}
	return es; // only 8n edges left, run kruskral on these edges
}
