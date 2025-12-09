#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;

    if (a - b == 0) {
        cout << 1 << '\n';
    } else if (abs(a - b) % 2 == 0) {
        cout << 3 << '\n';
    } else {
        cout << 2 << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
