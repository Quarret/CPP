#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;  

    ll ans = 0;
    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= n / a; b++) {
            int t = min((n - a * b) / (a + b), x - a - b);
            ans += max(t, 0);
        }
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
