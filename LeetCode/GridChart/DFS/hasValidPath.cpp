/*** 
 * @Author: Quarret
 * @Date: 2025-06-19 14:56:15
 * @LastEditTime: 2025-06-19 15:26:01
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<vector<int>> grid = {{1,1,1,1,1,1,3}};
bool hasValidPath(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size(), flag = 0;

    auto dfs = [&](this auto&& dfs, int i, int j) -> void {
        if (i == m - 1 && j == n - 1) flag = 1;
        
        int op = grid[i][j];
        grid[i][j] = 0;

        if (op == 1) {
            if (j - 1 >= 0 && (grid[i][j - 1] == 4 || grid[i][j - 1] == 6 || grid[i][j - 1] == 1)) dfs(i, j - 1);
            if (j + 1 < n && (grid[i][j + 1] == 3 || grid[i][j + 1] == 5 || grid[i][j + 1] == 1)) dfs(i, j + 1);
        } else if (op == 2) {
            if (i - 1 >= 0 && (grid[i - 1][j] == 3 || grid[i - 1][j] == 4 || grid[i - 1][j] == 2)) dfs(i - 1, j);
            if (i + 1 < m && (grid[i + 1][j] == 5 || grid[i + 1][j] == 6 || grid[i + 1][j] == 2)) dfs(i + 1, j);
        } else if (op == 3) {
            if (i + 1 < m && (grid[i + 1][j] == 5 || grid[i + 1][j] == 6 || grid[i + 1][j] == 2)) dfs(i + 1, j);
            if (j - 1 >= 0 && (grid[i][j - 1] == 4 || grid[i][j - 1] == 6 || grid[i][j - 1] == 1)) dfs(i, j - 1);
        } else if (op == 4) {
            if (j + 1 < n && (grid[i][j + 1] == 3 || grid[i][j + 1] == 5 || grid[i][j + 1] == 1)) dfs(i, j + 1);
            if (i + 1 < m && (grid[i + 1][j] == 5 || grid[i + 1][j] == 6 || grid[i + 1][j] == 2)) dfs(i + 1, j);
        } else if (op == 5) {
            if (i - 1 >= 0 && (grid[i - 1][j] == 3 || grid[i - 1][j] == 4 || grid[i - 1][j] == 2)) dfs(i - 1, j);
            if (j - 1 >= 0 && (grid[i][j - 1] == 4 || grid[i][j - 1] == 6 || grid[i][j - 1] == 1)) dfs(i, j - 1);
        } else {
            if (i - 1 >= 0 && (grid[i - 1][j] == 3 || grid[i - 1][j] == 4 || grid[i - 1][j] == 2)) dfs(i - 1, j);
            if (j + 1 < n && (grid[i][j + 1] == 3 || grid[i][j + 1] == 5 || grid[i][j + 1] == 1)) dfs(i, j + 1);
        }
    };

    dfs(0, 0);
    return flag;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    hasValidPath(grid);

    return 0;
}
