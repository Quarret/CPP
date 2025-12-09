#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
    unordered_map<string, vector<string>> g;
    int n = recipes.size();
    unordered_map<string, int> in_deg;
    for (int i = 0; i < n; i++) {
        string v = recipes[i];
        for (string u : ingredients[i]) {
            g[u].push_back(v);
            in_deg[v]++;
        }
    }
    
    vector<string> topo;
    queue<string> q;
    for (string u : supplies) q.push(u);
    
    while (!q.empty()) {
        string u = q.front();
        q.pop();

        for (string v : g[u]) {
            in_deg[v]--;
            if (!in_deg[v]) {
                topo.push_back(v);
                q.push(v);
            }
        }
    }

    return topo;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
