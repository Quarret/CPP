#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maximumAmount(vector<vector<int>>& coins) {
    int m = coins.size(), n = coins[0].size();
    int inf = -1e9;
    vector f(m + 1, vector<array<int, 3>>(n + 1, {inf, inf, inf}));
    
    f[0][1][0] = f[0][1][1] = f[0][1][2] = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int val = coins[i][j];
            if (val >= 0) {
                f[i + 1][j + 1][0] = max(f[i + 1][j][0], f[i][j + 1][0]) + val;
                f[i + 1][j + 1][1] = max(f[i + 1][j][1], f[i][j + 1][1]) + val; 
                f[i + 1][j + 1][2] = max(f[i + 1][j][2], f[i][j + 1][2]) + val; 
            } else {
                f[i + 1][j + 1][0] = max({f[i + 1][j][0] + val, f[i][j + 1][0] + val, f[i + 1][j][1], f[i][j + 1][1]});
                f[i + 1][j + 1][1] = max({f[i + 1][j][1] + val, f[i][j + 1][1] + val, f[i + 1][j][2], f[i][j + 1][2]});
                f[i + 1][j + 1][2] = max(f[i + 1][j][2], f[i][j + 1][2]) + val;
            }
        }
    }

    return max({f[m][n][0], f[m][n][1], f[m][n][2]});
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
