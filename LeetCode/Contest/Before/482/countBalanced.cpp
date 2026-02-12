#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long countBalanced(long long low, long long high)
{
    string low_s = to_string(low);
    string high_s = to_string(high);
    int n = high_s.size();
    int diff_lh = n - low_s.size();

    vector memo(n, vector<long long>(350, -1));
    auto dfs = [&](this auto &&dfs, int i, int diff, bool limit_low, bool limit_high) -> long long
    {
        if (i == n)
        {
            return diff == 0;
        }

        int mask = diff + 150;
        if (!limit_low && !limit_high && memo[i][mask] != -1)
        {
            return memo[i][mask];
        }

        int lo = limit_low && i >= diff_lh ? low_s[i - diff_lh] - '0' : 0;
        int hi = limit_high ? high_s[i] - '0' : 9;

        long long res = 0;
        for (int d = lo; d <= hi; d++)
        {
            res += dfs(i + 1, diff + (i % 2 ? d : -d), limit_low && d == lo, limit_high && d == hi);
        }

        if (!limit_low && !limit_high)
        {
            memo[i][mask] = res;
        }
        return res;
    };

    return dfs(0, 0, true, true);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}

/*
这道题卡住了? 没事! 冷静下慢慢想, 想了还做不出来就是收获
1. 这道题与位置无关吗? 可以先排序吗?
2. 从特殊到一般, 试试控制一些题目变量来找一些性质
3. 看到一些熟悉的性质? 试试从性质中的变量出发
4. 正面难做难想吗? 要不试试反面? 正逆序都试试
5. 此题有单调性吗? 可以二分答案吗?
6. 是最大 / 最小问题吗? 先试试 DP 后采取贪心
7. 贡献法可以做吗?
8. 没有想到符合时间复杂度的解? 试试暴力思考 + 数据结构优化
*/