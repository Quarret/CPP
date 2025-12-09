#include <bits/stdc++.h>
using ll = long long;
using namespace std;

map<string, string> mp;
void solve() {
    string s, s1, s2, s3;
    while (getline(cin, s)) {
        if (s == "@END@") {
            break;
        }

        int pos1 = s.find(']');
        s1 = s.substr(0, pos1 + 1);
        //cout << s1 << '\n';
        s2 = s.substr(pos1 + 2, s.size() - pos1 - 1);
        s3 = s.substr(1, pos1 - 1);
        mp[s1] = s2;
        mp[s2] = s3;
    }

    int n;
    cin >> n;
    getline(cin, s);
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        if (mp[s] == "") {
           cout << "what?\n"; 
        } else {
            cout << mp[s] << '\n';
        }
    }
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}
