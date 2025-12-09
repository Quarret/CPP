#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long zeroFilledSubarray(vector<int>& nums) {
    long long s = 0, n = nums.size(), ans = 0;
    for (int r = 0, l = 0; r < n; r++) {
        s += nums[r];

        while (s != 0) {
            s -= nums[l];
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
