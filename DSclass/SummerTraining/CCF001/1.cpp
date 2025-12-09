#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    ll n, m, sum1 = 0, sum2 = 0;
    cin >> n >> m;

    vector<int> a(n), b(m);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum1 += a[i];
    }

    for (int j = 0; j < m; j++) {
        cin >> b[j];
        sum2 += b[j];
    }

    if (sum1 > sum2) {
        cout << "Alice\n";
    } else if (sum1 == sum2) {
        cout << "Draw\n";
    } else {
        cout << "Bob\n";
    }

    
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
