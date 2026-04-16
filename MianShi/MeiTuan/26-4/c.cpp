#include <bits/stdc++.h>
using ll = long long;
using namespace std;


void solve() {
    int n, q;
    cin >> n >> q;

    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 0; i < q; i++) {
        int p, k;
        cin >> p >> k;
        
        ll ans = 0;
        vector<ll> cnt(n + 1);

        ll idx = p;
        while (k--) {
            cnt[idx]++;
            idx = a[idx];
        }

        for (int i = 1; i <= n; i++) {
            ans += 1LL * (1 + cnt[i]) * cnt[i] / 2 * i;
        }

        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}