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
};

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    UnionFind dsu(n);
    unordered_map<int, unordered_map<int, int>> g, tmp_g;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        g[u][v] = 1;
        g[v][u] = 1;
    }
    tmp_g = g;

    vector<array<int, 3>> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
        if (queries[i][0] == 1) {
            int u = queries[i][1], v = queries[i][2];
            g[u].erase(v);
            g[v].erase(u);
        }
    }

    for (auto [x, mp] : g) {
        for (auto [y, _] : mp) {
            dsu.merge(x, y);
        }
    }

    vector<int> ans;
    for (int i = q - 1; i >= 0; i--) {
        int ops = queries[i][0], u = queries[i][1], v = queries[i][2];
        if (ops == 2) {
            ans.push_back(dsu.is_same(u, v));
        } else {
            if (tmp_g[u][v]) dsu.merge(u, v);
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