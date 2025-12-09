#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    string s1, s2, cur = "http://www.game.org/";
    stack<string> stf, stb;
    while (cin >> s1) {
        if (s1 == "QUIT") {
            return;
        }

        if (s1 == "VISIT") {
            cin >> s2;
            stb.push(cur);
            cur = s2;
            while (!stf.empty()) {
                stf.pop();
            }
            cout << cur << '\n';
        } else if (s1 == "BACK") {
            if (!stb.empty()) {
                stf.push(cur);
                cur = stb.top();
                stb.pop();
                cout << cur << '\n';
            } else {
                cout << "Ignored\n";
            }
        } else if (s1 == "FORWARD") {   
            if (!stf.empty()) {
                stb.push(cur);
                cur = stf.top();
                stf.pop();
                cout << cur << '\n';
            } else {
                cout << "Ignored\n";
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}
