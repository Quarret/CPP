#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int findIntegers(int n) {
    auto num_to_bin = [&](int x) -> string {
        string s = "";
        while (x) {
            s += (x & 1) + '0';
            x >>= 1;
        }
        ranges::reverse(s);
        return s;
    };
    
    string s = num_to_bin(n);
    int m = s.size();
    vector<array<int, 2>> memo(m + 1, {-1, -1});

    auto dfs = [&](this auto&& dfs, int i, int pre, bool limit_high) -> int {
        if (i == m) {
            return 1;
        }

        if (!limit_high && memo[i][pre] != -1) {
            return memo[i][pre];
        }
        
        int hi = limit_high ? s[i] - '0' : 1;
        
        int res = 0;
        // 填 0
        res += dfs(i + 1, 0, limit_high && hi == 0);
        
        // 填 1
        if (pre == 0 && hi != 0) {
            res += dfs(i + 1, 1, limit_high && hi == 1);
        }
        
        if (!limit_high) {
            memo[i][pre] = res;
        }
        return res;
    };

    return dfs(0, 0, true);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
