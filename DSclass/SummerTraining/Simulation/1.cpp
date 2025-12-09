#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n, m, p, q, tmp;
    cin >> n >> m >> p >> q;

    vector<int> a;

    for (int i = 0;i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> tmp;
            a.push_back(tmp);
        }
    }

    int num = 0;
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            cout << a[num++] << ' ';
        }
        cout << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
