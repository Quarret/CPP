#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    double num1 = sqrt(n);

    if (num1 != (int)num1) {
        cout << "No" << '\n';
        return;
    }

    int r = (int)num1;

    for (int i = 0; i < s.size(); i++) {
        if (i < r) {
            if (s[i] == '0') {
                cout << "No" << '\n';
                return;
            }
        } else if (i % r == 0) {
            if (s[i] == '0') {
                cout << "No" << '\n';
                return;
            }
        } else if (i % r == r - 1) {
            if (s[i] == '0') {
                cout << "No" << '\n';
                return;
            }
        } else if (i / r == r - 1) {
            if (s[i] == '0') {
                cout << "No" << '\n';
                return;
            }
        } else {
            if (s[i] == '1') {
                cout << "No" << '\n';
                return;
            }
        }
    }

    cout << "Yes" << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
