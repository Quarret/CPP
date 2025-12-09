#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    string s, t;
    cin >> s >> t;
    vector<string> x;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] > t[i]) {
            s[i] = t[i];
            x.push_back(s);
        }
    }

    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] < t[i]) {
            s[i] = t[i];
            x.push_back(s);
        }
    }

    cout << x.size() << '\n';
    for (auto y : x) {
        cout << y << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
