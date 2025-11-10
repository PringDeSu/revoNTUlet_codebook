ll floor_sum(ll a, ll b, ll c, ll n) {
    // floor((a * x + b) / c) for x in [0, n]
    if (n < 0) return 0;
    if (a == 0) return b / c * (n + 1);
    if (a >= c || b >= c) return (n * (n + 1) / 2 * (a / c) + (b / c) * (n + 1)) + floor_sum(a % c, b % c, c, n);
    int m = (a * n + b) / c;
    return m * n - floor_sum(c, c - b - 1, a, m - 1);
}
