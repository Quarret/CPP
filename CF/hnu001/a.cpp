#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    if (a + b == c) {
        cout << '+' << '\n';
    } else {
        cout << '-' << '\n';
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
