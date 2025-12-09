#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int maxFrequency(vector<int>& nums, int k, int numOperations) {
    // 所有要考虑的值放入 set 中
    unordered_set<long long> st;

    // 统计 nums 中每种数出现多少次
    unordered_map<long long, int> cnt;

    for (int x : nums) {
        st.insert(1LL * x - k);
        st.insert(1LL * x + k);
        st.insert(1LL * x);
        cnt[x]++;
    }

    sort(nums.begin(), nums.end());
    int ans = 0;
    for (int x : st) {
        int s = 0;
        // 统计 (x, x + k] 的个数
        // upper_bound 找的是 (-∞, k] 的范围
        s += upper_bound(nums.begin(), nums.end(), 1LL * x + k) - upper_bound(nums.begin(), nums.end(), 1LL * x);
        
        // 统计 [x - k, x) 的个数
        // lower_bound 找的是 (-∞, k) 的范围
        s += lower_bound(nums.begin(), nums.end(), 1LL * x) - lower_bound(nums.begin(), nums.end(), 1LL * x - k);
        
        s = min(s, numOperations);
        ans = max(ans, s + cnt[x]);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
