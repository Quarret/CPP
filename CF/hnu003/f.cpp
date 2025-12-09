#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll MOD = 998244353;
ll qpow(ll x, ll y, ll p) {
    ll ret = 1;
    while (y) {
        if (y & 1) {
            ret = ret * x % p;
        }
        x = x * x % MOD;
        y >>= 1;
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    vector<ll> x(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        sum = (sum + x[i]) % MOD;
    }

    cout << (ll)sum * qpow(n, MOD - 2, MOD) % MOD << '\n';

    return 0;
}
