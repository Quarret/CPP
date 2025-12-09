#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long countPairs(int n, vector<vector<int>>& edges) {
    vector<int> vis(n);
    vector<vector<int>> g(n);
    for (auto arr : edges) {
        g[arr[0]].emplace_back(arr[1]);
        g[arr[1]].emplace_back(arr[0]);
    }
    long long ans = n * (n - 1) / 2;

    long long cnt = 0;
    auto dfs = [&](this auto&& dfs, int u) -> void {
        vis[u] = 1;
        cnt++;

        for (int v : g[u]) {
            if (!vis[v]) dfs(v);
        }
    };

    for (int u = 0; u < n; u++) {
        if (!vis[u]) {
            dfs(u);
            ans -= cnt * (cnt - 1) / 2;
            cnt = 0;
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
