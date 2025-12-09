#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> nums = {10,1};
int minimizeArrayValue(vector<int>& nums) {
    int n = nums.size();
    long long l = -1, r = *max_element(nums.begin(), nums.end()) + 1, mid = 0;

    auto check = [&](long long k) -> bool {
        long long diff = 0;
        for (int i = n - 1; i >= 1; i--) {
            if (nums[i] > k) diff += nums[i] - k;
            else {
                diff -= k - nums[i];
                diff = max((long long)0, diff);
            }
        }

        return nums[0] + diff <= k;
    };

    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        (check(mid) ? r : l) = mid;
    }

    return r;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    minimizeArrayValue(nums);

    return 0;
}
