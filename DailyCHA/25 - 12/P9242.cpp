#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), head(n), tail(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        tail[i] = a[i] % 10;
        head[i] = to_string(a[i])[0] - '0';
    }

    vector memo(n, vector<int>(10, -1));
    // 前 i 个数字中以 j 结尾的最长长度
    auto dfs = [&](this auto&& dfs, int i, int j) -> int {
        if (i < 0) {
            return 0;
        }

        int &res = memo[i][j];
        if (res != -1) {
            return res;
        }

        res = dfs(i - 1, j);
        if (tail[i] == j) {
            res = max(res, dfs(i - 1, head[i]) + 1);
        }

        return res;
    };

    int ans = 0;
    for (int i = 0; i <= 9; i++) {
        ans = max(ans, dfs(n - 1, i));
    }
    cout << n - ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
