#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;
    s += ' ';
    
    map<char, bool> vis, mp;

    for (int i = 0; i < n; i++) {
        if (s[i] == s[i + 1]) {
            cout << "NO" << '\n';
            return;
        }

        if (vis[s[i]] && mp[s[i]] != i % 2) {
            cout << "NO" << '\n';
            return;
        }

        vis[s[i]] = 1;
        mp[s[i]] = i % 2;   
    }

    cout << "YES" << '\n';
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
