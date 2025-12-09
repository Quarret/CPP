#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll n, k, num, maxx = (ll)-1e15;
    const ll mod = (ll) 1e9 + 7;
    cin >> n >> k;
    vector<ll> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> num;
        a[i] = a[i - 1] + num;
        maxx = max(maxx, max(a[i], num));
    }

    ll ans = a[n] % mod;
    
    if (maxx > 0) {
       /*for (int i = 0; i < k; i++) {
           ans += (1 << i) * maxx;//对maxx单独乘2操作 及解决了2^k 和 maxx过大的问题
           ans %= mod;
       }*/

       for (int i = 0; i < k; i++) {
           ans = (ans + maxx) % mod;
           maxx = (2 * maxx) % mod;
        }    
    }
    
    ans = ans % mod + mod;
    ans %= mod;
    
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
