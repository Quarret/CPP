/*** 
 * @Author: Quarret
 * @Date: 2025-06-04 16:37:08
 * @LastEditTime: 2025-06-04 16:39:35
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    int n = nums1.size(), ans = 0;
    unordered_map<long long, int> mp;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mp[1LL * (nums1[i] + nums2[j])]++;
        }
    }

    for (int k = 0; k < n; k++) {
        for (int l = 0; l < n; l++) {
            ans += mp[-1LL * (nums3[k] + nums4[l])];
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
