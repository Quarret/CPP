#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int trapRainWater(vector<vector<int>>& heightMap) {
    int m = heightMap.size(), n = heightMap[0].size();
    vector prerow(m, vector<int>(n, 0)), precol(m, vector<int>(n, 0));
    vector sufrow(m, vector<int>(n, 0)), sufcol(m, vector<int>(n, 0));
    vector val(m, vector<int>(n, 0));


    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            precol[i][j] = j == 0 ? 0 : max(precol[i][j - 1], heightMap[i][j - 1]);
            prerow[i][j] = i == 0 ? 0 : max(prerow[i - 1][j], heightMap[i - 1][j]);
        }
    }

    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            sufcol[i][j] = j == n - 1 ? 0 : max(sufcol[i][j + 1], heightMap[i][j + 1]);
            sufrow[i][j] = i == m - 1 ? 0 : max(sufrow[i + 1][j], heightMap[i + 1][j]);
            val[i][j] = min({precol[i][j], prerow[i][j], sufcol[i][j], sufrow[i][j]}); // 水位
        }
    }
    
    // 同一连通块里的水位要按最小的来算
    vector<int> height = {0};
    int idx = 1;
    int nxt[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
    vector vis(m, vector<int>(n, 0));
    auto dfs = [&](this auto&& dfs, int i, int j) -> void {
        vis[i][j] = idx;
        height[idx] = min(height[idx], val[i][j]);

        for (int k = 0; k < 4; k++) {
            int x = i + nxt[k][0];
            int y = j + nxt[k][1];

            if (x < 0 || x >= m || y < 0 || y >= n || vis[x][y] || (val[x][y] - heightMap[x][y]) <= 0) continue;
            dfs(x, y);
        }
    };

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if ((val[i][j] - heightMap[i][j]) > 0 && !vis[i][j]) {
                height.push_back(1e9);
                dfs(i, j);
                idx++;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j]) {
                int k = vis[i][j];
                if (height[k] - heightMap[i][j]) {
                    ans += height[k] - heightMap[i][j];
                }
            }
        }
    }

    return ans;
}

int trapRainWater(vector<vector<int>>& heightMap) {
    int m = heightMap.size(), n = heightMap[0].size();
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                pq.emplace(heightMap[i][j], i, j);
                heightMap[i][j] = -1;
            }
        }
    }
    
    int nxt[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
    int ans = 0;
    while (!pq.empty()) {
        auto [min_height, i, j] = pq.top();
        pq.pop();

        for (auto [dx, dy] : nxt) {
            int x = i + dx;
            int y = j + dy;
            if (x < 0 || x >= m || y < 0 || y >= n || heightMap[x][y] < 0) continue;

            // 比外围最短板小, 可以存水
            ans += max(min_height - heightMap[x][y], 0);

            // 比外围最短板大, 代替最短板
            // 比外围最短板小, 填水泥成为最短板
            pq.emplace(max(min_height, heightMap[x][y]), x, y);

            heightMap[i][j] = -1;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
