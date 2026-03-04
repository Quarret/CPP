#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minimumDifference(vector<int>& nums, int k) {
    ranges::sort(nums);

    int ans = INT_MAX, n = nums.size();
    for (int i = 0; i < n; i++) {
        if (i + k - 1 >= n) break;
        ans = min(ans, nums[i + k - 1] - nums[i]);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}