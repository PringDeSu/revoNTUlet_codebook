// only construct the automaton
struct AC {
  const static int c0 = 'a';
  int nc, c[MXN], pi[MXN], p[MXN], ch[MXN][MXC];
  void init() {
    nc = 2;
    fill(ch[0], ch[0] + MXC, 1);
    fill(ch[1], ch[1] + MXC, -1);
  }
  int nn(int pp, char cc) {
    c[nc] = cc;
    p[nc] = pp;
    fill(ch[nc], ch[nc] + MXC, -1);
    return nc++;
  }
  int push(const string &s) {
    int u = 1;
    for (auto &i : s) {
      int e = i - c0;
      if (!~ch[u][e]) ch[u][e] = nn(u, i);
      u = ch[u][e];
    }
    return u;
  }
  void build() {
    queue<int> q;
    q.push(1);
    while (q.size()) {
      int u = q.front();
      q.pop();
      pi[u] = (u == 1 ? 0 : ch[pi[p[u]]][c[u] - c0]);
      FOR(e, 0, MXC) {
        if (!~ch[u][e]) ch[u][e] = ch[pi[u]][e];
        else q.push(ch[u][e]);
      }
    }
  }
};
