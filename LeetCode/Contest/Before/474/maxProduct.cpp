#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

long long maxProduct(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    
    long long ans = INT64_MIN, minn = -1e5, maxx = 1e5;
    ans = max(ans, 1LL * nums[0] * nums[1] * minn);
    ans = max(ans, 1LL * nums[0] * nums[1] * maxx);
    ans = max(ans, 1LL * nums[n - 1] * nums[n - 2] * minn);
    ans = max(ans, 1LL * nums[n - 1] * nums[n - 2] * maxx);
    ans = max(ans, 1LL * nums[0] * nums[n - 1] * maxx);
    ans = max(ans, 1LL * nums[0] * nums[n - 1] * minn);

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
