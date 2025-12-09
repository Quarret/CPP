#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int countPaths(int n, vector<vector<int>>& roads) {
    unordered_map<int, vector<pair<int, long long>>> g;
    for (auto &e : roads) {
        long long u = e[0], v = e[1], wt = e[2];
        g[u].emplace_back(v, wt);
        g[v].emplace_back(u, wt);
    }
    
    long long MOD = 1e9 + 7;
    vector<long long> dis(n, INT64_MAX), ans(n, 0);
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> pq;
    dis[0] = 0;
    ans[0] = 1;// init start only 1 way to get
    pq.emplace(0, 0);

    while (!pq.empty()) {
        auto [s, u] = pq.top();
        pq.pop();

        if (s > dis[u]) continue;

        //in the path, no any point repeat
        //so when update dis[v], it must be new path that doesnt have v
        for (auto [v, wt] : g[u]) {
            long long ns = s + wt;
            if (ns < dis[v]) {
                dis[v] = ns;
                ans[v] = ans[u];
                pq.emplace(ns, v);
            } else if (ns == dis[v]) {
                ans[v] = (ans[v] + ans[u]) % MOD;
            }
        }
    }

    return ans[n - 1] % MOD;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
