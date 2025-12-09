#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool hasValidPath(vector<vector<char>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector f(m + 1, vector<unordered_set<int>>(n + 1));
    
    // if (grid[m - 1][n - 1] == ')') return false;
    
    f[m][n - 1].insert(0);
    f[m - 1][n].insert(0);
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            for (auto &x : f[i + 1][j]) {
                int val = x + (grid[i][j] == ')' ? 1 : -1);
                if (val >= 0) f[i][j].insert(val);
            }

            for (auto &x : f[i][j + 1]) {
                int val = x + (grid[i][j] == ')' ? 1 : -1);
                if (val >= 0) f[i][j].insert(val);
            }
        }
    }

    return f[0][0].contains(0);
}

// c - balance dig left 1 right -1
//dfs + cut
//注意到这个字符串最多m + n - 1长度
//合法字符串最多c = m + n - 1 / 2的长度
//创建memo[m][n][c + 1],利用dfs遍历里面的状态并且剪枝
bool hasValidPath(vector<vector<char>>& grid) {
    int m = grid.size(), n = grid[0].size();
    if ((m + n) % 2 == 0 || grid[m - 1][n - 1] == '(' || grid[0][0] == ')') return false;

    // bool vis[m][n][(m + n + 1) / 2];
    // memset(vis, 0, sizeof(vis));

    vector vis(m, vector(n, vector<int>((m + n + 1) / 2, 0)));

    auto dfs = [&](this auto&& dfs, int x, int y, int c) -> bool {
        if (c > m - x + n - y - 1) return false;

        if (x == m - 1 && y == n - 1 && c == 1) return true;

        if (vis[x][y][c]) return false;
        vis[x][y][c] = true;

        c += grid[x][y] == '(' ? 1 : -1; 
        return c >= 0 && ((x + 1 < m && dfs(x + 1, y, c)) || (y + 1 < n && dfs(x, y + 1, c)));
    };

    return dfs(0, 0, 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
