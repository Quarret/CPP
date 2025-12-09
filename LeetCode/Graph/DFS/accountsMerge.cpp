#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    unordered_map<string, vector<string>> g;
    int n = accounts.size();
    for (int i = 0; i < n; i++) {
        string u = to_string(i);
        for (int j = 1; j < accounts[i].size(); j++) {
            string v = accounts[i][j];
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }

    unordered_map<string, int> vis;
    vector<vector<string>> ans;
    auto dfs = [&](this auto&& dfs, string u, int root) -> void {
        vis[u] = 1;

        for (string v : g[u]) {
            if (!vis[v]) {
                if (v.find('@') != -1) ans[root].push_back(v);
                dfs(v, root);
            }
        }
    };

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        string u = to_string(i); 
        if (!vis[u]) {
            cout << u << '\n';
            ans.push_back({accounts[i][0]});
            dfs(u, cnt++);
        }
    }

    for (auto &a : ans) sort(a.begin(), a.end());

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
