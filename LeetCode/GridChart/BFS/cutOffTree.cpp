/*** 
 * @Author: Quarret
 * @Date: 2025-06-28 19:42:58
 * @LastEditTime: 2025-06-28 21:29:22
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<vector<int>> forest = {{1,2,3},{0,0,4},{7,6,5}};
int cutOffTree(vector<vector<int>>& forest) {
    int m = forest.size(), n = forest[0].size(), ans = 0;
    int next[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};

    auto cmp = [&](array<int, 3>& arr1, array<int, 3>& arr2) -> bool {
        return arr1[2] > arr2[2];
    };

    priority_queue<array<int, 3>, vector<array<int, 3>>, decltype(cmp)> pq(cmp);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (forest[i][j] > 1) {
                pq.push({i, j, forest[i][j]});
            }
        }
    }

    auto bfs = [&](int r, int c, int des) -> int {
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<array<int, 3>> q;
        q.push({r, c, forest[r][c]});
        vis[r][c] = 1;

        int d = 0;
        while (!q.empty()) {
            d++;

            int cnt = q.size();
            for (int t = 0; t < cnt; t++) {
                auto [x, y, h] = q.front();
                q.pop();
                if (h == des) return d;

                for (int k = 0; k < 4; k++) {
                    int nx = x + next[k][0];
                    int ny = y + next[k][1];

                    if (nx < 0 || nx >= m || ny < 0 || ny >= n || !forest[nx][ny] || vis[nx][ny]) continue;
                    q.push({nx, ny, forest[nx][ny]});
                    vis[nx][ny] = 1;
                }
            }
        }

        return -1;
    };

    int row = 0, col = 0;
    while (!pq.empty()) {
        auto [x, y, h] = pq.top();
        pq.pop();

        if (bfs(row, col, h) == -1) return -1;
        else ans += bfs(row, col, h);
        row = x, col = y;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cutOffTree(forest);

    return 0;
}
