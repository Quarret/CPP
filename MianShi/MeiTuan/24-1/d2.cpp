#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// 1. 修复 DSU：使用 map 代替 vector 以应对 n=10^9
class UnionFind {
public:
    unordered_map<int, int> fa; 

    int find(int x) {
        // 如果不在 map 中，说明它是孤立点，父节点是自己
        if (fa.find(x) == fa.end()) return x;
        if (x != fa[x]) {
            fa[x] = find(fa[x]);
        }
        return fa[x];
    }

    bool is_same(int x, int y) {
        return find(x) == find(y);
    }

    void merge(int from, int to) {
        int x = find(from), y = find(to);
        if (x != y) {
            fa[x] = y;
        }
    }
};

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    UnionFind dsu;
    // 2. 修复存储：使用 set 存储 pair<int, int> 节省内存
    // 规定存储时 u < v，保证边唯一性
    set<pair<int, int>> g, initial_g; 
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        g.insert({u, v});
    }
    initial_g = g; // 备份初始边集

    vector<array<int, 3>> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
        if (queries[i][0] == 1) {
            int u = queries[i][1], v = queries[i][2];
            if (u > v) swap(u, v);
            g.erase({u, v}); // 移除被删掉的边
        }
    }

    // 3. 将从未被删除的边加入并查集
    for (auto& edge : g) {
        dsu.merge(edge.first, edge.second);
    }

    vector<int> ans;
    // 4. 逆向处理
    for (int i = q - 1; i >= 0; i--) {
        int ops = queries[i][0], u = queries[i][1], v = queries[i][2];
        if (ops == 2) {
            ans.push_back(dsu.is_same(u, v));
        } else {
            if (u > v) swap(u, v);
            // 只有当这条边原本就在初始好友关系里，才进行合并
            if (initial_g.count({u, v})) {
                dsu.merge(u, v);
            }
        }
    }

    reverse(ans.begin(), ans.end());
    for (int x : ans) {
        cout << (x ? "Yes" : "No") << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
