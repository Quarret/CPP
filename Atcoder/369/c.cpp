#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (a.size() == 1) {
        cout << 1 << '\n';
        return;
    } else if (a.size() == 2) {
        cout << 3 << '\n';
        return;
    }

    ll num = a[1] - a[0], num1 = a[1], l = 2, ans = 0;
    for (int i = 2; i < a.size(); i++) {
        if (a[i] - num1 == num) {
            l++;
        } else {
            ans += l * (l + 1) / 2 - 1;
            l = 2;
            num = a[i] - num1;
        }
        num1 = a[i];
    }
    ans += l * (l + 1) / 2;

    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
