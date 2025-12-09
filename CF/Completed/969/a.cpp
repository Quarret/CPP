#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int l, r;
    cin >> l >> r;

    int cnt = 0;
    for (int i = l; i <= r; i++) {
        if (i % 2) cnt++;
    }

    cout << cnt / 2 << '\n';
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
