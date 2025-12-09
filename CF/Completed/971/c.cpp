#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int x, y, k, ans, ans1;
    cin >> x >> y >> k;

    // if (x == 0 && y == 0) {
    //     cout << 0 << '\n';
    //     return;
    // }

    ans = (x + k - 1) / k;
    ans1 = (y + k - 1) / k;

    cout << max(ans * 2 - 1, ans1 * 2) << '\n';
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
