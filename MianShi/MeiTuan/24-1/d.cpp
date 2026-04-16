#include <bits/stdc++.h>
using ll = long long;
using namespace std;


class UnionFind {
public:
    vector<int> fa;

    UnionFind(int n): fa(n + 1) {
        iota(fa.begin(), fa.end(), 0);
    }

    int find(int x) {
        if (x != fa[x]) {
            int root = find(fa[x]);
            fa[x] = root;
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

    void clear() {
        iota(fa.begin(), fa.end(), 0);
    }
};

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    UnionFind dsu(n);
    unordered_map<int, unordered_map<int, int>> g;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        dsu.merge(u, v);

        g[u][v] = 1;
        g[v][u] = 1;
    }

    for (int i = 0; i < q; i++) {
        int op, u, v;
        cin >> op >> u >> v;

        if (op == 2) cout << (dsu.is_same(u, v) ? "Yes\n" : "No\n");
        else {
            g[u].erase(v);
            g[v].erase(u);

            dsu.clear();
            for (auto [x, mp] : g) {
                for (auto [y, _] : mp) {
                    dsu.merge(x, y);
                }
            }
        } 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}