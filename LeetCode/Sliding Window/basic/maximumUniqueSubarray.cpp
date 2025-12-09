#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size(), l = 0, ans = 0, num = 0;
        unordered_map<int, int> mp;

        for (int r = 0; r < n; r++) {
            while (mp[nums[r]] == 1) {
                num -= nums[l];
                mp[nums[l]]--;
                l++;
            }

            num += nums[r];
            mp[nums[r]]++;

            ans = max(ans, num);
        }

        return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
