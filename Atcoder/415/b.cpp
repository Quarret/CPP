#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    string s;
    cin >> s;

    int idx1 = 0, cnt = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '#') {
            if (cnt == 0) {
                idx1 = i + 1;
                cnt++;
            } else {
                cout << idx1 << ',' << i + 1 << '\n';
                cnt = 0;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
