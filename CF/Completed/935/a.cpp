#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if (c < 3 - (b % 3) && b % 3 != 0) {
        cout << -1 << '\n';
        return;
    }
    
    ll ans = 0;
    ans += a;
    ans += b / 3;
    ans += (b % 3 + c) / 3;
    ans += ((b % 3 + c) % 3 ? 1 : 0);

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
