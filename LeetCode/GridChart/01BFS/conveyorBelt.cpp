/*** 
 * @Author: Quarret
 * @Date: 2025-06-30 18:28:42
 * @LastEditTime: 2025-06-30 19:10:38
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int conveyorBelt(vector<string>& matrix, vector<int>& start, vector<int>& end) {
    int m = matrix.size(), n = matrix[0].size();
    int next[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
    vector<vector<int>> dis(m, vector<int>(n, INT32_MAX));
    char dir[4] = {'v', '^', '>', '<'};

    deque<pair<int, int>> deq;
    deq.emplace_front(start[0],start[1]);
    dis[start[0]][start[1]] = 0;

    while (!deq.empty()) {
        auto [x, y] = deq.front();
        deq.pop_front();

        for (int k = 0; k < 4; k++) {
            int nx = x + next[k][0];
            int ny = y + next[k][1];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (dir[k] == matrix[x][y] && dis[x][y] < dis[nx][ny]) {
                dis[nx][ny] = dis[x][y];
                deq.emplace_front(nx, ny);
            } else if (dir[k] != matrix[x][y] && 1 + dis[x][y] < dis[nx][ny]) {
                dis[nx][ny] = 1 + dis[x][y];
                deq.emplace_back(nx, ny);
            }
        }
    }

    return dis[end[0]][end[1]];
}   
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
