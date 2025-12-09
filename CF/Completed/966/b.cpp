#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<bool> vis(n + 2, 0);
    vector<int> a(n - 1);

    int tmp;
    cin >> tmp;
    vis[tmp] = true;

    for (int i = 0; i < n - 1; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; i++) {
        if (vis[a[i] - 1] == true || vis[a[i] + 1] == true) {
            vis[a[i]] = true;
        } else {
            cout << "NO" << '\n';
            return;
        }
    }

    cout << "YES" << '\n';
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
