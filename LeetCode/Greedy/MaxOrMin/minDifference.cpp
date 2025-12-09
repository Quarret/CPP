#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int minDifference(vector<int>& nums) {
    int n = nums.size();
    if (n <= 4) return 0;

    ranges::sort(nums);
    return min({nums[n - 1] - nums[3], nums[n - 2] - nums[2], 
        nums[n - 3] - nums[1], nums[n - 4] - nums[0]});
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
