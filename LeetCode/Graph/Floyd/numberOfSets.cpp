#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
    vector g(n, vector<int>(n, INT_MAX / 2));
    for (auto &e : roads) {
        int x = e[0], y = e[1], wt = e[2];
        g[x][y] = min(g[x][y], wt);
        g[y][x] = min(g[y][x], wt);
    }

    int ans = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        vector w(n, vector<int>(n, INT_MAX / 2));
        vector<int> nodes;
        for (int i = 0; i < n; i++) {
            if (!(mask >> i & 1)) continue;
            nodes.push_back(i);

            w[i][i] = 0;
            for (int y = 0; y < n; y++) {
                if (!(mask >> y & 1)) continue;
                w[i][y] = g[i][y];
            }
        }

        auto f = move(w);
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
                }
            }
        }

        int ok = 1, m = __builtin_popcount(mask);
        for (int i = 0; i < m; i++) {
            int x = nodes[i];
            for (int j = i + 1; j < m; j++) {
                int y = nodes[j];
                if (f[x][y] > maxDistance) ok = 0;
            }
            if (!ok) break;
        }

        ans += ok;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}