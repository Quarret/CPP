#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    string s, ans;
    getline(cin, s);
    vector<int> a(10);

    for (int i = 0; i < s.size(); i++) {
        if (!(s[i] >= '0' && s[i] <= '9')) {
            ans.push_back(s[i]);
        } else {
        if (s[i] == '1') {
            ans += "(One)";
        } else if (s[i] == '2') {
            ans += "(Two)";
        } else if (s[i] == '3') {
            ans += "(Three)";
        } else if (s[i] == '4') {
            ans += "(Four)";
        } else if (s[i] == '5') {
            ans += "(Five)";
        } else if (s[i] == '6') {
            ans += "(Six)";
        } else if (s[i] == '7') {
            ans += "(Seven)";
        } else if (s[i] == '8') {
            ans += "(Eight)";
        } else if (s[i] == '9') {
            ans += "(Nine)";
        } else if (s[i] == '0') {
            ans += "(Zero)";
        }
        a[s[i] - '0']++;
        }
    }

    cout << ans << '\n';
    for (int i = 0; i < 10; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}
