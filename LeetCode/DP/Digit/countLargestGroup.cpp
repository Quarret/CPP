#include <bits/stdc++.h>
using i64 = long long;
using namespace std;


int countLargestGroup(int n) {
    string s = to_string(n);
    int m = s.size();

    vector memo(m, vector<int>(m * 9 + 1, -1));
    
    // 统计数位和为 target 的个数
    auto dfs = [&](this auto&& dfs, int i, int sum, bool limit_high) -> int {
        if (i == m) {
            return sum == 0;
        }

        if (!limit_high && memo[i][sum] != -1) {
            return memo[i][sum];
        }

        int hi = limit_high ? s[i] - '0' : 9;

        int res = 0;
        for (int d = 0; d <= min(hi, sum); d++) {
            res += dfs(i + 1, sum - d, limit_high && d == hi);
        }

        if (!limit_high) {
            memo[i][sum] = res;
        }
        return res;
    };

    int ans = 0, maxx = 0;
    for (int target = 1; target <= 9 * m; target++) {
        int cnt = dfs(0, target, true);
        if (cnt > maxx) {
            maxx = cnt;
            ans = 1;
        } else if (cnt == maxx) {
            ans++;
        }
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
