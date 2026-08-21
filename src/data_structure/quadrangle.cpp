// snippets from CSES houses and schools
pd[0] = INF;
deque<P> dq;
dq.push_back(P{1, n + 1, 0});
FOR(i, 1, n + 1) {
  int id = dq.front().id;
  pd[i] = dp[id] + f(id, i);
  if (++dq.front().l == dq.front().r) {
    dq.pop_front();
  }
  while (dq.size()) {
    auto [l, r, id] = dq.back();
    dq.pop_back();
    if (dp[i] + f(i, l) <= dp[id] + f(id, l)) {
      continue;
    }
    int l0 = l;
    r++;
    while (l + 1 < r) {
      int mid = (l + r) >> 1;
      (dp[i] + f(i, mid) <= dp[id] + f(id, mid) ? r : l) = mid;
    }
    dq.push_back(P{l0, min(n + 1, r), id});
    if (r < n + 1) dq.push_back(P{r, n + 1, i});
    break;
  }
  if (dq.empty()) {
    dq.push_back(P{i + 1, n + 1, i});
  }
}
copy(pd, pd + n + 1, dp);
