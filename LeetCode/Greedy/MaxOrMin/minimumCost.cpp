#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int minimumCost(vector<int>& nums) {
    int ans = nums[0];
    vector<int> a(nums.begin() + 1, nums.end());

    sort(a.begin(), a.end());
    ans += a[0];
    ans += a[1];

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
