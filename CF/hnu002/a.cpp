#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    string s;
    cin >> s;
    string tmp = "codeforces";

    int ans = 0;
    for (int i = 0; i < 10; i++) {
        if (s[i] != tmp[i]) {
            ans++;
        }
    }

    cout << ans << '\n';
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
