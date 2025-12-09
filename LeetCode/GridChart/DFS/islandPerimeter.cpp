/*** 
 * @Author: Quarret
 * @Date: 2025-06-17 11:16:03
 * @LastEditTime: 2025-06-17 11:30:36
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int islandPerimeter(vector<vector<int>>& grid) {
    int r = grid.size(), c = grid[0].size();

    auto dfs = [&](this auto&& dfs, int i, int j) -> int {
        if (i < 0 || i >= r || j < 0 || j >= c) return 0;
        //不是要求目标就是标记过的或者非目标值
        if (grid[i][j] != 1) return 0;

        grid[i][j] = 2;

        int res = 0;
        if (i - 1 < 0 || grid[i - 1][j] == 0) res++;
        if (i + 1 >= r || grid[i + 1][j] == 0) res++;
        if (j - 1 < 0 || grid[i][j - 1] == 0) res++;
        if (j + 1 >= c || grid[i][j + 1] == 0) res++;

        return res + dfs(i - 1, j) + dfs(i + 1, j) + dfs(i, j - 1) + dfs(i, j + 1);
    };

    int ans = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == 1) ans = dfs(i, j); 
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
