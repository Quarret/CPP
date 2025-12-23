#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long interactionCosts(int n, vector<vector<int>>& edges, vector<int>& group) {
    unordered_map<int, vector<int>> g;
    for (auto &e : edges) {
        int u = e[0], v = e[1];
        g[u].push_back(v);
        g[v].push_back(u); 
    }
    
    unordered_map<int, int> cnt;
    for (int x : group) {
        cnt[x]++;
    }

    long long ans = 0;
    // 统计每条边的出现次数
    auto dfs = [&](this auto&& dfs, int x, int fa) -> vector<int> {
        vector<int> cnt_x(21);
        cnt_x[group[x]] = 1;

        for (int y : g[x]) {
            if (y == fa) continue;
            auto cnt_y = dfs(y, x);

            for (int i = 1; i <= 20; i++) {
                ans += 1LL * (cnt[i] - cnt_y[i]) * cnt_y[i];
                cnt_x[i] += cnt_y[i];
            }
        }

        return cnt_x;
    };

    dfs(0, -1);
    return ans;
}

long long interactionCosts(int n, vector<vector<int>>& edges, vector<int>& group) {
    unordered_map<int, vector<int>> g;
    for (auto &e : edges) {
        int u = e[0], v = e[1];
        g[u].push_back(v);
        g[v].push_back(u); 
    }
    
    unordered_map<int, int> cnt;
    for (int x : group) {
        cnt[x]++;
    }

    long long ans = 0;
    // 统计每条边的出现次数
    for (int k = 1; k <= 20; k++) {
        auto dfs = [&](this auto&& dfs, int x, int fa) -> int {
            int cnt_x = group[x] == k;

            for (int y : g[x]) {
                if (y == fa) continue;
                int cnt_y = dfs(y, x);
                ans += 1LL * cnt_y * (cnt[k] - cnt_y);
                cnt_x += cnt_y;
            }

            return cnt_x;
        };

        dfs(0, -1);
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
