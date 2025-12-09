#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int num, n;
void solve() {
    cin >> n;
    vector<int> a(n, 0);
    vector<int> dp(num + 1, 10000);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    for (int i = 1; i <= num; i++) {
        for (int j = 0; j < n; j++) {
            if (a[j] <= i) {
                dp[i] = min(dp[i - a[j]] + 1, dp[i]);
            }
        }
    }

    if (dp[num] == 10000) {
        cout << "Impossible" << '\n';
    } else {
        cout << dp[num] << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    
    while (cin >> num && num) {
        solve();
    }
}
