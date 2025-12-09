#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<char> a= {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q',
                 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
void solve() {
    string s1, s2, s;
    while (cin >> s1) {
        if (s1 == "ENDOFINPUT") {
            return;
        }
        
        getline(cin, s);
        getline(cin, s);
        cin >> s2;
        // cout << s1 << '\n';
        // cout << s << '\n';
        // cout << s2 << '\n';

        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                char x = a[(s[i] - 'A' - 5 + 26) % 26];
                cout << x;
            } else {
                cout << s[i];
            }
        }
        cout << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}
