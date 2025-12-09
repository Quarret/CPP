#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

long long maxSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, long long> mp = {{0, 0}};

    long long ans = INT64_MIN, s = 0;
    for (int i = 0; i < n; i++) {
        s = s + 1LL * nums[i];
        int pos = (i + 1) % k;

        if (mp.contains(pos)) {
            ans = max(ans, s - mp[pos]);
            mp[pos] = min(mp[pos], s);
        } else {
            mp[pos] = s;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
