/*** 
 * @Author: Quarret
 * @Date: 2025-05-15 09:25:24
 * @LastEditTime: 2025-06-04 17:04:47
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long numberOfRightTriangles(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    long long ans = 0;
    vector<int> row(n, 0), col(m, 0);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j]) {
                row[i]++;
                col[j]++;
            }
        }
    }

    //枚举直角顶点
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j]) {
                ans += 1LL * (row[i] - 1) * (col[j] - 1);
            }
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
