#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
    using ll = long long;
    auto [mn, mx] = ranges::minmax(workerTimes);
    ll left = 0, right = mx * (1 + 1LL * mountainHeight) * 1LL * mountainHeight / 2 + 1;
    ll n = workerTimes.size(), mid = 0;

    auto check = [&](ll k) -> bool {
        ll ans = 0, num = 0;
        for (ll x : workerTimes) {
            num = sqrt(2 * k / x);
            if ((1 + num) * num > 2 * k / x) ans += num - 1;
            else ans += num;
        }

        return ans >= mountainHeight;
    };

    while (left + 1 < right) {
        ll mid = left + (right - left) / 2;
        (check(mid) ? right : left) = mid;
    }

    return right;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}