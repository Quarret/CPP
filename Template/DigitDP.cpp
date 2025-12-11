#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

class Solution {
public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        int n = num2.size();
        num1 = string(n - num1.size(), '0') + num1; // 补前导零（本题前导零不影响答案，可以补前导零，简化代码逻辑）

        vector memo(n, vector<int>(min(9 * n, max_sum) + 1, -1));
        auto dfs = [&](this auto&& dfs, int i, int sum, bool limit_low, bool limit_high) -> int {
            if (sum > max_sum) { // 非法
                return 0;
            }
            if (i == n) {
                return sum >= min_sum;
            }
            if (!limit_low && !limit_high && memo[i][sum] != -1) {
                return memo[i][sum];
            }

            int lo = limit_low ? num1[i] - '0' : 0;
            int hi = limit_high ? num2[i] - '0' : 9;

            int res = 0;
            for (int d = lo; d <= hi; d++) { // 枚举当前数位填 d
                res = (res + dfs(i + 1, sum + d, limit_low && d == lo, limit_high && d == hi)) % 1'000'000'007;
            }

            if (!limit_low && !limit_high) {
                memo[i][sum] = res;
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
