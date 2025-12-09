#include <bits/stdc++.h>
using ll = long long;
using namespace std;

//depend on 0x3f
// no circle and no direction edge -> like tree without brother leaf
double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
    auto f = [&](vector<vector<string>> pairs, vector<double> rates) {// no di gui not need return
        unordered_map<string, vector<pair<string, double>>> g;
        int n = pairs.size();
        for (int i = 0; i < n; i++) {
            string u = pairs[i][0], v = pairs[i][1];
            double rate = rates[i];
            g[u].emplace_back(v, rate);
            g[v].emplace_back(u, 1 / rate);
        }

        unordered_map<string, double> res;
        auto dfs = [&](this auto&& dfs, string u) -> void {//di gui need return
            double cur = res[u];

            for (auto [v, r] : g[u]) {
                if (!res.contains(v)) {
                    res[v] = 1.0 * cur * r;
                    dfs(v);
                }
            }
        };

        res[initialCurrency] = 1;
        dfs(initialCurrency);

        return res;
    };

    auto res1 = f(pairs1, rates1);
    auto res2 = f(pairs2, rates2);

    double ans = 0;
    for (auto [t, c] : res2) {
        ans = max(ans, res1[t] / c);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
