#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<int> vis(n);

    auto dfs = [&](this auto&& dfs, int i) -> void {
        vis[i] = 1;

        for (int j = 0; j < n; j++) {
            if (isConnected[i][j] && !vis[j]) dfs(j);
        }
    };

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i);
            ans++;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
