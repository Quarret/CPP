#include <bits/stdc++.h>
using ll = long long;
using namespace std;


void solve() {
    int E;
    cin >> E;

    int x, s = 0;
    vector<int> a;
    vector<int> damage, reward;
    while (cin >> x) a.push_back(x);
    int n = a.size() / 2;
    for (int i = 0; i < 2 * n; i++) {
        if (i < n) damage.push_back(a[i]);
        else {
            reward.push_back(a[i]);
            s += a[i];
        }
    }

    vector<vector<int>> memo(n, vector<int>(E + s + 1, -1));
    auto dfs = [&](auto&& dfs, int i, int left) -> int {
        if (i == n) {
            return 0;
        }

        int &res = memo[i][left];
        if (res != -1) return res;

        res = 0;
        if (left > damage[i]) {
            res = max(res, dfs(dfs, i + 1, left - damage[i] + reward[i]) + 1);
        }
        res = max(res, dfs(dfs, i + 1, left));
    };
    
    int ans = dfs(dfs, 0, E);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}