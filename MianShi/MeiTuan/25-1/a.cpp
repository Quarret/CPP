#include <bits/stdc++.h>
using ll = long long;
using namespace std;


void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector memo(n, vector(11, -1LL));
    auto dfs = [&](auto&& dfs, int i, int x) -> ll {
        if (i == n) {
            return 0;
        }

        ll &res = memo[i][x];
        if (res != -1) return res;

        res = max(dfs(dfs, i + 1, x) + i + 1, dfs(dfs, i + 1, (x + 1) % 10) + ((x + 1) % 10 + 1) * a[i]);
        return res;
    };

    cout << dfs(dfs, 0, 0) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}