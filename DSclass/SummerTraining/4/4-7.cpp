#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int cnt = 1, ans = -1;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            cnt++;
        } else {
            ans = max(ans, cnt);
            cnt = 1;
        }
    }
    ans = max(ans, cnt);

    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}
