#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
    vector<vector<int>> g(n);
    for (auto &e : edges) {
        int u = e[0], v = e[1];
        g[u].emplace_back(v);
    }

    vector<vector<int>> ans(n);
    vector<int> vis(n);
    auto dfs = [&](this auto&& dfs, int u, int root) -> void {
        vis[u] = 1;

        for (int v : g[u]) {
            if (!vis[v]) {
                ans[v].emplace_back(root);
                dfs(v, root);
            }
        }
    };

    for (int u = 0; u < n; u++) {
        vis.assign(vis.size(), 0);
        dfs(u, u);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
