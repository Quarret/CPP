#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    string s, tmp;
    while (getline(cin ,s)) {
        vector<string> a;
        s.push_back(' ');
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                a.push_back(tmp);
                tmp.clear();
            } else {
                tmp.push_back(s[i]);
            }
        }

        int cnt = a.size(), num = cnt / 2;

        for (int i = 0; i < num; i++) {
            swap(a[i], a[cnt - i - 1]);
        }

        for (int i = 0; i < cnt; i++) {
            cout << a[i] << ' ';
        }

        cout << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}
