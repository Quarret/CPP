#include <bits/stdc++.h>
using ll = long long;
using namespace std;


void solve() {
    int n, k;
    cin >> n >> k;

    string ans(n, 'b');
    for (int i = 0; i < n && k; i += 2) {
        ans[i] = 'a';
        if (i == 0 || i == n - 1) k--;
        else k -= 2;
    }

    if (k) cout << -1 << '\n';
    else cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}