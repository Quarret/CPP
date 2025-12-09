#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int numberOfPaths(vector<vector<int>>& grid, int k) {
    int m = grid.size(), n = grid[0].size();
    const int MOD = 1e9 + 7;
    vector memo(m, vector(n, vector<int>(k, -1)));

    auto dfs = [&](this auto&& dfs, int i, int j, int path) -> int {
        if (i < 0 || j < 0) {
            return 0;
        }

        path = ((path - grid[i][j]) % k + k) % k;
        if (i == 0 && j == 0) {
            return path == 0;
        }

        int &res = memo[i][j][path];
        if (res != -1) {
            return res;
        }

        res = (dfs(i - 1, j, path) + dfs(i, j - 1, path)) % MOD;        
        return res % MOD;
    };

    return dfs(m - 1, n - 1, 0);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
