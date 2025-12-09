/*** 
 * @Author: Quarret
 * @Date: 2025-06-18 09:14:16
 * @LastEditTime: 2025-06-18 10:38:07
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<vector<int>> grid = {{1,1},{1,2}};
vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
    int m = grid.size(), n = grid[0].size();
    int num = grid[row][col];
    vector<vector<int>> vis(m, vector<int>(n, 0));
    vector<pair<int, int>> border;

    auto dfs = [&](this auto&& dfs, int i,  int j) -> void {
        if (!vis[i][j]) vis[i][j] = 1;
        else return;

        if (i - 1 >= 0 && grid[i - 1][j] == num && !vis[i - 1][j]) dfs(i - 1, j);
        if (i + 1 < m && grid[i + 1][j] == num && !vis[i + 1][j]) dfs(i + 1, j);
        if (j - 1 >= 0 && grid[i][j - 1] == num && !vis[i][j - 1]) dfs(i, j - 1);
        if (j + 1 < n && grid[i][j + 1] == num && !vis[i][j + 1]) dfs(i, j + 1);


        //对于需要相邻关系的grid格，不要在dfs过程中改变格子的属性,判断遍历改变是否会影响结果
        if (i - 1 < 0 || (grid[i - 1][j] != num && !vis[i - 1][j])) grid[i][j] = color;
        if (i + 1 >= m || (grid[i + 1][j] != num && !vis[i + 1][j])) grid[i][j] = color;
        if (j - 1 < 0 || (grid[i][j - 1] != num && !vis[i][j - 1])) grid[i][j] = color;
        if ((j + 1 >= n || grid[i][j + 1] != num  && !vis[i][j + 1])) grid[i][j] = color;

        // if ((i - 1 < 0 || grid[i - 1][j] != num)) border.push_back({i, j});
        // if ((i + 1 >= m || grid[i + 1][j] != num)) border.push_back({i, j});
        // if ((j - 1 < 0 || grid[i][j - 1] != num)) border.push_back({i, j});
        // if ((j + 1 >= n || grid[i][j + 1] != num)) border.push_back({i, j});
    };

    dfs(row, col);
    // for (auto [x, y]: border) {
    //     grid[x][y] = color;
    // }

    return grid;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    colorBorder(grid, 0, 0, 3);

    return 0;
}
