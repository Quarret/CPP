#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> pre(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
    }

    string s;
    cin >> s;
    ll pos1 = 0, pos2 = n - 1, ans = 0;
    while (pos1 < pos2) {
        if (s[pos1] != 'L') {
            pos1++;
            continue;
        }

        if (s[pos2] != 'R') {
            pos2--;
            continue;
        }

        ans += pre[pos2 + 1] - pre[pos1];
        pos1++;
        pos2--;
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
