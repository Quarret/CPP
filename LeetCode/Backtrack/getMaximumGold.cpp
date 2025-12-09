#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int getMaximumGold(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int nxt[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
    
    int ans = 0;
    auto dfs = [&](this auto&& dfs, int x, int y, int sum) -> void {
        int score = grid[x][y];
        ans = max(ans, sum + score);

        for (int k = 0; k < 4; k++) {
            int nx = x + nxt[k][0];
            int ny = y + nxt[k][1];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || !grid[nx][ny]) continue;
            grid[x][y] = 0;
            dfs(nx, ny, sum + score);
            grid[x][y] = score;
        }
    };
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j]) {
                dfs(i, j, 0);
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
