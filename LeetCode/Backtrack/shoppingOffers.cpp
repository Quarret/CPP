#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
    int n = price.size(), m = special.size();
    int ans = INT_MAX;
    map<vector<int>, int> mp;
    for (auto e : special) {
        vector<int> a(e.begin(), e.begin() + n);
        if (!mp.contains(a)) {
            mp[a] = e.back();
        } else {
            mp[a] = min(mp[a], e.back());
        }
    }

    auto dfs = [&](this auto&& dfs, int cost, vector<int> path) -> void {
        int res = 0;
        for (int j = 0; j < n; j++) {
            if (path[j] > needs[j]) return;
            res += (needs[j] - path[j]) * price[j];
        }
        
        ans = min(ans, cost + res);
        
        for (int j = 0; j < m; j++) {
            vector<int> a(special[j].begin(), special[j].begin() + n);
            if (special[j].back() != mp[a]) continue;
            vector<int> tmp = path;
            for (int k = 0; k < n; k++) {
                tmp[k] += special[j][k];
            }
            dfs(cost + special[j][n], tmp);
        }
    };

    vector<int> path(n, 0);
    dfs(0, path);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
