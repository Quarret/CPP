#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') cnt0++;
        else cnt1++;
    }

    int maxx = cnt1 / 2 + cnt0 / 2, minn = abs(cnt1 - cnt0) / 2;

    if (k >= minn && k <= maxx && (k - minn) % 2 == 0) cout << "Yes\n";
    else cout << "No\n";
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
