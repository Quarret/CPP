#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    ll n, m;
    cin >> n >> m;

    vector<array<int, 2>> arr(m);

    for (int i = 0; i < m; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }

    sort(arr.begin(), arr.end(), [&](array<int, 2> x, array<int, 2> y) {
        //if (x.first - x.second == y.first - y.second) return x.first > y.first;
        return x[0] - x[1] < y[0] - y[1];
    });

    ll ans = 0;
    ll cur = n;
    for (int i = 0; i < m; i++) {
        int a = arr[i][0], b = arr[i][1];

        if (cur >= a) {
            int cnt = (cur - a + a - b) / (a - b);
            ans += cnt;
            cur -= cnt * (a - b);
        }
    }

    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
