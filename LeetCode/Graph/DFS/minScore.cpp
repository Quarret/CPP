#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minScore(int n, vector<vector<int>>& roads) {
    vector<vector<pair<int, int>>> g(n);
    
    for (auto &e : roads) {
        int a = e[0] - 1, b = e[1] - 1, dis = e[2];
        g[a].emplace_back(b, dis);
        g[b].emplace_back(a, dis);
    }

    int ans = 1e9;
    vector<int> vis(n), p;
    auto dfs = [&](this auto&& dfs, int u) -> void {
        vis[u] = 1;
        p.emplace_back(u);

        for (auto [v, dis] : g[u]) {
            if (!vis[v]) dfs(v);
        }       
    };

    dfs(0);

    for (int u : p) {
        for (auto [v, dis]: g[u]) {
            ans = min(ans, dis);
        }
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
