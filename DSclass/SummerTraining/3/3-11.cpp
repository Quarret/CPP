#include <bits/stdc++.h>
using ll = long long;
using namespace std;

map<int, vector<int> > mp;
void solve() {
    string s;
    while (getline(cin, s)) {
        if (s == "-1") {
            break;
        }

        vector<int> a;
        for (int i = 0; i < s.size(); i += 2) {
            a.push_back(s[i] - '0');
            //cout << s[i] - '0' << ' ';
        }
        //cout << '\n';
        
        bool flag = 0;
        for (int i = 1; i < a.size(); i++) {
            flag = binary_search(mp[a[i]].begin(), mp[a[i]].end(), a[i - 1]);
            if (flag == 0) {
                cout << "NO" << '\n';
                //cout << a[i - 1] << ' ' << a[i] << '\n';
                break;
            }

            if (i == a.size() - 1) {
                cout << "YES" << '\n';
            }
        }

        
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie();

    mp[1] = {0, 3, 4, 7, 8, 9};
    mp[2] = {8};
    mp[3] = {1, 7, 8, 9};
    mp[4] = {1, 8, 9};
    mp[5] = {6, 8, 9};
    mp[6] = {5, 8};
    mp[7] = {0, 1, 3, 8, 9};
    mp[8] = {0, 1, 2, 3, 4, 5, 6, 7, 9};
    mp[9] = {1, 3, 4, 5, 7, 8};
    mp[0] = {1, 7, 8};

    solve();
}
