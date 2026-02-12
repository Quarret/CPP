#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maximumAND(vector<int>& nums, int k, int m) {
    using ll = long long;

    int n = nums.size();
    vector<int> ops(n, 0);

    ll ans = 0;
    for (int i = 30; i >= 0; i--) {
        int target = ans | (1 << i);
        
        for (int t = 0; t < n; t++) {
            ll x = nums[t];
            // uint 是关键, 不然会溢出到负数
            ll j = __bit_width((uint32_t) target & (~x));
            ll mask = (1LL << j) - 1;
            ops[t] = (target & mask) - (x & mask);
        }

        ranges::sort(ops);
        ll s = reduce(ops.begin(), ops.begin() + m, 0LL);
        if (s <= k) {
            ans = target;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}