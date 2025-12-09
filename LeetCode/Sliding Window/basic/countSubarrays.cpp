#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long countSubarrays(vector<int>& nums, int k) {
        long long n = nums.size(), l = 0, ans = 0, num = 0, maxx = 0;

        for (int i = 0; i < n; i++) maxx = max(maxx , (long long)nums[i]);

        for (int r = 0; r < n; r++) {
            num += nums[r] == maxx;

            while (num == k) {
                num -= nums[l] == maxx;
                l++;
            }

            ans += l;
        }
        
        return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
