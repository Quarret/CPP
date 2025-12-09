#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
    unordered_map<int, vector<tuple<int, int, int>>> g;
    for (int i = 0; i < edges.size(); i++) {
        auto e = edges[i];
        int u = e[0], v = e[1], wt = e[2];
        g[u].emplace_back(v, wt, i);
        g[v].emplace_back(u, wt, i);
    }
    
    vector<long long> dis(n, INT64_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dis[0] = 0;
    pq.emplace(0, 0);

    while (!pq.empty()) {
        auto [s, u] = pq.top();
        pq.pop();

        if (s > dis[u]) continue;

        for (auto [v, wt, _] : g[u]) {
            int ns = s + wt;
            if (ns < dis[v]) {
                dis[v] = ns;
                pq.emplace(ns, v);
            }
        }
    }

    vector<bool> ans(edges.size());
    if (dis[n - 1] == INT64_MAX) return ans;
    vector<int> vis(n);

    //bfs
    // queue<int> q;
    // q.push(n - 1);
    // vis[n - 1] = 1;

    // while (!q.empty()) {
    //     int v = q.front();
    //     q.pop();

    //     for (auto [u, wt, i] : g[v]) {
    //         if (dis[u] + wt != dis[v]) continue;
            
    //         ans[i] = 1;
    //         if (!vis[u]) {
    //             vis[u] = 1;
    //             q.push(u);
    //         }
    //     }
    // }

    //dfs
    auto dfs = [&](this auto&& dfs, int v) -> void {
        vis[v] = 1;

        for (auto [u, wt, i] : g[v]) {
            if (dis[u] + wt != dis[v]) continue;

            ans[i] = 1;
            if (!vis[u]) {
                dfs(u);
            }
        }
    };

    dfs(n - 1);//from n - 1 search the paths that reach n - 1

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
