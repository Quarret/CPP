#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int n;
void solve() {
    int cnt = 0;

    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = (3 * n + 1) / 2;
        }
        cnt++;
    }

    cout << cnt << '\n';

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie();

    while (1) {
        cin >> n;
        if (!n) {
            return 0;
        }

        solve();
    }

}
