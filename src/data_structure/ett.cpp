#define ls ch[x][0]
#define rs ch[x][1]
#define p fa[x]
// 1-index
struct ETT: Splay {
	int n;
	map<int, int> adj[SZ];
	void init(int t_n) {
		n = t_n;
		for (int i = 1; i <= n; i++)
			newnode();
		return;
	}
	int locate(int x) {
		splay(x);
		return sz[ls] + 1;
	}
	void reroot(int u) {
		auto [l, r] = split(u, locate(u));
		merge(r, l);
		return;
	}
	void add_edge(int u, int v) {
		reroot(u); reroot(v);
		int a = newnode(), b = newnode();
		adj[u][v] = a; adj[v][u] = b;
		merge(u, a); merge(u, v); merge(u, b);
		return;
	}
	// subtree only works on existing edges (u, v)
	// splits v when root is u
	tuple<int, int, int> subtree(int u, int v) {
		reroot(u);
		int tl = adj[u][v], tr = adj[v][u];
		int sl = locate(tl), sr = locate(tr);
		split(tr, sr - 1); split(tl, sl);
		return make_tuple(tl, v, tr);
	}
	void del_edge(int u, int v) {
		auto [tl, tm, tr] = subtree(u, v);
		adj[u].erase(v); adj[v].erase(u);
		splay(tl); splay(tr); 
		int sl = sz[tl], sr = sz[tr];
		if (sl != 1) {
			tl = get_sz(tl, 1);
			split(tl, sl - 1);
		}
		else tl = 0;
		if (sr != 1) {
			tr = get_sz(tr, sr);
			split(tr, 1);
		}
		else tr = 0;
		merge(tl, tr);
		return;
	}
};
#undef ls
#undef rs
#undef p
ETT T;
