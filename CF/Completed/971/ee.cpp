#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {//看到n == 1e9,就确定用二分法了
    ll n, k;
    cin >> n >> k;

    ll sum = n * (k + k + n - 1) / 2;
    ll ans = sum;

    int l = 0, r = n;
    while (l < r) {
        ll x = (l + r + 1) / 2;
        ll s = x * (k + k + x - 1) / 2;

        if (s <= sum - s) {
            l = x;
        } else {
            r = x - 1;
        }
    }

    for (auto& it : {l, l + 1}) {
        if (it > n) {
            continue;
        }

        ll s = it * (k + k + it - 1) / 2;
        ans = min(ans, abs(sum - s - s));
    }

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
