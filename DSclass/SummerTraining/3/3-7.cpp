#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    string s, ans;
    cin >> s;
    ll num = 0;

    for (int i = 0; i < s.size(); i++) {
        num += s[i] - '0';
    }

    ans = to_string(num);

    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] == '0') {
            cout << "ling" << ' ';
        } else if (ans[i] == '1') {
            cout << "yi" << ' ';
        } else if (ans[i] == '2') {
            cout << "er" << ' ';
        } else if (ans[i] == '3') {
            cout << "san" << ' ';
        } else if (ans[i] == '4') {
            cout << "si" << ' ';
        } else if (ans[i] == '5') {
            cout << "wu" << ' ';
        } else if (ans[i] == '6') {
            cout << "liu" << ' ';
        } else if (ans[i] == '7') {
            cout << "qi" << ' ';
        } else if (ans[i] == '8') {
            cout << "ba" << ' ';
        } else if (ans[i] == '9') {
            cout << "jiu" << ' ';
        }
    }

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}
