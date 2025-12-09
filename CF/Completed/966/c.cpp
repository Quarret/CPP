#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    map<int, vector<int> > mp;
    vector<int> a(n);
    map<char, bool> mp1;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]].push_back(i);
    }

    int m;
    cin >> m;
    while (m--) {
        string s;
        cin >> s;

        if (s.size() != n) {
            cout << "NO" << '\n';
            continue;
        }

        bool flag1 = 0;
        for (auto& it : mp) {
            bool flag = 0;
            char x = s[it.second[0]];

            if (mp1[x]) {
                cout << "NO" << '\n';
                flag1 = 1;
                break;
            }

            for (int i = 0; i < it.second.size(); i++) {
                if (s[it.second[i]] != x) {
                    cout << "NO" << '\n';
                    flag1 = 1;
                    flag = 1;
                    break;
                }
            }

            if (flag) {
                break;
            }

            mp1[x] = true;
        }

        if (!flag1) {
            cout << "YES" << '\n';
        }

        mp1.clear();
    }
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
