// left node always become root for tie-breaker
// default: root is the largest node
template <typename T>
int cart(T *a, int n, pii *e) {
  vector<int> st;
  FOR(i, 0, n) {
    e[i] = {-1, -1};
    while (st.size() && a[st.back()] < a[i]) {
      e[i].fs = st.back();
      st.pop_back();
    }
    if (st.size()) e[st.back()].sc = i;
    st.push_back(i);
  }
  return st[0]; // root
}
