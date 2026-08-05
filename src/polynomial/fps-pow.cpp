// FPS section 4
static FPS pow(FPS a, ll k, int d) { // d = 5e5, 1573ms
  a.sd(d - 1);
  if (k == 0) {
    FPS b = FPS(d);
    b[0] = 1;
    return b;
  }
  int *it = find_if(a.data(), a.data() + d, [](int x) {
    return x != 0;
  });
  int c = *it, t = it - a.data();
  if (t == d || t >= ((d - 1) / k + 1)) {
    return FPS(d);
  }
  int dd = d - t * k;
  int kk = k % mod;
  FPS b = FPS(d - t);
  int ci = M::pow(c, mod - 2);
  FOR(i, t, d) {
    b[i - t] = M::mul(a[i], ci);
  }
  b = ln(b, dd);
  FOR(i, 0, dd) b[i] = M::mul(b[i], kk);
  b = exp(b, dd);
  FPS bb = FPS(d);
  c = M::pow(c, k % (mod - 1));
  FOR(i, 0, dd) {
    bb[d - dd + i] = M::mul(b[i], c);
  }
  return bb;
}
