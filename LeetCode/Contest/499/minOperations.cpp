#include <bits/stdc++.h>
using ll = long long;
using namespace std;


long long minOperations(vector<int>& nums) {
    using ll = long long;
    
    ll ans = 0, n = nums.size();
    for (int i = 0; i < n - 1; i++) {
        if (nums[i] > nums[i + 1]) {
            ans += 1LL * (nums[i] - nums[i + 1]);
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}