#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// 本质是传播约束
int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
    vector<int> mx(n, INT_MAX);
    for (auto &r : restrictions) {
        mx[r[0]] = r[1];
    }

    vector<int> a(n, 0);
    // 第一次扫描
    for (int i = 0; i < n - 1; i++) {
        a[i + 1] = min(a[i] + diff[i], mx[i + 1]);
    }

    // 第二次扫描
    for (int i = n - 2; i >= 1; i--) {
        a[i] = min(a[i + 1] + diff[i], a[i]);
    }

    return *ranges::max_element(a);
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