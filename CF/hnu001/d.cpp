#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> pre(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
    }

    auto query = [&](int l, int r, int k) {
        int u = ((r - l + 1) % 2) * (k % 2);
        int v = pre[l - 1] % 2;
        int m = (pre[n] - pre[r]) % 2;

        return (u + v + m) % 2;
    };

    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;

        bool flag = query(l, r, k);

        cout << (flag == 1 ? "YES" : "NO") << '\n';
    }
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
