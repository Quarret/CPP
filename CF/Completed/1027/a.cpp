#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    string s;
    cin >> s;
    int num = stoi(s), num1 = sqrt(num);

    if (num1* num1 != num) cout << -1 << '\n';
    else cout << 0 << ' ' << num1 << '\n';
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
