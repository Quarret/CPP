#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size(), num = 0, d = 0;
    int next[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
    vector<vector<int>> vis(m, vector<int>(n, 0));
    queue<pair<int, int>> q;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                vis[i][j] = 1;
                q.emplace(i, j);
            } else if (grid[i][j] == 1) num++;
        }
    }

    if (num == n * m) return -1;
    if (num == 0) return 0;

    while (!q.empty()) {
        d++;
        int cnt = q.size();
        for (int t = 0; t < cnt; t++) {
            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + next[k][0];
                int ny = y + next[k][1];

                if (nx < 0 || nx >= m || ny < 0 || ny >= n || vis[nx][ny] || !grid[nx][ny]) continue;
                num--;
                vis[nx][ny] = 1;
                q.emplace(nx, ny);
            }
        }
    }

    return num ? -1 : d - 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
