#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    string s, s1, s2;
    cin >> s;
    s1 = s.substr(0, 2);
    s2 = s.substr(3, 2);

    int num1 = stoi(s1), num2 = stoi(s2);

    int ans = 0;
    if (num1 == 0 || num1 > 12) {
        ans++;
        if (num1 == 0) {
            num1 = 1;
        } else {
            if (s1[0] == '1') {
                num1 = 12;
            }else if (s1[1] == '0') {
                num1 = 10;
            } else if (s1[1] == '1') {
                num1 = 1;
            } else if (s1[1] == '2') {
                num1 = 12;
            } else {
                num1 %= 10;
            }
        }
    }

    if (num1 == 1 || num1 == 3 || num1 == 5 || num1 == 7 || num1 == 8 || num1 == 10 || num1 == 12) {
        if (num2 > 31 || num2 == 0) ans++;
    } else if (num1 != 2) {
        if (num2 > 30 || num2 == 0) ans++;
    } else {
        if (num2 > 28 || num2 == 0) ans++;
    }

    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
