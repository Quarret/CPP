#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int arrayPairSum(vector<int>& nums) {
    int ans = 0, n = nums.size();
    sort(nums.begin(), nums.end());
    
    for (int i = 0; i < n; i += 2) {
        ans += nums[i];
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
