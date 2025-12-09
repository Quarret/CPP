#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector< vector<int> > g(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }

    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    auto dfs = [&](auto& self, int x, int y) -> int {
        if (!g[x][y]) {
            return 0;
        }

        int rec = g[x][y];
        g[x][y] = 0;
        for (int k = 0; k < 4; k++) {
            int i = x + dx[k], j = y + dy[k];
            if (i > 0 && j > 0 && i <= n && j <= m) {
                rec += self(self, i, j);
            }
        }
        return rec;
    };

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans = max(ans, dfs(dfs, i, j));
        }
    }

    cout << ans << '\n';
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
