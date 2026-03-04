#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector w(n, vector<int>(n, INT_MAX / 2));
    for (auto &e : edges) {
        int x = e[0], y = e[1], wt = e[2];
        w[x][y] = w[y][x] = wt;
        w[x][x] = w[y][y] = 0;
    }
    
    // f[k][i][j] = min(f[k - 1][i][j], f[k - 1][i][k] + f[k - 1][k][j])
    auto f = move(w);
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }

    int mn = INT_MAX, ans = 0;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            // if (i == j) cout << f[i][j] << '\n';
            if (f[i][j] <= distanceThreshold) {
                cnt++;
            }
        }

        if (cnt <= mn) {
            mn = cnt;
            ans = i;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}