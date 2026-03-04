#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minCost(int n, vector<vector<int>>& edges) {
    unordered_map<int, vector<int>> in, out;
    vector wt(n, vector<int>(n, INT_MAX));
    for (auto &e : edges) {
        int u = e[0], v = e[1], w = e[2];
        out[u].push_back(v);
        in[v].push_back(u);
        wt[u][v] = w;
    }
    
    unordered_map<int, unordered_map<int, int>> vis;
    vector<int> d(n, INT_MAX);
    d[0] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, 0);

    while (!pq.empty()) {
        auto [s, u] = pq.top();
        pq.pop();

        if (u == n - 1) break;

        for (int v : out[u]) {
            int new_s = s + wt[u][v];
            if (new_s < d[v]) {
                pq.emplace(new_s, v);
                d[v] = new_s;
            }
        }

        for (int v : in[u]) {
            if (vis[v][u]) continue;
            int new_s = s + 2 * wt[v][u];
            if (new_s < d[v]) {
                pq.emplace(new_s, v);
                d[v] = new_s;
                vis[v][u] = 1;
            }
        }
    }

    return d[n - 1] != INT_MAX ? d[n - 1] : -1;
}

int minCost(int n, vector<vector<int>>& edges) {
    unordered_map<int, vector<pair<int, int>>> in, out;
    for (auto &e : edges) {
        int u = e[0], v = e[1], w = e[2];
        out[u].emplace_back(v, w);
        in[v].emplace_back(u, w);
    }
    
    unordered_map<int, unordered_map<int, int>> vis;
    // vector vis(n, vector<int>(n, 0));
    vector<int> d(n, INT_MAX);
    d[0] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, 0);

    while (!pq.empty()) {
        auto [s, u] = pq.top();
        pq.pop();

        if (u == n - 1) break;

        for (auto [v, wt] : out[u]) {
            int new_s = s + wt;
            if (new_s < d[v]) {
                pq.emplace(new_s, v);
                d[v] = new_s;
            }
        }

        for (auto [v, wt] : in[u]) {
            if (vis[v][u]) continue;
            int new_s = s + 2 * wt;
            if (new_s < d[v]) {
                pq.emplace(new_s, v);
                d[v] = new_s;
                vis[v][u] = 1;
            }
        }
    }

    return d[n - 1] != INT_MAX ? d[n - 1] : -1;
}


int minCost(int n, vector<vector<int>>& edges) {
    unordered_map<int, vector<pair<int, int>>> g;
    for (auto &e : edges) {
        int u = e[0], v = e[1], w = e[2];
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, 2 * w);
    }

    vector d(n, INT_MAX);
    d[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, 0);

    while (!pq.empty()) {
        auto [s, x] = pq.top();
        pq.pop();

        if (x == n - 1) {
            return s;
        }

        for (auto &[y, w] : g[x]) {
            int new_s = s + w;
            if (new_s < d[y]) {
                d[y] = new_s;
                pq.emplace(new_s, y);
            }
        }
    }

    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}