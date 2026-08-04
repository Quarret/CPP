#include <bits/stdc++.h>
using ll = long long;
using namespace std;


int maxValue(vector<int>& nums1, vector<int>& nums0) {
    int n = nums1.size();
    vector<int> idxs(n);
    ranges::iota(idxs, 0);

    // 没有 0 的排前面, 1 多的排前面, 0 少的排前面
    ranges::sort(idxs, {}, [&](int &i) {
        return tuple(nums0[i] != 0, -nums1[i], nums0[i]);
    });
    
    using ll = long long;
    const int MOD = 1e9 + 7;
    ll ans = 0;

    auto qpow = [&](ll x, ll n) -> ll {
        ll res = 1;
        for (; n; n /= 2) {
            if (n & 1) res = res * x % MOD;
            x = x * x % MOD;
        }
        return res;
    };

    for (int i = 0; i < n; i++) {
        int x = nums1[idxs[i]], y = nums0[idxs[i]];
        ll res = ((qpow(2, x + y) - qpow(2, y)) % MOD + MOD) % MOD;
        ans = ((ans * qpow(2, x + y)) % MOD + res) % MOD;
    }
    
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}