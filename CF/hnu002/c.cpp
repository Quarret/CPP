#include <bits/stdc++.h>
using ll = long long;
using namespace std;

ll maxn = 200005;
void solve() {
    ll n, m;
    string s;
    cin >> n;
    map<string, ll> mp;
    mp["1"] = maxn, mp["01"] = maxn, mp["11"] = maxn;

    for (int i = 0; i < n; i++) {
        cin >> m >> s;
        if (s[0] == '1' && s != "11") {
            mp["1"] = min(mp["1"], m);
        } else if (s == "01") {
            mp["01"] = min(mp["01"], m);
        } else if (s == "11") {
            mp["11"] = min(mp["11"], m);
        }
    }
    if (mp["11"] == maxn) {
        if (mp["1"] == maxn || mp["01"] == maxn) {
            cout << -1 << '\n';
            return;
        }

        ll ans = mp["1"] + mp["01"];
        cout << ans << '\n';
        return;
    }

    ll ans = mp["1"] + mp["01"];
    cout << min(ans, mp["11"]) << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
