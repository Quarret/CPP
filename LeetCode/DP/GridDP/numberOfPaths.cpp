#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int numberOfPaths(vector<vector<int>>& grid, int k) {
    int m = grid.size(), n = grid[0].size(), MOD = 1e9 + 7, f[m + 1][n + 1][k];
    memset(f, 0, sizeof(f));
    // vector f(m + 1, vector(n + 1, vector<int>(k, 0)));
    
    f[0][1][0] = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int t = 0; t < k; t++) {
                int val = (t + grid[i][j]) % k;
                f[i + 1][j + 1][val] = (f[i + 1][j + 1][val] + f[i][j + 1][t]) % MOD;
                f[i + 1][j + 1][val] = (f[i + 1][j + 1][val] + f[i + 1][j][t]) % MOD;
            }
        }
    }

    return f[m][n][0];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
