#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector ans(n, vector<char>(m, 'B'));
    ans[0][0] = 'W';

    for (auto &row : ans) {
        for (char c : row) {
            cout << c << ' ';
        }
        cout << '\n';
    }
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