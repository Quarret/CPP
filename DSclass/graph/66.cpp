#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

int n;
vector<vector<int>> g;
set<int> s[2];

void dfs(int u, vector<int>& color, bool use_s) {
    color[u] = 1;
    for (int v: g[u])
        if (color[v] == 0)
            dfs(v, color, use_s);
        else if (use_s)
            s[color[v] - 1].insert(v);
    color[u] = 2;
}

int main() {
    int t;
    cin >> t;
    forn(tt, t) {
        int m;
        cin >> n >> m;
        g = vector<vector<int>>(n);
        forn(i, 2)
            s[i] = set<int>();
        forn(i, m) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            g[x].push_back(y);
        }
        vector<int> color = vector<int>(n);
        dfs(0, color, true);
        vector<vector<int>> c(2, vector<int>(n));
        forn(i, 2)
            for (auto u: s[i])
                dfs(u, c[i], false);
        forn(i, n) {
            int ans = 0;
            if (color[i] != 0) {
                ans = 1;
                if (c[0][i])
                    ans = -1;
                else if (c[1][i])
                    ans = 2;
            }
            cout << ans << " ";
        }
        cout << endl;
    }
}