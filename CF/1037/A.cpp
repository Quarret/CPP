#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int x;
    cin >> x;

    int ans = 10;
    while (x) {
        ans = min(ans, x % 10);
        x /= 10;
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
