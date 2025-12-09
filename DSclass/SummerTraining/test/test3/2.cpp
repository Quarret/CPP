#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int n, m, f, ans = 0;
int a[2050][2050], pre[2050][2050];
void dfs(int& x, int& y, int r) {
    if (x + r > n || y + r > m) {
        return;
    }

    int res;
    res = pre[x + r][y + r] - pre[x + r][y] - pre[x][y + r] + pre[x][y];
    res = r * r - res;

    

    if (res <= f) {
        ans = max(ans, r);
        dfs(x, y, r + 1);
    } else {
        return;
    }
}
void solve() {
    cin >> n >> m >> f;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + a[i][j];
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dfs(i, j, 1);
            // for (int r = 1; r <= 2050; r++) {
            //     if (i + r > n || j + r > m) {
            //         break;
            //     }

            //     int res;
            //     res = pre[i + r][j + r] - pre[i + r][j] - pre[i][j + r] + pre[i][j];
            //     res = r * r - res;

                

            //     if (res <= f) {
            //         ans = max(ans, r);
            //     } else {
            //         break;
            //     }
            // }
        }
    }

    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
