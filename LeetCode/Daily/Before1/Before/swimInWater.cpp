#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size();
    int nxt[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
    vector t(n, vector<int>(n, INT_MAX));
    
    auto cmp = [&](pair<int, int>& p1, pair<int, int>& p2) -> bool {
        return t[p1.first][p1.second] > t[p2.first][p2.second];
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

    pq.emplace(0, 0);
    t[0][0] = grid[0][0];


    while (!pq.empty()) {
        auto [x, y] = pq.top();
        pq.pop();

        for (auto [dx, dy] : nxt) {
            int nx = x + dx;
            int ny = y + dy;
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (grid[nx][ny] < t[nx][ny] && t[x][y] < t[nx][ny]) {
                t[nx][ny] = max(grid[nx][ny], t[x][y]);
                pq.emplace(nx, ny);
            }
        } 
    }

    return t[n - 1][n - 1];
}

int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size();
    int nxt[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
    vector dis(n, vector<int>(n, INT_MAX));
    
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

    pq.emplace(grid[0][0], 0, 0);
    dis[0][0] = grid[0][0];

    while (!pq.empty()) {
        auto [d, x, y] = pq.top();
        pq.pop();

        if (d > dis[x][y]) continue;

        if (x == n - 1 && y == n - 1) {
            return dis[x][y];
        }

        for (auto [dx, dy] : nxt) {
            int nx = x + dx;
            int ny = y + dy;

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            int new_dis = max(d, grid[nx][ny]);
            if (new_dis < dis[nx][ny]) {
                dis[nx][ny] = new_dis;
                pq.emplace(new_dis, nx, ny);
            }
        }
    }
}

// 二分
int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size();
    int nxt[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
    vector vis(n, vector<int>(n, 0));
    
    // 判断 grid[x][y] <= mx 的条件下是否可以到达终点
    auto check = [&](int mx) -> bool {
        auto dfs = [&](this auto&& dfs, int x, int y) -> bool {
            if (x == n - 1 && y == n - 1) {
                return true;
            }

            vis[x][y] = mx;

            for (auto [dx, dy] : nxt) {
                int nx = x + dx;
                int ny = y + dy;
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (grid[nx][ny] <= mx && vis[nx][ny] != mx && dfs(nx, ny)) {
                    return true;
                }
            }
            return false;
        };

        return dfs(0, 0);
    };

    int l = max(grid[0][0], grid[n - 1][n - 1]) - 1;
    int r = n * n - 1;
    while (l + 1 < r) {
        int mid = l + (r - l) / 2;
        (check(mid) ? r : l) = mid;
    }

    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
