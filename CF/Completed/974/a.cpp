#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int num = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= k) {
            num += a[i];
        } else if (a[i] == 0 && num != 0) {
            ans++;
            num--;
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
