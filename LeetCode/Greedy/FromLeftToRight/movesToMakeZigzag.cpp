#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int movesToMakeZigzag(vector<int>& nums) {
    int ans1 = 0, ans2 = 0;
    int n = nums.size();

    // 1 上升
    int flag = 1;
    vector<int> nums1(nums);
    for (int i = 1; i < n; i++) {
        if (flag) {
            ans1 += max(nums1[i - 1]  - (nums1[i] - 1), 0);
            nums1[i - 1] = min(nums1[i - 1], nums1[i] - 1);
        } else {
            ans1 += max(nums1[i] - (nums1[i - 1] - 1), 0);
            nums1[i] = min(nums1[i], nums1[i - 1] - 1);
        }
        flag ^= 1;
    }
    
    flag = 0;
    vector<int> nums2(nums);
    for (int i = 1; i < n; i++) {
        if (flag) {
            ans2 += max(nums2[i - 1]  - (nums2[i] - 1), 0);
            nums2[i - 1] = min(nums2[i - 1], nums2[i] - 1);
        } else {
            ans2 += max(nums2[i] - (nums2[i - 1] - 1), 0);
            nums2[i] = min(nums2[i], nums2[i - 1] - 1);
        }
        flag ^= 1;
    }
    
    return min(ans1, ans2);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    
    return 0;
}
