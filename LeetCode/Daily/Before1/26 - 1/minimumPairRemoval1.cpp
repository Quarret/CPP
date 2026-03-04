#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// 懒删除 + 双向链表
int minimumPairRemoval(vector<int>& nums) {
    using ll = long long;

    int n = nums.size();
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    int inv = 0; // 相邻逆序对个数
    for (int i = 0; i < n - 1; i++) {
        int x = nums[i], y = nums[i + 1];
        pq.emplace(x + y, i);
        inv += x > y;
    }
    
    // 维护每个下标最近未删除下标
    vector<int> left(n + 1), right(n);
    ranges::iota(left, -1);
    ranges::iota(right, 1);

    vector<ll> a(nums.begin(), nums.end());
    int ans = 0;

    while (inv) {
        ans++;

        // 懒删除堆
        // idx 已经被删除的
        // a[idx] + a[right[idx]] 和加入堆时的和不同的
        while (right[pq.top().second] >= n || pq.top().first != a[pq.top().second] + a[right[pq.top().second]]) {
            pq.pop();
        }

        auto [s, idx] = pq.top();
        pq.pop();

        // 当前元素的下一个数
        int nxt = right[idx];
        inv -= a[idx] > a[nxt];

        // 当前元素的钱一个数
        int pre = left[idx];
        if (pre >= 0) {
            inv -= a[pre] > a[idx]; // 旧数据
            inv += a[pre] > s; // 新数据
            pq.emplace(a[pre] + s, pre);
        }

        // 下一个数的下一个数
        int nxt2 = right[nxt];
        if (nxt2 < n) {
            inv -= a[nxt] > a[nxt2];
            inv += s > a[nxt2];
            pq.emplace(s + a[nxt2], idx);
        }

        a[idx] = s;
        // 模拟双端队列删除
        int l = left[nxt], r = right[nxt];
        right[l] = r;
        left[r] = l;
        right[nxt] = n;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}