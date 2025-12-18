#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// 根据对角线法则优化空间 由于本题的转移是从主对角线来的, 所以 j 要倒序枚举
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int k = 2;

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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
