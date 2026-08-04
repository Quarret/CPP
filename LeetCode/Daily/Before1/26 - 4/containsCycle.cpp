#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool containsCycle(vector<vector<char>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int nxt[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
    vector vis(m, vector<int>(n, 0));

    auto dfs = [&](this auto&& dfs, int x, int y, int px, int py) -> bool {
        vis[x][y] = 1;

        for (auto &[dx, dy] : nxt) {
            int nx = x + dx;
            int ny = y + dy;
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] != grid[x][y]) continue;
            if (nx == px && ny == py) continue;
            if (vis[nx][ny]) return true;
            if (dfs(nx, ny, x, y)) return true;
        }

        return false;
    };

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!vis[i][j] && dfs(i, j, -1, -1)) return true;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}