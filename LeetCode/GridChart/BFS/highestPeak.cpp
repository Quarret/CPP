/*** 
 * @Author: Quarret
 * @Date: 2025-06-23 21:42:50
 * @LastEditTime: 2025-06-23 21:48:49
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
    int m = isWater.size(), n = isWater[0].size(),d = 0;
    int next[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
    //可以利用原water数组来统计vis情况
    vector<vector<int>> vis(m, vector<int>(n, 0)), ans(m, vector<int>(n, 0));
    queue<pair<int, int>> q;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (isWater[i][j]) {
                vis[i][j] = 1;
                q.emplace(i, j);
            }
        }
    }

    while (!q.empty()) {
        d++;
        int cnt = q.size();

        for (int t = 0; t < cnt; t++) {
            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + next[k][0];
                int ny = y + next[k][1];

                if (nx < 0 || nx >= m || ny < 0 || ny >= n || vis[nx][ny]) continue;
                ans[nx][ny] = d;
                vis[nx][ny] = 1;
                q.emplace(nx, ny);
            }
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
