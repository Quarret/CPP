#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector< vector<int> > a(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char x;
            cin >> x;
            a[i][j] = x - '0';
        }
    }


    for (int i = 1; i <= n; i += k) {
        for (int j = 1; j <= n; j += k) {
            cout << a[i][j];
        }
        cout << '\n';
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
