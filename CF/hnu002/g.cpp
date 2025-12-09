#include <bits/stdc++.h>
using ll = long long;
using namespace std;

ll a[2050][2050];
ll ans[10000005];
void solve() {
    int n;
    cin >> n;

    cout << ans[n] << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll cnt = 0;
    for (int i = 1; i <= 2023; i++) {
        for (int j = 1; j <= i; j++) {
            cnt++;
            a[i][j] = cnt * cnt;
        }
    }

    for (int i = 2; i <= 2023; i++) {
        for (int j = 1; j <= i; j++) {
            a[i][j] += a[i - 1][j] + a[i - 1][j - 1] - a[i - 2][j - 1];
        }
    }

    cnt = 0;
    for (int i = 1; i <= 2023; i++) {
        for (int j = 1; j <= i; j++) {
            ans[++cnt] = a[i][j];
        }
    }

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
