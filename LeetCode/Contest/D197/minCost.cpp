#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minCost(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();

    int or_all = 0;
    for (auto &row : grid) {
        for (int x : row) {
            or_all |= x;
        }
    }
    
    int ans = INT_MAX;
    vector memo(m, vector(n, vector<int>(or_all + 1, 0)));
    auto dfs = [&](this auto&& dfs, int i, int j, int xor_all) -> void {
        if (ans == 0 || i < 0 || j < 0 || memo[i][j][xor_all]) {
            return;
        }

        memo[i][j][xor_all] = 1;
        xor_all ^= grid[i][j];
        if (i == 0 && j == 0) {
            ans = min(ans, xor_all);
        }

        dfs(i - 1, j , xor_all);
        dfs(i, j - 1, xor_all);
    };

    dfs(m - 1, n - 1, 0);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}