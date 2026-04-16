#include <bits/stdc++.h>
using ll = long long;
using namespace std;


void solve() {
    int n;
    cin >> n;

    vector grid(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            grid[i][j] = c - '0';
        }
    }

    vector sum(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + grid[i][j];
        }
    }

    for (int r = 0; r < n; r++) {
        int ans = 0;
        for (int x = 0; x < n - r; x++) {
            for (int y = 0; y < n - r; y++) {
                int x1 = x + r;
                int y1 = y + r;
                int s = sum[x1 + 1][y1 + 1] - sum[x1 + 1][y] - sum[x][y1 + 1] + sum[x][y];
                ans += (2 * s == (r + 1) * (r + 1));
            }
        }
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();    

    return 0;
}