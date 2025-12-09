#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int longestSubarray(vector<int>& nums) {
    int n = nums.size();
    vector<int> pre(n), suf(n);

    int s = 0;
    for (int i = 1; i < n; i++) {
        pre[i] = s;
        if (nums[i] >= nums[i - 1]) {
            s++;
        } else {
            s = 1;
        }
    }

    s = 0;
    for (int i = n - 2; i >= 0; i--) {
        suf[i] = s;
        if (nums[i] <= nums[i + 1]) {
            s++;
        } else {
            s = 1;
        }
    }

    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
        ans = max({ans, pre[i] + 1, suf[i] + 1});
        if (nums[i + 1] >= nums[i - 1]) ans = max(ans, pre[i] + suf[i] + 1);
    }

    ans = max({pre[0] + 1, suf[n - 1] + 1, ans});
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
