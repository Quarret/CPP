#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int uniquePathsIII(vector<vector<int>>& grid) {
    int cnt = 0, m = grid.size(), n = grid[0].size();
    int nxt[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
    int x1, y1, x2, y2;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0) cnt++;
            else if (grid[i][j] == 1) {
                x1 = i;
                y1 = j;
            } else if (grid[i][j] == 2) {
                x2 = i;
                y2 = j;
            }
        }
    }
    
    vector vis(m, vector<int>(n, 0));
    int ans = 0;
    auto dfs = [&](this auto&& dfs, int x, int y, int s) -> void {
        if (x == x2 && y == y2) {
            ans += s == cnt;
            return;
        }

        for (auto &[dx, dy] : nxt) {
            int nx = x + dx;
            int ny = y + dy;
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || vis[nx][ny] || grid[nx][ny] == -1) continue;
            vis[nx][ny] = 1;
            dfs(nx, ny, s + (grid[nx][ny] == 0));
            vis[nx][ny] = 0;
        }
    };

    vis[x1][y1] = 1;
    dfs(x1, y1, 0);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
