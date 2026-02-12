#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool canPartitionKSubsets(vector<int>& nums, int k) {
    int n = nums.size();
    int sum = reduce(nums.begin(), nums.end()), target = sum / k;
    // 剪枝 1
    ranges::sort(nums, greater());

    vector<int> s(k);
    auto dfs = [&](this auto&& dfs, int i) -> bool {
        if (i == n) {
            int x = s[0];
            for (int y : s) {
                if (x != y) {
                    return false;
                }
            }
            return true;
        }

        for (int j = 0; j < k; j++) {
            // 剪枝 2: 后面的判断是关键剪枝
            if (s[j] + nums[i] > target || (j && s[j - 1] == s[j])) continue;
            s[j] += nums[i];
            if (dfs(i + 1)) {
                return true;
            }
            s[j] -= nums[i];
        }

        return false;
    };

    return dfs(0);
}

// 状压 + 记忆化搜素
// dfs(mask, tot) 表示 mask 中为 1 的元素已经装入集合中后, 当前集合和为 tot 是否有效
bool canPartitionKSubsets(vector<int>& nums, int k) {
    int n = nums.size();
    int s = accumulate(nums.begin(), nums.end(), 0);
    if (s % k) return false;
    s /= k;
    ranges::sort(nums);
    
    vector memo(1 << n, 0);
    auto dfs = [&](this auto&& dfs, int mask, int tot) -> bool {
        if (mask == (1 << n) - 1) {
            return true;
        }

        if (memo[mask]) {
            return memo[mask] == 1;
        }

        for (int i = 0; i < n; i++) {
            if (mask >> i & 1) continue;
            if (tot + nums[i] > s) break;

            if (dfs(mask | (1 << i), (tot + nums[i]) % s)) {
                memo[mask] = 1;
                return true;
            }
        }

        memo[mask] = -1;
        return false;
    };

    return dfs(0, 0);
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