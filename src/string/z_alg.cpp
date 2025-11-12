template <typename T>
struct Z_alg {
  void operator()(T a, int n, int *z) {
    z[0] = 0;
    int l = 0;
    for (int i = 1; i <= n; i++) {
      for (z[i] = max(0, min(z[i - l], l + z[l] - i)); i + z[i] < n && a[i + z[i]] == a[z[i]]; z[i]++);
      if (i + z[i] > l + z[l]) l = i;
    }
  }
};
