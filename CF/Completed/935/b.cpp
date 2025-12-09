#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll a, b, m;
    cin >> a >> b >> m;

    ll ans = 0;
    ans += m / a;
    ans += m / b;
    ans += 2;

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
