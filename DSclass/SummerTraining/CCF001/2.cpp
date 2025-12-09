#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n, p;
    cin >> n >> p;

    vector<ll> k(n, 0);
    vector<bool> vis(n, 0);
    for (int i = 1; i < n; i++) {
        cin >> k[i];
    }

    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= p; i++) {
        if (i <= n) {
            dp[i] = 1;
        }   
    }

    for (int i = 1; i <= n - 1; i++) {
        if (i - k[i] >= 1) {
            dp[i - k[i]] = min(dp[i] + 1, dp[i - k[i]]);
        } else if (i + k[i] <= n) {
            dp[i + k[i]] = min(dp[i] + 1, dp[i + k[i]]);
        }
    }

    for (int j = 1; j <= n - 1; j++) {
            if (j - k[j] >= 1) {
            dp[j - k[j]] = min(dp[j] + 1, dp[j - k[j]]);
        } else if (j + k[j] <= n) {
            dp[j + k[j]] = min(dp[j] + 1, dp[j + k[j]]);
        }
    }

    if(dp[n] == 1e9) {
        cout << -1 << '\n';
    } else {
        cout << dp[n] << '\n';
    }
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
