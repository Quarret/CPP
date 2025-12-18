#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int countSteppingNumbers(string low, string high) {
    int n = high.size(), MOD = 1e9 + 7;
    int diff_lh = n - low.size();
    
    vector memo(n, vector<int>(10, -1));
    auto dfs = [&](this auto&& dfs, int i, int pre, bool limit_low, bool limit_high) -> int {
        if (i == n) {
            return 1;
        }

        if (!limit_low && !limit_high && memo[i][pre] != -1) {
            return memo[i][pre];
        }

        int lo = limit_low && i >= diff_lh ? low[i - diff_lh] - '0' : 0;
        int hi = limit_high ? high[i] - '0' : 9;
        int d = lo;

        int res = 0;
        // 贴近 low 但在前导 0 区域, 特殊化一开始进入 dfs 的就是 0 区域, 此时的 limit_low 为 true
        if (limit_low && i < diff_lh) {
            res = (res + dfs(i + 1, pre, true, false)) % MOD;
            d = 1;
        }

        for (; d <= hi; d++) {
            if (pre == -1) res = (res + dfs(i + 1, d, limit_low && d == lo, limit_high && d == hi)) % MOD;
            else {
                if (abs(d - pre) == 1) {
                    res = (res + dfs(i + 1, d, limit_low && d == lo, limit_high && d == hi)) % MOD;
                }
            }
        }

        if (!limit_low && !limit_high) {
            memo[i][pre] = res;
        }
        return res;
    };

    return dfs(0, -1, true, true);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
