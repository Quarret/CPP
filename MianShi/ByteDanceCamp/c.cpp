#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve() {
    int n, m, k;
    int nxt[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
    cin >> n >> m >> k;

    vector grid(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int x1, y1, x2, y2, EX, EY;
    int ans1 = INT_MAX, ans2 = INT_MAX;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--, y1--, x2--, y2--;
    cin >> EX >> EY;
    EX--, EY--;

    deque<tuple<int, int, int>> q;
    q.emplace_back(EX, EY, 0);
    vector vis(n, vector<int>(m, INT_MAX / 2));

    while (!q.empty()) {
        auto [x, y, dis] = q.front();
        q.pop_front();

        if (x == x1 && y == y1) {
            ans1 = min(dis, ans1);
        }

        if (x == x2 && y == y2) {
            ans2 = min(dis, ans2);
        }

        if (ans1 == 0 && ans2 == 0) {
            break;
        }

        for (auto [dx, dy] : nxt) {
            int nx = x + dx;
            int ny = y + dy;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            int cost = abs(grid[x][y] - grid[nx][ny]) <= k ? 0 : 6;
            if (dis + cost < vis[nx][ny]) {
                vis[nx][ny] = dis + cost;
                if (cost != 0) q.emplace_back(nx, ny, dis + cost);
                else q.emplace_front(nx, ny, dis);
            }
        }
    }

    cout << ans1 << ' ' << ans2 << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
