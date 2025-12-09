#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    ll k;
    cin >> k;
    ll n, d, e;

    while (k--) {
        cin >> n >> d >> e;
        ll n1, n2, num1, num2, p, q;
        double tmp1, tmp2;
        n2 = n;
        n1 = n + 2 - e * d;

        num1 = (n2 + sqrt(n2 * n2 - 4 * n1)) / 2;
        num2 = (n2 - sqrt(n2 * n2 - 4 * n1)) / 2;

        if ((int)(1.0 * (n2 + sqrt(n2 * n2 - 4 * n1)) / 2) == (1.0 * (n2 + sqrt(n2 * n2 - 4 * n1)))) {
            p = num1;
            q = n1 - num1;
            if (num1 > 0 && num2 > 0) {
                cout << p << ' ' << q << '\n';
                return;
            }
        }
        
        if ((int)(1.0 * (n2 - sqrt(n2 * n2 - 4 * n1)) / 2) == (1.0 * (n2 - sqrt(n2 * n2 - 4 * n1)))) {
            p = num2;
            q = n1 - num2;

            if (num1 > 0 && num2 > 0) {
                cout << p << ' ' << q << '\n';
                return;
            }
        }
        

        cout << "NO" << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
