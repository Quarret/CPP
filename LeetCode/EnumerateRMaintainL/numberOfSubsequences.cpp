#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> nums = {3,4,3,4,3,4,3,4};
long long numberOfSubsequences(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, long long> mp;
    long long ans = 0;

    // for (int q = n - 5; q >= 2; q--) {
    //     for (int s = q + 4; s < n; s++) {
    //         mp[nums[q] * nums[s]]++;
    //     }

    //     for (int p = 0; p <= q - 2; p++) {
    //         ans += mp[nums[p] * nums[q + 2]];
    //     }
    // }

    for (int q = 2; q <= n - 5; q++) {
        for (int s = q + 4; s < n; s++) {
            mp[nums[q] * nums[s]]++;
        }

        for (int p = 0; p <= q - 2; p++) {
            ans += mp[nums[p] * nums[q + 2]];
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    numberOfSubsequences(nums);

    return 0;
}
