#include <bits/stdc++.h>
using ll = long long;
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    ll res = 0, sum = 0, res1, ans = 1e18;

    vector<int> k(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
        sum += k[i];
    }
    sort(k.begin(), k.end());

    res = k[n];
    for (int i = 0; i <= n - 1; i++) {
        res += k[i];
        res1 = sum - res;
        ans = min(ans, max(res, res1));
    }

    cout << ans << '\n';

    return 0;
}
