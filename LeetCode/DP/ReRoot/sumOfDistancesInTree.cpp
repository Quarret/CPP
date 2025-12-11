#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
    unordered_map<int, vector<int>> g;
    for (auto &e : edges) {
        int u = e[0], v = e[1];
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    vector<int> ans(n);
    vector<int> size(n, 1); // 这里初始化为 1, 即代表本省, 也可以累加儿子的数量
    auto dfs = [&](this auto&& dfs, int u, int fa, int depth) -> void {
        ans[0] += depth;
        for (int v : g[u]) {
            if (v != fa) {
                dfs(v, u, depth + 1);
                size[u] += size[v];
            }
        }
    };
    dfs(0, -1, 0);

    auto reroot = [&](this auto&& reroot, int u, int fa) -> void {
        for (int v : g[u]) {
            if (v != fa) {
                // 相邻变量, 换根
                size[v] = ans[u] + n - 2 * size[u];
                reroot(v, u);
            }
        }
    };
    reroot(0, -1);

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
