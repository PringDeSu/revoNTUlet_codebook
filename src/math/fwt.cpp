void conv(int *a, int N, void (*btf)(int&, int&)) {
  for (int j = 1; j < N; j <<= 1) {
    FOR(i, 0, N) {
      if (i & j) continue;
      btf(a[i], a[i ^ j]);
    }
  }
}
// maybe use mod arithmetic?
void fwtand0(int &L, int &R) { L += R; }
void fwtand1(int &L, int &R) { L -= R; }
void fwtor0(int &L, int &R) { R += L; }
void fwtor1(int &L, int &R) { R -= L; }
void fwtxor(int &L, int &R) { L += R; R = L - 2 * R; }
// xor use the same btf whenever the value inv is
// remember to divide by N after inv when using xor
