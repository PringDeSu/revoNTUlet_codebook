struct Dinic { // 0-indexed
  // watch out for e.f overflow
  struct E { int v, c, f; };
  vector<vector<int>> g;
  vector<int> p, d;
  vector<E> e;
  queue<int> q;
  void init(int n) {
    g.resize(n);
    p.resize(n);
    d.resize(n);
  }
  void ae(int u, int v, int cu, int cv = 0) {
    g[u].push_back(e.size());
    e.push_back(E{v, cu, 0});
    g[v].push_back(e.size());
    e.push_back(E{u, cv, 0});
  }
  bool bfs(int s, int t, int l) {
    fill(d.begin(), d.end(), -1);
    d[s] = 0;
    q.push(s);
    while (q.size()) {
      int u = q.front();
      q.pop();
      for (auto &ei : g[u]) {
        if (!((e[ei].c-e[ei].f) >> (30-l))) continue;
        int v = e[ei].v;
        if (d[v] == -1) {
          d[v] = d[u] + 1;
          q.push(v);
        }
      }
    }
    return d[t] != -1;
  }
  int dfs(int u, int t, int fl) {
    if (u == t) return fl;
    for (int &i = p[u]; i < g[u].size(); i++) {
      int ei = g[u][i];
      if (e[ei].f == e[ei].c || d[e[ei].v] != d[u] + 1) continue;
      if (int re = dfs(e[ei].v, t, min(fl, e[ei].c - e[ei].f))) {
        e[ei].f += re;
        e[ei ^ 1].f -= re;
        return re;
      }
    }
    return 0;
  }
  int flow(int s, int t) {
    int ans = 0;
    for (int l = 0; l < 31; l++) {
      while (bfs(s, t, l)) {
        fill(p.begin(), p.end(), 0);
        while (auto re = dfs(s, t, INT_MAX)) ans += re;
      }
    }
    return ans;
  }
  bool inscut(int k) {
    return d[k] != -1;
  }
};
