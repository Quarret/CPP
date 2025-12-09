#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int countRestrictedPaths(int n, vector<vector<int>>& edges) {
    unordered_map<int, vector<pair<int, int>>> g;
    for (auto &e : edges) {
        int u = e[0] - 1, v = e[1] - 1, wt = e[2];
        g[u].emplace_back(v, wt);
        g[v].emplace_back(u, wt);
    }

    vector<long long> dis(n, INT64_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dis[n - 1] = 0;
    pq.emplace(0, n - 1);

    while (!pq.empty()) {
        auto [s, u] = pq.top();
        pq.pop();

        if (s > dis[u]) continue;
        for (auto [v, wt] : g[u]) {
            int ns = s + wt;
            if (ns < dis[v]) {
                dis[v] = ns;
                pq.emplace(ns, v);
            }
        }
    }

    //create dis no increase dag
    unordered_map<int, vector<int>> g1;
    queue<int> q1;
    vector<int> indeg(n), vis(n);
    q1.push(0);
    vis[0] = 1;

    while (!q1.empty()) {
        int u = q1.front();
        q1.pop();

        for (auto [v, _] : g[u]) {
            if (dis[u] <= dis[v]) continue;
            indeg[v]++;
            g1[u].push_back(v);
            if (!vis[v]) {
                q1.push(v);
                vis[v] = 1;
            } 
        }
    }

    //topo to find path
    long long MOD = 1e9 + 7;
    vector<long long> ans(n, 0);
    ans[0] = 1;
    queue<int> q2;
    q2.push(0);
    while (!q2.empty()) {
        int u = q2.front();
        q2.pop();

        for (int v : g1[u]) {
            ans[v] = (ans[u] + ans[v]) % MOD;
            indeg[v]--;
            if (!indeg[v]) q2.push(v);
        }
    }

    return ans[n - 1] % MOD;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
