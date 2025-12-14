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

// 先处理峰值, 后来计算区间和
// 推广之后的树状数组问题, 先计算 (题目要求变量), 再用树状数组记录前缀和
// 树状数组是固定长度的
class Solution {
public:
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        FenwickTree<int> t(n);

        auto check = [&](int i) -> bool {
            if (i == 0 || i == n - 1) return false;
            return nums[i] > nums[i - 1] && nums[i] > nums[i + 1];
        };

        for (int i = 0; i < n; i++) {
            t.update(i + 1, check(i));
        }

        vector<int> ans;
        for (auto &q : queries) {
            if (q[0] == 1) {
                ans.push_back(t.query(q[1] + 2, q[2]));
            } else {
                bool before[3];
                for (int i = max(0, q[1] - 1); i <= min(q[1] + 1, n - 1); i++) {
                    before[i - max(0, q[1] - 1)] = check(i);
                }

                nums[q[1]] = q[2];

                for (int i = max(0, q[1] - 1); i <= min(q[1] + 1, n - 1); i++) {
                    bool bef = before[i - max(0, q[1] - 1)];
                    bool after = check(i);

                    if (bef == false && after == true) {
                        t.update(i + 1, 1);
                    } else if (bef == true && after == false) {
                        t.update(i + 1, -1);
                    }
                }
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
