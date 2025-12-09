#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int n;
void solve() {
    string s, s1, tmp;
    cin >> s;

    int num = s.size(), num1;
    for (int i = num - 1; i >= 0; i--) {
        tmp += s[i];
        s1 = tmp;
        reverse(s1.begin(), s1.end());

        if (tmp == s1) {
            num1 = tmp.size();
        }
    }

    cout << num - num1 << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (1) {
        cin >> n;

        if (!n) {
            return 0;
        }

        solve();
    }
}
