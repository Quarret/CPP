#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long popcountDepth(long long n, int k)
{
    string s = "";
    while (n)
    {
        s.push_back((n & 1) + '0');
        n >>= 1;
    }
    ranges::reverse(s);

    auto check = [&](int x) -> int
    {
        int res = 1;
        while (x > 1)
        {
            x = __builtin_popcount(x);
            res++;
        }

        return res;
    };

    int m = s.size();
    vector memo(m, vector<long long>(100, -1));
    auto dfs = [&](this auto &&dfs, int i, int j, bool limit_high) -> long long
    {
        if (i == m)
        {
            return j && check(j) == k;
        }

        if (!limit_high && memo[i][j] != -1)
        {
            return memo[i][j];
        }

        int hi = limit_high ? s[i] - '0' : 1;

        long long res = 0;
        for (int d = 0; d <= min(1, hi); d++)
        {
            res += dfs(i + 1, j + d, limit_high && d == hi);
        }

        if (!limit_high)
        {
            memo[i][j] = res;
        }
        return res;
    };

    if (k == 0)
        return 1;
    return dfs(0, 0, true) - (k == 1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
