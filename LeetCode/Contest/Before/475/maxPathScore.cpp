#include <bits/stdc++.h>
using i64 = long long;
using namespace std;


int maxPathScore(vector<vector<int>>& grid, int k) {
    int m = grid.size(), n = grid[0].size();
    int nxt[2][2] = {1, 0, 0, 1};
    
    int ans = -1;
    vector vis(m, vector<int>(n, 0));
    auto dfs = [&](this auto&& dfs, int x, int y, int cost, int score) -> void {
        if (grid[x][y] == 1) {
            cost = cost + 1;
            score = score + 1;
        } else if (grid[x][y] == 2) {
            cost = cost + 1;
            score = score + 2;
        }
        
        
        if (cost > k) {
            return;
        }

        if (x == m - 1 && y == n - 1) {
            ans = max(ans, score);
            return;
        }

        vis[x][y] = 1;
        for (auto &[dx, dy] : nxt) {
            int nx = x + dx;
            int ny = y + dy;
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || vis[nx][ny]) continue;
            dfs(nx, ny, cost, score);
        }
        vis[x][y] = 0;
    };

    dfs(0, 0, 0, 0);
    return ans;
}

int maxPathScore(vector<vector<int>>& grid, int k) {
    int m = grid.size(), n = grid[0].size();
    vector f(m + 1, vector(n + 1, vector<int>(k + 1, INT_MIN)));
    for (int t = 0; t <= k; t++) {
        f[0][1][t] = 0;
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int t = 0; t <= k; t++) {
                if (grid[i][j] == 0) {
                    f[i + 1][j + 1][t] = max({f[i + 1][j + 1][t], f[i][j + 1][t], f[i + 1][j][t]});
                } else if (grid[i][j] == 1 && t < k) {
                    f[i + 1][j + 1][t + 1] = max({f[i + 1][j + 1][t + 1], f[i][j + 1][t] + 1, f[i + 1][j][t] + 1});
                } else if (grid[i][j] == 2 && t < k) {
                    f[i + 1][j + 1][t + 1] = max({f[i + 1][j + 1][t + 1], f[i][j + 1][t] + 2, f[i + 1][j][t] + 2});
                }
            }
        }
    }

    long long ans = *max_element(f[m][n].begin(), f[m][n].end());
    return ans == INT_MIN ? -1 : ans;
}


int maxPathScore(vector<vector<int>>& grid, int k) {
    int m = grid.size(), n = grid[0].size();

    // 记忆化搜索, 搜索中有几个状态就要创建几维的数组
    vector memo(m, vector(n, vector<int>(k + 1, -1)));
    auto dfs = [&](this auto&& dfs, int i, int j, int k) -> int {
        if (i < 0 || j < 0 || k < 0) {
            return INT_MIN / 2;
        }

        if (i == 0 && j == 0) {
            return 0;
        }

        int &res = memo[i][j][k];
        if (res != -1) {
            return res;
        }
        int x = grid[i][j];
        if (x > 0) k--;
        res = max(dfs(i - 1, j, k), dfs(i, j - 1, k)) + x;

        return res;
    };

    return max(dfs(m - 1, n - 1, k), -1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
