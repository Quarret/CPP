#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    string s;
    cin >> s;
    //cout << s << '\n';
    stack<char> stl, str;
    int n = s.size();

    for (int i = 0; i < n; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{' || s[i] == '<') {
            stl.push(s[i]);
        } else if (s[i] == ')') {
            if (stl.empty()) {
                cout << "No" << '\n';
                return;
            }
            if (stl.top() == '(') {
                stl.pop();
            } else {
                str.push(s[i]);
            }
        } else if (s[i] == ']') {
            if (stl.empty()) {
                cout << "No" << '\n';
                return;
            }
            if (stl.top() == '[') {
                stl.pop();
            } else {
                str.push(s[i]);
            }
        } else if (s[i] == '}') {
            if (stl.empty()) {
                cout << "No" << '\n';
                return;
            }
            if (stl.top() == '{') {
                stl.pop();
            } else {
                str.push(s[i]);
            }
        } else if (s[i] == '>') {
            if (stl.empty()) {
                cout << "No" << '\n';
                return;
            }
            if (stl.top() == '<') {
                stl.pop();
            } else {
                str.push(s[i]);
            }
        }
    }

    cout << ((stl.empty() && str.empty()) ? "Yes" : "No") << '\n';
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
