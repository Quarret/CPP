#include <bits/stdc++.h>
#define ll long long
using namespace std;

set<int> st;
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    if (s[0] == '0' && n >= 10) {
        cout << "Yes" << '\n';
        return;
    }
    if (n >= 10) {
        cout << "No" << '\n';
        return;
    }   
    ll num = stoll(s);
    if (num == 0) {
        cout << "Yes" << '\n';
        return;
    }
    ll num1 = num * n;
    string s1 =to_string(num1);
    if (s1.size() > n) {
        cout << "No" << '\n';
        return;
    }

    for (int i = 2; i <= n; i++) {
        ll num2 = num * i;
        string tmp = to_string(num2);
        tmp += tmp;
        if (tmp.find(s) == -1) {
            cout << "No" << '\n';
            return;
        }
    }

    cout << "Yes" << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}
