/*** 
 * @Author: Quarret
 * @Date: 2025-06-16 16:03:18
 * @LastEditTime: 2025-06-16 16:14:05
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int numSubmat(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> sum(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + mat[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int row = 0; row < m - i; row++) {
                int left = -1, right = n - j, mid = 0;
                while (left + 1 < right) {
                    mid = left + (right - left) / 2;
                    int res = sum[i + row + 1][j + mid + 1] - sum[i + row + 1][j] - sum[i][j + mid + 1] + sum[i][j];
                    if (res == (row + 1) * (mid + 1)) left = mid;
                    else right = mid;
                }
                ans += left + 1;
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
