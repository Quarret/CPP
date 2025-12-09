#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n + 1);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    sort(a.begin(), a.end());

    ll num;
    if (n % 2 == 0) {
        num = n / 2 + 1;
    } else {
        num = (n + 1) / 2;
    }
    
    if (n == 1 || n == 2) {
        cout << -1 << '\n';
        return;
    }

    ll ans = 2 * n * a[num] - sum + 1;
    if (ans <= 0) {
        cout << 0 << '\n';
    } else {
        cout << ans << '\n';
    }
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
