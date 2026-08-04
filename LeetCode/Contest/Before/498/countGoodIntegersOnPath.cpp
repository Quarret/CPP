#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long countGoodIntegersOnPath(long long l, long long r, string directions) {
    using ll = long long;
    
    string low_s = to_string(l);
    string high_s = to_string(r);
    int n = high_s.size();
    int diff_lh = n - low_s.size();

    vector in_path(n, 0);
    int pos = n - 16;
    for (char c : directions) {
        if (pos >= 0) in_path[pos] = 1;
        pos += c == 'D' ? 4 : 1;
    }
    in_path[n - 1] = 1;

    vector memo(n, vector(10, -1LL));
    auto dfs = [&](this auto&& dfs, int i, int pre, bool limit_low, bool limit_high) -> ll {
        if (i == n) {
            return 1;
        }

        if (!limit_low && !limit_high && memo[i][pre] != -1) {
            return memo[i][pre];
        }

        int lo = limit_low && i >= diff_lh ? low_s[i - diff_lh] - '0' : 0;
        int hi = limit_high ? high_s[i] - '0' : 9;
        
        ll res = 0;
        int start = in_path[i] ? max(lo, pre) : lo;
        for (int d = start; d <= hi; d++) {
            res += dfs(i + 1, in_path[i] ? d : pre, limit_low && d == lo, limit_high && d == hi);
        }

        if (!limit_low && !limit_high) {
            memo[i][pre] = res;
        }
        return res;
    };

    return dfs(0, 0, true, true);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}