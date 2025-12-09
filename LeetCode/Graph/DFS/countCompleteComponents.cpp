#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int countCompleteComponents(int n, vector<vector<int>>& edges) {
    vector<vector<int>> g(n);
    for (auto &e : edges) {
        int u = e[0], v = e[1];
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    
    int cnt = 0, pcnt = 0;
    vector<int> vis(n);
    auto dfs = [&](this auto&& dfs, int u) -> void {
        vis[u] = 1;
        pcnt++;
        cnt += g[u].size();

        for (int v : g[u]) {
            if (!vis[v]) dfs(v);
        }
    };

    int ans = 0;
    for (int u = 0; u < n; u++) {
        if (!vis[u]) {
            cnt = 0;
            pcnt = 0;
            dfs(u);
            if (pcnt * (pcnt - 1) == cnt) ans++;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
