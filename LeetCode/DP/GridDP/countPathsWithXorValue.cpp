#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
    int m = grid.size(), n = grid[0].size(), MOD = 1e9 + 7;

    vector memo(m + 1, vector<array<int, 16>>(n + 1, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}));
    auto dfs = [&](this auto&& dfs, int i, int j, int x) -> int {
        if (i < 0 || j < 0) return 0;

        int &res = memo[i][j][x];
        if (i == 0 && j == 0 && (x ^ grid[i][j]) == 0) return 1;
        if (res != -1) return res % MOD;
        res = dfs(i - 1, j, x ^ grid[i][j]) + dfs(i, j - 1, x ^ grid[i][j]);
        return res % MOD;
    };

    dfs(m - 1, n - 1, k);
    return memo[m - 1][n - 1][k] == -1 ? 0 : memo[m - 1][n - 1][k] % MOD;
}


int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
    int m = grid.size(), n = grid[0].size(), MOD = 1e9 + 7;
    vector f(m + 1, vector<array<int, 16>>(n + 1, {0}));
    
    f[0][1][0] = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 16; k++) {
                f[i + 1][j + 1][k] = (f[i][j + 1][k ^ grid[i][j]] + f[i + 1][j][k ^ grid[i][j]]) % MOD;
            }
        }
    }

    return f[m][n][k] % MOD;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
