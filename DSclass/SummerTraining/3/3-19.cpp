#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    string s;
    cin >> s;

    vector<int> a,b;

    if (s[0] == 'a') {
        a.push_back(1);
        b.push_back(0);
    } else {
        a.push_back(0);
        b.push_back(1);
    }

    for (int i = 1; i < s.size(); i++) {
        if (s[i] == 'a') {
            a.push_back(1 + a[i - 1]);
            b.push_back(0 + b[i - 1]);
        } else {
            a.push_back(0 + a[i - 1]);
            b.push_back(1 + b[i - 1]);
        }
    }

    int ans = -1, a1, bm, a2;
    for (int i = 0; i < s.size(); i++) {
        for (int j = i; j < s.size(); j++) {
            a1 = a[i];
            bm = b[j] - b[i - 1];
            a2 = a.back() - a[j - 1];
            ans = max(ans, a1 + bm + a2);
            //cout << a1 << ' ' << bm << ' ' << a2 << '\n'; 
        }
    }

    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();                               
}
