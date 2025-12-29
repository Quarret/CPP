#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
1 1
11 1 + 1
111 1 + 3 + 2
1111

*/

int minAllOneMultiple(int k)
{
    unordered_map<int, int> vis;

    int sum = 0, pre = 1, n = 1;
    while (1)
    {
        if (n == 1)
            pre = 1;
        else
            pre = (pre * 10) % k;
        sum = (sum + pre) % k;

        int mask = (sum << 16) | pre;
        if (vis[mask])
            return -1;

        vis[mask] = 1;
        if (sum == 0)
            break;
        n++;
    }

    return n;
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