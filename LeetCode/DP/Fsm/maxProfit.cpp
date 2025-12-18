#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size();

    vector memo(n, vector<int>(2, -1));
    auto dfs = [&](this auto &&dfs, int i, bool hold) -> int
    {
        if (i < 0)
        {
            // 第一天不可能持有股票
            return hold ? INT_MIN / 2 : 0;
        }

        int &res = memo[i][hold];
        if (res != -1)
        {
            return res;
        }

        if (hold)
        {
            res = max(dfs(i - 1, true), dfs(i - 1, false) - prices[i]);
        }
        else
        {
            res = max(dfs(i - 1, false), dfs(i - 1, true) + prices[i]);
        }

        return res;
    };

    return dfs(n - 1, 0);
}

//  递推
int maxProfit(vector<int> &prices)
{
    int n = prices.size();

    vector f(n + 1, vector<int>(2, INT_MIN / 2));
    f[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            f[i + 1][1] = max(f[i][1], f[i][0] - prices[i]);
            f[i + 1][0] = max(f[i][0], f[i][1] + prices[i]);
        }
    }

    return f[n][0];
}

// 空间优化 (很像背包的空间优化)
int maxProfit(vector<int> &prices)
{
    int n = prices.size();

    int f0 = 0, f1 = INT_MIN / 2;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            int new_f0 = max(f0, f1 + prices[i]);
            f1 = max(f1, f0 - prices[i]);
            f0 = new_f0;
        }
    }

    return f0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
