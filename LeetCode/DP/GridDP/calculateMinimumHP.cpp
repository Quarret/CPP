#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int m = dungeon.size(), n = dungeon[0].size();
    vector f(m + 1, vector<int>(n + 1, -1e9)), f1(m + 1, vector<int>(n + 1, -1e9));
    
    f[0][1] = 0, f1[0][1] = f1[1][0] = 0, f[1][0] = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            f[i + 1][j + 1] = max(f[i + 1][j], f[i][j + 1]) + dungeon[i][j];
            f1[i + 1][j + 1] = min(max(f1[i][j + 1], f1[i + 1][j]), f[i + 1][j + 1]);
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cout << f[i][j] << ' ';
        }
        cout << '\n';
    }

    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cout << f1[i][j] << ' ';
        }
        cout << '\n';
    }

    int ans1 = f[m - 1][n] + dungeon[m - 1][n - 1], ans2 = f[m][n - 1] + dungeon[m - 1][n - 1];
    ans1 = ans1 >= 0 ? 0 : ans1;
    ans2 = ans2 >= 0 ? 0 : ans2;
    if (f1[m - 1][n] > f1[m][n - 1]) return 1 - min(ans1, f1[m - 1][n]);
    else if (f1[m - 1][n] < f1[m][n - 1]) return 1 - min(ans2, f1[m][n - 1]);
    else return min((1 - min(ans2, f1[m][n - 1])), (1 - min(ans1, f1[m - 1][n])));

    // if (f1[m - 1][n] > f1[m][n - 1]) {
    //     int ans = f[m - 1][n] + dungeon[m - 1][n - 1];
    // }
}

int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int m = dungeon.size(), n = dungeon[0].size();
    vector f(m + 1, vector<int>(n + 1, INT32_MAX));
    
    f[m][n - 1] = f[m - 1][n] = 1;
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            f[i][j] = max(min(f[i + 1][j], f[i][j + 1]) - dungeon[i][j], 1);
        }
    }

    return f[0][0];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
