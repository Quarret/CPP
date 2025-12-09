#include <bits/stdc++.h>
using ll = long long;
using namespace std;
/*
定长滑动窗口
*/
double numOfSubarrays(vector<int>& nums, int k, int threshold) {
        double ans = 0, num = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            num += nums[i];

            if (i < k - 1) continue;

            if (num / k >= threshold) ans++;

            num -= nums[i - k + 1];
        }

        return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
