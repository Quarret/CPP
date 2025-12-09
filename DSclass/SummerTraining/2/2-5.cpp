#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n;
    while (cin >> n) {
        ll sum = 0, num = n;
        for (int i = 1; i <= n; i++) {
            if (num <= i) {
               sum += i * num;
               break;
            } else {
                sum += i * i;
                num -= i;
            }
        }

        cout << n << ' ' << sum << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}
