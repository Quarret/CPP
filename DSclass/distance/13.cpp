#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s;
void solve() {
    cin >> s;

    stack<char> st1, st2;
    for (int i = 'F'; i >= 'A'; i--) {
        st1.push((char)i);
    }
    
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (st2.size() != 0) {
        if (st2.top() == s[i]) {
            cout << 'Y';
            //cout << st2.top() << '\n';
            st2.pop();
            continue;
        }
        }
            while(st1.top() != s[i]) {
                st2.push(st1.top());
                st1.pop();
                cout << 'X';
                if (!st1.size()) {
                    system("cls");
                    cout << "NO" << '\n';
                    return;
                }
            }
            cout << 'X';
            cout << 'Y';
            //cout << st1.top() << '\n';
            st1.pop();
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    
    solve();
}
