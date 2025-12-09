#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    ll n, k, sum = 0;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i < n; i++) {
        sum += abs(a[i] - a[i - 1]);
    }

    ll maxx = -1, minn = 1e9;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            ll num1 = abs(a[i + 1] - a[i]), tmp = a[i] + k, tmp1 = a[i] - k;
            ll num2 = abs(tmp - a[i + 1]), num3 = abs(tmp1 - a[i + 1]);
            ll sum1 = sum + num2 - num1, sum2 = sum + num3 - num1;
            maxx = max(maxx, sum1), maxx = max(maxx, sum2);
            minn = min(minn, sum1), minn = min(minn, sum2);
        } else if (i == n - 1) {
            ll num1 = abs(a[i - 1] - a[i]), tmp = a[i] + k, tmp1 = a[i] - k;
            ll num2 = abs(tmp - a[i - 1]), num3 = abs(tmp1 - a[i - 1]);
            ll sum1 = sum + num2 - num1, sum2 = sum + num3 - num1;
            maxx = max(maxx, sum1), maxx = max(maxx, sum2);
            minn = min(minn, sum1), minn = min(minn, sum2);
        } else {
            ll num1 = abs(a[i - 1] - a[i]) + abs(a[i + 1] - a[i]), tmp = a[i] + k, tmp1 = a[i] - k;
            ll num2 = abs(tmp - a[i - 1]) + abs(tmp - a[i + 1]), num3 = abs(tmp1 - a[i - 1]) + abs(tmp1 - a[i + 1]);
            ll sum1 = sum + num2 - num1, sum2 = sum + num3 - num1;
            maxx = max(maxx, sum1), maxx = max(maxx, sum2);
            minn = min(minn, sum1), minn = min(minn, sum2);
        }
    }

    cout << maxx << ' ' << minn << '\n';

    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
