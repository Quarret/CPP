#include <bits/stdc++.h>
using ll = long long;
using namespace std;


void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] %= 2;
    }

    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < n - 2; i += 2) {
        if (a[i] == 0 && a[i + 1] == 0) cnt0++;
        else if (a[i] == 1 && a[i + 1] == 1) cnt1++;
    }

    if (n & 2) {
        if (a[n - 1]) cnt1++;
        else cnt0++;
    } else {
        if (a[n - 2] == 1 && a[n - 1] == 1) cnt1++;
        if (a[n - 2] == 0 && a[n - 1] == 0) cnt0++;
    }

    int res = (n + 1) / 2 - (cnt0 + cnt1);
    if (res >= x) cout << "Yes\n";
    else if ((cnt0 && res > 0) || cnt1) cout << "Yes\n";
    else cout << "No\n";

    // if (cnt0 + cnt1 == (n + 1) / 2 && 
    // (cnt1 == 0 || (x % 2 == 0 && cnt0 == 0) || (x == (n + 1) / 2 && (cnt0 + cnt1) % 2))) {
    //     cout << "No\n";
    //     return;
    // } else {
    //     cout << "Yes\n";
    // }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}