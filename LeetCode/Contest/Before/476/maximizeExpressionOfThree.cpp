#include <bits/stdc++.h>
using i64 = long long;
using namespace std;


int maximizeExpressionOfThree(vector<int>& nums) {
    int n = nums.size();
    ranges::sort(nums);
    
    return nums[n - 1] + nums[n - 2] - nums[0];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
