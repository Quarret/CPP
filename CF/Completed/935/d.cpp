#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    
    ll ans = 1e31, sum = 0;
    for (int i = 0; i < n; i++) {
        if (i >= n - m) {
           ans = min(ans, sum + a[i]);
        }
        sum += min(a[i], b[i]);
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
