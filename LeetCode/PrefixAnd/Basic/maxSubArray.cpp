#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];

    int pre = 0, minn = 0, ans = -1e9 - 5;

    for (int i = 0; i < n; i++) {
        pre = pre + nums[i];
        ans = max(ans, pre - minn);
        minn = min(minn, pre);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
