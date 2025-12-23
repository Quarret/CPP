#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    string s;
    cin >> s;

    if (n % 2) {
        cout << -1 << '\n';
        return;
    }
    
    int mx = 0;
    vector<int> cnt(26);
    for (char c : s) {
        cnt[c - 'a']++;
        mx = max(mx, cnt[c - 'a']);
    }
    
    if (mx > n / 2) {
        cout << -1 << '\n';
        return;
    }

    int maxx = 0, sum = 0;
    vector<int> cnt1(26);
    for (int i = 0; i < n / 2; i++) {
        if (s[i] == s[n - 1 - i]) {
            cnt1[s[i] - 'a']++;
            maxx = max(maxx, cnt1[s[i] - 'a']);
            sum++;
        }
    }

    cout << max((sum + 1) / 2, maxx) << '\n';
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
