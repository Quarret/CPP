#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector f(m + 1, vector<int>(n + 1, INT_MAX));
    
    f[0][1] = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            f[i + 1][j + 1] = min(f[i][j + 1], f[i + 1][j]) + grid[i][j];
        }
    }

    return f[m][n];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
