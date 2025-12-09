#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= i; j--) {
            if ((a[i] + a[j]) % 2 == 0) {
                ans = min(ans, i + n - 1 - j);
                break;
            }
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
