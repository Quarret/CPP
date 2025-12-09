#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    int q;
    cin >> q;

    ll count = 0;
    for (int i = 0; i < n - 3; i++) {
        count += s.substr(i, 4) == "1100";
    }

    while (q--) {
        int i, v;
        cin >> i >> v;
        i--;

        int before = 0, after = 0;
        for (int j = max(0, i - 3); j < min(n, i + 3); j++) {
            before += s.substr(j, 4) == "1100";
        }

        s[i] = '0' + v;
        for (int j = max(0, i - 3); j < min(n, i + 3); j++) {
            after += s.substr(j, 4) == "1100";
        }

        count += after - before;

        cout << (count > 0 ? "YES" : "NO") << '\n';
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
