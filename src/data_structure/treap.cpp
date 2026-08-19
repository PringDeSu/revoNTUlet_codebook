#define ll long long
// range reverse range add range sum
// need to push before using the info on node
struct node{
  int pri, pl, pr, sz, rev;
  ll sum, tag, val;
  node() {
    val = pl = pr = sum = tag = rev = 0;
    sz = 1;
    pri = rand();
  }
};

#define ls nd[now].pl
#define rs nd[now].pr
const int SZ = 2e5+10;
struct Treap{
  node nd[SZ];
  int cnt;
  Treap() {
    cnt = 0;
    nd[0].sz = 0;
  }
  int newnode() {
    nd[++cnt] = node();
    return cnt;
  }
  int pull(int now) {
    if (!now) return now;
    nd[now].sz = nd[ls].sz + nd[rs].sz + 1;
    nd[now].sum = nd[now].val + nd[ls].sum + nd[rs].sum;
    nd[now].sum += nd[ls].tag * nd[ls].sz;
    nd[now].sum += nd[rs].tag * nd[rs].sz;
    return now;
  }
  void push(int now) {
    if (!now) return;
    if (nd[now].rev) {
      swap(ls, rs);
      if (ls) nd[ls].rev ^= 1;
      if (rs) nd[rs].rev ^= 1;
      nd[now].rev = 0;
    }
    nd[now].val += nd[now].tag;
    if (ls) nd[ls].tag += nd[now].tag;
    if (rs) nd[rs].tag += nd[now].tag;
    nd[now].tag = 0;
    pull(now);
  }
  int merge(int a,int b) {
    if (!a) return b;
    if (!b) return a;
    push(a); push(b);
    if (nd[a].pri > nd[b].pri) {
      nd[a].pr = merge(nd[a].pr, b);
      return pull(a);
    }
    else{
      nd[b].pl = merge(a, nd[b].pl);
      return pull(b);
    }
  }
  void split(int now, int &a, int &b, int tar) {
    if (!now) {
      return void(a = b = 0);
    }
    push(now);
    if (nd[ls].sz+1<=tar) {
      a = now;
      split(rs, rs, b, tar-(nd[ls].sz + 1));
    }
    else {
      b = now;
      split(ls, a, ls, tar);
    }
    pull(a); pull(b);
    return;
  }
};
#undef ls
#undef rs
Treap T;
