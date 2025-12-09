#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minimumSubarrayLength(vector<int>& nums, int k) {
    int n = nums.size(), l = 0, r = 0, or_ = 0, ans = INT32_MAX;
    int cnt[35]{};

    auto remove = [&](int x) -> void {
        for (int i = 0; i <= 31; i++) {
            if (x & (1 << i) == (1 << i)) {
                if (cnt[i] == 1) or_ ^= (1 << i);
                cnt[i]--; 
            }  
        }
    };

    for (; r < n; r++) {
        or_ |= nums[r];
        for (int i = 0; i <= 31; i++) {
            if (nums[r] & (1 << i) == (1 << i)) cnt[i]++;
        }

        while (or_ >= k) {
            ans = min(ans, r - l + 1);
            remove(nums[l++]);
        }   
    }

    return ans == INT32_MAX ? -1 : ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
