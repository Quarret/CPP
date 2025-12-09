#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int maxx = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            ans++;
        } else ans = 0;
        maxx = max(maxx, ans);
    }

    cout << maxx << '\n';
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
