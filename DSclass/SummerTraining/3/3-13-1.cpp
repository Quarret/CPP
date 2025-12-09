#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int k;
    cin >> k;
    vector<int> dp(k, 1), num(k);

    for (int i = 0; i < k; i++) {
        cin >> num[i];
    }
    //reverse(num.begin(), num.end());

    for (int i = 1; i < k; i++) {
        for (int j = 0; j < i; j++) {
            if (num[i] >= num[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int ans = 0;
    for (int l : dp) {
        ans = max(ans, l);
    }

    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}
