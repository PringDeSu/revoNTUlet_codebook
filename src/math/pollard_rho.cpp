// needs mad,mub,mul,pw with changable mod
//!!! use int128 for pw and mul

bool isprime(ll x) {
    if (x <= 2 || ~x & 1) return x == 2;
    auto witn = [&](ll a, int t) {
        for (ll a2; t-- && (a2 = mul(a, a, x)); a = a2)
            if (a2 == 1 && a != 1 && a != x - 1) return true;
        return a > 1;
    };
    int t = __builtin_ctzll(x-1); ll odd = (x-1) >> t;
    for (ll m:
            {2, 325, 9375, 28178, 450775, 9780504, 1795265022})
    if (witn(pw(m % x, odd, x), t)) return false;
    return true;
}

ll pollard_rho(ll n) {
    static mt19937_64 rnd(120821011);
    if (!(n & 1)) return 2;
    ll y = 2, z = y, c = rnd() % n, p = 1, i = 0, t;
    auto f = [&](ll x) {
        return mad(mul(x, x, n), c, n); };
    do {
        p = mul(mub(z = f(f(z)), y = f(y), n), p, n);
        if (++i &= 63) if (i == (i & -i)) t = gcd(p, n);
    } while (t == 1);
    return t == n ? pollard_rho(n) : t;
}

vector<ll> factorize(ll k){
    if(k == 1)return {};
    else if(isprime(k))return {k};
    else{
        vector<ll> re;
        function<void(ll)> dc = [&](ll k){
            if(isprime(k)){
                re.push_back(k);
                return;
            }
            ll x = pollard_rho(k);
            dc(x);dc(k/x);
        };
        dc(k);
        sort(re.begin(),re.end());
        return re;
    }
}
