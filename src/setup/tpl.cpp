#include <bits/stdc++.h>
using namespace std;

#ifdef MIKU
string dbmc = "\033[1;38;2;57;197;187m", dbrs = "\033[0m";
#define debug(x...) cerr << dbmc << "#" << __LINE__ << " [" << #x << "]: ", dout(x)
void dout() { cerr << dbrs << endl; }
template <typename T, typename ...U>
void dout(T t, U ...u) { cerr << t << (sizeof...(u) ? ", " : ""); dout(u...); }
#else
#define debug(...) 39
#endif

#define fs first
#define sc second
#define FOR(i, j, k) for (int i = j, Z = k; i < Z; i++)
using ll = long long;
typedef pair<int, int> pii;

void miku() {
    int a, b;
    cin >> a >> b;
    debug(a, b);
    cout << "DECO*" << a * b << '\n';
}

int32_t main() {
    cin.tie(0) -> sync_with_stdio(false);
    cin.exceptions(cin.failbit);
    miku();
    return 0;
}
