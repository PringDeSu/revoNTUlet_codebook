int SA[MXN * 2], H[MXN], RA[MXN];
namespace SAIS {
  bool _t[MXN * 2];
  int _s[MXN * 2], _c[MXN * 2], x[MXN], _p[MXN], _q[MXN * 2];
  void pre(int *sa, int *c, int n, int z) {
    fill_n(sa, n, 0);
    copy_n(c, z, x);
  }
  void induce(int *sa, int *c, int *s, bool *t, int n, int z) {
    copy_n(c, z - 1, x + 1);
    FOR(i, 0, n) {
      if (sa[i] && !t[sa[i] - 1]) {
        sa[x[s[sa[i] - 1]]++] = sa[i] - 1;
      }
    }
    copy_n(c, z, x);
    for (int i = n - 1; i >= 0; i--) {
      if (sa[i] && t[sa[i] - 1]) {
        sa[--x[s[sa[i] - 1]]] = sa[i] - 1;
      }
    }
  }
  void sais(int *s, int *sa, int *p, int *q, bool *t, int *c, int n, int z) {
    bool uniq = t[n - 1] = true;
    int nn = 0, nmxz = -1, *nsa = sa + n, *ns = s + n, last = -1;
    fill_n(c, z, 0);
    FOR(i, 0, n) uniq &= ++c[s[i]] < 2;
    partial_sum(c, c + z, c);
    if (uniq) {
      FOR(i, 0, n) sa[--c[s[i]]] = i;
      return;
    }
    for (int i = n - 2; i >= 0; i--) {
      t[i] = (s[i] == s[i + 1] ? t[i + 1] : s[i] < s[i + 1]);
    }
    pre(sa, c, n, z);
    FOR(i, 1, n) {
      if (t[i] && !t[i - 1]) {
        sa[--x[s[i]]] = p[q[i] = nn++] = i;
      }
    }
    induce(sa, c, s, t, n, z);
    FOR(i, 0, n) {
      if (sa[i] && t[sa[i]] && !t[sa[i] - 1]) {
        bool neq = last < 0 || !equal(s + sa[i], s + p[q[sa[i]] + 1], s + last);
        ns[q[last = sa[i]]] = nmxz += neq;
      }
    }
    sais(ns, nsa, p + nn, q + n, t + n, c + z, nn, nmxz + 1);
    pre(sa, c, n, z);
    for (int i = nn - 1; i >= 0; i--) {
      sa[--x[s[p[nsa[i]]]]] = p[nsa[i]];
    }
    induce(sa, c, s, t, n, z);
  }
  void mkhei(int n) {
    for (int i = 0, j = 0; i < n; i++) {
      if (RA[i]) {
        for (; i + j < n && SA[RA[i] - 1] + j < n && _s[i + j] == _s[SA[RA[i] - 1] + j]; ++j);
        H[RA[i]] = j, j = max(0, j - 1);
      }
    }
  }
  void build(int *s, int n, int mxc) {
    copy_n(s, n, _s), _s[n] = 0;
    sais(_s, SA, _p, _q, _t, _c, n + 1, mxc);
    copy_n(SA + 1, n, SA);
    FOR(i, 0, n) RA[SA[i]] = i;
    mkhei(n);
    copy(H + 1, H + n, H);
  }
}
