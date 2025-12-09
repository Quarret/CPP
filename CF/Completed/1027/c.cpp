#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];

    int minn = a[0], ans = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] - minn > 1) {
            ans++;
            minn = a[i];
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
