#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool query(string s) {
    std::cout << "? " << s << endl;
    int res;
    cin >> res;
    return res;
};
void solve() {
    int n;
    cin >> n;

    string s;

    if (query("1")) {
        s += '1';
    } else {
        s += '0';
    }

    while (s.size() < n) {
        if (query(s + '0')) {
            s += '0';
        } else if (query(s + '1')) {
            s += '1';
        }  else {
            break;
        }
    }

    while (s.size() < n) {
        if (query('0' + s)) {
            s = '0' + s;
        } else if (query('1' + s)){
            s = '1' + s;
        } else {
            break;
        }
    }

    std::cout << "! " << s << endl;
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
