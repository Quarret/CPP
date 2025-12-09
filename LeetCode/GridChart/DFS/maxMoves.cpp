/*** 
 * @Author: Quarret
 * @Date: 2025-06-19 09:17:36
 * @LastEditTime: 2025-06-19 09:28:28
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<vector<int>> grid = {{2,4,3,5},{5,4,9,3},{3,4,2,11},{10,9,13,15}};
int maxMoves(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size(), ans = 0;
    vector<vector<int>> vis(m, vector<int>(n, 0));

    auto dfs = [&](this auto&& dfs, int i, int j, int val, int cnt) -> void {
        if (i < 0 || i >= m || j >= n || grid[i][j] <= val || vis[i][j]) return;

        vis[i][j] = 1;
        ans = max(ans, ++cnt);

        dfs(i - 1, j + 1, grid[i][j], cnt);
        dfs(i, j + 1, grid[i][j], cnt);
        dfs(i + 1, j + 1, grid[i][j], cnt);
    };

    for (int i = 0; i < m; i++) {
        dfs(i, 0, 0, 0);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    maxMoves(grid);

    return 0;
}
