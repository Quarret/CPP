/*** 
 * @Author: Quarret
 * @Date: 2025-06-22 22:27:41
 * @LastEditTime: 2025-06-23 20:17:10
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
单源bfs O(n ^ 4)
进行了大量的重复节点访问
*/
vector<vector<int>> grid = {{1,0,0},{0,0,0},{0,0,0}};
int maxDistance(vector<vector<int>>& grid) {
    int n = grid.size(), ans = 0, flag = 0;
    //vector<vector<int>> vis(n, vector<int>(n, 0));
    int next[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};

    // auto bfs = [&](int i, int j, vector<vector<int>> vis) -> void {
    //     queue<tuple<int, int, int>> q;
    //     q.emplace(i, j, 0);
    //     vis[i][j] = 1;

    //     while (!q.empty()) {
    //         auto [x, y, cnt] = q.front();
    //         q.pop();

    //         for (int k = 0; k < 4; k++) {
    //             int nx = x + next[k][0];
    //             int ny = y + next[k][1];

    //             if (nx < 0 || nx >= n || ny < 0 || ny >= n || vis[nx][ny]) continue;
    //             if (grid[nx][ny]) {
    //                 ans = max(ans, cnt + 1);
    //                 return;
    //             }
    //             q.emplace(nx, ny, cnt + 1);
    //             vis[nx][ny] = 1;
    //         }
    //     }
    // };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!grid[i][j]) {
                vector<vector<int>> vis(n, vector<int>(n, 0));
                queue<tuple<int, int, int>> q;
                q.emplace(i, j, 0);
                vis[i][j] = 1;
                flag = 0;

                while (!q.empty()) {
                    auto [x, y, cnt] = q.front();
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        int nx = x + next[k][0];
                        int ny = y + next[k][1];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= n || vis[nx][ny]) continue;
                        if (grid[nx][ny]) {
                            ans = max(ans, cnt + 1);
                            flag = 1;
                            break;
                        }
                        q.emplace(nx, ny, cnt + 1);
                        vis[nx][ny] = 1;
                    }
                    if (flag) break;
                }
            }
        }
    }

    return ans ? ans : -1;
}

/*
多源bfs
首先对问题换一个角度思考：
海洋距离最近的岛最大 -> 岛在bfs(单调不减)中能够到达的最大层海(对于这个最大层水这个岛就是最近的)
由于有多个岛，所以想象一个超级节点所有岛到它的距离都是0，所有岛为第一层,bfs的寻找最远层水
*/

int maxDistance(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<int>> vis(n, vector<int>(n, 0));
    queue<pair<int, int>> q;
    int next[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j]) {
                vis[i][j] = 1;
                q.push({i, j});
            }
        }
    }

    int depth = 0;
    while (!q.empty()) {
        depth++;
        int cnt = q.size();
        if (cnt == 0 || cnt == n * n) return -1;
        /*
        将每层节点都bfs完后再进行下一层
        由于单源bfs只有一个源节点，第一层只有一个所以可以一个一个bfs
        */
        for (int t = 0; t < cnt; t++) {
            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + next[k][0];
                int ny = y + next[k][1];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n || vis[nx][ny]) continue;
                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }

    return depth - 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    maxDistance(grid);

    return 0;
}
