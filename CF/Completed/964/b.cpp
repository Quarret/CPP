#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int a1, a2, b1, b2, ans = 0;

    cin >> a1 >> a2 >> b1 >> b2;
    if (a1 > b1 && a2 > b2) ans++;
    if (a1 > b2 && a2 > b1) ans++;
    if (a2 > b1 && a1 > b2) ans++;
    if (a2 > b2 && a1 > b1) ans++;
    if (a1 == b1 && a2 > b2) ans += 2;
    if (a1 == b2 && a2 > b1) ans += 2;
    if (a2 == b1 && a1 > b2) ans += 2;
    if (a2 == b2 && a1 > b1) ans += 2;

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
