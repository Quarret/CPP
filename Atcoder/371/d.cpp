#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n, q;
    cin >> n;

    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    vector<ll> pre(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + p[i];
    }

    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        r++;

        int pos1 = lower_bound(x.begin(), x.end(), l) - x.begin();
        int pos2 = lower_bound(x.begin(), x.end(), r) - x.begin();
        //cout << pos1 << ' ' << pos2 << '\n';

        cout << pre[pos2] - pre[pos1] << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
