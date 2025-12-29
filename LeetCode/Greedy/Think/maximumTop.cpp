#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maximumTop(vector<int>& nums, int k) {
    if (k == 0) return nums[0];
    
    int n = nums.size();
    if (n == 1 && k % 2) {
        return -1;
    }

    int mx = -1;
    for (int i = 0; i < min(k - 1, n); i++) {
        mx = max(mx, nums[i]);
    }
    if (k < n) mx = max(mx, nums[k]);
    return mx;
}
int main() {
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