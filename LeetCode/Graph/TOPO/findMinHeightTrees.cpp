#include <bits/stdc++.h>
using ll = long long;
using namespace std;

//from leaf topo
//topo from the safest point(min in_deg)
vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (n == 1) return {0};
    
    unordered_map<int, vector<int>> g;
    vector<int> in_deg(n);
    for (auto &e : edges) {
        int u = e[0], v = e[1];
        g[u].push_back(v);
        g[v].push_back(u);
        in_deg[u]++;
        in_deg[v]++;
    }
    
    queue<int> q;
    for (int u = 0; u < n; u++) {
        if (in_deg[u] == 1) q.push(u);
    }

    vector<int> d(n);
    int depth = 0;
    while (!q.empty()) {
        int t = q.size();

        for (int i = 0; i < t; i++) {
            int u = q.front();
            q.pop();

            d[u] = depth;
            for (int v : g[u]) {
                in_deg[v]--;
                if (in_deg[v] == 1) {
                    q.push(v);
                }
            }
        }

        depth++;
    }

    vector<int> ans;
    for (int u = 0; u < n; u++) {
        if (d[u] == depth - 1) ans.push_back(u);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
