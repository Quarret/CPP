#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int repeatedNTimes(vector<int>& nums) {
    int ans = 0, n = nums.size() / 2;
    unordered_map<int, int> cnt;
    for (int x : nums) {
        cnt[x]++;
        if (cnt[x] == n) ans = x;
    }

    return ans;
}


// 摩尔投票 --- 绝对众数
int repeatedNTimes(vector<int>& nums) {
    int ans = 0, hp = 0, n = nums.size();
    for (int i = 1; i < n; i++) {
        int x = nums[i];
        if (x == nums[0]) {
            return x;
        }

        if (hp == 0) {
            ans = x;
            hp++;
        } else {
            hp += ans == x ? 1 : -1;
        }
    }

    return ans;
}

// 检查相邻元素: 当 n >= 2 时, 两相邻元素之间的元素不超过 2 个
int repeatedNTimes(vector<int>& nums) {
    for (int i = 1; ; i++) {
        int x = nums[i];
        if (x == nums[i - 1] || 
            i > 1 && x == nums[i - 2] || 
            i > 2 && x == nums[i - 3]) {
            return x;
        }
    }

    return 0;
}

// 随机化
int repeatedNTimes(vector<int>& nums) {
    int n = nums.size();

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    while (1) {
        int i = uniform_int_distribution<>(0, n - 1)(rng);
        int j = uniform_int_distribution<>(0, n - 2)(rng);

        if (j >= i) {
            j++;
        }
        if (nums[i] == nums[j]) {
            return nums[i];
        }
    }

    return 0;
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
4. 试着从循环不变量着手思考
5. 正面难做难想吗? 要不试试反面? 正逆序都试试
6. 此题有单调性吗? 可以二分答案吗?
7. 是最大 / 最小问题吗? 先试试 DP 后采取贪心
8. 贡献法可以做吗?
9. 没有想到符合时间复杂度的解? 试试暴力思考 + 数据结构优化 
*/