/*** 
 * @Author: Quarret
 * @Date: 2025-07-01 15:29:10
 * @LastEditTime: 2025-07-01 15:58:43
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<vector<int>> heights = {{1,2,2},{3,8,2},{5,3,5}};
int minimumEffortPath(vector<vector<int>>& heights) {
    int row = heights.size(), col = heights[0].size();
    int next[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
    vector<vector<int>> dis(row, vector<int>(col, INT32_MAX));

    auto cmp = [&](pair<int, int> p1, pair<int, int> p2) -> bool {
        return dis[p1.first][p1.second] > dis[p2.first][p2.second];
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
    pq.emplace(0, 0);
    dis[0][0] = 0;

    while (!pq.empty()) {
        //非const引用绑定到const对象 auto& [x, y] = pq.top();
        auto [x, y] = pq.top();
        pq.pop();

        for (auto& [dx, dy]: next) {
            int nx = x + dx;
            int ny = y + dy;

            if (nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
            int cost = abs(heights[x][y] - heights[nx][ny]);
            if (cost < dis[nx][ny] && dis[x][y] < dis[nx][ny]) {
                dis[nx][ny] = max(cost, dis[x][y]);
                pq.emplace(nx, ny);
            }
        }
    }

    return dis[row - 1][col - 1];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cout << minimumEffortPath(heights);

    return 0;
}
