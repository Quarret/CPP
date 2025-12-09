#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
    vector vis(m, vector<int>(n, 0));
    int nxt[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
    int cnt1 = walls.size();

    for (auto &e : walls) {
        int x = e[0], y = e[1];
        vis[x][y] = 1 << 4;
    }

    int cnt = 0;
    auto dfs = [&](this auto&& dfs, int x, int y, int dir) -> void {
        if (!vis[x][y]) cnt++;
        vis[x][y] |= 1 << dir;
        
        int nx = x + nxt[dir][0];
        int ny = y + nxt[dir][1];
        if (nx < 0 || nx >= m || ny < 0 || ny >= n || vis[nx][ny] == 16) {
            return;
        }
        if (vis[nx][ny] >> dir & 1) {
            return;
        }
        dfs(nx, ny, dir);
    };

    for (auto &guard : guards) {
        int x = guard[0], y = guard[1];
        for (int dir = 0; dir < 4; dir++) {
            if (vis[x][y] >> dir & 1) continue;
            dfs(x, y, dir);
        }
    }

    return m * n - cnt - cnt1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
