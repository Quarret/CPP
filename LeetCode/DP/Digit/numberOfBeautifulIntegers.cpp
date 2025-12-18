#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int numberOfBeautifulIntegers(int low, int high, int k) {
    string low_s = to_string(low);
    string high_s = to_string(high);
    int n = high_s.size();
    int diff_lh = n - low_s.size();
    
    vector<int> pow10(n, 1);
    for (int i = n - 2; i >= 0; i--) {
        pow10[i] = (pow10[i + 1] * 10) % k;
    }

    vector memo(n, vector<int>(1 << 12, -1));
    auto dfs = [&](this auto&& dfs, int i, int cnt, int res, bool limit_low, bool limit_high) -> int {
        if (i == n) {
            return cnt == 0 && res == 0;
        }

        // cnt 可能为负, 加一个 offset
        int mask = ((cnt + n) << 5) | res;
        if (!limit_low && !limit_high && memo[i][mask] != -1) {
            return memo[i][mask];
        }

        int lo = limit_low && i >= diff_lh ? low_s[i - diff_lh] - '0' : 0;
        int hi = limit_high ? high_s[i] - '0' : 9;
        int d = lo;

        int ans = 0;
        // 处理前导 0 的逻辑, 贴合 low 的边界且在前导 0 区
        if (limit_low && i < diff_lh) {
            ans += dfs(i + 1, cnt, res, true, false);
            d = 1;
        }

        for (; d <= hi; d++) {
            // cnt += (d % 2 ? 1 : -1);
            ans += dfs(i + 1, cnt + (d % 2 ? 1 : -1), (res + pow10[i] * d) % k, limit_low && d == lo, limit_high && d == hi);
        }

        if (!limit_low && !limit_high) {
            memo[i][mask] = ans;
        }
        return ans;
    };

    return dfs(0, 0, 0, true, true);
} 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
