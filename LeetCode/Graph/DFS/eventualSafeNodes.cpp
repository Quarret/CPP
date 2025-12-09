#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// my 3-colors searching circle
// O(n + m) m - edge
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> vis(n);
    
    vector<int> ans, path;
    auto dfs = [&](this auto&& dfs, int u, vector<int> path) -> void {
        vis[u] = 1;
        path.push_back(u);

        for (int v : graph[u]) {
            if (vis[v] == 1 || vis[v] == -1) {
                for (int p : path) {
                    vis[p] = -1;
                }
            } else if (!vis[v]) dfs(v, path); 
        }
        if (vis[u] != -1) vis[u] = 2;
    };

    for (int u = 0; u < n; u++) {
        if (!vis[u]) dfs(u, path);
    }

    for (int i = 0; i < n; i++) {
        if (vis[i] != -1) ans.push_back(i);
    } 

    return ans;
}


vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();

    vector<int> vis(n);
    auto dfs = [&](this auto&& dfs, int u) -> bool {
        if (vis[u]) return vis[u] == 2;//if u in stack and visit u, it must be a circle
        vis[u] = 1;

        for (int v : graph[u]) {
            if (!dfs(v)) return 0;// return if v in circle right now
        }

        vis[u] = 2;
        return 1;
    };

    vector<int> ans;
    for (int u = 0; u < n; u++) {
        if (!vis[u] && dfs(u)) ans.push_back(u);
        else if (vis[u] == 2) ans.push_back(u);
    }

    return ans;
}

//topo sort
//avoid circle from safe to points
/*
拓扑排序：从给定的图的所有边中「提取出该图的某一个拓扑序列」的过程，拓扑序列是一条满足图中有向边前后关系的序列，任一有向边起点在序列中一定早于终点出现。
如果图中有环，则无法提取出拓扑序列。所以拓扑排序的一个重要应用是在给定的有向图中判定是否存在环路。
*/
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> out_deg(n);
    unordered_map<int, vector<int>> g;
    for (int u = 0; u < n; u++) {
        for (int v : graph[u]) {
            g[v].push_back(u);
        }
        out_deg[u] = graph[u].size();
    }

    queue<int> q;
    vector<int> topo;
    for (int u = 0; u < n; u++) {
        if (!out_deg[u]) q.push(u);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo.push_back(u);

        for (int v : g[u]) {
            out_deg[v]--;
            if (!out_deg[v]) q.push(v);
        }
    }

    sort(topo.begin(), topo.end());

    return topo;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
