#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, num = 0, l = 0;
        for (int r = 0; r < n; r++) {
            num += nums[r] == 0;

            while (num > 2) {
                num -= nums[l] == 0;
                l++;
            }

            ans = max(ans, r - l);
        }

        return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
