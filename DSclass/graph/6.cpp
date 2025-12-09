#include <bits/stdc++.h>
#define ll long long
using namespace std;

int e[10][10];
int ans[10];
int n, m, a, b;
void warshell() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (e[j][i]) {
                for (int h = 1; h <= n; h++) {
                    e[j][h] |= e[i][h]; 
                }
            }
        }
    }
}
void solve() {    
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        e[a][b] = 1;
    }

    e[1][1] = 1;

    warshell();

    for (int i = 1; i <= n; i++) {
        cout << e[1][i] << ' ';
    }

    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    
    int t;
    cin >> t;

    while (t--) {
    solve();
    }
}
