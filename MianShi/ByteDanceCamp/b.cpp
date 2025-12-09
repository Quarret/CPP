#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve() {
    int n, dis;
    cin >> n >> dis;
    vector<int> a(n), b(n);
    a[0] = b[0] = dis;

    int cnt;
    for (int i = 1; i < n; i++) {
        cin >> cnt;
        a[i] = min(cnt * 400 + 399, 1000);
        b[i] = cnt * 400;
    }

    sort(a.begin(), a.end(), greater());
    sort(b.begin(), b.end(), greater());

    int least = 0, best = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == dis) {
            least = i + 1;
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (b[i] == dis) {
            best = i + 1;
            break;
        }
    }

    cout << best << ' ' << least << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
