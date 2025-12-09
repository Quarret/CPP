#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minimumDifference(vector<int>& nums, int k) {
    int n = nums.size(), ans = INT32_MAX;
    
    for (int r = 0; r < n; r++) {
        ans = min(ans, abs(k - nums[r]));

        for (int l = r - 1; l >= 0 && (nums[r] | nums[l]) != nums[l]; l--) {
            nums[l] |= nums[r];
            ans = min(ans, abs(k - nums[l]));
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
