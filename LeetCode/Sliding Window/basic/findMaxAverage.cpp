#include <bits/stdc++.h>
using ll = long long;
using namespace std;
/*
定长滑动窗口
*/
double findMaxAverage(vector<int>& nums, int k) {
        double ans = -1e9, num = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            num += nums[i];

            if (i < k - 1) continue;

            ans = max(ans, num / k);

            num -= nums[i - k + 1];
        }

        return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
