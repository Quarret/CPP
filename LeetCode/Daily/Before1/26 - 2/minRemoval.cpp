#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minRemoval(vector<int>& nums, int k) {
    int n = nums.size();
    ranges::sort(nums);

    int ans = 0, cur = 0;
    for (int r = 0, l = 0; r < n; r++) {
        while (1LL * nums[l] * k < 1LL * nums[r]) {
            l++;
        }

        ans = max(ans, r - l + 1);
    }

    return n - ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}