#include <bits/stdc++.h>
using ll = long long;
using namespace std;


int maxRotateFunction(vector<int>& nums) {
    using ll = long long;

    int n = nums.size();
    ll sum = reduce(nums.begin(), nums.end(), 0LL);
    
    // f[i] = f[i - 1] - n * nums[(n - 1 - (i - 1)) % n] + sum
    vector<ll> F(n);
    for (int i = 0; i < n; i++) {
        F[0] += i * nums[i];
    }
    
    ll ans = F[0];
    for (int i = 1; i < n; i++) {
        F[i] = F[i - 1] - n * nums[((n - i) % n + n) % n] + sum;
        ans = max(ans, F[i]);
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}