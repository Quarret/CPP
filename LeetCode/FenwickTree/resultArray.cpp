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
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        ranges::sort(sorted);
        sorted.erase(ranges::unique(sorted).begin(), sorted.end());
        
        int m = sorted.size();
        vector<int> arr1, arr2;
        FenwickTree<int> t1(m), t2(m);

        arr1.push_back(nums[0]);
        int idx1 = ranges::lower_bound(sorted, nums[0]) - sorted.begin() + 1;
        t1.update(idx1, 1);
        
        arr2.push_back(nums[1]);
        int idx2 = ranges::lower_bound(sorted, nums[1]) - sorted.begin() + 1;
        t2.update(idx2, 1);

        for (int i = 2; i < n; i++) {
            int x = nums[i];
            int idx = ranges::lower_bound(sorted, x) - sorted.begin() + 1;
            int gc1 = arr1.size() - t1.pre(idx);
            int gc2 = arr2.size() - t2.pre(idx);

            if (gc1 > gc2 || gc1 == gc2 && arr1.size() <= arr2.size()) {
                arr1.push_back(x);
                t1.update(idx, 1);
            } else {
                arr2.push_back(x);
                t2.update(idx, 1);
            }
        }

        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        return arr1;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
