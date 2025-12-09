#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    if (c == 0) c = 24;

    if (a <= b) {
        if (c >= a && c <= b) {
            cout << "No\n";
            return;
        } else {
            cout << "Yes\n";
            return;
        }
    } else {
        b += 24;
        if (c >= a && c <= b) {
            cout << "No\n";
            return;
        } else {
            cout << "Yes\n";
            return;
        }
    }

    cout << "No\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
