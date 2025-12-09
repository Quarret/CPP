#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> nums = {10,1,2,4,7,2};
int longestSubarray(vector<int>& nums, int limit) {
    long long n = nums.size(), l = 0, ans = 0, maxx = -1, minn = 1e10;
    
    for (int r = 0; r < n; r++) {
        maxx = max(maxx, (long long)nums[r]);
        minn = min(minn, (long long)nums[r]);

        int r1 = r;
        if (abs(nums[r] - maxx) > limit || abs(nums[r] - minn) > limit) {
            maxx = -1, minn = 1e10; 
            while (abs(nums[r1] - nums[r]) <= limit) {
                maxx = max(maxx, (long long)nums[r1]);
                minn = min(minn, (long long)nums[r1]);
                r1--;
            }
        }

        l = (r1 == r ? l : r1 + 1);
        ans = max(ans, r - l + 1);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    longestSubarray(nums, 5);

    return 0;
}
