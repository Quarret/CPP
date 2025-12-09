#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size(), l = 0, num = 1, ans = 0;

        if (k == 0) return 0;
        
        for (int r = 0; r < n; r++) {
            num *= nums[r];

            while (num >= k) {
                num /= nums[l];
                l++;
            }

            ans += r - l + 1;
        }

        return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
