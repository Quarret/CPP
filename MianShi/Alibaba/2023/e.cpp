#include <bits/stdc++.h>
using ll = long long;
using namespace std;


void solve() {
    ll n;
    cin >> n;

    vector<array<ll, 2>> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i][0] >> arr[i][1];

    sort(arr.begin(), arr.end());

    vector<ll> suf_max(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        suf_max[i] = max(suf_max[i + 1], arr[i][1]);
    }

    auto check = [&](ll x) -> bool {
        for (int i = 0; i < n; i++) {
            ll need_a = x - arr[i][0];
            ll need_b = x - arr[i][1];

            int idx = lower_bound(arr.begin() + i + 1, arr.end(), need_a, [&](auto &p1, ll val) {
                return p1[0] < val;
            }) - arr.begin();

            if (idx < n && suf_max[idx] >= need_b) return true;
        }

        return false;
    };

    ll l = 0, r = 4e8 + 1, mid = 0;
    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        (check(mid) ? l : r) = mid;
    }

    cout << fixed << setprecision(1) << l / 2.0 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}