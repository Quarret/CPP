#include <bits/stdc++.h>
using ll = long long;
using namespace std;


void solve() {
    int n, k;
    cin >> n >> k;
    
    auto cal = [&](ll x, int p) -> int {
        int res = 0;
        while (x > 0 && x % p == 0) {
            x /= p;
            res++;
        }

        return res;
    };

    vector<ll> a(n), cnt2(n), cnt5(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt2[i] = cal(a[i], 2);
        cnt5[i] = cal(a[i], 5);
    }

    vector<ll> pre2(n + 1, 0), pre5(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pre2[i + 1] = pre2[i] + cnt2[i];
        pre5[i + 1] = pre5[i] + cnt5[i];
    }

    ll total2 = pre2[n], total5 = pre5[n];
    if (total2 < k || total5 < k) {
        cout << 0 << '\n';
        return;
    }

    // [l, mid] 是被删除的区间
    ll ans = 0;
    for (int l = 0; l < n; l++) {
        ll base2 = pre2[l];
        ll base5 = pre5[l];

        ll left = l - 1, right = n, mid = 0, r = l - 1;
        while (left + 1 < right) {
            mid = left + (right - left) / 2;
            ll remain2 = total2 - (pre2[mid + 1] - pre2[l]);
            ll remain5 = total5 - (pre5[mid + 1] - pre5[l]);
        
            if (min(remain2, remain5) >= k) {
                r = mid;
                left = mid;
            } else {
                right = mid;
            }
        }

        if (r >= l) ans += r - l + 1;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}