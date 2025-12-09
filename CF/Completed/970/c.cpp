#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int l, r;
    cin >> l >> r;

    int num = r - l, ans;

    for (int i = 0; i <= 1000000; i++) {
        if (i * (i + 1) / 2 > num) {
            ans = i - 1;
            break;
        } else if (i * (i + 1) / 2 == num) {
            ans = i;
            break;
        }
    }

    cout << ans + 1 << '\n';
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
