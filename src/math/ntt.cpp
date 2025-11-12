#define FOR(i, j, k) for (int i = j, Z = k; i < Z; i++)

struct NTT {
  const static int LG = 20;
  int mod;
  int o[(1 << LG) + 1];
  int ADD(int a, int b) {
    // help yourself
  }
  int SUB(int a, int b) {
    // help yourself
  }
  int MUL(int a, int b) {
    // help yourself
  }
  int POW(int a, int b) {
    // help yourself
  }
  NTT(int g, int gap, int _mod) {
    mod = _mod;
    o[0] = 1;
    int pp = POW(g, gap);
    FOR(i, 1, (1 << LG) + 1) o[i] = MUL(o[i - 1], pp);
  }
  void operator()(int *a, int n, bool inv) {
    auto REV = [&](int x) -> int {
      int ans = 0;
      for (int w = 1; w < n; w <<= 1) {
        ans = (ans << 1) | (x & 1);
        x >>= 1;
      }
      return ans;
    };
    FOR(i, 0, n) {
      int j = REV(i);
      if (i < j) swap(a[i], a[j]);
    }
    for (int w = 1; w < n; w <<= 1) {
      int owo = 1 << (LG - __lg(w) - 1), oid = 0;
      FOR(i, 0, w) {
        int omega = o[inv ? (1 << LG) - oid : oid];
        for (int s = 0; s < n; s += (w << 1)) {
          int &L = a[s + i], &R = a[s + w + i];
          int l = L, r = MUL(omega, R);
          L = ADD(l, r);
          R = SUB(l, r);
        }
        oid += owo;
      }
    }
    if (inv) {
      int x = POW(n, mod - 2);
      FOR(i, 0, n) a[i] = MUL(a[i], x);
    }
  }
};

NTT ntt1(3, 952, 998244353);
NTT ntt2(3, 100, 104857601);
NTT ntt3(3, 160, 167772161);

namespace POLY {
  const int MXM = 4 * MXN;
  int a[MXM], b[MXM];
  vector<int> VMUL(vector<int> v, vector<int> w, int m) {
    int N = 4 << __lg(m);
    fill(a, a + N, 0);
    fill(b, b + N, 0);
    int na = min((int) v.size(), m), nb = min((int) w.size(), m);
    FOR(i, 0, na) a[i] = v[i];
    FOR(i, 0, nb) b[i] = w[i];
    ntt(a, N, false);
    ntt(b, N, false);
    FOR(i, 0, N) a[i] = MUL(a[i], b[i]);
    ntt(a, N, true);
    vector<int> ans;
    FOR(i, 0, m) ans.push_back(a[i]);
    return ans;
  }
}
