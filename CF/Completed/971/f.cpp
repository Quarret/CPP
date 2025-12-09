#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n), pre(n + 1, 0);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
    }

/*
1 2 3 2 3 1 3 1 2 1 2 3

m = 5
u = 1, v = 2
u + v = 3
pre[3] - pre[1]

m = 4
u = 1, v = 1


m = 8
u = 2, v = 2
u + v = 4
pre[3] - pre[2] + pre[1]


*/
    auto query = [&](ll m) {
        int u = m / n;//几个循环
        ll res = u * pre[n];
        int v = m % n;//

        if (v > 0) {
            if (v + u <= n) {
                res += pre[v + u] - pre[u];
            } else {
                res += pre[v + u - n] + pre[n] - pre[u];
            }
        }
        return res;
    };

    ll l, r;
    while (q--) {
        cin >> l >> r;
        l--;
        
        cout << query(r) - query(l) << '\n';
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
