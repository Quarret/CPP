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
        ll tmp = 1, res = 0, sum = 1ll * (n + 1) * n / 2;
        for (int j = 0; j < pos[i].size(); j++) {
            int num = pos[i][j] - tmp;
            res += (num + 1) * num / 2;
            tmp = pos[i][j] + 1;
        }
        if (!pos[i].empty() && tmp <= n) {
            int num = n - tmp;
            res += (num + 1) * num / 2;
        }
        
        ans += sum - res;
    }

    cout << ans << '\n';

    return 0;
}
