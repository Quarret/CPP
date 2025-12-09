#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// 记忆化搜索
int countCoprime(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size(), MOD = 1e9 + 7;
    int maxx = -1;
    for (auto rows : mat) {
        maxx = max(maxx, ranges::max(rows));        
    }

    vector memo(m, vector<int>(maxx + 1, -1));
    auto dfs = [&](this auto&& dfs, int i, int g) -> int {
        if (i < 0) {
            return g == 1;
        }

        int &res = memo[i][g];
        if (res != -1) {
            return res;
        }
        res = 0;
        for (int x : mat[i]) {
            res = (res + dfs(i - 1, gcd(g, x))) % MOD;
        }
        
        return res;
    };

    return dfs(m - 1,  0);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
