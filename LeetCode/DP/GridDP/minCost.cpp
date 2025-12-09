#include <bits/stdc++.h>
using ll = long long;
using namespace std;
long long minCost(int m, int n, vector<vector<int>>& waitCost) {
    vector f(m + 1, vector<long long>(n + 1, INT64_MAX));
    
    f[0][1] = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            f[i + 1][j + 1] = min(f[i][j + 1], f[i + 1][j]) + 1LL * (i + 1) * (j + 1) + 1LL * waitCost[i][j];
        }
    }

    return f[m][n] - 1LL * waitCost[0][0] - 1LL * waitCost[m - 1][n - 1];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
