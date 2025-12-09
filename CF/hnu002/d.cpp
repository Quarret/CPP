#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    double a, b;
    cin >> a >> b;

    bool flag = 0;
    auto dfs = [&](auto& self, double i, double j) -> void {
        if (i / j == 3 || i / j == 1.5 || i == j) {
            flag = 1;
            return;
        }

        if (i < j) {
            return;
        }

        self(self, i, j * 3);

        if ((int)j % 2 == 0) self(self, i, j * 1.5);
    };

    dfs(dfs, a, b);

    cout << (flag == 1 ? "YES" : "NO") << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
