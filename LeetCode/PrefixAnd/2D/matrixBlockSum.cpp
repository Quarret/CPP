/*** 
 * @Author: Quarret
 * @Date: 2025-06-13 19:02:31
 * @LastEditTime: 2025-06-14 21:03:53
 */

#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> pre(m, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            pre[i][j + 1] = pre[i][j] + mat[i][j];
        }
    }

    vector<vector<int>> ans(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int row1 = max(i - k, 0), row2 = min(i + k, m - 1);
            int col1 = max(j - k, 0), col2 = min(j + k, n - 1);
            for (int r = row1; r <= row2; r++) {
                ans[i][j] += pre[r][col2 + 1] - pre[r][col1];
            }
        }
    }

    return ans;

}


/*
灵神2维前缀和写法:
sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j = 1] - sum[i][j] + mat[i][j];
求[r1, c1] 与[r2, c2]成对角的矩阵前缀和
sum = sum[r2 + 1][c2 + 1] - sum[r2 + 1][c1] - sum[r1][c2 + 1] + sum[r1][c1]
*/

vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> sum(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + mat[i][j];
        }
    }

    vector<vector<int>> ans(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int row1 = max(i - k, 0), row2 = min(i + k, m - 1);
            int col1 = max(j - k, 0), col2 = min(j + k, n - 1);
            ans[i][j] = sum[row2 + 1][col2 + 1] - sum[row2 + 1][col1] - sum[row1][col2 + 1] + sum[row1][col1];
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
