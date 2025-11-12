using lll = __int128_t;

struct ICRT {
  lll p1, p2, p3;
  lll c1, c2, c3;
  ICRT() {}
  ICRT(lll _p1, lll _p2, lll _p3) : p1(_p1), p2(_p2), p3(_p3) {
    auto POW = [&](lll a, lll b, lll mod) -> lll {
      lll ans = 1;
      while (b) {
        if (b & 1) ans = ans * a % mod;
        b >>= 1;
        a = a * a % mod;
      }
      return ans;
    };
    c1 = POW(p2 * p3 % p1, p1 - 2, p1) * p2 * p3;
    c2 = POW(p3 * p1 % p2, p2 - 2, p2) * p3 * p1;
    c3 = POW(p1 * p2 % p3, p3 - 2, p3) * p1 * p2;
  }
  lll operator()(int r1, int r2, int r3) {
    return (c1 * r1 + c2 * r2 + c3 * r3) % (p1 * p2 * p3);
  }
};

ICRT icrt(998244353, 104857601, 167772161);
