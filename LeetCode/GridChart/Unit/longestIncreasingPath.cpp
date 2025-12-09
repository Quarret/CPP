/*** 
 * @Author: Quarret
 * @Date: 2025-07-01 16:28:28
 * @LastEditTime: 2025-07-01 16:55:44
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int longestIncreasingPath(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size(), ans = 0;
    int next[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
    vector<vector<int>> vis(m, vector<int>(n, 0)), dis(m, vector<int>(n, 1));

    auto dfs = [&](this auto& dfs, int x, int y) -> void {
        vis[x][y] = 1;

        for (auto& [dx, dy]: next) {
            int nx = x + dx;
            int ny = y + dy;

            if (nx < 0 || nx >= m || ny < 0 || ny >= n || matrix[nx][ny] >= matrix[x][y]) continue;
            if (vis[nx][ny]) {
                dis[x][y] = max(dis[x][y], 1 + dis[nx][ny]);
                continue;
            }
            
            dfs(nx, ny);
            dis[x][y] = max(dis[x][y], 1 + dis[nx][ny]);
        }
    };
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!vis[i][j]) dfs(i, j);
            ans = max(ans, dis[i][j]);
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
