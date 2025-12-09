#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maxProductPath(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size(), MOD = 1e9 + 7;
    vector f0(m + 1, vector<long long>(n + 1, 1));
    vector f1(m + 1, vector<long long>(n + 1, 1));
    
    f0[1][1] = f1[1][1] = grid[0][0];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int val = grid[i][j];
            if (i == 0 && j == 0) continue;
            if (i == 0) {
                f0[i + 1][j + 1] = min(f0[i + 1][j] * val, f1[i + 1][j] * val);
                f1[i + 1][j + 1] = max(f0[i + 1][j] * val, f1[i + 1][j] * val);
                continue;
            } else if (j == 0) {
                f0[i + 1][j + 1] = min(f0[i][j + 1] * val, f1[i][j + 1] * val);
                f1[i + 1][j + 1] = max(f0[i][j + 1] * val, f1[i][j + 1] * val);
                continue;
            }

            f0[i + 1][j + 1] = min({f0[i + 1][j] * val, f1[i + 1][j] * val, f0[i][j + 1] * val, f1[i][j + 1] * val});
            f1[i + 1][j + 1] = max({f0[i + 1][j] * val, f1[i + 1][j] * val, f0[i][j + 1] * val, f1[i][j + 1] * val});
        }
    }

    return f1[m][n] >= 0 ? f1[m][n] % MOD : -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
