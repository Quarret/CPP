/*** 
 * @Author: Quarret
 * @Date: 2025-06-23 22:22:41
 * @LastEditTime: 2025-06-23 22:57:20
 */

#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<vector<int>> grid = {{1,1,1,1,1},{1,0,0,0,1},{1,0,1,0,1},{1,0,0,0,1},{1,1,1,1,1}};
int shortestBridge(vector<vector<int>>& grid) {
    int n = grid.size(), flag = 0, d = 0;;
    int next[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
    queue<pair<int, int>> q;
    
    auto dfs = [&](this auto&& dfs, int i, int j) -> void {
        grid[i][j] = 2;
        q.emplace(i, j);//dfs中bfs

        for (int k = 0; k < 4; k++) {
            int nx = i + next[k][0];
            int ny = j + next[k][1];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n || grid[nx][ny] != 1) continue;
            dfs(nx, ny);
        }
    };

    //dfs中bfs快很多:(
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                dfs(i, j);

                while (!q.empty()) {
                    d++;
                    int cnt = q.size();
            
                    for (int t = 0; t < cnt; t++) {
                        auto [x, y] = q.front();
                        q.pop();
            
                        for (int k = 0; k < 4; k++) {
                            int nx = x + next[k][0];
                            int ny = y + next[k][1];
            
                            if (nx < 0 || nx >= n || ny < 0 || ny >= n || grid[nx][ny] == 2) continue;
                            if (grid[nx][ny] == 1) return d - 1;
                            grid[nx][ny] = 2;
                            q.emplace(nx, ny);
                        }
                    }
                }
            }
        }
    }
    return d;


    //先dfs再bfs
    for (int i = 0; i < n ; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1 && !flag) {
                dfs(i, j);
                flag = 1;
            }
            if (grid[i][j] == 1 && flag) q.emplace(i, j);
        }
    }

    while (!q.empty()) {
        d++;
        int cnt = q.size();

        for (int t = 0; t < cnt; t++) {
            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + next[k][0];
                int ny = y + next[k][1];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n || grid[nx][ny] == 1) continue;
                if (grid[nx][ny] == 2) return d - 1;
                grid[nx][ny] = 1;
                q.emplace(nx, ny);
            }
        }
    }

    return d;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    shortestBridge(grid);

    return 0;
}
