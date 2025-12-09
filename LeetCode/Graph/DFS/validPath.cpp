#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    vector<vector<int>> g(n);
    for (auto arr : edges) {
        g[arr[0]].emplace_back(arr[1]);
        g[arr[1]].emplace_back(arr[0]);
    }
    
    vector<int> vis(n);
    bool ok = false;
    auto dfs = [&](this auto&& dfs, int u) -> void {
        vis[u] = 1;
        if (u == destination) ok = true;

        for (int v : g[u]) {
            if (!vis[v]) dfs(v);
        }
    };

    dfs(source);
    return ok;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
