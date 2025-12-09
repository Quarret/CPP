#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minTime(int n, vector<vector<int>>& edges) {
    unordered_map<int, vector<tuple<int, int, int>>> g;
    for (auto &e : edges) {
        int u = e[0], v = e[1], start = e[2], end = e[3];
        g[u].emplace_back(v, start, end);
    }

    vector<long long> dis(n, INT64_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dis[0] = 0;
    pq.emplace(0, 0);

    while (!pq.empty()) {
        auto [s, u] = pq.top();
        pq.pop();

        if (s > dis[u]) continue;

        for (auto &[v, start, end] : g[u]) {
            if (s > end) continue;
            int ns = s >= start ? s + 1 : start + 1;
            if (ns < dis[v]) {
                dis[v] = ns;
                pq.emplace(ns, v);
            }
        }
    }

    return dis[n - 1] == INT64_MAX ? -1 : dis[n - 1];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
