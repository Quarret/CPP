#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int numIslands(vector<vector<char>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int next[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
    vector vis(m, vector<int>(n, 0));
    
    auto dfs = [&](this auto&& dfs, int x, int y) -> void {
        vis[x][y] = 1;

        for (int k = 0; k < 4; k++) {
            int nx = x + next[k][0];
            int ny = y + next[k][1];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == '0' || vis[nx][ny]) continue;
            dfs(nx, ny);
        }
    };

    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!vis[i][j] && grid[i][j] == '1') {
                ans++;
                dfs(i, j);
            }
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
