#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int func(vector<int>& nums, int k) {
    int n = nums.size(), l = 0, num = 0, ans = 0;
    unordered_map<int, int> mp;

    for (int r = 0; r < n; r++) {
        if (!mp[nums[r]]) num++;
        mp[nums[r]]++;

        while (num >= k) {
            mp[nums[l]]--;
            if (!mp[nums[l]]) num--;
            l++;
        }

        ans += l;
    }

    return ans;
}
int subarraysWithKDistinct(vector<int>& nums, int k) {
        return func(nums, k) - func(nums, k + 1); 
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
