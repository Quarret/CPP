#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int beautifulNumbers(int l, int r)
{
    string low_s = to_string(l);
    string high_s = to_string(r);
    int n = high_s.size();
    int diff_lh = n - low_s.size();
    int pow9 = pow(9, n);

    // 三个参数 (i, sum, times) 压缩到一个变量
    unordered_map<long long, int> memo;
    // vector memo(n, vector(9 * n + 1, vector<int>(pow9, -1)));
    auto dfs = [&](this auto &&dfs, int i, int sum, int times, bool limit_low, bool limit_high) -> int
    {
        if (i == n)
        {
            return times % sum == 0;
        }

        long long mask = (long long)times << 32 | i << 16 | sum;
        if (!limit_low && !limit_high && memo.contains(mask))
        {
            return memo[mask];
        }

        int lo = limit_low && i >= diff_lh ? low_s[i - diff_lh] - '0' : 0;
        int hi = limit_high ? high_s[i] - '0' : 9;
        int d = lo;

        int res = 0;
        if (limit_low && i < diff_lh)
        {
            res += dfs(i + 1, sum, times, true, false);
            d = 1;
        }

        for (; d <= hi; d++)
        {
            res += dfs(i + 1, sum + d, times * d, limit_low && d == lo, limit_high && d == hi);
        }

        if (!limit_low && !limit_high)
        {
            memo[mask] = res;
        }
        return res;
    };

    return dfs(0, 0, 1, true, true);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
