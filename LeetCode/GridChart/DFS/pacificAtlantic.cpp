/*** 
 * @Author: Quarret
 * @Date: 2025-06-19 15:55:00
 * @LastEditTime: 2025-06-20 10:25:19
 */

 /*
 由于四个方向的更新不是同时的，可能因为这里的延迟导致错落状态
 所以采用“母体传染”，假如heights[i][j]这里可以连接到PA,则将所有能够与其相连其高度大于等于它的更新状态
 这样就不用担心状态更新的延迟

 秘诀：从母体来感染所有的可感染节点!!!
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int m = heights.size(), n = heights[0].size();
    vector<vector<int>> vis1(m, vector<int>(n, 0)), vis2(m, vector<int>(n, 0));
    vector<vector<int>> ans;
    int next[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};

    //如果要在函数中修改参数的值，一定要传实参！！！！ vector<vector<int>>& vis
    auto dfs = [&](this auto&& dfs, int i, int j, vector<vector<int>>& vis) -> void {
        vis[i][j] = 1;
        if (vis1[i][j] && vis2[i][j]) ans.push_back({i, j});

        for (int k = 0; k < 4; k++) {
            int nx = i + next[k][0];
            int ny = j + next[k][1];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n || vis[nx][ny]) continue;

            if (heights[i][j] <= heights[nx][ny]) {
                dfs(nx, ny, vis);
            }
        }
    };

    for (int r = 0; r < m; r++) {
        dfs(r, 0, vis1);

        dfs(r, n - 1, vis2);
    }

    for (int c = 0; c < n; c++) {
        dfs(0, c, vis1);

        dfs(m - 1, c, vis2);
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (vis1[i][j] && vis2[i][j]) ans.push_back({i, j});
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //pacificAtlantic(heights);

    return 0;
}
