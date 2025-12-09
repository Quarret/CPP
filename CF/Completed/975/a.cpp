#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if ((i + 1) % 2) cnt1++;
        else cnt2++;
    }

    int maxx = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= maxx) {
            if ((i + 1) % 2) {
                ans = max(a[i] + cnt1, ans);
            } else {
                ans = max(a[i] + cnt2, ans); 
            }
            maxx = a[i];
        }
    }

    cout << ans << '\n';
    
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
