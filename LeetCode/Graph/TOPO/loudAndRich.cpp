#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
    int n = quiet.size();
    unordered_map<int, vector<int>> g;
    vector<int> in_deg(n);
    for (auto &e : richer) {
        int u = e[0], v = e[1];
        g[u].push_back(v);
        in_deg[v]++;
    }
    
    queue<int> q;
    vector<int> ans(n), val(quiet.begin(), quiet.end());

    for (int u = 0; u < n; u++) {
        if (!in_deg[u]) {
            q.push(u);
        }
        ans[u] = u;
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : g[u]) {
            in_deg[v]--;
            if (val[v] > val[u]) {
                val[v] = val[u];
                ans[v] = ans[u];
            }
            if (!in_deg[v]) {
                q.push(v);
            }
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
