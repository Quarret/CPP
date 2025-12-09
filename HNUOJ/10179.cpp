#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin >> k;
    while (k--) {
        int n;
        cin >> n;
        vector<int> a(n + 1, 0);
        vector<int> dp(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
 
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if (a[j] <= a[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        int ans = -1;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, dp[i]);
        }

        cout << ans << '\n';
    }

    return 0;
}
