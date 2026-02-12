#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> color(n);
    int root = 0;
    for (int i = 0; i < n; i++) {
        cin >> color[i];
        if (color[i]) {
            root = i;
        }
    }

    unordered_map<int, vector<int>> g;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> vis(n);
    auto dfs = [&](this auto&& dfs, int x, int fa) -> void {
        for (int y : g[x]) {
            if (y == fa) continue;

            dfs(y, x);
            if (vis[y] || color[y]) {
                vis[x] = 1;
            }
        }   
    };

    dfs(root, -1);
    int ans = 0; 
    for (int i = 0; i < n; i++) {
        if (!color[i] && vis[i]) {
            ans++;
        }
    }

    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}



