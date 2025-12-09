#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int minSubarray(vector<int>& nums, int p) {
    int k = 0;
    for (int x : nums) {
        k = (k + x) % p;
    }
    if (k == 0) {
        return 0;
    }
    
    int n = nums.size(), s = 0, ans = INT_MAX;
    unordered_map<int, int> mp = {{0, -1}};
    for (int i = 0; i < n; i++) {
        s = (s + nums[i]) % p;
        int target = ((s - k) % p + p) % p;

        if (mp.contains(target)) {
            ans = min(ans, i - mp[target]);
        }

        mp[s] = i;
    }

    return ans == n ? -1 : ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
