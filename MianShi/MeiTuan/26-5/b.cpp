#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<array<ll, 2>> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i][0] >> p[i][1];
    }

    // dis[i] 表示其他点到 i 点的距离
    vector<vector<ll>> dis(n);
    unordered_map<int, unordered_map<int, ll>> mp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ll d = abs(p[i][0] - p[j][0]) * abs(p[i][0] - p[j][0]) + abs(p[i][1] - p[j][1]) * abs(p[i][1] - p[j][1]);
            dis[i].push_back(d);
            mp[i][j] = d;
        }
    }

    for (auto &arr : dis) {
        sort(arr.begin(), arr.end());
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                cout << 0 << ' ';
                continue;
            }
            ll d = mp[i][j];
            ll cnt = upper_bound(dis[i].begin(), dis[i].end(), d) - dis[i].begin();
            cout << cnt - 2 << ' ';
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