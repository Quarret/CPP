#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
    vector<int> vis(c + 1), cancel(c + 1), indexs(c + 1);
    unordered_map<int, vector<int>> g;
    for (auto &e : connections) {
        int u = e[0], v = e[1];
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    unordered_map<int, set<int>> G;
    int idx = 0;
    for (int x = 1; x <= c; x++) {
        if (vis[x]) continue;
        
        queue<int> q;
        q.push(x);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            vis[u] = 1;
            G[idx].insert(u);
            indexs[u] = idx;

            for (int v : g[u]) {
                if (vis[v]) continue;
                q.push(v);
            }
        }

        idx++;
    }

    vector<int> ans;
    for (auto &t : queries) {
        int op = t[0], x = t[1];
        int num = indexs[x];
        if (op == 2) {
            cancel[x] = 1;
            G[num].erase(x);
            continue;
        }

        if (!cancel[x]) {
            ans.push_back(x);
            continue;
        }

        if (G[num].empty()) ans.push_back(-1);
        else ans.push_back(*G[num].begin());
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
