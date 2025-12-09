#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maxSubarrayLength(vector<int>& nums, int k){
    int n = nums.size(), l = 0, ans = 0;
    unordered_map<int, int> mp;

    for (int r = 0; r < n; r++) {
        while (mp[nums[r]] == k) {
            mp[nums[l]]--;
            l++;
        }

        mp[nums[r]]++;

        ans = max(ans, r - l + 1);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
