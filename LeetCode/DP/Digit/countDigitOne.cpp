#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int countDigitOne(int n)
{
    string s = to_string(n);
    int m = s.size();
    vector memo(m, vector<int>(m + 1, -1));

    // 含 1 的必须填数字
    auto dfs = [&](this auto &&dfs, int i, bool is_limit, int cnt1) -> int
    {
        if (i == m)
        {
            return cnt1;
        }

        if (!is_limit && memo[i][cnt1] != -1)
        {
            return memo[i][cnt1];
        }

        int res = 0;
        int hi = is_limit ? s[i] - '0' : 9;

        for (int d = 0; d <= hi; d++)
        {
            res += dfs(i + 1, is_limit && d == hi, cnt1 + (d == 1));
        }

        if (!is_limit)
        {
            memo[i][cnt1] = res;
        }
        return res;
    };

    return dfs(0, true, 0);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
