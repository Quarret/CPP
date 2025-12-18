#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maxProfit(int k, vector<int> &prices)
{
    int n = prices.size();

    vector memo(n, vector(k + 1, vector<int>(2, -1)));
    auto dfs = [&](this auto &&dfs, int i, int k, bool hold) -> int
    {
        if (k < 0)
        {
            return INT_MIN / 2;
        }

        if (i < 0)
        {
            return hold ? INT_MIN / 2 : 0;
        }

        int &res = memo[i][k][hold];
        if (res != -1)
        {
            return res;
        }

        if (hold)
        {
            res = max(dfs(i - 1, k, true), dfs(i - 1, k, false) - prices[i]);
        }
        else
        {
            res = max(dfs(i - 1, k, false), dfs(i - 1, k - 1, true) + prices[i]);
        }

        return res;
    };

    // 最后一天如果持有股票没卖出一定比最后一天卖出小, 故入口为 dfs(n - 1, k, 0)
    return dfs(n - 1, k, 0);
}

// 递推
int maxProfit(int k, vector<int> &prices)
{
    int n = prices.size();

    vector f(n + 1, vector(k + 2, vector<int>(2, INT_MIN / 2)));
    for (int j = 0; j <= k + 1; j++)
    {
        // 建议边界还是按 dfs 来理解
        f[0][j][0] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= k + 1; j++)
        {
            f[i + 1][j][1] = max(f[i][j][1], f[i][j][0] - prices[i]);
            f[i + 1][j][0] = max(f[i][j][0], f[i][j - 1][1] + prices[i]);
        }
    }

    return f[n][k + 1][0];
}

// 根据对角线法则优化空间 由于本题的转移是从主对角线来的, 所以 j 要倒序枚举
int maxProfit(int k, vector<int> &prices)
{
    int n = prices.size();

    vector f(k + 2, vector<int>(2, INT_MIN / 2));
    for (int j = 0; j <= k + 1; j++)
    {
        // 建议边界还是按 dfs 来理解
        f[j][0] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = k + 1; j >= 1; j--)
        {
            f[j][1] = max(f[j][1], f[j][0] - prices[i]);
            f[j][0] = max(f[j][0], f[j - 1][1] + prices[i]);
        }
    }

    return f[k + 1][0];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
