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
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        vector<int> sorted = nums1;
        for (int i = 0; i < n; i++) {
            sorted.push_back(nums1[i] - nums2[i]);
            sorted[i] = nums1[i] - nums2[i] - diff;
        }
        ranges::sort(sorted);
        sorted.erase(ranges::unique(sorted).begin(), sorted.end());

        FenwickTree<long long> t(sorted.size());

        long long ans = 0;
        for (int j = 0; j < n; j++) {
            int x = nums1[j] - nums2[j];
            int idx1 = ranges::lower_bound(sorted, x) - sorted.begin() + 1;
            int idx2 = ranges::lower_bound(sorted, x - diff) - sorted.begin() + 1;
            ans += t.pre(idx1);

            t.update(idx2, 1);
        }

        return ans;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
