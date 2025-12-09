#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n, k, tmp;
    cin >> n >> k;
    set<ll> s;

    for (int i = 0; i < n; i++) {
        cin >> tmp;
        s.insert(tmp);
    }

    int cnt = 0;
    for (auto &it : s) {
        cout << it << ' ';
        cnt++;
        if (cnt == k) {
            cout << '\n';
            return;
        } 
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}
