#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long countSubarrays(vector<int>& nums, long long k) {
    long long n = nums.size(), l = 0, num = 0, ans = 0;
    
    for (int r = 0; r < n; r++) {
        num += nums[r];

        while (num * (r - l + 1) >= k) {
            num -= nums[l];
            l++;
        }

        ans += r - l + 1;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
