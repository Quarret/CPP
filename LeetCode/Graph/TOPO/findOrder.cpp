#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> in_deg(numCourses);
    unordered_map<int, vector<int>> g;
    for (auto &e : prerequisites) {
        int u = e[0], v = e[1];
        g[v].push_back(u);
        in_deg[u]++;
    }
    
    vector<int> topo;
    queue<int> q;
    for (int u = 0; u < numCourses; u++) {
        if (!in_deg[u]) {
            q.push(u);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo.push_back(u);

        for (int v : g[u]) {
            in_deg[v]--;// avoid repeating 
            if (!in_deg[v]) {
                q.push(v);
            }
        }
    }

    if (topo.size() < numCourses) return {};
    return topo;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
