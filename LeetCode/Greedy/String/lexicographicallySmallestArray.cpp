#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
    int n = nums.size();
    vector<int> idxs(n);
    ranges::iota(idxs, 0);
    ranges::sort(idxs, {}, [&](auto &x) {
        return nums[x];
    });
    
    vector<int> ans(n);
    vector<int> a, b;
    for (int i = 0; i < n; i++) {
        int idx = idxs[i], num = nums[idx];
        a.push_back(idx);
        b.push_back(num);

        if (i < n - 1 && nums[idxs[i + 1]] - num <= limit) continue;
        ranges::sort(a);
        ranges::sort(b);

        for (int j = 0; j < a.size(); j++) {
            ans[a[j]] = b[j];
        }
        a.clear();
        b.clear();
    }

    ranges::sort(a);
    ranges::sort(b);

    for (int j = 0; j < a.size(); j++) {
        ans[a[j]] = b[j];
    }

    return ans;
}

// 分组循环
vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
    int n = nums.size();
    vector<int> idxs(n);
    ranges::iota(idxs, 0);
    ranges::sort(idxs, {}, [&](auto &x) {
        return nums[x];
    });
    
    vector<int> ans(n);
    for (int i = 0; i < n;) {
        int st = i;

        for (i++; i < n && nums[idxs[i]] - nums[idxs[i - 1]] <= limit; i++);
        vector<int> a(idxs.begin() + st, idxs.begin() + i);
        ranges::sort(a);

        for (int j = 0; j < a.size(); j++) {
            ans[a[j]] = nums[idxs[st + j]];
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
