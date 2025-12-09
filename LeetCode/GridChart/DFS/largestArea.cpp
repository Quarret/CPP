/*** 
 * @Author: Quarret
 * @Date: 2025-06-17 09:38:12
 * @LastEditTime: 2025-06-17 11:03:55
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
"113415514",
"124112542",
"313225220",
"253354005",
"352014331",
"304514425",
"553313413",
"532352143",
"220340311",
"245210141"
*/
vector<string> grid = {"113415514","124112542","313225220","253354005","352014331","304514425","553313413","532352143","220340311","245210141"};
int largestArea(vector<string>& grid) {
    int m = grid.size(), n = grid[0].size();
    bool flag = true;

    auto dfs = [&](this auto&& dfs, int i, int j, char c) -> int {
        //要让所有与走廊相连的点都被标记，这样在后续遍历中就不会重复走，所以不能提前中断
        //if (!flag) return 0;

        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != c) return 0;
        if (i - 1 < 0 || i + 1 >= m || j - 1 < 0 || j + 1 >= n) {
            flag = 0;
            return 0;
        }
        if (grid[i - 1][j] == '0' || grid[i + 1][j] == '0' || grid[i][j - 1] == '0' || grid[i][j + 1] == '0') {
            flag = 0;
            return 0;
        }
        //标记已经走过的点
        grid[i][j] = '6';

        int res = 1;
        res += dfs(i - 1, j, c) + dfs(i + 1, j, c) + dfs(i, j - 1, c) + dfs(i, j + 1, c);
        return res;
    };

    //dfs(1, 2, grid[1][2]);
    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] > '0' && grid[i][j] < '6') {
                flag = true;
                int num = dfs(i, j, grid[i][j]);
                if (flag) ans = max(ans, num);
            }
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    largestArea(grid);

    return 0;
}
