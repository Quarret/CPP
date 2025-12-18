#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
    string low_s = to_string(start);
    string high_s = to_string(finish);
    int n = high_s.size();
    int diff_lh = n - low_s.size();
    int diff = n - s.size();
    
    vector<long long> memo(n, -1);
    auto dfs = [&](this auto&& dfs, int i, bool limit_low, bool limit_high) -> long long {
        if (i == n) {
            return 1;
        }

        if (!limit_low && !limit_high && memo[i] != -1) {
            return memo[i];
        }

        // 在这里不进行 min/max
        int lo = limit_low && i >= diff_lh ? low_s[i - diff_lh]  - '0' : 0;
        int hi = limit_high ? high_s[i] - '0' : 9;

        long long res = 0;
        if (i < diff) {
            for (int d = lo; d <= min(hi, limit); d++) {
                res += dfs(i + 1, limit_low && d == lo, limit_high && d == hi);
            }
        } else {
            int x = s[i - diff] - '0';
            if (lo <= x && x <= hi) {
                res += dfs(i + 1, limit_low && x == lo, limit_high && x == hi);
            }
        }

        if (!limit_low && !limit_high) {
            memo[i] = res;
        }
        return res;
    };

    return dfs(0, true, true);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
