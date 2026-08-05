// FPS section 3
static FPS deri(FPS a) {
  a.shrink();
  if (a.deg == 0) return FPS({0});
  FOR(i, 0, a.deg) a[i] = M::mul(a[i + 1], i + 1);
  return a.sd(a.deg - 1);
}
static FPS intr(FPS a) {
  a.sd(a.deg + 1);
  for (int i = a.deg; i; i--) {
    a[i] = M::mul(a[i - 1], M::pow(i, mod - 2));
  }
  a[0] = 0;
  return a;
}
static FPS ln(FPS a, int d) { // d = 5e5, 610ms
  return intr(mul(deri(a), inv(a, d - 1), d - 1));
}
static FPS exp(FPS a, int d) { // d = 5e5, 1220ms
  int e = 1;
  FPS b = {1};
  while (e < d) {
    e <<= 1;
    FPS c = ln(b, e);
    FOR(i, 0, e) {
      c[i] = M::add(i <= a.deg ? a[i] : 0, mod - c[i]);
    }
    c[0] = M::add(c[0], 1);
    b = mul(b, c, e);
  }
  return b.sd(d - 1);
}
