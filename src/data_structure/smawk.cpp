// For all 2x2 submatrix:
// If M[1][0] < M[1][1], M[0][0] < M[0][1]
// If M[1][0] == M[1][1], M[0][0] <= M[0][1]
// M[i][ans_i] is the best value in the i-th row
VI smawk(int N, int M, auto &&select) {
  auto dc = [&](auto self, const VI &r, const VI &c) {
    if (r.empty()) return VI{};
    const int n = (int)r.size(); VI ans(n), nr, nc;
    for (int i : c) {
      while (!nc.empty() &&
          select(r[nc.size() - 1], nc.back(), i))
        nc.pop_back();
      if (int(nc.size()) < n) nc.push_back(i);
    }
    for (int i = 1; i < n; i += 2) nr.push_back(r[i]);
    const auto na = self(self, nr, nc);
    for (int i = 1; i < n; i += 2) ans[i] = na[i >> 1];
    for (int i = 0, j = 0; i < n; i += 2) {
      ans[i] = nc[j];
      const int end = i + 1 == n ? nc.back() : ans[i + 1];
      while (nc[j] != end)
        if (select(r[i], ans[i], nc[++j])) ans[i] = nc[j];
    }
    return ans;
  };
  VI R(N), C(M); iota(all(R), 0), iota(all(C), 0);
  return dc(dc, R, C);
}
bool min_plus_conv_select(int r, int u, int v) {
  auto f = [](int i, int j) {
    if (0 <= i - j && i - j < n) return b[j] + a[i - j];
    return 2100000000 + (i - j);
  };
  return f(r, u) > f(r, v);
} // if f(r, v) is better than f(r, u), return true
