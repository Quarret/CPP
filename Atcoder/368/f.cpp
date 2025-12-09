#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    const int m = *max_element(a.begin(), a.end());

    vector< vector<int> > d(m + 1);
    for (int i = 1; i <= m; i++) {
        for (int j = 2 * i; j <= m; j += i) {
            d[j].push_back(i);
        }
    }

    vector<int> sg(m + 1, 0);
    for (int i = 2; i <= m; i++) {
        const int k = d[i].size();
        vector<int> cnt(k + 1);
        for (auto y : d[i]) {
            if (sg[y] <= k) {
                cnt[sg[y]]++;
            }
        }

        while (cnt[sg[i]]) sg[i]++;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans ^= sg[a[i]];
    }

    if (ans == 1) {
        cout << "Anna\n"; 
    } else {
        cout << "Bruno\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
