#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int longestOnes(vector<int>& nums, int k) {
    int n = nums.size(), l = 0, num1 = 0, ans = 0, num0 = 0;
    
    for (int r = 0; r < n; r++) {
        num1 += nums[r];
        num0 += nums[r] == 0;

        while (num0 > k) {
            num1 -= nums[l] == 1;
            num0 -= nums[l] == 0;
            l++;
        }

        ans = max(ans, num1 + num0);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
