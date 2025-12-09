#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    if (n < 2) {
        cout << 0 << ' ' << 1 << '\n';
        return;
    }

    vector<vector<int>> dp(n, vector<int>(n));
    
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    int maxlen = 1, begin = 0;
    
    for (int l = 2; l <= n; l++) {
        for (int i = 0; i < n; i++) {

            int j = i + l - 1;

            if (j >= n) {
                break;
            }

            if (s[i] != s[j]) {
                dp[i][j] = 0;
            } else {
                if (j - i < 3) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i + 1][j - 1];
                }
            }

            if (dp[i][j] && j - i + 1 > maxlen) {
                maxlen = j - i + 1;
                begin = i;
            }
        }
    }

    cout << begin << ' ' << maxlen << '\n';
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
