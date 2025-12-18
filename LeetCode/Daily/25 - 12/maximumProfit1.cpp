#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
做空: 在股票价格高时, 找别人借一些股票换成钱, 在股票价格低时, 用钱买等量股票还给别人
*/
long long maximumProfit(vector<int> &prices, int k)
{
    int n = prices.size();

    vector memo(n, vector(k + 1, array<long long, 3>{LLONG_MIN / 2, LLONG_MIN / 2, LLONG_MIN / 2}));
    auto dfs = [&](this auto &&dfs, int i, int j, int state) -> long long
    {
        if (j < 0)
        {
            return LLONG_MIN / 2;
        }

        if (i < 0)
        {
            // 不能一开始就做空, 道理和一开始就买入股票一样
            return state ? LLONG_MIN / 2 : 0;
        }

        long long &res = memo[i][j][state];
        if (res != LLONG_MIN / 2)
        {
            return res;
        }

        if (state == 0)
        {
            res = max({dfs(i - 1, j, 0), dfs(i - 1, j - 1, 1) + prices[i], dfs(i - 1, j - 1, 2) - prices[i]});
        }
        else if (state == 1)
        {
            res = max({dfs(i - 1, j, 1), dfs(i - 1, j, 0) - prices[i]});
        }
        else
        { // 做空
            res = max(dfs(i - 1, j, 2), dfs(i - 1, j, 0) + prices[i]);
        }

        return res;
    };

    return dfs(n - 1, k, 0);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
