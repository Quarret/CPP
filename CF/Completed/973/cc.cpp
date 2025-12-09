#include <bits/stdc++.h>
using ll = long long;
using namespace std;
 
void solve() {
    

    int n;
    cin >> n;
 
    string s;

    auto query = [&](string ss) -> bool {
        cout << "? " << ss << endl;
        cout.flush();
        int res;
        cin >> res;
        return res;
    };
 
    if (query("1")) {
        s += '1';
    } else {
        s += '0';
    }
 
    while (s.size() < n) {
        if (query(s + '1')) {
            s += '1';
        } else if (query(s + '0')) {
            s += '0';
        } else {
            break;
        }
    }
 
    while (s.size() < n) {
        if (query('1' + s)) {
            s = '1' + s;
        } else if (query('0' + s)) {
            s  = '0' + s;
        } else {
            break;
        }
    }
 
    cout << "! " << s << endl;
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