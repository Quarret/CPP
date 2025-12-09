#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<long long> findXSum(vector<int>& nums, int k, int x) {
    using pii = pair<int, int>; // {cnt, x}
    set<pii> left, right;
    long long sum_l = 0; // 前 x 个大频数
    unordered_map<int, int> cnt;
    
    auto add = [&](int x) {
        pii p = {cnt[x], x};
        if (p.first == 0) {
            return;
        }

        if (!left.empty() && p > *left.begin()) {
            sum_l += (long long) p.first * p.second;
            left.insert(p);
        } else {
            right.insert(p);
        }
    };
    
    auto del = [&](int x) {
        pii p = {cnt[x], x};
        if (p.first == 0) {
            return;
        }
        
        auto it = left.find(p);
        if (it != left.end()) {
            sum_l -= (long long) p.first * p.second;
            left.erase(it);
        } else {
            right.erase(p);
        }
    };
    
    auto l2r = [&]() {
        pii p = *left.begin();
        sum_l -= (long long) p.first * p.second;
        left.erase(p);
        right.insert(p);
    };

    auto r2l = [&]() {
        pii p = *right.rbegin();
        sum_l += (long long) p.first * p.second;
        left.insert(p);
        right.erase(p);
    };

    int n = nums.size();
    vector<long long> ans(n - k + 1);
    for (int r = 0; r < n; r++) {
        // 添加 nums[r]
        int in = nums[r];
        del(in);
        cnt[in]++;
        add(in);
        
        int l = r - k + 1;
        if (l < 0) continue;

        // 维护大小
        while (!right.empty() && left.size() < x) {
            r2l();
        }

        while (left.size() > x) {
            l2r();
        }

        ans[l] = sum_l;
        
        // 删 nums[l]
        int out = nums[l];
        del(out);
        cnt[out]--;
        add(out);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
