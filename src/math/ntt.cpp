template <int mod>
struct mint {
    static int add(int a, int b) { return ((a += b) >= mod ? a - mod : a); }
    static int mul(int a, int b) { return (ll) a * b % mod; }
    static int pow(int a, int b) {
        int c = 1;
        for (; b; b >>= 1) {
            if (b & 1) c = mul(c, a);
            a = mul(a, a);
        }
        return c;
    }
};

template <int mod, int g>
struct NTT {
    const static int LYR = 20;
    using M = mint<mod>;
    int o[1 << LYR];
    NTT() {
        int m = M::pow(g, (mod - 1) >> LYR);
        for (int s = 1 << (LYR - 1); s; s >>= 1, m = M::mul(m, m)) {
            o[s] = 1;
            FOR(i, 1, s) o[s + i] = M::mul(o[s + i - 1], m);
        }
    }
    void operator()(int *a, int N, bool inv = false) const {
        for (int i = 0, j = 1; j < N - 1; j++) {
            for (int k = N >> 1; (i ^= k) < k; k >>= 1);
            if (j < i) swap(a[i], a[j]);
        }
        for (int w = 1; w < N; w <<= 1) {
            int h = w << 1;
            for (int s = 0; s < N; s += h) {
                FOR(t, 0, w) {
                    int u = M::mul(a[s + t + w], o[w + t]);
                    a[s + t + w] = M::add(a[s + t], mod - u);
                    a[s + t] = M::add(a[s + t], u);
                }
            }
        }
        if (inv) {
            int u = M::pow(N, mod - 2);
            reverse(a + 1, a + N);
            FOR(i, 0, N) a[i] = M::mul(a[i], u);
        }
    }
    void operator()(vector<int> &a, int N, bool inv = false) const { operator()(a.data(), N, inv); }
};
