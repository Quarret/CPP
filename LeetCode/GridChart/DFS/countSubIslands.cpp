/*** 
 * @Author: Quarret
 * @Date: 2025-06-19 12:01:59
 * @LastEditTime: 2025-06-19 12:08:14
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    int m = grid1.size(), n = grid1[0].size(), flag = 1;
    int next[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};

    auto dfs = [&](this auto&& dfs, int i, int j) -> void {
        grid2[i][j] = 2;
        if (grid1[i][j] != 1) flag = 0;

        for (int k = 0; k < 4; k++) {
            int nx = i + next[k][0];
            int ny = j + next[k][1];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (grid2[nx][ny] != 1) continue;

            dfs(nx, ny);
        }
    };

    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid2[i][j] == 1) {
                flag = 1;
                dfs(i, j);
                ans += (flag == 1);
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
