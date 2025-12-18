#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maxProfit(vector<int> &prices, int fee)
{
    int n = prices.size();

    vector memo(n, array<int, 2>{-1, -1});
    auto dfs = [&](this auto &&dfs, int i, bool state) -> int
    {
        if (i < 0)
        {
            return state ? INT_MIN / 2 : 0;
        }

        int &res = memo[i][state];
        if (res != -1)
        {
            return res;
        }

        if (state)
        {
            res = max(dfs(i - 1, true), dfs(i - 1, false) - prices[i] - fee);
        }
        else
        {
            res = max(dfs(i - 1, false), dfs(i - 1, true) + prices[i]);
        }

        return res;
    };

    return dfs(n - 1, 0);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
