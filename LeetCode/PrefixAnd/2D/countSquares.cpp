/*** 
 * @Author: Quarret
 * @Date: 2025-06-16 11:46:47
 * @LastEditTime: 2025-06-16 12:11:52
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int countSquares(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> sum(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + matrix[i][j];
        }
    }

    int ans = 0;
    // for (int r = 0; r < n; r++) {
    //     for (int i = 0; i < m; i++) {
    //         for (int j = 0; j < n; j++) {
    //             if (i + r >= m || j + r >= n) continue;
    //             if (sum[i + r + 1][j + r + 1] - sum[i + r + 1][j] - sum[i][j + r + 1] + sum[i][j] == (r + 1) * (r + 1)) ans++;
    //         }
    //     }
    // }

    
    // for (int i = 0; i < m; i++) {
    //     for (int j = 0; j < n; j++) {
    //         for (int r = 0; r < min(m - i, n - j); r++) {
    //             if (sum[i + r + 1][j + r + 1] - sum[i + r + 1][j] - sum[i][j + r + 1] + sum[i][j] == (r + 1) * (r + 1)) ans++;
    //         }
    //     }
    // }

    //由于找寻以(i, j)为左端点的正方形具有单调性，l1 > l2,若无l1正方形，则必定无l2正方形
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int l = -1, r = min(m - i - 1, n - j - 1) + 1, mid = 0;
            while (l + 1 < r) {
                mid = l + (r - l) / 2;
                if (sum[i + mid + 1][j + mid + 1] - sum[i + mid + 1][j] - sum[i][j + mid + 1] + sum[i][j] == (mid + 1) * (mid + 1)) l = mid;
                else r = mid;
            }
            ans += l + 1;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
