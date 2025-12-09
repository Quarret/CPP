#include <bits/stdc++.h>
using ll = long long;
using namespace std;

string s;
int n;
void solve() {
    if (n < 3) {
        cout << "No\n";
        return;
    }

    if (s[n - 1] == 'n' && s[n - 2] == 'a' && s[n - 3] == 's') {
        cout << "Yes\n";
        return;
    } else {
        cout << "No\n";
        return;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;

    n = s.size();

    solve();

    return 0;
}
