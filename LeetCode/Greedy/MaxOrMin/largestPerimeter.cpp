#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

long long largestPerimeter(vector<int>& nums) {
    long long ans = -1;
    int n = nums.size();
    sort(nums.begin(), nums.end(), greater());
    long long sum = 0;
    for (int x : nums) {
        sum += 1LL * x;
    }


    for (int i = 0; i < n; i++) {
        sum -= 1LL * nums[i];
        if (nums[i] < sum) {
            ans = max(ans, sum + 1LL * nums[i]);
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
