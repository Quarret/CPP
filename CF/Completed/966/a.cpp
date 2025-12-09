#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int a;
    cin >> a;

    string s = to_string(a);
    if (s.size() <= 2) {
        cout << "NO" << '\n';
        return;
    }

    string s1 = s.substr(0, 2), s2 = s.substr(2, s.size() - 2);

    if (s1 != "10") {
        cout << "NO" << '\n';
        return;
    } else if (s2[0] == '0' || (s2.size() == 1 && s2[0] == '1')) {
        cout << "NO" << '\n';
        return;
    }

    cout << "YES" << '\n';
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
