#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> p(n + 1);
    vector<char> s(n + 1);
    vector<bool> vis(n + 1);
    vector<int> ans(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vector<int> cur;
            int pos = i, num = 0;
            while (!vis[pos]) {
                cur.push_back(pos);
                num += s[pos] == '0';
                vis[pos] = true;
                pos = p[pos];
            }

            for (auto& it : cur) {
                ans[it] = num;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }

    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
