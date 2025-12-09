#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int maxGoodNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end(), [&](int &x, int &y) {
        int n = __bit_width(x), m = __bit_width(y);
        return (x << m | y) > (y << n | x);
    });
    
    int ans = nums[0];
    for (int i = 1; i < 3; i++) {
        ans = ans << __bit_width(nums[i]) | nums[i];
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
