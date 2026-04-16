#include <bits/stdc++.h>
using ll = long long;
using namespace std;


void solve() {
    int n, q;
    cin >> n >> q;

    ll cnt = 0;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt += a[i] == 0;
    }

    ll s = accumulate(a.begin(), a.end(), 0LL);

    ll l = 0, r = 0;
    for (int i = 0; i < q; i++) {
        cin >> l >> r;
        cout << s + l * cnt << ' ' << s + r * cnt << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}