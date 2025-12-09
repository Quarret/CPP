#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> b(m), a(q);

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < q; i++) {
        cin >> a[i];
    }

    sort(b.begin(), b.end());

    for (int i = 0; i < q; i++) {
        auto it = lower_bound(b.begin(), b.end(), a[i]);
        

        if (it == b.begin()) {
            cout << *it - 1 << '\n';
            continue;
        } else if (it == b.end()) {
            auto it1 = prev(it);
            //cout << *it1 << '\n';
            cout << n - *it1 << '\n';
            continue;
        }

        int ans = 0;
        auto it1 = prev(it);
        int index1 = a[i] - *it1, index2 = *it - a[i];
        ans = (index1 + index2) / 2;
        cout << ans << '\n';  
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
