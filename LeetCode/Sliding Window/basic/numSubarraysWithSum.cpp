#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int func(vector<int>& nums, int k) {
    int n = nums.size(), l = 0, num = 0, ans = 0;

    for (int r = 0; r < n; r++) {
        num += nums[r];

        while (num >= k) {
            num -= nums[l];
            l++;
        }

        ans += l;
    }

    return ans;
}
int numSubarraysWithSum(vector<int>& nums, int goal) {
        return func(nums, goal) - func(nums, goal + 1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
