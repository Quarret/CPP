#include <bits/stdc++.h>
using ll = long long;
using namespace std;



// 模板来源 https://leetcode.cn/circle/discuss/mOr1u6/
class UnionFind
{
    vector<int> fa; // 代表元
    vector<int> sz; // 集合大小

public:
    int cc; // 连通块个数

    UnionFind(int n) : fa(n), sz(n, 1), cc(n)
    {
        // 一开始有 n 个集合 {0}, {1}, ..., {n-1}
        // 集合 i 的代表元是自己，大小为 1
        ranges::iota(fa, 0); // iota(fa.begin(), fa.end(), 0);
    }

    // 返回 x 所在集合的代表元
    // 同时做路径压缩，也就是把 x 所在集合中的所有元素的 fa 都改成代表元
    int find(int x)
    {
        // 如果 fa[x] == x，则表示 x 是代表元
        if (fa[x] != x)
        {
            fa[x] = find(fa[x]); // fa 改成代表元
        }
        return fa[x];
    }

    // 判断 x 和 y 是否在同一个集合
    bool is_same(int x, int y)
    {
        // 如果 x 的代表元和 y 的代表元相同，那么 x 和 y 就在同一个集合
        // 这就是代表元的作用：用来快速判断两个元素是否在同一个集合
        return find(x) == find(y);
    }

    // 把 from 所在集合合并到 to 所在集合中
    // 返回是否合并成功
    bool merge(int from, int to)
    {
        int x = find(from), y = find(to);
        if (x == y)
        { // from 和 to 在同一个集合，不做合并
            return false;
        }
        fa[x] = y;      // 合并集合。修改后就可以认为 from 和 to 在同一个集合了
        sz[y] += sz[x]; // 更新集合大小（注意集合大小保存在代表元上）
        // 无需更新 sz[x]，因为我们不用 sz[x] 而是用 sz[find(x)] 获取集合大小，但 find(x) == y，我们不会再访问 sz[x]
        cc--; // 成功合并，连通块个数减一
        return true;
    }

    // 返回 x 所在集合的大小
    int get_size(int x)
    {
        return sz[find(x)]; // 集合大小保存在代表元上
    }
};

class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        int n = nums.size();
        UnionFind dsu(n);
        
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '0' && s[i + 1] == '1') {
                dsu.merge(i, i + 1);
            }
        }

        unordered_map<int, int> mp;
        unordered_map<int, priority_queue<int>> pq;
        for (int i = 0; i < n; i++) {
            int fa = dsu.find(i);
            if (s[i] == '1') mp[fa]++;
            pq[fa].push(nums[i]);
        }

        long long ans = 0;
        for (auto [fa, c] : mp) {
            for (int i = 0; i < c; i++) {
                ans += 1LL * pq[fa].top();
                pq[fa].pop();
            }
        }

        return ans;
    }
};

long long maximumScore(vector<int>& nums, string s) {
    using pii = pair<int, int>;
    int n = nums.size();

    auto cmp = [&](pii &x, pii &y) -> bool {
        if (x.first > y.first) return false;
        else if (x.first == y.first) {
            return x.second > y.second;
        }
        return true;
    };
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
    int start = -1;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            while (!pq.empty()) {
                auto [v, idx] = pq.top();
                pq.pop();
                if (idx < start) continue;
                ans += 1LL * v;
                start = idx;
                break;
            }
        } else {
            pq.emplace(nums[i], i);
        }
    }

    return ans;
}

long long maximumScore(vector<int>& nums, string s) {
    int n = nums.size();
    int start = -1, end = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            start = i;
            break;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '1') {
            end = i;
            break;
        }
    }

    long long res = 0, cnt = 0;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        if (i < start || i > end) {
            res += 1LL * (s[i] == '1' ? nums[i] : 0);
        } else {
            cnt += s[i] == '1';
            pq.push(nums[i]);
        }
    }

    for (int i = 0; i < cnt; i++) {
        res += 1LL * pq.top();
        pq.pop();
    }

    return res;
}

// 1 只能左移, 从右向左维护前 '1'个数 最大的值
long long maximumScore(vector<int>& nums, string s) {
    priority_queue<int, vector<int>, greater<>> pq;

    int n = nums.size(), cnt1 = 0;
    for (int i = n - 1; i >= 0; i--) {
        cnt1 += s[i] == '1';
        pq.push(nums[i]); 

        if (pq.size() > cnt1) pq.pop();
    }

    long long ans = 0;
    for (int i = 0; i < cnt1; i++) {
        ans += 1LL * pq.top();
        pq.pop();
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
