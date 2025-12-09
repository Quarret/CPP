/*** 
 * @Author: Quarret
 * @Date: 2025-06-29 13:37:57
 * @LastEditTime: 2025-06-30 17:36:55
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<string> matrix = {".A","CA"};
int minMoves(vector<string>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    int next[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
    vector<vector<int>> dis(m, vector<int>(n, 2005));
    vector<int> vis(26, 0);

    vector<vector<pair<int, int>>> trans(26);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != '.' && matrix[i][j] != '#') {
                trans[matrix[i][j] - 'A'].emplace_back(i, j);
            }
        }
    }

    deque<pair<int, int>> deq;
    deq.emplace_front(0, 0);
    dis[0][0] = 0;

    while (!deq.empty()) {
        auto [x, y] = deq.front();
        deq.pop_front();

        if (matrix[x][y] != '.' && !vis[matrix[x][y] - 'A']) {
            vis[matrix[x][y] - 'A'] = 1;
            for (auto& [transx, transy]: trans[matrix[x][y] - 'A']) {
                if (dis[transx][transy] > dis[x][y]) {
                    deq.emplace_front(transx, transy);
                    dis[transx][transy] = dis[x][y];
                }
            }
        }

        for (auto& [dx, dy]: next) {
            int nx = x + dx;
            int ny = y + dy;

            if (nx < 0 || nx >= m || ny < 0 || ny >= n || matrix[nx][ny] == '#') continue;
            if (1 + dis[x][y] < dis[nx][ny]) {
                dis[nx][ny] = 1 + dis[x][y];
                deq.emplace_back(nx, ny);
            }
        }
    }

    return dis[m - 1][n - 1] == 2005 ? -1 : dis[m - 1][n - 1];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    minMoves(matrix);

    return 0;
}
