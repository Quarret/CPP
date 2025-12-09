#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    string s;
    cin >> s;
    char c = s[0];
    int n = s.size();
    if (n == 1) {
        cout << "NO" << '\n';
        return;
    }
    for (int i = 1; i < n; i++) {
        if (s[i] != c) {
            s[0] = s[i];
            s[i] = c;
            cout << "YES" << '\n';
            cout << s << '\n';
            return;
        }
    }

    cout << "NO" << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
