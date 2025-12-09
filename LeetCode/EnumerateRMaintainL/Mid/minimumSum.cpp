#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minimumSum(vector<int>& nums) {
    int n = nums.size();
    vector<int> suf(n, 0);
    int minn = nums.back(), ans = 1e9;

    suf.back() = nums.back();
    for (int i = n - 2; i >= 0; i--) {
        suf[i] = minn;
        minn = min(minn, nums[i]);
    }

    minn = nums[0];
    for (int i  = 1; i < n - 1; i++) {// 枚举j
        if (nums[i] > minn && nums[i] > suf[i]) ans = min(ans, nums[i] + minn + suf[i]);
        minn = min(minn, nums[i]);
    }

    return (ans == 1e9 ? -1 : ans);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
