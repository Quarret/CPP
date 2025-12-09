#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<long long> countStableSubarrays(vector<int>& nums, vector<vector<int>>& queries) {
    int n = nums.size();
    // 递增段
    vector<int> left; // 递增段的左端点
    vector<long long> s = {0}; // 递增数组个数的前缀和
    int start = 0;
    for (int i = 0; i < n; i++) {
        int x = nums[i];
        if (i == n - 1 || x > nums[i + 1]) {
            left.push_back(start);

            // 长度为 m 的递增数组, 有 m * (m + 1) / 2 个递增子数组
            long long m = i - start + 1;
            s.push_back(s.back() + m * (m + 1) / 2);
            start = i + 1;
        }
    }
    
    vector<long long> ans;
    ans.reserve(queries.size()); // 预分配空间, 减少动态开辟
    for (auto &q : queries) {
        int l = q[0], r = q[1];

        // 中间递增段的第一个段的左端点
        int i = ranges::upper_bound(left, l) - left.begin();
        
        // r 在的递增数组的左端点
        int j = ranges::upper_bound(left, r) - left.begin() - 1;
        
        // [l, r] 在一段递增数组中
        if (i > j) {
            long long m = r - l + 1;
            ans.push_back(m * (m + 1) / 2);
            continue;;
        }

        // l r 不在同一段递增数组
        // 分为三段: [l, left[i]) [left[i], left[j]) [left[j], r]
        long long m = left[i] - l;
        long long m2 = r - left[j] + 1;
        ans.push_back(m * (m + 1) / 2 + s[j] - s[i] + m2 * (m2 + 1) / 2);
    }

    return ans;
}

vector<long long> countStableSubarrays(vector<int>& nums, vector<vector<int>>& queries) {
    int n = nums.size(), cnt = 0;

    vector<long long> sum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int x = nums[i];
        if (i > 0 && x < nums[i - 1]) {
            cnt = 0;
        }

        cnt++;
        sum[i + 1] = sum[i] + cnt;
    }

    vector<int> nxt(n);
    nxt[n - 1] = n;
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] <= nums[i + 1]) {
            nxt[i] = nxt[i + 1];
        } else {
            nxt[i] = i + 1;
        }
    }

    vector<long long> ans;
    ans.reserve(queries.size());
    for (auto &q : queries) {
        int l = q[0], r = q[1];
        int l1 = nxt[l];

        // 在同一递增区间
        if (l1 > r) {
            long long m = r - l + 1;
            ans.push_back(m * (m + 1) / 2);
            continue;
        }

        long long m = l1 - l;
        ans.push_back(m * (m + 1) / 2 + sum[r + 1] - sum[l1]);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
