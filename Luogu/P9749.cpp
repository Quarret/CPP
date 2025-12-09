#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    ll n, d;
    cin >> n >> d;
    vector<ll> a(n), b(n), c(n, 0);

    for (int i = 1 ; i <= n - 1; i++) {
        cin >> a[i];
        c[i] = c[i - 1] + a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    ll ans = 0, num = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (b[j] >= b[i] && j != n - 1) {
                continue;
            }

            ll tmp = ceil((1.0 * (c[j] - c[i]) - num) / d);
            ans += b[i] * tmp;
            num = d * tmp + num - (c[j] - c[i]);

            i = j - 1;

            break;
        }
    }

    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
