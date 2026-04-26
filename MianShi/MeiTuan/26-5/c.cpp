#include <bits/stdc++.h>
using ll = long long;
using namespace std;


void solve() {
    int n;
    cin >> n;

    vector<int> p(n), q(n);
    unordered_map<int, int> mp1, mp2;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        mp1[p[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> q[i];
        mp2[q[i]] = i;
    }

    vector f(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            f[i + 1][j + 1] = p[i] == q[j] ? f[i][j] + 1 : max(f[i][j + 1], f[i + 1][j]);
        }
    }

    int mx = f[n][n];
    cout << mx << '\n';

    vector<int> x = p, y = q;
    vector f1(n + 1, vector<int>(n + 1, 0));
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            f1[i + 1][j + 1] = p[i] == q[j] ? f1[i][j] + 1 : max(f1[i][j + 1], f1[i + 1][j]);
        }
    }

    for (int x = n; x >= 1; x--) {
        int i = mp1[x], j = mp2[x];
        if (f[i + 1][j + 1] + f1[n - i - 1][n - j - 1] == mx) {
            cout << x << ' ';
        }
    }
    
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}