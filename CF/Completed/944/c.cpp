#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int a, b, c ,d;
    cin >> a >> b >> c >> d;

    bool a1[13] = {0}, a2[13] = {0};

    for (int i = min(a, b); i <= max(a, b); i++) {
        a1[i] = 1;
    }

    for (int i = 1; i <= min(a, b); i++) {
        a2[i] = 1;
    }

    for (int i = max(a, b); i <= 12; i++) {
        a2[i] = 1;
    }

    if (a1[c] && a1[d]) {
        cout << "NO" << '\n';
        return;
    }

    if (a2[c] && a2[d]) {
        cout << "NO" << '\n';
        return;
    }

    cout << "YES" << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
