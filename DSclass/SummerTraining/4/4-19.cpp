#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int n;
void solve() {
    vector<int> a(n), b(n), expand(n + 1);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    reverse(b.begin(), b.end());
    b.push_back(1);

    expand[0] = a[0];
    expand[1] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = i; j >= 0;j --) {
            if (i == j) {
                expand[j] = 1;
            } else if (j == 0) {
                expand[0] *= a[i - 1];
            } else {
                expand[j] = expand[j] * a[i - 1] + expand[j - 1];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (b[i] != expand[i]) {
            cout << 'N' << '\n';
            return;
        }
    }

    cout << "Y" << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> n && n) {
        solve();
    }
}
