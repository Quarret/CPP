/*** 
 * @Author: Quarret
 * @Date: 2025-06-04 12:06:58
 * @LastEditTime: 2025-06-04 12:10:24
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<vector<int>> pairSums(vector<int>& nums, int target) {
    int n = nums.size();
    vector<vector<int>> ans;

    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        if (mp.find(target - nums[i]) != mp.end() && mp[target - nums[i]]) {
            ans.push_back({nums[i], target - nums[i]});
            mp[target - nums[i]]--;
        } else mp[nums[i]]++;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
