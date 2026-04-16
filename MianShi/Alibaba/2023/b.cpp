#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    const ll MOD = 1e9 + 7;

    ll A, B, n;
    cin >> A >> B >> n;

    vector memo(n + 1, -1LL);
    auto dfs = [&](auto&& dfs, int i) -> ll {
        if (i == 0) return 2;
        else if (i == 1) return A;

        ll &res = memo[i];
        if (res != -1) return res;

        res = ((dfs(dfs, i - 1) * A - dfs(dfs, i - 2) * B) % MOD + MOD) % MOD;
        return res;
    };

    cout << dfs(dfs, n) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}