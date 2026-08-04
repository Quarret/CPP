#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// 根号优化
int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
    using ll = long long;
    const int MOD = 1e9 + 7;

    int n = nums.size();
    int B = sqrt(queries.size());
    vector<vector<int>> diff(B);

    auto qpow = [&](ll x, ll n) -> ll {
        ll res = 1;
        while (n) {
            if (n % 2) res = res * x % MOD;
            x = x * x % MOD;
            n /= 2;
        }

        return res;
    };


    for (auto &q : queries) {
        int l = q[0], r = q[1], k = q[2];
        ll v = q[3];

        if (k < B) {
            if (diff[k].empty()) {
                diff[k].resize(n + k, 1);
            }
            diff[k][l] = diff[k][l] * v % MOD;
            r = r - (r - l) % k + k;
            diff[k][r] = diff[k][r] * qpow(v, MOD - 2) % MOD; // 费马小定理, a / b 同余 a * b ^ (MOD - 2) % MOD
        } else {
            for (int i = l; i <= r; i += k) {
                nums[i] = nums[i] * v % MOD;
            }
        }
    }

    for (int k = 1; k < B; k++) {
        auto &d = diff[k];
        if (d.empty()) continue;

        for (int start = 0; start < k; start++) { // diff 数组的开始
            ll mul_d = 1;
            for (int i = start; i < n; i += k) { // nums 数组的开始 
                mul_d = mul_d * d[i] % MOD;
                nums[i] = nums[i] * mul_d % MOD;
            }
        }
    }

    return reduce(nums.begin(), nums.end(), 0, bit_xor());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}