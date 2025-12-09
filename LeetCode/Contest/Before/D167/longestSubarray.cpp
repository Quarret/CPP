#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int longestSubarray(vector<int>& nums) {
    int n = nums.size();
    int l = 0, mid = 1, len = 2;
    
    int ans = 0;
    for (int r = 2; r < n; r++) {
        if (nums[l] + nums[mid] == nums[r]) {
            len++;
        } else {
            len = 2;
        }
        l = mid;
        mid = r;
        ans = max(ans, len);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
