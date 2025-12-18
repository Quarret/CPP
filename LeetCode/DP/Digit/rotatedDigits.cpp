#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int diffs[10] = {0, 0, 1, -1, -1, 1, 1, -1, 0, 1};
class Solution {
public:
    int rotatedDigits(int n) {
        string s = to_string(n);
        int m = s.size();

        vector memo(m, vector(2, -1));
        auto dfs = [&](this auto&& dfs, int i, bool ok, bool limit_high) -> int {
            if (i == m) {
                return ok;
            }

            if (!limit_high && memo[i][ok] != -1) {
                return memo[i][ok];
            }

            int hi = limit_high ? s[i] - '0' : 9;

            int res = 0; 
            for (int d = 0; d <= hi; d++) {
                if (diffs[d] == -1) continue;
                res += dfs(i + 1, ok || diffs[d], limit_high && d == hi);
            }

            if (!limit_high) {
                memo[i][ok] = res;
            }
            return res;
        };

        return dfs(0, false, true);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
