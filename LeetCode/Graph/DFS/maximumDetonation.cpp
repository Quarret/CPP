#include <bits/stdc++.h>
using ll = long long;
using namespace std;

//预处理每个炸弹能够炸到那些可以将复杂度降到O(n ^ 2)
int maximumDetonation(vector<vector<int>>& bombs) {
    int n = bombs.size();
    int ans = 0, cnt = 0;

    vector<int> vis(n);
    auto dfs = [&](this auto&& dfs, int u) -> void {
        vis[u] = 1;
        cnt++;

        long long x = bombs[u][0], y = bombs[u][1], r = bombs[u][2];
        for (int v = 0; v < n; v++) {
            long long x1 = bombs[v][0], y1 = bombs[v][1], r1 = bombs[v][2];
            if (!vis[v] && (x - x1) * (x - x1) + (y - y1) * (y - y1) <= r * r) dfs(v);
        }
    };

    for (int u = 0; u < n; u++) {
        vis.assign(vis.size(), 0);
        dfs(u);
        ans = max(ans, cnt);
        cnt = 0;
    }

    return ans;
}

int maximumDetonation(vector<vector<int>>& bombs) {
    int n = bombs.size();
    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long x = bombs[i][0], y = bombs[i][1], r = bombs[i][2];
            long long x1 = bombs[j][0], y1 = bombs[j][1], r1= bombs[j][2];
            if ((x - x1) * (x - x1) + (y - y1) * (y - y1) <= r * r) g[i].push_back(j);
            if ((x - x1) * (x - x1) + (y - y1) * (y - y1) <= r1 * r1) g[j].push_back(i);
        }
    }

    vector<int> vis(n);
    auto dfs = [&](this auto&& dfs, int u) -> int {
        vis[u] = 1;
        int cnt = 1;

        for (int v : g[u]) {
            if (!vis[v]) cnt += dfs(v);
        }

        return cnt;
    };

    int ans = 0;
    for (int u = 0; u < n; u++) {
        vis.assign(vis.size(), 0);
        if (!vis[u]) ans = max(ans, dfs(u));
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
