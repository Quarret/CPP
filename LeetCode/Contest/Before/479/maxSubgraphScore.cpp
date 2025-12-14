#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<int> maxSubgraphScore(int n, vector<vector<int>>& edges, vector<int>& good) {
    unordered_map<int, vector<int>> g;
    for (auto &e : edges) {
        int u = e[0], v = e[1];
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // 在以 0 为根下, i 子树的最大值, 必须包含 i 节点
    vector<int> sub_tree(n);
    auto dfs = [&](this auto&& dfs, int x, int fa) -> int {
        sub_tree[x] += good[x] ? 1 : -1;
        for (int y : g[x]) {
            if (y != fa) {
                sub_tree[x] += max(dfs(y, x), 0);
            }
        }
        return sub_tree[x];
    };
    dfs(0, - 1);

    // 换根 DP: 从节点 x 计算到节点 y: ans[y] = sub_tree[y] + max(fa_score, 0)
    // fa_score 为来自 x 节点的最大得分
    vector<int> ans(n);
    auto reroot = [&](this auto&& reroot, int x, int fa, int fa_score) -> void {
        ans[x] = sub_tree[x] + max(fa_score, 0);
        for (int y : g[x]) {
            if (y != fa) {
                reroot(y, x, ans[x] - max(sub_tree[y], 0));
            }
        }
    };
    // ans[0] = sub_tree[0]
    reroot(0, -1, 0);

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
