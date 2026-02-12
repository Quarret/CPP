#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector mat(2, vector<char>(n, '.'));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }
    
    int ans = 0;
    for (int j = 0; j <= n - 3; j++) {
        // 
        if (mat[0][j] == mat[0][j + 1] && mat[0][j + 1] == mat[0][j + 2] && mat[0][j + 2] == mat[1][j + 1] && mat[0][j + 1] == '.' && 
            mat[1][j] == mat[1][j + 2] && mat[1][j] == 'x') {
                ans++;
        }

        if (mat[1][j] == mat[1][j + 1] && mat[1][j + 1] == mat[1][j + 2] && mat[1][j + 2] == mat[0][j + 1] && mat[1][j + 1] == '.' && 
            mat[0][j] == mat[0][j + 2] && mat[0][j] == 'x') {
                ans++;
        }
    }

    cout << ans << '\n';
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