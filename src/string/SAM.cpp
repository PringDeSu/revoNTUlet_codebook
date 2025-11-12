struct SAM {
    static const int MXND = 1000005, MXC = 33, C0 = 'a';
    int tot, rt, lst, pi[MXND], mx[MXND];
    int nxt[MXND][MXC], cnt[MXND], in[MXND];
    int newNode() {
        int res = ++tot;
        fill(nxt[res], nxt[res] + MXC, 0);
        pi[res] = mx[res] = cnt[res] = in[res] = 0;
        return res;
    }
    void init() {
        tot = 0;
        rt = newNode();
        pi[rt] = 0, mx[rt] = 0;
        lst = rt;
    }
    void push(int c) {
        int p = lst;
        int np = newNode();
        mx[np] = mx[p] + 1;
        for (; p && nxt[p][c] == 0; p = pi[p])
            nxt[p][c] = np;
        if (p == 0) pi[np] = rt;
        else {
            int q = nxt[p][c];
            if (mx[p] + 1 == mx[q]) pi[np] = q;
            else {
                int nq = newNode();
                mx[nq] = mx[p] + 1;
                for (int i = 0; i < MXC; i++)
                    nxt[nq][i] = nxt[q][i];
                pi[nq] = pi[q];
                pi[q] = nq;
                pi[np] = nq;
                for (; p && nxt[p][c] == q; p = pi[p])
                    nxt[p][c] = nq;
            }
        }
        lst = np, cnt[np] = 1;
    }
    void push(char *str) {
        for (int i = 0; str[i]; i++)
            push(str[i] - C0 + 1);
    }
    void count() {
        for (int i = 1; i <= tot; ++i)
            ++in[pi[i]];
        queue<int> q;
        for (int i = 1; i <= tot; ++i)
            if (!in[i]) q.push(i);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cnt[pi[u]] += cnt[u];
            if (!--in[pi[u]])
                q.push(pi[u]);
        }
    }
} sam;
