#include <bits/stdc++.h>
using ll = long long;
using namespace std;

double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
    unordered_map<int, vector<pair<int, double>>> g;
    int m  = edges.size();
    for (int i = 0; i < m; i++) {
        int u = edges[i][0], v = edges[i][1];
        double wt = succProb[i];
        g[u].emplace_back(v, wt);
        g[v].emplace_back(u, wt);
    }
    
    vector<double> dis(n, -1);
    priority_queue<pair<double, int>, vector<pair<double, int>>, less<>> pq;
    dis[start_node] = 1.0;
    pq.emplace(1.0, start_node);

    while (!pq.empty()) {
        auto [s, u] = pq.top();
        pq.pop();

        if (s < dis[u]) continue;

        for (auto &[v, wt] : g[u]) {
            double ns = s * wt;
            if (ns > dis[v]) {
                dis[v] = ns;
                pq.emplace(ns, v);
            }
        }
    }

    return dis[end_node] == -1 ? 0 : dis[end_node];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
