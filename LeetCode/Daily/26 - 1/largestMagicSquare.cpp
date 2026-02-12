#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int largestMagicSquare(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int mn = min(m, n);
    
    auto check = [&](int k) -> bool {
        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {
                vector<array<int, 2>> sum(k);
                int diag1 = 0, diag2 = 0;
                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + k; y++) {
                        sum[x - i][0] += grid[x][y];
                        sum[y - j][1] += grid[x][y];
                        if (x - i == y - j) diag1 += grid[x][y];
                        if ((x - i) + (y - j) == k - 1) diag2 += grid[x][y];    
                    }
                }

                int eq = sum[0][0], ok = 1;
                if (eq != diag1 || eq != diag2) ok = 0;
                for (auto &[sum_row, sum_col] : sum) {
                    if (!ok) break;
                    if (sum_row != eq || sum_col != eq) {
                        ok = 0;
                    }
                }

                if (ok) return true;
            }
        }

        return false;
    };

    int ans = 0;
    for (int r = 1; r <= mn; r++) {
        if (check(r)) ans = r;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}