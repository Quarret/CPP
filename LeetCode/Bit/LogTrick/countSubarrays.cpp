#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> nums = {85,14,26,17,86,94};
/*
7/16
这里的logtrick还是不明白，后续还要看灵神题解来理解
logtrick : (nums[j] & nums[i]) != nums[j];
*/
long long countSubarrays(vector<int>& nums, int k) {
    long long n = nums.size(), ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i - 1; j >= 0 && (nums[j] & nums[i]) != nums[j]; j--) {
            nums[j] &= nums[i];
        }

        //由于区间与后的数组具有单调性，利用二分查找
        ans += upper_bound(nums.begin(), nums.begin() + i + 1, k) - lower_bound(nums.begin(), nums.begin() + i + 1, k);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    countSubarrays(nums, 14);

    return 0;
}
