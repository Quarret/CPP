#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    ll n, q;
    cin >> n >> q;
    const ll N = (n - 1) * n / 2;

    vector<ll> x(n + 1);
    for (ll i = 1; i <= n; i++) {
        cin >> x[i];
    }

    map<ll, ll> mp;
    for (ll i = 1; i < n; i++) {
        ll num1 = (i - 2) * (i - 1) / 2;
        ll num2 = (n - i - 1) * (n - i) / 2;
        ll num = N - num1 - num2;
        mp[num] += 1;

        ll num3 = num - i + 1;
        mp[num3] += x[i + 1] - x[i] - 1;
    }
    mp[n - 1]++;

    while (q--) {
        ll k;
        cin >> k;
        cout << mp[k] << ' ';
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
