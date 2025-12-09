#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    string tmp;
    vector<string> a;
    while (cin >> tmp) {
        if (tmp == "#") {
            break;
        }
        a.push_back(tmp);
    }
    int n = a.size();

    while (cin >> tmp) {
        if (tmp == "#") {
            break;
        }
        
        int flag = 0;
        vector<string> b;
        for (int i = 0; i < n; i++) {
            if (a[i] == tmp) {
                cout << tmp << " is correct" << '\n';
                flag = 1;
                break;
            }
            

            if (tmp.size() == a[i].size()) {
                int cnt = 0;
                for (int j = 0; j < tmp.size(); j++) {
                    if (tmp[j] == a[i][j]) {
                        cnt++;
                    }
                }

                if (cnt == tmp.size() - 1) {
                    b.push_back(a[i]);
                }
            }

            if (tmp.size() == a[i].size() - 1) {
                string tmp1;
                for (int j = 0; j < a[i].size(); j++) {
                    tmp1 = a[i];
                    tmp1.erase(j, 1);
                    //cout << tmp1 << '\n';
                    if (tmp1 == tmp) {
                        b.push_back(a[i]);
                        break;
                    }
                }
            }

            if (tmp.size() == a[i].size() + 1) {
                string tmp1;
                for (int j = 0; j < tmp.size(); j++) {
                    tmp1 = tmp;
                    tmp1.erase(j, 1);
                    //cout << tmp1 << '\n';
                    if (tmp1 == a[i]) {
                        b.push_back(a[i]);
                        break;
                    }
                }
            }
        }
        if (flag) continue;

        cout << tmp << ": ";
            if (!b.empty()) {
               for (int j = 0; j < b.size(); j++) {
                cout << b[j] << ' ';
               }
            }
            cout << '\n';
    }

    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}
