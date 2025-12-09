#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int longestSubarray(vector<int>& nums) {
    int ans = 0, n = nums.size(), s = 0;
    for (int r = 0, l = 0; r < n; r++) {
        s += nums[r] == 0;

        while (s > 1) {
            s -= nums[l] == 0;
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
