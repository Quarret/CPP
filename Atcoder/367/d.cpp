#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<ll> a(n), pre(n + 1);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
    }

    ll ans = 0;
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
