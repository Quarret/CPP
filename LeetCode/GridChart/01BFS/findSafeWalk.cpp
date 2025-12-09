/*** 
 * @Author: Quarret
 * @Date: 2025-06-29 12:42:39
 * @LastEditTime: 2025-06-29 13:29:34
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool findSafeWalk(vector<vector<int>>& grid, int health) {
    int m = grid.size(), n = grid[0].size();
    int next[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
    vector<vector<vector<int>>> vis(m, vector<vector<int>>(n, vector<int>(health + 1, 0)));

    queue<tuple<int, int, int>> q;
    q.emplace(0, 0, health - grid[0][0]);
    vis[0][0][health - grid[0][0]] = 1;

    while (!q.empty()) {
        int cnt = q.size();

        for (int t = 0; t < cnt; t++) {
            auto [x, y, hp] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + next[k][0];
                int ny = y + next[k][1];

                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if (nx == m - 1 && ny == n - 1 && hp > grid[nx][ny]) return true;

                if (!grid[nx][ny] && !vis[nx][ny][hp]) {
                    q.emplace(nx, ny, hp);
                    vis[nx][ny][hp] = 1;
                } else if (hp > 1 && !vis[nx][ny][hp - 1]) {
                    q.emplace(nx, ny, hp - 1);
                    vis[nx][ny][hp - 1] = 1;
                }
            }
        }
    }

    return false;
}


/*
[0][1] 0 -> 1边权为1， 1 -> 0 边权为0
边权只有0，1的图，用bfs + 双端队列完成线性时间复杂度
01bfs其实是对dijstra算法的优化，它将较小边权的路放入队列队首来优先访问保证访问相同[x, y]距离最小
来替代dijstra中要维护的最小堆
*/

bool findSafeWalk(vector<vector<int>>& grid, int health) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dis(m, vector<int>(n, 105));
    int next[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};

    deque<pair<int, int>> deq;
    deq.emplace_front(0, 0);
    dis[0][0] = grid[0][0];

    while (!deq.empty()) {
        auto [x, y] = deq.front();
        deq.pop_front();

        for (auto& [dx, dy]: next) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                int cost = grid[nx][ny];
                if (cost + dis[x][y] < dis[nx][ny]) {//不走回头路
                    dis[nx][ny] = cost + dis[x][y];
                    cost ? deq.emplace_back(nx, ny) : deq.emplace_front(nx, ny);
                }
            }
        }
    }

    return dis[m - 1][n - 1] < health;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
