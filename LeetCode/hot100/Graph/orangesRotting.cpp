#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size(), sum = 0, cnt = 0;
    int next[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
    vector vis(m, vector<int>(n, 0));
    queue<pair<int, int>> q;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) q.emplace(i, j);
            if (grid[i][j] != 0) sum++;
        }
    }

    if (sum == 0) return 0;

    int d = 0;
    while (!q.empty()) {
        d++;
        
        int t = q.size();
        for (int i = 0; i < t; i++) {
            auto [x, y] = q.front();
            q.pop();

            cnt++;

            for (auto &[dx, dy] : next) {
                int nx = x + dx;
                int ny = y + dy;

                if (nx < 0 || nx >= m || ny < 0 || ny >= n || vis[nx][ny]) continue;
                if (grid[nx][ny] == 1) {
                    vis[nx][ny] = 1;
                    q.emplace(nx, ny);
                } 
            }
        }
    }

    return cnt == sum ? d - 1 : -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
