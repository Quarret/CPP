#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
    unordered_map<int, vector<int>> g;    
    for (auto &e : edges) {
        int u = e[0], v = e[1];
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int ans = 0;
    auto dfs = [&](this auto&& dfs, int root, int fa) -> long long {
        long long sum = values[root];
        for (int v : g[root]) {
            if (v != fa) {
                sum += dfs(v, root);
            }
        }

        ans += sum % k == 0;
        return sum;
    };

    dfs(0, -1);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
