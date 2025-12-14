#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int countNumbersWithUniqueDigits(int n) {
    int num = 1;
    for (int i = 0; i < n; i++) num *= 10;
    string s = to_string(num - 1);
    int m = s.size();
    
    vector memo(m, vector<int>(1 << 10, -1));
    auto dfs = [&](this auto&& dfs, int i, int mask, bool limit_high) -> int {
        if (i == m) {
            return mask != 0;
        }

        if (!limit_high && memo[i][mask] != -1) {
            return memo[i][mask];
        }

        int hi = limit_high ? s[i] - '0' : 9;
        int res = 0;

        if (!mask) {
            // 前面空位, 高位无限制
            res += dfs(i + 1, mask, false);
        }

        for (int d = mask ? 0 : 1; d <= hi; d++) {
            if (mask >> d & 1) continue;
            res += dfs(i + 1, mask | (1 << d), limit_high && d == hi);
        }

        if (!limit_high) {
            memo[i][mask] = res;
        }
        return res;
    };

    return dfs(0, 0, true) + 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
