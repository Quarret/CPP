#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve() {
    int x;
    cin >> x;

    if (x == 2 || x == 6) {
        cout << "koishiYun\n";
    } else {
        cout << "Kato_Shoko\n";
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
