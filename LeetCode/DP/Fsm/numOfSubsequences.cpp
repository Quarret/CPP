#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long numOfSubsequences(string s)
{
    long long t = ranges::count(s, 'T');
    long long l = 0, lc = 0, lct = 0, c = 0, ct = 0, lt = 0;
    for (char b : s)
    {
        if (b == 'L')
        {
            l++;
        }
        else if (b == 'C')
        {
            lc += l;
            c++;
        }
        else if (b == 'T')
        {
            lct += lc;
            ct += c;
            t--;
        }
        lt = max(lt, l * t);
    }

    return lct + max({ct, lt, lc});
}

class Solution
{
    // 115. 不同的子序列
    long long numDistinct(const string &s, const string &t)
    {
        int n = s.size(), m = t.size();
        if (n < m)
        {
            return 0;
        }

        vector<long long> f(m + 1);
        f[0] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = min(i, m - 1); j >= max(m - n + i, 0); j--)
            {
                if (s[i] == t[j])
                {
                    f[j + 1] += f[j];
                }
            }
        }
        return f[m];
    }

    // 计算插入 C 额外产生的 LCT 子序列个数的最大值
    long long calcInsertC(string s)
    {
        int cnt_t = ranges::count(s, 'T'); // s[i+1] 到 s[n-1] 的 'T' 的个数
        int cnt_l = 0;                     // s[0] 到 s[i] 的 'L' 的个数
        long long res = 0;
        for (char c : s)
        {
            if (c == 'T')
            {
                cnt_t--;
            }
            if (c == 'L')
            {
                cnt_l++;
            }
            res = max(res, 1LL * cnt_l * cnt_t);
        }
        return res;
    }

public:
    long long numOfSubsequences(string s)
    {
        long long extra = max({numDistinct(s, "CT"), numDistinct(s, "LC"), calcInsertC(s)});
        return numDistinct(s, "LCT") + extra;
    }
};

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