#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
    unordered_map<int, vector<pair<int, int>>> g;
    for (auto &e : edges) {
        int u = e[0], v = e[1], wt = e[2];
        g[u].emplace_back(v, wt);
        g[v].emplace_back(u, wt);
    }
    
    vector<int> dis(n, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dis[0] = 0;
    pq.emplace(0, 0);

    while (!pq.empty()) {
        auto [s, u] = pq.top();
        pq.pop();

        if (s > dis[u]) continue;
        
        for (auto &[v, wt] : g[u]) {
            int ns = s + wt;
            if (ns < disappear[v] && (ns < dis[v] || dis[v] == -1)) {
                dis[v] = ns;
                pq.emplace(ns, v);
            }
        }
    }

    return dis;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
