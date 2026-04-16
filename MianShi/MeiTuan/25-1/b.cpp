#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const int MOD = 998244353;

// 快速幂：计算 x^n % MOD
ll qpow(ll x, ll n) {
    ll res = 1;
    for (; n; n /= 2) {
        if (n & 1) res = res * x % MOD;  // 只有 n 为奇数时才乘
        x = x * x % MOD;
    }
    return res;
}

// 乘法逆元：使用费马小定理，q^{-1} = q^{MOD-2} (mod MOD)
ll inv(ll x) {
    return qpow(x, MOD - 2);
}

const int MAXN = 1e6 + 5;
ll variance[MAXN];  // variance[i] 表示 n=i 时的方差

// 预处理所有方差值
void init() {
    variance[1] = 0;  // n=1 时方差为 0

    for (int i = 2; i <= MAXN; i++) {
        // 方差递推公式：Var(X_n) = Var(X_{n-1}) + 2/(2n-1)^2
        ll denom = (2LL * i - 1) % MOD;
        ll denom2 = denom * denom % MOD;  // (2n-1)^2
        ll term = 2 * inv(denom2) % MOD;  // 2/(2n-1)^2
        variance[i] = (variance[i - 1] + term) % MOD;
    }
}

void solve() {
    int n;
    cin >> n;
    cout << variance[n] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();  // 预处理

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
