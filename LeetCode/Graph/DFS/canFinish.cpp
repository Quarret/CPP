#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> g(numCourses);
    for (auto &e : prerequisites) {
        int u = e[0], v = e[1];
        g[v].push_back(u);
    }
    
    vector<int> vis(numCourses);//3 status 0 - not visited 1 - visiting 2 - visited
    int ok = 1;
    auto dfs = [&](this auto&& dfs, int u) -> void {
        vis[u] = 1;

        for (int v : g[u]) {
            if (vis[v] == 1) ok = 0;
            else if (!vis[v]) dfs(v);
        }

        vis[u] = 2;
    };

    for (int u = 0; u < numCourses; u++) {
        if (!ok) return 0;
        if (!vis[u]) dfs(u);
    }

    return 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
