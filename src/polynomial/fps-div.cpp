// FPS section 2
static FPS inv(FPS a, int d) { // d = 5e5, 442ms
  int e = 1;
  FPS b = {M::pow(a[0], mod - 2)};
  while (e < d) {
    e <<= 1;
    FPS c = mul(a, b, e);
    c[0] = M::add(2, mod - c[0]);
    FOR(i, 1, e) c[i] = M::add(0, mod - c[i]);
    b = mul(b, c, e);
  }
  return b.sd(d - 1);
}
FPS &rev() {
  reverse(data(), data() + deg + 1);
  return *this;
}
static pair<FPS, FPS> ldiv(FPS a, FPS b) { // d = 5e5, 463ms
  a.shrink(), b.shrink();
  int n = a.deg, m = b.deg;
  if (n < m) return {FPS({0}), a};
  a.rev(), b.rev();
  FPS q = mul(a, inv(b, n - m + 1), n - m + 1).rev();
  a.rev(), b.rev();
  FPS bq = mul(b, q);
  FOR(i, 0, n + 1) {
    a[i] = M::add(a[i], mod - bq[i]);
  }
  return {q, a.shrink()};
}
