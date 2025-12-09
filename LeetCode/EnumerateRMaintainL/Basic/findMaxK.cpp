/*** 
 * @Author: Quarret
 * @Date: 2025-06-04 11:50:28
 * @LastEditTime: 2025-06-04 11:52:31
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int findMaxK(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;

    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        if (mp.find(-nums[i]) != mp.end()) ans = max(ans, abs(nums[i]));
        mp[nums[i]] = 1;
    }

    return (ans == 0 ? -1 : ans);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
