#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    string s1, s2;

    while (cin >> s1 >> s2) {
        int n = s1.size(), cnt = 0, num1 = 0, num2 = 1, pos1, pos2, ans = 1, tmp, sum = 0;
        vector<int> a;
        a.push_back(0);
        for (int i = 0; i < n; i++) {
            if (s1[i] == '?') {
                a.push_back(i);
            }
        }
        a.push_back(n - 1);
        cnt = a.size() - 2;

        while (1) {
            pos1 = a[num1++], pos2 = a[num2++];

            for (int i = pos1; i < pos2; i++) {
                if (s1[pos1] == '?') {
                    ans *= 9 - (s2[pos1] - '0');
                    tmp = cnt - (num1 - 1);
                    ans = ans * (10 ^ tmp);
                    sum += ans;
                }
            }

            if (pos2 == n - 1) {
                break;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}
