#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int a[105][105];
void solve() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> a[i][j];
        }
    }

    int e = 1;
    for (int i = 1; i <= n; i++) {
        if (e >= i) {
            e = a[e][i];
        } else {
            e = a[i][e];
        }
    }

    cout << e << '\n';

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
