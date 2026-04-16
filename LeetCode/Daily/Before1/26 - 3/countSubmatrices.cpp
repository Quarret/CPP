#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int countSubmatrices(vector<vector<int>>& grid, int k) {
    int m = grid.size(), n = grid[0].size();
    vector sum(m + 1, vector<int>(n + 1, 0));

    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + grid[i][j];
            if (sum[i + 1][j + 1] <= k) ans++;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}