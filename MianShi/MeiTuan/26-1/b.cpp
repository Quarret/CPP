#include <bits/stdc++.h>
using ll = long long;
using namespace std;


void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    queue<int> q;
    int balence = 0;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            if (balence < 0) {
                ans += i - q.front();
                s[i] == ')';
                cout << q.front() << ' ' << i << '\n';
                q.pop();
            }
            balence++;
        } else {
            balence--;
            if (balence < 0) q.push(i);
        }
    }

    cout << ans << '\n';
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