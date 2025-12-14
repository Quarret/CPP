#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

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
    T pre(int i)
    {
        T res = 0;
        for (; i > 0; i -= i & -i)
        {
            res += tree[i];
        }
        return res;
    }
};

class Solution
{
public:
    long long minInversionCount(vector<int> &nums, int k)
    {
        // 离散化
        // 100 90 80
        // 3 2 1
        vector<int> sorted = nums;
        ranges::sort(sorted);
        sorted.erase(ranges::unique(sorted).begin(), sorted.end());
        for (int &x : nums)
        {
            x = ranges::lower_bound(sorted, x) - sorted.begin() + 1; // FenwickTree 下标从 1 开始
        }

        FenwickTree<int> t(sorted.size());
        long long ans = LLONG_MAX, inv = 0;

        // 滑动窗口
        for (int i = 0; i < nums.size(); i++)
        {
            // 1. 入
            int in = nums[i];
            t.update(in, 1);
            inv += min(i + 1, k) - t.pre(in); // 窗口大小减去比 in 小的数字 = 逆序对

            int left = i - k + 1;
            if (left < 0)
                continue;

            // 2. 更新答案
            ans = min(ans, inv);

            // 3. 出
            int out = nums[left];
            inv -= t.pre(out - 1); // 在 out 右侧比 out 小的数字
            t.update(out, -1);
        }

        return ans;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
