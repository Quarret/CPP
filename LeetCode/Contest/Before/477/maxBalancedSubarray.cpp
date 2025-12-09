#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int maxBalancedSubarray(vector<int>& nums) {
    int cnt0 = 0, cnt1 = 0, XOR = 0, n = nums.size();
    map<pair<int, int>, int> mp;
    mp[{0, 0}] = -1;
    
    int ans = 0;
    for (int r = 0; r < n; r++) {
        if (nums[r] % 2) {
            cnt1++;
        } else {
            cnt0++;
        }

        XOR ^= nums[r];
        if (mp.contains({cnt1 - cnt0, XOR})) {
            ans = max(ans, r - mp[{cnt1 - cnt0, XOR}]);
        } else {
            mp[{cnt1 - cnt0, XOR}] = r;
        }
    }
    
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
