/*** 
 * @Author: Quarret
 * @Date: 2025-06-15 16:12:22
 * @LastEditTime: 2025-06-15 16:17:47
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int numberOfSubmatrices(vector<vector<char>>& grid) {
    int m = grid.size(), n = grid[0].size(), ans = 0;
    vector<vector<int>> sumx(m + 1, vector<int>(n + 1, 0)), sumy(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sumx[i + 1][j + 1] = sumx[i + 1][j] + sumx[i][j + 1] - sumx[i][j] + (grid[i][j] == 'X');
            sumy[i + 1][j + 1] = sumy[i + 1][j] + sumy[i][j + 1] - sumy[i][j] + (grid[i][j] == 'Y');

            if (sumx[i + 1][j + 1] && sumx[i + 1][j + 1] == sumy[i + 1][j + 1]) ans++;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
