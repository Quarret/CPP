#include <bits/stdc++.h>
using ll = long long;
using namespace std;

map<string, vector<string> > mp;
bool cmp(string x, string y) {
    if (x.size() < y.size()) return 1;
    else if (x.size() == y.size()) {
        return x < y;
    } else return 0;
}
void solve() {
    int n, t;
    string s, tmp;
    cin >> n;
    while (n--) {
        cin >> s >> t;
        for (int i = 0; i < t; i++) {
            cin >> tmp;
            if (mp[s].empty()) {
                mp[s].push_back(tmp);
                continue;
            }

            for (int j = 0; j < mp[s].size(); j++) {
                if (mp[s][j].rfind(tmp) + tmp.size() == mp[s][j].size() && mp[s][j].rfind(tmp) != -1) {
                    break;
                } else if (tmp.rfind(mp[s][j])  + mp[s][j].size() == tmp.size() && tmp.rfind(mp[s][j]) != -1) {
                    mp[s][j] = tmp;
                    break;
                }

                if (j == mp[s].size() - 1) {
                    mp[s].push_back(tmp);
                }
            }
        }

    }

    int cnt = mp.size();
    cout << cnt << '\n';
    for (auto &it : mp) {
        cout << it.first << ' ' << it.second.size() << ' ';
        sort(it.second.begin(), it.second.end(), cmp);
        for (int i = 0; i < it.second.size(); i++) {
            cout << it.second[i] << ' ';
        }
        cout << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}
