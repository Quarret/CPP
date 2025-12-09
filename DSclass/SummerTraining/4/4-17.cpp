#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int sum[1005][1005];
struct T {
    int num;
    int pos;
} a[1005][1005];
void solve() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> a[i][j].num;
        }
    }

    for (int i = 1; i <= n; i++) {
        sum[n][i] = a[n][i].num;
        a[n][i].pos = i;
    }

    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= n; j++) {
            if (sum[i + 1][j] > sum[i + 1][j + 1]) {
                sum[i][j] = sum[i + 1][j] + a[i][j].num;
                a[i][j].pos = j;
            } else {
                sum[i][j] = sum[i + 1][j + 1] + a[i][j].num;
                a[i][j].pos = j + 1;
            }
        }
    }

    cout << sum[1][1] << '\n';
    int next = 1, k = 1;
    while (k <= n) {
        cout << a[k][next].num << ' ';
        next = a[k][next].pos;
        k++;
    }

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}
