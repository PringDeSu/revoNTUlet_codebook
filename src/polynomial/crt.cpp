using lll = __int128_t;

template <lll p1, lll p2, lll p3>
struct ICRT {
  lll c1, c2, c3;
  static lll pow(lll a, lll b, lll mod) {
    lll c = 1;
    for (; b; b >>= 1) {
      if (b & 1) c = c * a % mod;
      a = a * a % mod;
    }
    return c;
  }
  ICRT() :
    c1(pow(p2 * p3 % p1, p1 - 2, p1) * p2 * p3),
    c2(pow(p3 * p1 % p2, p2 - 2, p2) * p3 * p1),
    c3(pow(p1 * p2 % p3, p3 - 2, p3) * p1 * p2)
  {}
  lll operator()(int r1, int r2, int r3) {
    return (c1 * r1 + c2 * r2 + c3 * r3) % (p1 * p2 * p3);
  }
};
