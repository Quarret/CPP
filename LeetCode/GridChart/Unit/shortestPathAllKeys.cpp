/*** 
 * @Author: Quarret
 * @Date: 2025-07-03 09:34:09
 * @LastEditTime: 2025-07-03 10:10:37
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<string> grid = {"@Aa"};
int shortestPathAllKeys(vector<string>& grid) {
    int m = grid.size(), n = grid[0].size(), sx, sy, ans = 0;
    int next[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
    vector vis(m, vector(n, vector<int>(64, 0)));
    vector idx(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '@') {
                sx = i;
                sy = j;
            } else if (islower(grid[i][j])) {
                idx[i][j] = 1 << (grid[i][j] - 'a');
                ans |= 1 << (grid[i][j] - 'a');
            }
        }
    }

    queue<tuple<int, int, int>> q;
    q.emplace(sx, sy, 0);
    vis[sx][sy][0] = 1;

    int d = 0;
    while (!q.empty()) {
        d++;
        int cnt = q.size();

        for (int t = 0; t < cnt; t++) {
            auto [x, y, key] = q.front();
            q.pop();

            if (key == ans) return d - 1;

            for (auto& [dx, dy]: next) {
                int nx = x + dx;
                int ny = y + dy;
                int nkey = key;

                if (nx < 0 || nx>= m || ny < 0 || ny >= n || grid[nx][ny] == '#') continue;
                if (isupper(grid[nx][ny])) {
                    if (((nkey >> (grid[nx][ny] - 'A')) & 1) != 1) continue;
                }
                nkey = key | idx[nx][ny];
                if (vis[nx][ny][nkey]) continue;
                q.emplace(nx, ny, nkey);
                vis[nx][ny][nkey] = 1;
            }
        }
    }

    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    shortestPathAllKeys(grid);

    return 0;
}
