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
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<int> sorted = scores;
        ranges::sort(sorted);
        sorted.erase(ranges::unique(sorted).begin(), sorted.end());

        int m = sorted.size();
        FenwickTree<int> t(m);
        vector<int> idxs(n);
        ranges::iota(idxs, 0);
        ranges::sort(idxs, {}, [&](auto &i) {
            return ages[i];
        });

        int ans = 0, res = 0;
        for (int i = 0; i < n; i++) {
            int idx = ranges::lower_bound(sorted, scores[idxs[i]]) - sorted.begin() + 1;
            res += scores[idxs[i]];
            cout << idx << '\n';
            res -= t.query(idx + 1, m + 1);
            t.update(idx, scores[idxs[i]]);
            ans = max(ans, res);
        }
        return ans;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
