#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int maxx = *max_element(a.begin(), a.end());

    while (m--) {
        char pos;
        int l, r;
        cin >> pos >> l >> r;

        if (l <= maxx && maxx <= r) {
            maxx += pos == '+' ? 1 : -1;
        }

        cout << maxx << " \n"[m == 0];
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
