#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int numIslands(vector<vector<char>>& grid) {
    int m = grid.size(), n = grid[0].size();

    /*
    对于递归函数，想清楚写清楚每个函数内部要实现的功能即可
    剩下的交给计算机或者命运
    */
    auto dfs = [&](this auto&& dfs, int i, int j) -> void {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1') return;
        grid[i][j] = '2';
        dfs(i - 1, j);
        dfs(i + 1, j);
        dfs(i, j - 1);
        dfs(i, j + 1);
    };
    
    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1') {
                ans++;
                dfs(i, j);
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
