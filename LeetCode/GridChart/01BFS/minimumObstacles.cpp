/*** 
 * @Author: Quarret
 * @Date: 2025-06-30 19:23:29
 * @LastEditTime: 2025-06-30 19:28:18
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minimumObstacles(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int next[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
    vector<vector<int>> dis(m, vector<int>(n, INT32_MAX));

    deque<pair<int, int>> deq;
    deq.emplace_front(0, 0);
    dis[0][0] = 1;

    while (!deq.empty()) {
        auto [x, y] = deq.front();
        deq.pop_front();

        for (auto& [dx, dy]: next) {
            int nx = x + dx;
            int ny = y + dy;

            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (grid[nx][ny] == 1 && 1 + dis[x][y] < dis[nx][ny]) {
                dis[nx][ny] = 1 + dis[x][y];
                deq.emplace_back(nx, ny);
            } else if (grid[nx][ny] == 0 && dis[x][y] < dis[nx][ny]) {
                dis[nx][ny] = dis[x][y];
                deq.emplace_front(nx, ny);
            }
        }
    }

    return dis[m - 1][n - 1];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
