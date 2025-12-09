/*** 
 * @Author: Quarret
 * @Date: 2025-06-10 15:43:54
 * @LastEditTime: 2025-06-10 15:59:14
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maxNonOverlapping(vector<int>& nums, int target) {
    int n = nums.size(), suf = 0, pre = 0;
    unordered_map<int, int> mp1, mp2;
    mp1[0] = 1, mp2[0] = 1;
    for (int i = n - 1; i >= 0; i--) {
        suf += nums[i];
        mp2[suf]++;
    }

    int ans = 0, sum = suf;
    for (int i = 0; i < n; i++) {
        mp2[suf]--;
        suf -= nums[i];
        pre += nums[i];
        if (mp1[pre - target] != 0) ans += mp1[pre - target];
        mp1[pre]++;
        
        int rest = sum - pre;
        if (mp2[rest - target] != 0) ans += mp2[rest - target];
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
