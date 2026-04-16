#include <bits/stdc++.h>
using ll = long long;
using namespace std;


int numberOfStableArrays(int zero, int one, int limit) {
    const int MOD = 1e9 + 7;
    vector memo(zero + 1, vector<array<int, 2>>(one + 1, {-1, -1}));
    
    auto dfs = [&](this auto&& dfs, int i, int j, int k) -> int {
        if (i == 0) {
            // i + j 上要填入 1, 并且连续 1 的个数不会超过 limit
            return k == 1 && j <= limit;
        }
        if (j == 0) {
            return k == 0 && i <= limit;
        }

        int &res = memo[i][j][k];
        if (res != -1) {
            return res;
        }
        if (k == 0) {
            res = ((long long) dfs(i - 1, j, 0) + dfs(i - 1, j, 1) 
                    + (i > limit ? MOD - dfs(i - limit - 1, j, 1) : 0)) % MOD;
        } else {
            res = ((long long) dfs(i, j - 1, 0) + dfs(i, j - 1, 1) 
                + (j > limit ? MOD - dfs(i, j - limit - 1, 0) : 0)) % MOD;    
        }
        return res;
    };

    return (dfs(zero, one, 0) + dfs(zero, one, 1)) % MOD;
}

// 递推
int numberOfStableArrays(int zero, int one, int limit) {
    const int MOD = 1e9 + 7;
    vector f(zero + 1, vector(one + 1, array<int, 2>{0, 0}));
    for (int i = 1; i <= min(limit, zero); i++) {
        f[i][0][0] = 1;
    }
    for (int j = 1; j <= min(limit, one); j++) {
        f[0][j][1] = 1;
    }

    for (int i = 1; i <= zero; i++) {
        for (int j = 1; j <= one; j++) {
            f[i][j][0] = ((long long) f[i - 1][j][0] + f[i - 1][j][1] 
                            + (i > limit ? MOD - f[i - limit - 1][j][1] : 0)) % MOD;
            f[i][j][1] = ((long long) f[i][j - 1][0] + f[i][j - 1][1] 
                            + (j > limit ? MOD - f[i][j - limit - 1][0] : 0)) % MOD;
        }
    }

    return (f[zero][one][0] + f[zero][one][1]) % MOD;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}