#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

long long maximumMedianSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    
    int n = nums.size() / 3;
    long long ans = 0;
    for (int i = n; i < nums.size(); i += 2) {
        ans += 1LL * nums[i];
    }
    
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
