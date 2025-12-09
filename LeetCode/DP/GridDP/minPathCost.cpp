#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
    int m = grid.size(), n = grid[0].size();
    vector f(m + 1, vector<int>(n + 1, INT32_MAX));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0) {
                f[i + 1][j + 1] = grid[i][j];
                continue;
            }
            for (int k = 0; k < n; k++) {
                f[i + 1][j + 1] = min(f[i + 1][j + 1], f[i][k + 1] + moveCost[grid[i -1][k]][j] + grid[i][j]);
            }
        }
    }

    return *min_element(f[m].begin() + 1, f[m].end());
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
