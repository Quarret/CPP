#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int longestBalanced(vector<int>& nums) {
    int n = nums.size();
    
    int ans = 0;
    for (int k = n; k >= 2; k--) {
        unordered_map<int, int> mp;
        int cnt1 = 0, cnt2 = 0;
        for (int r = 0, l = 0; r < n; r++) {
            if (!mp[nums[r]]) {
                nums[r] % 2 ? cnt1++ : cnt2++;
            }
            mp[nums[r]]++;

            if (r < k - 1) continue;
            if (cnt1 == cnt2) ans = max(ans, r - l + 1);
            if (mp[nums[l]] == 1) {
                nums[l] % 2 ? cnt1-- : cnt2--;
            }
            mp[nums[l]]--;
            l++;

        }

        if (ans) break;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
