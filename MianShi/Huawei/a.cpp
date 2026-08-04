#include <bits/stdc++.h>
using ll = long long;
using namespace std;


int n;
void solve() {
    // cout << n << '\n';

    vector<string> a;

    vector<int> wt(n + 1, 0);
    vector<array<int, 2>> edges(n);
    unordered_map<int, vector<int>> g;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        // cout << s << '\n';
        a.push_back(s);
    }

    int MX = 0;
    for (int i = 0; i < n; i++) {
        string s = a[i];

        int x = 0, y = 0, w = 0;
        int idx1 = -1, idx2 = -1;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == ',') {
                if (idx1 == -1) idx1 = j;
                else idx2 = j;
            }
        }
        // cout << idx1 << ' ' << idx2 << '\n';

        for (int j = 0; j < idx1; j++) {
            x = x * 10 + s[j] - '0';
        }
        for (int j = idx1 + 1; j < idx2; j++) {
            y = y * 10 + s[j] - '0';
        }

        for (int j = idx2 + 1; j < s.size(); j++) {
            w = w * 10 + s[j] - '0';
        }
        // cout << x << ' ' << y << ' ' << w << '\n';
         
        g[x].push_back(y);
        wt[y] = max(wt[y], w);
        MX = max({MX, x, y});
        edges[i][0] = x, edges[i][1] = y;
    }
    
    vector<int> vis(MX + 1, 0);
    auto dfs = [&](auto &&dfs, int x) -> bool {
        vis[x] = 1;

        for (int y : g[x]) {
            if (vis[y]) return false;
            if (!dfs(dfs, y)) return false;
        }

        return true;
    };

    for (int x = 1; x <= n; x++) {
        for (int i = 1; i <= MX; i++) vis[i] = 0;

        if (!dfs(dfs, x)) {
            cout << "false" << '\n';
            return;
        }
    }

    for (auto &[x, y] : edges) {
        cout << x << ',' << y << ',' << wt[y] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n) {
        solve();
    }

    return 0;
}