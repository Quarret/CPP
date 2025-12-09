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

    int ans = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) cnt++;
        else cnt = 0;

        if (cnt == k) {
            cnt = 0;
            ans++;
            i++;
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
