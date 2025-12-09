#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    double num;
    cin >> num;

    string s = to_string(num);

    int pos = s.find('.');

    for (int i = s.size() - 1; i >= pos; i--) {
        if (s[i] == '0' || s[i] == '.') {
            s.pop_back();
        } else {
            break;
        }
    }

    cout << s << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
