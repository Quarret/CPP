/*** 
 * @Author: Quarret
 * @Date: 2025-07-01 16:06:40
 * @LastEditTime: 2025-07-01 16:19:09
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size();
    int next[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
    vector<vector<int>> t(n, vector<int>(n, INT32_MAX));

    auto cmp = [&](pair<int, int> p1, pair<int, int> p2) -> bool {
        return t[p1.first][p1.second] > t[p2.first][p2.second];
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
    pq.emplace(0, 0);
    t[0][0] = grid[0][0];

    while (!pq.empty()) {
        auto [x, y] = pq.top();
        pq.pop();

        for (auto& [dx, dy]: next) {
            int nx = x + dx;
            int ny = y + dy;

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (grid[nx][ny] < t[nx][ny] && t[x][y] < t[nx][ny]) {
                t[nx][ny] = max(t[x][y], grid[nx][ny]);
                pq.emplace(nx, ny);
            }
        }
    }

    return t[n - 1][n - 1];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
