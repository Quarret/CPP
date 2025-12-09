/*** 
 * @Author: Quarret
 * @Date: 2025-06-19 09:43:47
 * @LastEditTime: 2025-06-19 11:12:42
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve(vector<vector<char>>& board) {
    int m = board.size(), n = board[0].size(), flag = 1;
    vector<vector<int>> vis(m, vector<int>(n, 0));
    vector<pair<int, int>> ans;
    int next[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

    auto dfs = [&](this auto&& dfs, int i, int j) -> void {
        if (i < 0 || i >= m || j < 0 || j >= n) {
            flag = 0;
            return;
        }
        if (board[i][j] == 'X' || vis[i][j]) return;

        vis[i][j] = 1;
        ans.push_back({i, j});

        dfs(i - 1, j);
        dfs(i + 1, j);
        dfs(i, j - 1);
        dfs(i, j + 1);
    };

    auto dfs1 = [&](this auto&& dfs1, int i, int j) -> void {
        vis[i][j] = 1;
        ans.push_back({i, j});

        for (int k = 0; k < 4; k++) {
            int nxtx = i + next[k][0];
            int nxty = j + next[k][1];

            if (nxtx < 0 || nxtx >= m || nxty < 0 || nxty >= n) {
                flag = 0;
                continue;
            }
            if (board[nxtx][nxty] == 'X' || vis[nxtx][nxty]) continue;

            dfs(nxtx, nxty);
        }
    };

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'O' && !vis[i][j]) {
                flag = 1;
                dfs1(i, j);

                if (flag) {
                    for (auto& [x, y]: ans) {
                        board[x][y] = 'X';
                    }
                } else ans.clear();
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
