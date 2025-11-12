// only construct the automaton
struct AC {
  int nc;
  char c[MXN];
  int pi[MXN], p[MXN], nxt[MXN][MXC];
  void init() {
    nc = 2;
    fill(nxt[0], nxt[0] + MXC, 1);
    fill(nxt[1], nxt[1] + MXC, -1);
  }
  int add_node(int par, char _c) {
    c[nc] = _c;
    p[nc] = par;
    fill(nxt[nc], nxt[nc] + MXC, -1);
    return nc++;
  }
  int push(string &s) {
    int now = 1;
    for (auto &i : s) {
      if (nxt[now][i - 'a'] == -1) nxt[now][i - 'a'] = add_node(now, i);
      now = nxt[now][i - 'a'];
    }
    return now;
  }
  void build() {
    queue<int> q;
    pi[1] = 0;
    FOR(i, 0, MXC) {
      if (nxt[1][i] == -1) nxt[1][i] = nxt[pi[1]][i];
      else q.push(nxt[1][i]);
    }
    while (q.size()) {
      int id = q.front();
      q.pop();
      pi[id] = nxt[pi[p[id]]][c[id] - 'a'];
      FOR(i, 0, MXC) {
        if (nxt[id][i] == -1) nxt[id][i] = nxt[pi[id]][i];
        else q.push(nxt[id][i]);
      }
    }
  }
};
