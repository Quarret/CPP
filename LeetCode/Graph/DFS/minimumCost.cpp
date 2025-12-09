#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
    unordered_map<int, vector<pair<int, int>>> g;
    for (auto &e : edges) {
        int u = e[0], v = e[1], w = e[2];
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    
    vector<int> vis(n);
    int idx = 1;
    auto dfs = [&](this auto&& dfs, int u) -> int {
        vis[u] = idx;
        int val = -1;

        for (auto [v, w] : g[u]) {
            val &= w;
            if (!vis[v]) {
                val &= dfs(v);
            }
        }
        return val;
    };

    vector<int> and_;
    for (int u = 0; u < n; u++) {
        if (!vis[u]) {
            and_.push_back(dfs(u));
            idx++;
        }
    }

    vector<int> ans;
    for (auto &arr : query) {
        int l = arr[0], r = arr[1];
        if (vis[l] != vis[r]) ans.push_back(-1);
        else ans.push_back(and_[vis[l] - 1]);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
