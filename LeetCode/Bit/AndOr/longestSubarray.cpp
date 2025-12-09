#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int longestSubarray(vector<int>& nums) {
    int ans = 0, n = nums.size();
    int maxx = *max_element(nums.begin(), nums.end());

    for (int i = 0; i < n; i++) {
        if (nums[i] == maxx) {
            int l = i, r = i;

            for (; l >= 0; l--) {
                if ((nums[l] & maxx) != maxx) {
                    l++;
                    break;
                }
            }

            for (; r < n; r++) {
                if ((nums[r] & maxx) != maxx) {
                    r--;
                    break;
                }
            }

            ans = max(ans, r - l + 1);
            i = r + 1;
        }
    }
    
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
