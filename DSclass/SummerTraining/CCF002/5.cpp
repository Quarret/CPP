#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> in(n + 1, 0);

    int u, v;
    while (m--) {
        cin >> u >> v;
        in[v]++;
    }

    for (int i = 1; i <= n; i++) {
        if (!in[i]) {
            cout << i << '\n';
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
