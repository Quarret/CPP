#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector f(m + 1, vector<int>(n + 1, INT32_MAX));
    
    f[1][1] = grid[0][0];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) continue;
            f[i + 1][j + 1] = min(f[i][j + 1], f[i + 1][j]) + grid[i][j];
        }
    }

    return f[m][n];
}

//better Memory
//f[0][1] -> f[1][1] -> f[2][1], 每一列上每个数字只用了一次，故用一维数组记录即可
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<int> f(m + 1, INT32_MAX);

    for (auto &row : grid) {
        for (int j = 0; j < n; j++) {
            f[j + 1] = min(f[j], f[j + 1]) + row[j];//注意这两个f[j + 1]的不同,括号内的是原来的
        }
    }
} 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
