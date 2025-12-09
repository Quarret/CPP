#include <bits/stdc++.h>
using ll = long long;
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    cin >> s >> t;

    for (int i = 0; i < t.size(); i++) {
        if (s[i] != t[i] || i > s.size()) {
            cout << i + 1 << '\n';
            return 0;
        }

        if (i == t.size() - 1 && t.size() != s.size()) {
            cout << i + 2 << '\n';
            return 0;
        }
    }

    cout << 0 << '\n';

    return 0;
}
