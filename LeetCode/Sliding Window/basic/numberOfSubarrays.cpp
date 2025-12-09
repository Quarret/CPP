#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), l1 = 0, l2 = 0, num1 = 0, num2 = 0, ans1 = 0, ans2 = 0;

        for (int r = 0; r < n; r++) {
            num1 += nums[r] % 2;
            num2 += nums[r] % 2;

            while (num1 >= k) {
                num1 -= nums[l1] % 2;
                l1++;
            }

            while (num2 >= k + 1) {
                num2 -= nums[l2] % 2;
                l2++;
            }

            ans1 += l1;
            ans2 += l2;
        }

        return ans1 - ans2;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
