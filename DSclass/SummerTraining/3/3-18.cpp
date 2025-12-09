#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    string s;
    while (cin >> s) {
        int pos = s.find('B');
        int num1 = 0, num2 = 0, num3 = 0, num4 = 0;
        for (int i = 0; i < pos; i++) {
            if (s[i] == '(') {
                num1++;
            } else num3++;
        }

        for (int i = s.size() - 1; i >pos; i--) {
            if (s[i] == ')') {
                num2++;
            } else num4++;
        }

        cout << min(num1 - num3, num2 - num4) << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}
