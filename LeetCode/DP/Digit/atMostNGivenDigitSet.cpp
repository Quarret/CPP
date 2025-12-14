#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int atMostNGivenDigitSet(vector<string> &digits, int n)
{
    string s = to_string(n);
    int m = s.size();

    vector<int> memo(m, -1);
    auto dfs = [&](this auto &&dfs, int i, bool is_limit, bool is_num) -> int
    {
        if (i == m)
        {
            return is_num;
        }

        if (!is_limit && !is_num && memo[i] != -1)
        {
            return memo[i];
        }

        int res = 0;
        // 不填数字
        if (!is_num)
        {
            res += dfs(i + 1, false, false);
        }

        char hi = is_limit ? s[i] : '9';
        for (auto &d : digits)
        {
            if (d[0] > hi)
                break;

            res += dfs(i + 1, is_limit && d[0] == hi, true);
        }

        if (!is_limit && !is_num)
        {
            memo[i] = res;
        }
        return res;
    };

    return dfs(0, true, false);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
