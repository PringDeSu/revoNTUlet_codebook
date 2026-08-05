template <int mod, int g>
struct FPS : vector<int> {
  using M = mint<mod>;
  inline const static NTT<mod, g> ntt;
  static int ub(int d) { return 2 << max(0, __lg(d)); }
  int deg;
  int dd() const { // detectDeg
    auto it = find_if(rbegin(), rend(), [](int x) {
      return x != 0;
    }).base();
    return (it == begin() ? 0 : it - begin() - 1);
  }
  FPS &sd(int d) { // setDeg
    int u = ub(d); resize(u); deg = d;
    fill(data() + d + 1, data() + u, 0);
    return *this;
  }
  FPS &shrink() { return sd(dd()); }
  bool t0() const { return dd() == 0 && at(0) == 0; }
  FPS(int d = 0): vector<int>(ub(d)), deg(d) {}
  FPS(initializer_list<int> it): vector<int>(it) {
    sd(dd());
  }
  static FPS mul(FPS a, FPS b, int d = -1) { // d = 1e6, 192ms
    if (d == -1) d = a.deg + b.deg + 1;
    int u = ub(min(d, a.deg) + min(d, b.deg));
    a.sd(d - 1); a.resize(u); ntt(a.data(), u);
    b.sd(d - 1); b.resize(u); ntt(b.data(), u);
    FOR(i, 0, u) a[i] = M::mul(a[i], b[i]);
    ntt(a.data(), u, true);
    return a.sd(d - 1);
  }
};
