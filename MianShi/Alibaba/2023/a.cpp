#include <bits/stdc++.h>
using ll = long long;
using namespace std;


void solve() {
    int n;
    cin >> n;

    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < n; i++) cin >> y[i];
    
    vector<int> idxs(n);
    iota(idxs.begin(), idxs.end(), 0);
    sort(idxs.begin(), idxs.end(), [&](int &i, int &j) {
        return x[i] > x[j];
    });
    
    int ans = 1;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < i; j++) {
            if (x[i] > x[j] && y[i] > y[j]) cnt++;
        }
        ans = max(ans, cnt);
    }

    cout << ans << '\n';
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