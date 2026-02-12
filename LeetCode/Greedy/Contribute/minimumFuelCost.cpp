#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
    using ll = long long;
    unordered_map<int, vector<int>> g;
    for (auto &e : roads) {
        int x = e[0], y = e[1];
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    ll ans = 0;
    auto dfs = [&](this auto&& dfs, int x, int fa) -> ll {
        ll s = 0;

        for (int y : g[x]) {
            if (y == fa) continue;
            s += dfs(y, x);
        }

        if (x != 0) ans += (s + seats) / seats;
        return s + 1;
    };

    dfs(0, -1);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}