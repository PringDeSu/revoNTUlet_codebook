int ori(Pt a, Pt b, Pt c) {
    ll tmp = (b-a) ^ (c-a);
    return tmp>0?1:tmp<0?-1:0;
}
 
int cyc_tsearch(int n, auto pred) {
    if (n == 1) return 0;
    int l = 0, r = n; bool rv = pred(1, 0);
    while(r-l > 1) {
        int m = (l+r) / 2;
        if (pred(0, m) ? rv: pred(m, (m+1) % n)) r = m;
        else l = m;
    }
    return pred(l, r % n) ? l : r % n;
}
 
pii get_tangent(const vector<Pt> &cvx, Pt p) {
    auto gao = [&](int s) {
        return cyc_tsearch(cvx.size(), [&](int x, int y)
         { return ori(p, cvx[x], cvx[y]) == s; });
    };
    return pii(gao(1), gao(-1));
}
