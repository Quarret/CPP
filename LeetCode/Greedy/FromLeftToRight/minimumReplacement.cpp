#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

long long minimumReplacement(vector<int>& nums) {
    int n = nums.size();
    long long ans = 0;

    for (int i = n - 1; i >= 1; i--) {
        if (nums[i] >= nums[i - 1]) continue;

        int cnt = (nums[i - 1] + nums[i] - 1) / nums[i];
        ans += cnt - 1;
        nums[i - 1] /= cnt;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
