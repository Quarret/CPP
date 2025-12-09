#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int n;
void solve() {
    vector<char> a1, a2;
    string mod = "no good", tmp;
    int cnt1 = 0, cnt2 = 0;
    getline(cin ,tmp);
    for (int i = 1; i <= n; i++) {
        getline(cin, tmp);
        //cout << tmp << '\n';
        if (tmp.find(mod, 0) == -1) {
            if (i % 2) {
                a1.push_back('O');
                cnt1++;
            } else {
                a2.push_back('O');
                cnt2++;
            }
        } else {
            if (i % 2) {
                a1.push_back('X');
            } else {
                a2.push_back('X');
            }
        }
    }

    if (n % 2) {
        a2.push_back('-');
    }

    int num = (n + 1) / 2;
    for (int i = 1; i <= num; i++) {
        cout << i << ' ';
    }
    cout << "Score" << '\n';

    for (int i = 0; i < num; i++) {
        cout << a1[i] << ' ';
    }
    cout << cnt1 << '\n';

    for (int i = 0; i < num; i++) {
        cout << a2[i] << ' ';
    }
    cout << cnt2 << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie();

    while (1) {
        cin >> n;
        if (!n) {
            return 0;
        }

        solve();
    }
}
