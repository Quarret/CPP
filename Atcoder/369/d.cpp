#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector< vector<ll> > dp(n + 1, vector<ll>(2, 0));

    dp[1][1] = a[1], dp[1][0] = 0;
    for (int i = 2; i <= n; i++) {
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + a[i]);
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + 2 * a[i]);
    }

    cout << max(dp[n][0], dp[n][1]) << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
