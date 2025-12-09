#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    vector<int> c(n);
    int MOD = gcd(a, b);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        c[i] %= MOD;
    }

    sort(c.begin(), c.end());
    int ans = c[n - 1] - c[0];
    for (int i = 0; i < n - 1; i++) {
        ans = min(ans, c[i] + MOD - c[i + 1]);
        /*
        要使极值最小，枚举所有极值情况取最小值
        c1, c2, c3, c4, c5
        原极值 = c5 - c1
        取c1, c2
        c2 c3 c4 c5 (c1 + MOD)
        ...
        
        若不取相邻的两个数c1, c3
        c1 + MOD 为极大值，但c3不是最小值.若要使c3最小，则c2 + MOD,此时c1 + MOD不再为最大值
        故矛盾

        所以为了枚举所有最小极值情况，应枚举相邻两数
        */
    }

    cout << ans << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
