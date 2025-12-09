#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n, p1, p2, p3, t1, t2;
    cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;

    vector< pair<int, int> > a(n);
    int l, r;

    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        a[i].first = l;
        a[i].second = r;
    }

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        ans += p1 * (a[i].second - a[i].first);
        if (i != n - 1) {
            int num = a[i + 1].first - a[i].second;
            if (num <= t1) {
                ans += num * p1;
            } else if (num > t1 && num <= t1 + t2) {
                ans += t1 * p1 + p2 * (num - t1);
            } else {
                ans += t1 * p1 + t2 * p2 + p3 * (num - t1 - t2);
            }
        }
    }

    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}
