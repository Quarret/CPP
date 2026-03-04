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
int sumSubseqWidths(vector<int>& nums) {
        using ll = long long;
        vector<int> sorted = nums;
        ranges::sort(sorted);
        sorted.erase(ranges::unique(sorted).begin());

        int n = nums.size(), m = sorted.size();
        FenwickTree<int> t1(n), t2(n);

        unordered_map<int, int> mp;
        vector<int> min_left(n, 0), min_right(n, 0);
        vector<int> max_left(n, 0), max_right(n, 0);
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            int idx = ranges::lower_bound(sorted, x) - sorted.begin() + 1;
            mp[x] = idx;
            t1.update(idx, 1);
            min_left[i] = t1.pre(idx);
            max_left[i] = i - t1.pre(idx - 1);
        }

        for (int i = n - 1; i >= 0; i--) {
            int x = nums[i], idx = mp[x];
            min_right[i] = t2.pre(idx);
            max_right[i] = (n - i + 1) - t2.pre(idx - 1);
            t2.update(idx, 1);
        }

        const int MOD = 1e9 + 7;
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ll min_l = min_left[i], min_r = min_right[i];
            ll max_l = max_left[i], max_r = max_right[i];
            // ll s = 1LL * (nums[i] * (max_l * max_r - min_l * min_r)) % MOD;
            ll s = 1LL * (nums[i] * (min_l * min_r - max_l * max_r)) % MOD;
            cout << "min" << ' ' << min_l << ' ' << min_r << '\n';
            cout << "max" << ' ' << max_l << ' ' << max_r << '\n';
            ans = (ans + s) % MOD;
        }

        return ans;
    }
};

int sumSubseqWidths(vector<int>& nums) {
    using ll = long long;
    const int MOD = 1e9 + 7;
    
    int n = nums.size();
    ranges::sort(nums);
    unordered_map<int, int> vis;
    
    auto qpow = [&](ll x, ll y) -> ll {
        ll ret = 1;
        while (y) {
            if (y & 1) {
                ret = (ret * x) % MOD;
            }
            x = (x * x) % MOD;
            y >>= 1;
        }

        return ret;
    }; 

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int x = nums[i];
        int cnt_max = i;
        int cnt_min = n - 1 - i;
        ll s = x * ((qpow(2, cnt_max) - qpow(2, cnt_min)) % MOD + MOD) % MOD;
        ans = (ans + s) % MOD;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}