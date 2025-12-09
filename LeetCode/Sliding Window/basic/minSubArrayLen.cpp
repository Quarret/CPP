#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size(), l = 0, num = 0, ans = 1e9, num1 = 0, flag = 0;

    for (int r = 0; r < n; r++) {
        num1 += nums[r];
        num += nums[r];
        flag = num >= target;

        while (num >= target) {
            num -= nums[l];
            l++;
        }

        if (flag) ans = min(ans, r - l + 2);
    }

    return (num1 < target ? 0 : ans);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
