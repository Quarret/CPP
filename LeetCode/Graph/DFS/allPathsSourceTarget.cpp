#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<vector<int>> ans;
    
    // vector<array<int, 16>> vis(16);
    auto dfs = [&](this auto&& dfs, int u, vector<int> path) -> void {
        // vis[u] = 1;
        path.push_back(u);
        if (u == n - 1) {
            ans.push_back(path);
            return;
        }

        for (int v : graph[u]) {
            dfs(v, path);
        }
    };

    vector<int> path;
    dfs(0, path);

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
