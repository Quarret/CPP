#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool canPartitionGrid(vector<vector<int>>& grid) {
    using ll = long long;
    int m = grid.size(), n = grid[0].size();

    if (m == 0 || n == 0) {
        ll pre = 0;
        unordered_map<int, int> mp;
        for (ll x : grid[0]) {
            pre += x;
            if (pre % 2 == 0 && mp[pre / 2]) return true;
        }
        
        pre = 0;
        mp.clear();
        for (auto &row : grid) {
            pre += row[0];
            if (pre % 2 == 0 && mp[pre / 2]) return true;
        }

        return false;
    }
    
    vector sum(m + 1, vector(n + 1, 0LL));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + grid[i][j];
        }
    }

    // 枚举删除点
    int s = sum[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            ll s1 = -1;
            // 上
            s1 = s - sum[i][n];
            if (i == m - 1 && (j != 0 && j != n - 1)) s1 = -1;
            if (s - s1 == s1 || s - s1 == s1 - grid[i][j]) return true;
            
            // 下
            s1 = sum[i + 1][n];
            if (i == 0 && (j != 0 && j != n - 1)) s1 = -1;
            if (s - s1 == s1 || s - s1 == s1 - grid[i][j]) return true;
            // cout << s1 << ' ';
            
            // 左
            s1 = s - sum[m][j];
            if (j == n - 1 && (i != 0 && i != m - 1)) s1 = -1;
            if (s - s1 == s1 || s - s1 == s1 - grid[i][j]) return true;

            // 右
            s1 = sum[m][j + 1];
            if (j == 0 && (i != 0 && i != m - 1)) s1 = -1;
            if (s - s1 == s1 || s - s1 == s1 - grid[i][j]) return true;
        }
    }

    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}