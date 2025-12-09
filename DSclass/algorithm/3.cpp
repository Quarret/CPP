#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 1), dp(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    int ans = 0;
    for (int i = n; i >= 1; i--) {
        if (i + a[i] > n) {
            dp[i] = a[i];
        } else {
            dp[i] = dp[i + a[i]] + a[i];
        }

        ans = max(ans, dp[i]);
    }

    cout << ans << '\n';
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
