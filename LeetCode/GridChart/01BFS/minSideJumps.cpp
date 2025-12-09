/*** 
 * @Author: Quarret
 * @Date: 2025-06-30 17:50:34
 * @LastEditTime: 2025-06-30 18:15:33
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> obs = {0,2,1,0,3,0};
int minSideJumps(vector<int>& obstacles) {
    int n = obstacles.size();
    int next[6][2] = {-1, 0, 1, 0, 0, -1, 0, 1, 0, 2, 0, -2};
    vector<array<int, 4>> dis(n, {INT32_MAX, INT32_MAX, INT32_MAX, INT32_MAX});

    deque<pair<int, int>> deq;
    deq.emplace_front(0, 2);
    dis[0][2] = 0;

    while (!deq.empty()) {
        auto [x, y] = deq.front();
        deq.pop_front();

        for (auto& [dx, dy]: next) {
            int nx = x + dx;
            int ny = y + dy;

            if (nx < 0 || nx >= n || ny <= 0 || ny > 3 || obstacles[nx] == ny) continue;
            if (x == nx && 1 + dis[x][y] < dis[nx][ny]) {
                dis[nx][ny] = 1 + dis[x][y];
                deq.emplace_back(nx, ny);
            } else if (y == ny && dis[x][y] < dis[nx][ny]) {
                dis[nx][ny] = dis[x][y];
                deq.emplace_front(nx, ny);
            }
        }
    }

    return min(dis[n - 1][1], min(dis[n - 1][2], dis[n - 1][3]));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    minSideJumps(obs);

    return 0;
}
