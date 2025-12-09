#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector f(m + 1, vector<int>(n + 1));
    
    f[0][1] = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (obstacleGrid[i][j]) {
                f[i][j] = 0;
                continue;
            }
            f[i + 1][j + 1] = f[i][j + 1] + f[i + 1][j];
        }
    }

    return f[m][n];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
