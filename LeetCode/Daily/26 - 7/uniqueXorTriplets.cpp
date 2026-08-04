#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int uniqueXorTriplets(vector<int>& nums) {
    int n = nums.size();
    ranges::sort(nums);

    unsigned int x = nums[n - 1], y = nums[n - 2];
    int l1 = bit_width(x), l2 = bit_width(y);
    int ans = pow(2, l1);
    if (l1 > l2) return ans - 1;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}