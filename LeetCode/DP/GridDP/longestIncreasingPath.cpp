#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int longestIncreasingPath(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector memo(m, vector<int>(n));
    int next[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
    
    auto dfs = [&](this auto&& dfs, int x, int y, int val) -> int {
        if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] <= val) return 0;

        int &res = memo[x][y];
        if (res) return res;
        for (int t = 0; t < 4; t++) {
            int nx = x + next[t][0];
            int ny = y + next[t][1];

            res = max(res, dfs(nx, ny, matrix[x][y]) + 1);
        }

        return res;
    };

    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            ans = max(ans, dfs(i, j, -1));
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
