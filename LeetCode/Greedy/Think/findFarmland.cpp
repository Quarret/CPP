#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<vector<int>> findFarmland(vector<vector<int>>& land) {
    int m = land.size(), n = land[0].size();
    int nxt[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};

    vector vis(m, vector<int>(n, 0));
    int mn = INT_MAX, mx = INT_MIN;
    int r1 = 0, c1 = 0, r2 = 0, c2 = 0;
    auto dfs = [&](this auto&& dfs, int x, int y) -> void {
        vis[x][y] = 1;

        int s = x + y;
        if (s < mn) {
            r1 = x;
            c1 = y;
            mn = s;
        }
        if (s > mx) {
            r2 = x;
            c2 = y;
            mx = s;
        }

        for (auto &[dx, dy] : nxt) {
            int nx = x + dx;
            int ny = y + dy;
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || vis[nx][ny] || !land[nx][ny]) continue;
            dfs(nx, ny);
        }
    };

    vector<vector<int>> ans;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j] || !land[i][j]) continue;
            mn = INT_MAX, mx = INT_MIN;
            dfs(i, j);
            // ans.emplace_back(r1, c1, r2, c2);
            ans.push_back({r1, c1, r2, c2});
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}