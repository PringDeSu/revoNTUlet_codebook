#define pb emplace_back
struct eertree {
    const static int MXC = 26, C0 = 'a';
    struct nd {
        int nxt[MXC], pi, len;
        int cnt, num; // optional
        nd(int l = 0) : pi(0), len(l), cnt(0), num(0) {
            fill(nxt, nxt + MXC, 0);
        }
    };
    vector<nd> v;
    vector<char> s;
    int lst, n;
    eertree() : v(2), lst(1), n(0) {
        v[0].pi = 1, v[1].len = -1, s.pb(-1);
    }
    void clear() {
        v.clear(), s.clear(), lst = 1, n = 0;
        v.pb(0), v.pb(-1);
        v[0].pi = 1, s.pb(-1);
    }
    int get_fail(int x) {
        while (s[n - v[x].len - 1] != s[n])
            x = v[x].pi;
        return x;
    }
    void add(int c) {
        s.push_back(c -= 'a'), ++n;
        int cur = get_fail(lst);
        if (!v[cur].nxt[c]) {
            int now = v.size();
            v.pb(v[cur].len + 2);
            v[now].pi =
                v[get_fail(v[cur].pi)].nxt[c];
            v[cur].nxt[c] = now;
            v[now].num = v[v[now].pi].num + 1;
        }
        lst = v[cur].nxt[c], ++v[lst].cnt;
    }
    void count() {
        for (auto i = v.rbegin(); i != v.rend(); i++) {
            v[i -> pi].cnt += i -> cnt;
        }
    }
    inline int size() {
        return v.size() - 2;
    }
};
