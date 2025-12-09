#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<bool> vis(n + 1, 0);

    while (m--) {
        int u;
        char x;
        cin >> u >> x;

        if (x == 'M') {
            if (!vis[u]) {
                cout << "YES\n";
                vis[u] = true;
            } else {
                cout << "NO\n";
            }
        } else {
            cout << "NO\n"; 
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
