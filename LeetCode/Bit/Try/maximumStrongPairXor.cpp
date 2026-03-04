#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maximumStrongPairXor(vector<int>& nums) {
    int n = nums.size();
    ranges::sort(nums);

    int ans = 0;
    for (int i = 21; i >= 0; i--) {
        int target = (ans >> i) | 1;
        unordered_map<int, int> mp;

        int ok = 0;
        for (int r = 0, l = 0; r < n; r++) {
            int x = nums[r];
            while (l < n && x > 2 * nums[l]) {
                mp[nums[l] >> i]--;
                l++;
            }

            x >>= i;
            if (mp[target ^ x]) {
                ok = 1;
                break;
            }
            mp[x]++;
        }

        if (ok) ans |= 1 << i;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}