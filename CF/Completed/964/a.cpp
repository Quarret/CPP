#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n, ans = 0;
    cin >> n;

    while (n) {
        ans += n % 10;
        n /= 10;
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
