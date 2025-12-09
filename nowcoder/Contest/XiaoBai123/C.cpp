#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int ok = 1;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] >= a[i + 1]) {
            ok = 0;
        }
    }

    if (ok) {
        cout << "0\n";
        return;
    }

    auto check = [&](int x) -> bool {
        int cnt = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] > a[i - 1]) continue;
            i64 diff = 1LL * (a[i - 1] - a[i] + 1);
            cnt += 1LL * (diff + x - 1) / x;
            if (cnt > m) return false;
        }

        return true;
    };

    int l = 0, r = 1e9 + 5;
    while (l + 1 < r) {
        int mid = l + (r - l) / 2;
        (check(mid) ? r : l) = mid;
    }

    cout << (r == 1e9 + 5 ? -1 : r) << '\n';
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
