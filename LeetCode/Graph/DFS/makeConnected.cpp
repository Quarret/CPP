#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int makeConnected(int n, vector<vector<int>>& connections) {
    vector<vector<int>> g(n);
    for (auto &e : connections) {
        int u = e[0], v = e[1];
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    int cnt = 0, cnt1 = 0;
    vector<int> vis(n);
    auto dfs = [&](this auto&& dfs, int u) -> void {
        vis[u] = 1;
        cnt++;
        cnt1 += g[u].size();

        for (int v : g[u]) {
            if (!vis[v]) dfs(v);
        }
    };

    int blocks = 0, cut = 0;
    for (int u = 0; u < n; u++) {
        if (!vis[u]) {
            blocks++;
            dfs(u);
            cut += cnt1 / 2 - cnt + 1;
            cnt1 = 0, cnt = 0;
        }
    }

    return (cut >= blocks - 1 ? blocks - 1 : -1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
