#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n, d, k;
    cin >> n >> d >> k;

    vector<int> in(n + 1, 0), out(n + 1, 0);
    while (k--) {
        int l, r;
        cin >> l >> r;
        in[l]++;
        out[r]++;
    }

    int ret = 0;
    int r1 = -1, r2 = -1;
    int ret1 = -1, ret2 = n + 1;
    for (int i = 1; i + d - 1 <= n; i++) {
        ret -= out[i - 1];
        ret += in[i + d - 1];

        if (ret > ret1) {
            ret1 = ret;
            r1 = i;
        }

        if (ret < ret2) {
            ret2 = ret;
            r2 = i;
        }
    }

    //cout << ret << ' ' << ret1 << ' ' << ret2 << '\n';
    cout << r1 << ' ' << r2 << '\n';
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
