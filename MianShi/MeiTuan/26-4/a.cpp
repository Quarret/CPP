#include <bits/stdc++.h>
using ll = long long;
using namespace std;


void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] %= 2;
    }

    vector memo(n, vector(x, array<int, 2>{-1, -1}));
    auto dfs = [&](auto&& dfs, int i, int x, int s) -> bool {
        if (x == 0) {
            return s == 1;
        }
        if (i < 0) return false;

        int &res = memo[i][x][s];
        if (res != -1) return res;

        // 不选
        res = false;
        if (dfs(dfs, i - 2, x, s)) {
            res = true;
        }

        // 选左
        if (dfs(dfs, i - 2, x - 1, (s + a[i]) % 2)) {
            res = true;
        }

        // 选右
        if (i + 1 < n && dfs(dfs, i - 2, x - 1, (s + a[i + 1]) % 2)) {
            res = true;
        }

        return res;
    };

    if (n % 2) cout << (dfs(dfs, n - 1, x, 0) ? "Yes\n" : "No\n");
    else cout << (dfs(dfs, n - 2, x, 0) ? "Yes\n" : "No\n");
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