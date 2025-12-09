#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
    int n = online.size(), maxx = 0;
    unordered_map<int, vector<pair<int, int>>> g;
    vector<int> in_deg(n);
    for (auto &e : edges) {
        int u = e[0], v = e[1], w = e[2];
        if (online[u] == false || online[v] == false) continue;
        g[u].emplace_back(v, w);
        in_deg[v]++;
        if (u == 0) maxx = max(maxx, w);
    }
    
    queue<int> q;
    //from 0 cant reach points
    for (int i = 1; i < n; i++) {
        if (!in_deg[i]) q.push(i);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto [v, _] : g[u]) {
            in_deg[v]--;
            if (!in_deg[v]) q.push(v);
        }
    }

    vector<long long> dis(n);
    auto check = [&](int lower) -> bool {
        auto deg_copy = in_deg;
        dis.assign(dis.size(), INT64_MAX / 2);
        dis[0] = 0;

        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (u == n - 1) return dis[u] <= k;

            for (auto [v, wt] : g[u]) {
                if (wt >= lower) {
                    dis[v] = min(dis[v], dis[u] + wt);
                }
                deg_copy[v]--;
                if (!deg_copy[v]) q.push(v);
            }
        }

        return false;// cant reach n - 1
    };

    int l = -1, r = maxx + 1;
    while (l + 1 < r) {
        int mid = l + (r - l) / 2;
        (check(mid) ? l : r) = mid;
    }

    return l;
}

int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
    int n = online.size(), maxx = 0;
    unordered_map<int, vector<pair<int, int>>> g;
    for (auto &e : edges) {
        int u = e[0], v = e[1], w = e[2];
        if (online[u] == false || online[v] == false) continue;
        g[u].emplace_back(v, w);
        if (u == 0) maxx = max(maxx, w);
    }
    
    vector<long long> memo(n);
    auto check = [&](int lower) -> bool {
        memo.assign(memo.size(), - 1);

        auto dfs = [&](this auto&& dfs, int u) -> long long {
            if (u == n - 1) return 0;//reach n - 1

            auto &res = memo[u];//notice &
            if (res != -1) return memo[u];// if visited, it must be shortest

            res = INT64_MAX / 2;
            for (auto [v, wt] : g[u]) {
                if (wt >= lower) res = min(res, dfs(v) + wt);
            }

            return res;
        };

        return dfs(0) <= k;
    };

    int l = -1, r = maxx + 1;
    while (l + 1 < r) {
        int mid = l + (r - l) / 2;
        (check(mid) ? l : r) = mid;
    }

    return l;  
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
