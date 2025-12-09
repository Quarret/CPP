#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    string s, ans;
    cin >> s;
    int n = s.size();

    if (n % 8 != 0) {
        cout << "WA" << '\n';
        return;
    } 

    bool flag = 0;
    int res = 0;
    for (int i = 0; i < n; i += 8) {
        string s1 = s.substr(i, 8);
        //cout << s1 << '\n';
        if (s1[0] == '1' && s1[1] == '0' && s1[2] == '1') {
            string tmp = s1.substr(3, 5);
            reverse(tmp.begin(), tmp.end());

            int num = 0;
            for (int j = 0; j <= 4; j++) {
                if (tmp[j] == '1') {
                    num += 1 << j;
                    //cout << num << '\n';
                }
            }

            if (num >= 26) {
                cout << "WA" << '\n';
                return;
            }

            ans += (char)('A' + num);
        } else if (s1[0] == '1' && s1[1] == '1' && s1[2] == '1') {
            ans += ' ';
        } else if (s1[0] == '0') {
            reverse(s1.begin(), s1.end());
            if (flag) {
                int tmp = 0;
                for (int h = 0; h <= 6; h++) {
                    if (s1[h] == '1') {
                        tmp += 1 << h;
                    }
                }
                tmp /= 2;
                ans += to_string(tmp + res);
                flag = 0;
                res = 0;
            } else {
                for (int h = 0; h <= 6; h++) {
                    if (s1[h] == '1') {
                        res += 1 << h;
                    }
                }

                res /= 2;
                flag = 1;
                continue;
            }
        } else {
            cout << "WA" << '\n';
            return;
        }

        if (flag) {
            cout << "WA" << '\n';
            return;
            flag = 0;
        }
    }

    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
