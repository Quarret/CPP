#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n, sum1 = 0, sum2 = 0, tmp;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> tmp;

        if (tmp % 2) {
            sum1 += tmp;
        } else {
            sum2 += tmp;
        }
    }

    cout << (sum2 > sum1 ? "YES" : "NO") << '\n';
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
