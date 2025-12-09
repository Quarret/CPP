#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minCost(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int next[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
    vector<vector<int>> dis(m, vector<int>(n, INT32_MAX));

    deque<pair<int, int>> deq;
    deq.emplace_front(0, 0);
    dis[0][0] = 0;

    while (!deq.empty()) {
        auto [x, y] = deq.front();
        deq.pop_front();

        for (int k = 0; k < 4; k++) {
            int nx = x + next[k][0];
            int ny = y + next[k][1];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (k == grid[x][y] - 1 && dis[x][y] < dis[nx][ny]) {
                dis[nx][ny] = dis[x][y];
                deq.emplace_front(nx, ny);
            } else if (k != grid[x][y] - 1 && dis[x][y] + 1 < dis[nx][ny]) {
                dis[nx][ny] = dis[x][y] + 1;
                deq.emplace_back(nx, ny);
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
