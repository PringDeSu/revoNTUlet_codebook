using cd = complex<double>;
struct PolyF : public vector<cd> {
  static constexpr double PI = 3.14159265358979323;
  PolyF() : vector<cd>() {}
  PolyF(size_t sz) : vector<cd>(sz) {}
  void conv(size_t N, bool inv = 0) {
    assert(size() && N >= size());
    int LG = __lg(N);
    assert(N == (1 << LG));
    resize(N);
    vector<int> r(N);
    FOR(i, 1, N) {
      int i_ = i ^ (1 << __lg(i));
      r[i] = r[i_] << (__lg(i) - __lg(i_)) | 1;
      int j = r[i] << (LG - 1 - __lg(i));
      if (i < j) {
        std::swap(at(i), at(j));
      }
    }
    for (int w = 1; w < N; w <<= 1) {
      FOR(ok, 0, w) {
        double th = PI * ok / w * (inv ? -1 : 1);
        cd o(cos(th), sin(th));
        for (int s = 0; s < N; s += (w << 1)) {
          cd &L = at(s + ok), &R = at(s + ok + w);
          cd l = L, r = o * R;
          L = l + r;
          R = l - r;
        }
      }
    }
    if (inv) {
      FOR(i, 0, N) {
        at(i) /= N;
      }
    }
  }
};
