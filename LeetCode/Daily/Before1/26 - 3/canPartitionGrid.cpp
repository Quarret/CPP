#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool canPartitionGrid(vector<vector<int>>& grid) {
    using ll = long long;
    int m = grid.size(), n = grid[0].size();

    ll s = 0;
    vector sum(m + 1, vector<ll>(n + 1, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + grid[i][j];
            s += grid[i][j];
        }
    }

    for (int r = 0; r < m; r++) {
        if (s - sum[r + 1][n] == sum[r + 1][n]) return true;
    }
    
    for (int c = 0; c < n; c++) {
        if (s - sum[m][c + 1] == sum[m][c + 1]) return true;
    }

    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}