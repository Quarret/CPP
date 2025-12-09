#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int minimizeSum(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    return min({nums[n - 3] - nums[0], nums[n - 1] - nums[2], nums[n - 2] - nums[1]});
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
