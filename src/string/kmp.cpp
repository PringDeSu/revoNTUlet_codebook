template <typename T>
struct KMP {
  void operator()(T a, int n, int *pi) {
    pi[0] = -1, pi[1] = 0;
    for (int i = 1; i < n; i++) {
      int j = pi[i];
      while (j >= 0 && a[i] != a[j]) j = pi[j];
      pi[i + 1] = j + 1;
    }
  }
};
