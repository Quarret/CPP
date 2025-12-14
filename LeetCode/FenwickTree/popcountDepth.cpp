#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// 模板来源 https://leetcode.cn/circle/discuss/mOr1u6/
// 根据题目用 FenwickTree<int> t(n) 或者 FenwickTree<long long> t(n) 初始化
template <typename T>
class FenwickTree
{
    vector<T> tree;

public:
    // 使用下标 1 到 n
    FenwickTree(int n) : tree(n + 1) {}

    // a[i] 增加 val
    // 1 <= i <= n
    // 时间复杂度 O(log n)
    void update(int i, T val)
    {
        for (; i < tree.size(); i += i & -i)
        {
            tree[i] += val;
        }
    }

    // 求前缀和 a[1] + ... + a[i]
    // 1 <= i <= n
    // 时间复杂度 O(log n)
    T pre(int i) const
    {
        T res = 0;
        for (; i > 0; i &= i - 1)
        {
            res += tree[i];
        }
        return res;
    }

    // 求区间和 a[l] + ... + a[r]
    // 1 <= l <= r <= n
    // 时间复杂度 O(log n)
    T query(int l, int r) const
    {
        if (r < l)
        {
            return 0;
        }
        return pre(r) - pre(l - 1);
    }
};

class Solution {

    int popcount_depth(uint64_t x) {
        int res = 0;
        while (x > 1) {
            res++;
            x = __builtin_popcountll(x);
        }
        return res;
    }

public:
    vector<int> popcountDepth(vector<long long>& nums, vector<vector<long long>>& queries) {
        int n = nums.size();
        vector t(6, FenwickTree<int>(n));
        
        auto update = [&](int i, int delta) -> void {
            int d = popcount_depth(nums[i]);
            t[d].update(i + 1, delta);
        };

        for (int i = 0; i < n; i++) {
            update(i, 1);
        }

        vector<int> ans;
        for (auto &q : queries) {
            if (q[0] == 1) {
                ans.push_back(t[q[3]].query(q[1] + 1, q[2] + 1));
            } else {
                int i = q[1];
                update(i, -1);
                nums[i] = q[2];
                update(i, 1);
            }
        }

        return ans;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
