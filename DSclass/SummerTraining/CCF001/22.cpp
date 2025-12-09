#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int n, p, tmp, ans = 1e9;
vector<int> k;
void dfs(int x, int res) {
    if (x < 1) {
        return;
    } else if (x > n) {
        return;
    } else if (x == n) {
        ans = min(ans, res);
        return;
    }

    dfs(x - k[x], res + 1);
    dfs(x + k[x], res + 1);
}
void solve() {
    cin >> n >> p;

    k.push_back(0);
    for (int i = 0; i < n - 1; i++) {
        cin >> tmp;
        k.push_back(tmp);
    }

    for (int i = 1; i <= p; i++) {
        dfs(i , 1);
    }

    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
