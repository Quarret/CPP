#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
    unordered_map<int, vector<int>> g;
    for (int u = 0; u < n; u++) {
        if (u != n - 1) g[u].push_back(u + 1);
    }
    
    vector<int> dis(n);
    for (int u = 0; u < n; u++) dis[u] = u;
    queue<int> q;
    
    vector<int> ans;
    for (auto &e : queries) {
        int u = e[0], v = e[1];
        g[u].push_back(v);

        q.push(u);
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : g[u]) {
                if (dis[u] + 1 < dis[v]) {
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
            }
        }

        ans.push_back(dis[n - 1]);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
