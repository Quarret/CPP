#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int minOperations(vector<int>& nums) {
    int n = nums.size(), ans = 0;
    for (int i = 1; i < n; i++) {
        ans += max(nums[i - 1] + 1 - nums[i], 0);
        nums[i] = max(nums[i - 1] + 1, nums[i]);
    }
    
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
