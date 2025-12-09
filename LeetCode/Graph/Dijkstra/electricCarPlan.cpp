#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int electricCarPlan(vector<vector<int>>& paths, int cnt, int start, int end, vector<int>& charge) {
    int n = charge.size();
    unordered_map<int, vector<pair<int, int>>> g;
    for (auto &e : paths) {
        int u = e[0], v = e[1], wt = e[2];
        g[u].emplace_back(v, wt);
        g[v].emplace_back(u, wt);
    }

    vector<int> vis(n);
    vector<long long> dis(n, INT64_MAX);
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    dis[start] = 0;
    pq.emplace(0, start, 0);

    while (!pq.empty()) {
        auto [s, u, cur] = pq.top();
        pq.pop();

        if (s > dis[u]) continue;

        for (auto [v, wt] : g[u]) {
            if (cur < wt) continue;
            int ns = s + wt, val = cur - wt;
            if (ns < dis[v]) {
                dis[v] = ns;
                pq.emplace(ns, v, val);
            }
        }

        if (vis[u]) continue;
        vis[u] = 1;
        for (int val = cur + 1, ns = s + charge[u]; val <= cnt; val++, ns += charge[u]) {
            pq.emplace(ns, u, val);
        }
    }

    return dis[end];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
