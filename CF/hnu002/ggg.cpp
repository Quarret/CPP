#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e6 + 10;
typedef long long ll;
 
ll a[2050][2050];
ll ans[maxn];
const ll mod = 1e9 + 7;
 
void solve() {
    int n;
    cin >> n;
    cout << ans[n] << endl;
 
 
}
 
int main() {
    ll cnt = 0;
    for (int i = 1; i <= 2023; i++) {
        for (int j = 1; j <= i; j++) {
            cnt++;
            a[i][j] = cnt * cnt;
        }
    }
 
    cnt = 0;
    for (int i = 2; i <= 2023; i++) {
        for (int j = 1; j <= i; j++) {
            a[i][j] += a[i - 1][j] + a[i - 1][j - 1] - a[i - 2][j - 1];
        }
    }
 
    for (int i = 1; i <= 2023; i++) {
        for (int j = 1; j <= i; j++) {
            ans[++cnt] = a[i][j];
        }
    }
//    cout << " ??? ? ";
    int T = 1;
    cin >> T;
    while (T--) solve();
}