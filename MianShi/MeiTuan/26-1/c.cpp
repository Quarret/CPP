#include <bits/stdc++.h>
using ll = long long;
using namespace std;


void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    unordered_map<int, vector<int>> g;
    for (int i = 0; i < n - 1; i++) {
        int u = 0, v = 0;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    auto query = [&](auto&& query, int x, int fa, int offset) -> int {
        
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}