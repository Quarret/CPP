#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
    unordered_map<int, vector<int>> row, col;
    vector<int> r_indeg(k + 1), c_indeg(k + 1);
    for (auto &e : rowConditions) {
        int u = e[0], v = e[1];
        row[u].push_back(v);
        r_indeg[v]++;
    }
    
    for (auto &e : colConditions) {
        int u = e[0], v = e[1];
        col[u].push_back(v);
        c_indeg[v]++;
    }

    queue<int> q;
    vector<array<int, 2>> mat(k + 1, {500, 500});
    for (int u = 1; u <= k; u++) {
        if (!r_indeg[u]) q.push(u);
    }

    int cnt = 0;
    vector<int> topo1, topo2;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo1.push_back(u);
        mat[u][0] = cnt++;

        for (int v : row[u]) {
            r_indeg[v]--;
            if (!r_indeg[v]) q.push(v);
        }
    }

    if (topo1.size() != k) return {};

    
    cnt = 0;
    for (int u = 1; u <= k; u++) {
        if (!c_indeg[u]) q.push(u);//all point will be operated
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo2.push_back(u);
        mat[u][1] = cnt++;

        for (int v : col[u]) {
            c_indeg[v]--;
            if (!c_indeg[v]) q.push(v);
        }
    }

    if (topo2.size() != k) return {};

    vector<vector<int>> res(k, vector<int>(k, 0));
    for (int u = 1; u <= k; u++) {
        auto [x, y] = mat[u];
        res[x][y] = u;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
