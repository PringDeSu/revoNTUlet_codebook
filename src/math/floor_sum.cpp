ll floor_sum(ll n, ll m, ll a, ll b) {
  // floor((a * x + b) / m) for x in [0, n)
  ll a2 = ((a % m) + m) % m, b2 = ((b % m) + m) % m;
  ll a1 = (a - a2) / m, b1 = (b - b2) / m;
  ll r = a1 * n * (n - 1) / 2 + b1 * n;
  if (a2 == 0) return r + b2 / m * n;
  ll d = (a2 * (n - 1) + b2) / m;
  return r + d * (n - 1) - floor_sum(d, a2, m, m - b2 - 1);
}
