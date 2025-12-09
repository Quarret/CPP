/*** 
 * @Author: Quarret
 * @Date: 2025-06-16 21:05:07
 * @LastEditTime: 2025-06-16 21:10:15
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size(), ans = 0;

    auto dfs = [&](this auto&& dfs, int i, int j) -> int {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1) return 0;
        grid[i][j] = 2;

        //return 1 + dfs(i - 1, j) + dfs(i + 1, j) + dfs(i, j - 1) + dfs(i, j + 1);
        int res = 1;
        res += dfs(i - 1, j) + dfs(i + 1, j) + dfs(i, j - 1) + dfs(i, j + 1);
        return res;
    };

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                ans = max(ans, dfs(i, j));
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
