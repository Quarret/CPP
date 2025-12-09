#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
    int n = patience.size();
    unordered_map<int, vector<int>> g;
    for (auto &e : edges) {
        int u = e[0], v = e[1];
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    unordered_map<int, int> dis;
    queue<int> q;
    q.push(0);
    dis[0] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : g[u]) {
            if (!dis.contains(v)) {
                dis[v] = 1 + dis[u];
                q.push(v);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i < n; i++) {
        int cnt = (2 * dis[i] - 1) / patience[i];
        ans = max(ans, 2 * dis[i] + cnt * patience[i] + 1);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
