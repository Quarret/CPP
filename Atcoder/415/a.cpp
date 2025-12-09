#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n, num;
    cin >> n;
    int vis[105]{};

    for (int i = 0; i < n; i++) {
        cin >> num;
        vis[num] = 1;
    }

    int x;
    cin >> x;
    cout << (vis[x] ? "Yes" : "No") << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
