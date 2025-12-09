#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n, s, m, l, r, num = 0;
    cin >> n >> s >> m;
    bool flag = false;

    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        if (l - num >= s) {
            flag = 1;
        }

        num = r;
    }

    if (m - num >= s) {
        flag = 1;
    }

    cout << (flag ? "YES\n" : "NO\n");
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
