#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long gcdSum(vector<int>& nums) {
    using ll = long long;
    ll mx = nums[0];

    int n = nums.size();
    vector<ll> prefixGCD(n);
    for (int i = 0; i < n; i++) {
        mx = max(mx, 1LL * nums[i]);
        prefixGCD[i] = gcd(nums[i], mx);
    }
    
    ranges::sort(prefixGCD);
    ll i = 0, j = n - 1, ans = 0;
    while (i < j) {
        cout << prefixGCD[i] << ' ' << prefixGCD[j] << '\n';
        ans += gcd(prefixGCD[i], prefixGCD[j]);
        i++;
        j--;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}