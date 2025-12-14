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
    vector<int> minDeletions(string s, vector<vector<int>>& queries) {
        int n = s.size();
        FenwickTree<int> t(n);
        
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1]) {
                t.update(i + 1, 1);
            }
        }

        vector<int> ans;
        for (auto &q : queries) {
            if (q[0] == 1) {
                int j = q[1];
                if (j != 0) {
                    if (s[j - 1] != s[j]) t.update(j + 1, -1);
                    else t.update(j + 1, 1);
                }
                if (j != n - 1) {
                    if (s[j] != s[j + 1]) t.update(j + 2, -1);
                    else t.update(j + 2, 1);
                }
                // s[j] = (s[j] == 'A') ? 'B' : 'A';
                s[j] ^= 'A' ^ 'B';
            } else if (q[0] == 2) {
                int l = q[1], r = q[2];
                int cnt = t.query(l + 2, r + 1);
                // int cnt = t.query(l + 1, r + 1);
                // if (l != 0 && s[l - 1] != s[l]) cnt--;
                ans.push_back(r - l + 1 - (cnt + 1));
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
