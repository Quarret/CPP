#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n, x, y;
    cin >> n;

    vector<int> n0, n1;
    bool vis0[200050] = {0}, vis1[200050] = {0};

    for (int i = 0; i < n; i++) {
        cin >> x >> y;

        if (!y) {
            n0.push_back(x);
            vis0[x] = true;
        } else {
            n1.push_back(x);
            vis1[x] = true;
        }
    }

    int num0 = n0.size(), num1 = n1.size();
    ll ans = 0;

    for (int i = 0; i < num0; i++) {
        if (vis1[n0[i]]) {
            ans += n - 2;
        }
    }


    int tmp;
    for (int i = 0; i < num0; i++) {
        tmp = n0[i] + 2;
        if (vis0[tmp] == true && vis1[(n0[i] + tmp) / 2] == true) {
            ans++;
        }
    }

    for (int i = 0; i < num1; i++) {
        tmp = n1[i] + 2;
        if (vis1[tmp] == true && vis0[(n1[i] + tmp) / 2] == true) {
            ans++;
        }
    }

    cout << ans << '\n';
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
