#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n, m;
    char x;
    cin >> n >> m;
    int a[n][m] = {0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> x;
            a[i][j] = x - '0';
        }
    }

    for (int i = 0; i < n; i++) {
        int b[m] = {0};
        for (int j = 0; j < n; j++) {
            if (j != i) {
                for (int h = 0; h < m; h++) {
                    b[h] |= a[j][h];
                }
            }
        }

        for (int j = 0; j < m; j++) {
            if (b[j] == 0) {
                break;
            }
            if(j == m - 1) {
                cout << "YES" << '\n';
                return;
            }
        }
    }

    cout << "NO" << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}
