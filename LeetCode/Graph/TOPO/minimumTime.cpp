#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
    unordered_map<int, vector<int>> g;
    vector<int> in_deg(n + 1);
    for (auto &e : relations) {
        int u = e[0], v = e[1];
        g[u].push_back(v);
        in_deg[v]++;
    }
    
    queue<int> q;
    vector<int> val(n + 1);
    for (int u = 1; u <= n; u++) {
        if (!in_deg[u]) {
            q.push(u);
            val[u] = time[u - 1];
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : g[u]) {
            in_deg[v]--;
            val[v] = max(val[v], val[u] + time[v - 1]);
            // cout << u << ' ' << val[u] << ' ' << v << ' ' << val[v] << '\n';
            if (!in_deg[v]) {
                q.push(v);
            }
        }
    }

    int ans = *max_element(val.begin(), val.end());
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
