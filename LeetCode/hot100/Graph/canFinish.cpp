#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int, vector<int>> g;
    vector<int> indeg(numCourses, 0);
    
    for (auto &e : prerequisites) {
        int v = e[0], u = e[1];
        g[u].push_back(v);
        indeg[v]++;
    }

    queue<int> q;
    for (int u = 0; u < numCourses; u++) {
        if (!indeg[u]) q.push(u);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : g[u]) {
            if (indeg[v] == 1) q.push(v);
            indeg[v]--;
        }
    }

    for (int u = 0; u < numCourses; u++) {
        if (indeg[u]) return false;
    }

    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
