#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

bool canMakeEqual(vector<int>& nums, int k) {
    int n = nums.size(), cnt1 = 0, cnt2 = 0;
    
    vector<int> nums1(nums.begin(), nums.end());
    for (int i = 0; i < n - 1; i++) {
        if (nums1[i] != 1) {
            nums1[i] = -nums[i];
            nums1[i + 1] = -nums1[i + 1];
            cnt1++;
        }
    }
    if (nums1.back() != 1) cnt1 = INT_MAX;

    vector<int> nums2(nums.begin(), nums.end());
    for (int i = 0; i < n - 1; i++) {
        if (nums2[i] != -1) {
            nums2[i] = -nums[i];
            nums2[i + 1] = -nums2[i + 1];
            cnt2++;
        }
    }
    if (nums2.back() != -1) cnt2 = INT_MAX;

    return min(cnt1, cnt2) <= k;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
