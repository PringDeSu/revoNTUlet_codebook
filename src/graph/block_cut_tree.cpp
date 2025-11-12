// [0, n): round points, [n, tr.size()): square points
// take care of cases when n=1
struct BlockCutTree { // 0 based
  vector<vector<int>> paths, tr;
  vector<int> idx, low, stk;
  int gid, dfn;
  int n;
  BlockCutTree(int _n) {
    n = _n;
    paths = tr = vector<vector<int>>(n);
    gid = 0;
    idx = low = vector<int>(n, -1);
    stk.clear();
  }
  void add_edge(int a, int b) {
    paths[a].push_back(b);
    paths[b].push_back(a);
  }
  void dfs(int now) {
    idx[now] = low[now] = ++dfn;
    stk.push_back(now);
    for(auto nxt:paths[now]) {
      if (idx[nxt] == -1) {
        dfs(nxt);
        low[now] = min(low[now], low[nxt]);
        if (low[nxt] == idx[now]) {
          tr.push_back({});
          int t = -1;
          do {
            t = stk.back();
            stk.pop_back();
            tr[gid+n].push_back(t);
            tr[t].push_back(gid+n);
          } while(t != nxt);
          tr[now].push_back(gid+n);
          tr[gid+n].push_back(now);
          gid ++;
        }
      }
      else low[now] = min(low[now], idx[nxt]);
    }
    return;
  }
  vector<vector<int>> solve() {
    dfn = 0;
    for(int i = 0;i<n;i++) {
      if (idx[i] == -1) dfs(i);
    }
    return tr;
  }
};
