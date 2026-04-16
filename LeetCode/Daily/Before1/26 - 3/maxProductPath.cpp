#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maxProductPath(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    const int MOD = 1e9 + 7;

    vector f_min(m + 1, vector<long long>(n + 1, 1));    
    vector f_max(m + 1, vector<long long>(n + 1, 1));
    // f[i][j] = max(f[i - 1][j], f[i][j - 1]) * grid[i][j]
    
    f_min[1][1] = f_max[1][1] = grid[0][0];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int x = grid[i][j];
            if (i == 0 && j == 0) continue;
            if (i == 0) {
                f_min[i + 1][j + 1] = min(f_min[i + 1][j] * x, f_max[i + 1][j] * x);
                f_max[i + 1][j + 1] = max(f_min[i + 1][j] * x, f_max[i + 1][j] * x);
                continue;
            }
            if (j == 0) {
                f_min[i + 1][j + 1] = min(f_min[i][j + 1] * x, f_max[i][j + 1] * x);
                f_max[i + 1][j + 1] = max(f_min[i][j + 1] * x, f_max[i][j + 1] * x);
                continue;
            }

            f_min[i + 1][j + 1] = min({f_min[i + 1][j] * x, f_max[i + 1][j] * x, 
                                        f_min[i][j + 1] * x, f_max[i][j + 1] * x});
            
            f_max[i + 1][j + 1] = max({f_min[i + 1][j] * x, f_max[i + 1][j] * x, 
                                        f_min[i][j + 1] * x, f_max[i][j + 1] * x});
        }
    }    

    return f_max[m][n] >= 0 ? f_max[m][n] % MOD : -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}