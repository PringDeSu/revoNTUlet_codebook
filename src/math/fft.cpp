struct FFT {
  inline const static double PI = 3.14159265358979323;
  void operator()(cd *a, int N, bool inv = false) const {
    for (int i = 0, j = 1; j < N - 1; j++) {
      for (int k = N >> 1; (i ^= k) < k; k >>= 1);
      if (j < i) swap(a[i], a[j]);
    }
    for (int w = 1; w < N; w <<= 1) {
      int h = w << 1;
      FOR(t, 0, w) {
        double th = PI * t / w;
        cd o(cos(th), sin(th));
        for (int s = 0; s < N; s += h) {
          cd u = a[s + t + w] * o;
          a[s + t + w] = a[s + t] - u;
          a[s + t] += u;
        }
      }
    }
    if (inv) {
      reverse(a + 1, a + N);
      FOR(i, 0, N) a[i] /= N;
    }
  }
} fft;
// round(a[i].real())
