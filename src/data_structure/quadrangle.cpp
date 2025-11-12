struct QUADRANGLE {
  struct TUPLE {
    int l, r, id;
    TUPLE() {}
    TUPLE(int _l, int _r, int _id) : l(_l), r(_r), id(_id) {}
  };
  int n, now;
  deque<TUPLE> dq;

  int calc_dp(int id, int i) {
    // ...
  }
  bool cmp(int cid, int pid, int i) {
    // ...
  }
  void init(int _n) {
    n = _n;
    now = 1;
    dq.clear();
  }
  void kill_head() {
    now++;
    if (dq.front().l == dq.front().r) dq.pop_front();
    else dq.front().l++;
  }
  void push(int id) {
    while (dq.size()) {
      TUPLE tl = dq.back();
      dq.pop_back();
      if (cmp(id, tl.id, tl.l)) {
        continue;
      }
      int l = tl.l, r = tl.r + 1;
      while (l + 1 < r) {
        int mid = (l + r) >> 1;
        (cmp(id, tl.id, mid) ? r : l) = mid;
      }
      dq.push_back(TUPLE(tl.l, l, tl.id));
      if (r <= n) dq.push_back(TUPLE(r, n, id));
      return;
    }
    dq.push_back(TUPLE(now, n, id));
  }
  int determine(int id) {
    return calc_dp(dq.front().id, id);
  }
};
