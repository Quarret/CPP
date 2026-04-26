#include <bits/stdc++.h>
using ll = long long;
using namespace std;


vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
    vector grid(n, vector<int>(m, 0));
    vector vis(n, vector<int>(m, 0));
    int nxt[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};

    queue<array<int, 3>> q;

    for (auto &e : sources) {
        int r = e[0], c = e[1], color = e[2];
        q.push({r, c, color});
        grid[r][c] = max(grid[r][c], color);
        vis[r][c] = 1e9;
    }

    int d = 0;
    while (!q.empty()) {
        int t = q.size();
        d++;

        for (int i = 0; i < t; i++) {
            auto [x, y, color] = q.front();
            q.pop();

            if (grid[x][y] != color) continue;

            for (auto &[dx, dy] : nxt) {
                int nx = x + dx;
                int ny = y + dy;

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (!vis[nx][ny] || (d == vis[nx][ny] && color > grid[nx][ny])) {
                    grid[nx][ny] = max(grid[nx][ny], color);
                    vis[nx][ny] = d;
                    q.push({nx, ny, color});
                }

            }
        }
    }

    return grid;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}