#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long countFancy(long long l, long long r) {
    static const int STATE_INIT = 0;
    static const int STATE_INC = 1;
    static const int STATE_DEC = 2;
    static const int STATE_NOT_GOOD = 3;

    // 判断数位和是否为好数
    auto is_good = [&](int s) -> bool {
        if (s < 100) {
            return s % 10 != s / 10;
        }
        // 1 开头的数字必增
        return  1 < s / 10 % 10 && s / 10 % 10 < s % 10;
    };

    using ll = long long;
    string low_s = to_string(l);
    string high_s = to_string(r);
    int n = high_s.size();
    int diff_lh = n - low_s.size();

    vector memo(n, vector<array<array<long long, 4>, 10>>(9 * n + 1));
    auto dfs = [&](this auto&& dfs, int i, int sum, int prev, int state, bool limit_low, bool limit_high) -> ll {
        if (i == n) {
            return state != STATE_NOT_GOOD || is_good(sum);
        }

        ll &ref = memo[i][sum][prev][state];
        if (!limit_low && !limit_high && ref) {
            return ref - 1;
        }

        int lo = limit_low && i >= diff_lh ? low_s[i - diff_lh] - '0' : 0;
        int hi = limit_high ? high_s[i] - '0' : 9;

        ll res = 0;
        int d = lo;

        // 状态机 DP
        for (; d <= hi; d++) {
            int new_state = state;
            switch (state) {
                case STATE_INIT:
                    if (prev > 0) {
                        if (d > prev) {
                            new_state = STATE_INC;
                        } else if (d < prev) {
                            new_state = STATE_DEC;
                        } else {
                            new_state = STATE_NOT_GOOD;
                        }
                    }
                    break;
                case STATE_INC:
                    if (d <= prev) {
                        new_state = STATE_NOT_GOOD;
                    }
                    break;
                case STATE_DEC:
                    if (d >= prev) {
                        new_state = STATE_NOT_GOOD;
                    }
                    break;
            }
            res += dfs(i + 1, sum + d, d, new_state, limit_low && d == lo, limit_high && d == hi);
        }

        if (!limit_low && !limit_high) {
            ref = res + 1; // 省去初始化 -1 的过程
        }
        return res;
    };

    return dfs(0, 0, 0, STATE_INIT, true, true);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}