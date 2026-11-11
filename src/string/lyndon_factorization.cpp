// starting position of each substring
vector<int> lyndon(string &s) {
  int n = s.size();
  int i = 0;
  vector<int> ans;
  while (i < n) {
    int j = i + 1, k = i;
    while (j < n && s[k] <= s[j]) {
      if (s[k] < s[j]) k = i;
      else k++;
      j++;
    }
    while (i <= k) {
      ans.push_back(i);
      i += j - k;
    }
  }
  return ans;
}
