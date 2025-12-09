#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<vector<int>> grid = {{1, 2}};
int countPaths(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size(), MOD = 1e9 + 7;
    int next[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
    vector memo(m, vector<int>(n));

    auto dfs = [&](this auto&& dfs, int x, int y, int val) -> int {
        if (x < 0 || x >= m || y < 0 || y >= n || val >= grid[x][y]) return 0;

        int &res = memo[x][y];
        if (res) return res;
        for (auto &[dx, dy] : next) {
            int nx = x + dx;
            int ny = y + dy;
            res = (res + dfs(nx, ny, grid[x][y])) % MOD;
        }

        res++;
        return res;
    };

    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            ans = (ans + dfs(i, j, 0)) % MOD;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    countPaths(grid);

    return 0;
}
