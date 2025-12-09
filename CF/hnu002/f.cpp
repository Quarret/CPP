#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> deg(n + 1, 0);

    int u, v;
    for (int i = 0; i < m; i++) { 
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
    }

    int xy = count(deg.begin(), deg.end(), 1);
    int x = m - xy;
    int y = xy / x;

    cout << x << ' ' << y << '\n';
};
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
