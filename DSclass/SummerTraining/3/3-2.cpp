#include <bits/stdc++.h>
using ll = long long;
using namespace std;


void solve() {
    string s;
    cin >> s;

    sort(s.begin() ,s.end());

    int cnt = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] != s[i - 1]) {
            cout << s[i - 1] << ":" << cnt << '\n';
            cnt = 0;
        }

        cnt++;
    }

    cout << s.back() << ":" << cnt << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}
