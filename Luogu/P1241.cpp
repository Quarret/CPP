#include <bits/stdc++.h>
using namespace std;
void solve() {
    string s;
    cin >> s;
    vector<char> l, r;
    vector<string> ans;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == ')') {
            if (l[l.size() - 1] == '(' && !l.empty()) {
                l.pop_back();
                ans.push_back("()");
            } else {
                r.push_back(')');
            }
        }
        else if(s[i] == ']') {
            if (l[l.size() - 1] == '[' && !l.empty()) {
                l.pop_back();
                ans.push_back("[]");
            } else {
                r.push_back(']');
            }

        } else {
            l.push_back(s[i]);
        }
    }
    
    if (!l.empty()) {
    int num = l.size();
    for (int i = 0; i < num; i++) {
        if (l[i] == '(') {
           cout << "()";
        } else {
           cout << "[]";
        }
    }
    }
    if (!ans.empty()) {
    int num = ans.size();
       for (int i = 0; i < num; i++) {
        cout << ans[i];
       }
    }

    if (!r.empty()) {
        int num = r.size();
    for (int i = 0; i < num; i++) {
        if (r[i] == ')') {
           cout << "()" ;
        } else {
           cout << "[]";
        }
    }
    }

    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}