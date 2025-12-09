#include <bits/stdc++.h>
#define int long long
using namespace std;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<set<int>> g(n + 1);
    for (int i = 1; i <= n; i++) {
        g[i].insert(i);
    }

    auto query1 =[&](int u, int v) -> void {
            for (auto e : g[u]) {
                g[v].insert(e);
            }

            for (auto e : g[v]) {
                g[u].insert(e);
            }
    };

    auto query2 = [&](int v, int k) -> void {
        if (g[v].size() < k) {
            cout << -1 << '\n';
            return;
        }

        int cnt = 0;
        for (auto e : g[v]) {
            cnt++;
            if (cnt == k) {
            int num = *max_element(g[e].begin(), g[e].end());
            cout << num << '\n';
            return;
            }
        }

    };

    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;

        if (x == 1) {
             query1(y, z);
        } else {
            query2(y, z);
        }
    }


    return 0;
}
