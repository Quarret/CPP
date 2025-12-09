#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    int ans = n / 4;
    ans += (n % 4) / 2;

    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
