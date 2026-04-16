#include <bits/stdc++.h>
using ll = long long;
using namespace std;



vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector p(m, vector<long long>(n, 1));
    const int MOD = 12345;

    long long suf = 1;
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            p[i][j] = suf;
            suf = 1LL * suf * grid[i][j] % MOD;
        }
    }

    long long pre = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int x = grid[i][j];
            grid[i][j] = 1LL * pre * p[i][j] % MOD;
            pre = pre * x % MOD;
        }
    }

    return grid;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}