// please don't use with other geometry templates
#define iter(v) v.begin(), v.end()
#define SZ(v) int(v.size())
#define pb emplace_back
#define ff first
#define ss second

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template<class A, class B>
ostream &operator<<(ostream &o, pair<A, B> p) {
    return o << '(' << p.ff << ',' << p.ss << ')';
}

#define temp template<class T>
#define ptt pair<T, T>
#define X ff
#define Y ss
using ld = long double;
using pdd = pair<ld, ld>;

temp ptt operator+(ptt a, ptt b) {
    return {a.X + b.X, a.Y + b.Y};
}
temp ptt operator-(ptt a, ptt b) {
    return {a.X - b.X, a.Y - b.Y};
}
temp ptt operator*(ptt v, T i) {
    return {v.X * i, v.Y * i};
}
temp ptt operator*(T i, ptt v) {
    return {v.X * i, v.Y * i};
}
temp ptt operator/(ptt v, T i) {
    return {v.X / i, v.Y / i};
}
temp T dot(ptt a, ptt b) {
    return a.X * b.X + a.Y * b.Y;
}
temp T cross(ptt a, ptt b) {
    return a.X * b.Y - a.Y * b.X;
}
temp T abs2(ptt a) {
    return dot(a, a);
}
temp ld abs(ptt a) {
    return sqrt(abs2(a));
}
temp int sgn(T v) {
    return v > 0 ? 1 : (v < 0 ? -1 : 0);
}
temp int ori(ptt a, ptt b, ptt c) {
    return sgn(cross(b - a, c - a));
}
// intersects Line(p1, p2), Line(p3, p4)
pdd intersect(pdd p1, pdd p2, pdd p3, pdd p4) {
    ld a123 = cross(p2 - p1, p3 - p1);
    ld a124 = cross(p2 - p1, p4 - p1);
    return (p4 * a123 - p3 * a124) / (a123 - a124);
}

int cmp(pll a, pll b, bool same = true) {
#define is_neg(k) (sgn(k.Y) < 0 || (sgn(k.Y) == 0 && sgn(k.X) < 0))
    int A = is_neg(a), B = is_neg(b);
    if (A != B) return A < B;
    if (sgn(cross(a, b)) == 0) return same ? abs2(a) < abs2(b) : -1;
    return sgn(cross(a, b)) > 0;
}

using Line = pair<pll, pll>;
// cross(p - line.X, line.Y-line.X) <= 0 <-> p in half plane
// LHS when going from line.X to line.Y

pll area_pair(Line a, Line b) {
    return pll(cross(a.Y - a.X, b.X - a.X), cross(a.Y - a.X, b.Y - a.X));
}
bool isin(Line l0, Line l1, Line l2) {
    auto [a02X, a02Y] = area_pair(l0, l2);
    auto [a12X, a12Y] = area_pair(l1, l2);
    if (a12X - a12Y < 0) a12X *= -1, a12Y *= -1;
    return (__int128) a02Y * a12X - (__int128) a02X * a12Y > 0;
}
vector<Line> HalfPlaneInter(vector<Line> arr) {
    sort(iter(arr), [&](Line a, Line b) -> int {
            if (cmp(a.Y - a.X, b.Y - b.X, 0) != -1)
            return cmp(a.Y - a.X, b.Y - b.X, 0);
            return ori(a.X, a.Y, b.Y) < 0;
            });
    deque<Line> dq(1, arr[0]);
    for (auto p : arr) {
        if (cmp(dq.back().Y - dq.back().X, p.Y - p.X, 0) == -1)
            continue;
        while (SZ(dq) >= 2 && !isin(p, dq[SZ(dq) - 2], dq.back()))
            dq.pop_back();
        while (SZ(dq) >= 2 && !isin(p, dq[0], dq[1]))
            dq.pop_front();
        dq.pb(p);
    }
    while (SZ(dq) >= 3 && !isin(dq[0], dq[SZ(dq) - 2], dq.back()))
        dq.pop_back();
    while (SZ(dq) >= 3 && !isin(dq.back(), dq[0], dq[1]))
        dq.pop_front();
    return vector<Line>(iter(dq));
}

