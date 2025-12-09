#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
    vector<vector<int>> g(n);
    for (auto &e : invocations) {
        int u = e[0], v = e[1];
        g[u].emplace_back(v);
    }
    
    vector<int> vis(n);
    auto dfs = [&](this auto&& dfs, int u) -> void {
        vis[u] = 1;

        for (int v : g[u]) {
            if (!vis[v]) dfs(v);
        }
    };

    vis[k] = 1;
    dfs(k);

    bool ok = 0;
    vector<int> ans, ans1;
    for (int i = 0; i < n; i++) {
        ans1.emplace_back(i);
        if (!vis[i] && !ok) {
            ans.emplace_back(i);
            for (int v : g[i]) {
                if (vis[v]) ok = 1;
            }
        }
    }

    return (ok ? ans1 : ans);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
