#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int dp[105][3];
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        //cout << a[i] << ' ';
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            dp[i][j] = 10000;
        }
    }

    
    dp[0][0] = 1;
    if (a[0] == 1) {
        dp[0][1] = 0;
    } else if (a[0] == 2) {
        dp[0][2] = 0;
    } else if (a[0] == 3) {
        dp[0][1] = 0;
        dp[0][2] = 0;
    }

    for (int i = 1; i < n; i++) {
        if (a[i] == 1) {
            dp[i][1] = min(dp[i - 1][2], dp[i - 1][0]);
        } else if (a[i] == 2) {
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
        } else if (a[i] == 3) {
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
        }
        dp[i][0] = 1 + min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2]));
    }

    cout << min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2])) << '\n';

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}
