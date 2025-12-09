/*** 
 * @Author: Quarret
 * @Date: 2025-06-03 08:24:43
 * @LastEditTime: 2025-06-09 10:32:47
 */

#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long maximumSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    bool flag = 0;
    vector<long long> pre(n + 1, 0);
    for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + nums[i];

    unordered_map<int, int> mp;
    long long ans = -1e9;

    for (int j = 0; j < n; j++) {
        if (mp.contains(nums[j] - k)) {
            ans = max(ans, pre[j + 1] - pre[mp[nums[j] - k]]);
            flag = 1;
        }

        if (mp.contains(nums[j] + k)) {
            ans = max(ans, pre[j + 1] - pre[mp[nums[j] + k]]);
            flag = 1;
        }

        if (!mp.contains(nums[j])) mp[nums[j]] = j;
        else if (pre[mp[nums[j]]] > pre[j]) mp[nums[j]] = j;
    }

    return (flag == 1 ? ans : 0 );
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
