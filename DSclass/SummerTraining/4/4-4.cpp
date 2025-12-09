#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int n;
void solve() {
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0, cnt;
    for (int i = 0; i < n; i++) {
        cnt = 0;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[i]) {
                cnt++;
            }
        }
        ans += cnt;
    }

    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (1) {
        cin >> n;
        if (!n) return 0;

        solve();
    }
}
