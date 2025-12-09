/*** 
 * @Author: Quarret
 * @Date: 2025-06-16 10:07:15
 * @LastEditTime: 2025-06-16 10:15:07
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> sum(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + (matrix[i][j] == '1');
        }
    }
    
    int r = 0, flag = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i + r >= m || j + r >= n) {
                continue;
            } 

            int res = sum[i + r + 1][j + r + 1] - sum[i + r + 1][j] - sum[i][j + r + 1] + sum[i][j];
            if (res != (r + 1) * (r + 1)) continue;

            flag = 1;

            while (1) {
                if (i + r >= m || j + r >= n) {
                    r--;
                    break;
                } 

                int res = sum[i + r + 1][j + r + 1] - sum[i + r + 1][j] - sum[i][j + r + 1] + sum[i][j];
                if (res != (r + 1) * (r + 1)) {
                    r--;
                    break;
                } else r++;
            }
        }
    }

    return (flag ? (r + 1) * (r + 1) : 0);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
