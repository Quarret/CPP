#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pq.emplace(a[i], i);
    }

    vector<int> del(n, 0);
    for (int i = 0; i < m; i++) {
        auto [_, idx] = pq.top();
        pq.pop();
        del[idx] = 1;
    }

    for (int i = 0; i < n; i++) {
        if (!del[i]) cout << a[i] << ' ';
    }
    cout << '\n';
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