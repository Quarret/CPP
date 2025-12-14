#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int countBalls(int lowLimit, int highLimit) {
    unordered_map<int, int> cnt;

    int ans = 0;
    for (int x = lowLimit; x <= highLimit; x++) {
        string s = to_string(x);
        int sum = 0;
        for (char c : s) {
            sum += c - '0';
        }
        cnt[sum]++;
        ans = max(ans, cnt[sum]);
    }
    return ans;    
}

int countBalls(int lowLimit, int highLimit) {
    string low_s = to_string(lowLimit), high_s = to_string(highLimit);
    int n = high_s.size();
    low_s = string(n - low_s.size(), '0') + low_s;
    // 数位和的上界
    int m = high_s[0] - '0' + (n - 1) * 9; 
    vector memo(n, vector<int>(m + 1, -1));

    auto dfs = [&](this auto&& dfs, int i, int j, bool limit_low, bool limit_high) -> int {
        if (i == n) {
            return j == 0;
        }

        if (!limit_low && !limit_high && memo[i][j] != -1) {
            return memo[i][j];
        }

        int lo = limit_low ? low_s[i] - '0' : 0;
        int hi = limit_high ? high_s[i] - '0' : 9;

        int res = 0;
        for (int d = lo; d <= min(hi, j); d++) {
            res += dfs(i + 1, j - d, limit_low && d == lo, limit_high && d == hi);
        }

        if (!limit_low && !limit_high) {
            memo[i][j] = res;
        }
        return res;
    };

    int ans = 0;
    for (int j = 1; j <= m; j++) {
        ans = max(ans, dfs(0, j, true, true));
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
