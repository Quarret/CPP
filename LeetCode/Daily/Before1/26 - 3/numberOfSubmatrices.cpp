#include <bits/stdc++.h>
using ll = long long;
using namespace std;


int numberOfSubmatrices(vector<vector<char>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector sum_x(m + 1, vector<int>(n + 1, 0));        
    vector sum_y(m + 1, vector<int>(n + 1, 0));        

    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sum_x[i + 1][j + 1] = sum_x[i + 1][j] + sum_x[i][j + 1] - sum_x[i][j] + (grid[i][j] == 'X');
            sum_y[i + 1][j + 1] = sum_y[i + 1][j] + sum_y[i][j + 1] - sum_y[i][j] + (grid[i][j] == 'Y');
            ans += sum_x[i + 1][j + 1] == sum_y[i + 1][j + 1] && sum_x[i + 1][j + 1];
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}