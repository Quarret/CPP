#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int m = heights.size(), n = heights[0].size();
    int nxt[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
    vector vis(m, vector<int>(n, 0));

    int idx = 1;
    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++) {
        vis[i][0] = idx;
        q.emplace(i, 0);
    }
    for (int j = 0; j < n; j++) {
        vis[0][j] = idx;
        q.emplace(0, j);
    }
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (auto [dx, dy] : nxt) {
            int nx = x + dx;
            int ny = y + dy;
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || vis[nx][ny]) continue;
            if (heights[x][y] > heights[nx][ny]) continue;
            vis[nx][ny] = idx;
            q.emplace(nx, ny);
        }
    }

    vector<vector<int>> ans;
    idx = 2;
    for (int i = 0; i < m; i++) {
        if (vis[i][n - 1]) ans.push_back({i, n - 1});
        vis[i][n - 1] = idx;
        q.emplace(i, n - 1);
    }
    for (int j = 0; j < n; j++) {
        if (j == n - 1) continue;
        if (vis[m - 1][j]) ans.push_back({m - 1, j});
        vis[m - 1][j] = idx;
        q.emplace(m - 1, j);
    }

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (auto [dx, dy] : nxt) {
            int nx = x + dx;
            int ny = y + dy;
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (vis[nx][ny] == 2 || heights[x][y] > heights[nx][ny]) continue;
            if (vis[nx][ny] == 1) ans.push_back({nx, ny});
            vis[nx][ny] = idx;

            q.emplace(nx, ny);
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
