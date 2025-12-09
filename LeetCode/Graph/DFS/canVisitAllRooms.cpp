#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int n = rooms.size();
    vector<int> vis(n);
    int cnt = 0;
    
    auto dfs = [&](this auto&& dfs, int u) -> void {
        vis[u] = 1;
        cnt++;

        for (int v : rooms[u]) {
            if (!vis[v]) dfs(v);
        }
    };

    dfs(0);

    return cnt == n;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
