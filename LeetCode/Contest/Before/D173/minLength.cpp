#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minLength(vector<int>& nums, int k) {
    int n = nums.size();

    unordered_map<int, int> cnt;
    long long m = 0, ans = INT64_MAX;
    for (int r = 0, l = 0; r < n; r++) {
        if (!cnt[nums[r]]) {
            m += nums[r];
        }
        cnt[nums[r]]++;
        
        while (m >= k) {
            ans = min(ans, 1LL * (r - l + 1));
            cnt[nums[l]]--;
            if (!cnt[nums[l]]) {
                m -= nums[l];
            }
            l++;
        }
    }

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