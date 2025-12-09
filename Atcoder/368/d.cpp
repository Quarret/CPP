#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n, k, ans = 0;
    cin >> n >> k;

    vector< vector<int> > adj(n + 1);
    int u, v;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> f(n + 1, 0), sum(n + 1, 0);
    int V;
    for (int i = 0; i < k; i++) {
        cin >> V;
        f[V] = 1;
    }

    auto dfs = [&](auto& self, int x, int p) -> void {
        sum[x] = f[x];
        for (auto y : adj[x]) {
            if (y == p) {
                continue;
            }
            self(self, y, x);
            sum[x] += sum[y];
        }

        if (sum[x] >= 1) ans++;
    };

    dfs(dfs, 1, -1);

    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
