#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve() {
    string s1, s2;
    while (cin >> s1 >> s2) {
        char left = s1[0], right = s2.back();
        int num1 = 0, num2 = 0, n = s1.size(), m = s2.size();
        int flag1 = 0, flag2 = 0;
        for (int i = 1; i < n - 1; i++) {
            if (s1[i] == '-') flag1 = 1;
            else {
                num1 = num1 * 10 + (s1[i] - '0');
            }
        }

        
        for (int i = 0; i < m - 1; i++) {
            if (s2[i] == '-') flag2 = 1;
            else {
                num2 = num2 * 10 + (s2[i] - '0');
            }
        }

        if (flag1) num1 = -num1;
        if (flag2) num2 = -num2;

        if (left == '(' && right == ')') {
            cout << num1 + 1 << ' ' << num2 - 1;
        } else if (left == '[' && right == ']') {
            cout << num1 - 1 << ' ' << num2 + 1;
        } else if (left == '[' && right == ')') {
            cout << num1 - 1 << ' ' << num2 - 1;
        } else {
            cout << num1 + 1 << ' ' << num2 + 1;
        }
        cout << '\n';
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
