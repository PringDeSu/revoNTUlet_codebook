template <typename T>
struct MANACHER {
  void operator()(T a, int n, int *mn) {
    int l = 0;
    mn[0] = 0;
    for (int i = 1; i < n; i++) {
      mn[i] = (l + mn[l] >= i ? min(mn[2 * l - i], l + mn[l] - i) : 0);
      while (i - mn[i] - 1 >= 0 && i + mn[i] + 1 < n && a[i - mn[i] - 1] == a[i + mn[i] + 1]) mn[i]++;
      if (i + mn[i] > l + mn[l]) l = i;
    }
  }
};
