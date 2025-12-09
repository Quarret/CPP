#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

long long maxAlternatingSum(vector<int>& nums) {
    long long ans = 0, n = nums.size();
    for (int i = 0; i < n; i++) {
        nums[i] = abs(nums[i]);
    }
    sort(nums.begin(), nums.end(), greater());
    int m = n / 2;
    
    for (int i = 0; i < n; i++) {
        if (i < m) {
            ans += 1LL * nums[i] * nums[i];
        } else if (i == m) {
            if (n % 2) ans += 1LL * nums[i] * nums[i];
            else ans -= 1LL * nums[i] * nums[i];
        } else {
            ans -= 1LL * nums[i] * nums[i];
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
