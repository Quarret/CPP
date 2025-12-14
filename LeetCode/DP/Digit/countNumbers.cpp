#include <bits/stdc++.h>
using ll = long long;
using namespace std;


class Solution {
    vector<int> trans(string& s, int b) {
        for (char& c : s) {
            c -= '0';
        }
        vector<int> digits;
        while (!s.empty()) {
            string nxt_s; // 用竖式除法计算 s / b 得到的商（十进制）
            int rem = 0; // s % b
            for (char c : s) {
                rem = rem * 10 + c;
                int q = rem / b; // 商
                if (q || !nxt_s.empty()) { // 忽略前导零
                    nxt_s.push_back(q);
                }
                rem = rem % b;
            }
            digits.push_back(rem);
            s = move(nxt_s);
        }
        ranges::reverse(digits);
        return digits;
    }

public:
    int countNumbers(string l, string r, int b) {
    vector<int> low_s = trans(l, b);
    vector<int> high_s = trans(r, b);
    int n = high_s.size(), MOD = 1e9 + 7;
    int diff_lh = n - low_s.size();

    vector memo(n, vector<int>(b, -1));
    auto dfs = [&](this auto&& dfs, int i, int pre, bool limit_low, bool limit_high) -> int {
        if (i == n) {
            return 1;
        }

        if (!limit_high && !limit_low && memo[i][pre] != -1) {
            return memo[i][pre];
        }

        int lo = limit_low && i >= diff_lh ? low_s[i - diff_lh] : 0;
        int hi = limit_high ? high_s[i] : b - 1;

        long long res = 0;
        for (int d = max(pre, lo); d <= hi; d++) {
            res += dfs(i + 1, d, limit_low && d == lo, limit_high && d == hi);
        }
        res = res % MOD;

        if (!limit_low && !limit_high) {
            memo[i][pre] = res;
        }
        return res;
    };

    return dfs(0, 0, true, true);
}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
