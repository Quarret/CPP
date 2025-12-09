#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int findShortestCycle(int n, vector<vector<int>>& edges) {
    unordered_map<int, vector<int>> g;
    for (auto &e : edges) {
        int u = e[0], v = e[1];
        g[u].push_back(v);
        g[v].push_back(u);
    } 
    
    queue<pair<int, int>> q;

    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        vector<int> vis(n), dis(n, INT32_MAX);
        q.emplace(i, -1);
        dis[i] = 0;

        while (!q.empty()) {
            auto [u, from] = q.front();
            vis[u] = 1;
            q.pop();

            for (int v : g[u]) {
                if (1 + dis[u] < dis[v]) {
                    dis[v] = dis[u] + 1;
                    q.emplace(v, u);
                }
                if (vis[v] && from != v) {
                    ans = min(ans, 1 + dis[u] + dis[v]);
                }
            }
        }
    }

    return ans == 1e9 ? -1 : ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
