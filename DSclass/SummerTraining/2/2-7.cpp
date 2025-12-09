#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int n, cnt = 0;
void solve() {
    vector<string> a1, a2;
    string s;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        if (i % 2) {
           a1.push_back(s);
        } else {
            a2.push_back(s);
        }
    }
    
    cout << "set-" << cnt << '\n';
    for (int i = 0; i < a1.size(); i++) {
        cout << a1[i] << '\n';
    }

    for (int i = a2.size() - 1; i >= 0; i--) {
        cout << a2[i] << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie();

    while (1) {
        cin >> n;
        if (!n) {
            return 0;
        }
        cnt++;
        solve();
    }
}
