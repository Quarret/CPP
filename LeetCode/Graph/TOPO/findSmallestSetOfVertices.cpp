#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
    vector<int> in_deg(n);
    for (auto &e : edges) {
        int u = e[0], v = e[1];
        in_deg[v]++;
    }
    
    vector<int> topo;
    for (int i = 0; i < n; i++) {
        if (!in_deg[i]) topo.push_back(i);
    }
    
    return topo;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
