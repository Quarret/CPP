#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int cnt[801];
int init = []
{
    for (int i = 1; i <= 800; i++)
    {
        int res = 0, x = i;
        while (x > 1)
        {
            x = __builtin_popcount(x);
            res++;
        }
        cnt[i] = res;
    }
    return 0;
}();

class Solution
{
public:
    int countKReducibleNumbers(string s, int k)
    {
        int n = s.size(), MOD = 1e9 + 7;

        vector memo(n, vector(801, -1));
        // string path(n, ' ');
        auto dfs = [&](this auto &&dfs, int i, int j, bool limit_high) -> int
        {
            if (i == n)
            {
                // cout << path << '\n';
                return 1 + cnt[j] <= k;
            }

            if (!limit_high && memo[i][j] != -1)
            {
                return memo[i][j];
            }

            int hi = limit_high ? s[i] - '0' : 1;

            int res = 0;
            // path[i] = '0';
            res = (res + dfs(i + 1, j, limit_high && hi == 0)) % MOD;

            // path[i] = '1';
            if (hi == 1)
                res = (res + dfs(i + 1, j + 1, limit_high && hi == 1)) % MOD;

            if (!limit_high)
            {
                memo[i][j] = res;
            }
            return res;
        };

        int cnt1 = 0;
        for (char c : s)
            cnt1 += c == '1';
        return dfs(0, 0, true) - (1 + cnt[cnt1] <= k) - 1;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
