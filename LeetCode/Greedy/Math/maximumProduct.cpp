#include <bits/stdc++.h>
using i64 = long long;
using namespace std;


int maximumProduct(vector<int>& nums) {
    ranges::sort(nums);
    int n = nums.size();

    return max({nums[n - 1] * nums[n - 2] * nums[n - 3], nums[0] * nums[1] * nums[2],
                nums[0] * nums[1] * nums[n - 1]});
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
