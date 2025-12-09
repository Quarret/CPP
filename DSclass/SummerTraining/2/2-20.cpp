#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n, a, b;
    string s, s1, s2;
    cin >> n >> a >> b;
    cin >> s;
    s = ' ' + s;
    vector<int> dp(n + 1);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + a;
        for (int j = 1; j <= i - 1; j++) {
            s1 = s.substr(1, j);
            s2 = s.substr(j + 1, i - j);
            //cout << s1 << ' ' << s2 << '\n';
            if (s1.find(s2) != -1) {
                dp[i] = min(dp[i], dp[j] + b);
            }
        }
    }

    cout << dp[n] << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}
