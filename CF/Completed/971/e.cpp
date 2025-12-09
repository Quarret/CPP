#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    ll ans = 1e31, tmp;

    for (int i = 1; i <= n; i++) {
        tmp = abs(2 * k * i - k * n + i * i - i - (n - 1) * n / 2);
        ans = min(ans, tmp);
    }

    cout << ans << '\n';
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
