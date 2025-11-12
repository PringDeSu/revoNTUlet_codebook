//     AND       OR        XOR
//  | 1  1 |  | 1  0 |  | 1  1 |
//  | 0  1 |  | 1  1 |  | 1 -1 |

struct FWT {
  // mod operations ADD, SUB, MUL, POW (if needed)
  void btf(int &L, int &R, bool inv) { // sample: XOR
    int l = L, r = R;
    L = ADD(l, r);
    R = SUB(l, r);
  }
  void operator()(int *a, int n, bool inv) {
    // sample: XOR
    for (int w = 1; w < n; w <<= 1) {
      FOR(i, 0, n) if (i & w) {
        btf(a[i - w], a[i], inv);
      }
    }
    if (inv) {
      int x = POW(n, mod - 2);
      FOR(i, 0, n) a[i] = MUL(a[i], x);
    }
  }
};
