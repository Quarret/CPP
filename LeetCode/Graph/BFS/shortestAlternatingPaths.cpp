#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
    unordered_map<int, vector<int>> red, blue;
    for (auto &e : redEdges) {
        int u = e[0], v = e[1];
        red[u].push_back(v);
    }
    
    for (auto &e : blueEdges) {
        int u = e[0], v = e[1];
        blue[u].push_back(v);
    }

    vector<array<int, 2>> dis(n, {INT32_MAX, INT32_MAX});
    queue<pair<int, int>> q;
    q.emplace(0, 0);
    q.emplace(0, 1);
    dis[0][0] = 0;
    dis[0][1] = 0;

    while (!q.empty()) {
        auto [u, t] = q.front();
        q.pop();

        for (int v : (t ? red[u] : blue[u])) {// t - latest edge color
            if (1 + dis[u][t] < dis[v][t ^ 1]) {
                dis[v][t ^ 1] = 1 + dis[u][t];
                q.emplace(v, t ^ 1);
            }
        }
    }

    vector<int> ans;
    for (auto [dis1, dis2] : dis) {
        ans.push_back(min(dis1, dis2) == INT32_MAX ? -1 : min(dis1, dis2));
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
