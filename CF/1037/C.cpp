#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    k--;

    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    int start = h[k];
    sort(h.begin(), h.end());

    int cur = 1;
    for (int i = lower_bound(h.begin(), h.end(), start) - h.begin(); i < n; i++) {
        if (h[i] != h.back()) {
            cur += abs(h[i + 1] - h[i]);
            if (cur - 1 > h[i]) {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
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
