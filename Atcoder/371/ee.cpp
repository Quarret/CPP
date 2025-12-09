#include <bits/stdc++.h>
using ll = long long;
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a;
    cin >> n;

    vector< vector<int> > pos(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a;
        pos[a].push_back(i);
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ll sum = 0;
        sum = 1ll * (1 + n) * n / 2;
        pos[i].push_back(n + 1);
        int last = 0;
        for (auto e: pos[i]) {
            int l = e - 1 - (last + 1) + 1;
            sum -= 1ll * l * (l + 1) / 2;
            last = e;
        }
        ans += sum;
    }

    cout << ans << '\n';
    return 0;
}
