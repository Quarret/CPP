#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    // unordered_map<int, vector<pair<int, int>>> g;
    vector<vector<pair<int, int>>> g(n);
    for (auto &e : times) {
        int u = e[0], v = e[1], wt = e[2];
        g[u].emplace_back(v, wt);
    }

    vector<int> dis(n + 1, INT32_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(k, 0);
    dis[k] = 0;

    while (!pq.empty()) {
        auto[u, s] = pq.top();
        pq.pop();

        if (s > dis[u]) continue;

        for (auto &[v, wt] : g[u]) {
            int ns = s + wt;
            if (ns < dis[v]) {
                dis[v] = ns;//lazy update
                pq.emplace(v, ns);
            } 
        }
    }

    // int maxx = *max_element(dis.begin() + 1, dis.end());
    int maxx = ranges::max(dis);
    return maxx == INT32_MAX ? -1 : maxx;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
