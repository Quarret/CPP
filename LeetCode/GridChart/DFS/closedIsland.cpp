#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int closedIsland(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size(), flag = 1;

    auto dfs = [&](this auto&& dfs, int i, int j) -> void {
        if (i < 0 || i >= m || j < 0 || j >= n) {
            flag = 0;
            return;
        }
        if (grid[i][j] != 0) return;

        grid[i][j] = 2;

        dfs(i - 1, j);
        dfs(i + 1, j);
        dfs(i, j - 1);
        dfs(i, j + 1);
    };

    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0) {
                flag = 1;
                dfs(i, j);
                if (flag) ans++;
            }
        }
    }

    return ans;
}

int closedIsland(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size(), flag = 1;
    int nxt[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};

    auto dfs = [&](this auto&& dfs, int i, int j) -> void {
        grid[i][j] = 2;
        for (int k = 0; k < 4; k++) {
            int nxtx = i + nxt[k][0];
            int nxty = j + nxt[k][1];

            if (nxtx < 0 || nxtx >= m || nxty < 0 || nxty >= n) {
                flag = 0;
                continue;
            }

            if (grid[nxtx][nxty] != 0) continue;
            dfs(nxtx, nxty);
        }
    };

    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0) {
                flag = 1;
                dfs(i, j);
                if (flag) ans++;
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
