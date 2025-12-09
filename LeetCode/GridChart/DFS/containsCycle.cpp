/*** 
 * @Author: Quarret
 * @Date: 2025-06-20 10:37:33
 * @LastEditTime: 2025-06-20 10:58:17
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool containsCycle(vector<vector<char>>& grid) {
    int m = grid.size(), n = grid[0].size(), flag = 0;
    vector<vector<int>> cnt(m, vector<int>(n, 0)), vis(m, vector<int>(n, 0));
    int next[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};

    auto dfs = [&](this auto&& dfs, int i, int j, char c, int num) -> void {
        vis[i][j] = 1;
        cnt[i][j] = num + 1;

        for (int k = 0; k < 4; k++) {
            int nx = i + next[k][0];
            int ny = j + next[k][1];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] != c) continue;
            if (!vis[nx][ny]) dfs(nx, ny, c, cnt[nx][ny]);
            else if (cnt[i][j] - cnt[nx][ny] >= 3) flag = 1;
        }
    };

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!vis[i][j]) dfs(i, j, grid[i][j], 0);
        }
    }

    return flag;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
