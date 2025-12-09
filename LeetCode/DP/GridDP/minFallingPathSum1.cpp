#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minFallingPathSum(vector<vector<int>>& grid) {
    int n = grid[0].size();
    vector f(n + 1, vector<int>(n + 1, INT32_MAX));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (i == 0) {
                    f[i + 1][j + 1] = grid[i][j];
                    continue;
                }
                if (k == j) continue;
                f[i + 1][j + 1] = min(f[i + 1][j + 1], f[i][k + 1] + grid[i][j]);
            }
        }
    }

    return *min_element(f[n].begin(), f[n].end());
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
