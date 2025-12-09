/*** 
 * @Author: Quarret
 * @Date: 2025-06-15 09:40:04
 * @LastEditTime: 2025-06-15 09:42:11
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int countSubmatrices(vector<vector<int>>& grid, int k) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> sum(n + 1, vector<int>(m + 1, 0));

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + grid[i][j];
            if (sum[i + 1][j + 1] <= k) ans++;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
