#include <bits/stdc++.h>
using ll = long long;
using namespace std;


void solve() {
    int k, n;
    cin >> n >> k;

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;

        cnt += (c != 'M' && c != 'T');
    }

    cout << n - cnt + min(cnt, k) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}