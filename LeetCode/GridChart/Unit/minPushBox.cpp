#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minPushBox(vector<vector<char>>& grid) {
    int m = grid.size(), n = grid[0].size(), sx = 0, sy = 0;
    int next1[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1}, next2[4][2] = {1, 0, -1, 0, 0, -1, 0, 1};
    vector vis(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 'B') {
                sx = i;
                sy = j;
            }
        }
    } 

    queue<pair<int, int>> q;
    q.emplace(sx, sy);
    vis[sx][sy] = 1;

    int d = 0;
    while (!q.empty()) {
        d++;
        int cnt = q.size();

        for (int t = 0; t < cnt; t++) {
            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx1 = x + next1[k][0];
                int ny1 = y + next1[k][1];
                int nx2 = x + next2[k][0];
                int ny2 = y + next2[k][1];

                if (nx1 < 0 || nx1 >= m || ny1 < 0 || ny1 >= n || nx2 < 0 || nx2 >= m || ny2 < 0 || ny2 >= n) continue;
                if (grid[nx1][ny1] == '#' || grid[nx2][ny2] == '#' || vis[nx1][ny1]) continue;
                q.emplace(nx1, ny1);
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
