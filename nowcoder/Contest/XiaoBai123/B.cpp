#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve() {
    int n;
    cin >> n;

    long long ans = 0;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        ans += 1LL * a[i];
    }

    sort(b.begin(), b.end(), greater());
    for (int i = 0; i < n; i++) {
        ans -= 1LL * b[i] * i;
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
