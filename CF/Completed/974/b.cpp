#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    int cnt = 0;

    int num = n - k + 1;
    if (num % 2 == 0) {
        cnt = k / 2;
    } else {
        cnt = (k + 1) / 2;
    }

    //cout << cnt << '\n';
    cout << (cnt % 2 == 0 ? "YES\n" : "NO\n");
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
