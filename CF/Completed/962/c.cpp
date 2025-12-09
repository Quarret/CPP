#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;

    string a, b;
    cin >> a >> b;

    vector< vector<int> > pre1(n + 1, vector<int>(26, 0));
    vector< vector<int> > pre2(n + 1, vector<int>(26, 0));

    for (int i = 1; i <= n; i++) {
        pre1[i][a[i - 1] - 'a']++;
        for (int j = 0; j < 26; j++) {
            pre1[i][j] += pre1[i - 1][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        pre2[i][b[i - 1] - 'a']++;
        for (int j = 0; j < 26; j++) {
            pre2[i][j] += pre2[i - 1][j];
        }
    }

    
    while (q--) {
        int ans = 0;
        int l, r;
        cin >> l >> r;

        for (int i = 0; i < 26; i++) {
            int u = pre1[r][i] - pre1[l - 1][i];
            int v = pre2[r][i] - pre2[l - 1][i];

            ans += abs(u - v);
        }

        cout << ans / 2 << '\n';
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
