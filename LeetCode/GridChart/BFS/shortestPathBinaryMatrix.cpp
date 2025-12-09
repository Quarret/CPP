/*** 
 * @Author: Quarret
 * @Date: 2025-06-22 20:59:59
 * @LastEditTime: 2025-06-22 21:09:28
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    int next[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

    if (grid[0][0]) return -1;
    if (n == 1 & !grid[0][0]) return 1;

    queue<tuple<int, int, int>> q;
    q.emplace(0, 0, 1);
    grid[0][0] = 1;
    

    while (!q.empty()) {
        auto [x, y, cnt] = q.front();
        q.pop();

        for (int k = 0; k < 8; k++) {
            int nx = x + next[k][0];
            int ny = y + next[k][1];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n || grid[nx][ny] == 1) continue;
            if (nx == n - 1 && ny == n - 1) return cnt + 1;
            grid[nx][ny] = 1;
            q.emplace(nx, ny, cnt + 1);
        }
    }

    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
