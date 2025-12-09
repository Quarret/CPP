#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int lenOfVDiagonal(vector<vector<int>>& grid) {
    int dir[4][2] = {1, 1, 1, -1, -1, -1, -1, 1};
    int n = grid.size(), m = grid[0].size();
    vector memo(n, vector<array<array<int, 2>, 4>>(m));

    auto dfs = [&](this auto&& dfs, int i, int j, int k, bool can_turn, int val) -> int {
        int x = i + dir[k][0];
        int y = j + dir[k][1];

        if (x < 0 || x >= n || y < 0 || y >= m || grid[i][j] != val) return 0;

        int &res = memo[x][y][k][can_turn];
        if (res) return res;
        res = dfs(x, y, k, can_turn, 2 - val) + 1;//straight
        if (can_turn) res = max(res, dfs(x, y, (k + 1) % 4, false, 2 - val) + 1);//right turn

        return res;
    };

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                for (int k = 0; k < 4; k++) {
                    ans = max(dfs(i, j, k, true, 2) + 1, ans);
                }
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
