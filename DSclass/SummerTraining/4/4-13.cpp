#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    ll M1, M2, R1, R2, R3;
    string s;
    while (cin >> M1 >> M2) {
        cin >> s;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'A') {
                R1 = M1;
            } else if (s[i] == 'B') {
                R2 = M2;
            } else if (s[i] == 'C') {
                M1 = R3;
            } else if (s[i] == 'D') {
                M2 = R3;
            } else if (s[i] == 'E') {
                R3 = R1 + R2;
            } else {
                R3 = R1 - R2;
            }
        }

        cout << M1 << ',' << M2 << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}
