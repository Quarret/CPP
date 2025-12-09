/*** 
 * @Author: Quarret
 * @Date: 2025-06-18 10:39:53
 * @LastEditTime: 2025-06-18 10:46:22
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int numEnclaves(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size(), flag = 0, cnt = 0;

    auto dfs = [&](this auto&& dfs, int i, int j) -> void {
        if (i < 0 || i >= m || j < 0 || j >= n) {
            flag = 1;
            return;
        }
        if (grid[i][j] != 1) return;

        cnt++;
        grid[i][j] = 2;
        dfs(i - 1, j);
        dfs(i + 1, j);
        dfs(i, j - 1);
        dfs(i, j + 1);
    };

    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                flag = 0;
                cnt = 0;
                dfs(i, j);
                ans += (flag == 0 ? cnt : 0);
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
