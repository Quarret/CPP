#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> h(n);

    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    ll t = 0, op = 0;
    for (int i = 0; i < n; i++) {
        if (t == 0) {
            int tmp1 = h[i] / 5;
            int tmp2 = h[i] % 5;

            op += 3 * tmp1;
            if (tmp2 == 0) {
                t = 0;
                continue;
            }
            if (tmp2 == 1) {
                op++;
                t = 1;
            } else if (tmp2 == 2) {
                op += 2;
                t = 2;
            } else {
                op += 3;
                t = 0;
            }
        } else if (t == 1) {
            int tmp1 = h[i];
            tmp1 -= 1;
            op++;
            if (tmp1 <= 0) {
                t = 2;
                continue;
            }

            tmp1 -= 3;
            op++;
            if (tmp1 <= 0) {
                t = 0;
                continue;
            }

            int tmp = tmp1;
            op += 3 * (tmp / 5);
            int tmp2 = tmp % 5;
            if (tmp2 == 0) {
                t = 0;
                continue;
            }
            if (tmp2 == 1) {
                op++;
                t = 1;
            } else if (tmp2 == 2) {
                op += 2;
                t = 2;
            } else {
                op += 3;
                t = 0;
            }
        } else if(t == 2) {
            int tmp1 = h[i];
            tmp1 -= 3;
            op++;
            if (tmp1 <= 0) {
                t = 0;
                continue;
            }

            int tmp = tmp1;
            op += 3 * (tmp / 5);
            int tmp2 = tmp % 5;
            if (tmp2 == 0) {
                t = 0;
                continue;
            }
            if (tmp2 == 1) {
                op++;
                t = 1;
            } else if (tmp2 == 2) {
                op += 2;
                t = 2;
            } else {
                op += 3;
                t = 0;
            }
        } 
    }

    cout << op << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
