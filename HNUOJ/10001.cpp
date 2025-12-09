#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), dp(n, 1);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (a[j] < a[i]) {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
    }

    int ans = -1;
    for (int i = 0; i < n; i++) {
        ans = max(dp[i], ans);
    }

    cout << ans << '\n';

    return 0;
}