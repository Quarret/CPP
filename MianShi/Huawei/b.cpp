#include <bits/stdc++.h>
using ll = long long;
using namespace std;


void solve() {
    int m, n;
    cin >> m >> n;

    if (m <= 0 || n <= 0) {
        cout << -1 << '\n';
        return;
    }

    vector<vector<int>> pcb(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> pcb[i][j];
        }
    }

    if (pcb[0][0] || pcb[m - 1][n - 1]) {
        cout << -1 << '\n';
        return;
    }

    vector<vector<array<int, 2>>> memo(m, vector<array<int, 2>>(n, {-1, -1}));
    auto dfs = [&](auto&& dfs, int i, int j, int d) -> int {
        if (i < 0 || j < 0 || pcb[i][j]) {
            return 1e9;
        }

        if (i == 0 && j == 0) {
            return 0;
        }

        int &res = memo[i][j][d];
        if (res != -1) return res;

        res = INT_MAX / 2;
        if (d == 0) {
            res = min({res, dfs(dfs, i - 1, j, d), dfs(dfs, i, j - 1, d ^ 1) + 1});
        } else {
            res = min({res, dfs(dfs, i, j - 1, d), dfs(dfs, i - 1, j, d ^ 1) + 1});
        }
        
        return res;
    };

    int ans = min(dfs(dfs, m - 1, n - 1, 0), dfs(dfs, m - 1, n - 1, 1));
    ans = ans >= 1e9 ? -1 : ans;

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}