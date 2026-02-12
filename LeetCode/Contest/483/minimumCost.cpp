#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
    int n = s.size();
    
    long long s_0 = 0, s_1 = 0, t_0 = 0, diff = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') s_0++;
        else s_1++;

        t_0 += t[i] == '0';
        diff += s[i] != t[i];
    }

    // 如果奇数个 0, 则必须 flip
    long long ans = 0;
    if ((s_0 + t_0) % 2) {
        ans += 1LL * flipCost;
        diff--; // 贪心修改在 01 上
        // 111 000
        if (s_1 >= s_0) s_1--;
        else s_0--;
    }

    // 先直接 swap 同一个字符串内的
    long long c = min(s_0, s_1);
    if (c && diff) {
        ans += min(1LL * swapCost * c, 2LL * c * flipCost);
        diff -= 2 * c;
    }
    
    // 在 1cross + 1 swap 与 2 flip 比较
    long long p = diff / 2;
    ans += min(1LL * (crossCost + swapCost) * p, 1LL * 2 * p * flipCost);
    // 奇数个必须使用 flip
    if (diff % 2) ans += flipCost;

    return ans;
}

// 分类讨论
// 对于上下不同对, 分别统计
long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
    int n = s.size();

    int cnt01 = 0, cnt10 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0' && t[i] == '1') cnt01++;
        if (s[i] == '1' && t[i] == '0') cnt10++;
    }

    if (cnt01 < cnt10) swap(cnt01, cnt10);

    long long ans = LLONG_MAX;
    // 当 flip 很小时
    ans = min(ans, 1LL * flipCost * (cnt01 + cnt10));

    // 当 flip 很大时
    // 1. 当 swap 比 cross 小时
    ans = min(ans, 1LL * min(cnt01, cnt10) * swapCost + 1LL * flipCost * (cnt01 - cnt10));

    // 2. 当 swap 比 cross 大时
    int avg = (cnt01 + cnt10) / 2, rem = (cnt01 + cnt10) % 2;
    ans = min(ans, 1LL * (avg - cnt10) * crossCost + 1LL * avg * swapCost + 1LL * rem * flipCost);

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}



/*
这道题卡住了? 没事! 冷静下慢慢想, 想了还做不出来就是收获
1. 这道题与位置无关吗? 可以先排序吗?
2. 从特殊到一般, 试试控制一些题目变量来找一些性质
3. 看到一些熟悉的性质? 试试从性质中的变量出发
4. 试着从循环不变量着手思考
5. 正面难做难想吗? 要不试试反面? 正逆序都试试
6. 此题有单调性吗? 可以二分答案吗?
7. 是最大 / 最小问题吗? 先试试 DP 后采取贪心
8. 贡献法可以做吗?
9. 没有想到符合时间复杂度的解? 试试暴力思考 + 数据结构优化 
*/