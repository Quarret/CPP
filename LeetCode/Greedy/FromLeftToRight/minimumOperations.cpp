#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int minimumOperations(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    
    int ans = 0;
    for (int j = 0; j < n; j++) {
        for (int i = 1; i < m; i++) {
            ans += max((grid[i - 1][j] + 1) - grid[i][j], 0);
            grid[i][j] = max(grid[i - 1][j] + 1, grid[i][j]);
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
