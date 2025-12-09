#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;

    int ans = ceil(1.0 * n / min(x, y));

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
