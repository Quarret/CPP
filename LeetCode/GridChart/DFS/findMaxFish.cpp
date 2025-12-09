/*** 
 * @Author: Quarret
 * @Date: 2025-06-17 16:07:59
 * @LastEditTime: 2025-06-17 16:14:41
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int findMaxFish(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();

    auto dfs = [&](this auto&& dfs, int i, int j) -> int {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] <= 0) return 0;
        int res = grid[i][j];
        grid[i][j] = -1;

        //return res + dfs(i - 1, j) + dfs(i + 1, j) + dfs(i, j - 1) + dfs(i, j + 1);

        //剪枝版
        if (i - 1 >= 0 && grid[i - 1][j] > 0) res += dfs(i - 1, j);
        if (i + 1 < m && grid[i + 1][j] > 0) res += dfs(i + 1, j);
        if (j - 1 >= 0 && grid[i][j - 1] > 0) res += dfs(i, j - 1);
        if (j + 1 < n && grid[i][j + 1] > 0) res += dfs(i, j + 1);
        return res;
    };

    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] > 0) ans = max(ans, dfs(i, j));
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
