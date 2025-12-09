int main() {
  multiCase() {
    int n; cin >> n;
    auto p = getv(n);
    string s; cin >> s;
    vector<bool> vis(n);
    vector<int> ans(n);
    for (int i = 0; i < n; i ++) if (!vis[i]) {
      vector<int> cur;
      int pos = i, num = 0;
      do {
        cur.push_back(pos);
        num += s[pos] == '0';
        vis[pos] = true;
        pos = p[pos] - 1;
      } while (!vis[pos]);
      for (auto e: cur)
        ans[e] = num;
    }
    write(ans, "%d ", "\n");
  }
  return 0;
}